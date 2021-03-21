# encoding: utf-8
# frozen_string_literal: true

require_relative "perro.rb"

module Prototipo
class PerroMonstruoso < Perro
  def hablar()
    puts "Perro monstruoso #{@id}: Guau reguau guau en lenguaje de perro (perroguaje)"
  end
end
end



