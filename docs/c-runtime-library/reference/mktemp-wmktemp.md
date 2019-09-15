---
title: _mktemp, _wmktemp
ms.date: 11/04/2016
api_name:
- _wmktemp
- _mktemp
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
api_type:
- DLLExport
topic_type:
- apiref
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
ms.openlocfilehash: 7cfca04d4f0df2673a2221f00a1263f73e8516ec
ms.sourcegitcommit: f19474151276d47da77cdfd20df53128fdcc3ea7
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/12/2019
ms.locfileid: "70951575"
---
# <a name="_mktemp-_wmktemp"></a>_mktemp, _wmktemp

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

Cada uma dessas funções retorna um ponteiro para o nametemplate modificado. A função retornará **NULL** se *nametemplate* estiver mal formado ou nenhum nome mais exclusivo puder ser criado a partir de nametemplate fornecido.

## <a name="remarks"></a>Comentários

A função **_mktemp** cria um nome de arquivo exclusivo modificando o argumento *nametemplate* . o **_mktemp** manipula automaticamente argumentos de cadeia de caracteres multibyte conforme apropriado, reconhecendo sequências de caracteres multibyte de acordo com a página de código multibyte atualmente em uso pelo sistema de tempo de execução. **_wmktemp** é uma versão de caractere largo do **_mktemp**; o argumento e o valor de retorno de **_wmktemp** são cadeias de caracteres largos. o **_wmktemp** e o **_mktemp** se comportam de forma idêntica, exceto pelo fato de que o **_wmktemp** não lida com cadeias de caracteres multibyte.

### <a name="generic-text-routine-mappings"></a>Mapeamentos da rotina de texto genérico

|Rotina Tchar.h|_UNICODE e _MBCS não definidos|_MBCS definido|_UNICODE definido|
|---------------------|--------------------------------------|--------------------|-----------------------|
|**_tmktemp**|**_mktemp**|**_mktemp**|**_wmktemp**|

O argumento *nametemplate* tem o formulário *base*xxxxxx, em que *base* é a parte do novo nome de arquivo que você fornece e cada X é um espaço reservado para um caractere fornecido por **_mktemp**. Cada caractere de espaço reservado em *nametemplate* deve ser uma x maiúsculo. **_mktemp** preserva a *base* e substitui o primeiro X à direita por um caractere alfabético. **_mktemp** substitui os seguintes X à direita por um valor de cinco dígitos; Esse valor é um número exclusivo que identifica o processo de chamada ou em programas multithread, o thread de chamada.

Cada chamada bem-sucedida para **_mktemp** modifica *nametemplate*. Em cada chamada subsequente do mesmo processo ou thread com o mesmo argumento *nametemplate* , **_mktemp** verifica os nomes de arquivo que correspondem aos nomes retornados por **_mktemp** nas chamadas anteriores. Se nenhum arquivo existir para um determinado nome, **_mktemp** retornará esse nome. Se existirem arquivos para todos os nomes retornados anteriormente, o **_mktemp** criará um novo nome substituindo o caractere alfabético usado no nome retornado anteriormente pela próxima letra minúscula disponível, em ordem, de ' a ' até ' z '. Por exemplo, se *base* for:

> **fn**

e o valor de cinco dígitos fornecido pelo **_mktemp** é 12345, o primeiro nome retornado é:

> **fna12345**

Se esse nome for usado para criar o arquivo FNA12345 e esse arquivo ainda existir, o próximo nome retornado em uma chamada do mesmo processo ou thread com a mesma *base* para *nametemplate* será:

> **fnb12345**

Se FNA12345 não existir, o próximo nome retornado será novamente:

> **fna12345**

**_mktemp** pode criar no máximo 26 nomes de arquivo exclusivos para qualquer combinação determinada de valores *base* e *nametemplate* . Portanto, FNZ12345 é o último nome de arquivo exclusivo que **_mktemp** pode criar para os valores *base* e *nametemplate* usados neste exemplo.

Em caso de falha, **errno** é definido. Se *nametemplate* tiver um formato inválido (por exemplo, menos de 6 X), **errno** será definido como **EINVAL**. Se **_mktemp** não puder criar um nome exclusivo porque todos os 26 nomes de arquivo possíveis já existem, **_mktemp** define nametemplate como uma cadeia de caracteres vazia e retorna **EEXIST**.

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
