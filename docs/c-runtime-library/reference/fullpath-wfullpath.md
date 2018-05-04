---
title: _fullpath, _wfullpath | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-standard-libraries
ms.topic: reference
apiname:
- _fullpath
- _wfullpath
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
- api-ms-win-crt-filesystem-l1-1-0.dll
apitype: DLLExport
f1_keywords:
- wfullpath
- fullpath
- _wfullpath
- _fullpath
dev_langs:
- C++
helpviewer_keywords:
- _wfullpath function
- relative file paths
- absolute paths
- wfullpath function
- _fullpath function
- fullpath function
ms.assetid: 4161ec17-0d22-45dd-b07d-0222553afae9
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: e538ff94a6cd49e4d766dfbca2798aa0daf0e462
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
---
# <a name="fullpath-wfullpath"></a>_fullpath, _wfullpath

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

*absPath*<br/>
Ponteiro para um buffer contendo o nome de caminho absoluto ou completo ou NULL.

*relPath*<br/>
Nome de caminho relativo.

*maxLength*<br/>
Comprimento máximo do buffer de nome de caminho absoluto (*absPath*). Esse comprimento é em bytes para **FullPath** , mas em caracteres largos (**wchar_t**) para **wfullpath**.

## <a name="return-value"></a>Valor de retorno

Cada uma dessas funções retorna um ponteiro para um buffer que contém o nome de caminho absoluto (*absPath*). Se houver um erro (por exemplo, se o valor passado na *relPath* inclui uma letra de unidade que não é válido ou não pode ser encontrada, ou se o comprimento do nome do caminho absoluto criado (*absPath*) é maior que *maxLength*), a função retorna **nulo**.

## <a name="remarks"></a>Comentários

O **FullPath** função expande o nome de caminho relativo no *relPath* de caminho totalmente qualificado ou absoluto e armazena esse nome no *absPath*. Se *absPath* for NULL, **malloc** é usada para alocar um buffer de tamanho suficiente para conter o nome de caminho. É responsabilidade do chamador liberar esse buffer. Um nome de caminho relativo especifica um caminho para outro local do local atual (como o diretório de trabalho atual: "."). Um nome de caminho absoluto é a expansão de um nome de caminho relativo que indica o caminho inteiro necessário para alcançar o local desejado da raiz do sistema de arquivos. Ao contrário de **makepath**, **FullPath** pode ser usado para obter o nome de caminho absoluto para caminhos relativos (*relPath*) que incluem ". /"ou"... / "em seus nomes.

Por exemplo, para usar rotinas de tempo de execução de C, o aplicativo deve incluir os arquivos de cabeçalho que contêm as declarações para as rotinas. Cada instrução include do arquivo de cabeçalho faz referência ao local do arquivo de forma relativa (do diretório de trabalho do aplicativo):

```C
#include <stdlib.h>
```

quando o caminho absoluto (local do sistema de arquivos real) do arquivo pode ser:

`\\machine\shareName\msvcSrc\crt\headerFiles\stdlib.h`

**FullPath** manipula automaticamente os argumentos da cadeia de caracteres multibyte conforme apropriado, reconhecer sequências de caracteres multibyte de acordo com a página de código multibyte em uso no momento. **wfullpath** é uma versão de caractere largo de **FullPath**; os argumentos de cadeia de caracteres para **wfullpath** são cadeias de caracteres do caractere largo. **wfullpath** e **FullPath** tenham comportamento idêntico, exceto que **wfullpath** não trata cadeias de caracteres multibyte.

Se **Debug** e **crtdbg_map_alloc** forem definida, chamadas para **FullPath** e **wfullpath** são substituídos por chamadas para **fullpath_dbg** e **wfullpath_dbg** para permitir a depuração de alocações de memória. Para obter mais informações, consulte [_fullpath_dbg, _wfullpath_dbg](fullpath-dbg-wfullpath-dbg.md).

Essa função invoca o manipulador de parâmetro inválido, conforme descrito em [validação do parâmetro](../../c-runtime-library/parameter-validation.md), se *maxlen* é menor ou igual a 0. Se a execução é permitida para continuar, esta função define **errno** para **EINVAL** e retorna **nulo**.

### <a name="generic-text-routine-mappings"></a>Mapeamentos da rotina de texto genérico

|Rotina Tchar.h|_UNICODE e _MBCS não definidos|_MBCS definido|_UNICODE definido|
|---------------------|--------------------------------------|--------------------|-----------------------|
|**_tfullpath**|**_fullpath**|**_fullpath**|**_wfullpath**|

Se o *absPath* buffer é **nulo**, **FullPath** chamadas [malloc](malloc.md) para alocar um buffer e ignora o *maxLength*  argumento. É responsabilidade do chamador desalocar esse buffer (usando [free](free.md)) conforme apropriado. Se o *relPath* argumento especifica uma unidade de disco, o diretório atual da unidade é combinado com o caminho.

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

## <a name="see-also"></a>Consulte também

[Manipulação de Arquivos](../../c-runtime-library/file-handling.md)<br/>
[_getcwd, _wgetcwd](getcwd-wgetcwd.md)<br/>
[_getdcwd, _wgetdcwd](getdcwd-wgetdcwd.md)<br/>
[_makepath, _wmakepath](makepath-wmakepath.md)<br/>
[_splitpath, _wsplitpath](splitpath-wsplitpath.md)<br/>
