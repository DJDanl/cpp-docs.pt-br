---
title: "Compilador (nível 1) de aviso C4002 | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
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
ms.translationtype: MT
ms.sourcegitcommit: 35b46e23aeb5f4dbfd2a0dd44b906389dd5bfc88
ms.openlocfilehash: 1bb1e3512074b2767977367b30ac5d01dc5758b0
ms.contentlocale: pt-br
ms.lasthandoff: 10/10/2017

---
# <a name="compiler-warning-level-1-c4002"></a>Compilador C4002 de aviso (nível 1)
Muitos parâmetros reais para 'Identificador de macro'  
  
 O número de parâmetros reais da macro excede o número de parâmetros formais na definição de macro. A coleta de pré-processador os parâmetros extras mas ignora durante a expansão de macro.  
  
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
  
 Esse erro também pode ser gerado como resultado do trabalho de conformidade do compilador que foi feito para o Visual Studio .NET 2003: vírgulas extras em macro não aceito.  
  
 O compilador não aceitará mais vírgulas extras em uma macro. Para o código ser válida no Visual Studio .NET 2003 e versões do Visual Studio .NET do Visual C++, remova as vírgulas extras.  
  
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
