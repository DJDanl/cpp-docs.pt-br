---
title: fread
ms.date: 11/28/2018
api_name:
- fread
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
- fread
helpviewer_keywords:
- reading data [C++], from input streams
- fread function
- data [C++], reading from input stream
- streams [C++], reading data from
ms.assetid: 9a3c1538-93dd-455e-ae48-77c1e23c53f0
ms.openlocfilehash: 7cf4542a656798f7e2431b2f939df1b5d6396144
ms.sourcegitcommit: f19474151276d47da77cdfd20df53128fdcc3ea7
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/12/2019
ms.locfileid: "70956813"
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

*buffer*<br/>
Local de armazenamento de dados.

*size*<br/>
Tamanho do item em bytes.

*count*<br/>
Número máximo de itens a serem lidos.

*stream*<br/>
Ponteiro para a estrutura **FILE**.

## <a name="return-value"></a>Valor de retorno

**fread** retorna o número de itens completos realmente lidos, o que pode ser menor que a *contagem* se ocorrer um erro ou se o final do arquivo for encontrado antes de atingir a *contagem*. Use a função **feof** ou **referenciadora** para distinguir um erro de leitura de uma condição de fim de arquivo. Se *tamanho* ou *contagem* for 0, **fread** retornará 0 e o conteúdo do buffer não será alterado. Se *Stream* ou *buffer* for um ponteiro NULL, **fread** invocará o manipulador de parâmetro inválido, conforme descrito em [validação de parâmetro](../../c-runtime-library/parameter-validation.md). Se a execução tiver permissão para continuar, essa função definirá **errno** como **EINVAL** e retornará 0.

Consulte [ \_\_doserrno, errno, \_sys errlist e sys\_nerr para obter mais informações sobre esses códigos de erro. \_](../../c-runtime-library/errno-doserrno-sys-errlist-and-sys-nerr.md)

## <a name="remarks"></a>Comentários

A função **fread** lê até *contar* itens de *tamanho* bytes do *fluxo* de entrada e os armazena no *buffer*. O ponteiro de arquivo associado ao *fluxo* (se houver) é aumentado pelo número de bytes realmente lidos. Se o fluxo fornecido for aberto no [modo de texto](../../c-runtime-library/text-and-binary-mode-file-i-o.md), as linhas do estilo do Windows serão convertidas em novas linhas no estilo UNIX. Ou seja, os pares de linha de retorno de carro (CRLF) são substituídos por caracteres LF (single line feed). A substituição não interfere no ponteiro do arquivo ou no valor retornado. A posição do ponteiro do arquivo será indeterminada se ocorrer um erro. O valor de um item lido parcialmente não pode ser determinado.

Quando usado em um fluxo de modo de texto, se a quantidade de dados solicitada (ou seja, *contagem*de *tamanho* \* ) for maior ou igual ao tamanho do buffer de **arquivo** \* interno (por padrão, é 4096 bytes, configuráveis usando [ setvbuf](../../c-runtime-library/reference/setvbuf.md)), os dados de fluxo são copiados diretamente no buffer fornecido pelo usuário e a conversão de nova linha é feita nesse buffer. Como os dados convertidos podem ser menores do que os dados de fluxo copiados para o buffer, os dados após o *buffer*\[*return_value* \* *tamanho*] (em que *return_value* é o valor de retorno de **fread**) podem conter dados não convertidos do arquivo. Por esse motivo, recomendamos que você destermine dados de caracteres de caractere nulo no *buffer*\[*return_value* \* *tamanho*] se a intenção do buffer for agir como uma cadeia de estilo C. Consulte [fopen](fopen-wfopen.md) para obter detalhes sobre os efeitos do modo de texto e do modo binário.

Essa função bloqueia outros threads. Se você precisar de uma versão sem bloqueio, use **_fread_nolock**.

## <a name="requirements"></a>Requisitos

|Função|Cabeçalho necessário|
|--------------|---------------------|
|**fread**|\<stdio.h>|

Para obter informações adicionais sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

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

## <a name="see-also"></a>Consulte também

[E/S de fluxo](../../c-runtime-library/stream-i-o.md)<br/>
[Texto e e/s de arquivo binário](../../c-runtime-library/text-and-binary-mode-file-i-o.md)<br/>
[fopen](fopen-wfopen.md)<br/>
[fwrite](fwrite.md)<br/>
[_read](read.md)<br/>
