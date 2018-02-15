---
title: _fullpath, _wfullpath | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-standard-libraries
ms.tgt_pltfrm: 
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
caps.latest.revision: 
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: a9874d4c0b3576f79880d95a04285be9ff299c7c
ms.sourcegitcommit: 6002df0ac79bde5d5cab7bbeb9d8e0ef9920da4a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/14/2018
---
# <a name="fullpath-wfullpath"></a>_fullpath, _wfullpath
Cria um nome de caminho absoluto ou completo para o nome de caminho relativo especificado.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
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
  
#### <a name="parameters"></a>Parâmetros  
 `absPath`  
 Ponteiro para um buffer contendo o nome de caminho absoluto ou completo ou NULL.  
  
 `relPath`  
 Nome de caminho relativo.  
  
 `maxLength`  
 Comprimento máximo do buffer do nome de caminho absoluto (`absPath`). Esse comprimento é em bytes para `_fullpath` mas em caracteres largos (`wchar_t`) para `_wfullpath`.  
  
## <a name="return-value"></a>Valor de retorno  
 Cada uma dessas funções retorna um ponteiro para um buffer contendo o nome de caminho absoluto (`absPath`). Se houver um erro (por exemplo, se o valor passado em `relPath` incluir uma letra da unidade inválida ou que não possa ser encontrada ou se o tamanho do nome de caminho absoluto criado (`absPath`) for maior que `maxLength`), a função retornará `NULL`.  
  
## <a name="remarks"></a>Comentários  
 O `_fullpath` função expande o nome de caminho relativo no `relPath` de caminho totalmente qualificado ou absoluto e armazena esse nome no `absPath`. Se `absPath` for NULL, `malloc` será usado para alocar um buffer de tamanho suficiente para armazenar o nome do caminho. É responsabilidade do chamador liberar esse buffer. Um nome de caminho relativo especifica um caminho para outro local do local atual (como o diretório de trabalho atual: "."). Um nome de caminho absoluto é a expansão de um nome de caminho relativo que indica o caminho inteiro necessário para alcançar o local desejado da raiz do sistema de arquivos. Diferente de `_makepath`, `_fullpath` pode ser usado para obter o nome de caminho absoluto para caminhos relativos (`relPath`) que incluem "./"ou"../" em seus nomes.  
  
 Por exemplo, para usar rotinas de tempo de execução de C, o aplicativo deve incluir os arquivos de cabeçalho que contêm as declarações para as rotinas. Cada instrução include do arquivo de cabeçalho faz referência ao local do arquivo de forma relativa (do diretório de trabalho do aplicativo):  
  
```  
#include <stdlib.h>  
```  
  
 quando o caminho absoluto (local do sistema de arquivos real) do arquivo pode ser:  
  
```  
\\machine\shareName\msvcSrc\crt\headerFiles\stdlib.h  
```  
  
 `_fullpath` manipula automaticamente argumentos de cadeia de caracteres multibyte conforme apropriado, reconhecendo sequências de caracteres multibyte de acordo com a página de código multibyte que está sendo usada no momento. `_wfullpath` é uma versão de caractere largo de `_fullpath`; os argumentos de cadeia de caracteres `_wfullpath` são cadeias de caracteres largos. `_wfullpath` e `_fullpath` têm comportamento idêntico, exceto pelo fato de que `_wfullpath` não manipula cadeias de caracteres multibyte.  
  
 Se `_DEBUG` e `_CRTDBG_MAP_ALLOC` forem definidos, chamadas para `_fullpath` e `_wfullpath` serão substituídas por chamadas para `_fullpath_dbg` e `_wfullpath_dbg`, para permitir a depuração de alocações de memória. Para obter mais informações, consulte [_fullpath_dbg, _wfullpath_dbg](../../c-runtime-library/reference/fullpath-dbg-wfullpath-dbg.md).  
  
 Essa função invoca o manipulador de parâmetro inválido, conforme descrito em [Validação de parâmetro](../../c-runtime-library/parameter-validation.md), se `maxlen` for menor ou igual a 0. Se a execução puder continuar, essa função definirá `errno` como `EINVAL` e retornará `NULL`.  
  
### <a name="generic-text-routine-mappings"></a>Mapeamentos da rotina de texto genérico  
  
|Rotina Tchar.h|_UNICODE e _MBCS não definidos|_MBCS definido|_UNICODE definido|  
|---------------------|--------------------------------------|--------------------|-----------------------|  
|`_tfullpath`|`_fullpath`|`_fullpath`|`_wfullpath`|  
  
 Se o buffer `absPath` for `NULL`, `_fullpath` chamará [malloc](../../c-runtime-library/reference/malloc.md) para alocar um buffer e ignorará o argumento `maxLength`. É responsabilidade do chamador desalocar esse buffer (usando [free](../../c-runtime-library/reference/free.md)) conforme apropriado. Se o argumento `relPath` especificar uma unidade de disco, o diretório atual da unidade será combinado ao caminho.  
  
## <a name="requirements"></a>Requisitos  
  
|Função|Cabeçalho necessário|  
|--------------|---------------------|  
|`_fullpath`|\<stdlib.h>|  
|`_wfullpath`|\<stdlib.h> ou \<wchar.h>|  
  
 Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md) na Introdução.  
  
## <a name="example"></a>Exemplo  
  
```  
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
 [Manipulação de Arquivos](../../c-runtime-library/file-handling.md)   
 [_getcwd, _wgetcwd](../../c-runtime-library/reference/getcwd-wgetcwd.md)   
 [_getdcwd, _wgetdcwd](../../c-runtime-library/reference/getdcwd-wgetdcwd.md)   
 [_makepath, _wmakepath](../../c-runtime-library/reference/makepath-wmakepath.md)   
 [_splitpath, _wsplitpath](../../c-runtime-library/reference/splitpath-wsplitpath.md)