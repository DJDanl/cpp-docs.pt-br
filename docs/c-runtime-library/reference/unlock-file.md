---
title: "_unlock_file | Microsoft Docs"
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
  - "_unlock_file"
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
  - "_unlock_file"
  - "unlock_file"
dev_langs: 
  - "C++"
  - "C"
helpviewer_keywords: 
  - "Função _unlock_file"
  - "Arquivos  [C++], desbloqueando"
  - "Função unlock_file"
  - "desbloqueando arquivos"
ms.assetid: cf380a51-6d3a-4f38-bd64-2d4fb57b4369
caps.latest.revision: 10
caps.handback.revision: 10
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# _unlock_file
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Desbloqueia um arquivo, permitindo que outros processos para acessar o arquivo.  
  
## Sintaxe  
  
```  
void _unlock_file(  
   FILE* file  
);  
```  
  
#### Parâmetros  
 `file`  
 Identificador de arquivo.  
  
## Comentários  
 A função de `_unlock_file` desbloqueia o arquivo especificado por `file`.  Desbloquear um arquivo permite acesso ao arquivo por outros processos.  Essa função não deve ser chamada a menos que `_lock_file` é chamado anteriormente o ponteiro de `file` .  A chamada `_unlock_file` em um arquivo que não seja bloqueada pode resultar em um deadlock.  Para ver um exemplo, consulte [\_lock\_file](../Topic/_lock_file.md).  
  
## Requisitos  
  
|Rotina|Cabeçalho necessário|  
|------------|--------------------------|  
|`_unlock_file`|\<stdio.h\>|  
  
 Para informações adicionais de compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md) na Introdução.  
  
## Equivalência do .NET Framework  
 [System::IO::FileStream::Lock](https://msdn.microsoft.com/en-us/library/system.io.filestream.lock.aspx)  
  
## Consulte também  
 [Manipulação de arquivos](../../c-runtime-library/file-handling.md)   
 [\_creat, \_wcreat](../../c-runtime-library/reference/creat-wcreat.md)   
 [\_open, \_wopen](../../c-runtime-library/reference/open-wopen.md)   
 [\_lock\_file](../Topic/_lock_file.md)