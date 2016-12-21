---
title: "Aviso do compilador (n&#237;vel 4) C4211 | Microsoft Docs"
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
  - "C4211"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "C4211"
ms.assetid: 3eea3455-6faa-4cdb-8730-73db7026bd1f
caps.latest.revision: 7
caps.handback.revision: 7
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Aviso do compilador (n&#237;vel 4) C4211
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

extensão não padrão usada: extern redefinido em estático  
  
 Com as extensões padrão da Microsoft \(\/Ze\), você pode redefinir um identificador de `extern` como **static**.  
  
## Exemplo  
  
```  
// C4211.c  
// compile with: /W4  
extern int i;  
static int i;   // C4211  
  
int main()  
{  
}  
```  
  
 Tais redefine não são válidos na compatibilidade ANSI \([\/Za](../../build/reference/za-ze-disable-language-extensions.md)\).  
  
## Consulte também  
 [\(NOTINBUILD\)Static Storage\-Class Specifiers](http://msdn.microsoft.com/pt-br/3ba9289a-a412-4a17-b319-ceb2c087df48)