---
title: C2785 de erro do compilador | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords: C2785
dev_langs: C++
helpviewer_keywords: C2785
ms.assetid: d8d13360-0d00-4815-8475-b49c7f0dc0f3
caps.latest.revision: "11"
author: corob-msft
ms.author: corob
manager: ghogen
ms.openlocfilehash: a545935e06d958502fb3b97cb8969f92172ca6b6
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
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