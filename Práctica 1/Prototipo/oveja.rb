# encoding: utf-8
# frozen_string_literal: true

require_relative "animal.rb"

module Prototipo
class Oveja < Animal
  # def initialize(id)
  #   @id = id
  # end

  def hablar()
    puts "Oveja #{@id}: Beeeeee"
  end
end
end
