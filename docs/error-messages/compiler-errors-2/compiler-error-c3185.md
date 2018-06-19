---
title: C3185 de erro do compilador | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C3185
dev_langs:
- C++
helpviewer_keywords:
- C3185
ms.assetid: 5bf96279-043c-4981-9d02-b4550071b192
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: ce6eea7c9a40f9dd38bf6892995eaa52ac540de7
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33256180"
---
# <a name="compiler-error-c3185"></a>C3185 de erro do compilador
'typeid' usado na gerenciados ou tipo de WinRT 'type', use 'operator' em vez disso  
  
 Não é possível aplicar o [typeid](../../cpp/typeid-operator.md) operador a ser gerenciada ou WinRT tipo; use [typeid](../../windows/typeid-cpp-component-extensions.md) em vez disso.  
  
 O exemplo a seguir gera C3185 e mostra como corrigi-lo:  
  
```  
// C3185a.cpp  
// compile with: /clr  
ref class Base {};  
ref class Derived : public Base {};  
  
int main() {  
   Derived ^ pd = gcnew Derived;  
   Base ^pb = pd;  
   const type_info & t1 = typeid(pb);   // C3185  
   System::Type ^ MyType = Base::typeid;   // OK  
};  
```  
