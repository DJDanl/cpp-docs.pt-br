---
title: "Erro fatal U1095 (NMAKE) | Microsoft Docs"
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
  - "U1095"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "U1095"
ms.assetid: a392582b-06db-4568-9c13-450293a4fbda
caps.latest.revision: 6
caps.handback.revision: 6
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Erro fatal U1095 (NMAKE)
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

linha de comando expandida “commandline” é muito longa  
  
 Depois da expansão macro, a linha de comando determinada excedeu o limite no comprimento de linhas de comando do sistema operacional.  
  
 MS\-DOS permite até 128 caracteres em uma linha de comando.  
  
 Se o comando é para um programa que pode aceitar a entrada da linha de comando de um arquivo, para alterar a entrada de comando e de fonte de um arquivo em disco ou de um arquivo embutido.  Por exemplo, o LINK e o LIB aceitam entrada de um arquivo de resposta.