---
title: fgetpos
ms.date: 11/04/2016
apiname:
- fgetpos
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
- fgetpos
helpviewer_keywords:
- fgetpos function
- streams, file position indicator
ms.assetid: bfa05c38-1135-418c-bda1-d41be51acb62
ms.openlocfilehash: e213c9830ffe6edf04b12a80828f14cc48f77524
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50658413"
---
# <a name="fgetpos"></a>fgetpos

Obtém o indicador de posição do arquivo do fluxo.

## <a name="syntax"></a>Sintaxe

```C
int fgetpos(
   FILE *stream,
   fpos_t *pos
);
```

### <a name="parameters"></a>Parâmetros

*fluxo*<br/>
O fluxo de destino.

*POS*<br/>
Armazenamento do indicador de posição.

## <a name="return-value"></a>Valor de retorno

Se for bem-sucedido, **fgetpos** retornará 0. Em caso de falha, ele retorna um valor diferente de zero e define **errno** para uma das seguintes constantes (definidas em STDIO de manifesto. H): **EBADF**, que significa que o fluxo especificado não for um ponteiro de arquivo válido ou não está acessível, ou **EINVAL**, que significa que o *fluxo* valor ou o valor de *pos* é inválido, por exemplo, se é um ponteiro nulo. Se *stream* ou *pos* é um **nulo** ponteiro, a função invocará o manipulador de parâmetro inválido, conforme descrito em [validação de parâmetro](../../c-runtime-library/parameter-validation.md).

## <a name="remarks"></a>Comentários

O **fgetpos** função obtém o valor atual das *fluxo* indicador de posição do arquivo do argumento e o armazena no objeto apontado por *pos*. O **fsetpos** função posterior pode usar informações armazenadas no *pos* para redefinir o *fluxo* ponteiro do argumento com sua posição no momento **fgetpos** foi chamado. O *pos* valor é armazenado em um formato interno e é destinado para uso somente pelo **fgetpos** e **fsetpos**.

## <a name="requirements"></a>Requisitos

|Função|Cabeçalho necessário|
|--------------|---------------------|
|**fgetpos**|\<stdio.h>|

Para obter informações adicionais sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="example"></a>Exemplo

```C
// crt_fgetpos.c
// This program uses fgetpos and fsetpos to
// return to a location in a file.

#include <stdio.h>

int main( void )
{
   FILE   *stream;
   fpos_t pos;
   char   buffer[20];

   if( fopen_s( &stream, "crt_fgetpos.txt", "rb" ) ) {
      perror( "Trouble opening file" );
      return -1;
   }

   // Read some data and then save the position.
   fread( buffer, sizeof( char ), 8, stream );
   if( fgetpos( stream, &pos ) != 0 ) {
      perror( "fgetpos error" );
      return -1;
   }

   fread( buffer, sizeof( char ), 13, stream );
   printf( "after fgetpos: %.13s\n", buffer );

   // Restore to old position and read data
   if( fsetpos( stream, &pos ) != 0 ) {
      perror( "fsetpos error" );
      return -1;
   }

   fread( buffer, sizeof( char ), 13, stream );
   printf( "after fsetpos: %.13s\n", buffer );
   fclose( stream );
}
```

## <a name="input-crtfgetpostxt"></a>Entrada: crt_fgetpos.txt

```Input
fgetpos gets a stream's file-position indicator.
```

### <a name="output-crtfgetpostxt"></a>Saída crt_fgetpos.txt

```Output
after fgetpos: gets a stream
after fsetpos: gets a stream
```

## <a name="see-also"></a>Consulte também

[E/S de fluxo](../../c-runtime-library/stream-i-o.md)<br/>
[fsetpos](fsetpos.md)<br/>
