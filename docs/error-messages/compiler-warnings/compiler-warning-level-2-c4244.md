---
title: "Compilador aviso (nível 2) C4244 | Documentos do Microsoft"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C4244
dev_langs:
- C++
helpviewer_keywords:
- C4244
ms.assetid: 2c19d157-21d1-42c2-a6c0-3f30f2ce3813
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
ms.translationtype: Machine Translation
ms.sourcegitcommit: 3168772cbb7e8127523bc2fc2da5cc9b4f59beb8
ms.openlocfilehash: 4f77df52e0b3fd4fd96fb94bc982e08904abb06e
ms.contentlocale: pt-br
ms.lasthandoff: 02/25/2017

---
# <a name="compiler-warning-level-2-c4244"></a>Compilador C4244 de aviso (nível 2)
'argumento de ': conversão de 'type1' em 'type2', possível perda de dados  
  
 Um tipo de ponto flutuante foi convertido para um tipo inteiro.  Uma possível perda de dados pode ter ocorrido.  
  
 Se você receber C4244, você deve alterar seu programa usar tipos compatíveis ou adicionar alguma lógica em seu código, para garantir que o intervalo de valores possíveis sempre será compatível com os tipos que você está usando.  
  
 C4244 também pode ser acionado no nível 3 e 4; consulte [C4244 de aviso do compilador (níveis 3 e 4)](../../error-messages/compiler-warnings/compiler-warning-levels-3-and-4-c4244.md) para obter mais informações.  
  
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
