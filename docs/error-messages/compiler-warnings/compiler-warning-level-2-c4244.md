---
title: Compilador (nível 2) do aviso C4244 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C4244
dev_langs:
- C++
helpviewer_keywords:
- C4244
ms.assetid: 2c19d157-21d1-42c2-a6c0-3f30f2ce3813
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: de3b2392575f069c9ffc7b661cbd647f81f9557b
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33290706"
---
# <a name="compiler-warning-level-2-c4244"></a>Compilador C4244 de aviso (nível 2)
'argumento de ': conversão de 'type1' em 'type2', possível perda de dados  
  
 Um tipo de ponto de flutuante foi convertido em um tipo inteiro.  Uma possível perda de dados pode ter ocorrido.  
  
 Se você obtiver C4244, você deve alterar seu programa para usar tipos compatíveis ou adicionar alguma lógica em seu código, para garantir que o intervalo de valores possíveis sempre será compatível com os tipos que você está usando.  
  
 C4244 também podem disparar no nível 3 e 4; consulte [C4244 de aviso do compilador (níveis 3 e 4)](../../error-messages/compiler-warnings/compiler-warning-levels-3-and-4-c4244.md) para obter mais informações.  
  
## <a name="example"></a>Exemplo  
 O exemplo a seguir gera C4244:  
  
```  
// C4244_level2.cpp  
// compile with: /W2  
  
int f(int x){ return 0; }  
int main() {  
   double x = 10.1;  
   int i = 10;  
   return (f(x));   // C4244  
   // try the following line instead  
   // return (f(i));  
}  
```