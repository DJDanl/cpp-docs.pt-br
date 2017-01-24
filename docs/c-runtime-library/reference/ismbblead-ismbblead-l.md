---
title: "_ismbblead, _ismbblead_l | Microsoft Docs"
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
  - "_ismbblead_l"
  - "_ismbblead"
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
  - "ismbblead_l"
  - "istlead"
  - "_ismbblead"
  - "_ismbblead_l"
  - "ismbblead"
  - "_istlead"
dev_langs: 
  - "C++"
  - "C"
helpviewer_keywords: 
  - "Função _ismbblead_l"
  - "Função ismbblead"
  - "Função _ismbblead"
  - "Função istlead"
  - "Função ismbblead_l"
  - "Função _istlead"
ms.assetid: 2abc6f75-ed5c-472e-bfd0-e905a1835ccf
caps.latest.revision: 21
caps.handback.revision: 21
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# _ismbblead, _ismbblead_l
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Testa um caractere para determinar se ele é um byte de um caractere multibyte.  
  
## Sintaxe  
  
```  
int _ismbblead(  
   unsigned int c   
);  
int _ismbblead_l(  
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
 Retorna um valor diferente de zero se o inteiro `c` é o primeiro byte de um caractere multibyte.  
  
## Comentários  
 Caracteres multibyte consistem em um byte inicial seguido de um byte à direita. Bytes de clientes potenciais são diferenciados por estarem em um intervalo específico para um determinado conjunto de caracteres. Por exemplo, em bytes de avanço, somente de código 932 página variam de 0x81 – 0x9F e 0xE0 – 0xFC.  
  
 `_ismbblead` usa a localidade atual para o comportamento depende da localidade.`_ismbblead_l` é idêntico, exceto que ele usa a localidade passada em seu lugar. Para obter mais informações, consulte [Localidade](../../c-runtime-library/locale.md).  
  
### Mapeamentos de rotina de texto genérico  
  
|Rotina TCHAR. h|Unicode e MBCS não definidos|MBCS definido|Unicode definido|  
|---------------------|----------------------------------|-------------------|----------------------|  
|`_istlead`|Sempre retorna false|`_ismbblead`|Sempre retorna false|  
  
## Requisitos  
  
|Rotina|Cabeçalho necessário|Cabeçalho opcional|  
|------------|--------------------------|------------------------|  
|`_ismbblead`|\< mbctype.h \> ou \< mbstring.h \>|\< CType \> \* \< Limits. h \>, \< stdlib. h \>|  
|`_ismbblead_l`|\< mbctype.h \> ou \< mbstring.h \>|\< CType \> \* \< Limits. h \>, \< stdlib. h \>|  
  
 \* Para constantes de manifesto para as condições de teste.  
  
 Para obter informações de compatibilidade, consulte [compatibilidade](../../c-runtime-library/compatibility.md).  
  
## Equivalência do .NET Framework  
 Não aplicável. Para chamar a função C padrão, use `PInvoke`. Para obter mais informações, consulte [exemplos de invocação de plataforma](../Topic/Platform%20Invoke%20Examples.md).  
  
## Consulte também  
 [Classificação de byte](../../c-runtime-library/byte-classification.md)   
 [Rotinas \_ismbb](../../c-runtime-library/ismbb-routines.md)