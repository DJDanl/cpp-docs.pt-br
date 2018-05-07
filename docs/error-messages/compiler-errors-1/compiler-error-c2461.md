---
title: C2461 de erro do compilador | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C2461
dev_langs:
- C++
helpviewer_keywords:
- C2461
ms.assetid: e64ba651-f441-4fdb-b5cb-4209bbbe4db4
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 47aee3122dad3e875cf58d5a41bcadda297e1463
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="compiler-error-c2461"></a>C2461 de erro do compilador
  
> '*classe*': parâmetros formais faltando na sintaxe do construtor  
  
 O construtor para a classe não especifica nenhum parâmetro formal. A declaração de um construtor deve especificar uma lista de parâmetros formais. A lista pode estar vazia.  
  
Para corrigir esse problema, adicione um par de parênteses após a declaração de *classe*:: **classe*.  
  
## <a name="example"></a>Exemplo  
  
O exemplo a seguir mostra como corrigir C2461:  
  
```cpp  
// C2461.cpp  
// compile with: /c  
class C {  
   C::C;     // C2461  
   C::C();   // OK  
};  
```