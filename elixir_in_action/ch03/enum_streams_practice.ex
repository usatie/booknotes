defmodule EnumStreams do
  def large_lines!(path) do
    File.stream!(path)
    |> Stream.map(&String.trim_trailing(&1, "\n"))
    |> Enum.filter(&(String.length(&1) > 80))
  end

  def lines_lengths!(path) do
    File.stream!(path)
    |> Stream.map(&String.trim_trailing(&1, "\n"))
    |> Enum.map(&(String.length(&1)))
  end

  def longest_line_length!(path) do
    File.stream!(path)
    |> Stream.map(&String.trim_trailing(&1, "\n"))
    |> Stream.map(&(String.length(&1)))
    |> Enum.reduce(0, &(max(&1, &2)))
  end

  def longest_line!(path) do
    File.stream!(path)
    |> Stream.map(&String.trim_trailing(&1, "\n"))
    |> Stream.map(&(%{line: &1, len: String.length(&1)}))
    |> Enum.reduce(%{line: "", len: 0}, &(if &1[:len] >= &2[:len], do: &1, else: &2))
    |> Map.get(:line)
  end

  def words_per_line!(path) do
    File.stream!(path)
    |> Stream.map(&String.trim_trailing(&1, "\n"))
    |> Stream.map(&String.split(&1))
    |> Enum.map(&Enum.count(&1))
  end
end
