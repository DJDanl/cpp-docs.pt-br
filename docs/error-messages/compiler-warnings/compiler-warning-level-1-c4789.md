---
title: Aviso do compilador (nível 1) C4789
ms.date: 03/25/2019
f1_keywords:
- C4789
helpviewer_keywords:
- C4789
ms.assetid: 5800c301-5afb-4af0-85c1-ceb54d775234
ms.openlocfilehash: 36278615631d017db1d1c2fc4eecf8c1612892de
ms.sourcegitcommit: a930a9b47bd95599265d6ba83bb87e46ae748949
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 01/22/2020
ms.locfileid: "76518394"
---
# <a name="compiler-warning-level-1-c4789"></a>Aviso do compilador (nível 1) C4789

> o buffer '*Identifier*' do tamanho de *N* bytes será saturado; *M* bytes serão gravados começando no deslocamento *L*

## <a name="remarks"></a>Comentários

O **C4789** avisa sobre saturações de buffer quando funções CRT (tempo de execução) de C específicas são usadas. Ele também pode relatar incompatibilidades de tamanho quando os parâmetros são passados ou as atribuições são feitas. O aviso será possível se os tamanhos de dados forem conhecidos no momento da compilação. Esse aviso é para situações que podem elude a detecção de incompatibilidade de tamanho de dados típico.

O **C4789** avisa quando os dados são copiados em um bloco de dados que é conhecido como muito pequeno no momento da compilação.

O aviso ocorrerá se a cópia usar a forma intrínseca de uma dessas funções CRT:

- [strcpy](../../c-runtime-library/reference/strcpy-wcscpy-mbscpy.md)

- [memset](../../c-runtime-library/reference/memset-wmemset.md)

- [memcpy](../../c-runtime-library/reference/memcpy-wmemcpy.md), [wmemcpy](../../c-runtime-library/reference/memcpy-wmemcpy.md)

O aviso também aparece quando você converte um parâmetro para um tipo de dados maior e, em seguida, faz uma atribuição de cópia de uma referência lvalue.

O C++ visual pode gerar esse aviso para um caminho de código que nunca é executado. Você pode desabilitar temporariamente o aviso usando `#pragma`, conforme mostrado neste exemplo:

```cpp
#pragma warning( push )
#pragma warning( disable : 4789 )
// unused code that generates compiler warning C4789`
#pragma warning( pop )
```

Esse idioma impede que C++ o Visual gere o aviso para esse bloco específico de código. O `#pragma warning(push)` preserva o estado existente antes de `#pragma warning(disable: 4789)` alterá-lo. O `#pragma warning(pop)` restaura o estado enviado por push e remove os efeitos da `#pragma warning(disable:4789)`. Para obter mais informações sobre C++ a diretiva de pré-processador `#pragma`, consulte Diretivas de [aviso](../../preprocessor/warning.md) e [pragma e a palavra-chave __Pragma](../../preprocessor/pragma-directives-and-the-pragma-keyword.md).

## <a name="example"></a>Exemplo

O exemplo a seguir gera C4789.

```cpp
// C4789.cpp
// compile with: /Oi /W1 /c
#include <string.h>
#include <stdio.h>

int main()
{
    char a[20];
    strcpy(a, "0000000000000000000000000\n");   // C4789

    char buf2[20];
    memset(buf2, 'a', 21);   // C4789

    char c;
    wchar_t w = 0;
    memcpy(&c, &w, sizeof(wchar_t));
}
```

## <a name="example"></a>Exemplo

O exemplo a seguir também gera C4789.

```cpp
// C4789b.cpp
// compile with: /W1 /O2 /c
// processor: x86
short G;

int main()
{
   int * p = (int *)&G;
   *p = 3;   // C4789 - writes an int through a pointer to short
}
```
