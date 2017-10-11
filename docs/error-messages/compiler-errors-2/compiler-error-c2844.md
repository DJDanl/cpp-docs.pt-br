---
title: C2844 de erro do compilador | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C2844
dev_langs:
- C++
helpviewer_keywords:
- C2844
ms.assetid: dcaf4cd2-21b0-4280-ae42-0a706c524d83
caps.latest.revision: 9
author: corob-msft
ms.author: corob
manager: ghogen
ms.translationtype: MT
ms.sourcegitcommit: 35b46e23aeb5f4dbfd2a0dd44b906389dd5bfc88
ms.openlocfilehash: 45e0a7eb7a8846d90cc8e0743f5484ba1b58208a
ms.contentlocale: pt-br
ms.lasthandoff: 10/10/2017

---
# <a name="compiler-error-c2844"></a>C2844 de erro do compilador
'member': não pode ser um membro de interface 'interface'  
  
 Um [classe de interface](../../windows/interface-class-cpp-component-extensions.md) não pode conter um membro de dados, a menos que também é uma propriedade.  
  
 Algo diferente de uma propriedade ou função de membro não é permitido em uma interface. Além disso, operadores de construtores e destruidores não são permitidos.  
  
 O exemplo a seguir gera C2844:  
  
```  
// C2844a.cpp  
// compile with: /clr /c  
public interface class IFace {  
   int i;   // C2844  
   // try the following line instead  
   // property int Size;  
};  
```  

