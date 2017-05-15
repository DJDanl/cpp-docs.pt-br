---
title: "Compilador (nível 4) de aviso C4458 | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C4458
dev_langs:
- C++
helpviewer_keywords:
- C4458
ms.assetid: 7bdaa1b1-0caf-4d68-98c4-6bdd441c23fb
caps.latest.revision: 0
author: corob-msft
ms.author: corob
manager: ghogen
translation.priority.ht:
- cs-cz
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- pl-pl
- pt-br
- ru-ru
- tr-tr
- zh-cn
- zh-tw
ms.translationtype: Machine Translation
ms.sourcegitcommit: 128bd124c2536d86c8b673b54abc4b5505526b41
ms.openlocfilehash: 07b8db673b2db27f456f0e7228695c83497d1278
ms.contentlocale: pt-br
ms.lasthandoff: 05/10/2017

---
# <a name="compiler-warning-level-4-c4458"></a>Compilador C4458 de aviso (nível 4)
  
> declaração de '*identificador*' oculta o membro da classe
  
A declaração de *identificador* no escopo local oculta a declaração de idêntico *identificador* no escopo da classe. Este aviso informa que faz referência às *identificador* neste escopo resolver para a versão declarada localmente, não a versão de membro de classe, que pode ou não ser a intenção. Para corrigir esse problema, é recomendável que você fornecer nomes de variáveis locais que não estão em conflito com nomes de membros de classe.  
    
## <a name="example"></a>Exemplo
  
O exemplo a seguir gera C4458 porque o parâmetro `x` e a variável local `y` na `member_fn` têm os mesmos nomes de membros de dados na classe. Para corrigir esse problema, use nomes diferentes para os parâmetros e variáveis locais.  
  
```cpp  
// C4458_hide.cpp
// compile with: cl /W4 /c C4458_hide.cpp

struct S {
    int x;
    float y;
    void member_fn(long x) {   // C4458
        double y;  // C4458
        y = x;  
        // To fix this issue, change the parameter name x
        // and local name y to something that does not 
        // conflict with the data member names.
    }
} s;
```  

