---
title: "Compilador aviso (nível 2) C4094 | Documentos do Microsoft"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C4094
dev_langs:
- C++
helpviewer_keywords:
- C4094
ms.assetid: e68929fb-3a1c-4be7-920b-d5f79f534f99
caps.latest.revision: 7
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
translationtype: Machine Translation
ms.sourcegitcommit: 3168772cbb7e8127523bc2fc2da5cc9b4f59beb8
ms.openlocfilehash: b5f5e8eaf800dcfbec66705c5c21bd791694210c
ms.lasthandoff: 02/25/2017

---
# <a name="compiler-warning-level-2-c4094"></a>Compilador C4094 de aviso (nível 2)
sem marcas 'token' declarado sem símbolos  
  
 O compilador detectou uma declaração vazia usando uma estrutura sem marcas, união ou classe. A declaração é ignorada.  
  
## <a name="example"></a>Exemplo  
  
```  
// C4094.cpp  
// compile with: /W2  
struct  
{  
};   // C4094  
  
int main()  
{  
}  
```  
  
 Essa condição gera um erro em compatibilidade com ANSI ([/Za](../../build/reference/za-ze-disable-language-extensions.md)).
