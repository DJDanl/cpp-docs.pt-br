---
title: "Acesso incorreto a uma uni&#227;o | Microsoft Docs"
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
ms.assetid: b273d984-62a8-4003-9a87-bf0149d3f2dd
caps.latest.revision: 7
caps.handback.revision: 7
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Acesso incorreto a uma uni&#227;o
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

**ANSI 3.3.2.3** Um membro de um objeto de união é acessado usando um membro de um tipo diferente  
  
 Se uma união de dois tipos é declarada e um valor é armazenado, mas a união é acessada com o outro tipo, os resultados são não confiáveis.  
  
 Por exemplo, uma união de **float** e `int` é declarada.  Um valor **float** é armazenado, mas o programa acessa posteriormente o valor como `int`.  Nessa situação, o valor dependeria de armazenamento interno de valores **float**.  O valor inteiro não seria confiável.  
  
## Consulte também  
 [Estruturas, uniões, enumerações e campos de bit](../c-language/structures-unions-enumerations-and-bit-fields.md)