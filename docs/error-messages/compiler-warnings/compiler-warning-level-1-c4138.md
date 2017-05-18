---
title: "Compilador aviso (nível 1) C4138 | Documentos do Microsoft"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- C4138
dev_langs:
- C++
helpviewer_keywords:
- C4138
ms.assetid: 65ebf929-bba0-4237-923b-c1b66adfe17d
caps.latest.revision: 6
author: corob-msft
ms.author: corob
manager: ghogen
translation.priority.ht:
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- ru-ru
- zh-cn
- zh-tw
translation.priority.mt:
- cs-cz
- pl-pl
- pt-br
- tr-tr
ms.translationtype: Machine Translation
ms.sourcegitcommit: 3168772cbb7e8127523bc2fc2da5cc9b4f59beb8
ms.openlocfilehash: 4135189008a68a08ed27738475a1cf5ca8fbdc52
ms.contentlocale: pt-br
ms.lasthandoff: 02/25/2017

---
# <a name="compiler-warning-level-1-c4138"></a>Compilador C4138 de aviso (nível 1)
'*/' encontrado fora de comentário  
  
 O delimitador de comentário de fechamento não é precedido por um delimitador de comentário de abertura. O compilador pressupõe um espaço entre o asterisco (**\***) e a barra (/).  
  
## <a name="example"></a>Exemplo  
  
```  
// C4138a.cpp  
// compile with: /W1  
int */*comment*/ptr;   // C4138 Ambiguous first delimiter causes warning  
int main()  
{  
}  
```  
  
 Esse aviso pode ser causado pela tentativa de aninhar comentários.  
  
 Esse aviso pode ser resolvido se você comentar seções de código que contém comentários, coloque o código em um **#if / #endif** bloquear e definir a expressão de controle como zero:  
  
```  
// C4138b.cpp  
// compile with: /W1  
#if 0  
int my_variable;   /* Declaration currently not needed */  
#endif  
int main()  
{  
}  
```
