---
title: "Compilador C4937 de aviso (n&#237;vel 4) | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-csharp"
ms.tgt_pltfrm: ""
ms.topic: "article"
f1_keywords: 
  - "C4937"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "C4937"
ms.assetid: 2bb9f0e7-bbd6-4697-84de-95955e32ae29
caps.latest.revision: 7
caps.handback.revision: 7
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Compilador C4937 de aviso (n&#237;vel 4)
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

'text1' e 'text2' não podem ser diferenciados como argumentos para 'diretiva'  
  
 Devido ao modo como o compilador processa argumentos para diretivas, os nomes que tenham significado para o compilador, como palavras\-chave com várias representações de texto \(formulários simples e duplas sublinhado\), não podem ser diferenciadas.  
  
 Exemplos de cadeias de caracteres são cdecl e forceinline.  Observe, sob \/Za, que somente os formulários de sublinhado duplo são habilitados.  
  
 O exemplo a seguir gera C4937:  
  
```  
// C4937.cpp // compile with: /openmp /W4 #include "omp.h" int main() { #pragma omp critical ( __leave )   // C4937 ; // OK #pragma omp critical ( leave ) ; }  
```