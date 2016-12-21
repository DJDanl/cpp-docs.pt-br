---
title: "__set_app_type | Microsoft Docs"
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
  - "__set_app_type"
  - "_set_app_type"
apilocation: 
  - "msvcr90.dll"
  - "msvcr100.dll"
  - "msvcr110.dll"
  - "msvcr80.dll"
  - "msvcrt.dll"
  - "msvcr120.dll"
  - "msvcr110_clr0400.dll"
  - "api-ms-win-crt-runtime-l1-1-0.dll"
apitype: "DLLExport"
f1_keywords: 
  - "__set_app_type"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "__set_app_type"
ms.assetid: f0ac0f4d-70e6-4e96-9e43-eb9d1515490c
caps.latest.revision: 2
caps.handback.revision: 2
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# __set_app_type
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Define o tipo de aplicativo atual.  
  
## Sintaxe  
  
```cpp  
void __set_app_type (  
   int at  
   )  
```  
  
#### Parâmetros  
 `at`  
 Um valor que indica o tipo de aplicativo.  Os valores possíveis são:  
  
|Valor|Descrição|  
|-----------|---------------|  
|\_UNKNOWN\_APP|Tipo de aplicativo desconhecido.|  
|\_CONSOLE\_APP|Aplicativo de console \(linha de comando\).|  
|\_GUI\_APP|Aplicativo de GUI \(windows\).|  
  
## Comentários  
  
## Requisitos  
  
|Rotina|Cabeçalho necessário|  
|------------|--------------------------|  
|\_\_set\_app\_type|internal.h|