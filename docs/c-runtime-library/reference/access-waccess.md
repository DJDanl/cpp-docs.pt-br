---
title: _access, _waccess | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: article
apiname:
- _access
- _waccess
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
- _waccess
- _access
- taccess
- waccess
- _taccess
dev_langs:
- C++
helpviewer_keywords:
- access function
- _taccess function
- waccess function
- _access function
- _waccess function
- taccess function
ms.assetid: ba34f745-85c3-49e5-a7d4-3590bd249dd3
caps.latest.revision: 27
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
ms.translationtype: Machine Translation
ms.sourcegitcommit: 3f91eafaf3b5d5c1b8f96b010206d699f666e224
ms.openlocfilehash: d0968ec14a43cfbbf1169f34ac929435787bc349
ms.contentlocale: pt-br
ms.lasthandoff: 04/01/2017

---
# <a name="access-waccess"></a>_access, _waccess
Determina se um arquivo é somente leitura ou não. Há versões mais seguras disponíveis, consulte [access_s, waccess_s](../../c-runtime-library/reference/access-s-waccess-s.md).  
  
## <a name="syntax"></a>Sintaxe  
  
```  
int _access(   
   const char *path,   
   int mode   
);  
int _waccess(   
   const wchar_t *path,   
   int mode   
);  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `path`  
 Caminho do arquivo ou do diretório.  
  
 `mode`  
 Atributo de leitura/gravação.  
  
## <a name="return-value"></a>Valor de retorno  
 Cada função retorna 0 se o arquivo tem o modo determinado. A função retornará -1 se o arquivo não existe ou não tem o modo determinado; Nesse caso, `errno` é definido como mostrado na tabela a seguir.  
  
 `EACCES`  
 Acesso negado: a configuração de permissão do arquivo não permite o acesso especificado.  
  
 `ENOENT`  
 Nome ou caminho do arquivo não encontrado.  
  
 `EINVAL`  
 Parâmetro inválido.  
  
 Para obter mais informações sobre esses e outros códigos de retorno, consulte [_doserrno, errno, _sys_errlist e _sys_nerr](../../c-runtime-library/errno-doserrno-sys-errlist-and-sys-nerr.md).  
  
## <a name="remarks"></a>Comentários  
 Quando usado com arquivos, a função `_access` determina se o arquivo ou o diretório especificado existe e tem os atributos especificados pelo valor de `mode`. Quando usado com diretórios, `_access` determina apenas se o diretório especificado existe. No [!INCLUDE[Win2kFamily](../../c-runtime-library/includes/win2kfamily_md.md)] e nos sistemas operacionais mais recentes, todos os diretórios têm acesso de leitura e gravação.  
  
|Valor `mode`|Verifica o arquivo quanto a|  
|------------------|---------------------|  
|00|Existência apenas|  
|02|Somente gravação|  
|04|Somente leitura|  
|06|Leitura e gravação|  
  
 Essa função apenas verifica se os arquivos e diretórios são somente leitura ou não, ela não verifica as configurações de segurança do sistema de arquivos. Para isso você precisa de um token de acesso. Para obter mais informações sobre a segurança do sistema de arquivos, consulte [Access Tokens (Tokens de acesso)](http://msdn.microsoft.com/library/windows/desktop/aa374909). Existe uma classe ATL para fornecer essa funcionalidade, consulte [Classe CAccessToken](../../atl/reference/caccesstoken-class.md).  
  
 A função `_waccess` é uma versão de caractere largo da função `_access`; o argumento `path` para `_waccess` é uma cadeia de caracteres larga. Caso contrário, `_waccess` e `_access` se comportam de forma idêntica.  
  
 Essa função valida seus parâmetros. Se `path` é `NULL` ou `mode` não especifica um modo válido, o manipulador de parâmetro inválido é invocado, conforme a descrição em [Validação do parâmetro](../../c-runtime-library/parameter-validation.md). Se a execução puder continuar, a função definirá `errno` como `EINVAL` e retornará –1.  
  
### <a name="generic-text-routine-mappings"></a>Mapeamentos da rotina de texto genérico  
  
|Rotina Tchar.h|_UNICODE e _MBCS não definidos|_MBCS definido|_UNICODE definido|  
|---------------------|--------------------------------------|--------------------|-----------------------|  
|`_taccess`|`_access`|`_access`|`_waccess`|  
  
## <a name="requirements"></a>Requisitos  
  
|Rotina|Cabeçalho necessário|Cabeçalhos opcionais|  
|-------------|---------------------|----------------------|  
|`_access`|\<io.h>|\<errno.h>|  
|`_waccess`|\<wchar.h> ou \<io.h>|\<errno.h>|  
  
## <a name="example"></a>Exemplo  
 O exemplo a seguir usa `_access` para verificar o arquivo nomeado crt_ACCESS.C a fim de saber se ele existe e se a gravação é permitida.  
  
```  
// crt_access.c  
// compile with: /W1  
// This example uses _access to check the file named  
// crt_ACCESS.C to see if it exists and if writing is allowed.  
  
#include  <io.h>  
#include  <stdio.h>  
#include  <stdlib.h>  
  
int main( void )  
{  
    // Check for existence.  
    if( (_access( "crt_ACCESS.C", 0 )) != -1 )  
    {  
        printf_s( "File crt_ACCESS.C exists.\n" );  
  
        // Check for write permission.  
        // Assume file is read-only.  
        if( (_access( "crt_ACCESS.C", 2 )) == -1 )  
            printf_s( "File crt_ACCESS.C does not have write permission.\n" );  
    }  
}  
```  
  
```Output  
File crt_ACCESS.C exists.  
File crt_ACCESS.C does not have write permission.  
```  
  
## <a name="see-also"></a>Consulte também  
 [Manipulação de Arquivos](../../c-runtime-library/file-handling.md)   
 [_chmod, _wchmod](../../c-runtime-library/reference/chmod-wchmod.md)   
 [_fstat, _fstat32, _fstat64, _fstati64, _fstat32i64, _fstat64i32](../../c-runtime-library/reference/fstat-fstat32-fstat64-fstati64-fstat32i64-fstat64i32.md)   
 [_open, _wopen](../../c-runtime-library/reference/open-wopen.md)   
 [Funções _stat, _wstat](../../c-runtime-library/reference/stat-functions.md)
