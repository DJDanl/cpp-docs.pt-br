---
title: "_flushall | Microsoft Docs"
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
  - "_flushall"
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
  - "_flushall"
dev_langs: 
  - "C++"
  - "C"
helpviewer_keywords: 
  - "Função flushall"
  - "liberando fluxos"
  - "fluxos de liberação"
  - "Função _flushall"
ms.assetid: 2cd73562-6d00-4ca2-b13c-80d0ae7870b5
caps.latest.revision: 16
caps.handback.revision: 14
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# _flushall
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Libera todos os fluxos; limpa todos os buffers.  
  
## Sintaxe  
  
```  
int _flushall( void );  
```  
  
## Valor de retorno  
 `_flushall` retorna o número de fluxos abertos \(entrada e saída\).  Não há nenhum retorno de erro.  
  
## Comentários  
 Por padrão, a função de `_flushall` grava os arquivos apropriados o conteúdo de todos os buffers associados com os fluxos de saída abertos.  Todos os buffers associados com os fluxos de entrada abertos serão desmarcados de seus conteúdos atuais. \(Esses buffers são mantidos normalmente pelo sistema operacional, que determina o tempo ótimos de gravar automaticamente os dados em disco: quando um buffer for concluída, quando um fluxo está fechado, ou quando um programa será encerrado normalmente sem fechar os fluxos.\)  
  
 Se uma leitura segue uma chamada a `_flushall`, os novos dados são lidos os arquivos de entrada nos buffers.  Todos os fluxos permanecem abertos depois da chamada a `_flushall`.  
  
 O recurso de disco confirmação\-à\- da biblioteca de tempo de execução permite garantir que os dados críticos seja gravado diretamente no disco em vez de buffers do sistema operacional.  Sem reescrever um programa existente, você pode habilitar esse recurso vincular os arquivos de programa do objeto com Commode.obj.  No arquivo executável resultante, as chamadas para `_flushall` grava o conteúdo de todos os buffers em disco.  Somente `_flushall` e `fflush` são afetados por Commode.obj.  
  
 Para obter informações sobre como controlar o recurso de confirmação\-à\- disco, consulte [Fluxo de E\/S](../../c-runtime-library/stream-i-o.md), [fopen](../../c-runtime-library/reference/fopen-wfopen.md), e [\_fdopen](../Topic/_fdopen,%20_wfdopen.md).  
  
## Requisitos  
  
|Função|Cabeçalho necessário|  
|------------|--------------------------|  
|`_flushall`|\<stdio.h\>|  
  
 Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md) na Introdução.  
  
## Exemplo  
  
```  
// crt_flushall.c  
// This program uses _flushall  
// to flush all open buffers.  
  
#include <stdio.h>  
  
int main( void )  
{  
   int numflushed;  
  
   numflushed = _flushall();  
   printf( "There were %d streams flushed\n", numflushed );  
}  
```  
  
  **Houvesse 3 fluxos liberados**   
## Equivalência do .NET Framework  
  
-   [System::IO::FileStream::Flush](https://msdn.microsoft.com/en-us/library/2bw4h516.aspx)  
  
-   [System::IO::StreamWriter::Flush](https://msdn.microsoft.com/en-us/library/system.io.streamwriter.flush.aspx)  
  
-   [System::IO::TextWriter::Flush](https://msdn.microsoft.com/en-us/library/system.io.textwriter.flush.aspx)  
  
-   [System::IO::BinaryWriter::Flush](https://msdn.microsoft.com/en-us/library/system.io.binarywriter.flush.aspx)  
  
## Consulte também  
 [E\/S de fluxo](../../c-runtime-library/stream-i-o.md)   
 [\_commit](../../c-runtime-library/reference/commit.md)   
 [fclose, \_fcloseall](../../c-runtime-library/reference/fclose-fcloseall.md)   
 [fflush](../Topic/fflush.md)   
 [setvbuf](../../c-runtime-library/reference/setvbuf.md)