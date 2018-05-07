---
title: C2946 de erro do compilador | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C2946
dev_langs:
- C++
helpviewer_keywords:
- C2946
ms.assetid: c86dfbfc-7702-4f09-8a53-d205710e99c2
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 9485f424306d66514c9e919f13ff5988f8b0d1f2
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="compiler-error-c2946"></a>C2946 de erro do compilador
instanciação explícita; 'class' não é uma especialização de classe de modelo  
  
 Você não pode instanciar uma classe nontemplated explicitamente.  
  
## <a name="example"></a>Exemplo  
 O exemplo a seguir gera C2946.  
  
```  
// C2946.cpp  
class C {};  
template C;  // C2946  
int main() {}  
```