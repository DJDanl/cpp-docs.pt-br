---
title: _dup, _dup2 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-standard-libraries
ms.topic: reference
apiname:
- _dup
- _dup2
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
- _dup2
- _dup
dev_langs:
- C++
helpviewer_keywords:
- _dup2 function
- dup function
- file handles [C++], duplicating
- file handles [C++], reassigning
- dup2 function
- _dup function
ms.assetid: 4d07e92c-0d76-4832-a770-dfec0e7a0cfa
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 820172e1e6ab4ad007c89b2b40f03512134f0f0d
ms.sourcegitcommit: 9a0905c03a73c904014ec9fd3d6e59e4fa7813cd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/29/2018
ms.locfileid: "43215947"
---
# <a name="dup-dup2"></a>_dup, _dup2

Cria um segundo descritor de arquivo para um arquivo aberto (**DUP**), ou reatribui um descritor de arquivo (**_dup2**).

## <a name="syntax"></a>Sintaxe

```C
int _dup( int fd );
int _dup2( int fd1, int fd2 );
```

### <a name="parameters"></a>Parâmetros

*FD*, *fd1*<br/>
Descritores de arquivo que fazem referência ao arquivo aberto.

*fd2*<br/>
Qualquer descritor de arquivo.

## <a name="return-value"></a>Valor de retorno

**DUP** retorna um novo descritor de arquivo. **_dup2** retorna 0 para indicar êxito. Se ocorrer um erro, cada função retornará -1 e definirá **errno** à **EBADF** se o descritor de arquivo é inválido ou a **EMFILE** se não há outros descritores de arquivo disponíveis. No caso de um descritor de arquivo inválido, a função também invoca o manipulador de parâmetro inválido, como descrito em [Validação do parâmetro](../../c-runtime-library/parameter-validation.md).

Para obter mais informações sobre esses e outros códigos de retorno, consulte [_doserrno, errno, _sys_errlist e _sys_nerr](../../c-runtime-library/errno-doserrno-sys-errlist-and-sys-nerr.md).

## <a name="remarks"></a>Comentários

O **DUP** e **_dup2** funções associar um segundo descritor de arquivo com um arquivo aberto. Essas funções podem ser usadas para associar um descritor de arquivo predefinido, como **stdout**, com um arquivo diferente. As operações no arquivo podem ser realizadas usando um descritor de arquivo. O tipo de acesso permitido para o arquivo não é afetado pela criação de um novo descritor. **DUP** retorna o próximo descritor de arquivo disponível para o arquivo. **_dup2** força *fd2* para se referir ao mesmo arquivo como *fd1*. Se *fd2* está associado com um arquivo aberto no momento da chamada, esse arquivo é fechado.

Ambos **DUP** e **_dup2** aceitam descritores de arquivo como parâmetros. Para passar um fluxo (`FILE *`) para qualquer uma dessas funções, use [fileno](fileno.md). O **fileno** rotina retorna o descritor de arquivo atualmente associado com o fluxo fornecido. O exemplo a seguir mostra como associar **stderr** (definido como `FILE *` em stdio. h) com um descritor de arquivo:

```C
int cstderr = _dup( _fileno( stderr ));
```

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|
|-------------|---------------------|
|**_dup**|\<io.h>|
|**_dup2**|\<io.h>|

Não há suporte para o console em aplicativos da plataforma Universal do Windows (UWP). Os identificadores de fluxo padrão que estão associados com o console **stdin**, **stdout**, e **stderr**, deverá ser redirecionado para funções de tempo de execução C possam ser usados em aplicativos UWP . Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="example"></a>Exemplo

```C
// crt_dup.c
// This program uses the variable old to save
// the original stdout. It then opens a new file named
// DataFile and forces stdout to refer to it. Finally, it
// restores stdout to its original state.

#include <io.h>
#include <stdlib.h>
#include <stdio.h>

int main( void )
{
   int old;
   FILE *DataFile;

   old = _dup( 1 );   // "old" now refers to "stdout"
                      // Note:  file descriptor 1 == "stdout"
   if( old == -1 )
   {
      perror( "_dup( 1 ) failure" );
      exit( 1 );
   }
   _write( old, "This goes to stdout first\n", 26 );
   if( fopen_s( &DataFile, "data", "w" ) != 0 )
   {
      puts( "Can't open file 'data'\n" );
      exit( 1 );
   }

   // stdout now refers to file "data"
   if( -1 == _dup2( _fileno( DataFile ), 1 ) )
   {
      perror( "Can't _dup2 stdout" );
      exit( 1 );
   }
   puts( "This goes to file 'data'\n" );

   // Flush stdout stream buffer so it goes to correct file
   fflush( stdout );
   fclose( DataFile );

   // Restore original stdout
   _dup2( old, 1 );
   puts( "This goes to stdout\n" );
   puts( "The file 'data' contains:" );
   _flushall();
   system( "type data" );
}
```

```Output
This goes to stdout first
This goes to stdout

The file 'data' contains:
This goes to file 'data'
```

## <a name="see-also"></a>Consulte também

[E/S de nível inferior](../../c-runtime-library/low-level-i-o.md)<br/>
[_close](close.md)<br/>
[_creat, _wcreat](creat-wcreat.md)<br/>
[_open, _wopen](open-wopen.md)<br/>
