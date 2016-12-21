---
title: "Aviso do compilador (n&#237;vel 1) C4651 | Microsoft Docs"
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
  - "C4651"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "C4651"
ms.assetid: f1ea82aa-4dc1-4972-b55a-57fdb962f0dd
caps.latest.revision: 7
caps.handback.revision: 7
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Aviso do compilador (n&#237;vel 1) C4651
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

a definição “” especificado para o cabeçalho pré\-compilado mas não para o atual cria  
  
 A definição foi especificada quando o cabeçalho pré\-compilado foi gerado, mas não nesta compilação.  
  
 A definição será aplicado no cabeçalho pré\-compilado, mas não no restante de código.  
  
 Se um cabeçalho pré\-compilado foi criado com \/DSYMBOL, o compilador gerará este aviso se \/Yu cria não tem \/DSYMBOL.  Adicionando \/DSYMBOL para a linha de comando \/Yu resolve esse aviso.