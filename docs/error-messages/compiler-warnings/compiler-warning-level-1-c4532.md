---
title: Compilador (nível 1) de aviso C4532 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C4532
dev_langs:
- C++
helpviewer_keywords:
- C4532
ms.assetid: 4e2a286a-d233-4106-9f65-29be1a94ca02
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: e37d36f565cc63c7cef9954a78e14ed60d676996
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="compiler-warning-level-1-c4532"></a>Compilador C4532 de aviso (nível 1)
'continue': salto para fora de Finally/bloco finally possui comportamento indefinido durante manipulação de encerramento  
  
 O compilador encontrou uma das seguintes palavras-chave:  
  
-   [continue](../../cpp/continue-statement-cpp.md)  
  
-   [break](../../cpp/break-statement-cpp.md)  
  
-   [goto](../../cpp/goto-statement-cpp.md)  
  
 fazendo com que um salto de um [Finally](../../cpp/try-finally-statement.md) ou [finalmente](../../dotnet/finally.md) bloco durante o encerramento anormal.  
  
 Se ocorrer uma exceção, e enquanto está sendo retornou a pilha durante a execução dos manipuladores de encerramento (o `__finally` ou blocos finally), e seu código vai fora de um `__finally` bloquear antes do `__finally` bloco termina, o comportamento será indefinido. Controle não pode retornar para o código de desenrolamento para a exceção não pode ser tratada corretamente.  
  
 Se você deve ir de um **Finally** bloquear, procure o encerramento anormal primeiro.  
  
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