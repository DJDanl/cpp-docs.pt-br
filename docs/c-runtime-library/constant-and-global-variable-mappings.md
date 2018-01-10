---
title: "Mapeamentos constantes e de variável global | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-standard-libraries
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- _tenviron
- _TEOF
- _tfinddata_t
dev_langs: C++
helpviewer_keywords:
- tfinddatat function
- tenviron function
- TEOF type
- _TEOF type
- generic-text mappings
- _tenviron function
- _tfinddata_t function
ms.assetid: 3af4fd3e-9ed5-4ed9-96fd-7031e5126fd1
caps.latest.revision: "7"
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: bb767bb3dbfbde8d73ab81acc444a772a05e7880
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="constant-and-global-variable-mappings"></a>Constante e mapeamentos de variável global
Esses mapeamentos constantes de texto genérico, de variável global e de tipo padrão são definidos no TCHAR.H e dependem se a constante `_UNICODE` ou `_MBCS` foi definida em seu programa.  
  
### <a name="generic-text-constant-and-global-variable-mappings"></a>Mapeamentos constantes de texto genérico e de variável global  
  
|De texto genérico – nome do objeto|SBCS (_UNICODE, _MBCS não definidos)|_MBCS definido|_UNICODE definido|  
|----------------------------------|--------------------------------------------|--------------------|-----------------------|  
|`_TEOF`|`EOF`|`EOF`|`WEOF`|  
|`_tenviron`|`_environ`|`_environ`|`_wenviron`|  
|`_tpgmptr`|`_pgmptr`|`_pgmptr`|`_wpgmptr`|  
  
## <a name="see-also"></a>Consulte também  
 [Mapeamentos de texto genérico](../c-runtime-library/generic-text-mappings.md)   
 [Mapeamentos de tipo de dados](../c-runtime-library/data-type-mappings.md)   
 [Mapeamentos de rotina](../c-runtime-library/routine-mappings.md)   
 [Um programa de texto genérico de amostra](../c-runtime-library/a-sample-generic-text-program.md)   
 [Usando mapeamentos de texto genérico](../c-runtime-library/using-generic-text-mappings.md)