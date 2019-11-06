---
title: _mktemp_s, _wmktemp_s
ms.date: 11/04/2016
api_name:
- _mktemp_s
- _wmktemp_s
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
- wmktemp_s
- mktemp_s
- _mktemp_s
- _wmktemp_s
helpviewer_keywords:
- _tmktemp_s function
- mktemp_s function
- _wmktemp_s function
- _mktemp_s function
- files [C++], temporary
- tmktemp_s function
- wmktemp_s function
- temporary files [C++]
ms.assetid: 92a7e269-7f3d-4c71-bad6-14bc827a451d
ms.openlocfilehash: 464f0dfbdb0b84e1fd29ec650e53f5c2543c4403
ms.sourcegitcommit: 0cfc43f90a6cc8b97b24c42efcf5fb9c18762a42
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 11/05/2019
ms.locfileid: "73624218"
---
# <a name="_mktemp_s-_wmktemp_s"></a>_mktemp_s, _wmktemp_s

Cria um nome de arquivo exclusivo. Estas são versões de [_mktemp, _wmktemp](mktemp-wmktemp.md) com melhorias de segurança, conforme descrito em [Recursos de Segurança no CRT](../../c-runtime-library/security-features-in-the-crt.md).

## <a name="syntax"></a>Sintaxe

```C
errno_t _mktemp_s(
   char *nameTemplate,
   size_t sizeInChars
);
errno_t _wmktemp_s(
   wchar_t *nameTemplate,
   size_t sizeInChars
);
template <size_t size>
errno_t _mktemp_s(
   char (&nameTemplate)[size]
); // C++ only
template <size_t size>
errno_t _wmktemp_s(
   wchar_t (&nameTemplate)[size]
); // C++ only
```

### <a name="parameters"></a>Parâmetros

*nometemplate*<br/>
Padrão de nome de arquivo.

*sizeInChars*<br/>
Tamanho do buffer em caracteres de byte único em **_mktemp_s**; caracteres largos em **_wmktemp_s**, incluindo o terminador nulo.

## <a name="return-value"></a>Valor retornado

Ambas as funções retornam zero em caso de êxito, um código de erro em caso de falha.

### <a name="error-conditions"></a>Condições de Erro

|*nometemplate*|*sizeInChars*|Valor retornado|Novo valor em *nametemplate*|
|----------------|-------------------|----------------------|-------------------------------|
|**NULL**|qualquer|**EINVAL**|**NULL**|
|Formato incorreto (consulte a seção de comentários para o formato correto)|qualquer|**EINVAL**|cadeia de caracteres vazia|
|qualquer|<= número de X's|**EINVAL**|cadeia de caracteres vazia|

Se qualquer uma das condições de erro acima ocorrer, o manipulador de parâmetro inválido será invocado, conforme descrito em [Validação de parâmetro](../../c-runtime-library/parameter-validation.md). Se a execução puder continuar, **errno** será definido como **EINVAL** e as funções retornarão **EINVAL**.

## <a name="remarks"></a>Comentários

A função **_mktemp_s** cria um nome de arquivo exclusivo modificando o argumento *nametemplate* , de modo que após a chamada, o ponteiro *nametemplate* aponta para uma cadeia de caracteres que contém o novo nome de arquivo. o **_mktemp_s** manipula automaticamente argumentos de cadeia de caracteres multibyte conforme apropriado, reconhecendo sequências de caracteres multibyte de acordo com a página de código multibyte atualmente em uso pelo sistema de tempo de execução. **_wmktemp_s** é uma versão de caractere largo do **_mktemp_s**; o argumento de **_wmktemp_s** é uma cadeia de caracteres largos. o **_wmktemp_s** e o **_mktemp_s** se comportam de forma idêntica, exceto pelo fato de que o **_wmktemp_s** não lida com cadeias de caracteres multibyte.

As versões de biblioteca de depuração dessas funções primeiro preenchem o buffer com 0xFE. Para desabilitar esse comportamento, use [_CrtSetDebugFillThreshold](crtsetdebugfillthreshold.md).

### <a name="generic-text-routine-mappings"></a>Mapeamentos da rotina de texto genérico

|Rotina Tchar.h|_UNICODE e _MBCS não definidos|_MBCS definido|_UNICODE definido|
|---------------------|--------------------------------------|--------------------|-----------------------|
|**_tmktemp_s**|**_mktemp_s**|**_mktemp_s**|**_wmktemp_s**|

