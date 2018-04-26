---
title: _get_osfhandle | Microsoft Docs
ms.custom: ''
ms.date: 12/12/2017
ms.reviewer: ''
ms.suite: ''
ms.technology:
- cpp-standard-libraries
ms.tgt_pltfrm: ''
ms.topic: reference
apiname:
- _get_osfhandle
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
- get_osfhandle
- _get_osfhandle
dev_langs:
- C++
helpviewer_keywords:
- operating systems, getting file handles
- get_osfhandle function
- _get_osfhandle function
- file handles [C++], operating system
ms.assetid: 0bdd728a-4fd8-410b-8c9f-01a121135196
caps.latest.revision: 14
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: ef9481cb0ad962de96b710b31ac1460b9703ae6e
ms.sourcegitcommit: ef859ddf5afea903711e36bfd89a72389a12a8d6
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/20/2018
---
# <a name="getosfhandle"></a>_get_osfhandle

Recupera o identificador de arquivo do sistema operacional associado ao descritor do arquivo especificado.

## <a name="syntax"></a>Sintaxe

```C
intptr_t _get_osfhandle(
   int fd
);
```

### <a name="parameters"></a>Parâmetros

*fd*<br/>
Um descritor de arquivo existente.

## <a name="return-value"></a>Valor de retorno

Retorna um identificador de arquivo do sistema operacional se *fd* é válido. Caso contrário, o manipulador de parâmetro inválido será invocado, conforme descrito em [Validação de parâmetro](../../c-runtime-library/parameter-validation.md). Se a execução é permitida para continuar, essa função retorna **INVALID_HANDLE_VALUE** (-1) e define **errno** para **EBADF**, que indica o identificador de arquivo inválido.

## <a name="remarks"></a>Comentários

Para fechar um arquivo cujo identificador de arquivo do sistema operacional (SO) é obtido por **get_osfhandle**, chame [echar](close.md) no descritor de arquivo *fd*. Não chame **CloseHandle** no valor de retorno dessa função. O identificador de arquivo do sistema operacional subjacente é de propriedade de *fd* descritor de arquivo e é fechado quando [echar](close.md) é chamado em *fd*. Se o descritor de arquivo pertence a um **arquivo \***  fluxo, em seguida, chamar [fclose](fclose-fcloseall.md) naquele **arquivo \***  fluxo fecha ambos o descritor de arquivo e o identificador de arquivo do sistema operacional subjacente. Nesse caso, não chame [echar](close.md) no descritor de arquivo.

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|
|-------------|---------------------|
|**_get_osfhandle**|\<io.h>|

Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="see-also"></a>Consulte também

[Manipulação de Arquivos](../../c-runtime-library/file-handling.md)<br/>
[_close](close.md)<br/>
[_creat, _wcreat](creat-wcreat.md)<br/>
[_dup, _dup2](dup-dup2.md)<br/>
[_open, _wopen](open-wopen.md)<br/>
