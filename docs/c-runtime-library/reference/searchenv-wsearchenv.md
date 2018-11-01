---
title: _searchenv, _wsearchenv
ms.date: 11/04/2016
apiname:
- _searchenv
- _wsearchenv
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
- api-ms-win-crt-environment-l1-1-0.dll
apitype: DLLExport
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
ms.openlocfilehash: c1d2361fceec448c98fd9e5a368653aac38c83e2
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50628248"
---
# <a name="searchenv-wsearchenv"></a>_searchenv, _wsearchenv

Usa caminhos de ambiente para pesquisar por um arquivo. Versões mais seguras dessas funções estão disponíveis; consulte [_searchenv_s, _wsearchenv_s](searchenv-s-wsearchenv-s.md).

> [!IMPORTANT]
> Esta API não pode ser usada em aplicativos executados no Tempo de Execução do Windows. Para obter mais informações, confira [Funções do CRT sem suporte em aplicativos da Plataforma Universal do Windows](../../cppcx/crt-functions-not-supported-in-universal-windows-platform-apps.md).

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

*filename*<br/>
O nome de arquivo a ser pesquisado.

*varname*<br/>
O ambiente a pesquisar.

*pathname*<br/>
O buffer para armazenar o caminho completo.

## <a name="remarks"></a>Comentários

O **SEARCHENV** rotina procurará o arquivo de destino no domínio especificado. O *varname* variável pode ser qualquer ambiente ou variável definida pelo usuário — por exemplo, **caminho**, **LIB**, ou **INCLUDE**— que especifica um lista de caminhos de diretório. Porque **SEARCHENV** diferencia maiusculas de minúsculas *varname* deve corresponder ao uso de variável de ambiente.

A rotina pesquisa pelo arquivo primeiramente no diretório de trabalho atual. Se não encontrar o arquivo, ela procurará nos diretórios especificados pela variável de ambiente. Se o arquivo de destino estiver em um desses diretórios, o caminho criado recentemente é copiado para *pathname*. Se o *filename* arquivo não for encontrado, *pathname* contém uma cadeia de caracteres vazia terminada em nulo.

O *pathname* buffer deve ser pelo menos **MAX_PATH** caracteres para acomodar o comprimento total do nome do caminho criado. Caso contrário, **SEARCHENV** poderia causar um estouro de *pathname* armazenar em buffer e causar um comportamento inesperado.

**wsearchenv** é uma versão de caractere largo de **SEARCHENV**e os argumentos a serem **wsearchenv** são cadeias de caracteres largos. **wsearchenv** e **SEARCHENV** se comportam de forma idêntica caso contrário.

Se *filename* é uma cadeia de caracteres vazia, essas funções retornarão **ENOENT**.

Se *filename* ou *pathname* é um **nulo** ponteiro, o manipulador de parâmetro inválido será invocado, conforme descrito no [validação de parâmetro](../../c-runtime-library/parameter-validation.md). Se a execução puder continuar, essas funções retornarão -1 e defina **errno** à **EINVAL**.

Para obter mais informações sobre **errno** e códigos de erro, consulte [constantes errno](../../c-runtime-library/errno-constants.md).

Em C++, essas funções têm sobrecargas de modelo que invocam os equivalentes mais recentes e mais seguros dessas funções. Para obter mais informações, consulte [Sobrecargas de modelo seguro](../../c-runtime-library/secure-template-overloads.md).

### <a name="generic-text-routine-mappings"></a>Mapeamentos da rotina de texto genérico

|Rotina Tchar.h|_UNICODE e _MBCS não definidos|_MBCS definido|_UNICODE definido|
|---------------------|--------------------------------------|--------------------|-----------------------|
|**tsearchenv**|**_searchenv**|**_searchenv**|**_wsearchenv**|

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

## <a name="see-also"></a>Consulte também

[Controle de diretório](../../c-runtime-library/directory-control.md)<br/>
[getenv, _wgetenv](getenv-wgetenv.md)<br/>
[_putenv, _wputenv](putenv-wputenv.md)<br/>
[_searchenv_s, _wsearchenv_s](searchenv-s-wsearchenv-s.md)<br/>
