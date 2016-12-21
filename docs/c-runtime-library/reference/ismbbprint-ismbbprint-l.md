---
title: "_ismbbprint, _ismbbprint_l | Microsoft Docs"
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
  - "_ismbbprint_l"
  - "_ismbbprint"
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
  - "api-ms-win-crt-multibyte-l1-1-0.dll"
apitype: "DLLExport"
f1_keywords: 
  - "_ismbbprint_l"
  - "_ismbbprint"
  - "ismbbprint"
  - "ismbbprint_l"
dev_langs: 
  - "C++"
  - "C"
helpviewer_keywords: 
  - "Função ismbbprint_l"
  - "Função ismbbprint"
  - "Função _ismbbprint"
  - "Função _ismbbprint_l"
ms.assetid: d08a061c-18a8-48f2-a75d-bff4870aec9d
caps.latest.revision: 19
caps.handback.revision: 19
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# _ismbbprint, _ismbbprint_l
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Determina se um caractere multibyte especificado é um caractere de impressão.  
  
## Sintaxe  
  
```  
int _ismbbprint(  
   unsigned int c   
);  
int _ismbbprint_l(  
   unsigned int c,  
   _locale_t locale  
);  
```  
  
#### Parâmetros  
 `c`  
 Inteiro a ser testada.  
  
 `locale`  
 Localidade a ser usada.  
  
## Valor de retorno  
 `_ismbbprint` Retorna um valor diferente de zero se a expressão:  
  
```  
isprint || _ismbbkprint  
```  
  
 é diferente de zero para `c`, ou 0 se não for.`_ismbbprint` usa a localidade atual para qualquer comportamento depende da localidade.`_ismbbprint_l` é idêntico, exceto que ele usa a localidade passada em seu lugar. Para obter mais informações, consulte [Localidade](../../c-runtime-library/locale.md).  
  
## Requisitos  
  
|Rotina|Cabeçalho necessário|  
|------------|--------------------------|  
|`_ismbbprint`|\< mbctype.h \>|  
|`_ismbbprint_l`|\< mbctype.h \>|  
  
 Para obter informações de compatibilidade, consulte [compatibilidade](../../c-runtime-library/compatibility.md).  
  
## Equivalência do .NET Framework  
 Não aplicável. Para chamar a função C padrão, use `PInvoke`. Para obter mais informações, consulte [exemplos de invocação de plataforma](../Topic/Platform%20Invoke%20Examples.md).  
  
## Consulte também  
 [Classificação de byte](../../c-runtime-library/byte-classification.md)   
 [Rotinas \_ismbb](../../c-runtime-library/ismbb-routines.md)