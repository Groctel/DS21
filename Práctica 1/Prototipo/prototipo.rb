# encoding: utf-8
# frozen_string_literal: true

require_relative "animal_factory.rb"

module Prototipo
  oveja_proto = OvejaNormal.new(-1)
  perro_proto = PerroMonstruoso.new(-1)
  factoria    = AnimalFactory.new(oveja_proto, perro_proto)
  hebras      = []

  6.times {|id|
    hebras << Thread.new {
      if id % 2 == 0
        animal = factoria.CrearOveja()
      else
        animal = factoria.CrearPerro()
      end

      5.times {
        animal.hablar()
      }
    }
  }

  hebras.each {|thr|
    thr.join
  }
end
