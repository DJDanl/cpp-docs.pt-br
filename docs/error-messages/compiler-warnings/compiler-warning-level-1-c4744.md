---
title: "Aviso C4744 (compilador) (n&#237;vel 1) | Microsoft Docs"
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
  - "C4744"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "C4744"
ms.assetid: f2a7d0b5-afd5-4926-abc3-cfbd367e3ff5
caps.latest.revision: 8
caps.handback.revision: 8
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Aviso C4744 (compilador) (n&#237;vel 1)
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

“var” tem diferente digitar “file1” e “file2”: tipo “\- 1 " e “tipo 2 "  
  
 Uma variável externo referenciado ou definida em arquivos tem dois tipos diferentes nesses arquivos.  Para resolver, faça as definições do mesmo tipo, ou alterar o nome de variável em um dos arquivos.  
  
 C4744 é emitido somente quando os arquivos são criados com a \/GL.  Para obter mais informações, consulte [\/GL \(otimização de todo o programa\)](../../build/reference/gl-whole-program-optimization.md).  
  
> [!NOTE]
>  C4744 normalmente ocorre em arquivos de C \(não C\+\+\), como em C\+\+ um nome de variável é decorado com informações de tipo.  Quando o exemplo a seguir \(\) é compilado como C\+\+, você obterá o erro LNK2019 do vinculador.  
  
## Exemplo  
 Este exemplo contém a primeira definição.  
  
```  
// C4744.c  
// compile with: /c /GL  
int global;  
```  
  
## Exemplo  
 O exemplo a seguir produz C4744.  
  
```  
// C4744b.c  
// compile with: C4744.c /GL /W1  
// C4744 expected  
#include <stdio.h>  
  
extern unsigned global;  
  
main()   
{  
    printf_s("%d\n", global);  
}  
```