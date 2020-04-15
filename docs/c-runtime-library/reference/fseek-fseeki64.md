---
title: fseek, _fseeki64
ms.date: 4/2/2020
api_name:
- _fseeki64
- fseek
- _o__fseeki64
- _o_fseek
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
- fseek
- _fseeki64
helpviewer_keywords:
- _fseeki64 function
- fseeki64 function
- fseek function
- file pointers [C++], moving
- file pointers [C++]
- seek file pointers
ms.assetid: f6bb1f8b-891c-426e-9e14-0e7e5c62df70
ms.openlocfilehash: e8f6021a0b770f6b435653c190d5968f9ac50a57
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81345761"
---
# <a name="fseek-_fseeki64"></a>fseek, _fseeki64

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

*fluxo*<br/>
Ponteiro para a estrutura **FILE**.

*deslocamento*<br/>
Número de bytes de *origem*.

*Origem*<br/>
Posição inicial.

## <a name="return-value"></a>Valor retornado

Se for bem **sucedido, fseek** e **_fseeki64** retorna 0. Caso contrário, retornará um valor diferente de zero. Em dispositivos sem capacidade de busca, o valor retornado será indefinido. Se *o fluxo* for um ponteiro nulo, ou se a *origem* não for um dos valores permitidos descritos abaixo, **fseek** e **_fseeki64** invocar o manipulador de parâmetros inválidos, conforme descrito na [Validação de Parâmetros](../../c-runtime-library/parameter-validation.md). Se a execução for permitida, essas funções definem **errno** para **EINVAL** e retornam -1.

## <a name="remarks"></a>Comentários

As funções **fseek** e **_fseeki64** moveo o ponteiro de arquivo (se houver) associado ao *fluxo* para um novo local que é *offset* bytes de *origem*. A operação seguinte no fluxo ocorre no novo local. Em um fluxo aberto para atualização, a operação seguinte pode ser uma leitura ou uma gravação. A *origem* do argumento deve ser uma das seguintes constantes, definidas no STDIO. H:

|valor de origem|Significado|
|-|-|
| **SEEK_CUR** | Posição atual do ponteiro de arquivo. |
| **SEEK_END** | Final do arquivo. |
| **SEEK_SET** | Início do arquivo. |

Você pode usar **fseek** e **_fseeki64** para reposicionar o ponteiro em qualquer lugar em um arquivo. O ponteiro também pode ser posicionado após o final do arquivo. **fseek** e **_fseeki64** limpa o indicador de fim de arquivo e nega o efeito de quaisquer chamadas [anteriores](ungetc-ungetwc.md) contra *o fluxo*.

Quando um arquivo é aberto para acrescentar dados, a posição do arquivo atual é determinada pela última operação de E/S e não por onde a gravação seguinte ocorreria. Se nenhuma operação de E/S tiver ocorrido em um arquivo aberto para acréscimo, a posição do arquivo será o início do arquivo.

Para fluxos abertos no modo texto, **fseek** e **_fseeki64** têm uso limitado, porque as traduções de feed de linha de retorno de transporte podem fazer com **que fseek** e **_fseeki64** produzam resultados inesperados. As únicas operações **de fseek** e **_fseeki64** garantidas para trabalhar em fluxos abertos no modo texto são:

- buscar com um deslocamento de 0 em relação a qualquer um dos valores de origem.

- Buscando desde o início do arquivo com um valor de deslocamento retornado de uma chamada para [ftell](ftell-ftelli64.md) ao usar **fseek** ou [_ftelli64](ftell-ftelli64.md) ao usar **_fseeki64**.

Também no modo de texto, CTRL+Z é interpretado como um caractere de fim do arquivo na entrada. Em arquivos abertos para leitura/escrita, [fopen](fopen-wfopen.md) e todas as rotinas relacionadas verifique se há um CTRL+Z no final do arquivo e remova-o se possível. Isso é feito porque usar a combinação de **fseek** e [ftell](ftell-ftelli64.md) ou **_fseeki64** e [_ftelli64](ftell-ftelli64.md), para mover dentro de um arquivo que termina com um CTRL+Z pode fazer com que **fseek** ou **_fseeki64** se comportem incorretamente perto do final do arquivo.

Quando o CRT abre um arquivo que começa com uma BOM (marca de ordem de byte), o ponteiro do arquivo é posicionado após a BOM (ou seja, no início do conteúdo real do arquivo). Se você tiver que **procurar** até o início do arquivo, use [ftell](ftell-ftelli64.md) para obter a posição inicial e **procurar-o** em vez de posicionar-se 0.

Essa função bloqueia outros threads durante a execução e, portanto, é thread-safe. Para obter uma versão sem bloqueio, consulte [fseek_nolock, _fseeki64_nolock](fseek-nolock-fseeki64-nolock.md).

Por padrão, o estado global desta função é escopo para o aplicativo. Para mudar isso, consulte [Estado Global no CRT](../global-state.md).

## <a name="requirements"></a>Requisitos

|Função|Cabeçalho necessário|
|--------------|---------------------|
|**fseek**|\<stdio.h>|
|**_fseeki64**|\<stdio.h>|

Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

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

## <a name="see-also"></a>Confira também

[E/S de fluxo](../../c-runtime-library/stream-i-o.md)<br/>
[fopen, _wfopen](fopen-wfopen.md)<br/>
[ftell, _ftelli64](ftell-ftelli64.md)<br/>
[_lseek, _lseeki64](lseek-lseeki64.md)<br/>
[Rebobinar](rewind.md)<br/>
