---
title: _mktemp, _wmktemp
ms.date: 11/04/2016
apiname:
- _wmktemp
- _mktemp
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
- _tmktemp
- wmktemp
- tmktemp
- _wmktemp
- _mktemp
helpviewer_keywords:
- _wmktemp function
- _mktemp function
- files [C++], temporary
- tmktemp function
- _tmktemp function
- wmktemp function
- mktemp function
- temporary files [C++]
ms.assetid: 055eb539-a8c2-4a7d-be54-f5b6d1eb5c85
ms.openlocfilehash: c1c5f0ee12c9e07d76405014bb4a6a6ecc7d97e6
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62156506"
---
# <a name="mktemp-wmktemp"></a>_mktemp, _wmktemp

Cria um nome de arquivo exclusivo. Estão disponíveis versões mais seguras dessas funções; consulte [_mktemp_s, _wmktemp_s](mktemp-s-wmktemp-s.md).

## <a name="syntax"></a>Sintaxe

```C
char *_mktemp(
   char *nameTemplate
);
wchar_t *_wmktemp(
   wchar_t *nameTemplate
);
template <size_t size>
char *_mktemp(
   char (&nameTemplate)[size]
); // C++ only
template <size_t size>
wchar_t *_wmktemp(
   wchar_t (&nameTemplate)[size]
); // C++ only
```

### <a name="parameters"></a>Parâmetros

*nameTemplate*<br/>
Padrão de nome de arquivo.

## <a name="return-value"></a>Valor de retorno

Cada uma dessas funções retorna um ponteiro para o nameTemplate modificado. A função retornará **nulo** se *nameTemplate* está mal formado ou não mais nomes exclusivos podem ser criados a partir de determinado nameTemplate.

## <a name="remarks"></a>Comentários

O **mktemp** função cria um nome de arquivo exclusivo modificando o *nameTemplate* argumento. **mktemp** manipula automaticamente argumentos de cadeia de caracteres multibyte conforme apropriado, reconhecendo sequências de caracteres multibyte de acordo com a página de código multibyte em uso no momento pelo sistema de tempo de execução. **wmktemp** é uma versão de caractere largo de **mktemp**; o argumento e o valor retornado de **wmktemp** são cadeias de caracteres largos. **wmktemp** e **mktemp** se comportam de forma idêntica caso contrário, exceto que **wmktemp** não manipula cadeias de caracteres multibyte.

### <a name="generic-text-routine-mappings"></a>Mapeamentos da rotina de texto genérico

|Rotina Tchar.h|_UNICODE e _MBCS não definidos|_MBCS definido|_UNICODE definido|
|---------------------|--------------------------------------|--------------------|-----------------------|
|**_tmktemp**|**_mktemp**|**_mktemp**|**_wmktemp**|

O *nameTemplate* argumento tem o formato *base*XXXXXX, em que *base* é a parte do novo nome do arquivo que você fornece e cada X é um espaço reservado para um caractere fornecido pelo **mktemp**. Cada caractere de espaço reservado na *nameTemplate* deve ser um x maiusculo. **mktemp** preserva *base* e substitui o primeiro X à direita com um caractere alfabético. **mktemp** substitui à direita seguinte x com um valor de cinco dígitos; esse valor é um número exclusivo que identifica o processo de chamada ou em programas multithread, o thread de chamada.

Cada chamada bem-sucedida para **mktemp** modifica *nameTemplate*. Em cada chamada subsequente do mesmo processo ou thread com o mesmo *nameTemplate* argumento **mktemp** procura nomes de arquivo que correspondem aos nomes retornados por **mktemp** em chamadas anteriores. Se o arquivo não existe para um determinado nome, **mktemp** retorna esse nome. Se existirem arquivos para todos os nomes retornados anteriormente, **mktemp** cria um novo nome, substituindo o caractere alfabético que ele usado no nome retornado anteriormente com a próxima letra de minúscula disponível, em ordem, de 'a' a 'z'. Por exemplo, se *base* é:

> **fn**

e o valor de cinco dígitos fornecido pelo **mktemp** for 12345, o primeiro nome retornado será:

