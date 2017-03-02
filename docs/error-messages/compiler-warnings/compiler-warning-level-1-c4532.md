---
title: "Compilador aviso (nível 1) C4532 | Documentos do Microsoft"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C4532
dev_langs:
- C++
helpviewer_keywords:
- C4532
ms.assetid: 4e2a286a-d233-4106-9f65-29be1a94ca02
caps.latest.revision: 9
author: corob-msft
ms.author: corob
manager: ghogen
translation.priority.ht:
- cs-cz
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- pl-pl
- pt-br
- ru-ru
- tr-tr
- zh-cn
- zh-tw
translationtype: Machine Translation
ms.sourcegitcommit: 3168772cbb7e8127523bc2fc2da5cc9b4f59beb8
ms.openlocfilehash: 7a188878267ce6889106183fd1bf9db3533134f0
ms.lasthandoff: 02/25/2017

---
# <a name="compiler-warning-level-1-c4532"></a>Compilador C4532 de aviso (nível 1)
'continue': Finally/bloco finally de saída tem um comportamento indefinido durante a manipulação de término  
  
 O compilador encontrou uma das seguintes palavras-chave:  
  
-   [continue](../../cpp/continue-statement-cpp.md)  
  
-   [break](../../cpp/break-statement-cpp.md)  
  
-   [goto](../../cpp/goto-statement-cpp.md)  
  
 causando um salto de um [Finally](../../cpp/try-finally-statement.md) ou [finalmente](../../dotnet/finally.md) bloco durante o encerramento anormal.  
  
 Se ocorrer uma exceção, e enquanto a pilha está sendo desenrolada durante a execução de manipuladores de terminação (o `__finally` ou blocos finally), e seu código ignora uma `__finally` bloquear antes do `__finally` bloco termina, o comportamento é indefinido. Controle pode não retornar para o código de desenrolamento, para que a exceção não pode ser tratada adequadamente.  
  
 Se você deve ignorar um **Finally** bloco, verifique primeiro para encerramento anormal.  
  
 O exemplo a seguir gera C4532; Comente simplesmente as instruções de salto para resolver os avisos.  
  
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
