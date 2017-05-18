---
title: "Compilador (níveis 3 e 4) de aviso C4244 | Documentos do Microsoft"
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
ms.assetid: f116bb09-c479-4b4e-a647-fe629a1383f6
caps.latest.revision: 16
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
ms.openlocfilehash: ffc1f0012d7b65ab959503c3845b1f7a04268676
ms.contentlocale: pt-br
ms.lasthandoff: 02/25/2017

---
# <a name="compiler-warning-levels-3-and-4-c4244"></a>Compilador C4244 de aviso (níveis 3 e 4)
conversão de 'conversion' de 'type1' em 'type2', possível perda de dados  
  
 Um tipo inteiro é convertido em um tipo de inteiro menor. Este é um aviso de nível&4; se *type1* é `int` e *type2* é menor do que `int`. Caso contrário, ele é um nível 3 (atribuído um valor do tipo [Int64](../../cpp/int8-int16-int32-int64.md) a uma variável do tipo `unsigned int`). Uma possível perda de dados pode ter ocorrido.  
  
 Se você receber C4244, você deve alterar seu programa usar tipos compatíveis ou adicionar alguma lógica em seu código, para garantir que o intervalo de valores possíveis sempre será compatível com os tipos que você está usando.  
  
 Também podem acionar C4244 no nível 2; consulte [C4244 de aviso do compilador (nível 2)](../../error-messages/compiler-warnings/compiler-warning-level-2-c4244.md) para obter mais informações.  
  
 A conversão pode ter um problema devido a conversões implícitas.  
  
 O exemplo a seguir gera C4244:  
  
```  
// C4244_level4.cpp  
// compile with: /W4  
int aa;  
unsigned short bb;  
int main() {  
   int b = 0, c = 0;  
   short a = b + c;   // C4244  
  
   bb += c;   // C4244  
   bb = bb + c;   // C4244  
   bb += (unsigned short)aa;   // C4244  
   bb = bb + (unsigned short)aa;   // OK  
}  
```  
  
 Para obter mais informações, consulte [conversões aritméticas usuais](../../c-language/usual-arithmetic-conversions.md).  
  
```  
// C4244_level3.cpp  
// compile with: /W3  
int main() {  
   __int64 i = 8;  
   unsigned int ii = i;   // C4244  
}  
```  
  
 Aviso C4244 pode ocorrer quando a criação de código para destinos de 64 bits que não gera o aviso ao compilar para destinos de 32 bits. Por exemplo, uma diferença entre ponteiros é uma quantidade de 32 bits em plataformas de 32 bits, mas uma quantidade de 64 bits em plataformas de 64 bits.  
  
 O exemplo a seguir gera C4244 quando compilado para destinos de 64 bits:  
  
```  
// C4244_level3_b.cpp  
// compile with: /W3   
int main() {  
   char* p1 = 0;  
   char* p2 = 0;  
   int x = p2 - p1;   // C4244  
}  
```
