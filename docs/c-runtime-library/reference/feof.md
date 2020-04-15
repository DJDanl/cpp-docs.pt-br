---
title: feof
ms.date: 4/2/2020
api_name:
- feof
- _o_feof
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
- feof
helpviewer_keywords:
- end of file, testing for
- feof function
ms.assetid: 09081eee-7c4b-4189-861f-2fad95d3ec6d
ms.openlocfilehash: 9ee085624be3c5613ac4b5e87965d47324727778
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81347379"
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

*fluxo*<br/>
Ponteiro para a estrutura **FILE**.

## <a name="return-value"></a>Valor retornado

A função **feof** retorna um valor não zero se uma operação de leitura tentou ler após o final do arquivo; ele retorna 0 de outra forma. Se o ponteiro do fluxo for **NULO,** a função invoca o manipulador de parâmetros inválidos, conforme descrito na [Validação de Parâmetros](../../c-runtime-library/parameter-validation.md). Se a execução continuar, **errno** será definido **como EINVAL** e o **feof** retorna 0.

Consulte [_doserrno, errno, _sys_errlist e _sys_nerr](../../c-runtime-library/errno-doserrno-sys-errlist-and-sys-nerr.md) para obter mais informações sobre esses e outros códigos de erro.

## <a name="remarks"></a>Comentários

A rotina **do feof** (implementada tanto como função quanto como macro) determina se o fim do *fluxo* foi passado. Quando o fim do arquivo for aprovado, as operações de leitura retornem um indicador de fim de arquivo até que o fluxo seja fechado ou até que [o fluxo seja](rewind.md)fechado, **fsetpos,** [fseek](fseek-fseeki64.md)ou **mais claror** é chamado contra ele.

Por exemplo, se um arquivo contém 10 bytes e você lê 10 bytes do arquivo, **feof** retornará 0 porque, mesmo que o ponteiro do arquivo esteja no final do arquivo, você não tentou ler além do final. Somente depois de tentar ler um 11º byte **será que feof** devolver um valor não zero.

Por padrão, o estado global desta função é escopo para o aplicativo. Para mudar isso, consulte [Estado Global no CRT](../global-state.md).

## <a name="requirements"></a>Requisitos

|Função|Cabeçalho necessário|
|--------------|---------------------|
|**feof**|\<stdio.h>|

Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

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

## <a name="input-crt_feoftxt"></a>Entrada: crt_feof.txt

```Input
Line one.
Line two.
```

### <a name="output"></a>Saída

```Output
Number of bytes read = 19
```

## <a name="see-also"></a>Confira também

[Tratamento de erros](../../c-runtime-library/error-handling-crt.md)<br/>
[E/S de fluxo](../../c-runtime-library/stream-i-o.md)<br/>
[clearerr](clearerr.md)<br/>
[_eof](eof.md)<br/>
[ferror](ferror.md)<br/>
[perror, _wperror](perror-wperror.md)<br/>
