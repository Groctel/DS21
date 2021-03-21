# encoding: utf-8
# frozen_string_literal: true

require_relative "animal_factory.rb"

module Prototipo
class GestorEntidades
  def initialize()
    oveja_proto = OvejaNormal.new(-1)
    perro_proto = PerroMonstruoso.new(-1)
    @@factoria    = AnimalFactory.new(oveja_proto, perro_proto)
  end

  def gestionar(num_animales, num_interacciones)
    hebras = []

    num_animales.times {|id|
      hebras << Thread.new {
        if id % 2 == 0
          animal = @@factoria.CrearOveja()
        else
          animal = @@factoria.CrearPerro()
        end

        num_interacciones.times {
          animal.hablar()
        }
      }
    }

    hebras.each {|thr|
      thr.join
    }
  end
end
end
