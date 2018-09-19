---
title: Compilador aviso (nível 1) C4789 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C4789
dev_langs:
- C++
helpviewer_keywords:
- C4789
ms.assetid: 5800c301-5afb-4af0-85c1-ceb54d775234
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 167bca2a4596a738813309eceb7e22751b5584b8
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46087325"
---
# <a name="compiler-warning-level-1-c4789"></a>Compilador aviso (nível 1) C4789

> buffer '*identificador*' de tamanho *N* bytes serão substituídos; *M* bytes serão escritos começando no deslocamento *L*

## <a name="remarks"></a>Comentários

Avisa sobre quando específicas funções do C Runtime (CRT) são usadas, de estouro de buffer de parâmetros são passados, e as atribuições são executadas, de modo que os tamanhos de dados são conhecidos em tempo de compilação. Esse aviso é para situações em que talvez elude detecção de incompatibilidade de tamanho de dados típico.

O aviso é exibido quando os dados, cujo tamanho é conhecido em tempo de compilação, são copiados e colocados em um bloco de dados cujo tamanho é conhecido no tempo de compilação para ser muito pequeno para os dados. A cópia deve ser feita usando o formulário intrínseco de uma das seguintes funções de CRT:

- [strcpy](../../c-runtime-library/reference/strcpy-wcscpy-mbscpy.md)

- [memset](../../c-runtime-library/reference/memset-wmemset.md)

- [memcpy](../../c-runtime-library/reference/memcpy-wmemcpy.md), [wmemcpy](../../c-runtime-library/reference/memcpy-wmemcpy.md)

O aviso também é exibida quando um parâmetro de tipo de dados é incompatível com o uso de uma conversão, e, em seguida, há a tentativa de uma atribuição de cópia de uma referência de lvalue.

Visual C++ pode gerar esse aviso para um caminho de código que nunca seja executado. Você pode desativar temporariamente o aviso usando `#pragma`, conforme mostrado neste exemplo:

```cpp
#pragma(push)
#pragma warning ( disable : 4789 )
// unused code that generates compiler warning C4789`
#pragma(pop)
```

Isso impede que o Visual C++ gera o aviso para esse bloco específico de código. O `#pragma(push)` preserva o estado existente antes de `#pragma warning(disable: 4789)` altera-la. O `#pragma(pop)` restaura o estado pressionado e remove os efeitos da `#pragma warning(disable:4789)`. Para obter mais informações sobre a diretiva de pré-processador C++ `#pragma`, consulte [aviso](../../preprocessor/warning.md) e [diretivas Pragma e a palavra-chave pragma](../../preprocessor/pragma-directives-and-the-pragma-keyword.md).

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