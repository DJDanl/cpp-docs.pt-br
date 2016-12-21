---
title: "Classe multi_link_registry | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
f1_keywords: 
  - "agents/concurrency::multi_link_registry"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe multi_link_registry"
ms.assetid: b2aa73a8-e8a6-4255-b117-d07530c328b2
caps.latest.revision: 19
caps.handback.revision: 13
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe multi_link_registry
[!INCLUDE[vs2017banner](../../../assembler/inline/includes/vs2017banner.md)]

O objeto de `multi_link_registry` é `network_link_registry` que gerencia vários blocos de origem ou vários blocos de destino.  
  
## Sintaxe  
  
```  
template<  
   class _Block  
>  
class multi_link_registry : public network_link_registry<_Block>;  
```  
  
#### Parâmetros  
 `_Block`  
 O tipo de dados do bloco que está sendo armazenado no objeto de `multi_link_registry` .  
  
## Membros  
  
### Construtores Públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[Construtor multi\_link\_registry::multi\_link\_registry](../Topic/multi_link_registry::multi_link_registry%20Constructor.md)|Constrói um objeto `multi_link_registry`.|  
|[Destruidor multi\_link\_registry::~multi\_link\_registry](../Topic/multi_link_registry::~multi_link_registry%20Destructor.md)|Destrói o objeto `multi_link_registry`.|  
  
### Métodos Públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[Método multi\_link\_registry::add](../Topic/multi_link_registry::add%20Method.md)|Adiciona um link para o objeto de `multi_link_registry` . \(Substitui [network\_link\_registry::add](../Topic/network_link_registry::add%20Method.md).\)|  
|[Método multi\_link\_registry::begin](../Topic/multi_link_registry::begin%20Method.md)|Retorna um iterador para o primeiro elemento no objeto de `multi_link_registry` . \(Substitui [network\_link\_registry::begin](../Topic/network_link_registry::begin%20Method.md).\)|  
|[Método multi\_link\_registry::contains](../Topic/multi_link_registry::contains%20Method.md)|Pesquisa o objeto de `multi_link_registry` por um bloco especificado. \(Substitui [network\_link\_registry::contains](../Topic/network_link_registry::contains%20Method.md).\)|  
|[Método multi\_link\_registry::count](../Topic/multi_link_registry::count%20Method.md)|Conta o número de itens no objeto de `multi_link_registry` . \(Substitui [network\_link\_registry::count](../Topic/network_link_registry::count%20Method.md).\)|  
|[Método multi\_link\_registry::remove](../Topic/multi_link_registry::remove%20Method.md)|Remove um link de objeto de `multi_link_registry` . \(Substitui [network\_link\_registry::remove](../Topic/network_link_registry::remove%20Method.md).\)|  
|[Método multi\_link\_registry::set\_bound](../Topic/multi_link_registry::set_bound%20Method.md)|Define um limite superior no número de links que o objeto de `multi_link_registry` pode conter.|  
  
## Hierarquia de Herança  
 [network\_link\_registry](../Topic/network_link_registry%20Class.md)  
  
 `multi_link_registry`  
  
## Requisitos  
 **Cabeçalho:** agents.h  
  
 **Namespace:** simultaneidade  
  
## Consulte também  
 [Namespace Concurrency](../../../parallel/concrt/reference/concurrency-namespace.md)   
 [Classe single\_link\_registry](../Topic/single_link_registry%20Class.md)