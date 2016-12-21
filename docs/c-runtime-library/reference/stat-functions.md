---
title: "STAT, stat32, stat64, stati64, _stat32i64, _stat64i32, wstat, wstat32, wstat64, wstati64, _wstat32i64, _wstat64i32 | Microsoft Docs"
ms.custom: ""
ms.date: "12/09/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
apiname: 
  - "_wstat64"
  - "_stati64"
  - "_stat32"
  - "_stat32i64"
  - "_stat"
  - "_wstati64"
  - "_wstat32"
  - "_wstat64i32"
  - "_wstat"
  - "_stat64"
  - "_stat64i32"
  - "_wstat32i64"
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
  - "tstat32"
  - "tstat"
  - "_tstat64i32"
  - "tstati64"
  - "_wstat64"
  - "_wstat32"
  - "wstati64"
  - "tstat64"
  - "_stati64"
  - "_wstat"
  - "wstat64i32"
  - "stat32i64"
  - "tstat32i64"
  - "_tstat"
  - "_wstati64"
  - "_tstati64"
  - "_wstat32i64"
  - "wstat32"
  - "_wstat64i32"
  - "_stat"
  - "_tstat32"
  - "stat64i32"
  - "wstat64"
  - "stat"
  - "_stat32i64"
  - "_stat32"
  - "stati64"
  - "wstat"
  - "_stat64i32"
  - "stat32"
  - "_tstat32i64"
  - "tstat64i32"
  - "_tstat64"
  - "_stat64"
  - "stat/_stat"
  - "stat/_stat32"
  - "stat/_stat64"
  - "stat/_stati64"
  - "stat/_stat32i64"
  - "stat/_stat64i32"
  - "stat/_wstat"
  - "stat/_wstat32"
  - "stat/_wstat64"
  - "stat/_wstati64"
  - "stat/_wstat32i64"
  - "stat/_wstat64i32"
dev_langs: 
  - "C++"
  - "C"
helpviewer_keywords: 
  - "arquivos [C++], informações de status"
  - "Função _stat"
  - "Função _wstat"
  - "Função _stat64i32"
  - "Função tstat"
  - "Função _tstat64i32"
  - "Função _stati64"
  - "Função _stat64"
  - "Função tstati64"
  - "Função wstati64"
  - "Função wstat64"
  - "Função _wstat64i32"
  - "Função _tstat32i64"
  - "Função _stat32i64"
  - "Função stat"
  - "status de arquivos"
  - "Função _tstat32"
  - "Função tstat64"
  - "Função _wstat64"
  - "Função _tstat"
  - "Função _stat32"
  - "Função wstat"
  - "Função _wstat32i64"
  - "Função _tstati64"
  - "Função _wstat32"
  - "Função stat64"
  - "Função stati64"
  - "Função _wstati64"
  - "Função _tstat64"
  - "arquivos [C++], obtendo informações de status"
ms.assetid: 99a75ae6-ff26-47ad-af70-5ea7e17226a5
caps.latest.revision: 26
caps.handback.revision: 26
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# STAT, stat32, stat64, stati64, _stat32i64, _stat64i32, wstat, wstat32, wstat64, wstati64, _wstat32i64, _wstat64i32
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Obter informações de status em um arquivo.  
  
## Sintaxe  
  
```  
int _stat(  
   const char *path,  
   struct _stat *buffer   
);  
int _stat32(  
   const char *path,  
   struct __stat32 *buffer   
);  
int _stat64(  
   const char *path,  
   struct __stat64 *buffer   
);  
int _stati64(  
   const char *path,  
   struct _stati64 *buffer   
);  
int _stat32i64(  
   const char *path,  
   struct _stat32i64 *buffer   
);  
int _stat64i32(  
   const char *path,  
   struct _stat64i32 *buffer   
);  
int _wstat(  
   const wchar_t *path,  
   struct _stat *buffer   
);  
int _wstat32(  
   const wchar_t *path,  
   struct __stat32 *buffer   
);  
int _wstat64(  
   const wchar_t *path,  
   struct __stat64 *buffer   
);  
int _wstati64(  
   const wchar_t *path,  
   struct _stati64 *buffer   
);  
int _wstat32i64(  
   const wchar_t *path,  
   struct _stat32i64 *buffer   
);  
int _wstat64i32(  
   const wchar_t *path,  
   struct _stat64i32 *buffer   
);  
```  
  
