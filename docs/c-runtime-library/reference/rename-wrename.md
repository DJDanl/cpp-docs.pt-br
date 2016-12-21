---
title: "rename, _wrename | Microsoft Docs"
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
  - "rename"
  - "_wrename"
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
  - "_wrename"
  - "_trename"
  - "Rename"
dev_langs: 
  - "C++"
  - "C"
helpviewer_keywords: 
  - "Função _trename"
  - "Função _wrename"
  - "diretórios [C++], renomeando"
  - "Arquivos  [C++], renomeando"
  - "nomes [C++], alterando diretório"
  - "nomes [C++], alterando o arquivo"
  - "Função rename"
  - "renomeando diretórios"
  - "renomeando arquivos"
  - "Função trename"
  - "Função wrename"
ms.assetid: 9f0a6103-26a2-4dda-b14b-79a48946266a
caps.latest.revision: 9
caps.handback.revision: 9
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# rename, _wrename
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Renomear um arquivo ou diretório.  
  
## Sintaxe  
  
```  
  
      int rename(  
   const char *oldname,  
   const char *newname   
);  
int _wrename(  
   const wchar_t *oldname,  
   const wchar_t *newname   
);  
```  
  
#### Parâmetros  
 *oldname*  
 Ponteiro para o nome antigo.  
  
 *newname*  
 Ponteiro para o novo nome.  
  
## Valor de retorno  
 Cada uma dessas funções retornará 0 se for bem\-sucedida.  Em um erro, a função retorna um valor diferente de zero e define `errno` a um dos seguintes valores:  
  
 `EACCES`  
 Arquivo ou diretório especificado *por newname* já existe ou não podem ser criados \(caminho inválido\); ou o *oldname* é um diretório e o *newname* especifica um caminho diferente.  
  
 `ENOENT`  
 Arquivo ou caminho especificado pelo *oldname* não seja localizado\).  
  
 `EINVAL`  
 O nome contiver caracteres inválidos.  
  
 Para outros valores de retorno possíveis, consulte [\_doserrno, \_errno, syserrlist, e \_sys\_nerr](../Topic/errno,%20_doserrno,%20_sys_errlist,%20and%20_sys_nerr.md).  
  
## Comentários  
 A função de **rename** renomeia o arquivo ou diretório especificado *por oldname* ao nome fornecido *por newname*.  O nome antigo deve ser o caminho de um arquivo existente ou diretório.  O novo nome não deve ser o nome de um arquivo existente ou diretório.  Você pode usar **rename** para mover um arquivo de um diretório ou o dispositivo para outro capacete um caminho diferente no argumento de *newname* .  Porém, você não pode usar **rename** para mover um diretório.  Os diretórios podem ser renomeados, mas não ser movido.  
  
 `_wrename` é uma versão de ampla caractere de **\_rename**; os argumentos a `_wrename` são cadeias de caracteres de ampla caractere.  `_wrename` e **\_rename** se comportam idêntica de outra forma.  
  
### Mapeamentos da rotina de texto genérico  
  
|Rotina TCHAR.H|\_UNICODE & \_MBCS não definido|\_MBCS definido|\_UNICODE definido|  
|--------------------|-------------------------------------|---------------------|------------------------|  
|`_trename`|**renomear**|**renomear**|`_wrename`|  
  
## Requisitos  
  
|Rotina|Cabeçalho necessário|  
|------------|--------------------------|  
|**renomear**|\<io.h ou\> stdio.h \<\>|  
|`_wrename`|\<stdio.h\> ou \<wchar.h\>|  
  
 Para informações adicionais de compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md) na Introdução.  
  
## Bibliotecas  
 Todas as versões das [Bibliotecas em tempo de execução C](../../c-runtime-library/crt-library-features.md).  
  
## Exemplo  
  
```  
// crt_renamer.c  
/* This program attempts to rename a file named  
 * CRT_RENAMER.OBJ to CRT_RENAMER.JBO. For this operation  
 * to succeed, a file named CRT_RENAMER.OBJ must exist and  
 * a file named CRT_RENAMER.JBO must not exist.  
 */  
  
#include <stdio.h>  
  
int main( void )  
{  
   int  result;  
   char old[] = "CRT_RENAMER.OBJ", new[] = "CRT_RENAMER.JBO";  
  
   /* Attempt to rename file: */  
   result = rename( old, new );  
   if( result != 0 )  
      printf( "Could not rename '%s'\n", old );  
   else  
      printf( "File '%s' renamed to '%s'\n", old, new );  
}  
```  
  
## Saída  
  
```  
File 'CRT_RENAMER.OBJ' renamed to 'CRT_RENAMER.JBO'  
```  
  
## Equivalência do .NET Framework  
 [System::IO::File::Move](https://msdn.microsoft.com/en-us/library/system.io.file.move.aspx)  
  
## Consulte também  
 [Manipulação de arquivos](../../c-runtime-library/file-handling.md)