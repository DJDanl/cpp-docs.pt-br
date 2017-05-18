---
title: "Compilador aviso (nível 1) C4142 | Documentos do Microsoft"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C4142
dev_langs:
- C++
helpviewer_keywords:
- C4142
ms.assetid: 1fdfc3dc-60a2-4f00-b133-20e400f9b7a6
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
ms.translationtype: Machine Translation
ms.sourcegitcommit: 3168772cbb7e8127523bc2fc2da5cc9b4f59beb8
ms.openlocfilehash: 81fbb15b9589d5ddfdcc949dce24aec2a3c1716e
ms.contentlocale: pt-br
ms.lasthandoff: 02/25/2017

---
# <a name="compiler-warning-level-1-c4142"></a>Compilador C4142 de aviso (nível 1)
redefinição benigna de tipo  
  
 Um tipo é redefinido em uma forma que não tem nenhum efeito no código gerado.  
  
 Para corrigir verificando as possíveis causas:  
  
-   Uma função de membro de uma classe derivada tem um tipo de retorno diferente da função de membro correspondente da classe base.  
  
-   Um tipo definido com o `typedef` comando será redefinido usando uma sintaxe diferente.  
  
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
