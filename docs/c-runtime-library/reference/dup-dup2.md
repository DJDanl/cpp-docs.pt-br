---
title: "_dup, _dup2 | Microsoft Docs"
ms.custom: ""
ms.date: "12/16/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
apiname: 
  - "_dup"
  - "_dup2"
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
  - "api-ms-win-crt-stdio-l1-1-0.dll"
apitype: "DLLExport"
f1_keywords: 
  - "_dup2"
  - "_dup"
dev_langs: 
  - "C++"
  - "C"
helpviewer_keywords: 
  - "Função _dup"
  - "Função _dup2"
  - "Função dup"
  - "Função dup2"
  - "identificadores de arquivo [C++], duplicando"
  - "identificadores de arquivo [C++], reatribuindo"
ms.assetid: 4d07e92c-0d76-4832-a770-dfec0e7a0cfa
caps.latest.revision: 19
caps.handback.revision: 17
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# _dup, _dup2
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Cria um segundo arquivo descritor para um arquivo aberto \(`_dup`\), ou reatribui um arquivo descritor \(`_dup2`\).  
  
## Sintaxe  
  
```  
int _dup(   
   int fd   
);  
int _dup2(   
   int fd1,  
   int fd2   
);  
```  
  
#### Parâmetros  
 `fd`, `fd1`  
 Descritores de arquivo que se referem ao arquivo aberto.  
  
 `fd2`  
 Qualquer descritor de arquivo.  
  
## Valor de retorno  
 `_dup` retorna um novo descritor de arquivo.  `_dup2` retorna 0 para indicar o sucesso.  Se um erro ocorrer, cada função retornará \-1 e definirá `errno` como `EBADF` se o arquivo descritor for inválido ou como `EMFILE` se mais nenhum arquivo descritor estiver disponível.  No caso de um arquivo descritor inválido, a função também chama o manipulador de parâmetro inválido, conforme descrito em [Validação do parâmetro](../../c-runtime-library/parameter-validation.md).  
  
 Para obter mais informações sobre esses e outros códigos de retorno, consulte [\_doserrno, errno, \_sys\_errlist, and \_sys\_nerr](../Topic/errno,%20_doserrno,%20_sys_errlist,%20and%20_sys_nerr.md).  
  
## Comentários  
 As funções `_dup` e `_dup2` associam um segundo descritor de arquivo a um arquivo atualmente aberto.  Essas funções podem ser usadas para associar um descritor de arquivo predefinido, como aquele para `stdout`, a um arquivo diferente.  As operações no arquivo podem ser executadas usando qualquer descritor de arquivo.  O tipo de acesso permitido para o arquivo não é afetado pela criação de um novo descritor.  `_dup` retorna o próximo descritor de arquivo disponível para o arquivo especificado.  `_dup2` força `fd2` para fazer referência ao mesmo arquivo do `fd1`.  Se `fd2` estiver associado a um arquivo aberto no momento da chamada, esse arquivo é fechado.  
  
 `_dup` e `_dup2` aceitam descritores de arquivo como parâmetros.  Para passar um fluxo `(FILE *)` a qualquer uma dessas funções, use [\_fileno](../Topic/_fileno.md).  A rotina `fileno` retorna o descritor de arquivo atualmente associado ao fluxo especificado.  O exemplo a seguir mostra como associar `stderr` \(definido como `FILE` `*` em Stdio.h\) a um descritor de arquivo:  
  
```  
int cstderr = _dup( _fileno( stderr ));  
```  
  
## Requisitos  
  
|Rotina|Cabeçalho necessário|  
|------------|--------------------------|  
|`_dup`|\<io.h\>|  
|`_dup2`|\<io.h\>|  
  
 O console não tem suporte em aplicativos do [!INCLUDE[win8_appname_long](../../build/includes/win8_appname_long_md.md)].  Os manipuladores de fluxo padrão associados ao console — `stdin`, `stdout` e `stderr` — devem ser redirecionados antes que as funções de tempo de execução do C possam utilizá\-los em aplicativos do [!INCLUDE[win8_appname_long](../../build/includes/win8_appname_long_md.md)].  Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).  
  
## Exemplo  
  
```  
// crt_dup.c  
// This program uses the variable old to save  
// the original stdout. It then opens a new file named  
// DataFile and forces stdout to refer to it. Finally, it  
// restores stdout to its original state.  
//  
  
#include <io.h>  
#include <stdlib.h>  
#include <stdio.h>  
  
int main( void )  
{  
   int old;  
   FILE *DataFile;  
  
   old = _dup( 1 );   // "old" now refers to "stdout"   
                      // Note:  file descriptor 1 == "stdout"   
   if( old == -1 )  
   {  
      perror( "_dup( 1 ) failure" );  
      exit( 1 );  
   }  
   _write( old, "This goes to stdout first\n", 26 );  
   if( fopen_s( &DataFile, "data", "w" ) != 0 )  
   {  
      puts( "Can't open file 'data'\n" );  
      exit( 1 );  
   }  
  
   // stdout now refers to file "data"   
   if( -1 == _dup2( _fileno( DataFile ), 1 ) )  
   {  
      perror( "Can't _dup2 stdout" );  
      exit( 1 );  
   }  
   puts( "This goes to file 'data'\n" );  
  
   // Flush stdout stream buffer so it goes to correct file   
   fflush( stdout );  
   fclose( DataFile );  
  
   // Restore original stdout   
   _dup2( old, 1 );  
   puts( "This goes to stdout\n" );  
   puts( "The file 'data' contains:" );  
   _flushall();  
   system( "type data" );  
}  
```  
  
  **Isso vai para stdout primeiro**  
**Isso vai para stdout**  
**O arquivo de 'dados' contém:**  
**Isso vai para 'dados' do arquivo**   
## Consulte também  
 [E\/S de nível inferior](../../c-runtime-library/low-level-i-o.md)   
 [\_close](../Topic/_close.md)   
 [\_creat, \_wcreat](../../c-runtime-library/reference/creat-wcreat.md)   
 [\_open, \_wopen](../../c-runtime-library/reference/open-wopen.md)