---
title: C3450 de erro do compilador | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C3450
dev_langs:
- C++
helpviewer_keywords:
- C3450
ms.assetid: 78892cf7-0b82-4589-90d0-e06666247003
caps.latest.revision: 8
author: corob-msft
ms.author: corob
manager: ghogen
ms.translationtype: MT
ms.sourcegitcommit: 35b46e23aeb5f4dbfd2a0dd44b906389dd5bfc88
ms.openlocfilehash: 90aa45cc810f8a0d7f869484216a28ea80eaf602
ms.contentlocale: pt-br
ms.lasthandoff: 10/10/2017

---
# <a name="compiler-error-c3450"></a>C3450 de erro do compilador
'type': não é um atributo. não é possível especificar [System::AttributeUsageAttribute] ou [Windows::Foundation::Metadata::AttributeUsageAttribute]  
  
 Um atributo gerenciado definidos pelo usuário deve herdar de <xref:System.ComponentModel.AttributeCollection.%23ctor%2A>. Um atributo de tempo de execução do Windows deve ser definido na `Windows::Foundation::Metadata` namespace.  
  
 Para obter mais informações, consulte [atributos definidos pelo usuário](../../windows/user-defined-attributes-cpp-component-extensions.md).  
  
## <a name="example"></a>Exemplo  
 O exemplo a seguir gera C3450 e mostra como corrigi-lo.  
  
```  
// C3450.cpp  
// compile with: /clr  
// C3450 expected  
using namespace System;  
using namespace System::Security;  
using namespace System::Security::Permissions;  
  
public ref class MyClass {};  
  
class MyClass2 {};  
  
[attribute(AttributeTargets::All)]  
ref struct AtClass {  
   AtClass(Type ^) {}  
};  
  
[attribute(AttributeTargets::All)]  
ref struct AtClass2 {  
   AtClass2() {}  
};  
  
// Apply the AtClass and AtClass2 attributes to class B  
[AtClass(MyClass::typeid), AtClass2]     
[AttributeUsage(AttributeTargets::All)]  
// Delete the following line to resolve.  
ref class B {};  
// Uncomment the following line to resolve.  
// ref class B : Attribute {};  
```
