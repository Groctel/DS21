# encoding: utf-8
# frozen_string_literal: true

require_relative "gestor_entidades.rb"

module Prototipo
  @oveja = ""
  @perro = ""

  while @oveja.upcase[0] != "N" and @oveja.upcase[0] != "M"
    puts  "¿Qué tipo de oveja?"
    puts  "[N]ormal, [M]onstruosa"
    print "> "
    @oveja = gets.chomp
  end

  puts ""

  while @perro.upcase[0] != "N" and @perro.upcase[0] != "M"
    puts  "¿Qué tipo de perro?"
    puts  "[N]ormal, [M]onstruoso"
    print "> "
    @perro = gets.chomp
  end

  @gestor = GestorEntidades.new(@oveja.upcase[0], @perro.upcase[0])

  puts ""
  puts "¿Cuántos animales?"
  print "> "
  @animales = gets.chomp

  puts ""
  puts "¿Cuántas iteraciones por animal?"
  print "> "
  @iteraciones = gets.chomp

  @gestor.gestionar(@animales.to_i, @iteraciones.to_i)
end
