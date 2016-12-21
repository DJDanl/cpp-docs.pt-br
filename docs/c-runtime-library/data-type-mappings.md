---
title: "Mapeamentos de tipo de dados | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
f1_keywords: 
  - "_TXCHAR"
  - "_TUCHAR"
  - "_TINT"
  - "_TSCHAR"
  - "_TCHAR"
  - "TCHAR::H"
  - "TCHAR"
  - "_T"
  - "_TEXT"
dev_langs: 
  - "C++"
  - "C"
helpviewer_keywords: 
  - "Tipo _T"
  - "Tipo _TCHAR"
  - "Tipo _TEXT"
  - "Tipo _TINT"
  - "Tipo _TSCHAR"
  - "Tipo _TUCHAR"
  - "Tipo _TXCHAR"
  - "tipos de dados de texto genérico"
  - "Tipo T"
  - "Tipo TCHAR"
  - "Tipos de dados TCHAR.H, mapeamentos definidos em"
  - "Tipo TEXT"
  - "Tipo TINT"
  - "Tipo TSCHAR"
  - "Tipo TUCHAR"
  - "Tipo TXCHAR"
ms.assetid: 4e573c05-8800-468b-ae5f-76ff7409835e
caps.latest.revision: 7
caps.handback.revision: 7
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Mapeamentos de tipo de dados
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Esses mapeamentos de tipo de dados estão definidos em TCHAR.H e dependem se `_UNICODE` constante ou `_MBCS` foram definidos em seu programa.  
  
 Para obter informações relacionadas, consulte [Usando tipos de dados de TCHAR.H com o código de \_MBCS](../text/using-tchar-h-data-types-with-mbcs-code.md).  
  
### Mapeamentos de tipo de dados de Genérico\- texto  
  
|Genérico\-texto<br /><br /> nome do tipo de dados|SBCS \(\_UNICODE,<br /><br /> não \_MBCS<br /><br /> definido\)|\_MBCS<br /><br /> definido|\_UNICODE<br /><br /> definido|  
|-----------------------------------------------|-----------------------------------------------------|-------------------------|----------------------------|  
|`_TCHAR`|`char`|`char`|`wchar_t`|  
|`_tfinddata_t`|`_finddata_t`|`_finddata_t`|`_wfinddata_t`|  
|`_tfinddata64_t`|`__finddata64_t`|`__finddata64_t`|`__wfinddata64_t`|  
|`_tfinddatai64_t`|`_finddatai64_t`|`_finddatai64_t`|`_wfinddatai64_t`|  
|`_TINT`|`int`|`int`|`wint_t`|  
|`_TSCHAR`|`signed char`|`signed char`|`wchar_t`|  
|`_TUCHAR`|`unsigned char`|`unsigned char`|`wchar_t`|  
|`_TXCHAR`|`char`|`unsigned char`|`wchar_t`|  
|`_T` ou `_TEXT`|Nenhum efeito \(cancelado por pré\-processador\)|Nenhum efeito \(cancelado por pré\-processador\)|`L` \(converte após o caractere ou cadeia de caracteres à sua contraparte Unicode\)|  
  
## Consulte também  
 [Mapeamentos de texto genérico](../c-runtime-library/generic-text-mappings.md)   
 [Constante e mapeamentos de variável global](../c-runtime-library/constant-and-global-variable-mappings.md)   
 [Mapeamentos de rotina](../c-runtime-library/routine-mappings.md)   
 [Um programa de texto genérico de exemplo](../c-runtime-library/a-sample-generic-text-program.md)   
 [Usando mapeamentos de texto genérico](../c-runtime-library/using-generic-text-mappings.md)