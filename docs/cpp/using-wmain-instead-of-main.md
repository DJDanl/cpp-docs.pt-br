---
title: Usando wmain em vez main
ms.date: 11/04/2016
f1_keywords:
- wmain
helpviewer_keywords:
- main function, vs. wmain
- wmain function
ms.assetid: 7abb1257-b85c-413a-b913-d45b1582a71d
ms.openlocfilehash: f47d7219a54b197ec59f109cf08879774b48e6f7
ms.sourcegitcommit: a6d63c07ab9ec251c48bc003ab2933cf01263f19
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/05/2019
ms.locfileid: "74857210"
---
# <a name="using-wmain-instead-of-main"></a>Usando wmain em vez main

**Seção específica da Microsoft**

No modelo de programação Unicode, você pode definir uma versão de caractere largo da função `main`. Use **wmain** em vez de `main` se você quiser escrever código portátil que obedeça à especificação Unicode.

Declare parâmetros formais para **wmain** usando um formato semelhante para `main`. Em seguida, pode passar argumentos de caractere largo e, opcionalmente, um ponteiro de ambiente de caractere largo para o programa. Os parâmetros *argv* e *envp* para **wmain** são do tipo `wchar_t*`.

Se o seu programa usar uma função `main`, o ambiente de caracteres multibyte será criado pelo sistema operacional na inicialização do programa. Uma cópia de caractere largo do ambiente é criada somente quando necessário (por exemplo, por uma chamada para as funções [_wgetenv](../c-runtime-library/reference/getenv-wgetenv.md) ou [_wputenv](../c-runtime-library/reference/putenv-wputenv.md) ). Na primeira chamada para `_wputenv`, ou na primeira chamada para `_wgetenv` se um ambiente MBCS já existir, um ambiente correspondente de cadeia de caracteres largos será criado. Em seguida, a variável global `_wenviron`, uma versão de caractere largo da variável global `_environ`, apontará para esse ambiente. Nesse momento, duas cópias do ambiente (MBCS e Unicode) existirão simultaneamente e serão mantidas pelo sistema operacional durante toda a vida do programa.

Da mesma forma, se o seu programa usa uma função **wmain** , um ambiente MBCS (ASCII) é criado na primeira chamada para `_putenv` ou `getenv`e é apontado pela variável global `_environ`.

Para obter mais informações sobre o ambiente MBCS, consulte [conjuntos de caracteres de byte único e multibyte](../c-runtime-library/single-byte-and-multibyte-character-sets.md) na *referência da biblioteca de tempo de execução.*

**Fim da seção específica da Microsoft**

## <a name="see-also"></a>Consulte também

[main: inicialização do programa](../cpp/main-program-startup.md)