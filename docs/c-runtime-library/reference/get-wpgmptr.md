---
title: "_get_wpgmptr | Microsoft Docs"
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
  - "_get_wpgmptr"
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
  - "api-ms-win-crt-runtime-l1-1-0.dll"
apitype: "DLLExport"
f1_keywords: 
  - "get_wpgmptr"
  - "_get_wpgmptr"
dev_langs: 
  - "C++"
  - "C"
helpviewer_keywords: 
  - "Função _get_wpgmptr"
  - "Variável global _wpgmptr"
  - "Função get_wpgmptr"
  - "variável global wpgmptr"
ms.assetid: a77cdd13-2303-4b7c-9a60-8debdbef2011
caps.latest.revision: 17
caps.handback.revision: 17
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# _get_wpgmptr
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Obtém o valor atual da variável global `_wpgmptr`.  
  
## Sintaxe  
  
```  
errno_t _get_wpgmptr(     wchar_t **pValue  );  
```  
  
#### Parâmetros  
 \[out\] `pValue`  
 Um ponteiro para uma cadeia de caracteres para ser preenchido com o valor atual da variável `_wpgmptr`.  
  
## Valor de retorno  
 Retorna zero se tiver êxito; um código de erro em caso de falha.  Se `pValue` for `NULL`, o manipulador de parâmetro inválido é chamado, como descrito em [Validação do parâmetro](../../c-runtime-library/parameter-validation.md).  Se a execução puder continuar, essa função definirá `errno` para `EINVAL` e retornará `EINVAL`.  
  
## Comentários  
 A variável global `_wpgmptr` contém o caminho completo para o executável associado ao processo como uma cadeia de caracteres largos.  Para obter mais informações, consulte [\_pgmptr, \_wpgmptr](../../c-runtime-library/pgmptr-wpgmptr.md).  
  
## Requisitos  
  
|Rotina|Cabeçalho necessário|  
|------------|--------------------------|  
|`_get_wpgmptr`|\<stdlib.h\>|  
  
 Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md) na Introdução.  
  
## Equivalência do .NET Framework  
 Não aplicável. Para chamar a função C padrão, use `PInvoke`. Para obter mais informações, consulte [Exemplos de invocação de plataforma](../Topic/Platform%20Invoke%20Examples.md).  
  
## Consulte também  
 [\_get\_pgmptr](../../c-runtime-library/reference/get-pgmptr.md)