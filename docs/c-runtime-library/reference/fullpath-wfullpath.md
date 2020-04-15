---
title: _fullpath, _wfullpath
ms.date: 4/2/2020
api_name:
- _fullpath
- _wfullpath
- _o__fullpath
- _o__wfullpath
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
- api-ms-win-crt-filesystem-l1-1-0.dll
- api-ms-win-crt-private-l1-1-0
api_type:
- DLLExport
topic_type:
- apiref
f1_keywords:
- wfullpath
- fullpath
- _wfullpath
- _fullpath
helpviewer_keywords:
- _wfullpath function
- relative file paths
- absolute paths
- wfullpath function
- _fullpath function
- fullpath function
ms.assetid: 4161ec17-0d22-45dd-b07d-0222553afae9
ms.openlocfilehash: 0910cf4f39e00be84e683cd6f3b9afbeb3f2a749
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81345493"
---
# <a name="_fullpath-_wfullpath"></a>_fullpath, _wfullpath

Cria um nome de caminho absoluto ou completo para o nome de caminho relativo especificado.

## <a name="syntax"></a>Sintaxe

```C
char *_fullpath(
   char *absPath,
   const char *relPath,
   size_t maxLength
);
wchar_t *_wfullpath(
   wchar_t *absPath,
   const wchar_t *relPath,
   size_t maxLength
);
```

### <a name="parameters"></a>Parâmetros

*Abspath*<br/>
Ponteiro para um buffer contendo o nome do caminho absoluto ou completo, ou **NULL**.

*Relpath*<br/>
Nome de caminho relativo.

*Maxlength*<br/>
Comprimento máximo do buffer de nome do caminho absoluto *(absPath).* Este comprimento está em bytes para **_fullpath** mas em caracteres largos **(wchar_t)** para **_wfullpath**.

## <a name="return-value"></a>Valor retornado

Cada uma dessas funções retorna um ponteiro para um buffer contendo o nome do caminho absoluto *(absPath).* Se houver um erro (por exemplo, se o valor passado no *relPath* incluir uma letra de unidade que não seja válida ou não possa ser encontrada, ou se o comprimento do nome do caminho absoluto criado *(absPath)* for maior que *maxLength),* a função retorna **NULL**.

## <a name="remarks"></a>Comentários

A função **_fullpath** expande o nome relativo do caminho no *relPath* para seu caminho totalmente qualificado ou absoluto e armazena este nome em *absPath*. Se *absPath* for **NULL,** **malloc** é usado para alocar um buffer de comprimento suficiente para manter o nome do caminho. É responsabilidade do chamador liberar esse buffer. Um nome de caminho relativo especifica um caminho para outro local do local atual (como o diretório de trabalho atual: "."). Um nome de caminho absoluto é a expansão de um nome de caminho relativo que indica o caminho inteiro necessário para alcançar o local desejado da raiz do sistema de arquivos. Ao contrário **_makepath,** **_fullpath** pode ser usado para obter o nome do caminho absoluto para caminhos relativos *(relPath)* que incluem "./" ou ".. /" em seus nomes.

Por exemplo, para usar rotinas de tempo de execução de C, o aplicativo deve incluir os arquivos de cabeçalho que contêm as declarações para as rotinas. Cada instrução include do arquivo de cabeçalho faz referência ao local do arquivo de forma relativa (do diretório de trabalho do aplicativo):

```C
By default, this function's global state is scoped to the application. To change this, see [Global state in the CRT](../global-state.md).

#include <stdlib.h>
```

quando o caminho absoluto (local do sistema de arquivos real) do arquivo pode ser:

`\\machine\shareName\msvcSrc\crt\headerFiles\stdlib.h`

**_fullpath** lida automaticamente com argumentos de seqüência de caracteres de vários bytes conforme apropriado, reconhecendo seqüências de caracteres multibytes de acordo com a página de código multibyte atualmente em uso. **_wfullpath** é uma versão ampla de **_fullpath;** os argumentos de seqüência **para _wfullpath** são strings de caracteres largos. **_wfullpath** e **_fullpath** se comportam de forma idêntica, exceto que **_wfullpath** não lida com cordas de caracteres multibytes.

Se **_DEBUG** e **_CRTDBG_MAP_ALLOC** forem definidas, as chamadas para **_fullpath** e **_wfullpath** são substituídas por chamadas para **_fullpath_dbg** e **_wfullpath_dbg** para permitir a depuração das alocações de memória. Para obter mais informações, consulte [_fullpath_dbg, _wfullpath_dbg](fullpath-dbg-wfullpath-dbg.md).

Esta função invoca o manipulador de parâmetros inválidos, conforme descrito na [Validação de Parâmetros,](../../c-runtime-library/parameter-validation.md)se *maxlen* for menor ou igual a 0. Se a execução for permitida, esta função define **errno** para **EINVAL** e retorna **NULL**.

### <a name="generic-text-routine-mappings"></a>Mapeamentos da rotina de texto genérico

|Rotina Tchar.h|_UNICODE e _MBCS não definidos|_MBCS definido|_UNICODE definido|
|---------------------|--------------------------------------|--------------------|-----------------------|
|**_tfullpath**|**_fullpath**|**_fullpath**|**_wfullpath**|

Se o buffer *absPath* for **NULL**, **_fullpath** chama [malloc](malloc.md) para alocar um buffer e ignora o argumento *maxLength.* É responsabilidade do chamador desalocar esse buffer (usando [free](free.md)) conforme apropriado. Se o argumento *relPath* especificar uma unidade de disco, o diretório atual desta unidade será combinado com o caminho.

## <a name="requirements"></a>Requisitos

|Função|Cabeçalho necessário|
|--------------|---------------------|
|**_fullpath**|\<stdlib.h>|
|**_wfullpath**|\<stdlib.h> ou \<wchar.h>|

Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="example"></a>Exemplo

```C
// crt_fullpath.c
// This program demonstrates how _fullpath
// creates a full path from a partial path.

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <direct.h>

void PrintFullPath( char * partialPath )
{
   char full[_MAX_PATH];
   if( _fullpath( full, partialPath, _MAX_PATH ) != NULL )
      printf( "Full path is: %s\n", full );
   else
      printf( "Invalid path\n" );
}

int main( void )
{
   PrintFullPath( "test" );
   PrintFullPath( "\\test" );
   PrintFullPath( "..\\test" );
}
```

```Output
Full path is: C:\Documents and Settings\user\My Documents\test
Full path is: C:\test
Full path is: C:\Documents and Settings\user\test
```

## <a name="see-also"></a>Confira também

[Manipulação de Arquivos](../../c-runtime-library/file-handling.md)<br/>
[_getcwd, _wgetcwd](getcwd-wgetcwd.md)<br/>
[_getdcwd, _wgetdcwd](getdcwd-wgetdcwd.md)<br/>
[_makepath, _wmakepath](makepath-wmakepath.md)<br/>
[_splitpath, _wsplitpath](splitpath-wsplitpath.md)<br/>
