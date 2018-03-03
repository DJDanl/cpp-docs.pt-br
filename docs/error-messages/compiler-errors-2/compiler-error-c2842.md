---
title: C2842 de erro do compilador | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C2842
dev_langs:
- C++
helpviewer_keywords:
- C2842
ms.assetid: 8674f08d-9f50-46ad-9229-abc6b74fa0e5
caps.latest.revision: 
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 47130ec2bf73889130d64f3ca8411bbc38dabf93
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="compiler-error-c2842"></a>C2842 de erro do compilador
'class': um gerenciado ou tipo de WinRT não pode definir seu próprio 'operator new' ou 'operator delete'  
  
 Você pode definir suas próprias * * operador novo ou **operador delete** para gerenciar a alocação de memória no heap nativo. No entanto, as classes de referência não é possível definir esses operadores porque elas só são alocadas no heap gerenciado.  

  
 Para obter mais informações, consulte [operadores definidos pelo usuário (C + + CLI)](../../dotnet/user-defined-operators-cpp-cli.md).  
  
## <a name="example"></a>Exemplo  
 O exemplo a seguir gera C2842.  
  
```  
// C2842.cpp  
// compile with: /clr /c  
ref class G {  
   void* operator new( size_t nSize );   // C2842  
};  
```  
