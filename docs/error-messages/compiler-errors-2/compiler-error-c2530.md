---
title: C2530 de erro do compilador | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C2530
dev_langs:
- C++
helpviewer_keywords:
- C2530
ms.assetid: b790a312-48df-4a6a-9e27-be2c5f32f16c
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
ms.openlocfilehash: 7a5d6831c293f6ef25eb53cdfb6216f8142908d2
ms.contentlocale: pt-br
ms.lasthandoff: 02/25/2017

---
# <a name="compiler-error-c2530"></a>C2530 de erro do compilador
'identifier': referências devem ser inicializadas  
  
 Você deve inicializar uma referência quando ele foi declarado, a menos que ela é declarada já:  
  
-   Com a palavra-chave [extern](../../cpp/using-extern-to-specify-linkage.md).  
  
-   Como um membro de uma classe, estrutura ou união (e ele é inicializado no construtor).  
  
-   Como um parâmetro em uma definição ou declaração de função.  
  
-   Como o tipo de retorno de uma função.  
  
 O exemplo a seguir gera C2530:  
  
```  
// C2530.cpp  
int main() {  
   int i = 0;  
   int &j;   // C2530  
   int &k = i;   // OK  
}  
```
