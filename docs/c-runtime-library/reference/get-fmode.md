---
title: _get_fmode
ms.date: 4/2/2020
api_name:
- _get_fmode
- _o__get_fmode
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
- api-ms-win-crt-stdio-l1-1-0.dll
- api-ms-win-crt-private-l1-1-0
api_type:
- DLLExport
topic_type:
- apiref
f1_keywords:
- get_fmode
- _get_fmode
helpviewer_keywords:
- _get_fmode function
- file translation [C++], default mode
- get_fmode function
ms.assetid: 22ea70e2-b9b5-422d-b514-64f4beaea45c
ms.openlocfilehash: fbaa30d0842400037f37508df94726f3e7fd7090
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81345165"
---
# <a name="_get_fmode"></a>_get_fmode

Obtém o modo de conversão de arquivo padrão para operações de E/S de arquivo.

## <a name="syntax"></a>Sintaxe

```C
errno_t _get_fmode(
   int * pmode
);
```

### <a name="parameters"></a>Parâmetros

*Pmode*<br/>
Um ponteiro para um inteiro a ser preenchido com o modo padrão atual: **_O_TEXT** ou **_O_BINARY**.

## <a name="return-value"></a>Valor retornado

Retorna zero se tiver êxito; um código de erro em caso de falha. Se *o pmode* for **NULO,** o manipulador de parâmetros inválidos será invocado conforme descrito na [Validação de Parâmetros](../../c-runtime-library/parameter-validation.md). Se a execução continuar, **errno** será definido **como EINVAL** e a função retorna **EINVAL**.

## <a name="remarks"></a>Comentários

A função obtém o valor da variável global [_fmode](../../c-runtime-library/fmode.md). Esta variável especifica o modo de tradução de arquivo padrão para operações de I/O de arquivo de baixo nível e de fluxo, como **_open,** **_pipe,** **fopen**e [freopen](freopen-wfreopen.md).

Por padrão, o estado global desta função é escopo para o aplicativo. Para mudar isso, consulte [Estado Global no CRT](../global-state.md).

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|Cabeçalho opcional|
|-------------|---------------------|---------------------|
|**_get_fmode**|\<stdlib.h>|\<fcntl.h>|

Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="example"></a>Exemplo

Veja o exemplo em [_set_fmode](set-fmode.md).

## <a name="see-also"></a>Confira também

[_fmode](../../c-runtime-library/fmode.md)<br/>
[_set_fmode](set-fmode.md)<br/>
[_setmode](setmode.md)<br/>
[I/O do arquivo de texto e modo binário](../../c-runtime-library/text-and-binary-mode-file-i-o.md)<br/>
