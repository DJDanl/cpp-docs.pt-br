---
title: _getcwd, _wgetcwd | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: article
apiname:
- _wgetcwd
- _getcwd
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
- api-ms-win-crt-stdio-l1-1-0.dll
apitype: DLLExport
f1_keywords:
- _getcwd
- wgetcwd
- _wgetcwd
- tgetcwd
- _tgetcwd
dev_langs:
- C++
helpviewer_keywords:
- getcwd function
- working directory
- _wgetcwd function
- _getcwd function
- current working directory
- wgetcwd function
- directories [C++], current working
ms.assetid: 888dc8c6-5595-4071-be55-816b38e3e739
caps.latest.revision: 24
author: corob-msft
ms.author: corob
manager: ghogen
translation.priority.mt:
- cs-cz
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- pl-pl
- pt-br
- ru-ru
- tr-tr
- zh-cn
- zh-tw
ms.translationtype: Machine Translation
ms.sourcegitcommit: a82768750e6a7837bb81edd8a51847f83c294c20
ms.openlocfilehash: ad70ffac5cbe6cc7c56dbad0930bc87b969a1857
ms.contentlocale: pt-br
ms.lasthandoff: 04/04/2017

---
# <a name="getcwd-wgetcwd"></a>_getcwd, _wgetcwd
Obtém o diretório de trabalho atual.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
char *_getcwd(   
   char *buffer,  
   int maxlen   
);  
wchar_t *_wgetcwd(   
   wchar_t *buffer,  
   int maxlen   
);  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `buffer`  
 Local de armazenamento para o caminho.  
  
 `maxlen`  
 Comprimento máximo do caminho em caracteres: `char` para `_getcwd` e `wchar_t` para `_wgetcwd`.  
  
## <a name="return-value"></a>Valor de retorno  
 Retorna um ponteiro para `buffer`. Um valor retornado `NULL` indica que houve um erro e `errno` é definido como `ENOMEM`, indicando que a memória não é suficiente para alocar os bytes de `maxlen` (quando um argumento `NULL` é informado como `buffer`), ou como `ERANGE`, indicando que o caminho tem mais caracteres que o definido pelo parâmetro `maxlen`. Se `maxlen` for menor ou igual a zero, essa função invocará o manipulador de parâmetro inválido, conforme descrito em [Validação de parâmetro](../../c-runtime-library/parameter-validation.md).  
  
 Para obter mais informações sobre esses e outros códigos de retorno, consulte [_doserrno, errno, _sys_errlist e _sys_nerr](../../c-runtime-library/errno-doserrno-sys-errlist-and-sys-nerr.md).  
  
## <a name="remarks"></a>Comentários  
 A função `_getcwd` obtém o caminho completo do diretório de trabalho atual para a unidade padrão e o armazena em `buffer`. O argumento inteiro `maxlen` especifica o tamanho máximo para o caminho. Ocorrerá um erro se excede o comprimento do caminho (incluindo o caractere null de terminação) `maxlen`. O argumento `buffer` pode ser `NULL`; um buffer com tamanho de pelo menos `maxlen` (mais somente se for necessário) será alocado automaticamente, usando `malloc`, para armazenar o caminho. Esse buffer pode, posteriormente, ser liberado chamando `free` e passando o valor retornado `_getcwd` (um ponteiro para o buffer alocado).  
  
 `_getcwd` retorna uma cadeia de caracteres que representa o caminho para o diretório de trabalho atual. Se o diretório de trabalho atual for raiz, a cadeia de caracteres terminará com uma barra invertida (`\`). Se o diretório de trabalho atual for um diretório que não seja o raiz, a cadeia de caracteres terminará com o nome do diretório e não com uma barra invertida.  
  
 `_wgetcwd` é uma versão caracteres largos de `_getcwd`; o argumento `buffer` e o valor de retorno de `_wgetcwd` são cadeias de caracteres largos. Caso contrário, `_wgetcwd` e `_getcwd` se comportam de forma idêntica.  
  
 Quando `_DEBUG` e `_CRTDBG_MAP_ALLOC` forem definidos, chamadas para `_getcwd` e `_wgetcwd` são substituídas por chamadas para `_getcwd_dbg` e `_wgetcwd_dbg`, para permitir a depuração de alocações de memória. Para obter mais informações, consulte [_getcwd_dbg, _wgetcwd_dbg](../../c-runtime-library/reference/getcwd-dbg-wgetcwd-dbg.md).  
  
### <a name="generic-text-routine-mappings"></a>Mapeamentos da rotina de texto genérico  
  
|Rotina Tchar.h|_UNICODE e _MBCS não definidos|_MBCS definido|_UNICODE definido|  
|---------------------|--------------------------------------|--------------------|-----------------------|  
|`_tgetcwd`|`_getcwd`|`_getcwd`|`_wgetcwd`|  
  
## <a name="requirements"></a>Requisitos  
  
|Rotina|Cabeçalho necessário|  
|-------------|---------------------|  
|`_getcwd`|\<direct.h>|  
|`_wgetcwd`|\<direct.h> ou \<wchar.h>|  
  
 Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).  
  
## <a name="example"></a>Exemplo  
  
```  
// crt_getcwd.c  
// This program places the name of the current directory in the   
// buffer array, then displays the name of the current directory   
// on the screen. Passing NULL as the buffer forces getcwd to allocate  
// memory for the path, which allows the code to support file paths  
// longer than _MAX_PATH, which are supported by NTFS.  
  
#include <direct.h>  
#include <stdlib.h>  
#include <stdio.h>  
  
int main( void )  
{  
   char* buffer;  
  
   // Get the current working directory:   
   if( (buffer = _getcwd( NULL, 0 )) == NULL )  
      perror( "_getcwd error" );  
   else  
   {  
      printf( "%s \nLength: %d\n", buffer, strnlen(buffer) );  
      free(buffer);  
   }  
}  
```  
  
```Output  
C:\Code  
```  
  
## <a name="see-also"></a>Consulte também  
 [Controle de diretório](../../c-runtime-library/directory-control.md)   
 [_chdir, _wchdir](../../c-runtime-library/reference/chdir-wchdir.md)   
 [_mkdir, _wmkdir](../../c-runtime-library/reference/mkdir-wmkdir.md)   
 [_rmdir, _wrmdir](../../c-runtime-library/reference/rmdir-wrmdir.md)