#### Parâmetros  
 `path`  
 Ponteiro para uma cadeia de caracteres contendo o caminho do arquivo ou diretório existente.  
  
 `buffer`  
 Ponteiro para a estrutura que armazena os resultados.  
  
## Valor de retorno  
 Cada uma dessas funções retornará 0 se as informações de status do arquivo são obtidas. Um valor de retorno de\-1 indica um erro, caso em que `errno` é definido como `ENOENT`, indicando que o nome do arquivo ou caminho não pode ser encontrado. Um valor de retorno `EINVAL` indica um parâmetro inválido; `errno` também é definida como `EINVAL` nesse caso.  
  
 Consulte [doserrno, errno, sys\_errlist e sys\_nerr](../Topic/errno,%20_doserrno,%20_sys_errlist,%20and%20_sys_nerr.md) para obter mais informações sobre esta e outras, códigos de retorno.  
  
 O carimbo de data em um arquivo pode ser representado se for mais recente do que meia\-noite de 1º de janeiro de 1970 e antes de 23:59:59, 31 de dezembro de 3000 a UTC, a menos que você use `_stat32` ou `_wstat32`, ou tenha definido `_USE_32BIT_TIME_T`, caso em que a data pode ser representada somente até 23:59:59 18 de janeiro de 2038, UTC.  
  
## Comentários  
 O `_stat` função obtém informações sobre o arquivo ou diretório especificado por `path` e o armazena na estrutura apontada por `buffer`.`_stat` manipula automaticamente os argumentos de cadeia de caracteres multibyte como apropriados, reconhecendo as sequências de caracteres multibyte de acordo com a página de código multibyte em uso no momento.  
  
 `_wstat` é uma versão de caractere largo de `_stat`; o `path` argumento `_wstat` é uma cadeia de caracteres largos.`_wstat` e `_stat` tenham comportamento idêntico, exceto que `_wstat` não lida com cadeias de caracteres multibyte.  
  
 Variações dessas funções oferecem suporte a tipos de tempo de 32 ou 64 bits e tamanhos de arquivo de 32 ou 64 bits. O primeiro sufixo numérico \(`32` ou `64`\) indica o tamanho do tempo tipo usado; o segundo sufixo é `i32` ou `i64`, indicando se o tamanho do arquivo é representado como um inteiro de 32 bits ou 64 bits.  
  
 `_stat` é equivalente a `_stat64i32`, e `struct``_stat` contém a hora de 64 bits. Isso é verdadeiro, a menos que `_USE_32BIT_TIME_T` é definido, caso em que o comportamento antigo está em vigor; `_stat` usa um tempo de 32 bits, e `struct``_stat` contém a hora de 32 bits. O mesmo é verdadeiro para `_stati64`.  
  
> [!NOTE]
>  `_wstat` não funciona com [!INCLUDE[wiprlhext](../../c-runtime-library/reference/includes/wiprlhext_md.md)] links simbólicos. Nesses casos, `_wstat` sempre relatará um tamanho de arquivo de 0.`_stat` funciona corretamente com links simbólicos.  
  
 Esta função valida seus parâmetros. Se `path` ou `buffer` é `NULL`, o manipulador de parâmetro inválido é invocado, conforme descrito em [Validação do parâmetro](../../c-runtime-library/parameter-validation.md).  
  
### Tipo de tempo e variações de tipo de comprimento de arquivo de STAT  
  
