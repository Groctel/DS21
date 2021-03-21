# encoding: utf-8
# frozen_string_literal: true

require_relative "oveja.rb"

module Prototipo
  hebras = []

  6.times {|id|
    hebras << Thread.new {
      oveja = Oveja.new(id+1)
      5.times {
        oveja.hablar()
      }
    }
  }

  hebras.each {|thr|
    thr.join
  }
end
