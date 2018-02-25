---
title: "Operador de caracterização (#@) | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- '#@'
dev_langs:
- C++
helpviewer_keywords:
- preprocessor, operators
- charizing operator
- '#@ preprocessor operator'
ms.assetid: dee03314-d27c-4063-965c-64756efbef22
caps.latest.revision: 
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: a6521322e7a71d8e76b657fb8580157c036e881b
ms.sourcegitcommit: d51ed21ab2b434535f5c1d553b22e432073e1478
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/23/2018
---
# <a name="charizing-operator-"></a>Operador de caracterização (#@)
**Seção específica da Microsoft**  
  
 O operador de charizing pode usado apenas com os argumentos das macros. Se  **#@**  precede um parâmetro formal na definição de macro, o argumento é colocado entre aspas simples e tratado como um caractere quando a macro é expandida. Por exemplo:  
  
```  
#define makechar(x)  #@x  
```  
  
 faz com que a instrução  
  
```  
a = makechar(b);  
```  
  
 seja expandida para  
  
```  
a = 'b';  
```  
  
 O caractere de aspas simples não pode ser usado com o operador de charizing.  
  
 **Fim da seção específica da Microsoft**  
  
## <a name="see-also"></a>Consulte também  
 [Operadores de pré-processador](../preprocessor/preprocessor-operators.md)