|Funções|\_USE\_32BIT\_TIME\_T definido?|Tipo de tempo|Tipo de tamanho de arquivo|  
|-------------|-------------------------------------|-------------------|--------------------------------|  
|`_stat`, `_wstat`|Não definido|64 bits|32 bits|  
|`_stat`, `_wstat`|Definido|32 bits|32 bits|  
|`_stat32`, `_wstat32`|Não é afetada pela definição de macro|32 bits|32 bits|  
|`_stat64`, `_wstat64`|Não é afetada pela definição de macro|64 bits|64 bits|  
|`_stati64`, `_wstati64`|Não definido|64 bits|64 bits|  
|`_stati64`, `_wstati64`|Definido|32 bits|64 bits|  
|`_stat32i64`, `_wstat32i64`|Não é afetada pela definição de macro|32 bits|64 bits|  
|`_stat64i32`, `_wstat64i32`|Não é afetada pela definição de macro|64 bits|32 bits|  
  
### Mapeamentos de rotina de texto genérico  
  
|TCHAR. Rotina H|Unicode e MBCS não definidos|MBCS definido|Unicode definido|  
|---------------------|----------------------------------|-------------------|----------------------|  
|`_tstat`|`_stat`|`_stat`|`_wstat`|  
|`_tstat64`|`_stat64`|`_stat64`|`_wstat64`|  
|`_tstati64`|`_stati64`|`_stati64`|`_wstati64`|  
|`_tstat32i64`|`_stat32i64`|`_stat32i64`|`_wstat32i64`|  
|`_tstat64i32`|`_stat64i32`|`_stat64i32`|`_wstat64i32`|  
  
 O `_stat` estrutura, definida em SYS\\STAT. H, inclui os seguintes campos.  
  
 `st_gid`  
 Identificador numérico do grupo que possui o arquivo \(específico do UNIX\) esse campo sempre será zero em sistemas Windows. Um arquivo redirecionado é classificado como um arquivo do Windows.  
  
 `st_atime`  
 Hora do último acesso do arquivo. Válido em NTFS, mas não em FAT unidades de disco formatadas.  
  
 `st_ctime`  
 Hora de criação do arquivo. Válido em NTFS, mas não em FAT unidades de disco formatadas.  
  
 `st_dev`  
 Número do disco que contém o arquivo da unidade \(mesmo que `st_rdev`\).  
  
 `st_ino`  
 Número do nó de informações \(o `inode`\) para o arquivo \(específico do UNIX\). Em sistemas de arquivos UNIX, o `inode` descreve a data do arquivo e carimbos de hora, permissões e conteúdo. Quando arquivos são vinculados uns aos outros, eles compartilham o mesmo `inode`. O `inode`, e, portanto, `st_ino`, não tem nenhum significado nos sistemas de arquivos FAT, HPFS ou NTFS.  
  
 `st_mode`  
 Máscara de bits para informações sobre o modo de arquivo. O `_S_IFDIR` bit é definido se `path` Especifica um diretório; o `_S_IFREG` bit é definido se `path` Especifica um arquivo comum ou um dispositivo. Bits de leitura\/gravação do usuário estão definidas de acordo com o modo de permissão do arquivo; usuário executar bits são definidos de acordo com a extensão de nome de arquivo.  
  
 `st_mtime`  
 Hora da última modificação do arquivo.  
  
 `st_nlink`  
 Sempre 1 em sistemas de arquivos não NTFS.  
  
 `st_rdev`  
 Número do disco que contém o arquivo da unidade \(mesmo que `st_dev`\).  
  
 `st_size`  
 Tamanho do arquivo em bytes. um inteiro de 64 bits para variações com a `i64` sufixo**.**  
  
 `st_uid`  
 Identificador numérico do usuário que possui o arquivo \(específico do UNIX\). Esse campo sempre será zero em sistemas Windows. Um arquivo redirecionado é classificado como um arquivo do Windows.  
  
 Se `path` refere\-se a um dispositivo, o `st_size`, vários campos de hora, `st_dev`, e `st_rdev` campos de `_stat` estrutura fazem sentido. Porque STAT. H usa o [dev\_t](../../c-runtime-library/standard-types.md) tipo que é definido em tipos. H, você deve incluir tipos. H antes de estatística. H em seu código.  
  
