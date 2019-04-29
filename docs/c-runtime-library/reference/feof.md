---
title: feof
ms.date: 11/04/2016
apiname:
- feof
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
- feof
helpviewer_keywords:
- end of file, testing for
- feof function
ms.assetid: 09081eee-7c4b-4189-861f-2fad95d3ec6d
ms.openlocfilehash: 9c023290df601bfc48f9708af86d32d91cd52dc4
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62334392"
---
# <a name="feof"></a>feof

Testa o fim do arquivo em um fluxo.

## <a name="syntax"></a>Sintaxe

```C
int feof(
   FILE *stream
);
```

### <a name="parameters"></a>Parâmetros

*stream*<br/>
Ponteiro para a estrutura **FILE**.

## <a name="return-value"></a>Valor de retorno

O **feof** função retorna um valor diferente de zero se uma operação de leitura tentou ler após o final do arquivo; ele retorna 0 caso contrário. Se o ponteiro de fluxo estiver **nulo**, a função invocará o manipulador de parâmetro inválido, conforme descrito em [validação de parâmetro](../../c-runtime-library/parameter-validation.md). Se a execução puder continuar, **errno** é definido como **EINVAL** e o **feof** retornará 0.

Consulte [_doserrno, errno, _sys_errlist e _sys_nerr](../../c-runtime-library/errno-doserrno-sys-errlist-and-sys-nerr.md) para obter mais informações sobre esses e outros códigos de erro.

## <a name="remarks"></a>Comentários

O **feof** rotina (implementada como uma função e como uma macro) determina se o final do *fluxo* foi passado. Quando o final do arquivo for passado, operações retornam um indicador de fim-de-arquivo até que o fluxo está fechado ou até de leitura [rewind](rewind.md), **fsetpos**, [fseek](fseek-fseeki64.md), ou  **clearerr** é chamado em relação a ela.

Por exemplo, se um arquivo contiver 10 bytes e ler 10 bytes do arquivo, **feof** retornará 0 porque, mesmo que o ponteiro do arquivo está no final do arquivo, você não tentou ler além do fim. Somente após a tentativa de ler um 11 º byte serão **feof** retornam um valor diferente de zero.

## <a name="requirements"></a>Requisitos

|Função|Cabeçalho necessário|
|--------------|---------------------|
|**feof**|\<stdio.h>|

Para obter informações adicionais sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="example"></a>Exemplo

```C
// crt_feof.c
// This program uses feof to indicate when
// it reaches the end of the file CRT_FEOF.TXT. It also
// checks for errors with ferror.
//

#include <stdio.h>
#include <stdlib.h>

int main( void )
{
   int  count, total = 0;
   char buffer[100];
   FILE *stream;

   fopen_s( &stream, "crt_feof.txt", "r" );
   if( stream == NULL )
      exit( 1 );

   // Cycle until end of file reached:
   while( !feof( stream ) )
   {
      // Attempt to read in 100 bytes:
      count = fread( buffer, sizeof( char ), 100, stream );
      if( ferror( stream ) )      {
         perror( "Read error" );
         break;
      }

      // Total up actual bytes read
      total += count;
   }
   printf( "Number of bytes read = %d\n", total );
   fclose( stream );
}
```

## <a name="input-crtfeoftxt"></a>Entrada: crt_feof.txt

```Input
Line one.
Line two.
```

### <a name="output"></a>Saída

```Output
Number of bytes read = 19
```

## <a name="see-also"></a>Consulte também

[Tratamento de erro](../../c-runtime-library/error-handling-crt.md)<br/>
[E/S de fluxo](../../c-runtime-library/stream-i-o.md)<br/>
[clearerr](clearerr.md)<br/>
[_eof](eof.md)<br/>
[ferror](ferror.md)<br/>
[perror, _wperror](perror-wperror.md)<br/>
