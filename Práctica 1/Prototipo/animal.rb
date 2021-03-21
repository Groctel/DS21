# encoding: utf-8
# frozen_string_literal: true

module Prototipo
class Animal
  def initialize(id)
    set_id(id)
  end

  def set_id(id)
    @id = id
  end

  def hablar()
    raise "Método abstracto '::hablar' no implementado"
  end
end
end

