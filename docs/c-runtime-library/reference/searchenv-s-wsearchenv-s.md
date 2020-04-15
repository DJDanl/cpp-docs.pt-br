---
title: _searchenv_s, _wsearchenv_s
ms.date: 4/2/2020
api_name:
- _wsearchenv_s
- _searchenv_s
- _o__searchenv_s
- _o__wsearchenv_s
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
- api-ms-win-crt-environment-l1-1-0.dll
- api-ms-win-crt-private-l1-1-0
api_type:
- DLLExport
topic_type:
- apiref
f1_keywords:
- _searchenv_s
- _wsearchenv_s
- wsearchenv_s
- searchenv_s
helpviewer_keywords:
- tsearchenv_s function
- files [C++], finding
- buffers [C++], buffer overruns
- environment paths, searching for files
- wsearchenv_s function
- searchenv_s function
- _tsearchenv_s function
- buffer overruns
- buffers [C++], avoiding overruns
- _wsearchenv_s function
- _searchenv_s function
- environment paths
ms.assetid: 47f9fc29-250e-4c09-b52e-9e9f0ef395ca
ms.openlocfilehash: 3d526c546e1496b3b13b14a12c9025cbd0347cd2
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81332397"
---
# <a name="_searchenv_s-_wsearchenv_s"></a>_searchenv_s, _wsearchenv_s

Pesquisa por um arquivo usando caminhos de ambiente. Estas versões de [_searchenv, _wsearchenv](searchenv-wsearchenv.md) têm aprimoramentos de segurança, conforme descrito em [Recursos de segurança no CRT](../../c-runtime-library/security-features-in-the-crt.md).

> [!IMPORTANT]
> Esta API não pode ser usada em aplicativos executados no Windows Runtime. Para obter mais informações, confira [Funções do CRT sem suporte em aplicativos da Plataforma Universal do Windows](../../cppcx/crt-functions-not-supported-in-universal-windows-platform-apps.md).

## <a name="syntax"></a>Sintaxe

```C
errno_t _searchenv_s(
   const char *filename,
   const char *varname,
   char *pathname,
   size_t numberOfElements
);
errno_t _wsearchenv_s(
   const wchar_t *filename,
   const wchar_t *varname,
   wchar_t *pathname,
   size_t numberOfElements
);
template <size_t size>
errno_t _searchenv_s(
   const char *filename,
   const char *varname,
   char (&pathname)[size]
); // C++ only
template <size_t size>
errno_t _wsearchenv_s(
   const wchar_t *filename,
   const wchar_t *varname,
   wchar_t (&pathname)[size]
); // C++ only
```

### <a name="parameters"></a>Parâmetros

*Filename*<br/>
O nome de arquivo a ser pesquisado.

*Varname*<br/>
O ambiente a pesquisar.

*Caminho*<br/>
O buffer para armazenar o caminho completo.

*Numberofelements*<br/>
Tamanho do buffer de nome de *caminho.*

## <a name="return-value"></a>Valor retornado

Zero se for bem-sucedido; um código de erro em caso de falha.

Se *o nome do arquivo* for uma seqüência de string vazia, o valor de retorno será **ENOENT**.

### <a name="error-conditions"></a>Condições de erro

|*Filename*|*Varname*|*Caminho*|*Numberofelements*|Valor retornado|Conteúdo do nome do *caminho*|
|----------------|---------------|----------------|------------------------|------------------|----------------------------|
|any|any|**NULO**|any|**Einval**|n/d|
|**NULO**|any|any|any|**Einval**|não alterado|
|any|any|any|<= 0|**Einval**|não alterado|

Se qualquer uma dessas condições de erro ocorrer, o manipulador de parâmetro inválido será invocado, conforme descrito em [Validação de parâmetro](../../c-runtime-library/parameter-validation.md). Se a execução for permitida, essas funções definem **errno** para **EINVAL** e retornam **EINVAL**.

