---
title: Erro do compilador C2893
ms.date: 11/04/2016
f1_keywords:
- C2893
helpviewer_keywords:
- C2893
ms.assetid: ec0cbe43-005d-45da-8742-aaeb9b81d28e
ms.openlocfilehash: ca603eb94d5d528a7fed15e0320e1f5d88bf0629
ms.sourcegitcommit: 16fa847794b60bf40c67d20f74751a67fccb602e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/03/2019
ms.locfileid: "74760870"
---
# <a name="compiler-error-c2893"></a>Erro do compilador C2893

Falha ao especializar o modelo de função ' nome do modelo '

O compilador não pôde especializar um modelo de função. Pode haver muitas causas para esse erro.

Em geral, a maneira de resolver um erro C2893 é examinar a assinatura da função e certificar-se de que você pode instanciar todos os tipos.

## <a name="example"></a>Exemplo

C2893 ocorre porque o parâmetro de modelo do `f``T` é deduzido para ser `std::map<int,int>`, mas `std::map<int,int>` não tem nenhum membro `data_type` (`T::data_type` não pode ser instanciado com `T = std::map<int,int>`.). O exemplo a seguir gera C2893.

```cpp
// C2893.cpp
// compile with: /c /EHsc
#include<map>
using namespace std;
class MyClass {};

template<class T>
inline typename T::data_type
// try the following line instead
// inline typename  T::mapped_type
f(T const& p1, MyClass const& p2);

template<class T>
void bar(T const& p1) {
    MyClass r;
    f(p1,r);   // C2893
}

int main() {
   map<int,int> m;
   bar(m);
}
```
