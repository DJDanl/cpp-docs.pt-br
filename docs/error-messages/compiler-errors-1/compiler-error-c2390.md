---
title: C2390 de erro do compilador | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C2390
dev_langs:
- C++
helpviewer_keywords:
- C2390
ms.assetid: 06b749ee-d072-4db1-b229-715f2c0728b5
caps.latest.revision: 
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 93d4cbd9de274d53fdc0369c2b85dbf2e97af48f
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="compiler-error-c2390"></a>C2390 de erro do compilador
'Identificador': classe de armazenamento incorreta 'especificador'  
  
 A classe de armazenamento não é válida para o identificador de escopo global. A classe de armazenamento padrão é usada no lugar de classe inválida.  
  
 Possíveis resoluções:  
  
-   Se o identificador é uma função, declare-o com `extern` armazenamento.  
  
-   Se o identificador é uma variável local ou o parâmetro formal, declare-o com o armazenamento automaticamente.  
  
-   Se o identificador é uma variável global, declare-o com nenhuma classe de armazenamento (armazenamento automático).  
  
## <a name="example"></a>Exemplo  
  
-   O exemplo a seguir gera C2390:  
  
```  
// C2390.cpp  
register int i;   // C2390  
  
int main() {  
   register int j;   // OK  
}  
```