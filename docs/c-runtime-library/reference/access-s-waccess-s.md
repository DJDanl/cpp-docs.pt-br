---
title: "_access_s, _waccess_s | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
apiname: 
  - "_access_s"
  - "_waccess_s"
apilocation: 
  - "msvcrt.dll"
  - "msvcr80.dll"
  - "msvcr90.dll"
  - "msvcr100.dll"
  - "msvcr100_clr0400.dll"
  - "msvcr110.dll"
  - "msvcr110_clr0400.dll"
  - "msvcr120.dll"
  - "msvcr120_clr0400.dll"
  - "ucrtbase.dll"
  - "api-ms-win-crt-filesystem-l1-1-0.dll"
apitype: "DLLExport"
f1_keywords: 
  - "waccess_s"
  - "access_s"
  - "_waccess_s"
  - "_access_s"
dev_langs: 
  - "C++"
  - "C"
helpviewer_keywords: 
  - "Função _access_s"
  - "Função _taccess_s"
  - "Função _waccess_s"
  - "Função access_s"
  - "Função taccess_s"
  - "Função waccess_s"
ms.assetid: fb3004fc-dcd3-4569-8b27-d817546e947e
caps.latest.revision: 28
caps.handback.revision: 26
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# _access_s, _waccess_s
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Determina permissões de leitura\/gravação de arquivo.  Essa é uma versão de [\_access, \_waccess](../../c-runtime-library/reference/access-waccess.md) com aprimoramentos de segurança conforme descrito em [Recursos de segurança no CRT](../Topic/Security%20Features%20in%20the%20CRT.md).  
  
## Sintaxe  
  
```  
errno_t _access_s(   
   const char *path,   
   int mode   
);  
errno_t _waccess_s(   
   const wchar_t *path,   
   int mode   
);  
```  
  
#### Parâmetros  
 `path`  
 Arquivo ou diretório.  
  
 `mode`  
 Configuração de permissão.  
  
## Valor de retorno  
 Cada função retornará 0 se o arquivo tiver o modo determinado.  A função retorna um código de erro se o arquivo nomeado não existe ou não está acessível no modo determinado.  Nesse caso, a função retornará um código de erro do cluster como se segue e também define `errno` com o mesmo valor.  
  
 `EACCES`  
 Acesso negado.  A configuração de permissão do arquivo não permite o acesso especificado.  
  
 `ENOENT`  
 Nome de arquivo ou caminho não encontrado.  
  
 `EINVAL`  
 Parâmetro inválido.  
  
 Para obter mais informações, consulte [errno, \_doserrno, \_sys\_errlist e \_sys\_nerr](../Topic/errno,%20_doserrno,%20_sys_errlist,%20and%20_sys_nerr.md).  
  
## Comentários  
 Quando usada com arquivos, a função de `_access_s` determina se o arquivo especificado existir e pode ser acessado como especificado pelo valor de `mode`.  Quando usado com diretórios, `_access_s` determina se o diretório especificado existe.  Em [!INCLUDE[Win2kFamily](../../c-runtime-library/includes/win2kfamily_md.md)] e em sistemas operacionais mais tarde, todos os diretórios têm acesso de leitura e gravação.  
  
|valor do modo|As verificações para arquivo|  
|-------------------|----------------------------------|  
|00|Somente existente.|  
|02|Permissão de gravação.|  
|04|Permissão de leitura.|  
|06|Permissão de leitura e gravação.|  
  
 Permissão para ler ou gravar o arquivo não é suficiente para assegurar a capacidade de abrir um arquivo.  Por exemplo, se um arquivo está bloqueado por outro processo, pode não estar acessível mesmo que retorna 0 de `_access_s` .  
  
 `_waccess_s` é uma versão de ampla caractere de `_access_s`, onde o argumento de `path` a `_waccess_s` é uma cadeia de caracteres de ampla caractere.  Caso contrário, `_waccess_s` e `_access_s` se comportam de forma idêntica.  
  
 Essas funções validam seus parâmetros.  Se `path` é `NULL` ou `mode` não especificar um modo válido, o manipulador inválido do parâmetro será chamado, conforme descrito em [Validação do parâmetro](../../c-runtime-library/parameter-validation.md).  Se a execução puder continuar, essas funções definirão `errno` como `EINVAL` e retornarão `EINVAL`.  
  
### Mapeamentos da rotina de texto genérico  
  
|Rotina Tchar.h|\_UNICODE e \_MBCS não definidos|\_MBCS definido|\_UNICODE definido|  
|--------------------|--------------------------------------|---------------------|------------------------|  
|`_taccess_s`|`_access_s`|`_access_s`|`_waccess_s`|  
  
## Requisitos  
  
|Rotina|Cabeçalho necessário|Cabeçalho opcional|  
|------------|--------------------------|------------------------|  
|`_access_s`|\<io.h\>|\<errno.h\>|  
|`_waccess_s`|\<wchar.h ou\> io.h \<\>|\<errno.h\>|  
  
## Exemplo  
 Este exemplo usa `_access_s` para verificar o arquivo chamado crt\_access\_s.c para saber se ele existe e se escrever é permitida.  
  
```  
// crt_access_s.c  
  
#include <io.h>  
#include <stdio.h>  
#include <stdlib.h>  
  
int main( void )  
{  
    errno_t err = 0;  
  
    // Check for existence.   
    if ((err = _access_s( "crt_access_s.c", 0 )) == 0 )  
    {  
        printf_s( "File crt_access_s.c exists.\n" );  
  
        // Check for write permission.   
        if ((err = _access_s( "crt_access_s.c", 2 )) == 0 )  
        {  
            printf_s( "File crt_access_s.c does have "  
                      "write permission.\n" );  
        }  
        else  
        {  
            printf_s( "File crt_access_s.c does not have "  
                      "write permission.\n" );  
        }  
    }  
    else  
    {  
        printf_s( "File crt_access_s.c does not exist.\n" );  
    }  
}  
```  
  
  **Arquivo crt\_access\_s.c existe.**  
**Arquivo crt\_access\_s.c não tem permissão de gravação.**   
## Equivalência do .NET Framework  
 <xref:System.IO.FileAccess?displayProperty=fullName>  
  
## Consulte também  
 [Manipulação de arquivos](../../c-runtime-library/file-handling.md)   
 [\_access, \_waccess](../../c-runtime-library/reference/access-waccess.md)   
 [\_chmod, \_wchmod](../../c-runtime-library/reference/chmod-wchmod.md)   
 [\_fstat, \_fstat32, \_fstat64, \_fstati64, \_fstat32i64, \_fstat64i32](../../c-runtime-library/reference/fstat-fstat32-fstat64-fstati64-fstat32i64-fstat64i32.md)   
 [\_open, \_wopen](../../c-runtime-library/reference/open-wopen.md)   
 [Funções \_stat, \_wstat](../../c-runtime-library/reference/stat-functions.md)