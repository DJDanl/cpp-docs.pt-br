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
- api-ms-win-crt-private-l1-1-0.dll
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
ms.openlocfilehash: 5dd21013c8910ba07e2d23606af49bc80458dbc6
ms.sourcegitcommit: 5a069c7360f75b7c1cf9d4550446ec2fa2eb2293
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/07/2020
ms.locfileid: "82918989"
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

*nome do arquivo*<br/>
O nome de arquivo a ser pesquisado.

*varname*<br/>
O ambiente a pesquisar.

*nome*<br/>
O buffer para armazenar o caminho completo.

*numberOfElements*<br/>
Tamanho do buffer do *nome do caminho* .

## <a name="return-value"></a>Valor retornado

Zero se for bem-sucedido; um código de erro em caso de falha.

Se *filename* for uma cadeia de caracteres vazia, o valor de retorno será **ENOENT**.

### <a name="error-conditions"></a>Condições de erro

|*nome do arquivo*|*varname*|*nome*|*numberOfElements*|Valor retornado|Conteúdo de *PathName*|
|----------------|---------------|----------------|------------------------|------------------|----------------------------|
|any|any|**NULO**|any|**EINVAL**|N/D|
|**NULO**|any|any|any|**EINVAL**|não alterado|
|any|any|any|<= 0|**EINVAL**|não alterado|

Se qualquer uma dessas condições de erro ocorrer, o manipulador de parâmetro inválido será invocado, conforme descrito em [Validação de parâmetro](../../c-runtime-library/parameter-validation.md). Se a execução puder continuar, essas funções definirão **errno** como **EINVAL** e retornarão **EINVAL**.

## <a name="remarks"></a>Comentários

A rotina **_searchenv_s** procura o arquivo de destino no domínio especificado. A variável *VarName* pode ser qualquer ambiente ou variável definida pelo usuário que especifique uma lista de caminhos de diretório, como **Path**, **lib**e **include**. Como **_searchenv_s** diferencia maiúsculas de minúsculas, *VarName* deve corresponder ao caso da variável de ambiente. Se *VarName* não corresponder ao nome de uma variável de ambiente definida no ambiente do processo, a função retornará zero e a variável de *nome de caminho* será inalterada.

A rotina pesquisa pelo arquivo primeiramente no diretório de trabalho atual. Se não encontrar o arquivo, ela procurará em seguida nos diretórios especificados pela variável de ambiente. Se o arquivo de destino estiver em um desses diretórios, o caminho recém-criado será copiado em *PathName*. Se o arquivo *filename* não for encontrado, *PathName* conterá uma cadeia de caracteres vazia terminada em nulo.

O *buffer de nome de caminho deve* ter pelo menos **_MAX_PATH** caracteres para acomodar o comprimento completo do nome de caminho construído. Caso contrário, **_searchenv_s** pode saturar o buffer de *nome de caminho* resultando em um comportamento inesperado

**_wsearchenv_s** é uma versão de caractere largo do **_searchenv_s**; os argumentos para **_wsearchenv_s** são cadeias de caracteres largos. **_wsearchenv_s** e **_searchenv_s** se comportar de forma idêntica.

Em C++, o uso dessas funções é simplificado pelas sobrecargas de modelo; as sobrecargas podem inferir o tamanho do buffer automaticamente (eliminando a necessidade de especificar um argumento de tamanho) e podem substituir automaticamente funções mais antigas e não seguras por suas equivalentes mais recentes e seguras. Para obter mais informações, consulte [Sobrecargas de modelo seguro](../../c-runtime-library/secure-template-overloads.md).

Por padrão, o estado global dessa função tem como escopo o aplicativo. Para alterar isso, consulte [estado global no CRT](../global-state.md).

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
