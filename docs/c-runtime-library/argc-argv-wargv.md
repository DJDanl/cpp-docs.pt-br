---
title: __argc, __argv, __wargv
description: Descreve as constantes globais da biblioteca de tempo de execução da Microsoft C __argc , __argv e __wargv .
ms.date: 11/04/2016
api_name:
- __wargv
- __argv
- __argc
api_location:
- msvcrt120.dll
api_type:
- DLLExport
topic_type:
- apiref
f1_keywords:
- __argv
- __argc
- __wargv
helpviewer_keywords:
- __argv
- __wargv
- __argc
ms.assetid: 17001b0a-04ad-4762-b3a6-c54847f02d7c
no-loc:
- __argc
- __argv
- __wargv
- main
- wmain
ms.openlocfilehash: 02c130be0d2dcb8e48d2bb5c75438c94003fc9dd
ms.sourcegitcommit: a1676bf6caae05ecd698f26ed80c08828722b237
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/29/2020
ms.locfileid: "91507595"
---
# <a name="no-loc__argc-no-loc__argv-no-loc__wargv"></a>__argc, __argv, __wargv

A variável global `__argc` é uma contagem do número de argumentos de linha de comando passados para o programa. `__argv` é um ponteiro para uma matriz de cadeias de caracteres de caractere de byte único ou de caractere multibyte que contêm os argumentos do programa; `__wargv` é um ponteiro para uma matriz de cadeias de caracteres de caractere largo que contêm os argumentos do programa. Essas variáveis globais fornecem os argumentos para `main` ou `wmain`.

## <a name="syntax"></a>Sintaxe

```C
extern int __argc;
extern char ** __argv;
extern wchar_t ** __wargv;
```

## <a name="remarks"></a>Comentários

Em um programa que usa a função `main`, `__argc` e `__argv` são inicializados na inicialização do programa com a linha de comando usada para iniciar o programa. A linha de comando é analisada em argumentos individuais, e os curingas são expandidos. A contagem de argumentos é atribuída ao `__argc` e as cadeias de caracteres de argumento são alocadas no heap, e um ponteiro para a matriz de argumentos é atribuído ao `__argv`. Em um programa compilado para usar caracteres largos e uma função `wmain`, os argumentos são analisados e os curingas são expandidos como cadeias de caracteres de caractere largo, e um ponteiro para a matriz de cadeias de caracteres de argumento é atribuído ao `__wargv`.

No caso do código portátil, recomendamos usar os argumentos passados para `main` a fim de obter os argumentos de linha de comando no programa.

### <a name="generic-text-routine-mappings"></a>Mapeamentos de rotina de texto genérico

|Rotina Tchar.h|_UNICODE não definido|_UNICODE definido|
|---------------------|---------------------------|-----------------------|
|`__targv`|`__argv`|`__wargv`|

## <a name="requirements"></a>Requisitos

|Variável global|Cabeçalho necessário|
|---------------------|---------------------|
|`__argc`, `__argv`, `__wargv`|\<stdlib.h>, \<cstdlib> (C++)|

`__argc`, `__argv` e `__wargv` são extensões da Microsoft. Para obter informações sobre compatibilidade, consulte [Compatibilidade](../c-runtime-library/compatibility.md).

## <a name="see-also"></a>Consulte também

[Variáveis globais](../c-runtime-library/global-variables.md)\
[main argumentos de linha de comando e de função (C++)](../cpp/main-function-command-line-args.md)\
[Usando wmain em vez de main](../cpp/main-function-command-line-args.md)
