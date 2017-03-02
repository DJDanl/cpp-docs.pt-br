---
title: C2390 de erro do compilador | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C2390
dev_langs:
- C++
helpviewer_keywords:
- C2390
ms.assetid: 06b749ee-d072-4db1-b229-715f2c0728b5
caps.latest.revision: 9
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
ms.openlocfilehash: 8334477aef71e8f698bb70a48218c4b4b6c5ce0b
ms.lasthandoff: 02/25/2017

---
# <a name="compiler-error-c2390"></a>C2390 de erro do compilador
'identifier': classe de armazenamento incorreto 'especificador'  
  
 A classe de armazenamento não é válida para o identificador de escopo global. A classe de armazenamento padrão é usada no lugar de classe inválida.  
  
 Possíveis resoluções:  
  
-   Se o identificador é uma função, declare-o com `extern` armazenamento.  
  
-   Se o identificador é um parâmetro formal ou uma variável local, declare-o com o armazenamento automático.  
  
-   Se o identificador é uma variável global, você deve declará-lo com nenhuma classe de armazenamento (armazenamento automático).  
  
## <a name="example"></a>Exemplo  
  
-   O exemplo a seguir gera C2390:  
  
```  
// C2390.cpp  
register int i;   // C2390  
  
int main() {  
   register int j;   // OK  
}  
```
