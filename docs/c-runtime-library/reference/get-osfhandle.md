---
title: _get_osfhandle
ms.date: 05/29/2018
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
helpviewer_keywords:
- operating systems, getting file handles
- get_osfhandle function
- _get_osfhandle function
- file handles [C++], operating system
ms.assetid: 0bdd728a-4fd8-410b-8c9f-01a121135196
ms.openlocfilehash: cc3b50e3d3f65bee83b8df83aa0adb5c8694e35a
ms.sourcegitcommit: 8adabe177d557c74566c13145196c11cef5d10d4
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/10/2019
ms.locfileid: "66821661"
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

Retorna um identificador de arquivo do sistema operacional, se *fd* é válido. Caso contrário, o manipulador de parâmetro inválido será invocado, conforme descrito em [Validação de parâmetro](../../c-runtime-library/parameter-validation.md). Se a execução puder continuar, ele retornará **INVALID_HANDLE_VALUE** (-1). Ele também define **errno** à **EBADF**, que indica o identificador de arquivo inválido. Para evitar um aviso quando o resultado é usado como um identificador de arquivo do Win32, convertê-lo em um **MANIPULAR** tipo.

> [!NOTE]
> Quando **stdin**, **stdout**, e **stderr** não estiver associado a um fluxo (por exemplo, em um Windows aplicativo sem uma janela de console), os valores do descritor de arquivo para Esses fluxos são retornados de [fileno](fileno.md) como especiais de valor -2. Da mesma forma, se você usar um 0, 1 ou 2 como o parâmetro de descritor de arquivo em vez do resultado de uma chamada para **fileno**, **get_osfhandle** também retorna o valor especial, -2, quando o descritor de arquivo não está associado a com um fluxo e não definido **errno**. No entanto, isso não é um valor de identificador de arquivo válido e as chamadas subsequentes que tentam usá-lo provavelmente falharão.

Para obter mais informações sobre **EBADF** e outros códigos de erro, consulte [doserrno, errno, sys_errlist e sys_nerr](../../c-runtime-library/errno-doserrno-sys-errlist-and-sys-nerr.md).

## <a name="remarks"></a>Comentários

Para fechar um arquivo cujo identificador de arquivo do sistema operacional (SO) obtido pela **get_osfhandle**, chame [Close](close.md) sobre o descritor de arquivo *fd*. Nunca chama **CloseHandle** no valor de retorno dessa função. O identificador de arquivo do sistema operacional subjacente é de propriedade de *fd* descritor de arquivo e é fechado quando [Close](close.md) é chamado no *fd*. Se o descritor de arquivo pertence a um `FILE *` fluxo, em seguida, chamar [fclose](fclose-fcloseall.md) em que `FILE *` fluxo fecha o descritor de arquivo e o identificador de arquivo do sistema operacional subjacente. Nesse caso, não chame [Close](close.md) no descritor de arquivo.

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
