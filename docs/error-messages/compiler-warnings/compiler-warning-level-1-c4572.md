---
title: "Compilador aviso (nível 1) C4572 | Documentos do Microsoft"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C4572
dev_langs:
- C++
helpviewer_keywords:
- C4572
ms.assetid: 482dee5a-29bd-4fc3-b769-9dfd4cd2a964
caps.latest.revision: 6
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
ms.openlocfilehash: 0814f78442366ae247a317d082368493930f0836
ms.lasthandoff: 02/25/2017

---
# <a name="compiler-warning-level-1-c4572"></a>Compilador C4572 de aviso (nível 1)
Atributo [ParamArray] é preterido em /clr, use '...' em vez disso  
  
 Foi usado um estilo obsoleto para especificar uma lista de argumentos variável. Ao compilar para o CLR, use a sintaxe de reticências, em vez de <xref:System.ParamArrayAttribute>.</xref:System.ParamArrayAttribute> Para obter mais informações, consulte [listas de argumentos variáveis (...) (C + + / CLI) ](../../windows/variable-argument-lists-dot-dot-dot-cpp-cli.md).  
  
## <a name="example"></a>Exemplo  
 O exemplo a seguir gera C4572.  
  
```  
// C4572.cpp  
// compile with: /clr /W1  
void Func([System::ParamArray] array<int> ^);   // C4572  
void Func2(... array<int> ^){}   // OK  
  
int main() {  
   Func2(1, 2, 3);  
}  
```
