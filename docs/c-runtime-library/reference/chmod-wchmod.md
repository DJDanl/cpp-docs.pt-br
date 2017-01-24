---
title: "_chmod, _wchmod | Microsoft Docs"
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
  - "_chmod"
  - "_wchmod"
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
  - "_chmod"
  - "_wchmod"
  - "wchmod"
dev_langs: 
  - "C++"
  - "C"
helpviewer_keywords: 
  - "Função _chmod"
  - "Função _wchmod"
  - "Função chmod"
  - "permissões de arquivo [C++]"
  - "Arquivos  [C++], alterando permissões"
  - "Função wchmod"
ms.assetid: 92f7cb86-b3b0-4232-a599-b8c04a2f2c19
caps.latest.revision: 23
caps.handback.revision: 21
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# _chmod, _wchmod
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Altera as configurações de arquivo permissão.  
  
## Sintaxe  
  
```  
  
      int _chmod(   
   const char *filename,  
   int pmode   
);  
int _wchmod(   
   const wchar_t *filename,  
   int pmode   
);  
```  
  
#### Parâmetros  
 `filename`  
 Nome do arquivo.  
  
 `pmode`  
 Configuração de permissão para o arquivo.  
  
## Valor de retorno  
 Essas funções retornam 0 se a configuração de permissão é alterada com êxito.  Um valor de retorno – 1 indica falha.  Se o arquivo especificado não pôde ser encontrado, `errno` é definido como `ENOENT`; se um parâmetro for inválido, `errno` está definido como `EINVAL`.  
  
## Comentários  
 As alterações de função de `_chmod` a configuração de permissão do arquivo especificado por `filename`*.* A configuração de permissão controla o acesso de leitura e gravação no arquivo.  A expressão de inteiro `pmode` contém uma ou ambas as seguintes constantes manifestas, definido no sistema \\ Stat.h.  
  
 `_S_IWRITE`  
 Gravando permitida.  
  
 `_S_IREAD`  
 Leitura permitidas.  
  
 `_S_IREAD | _S_IWRITE`  
 Leitura e gravação permitidas.  
  
 Quando ambas as constantes são fornecidas, são adicionadas com o operador bit a bit de `OR` \(          `|` \).  Se a permissão de gravação não for especificado, o arquivo é somente leitura.  Observe que todos os arquivos são sempre legíveis; não é possível atribuir a permissão somente gravação.  Portanto, os modos `_S_IWRITE` e `_S_IREAD | _S_IWRITE` são equivalentes.  
  
 `_wchmod` é uma versão de caractere longo de `_chmod`; o argumento `filename` para `_wchmod` é uma cadeia de caractere longo.  Caso contrário, `_wchmod` e `_chmod`, ao contrário, se comportam de forma idêntica.  
  
 Essa função valida seus parâmetros.  Se `pmode` não é uma combinação de uma das constantes manifestas nem inserir um conjunto de substituição de constantes, a função ignora somente as.  Se `filename` é `NULL`, o parâmetro de manipulador inválido é invocado, como descrito em [Validação do parâmetro](../../c-runtime-library/parameter-validation.md).  Se a execução for permitida continuar, `errno` está definido como `EINVAL` e a função retorna \-1.  
  
### Mapeamentos da rotina de texto genérico  
  
|Rotina Tchar.h|\_UNICODE e \_MBCS não definidos|\_MBCS definido|\_UNICODE definido|  
|--------------------|--------------------------------------|---------------------|------------------------|  
|`_tchmod`|`_chmod`|`_chmod`|`_wchmod`|  
  
## Requisitos  
  
|Rotina|Cabeçalho necessário|Cabeçalho opcional|  
|------------|--------------------------|------------------------|  
|`_chmod`|\<io.h\>|\<o sistema\/types.h, o sistema\>\<\/stat.h, errno.h\>\<\>|  
|`_wchmod`|\<io.h ou\> wchar.h \<\>|\<o sistema\/types.h, o sistema\>\<\/stat.h, errno.h\>\<\>|  
  
 Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md) na Introdução.  
  
## Exemplo  
  
```  
// crt_chmod.c  
// This program uses _chmod to  
// change the mode of a file to read-only.  
// It then attempts to modify the file.  
//  
  
#include <sys/types.h>  
#include <sys/stat.h>  
#include <io.h>  
#include <stdio.h>  
#include <stdlib.h>  
#include <errno.h>  
  
// Change the mode and report error or success   
void set_mode_and_report(char * filename, int mask)  
{  
   // Check for failure   
   if( _chmod( filename, mask ) == -1 )  
   {  
      // Determine cause of failure and report.   
      switch (errno)  
      {  
         case EINVAL:  
            fprintf( stderr, "Invalid parameter to chmod.\n");  
            break;  
         case ENOENT:  
            fprintf( stderr, "File %s not found\n", filename );  
            break;  
         default:  
            // Should never be reached   
            fprintf( stderr, "Unexpected error in chmod.\n" );  
       }  
   }  
   else  
   {  
      if (mask == _S_IREAD)  
        printf( "Mode set to read-only\n" );  
      else if (mask & _S_IWRITE)  
        printf( "Mode set to read/write\n" );  
   }  
   fflush(stderr);  
}  
  
int main( void )  
{   
  
   // Create or append to a file.   
   system( "echo /* End of file */ >> crt_chmod.c_input" );  
  
   // Set file mode to read-only:   
   set_mode_and_report("crt_chmod.c_input ", _S_IREAD );  
  
   system( "echo /* End of file */ >> crt_chmod.c_input " );  
  
   // Change back to read/write:   
   set_mode_and_report("crt_chmod.c_input ", _S_IWRITE );  
  
   system( "echo /* End of file */ >> crt_chmod.c_input " );   
}   
```  
  
  **`Uma linha de texto.`  `Uma linha de texto.` Modo definido como somente leitura**  
**O acesso foi negado.**  
**Modo definido como leitura\/gravação**   
## Equivalência do .NET Framework  
  
-   [System::IO::File::SetAttributes](https://msdn.microsoft.com/en-us/library/system.io.file.setattributes.aspx)  
  
-   [System::Security::Permissions::FileIOPermission](https://msdn.microsoft.com/en-us/library/system.security.permissions.fileiopermission.aspx)  
  
## Consulte também  
 [Manipulação de arquivos](../../c-runtime-library/file-handling.md)   
 [\_access, \_waccess](../../c-runtime-library/reference/access-waccess.md)   
 [\_creat, \_wcreat](../../c-runtime-library/reference/creat-wcreat.md)   
 [\_fstat, \_fstat32, \_fstat64, \_fstati64, \_fstat32i64, \_fstat64i32](../../c-runtime-library/reference/fstat-fstat32-fstat64-fstati64-fstat32i64-fstat64i32.md)   
 [\_open, \_wopen](../../c-runtime-library/reference/open-wopen.md)   
 [Funções \_stat, \_wstat](../../c-runtime-library/reference/stat-functions.md)