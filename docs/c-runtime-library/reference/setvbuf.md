---
title: setvbuf | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-standard-libraries
ms.topic: reference
apiname:
- setvbuf
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
- setvbuf
dev_langs:
- C++
helpviewer_keywords:
- controlling stream buffering
- stream buffering
- setvbuf function
ms.assetid: 6aa5aa37-3408-4fa0-992f-87f9f9c4baea
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 4c516932eb8d50fb8c9fdbe6f8c48a3f590b1ffb
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
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

*Fluxo*<br/>
Ponteiro para a estrutura **FILE**.

*buffer*<br/>
Buffer alocado pelo usuário.

*modo*<br/>
Modo de buffer.

*size*<br/>
O tamanho do buffer, em bytes. Intervalo permitido: 2 < = *tamanho* < = INT_MAX (2147483647). Internamente, o valor fornecido para *tamanho* é arredondado para baixo até o múltiplo mais próximo de 2.

## <a name="return-value"></a>Valor de retorno

Retorna 0 se for bem-sucedido.

Se *fluxo* é **nulo**, ou se *modo* ou *tamanho* é não dentro de uma alteração válida, o manipulador de parâmetro inválido é invocado, conforme descrito em [Validação do parâmetro](../../c-runtime-library/parameter-validation.md). Se a execução é permitida para continuar, esta função retornará -1 e conjuntos de **errno** para **EINVAL**.

Para obter informações sobre esses e outros códigos de erro, consulte [_doserrno, errno, _sys_errlist e _sys_nerr](../../c-runtime-library/errno-doserrno-sys-errlist-and-sys-nerr.md).

## <a name="remarks"></a>Comentários

O **setvbuf** função permite que o programa controlar os dois buffer e tamanho do buffer *fluxo*. *fluxo* devem se referir a um arquivo aberto que não passou por uma operação de e/s desde que ela foi aberta. A matriz apontada pelo *buffer* é usado como o buffer, a menos que ele seja **nulo**, caso em que **setvbuf** utiliza um buffer alocado automaticamente de comprimento  *tamanho*bytes de e/2 * 2.

O modo deve ser **iofbf**, **iolbf**, ou **ionbf**. Se *modo* é **iofbf** ou **iolbf**, em seguida, *tamanho* é usado como o tamanho do buffer. Se *modo* é **ionbf**, o fluxo é sem buffer e *tamanho* e *buffer* são ignorados. Os valores para *modo* e seus significados são:

|*modo* valor|Significado|
|-|-|
**IOFBF**|Buffer completo; ou seja, *buffer* é usado como o buffer e *tamanho* é usado como o tamanho do buffer. Se *buffer* é **nulo**, um buffer alocado automaticamente *tamanho* bytes de comprimento é usado.
**IOLBF**|Para alguns sistemas, isso fornece buffer em linha. No entanto, para Win32, o comportamento é o mesmo que **iofbf** -buffer completo.
**IONBF**|Nenhum buffer é usado, independentemente de *buffer* ou *tamanho*.

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|
|-------------|---------------------|
|**setvbuf**|\<stdio.h>|

Para obter informações adicionais sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="libraries"></a>Libraries

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

## <a name="see-also"></a>Consulte também

[E/S de fluxo](../../c-runtime-library/stream-i-o.md)<br/>
[fclose, _fcloseall](fclose-fcloseall.md)<br/>
[fflush](fflush.md)<br/>
[fopen, _wfopen](fopen-wfopen.md)<br/>
[setbuf](setbuf.md)<br/>
