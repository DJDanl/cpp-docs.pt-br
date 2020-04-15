---
title: ___mb_cur_max_func, ___mb_cur_max_l_func, __p___mb_cur_max, __mb_cur_max
ms.date: 4/2/2020
api_name:
- ___mb_cur_max_l_func
- __p___mb_cur_max
- ___mb_cur_max_func
- __mb_cur_max
- _o____mb_cur_max_func
api_location:
- msvcr110_clr0400.dll
- msvcr110.dll
- msvcr80.dll
- msvcr100.dll
- msvcrt.dll
- msvcr90.dll
- msvcr120.dll
- api-ms-win-crt-locale-l1-1-0.dll
- api-ms-win-crt-private-l1-1-0
api_type:
- DLLExport
topic_type:
- apiref
f1_keywords:
- ___mb_cur_max_func
- ___mb_cur_max_l_func
- __p___mb_cur_max
- __mb_cur_max
helpviewer_keywords:
- __mb_cur_max
- ___mb_cur_max_func
- ___mb_cur_max_l_func
- __p___mb_cur_max
ms.assetid: 60d36108-1ca7-45a6-8ce7-68a91f13e3a1
ms.openlocfilehash: f9b9e2d903bb05f5b1b653b4fb51c57b354d4126
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81351073"
---
# <a name="___mb_cur_max_func-___mb_cur_max_l_func-__p___mb_cur_max-__mb_cur_max"></a>___mb_cur_max_func, ___mb_cur_max_l_func, __p___mb_cur_max, __mb_cur_max

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

Por padrão, o estado global desta função é escopo para o aplicativo. Para mudar isso, consulte [Estado Global no CRT](global-state.md).

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|
|-------------|---------------------|
|`___mb_cur_max_func`, `___mb_cur_max_l_func`, `__p___mb_cur_max`|\<ctype.h>, \<stdlib.h>|

## <a name="see-also"></a>Confira também

[MB_CUR_MAX](../c-runtime-library/mb-cur-max.md)
