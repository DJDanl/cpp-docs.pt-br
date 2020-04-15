---
title: fread
ms.date: 4/2/2020
api_name:
- fread
- _o_fread
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
- fread
helpviewer_keywords:
- reading data [C++], from input streams
- fread function
- data [C++], reading from input stream
- streams [C++], reading data from
ms.assetid: 9a3c1538-93dd-455e-ae48-77c1e23c53f0
ms.openlocfilehash: 26ffd56072f1a5fddc3131a42cd47c145e437b60
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81346058"
---
# <a name="fread"></a>fread

Lê dados de um fluxo.

## <a name="syntax"></a>Sintaxe

```C
size_t fread(
   void *buffer,
   size_t size,
   size_t count,
   FILE *stream
);
```

### <a name="parameters"></a>Parâmetros

*Buffer*<br/>
Local de armazenamento de dados.

*Tamanho*<br/>
Tamanho do item em bytes.

*contagem*<br/>
Número máximo de itens a serem lidos.

*fluxo*<br/>
Ponteiro para a estrutura **FILE**.

## <a name="return-value"></a>Valor retornado

**fread** retorna o número de itens completos realmente lidos, o que pode ser menor do que *a contagem* se ocorrer um erro ou se o final do arquivo for encontrado antes de atingir a *contagem*. Use a função **feof** ou **ferror** para distinguir um erro de leitura de uma condição de fim de arquivo. Se *o tamanho* ou *contagem* for 0, **fread** retorna 0 e o conteúdo do buffer não será alterado. Se *o fluxo* ou *buffer* for um ponteiro nulo, **fread** invoca o manipulador de parâmetros inválido, conforme descrito na [Validação de Parâmetros](../../c-runtime-library/parameter-validation.md). Se a execução for permitida, esta função define **errno** para **EINVAL** e retorna 0.

Consulte [ \_doserrno, \_errno,\_sys errlist e \_sys nerr\_](../../c-runtime-library/errno-doserrno-sys-errlist-and-sys-nerr.md) para obter mais informações sobre esses códigos de erro.

## <a name="remarks"></a>Comentários

A função **fread** lê-se para *contar* itens de *tamanho* bytes do *fluxo* de entrada e armazena-os em *buffer*. O ponteiro de arquivo associado ao *fluxo* (se houver um) é aumentado pelo número de bytes realmente lidos. Se o fluxo dado for aberto no [modo texto,](../../c-runtime-library/text-and-binary-mode-file-i-o.md)as novas linhas no estilo Windows serão convertidas em novas linhas no estilo Unix. Ou seja, os pares de alimentação de linha de retorno de transporte (CRLF) são substituídos por caracteres de alimentação de linha única (LF). A substituição não interfere no ponteiro do arquivo ou no valor retornado. A posição do ponteiro do arquivo será indeterminada se ocorrer um erro. O valor de um item lido parcialmente não pode ser determinado.

Quando usado em um fluxo de modo de texto, se a quantidade de dados solicitados (isto é, *contagem*de *tamanho)* \* for maior ou igual ao tamanho interno do buffer **FILE** \* (por padrão, são 4096 bytes, configuráveis usando [setvbuf),](../../c-runtime-library/reference/setvbuf.md)os dados de fluxo são copiados diretamente no buffer fornecido pelo usuário, e a conversão newline é feita nesse buffer. Uma vez que os dados convertidos podem ser mais curtos do que os dados de fluxo copiados para o buffer, os dados *passados buffer*\[*return_value* \* *tamanho*] (onde *return_value* é o valor de retorno de **fread**) podem conter dados não convertidos do arquivo. Por esta razão, recomendamos que você termine os dados de caracteres no *buffer*\[*return_value* \* *tamanho*] se a intenção do buffer for agir como uma seqüência de estilo C. Consulte [fopen](fopen-wfopen.md) para obter detalhes sobre os efeitos do modo texto e do modo binário.

Essa função bloqueia outros threads. Se você precisar de uma versão sem travamento, **use _fread_nolock**.

Por padrão, o estado global desta função é escopo para o aplicativo. Para mudar isso, consulte [Estado Global no CRT](../global-state.md).

## <a name="requirements"></a>Requisitos

|Função|Cabeçalho necessário|
|--------------|---------------------|
|**fread**|\<stdio.h>|

Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="example"></a>Exemplo

```C
// crt_fread.c
// This program opens a file named FREAD.OUT and
// writes 25 characters to the file. It then tries to open
// FREAD.OUT and read in 25 characters. If the attempt succeeds,
// the program displays the number of actual items read.

#include <stdio.h>

int main( void )
{
   FILE *stream;
   char list[30];
   int  i, numread, numwritten;

   // Open file in text mode:
   if( fopen_s( &stream, "fread.out", "w+t" ) == 0 )
   {
      for ( i = 0; i < 25; i++ )
         list[i] = (char)('z' - i);
      // Write 25 characters to stream
      numwritten = fwrite( list, sizeof( char ), 25, stream );
      printf( "Wrote %d items\n", numwritten );
      fclose( stream );

   }
   else
      printf( "Problem opening the file\n" );

   if( fopen_s( &stream, "fread.out", "r+t" ) == 0 )
   {
      // Attempt to read in 25 characters
      numread = fread( list, sizeof( char ), 25, stream );
      printf( "Number of items read = %d\n", numread );
      printf( "Contents of buffer = %.25s\n", list );
      fclose( stream );
   }
   else
      printf( "File could not be opened\n" );
}
```

```Output
Wrote 25 items
Number of items read = 25
Contents of buffer = zyxwvutsrqponmlkjihgfedcb
```

## <a name="see-also"></a>Confira também

[E/S de fluxo](../../c-runtime-library/stream-i-o.md)<br/>
[I/O de texto e arquivo binário](../../c-runtime-library/text-and-binary-mode-file-i-o.md)<br/>
[fopen](fopen-wfopen.md)<br/>
[fwrite](fwrite.md)<br/>
[_read](read.md)<br/>
