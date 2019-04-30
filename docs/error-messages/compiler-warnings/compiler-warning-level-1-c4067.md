---
title: Compilador aviso (nível 1) C4067
ms.date: 11/04/2016
f1_keywords:
- C4067
helpviewer_keywords:
- C4067
ms.assetid: 1d10353e-8cd5-4b01-9184-a06189b965a4
ms.openlocfilehash: 012866e328433ec9511782c26a39265481ff4940
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62386506"
---
# <a name="compiler-warning-level-1-c4067"></a>Compilador aviso (nível 1) C4067

> tokens inesperados após diretiva de pré-processador - esperado um newline

## <a name="remarks"></a>Comentários

O compilador encontrada e ignorada caracteres extras após uma diretiva de pré-processador. Isso pode ser causado por qualquer caractere inesperado, embora uma causa comum é um ponto e vírgula isolado após a diretiva. Comentários não causam esse aviso. O **/Za** habilita a opção de compilador esse aviso para diretivas de pré-processador mais que a configuração padrão.

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

Para resolver este aviso, exclua os caracteres isolados ou movê-los para um bloco de comentário. Determinados avisos C4067 podem ser desabilitados, removendo o **/Za** opção de compilador.

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