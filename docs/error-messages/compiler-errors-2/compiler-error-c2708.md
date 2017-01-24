---
title: "Erro do Compilador C2708 | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "error-reference"
f1_keywords: 
  - "C2708"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "C2708"
ms.assetid: d52d3088-1141-42f4-829c-74755a7fcc3a
caps.latest.revision: 7
caps.handback.revision: 7
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Erro do Compilador C2708
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

“identificador”: o comprimento dos parâmetros reais em bytes difere de chamada anterior ou de referência  
  
 Uma função de [\_\_stdcall](../../cpp/stdcall.md) deve ser precedida por um protótipo.  Caso contrário, o compilador interpreta a primeira chamada à função como um protótipo e esse erro ocorre quando o compilador encontrar uma chamada que não corresponde a.  
  
 Para corrigir esse erro adicionar um protótipo da função.