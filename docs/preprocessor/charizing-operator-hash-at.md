---
title: "Operador de caracterização (#@) | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords: '#@'
dev_langs: C++
helpviewer_keywords:
- preprocessor, operators
- charizing operator
- '#@ preprocessor operator'
ms.assetid: dee03314-d27c-4063-965c-64756efbef22
caps.latest.revision: "6"
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 933e97732462b61919d9e5a1e73f2a72d26ea01b
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
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