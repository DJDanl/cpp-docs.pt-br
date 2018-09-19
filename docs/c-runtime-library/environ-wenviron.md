---
title: _environ, _wenviron | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-standard-libraries
ms.topic: conceptual
f1_keywords:
- environ
- wenviron
- _wenviron
- _environ
dev_langs:
- C++
helpviewer_keywords:
- environ function
- _environ function
- _wenviron function
- process environment
- wenviron function
ms.assetid: 7e639962-6536-47cd-8095-0cbe44a56e03
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 59ec0a0279c0b43b6ffdc1e5f25616c916624be2
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46018347"
---
# <a name="environ-wenviron"></a>_environ, _wenviron

A variável `_environ` é um ponteiro para uma matriz de ponteiros para as sequências de caracteres multibyte que constituem o ambiente do processo. Essa variável global foi preterida em favor das versões funcionais mais seguras [getenv_s, _wgetenv_s](../c-runtime-library/reference/getenv-s-wgetenv-s.md) e [_putenv_s, _wputenv_s](../c-runtime-library/reference/putenv-s-wputenv-s.md), que devem ser usadas no lugar da variável global. `_environ` é declarado em Stdlib.h.

> [!IMPORTANT]
>  Esta API não pode ser usada em aplicativos executados no Tempo de Execução do Windows. Para obter mais informações, confira [Funções do CRT sem suporte em aplicativos da Plataforma Universal do Windows](../cppcx/crt-functions-not-supported-in-universal-windows-platform-apps.md).

## <a name="syntax"></a>Sintaxe

```
extern char **_environ;
```

## <a name="remarks"></a>Comentários

Em um programa que usa a `main` função `_environ` inicializados na inicialização do programa de acordo com as obtidas do ambiente do sistema operacional. O ambiente consiste em uma ou mais entradas do formulário

`ENVVARNAME` `=string`

`getenv_s`e `putenv_s` usam a variável `_environ` para acessar e modificar a tabela de ambiente. Quando `_putenv` é chamado para adicionar ou excluir configurações de ambiente, a tabela de ambiente muda de tamanho. Seu local na memória também pode mudar, dependendo dos requisitos de memória do programa. O valor de `_environ` será automaticamente ajustado.

A variável `_wenviron` declarada em Stdlib.h como:

```
extern wchar_t **_wenviron;
```

é uma versão de caractere largo de `_environ`. Em um programa que usa a `wmain` função `_wenviron` inicializados na inicialização do programa de acordo com as obtidas do ambiente do sistema operacional.

Em um programa que usa `main`, `_wenviron` é inicialmente **NULL** porque o ambiente é composto de cadeias de caracteres multibyte. Na primeira chamada para `_wgetenv` ou `_wputenv`, um ambiente de sequências de caracteres largos correspondente é criada e é apontada pelo `_wenviron`.

De forma semelhante, em um programa que use `wmain`, `_environ` é inicialmente **NULL** porque o ambiente é composto por cadeias de caracteres largos. Na primeira chamada para `_getenv` ou `_putenv`, um ambiente de cadeia de caracteres multibyte correspondente é criado e é apontado pelo `_environ`.

Quando duas cópias do ambiente (MBCS e Unicode) existirem simultaneamente em um programa, o sistema de tempo de execução deverá manter as duas cópias, fazendo com que o tempo de execução fique mais lento. Por exemplo, sempre que você chama `_putenv`, uma chamada para `_wputenv` também é executada automaticamente para que as duas cadeias de caracteres de ambiente correspondam.

> [!CAUTION]
>  Em casos raros, quando o sistema de tempo de execução mantém uma versão Unicode e uma versão multibyte do ambiente, as duas versões de ambiente podem não corresponder exatamente. Isso acontece porque, embora qualquer cadeia de caracteres multibyte exclusiva seja mapeada para uma cadeia de caracteres Unicode exclusiva, o mapeamento de uma cadeia de caracteres Unicode exclusiva para uma cadeia de caracteres multibyte não é necessariamente exclusivo. Portanto, duas cadeias de caracteres distintas do Unicode podem ser mapeadas para a mesma cadeia de caracteres multibyte.

A sondagem `_environ` em um contexto de Unicode é insignificante quando uma ligação [/MD](../build/reference/md-mt-ld-use-run-time-library.md) ou `/MDd` é usada. Para a DLL do CRT, o tipo (multibyte ou largo) do programa é desconhecido. Somente o tipo multibyte é criado porque esse é o cenário mais provável.

O pseudocódigo a seguir ilustra como isso pode acontecer.

```
int i, j;
i = _wputenv( "env_var_x=string1" );  // results in the implicit call:
                                      // putenv ("env_var_z=string1")
j = _wputenv( "env_var_y=string2" );  // also results in implicit call:
                                      // putenv("env_var_z=string2")
```

Na notação usada para este exemplo, as cadeias de caracteres não são literais de cadeia de caracteres do C; em vez disso, são espaços reservados que representam os literais de cadeia de caracteres de ambiente Unicode na chamada `_wputenv` e em cadeias de caracteres de ambiente multibyte na chamada `putenv`. Espaços reservados de caractere`x`'e'`y`' no Unicode distintos duas cadeias de caracteres de ambiente não mapeiam exclusivamente aos caracteres MBCS o atual. Em vez disso, são mapeados para alguns caracteres MBCS '`z`' que é o resultado padrão de tentativa de converter as cadeias de caracteres.

Assim, no ambiente de vários bytes, o valor de "`env_var_z`" após a primeira chamada implícita para `putenv` seria "`string1`", mas esse valor será substituído na segunda chamada implícita a `putenv`, quando o valor de "`env_var_z`" é definido como"`string2`". O ambiente de Unicode (em `_wenviron`) e o ambiente de vários bytes (em `_environ`) seria diferente, portanto, seguindo essa série de chamadas.

## <a name="see-also"></a>Consulte também

[Variáveis globais](../c-runtime-library/global-variables.md)<br/>
[getenv, _wgetenv](../c-runtime-library/reference/getenv-wgetenv.md)<br/>
[getenv_s, _wgetenv_s](../c-runtime-library/reference/getenv-s-wgetenv-s.md)<br/>
[_putenv, _wputenv](../c-runtime-library/reference/putenv-wputenv.md)<br/>
[_putenv_s, _wputenv_s](../c-runtime-library/reference/putenv-s-wputenv-s.md)