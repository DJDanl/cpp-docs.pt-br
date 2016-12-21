---
title: "__max | Microsoft Docs"
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
  - "__max"
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
  - "max"
  - "__max"
dev_langs: 
  - "C++"
  - "C"
helpviewer_keywords: 
  - "Macro __max"
  - "macro máx"
  - "macro máxima"
ms.assetid: 05c936f6-0e22-45d6-a58d-4bc102e9dae2
caps.latest.revision: 12
caps.handback.revision: 12
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# __max
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Retorna o maior de dois valores.  
  
## Sintaxe  
  
```  
type __max(  
   type a,  
   type b   
);  
```  
  
#### Parâmetros  
 `type`  
 Qualquer tipo de dados numérico.  
  
 `a, b`  
 Valores de qualquer tipo numérico a ser comparado.  
  
## Valor de retorno  
 `__max` retorna o maior de seus argumentos.  
  
## Comentários  
 A macro de `__max` compara dois valores e retorna o valor de maior.  Os argumentos podem ser de qualquer tipo de dados numérico, assinado ou não assinado.  Os argumentos e o valor de retorno devem ser do mesmo tipo de dados.  
  
## Requisitos  
  
|Rotina|Cabeçalho necessário|  
|------------|--------------------------|  
|`__max`|\<stdlib.h\>|  
  
## Exemplo  
 Para obter mais informações, consulte o exemplo de [\_\_min](../../c-runtime-library/reference/min.md).  
  
## Equivalência do .NET Framework  
 [System::Math::Max](https://msdn.microsoft.com/en-us/library/system.math.max.aspx)  
  
## Consulte também  
 [Suporte de ponto flutuante](../../c-runtime-library/floating-point-support.md)   
 [\_\_min](../../c-runtime-library/reference/min.md)