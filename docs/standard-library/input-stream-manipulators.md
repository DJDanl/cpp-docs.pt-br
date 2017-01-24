---
title: "Manipuladores de Fluxo de Entrada | Microsoft Docs"
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
helpviewer_keywords: 
  - "objetos de fluxo de entrada"
  - "fluxos de entrada, manipuladores"
ms.assetid: 0addcacb-7b7b-4d70-9775-a59abc400fb3
caps.latest.revision: 8
caps.handback.revision: 7
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Manipuladores de Fluxo de Entrada
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Muitos manipuladores, como [setprecision](../Topic/setprecision.md), são definidos para a classe de `ios` e assim se aplicam aos fluxos de entrada.  Poucos manipuladores, porém, afetam realmente objetos do fluxo de entrada.  Esses que fizer isso, o mais importante são os manipuladores `dec``oct`, e `hex`raiz, que determinam a base de conversão usada com números de fluxo de entrada.  
  
 Na extração, o manipulador de `hex` permite o processamento de vários formatos de entrada.  Por exemplo, c, C, 0xc 2.0, 0xC, 0Xc, e 0XC todos são interpretados como o inteiro decimal 12.  Qualquer caractere diferente de 0 a 9, A F\- com 2.0, à f, x, X e encerra a conversão numérica.  Portanto a sequência `"124n5"` é convertida no número 124 com o conjunto [basic\_ios::fail](../Topic/basic_ios::fail.md) bit.  
  
## Consulte também  
 [Fluxos de entrada](../standard-library/input-streams.md)