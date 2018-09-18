---
title: Erro do compilador C2893 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C2893
dev_langs:
- C++
helpviewer_keywords:
- C2893
ms.assetid: ec0cbe43-005d-45da-8742-aaeb9b81d28e
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 73d4f838f030db3667b08295006c2ea1df94c87b
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46026173"
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