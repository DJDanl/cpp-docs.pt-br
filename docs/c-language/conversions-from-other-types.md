---
title: "Convers&#245;es de outros tipos | Microsoft Docs"
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
  - "C"
helpviewer_keywords: 
  - "conversões de tipo, conversão"
  - "Valores, convertendo"
ms.assetid: 30fbd974-8f5a-4b70-ac44-d3937b96b702
caps.latest.revision: 9
caps.handback.revision: 9
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Convers&#245;es de outros tipos
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Como um valor `enum` é um valor `int` por definição, as conversões de e para um valor `enum` são do mesmo tipo de `int`.  Para o compilador Microsoft C, um inteiro é o mesmo que um **long**.  
  
 **Específico da Microsoft**  
  
 Nenhuma conversão entre os tipos de estrutura ou união é permitida.  
  
 Qualquer valor pode ser convertido no tipo `void`, mas o resultado dessa conversão pode ser usado somente em um contexto onde um valor da expressão é descartado, como em uma instrução expression.  
  
 O tipo `void` não tem valor, por definição.  Portanto, não pode ser convertido em qualquer outro tipo, e outros tipos não podem ser convertidos em `void` por atribuição.  Porém, você pode converter explicitamente um valor no tipo `void`, como descrito em [Conversões Type\-Cast](../c-language/type-cast-conversions.md).  
  
 **FIM de Específico da Microsoft**  
  
## Consulte também  
 [Conversões de atribuição](../c-language/assignment-conversions.md)