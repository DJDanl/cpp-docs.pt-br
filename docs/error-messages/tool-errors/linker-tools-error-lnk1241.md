---
title: "Erro das Ferramentas de Vinculador LNK1241 | Microsoft Docs"
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
  - "LNK1241"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "LNK1241"
ms.assetid: 7b8b52eb-0231-4521-b52a-2bce8d3e8956
caps.latest.revision: 7
caps.handback.revision: 7
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Erro das Ferramentas de Vinculador LNK1241
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

arquivo de recurso de “arquivo especificado já recurso”  
  
 Esse erro será gerado se você executar manualmente **cvtres** de linha de comando e se você passa o arquivo resultante de .obj ao vinculador além de outros arquivos de .res.  
  
 Para especificar vários arquivos de .res, todos os passa para o vinculador como arquivos de .res, não de dentro dos arquivos de .obj criados por **cvtres**.