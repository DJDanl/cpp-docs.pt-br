---
title: "Corpo da função ou variável ausente | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
dev_langs: C++
helpviewer_keywords:
- function body
- variables, missing
ms.assetid: 1a88d809-b14f-46a4-97c4-3e48beb418f2
caps.latest.revision: "8"
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 356d0f0a71feccee953a0b1bd7dc54bc64a0e233
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="missing-function-body-or-variable"></a>Corpo de função ou variável ausente
Com apenas um protótipo de função, o compilador pode continuar sem erro, mas o vinculador não pode resolver uma chamada para um endereço porque não há nenhum código de função ou variável espaço reservado. Você não verá esse erro até que você crie uma chamada para a função que o vinculador deve resolver.  
  
## <a name="example"></a>Exemplo  
 A chamada de função no principal causará LNK2019 porque o protótipo permite que o compilador que a função existe.  O vinculador localiza que não.  
  
```  
// LNK2019_MFBV.cpp  
// LNK2019 expected  
void DoSomething(void);  
int main() {  
   DoSomething();  
}  
```  
  
## <a name="example"></a>Exemplo  
 No C++, certifique-se de incluir a implementação de uma função específica para uma classe e não apenas um protótipo na definição de classe. Se você estiver definindo a classe fora do arquivo de cabeçalho, certifique-se de incluir o nome da classe antes da função (`Classname::memberfunction`).  
  
```  
// LNK2019_MFBV_2.cpp  
// LNK2019 expected  
struct A {  
   static void Test();  
};  
  
// Should be void A::Test() {}  
void Test() {}  
  
int main() {  
   A AObject;  
   AObject.Test();  
}  
```  
  
## <a name="see-also"></a>Consulte também  
 [Erro das ferramentas de vinculador LNK2019](../../error-messages/tool-errors/linker-tools-error-lnk2019.md)