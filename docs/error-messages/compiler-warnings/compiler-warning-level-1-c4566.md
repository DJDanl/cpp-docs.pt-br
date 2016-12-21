---
title: "Aviso do compilador (n&#237;vel 1) C4566 | Microsoft Docs"
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
  - "C4566"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "C4566"
ms.assetid: 65f40730-e86f-447c-b37b-16caadcfe311
caps.latest.revision: 7
caps.handback.revision: 7
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Aviso do compilador (n&#237;vel 1) C4566
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

o caractere representado pelo universal\-caractere\- nome “char” não pode ser representada na página de código atual \(página\)  
  
 Cada caractere não Unicode pode ser representado na página de código ANSI atual.  
  
 As cadeias de caracteres estreitas \(caracteres de um byte\) são convertidas em caracteres de vários bytes enquanto as cadeias de caracteres amplas \(caracteres de dois bytes\) não são.  
  
 O seguinte exemplo gera C4566:  
  
```  
// C4566.cpp  
// compile with: /W1  
int main() {  
   char c1 = '\u03a0';   // C4566  
   char c2 = '\u0642';   // C4566  
  
   wchar_t c3 = L'\u03a0';   // OK  
   wchar_t c4 = L'\u0642';   // OK  
}  
```