---
title: Compilador aviso (nível 1) C4789
ms.date: 03/25/2019
f1_keywords:
- C4789
helpviewer_keywords:
- C4789
ms.assetid: 5800c301-5afb-4af0-85c1-ceb54d775234
ms.openlocfilehash: 36a5032098c5caabb1b050833e487fd58679a782
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62187225"
---
# <a name="compiler-warning-level-1-c4789"></a>Compilador aviso (nível 1) C4789

> buffer '*identificador*' de tamanho *N* bytes serão substituídos; *M* bytes serão escritos começando no deslocamento *L*

## <a name="remarks"></a>Comentários

**C4789** avisa sobre estouros de buffer quando funções específicas de tempo de execução (CRT) de C são usadas. Ele também pode relatar incompatibilidade de tamanho quando os parâmetros são passados ou atribuições são feitas. O aviso é possível se os tamanhos de dados são conhecidos em tempo de compilação. Esse aviso é para situações em que talvez elude detecção de incompatibilidade de tamanho de dados típico.

**C4789** avisa quando dados são copiados em um bloco de dados que tem conhecida por ser muito pequeno em tempo de compilação.

O aviso ocorre se a cópia usa a forma intrínseca de uma dessas funções de CRT:

- [strcpy](../../c-runtime-library/reference/strcpy-wcscpy-mbscpy.md)

- [memset](../../c-runtime-library/reference/memset-wmemset.md)

- [memcpy](../../c-runtime-library/reference/memcpy-wmemcpy.md), [wmemcpy](../../c-runtime-library/reference/memcpy-wmemcpy.md)

O aviso também é exibida quando você converter um parâmetro para um tipo de dados maior e, em seguida, fazer uma atribuição de cópia de uma referência de lvalue.

Visual C++ pode gerar esse aviso para um caminho de código que nunca será executado. Você pode desativar temporariamente o aviso usando `#pragma`, conforme mostrado neste exemplo:

```cpp
#pragma warning( push )
#pragma warning( disable : 4789 )
// unused code that generates compiler warning C4789`
#pragma warning( pop )
```

Essa linguagem impede que o Visual C++ gerando o aviso para esse bloco específico de código. O `#pragma warning(push)` preserva o estado existente antes de `#pragma warning(disable: 4789)` altera-la. O `#pragma warning(pop)` restaura o estado pressionado e remove os efeitos da `#pragma warning(disable:4789)`. Para obter mais informações sobre o C++ diretiva de pré-processador `#pragma`, consulte [aviso](../../preprocessor/warning.md) e [diretivas Pragma e a palavra-chave pragma](../../preprocessor/pragma-directives-and-the-pragma-keyword.md).

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

void main()
{
   int * p = (int *)&G;
   *p = 3;   // C4789 - writes an int through a pointer to short
}
```