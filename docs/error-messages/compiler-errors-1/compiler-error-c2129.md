---
title: "Erro do Compilador C2129 | Microsoft Docs"
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
  - "C2129"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "C2129"
ms.assetid: 21a8223e-1d22-4baa-9ca1-922b7f751dd0
caps.latest.revision: 7
caps.handback.revision: 7
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Erro do Compilador C2129
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

função estática “function” declarada mas não definido  
  
 Uma referência antecipada é feita a uma função de `static` que nunca foi definida.  
  
 Uma função de `static` deve ser definida no escopo de arquivo.  Se a função é definida em outro arquivo, deve ser declarado `extern`.