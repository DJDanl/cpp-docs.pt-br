---
title: "Classe independent_bits_engine | Microsoft Docs"
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
  - "std.tr1.independent_bits_engine"
  - "std::tr1::independent_bits_engine"
  - "tr1::independent_bits_engine"
  - "tr1.independent_bits_engine"
  - "independent_bits_engine"
  - "random/std::tr1::independent_bits_engine"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe independent_bits_engine"
ms.assetid: 889e9a82-f457-49a7-9d2e-26e0fc3cd907
caps.latest.revision: 17
caps.handback.revision: 8
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Classe independent_bits_engine
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Gera uma sequência aleatória de números com um número especificado de bits, recompactando bits de valores retornados pelo mecanismo básico.  
  
## Sintaxe  
  
```  
template<class Engine, size_t W, class UIntType> class independent_bits_engine;  
```  
  
#### Parâmetros  
 `Engine`  
 O tipo de mecanismo de base.  
  
 `W`  
 **Tamanho da palavra**.  Tamanho, em bits, de cada número gerado.  **Pré\-condição**: `0 < W ≤ numeric_limits<UIntType>::digits`  
  
 `UIntType`  
 O tipo de resultado inteiro sem sinal.  Para obter os tipos possíveis, consulte [\<random\>](../standard-library/random.md).  
  
## Membros  
  
||||  
|-|-|-|  
|`independent_bits_engine::independent_bits_engine`|`independent_bits_engine::base`|`independent_bits_engine::discard`|  
|`independent_bits_engine::operator()`|`independent_bits_engine::base_type`|`independent_bits_engine::seed`|  
  
 Para obter mais informações sobre membros do mecanismo, consulte [\<random\>](../standard-library/random.md).  
  
## Comentários  
 Essa classe de template descreve um *adaptador de mecanismo* que produz valores recompactando bits dos valores retornados pelo mecanismo básico, resultando em valores de `W` bits.  
  
## Requisitos  
 **Cabeçalho:** \<random\>  
  
 **Namespace:** std  
  
## Consulte também  
 [\<random\>](../standard-library/random.md)