---
title: "Compilador (nível 1) de aviso C4142 | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords: C4142
dev_langs: C++
helpviewer_keywords: C4142
ms.assetid: 1fdfc3dc-60a2-4f00-b133-20e400f9b7a6
caps.latest.revision: "7"
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 73d3ad63aaf040b83622720040adf3a291d354e3
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="compiler-warning-level-1-c4142"></a>Compilador C4142 de aviso (nível 1)
redefinição benigna de tipo  
  
 Um tipo é redefinido de forma que não tem nenhum efeito no código gerado.  
  
 Para corrigir, verificando as possíveis causas:  
  
-   Uma função de membro de uma classe derivada tem um tipo de retorno diferente da função de membro correspondente da classe base.  
  
-   Um tipo definido com o `typedef` comando será redefinido usando sintaxe diferente.  
  
 O exemplo a seguir gera C4142:  
  
```  
// C4142.c  
// compile with: /W1  
float X2;  
X2 = 2.0 + 1.0;   // C4142  
  
int main() {  
   float X2;  
   X2 = 2.0 + 1.0;   // OK  
}  
```