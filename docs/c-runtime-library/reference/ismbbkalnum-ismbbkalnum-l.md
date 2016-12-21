---
title: "_ismbbkalnum, _ismbbkalnum_l | Microsoft Docs"
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
  - "_ismbbkalnum"
  - "_ismbbkalnum_l"
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
  - "_ismbbkalnum"
  - "ismbbkalnum"
  - "ismbbkalnum_l"
  - "_ismbbkalnum_l"
dev_langs: 
  - "C++"
  - "C"
helpviewer_keywords: 
  - "Função _ismbbkalnum_l"
  - "Função ismbbkalnum_l"
  - "Função _ismbbkalnum"
  - "Função ismbbkalnum"
ms.assetid: e1d70e7b-29d0-469c-9d93-442b99de22ac
caps.latest.revision: 19
caps.handback.revision: 19
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# _ismbbkalnum, _ismbbkalnum_l
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Determina se um determinado caractere multibyte é um símbolo de texto não\-ASCII.  
  
## Sintaxe  
  
```  
int _ismbbkalnum(  
   unsigned int c   
);  
int _ismbbkalnum_l(  
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
 `_ismbbkalnum` Retorna um valor diferente de zero se o inteiro `c` é um símbolo de texto não\-ASCII diferente de pontuação, ou 0 se não for.`_ismbbkalnum` usa a localidade atual para obter informações de caracteres depende da localidade.`_ismbbkalnum_l` é idêntico ao `_ismbbkalnum` exceto que assume a localidade como um parâmetro. Para obter mais informações, consulte [Localidade](../../c-runtime-library/locale.md).  
  
## Requisitos  
  
|Rotina|Cabeçalho necessário|  
|------------|--------------------------|  
|`_ismbbkalnum`|\< mbctype.h \>|  
|`_ismbbkalnum_l`|\< mbctype.h \>|  
  
 Para obter informações de compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).  
  
## Equivalência do .NET Framework  
 Não aplicável. Para chamar a função C padrão, use `PInvoke`. Para obter mais informações, consulte [Exemplos de invocação de plataforma](../Topic/Platform%20Invoke%20Examples.md).  
  
## Consulte também  
 [Classificação de byte](../../c-runtime-library/byte-classification.md)   
 [Rotinas \_ismbb](../../c-runtime-library/ismbb-routines.md)