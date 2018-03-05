---
title: Acesso a argumento | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-standard-libraries
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- c.arguments
dev_langs:
- C++
helpviewer_keywords:
- argument access macros [C++]
- variable-length argument lists
ms.assetid: 7046ae34-a0ec-44f0-815d-3209492a3e19
caps.latest.revision: 
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 97db036822687936f3f8e4084c065c8ec64ca23e
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="argument-access"></a>Acesso a argumento
As macros `va_arg`, `va_end` e `va_start` fornecem acesso aos argumentos de função quando o número de argumentos é variável. Elas são definidas em STDARG.H para compatibilidade com ANSI C e em VARARGS.H para compatibilidade com UNIX System V.  
  
### <a name="argument-access-macros"></a>Macros de acesso a argumento  
  
|Macro|Use|  
|-----------|-------------------------------|  
|[va_arg](../c-runtime-library/reference/va-arg-va-copy-va-end-va-start.md)|Recuperar o argumento da lista|  
|[va_end](../c-runtime-library/reference/va-arg-va-copy-va-end-va-start.md)|Reiniciar o ponteiro|  
|[va_start](../c-runtime-library/reference/va-arg-va-copy-va-end-va-start.md)|Definir o ponteiro para o início da lista de argumentos|  
  
## <a name="see-also"></a>Consulte também  
 [Rotinas de tempo de execução por categoria](../c-runtime-library/run-time-routines-by-category.md)