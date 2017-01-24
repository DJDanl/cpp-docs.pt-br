---
title: "Erro fatal C1005 | Microsoft Docs"
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
  - "C1005"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "C1005"
ms.assetid: 150daf8e-a38a-4669-9c1a-a05b5a1f65ef
caps.latest.revision: 7
caps.handback.revision: 7
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Erro fatal C1005
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

muito grande para o buffer de cadeia de caracteres  
  
 Uma cadeia de caracteres em um arquivo intermediário do compilador estourou um buffer.  
  
 Você pode obter esse erro quando o parâmetro que você passa como o [\/Fd](../../build/reference/fd-program-database-file-name.md) ou [\/Yl](../../build/reference/yl-inject-pch-reference-for-debug-library.md) opções do compilador é maior do que 256 bytes.