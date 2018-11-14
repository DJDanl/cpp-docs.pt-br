---
title: fseek, _fseeki64
ms.date: 11/04/2016
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
- api-ms-win-crt-stdio-l1-1-0.dll
apitype: DLLExport
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
ms.openlocfilehash: e5f775eab370f8f4a3b6a5c1d7f0918ec7efa3ff
ms.sourcegitcommit: 1819bd2ff79fba7ec172504b9a34455c70c73f10
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 11/09/2018
ms.locfileid: "51331081"
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

*fluxo*<br/>
Ponteiro para a estrutura **FILE**.

*deslocamento*<br/>
Número de bytes de *origem*.

*origem*<br/>
Posição inicial.

## <a name="return-value"></a>Valor de retorno

Se for bem-sucedido, **fseek** e **_fseeki64** retornará 0. Caso contrário, retornará um valor diferente de zero. Em dispositivos sem capacidade de busca, o valor retornado será indefinido. Se *stream* for um ponteiro nulo, ou se *origem* não é um dos valores permitidos descritos abaixo, **fseek** e **_fseeki64** invocar o inválido manipulador de parâmetro, conforme descrito em [validação de parâmetro](../../c-runtime-library/parameter-validation.md). Se a execução puder continuar, essas funções definirão **errno** à **EINVAL** e retornarão -1.

## <a name="remarks"></a>Comentários

O **fseek** e **_fseeki64** funções move o ponteiro do arquivo (se houver) associado *fluxo* para um novo local é *deslocamento* bytes do *origem*. A operação seguinte no fluxo ocorre no novo local. Em um fluxo aberto para atualização, a operação seguinte pode ser uma leitura ou uma gravação. O argumento *origem* deve ser uma das constantes a seguir, definidas em STDIO. H:

|valor de origem|Significado|
|-|-|
| **SEEK_CUR** | Posição atual do ponteiro de arquivo. |
| **SEEK_END** | Final do arquivo. |
| **SEEK_SET** | Início do arquivo. |

Você pode usar **fseek** e **_fseeki64** para reposicionar o ponteiro em qualquer lugar em um arquivo. O ponteiro também pode ser posicionado após o final do arquivo. **constantes fseek** e **_fseeki64** limpa o indicador de final de arquivo e anulam o efeito do qualquer anterior [ungetc](ungetc-ungetwc.md) chama contra *fluxo*.

Quando um arquivo é aberto para acrescentar dados, a posição do arquivo atual é determinada pela última operação de E/S e não por onde a gravação seguinte ocorreria. Se nenhuma operação de E/S tiver ocorrido em um arquivo aberto para acréscimo, a posição do arquivo será o início do arquivo.

Para fluxos abertos no modo de texto **fseek** e **_fseeki64** têm uso limitado, pois podem fazer com que as traduções de avanço de linha de retorno de carro **fseek** e **_ fseeki64** para produzir resultados inesperados. As únicas **fseek** e **_fseeki64** operações de garantia de funcionar em fluxos abertos no modo de texto são:

- buscar com um deslocamento de 0 em relação a qualquer um dos valores de origem.

- Buscar desde o início do arquivo com um valor de deslocamento retornado de uma chamada para [ftell](ftell-ftelli64.md) ao usar **fseek** ou [_ftelli64](ftell-ftelli64.md) ao usar **_fseeki64**.

Também no modo de texto, CTRL+Z é interpretado como um caractere de fim do arquivo na entrada. Em arquivos abertos para leitura/gravação [fopen](fopen-wfopen.md) e todas as rotinas relacionadas a verificar se há um CTRL + Z no final do arquivo e removem-la se possível. Isso é feito porque usar a combinação de **fseek** e [ftell](ftell-ftelli64.md) ou **_fseeki64** e [_ftelli64](ftell-ftelli64.md)para movimentação dentro de um arquivo que termina com CTRL + Z pode causar **fseek** ou **_fseeki64** se comportar incorretamente perto do fim do arquivo.

Quando o CRT abre um arquivo que começa com uma BOM (marca de ordem de byte), o ponteiro do arquivo é posicionado após a BOM (ou seja, no início do conteúdo real do arquivo). Se você precisar **fseek** para o início do arquivo, use [ftell](ftell-ftelli64.md) para obter a posição inicial e **fseek** a ele em vez de posicionar 0.

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
