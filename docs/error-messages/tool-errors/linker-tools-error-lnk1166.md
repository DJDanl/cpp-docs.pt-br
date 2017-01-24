---
title: "Erro das Ferramentas de Vinculador LNK1166 | Microsoft Docs"
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
  - "LNK1166"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "LNK1166"
ms.assetid: d69548a8-0efb-44e1-90b7-b27636a4b575
caps.latest.revision: 6
caps.handback.revision: 6
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Erro das Ferramentas de Vinculador LNK1166
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

não pode ajustar o código no offset\=offset, va\=value  
  
 O LINK não pôde preencher conforme necessário o código.  
  
 Certas instruções não são permitidas qual cruzar os limites de página em alguns processadores.  O LINK tentar adicionar preenche para corrigir isso.  Nesse caso, o LINK não pode contornar o problema.