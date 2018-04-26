---
title: _get_fmode | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.reviewer: ''
ms.suite: ''
ms.technology:
- cpp-standard-libraries
ms.tgt_pltfrm: ''
ms.topic: reference
apiname:
- _get_fmode
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
- api-ms-win-crt-stdio-l1-1-0.dll
apitype: DLLExport
f1_keywords:
- get_fmode
- _get_fmode
dev_langs:
- C++
helpviewer_keywords:
- _get_fmode function
- file translation [C++], default mode
- get_fmode function
ms.assetid: 22ea70e2-b9b5-422d-b514-64f4beaea45c
caps.latest.revision: 19
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 3a3845de8feb36b995fec8d450bfc5a9656d429c
ms.sourcegitcommit: ef859ddf5afea903711e36bfd89a72389a12a8d6
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/20/2018
---
# <a name="getfmode"></a>_get_fmode

Obtém o modo de conversão de arquivo padrão para operações de E/S de arquivo.

## <a name="syntax"></a>Sintaxe

```C
errno_t _get_fmode( 
   int * pmode 
);
```

### <a name="parameters"></a>Parâmetros

*pmode*<br/>
Um ponteiro para um inteiro a ser preenchida com o modo padrão atual: **o_text** ou **o_binary**.

## <a name="return-value"></a>Valor de retorno

Retorna zero se tiver êxito; um código de erro em caso de falha. Se *pmode* é **nulo**, o manipulador de parâmetro inválido é invocado, conforme descrito em [validação do parâmetro](../../c-runtime-library/parameter-validation.md). Se a execução é permitida para continuar, **errno** é definido como **EINVAL** e a função retorna **EINVAL**.

## <a name="remarks"></a>Comentários

A função obtém o valor da variável global [_fmode](../../c-runtime-library/fmode.md). Essa variável Especifica o modo de tradução de arquivo padrão para baixo nível e fluxo de operações de e/s de arquivo, como **abrir**, **pipe**, **fopen**, e [ freopen](freopen-wfreopen.md).

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
[E/S de texto e arquivo de modo binário](../../c-runtime-library/text-and-binary-mode-file-i-o.md)<br/>
