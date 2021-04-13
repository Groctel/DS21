# encoding: utf-8
# frozen_string_literal: true

require_relative "oveja_normal.rb"
require_relative "oveja_monstruosa.rb"
require_relative "perro_normal.rb"
require_relative "perro_monstruoso.rb"

module Prototipo
class AnimalFactory
  def initialize(oveja_proto, perro_proto)
    @@id = 1

    @oveja_proto = oveja_proto
    @perro_proto = perro_proto
  end

  def crear_oveja()
    oveja = @oveja_proto.clone
    oveja.id = @@id
    @@id += 1

    return oveja
  end

  def crear_perro()
    perro = @perro_proto.clone
    perro.id = @@id
    @@id += 1

    return perro
  end
end
end
