---
title: "remove, _wremove | Microsoft Docs"
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
  - "_wremove"
  - "remove"
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
  - "remove"
  - "_wremove"
  - "_tremove"
dev_langs: 
  - "C++"
  - "C"
helpviewer_keywords: 
  - "Função _tremove"
  - "Função _wremove"
  - "Arquivos  [C++], excluindo"
  - "Arquivos  [C++], removendo"
  - "Função remove"
  - "Função tremove"
  - "Função wremove"
ms.assetid: b6345ec3-3289-4645-93a4-28b9e478cc19
caps.latest.revision: 10
caps.handback.revision: 10
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# remove, _wremove
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Excluir um arquivo.  
  
## Sintaxe  
  
```  
  
      int remove(  
   const char *path   
);  
int _wremove(  
   const wchar_t *path   
);  
```  
  
#### Parâmetros  
 *caminho*  
 Caminho do arquivo a ser removido.  
  
## Valor de retorno  
 Cada uma dessas funções retornará 0 se o arquivo é excluído com êxito.  Caso contrário, retorna \-1 e define um `errno` ou a `EACCES` para indicar que o caminho especifica um arquivo somente leitura ou o arquivo está aberto, ou a **ENOENT** para indicar que o nome de arquivo ou o caminho não foram encontrados ou se o caminho especifica um diretório.  
  
 Consulte [\_doserrno, errno, \_sys\_errlist, e \_sys\_nerr](../Topic/errno,%20_doserrno,%20_sys_errlist,%20and%20_sys_nerr.md) para obter mais informações sobre esses e outros códigos de retorno.  
  
## Comentários  
 A função de **remove** exclui o arquivo especificado pelo *caminho.* `_wremove` é uma versão de ampla caractere de **\_remove**; o argumento *de caminho* a `_wremove` é uma cadeia de caracteres de ampla caractere.  `_wremove` e **\_remove** se comportam idêntica de outra forma.  Todas as alças para um arquivo devem ser fechadas antes que possa ser excluído.  
  
### Mapeamentos da rotina de texto genérico  
  
|Rotina TCHAR.H|\_UNICODE & \_MBCS não definido|\_MBCS definido|\_UNICODE definido|  
|--------------------|-------------------------------------|---------------------|------------------------|  
|`_tremove`|**remover**|**remover**|`_wremove`|  
  
## Requisitos  
  
|Rotina|Cabeçalho necessário|  
|------------|--------------------------|  
|**remover**|\<stdio.h ou\> io.h \<\>|  
|`_wremove`|\<stdio.h\> ou \<wchar.h\>|  
  
 Para informações adicionais de compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md) na Introdução.  
  
## Bibliotecas  
 Todas as versões das [Bibliotecas em tempo de execução C](../../c-runtime-library/crt-library-features.md).  
  
## Exemplo  
  
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
  
## Entrada: crt\_remove.txt  
  
```  
This file will be deleted.  
```  
  
## Saída de Exemplo  
  
```  
Deleted 'CRT_REMOVE.TXT'  
```  
  
## Equivalência do .NET Framework  
 [System::IO::File::Delete](https://msdn.microsoft.com/en-us/library/system.io.file.delete.aspx)  
  
## Consulte também  
 [Manipulação de arquivos](../../c-runtime-library/file-handling.md)   
 [\_unlink, \_wunlink](../Topic/_unlink,%20_wunlink.md)