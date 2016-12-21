---
title: "Erro das Ferramentas de Vinculador LNK2008 | Microsoft Docs"
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
  - "LNK2008"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "LNK2008"
ms.assetid: bbcd83c5-c8ae-439e-a033-63643a5bb373
caps.latest.revision: 11
caps.handback.revision: 11
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Erro das Ferramentas de Vinculador LNK2008
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

O destino de Fixup não é “symbol\_name alinhado”  
  
 O LINK encontrou um destino de fixup em seu arquivo de objeto que não foi alinhado corretamente.  
  
 Esse erro pode ser causado pelo alinhamento personalizado de secton \(por exemplo, \#pragma [bloco](../../preprocessor/pack.md)\), pelo modificador de [alinhar](../../cpp/align-cpp.md) , ou usando o código da linguagem assembly que altera o alinhamento de secton.  
  
 Se seu código não usar qualquer de acima, isto pode ser causado pelo compilador.