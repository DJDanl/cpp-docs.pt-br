---
title: "_access, _waccess | Microsoft Docs"
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
  - "_access"
  - "_waccess"
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
  - "_waccess"
  - "_access"
  - "taccess"
  - "waccess"
  - "_taccess"
dev_langs: 
  - "C++"
  - "C"
helpviewer_keywords: 
  - "Função _access"
  - "Função _taccess"
  - "Função _waccess"
  - "Função access"
  - "Função taccess"
  - "Função waccess"
ms.assetid: ba34f745-85c3-49e5-a7d4-3590bd249dd3
caps.latest.revision: 27
caps.handback.revision: 25
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# _access, _waccess
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Determina se um arquivo for somente leitura ou não.  Versões mais seguros estão disponíveis; consulte [\_access\_s, \_waccess\_s](../../c-runtime-library/reference/access-s-waccess-s.md).  
  
## Sintaxe  
  
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
  
#### Parâmetros  
 `path`  
 Arquivo ou diretório.  
  
 `mode`  
 Atributo de leitura\/gravação.  
  
## Valor de retorno  
 Cada função retornará 0 se o arquivo tiver o modo determinado.  A função retorna – 1 se o arquivo nomeado não existe ou não tiver o modo determinado; nesse caso, `errno` é definido como mostra a tabela a seguir.  
  
 `EACCES`  
 Acesso negado: a configuração de permissão do arquivo não permite o acesso especificado.  
  
 `ENOENT`  
 Nome de arquivo ou caminho não encontrado.  
  
 `EINVAL`  
 Parâmetro inválido.  
  
 Para obter mais informações sobre esses e outros códigos de retorno, consulte [\_doserrno, errno, \_sys\_errlist, and \_sys\_nerr](../Topic/errno,%20_doserrno,%20_sys_errlist,%20and%20_sys_nerr.md).  
  
## Comentários  
 Quando usada com arquivos, a função de `_access` determina se o arquivo ou diretório especificado existir e tem os atributos especificados pelo valor de `mode`.  Quando usado com diretórios, `_access` determina se o diretório especificado existir; em [!INCLUDE[Win2kFamily](../../c-runtime-library/includes/win2kfamily_md.md)] e em sistemas operacionais mais tarde, todos os diretórios têm acesso de leitura e gravação.  
  
|Valor `mode`|As verificações para arquivo|  
|------------------|----------------------------------|  
|00|Somente existente|  
|02|Somente gravação|  
|04|Somente leitura|  
|06|Leitura e gravação|  
  
 Essa função só verifica se o arquivo e diretório é somente leitura ou não, ele não verifica as configurações de segurança do sistema de arquivos.  Para que você precisa de um token de acesso.  Para obter mais informações sobre a segurança do sistema de arquivos, consulte [Tokens de acesso](http://msdn.microsoft.com/library/windows/desktop/aa374909).  Uma classe de ATL existir para fornecer essa funcionalidade; consulte [Classe de CAccessToken](../Topic/CAccessToken%20Class.md).  
  
 `_waccess` é uma versão de caractere longo de `_access`; o argumento `path` para `_waccess` é uma cadeia de caractere longo.  Caso contrário, `_waccess` e `_access`, ao contrário, se comportam de forma idêntica.  
  
 Essa função valida seus parâmetros.  Se `path` é `NULL` ou `mode` não especificar um modo válido, o manipulador inválido do parâmetro será chamado, conforme descrito em [Validação do parâmetro](../../c-runtime-library/parameter-validation.md).  Se a execução for permitida continuar, a função `errno` define a `EINVAL` e retorna \-1.  
  
### Mapeamentos da rotina de texto genérico  
  
|Rotina Tchar.h|\_UNICODE e \_MBCS não definidos|\_MBCS definido|\_UNICODE definido|  
|--------------------|--------------------------------------|---------------------|------------------------|  
|`_taccess`|`_access`|`_access`|`_waccess`|  
  
## Requisitos  
  
|Rotina|Cabeçalho necessário|Cabeçalhos opcionais|  
|------------|--------------------------|--------------------------|  
|`_access`|\<io.h\>|\<errno.h\>|  
|`_waccess`|\<wchar.h ou\> io.h \<\>|\<errno.h\>|  
  
## Exemplo  
 O exemplo a seguir usa `_access` para verificar o arquivo chamado crt\_ACCESS.C para saber se ele existe e se escrever é permitida.  
  
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
  
  **Arquivo crt\_ACCESS.C existe.**  
**Arquivo crt\_ACCESS.C não tem permissão de gravação.**   
## Equivalência do .NET Framework  
 <xref:System.IO.FileAccess?displayProperty=fullName>  
  
## Consulte também  
 [Manipulação de arquivos](../../c-runtime-library/file-handling.md)   
 [\_chmod, \_wchmod](../../c-runtime-library/reference/chmod-wchmod.md)   
 [\_fstat, \_fstat32, \_fstat64, \_fstati64, \_fstat32i64, \_fstat64i32](../../c-runtime-library/reference/fstat-fstat32-fstat64-fstati64-fstat32i64-fstat64i32.md)   
 [\_open, \_wopen](../../c-runtime-library/reference/open-wopen.md)   
 [Funções \_stat, \_wstat](../../c-runtime-library/reference/stat-functions.md)