---
title: "Compilador (nível 4) de aviso C4456 | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C4456
dev_langs:
- C++
helpviewer_keywords:
- C4456
ms.assetid: 5ab39fc1-0e19-461b-842b-4da80560b044
caps.latest.revision: 
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 9e298f092f546c589606be42b6e7b9faed15ddd4
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
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
