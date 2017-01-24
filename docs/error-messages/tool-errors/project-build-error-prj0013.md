---
title: "Erro PRJ0013 (compila&#231;&#227;o de projeto) | Microsoft Docs"
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
  - "PRJ0013"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "PRJ0013"
ms.assetid: 95e7bafd-63c8-4b2d-b778-f19cdf9ba36c
caps.latest.revision: 7
caps.handback.revision: 7
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Erro PRJ0013 (compila&#231;&#227;o de projeto)
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Os recursos do sistema podem ficar baixos de maneira crítica.Não foi possível criar um pipe necessário para lançar uma compilação.  
  
 Esse erro indica que os recursos do sistema estão baixos.  Para resolver esse erro, reduza o uso dos recursos do sistema por parte de outros processos\/aplicativos.  
  
 Esse erro também pode ocorrer se seu nível de segurança não for suficiente para criar pipes \(consulte [CreatePipe](http://msdn.microsoft.com/library/windows/desktop/aa365152.aspx)\).