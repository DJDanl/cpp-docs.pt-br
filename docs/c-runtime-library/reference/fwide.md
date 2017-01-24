---
title: "fwide | Microsoft Docs"
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
  - "fwide"
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
apitype: "DLLExport"
f1_keywords: 
  - "fwide"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Função fwide"
ms.assetid: a4641f5b-d74f-4946-95d5-53a64610d28d
caps.latest.revision: 6
caps.handback.revision: 6
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# fwide
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Não.  
  
## Sintaxe  
  
```  
int fwide(  
   FILE *stream,  
   int mode;  
);  
```  
  
#### Parâmetros  
 `stream`  
 Ponteiro para a estrutura de `FILE` ignorada \(\).  
  
 `mode`  
 A nova largura do fluxo: positivo para o caractere largo, negativo do byte, zero para sair inalterado. \(Esse valor é ignorado.\)  
  
## Valor de retorno  
 Essa função retorna apenas `mode`atualmente.  
  
## Comentários  
 A versão atual dessa função não obedece ao padrão.  
  
## Requisitos  
  
|Função|Cabeçalho necessário|  
|------------|--------------------------|  
|`fwide`|\<wchar.h\>|  
  
 Para obter mais informações, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).