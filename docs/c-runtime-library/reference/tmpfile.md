---
title: "tmpfile | Microsoft Docs"
ms.custom: ""
ms.date: "12/15/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
apiname: 
  - "tmpfile"
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
  - "tmpfile"
dev_langs: 
  - "C++"
  - "C"
helpviewer_keywords: 
  - "arquivos temporários"
  - "Função tmpfile"
  - "arquivos temporários, criando"
ms.assetid: c4a4dc24-70da-438d-ae4e-98352d88e375
caps.latest.revision: 21
caps.handback.revision: 19
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# tmpfile
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Cria um arquivo temporário.  Esta função é substituída por uma versão mais segura estiver disponível; consulte [tmpfile\_s](../Topic/tmpfile_s.md).  
  
## Sintaxe  
  
```  
FILE *tmpfile( void );  
```  
  
## Valor de retorno  
 Se tiver êxito, `tmpfile` retorna um ponteiro de fluxo.  Caso contrário, retorna um ponteiro de `NULL` .  
  
## Comentários  
 A função de `tmpfile` cria um arquivo temporário e retorna um ponteiro para o fluxo.  O arquivo temporário é criado no diretório raiz.  Para criar um arquivo temporário em um diretório diferente da raiz, use [tmpnam](../../c-runtime-library/reference/tempnam-wtempnam-tmpnam-wtmpnam.md) ou [tempnam](../../c-runtime-library/reference/tempnam-wtempnam-tmpnam-wtmpnam.md) junto com [fopen](../../c-runtime-library/reference/fopen-wfopen.md).  
  
 Se o arquivo não pode ser aberto, `tmpfile` retorna um ponteiro de `NULL` .  Esse arquivo temporário será excluído automaticamente quando o arquivo estiver fechado, quando o programa será encerrado normalmente, ou quando `_rmtmp` for chamado, supondo que o diretório de trabalho atual não se altera.  O arquivo temporário é aberto em modo de leitura\/gravação \( `w+b` binário\).  
  
 A falha pode ocorrer se você tentar mais do que TMP\_MAX \(consulte\) STDIO.H chama com `tmpfile`.  
  
## Requisitos  
  
|Rotina|Cabeçalho necessário|  
|------------|--------------------------|  
|`tmpfile`|\<stdio.h\>|  
  
 Para informações adicionais de compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md) na Introdução.  
  
## Exemplo  
  
> [!NOTE]
>  Este exemplo requer privilégios administrativos executar no Windows Vista.  
  
```  
// crt_tmpfile.c  
// compile with: /W3  
// This program uses tmpfile to create a  
// temporary file, then deletes this file with _rmtmp.  
#include <stdio.h>  
  
int main( void )  
{  
   FILE *stream;  
   int  i;  
  
   // Create temporary files.  
   for( i = 1; i <= 3; i++ )  
   {  
      if( (stream = tmpfile()) == NULL ) // C4996  
      // Note: tmpfile is deprecated; consider using tmpfile_s instead  
         perror( "Could not open new temporary file\n" );  
      else  
         printf( "Temporary file %d was created\n", i );  
   }  
  
   // Remove temporary files.  
   printf( "%d temporary files deleted\n", _rmtmp() );  
}  
```  
  
  **O arquivo temporário 1 foi criado**  
**O arquivo temporário 2 foi criado**  
**O arquivo temporário 3 foi criado**  
**3 arquivos temporários excluídos**   
## Equivalência do .NET Framework  
 Não aplicável. Para chamar a função padrão de C, use `PInvoke`. Para obter mais informações, consulte [Exemplos de chamadas de plataformas](../Topic/Platform%20Invoke%20Examples.md).  
  
## Consulte também  
 [E\/S de fluxo](../../c-runtime-library/stream-i-o.md)   
 [\_rmtmp](../Topic/_rmtmp.md)   
 [\_tempnam, \_wtempnam, tmpnam, \_wtmpnam](../../c-runtime-library/reference/tempnam-wtempnam-tmpnam-wtmpnam.md)