---
title: "_ismbbtrail, _ismbbtrail_l | Microsoft Docs"
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
  - "_ismbbtrail"
  - "_ismbbtrail_l"
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
  - "_ismbbtrail"
  - "ismbbtrail"
  - "_ismbbtrail_l"
  - "ismbbtrail_l"
dev_langs: 
  - "C++"
  - "C"
helpviewer_keywords: 
  - "Função ismbbtrail_l"
  - "Função _ismbbtrail"
  - "Função _ismbbtrail_l"
  - "Função ismbbtrail"
ms.assetid: dfdd0292-960b-4c1d-bf11-146e0fc80247
caps.latest.revision: 22
caps.handback.revision: 22
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# _ismbbtrail, _ismbbtrail_l
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Determina se um byte é um byte à direita de um caractere multibyte.  
  
## Sintaxe  
  
```  
int _ismbbtrail(  
   unsigned int c   
);  
int _ismbbtrail_l(  
   unsigned int c,  
   _locale_t locale   
);  
```  
  
#### Parâmetros  
 `c`  
 O inteiro a ser testada.  
  
 `locale`  
 A localidade a ser usada.  
  
## Valor de retorno  
 `_ismbbtrail` Retorna um valor diferente de zero se o inteiro `c` é o segundo byte de um caractere multibyte. Por exemplo, no código e os intervalos de páginas 932 válido, somente são 0x40 para 0x7E e 0x80 para 0xFC.  
  
## Comentários  
 `_ismbbtrail` usa a localidade atual para o comportamento depende da localidade.`_ismbbtrail_l` é idêntico, exceto que ele usa a localidade que é passada em vez disso. Para obter mais informações, consulte [Localidade](../../c-runtime-library/locale.md).  
  
## Requisitos  
  
|Rotina|Cabeçalho necessário|Cabeçalho opcional|  
|------------|--------------------------|------------------------|  
|`_ismbbtrail`|\< mbctype.h \> ou \< mbstring.h \>|\< CType \> \* \< Limits. h \>, \< stdlib. h \>|  
|`_ismbbtrail_l`|\< mbctype.h \> ou \< mbstring.h \>|\< CType \> \* \< Limits. h \>, \< stdlib. h \>|  
  
 \* Para constantes de manifesto para as condições de teste.  
  
 Para obter informações de compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).  
  
## Equivalência do .NET Framework  
 Não aplicável. Para chamar a função C padrão, use `PInvoke`. Para obter mais informações, consulte [Exemplos de invocação de plataforma](../Topic/Platform%20Invoke%20Examples.md).  
  
## Consulte também  
 [Classificação de byte](../../c-runtime-library/byte-classification.md)   
 [Rotinas \_ismbb](../../c-runtime-library/ismbb-routines.md)