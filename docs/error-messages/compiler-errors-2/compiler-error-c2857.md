---
title: "Erro do Compilador C2857 | Microsoft Docs"
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
  - "C2857"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "C2857"
ms.assetid: b57302bd-58ec-45ae-992a-1e282d5eeccc
caps.latest.revision: 7
caps.handback.revision: 7
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Erro do Compilador C2857
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

a instrução “\#include” especificada com a opção de linha de comando \/Ycfilename não foi encontrada no arquivo de origem  
  
 A opção de [\/Yc](../../build/reference/yc-create-precompiled-header-file.md) especifica o nome de um arquivo incluir que não serão incluídos no arquivo de origem que está sendo criado.  
  
 Esse erro pode ser causado por uma instrução de `#include` em um bloco de compilação condicional que não é criado.