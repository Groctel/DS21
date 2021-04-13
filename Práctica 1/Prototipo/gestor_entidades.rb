# encoding: utf-8
# frozen_string_literal: true

require_relative "animal_factory.rb"

module Prototipo
class GestorEntidades
  def initialize(oveja, perro)
    if oveja == 'N'
      oveja_proto = OvejaNormal.new(-1)
    elsif oveja == 'M'
      oveja_proto = OvejaMonstruosa.new(-1)
    end

    if perro == 'N'
      perro_proto = PerroNormal.new(-1)
    elsif perro == 'M'
      perro_proto = PerroMonstruoso.new(-1)
    end

    @@factoria = AnimalFactory.new(oveja_proto, perro_proto)
  end

  def gestionar(num_animales, num_interacciones)
    hebras = []

    num_animales.times {|id|
      hebras << Thread.new {
        if id % 2 == 0
          animal = @@factoria.crear_oveja()
        else
          animal = @@factoria.crear_perro()
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
