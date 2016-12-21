---
title: "Classe texture_view | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
dev_langs: 
  - "C++"
ms.assetid: 6ec2e289-1626-4727-9592-07981cf1d27d
caps.latest.revision: 11
caps.handback.revision: 6
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe texture_view
[!INCLUDE[vs2017banner](../../../assembler/inline/includes/vs2017banner.md)]

Fornece acesso de leitura e acesso de gravação a uma textura.  `texture_view` pode ser usado somente para ler texturas cujo tipo de valor é `int`, `unsigned int` ou `float` que têm o bpse padrão de 32 bits.  Para ler outros formatos de textura, use `texture_view<const _Value_type, _Rank>`.  
  
## Sintaxe  
  
```  
template <  
   typename _Value_type,  
   int _Rank  
>  
class texture_view;  
  
template <  
   typename _Value_type,  
   int _Rank  
>  
class texture_view : public details::_Texture_base<_Value_type, _Rank>;  
  
template <  
   typename _Value_type,  
   int _Rank  
>  
class texture_view<const _Value_type, _Rank> : public details::_Texture_base<_Value_type, _Rank>;  
```  
  
#### Parâmetros  
 `_Value_type`  
 O tipo dos elementos na textura de agrega.  
  
 `_Rank`  
 A classificação do `texture_view`.  
  
## Membros  
  
### Typedefs Públicas  
  
|Nome|Descrição|  
|----------|---------------|  
|`value_type`|O tipo dos elementos na textura agrega.|  
|`coordinates_type`|O tipo da coordenada usada para especificar um texel na `texture_view`\- isto é, `short_vector` que possui a mesma classificação que a textura associada que tem um tipo de valor `float`.|  
|`gather_return_type`|O tipo de retorno usado para coletar operações, ou seja, uma classificação 4 `short_vector` que mantém os quatro componentes de cor homogêneos obtidos dos quatro valores de texel testados.|  
  
### Construtores Públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[Construtor texture\_view::texture\_view](../Topic/texture_view::texture_view%20Constructor.md)|Sobrecarregado.  Constrói uma instância de `texture_view`.|  
|[Destruidor texture\_view::~texture\_view](../Topic/texture_view::~texture_view%20Destructor.md)|Destrói a instância `texture_view`.|  
  
### Métodos Públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[Método texture\_view::gather\_alpha](../Topic/texture_view::gather_alpha%20Method.md)|Sobrecarregado.  Prova a textura nas coordenadas especificadas usando a configuração de amostragem especificada e retorna os componentes alfa \(w\) dos quatro texels provados.|  
|[Método texture\_view::gather\_blue](../Topic/texture_view::gather_blue%20Method.md)|Sobrecarregado.  Prova a textura nas coordenadas especificadas usando a configuração de amostragem especificada e retorna os componentes azuis \(z\) dos quatro texels provados.|  
|[Método texture\_view::gather\_green](../Topic/texture_view::gather_green%20Method.md)|Sobrecarregado.  Prova a textura nas coordenadas especificadas usando a configuração de amostragem especificada e retorna os componentes verdes \(y\) dos quatro texels provados.|  
|[Método texture\_view::gather\_red](../Topic/texture_view::gather_red%20Method.md)|Sobrecarregado.  Prova a textura nas coordenadas especificadas usando a configuração de amostragem especificada e retorna os componentes vermelhos \(x\) dos quatro texels provados.|  
|[Método texture\_view::get](../Topic/texture_view::get%20Method.md)|Sobrecarregado.  Obtém o valor do elemento por índice.|  
|[Método texture\_view::sample](../Topic/texture_view::sample%20Method.md)|Sobrecarregado.  Prova a textura nas coordenadas e no nível de detalhes especificados usando a configuração de amostragem especificada.|  
|[Método texture\_view::set](../Topic/texture_view::set%20Method.md)|Define o valor de um elemento pelo índice.|  
  
### Operadores Públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[Operador texture\_view::operator\(\)](../Topic/texture_view::operator\(\)%20Operator.md)|Sobrecarregado.  Obtém o valor do elemento por índice.|  
|[Operador texture\_view::operator](../Topic/texture_view::operatorOperator.md)|Sobrecarregado.  Obtém o valor do elemento por índice.|  
|[Operador texture\_view::operator\=](../Topic/texture_view::operator=%20Operator.md)|Sobrecarregado.  Operador de atribuição.|  
  
### Membros de Dados Públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[Membro de Dados texture\_view::value\_type](../Topic/texture_view::value_type%20Data%20Member.md)|O tipo de valor dos elementos de `texture_view`.|  
  
## Hierarquia de Herança  
 `_Texture_base`  
  
 `texture_view`  
  
## Requisitos  
 **Cabeçalho:** amp\_graphics.h  
  
 **Namespace:** concurrency::graphics  
  
## Consulte também  
 [Namespace Concurrency::graphics](../../../parallel/amp/reference/concurrency-graphics-namespace.md)