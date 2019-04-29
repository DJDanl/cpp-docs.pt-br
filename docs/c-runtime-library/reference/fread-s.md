---
title: fread_s
ms.date: 11/04/2016
apiname:
- fread_s
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
- fread_s
- stdio/fread_s
ms.assetid: ce735de0-f005-435d-a8f2-6f4b80ac775e
ms.openlocfilehash: 898e813c19fd53cfdacd536c2e9819743a62a8da
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62287805"
---
# <a name="freads"></a>fread_s

Lê dados de um fluxo. Esta versão de [fread](fread.md) tem melhorias de segurança, conforme descrito em [Recursos de segurança no CRT](../../c-runtime-library/security-features-in-the-crt.md).

## <a name="syntax"></a>Sintaxe

```C
size_t fread_s(
   void *buffer,
   size_t bufferSize,
   size_t elementSize,
   size_t count,
   FILE *stream
);
```

### <a name="parameters"></a>Parâmetros

*buffer*<br/>
Local de armazenamento de dados.

*bufferSize*<br/>
Tamanho do buffer de destino em bytes.

*elementSize*<br/>
Tamanho do item a ser lido em bytes.

*count*<br/>
Número máximo de itens a serem lidos.

*stream*<br/>
Ponteiro para a estrutura **FILE**.

## <a name="return-value"></a>Valor de retorno

**fread_s** retorna o número de (inteiro) de itens que foram lidos no buffer, que pode ser menor que *contagem* se um erro de leitura ou o final do arquivo é encontrado antes *contagem* for atingido. Use o **feof** ou **ferror** função para diferenciar um erro de uma condição de fim-de-arquivo. Se *tamanho* ou *contagem* é 0, o **fread_s** retorna 0 e o conteúdo do buffer é as mesmas. Se *stream* ou *buffer* é um ponteiro nulo, **fread_s** invocará o manipulador de parâmetro inválido, conforme descrito na [validação de parâmetro](../../c-runtime-library/parameter-validation.md) . Se a execução puder continuar, essa função definirá **errno** à **EINVAL** e retornará 0.

Para obter mais informações sobre códigos de erro, consulte [_doserrno, errno, _sys_errlist e _sys_nerr](../../c-runtime-library/errno-doserrno-sys-errlist-and-sys-nerr.md).

## <a name="remarks"></a>Comentários

O **fread_s** função lê até *contagem* itens do *elementSize* bytes de entrada *fluxo* e as armazena no *buffer*.  O ponteiro do arquivo que está associado com *stream* (se houver) é aumentado pelo número de bytes realmente lidos. Se o fluxo em questão for aberto no modo de texto, pares de alimentação de linha de retorno de carro são substituídos por caracteres de avanço de linha única. A substituição não interfere no ponteiro do arquivo ou no valor retornado. A posição do ponteiro do arquivo será indeterminada se ocorrer um erro. O valor de um item lido parcialmente não pode ser determinado.

Essa função bloqueia outros threads. Se você precisar de uma versão sem bloqueio, use **fread_nolock**.

## <a name="requirements"></a>Requisitos

|Função|Cabeçalho necessário|
|--------------|---------------------|
|**fread_s**|\<stdio.h>|

Para obter informações adicionais sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="example"></a>Exemplo

```cpp
// crt_fread_s.c
// Command line: cl /EHsc /nologo /W4 crt_fread_s.c
//
// This program opens a file that's named FREAD.OUT and
// writes characters to the file. It then tries to open
// FREAD.OUT and read in characters by using fread_s. If the attempt succeeds,
// the program displays the number of actual items read.

#include <stdio.h>

#define BUFFERSIZE 30
#define DATASIZE 22
#define ELEMENTCOUNT 2
#define ELEMENTSIZE (DATASIZE/ELEMENTCOUNT)
#define FILENAME "FREAD.OUT"

int main( void )
{
   FILE *stream;
   char list[30];
   int  i, numread, numwritten;

   for ( i = 0; i < DATASIZE; i++ )
      list[i] = (char)('z' - i);
   list[DATASIZE] = '\0'; // terminal null so we can print it

   // Open file in text mode:
   if( fopen_s( &stream, FILENAME, "w+t" ) == 0 )
   {
      // Write DATASIZE characters to stream
      printf( "Contents of buffer before write/read:\n\t%s\n\n", list );
      numwritten = fwrite( list, sizeof( char ), DATASIZE, stream );
      printf( "Wrote %d items\n\n", numwritten );
      fclose( stream );
   } else {
      printf( "Problem opening the file\n" );
      return -1;
   }

   if( fopen_s( &stream, FILENAME, "r+t" ) == 0 )   {
      // Attempt to read in characters in 2 blocks of 11
      numread = fread_s( list, BUFFERSIZE, ELEMENTSIZE, ELEMENTCOUNT, stream );
      printf( "Number of %d-byte elements read = %d\n\n", ELEMENTSIZE, numread );
      printf( "Contents of buffer after write/read:\n\t%s\n", list );
      fclose( stream );
   } else {
      printf( "File could not be opened\n" );
      return -1;
   }
}
```

```Output
Contents of buffer before write/read:
        zyxwvutsrqponmlkjihgfe

Wrote 22 items

Number of 11-byte elements read = 2

Contents of buffer after write/read:
        zyxwvutsrqponmlkjihgfe
```

## <a name="see-also"></a>Consulte também

[E/S de fluxo](../../c-runtime-library/stream-i-o.md)<br/>
[fwrite](fwrite.md)<br/>
[_read](read.md)<br/>
