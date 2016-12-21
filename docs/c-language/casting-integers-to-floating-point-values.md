---
title: "Convertendo inteiros em valores de ponto flutuante | Microsoft Docs"
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
  - "números inteiros, convertendo em valores de ponto flutuante"
ms.assetid: 81fd5b7d-15eb-4c11-a8c8-e1621ff54fd3
caps.latest.revision: 6
caps.handback.revision: 6
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Convertendo inteiros em valores de ponto flutuante
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

**ANSI 3.2.1.3** A direção de truncamento quando um número integral é convertido em um número de ponto flutuante que não pode representar exatamente o valor original  
  
 Quando um número integral é convertido em um valor de ponto flutuante que não pode representar o valor com exatidão, o valor é arredondado \(para cima ou para baixo\) para o valor apropriado mais próximo.  
  
 Por exemplo, a conversão de **unsigned long** \(com 32 bits de precisão\) em um **float** \(cuja mantissa tem 23 bits de precisão\) arredondará o número para o múltiplo mais próximo de 256.  Todos os valores de 4.294.966.913 a 4.294.967.167 de **long** serão arredondados para o valor 4.294.967.040 de **float**.  
  
## Consulte também  
 [Matemática de ponto flutuante](../c-language/floating-point-math.md)