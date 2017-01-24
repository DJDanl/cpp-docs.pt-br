---
title: "Aviso do compilador (n&#237;vel 1) C4129 | Microsoft Docs"
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
  - "C4129"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "C4129"
ms.assetid: a4190c64-4bfb-48fd-8e98-52720bc0d878
caps.latest.revision: 7
caps.handback.revision: 7
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Aviso do compilador (n&#237;vel 1) C4129
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

“caractere”: sequência de escape não reconhecido de caractere  
  
 `character` que segue uma barra invertida \(\\\) em uma constante de caractere ou cadeia de caracteres não é reconhecido como uma sequência de escape válido.  A barra invertida não é ignorada e impressa.  O caractere que segue a barra invertida é impresso.  
  
 Para imprimir uma única barra invertida, especifique uma barra invertida dupla \(\\\\\).  
  
 O padrão do C\+\+, na seção discute 2.13.2 sequências de escape.  
  
 O seguinte exemplo gera C4129:  
  
```  
// C4129.cpp  
// compile with: /W1  
int main() {  
   char array1[] = "\/709";   // C4129  
   char array2[] = "\n709";   // OK  
}  
```