---
title: Usando wmain em vez main
ms.date: 11/04/2016
f1_keywords:
- wmain
helpviewer_keywords:
- main function, vs. wmain
- wmain function
ms.assetid: 7abb1257-b85c-413a-b913-d45b1582a71d
ms.openlocfilehash: 8cdc986d1582d2b26f137e3147ce78bc83e9daca
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50677754"
---
# <a name="using-wmain-instead-of-main"></a>Usando wmain em vez main

## <a name="microsoft-specific"></a>Específico da Microsoft

No modelo de programação Unicode, você pode definir uma versão de caractere largo do `main` função. Use **wmain** em vez de `main` se você quiser escrever um código portátil que obedeça à especificação Unicode.

Declarar parâmetros formais para **wmain** usando um formato semelhante ao `main`. Em seguida, pode passar argumentos de caractere largo e, opcionalmente, um ponteiro de ambiente de caractere largo para o programa. O *argv* e *envp* parâmetros a serem **wmain** são do tipo `wchar_t*`.

Se seu programa usa uma `main` função, o ambiente de caractere multibyte é criado pelo sistema operacional na inicialização do programa. Uma cópia de caractere largo do ambiente é criada somente quando necessário (por exemplo, por uma chamada para o [wgetenv](../c-runtime-library/reference/getenv-wgetenv.md) ou [wputenv](../c-runtime-library/reference/putenv-wputenv.md) funções). Na primeira chamada para `_wputenv`, ou na primeira chamada para `_wgetenv` se um ambiente MBCS já existir, um ambiente correspondente de cadeia de caracteres largos será criado. Em seguida, a variável global `_wenviron`, uma versão de caractere largo da variável global `_environ`, apontará para esse ambiente. Nesse momento, duas cópias do ambiente (MBCS e Unicode) existirão simultaneamente e serão mantidas pelo sistema operacional durante toda a vida do programa.

Da mesma forma, se seu programa usa uma **wmain** função, um ambiente de MBCS (ASCII) é criado na primeira chamada para `_putenv` ou `getenv`e é indicada pela `_environ` variável global.

Para obter mais informações sobre o ambiente de MBCS, consulte [byte único e conjuntos de caracteres Multibyte](../c-runtime-library/single-byte-and-multibyte-character-sets.md) no *referência da biblioteca de tempo de execução.*

**Fim da seção específica da Microsoft**

## <a name="see-also"></a>Consulte também

[main: inicialização do programa](../cpp/main-program-startup.md)