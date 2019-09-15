---
title: fgetpos
ms.date: 11/04/2016
api_name:
- fgetpos
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
api_type:
- DLLExport
topic_type:
- apiref
f1_keywords:
- fgetpos
helpviewer_keywords:
- fgetpos function
- streams, file position indicator
ms.assetid: bfa05c38-1135-418c-bda1-d41be51acb62
ms.openlocfilehash: 27d25b29f656d1df889e5f83857ca437f609a07a
ms.sourcegitcommit: f19474151276d47da77cdfd20df53128fdcc3ea7
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/12/2019
ms.locfileid: "70940839"
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

*stream*<br/>
O fluxo de destino.

*pos*<br/>
Armazenamento do indicador de posição.

## <a name="return-value"></a>Valor de retorno

Se for bem-sucedido, **fgetpos** retornará 0. Em caso de falha, ele retorna um valor diferente de zero e define **errno** como uma das constantes de manifesto a seguir (definidas em STDIO. H): **EBADF**, que significa que o fluxo especificado não é um ponteiro de arquivo válido ou não está acessível, ou **EINVAL**, o que significa que o valor de *fluxo* ou o valor de *PDV* é inválido, como se um deles for um ponteiro nulo. Se *Stream* ou *pos* for um ponteiro **NULL** , a função invocará o manipulador de parâmetro inválido, conforme descrito em [validação de parâmetro](../../c-runtime-library/parameter-validation.md).

## <a name="remarks"></a>Comentários

A função **fgetpos** Obtém o valor atual do indicador de posição de arquivo do argumento de *fluxo* e o armazena no objeto apontado pelo *PDV*. A função **fsetpos** pode usar posteriormente as informações armazenadas no *PDV* para redefinir o ponteiro do argumento de *fluxo* para sua posição no momento em que **fgetpos** foi chamado. O valor de *PDV* é armazenado em um formato interno e destina-se ao uso somente por **fgetpos** e **fsetpos**.

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

## <a name="input-crt_fgetpostxt"></a>Entrada: crt_fgetpos.txt

```Input
fgetpos gets a stream's file-position indicator.
```

### <a name="output-crt_fgetpostxt"></a>Saída crt_fgetpos.txt

```Output
after fgetpos: gets a stream
after fsetpos: gets a stream
```

## <a name="see-also"></a>Consulte também

[E/S de fluxo](../../c-runtime-library/stream-i-o.md)<br/>
[fsetpos](fsetpos.md)<br/>
