---
title: Erro do compilador C2001
ms.date: 11/04/2016
f1_keywords:
- C2001
helpviewer_keywords:
- C2001
ms.assetid: 0c3a7821-d8e5-4398-ab5a-4116d46e8dda
ms.openlocfilehash: 6b40a3bd186b5c45a0ea5163f433635ab1e7b07f
ms.sourcegitcommit: 72161bcd21d1ad9cc3f12261aa84a5b026884afa
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/17/2020
ms.locfileid: "90743484"
---
# <a name="compiler-error-c2001"></a>Erro do compilador C2001

nova linha em constante

Uma constante de cadeia de caracteres não pode continuar em uma segunda linha, a menos que você faça o seguinte:

- Terminar a primeira linha com uma barra invertida.

- Feche a cadeia de caracteres na primeira linha com aspas duplas e abra a cadeia de caracteres na linha seguinte com uma outra aspa dupla.

O encerramento da primeira linha com \n não é suficiente.

## <a name="examples"></a>Exemplos

O exemplo a seguir gera C2001:

```cpp
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

Espaços no início da próxima linha após um caractere de continuação de linha são incluídos na constante de cadeia de caracteres. Nenhum dos exemplos mostrados acima insere um caractere de nova linha na constante de cadeia de caracteres. Você pode inserir um caractere de nova linha como mostrado aqui:

```cpp
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
