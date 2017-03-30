---
title: Acesso a argumento | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
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
caps.latest.revision: 8
author: corob-msft
ms.author: corob
manager: ghogen
translation.priority.ht:
- cs-cz
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- pl-pl
- pt-br
- ru-ru
- tr-tr
- zh-cn
- zh-tw
translationtype: Human Translation
ms.sourcegitcommit: e257f037a05c45f5b98e64ea55bd125af443b0be
ms.openlocfilehash: 66f9ff6dff86bbdff2ec86970a4176f3581316fa
ms.lasthandoff: 03/30/2017

---
# <a name="argument-access"></a>Acesso a argumento
As macros `va_arg`, `va_end` e `va_start` fornecem acesso aos argumentos de função quando o número de argumentos é variável. Elas são definidas em STDARG.H para compatibilidade com ANSI C e em VARARGS.H para compatibilidade com UNIX System V.  
  
### <a name="argument-access-macros"></a>Macros de acesso a argumento  
  
|Macro|Uso|  
|-----------|-------------------------------|  
|[va_arg](../c-runtime-library/reference/va-arg-va-copy-va-end-va-start.md)|Recuperar o argumento da lista|  
|[va_end](../c-runtime-library/reference/va-arg-va-copy-va-end-va-start.md)|Reiniciar o ponteiro|  
|[va_start](../c-runtime-library/reference/va-arg-va-copy-va-end-va-start.md)|Definir o ponteiro para o início da lista de argumentos|  
  
## <a name="see-also"></a>Consulte também  
 [Rotinas de tempo de execução por categoria](../c-runtime-library/run-time-routines-by-category.md)
