defmodule Todo.Database do
  use GenServer

  @db_folder "./persist"

  def start do
    GenServer.start(__MODULE__, nil,
      name: __MODULE__
    )
  end

  def store(key, data) do
    key
    |> choose_worker()
    |> Todo.DatabaseWorker.store(key, data)
  end

  def get(key) do
    key
    |> choose_worker()
    |> Todo.DatabaseWorker.get(key)
  end

  @impl GenServer
  def init(_) do
    IO.puts("Starting to-do database server. #{inspect(self())}")
    File.mkdir_p!(@db_folder)
    pool = Enum.reduce(0..2, %{}, fn index, workers ->
      db_folder = Path.join(@db_folder, "#{index}")
      pid = Todo.DatabaseWorker.start(db_folder)
      Map.put(workers, index, pid)
    end)
    {:ok, pool}
  end

  def choose_worker(key) do
    GenServer.call(__MODULE__, {:choose_worker, key})
  end

  @impl GenServer
  def handle_call({:choose_worker, key}, _, pool) do
    index = :erlang.phash2(key, 3)
    {:ok, worker} = Map.get(pool, index)
    {:reply, worker, pool}
  end
end