O argumento *nametemplate* tem o formato **baseXXXXXX**, em que *base* é a parte do novo nome de arquivo que você fornece e cada X é um espaço reservado para um caractere fornecido por **_mktemp_s**. Cada caractere de espaço reservado em *nametemplate* deve ser uma x maiúsculo. **_mktemp_s** preserva a *base* e substitui o primeiro X à direita por um caractere alfabético. **_mktemp_s** substitui os seguintes X à direita por um valor de cinco dígitos; Esse valor é um número exclusivo que identifica o processo de chamada ou em programas multithread, o thread de chamada.

Cada chamada bem-sucedida para **_mktemp_s** modifica *nametemplate*. Em cada chamada subsequente do mesmo processo ou thread com o mesmo argumento *nametemplate* , **_mktemp_s** verifica os nomes de arquivo que correspondem aos nomes retornados por **_mktemp_s** nas chamadas anteriores. Se nenhum arquivo existir para um determinado nome, **_mktemp_s** retornará esse nome. Se existirem arquivos para todos os nomes retornados anteriormente, o **_mktemp_s** criará um novo nome substituindo o caractere alfabético usado no nome retornado anteriormente pela próxima letra minúscula disponível, em ordem, de ' a ' até ' z '. Por exemplo, se *base* for:

> **FN**

e o valor de cinco dígitos fornecido pelo **_mktemp_s** é 12345, o primeiro nome retornado é:

> **fna12345**

Se esse nome for usado para criar o arquivo FNA12345 e esse arquivo ainda existir, o próximo nome retornado em uma chamada do mesmo processo ou thread com a mesma *base* para *nametemplate* será:

> **fnb12345**

Se FNA12345 não existir, o próximo nome retornado será novamente:

> **fna12345**

**_mktemp_s** pode criar no máximo 26 nomes de arquivo exclusivos para qualquer combinação determinada de valores *base* e *nametemplate* . Portanto, FNZ12345 é o último nome de arquivo exclusivo que **_mktemp_s** pode criar para os valores *base* e *nametemplate* usados neste exemplo.

Em C++, o uso dessas funções é simplificado pelas sobrecargas de modelo; as sobrecargas podem inferir o tamanho do buffer automaticamente (eliminando a necessidade de especificar um argumento de tamanho) e podem substituir automaticamente funções mais antigas e não seguras por suas equivalentes mais recentes e seguras. Para obter mais informações, consulte [Sobrecargas de modelo seguro](../../c-runtime-library/secure-template-overloads.md).

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|
|-------------|---------------------|
|**_mktemp_s**|\<io.h>|
|**_wmktemp_s**|\<io.h> ou \<wchar.h>|

Para obter informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="example"></a>Exemplo

```cpp
// crt_mktemp_s.cpp
/* The program uses _mktemp to create
* five unique filenames. It opens each filename
* to ensure that the next name is unique.
*/

#include <io.h>
#include <string.h>
#include <stdio.h>

char *fnTemplate = "fnXXXXXX";
char names[5][9];

int main()
{
   int i, err, sizeInChars;
   FILE *fp;

   for( i = 0; i < 5; i++ )
   {
      strcpy_s( names[i], sizeof(names[i]), fnTemplate );
      /* Get the size of the string and add one for the null terminator.*/
      sizeInChars = strnlen(names[i], 9) + 1;
      /* Attempt to find a unique filename: */
      err = _mktemp_s( names[i], sizeInChars );
      if( err != 0 )
         printf( "Problem creating the template" );
      else
      {
         if( fopen_s( &fp, names[i], "w" ) == 0 )
            printf( "Unique filename is %s\n", names[i] );
         else
            printf( "Cannot open %s\n", names[i] );
         fclose( fp );
      }
   }

   return 0;
}
```

### <a name="sample-output"></a>Saída de Exemplo

```Output
Unique filename is fna03188
Unique filename is fnb03188
Unique filename is fnc03188
Unique filename is fnd03188
Unique filename is fne03188
```

## <a name="see-also"></a>Consulte também

[Manipulação de Arquivos](../../c-runtime-library/file-handling.md)<br/>
[fopen, _wfopen](fopen-wfopen.md)<br/>
[_getmbcp](getmbcp.md)<br/>
[_getpid](getpid.md)<br/>
[_open, _wopen](open-wopen.md)<br/>
[_setmbcp](setmbcp.md)<br/>
[_tempnam, _wtempnam, tmpnam, _wtmpnam](tempnam-wtempnam-tmpnam-wtmpnam.md)<br/>
[tmpfile_s](tmpfile-s.md)<br/>