## Requisitos  
  
|Rotina|Cabeçalho necessário|Cabeçalhos opcionais|  
|------------|--------------------------|--------------------------|  
|`_stat`, `_stat32`, `_stat64`, `_stati64`, `_stat32i64`, `_stat64i32`|\< sys\/types.h \> seguido por \< sys\/stat.h \>|\< errno. h \>|  
|`_wstat`, `_wstat32`, `_wstat64`, `_wstati64`, `_wstat32i64`, `_wstat64i32`|\< sys\/types.h \> seguido por \< sys\/stat.h \> ou \< WCHAR \>|\< errno. h \>|  
  
 Para obter informações adicionais sobre compatibilidade, consulte [compatibilidade](../../c-runtime-library/compatibility.md) na introdução.  
  
## Exemplo  
  
```  
// crt_stat.c  
// This program uses the _stat function to  
// report information about the file named crt_stat.c.  
  
#include <time.h>  
#include <sys/types.h>  
#include <sys/stat.h>  
#include <stdio.h>  
#include <errno.h>  
  
int main( void )  
{  
   struct _stat buf;  
   int result;  
   char timebuf[26];  
   char* filename = "crt_stat.c";  
   errno_t err;  
  
   // Get data associated with "crt_stat.c":   
   result = _stat( filename, &buf );  
  
   // Check if statistics are valid:   
   if( result != 0 )  
   {  
      perror( "Problem getting information" );  
      switch (errno)  
      {  
         case ENOENT:  
           printf("File %s not found.\n", filename);  
           break;  
         case EINVAL:  
           printf("Invalid parameter to _stat.\n");  
           break;  
         default:  
           /* Should never be reached. */  
           printf("Unexpected error in _stat.\n");  
      }  
   }  
   else  
   {  
      // Output some of the statistics:   
      printf( "File size     : %ld\n", buf.st_size );  
      printf( "Drive         : %c:\n", buf.st_dev + 'A' );  
      err = ctime_s(timebuf, 26, &buf.st_mtime);  
      if (err)  
      {  
         printf("Invalid arguments to ctime_s.");  
         exit(1);  
      }  
      printf( "Time modified : %s", timebuf );  
   }  
}  
```  
  
```Output  
Tamanho do arquivo: unidade 732: c: tempo modificado: 07 de fevereiro de quinta-feira 14:39:36 2002  
```  
  
## Equivalência do .NET Framework  
  
-   [System::IO::file::GetAttributes](https://msdn.microsoft.com/en-us/library/system.io.file.getattributes.aspx)  
  
-   [System::IO::file::GetCreationTime](https://msdn.microsoft.com/en-us/library/system.io.file.getcreationtime.aspx)  
  
-   [System::IO::file::GetLastAccessTime](https://msdn.microsoft.com/en-us/library/system.io.file.getlastaccesstime.aspx)  
  
-   [System::IO::file::GetLastWriteTime](https://msdn.microsoft.com/en-us/library/system.io.file.getlastwritetime.aspx)  
  
## Consulte também  
 [Manipulação de arquivos](../../c-runtime-library/file-handling.md)   
 [\_access, \_waccess](../../c-runtime-library/reference/access-waccess.md)   
 [\_fstat, \_fstat32, \_fstat64, \_fstati64, \_fstat32i64, \_fstat64i32](../../c-runtime-library/reference/fstat-fstat32-fstat64-fstati64-fstat32i64-fstat64i32.md)   
 [\_getmbcp](../../c-runtime-library/reference/getmbcp.md)   
 [\_setmbcp](../../c-runtime-library/reference/setmbcp.md)