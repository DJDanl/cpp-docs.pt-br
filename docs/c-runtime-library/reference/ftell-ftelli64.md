---
title: ftell, _ftelli64 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.reviewer: ''
ms.suite: ''
ms.technology:
- cpp-standard-libraries
ms.tgt_pltfrm: ''
ms.topic: reference
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
dev_langs:
- C++
helpviewer_keywords:
- ftell function
- ftelli64 function
- _ftelli64 function
- file pointers [C++], getting current position
- file pointers [C++]
ms.assetid: 40149cd8-65f2-42ff-b70c-68e3e918cdd7
caps.latest.revision: 19
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 3661f4fa36ff83ca47a4847ff416edb3cef0c2fc
ms.sourcegitcommit: ef859ddf5afea903711e36bfd89a72389a12a8d6
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/20/2018
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

*Fluxo*<br/>
Destino **arquivo** estrutura.

## <a name="return-value"></a>Valor de retorno

**ftell** e **ftelli64** retornar a posição atual do arquivo. O valor retornado por **ftell** e **ftelli64** podem não refletir o deslocamento de byte físico para fluxos aberto no modo de texto, como o modo de texto faz com que a conversão de avanço de linha de retorno de carro. Use **ftell** com [fseek](fseek-fseeki64.md) ou **ftelli64** com [fseeki64](fseek-fseeki64.md) para retornar para locais de arquivo corretamente. Em erro, **ftell** e **ftelli64** invocar o manipulador de parâmetro inválido, conforme descrito em [validação do parâmetro](../../c-runtime-library/parameter-validation.md). Se a execução é permitida para continuar, essas funções retornam L-1 e o conjunto **errno** a uma das duas constantes, definidos em ERRNO. H. O **EBADF** constante significa o *fluxo* argumento não é um valor de ponteiro de arquivo válido ou não faz referência a um arquivo aberto. **EINVAL** significa inválido *fluxo* argumento foi passado para a função. Em dispositivos sem capacidade de busca (como terminais e impressoras), ou quando *fluxo* não se refere a um arquivo aberto, o valor retornado é indefinido.

Consulte [_doserrno, errno, _sys_errlist e _sys_nerr](../../c-runtime-library/errno-doserrno-sys-errlist-and-sys-nerr.md) para obter mais informações sobre esses e outros códigos de retorno.

## <a name="remarks"></a>Comentários

O **ftell** e **ftelli64** funções recuperam a posição atual do ponteiro do arquivo (se houver) associada *fluxo*. A posição é expressa como um deslocamento relativo ao início do fluxo.

Observe que quando um arquivo é aberto para acrescentar dados, a posição do arquivo atual é determinada pela última operação de E/S e não por onde a gravação seguinte ocorreria. Por exemplo, se um arquivo for aberto para fazer um acréscimo e a última operação tiver sido uma leitura, a posição do arquivo será o ponto em que a operação de leitura seguinte começaria e não onde a próxima gravação começaria. (Quando um arquivo é aberto para fazer um acréscimo, a posição do arquivo é movida para o final do arquivo antes de qualquer operação de gravação.) Se nenhuma operação de E/S tiver ocorrido em um arquivo aberto para acréscimo, a posição do arquivo será o início do arquivo.

No modo de texto, CTRL+Z é interpretado como um caractere de fim do arquivo na entrada. Em arquivos abertos para leitura/gravação, **fopen** e todas as rotinas relacionadas verificar um CTRL + Z no final do arquivo e removê-la se possível. Isso é feito porque usando a combinação de **ftell** e [fseek](fseek-fseeki64.md) ou **ftelli64** e [fseeki64](fseek-fseeki64.md), mover dentro de um arquivo que termina com pode causar um CTRL + Z **ftell** ou **ftelli64** se comporte incorretamente no final do arquivo.

Essa função bloqueia o thread de chamada durante a execução e, portanto, é thread-safe. Para obter uma versão de não bloqueio, consulte **ftell_nolock**.

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
