# encoding: utf-8
# frozen_string_literal: true

require_relative "gestor_entidades.rb"

module Prototipo
  gestor = GestorEntidades.new
  gestor.gestionar(6, 5)
end
