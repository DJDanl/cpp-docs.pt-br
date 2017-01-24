---
title: "Classe de CComCurrency | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "reference"
f1_keywords: 
  - "CComCurrency"
  - "ATL.CComCurrency"
  - "ATL::CComCurrency"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe de CComCurrency"
ms.assetid: a1c3d10a-bba6-40cc-8bcf-aed9023c8a9e
caps.latest.revision: 21
caps.handback.revision: 9
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe de CComCurrency
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

`CComCurrency` tem métodos e operadores para criar e gerenciar um objeto de moeda.  
  
## Sintaxe  
  
```  
  
class CComCurrency  
  
```  
  
## Membros  
  
### Construtores Públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[CComCurrency::CComCurrency](../Topic/CComCurrency::CComCurrency.md)|O construtor para uma `CComCurrency` objeto.|  
  
### Métodos Públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[CComCurrency::GetCurrencyPtr](../Topic/CComCurrency::GetCurrencyPtr.md)|Retorna o endereço de uma `m_currency` membro de dados.|  
|[CComCurrency::GetFraction](../Topic/CComCurrency::GetFraction.md)|Chame esse método para retornar o componente frações de um `CComCurrency` objeto.|  
|[CComCurrency::GetInteger](../Topic/CComCurrency::GetInteger.md)|Chame esse método para retornar o componente inteiro de uma `CComCurrency` objeto.|  
|[CComCurrency::Round](../Topic/CComCurrency::Round.md)|Chame este método para arredondar um `CComCurrency` objeto até o valor inteiro mais próximo.|  
|[CComCurrency::SetFraction](../Topic/CComCurrency::SetFraction.md)|Chame esse método para configurar o componente frações de um `CComCurrency` objeto.|  
|[CComCurrency::SetInteger](../Topic/CComCurrency::SetInteger.md)|Chame esse método para configurar o componente de inteiro de uma `CComCurrency` objeto.|  
  
### Operadores Públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[CComCurrency::operator \-](../Topic/CComCurrency::operator%20-2.md)|Esse operador é usado para executar subtração em um `CComCurrency` objeto.|  
|[CComCurrency::operator\! \=](../Topic/CComCurrency::operator%20!=.md)|Compara dois `CComCurrency` objetos desigualdade.|  
|[CComCurrency::operator \*](../Topic/CComCurrency::operator%20*.md)|Esse operador é usado para executar uma multiplicação em uma `CComCurrency` objeto.|  
|[\*\= De CComCurrency::operator](../Topic/CComCurrency::operator%20*=.md)|Esse operador é usado para executar uma multiplicação em um `CComCurrency` do objeto e atribui o resultado.|  
|[CComCurrency::operator\/](../Topic/CComCurrency::operator%20-1.md)|Esse operador é usado para realizar a divisão em uma `CComCurrency` objeto.|  
|[CComCurrency::operator\/\=](../Topic/CComCurrency::operator%20-=2.md)|Esse operador é usado para realizar a divisão em uma `CComCurrency` do objeto e atribui o resultado.|  
|[CComCurrency::operator \+](../Topic/CComCurrency::operator%20+.md)|Esse operador é usado para executar a adição em um `CComCurrency` objeto.|  
|[CComCurrency::operator \+\=](../Topic/CComCurrency::operator%20+=.md)|Esse operador é usado para executar a adição em um `CComCurrency` do objeto e atribuir o resultado ao objeto atual.|  
|[CComCurrency::operator \<](../Topic/CComCurrency::operator%20%3C.md)|Esse operador compara dois `CComCurrency` objetos para determinar o menor.|  
|[\<\= De CComCurrency::operator](../Topic/CComCurrency::operator%20%3C=.md)|Esse operador compara dois `CComCurrency` objetos para determinar igualdade ou menor.|  
|[CComCurrency::operator \=](../Topic/CComCurrency::operator%20=.md)|Esse operador atribui o `CComCurrency` objeto para um novo valor.|  
|[CComCurrency::operator \- \=](../Topic/CComCurrency::operator%20-=1.md)|Esse operador é usado para executar subtração em um `CComCurrency` do objeto e atribui o resultado.|  
|[\=\= De CComCurrency::operator](../Topic/CComCurrency::operator%20==.md)|Esse operador compara dois `CComCurrency` objetos para igualdade.|  
|[CComCurrency::operator \>](../Topic/CComCurrency::operator%20%3E.md)|Esse operador compara dois `CComCurrency` objetos para determinar o maior.|  
|[\>\= De CComCurrency::operator](../Topic/CComCurrency::operator%20%3E=.md)|Esse operador compara dois `CComCurrency` objetos para determinar igualdade ou maior.|  
|[MOEDA de CComCurrency::operator](../Topic/CComCurrency::operator%20CURRENCY.md)|Conversões de uma `CURRENCY` objeto.|  
  
### Membros de Dados Públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[CComCurrency::m\_currency](../Topic/CComCurrency::m_currency.md)|O `CURRENCY` variável criada por sua instância de classe.|  
  
## Comentários  
 `CComCurrency` é um wrapper para o **moeda** tipo de dados.  **Moeda** é implementado como um valor inteiro de 8 bytes dois complementos dimensionado por 10.000.  Isso fornece um número de ponto fixo com 15 dígitos à esquerda da vírgula decimal e 4 dígitos à direita.  O **moeda** tipo de dados é extremamente útil para cálculos que envolvem dinheiro ou para os cálculos de ponto fixo em que a precisão é importante.  
  
 O **CComCurrency** wrapper implementa operações de aritmética, atribuição e comparação para este tipo de ponto fixo.  Os aplicativos suportados foram selecionados para controlar os erros de arredondamento que podem ocorrer durante os cálculos de ponto fixo.  
  
 O `CComCurrency` objeto fornece acesso aos números em ambos os lados do ponto decimal na forma de dois componentes: um componente de número inteiro que armazena o valor à esquerda do ponto decimal e um componente de fração que armazena o valor à direita do ponto decimal.  O componente fracionário é armazenado internamente como um valor inteiro entre\-9999 \(**CY\_MIN\_FRACTION**\) e \+9999 \(**CY\_MAX\_FRACTION**\).  O método [CComCurrency::GetFraction](../Topic/CComCurrency::GetFraction.md) retorna um valor de escala com um fator de 10000 \(**CY\_SCALE**\).  
  
 Ao especificar o número inteiro e componentes fracionários de um **CComCurrency** de objeto, lembre\-se de que o componente fracionário é um número no intervalo de 0 a 9999.  Isso é importante ao lidar com uma moeda como o dólar americano que expresse quantidades usando apenas dois dígitos significativos após o ponto decimal.  Embora os dois últimos dígitos não forem exibidos, eles devem ser levados em conta.  
  
|Valor|Atribuições de CComCurrency possíveis|  
|-----------|-------------------------------------------|  
|$10.50|CComCurrency\(10,5000\) *ou* CComCurrency\(10.50\)|  
|$10.05|CComCurrency\(10,500\) *ou* CComCurrency\(10.05\)|  
  
 Os valores **CY\_MIN\_FRACTION**, **CY\_MAX\_FRACTION**, e **CY\_SCALE** são definidos em atlcur.h.  
  
## Requisitos  
 **Cabeçalho:** atlcur.h  
  
## Consulte também  
 [Classe de COleCurrency](../Topic/COleCurrency%20Class.md)   
 [moeda](http://msdn.microsoft.com/pt-br/5e81273c-7289-45c7-93c0-32c1553f708e)   
 [Visão geral de classe](../../atl/atl-class-overview.md)