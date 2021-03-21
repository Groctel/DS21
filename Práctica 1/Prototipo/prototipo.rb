# encoding: utf-8
# frozen_string_literal: true

require_relative "oveja_normal.rb"
require_relative "perro_normal.rb"

module Prototipo
  hebras = []

  6.times {|id|
    hebras << Thread.new {
      if id % 2 == 0
        animal = OvejaNormal.new(id+1)
      else
        animal = PerroNormal.new(id+1)
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
