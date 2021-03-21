# encoding: utf-8
# frozen_string_literal: true

require_relative "oveja.rb"

module Prototipo
class OvejaMonstruosa < Oveja
  def hablar()
    puts "Oveja monstruosa #{@id}: Beeeeeeber es bueno para el hígado"
  end
end
end


