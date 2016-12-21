---
title: "Erro do Compilador C2856 | Microsoft Docs"
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
  - "C2856"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "C2856"
ms.assetid: fe616c51-124e-49e3-9dd8-883ec1660680
caps.latest.revision: 7
caps.handback.revision: 7
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Erro do Compilador C2856
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

o hdrstop de \#pragma não pode estar dentro de um bloco de \#if  
  
 O pragma de `hdrstop` não pode ser colocado dentro do corpo de um bloco de compilação condicional.  
  
 Mover a instrução de `#pragma hdrstop` a uma área que não esteja contida em um bloco de `#if/#endif` .