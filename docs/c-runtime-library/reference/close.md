---
title: _close
ms.date: 4/2/2020
api_name:
- _close
- _o__close
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
- _close
helpviewer_keywords:
- _close function
- close function
- files [C++], closing
ms.assetid: 4708a329-8acf-4cd9-b7b0-a952e1897247
ms.openlocfilehash: 4d8b702a10624ae80629b4ce4644c428322500cb
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81348651"
---
# <a name="_close"></a>_close

Fecha um arquivo.

## <a name="syntax"></a>Sintaxe

```C
int _close(
   int fd
);
```

### <a name="parameters"></a>Parâmetros

*Fd*<br/>
Descritor de arquivo que se refere ao arquivo aberto.

## <a name="return-value"></a>Valor retornado

**_close** retorna 0 se o arquivo foi fechado com sucesso. Um valor de retorno de -1 indica um erro.

## <a name="remarks"></a>Comentários

A função **_close** fecha o arquivo associado ao *fd*.

O descritor de arquivo e o identificador de arquivo do sistema operacional subjacente são fechados. Assim, não é necessário chamar **o CloseHandle** se o arquivo foi originalmente aberto usando a função Win32 **CreateFile** e convertido em um descritor de arquivo usando **_open_osfhandle**.

Essa função valida seus parâmetros. Se *fd* for um descritor de arquivo ruim, o manipulador de parâmetros inválidos é invocado, conforme descrito na [Validação de Parâmetros](../../c-runtime-library/parameter-validation.md). Se a execução continuar, as funções retornarão -1 e **errno** será definida **como EBADF**.

Por padrão, o estado global desta função é escopo para o aplicativo. Para mudar isso, consulte [Estado Global no CRT](../global-state.md).

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|Cabeçalho opcional|
|-------------|---------------------|---------------------|
|**_close**|\<io.h>|\<errno.h>|

Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="example"></a>Exemplo

Veja o exemplo de [_open](open-wopen.md).

## <a name="see-also"></a>Confira também

[E/S de nível inferior](../../c-runtime-library/low-level-i-o.md)<br/>
[_chsize](chsize.md)<br/>
[_creat, _wcreat](creat-wcreat.md)<br/>
[_dup, _dup2](dup-dup2.md)<br/>
[_open, _wopen](open-wopen.md)<br/>
[_unlink, _wunlink](unlink-wunlink.md)<br/>
