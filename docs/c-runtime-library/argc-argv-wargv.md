---
title: __argc, __argv, __wargv
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
ms.openlocfilehash: 59ab1f5ba52e6dc84d44e8cb5465cfa412d01895
ms.sourcegitcommit: f19474151276d47da77cdfd20df53128fdcc3ea7
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/12/2019
ms.locfileid: "70940630"
---
# <a name="__argc-__argv-__wargv"></a>__argc, __argv, __wargv

A variável global `__argc` é uma contagem do número de argumentos de linha de comando passados para o programa. `__argv` é um ponteiro para uma matriz de cadeias de caracteres de caractere de byte único ou de caractere multibyte que contêm os argumentos do programa; `__wargv` é um ponteiro para uma matriz de cadeias de caracteres de caractere largo que contêm os argumentos do programa. Essas variáveis globais fornecem os argumentos para `main` ou `wmain`.

## <a name="syntax"></a>Sintaxe

```
extern int __argc;
extern char ** __argv;
extern wchar_t ** __wargv;
```

## <a name="remarks"></a>Comentários

Em um programa que usa a função `main`, `__argc` e `__argv` são inicializados na inicialização do programa com a linha de comando usada para iniciar o programa. A linha de comando é analisada em argumentos individuais, e os curingas são expandidos. A contagem de argumentos é atribuída ao `__argc` e as cadeias de caracteres de argumento são alocadas no heap, e um ponteiro para a matriz de argumentos é atribuído ao `__argv`. Em um programa compilado para usar caracteres largos e uma função `wmain`, os argumentos são analisados e os curingas são expandidos como cadeias de caracteres de caractere largo, e um ponteiro para a matriz de cadeias de caracteres de argumento é atribuído ao `__wargv`.

No caso do código portátil, recomendamos usar os argumentos passados para `main` a fim de obter os argumentos de linha de comando no programa.

### <a name="generic-text-routine-mappings"></a>Mapeamentos da rotina de texto genérico

|Rotina Tchar.h|_UNICODE não definido|_UNICODE definido|
|---------------------|---------------------------|-----------------------|
|`__targv`|`__argv`|`__wargv`|

## <a name="requirements"></a>Requisitos

|Variável global|Cabeçalho necessário|
|---------------------|---------------------|
|`__argc`, `__argv`, `__wargv`|\<stdlib.h>, \<cstdlib> (C++)|

`__argc`, `__argv` e `__wargv` são extensões da Microsoft. Para obter informações sobre compatibilidade, consulte [Compatibilidade](../c-runtime-library/compatibility.md).

## <a name="see-also"></a>Consulte também

[Variáveis globais](../c-runtime-library/global-variables.md)<br/>
[main: inicialização de programa](../cpp/main-program-startup.md)<br/>
[Usando wmain em vez main](../cpp/using-wmain-instead-of-main.md)
