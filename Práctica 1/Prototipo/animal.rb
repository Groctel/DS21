# encoding: utf-8
# frozen_string_literal: true

module Prototipo
class Animal
  def initialize(id)
    @id = id
  end

  attr_writer :id

  def hablar()
    raise "Método abstracto '::hablar' no implementado"
  end
end
end

