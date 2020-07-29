---
title: Funções de pesquisa de nome de arquivo
ms.date: 11/04/2016
api_location:
- msvcr100.dll
- msvcr120.dll
- msvcr90.dll
- msvcrt.dll
- msvcr80.dll
- msvcr110.dll
- msvcr110_clr0400.dll
api_type:
- DLLExport
topic_type:
- apiref
helpviewer_keywords:
- file names [C++], searching for
- _find function
- wfind function
- find function
- _wfind function
ms.assetid: 2bc2f8ef-44e4-4271-b3e8-666d36fde828
ms.openlocfilehash: fb5cc0e18d150d4171e33038e27810989c0f503b
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87226236"
---
# <a name="filename-search-functions"></a>Funções de pesquisa de nome de arquivo

Essas funções procuram por e fecham pesquisas de nomes de arquivo especificados:

- [_findnext, _wfindnext](../c-runtime-library/reference/findnext-functions.md)

- [_findfirst, _wfindfirst](../c-runtime-library/reference/findfirst-functions.md)

- [_findclose](../c-runtime-library/reference/findclose.md)

## <a name="remarks"></a>Comentários

A função `_findfirst` fornece informações sobre a primeira instância de um nome de arquivo que corresponde ao arquivo especificado no argumento `filespec`. Você pode usar `filespec` em qualquer combinação de caracteres curinga que tenha suporte do sistema operacional do host.

As funções retornam informações sobre o arquivo em uma estrutura `_finddata_t`, que é definida em ES.h. Várias funções na família usam muitas variações da estrutura `_finddata_t`. A estrutura `_finddata_t` básica inclui os seguintes elementos:

`unsigned attrib`<br/>
Atributo do arquivo.

`time_t time_create`<br/>
Hora de criação do arquivo (-1L para sistemas de arquivos FAT). Essa hora é armazenada no formato UTC. Para converter para a hora local, use [localtime_s](../c-runtime-library/reference/localtime-s-localtime32-s-localtime64-s.md).

`time_t time_access`<br/>
Hora do último acesso do arquivo (-1L para sistemas de arquivo FAT). Essa hora é armazenada no formato UTC. Para converter para a hora local, use `localtime_s`.

`time_t time_write`<br/>
Hora da última gravação no arquivo. Essa hora é armazenada no formato UTC. Para converter para a hora local, use `localtime_s`.

`_fsize_t size`<br/>
Comprimento do arquivo em bytes.

`char name`[ `_MAX_PATH`] Nome com terminação nula do arquivo ou diretório correspondente, sem o caminho.

Em sistemas de arquivos que não dão suporte aos horários de criação e de último acesso de um arquivo, como o sistema FAT, os campos `time_create` e `time_access` são sempre -1L.

`_MAX_PATH` é definidos em Stdlib.h como 260 bytes.

Não é possível especificar atributos de destino (como `_A_RDONLY`) para limitar a operação de localização. Esses atributos retornam no campo `attrib` da estrutura `_finddata_t` e podem ter os seguintes valores (definidos em ES.h). Os usuários não devem depender exclusivamente desses valores possíveis para o campo `attrib`.

`_A_ARCH`<br/>
Arquivo morto. Definido sempre que o arquivo é alterado e limpo com o comando **BACKUP**. Valor: 0x20.

`_A_HIDDEN`<br/>
Arquivo oculto. Normalmente não visto com o comando DIR, a menos que você use a opção **/AH**. Retorna informações sobre arquivos normais e arquivos que possuem esse atributo. Valor: 0x02.

`_A_NORMAL`<br/>
Normal. O arquivo não tem outros atributos definidos e pode ser lido ou gravado sem restrição. Valor: 0x00.

`_A_RDONLY`<br/>
Somente leitura. O arquivo não pode ser aberto para gravação, e não é possível criar um arquivo com o mesmo nome. Valor: 0x01.

`_A_SUBDIR`<br/>
Subdiretório. Valor: 0x10.

`_A_SYSTEM`<br/>
Arquivo do sistema. Normalmente não visto com o comando **DIR**, a menos que a opção **/A** ou **/A:S** seja usada. Valor: 0x04.

`_findnext` localiza o próximo nome, se houver algum, que corresponde ao argumento `filespec` especificado em uma chamada anterior para `_findfirst`. O argumento `fileinfo` deve apontar para uma estrutura inicializada pela chamada anterior a `_findfirst`. Se uma correspondência for encontrada, o conteúdo da estrutura de `fileinfo` será alterado conforme descrito anteriormente. Caso contrário, ele permanecerá inalterado. `_findclose` fecha o identificador de pesquisa especificado e libera todos os recursos associados a `_findfirst` e `_findnext`. O identificador retornado por `_findfirst` ou `_findnext` deve ser passado primeiro para `_findclose`, antes que as operações de modificação, como excluir, possam ser executadas nos diretórios que formam os caminhos passados a eles.

