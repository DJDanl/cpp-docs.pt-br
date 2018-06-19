---
title: C3908 de erro do compilador | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C3908
dev_langs:
- C++
helpviewer_keywords:
- C3908
ms.assetid: 3c322482-c79e-4197-a578-2ad9bc379d1a
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 3f971ec355c3f1c3772b2a0cd4059cf0a8abd630
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33275272"
---
# <a name="compiler-error-c3908"></a>C3908 de erro do compilador
nível de acesso menos restritivo do que 'em construção'  
  
 Um método de acessador de propriedade (get ou set) não pode ter acesso menos restritivo do que o acesso especificado na própria propriedade.  Da mesma forma, para métodos de acessador de evento.  
  
 Para obter mais informações, consulte [propriedade](../../windows/property-cpp-component-extensions.md) e [evento](../../windows/event-cpp-component-extensions.md).  
  
 O exemplo a seguir gera C3908:  
  
```  
// C3908.cpp  
// compile with: /clr  
ref class X {  
protected:  
   property int i {  
   public:   // C3908 property i is protected   
      int get();  
   private:  
      void set(int);   // OK more restrictive  
   };  
};  
```