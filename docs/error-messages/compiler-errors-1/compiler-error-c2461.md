---
title: C2461 de erro do compilador | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords: C2461
dev_langs: C++
helpviewer_keywords: C2461
ms.assetid: e64ba651-f441-4fdb-b5cb-4209bbbe4db4
caps.latest.revision: "8"
author: corob-msft
ms.author: corob
manager: ghogen
ms.openlocfilehash: 18413443abb074d16c0d813de660555f8ba2b4c4
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
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