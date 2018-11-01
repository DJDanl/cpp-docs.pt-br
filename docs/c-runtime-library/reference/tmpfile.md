---
title: tmpfile
ms.date: 11/04/2016
apiname:
- tmpfile
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
- tmpfile
helpviewer_keywords:
- temporary files
- tmpfile function
- temporary files, creating
ms.assetid: c4a4dc24-70da-438d-ae4e-98352d88e375
ms.openlocfilehash: 98afcb7a3e04a96a1b08bc1b975634153e550839
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50530319"
---
# <a name="tmpfile"></a>tmpfile

Cria um arquivo temporário. Essa função foi preterida pois uma versão mais segura está disponível; consulte [tmpfile_s](tmpfile-s.md).

## <a name="syntax"></a>Sintaxe

```C
FILE *tmpfile( void );
```

## <a name="return-value"></a>Valor de retorno

Se for bem-sucedido, **tmpfile** retorna um ponteiro de fluxo. Caso contrário, retornará um **nulo** ponteiro.

## <a name="remarks"></a>Comentários

O **tmpfile** função cria um arquivo temporário e retorna um ponteiro nesse fluxo. O arquivo temporário é criado no diretório raiz. Para criar um arquivo temporário em um diretório que não seja a raiz, use [tmpnam](tempnam-wtempnam-tmpnam-wtmpnam.md) ou [tempnam](tempnam-wtempnam-tmpnam-wtmpnam.md) em conjunto com [fopen](fopen-wfopen.md).

Se o arquivo não pode ser aberto, **tmpfile** retorna um **nulo** ponteiro. Esse arquivo temporário é excluído automaticamente quando o arquivo é fechado quando o programa for encerrado normalmente ou quando **rmtmp** é chamado, supondo que o diretório de trabalho atual não é alterado. O arquivo temporário é aberto no **w + b** modo (leitura/gravação binária).

Falha pode ocorrer se você tentar mais de TMP_MAX (consulte STDIO. H) chamadas de com **tmpfile**.

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|
|-------------|---------------------|
|**tmpfile**|\<stdio.h>|

Para obter informações adicionais sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="example"></a>Exemplo

> [!NOTE]
> Esse exemplo exige privilégios administrativos para ser executado no Windows Vista.

```C
// crt_tmpfile.c
// compile with: /W3
// This program uses tmpfile to create a
// temporary file, then deletes this file with _rmtmp.
#include <stdio.h>

int main( void )
{
   FILE *stream;
   int  i;

   // Create temporary files.
   for( i = 1; i <= 3; i++ )
   {
      if( (stream = tmpfile()) == NULL ) // C4996
      // Note: tmpfile is deprecated; consider using tmpfile_s instead
         perror( "Could not open new temporary file\n" );
      else
         printf( "Temporary file %d was created\n", i );
   }

   // Remove temporary files.
   printf( "%d temporary files deleted\n", _rmtmp() );
}
```

```Output
Temporary file 1 was created
Temporary file 2 was created
Temporary file 3 was created
3 temporary files deleted
```

## <a name="see-also"></a>Consulte também

[E/S de fluxo](../../c-runtime-library/stream-i-o.md)<br/>
[_rmtmp](rmtmp.md)<br/>
[_tempnam, _wtempnam, tmpnam, _wtmpnam](tempnam-wtempnam-tmpnam-wtmpnam.md)<br/>
