defmodule Loop do
  def list_len(list) do
    do_list_len(list)
  end
  defp do_list_len([]), do: 0
  defp do_list_len([_ | tail]), do: 1 + do_list_len(tail)

  def range(from, to) do
    if from < to, do: do_range(from, to, 1), else: do_range(from, to, -1)
  end
  defp do_range(from, from, _), do: [from]
  defp do_range(from, to, inc), do: [from | do_range(from+inc, to, inc)]

  def positive([]), do: []
  def positive([head | tail]) when head > 0 do
    [head | positive(tail)]
  end
  def positive([_ | tail]) do
    positive(tail)
  end
end
