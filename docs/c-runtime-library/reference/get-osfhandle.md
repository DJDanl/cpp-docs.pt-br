---
title: _get_osfhandle
ms.date: 4/2/2020
api_name:
- _get_osfhandle
- _o__get_osfhandle
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
- get_osfhandle
- _get_osfhandle
helpviewer_keywords:
- operating systems, getting file handles
- get_osfhandle function
- _get_osfhandle function
- file handles [C++], operating system
ms.assetid: 0bdd728a-4fd8-410b-8c9f-01a121135196
ms.openlocfilehash: 085bf20a12d9b77be0977521bde2ab75d9b2636a
ms.sourcegitcommit: 5a069c7360f75b7c1cf9d4550446ec2fa2eb2293
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/07/2020
ms.locfileid: "82918278"
---
# <a name="_get_osfhandle"></a>_get_osfhandle

Recupera o identificador de arquivo do sistema operacional associado ao descritor do arquivo especificado.

## <a name="syntax"></a>Sintaxe

```C
intptr_t _get_osfhandle(
   int fd
);
```

### <a name="parameters"></a>Parâmetros

*FD*<br/>
Um descritor de arquivo existente.

## <a name="return-value"></a>Valor retornado

Retorna um identificador de arquivo do sistema operacional se *FD* for válido. Caso contrário, o manipulador de parâmetro inválido será invocado, conforme descrito em [Validação de parâmetro](../../c-runtime-library/parameter-validation.md). Se a execução tiver permissão para continuar, ela retornará **INVALID_HANDLE_VALUE** (-1). Ele também define **errno** como **EBADF**, indicando um identificador de arquivo inválido. Para evitar um aviso quando o resultado é usado como um identificador de arquivo do Win32, converta-o em um tipo de **identificador** .

> [!NOTE]
> Quando **stdin**, **stdout**e **stderr** não estão associados a um fluxo (por exemplo, em um aplicativo do Windows sem uma janela de console), os valores do descritor de arquivo para esses fluxos são retornados de [_fileno](fileno.md) como o valor especial-2. Da mesma forma, se você usar um 0, 1 ou 2 como o parâmetro do descritor de arquivo em vez do resultado de uma chamada para **_fileno**, **_get_osfhandle** também retornará o valor especial-2 quando o descritor de arquivo não estiver associado a um fluxo e não definir **errno**. No entanto, esse não é um valor de identificador de arquivo válido e as chamadas subsequentes que tentam usá-lo provavelmente falharão.

Para obter mais informações sobre **EBADF** e outros códigos de erro, consulte [_doserrno, errno, _sys_errlist e _sys_nerr](../../c-runtime-library/errno-doserrno-sys-errlist-and-sys-nerr.md).

## <a name="remarks"></a>Comentários

Para fechar um arquivo cujo identificador de arquivo do sistema operacional (SO) é obtido por **_get_osfhandle**, chame [_close](close.md) no descritor de arquivo *fd*. Nunca chame **CloseHandle** no valor de retorno dessa função. O identificador de arquivo do sistema operacional subjacente é de Propriedade do descritor de arquivo *FD* e é fechado quando [_close](close.md) é chamado em *fd*. Se o descritor de arquivo pertencer `FILE *` a um fluxo, chamar [fclose](fclose-fcloseall.md) nesse `FILE *` fluxo fecha o descritor de arquivo e o identificador de arquivo do sistema operacional subjacente. Nesse caso, não chame [_close](close.md) no descritor de arquivo.

Por padrão, o estado global dessa função tem como escopo o aplicativo. Para alterar isso, consulte [estado global no CRT](../global-state.md).

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
[\_open_osfhandle](open-osfhandle.md)
