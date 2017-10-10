---
title: C3114 de erro do compilador | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C3114
dev_langs:
- C++
helpviewer_keywords:
- C3114
ms.assetid: b5d2df4f-87d0-4292-9981-25c6a6013c05
caps.latest.revision: 6
author: corob-msft
ms.author: corob
manager: ghogen
ms.translationtype: MT
ms.sourcegitcommit: 35b46e23aeb5f4dbfd2a0dd44b906389dd5bfc88
ms.openlocfilehash: e4ec82d31e26b33364a73384aae08f6adc48da02
ms.contentlocale: pt-br
ms.lasthandoff: 10/10/2017

---
# <a name="compiler-error-c3114"></a>C3114 de erro do compilador
'argumento de ': argumento de atributo nomeado não válido  
  
 Em ordem para um membro de dados de classe de atributo válido para o argumento de nome, ele não deve ser marcado `static`, `const`, ou `literal`. Se uma propriedade, a propriedade não deve ser `static` e deve ter get e definir acessadores.  
  
 Para obter mais informações, consulte [propriedade](../../windows/property-cpp-component-extensions.md) e [atributos definidos pelo usuário](../../windows/user-defined-attributes-cpp-component-extensions.md).  
  
## <a name="example"></a>Exemplo  
 O exemplo a seguir gera C3114.  
  
```  
// C3114.cpp  
// compile with: /clr /c  
public ref class A : System::Attribute {  
public:  
   static property int StaticProp {  
      int get();  
   }  
  
   property int Prop2 {  
      int get();  
      void set(int i);  
   }  
};  
  
[A(StaticProp=123)]   // C3114  
public ref class R {};  
  
[A(Prop2=123)]   // OK  
public ref class S {};  
```
