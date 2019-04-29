---
title: ftell, _ftelli64
ms.date: 11/04/2016
apiname:
- _ftelli64
- ftell
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
- _ftelli64
- ftell
helpviewer_keywords:
- ftell function
- ftelli64 function
- _ftelli64 function
- file pointers [C++], getting current position
- file pointers [C++]
ms.assetid: 40149cd8-65f2-42ff-b70c-68e3e918cdd7
ms.openlocfilehash: cc76ad0776ae82637b95d32cdc6254d3c40da5b5
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62332774"
---
# <a name="ftell-ftelli64"></a>ftell, _ftelli64

Obtém a posição atual de um ponteiro de arquivo.

## <a name="syntax"></a>Sintaxe

```C
long ftell(
   FILE *stream
);
__int64 _ftelli64(
   FILE *stream
);
```

### <a name="parameters"></a>Parâmetros

*stream*<br/>
Destino **arquivo** estrutura.

## <a name="return-value"></a>Valor de retorno

**ftell** e **_ftelli64** retornar a posição atual do arquivo. O valor retornado por **ftell** e **_ftelli64** podem não refletir o deslocamento de bytes físico para fluxos abertos no modo de texto, porque o modo de texto faz com que a conversão de linha de retorno de carro. Use **ftell** com [fseek](fseek-fseeki64.md) ou **_ftelli64** com [_fseeki64](fseek-fseeki64.md) para retornar para locais de arquivo corretamente. Em erro, **ftell** e **_ftelli64** invocarão o manipulador de parâmetro inválido, conforme descrito na [validação de parâmetro](../../c-runtime-library/parameter-validation.md). Se a execução puder continuar, essas funções retornarão-1l e definirão **errno** a uma das duas constantes, definida em ERRNO. H. O **EBADF** constante significa que o *fluxo* argumento não é um valor de ponteiro de arquivo válido ou não faz referência a um arquivo aberto. **EINVAL** significa um inválido *stream* argumento foi passado para a função. Em dispositivos incapazes de fazer buscas (como terminais e impressoras), ou quando *stream* não faz referência a um arquivo aberto, o valor retornado será indefinido.

Consulte [_doserrno, errno, _sys_errlist e _sys_nerr](../../c-runtime-library/errno-doserrno-sys-errlist-and-sys-nerr.md) para obter mais informações sobre esses e outros códigos de retorno.

## <a name="remarks"></a>Comentários

O **ftell** e **_ftelli64** funções de recuperar a posição atual do ponteiro do arquivo (se houver) associado *fluxo*. A posição é expressa como um deslocamento relativo ao início do fluxo.

Observe que quando um arquivo é aberto para acrescentar dados, a posição do arquivo atual é determinada pela última operação de E/S e não por onde a gravação seguinte ocorreria. Por exemplo, se um arquivo for aberto para fazer um acréscimo e a última operação tiver sido uma leitura, a posição do arquivo será o ponto em que a operação de leitura seguinte começaria e não onde a próxima gravação começaria. (Quando um arquivo é aberto para fazer um acréscimo, a posição do arquivo é movida para o final do arquivo antes de qualquer operação de gravação.) Se nenhuma operação de E/S tiver ocorrido em um arquivo aberto para acréscimo, a posição do arquivo será o início do arquivo.

No modo de texto, CTRL+Z é interpretado como um caractere de fim do arquivo na entrada. Em arquivos abertos para leitura/gravação **fopen** e todas as rotinas relacionadas a verificar se há um CTRL + Z no final do arquivo e removem-la se possível. Isso é feito porque usar a combinação de **ftell** e [fseek](fseek-fseeki64.md) ou **_ftelli64** e [_fseeki64](fseek-fseeki64.md)para movimentação dentro de um arquivo que termina com CTRL + Z pode causar **ftell** ou **_ftelli64** se comportar incorretamente perto do fim do arquivo.

Essa função bloqueia o thread de chamada durante a execução e, portanto, é thread-safe. Para obter uma versão sem bloqueio, consulte **ftell_nolock**.

## <a name="requirements"></a>Requisitos

|Função|Cabeçalho necessário|Cabeçalhos opcionais|
|--------------|---------------------|----------------------|
|**ftell**|\<stdio.h>|\<errno.h>|
|**_ftelli64**|\<stdio.h>|\<errno.h>|

Para obter informações adicionais sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="example"></a>Exemplo

```C
// crt_ftell.c
// This program opens a file named CRT_FTELL.C
// for reading and tries to read 100 characters. It
// then uses ftell to determine the position of the
// file pointer and displays this position.

#include <stdio.h>

FILE *stream;

int main( void )
{
   long position;
   char list[100];
   if( fopen_s( &stream, "crt_ftell.c", "rb" ) == 0 )
   {
      // Move the pointer by reading data:
      fread( list, sizeof( char ), 100, stream );
      // Get position after read:
      position = ftell( stream );
      printf( "Position after trying to read 100 bytes: %ld\n",
              position );
      fclose( stream );
   }
}
```

```Output
Position after trying to read 100 bytes: 100
```

## <a name="see-also"></a>Consulte também

[E/S de fluxo](../../c-runtime-library/stream-i-o.md)<br/>
[fopen, _wfopen](fopen-wfopen.md)<br/>
[fgetpos](fgetpos.md)<br/>
[fseek, _fseeki64](fseek-fseeki64.md)<br/>
[_lseek, _lseeki64](lseek-lseeki64.md)<br/>
