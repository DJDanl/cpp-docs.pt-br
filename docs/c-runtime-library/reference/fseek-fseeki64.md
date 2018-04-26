---
title: fseek, _fseeki64 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.reviewer: ''
ms.suite: ''
ms.technology:
- cpp-standard-libraries
ms.tgt_pltfrm: ''
ms.topic: reference
apiname:
- _fseeki64
- fseek
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
apitype: DLLExport
f1_keywords:
- fseek
- _fseeki64
dev_langs:
- C++
helpviewer_keywords:
- _fseeki64 function
- fseeki64 function
- fseek function
- file pointers [C++], moving
- file pointers [C++]
- seek file pointers
ms.assetid: f6bb1f8b-891c-426e-9e14-0e7e5c62df70
caps.latest.revision: 23
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 266eb1589c97b177057e6a72874261c745acb475
ms.sourcegitcommit: ef859ddf5afea903711e36bfd89a72389a12a8d6
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/20/2018
---
# <a name="fseek-fseeki64"></a>fseek, _fseeki64

Move o ponteiro do arquivo para um local especificado.

## <a name="syntax"></a>Sintaxe

```C
int fseek(
   FILE *stream,
   long offset,
   int origin
);
int _fseeki64(
   FILE *stream,
   __int64 offset,
   int origin
);
```

### <a name="parameters"></a>Parâmetros

*Fluxo*<br/>
Ponteiro para a estrutura **FILE**.

*deslocamento*<br/>
Número de bytes de *origem*.

*origem*<br/>
Posição inicial.

## <a name="return-value"></a>Valor de retorno

Se for bem-sucedido, **fseek** e **fseeki64** retornará 0. Caso contrário, retornará um valor diferente de zero. Em dispositivos sem capacidade de busca, o valor retornado será indefinido. Se *fluxo* é um ponteiro nulo, ou se *origem* não é um dos valores permitidos descritos abaixo, **fseek** e **fseeki64** invocar inválido manipulador de parâmetro, conforme descrito em [validação do parâmetro](../../c-runtime-library/parameter-validation.md). Se a execução é permitida para continuar, essas funções definido **errno** para **EINVAL** e retorne -1.

## <a name="remarks"></a>Comentários

O **fseek** e **fseeki64** move o ponteiro do arquivo (se houver) associado com as funções *fluxo* para um novo local é *deslocamento* bytes do *origem*. A operação seguinte no fluxo ocorre no novo local. Em um fluxo aberto para atualização, a operação seguinte pode ser uma leitura ou uma gravação. O argumento *origem* deve ser uma das seguintes constantes definidas em STDIO. H:

|valor de origem|Significado|
|-|-|
**SEEK_CUR**|Posição atual do ponteiro de arquivo.
**SEEK_END**|Final do arquivo.
**SEEK_SET**|Início do arquivo.

Você pode usar **fseek** e **fseeki64** para reposicionar o ponteiro em qualquer lugar em um arquivo. O ponteiro também pode ser posicionado após o final do arquivo. **fseek** e **fseeki64** limpa o indicador de fim de arquivo e nega o efeito de qualquer antes [ungetc](ungetc-ungetwc.md) chamadas *fluxo*.

Quando um arquivo é aberto para acrescentar dados, a posição do arquivo atual é determinada pela última operação de E/S e não por onde a gravação seguinte ocorreria. Se nenhuma operação de E/S tiver ocorrido em um arquivo aberto para acréscimo, a posição do arquivo será o início do arquivo.

Para fluxos abertos no modo de texto, **fseek** e **fseeki64** limitaram uso, como conversões de avanço de linha de retorno de carro podem causar **fseek** e **_ fseeki64** para produzir resultados inesperados. A única **fseek** e **fseeki64** operações garantidas em fluxos abertos no modo de texto são:

- buscar com um deslocamento de 0 em relação a qualquer um dos valores de origem.

- Busca do início do arquivo com um valor de deslocamento retornado de uma chamada para [ftell](ftell-ftelli64.md) ao usar **fseek** ou [ftelli64](ftell-ftelli64.md) ao usar **fseeki64**.

Também no modo de texto, CTRL+Z é interpretado como um caractere de fim do arquivo na entrada. Em arquivos abertos para leitura/gravação, [fopen](fopen-wfopen.md) e todas as rotinas relacionadas verificar um CTRL + Z no final do arquivo e removê-la se possível. Isso é feito porque usando a combinação de **fseek** e [ftell](ftell-ftelli64.md) ou **fseeki64** e [ftelli64](ftell-ftelli64.md), mover dentro de um arquivo que termina com pode causar um CTRL + Z **fseek** ou **fseeki64** se comporte incorretamente no final do arquivo.

Quando o CRT abre um arquivo que começa com uma BOM (marca de ordem de byte), o ponteiro do arquivo é posicionado após a BOM (ou seja, no início do conteúdo real do arquivo). Se você tiver **fseek** para o início do arquivo, use [ftell](ftell-ftelli64.md) para obter a posição inicial e **fseek** a ele em vez de posição 0.

Essa função bloqueia outros threads durante a execução e, portanto, é thread-safe. Para obter uma versão sem bloqueio, consulte [fseek_nolock, _fseeki64_nolock](fseek-nolock-fseeki64-nolock.md).

## <a name="requirements"></a>Requisitos

|Função|Cabeçalho necessário|
|--------------|---------------------|
|**fseek**|\<stdio.h>|
|**_fseeki64**|\<stdio.h>|

Para obter informações adicionais sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="example"></a>Exemplo

```C
// crt_fseek.c
// This program opens the file FSEEK.OUT and
// moves the pointer to the file's beginning.

#include <stdio.h>

int main( void )
{
   FILE *stream;
   char line[81];
   int  result;

   if ( fopen_s( &stream, "fseek.out", "w+" ) != 0 )
   {
      printf( "The file fseek.out was not opened\n" );
      return -1;
   }
   fprintf( stream, "The fseek begins here: "
                    "This is the file 'fseek.out'.\n" );
   result = fseek( stream, 23L, SEEK_SET);
   if( result )
      perror( "Fseek failed" );
   else
   {
      printf( "File pointer is set to middle of first line.\n" );
      fgets( line, 80, stream );
      printf( "%s", line );
    }
   fclose( stream );
}
```

```Output
File pointer is set to middle of first line.
This is the file 'fseek.out'.
```

## <a name="see-also"></a>Consulte também

[E/S de fluxo](../../c-runtime-library/stream-i-o.md)<br/>
[fopen, _wfopen](fopen-wfopen.md)<br/>
[ftell, _ftelli64](ftell-ftelli64.md)<br/>
[_lseek, _lseeki64](lseek-lseeki64.md)<br/>
[rewind](rewind.md)<br/>
