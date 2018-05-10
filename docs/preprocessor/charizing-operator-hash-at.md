---
title: Operador de caracterização (#@) | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-tools
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
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: e9e0c0d140d937b7359ff3abf9c0eae145a89210
ms.sourcegitcommit: d55ac596ba8f908f5d91d228dc070dad31cb8360
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/08/2018
---
# <a name="charizing-operator-"></a>Operador de caracterização (#@)
**Seção específica da Microsoft**  
  
 O operador de charizing pode usado apenas com os argumentos das macros. Se **#@** precede um parâmetro formal na definição de macro, o argumento é colocado entre aspas simples e tratado como um caractere quando a macro é expandida. Por exemplo:  
  
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