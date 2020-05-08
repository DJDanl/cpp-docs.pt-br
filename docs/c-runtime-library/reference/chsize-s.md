---
title: _chsize_s
ms.date: 4/2/2020
api_name:
- _chsize_s
- _o__chsize_s
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
- chsize_s
- _chsize_s
helpviewer_keywords:
- files [C++], changing size
- chsize_s function
- _chsize_s function
ms.assetid: d88d2e94-6e3b-42a5-8631-16ac4d82fa38
ms.openlocfilehash: faed95bfeb6fad88f502101e166ec6124b6e591d
ms.sourcegitcommit: 5a069c7360f75b7c1cf9d4550446ec2fa2eb2293
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/07/2020
ms.locfileid: "82910408"
---
# <a name="_chsize_s"></a>_chsize_s

Altera o tamanho de um arquivo. Esta é uma versão de [_chsize](chsize.md) com melhorias de segurança, conforme descrito em [Recursos de segurança no CRT](../../c-runtime-library/security-features-in-the-crt.md).

## <a name="syntax"></a>Sintaxe

```C
errno_t _chsize_s(
   int fd,
   __int64 size
);
```

### <a name="parameters"></a>Parâmetros

*FD*<br/>
Descritor de arquivo que faz referência a um arquivo aberto.

*size*<br/>
Novo tamanho do arquivo em bytes.

## <a name="return-value"></a>Valor retornado

**_chsize_s** retornará o valor 0 se o tamanho do arquivo for alterado com êxito. Um valor de retorno diferente de zero indica um erro: o valor de retorno será **EACCES** se o arquivo especificado estiver bloqueado em relação ao acesso, **EBADF** se o arquivo especificado for somente leitura ou o descritor for inválido, **ENOSPC** se nenhum espaço for deixado no dispositivo ou **EINVAL** se o tamanho for menor que zero. **errno** é definido com o mesmo valor.

Para obter mais informações sobre esses e outros códigos de retorno, consulte [_doserrno, errno, _sys_errlist e _sys_nerr](../../c-runtime-library/errno-doserrno-sys-errlist-and-sys-nerr.md).

## <a name="remarks"></a>Comentários

A função **_chsize_s** estende ou trunca o arquivo associado a *FD* para o comprimento especificado por *size*. O arquivo deve ser aberto em um modo que permita gravação. Caracteres nulos ('\0') que serão acrescentados se o arquivo for estendido. Se o arquivo for truncado, todos os dados do final do arquivo reduzido para o tamanho original do arquivo serão perdidos.

**_chsize_s** usa um inteiro de 64 bits como o tamanho do arquivo e, portanto, pode manipular tamanhos de arquivo maiores que 4 GB. **_chsize** é limitado a tamanhos de arquivo de 32 bits.

Essa função valida seus parâmetros. Se *FD* não for um descritor de arquivo válido ou o tamanho for menor que zero, o manipulador de parâmetro inválido será invocado, conforme descrito em [validação de parâmetro](../../c-runtime-library/parameter-validation.md).

Por padrão, o estado global dessa função tem como escopo o aplicativo. Para alterar isso, consulte [estado global no CRT](../global-state.md).

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|Cabeçalho opcional|
|-------------|---------------------|---------------------|
|**_chsize_s**|\<io.h>|\<errno.h>|

Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="see-also"></a>Consulte também

[Manipulação de Arquivos](../../c-runtime-library/file-handling.md)<br/>
[_chsize](chsize.md)<br/>
[_close](close.md)<br/>
[_creat, _wcreat](creat-wcreat.md)<br/>
[_open, _wopen](open-wopen.md)<br/>
