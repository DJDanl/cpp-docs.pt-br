---
title: setbuf
ms.date: 4/2/2020
api_name:
- setbuf
- _o_setbuf
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
- setbuf
helpviewer_keywords:
- setbuf function
- stream buffering
ms.assetid: 13beda22-7b56-455d-8a6c-f2eb636885b9
ms.openlocfilehash: 40f23db88abf9733eada9e775aacda83cba5829a
ms.sourcegitcommit: 5a069c7360f75b7c1cf9d4550446ec2fa2eb2293
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/07/2020
ms.locfileid: "82910339"
---
# <a name="setbuf"></a>setbuf

Controla o buffer de fluxo. Essa função foi preterida; use [setvbuf](setvbuf.md) em seu lugar.

## <a name="syntax"></a>Sintaxe

```C
void setbuf(
   FILE *stream,
   char *buffer
);
```

### <a name="parameters"></a>Parâmetros

*fluxo*<br/>
Ponteiro para a estrutura **FILE**.

*completo*<br/>
Buffer alocado pelo usuário.

## <a name="remarks"></a>Comentários

A função **setbuf** controla o buffer para o *Stream*. O argumento de *fluxo* deve se referir a um arquivo aberto que não foi lido ou gravado. Se o argumento de *buffer* for **nulo**, o fluxo não será armazenado em buffer. Caso contrário, o buffer deve apontar para uma matriz de caracteres de comprimento **BUFSIZ**, em que **BUFSIZ** é o tamanho do buffer, conforme definido em STDIO. T. O buffer especificado pelo usuário, em vez do buffer alocado do sistema padrão para o fluxo informado, é usado para buffer de E/S. O fluxo **stderr** é sem buffer por padrão, mas você pode usar **setbuf** para atribuir buffers a **stderr**.

o **setbuf** foi substituído por [setvbuf](setvbuf.md), que é a rotina preferida para o novo código. Ao contrário de **setvbuf**, o **setbuf** não tem nenhuma maneira de relatar erros. o **setvbuf** também permite que você controle o modo de buffer e o tamanho do buffer. **setbuf** existe para compatibilidade com o código existente.

Por padrão, o estado global dessa função tem como escopo o aplicativo. Para alterar isso, consulte [estado global no CRT](../global-state.md).

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|
|-------------|---------------------|
|**setbuf**|\<stdio.h>|

Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="example"></a>Exemplo

```C
// crt_setbuf.c
// compile with: /W3
// This program first opens files named DATA1 and
// DATA2. Then it uses setbuf to give DATA1 a user-assigned
// buffer and to change DATA2 so that it has no buffer.

#include <stdio.h>

int main( void )
{
   char buf[BUFSIZ];
   FILE *stream1, *stream2;

   fopen_s( &stream1, "data1", "a" );
   fopen_s( &stream2, "data2", "w" );

   if( (stream1 != NULL) && (stream2 != NULL) )
   {
      // "stream1" uses user-assigned buffer:
      setbuf( stream1, buf ); // C4996
      // Note: setbuf is deprecated; consider using setvbuf instead
      printf( "stream1 set to user-defined buffer at: %Fp\n", buf );

      // "stream2" is unbuffered
      setbuf( stream2, NULL ); // C4996
      printf( "stream2 buffering disabled\n" );
      _fcloseall();
   }
}
```

```Output
stream1 set to user-defined buffer at: 0012FCDC
stream2 buffering disabled
```

## <a name="see-also"></a>Confira também

[E/S de fluxo](../../c-runtime-library/stream-i-o.md)<br/>
[fclose, _fcloseall](fclose-fcloseall.md)<br/>
[fflush](fflush.md)<br/>
[fopen, _wfopen](fopen-wfopen.md)<br/>
[setvbuf](setvbuf.md)<br/>