## <a name="remarks"></a>Comentários

A **_searchenv_s** pesquisa de rotina para o arquivo de destino no domínio especificado. A variável *varname* pode ser qualquer ambiente ou variável definida pelo usuário que especifique uma lista de caminhos de diretório, como **PATH**, **LIB**e **INCLUDE**. Como **_searchenv_s** é sensível a casos, *o varname* deve coincidir com o caso da variável ambiente. Se *varname* não corresponder ao nome de uma variável de ambiente definida no ambiente do processo, a função retorna zero e a variável nome de *caminho* é inalterada.

A rotina pesquisa pelo arquivo primeiramente no diretório de trabalho atual. Se não encontrar o arquivo, ela procurará em seguida nos diretórios especificados pela variável de ambiente. Se o arquivo de destino estiver em um desses diretórios, o caminho recém-criado será copiado para *pathname*. Se o arquivo *nome* do arquivo não for encontrado, *o nome do caminho* contém uma seqüência de seqüência de nulidade vazia.

O buffer *de nome de caminho* deve ser pelo menos **_MAX_PATH** caracteres para acomodar toda a extensão do nome do caminho construído. Caso contrário, **_searchenv_s** pode ultrapassar o buffer *de nome de caminho,* resultando em comportamento inesperado.

**_wsearchenv_s** é uma versão ampla de **_searchenv_s;** os argumentos para **_wsearchenv_s** são cordas de caracteres amplos. **_wsearchenv_s** e **_searchenv_s** se comportam de forma idêntica.

Em C++, o uso dessas funções é simplificado pelas sobrecargas de modelo; as sobrecargas podem inferir o tamanho do buffer automaticamente (eliminando a necessidade de especificar um argumento de tamanho) e podem substituir automaticamente funções mais antigas e não seguras por suas equivalentes mais recentes e seguras. Para obter mais informações, consulte [Sobrecargas de modelo seguro](../../c-runtime-library/secure-template-overloads.md).

Por padrão, o estado global desta função é escopo para o aplicativo. Para mudar isso, consulte [Estado Global no CRT](../global-state.md).

### <a name="generic-text-routine-mappings"></a>Mapeamentos da rotina de texto genérico

|Rotina Tchar.h|_UNICODE e _MBCS não definidos|_MBCS definido|_UNICODE definido|
|---------------------|--------------------------------------|--------------------|-----------------------|
|**_tsearchenv_s**|**_searchenv_s**|**_searchenv_s**|**_wsearchenv_s**|

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|
|-------------|---------------------|
|**_searchenv_s**|\<stdlib.h>|
|**_wsearchenv_s**|\<stdlib.h> ou \<wchar.h>|

Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="example"></a>Exemplo

```C
// crt_searchenv_s.c
/* This program searches for a file in
* a directory specified by an environment variable.
*/

#include <stdlib.h>
#include <stdio.h>

int main( void )
{
   char pathbuffer[_MAX_PATH];
   char searchfile[] = "CL.EXE";
   char envvar[] = "PATH";
   errno_t err;

   /* Search for file in PATH environment variable: */
   err = _searchenv_s( searchfile, envvar, pathbuffer, _MAX_PATH );
   if (err != 0)
   {
      printf("Error searching the path. Error code: %d\n", err);
   }
   if( *pathbuffer != '\0' )
      printf( "Path for %s:\n%s\n", searchfile, pathbuffer );
   else
      printf( "%s not found\n", searchfile );
}
```

```Output
Path for CL.EXE:
C:\Program Files\Microsoft Visual Studio 2010\VC\BIN\CL.EXE
```

## <a name="see-also"></a>Confira também

[Controle de diretório](../../c-runtime-library/directory-control.md)<br/>
[_searchenv, _wsearchenv](searchenv-wsearchenv.md)<br/>
[getenv, _wgetenv](getenv-wgetenv.md)<br/>
[_putenv, _wputenv](putenv-wputenv.md)<br/>
