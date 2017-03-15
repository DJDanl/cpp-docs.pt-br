---
title: "Compilador aviso (nível 1) C4002 | Documentos do Microsoft"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-csharp
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- C4002
dev_langs:
- C++
helpviewer_keywords:
- C4002
ms.assetid: 6bda1dfe-e2e4-4771-9794-5a404c466dd5
caps.latest.revision: 8
author: corob-msft
ms.author: corob
manager: ghogen
translation.priority.ht:
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- ru-ru
- zh-cn
- zh-tw
translation.priority.mt:
- cs-cz
- pl-pl
- pt-br
- tr-tr
translationtype: Machine Translation
ms.sourcegitcommit: 3168772cbb7e8127523bc2fc2da5cc9b4f59beb8
ms.openlocfilehash: 983935ef0e48f94cee3ff08186f27502ea48a7d7
ms.lasthandoff: 02/25/2017

---
# <a name="compiler-warning-level-1-c4002"></a>Compilador C4002 de aviso (nível 1)
número excessivo de parâmetros real para 'Identificador' de macro  
  
 O número de parâmetros reais na macro excede o número de parâmetros formais na definição da macro. O pré-processador coleta os parâmetros extras mas ignora durante a expansão de macro.  
  
 C4002 podem ocorrer ao usar incorretamente [Macros Variadic](../../preprocessor/variadic-macros.md).  
  
 O exemplo a seguir gera C4002:  
  
```  
// C4002.cpp  
// compile with: /W1  
#define test(a) (a)  
  
int main() {  
   int a = 1;  
   int b = 2;  
   a = test(a,b);   // C4002  
   // try..  
   a = test(a);  
}  
```  
  
 Esse erro também pode ser gerado como resultado de trabalho de conformidade do compilador que foi feito para o Visual Studio .NET 2003: vírgulas adicionais na macro não aceito.  
  
 O compilador não aceitará mais vírgulas adicionais em uma macro. Para o código seja válido no versões do Visual Studio .NET do Visual C++ e Visual Studio .NET 2003, remova as vírgulas extras.  
  
```  
// C4002b.cpp  
// compile with: /W1  
#define F(x,y)  
int main()  
{  
   F(2,,,,,,3,,,,,,)   // C4002  
   // Try the following line instead:  
   // F(2,3)  
}  
```
