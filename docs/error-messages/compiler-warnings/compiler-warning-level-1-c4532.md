---
title: "Aviso do compilador (n&#237;vel 1) C4532 | Microsoft Docs"
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
  - "C4532"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "C4532"
ms.assetid: 4e2a286a-d233-4106-9f65-29be1a94ca02
caps.latest.revision: 9
caps.handback.revision: 9
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Aviso do compilador (n&#237;vel 1) C4532
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

“acompanhamento”: ignore do bloco de \_\_finally\/finally tem comportamento indefinido durante a manipulação de término  
  
 O compilador encontrou uma das seguintes palavras\-chave:  
  
-   [continue](../../cpp/continue-statement-cpp.md)  
  
-   [break](../../cpp/break-statement-cpp.md)  
  
-   [goto](../../cpp/goto-statement-cpp.md)  
  
 causando ignorar de um bloco de [\_\_finally](../../cpp/try-finally-statement.md) ou de [finalmente](../../dotnet/finally.md) durante o encerramento anormal.  
  
 Se ocorrer uma exceção, e quando a pilha é distribuída depois durante a execução de manipuladores de término \( `__finally` ou finalmente os blocos\), e seu código ignora de um bloco de `__finally` antes das extremidades do bloco de `__finally` , o comportamento será indefinido.  O controle não pode retornar para o código de desenrolamento, a exceção não pode ser tratado adequadamente.  
  
 Se você deverá ignorar de um bloco de **\_\_finally** , verifique se há o encerramento anormal primeiro.  
  
 O exemplo a seguir gerenciar C4532; comentam somente das instruções de salto para resolver os avisos.  
  
```  
// C4532.cpp  
// compile with: /W1  
// C4532 expected  
int main() {  
   int i;  
   for (i = 0; i < 10; i++) {  
      __try {  
      } __finally {  
         // Delete the following line to resolve.  
         continue;  
      }  
  
      __try {  
      } __finally {  
         // Delete the following line to resolve.  
         break;  
      }  
   }  
}  
```