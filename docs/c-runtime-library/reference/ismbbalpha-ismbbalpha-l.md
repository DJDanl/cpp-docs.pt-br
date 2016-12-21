---
title: "_ismbbalpha, _ismbbalpha_l | Microsoft Docs"
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
  - "_ismbbalpha"
  - "_ismbbalpha_l"
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
  - "ismbbalpha"
  - "ismbbalpha_l"
  - "_ismbbalpha"
  - "_ismbbalpha_l"
dev_langs: 
  - "C++"
  - "C"
helpviewer_keywords: 
  - "Função ismbbalpha"
  - "Função ismbbalpha_l"
  - "Função _ismbbalpha"
  - "Função _ismbbalpha_l"
ms.assetid: 8e54cb92-fc2b-41f5-8ab4-b22ac8aa9ad0
caps.latest.revision: 18
caps.handback.revision: 18
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# _ismbbalpha, _ismbbalpha_l
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Determina se um caractere multibyte especificado é alfa.  
  
## Sintaxe  
  
```  
int _ismbbalpha(  
   unsigned int c   
);  
int _ismbbalpha_l(  
   unsigned int c   
);  
```  
  
#### Parâmetros  
 `c`  
 Inteiro a ser testada.  
  
 `locale`  
 Localidade a ser usada.  
  
## Valor de retorno  
 `_ismbbalpha` Retorna um valor diferente de zero se a expressão:  
  
```  
isalpha || _ismbbkalnum  
```  
  
 é diferente de zero para `c`, ou 0 se não for.`_ismbbalpha` usa a localidade atual para as configurações de caracteres depende da localidade.`_ismbbalpha_l` é idêntico, exceto que ele usa a localidade passada.  
  
## Requisitos  
  
|Rotina|Cabeçalho necessário|  
|------------|--------------------------|  
|`_ismbbalpha`|\< mbctype.h \>|  
|`_ismbbalpha_l`|\< mbctype.h \>|  
  
 Para obter informações de compatibilidade, consulte [compatibilidade](../../c-runtime-library/compatibility.md).  
  
## Libraries  
 Todas as versões do [bibliotecas de tempo de execução C](../../c-runtime-library/crt-library-features.md).  
  
## Equivalência do .NET Framework  
 Não aplicável. Para chamar a função C padrão, use `PInvoke`. Para obter mais informações, consulte [exemplos de invocação de plataforma](../Topic/Platform%20Invoke%20Examples.md).  
  
## Consulte também  
 [Classificação de byte](../../c-runtime-library/byte-classification.md)   
 [Rotinas \_ismbb](../../c-runtime-library/ismbb-routines.md)