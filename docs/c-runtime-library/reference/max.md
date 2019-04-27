---
title: __max
ms.date: 04/05/2018
apiname:
- __max
apilocation:
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
apitype: DLLExport
f1_keywords:
- max
- __max
helpviewer_keywords:
- max macro
- maximum macro
- __max macro
ms.assetid: 05c936f6-0e22-45d6-a58d-4bc102e9dae2
ms.openlocfilehash: 32e1207ea4bb030ac5303de32c0566f98e0596a3
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62156857"
---
# <a name="max"></a>__max

Uma macro de pré-processador que retorna o maior dos dois valores.

## <a name="syntax"></a>Sintaxe

```C
#define __max(a,b) (((a) > (b)) ? (a) : (b))
```

### <a name="parameters"></a>Parâmetros

*a*, *b*<br/>
Valores de qualquer tipo numérico a serem comparados.

## <a name="return-value"></a>Valor de retorno

**Max** retorna o maior dos seus argumentos.

## <a name="remarks"></a>Comentários

O **max** macro compara dois valores e retorna o valor do maior. Os argumentos podem ser de qualquer tipo de dados numérico, com ou sem sinal. Os argumentos e o valor retornado devem ser do mesmo tipo de dados.

O argumento retornado é avaliado duas vezes, a macro. Isso pode levar a resultados inesperados se o argumento for uma expressão que altera seu valor quando ele é avaliado, tais como `*p++`.

## <a name="requirements"></a>Requisitos

|Macro|Cabeçalho necessário|
|-------------|---------------------|
|**__max**|\<stdlib.h>|

## <a name="example"></a>Exemplo

Para obter mais informações, consulte o exemplo para [__min](min.md).

## <a name="see-also"></a>Consulte também

[Suporte a ponto flutuante](../../c-runtime-library/floating-point-support.md)<br/>
[__min](min.md)<br/>