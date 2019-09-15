---
title: __max
ms.date: 04/05/2018
api_name:
- __max
api_location:
- msvcrt.dll
- msvcr80.dll
- msvcr90.dll
- msvcr100.dll
- msvcr100_clr0400.dll
- msvcr110.dll
- msvcr110_clr0400.dll
- msvcr120.dll
- msvcr120_clr0400.dll
- ucrtbase.dll
api_type:
- DLLExport
topic_type:
- apiref
f1_keywords:
- max
- __max
helpviewer_keywords:
- max macro
- maximum macro
- __max macro
ms.assetid: 05c936f6-0e22-45d6-a58d-4bc102e9dae2
ms.openlocfilehash: dac82ecd1c96d1edf9175a29797d93c65bc19c99
ms.sourcegitcommit: f19474151276d47da77cdfd20df53128fdcc3ea7
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/12/2019
ms.locfileid: "70952744"
---
# <a name="__max"></a>__max

Uma macro de pré-processador que retorna o maior de dois valores.

## <a name="syntax"></a>Sintaxe

```C
#define __max(a,b) (((a) > (b)) ? (a) : (b))
```

### <a name="parameters"></a>Parâmetros

*a*, *b*<br/>
Valores de qualquer tipo numérico a serem comparados.

## <a name="return-value"></a>Valor de retorno

**__max** retorna o maior de seus argumentos.

## <a name="remarks"></a>Comentários

A macro **__max** compara dois valores e retorna o valor do maior. Os argumentos podem ser de qualquer tipo de dados numérico, com ou sem sinal. Os argumentos e o valor retornado devem ser do mesmo tipo de dados.

O argumento retornado é avaliado duas vezes pela macro. Isso pode levar a resultados inesperados se o argumento for uma expressão que altera seu valor quando ele é avaliado, como `*p++`.

## <a name="requirements"></a>Requisitos

|Macro|Cabeçalho necessário|
|-------------|---------------------|
|**__max**|\<stdlib.h>|

## <a name="example"></a>Exemplo

Para obter mais informações, consulte o exemplo para [__min](min.md).

## <a name="see-also"></a>Consulte também

[Suporte a ponto flutuante](../../c-runtime-library/floating-point-support.md)<br/>
[__min](min.md)<br/>