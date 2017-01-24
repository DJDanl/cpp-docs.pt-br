---
title: "_ftell_nolock, _ftelli64_nolock | Microsoft Docs"
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
  - "_ftelli64_nolock"
  - "_ftell_nolock"
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
  - "_ftelli64_nolock"
  - "ftelli64_nolock"
  - "ftell_nolock"
  - "_ftell_nolock"
dev_langs: 
  - "C++"
  - "C"
helpviewer_keywords: 
  - "Função _ftell_nolock"
  - "Função _ftelli64_nolock"
  - "ponteiros de arquivo [C++], obtendo posição atual"
  - "Função ftell_nolock"
  - "Função ftelli64_nolock"
ms.assetid: 84e68b0a-32f8-4c4a-90ad-3f2387685ede
caps.latest.revision: 13
caps.handback.revision: 13
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# _ftell_nolock, _ftelli64_nolock
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Obtém a posição atual de um ponteiro de arquivo, sem bloquear o thread.  
  
## Sintaxe  
  
```  
long _ftell_nolock(   
   FILE *stream   
);  
__int64 _ftelli64_nolock(   
   FILE *stream   
);  
```  
  
#### Parâmetros  
 `stream`  
 Direcionar a estrutura de `FILE` .  
  
## Valor de retorno  
 Mesmo que `ftell` e `_ftelli64`.  Para obter mais informações, consulte [ftell, \_ftelli64](../../c-runtime-library/reference/ftell-ftelli64.md)**.**  
  
## Comentários  
 Essas funções são versões sem\-bloqueio de `ftell` e de `_ftelli64`, respectivamente.  São idênticos a `ftell` e a `_ftelli64`exceto que não são protegidos de interferências dos outros threads.  Essas funções podem ser mais rápidas porque não incorrer na sobrecarga do bloqueio out outros threads.  Use essas funções somente em contextos de thread\-safe, como aplicativos single\-threaded ou onde o escopo de chamada já manipula o isolamento do thread.  
  
## Requisitos  
  
|Função|Cabeçalho necessário|Cabeçalho opcional|  
|------------|--------------------------|------------------------|  
|`ftell_nolock`|\<stdio.h\>|\<errno.h\>|  
|`_ftelli64_nolock`|\<stdio.h\>|\<errno.h\>|  
  
 Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md) na Introdução.  
  
## Equivalência do .NET Framework  
 [System::IO::FileStream::Position](https://msdn.microsoft.com/en-us/library/system.io.filestream.position.aspx)  
  
## Consulte também  
 [E\/S de fluxo](../../c-runtime-library/stream-i-o.md)   
 [fgetpos](../../c-runtime-library/reference/fgetpos.md)   
 [fseek, \_fseeki64](../../c-runtime-library/reference/fseek-fseeki64.md)   
 [\_lseek, \_lseeki64](../../c-runtime-library/reference/lseek-lseeki64.md)   
 [ftell, \_ftelli64](../../c-runtime-library/reference/ftell-ftelli64.md)