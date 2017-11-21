---
title: C3908 de erro do compilador | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords: C3908
dev_langs: C++
helpviewer_keywords: C3908
ms.assetid: 3c322482-c79e-4197-a578-2ad9bc379d1a
caps.latest.revision: "8"
author: corob-msft
ms.author: corob
manager: ghogen
ms.openlocfilehash: 05b4f772c5c1acf8da9247f27fa92a947a0ffc5b
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
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