---
title: "_fread_nolock | Microsoft Docs"
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
  - "_fread_nolock"
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
  - "_fread_nolock"
  - "fread_nolock"
dev_langs: 
  - "C++"
  - "C"
helpviewer_keywords: 
  - "Função _fread_nolock"
  - "dados [C++], lendo de fluxo de entrada"
  - "Função fread_nolock"
  - "lendo dados [C++], de fluxos de entrada"
  - "fluxos [C++], lendo dados de"
ms.assetid: 60e4958b-1097-46f5-a77b-94af5e7dba40
caps.latest.revision: 11
caps.handback.revision: 11
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# _fread_nolock
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Ler dados de um fluxo, sem bloquear outros threads.  
  
## Sintaxe  
  
```  
size_t _fread_nolock(   
   void *buffer,  
   size_t size,  
   size_t count,  
   FILE *stream   
);  
```  
  
#### Parâmetros  
 `buffer`  
 Local para armazenamento de dados.  
  
 `size`  
 Tamanho do item em bytes.  
  
 `count`  
 Número máximo de itens a serem lidos.  
  
 `stream`  
 Ponteiro para a estrutura `FILE`.  
  
## Valor de retorno  
 Consulte [fread](../../c-runtime-library/reference/fread.md).  
  
## Comentários  
 Esta função é uma versão sem\-bloqueio de `fread`.  É idêntica a `fread` exceto que não é protegida de interferências dos outros threads.  Pode ser mais rápida porque não imponha a sobrecarga do bloqueio out outros threads.  Use essa função só em contextos seguro para threads como aplicativos de thread único ou onde os identificadores do escopo da chamada já thread o isolamento.  
  
## Requisitos  
  
|Função|Cabeçalho necessário|  
|------------|--------------------------|  
|`_fread_nolock`|\<stdio.h\>|  
  
 Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md) na Introdução.  
  
## Equivalência do .NET Framework  
 [System::IO::FileStream::Read](https://msdn.microsoft.com/en-us/library/system.io.filestream.read.aspx)  
  
## Consulte também  
 [E\/S de fluxo](../../c-runtime-library/stream-i-o.md)   
 [fwrite](../Topic/fwrite.md)   
 [\_read](../Topic/_read.md)