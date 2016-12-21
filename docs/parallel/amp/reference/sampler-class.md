---
title: "Classe de amostra | Microsoft Docs"
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
ms.assetid: 9a6a9807-497d-402d-b092-8c4d86275b80
caps.latest.revision: 7
caps.handback.revision: 2
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe de amostra
[!INCLUDE[vs2017banner](../../../assembler/inline/includes/vs2017banner.md)]

A classe sampler agrega informações de configuração de amostragem a serem usadas na amostragem de textura.  
  
## Sintaxe  
  
```  
class sampler;  
```  
  
## Membros  
  
### Construtores Públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[Construtor sampler::sampler](../Topic/sampler::sampler%20Constructor.md)|Sobrecarregado.  Constrói uma instância de demonstrador.|  
  
### Métodos Públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[Método sampler::get\_address\_mode](../Topic/sampler::get_address_mode%20Method.md)|Retorna o `address_mode` que está associado ao objeto de amostra.|  
|[Método sampler::get\_border\_color](../Topic/sampler::get_border_color%20Method.md)|Retorna a cor da borda que está associada ao objeto de amostra.|  
|[Método sampler::get\_filter\_mode](../Topic/sampler::get_filter_mode%20Method.md)|Retorna o `filter_mode` que está associado com o objeto de amostra.|  
  
### Operadores Públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[Operador sampler::operator\=](../Topic/sampler::operator=%20Operator.md)|Sobrecarregado.  Operador de atribuição.|  
  
### Membros de Dados Públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[Membro de Dados sampler::address\_mode](../Topic/sampler::address_mode%20Data%20Member.md)|Obtém o modo de endereço do objeto `sampler`.|  
|[Membro de Dados sampler::border\_color](../Topic/sampler::border_color%20Data%20Member.md)|Obtém a cor da borda do objeto `sampler`.|  
|[Membro de Dados sampler::filter\_mode](../Topic/sampler::filter_mode%20Data%20Member.md)|Obtém o modo de filtro do objeto `sampler`.|  
  
## Hierarquia de Herança  
 `sampler`  
  
## Requisitos  
 **Cabeçalho:** amp\_graphics.h  
  
 **Namespace:** concurrency::graphics  
  
## Consulte também  
 [Namespace Concurrency::graphics](../../../parallel/amp/reference/concurrency-graphics-namespace.md)