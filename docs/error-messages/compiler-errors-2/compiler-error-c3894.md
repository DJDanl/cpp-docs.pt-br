---
title: C3894 de erro do compilador | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C3894
dev_langs:
- C++
helpviewer_keywords:
- C3894
ms.assetid: 6d5ac903-1dea-431d-8e3a-cebca4342983
caps.latest.revision: 10
author: corob-msft
ms.author: corob
manager: ghogen
ms.translationtype: MT
ms.sourcegitcommit: 35b46e23aeb5f4dbfd2a0dd44b906389dd5bfc88
ms.openlocfilehash: 46dffabb57e871e1635738434e7efb4812850379
ms.contentlocale: pt-br
ms.lasthandoff: 10/10/2017

---
# <a name="compiler-error-c3894"></a>C3894 de erro do compilador
'var': uso l-value de membro de dados estáticos initonly só é permitido no construtor da classe da classe 'class'  
  
 Estático [initonly](../../dotnet/initonly-cpp-cli.md) membros de dados só podem ser usados como valores l em seu ponto de declaração, ou em um construtor estático.  
  
 Membros de dados initonly (não estático) instância só podem ser usados como valores l em seu ponto de declaração ou em construtores de (não estático) da instância.  
  
 O exemplo a seguir gera C3894:  
  
```  
// C3894.cpp  
// compile with: /clr  
ref struct Y1 {  
   initonly static int data_var = 0;  
  
public:  
   // class constructor  
   static Y1() {  
      data_var = 99;   // OK  
      System::Console::WriteLine("in static constructor");  
   }  
  
   // not the class constructor  
   Y1(int i) {  
      data_var = i;   // C3894  
   }  
  
   static void Test() {}  
  
};  
  
int main() {  
   Y1::data_var = 88;   // C3894  
   int i = Y1::data_var;  
   Y1 ^ MyY1 = gcnew Y1(99);  
   Y1::Test();  
}  
```
