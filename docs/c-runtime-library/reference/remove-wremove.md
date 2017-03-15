---
title: remove, _wremove | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: article
apiname:
- _wremove
- remove
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
- remove
- _wremove
- _tremove
dev_langs:
- C++
helpviewer_keywords:
- tremove function
- _wremove function
- files [C++], deleting
- _tremove function
- files [C++], removing
- wremove function
- remove function
ms.assetid: b6345ec3-3289-4645-93a4-28b9e478cc19
caps.latest.revision: 10
author: corob-msft
ms.author: corob
manager: ghogen
translation.priority.ht:
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
translationtype: Machine Translation
ms.sourcegitcommit: a937c9d083a7e4331af63323a19fb207142604a0
ms.openlocfilehash: 604b71125f4ad056269e07ab759a67d367a5b5f6
ms.lasthandoff: 02/25/2017

---
# <a name="remove-wremove"></a>remove, _wremove
Excluir um arquivo.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
  
      int remove(  
   const char *path   
);  
int _wremove(  
   const wchar_t *path   
);  
```  
  
#### <a name="parameters"></a>Parâmetros  
 *path*  
 Caminho do arquivo a ser removido.  
  
## <a name="return-value"></a>Valor de retorno  
 Cada uma dessas funções retornará 0 se o arquivo for excluído com êxito. Caso contrário, ela retornará -1 e definirá `errno` como `EACCES` para indicar que o caminho especifica um arquivo somente leitura ou o que arquivo está aberto ou **ENOENT** para indicar que o nome ou caminho do arquivo não foi encontrado ou que o caminho especifica um diretório.  
  
 Consulte [_doserrno, errno, _sys_errlist e _sys_nerr](../../c-runtime-library/errno-doserrno-sys-errlist-and-sys-nerr.md) para obter mais informações sobre esses e outros códigos de retorno.  
  
## <a name="remarks"></a>Comentários  
 A função **remove** exclui o arquivo especificado por *path.* `_wremove` é uma versão de caractere largo de **_remove**; o argumento *path* para `_wremove` é uma cadeia de caracteres larga. Caso contrário, `_wremove` e **_remove** se comportam de forma idêntica. Todos os manipuladores de um arquivo devem ser fechados para que ele possa ser excluído.  
  
### <a name="generic-text-routine-mappings"></a>Mapeamentos da rotina de texto genérico  
  
|Rotina TCHAR.H|_UNICODE e _MBCS não definidos|_MBCS definido|_UNICODE definido|  
|---------------------|------------------------------------|--------------------|-----------------------|  
|`_tremove`|**remove**|**remove**|`_wremove`|  
  
## <a name="requirements"></a>Requisitos  
  
|Rotina|Cabeçalho necessário|  
|-------------|---------------------|  
|**remove**|\<stdio.h> ou \<io.h>|  
|`_wremove`|\<stdio.h> ou \<wchar.h>|  
  
 Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md) na Introdução.  
  
## <a name="libraries"></a>Libraries  
 Todas as versões das [bibliotecas em tempo de execução C](../../c-runtime-library/crt-library-features.md).  
  
## <a name="example"></a>Exemplo  
  
```  
// crt_remove.c  
/* This program uses remove to delete crt_remove.txt */  
  
#include <stdio.h>  
  
int main( void )  
{  
   if( remove( "crt_remove.txt" ) == -1 )  
      perror( "Could not delete 'CRT_REMOVE.TXT'" );  
   else  
      printf( "Deleted 'CRT_REMOVE.TXT'\n" );  
}  
```  
  
## <a name="input-crtremovetxt"></a>Entrada: crt_remove.txt  
  
```  
This file will be deleted.  
```  
  
## <a name="sample-output"></a>Saída de Exemplo  
  
```  
Deleted 'CRT_REMOVE.TXT'  
```  
  
## <a name="net-framework-equivalent"></a>Equivalente ao .NET Framework  
 [System::IO::File::Delete](https://msdn.microsoft.com/en-us/library/system.io.file.delete.aspx)  
  
## <a name="see-also"></a>Consulte também  
 [Manipulação de Arquivos](../../c-runtime-library/file-handling.md)   
 [_unlink, _wunlink](../../c-runtime-library/reference/unlink-wunlink.md)
