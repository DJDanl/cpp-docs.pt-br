---
title: _searchenv, _wsearchenv
ms.date: 4/2/2020
api_name:
- _searchenv
- _wsearchenv
- _o__searchenv
- _o__wsearchenv
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
- _wsearchenv
- _tsearchenv
- wsearchenv
- _searchenv
- searchenv
helpviewer_keywords:
- _wsearchenv function
- files [C++], finding
- _searchenv function
- tsearchenv function
- environment paths, searching for files
- _tsearchenv function
- wsearchenv function
- searchenv function
- environment paths
ms.assetid: 9c944a27-d326-409b-aee6-410e8762d9d3
ms.openlocfilehash: 22a8ca8fa7e56a84289d7e90ffb519073f006b5c
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81332389"
---
# <a name="_searchenv-_wsearchenv"></a>_searchenv, _wsearchenv

Usa caminhos de ambiente para pesquisar por um arquivo. Versões mais seguras dessas funções estão disponíveis; consulte [_searchenv_s, _wsearchenv_s](searchenv-s-wsearchenv-s.md).

> [!IMPORTANT]
> Esta API não pode ser usada em aplicativos executados no Windows Runtime. Para obter mais informações, confira [Funções do CRT sem suporte em aplicativos da Plataforma Universal do Windows](../../cppcx/crt-functions-not-supported-in-universal-windows-platform-apps.md).

## <a name="syntax"></a>Sintaxe

```C
void _searchenv(
   const char *filename,
   const char *varname,
   char *pathname
);
void _wsearchenv(
   const wchar_t *filename,
   const wchar_t *varname,
   wchar_t *pathname
);
template <size_t size>
void _searchenv(
   const char *filename,
   const char *varname,
   char (&pathname)[size]
); // C++ only
template <size_t size>
void _wsearchenv(
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

## <a name="remarks"></a>Comentários

A **_searchenv** pesquisa de rotina para o arquivo de destino no domínio especificado. A variável *varname* pode ser qualquer ambiente ou variável definida pelo usuário — por exemplo, **PATH,** **LIB**ou **INCLUDE**— que especifica uma lista de caminhos de diretório. Como **_searchenv** é sensível a casos, *o varname* deve coincidir com o caso da variável ambiente.

A rotina pesquisa pelo arquivo primeiramente no diretório de trabalho atual. Se não encontrar o arquivo, ela procurará nos diretórios especificados pela variável de ambiente. Se o arquivo de destino estiver em um desses diretórios, o caminho recém-criado será copiado para *pathname*. Se o arquivo *nome* do arquivo não for encontrado, *o nome do caminho* contém uma seqüência de seqüência de nulidade vazia.

O buffer *de nome de caminho* deve ser pelo menos **_MAX_PATH** caracteres para acomodar toda a extensão do nome do caminho construído. Caso contrário, **_searchenv** podem ultrapassar o buffer *de nome de caminho* e causar comportamentos inesperados.

**_wsearchenv** é uma versão de grande caráter de **_searchenv**, e os argumentos para **_wsearchenv** são cordas de caráter amplo. **_wsearchenv** e **_searchenv** se comportem de forma idêntica.

Se *o nome do arquivo* for uma seqüência de arquivos, essas funções retornam **ENOENT**.

Se *o nome do arquivo* ou nome do *caminho* for um ponteiro **NULL,** o manipulador de parâmetros inválidos será invocado, conforme descrito na [Validação de Parâmetros](../../c-runtime-library/parameter-validation.md). Se a execução continuar, essas funções retornam -1 e definem **errno** para **EINVAL**.

Para obter mais informações sobre **errno** e códigos de erro, consulte [errno Constants](../../c-runtime-library/errno-constants.md).

Em C++, essas funções têm sobrecargas de modelo que invocam os equivalentes mais recentes e mais seguros dessas funções. Para obter mais informações, consulte [Sobrecargas de modelo seguro](../../c-runtime-library/secure-template-overloads.md).

Por padrão, o estado global desta função é escopo para o aplicativo. Para mudar isso, consulte [Estado Global no CRT](../global-state.md).

### <a name="generic-text-routine-mappings"></a>Mapeamentos da rotina de texto genérico

|Rotina Tchar.h|_UNICODE e _MBCS não definidos|_MBCS definido|_UNICODE definido|
|---------------------|--------------------------------------|--------------------|-----------------------|
|**_tsearchenv**|**_searchenv**|**_searchenv**|**_wsearchenv**|

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|
|-------------|---------------------|
|**_searchenv**|\<stdlib.h>|
|**_wsearchenv**|\<stdlib.h> ou \<wchar.h>|

Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="example"></a>Exemplo

```C
// crt_searchenv.c
// compile with: /W3
// This program searches for a file in
// a directory that's specified by an environment variable.

#include <stdlib.h>
#include <stdio.h>

int main( void )
{
   char pathbuffer[_MAX_PATH];
   char searchfile[] = "CL.EXE";
   char envvar[] = "PATH";

   // Search for file in PATH environment variable:
   _searchenv( searchfile, envvar, pathbuffer ); // C4996
   // Note: _searchenv is deprecated; consider using _searchenv_s
   if( *pathbuffer != '\0' )
      printf( "Path for %s:\n%s\n", searchfile, pathbuffer );
   else
      printf( "%s not found\n", searchfile );
}
```

```Output
Path for CL.EXE:
C:\Program Files\Microsoft Visual Studio 8\VC\BIN\CL.EXE
```

## <a name="see-also"></a>Confira também

[Controle de diretório](../../c-runtime-library/directory-control.md)<br/>
[getenv, _wgetenv](getenv-wgetenv.md)<br/>
[_putenv, _wputenv](putenv-wputenv.md)<br/>
[_searchenv_s, _wsearchenv_s](searchenv-s-wsearchenv-s.md)<br/>
