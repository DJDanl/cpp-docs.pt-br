---
title: "Compilador (nível 4) de aviso C4457 | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C4457
dev_langs:
- C++
helpviewer_keywords:
- C4457
ms.assetid: 02fd149a-917d-4f67-97a6-eb714572271f
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
ms.openlocfilehash: 4977ade625e3f4af5f01364b865d2c2f41ebe80a
ms.contentlocale: pt-br
ms.lasthandoff: 05/10/2017

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

