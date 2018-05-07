---
title: C2785 de erro do compilador | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C2785
dev_langs:
- C++
helpviewer_keywords:
- C2785
ms.assetid: d8d13360-0d00-4815-8475-b49c7f0dc0f3
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: dc0ca6235e0fd4bdd22330e807464e96280ae461
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="compiler-error-c2785"></a>C2785 de erro do compilador
'declaration1' e 'declaration2' têm tipos diferentes de retorno  
  
 O tipo de retorno de especialização de modelo de função é diferente do tipo de retorno do modelo de função primária.  
  
### <a name="to-correct-this-error"></a>Para corrigir este erro  
  
1.  Verifique se todas as especializações do modelo de função para manter a consistência.  
  
## <a name="example"></a>Exemplo  
 O exemplo a seguir gera C2785:  
  
```  
// C2785.cpp  
// compile with: /c  
template<class T> void f(T);  
  
template<> int f(int); // C2785  
template<> void f(int); // OK  
```