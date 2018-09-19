---
title: Erro do compilador C2001 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C2001
dev_langs:
- C++
helpviewer_keywords:
- C2001
ms.assetid: 0c3a7821-d8e5-4398-ab5a-4116d46e8dda
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 71048a706678e4d9e6906972ebf148748927e829
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46088236"
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