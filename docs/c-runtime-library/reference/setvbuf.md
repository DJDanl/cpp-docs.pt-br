---
title: setvbuf
ms.date: 4/2/2020
api_name:
- setvbuf
- _o_setvbuf
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
- setvbuf
helpviewer_keywords:
- controlling stream buffering
- stream buffering
- setvbuf function
ms.assetid: 6aa5aa37-3408-4fa0-992f-87f9f9c4baea
ms.openlocfilehash: 907d02e94c79acf09dfa99a8b42e9f448d32dcfa
ms.sourcegitcommit: 5a069c7360f75b7c1cf9d4550446ec2fa2eb2293
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/07/2020
ms.locfileid: "82915760"
---
# <a name="setvbuf"></a>setvbuf

Controla o tamanho do buffer e o buffer de fluxo.

## <a name="syntax"></a>Sintaxe

```C
int setvbuf(
   FILE *stream,
   char *buffer,
   int mode,
   size_t size
);
```

### <a name="parameters"></a>Parâmetros

*fluxo*<br/>
Ponteiro para a estrutura **FILE**.

*completo*<br/>
Buffer alocado pelo usuário.

*mode*<br/>
Modo de buffer.

*size*<br/>
O tamanho do buffer, em bytes. Intervalo permitido: 2 <= *size* <= INT_MAX (2147483647). Internamente, o valor fornecido para o *tamanho* é arredondado para baixo até o múltiplo mais próximo de 2.

## <a name="return-value"></a>Valor retornado

Retorna 0 se for bem-sucedido.

Se o *fluxo* for **nulo**, ou se o *modo* ou o *tamanho* não estiver dentro de uma alteração válida, o manipulador de parâmetro inválido será invocado, conforme descrito em [validação de parâmetro](../../c-runtime-library/parameter-validation.md). Se a execução puder continuar, essa função retornará um valor -1 e definirá **errno** como **EINVAL**.

Para obter informações sobre esses e outros códigos de erro, consulte [_doserrno, errno, _sys_errlist e _sys_nerr](../../c-runtime-library/errno-doserrno-sys-errlist-and-sys-nerr.md).

## <a name="remarks"></a>Comentários

A função **setvbuf** permite que o programa controle o buffer e o tamanho do buffer para o *fluxo*. o *fluxo* deve se referir a um arquivo aberto que não passou por uma operação de e/s desde que ele foi aberto. A matriz apontada por *buffer* é usada como buffer, a menos que seja **nula**, caso em que **setvbuf** usa um buffer alocado automaticamente de *tamanho*de comprimento/ \* 2 2 bytes.

O modo deve ser **_IOFBF**, **_IOLBF**ou **_IONBF**. Se o *modo* for **_IOFBF** ou **_IOLBF**, o *tamanho* será usado como o tamanho do buffer. Se o *modo* for **_IONBF**, o fluxo será sem buffer e o *tamanho* e o *buffer* serão ignorados. Os valores para o *modo* e seus significados são:

|valor de *modo*|Significado|
|-|-|
| **_IOFBF** | Buffer completo; ou seja, o *buffer* é usado como o buffer e o *tamanho* são usados como o tamanho do buffer. Se o *buffer* for **nulo**, será usado um *tamanho* de buffer atribuído automaticamente com comprimento de bytes. |
| **_IOLBF** | Para alguns sistemas, isso fornece buffer em linha. No entanto, para o Win32, o comportamento é o mesmo que **_IOFBF** buffer completo. |
| **_IONBF** | Nenhum buffer é usado, independentemente do *buffer* ou do *tamanho*. |

Por padrão, o estado global dessa função tem como escopo o aplicativo. Para alterar isso, consulte [estado global no CRT](../global-state.md).

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|
|-------------|---------------------|
|**setvbuf**|\<stdio.h>|

Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="libraries"></a>Bibliotecas

Todas as versões das [bibliotecas em tempo de execução C](../../c-runtime-library/crt-library-features.md).

## <a name="example"></a>Exemplo

```C
// crt_setvbuf.c
// This program opens two streams: stream1
// and stream2. It then uses setvbuf to give stream1 a
// user-defined buffer of 1024 bytes and stream2 no buffer.
//

#include <stdio.h>

int main( void )
{
   char buf[1024];
   FILE *stream1, *stream2;

   if( fopen_s( &stream1, "data1", "a" ) == 0 &&
       fopen_s( &stream2, "data2", "w" ) == 0 )
   {
      if( setvbuf( stream1, buf, _IOFBF, sizeof( buf ) ) != 0 )
         printf( "Incorrect type or size of buffer for stream1\n" );
      else
         printf( "'stream1' now has a buffer of 1024 bytes\n" );
      if( setvbuf( stream2, NULL, _IONBF, 0 ) != 0 )
         printf( "Incorrect type or size of buffer for stream2\n" );
      else
         printf( "'stream2' now has no buffer\n" );
      _fcloseall();
   }
}
```

```Output
'stream1' now has a buffer of 1024 bytes
'stream2' now has no buffer
```

## <a name="see-also"></a>Confira também

[E/S de fluxo](../../c-runtime-library/stream-i-o.md)<br/>
[fclose, _fcloseall](fclose-fcloseall.md)<br/>
[fflush](fflush.md)<br/>
[fopen, _wfopen](fopen-wfopen.md)<br/>
[setbuf](setbuf.md)<br/>
