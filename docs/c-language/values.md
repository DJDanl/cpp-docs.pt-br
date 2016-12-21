---
title: "Valores | Microsoft Docs"
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
ms.assetid: 24003f89-220f-4f93-be7a-b650c26157d7
caps.latest.revision: 9
caps.handback.revision: 9
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Valores
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

**ANSI 3.1.2.5** As representações e os conjuntos de valores de vários tipos de números de ponto flutuante  
  
 O tipo **float** contém 32 bits: 1 para o sinal, 8 para o exponente e 23 para a mantissa.  O intervalo é \+\/– 3.4E38 com pelo menos 7 dígitos de precisão.  
  
 O tipo **double** contém 64 bits: 1 para o sinal, 11 para o expoente e 52 para a mantissa.  O intervalo é \+\/– 1.7E308 com pelo menos 15 dígitos de precisão.  
  
 O tipo **long double** contém 80 bits: 1 para o sinal, 15 para o expoente e 64 para a mantissa.  O intervalo é \+\/– 1.2E4932 com pelo menos 19 dígitos de precisão.  Observe que com o compilador Microsoft C, a representação do tipo **long double** é idêntico ao tipo **double**.  
  
## Consulte também  
 [Matemática de ponto flutuante](../c-language/floating-point-math.md)