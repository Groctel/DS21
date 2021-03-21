# encoding: utf-8
# frozen_string_literal: true

require_relative "oveja.rb"
require_relative "perro.rb"

module Prototipo
  hebras = []

  6.times {|id|
    hebras << Thread.new {
      if id % 2 == 0
        animal = Oveja.new(id+1)
      else
        animal = Perro.new(id+1)
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
