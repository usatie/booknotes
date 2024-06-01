defmodule TodoServer do
  use GenServer

  def start() do
    GenServer.start(TodoServer, nil)
  end

  def add_entry(todo_server, new_entry) do
    GenServer.cast(todo_server, {:add_entry, new_entry})
  end

  def update_entry(todo_server, entry_id, updater_fun) do
    GenServer.cast(todo_server, {:update_entry, entry_id, updater_fun})
  end

  def delete_entry(todo_server, entry_id) do
    GenServer.cast(todo_server, {:delete_entry, entry_id})
  end

  def entries(todo_server, date) do
    GenServer.call(todo_server, {:entries, date})
  end

  @impl GenServer
  def init(_) do
    {:ok, TodoList.new()}
  end

  @impl GenServer
  def handle_call({:entries, date}, _, todo_list) do
    {:reply, TodoList.entries(todo_list, date), todo_list}
  end

  @impl GenServer
  def handle_cast({:add_entry, new_entry}, todo_list) do
    {:noreply, TodoList.add_entry(todo_list, new_entry)}
  end

  @impl GenServer
  def handle_cast({:update_entry, entry_id, updater_fun}, todo_list) do
    {:noreply, TodoList.update_entry(todo_list, entry_id, updater_fun)}
  end

  @impl GenServer
  def handle_cast({:delete_entry, entry_id}, todo_list) do
    {:noreply, TodoList.delete_entry(todo_list, entry_id)}
  end
end

defmodule TodoList do
  defstruct next_id: 1, entries: %{}

  def new(entries \\ []) do
    Enum.reduce(
      entries,
      %TodoList{},
      &add_entry(&2, &1)
    )
  end

  def add_entry(todo_list, entry) do
    entry = Map.put(entry, :id, todo_list.next_id)
    new_entries = Map.put(
      todo_list.entries,
      todo_list.next_id,
      entry
    )
    %TodoList{todo_list |
      entries: new_entries,
      next_id: todo_list.next_id + 1
    }
  end

  def entries(todo_list, date) do
    todo_list.entries
    |> Map.values()
    |> Enum.filter(fn entry -> entry.date == date end)
  end

  def update_entry(todo_list, entry_id, updater_fun) do
    case Map.fetch(todo_list.entries, entry_id) do
      :error ->
        todo_list
      {:ok, old_entry} ->
        new_entry = updater_fun.(old_entry)
        new_entries = Map.put(todo_list.entries, new_entry.id, new_entry)
        %TodoList{todo_list | entries: new_entries}
    end
  end

  def delete_entry(todo_list, entry_id) do
    %TodoList{todo_list | entries: Map.delete(todo_list.entries, entry_id)}
  end
end
