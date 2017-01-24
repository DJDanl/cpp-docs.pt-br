---
title: "Classe discard_block_engine | Microsoft Docs"
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
  - "tr1.discard_block_engine"
  - "std.tr1.discard_block_engine"
  - "std::tr1::discard_block_engine"
  - "random/std::tr1::discard_block_engine"
  - "discard_block_engine"
  - "tr1::discard_block_engine"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe discard_block_engine"
ms.assetid: aa84808e-38fe-4fa0-9f73-d5b9a653345b
caps.latest.revision: 18
caps.handback.revision: 9
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Classe discard_block_engine
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Gera uma sequência aleatória descartando valores retornados pelo mecanismo de base.  
  
## Sintaxe  
  
```  
template<class Engine, size_t P, size_t R> class discard_block_engine;  
```  
  
#### Parâmetros  
 `Engine`  
 O tipo de mecanismo de base.  
  
 `P`  
 **Tamanho do bloco**.  O número de valores em cada bloco.  
  
 `R`  
 **Bloco usado**.  O número de valores em cada bloco usado.  O restante é descartado \(`P` \- `R`\).  **Pré\-condição**: `0 < R ≤ P`  
  
## Membros  
  
||||  
|-|-|-|  
|`discard_block_engine::discard_block_engine`|`discard_block_engine::base`|`discard_block_engine::discard`|  
|`discard_block_engine::operator()`|`discard_block_engine::base_type`|`discard_block_engine::seed`|  
  
 Para obter mais informações sobre membros do mecanismo, consulte [\<random\>](../standard-library/random.md).  
  
## Comentários  
 Essa classe de modelo descreve um adaptador de mecanismo que produz valores descartando alguns dos valores retornados pelo mecanismo de base.  
  
## Requisitos  
 **Cabeçalho:** \<random\>  
  
 **Namespace:** std  
  
## Consulte também  
 [\<random\>](../standard-library/random.md)