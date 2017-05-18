---
title: "Compilador (nível 4) de aviso C4459 | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C4459
dev_langs:
- C++
helpviewer_keywords:
- C4459
ms.assetid: ee9f6287-9c70-4b10-82a0-add82a13997f
caps.latest.revision: 0
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
ms.sourcegitcommit: 128bd124c2536d86c8b673b54abc4b5505526b41
ms.openlocfilehash: 87550474065639f6e1c7521ebfe76792d748ce9b
ms.contentlocale: pt-br
ms.lasthandoff: 05/10/2017

---
# <a name="compiler-warning-level-4-c4459"></a>Compilador C4459 de aviso (nível 4)
  
> declaração de '*identificador*' oculta uma declaração global
  
A declaração de *identificador* no escopo local oculta a declaração de idêntico *identificador* no escopo global. Este aviso informa que faz referência às *identificador* neste escopo resolver para a versão declarada localmente, não a versão global, que pode ou não ser a intenção. Em geral, recomendamos que você minimize o uso de variáveis globais como uma prática recomendada de engenharia. Para reduzir a poluição de namespace global, recomendamos o uso de um namespace nomeado para variáveis globais.  
  
Esse aviso é novo no Visual Studio 2015, no Visual C++ versão do compilador 18h00 Hora. Para suprimir avisos do que a versão do compilador ou posterior ao migrar seu código, use o [/wv: 18](../../build/reference/compiler-option-warning-level.md) opção de compilador. 

## <a name="example"></a>Exemplo
  
 O exemplo a seguir gera C4459:  
  
```cpp  
// C4459_hide.cpp
// compile with: cl /W4 /EHsc C4459_hide.cpp
int global_or_local = 1;

int main() { 
    int global_or_local; // warning C4459 
    global_or_local = 2;
} 
```  
  
Uma maneira de corrigir esse problema é criar um namespace para o globais, mas não usar um `using` nomes qualificados de diretiva para colocar esse namespace no escopo, para todas as referências devem usar o ambíguo:  
  
```cpp  
// C4459_namespace.cpp
// compile with: cl /W4 /EHsc C4459_namespace.cpp
namespace globals {
    int global_or_local = 1;
}

int main() { 
    int global_or_local; // OK 
    global_or_local = 2;
    globals::global_or_local = 3;
} 
```  

