---
title: "Erros de posi&#231;&#227;o de arquivo | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
dev_langs: 
  - "C++"
  - "C"
helpviewer_keywords: 
  - "ponteiros de arquivo [C++], erros de posição de arquivo"
ms.assetid: d5e59d8b-08c0-4927-a338-0b2d8234ce24
caps.latest.revision: 6
caps.handback.revision: 6
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Erros de posi&#231;&#227;o de arquivo
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

**ANSI 4.9.9.1, 4.9.9.4** O valor no qual a macro `errno` é definida pela função `fgetpos` ou `ftell` na falha  
  
 Quando `fgetpos` ou `ftell` falha, `errno` é definido como a contaste de manifesto `EINVAL` se a posição for inválida ou EBADF, se o número do arquivo estiver incorreto.  As constantes também são definidas em ERRNO.H.  
  
## Consulte também  
 [Funções de biblioteca](../c-language/library-functions.md)