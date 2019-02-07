---
title: fread
ms.date: 11/28/2018
apiname:
- fread
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
- fread
helpviewer_keywords:
- reading data [C++], from input streams
- fread function
- data [C++], reading from input stream
- streams [C++], reading data from
ms.assetid: 9a3c1538-93dd-455e-ae48-77c1e23c53f0
ms.openlocfilehash: 7248eb08409b50d855dbb70c7638a856302b345b
ms.sourcegitcommit: bd637e9c39650cfd530520ea978a22fa4caa0e42
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/07/2019
ms.locfileid: "55849965"
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

**fread** retorna o número de itens completos realmente lidos, que pode ser menor que *contagem* se ocorrer um erro ou se o final do arquivo for encontrado antes de alcançar *contagem*. Use o **feof** ou **ferror** função para diferenciar um erro de leitura de uma condição de fim-de-arquivo. Se *tamanho* ou *contagem* é 0, o **fread** retorna 0 e o conteúdo do buffer é as mesmas. Se *stream* ou *buffer* é um ponteiro nulo, **fread** invocará o manipulador de parâmetro inválido, conforme descrito na [validação de parâmetro](../../c-runtime-library/parameter-validation.md). Se a execução puder continuar, essa função definirá **errno** à **EINVAL** e retornará 0.

Ver [ \_doserrno, errno, \_sys\_errlist, e \_sys\_nerr](../../c-runtime-library/errno-doserrno-sys-errlist-and-sys-nerr.md) para obter mais informações sobre esses códigos de erro.

## <a name="remarks"></a>Comentários

O **fread** função lê até *contagem* itens do *tamanho* bytes de entrada *fluxo* e armazena-os no *buffer* . O ponteiro de arquivo associado *stream* (se houver) é aumentado pelo número de bytes realmente lidos. Se o fluxo em questão for aberto no [modo de texto](../../c-runtime-library/text-and-binary-mode-file-i-o.md), novas linhas de estilo do Windows são convertidas em novas linhas de estilo Unix. Ou seja, pares de retorno e avanço de linha (CRLF) do carro serão substituídos por caracteres de única linha (LF). A substituição não interfere no ponteiro do arquivo ou no valor retornado. A posição do ponteiro do arquivo será indeterminada se ocorrer um erro. O valor de um item lido parcialmente não pode ser determinado.

Quando usado em um fluxo de modo de texto, se a quantidade de dados solicitada (ou seja, *tamanho* \* *contagem*) é maior que ou igual a interno **arquivo** \*tamanho do buffer (por padrão é 4096 bytes configuráveis por meio [setvbuf](../../c-runtime-library/reference/setvbuf.md)), o fluxo de dados é copiado diretamente para o buffer fornecido pelo usuário e conversão de nova linha é feita no buffer. Como os dados convertidos podem ser menores do que os dados de fluxo copiados no buffer de dados anteriores *buffer*\[*return_value* \* *tamanho*] ( em que *return_value* é o valor de retorno **fread**) pode conter os dados do arquivo não convertidos. Por esse motivo, recomendamos que você null terminar com dados de caractere em *buffer*\[*return_value* \* *tamanho*] se for a intenção do buffer para atuar como uma cadeia de caracteres de estilo C. Ver [fopen](fopen-wfopen.md) para obter detalhes sobre os efeitos de modo de texto e o modo binário.

Essa função bloqueia outros threads. Se você precisar de uma versão sem bloqueio, use **fread_nolock**.

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
[E/s de texto e arquivo binário](../../c-runtime-library/text-and-binary-mode-file-i-o.md)<br/>
[fopen](fopen-wfopen.md)<br/>
[fwrite](fwrite.md)<br/>
[_read](read.md)<br/>
