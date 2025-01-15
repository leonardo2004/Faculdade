#Nome: Leonardo Tomasela Leal RA: 170291
class Viagem:
    def __init__(self, distancia_km, tempo_min, tarifa_base, tipo_servico, surge_price=False, gorjeta=0.0):
        self.distancia_km = distancia_km
        self.tempo_min = tempo_min
        self.tarifa_base = tarifa_base
        self.tipo_servico = tipo_servico
        self.surge_price = surge_price
        self.gorjeta = gorjeta
        self.incentivos = 0.0
        self.taxas_servico = 0.2  # taxa de serviço do Uber (20%)
        self.bonus_consecutivos = 0.0
        self.bonus_quest = 0.0
        self.taxas_dinamic = {'UberX': 1.0, 'UberXL': 1.5, 'UberBlack': 2.0}
    
    def calcular_pago_base(self):
        # Retorna o valor base sem considerar outros fatores
        return self.tarifa_base
    
    def calcular_taxa_distancia(self):
        # Dependendo do tipo de serviço, podemos ter diferentes taxas por quilômetro
        taxa_distancia = {
            'UberX': 1.2,  # exemplo, R$1,20 por km
            'UberXL': 1.5,  # exemplo, R$1,50 por km
            'UberBlack': 2.0  # exemplo, R$2,00 por km
        }
        return taxa_distancia.get(self.tipo_servico, 1.2) * self.distancia_km
    
    def calcular_taxa_tempo(self):
        # Considerando uma taxa por minuto
        taxa_tempo = 0.5  # exemplo: R$0,50 por minuto
        return taxa_tempo * self.tempo_min
    
    def aplicar_surge_price(self, valor):
        if self.surge_price:
            return valor * 1.5  # Surge pricing aumenta o valor em 50%
        return valor
    
    def calcular_bonus_consecutivos(self, num_vias_consecutivas):
        # Se o motorista completar várias viagens consecutivas, recebe um bônus
        if num_vias_consecutivas >= 5:
            self.bonus_consecutivos = 10.0  # exemplo de bônus
        return self.bonus_consecutivos
    
    def calcular_bonus_quest(self, quest_completada):
        # Caso o motorista complete uma quest (meta), ganha um bônus
        if quest_completada:
            self.bonus_quest = 20.0  # exemplo de bônus
        return self.bonus_quest
    
    def calcular_taxa_servico(self, total_pago):
        return total_pago * self.taxas_servico
    
    def calcular_pago_total(self, num_vias_consecutivas, quest_completada):
        # Cálculos de pagamento com todos os fatores
        pago_base = self.calcular_pago_base()
        taxa_distancia = self.calcular_taxa_distancia()
        taxa_tempo = self.calcular_taxa_tempo()
        
        total = pago_base + taxa_distancia + taxa_tempo + self.gorjeta
        total = self.aplicar_surge_price(total)
        total += self.calcular_bonus_consecutivos(num_vias_consecutivas)
        total += self.calcular_bonus_quest(quest_completada)
        
        total_pago = total - self.calcular_taxa_servico(total)
        return total_pago


class Motorista:
    def __init__(self, nome, classificacao, cidade):
        """
        Inicializa o motorista.
        :param nome: Nome do motorista
        :param classificacao: Classificação média do motorista (exemplo: 4.9)
        :param cidade: Cidade em que o motorista opera
        """
        self.nome = nome
        self.classificacao = classificacao
        self.cidade = cidade
        self.total_viagens = 0
        self.ganhos_totais = 0.0
    
    def registrar_viagem(self, viagem: Viagem, num_vias_consecutivas=0, quest_completada=False):
        """
        Registra uma viagem e atualiza os ganhos e total de viagens.
        :param viagem: Objeto da classe Viagem
        :param num_vias_consecutivas: Número de viagens consecutivas
        :param quest_completada: Se o motorista completou uma quest
        """
        ganho_viagem = viagem.calcular_pago_total(num_vias_consecutivas, quest_completada)
        self.ganhos_totais += ganho_viagem
        self.total_viagens += 1
        print(f"Viagem registrada. Ganho: R${ganho_viagem:.2f}")
    
    def exibir_detalhes_motorista(self):
        """
        Exibe os detalhes do motorista, como nome, classificação e ganhos totais.
        """
        print(f"Nome: {self.nome}")
        print(f"Classificação: {self.classificacao}")
        print(f"Cidade: {self.cidade}")
        print(f"Total de viagens: {self.total_viagens}")
        print(f"Ganhos totais: R${self.ganhos_totais:.2f}")


# Exemplo de uso
motorista = Motorista(nome="Carlos Silva", classificacao=4.9, cidade="São Paulo")
viagem1 = Viagem(distancia_km=10, tempo_min=20, tarifa_base=5.0, tipo_servico='UberX', surge_price=False, gorjeta=5.0)
viagem2 = Viagem(distancia_km=8, tempo_min=15, tarifa_base=5.0, tipo_servico='UberXL', surge_price=True, gorjeta=8.0)

# Registrar viagens
motorista.registrar_viagem(viagem1, num_vias_consecutivas=3, quest_completada=False)
motorista.registrar_viagem(viagem2, num_vias_consecutivas=5, quest_completada=True)

# Exibir detalhes do motorista
motorista.exibir_detalhes_motorista()

# Exemplo de uso
viagem = Viagem(distancia_km=15, tempo_min=30, tarifa_base=5.0, tipo_servico='UberXL', surge_price=True, gorjeta=10.0)
ganhos_motorista = viagem.calcular_pago_total(num_vias_consecutivas=6, quest_completada=True)

print(f"Ganhos totais do motorista: R${ganhos_motorista:.2f}")