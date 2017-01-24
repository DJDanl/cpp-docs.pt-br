---
title: "Erro do Compilador C2001 | Microsoft Docs"
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
  - "C2001"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "C2001"
ms.assetid: 0c3a7821-d8e5-4398-ab5a-4116d46e8dda
caps.latest.revision: 8
caps.handback.revision: 8
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Erro do Compilador C2001
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

nova linha na constante  
  
 Uma constante de cadeia de caracteres não pode ser retomada em uma segunda linha a menos que você faça o seguinte:  
  
-   Termine a primeira linha com uma barra invertida.  
  
-   Feche a cadeia de caracteres na primeira linha com aspas duplas e abra a cadeia de caracteres na próxima linha com outra aspa dupla.  
  
 Encerrar a primeira linha com \\ n não é suficiente.  
  
## Exemplo  
 O seguinte exemplo gera C2001:  
  
```  
// C2001.cpp  
// C2001 expected  
#include <stdio.h>  
  
int main()  
{  
    printf_s("Hello,  
             world");  
    printf_s("Hello,\n  
             world");  
}  
```  
  
## Exemplo  
 Os espaços no início da linha seguinte depois que um caractere de linha acompanhamento é incluído na constante de cadeia de caracteres.  Nenhum dos exemplos citados acima inserir um caractere de nova linha na constante de cadeia de caracteres.  Você pode inserir um caractere de nova linha como mostrado a seguir:  
  
```  
// C2001b.cpp  
#include <stdio.h>  
  
int main()  
{  
    printf_s("Hello,\n\  
             world");  
  
    printf_s("Hello,\  
             \nworld");  
  
    printf_s("Hello,\n"  
             "world");  
  
    printf_s("Hello,"  
             "\nworld");  
  
    printf_s("Hello,"  
             " world");  
  
    printf_s("Hello,\  
             world");  
}  
```