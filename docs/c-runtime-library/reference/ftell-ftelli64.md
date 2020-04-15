---
title: ftell, _ftelli64
ms.date: 4/2/2020
api_name:
- _ftelli64
- ftell
- _o__ftelli64
- _o_ftell
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
- _ftelli64
- ftell
helpviewer_keywords:
- ftell function
- ftelli64 function
- _ftelli64 function
- file pointers [C++], getting current position
- file pointers [C++]
ms.assetid: 40149cd8-65f2-42ff-b70c-68e3e918cdd7
ms.openlocfilehash: bfe79610161a7f4032517d9f7eaa0de50be18e50
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81345624"
---
# <a name="ftell-_ftelli64"></a>ftell, _ftelli64

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

*fluxo*<br/>
Estrutura **de arquivo** de destino.

## <a name="return-value"></a>Valor retornado

**ftell** e **_ftelli64** retornar a posição atual do arquivo. O valor devolvido por **ftell** e **_ftelli64** pode não refletir a compensação de byte físico para fluxos abertos no modo texto, porque o modo texto causa a tradução de feed de linha de retorno do transporte. Use **ftell** com [fseek](fseek-fseeki64.md) ou **_ftelli64** com [_fseeki64](fseek-fseeki64.md) para retornar aos locais de arquivo corretamente. No erro, **ftell** e **_ftelli64** invocar o manipulador de parâmetros inválidos, conforme descrito na [Validação de Parâmetros](../../c-runtime-library/parameter-validation.md). Se a execução for permitida, essas funções retornam -1L e definem **errno** a uma das duas constantes, definidas em ERRNO. H. A **constante EBADF** significa que o argumento *do fluxo* não é um valor de ponteiro de arquivo válido ou não se refere a um arquivo aberto. **EINVAL** significa que um argumento de *fluxo* inválido foi passado para a função. Em dispositivos incapazes de procurar (como terminais e impressoras), ou quando *o fluxo* não se refere a um arquivo aberto, o valor de devolução é indefinido.

Veja [_doserrno, errno, _sys_errlist e _sys_nerr](../../c-runtime-library/errno-doserrno-sys-errlist-and-sys-nerr.md) para obter mais informações sobre esses, e outros, códigos de devolução.

## <a name="remarks"></a>Comentários

As funções **ftell** e **_ftelli64** recuperam a posição atual do ponteiro do arquivo (se houver) associada ao *fluxo*. A posição é expressa como um deslocamento relativo ao início do fluxo.

Observe que quando um arquivo é aberto para acrescentar dados, a posição do arquivo atual é determinada pela última operação de E/S e não por onde a gravação seguinte ocorreria. Por exemplo, se um arquivo for aberto para fazer um acréscimo e a última operação tiver sido uma leitura, a posição do arquivo será o ponto em que a operação de leitura seguinte começaria e não onde a próxima gravação começaria. (Quando um arquivo é aberto para anexação, a posição do arquivo é movida para o fim do arquivo antes de qualquer operação de gravação.) Se nenhuma operação de I/O ainda não ocorreu em um arquivo aberto para anexação, a posição do arquivo é o início do arquivo.

No modo de texto, CTRL+Z é interpretado como um caractere de fim do arquivo na entrada. Em arquivos abertos para leitura/escrita, **fopen** e todas as rotinas relacionadas verifique se há um CTRL+Z no final do arquivo e remova-o se possível. Isso é feito porque usar a combinação de **ftell** e [fseek](fseek-fseeki64.md) ou **_ftelli64** e [_fseeki64](fseek-fseeki64.md), para mover dentro de um arquivo que termina com um CTRL+Z pode fazer com que **ftell** ou **_ftelli64** se comportem incorretamente perto do final do arquivo.

Essa função bloqueia o thread de chamada durante a execução e, portanto, é thread-safe. Para obter uma versão sem travamento, **consulte _ftell_nolock**.

Por padrão, o estado global desta função é escopo para o aplicativo. Para mudar isso, consulte [Estado Global no CRT](../global-state.md).

## <a name="requirements"></a>Requisitos

|Função|Cabeçalho necessário|Cabeçalhos opcionais|
|--------------|---------------------|----------------------|
|**ftell**|\<stdio.h>|\<errno.h>|
|**_ftelli64**|\<stdio.h>|\<errno.h>|

Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

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

## <a name="see-also"></a>Confira também

[E/S de fluxo](../../c-runtime-library/stream-i-o.md)<br/>
[fopen, _wfopen](fopen-wfopen.md)<br/>
[fgetpos](fgetpos.md)<br/>
[fseek, _fseeki64](fseek-fseeki64.md)<br/>
[_lseek, _lseeki64](lseek-lseeki64.md)<br/>
