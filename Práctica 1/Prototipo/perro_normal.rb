# encoding: utf-8
# frozen_string_literal: true

require_relative "perro.rb"

module Prototipo
class PerroNormal < Perro
  def hablar()
    puts "Perro normal #{@id}: Guau"
  end
end
end


