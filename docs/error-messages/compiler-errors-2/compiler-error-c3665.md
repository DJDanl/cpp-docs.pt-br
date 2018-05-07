---
title: C3665 de erro do compilador | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C3665
dev_langs:
- C++
helpviewer_keywords:
- C3665
ms.assetid: 893bb47e-8de1-43aa-af7d-fa47ad149ee9
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: e55be277f5016be2440987864e67dfc54f4cd094
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="compiler-error-c3665"></a>C3665 de erro do compilador
'destruidor': especificador 'palavra-chave' não é permitido em um destruidor/finalizador de substituição  
  
 Uma palavra-chave que não é permitido em um destruidor ou finalizador foi usada.  
  
 Por exemplo, um novo slot não pode ser solicitado em um destruidor ou finalizador.  Para obter mais informações, consulte [substituições explícitas](../../windows/explicit-overrides-cpp-component-extensions.md) e [destruidores e finalizadores](../../dotnet/how-to-define-and-consume-classes-and-structs-cpp-cli.md#BKMK_Destructors_and_finalizers).  
  
 O exemplo a seguir gera C3665:  
  
```  
// C3665.cpp  
// compile with: /clr  
public ref struct R {  
   virtual ~R() { }  
   virtual void a() { }  
};  
  
public ref struct S : R {  
   virtual ~S() new {}   // C3665  
   virtual void a() new {}   // OK  
};  
```