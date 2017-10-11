---
title: C2144 de erro do compilador | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C2144
dev_langs:
- C++
helpviewer_keywords:
- C2144
ms.assetid: 49f3959b-324f-4c06-9588-c0ecef5dc5b3
caps.latest.revision: 16
author: corob-msft
ms.author: corob
manager: ghogen
ms.translationtype: MT
ms.sourcegitcommit: 35b46e23aeb5f4dbfd2a0dd44b906389dd5bfc88
ms.openlocfilehash: 0f541465009dcc137b8853351d10ceb9d5db4d05
ms.contentlocale: pt-br
ms.lasthandoff: 10/09/2017

---
# <a name="compiler-error-c2144"></a>C2144 de erro do compilador
Erro de sintaxe: 'type' deve ser precedido por 'token'  
  
 O compilador esperado `token` e encontrado `type` em vez disso.  
  
 Esse erro pode ser causado por uma chave de fechamento ausente, parêntese direito ou ponto e vírgula.  
  
 C2144 também pode ocorrer ao tentar criar uma macro de uma palavra-chave CLR que contém um caractere de espaço em branco.  
  
 Você também pode ver C2144 se você estiver tentando encaminhamento de tipos. Consulte [encaminhamento de tipo (C + + CLI)](../../windows/type-forwarding-cpp-cli.md) para obter mais informações.  
  
## <a name="example"></a>Exemplo  
 O exemplo a seguir gera C2144.  
  
```  
// C2144.cpp  
// compile with: /clr /c  
#define REF ref  
REF struct MyStruct0;   // C2144  
  
// OK  
#define REF1 ref struct  
REF1 MyStruct1;  
```  
  
## <a name="example"></a>Exemplo  
 O exemplo a seguir gera C2144.  
  
```  
// C2144_2.cpp  
// compile with: /clr /c  
ref struct X {  
  
   property double MultiDimProp[,,] {   // C2144  
   // try the following line instead  
   // property double MultiDimProp[int , int, int] {  
      double get(int, int, int) { return 1; }  
      void set(int i, int j, int k, double l) {}  
   }  
  
   property double MultiDimProp2[] {   // C2144  
   // try the following line instead  
   // property double MultiDimProp2[int] {  
      double get(int) { return 1; }  
      void set(int i, double l) {}  
   }  
};  
```
