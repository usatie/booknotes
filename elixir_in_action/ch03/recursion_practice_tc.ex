defmodule Loop do
  def list_len(list) do
    do_list_len(0, list)
  end
  defp do_list_len(current_len, []), do: current_len
  defp do_list_len(current_len, [_ | tail]) do
    do_list_len(current_len+1, tail)
  end

  def range(from, to) when from < to, do: do_range([], from, to, 1)
  def range(from, to), do: do_range([], from, to, -1)
  defp do_range(current_range, to, to, _), do: [to | current_range]
  defp do_range(current_range, from, to, inc) do
    do_range([to | current_range], from, to-inc, inc)
  end

  def positive(list), do: filter_positive([], list)
  defp filter_positive(result, []) do
    Enum.reverse(result)
  end
  defp filter_positive(result, [head | tail]) when head > 0 do
    filter_positive([head | result], tail)
  end
  defp filter_positive(result, [_ | tail]) do
    filter_positive(result, tail)
  end
end
