defmodule TodoList.CsvImporter do
  def import(path) do
    path
    |> read_lines
    |> create_entries
    |> TodoList.new()
  end

  defp read_lines(path) do
    path
    |> File.stream!()
    |> Stream.map(&String.trim_trailing(&1, "\n"))
  end

  defp create_entries(lines) do
    Stream.map(
      lines,
      fn line ->
        [date_string, title] = String.split(line, ",")
        date = Date.from_iso8601!(date_string)
        %{date: date, title: title}
      end
    )
  end
end
