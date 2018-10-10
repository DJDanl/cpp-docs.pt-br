---
title: ___mb_cur_max_func, ___mb_cur_max_l_func, __p___mb_cur_max, __mb_cur_max | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-standard-libraries
ms.topic: conceptual
apiname:
- ___mb_cur_max_l_func
- __p___mb_cur_max
- ___mb_cur_max_func
- __mb_cur_max
apilocation:
- msvcr110_clr0400.dll
- msvcr110.dll
- msvcr80.dll
- msvcr100.dll
- msvcrt.dll
- msvcr90.dll
- msvcr120.dll
apitype: DLLExport
f1_keywords:
- ___mb_cur_max_func
- ___mb_cur_max_l_func
- __p___mb_cur_max
- __mb_cur_max
dev_langs:
- C++
helpviewer_keywords:
- __mb_cur_max
- ___mb_cur_max_func
- ___mb_cur_max_l_func
- __p___mb_cur_max
ms.assetid: 60d36108-1ca7-45a6-8ce7-68a91f13e3a1
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 7eb9682a648f8e302a620e3c2e0dc1631abf7945
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46068267"
---
# <a name="mbcurmaxfunc-mbcurmaxlfunc-pmbcurmax-mbcurmax"></a>___mb_cur_max_func, ___mb_cur_max_l_func, __p___mb_cur_max, __mb_cur_max

Função CRT interna. Recupera o número máximo de bytes em um caractere multibyte para o código de idioma atual ou especificado.

## <a name="syntax"></a>Sintaxe

```cpp
int ___mb_cur_max_func(void);
int ___mb_cur_max_l_func(_locale_t locale);
int * __p___mb_cur_max(void);
#define __mb_cur_max (___mb_cur_max_func())
```

#### <a name="parameters"></a>Parâmetros

locale A estrutura da localidade da qual o resultado deve ser recuperado. Caso esse valor seja nulo, o código de idioma do thread atual será usado.

## <a name="return-value"></a>Valor retornado

Recupera o número máximo de bytes em um caractere multibyte para o código de idioma de thread atual ou especificado.

## <a name="remarks"></a>Comentários

Essa é uma função interna que o CRT usa para recuperar o valor atual da macro [MB_CUR_MAX](../c-runtime-library/mb-cur-max.md) do armazenamento local do thread. Recomendamos o uso da macro `MB_CUR_MAX` no seu código para fins de portabilidade.

A macro `__mb_cur_max` é uma maneira conveniente de chamar a função `___mb_cur_max_func()`. A função `__p___mb_cur_max` é definida para fins de compatibilidade com o Visual C++ 5.0 e versões anteriores.

Funções CRT internas são específicas da implementação e estão sujeitas a alteração em cada versão. Não recomendamos usá-las no seu código.

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|
|-------------|---------------------|
|`___mb_cur_max_func`, `___mb_cur_max_l_func`, `__p___mb_cur_max`|\<ctype.h>, \<stdlib.h>|

## <a name="see-also"></a>Consulte também

[MB_CUR_MAX](../c-runtime-library/mb-cur-max.md)