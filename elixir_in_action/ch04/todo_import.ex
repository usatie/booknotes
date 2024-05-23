defmodule TodoList.CsvImporter do
  defp filtered_lines!(path) do
    path
    |> File.stream!()
    |> Stream.map(&String.trim_trailing(&1, "\n"))
  end

  defp to_date!(date_string) do
    Date.from_iso8601!(date_string)
  end

  def import(path) do
    path
    |> filtered_lines!                                                        # line
    |> Stream.map(&(String.split(&1, ",")))                                   # [date_string, title]
    |> Stream.map(fn [ds, title] -> %{date: to_date!(ds), title: title} end)  # %{date: date, title: title}
    |> TodoList.new()
  end
end
