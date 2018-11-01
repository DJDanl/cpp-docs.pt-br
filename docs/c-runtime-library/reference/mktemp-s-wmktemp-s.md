---
title: _mktemp_s, _wmktemp_s
ms.date: 11/04/2016
apiname:
- _mktemp_s
- _wmktemp_s
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
ms.openlocfilehash: fef10f2cfbcc0332741d560a41a782b70ed14798
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50590938"
---
# <a name="mktemps-wmktemps"></a>_mktemp_s, _wmktemp_s

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

*sizeInChars*<br/>
Tamanho do buffer em caracteres de byte único na **mktemp_s**; ampla caracteres no **wmktemp_s**, incluindo o terminador nulo.

## <a name="return-value"></a>Valor de retorno

Ambas as funções retornam zero em caso de êxito, um código de erro em caso de falha.

### <a name="error-conditions"></a>Condições de Erro

|*nameTemplate*|*sizeInChars*|Valor retornado|Novo valor na *nameTemplate*|
|----------------|-------------------|----------------------|-------------------------------|
|**NULL**|qualquer|**EINVAL**|**NULL**|
|Formato incorreto (consulte comentários seção para o formato correto)|qualquer|**EINVAL**|cadeia de caracteres vazia|
|qualquer|<= número de X's|**EINVAL**|cadeia de caracteres vazia|

Se qualquer uma das condições de erro acima ocorrer, o manipulador de parâmetro inválido será invocado, conforme descrito em [Validação de parâmetro](../../c-runtime-library/parameter-validation.md). Se a execução puder continuar, **errno** é definido como **EINVAL** e as funções retornarão **EINVAL**.

## <a name="remarks"></a>Comentários

O **mktemp_s** função cria um nome de arquivo exclusivo modificando o *nameTemplate* argumento, para que depois da chamada, o *nameTemplate* ponteiro aponta para uma cadeia de caracteres que contém o novo nome de arquivo. **mktemp_s** manipula automaticamente argumentos de cadeia de caracteres multibyte conforme apropriado, reconhecendo sequências de caracteres multibyte de acordo com a página de código multibyte em uso no momento pelo sistema de tempo de execução. **wmktemp_s** é uma versão de caractere largo de **mktemp_s**; o argumento da **wmktemp_s** é uma cadeia de caracteres largos. **wmktemp_s** e **mktemp_s** se comportam de forma idêntica caso contrário, exceto que **wmktemp_s** não manipula cadeias de caracteres multibyte.

### <a name="generic-text-routine-mappings"></a>Mapeamentos da rotina de texto genérico

|Rotina Tchar.h|_UNICODE e _MBCS não definidos|_MBCS definido|_UNICODE definido|
|---------------------|--------------------------------------|--------------------|-----------------------|
|**tmktemp_s**|**_mktemp_s**|**_mktemp_s**|**_wmktemp_s**|

O *nameTemplate* argumento tem o formato **baseXXXXXX**, onde *base* é a parte do novo nome do arquivo que você fornece e cada X é um espaço reservado para um caractere fornecido pelo **mktemp_s**. Cada caractere de espaço reservado na *nameTemplate* deve ser um x maiusculo. **mktemp_s** preserva *base* e substitui o primeiro X à direita com um caractere alfabético. **mktemp_s** substitui à direita seguinte x com um valor de cinco dígitos; esse valor é um número exclusivo que identifica o processo de chamada ou em programas multithread, o thread de chamada.

Cada chamada bem-sucedida para **mktemp_s** modifica *nameTemplate*. Em cada chamada subsequente do mesmo processo ou thread com o mesmo *nameTemplate* argumento **mktemp_s** procura nomes de arquivo que correspondem aos nomes retornados por **mktemp_s** em chamadas anteriores. Se o arquivo não existe para um determinado nome, **mktemp_s** retorna esse nome. Se existirem arquivos para todos os nomes retornados anteriormente, **mktemp_s** cria um novo nome, substituindo o caractere alfabético que ele usado no nome retornado anteriormente com a próxima letra de minúscula disponível, em ordem, de 'a' a 'z'. Por exemplo, se *base* é:

> **Fn**

e o valor de cinco dígitos fornecido pelo **mktemp_s** for 12345, o primeiro nome retornado será:

> **fna12345**

Se esse nome é usado para criar o arquivo FNA12345 e esse arquivo ainda existe, o próximo nome retornado em uma chamada do mesmo processo ou thread com o mesmo *base* para *nameTemplate* é:

> **fnb12345**

Se FNA12345 não existir, o próximo nome retornado será novamente:

> **fna12345**

**mktemp_s** pode criar no máximo 26 nomes de arquivo exclusivos para qualquer determinada combinação de *base* e *nameTemplate* valores. Portanto, FNZ12345 é o último nome de arquivo exclusivo **mktemp_s** pode criar para o *base* e *nameTemplate* valores usados neste exemplo.

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
