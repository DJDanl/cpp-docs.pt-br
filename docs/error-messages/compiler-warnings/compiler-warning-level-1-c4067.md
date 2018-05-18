---
title: Compilador (nível 1) de aviso C4067 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C4067
dev_langs:
- C++
helpviewer_keywords:
- C4067
ms.assetid: 1d10353e-8cd5-4b01-9184-a06189b965a4
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 2ee6b48327e8754f9388e0df8f43009a5be70c97
ms.sourcegitcommit: 19a108b4b30e93a9ad5394844c798490cb3e2945
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/17/2018
---
# <a name="compiler-warning-level-1-c4067"></a>Compilador C4067 de aviso (nível 1)

> tokens inesperados após diretiva de pré-processador - esperado um newline

## <a name="remarks"></a>Comentários

O compilador encontrada e ignorada caracteres extras após uma diretiva de pré-processador. Isso pode ser causado por qualquer caractere inesperado, embora uma causa comum é um ponto e vírgula perdido após a diretiva. Comentários não causam esse aviso. O **/Za** habilita a opção de compilador esse aviso para diretivas de pré-processador mais que a configuração padrão.

## <a name="example"></a>Exemplo

```cpp
// C4067a.cpp
// compile with: cl /EHsc /DX /W1 /Za C4067a.cpp
#include <iostream>
#include <string> s     // C4067
#if defined(X);         // C4067
std::string s{"X is defined"};
#else
std::string s{"X is not defined"};
#endif;                 // C4067 only under /Za
int main()
{
    std::cout << s << std::endl;
}
```

Para resolver este aviso, exclua os caracteres isolados ou movê-los em um bloco de comentário. Determinados avisos C4067 podem ser desabilitados, removendo o **/Za** opção de compilador.

```cpp
// C4067b.cpp
// compile with: cl /EHsc /DX /W1 C4067b.cpp
#include <iostream>
#include <string>
#if defined(X)
std::string s{"X is defined"};
#else
std::string s{"X is not defined"};
#endif
int main()
{
    std::cout << s << std::endl;
}
```