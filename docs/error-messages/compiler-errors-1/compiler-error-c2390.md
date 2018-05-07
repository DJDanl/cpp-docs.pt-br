---
title: C2390 de erro do compilador | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C2390
dev_langs:
- C++
helpviewer_keywords:
- C2390
ms.assetid: 06b749ee-d072-4db1-b229-715f2c0728b5
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 5a32a9ca77ba43e5f2866baed91b99103224dbc0
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
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