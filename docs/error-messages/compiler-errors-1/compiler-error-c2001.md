---
title: Erro do compilador C2001
ms.date: 11/04/2016
f1_keywords:
- C2001
helpviewer_keywords:
- C2001
ms.assetid: 0c3a7821-d8e5-4398-ab5a-4116d46e8dda
ms.openlocfilehash: 03b54fe2373063c8c0f9905da93822928392998d
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50596359"
---
# <a name="compiler-error-c2001"></a>Erro do compilador C2001

Newline em constante

Uma constante de cadeia de caracteres não pode ser continuada em uma segunda linha, a menos que você faça o seguinte:

- Finalizar a primeira linha com uma barra invertida.

- Feche a cadeia de caracteres na primeira linha com uma marca de aspas duplas e abra a cadeia de caracteres na próxima linha com outra aspa dupla.

Terminando a primeira linha com \n não é suficiente.

## <a name="example"></a>Exemplo

O exemplo a seguir gera C2001:

```
// C2001.cpp
// C2001 expected
#include <stdio.h>

int main()
{
    printf_s("Hello,
             world");
    printf_s("Hello,\n
             world");
}
```

## <a name="example"></a>Exemplo

Espaços no início da próxima linha depois de um caractere de continuação de linha são incluídos na constante de cadeia de caracteres. Nenhum dos exemplos mostrados acima inserir um caractere de nova linha em constante de cadeia de caracteres. Você pode inserir um caractere de nova linha, conforme mostrado aqui:

```
// C2001b.cpp
#include <stdio.h>

int main()
{
    printf_s("Hello,\n\
             world");

    printf_s("Hello,\
             \nworld");

    printf_s("Hello,\n"
             "world");

    printf_s("Hello,"
             "\nworld");

    printf_s("Hello,"
             " world");

    printf_s("Hello,\
             world");
}
```