# encoding: utf-8
# frozen_string_literal: true

require_relative "oveja.rb"

module Prototipo
class OvejaNormal < Oveja
  def hablar()
    puts "Oveja normal #{@id}: Beeeeee"
  end
end
end

