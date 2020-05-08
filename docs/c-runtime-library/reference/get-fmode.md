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
- api-ms-win-crt-private-l1-1-0.dll
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
ms.openlocfilehash: 3e59e608f83874088b64d316c04053b94d8fbfdd
ms.sourcegitcommit: 5a069c7360f75b7c1cf9d4550446ec2fa2eb2293
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/07/2020
ms.locfileid: "82909856"
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

*pmode*<br/>
Um ponteiro para um inteiro a ser preenchido com o modo padrão atual: **_O_TEXT** ou **_O_BINARY**.

## <a name="return-value"></a>Valor retornado

Retorna zero se tiver êxito; um código de erro em caso de falha. Se *pmode* for **NULL**, o manipulador de parâmetro inválido será invocado conforme descrito em [validação de parâmetro](../../c-runtime-library/parameter-validation.md). Se a execução puder continuar, **errno** será definido como **EINVAL** e a função retornará **EINVAL**.

## <a name="remarks"></a>Comentários

A função obtém o valor da variável global [_fmode](../../c-runtime-library/fmode.md). Essa variável especifica o modo de conversão de arquivo padrão para operações de e/s de arquivo de baixo nível e fluxo, como **_open**, **_pipe**, **fopen**e [freopen](freopen-wfreopen.md).

Por padrão, o estado global dessa função tem como escopo o aplicativo. Para alterar isso, consulte [estado global no CRT](../global-state.md).

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|Cabeçalho opcional|
|-------------|---------------------|---------------------|
|**_get_fmode**|\<stdlib.h>|\<fcntl.h>|

Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="example"></a>Exemplo

Veja o exemplo em [_set_fmode](set-fmode.md).

## <a name="see-also"></a>Consulte também

[_fmode](../../c-runtime-library/fmode.md)<br/>
[_set_fmode](set-fmode.md)<br/>
[_setmode](setmode.md)<br/>
[E/s de arquivo de modo binário](../../c-runtime-library/text-and-binary-mode-file-i-o.md)<br/>
