---
title: Compilador (nível 4) de aviso C4457 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C4457
dev_langs:
- C++
helpviewer_keywords:
- C4457
ms.assetid: 02fd149a-917d-4f67-97a6-eb714572271f
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 80eac0ade54df1626e993bfed12468b2aa34402f
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="compiler-warning-level-4-c4457"></a>Compilador C4457 de aviso (nível 4)
  
> declaração de '*identificador*' oculta um parâmetro de função
  
A declaração de *identificador* no escopo local oculta a declaração do parâmetro de função idêntico. Este aviso informa que faz referência às *identificador* no escopo local resolver para a versão declarada localmente, não o parâmetro, o que pode ou não ser a intenção. Para corrigir esse problema, recomendamos que você fornecer nomes de variáveis locais que não estão em conflito com nomes de parâmetro.  
    
## <a name="example"></a>Exemplo
  
O exemplo a seguir gera C4457 porque o parâmetro `x` e a variável local `x` na `member_fn` têm os mesmos nomes. Para corrigir esse problema, use nomes diferentes para os parâmetros e variáveis locais.  
  
```cpp  
// C4457_hide.cpp
// compile with: cl /W4 /c C4457_hide.cpp

struct S {
    void member_fn(unsigned x) {
        double a = 0;
        for (int x = 0; x < 10; ++x) {  // C4457
            a += x; // uses local x
        } 
        a += x; // uses parameter x
    }
} s;
```  
