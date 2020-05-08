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
- api-ms-win-crt-private-l1-1-0.dll
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
ms.openlocfilehash: c642820bf1bc2e2afbd14e17832fb3fdb6f865b8
ms.sourcegitcommit: 5a069c7360f75b7c1cf9d4550446ec2fa2eb2293
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/07/2020
ms.locfileid: "82919849"
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

*FD*<br/>
Descritor de arquivo que se refere ao arquivo aberto.

## <a name="return-value"></a>Valor retornado

**_close** retornará 0 se o arquivo tiver sido fechado com êxito. Um valor de retorno de-1 indica um erro.

## <a name="remarks"></a>Comentários

A função **_close** fecha o arquivo associado ao *FD*.

O descritor de arquivo e o identificador de arquivo do sistema operacional subjacente são fechados. Portanto, não é necessário chamar **CloseHandle** se o arquivo foi aberto originalmente usando a função **CreateFile** do Win32 e convertido em um descritor de arquivo usando **_open_osfhandle**.

Essa função valida seus parâmetros. Se *FD* for um descritor de arquivo incorreto, o manipulador de parâmetro inválido será invocado, conforme descrito em [validação de parâmetro](../../c-runtime-library/parameter-validation.md). Se a execução tiver permissão para continuar, as funções retornam-1 e **errno** são definidas como **EBADF**.

Por padrão, o estado global dessa função tem como escopo o aplicativo. Para alterar isso, consulte [estado global no CRT](../global-state.md).

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|Cabeçalho opcional|
|-------------|---------------------|---------------------|
|**_close**|\<io.h>|\<errno.h>|

Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="example"></a>Exemplo

Veja o exemplo de [_open](open-wopen.md).

## <a name="see-also"></a>Consulte também

[E/S de nível inferior](../../c-runtime-library/low-level-i-o.md)<br/>
[_chsize](chsize.md)<br/>
[_creat, _wcreat](creat-wcreat.md)<br/>
[_dup, _dup2](dup-dup2.md)<br/>
[_open, _wopen](open-wopen.md)<br/>
[_unlink, _wunlink](unlink-wunlink.md)<br/>
