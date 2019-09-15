---
title: _set_controlfp
ms.date: 04/05/2018
api_name:
- _set_controlfp
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
- api-ms-win-crt-runtime-l1-1-0.dll
api_type:
- DLLExport
topic_type:
- apiref
f1_keywords:
- set_controlfp
- _set_controlfp
helpviewer_keywords:
- set_controlfp function
- floating-point functions, setting control word
- _set_controlfp function
ms.assetid: e0689d50-f68a-4028-a9c1-fb23eedee4ad
ms.openlocfilehash: 4d39406db0f4c9ba6374776da62aea2dbb61e23d
ms.sourcegitcommit: f19474151276d47da77cdfd20df53128fdcc3ea7
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/12/2019
ms.locfileid: "70948678"
---
# <a name="_set_controlfp"></a>_set_controlfp

Define a palavra de controle de ponto flutuante.

## <a name="syntax"></a>Sintaxe

```C
void __cdecl _set_controlfp(
    unsigned int newControl,
    unsigned int mask
);
```

### <a name="parameters"></a>Parâmetros

*newControl*<br/>
Novos valores de bit da palavra de controle.

*mascara*<br/>
Máscara para novos bits da palavra de controle a ser definida.

## <a name="return-value"></a>Valor de retorno

nenhuma.

## <a name="remarks"></a>Comentários

A função **_set_controlfp** é semelhante a **_control87**, mas só define a palavra de controle de ponto flutuante como *newControl*. Os bits nos valores indicam o estado do controle de ponto flutuante. O estado do controle de ponto flutuante permite que o programa altere os modos de precisão, arredondamento e infinito no pacote de matemática de ponto flutuante. Você também pode mascarar ou desmascarar as exceções de ponto flutuante usando **_set_controlfp**. Para obter mais informações, consulte [_control87, _controlfp, \__control87_2](control87-controlfp-control87-2.md).

Essa função é preterida durante a compilação com [/CLR (compilação Common Language Runtime)](../../build/reference/clr-common-language-runtime-compilation.md) porque a Common Language Runtime só dá suporte à precisão de ponto flutuante padrão.

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|Compatibilidade|
|-------------|---------------------|-------------------|
|**_set_controlfp**|\<float.h>|Somente processador x86|

Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="see-also"></a>Consulte também

[Suporte a ponto flutuante](../../c-runtime-library/floating-point-support.md)<br/>
[_clear87, _clearfp](clear87-clearfp.md)<br/>
[_status87, _statusfp, _statusfp2](status87-statusfp-statusfp2.md)<br/>
