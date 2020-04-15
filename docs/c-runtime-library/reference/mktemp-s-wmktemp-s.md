---
title: _mktemp_s, _wmktemp_s
ms.date: 4/2/2020
api_name:
- _mktemp_s
- _wmktemp_s
- _o__mktemp_s
- _o__wmktemp_s
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
ms.openlocfilehash: 061c5647b2c5a5e79b017cf93989f62ad19cfc0a
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81338760"
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

*nameTemplate*<br/>
Padrão de nome de arquivo.

*tamanhoInChars*<br/>
Tamanho do buffer em caracteres de byte único em **_mktemp_s;** grandes personagens em **_wmktemp_s,** incluindo o exterminador nulo.

## <a name="return-value"></a>Valor retornado

Ambas as funções retornam zero em caso de êxito, um código de erro em caso de falha.

### <a name="error-conditions"></a>Condições de erro

|*nameTemplate*|*tamanhoInChars*|Valor retornado|Novo valor no *nameTemplate*|
|----------------|-------------------|----------------------|-------------------------------|
|**NULO**|any|**Einval**|**NULO**|
|Formato incorreto (ver seção Observações para o formato correto)|any|**Einval**|cadeia de caracteres vazia|
|any|<= número de X's|**Einval**|cadeia de caracteres vazia|

Se qualquer uma das condições de erro acima ocorrer, o manipulador de parâmetro inválido será invocado, conforme descrito em [Validação de parâmetro](../../c-runtime-library/parameter-validation.md). Se a execução continuar, **errno** será definido **como EINVAL** e as funções retornarão **EINVAL**.

## <a name="remarks"></a>Comentários

A função **_mktemp_s** cria um nome de arquivo exclusivo modificando o argumento *nameTemplate,* de modo que após a chamada, o ponteiro *nameTemplate* aponta para uma seqüência contendo o nome do novo arquivo. **_mktemp_s** lida automaticamente com argumentos de seqüência de caracteres de vários bytes conforme apropriado, reconhecendo seqüências de caracteres multibytes de acordo com a página de código multibyte atualmente em uso pelo sistema de tempo de execução. **_wmktemp_s** é uma versão ampla de **_mktemp_s;** o argumento de **_wmktemp_s** é uma seqüência de caracteres amplos. **_wmktemp_s** e **_mktemp_s** se comportam de forma idêntica de outra forma, exceto que **_wmktemp_s** não lida com cordas de caracteres multibytes.

As versões da biblioteca de depuração dessas funções primeiro preenchem o buffer com 0xFE. Para desabilitar esse comportamento, use [_CrtSetDebugFillThreshold](crtsetdebugfillthreshold.md).

Por padrão, o estado global desta função é escopo para o aplicativo. Para mudar isso, consulte [Estado Global no CRT](../global-state.md).

### <a name="generic-text-routine-mappings"></a>Mapeamentos da rotina de texto genérico

|Rotina Tchar.h|_UNICODE e _MBCS não definidos|_MBCS definido|_UNICODE definido|
|---------------------|--------------------------------------|--------------------|-----------------------|
|**_tmktemp_s**|**_mktemp_s**|**_mktemp_s**|**_wmktemp_s**|

O argumento *nameTemplate* tem o formulário **baseXXXXXX**, onde a *base* é a parte do novo nome de arquivo que você fornece e cada X é um espaço reservado para um caractere fornecido por **_mktemp_s**. Cada caractere de espaço reservado no *nomeTemplate* deve ser um X maiúsculo **_mktemp_s** preserva *a base* e substitui o primeiro X de arrasto por um caractere alfabético. **_mktemp_s** substitui os Seguintes X's por um valor de cinco dígitos; esse valor é um número único que identifica o processo de chamada, ou em programas multithreaded, o segmento de chamada.

Cada chamada bem sucedida para **_mktemp_s** modifica *o nameTemplate*. Em cada chamada subseqüente do mesmo processo ou segmento com o mesmo *nomeArgumento de modelo,* **_mktemp_s** verifica nomes de arquivos que correspondem a nomes retornados por **_mktemp_s** em chamadas anteriores. Se não houver nenhum arquivo para um determinado nome, **_mktemp_s** retorna esse nome. Se existirem arquivos para todos os nomes retornados anteriormente, **_mktemp_s** cria um novo nome substituindo o caractere alfabético usado no nome anteriormente retornado pela próxima letra minúscula disponível, em ordem, de 'a' a 'z'. Por exemplo, se *base* for:

> **fn**

e o valor de cinco dígitos fornecido por **_mktemp_s** é 12345, o primeiro nome retornado é:

> **fna12345**

Se esse nome for usado para criar o arquivo FNA12345 e esse arquivo ainda existir, o próximo nome retornou em uma chamada do mesmo processo ou segmento com a mesma *base* para *nomeModelo* é:

> **fnb12345**

Se FNA12345 não existir, o próximo nome retornado será novamente:

> **fna12345**

**_mktemp_s** pode criar um máximo de 26 nomes de arquivo exclusivos para qualquer combinação de valores *base* e *nameTemplate.* Portanto, FNZ12345 é o último nome de arquivo único **_mktemp_s** pode criar para os valores *base* e *nameTemplate* usados neste exemplo.

Em C++, o uso dessas funções é simplificado pelas sobrecargas de modelo; as sobrecargas podem inferir o tamanho do buffer automaticamente (eliminando a necessidade de especificar um argumento de tamanho) e podem substituir automaticamente funções mais antigas e não seguras por suas equivalentes mais recentes e seguras. Para obter mais informações, consulte [Sobrecargas de modelo seguro](../../c-runtime-library/secure-template-overloads.md).

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|
|-------------|---------------------|
|**_mktemp_s**|\<io.h>|
|**_wmktemp_s**|\<io.h> ou \<wchar.h>|

Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

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

### <a name="sample-output"></a>Saída de exemplo

```Output
Unique filename is fna03188
Unique filename is fnb03188
Unique filename is fnc03188
Unique filename is fnd03188
Unique filename is fne03188
```

## <a name="see-also"></a>Confira também

[Manipulação de Arquivos](../../c-runtime-library/file-handling.md)<br/>
[fopen, _wfopen](fopen-wfopen.md)<br/>
[_getmbcp](getmbcp.md)<br/>
[_getpid](getpid.md)<br/>
[_open, _wopen](open-wopen.md)<br/>
[_setmbcp](setmbcp.md)<br/>
[_tempnam, _wtempnam, tmpnam, _wtmpnam](tempnam-wtempnam-tmpnam-wtmpnam.md)<br/>
[tmpfile_s](tmpfile-s.md)<br/>
