---
title: _mktemp, _wmktemp
ms.date: 4/2/2020
api_name:
- _wmktemp
- _mktemp
- _o__mktemp
- _o__wmktemp
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
ms.openlocfilehash: 8affd20ca7826f0d383f749567c9625d61dacd48
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81338712"
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

## <a name="return-value"></a>Valor retornado

Cada uma dessas funções retorna um ponteiro para o nome modificadoTemplate. A função retorna **NULL** se *o nomeTemplate* estiver mal formado ou não mais nomes exclusivos podem ser criados a partir do nome dadoTemplate.

## <a name="remarks"></a>Comentários

A função **_mktemp** cria um nome de arquivo exclusivo modificando o *argumento nameTemplate.* **_mktemp** lida automaticamente com argumentos de seqüência de caracteres de vários bytes conforme apropriado, reconhecendo seqüências de caracteres multibytes de acordo com a página de código multibyte atualmente em uso pelo sistema de tempo de execução. **_wmktemp** é uma versão de grande caráter **da _mktemp;** o argumento e o valor de retorno de **_wmktemp** são cadeias de caracteres amplos. **_wmktemp** e **_mktemp** se comportam de forma idêntica, exceto que **_wmktemp** não lida com cordas de caracteres multibytes.

Por padrão, o estado global desta função é escopo para o aplicativo. Para mudar isso, consulte [Estado Global no CRT](../global-state.md).

### <a name="generic-text-routine-mappings"></a>Mapeamentos da rotina de texto genérico

|Rotina Tchar.h|_UNICODE e _MBCS não definidos|_MBCS definido|_UNICODE definido|
|---------------------|--------------------------------------|--------------------|-----------------------|
|**_tmktemp**|**_mktemp**|**_mktemp**|**_wmktemp**|

O argumento *nameTemplate* tem a *base*de formulárioXXXXXX, onde a *base* é a parte do novo nome de arquivo que você fornece e cada X é um espaço reservado para um caractere fornecido por **_mktemp**. Cada caractere de espaço reservado no *nomeTemplate* deve ser um X maiúsculo **_mktemp** preserva *a base* e substitui o primeiro X de arrasto por um caractere alfabético. **_mktemp** substitui os Seguintes X's por um valor de cinco dígitos; esse valor é um número único que identifica o processo de chamada, ou em programas multithreaded, o segmento de chamada.

Cada chamada bem sucedida para **_mktemp** modifica *o nameTemplate*. Em cada chamada subseqüente do mesmo processo ou segmento com o mesmo *nomeArgumento de modelo,* **_mktemp** verifica nomes de arquivos que correspondem a nomes retornados por **_mktemp** em chamadas anteriores. Se não houver nenhum arquivo para um determinado nome, **_mktemp** retorna esse nome. Se existirem arquivos para todos os nomes retornados anteriormente, **_mktemp** cria um novo nome substituindo o caractere alfabético usado no nome anteriormente retornado pela próxima letra minúscula disponível, em ordem, de 'a' a 'z'. Por exemplo, se *base* for:

> **fn**

e o valor de cinco dígitos fornecido por **_mktemp** é 12345, o primeiro nome retornado é:

> **fna12345**

Se esse nome for usado para criar o arquivo FNA12345 e esse arquivo ainda existir, o próximo nome retornou em uma chamada do mesmo processo ou segmento com a mesma *base* para *nomeModelo* é:

> **fnb12345**

Se FNA12345 não existir, o próximo nome retornado será novamente:

> **fna12345**

**_mktemp** pode criar um máximo de 26 nomes de arquivo exclusivos para qualquer combinação de valores *base* e *nameTemplate.* Portanto, FNZ12345 é o último nome de arquivo único **_mktemp** pode criar para os valores *base* e *nameTemplate* usados neste exemplo.

No fracasso, **errno** está definido. Se *nameTemplate* tiver um formato inválido (por exemplo, menos de 6 X's), **errno** será definido **como EINVAL**. Se **_mktemp** não conseguir criar um nome único porque todos os 26 nomes de arquivo possíveis já existem, **_mktemp** define o nomeTemplate para uma seqüência de string vazia e retorna **EEXIST**.

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

## <a name="see-also"></a>Confira também

[Manipulação de Arquivos](../../c-runtime-library/file-handling.md)<br/>
[fopen, _wfopen](fopen-wfopen.md)<br/>
[_getmbcp](getmbcp.md)<br/>
[_getpid](getpid.md)<br/>
[_open, _wopen](open-wopen.md)<br/>
[_setmbcp](setmbcp.md)<br/>
[_tempnam, _wtempnam, tmpnam, _wtmpnam](tempnam-wtempnam-tmpnam-wtmpnam.md)<br/>
[tmpfile](tmpfile.md)<br/>
