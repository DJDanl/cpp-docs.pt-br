---
title: "Compilador (nível 4) de aviso C4457 | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords: C4457
dev_langs: C++
helpviewer_keywords: C4457
ms.assetid: 02fd149a-917d-4f67-97a6-eb714572271f
caps.latest.revision: "0"
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 77965ba08b311768b54788692d3f5b7fa724f5b8
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
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
