---
title: Erro do compilador C2893
ms.date: 11/04/2016
f1_keywords:
- C2893
helpviewer_keywords:
- C2893
ms.assetid: ec0cbe43-005d-45da-8742-aaeb9b81d28e
ms.openlocfilehash: f1fad1ad18af54945ef32dadaac50a6de4dbd62f
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50455173"
---
# <a name="compiler-error-c2893"></a>Erro do compilador C2893

Falha ao especializar template de função 'nome do modelo'

O compilador Falha ao especializar um modelo de função. Pode haver várias causas para esse erro.

Em geral, a maneira de resolver um erro de C2893 é examinar a assinatura da função e verifique se que você pode criar uma instância de todos os tipos.

## <a name="example"></a>Exemplo

C2893 ocorre porque `f`do parâmetro de modelo `T` é deduzida como sendo `std::map<int,int>`, mas `std::map<int,int>` não tem nenhum membro `data_type` (`T::data_type` não pode ser instanciado com `T = std::map<int,int>`.). O exemplo a seguir gera C2893.

```
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