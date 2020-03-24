---
title: Aviso do compilador (nível 1) C4067
ms.date: 11/04/2016
f1_keywords:
- C4067
helpviewer_keywords:
- C4067
ms.assetid: 1d10353e-8cd5-4b01-9184-a06189b965a4
ms.openlocfilehash: 8bdd16f5c3182e4217e195475bdb4a9a0f60fa6f
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80164112"
---
# <a name="compiler-warning-level-1-c4067"></a>Aviso do compilador (nível 1) C4067

> tokens inesperados após diretiva de pré-processador-esperado uma nova linha

## <a name="remarks"></a>Comentários

O compilador encontrou e ignorou caracteres extras após uma diretiva de pré-processador. Isso pode ser causado por qualquer caractere inesperado, embora uma causa comum seja um ponto-e-vírgula perdido após a diretiva. Os comentários não causam esse aviso. A opção de compilador **/za** habilita esse aviso para mais diretivas de pré-processador do que a configuração padrão.

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

Para resolver esse aviso, exclua os caracteres isolados ou mova-os para um bloco de comentário. Determinados avisos do C4067 podem ser desabilitados removendo a opção de compilador **/za** .

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
