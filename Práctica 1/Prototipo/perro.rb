# encoding: utf-8
# frozen_string_literal: true

require_relative "animal.rb"

module Prototipo
class Perro < Animal
  # def initialize(id)
  #   @id = id
  # end

  def hablar()
    puts "Perro #{@id}: Guau"
  end
end
end