Você pode aninhar as funções `_find`. Por exemplo, se uma chamada para `_findfirst` ou `_findnext` localizar o arquivo que é um subdiretório, uma nova pesquisa poderá ser iniciada com outra chamada para `_findfirst` ou `_findnext`.

`_wfindfirst`e `_wfindnext` são versões de caractere largo de `_findfirst` e `_findnext`. O argumento da estrutura das versões de caractere largo tem o tipo de dados `_wfinddata_t`, que é definido em ES.h e em Wchar.h. Os campos desse tipo de dados são os mesmos que os do `_finddata_t` tipo de dados, exceto que no `_wfinddata_t` campo nome é do tipo **`wchar_t`** em vez do tipo **`char`** . Caso contrário, `_wfindfirst`, `_wfindnext` se comportarão de modo idêntico a `_findfirst` e `_findnext`.

`_findfirst` e `_findnext` usam o tipo de tempo de 64 bits. Se você precisar usar o tipo de tempo de 32 bits antigo, defina `_USE_32BIT_TIME_T`. As versões dessas funções que têm o sufixo `32` em seus nomes usam o tipo de tempo de 32 bits, e aquelas com o sufixo `64` usam o tipo de tempo de 64 bits.

As funções `_findfirst32i64`, `_findnext32i64`, `_wfindfirst32i64` e `_wfindnext32i64` também se comportam de forma idêntica às versões de tipo de tempo de 32 bits dessas funções, exceto que usam e retornam os comprimentos de arquivo de 64 bits. As funções `_findfirst64i32`, `_findnext64i32`, `_wfindfirst64i32` e `_wfindnext64i32` usam o tipo de tempo de 64 bits, mas usam os comprimentos de arquivo de 32 bits. Essas funções usam variações apropriadas do tipo `_finddata_t` no qual os campos têm tipos diferentes para o tempo e o tamanho do arquivo.

`_finddata_t` é na verdade uma macro avaliada como `_finddata64i32_t` (ou `_finddata32_t` se `_USE_32BIT_TIME_T` for definido). A tabela a seguir resume as variações em `_finddata_t`:

|Estrutura|Tipo de hora|Tipo de tamanho do arquivo|
|---------------|---------------|--------------------|
|`_finddata_t`, `_wfinddata_t`|`__time64_t`|`_fsize_t`|
|`_finddata32_t`, `_wfinddata32_t`|`__time32_t`|`_fsize_t`|
|`__finddata64_t`, `__wfinddata64_t`|`__time64_t`|**`__int64`**|
|`_finddata32i64_t`, `_wfinddata32i64_t`|`__time32_t`|**`__int64`**|
|`_finddata64i32_t`, `_wfinddata64i32_t`|`__time64_t`|`_fsize_t`|

`_fsize_t`é um **`typedef`** para **`unsigned long`** (32 bits).

## <a name="example"></a>Exemplo

```c
// crt_find.c
// This program uses the 32-bit _find functions to print
// a list of all files (and their attributes) with a .C extension
// in the current directory.

#include <stdio.h>
#include <stdlib.h>
#include <io.h>
#include <time.h>

int main( void )
{
   struct _finddata_t c_file;
   intptr_t hFile;

   // Find first .c file in current directory
   if( (hFile = _findfirst( "*.c", &c_file )) == -1L )
      printf( "No *.c files in current directory!\n" );
   else
   {
      printf( "Listing of .c files\n\n" );
      printf( "RDO HID SYS ARC  FILE         DATE %25c SIZE\n", ' ' );
      printf( "--- --- --- ---  ----         ---- %25c ----\n", ' ' );
      do {
         char buffer[30];
         printf( ( c_file.attrib & _A_RDONLY ) ? " Y  " : " N  " );
         printf( ( c_file.attrib & _A_HIDDEN ) ? " Y  " : " N  " );
         printf( ( c_file.attrib & _A_SYSTEM ) ? " Y  " : " N  " );
         printf( ( c_file.attrib & _A_ARCH )   ? " Y  " : " N  " );
         ctime_s( buffer, _countof(buffer), &c_file.time_write );
         printf( " %-12s %.24s  %9ld\n",
            c_file.name, buffer, c_file.size );
      } while( _findnext( hFile, &c_file ) == 0 );
      _findclose( hFile );
   }
}
```

```Output
Listing of .c files

RDO HID SYS ARC  FILE         DATE                           SIZE
--- --- --- ---  ----         ----                           ----
N   N   N   Y   blah.c       Wed Feb 13 09:21:42 2002       1715
N   N   N   Y   test.c       Wed Feb 06 14:30:44 2002        312
```

## <a name="see-also"></a>Confira também

[Chamadas do sistema](../c-runtime-library/system-calls.md)
