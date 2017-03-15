---
title: "Corpo da função ou variável ausente | Documentos do Microsoft"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: error-reference
dev_langs:
- C++
helpviewer_keywords:
- function body
- variables, missing
ms.assetid: 1a88d809-b14f-46a4-97c4-3e48beb418f2
caps.latest.revision: 8
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
ms.openlocfilehash: 5a50f119b35ccd5e84ea50b28377df02cb5ac9c6
ms.lasthandoff: 02/25/2017

---
# <a name="missing-function-body-or-variable"></a>Corpo de função ou variável ausente
Com apenas um protótipo de função, o compilador pode continuar sem erro, mas o vinculador não pode resolver uma chamada para um endereço porque não há nenhum código de função ou variável espaço reservado. Você não verá esse erro até que você crie uma chamada para a função que o vinculador deve resolver.  
  
## <a name="example"></a>Exemplo  
 A chamada de função em main causará LNK2019 porque o protótipo permite que o compilador acha que a função existe.  O vinculador localiza que não.  
  
```  
// LNK2019_MFBV.cpp  
// LNK2019 expected  
void DoSomething(void);  
int main() {  
   DoSomething();  
}  
```  
  
## <a name="example"></a>Exemplo  
 No C++, certifique-se de incluir a implementação de uma função específica de uma classe e não apenas um protótipo na definição de classe. Se você estiver definindo a classe fora do arquivo de cabeçalho, certifique-se de incluir o nome da classe antes da função (`Classname``::``memberfunction`).  
  
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
