# encoding: utf-8
# frozen_string_literal: true

module Prototipo
class Oveja

  def initialize(id)
    @id = id
  end

  def hablar()
    puts "Oveja #{@id}: Beeeeee"
  end
end
end