> **fna12345**

Se esse nome é usado para criar o arquivo FNA12345 e esse arquivo ainda existe, o próximo nome retornado em uma chamada do mesmo processo ou thread com o mesmo *base* para *nameTemplate* é:

> **fnb12345**

Se FNA12345 não existir, o próximo nome retornado será novamente:

> **fna12345**

**mktemp** pode criar no máximo 26 nomes de arquivo exclusivos para qualquer determinada combinação de *base* e *nameTemplate* valores. Portanto, FNZ12345 é o último nome de arquivo exclusivo **mktemp** pode criar para o *base* e *nameTemplate* valores usados neste exemplo.

Em caso de falha, **errno** está definido. Se *nameTemplate* tem um formato inválido (por exemplo, menos de 6 x), **errno** está definido como **EINVAL**. Se **mktemp** não pode criar um nome exclusivo porque todos os 26 nomes de arquivo possíveis já existem, **mktemp** nameTemplate define uma cadeia de caracteres vazia e retorna **EEXIST**.

No C++, essas funções têm sobrecargas de modelo que invocam os equivalentes mais novos e seguros dessas funções. Para obter mais informações, consulte [Sobrecargas de modelo seguro](../../c-runtime-library/secure-template-overloads.md).

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|
|-------------|---------------------|
|**_mktemp**|\<io.h>|
|**_wmktemp**|\<io.h> ou \<wchar.h>|

Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="example"></a>Exemplo

```C
// crt_mktemp.c
// compile with: /W3
/* The program uses _mktemp to create
* unique filenames. It opens each filename
* to ensure that the next name is unique.
*/

#include <io.h>
#include <string.h>
#include <stdio.h>
#include <errno.h>

char *template = "fnXXXXXX";
char *result;
char names[27][9];

int main( void )
{
   int i;
   FILE *fp;

   for( i = 0; i < 27; i++ )
   {
      strcpy_s( names[i], sizeof( names[i] ), template );
      /* Attempt to find a unique filename: */
      result = _mktemp( names[i] );  // C4996
      // Note: _mktemp is deprecated; consider using _mktemp_s instead
      if( result == NULL )
      {
         printf( "Problem creating the template\n" );
         if (errno == EINVAL)
         {
             printf( "Bad parameter\n");
         }
         else if (errno == EEXIST)
         {
             printf( "Out of unique filenames\n");
         }
      }
      else
      {
         fopen_s( &fp, result, "w" );
         if( fp != NULL )
            printf( "Unique filename is %s\n", result );
         else
            printf( "Cannot open %s\n", result );
         fclose( fp );
      }
   }
}
```

```Output
Unique filename is fna03912
Unique filename is fnb03912
Unique filename is fnc03912
Unique filename is fnd03912
Unique filename is fne03912
Unique filename is fnf03912
Unique filename is fng03912
Unique filename is fnh03912
Unique filename is fni03912
Unique filename is fnj03912
Unique filename is fnk03912
Unique filename is fnl03912
Unique filename is fnm03912
Unique filename is fnn03912
Unique filename is fno03912
Unique filename is fnp03912
Unique filename is fnq03912
Unique filename is fnr03912
Unique filename is fns03912
Unique filename is fnt03912
Unique filename is fnu03912
Unique filename is fnv03912
Unique filename is fnw03912
Unique filename is fnx03912
Unique filename is fny03912
Unique filename is fnz03912
Problem creating the template.
Out of unique filenames.
```

## <a name="see-also"></a>Consulte também

[Manipulação de Arquivos](../../c-runtime-library/file-handling.md)<br/>
[fopen, _wfopen](fopen-wfopen.md)<br/>
[_getmbcp](getmbcp.md)<br/>
[_getpid](getpid.md)<br/>
[_open, _wopen](open-wopen.md)<br/>
[_setmbcp](setmbcp.md)<br/>
[_tempnam, _wtempnam, tmpnam, _wtmpnam](tempnam-wtempnam-tmpnam-wtmpnam.md)<br/>
[tmpfile](tmpfile.md)<br/>
