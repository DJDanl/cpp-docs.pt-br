---
title: "Conven&#231;&#245;es de chamada obsoletas | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "language-reference"
f1_keywords: 
  - "__fortran"
  - "__pascal"
  - "__syscall"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Palavra-chave __fortran [C++]"
  - "Palavra-chave __pascal [C++]"
  - "Palavra-chave __syscall [C++]"
  - "convenções de chamada, obsoleto"
  - "WINAPI"
ms.assetid: a91fc665-034a-48ce-b6bd-d27125f308a7
caps.latest.revision: 7
caps.handback.revision: 7
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Conven&#231;&#245;es de chamada obsoletas
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

## Específico da Microsoft  
 As convenções de chamada **\_\_pascal**, **\_\_fortran** e **\_\_syscall** não têm mais suporte.  Você pode emular a funcionalidade delas usando uma das convenções de chamada com suporte e as opções do vinculador apropriadas.  
  
 O WINDOWS.H agora oferece suporte à macro **WINAPI**, que traduz a convenção de chamada apropriada para o destino.  Use **WINAPI** onde você usava **PASCAL** ou **\_\_far \_\_pascal** anteriormente.  
  
## FIM de Específico da Microsoft  
  
## Consulte também  
 [Passagem de argumento e convenções de nomenclatura](../Topic/Argument%20Passing%20and%20Naming%20Conventions.md)