---
title: "Definindo uma macro NMAKE | Microsoft Docs"
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
helpviewer_keywords: 
  - "definindo macros NMAKE"
  - "Macros , NMAKE"
  - "macros NMAKE, definindo"
ms.assetid: 45aae451-9d33-4a3d-8799-2e0cae17070d
caps.latest.revision: 8
caps.handback.revision: 8
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Definindo uma macro NMAKE
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

## Sintaxe  
  
```  
  
macroname=string  
```  
  
## Comentários  
 *O macroname* é uma combinação de letras, abreviação de dígitos, e sublinhados \(\_\) até 1.024 caracteres, e diferencia maiúsculas e minúsculas.  *O macroname* pode conter uma macro invocado.  Se *o macroname* completamente consiste em uma macro chamado, a macro que está sendo invocado não pode ser nulo ou indefinido.  
  
 `string` pode ser qualquer sequência de zero ou mais caracteres.  Uma cadeia de caracteres nula contém os caracteres ou apenas espaços ou guias zero.  `string` pode conter uma invocação macro.  
  
## Que você deseja saber mais?  
 [Caracteres especiais em macros](../build/special-characters-in-macros.md)  
  
 [Macros nulos e indefinidos](../build/null-and-undefined-macros.md)  
  
 [Onde definir macros](../Topic/Where%20to%20Define%20Macros.md)  
  
 [Precedência em definições macro](../build/precedence-in-macro-definitions.md)  
  
## Consulte também  
 [Macros e NMAKE](../Topic/Macros%20and%20NMAKE.md)