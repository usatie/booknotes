defmodule Fraction do
  defstruct a: nil, b: nil

  def new(a, b) do
    %Fraction{a: a, b: b}
  end

  def value(%Fraction{a: a, b: b}) do
    a / b
  end

  def value2(f = %Fraction{}) do
    f.a / f.b
  end

  def add(lhs = %Fraction{}, rhs = %Fraction{}) do
    new(lhs.a * rhs.b + lhs.b * rhs.a, lhs.b * rhs.b)
  end
end
