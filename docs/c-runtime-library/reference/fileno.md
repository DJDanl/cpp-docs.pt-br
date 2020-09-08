---
title: _fileno
description: Referência de API para _fileno; que obtém o descritor de arquivo associado a um fluxo.
ms.date: 4/2/2020
api_name:
- _fileno
- _o__fileno
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
- _fileno
helpviewer_keywords:
- file handles [C++], getting from streams
- fileno function
- _fileno function
- streams, getting file handles
ms.assetid: 86474174-2f17-4100-bcc4-352dd976c7b5
ms.openlocfilehash: c07f446cc3c5c29fb102a74b2b095957589eab46
ms.sourcegitcommit: 4ed2d68634eb2fb77e18110a2d26bc0008be369c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/08/2020
ms.locfileid: "89554845"
---
# <a name="_fileno"></a>_fileno

Obtém o descritor de arquivo associado a um fluxo.

## <a name="syntax"></a>Sintaxe

```C
int _fileno(
   FILE *stream
);
```

### <a name="parameters"></a>Parâmetros

*fluxo*<br/>
Ponteiro para a estrutura **FILE**.

## <a name="return-value"></a>Valor Retornado

**_fileno** retorna o descritor de arquivo. Não há nenhum retorno de erro. O resultado será indefinido se o *fluxo* não especificar um arquivo aberto. Se o fluxo for **nulo**, **_fileno** invocará o manipulador de parâmetro inválido, conforme descrito em [validação de parâmetro](../../c-runtime-library/parameter-validation.md). Se a execução puder continuar, essa função retornará um valor -1 e definirá **errno** como **EINVAL**.

Para obter mais informações sobre esses e outros códigos de erro, consulte [_doserrno, errno, _sys_errlist e _sys_nerr](../../c-runtime-library/errno-doserrno-sys-errlist-and-sys-nerr.md).

> [!NOTE]
> Se **stdout** ou **stderr** não estiver associado a um fluxo de saída (por exemplo, em um aplicativo do Windows sem uma janela de console), o descritor de arquivo retornado será-2. Nas versões anteriores, o descritor de arquivo retornado era –1. Essa alteração permite que aplicativos faça a distinção dessa condição de um erro.

## <a name="remarks"></a>Comentários

A rotina **_fileno** retorna o descritor de arquivo atualmente associado ao *fluxo*. Essa rotina é implementada como uma função e uma macro. Para obter informações sobre como escolher a implementação, consulte [Escolher entre funções e macros](../../c-runtime-library/recommendations-for-choosing-between-functions-and-macros.md).

Por padrão, o estado global dessa função tem como escopo o aplicativo. Para alterar isso, consulte [estado global no CRT](../global-state.md).

## <a name="requirements"></a>Requisitos

|Função|Cabeçalho necessário|
|--------------|---------------------|
|**_fileno**|\<stdio.h>|

Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="example"></a>Exemplo

```C
// crt_fileno.c
// This program uses _fileno to obtain
// the file descriptor for some standard C streams.
//

#include <stdio.h>

int main( void )
{
   printf( "The file descriptor for stdin is %d\n", _fileno( stdin ) );
   printf( "The file descriptor for stdout is %d\n", _fileno( stdout ) );
   printf( "The file descriptor for stderr is %d\n", _fileno( stderr ) );
}
```

```Output
The file descriptor for stdin is 0
The file descriptor for stdout is 1
The file descriptor for stderr is 2
```

## <a name="see-also"></a>Confira também

[E/S de fluxo](../../c-runtime-library/stream-i-o.md)<br/>
[_fdopen, _wfdopen](fdopen-wfdopen.md)<br/>
[_filelength, _filelengthi64](filelength-filelengthi64.md)<br/>
[fopen, _wfopen](fopen-wfopen.md)<br/>
[freopen, _wfreopen](freopen-wfreopen.md)<br/>
