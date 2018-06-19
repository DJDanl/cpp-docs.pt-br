---
title: Compilador (nível 4) de aviso C4456 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C4456
dev_langs:
- C++
helpviewer_keywords:
- C4456
ms.assetid: 5ab39fc1-0e19-461b-842b-4da80560b044
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 2ca4af4e7353595dc687b77fa87acf70861bcb6f
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33295906"
---
# <a name="compiler-warning-level-4-c4456"></a>Compilador C4456 de aviso (nível 4)
  
> declaração de '*identificador*' oculta uma declaração local anterior
  
A declaração de *identificador* no escopo local oculta a declaração da declaração local anterior do mesmo nome. Este aviso informa que faz referência às *identificador* no escopo local resolver para a versão declarada localmente, não o local anterior, que pode ou não ser a intenção. Para corrigir esse problema, é recomendável que você fornecer nomes de variáveis locais que não estão em conflito com outros nomes de locais.  
    
## <a name="example"></a>Exemplo
  
O exemplo a seguir gera C4456 porque a variável de controle de loop `int x` e a variável local `double x` na `member_fn` têm os mesmos nomes. Para corrigir esse problema, use nomes diferentes para as variáveis locais.  
  
```cpp  
// C4456_hide.cpp
// compile with: cl /W4 /c C4456_hide.cpp

struct S {
    void member_fn(unsigned u) {
        double x = 0;
        for (int x = 0; x < 10; ++x) {  // C4456
            u += x; // uses local int x
        } 
        x += u; // uses local double x
    }
} s;
```  
