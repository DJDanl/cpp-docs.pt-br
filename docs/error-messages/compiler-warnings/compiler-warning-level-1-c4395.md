---
title: Compilador (nível 1) de aviso C4395 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C4395
dev_langs:
- C++
helpviewer_keywords:
- C4395
ms.assetid: 8051469a-3a39-4677-80f7-1300fbffe8ea
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 95b52322b7114a16fcd0f447ba6fd628751c250e
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33277849"
---
# <a name="compiler-warning-level-1-c4395"></a>Compilador C4395 de aviso (nível 1)
'function': função membro será invocada em uma cópia do membro de dados initonly 'member'  
  
 Uma função de membro foi chamada em um [initonly (C + + CLI)](../../dotnet/initonly-cpp-cli.md) membro de dados.  C4395 avisa que o **initonly** membro de dados não pode ser modificado pela função.  
  
 O exemplo a seguir gera C4395:  
  
```  
// C4395.cpp  
// compile with: /W1 /clr  
public value class V {  
public:  
   V(int data) : m_data(data) {}  
  
   void Mutate() {  
      System::Console::WriteLine("Enter Mutate: m_data = {0}", m_data);  
      m_data *= 2;  
      System::Console::WriteLine("Leave Mutate: m_data = {0}", m_data);  
   }  
  
   int m_data;  
};  
  
public ref class R {  
public:  
   static void f() {  
      System::Console::WriteLine("v.m_data = {0}", v.m_data);  
      v.Mutate();   // C4395  
      System::Console::WriteLine("v.m_data = {0}", v.m_data);  
   }  
  
private:  
   initonly static V v = V(4);  
};  
  
int main() {  
   R::f();  
}  
```