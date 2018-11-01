---
title: Erro do compilador C3373
ms.date: 11/04/2016
f1_keywords:
- C3373
helpviewer_keywords:
- C3373
ms.assetid: 6e7586c3-1a15-4773-ad20-f90090a400dc
ms.openlocfilehash: 2f279d602d5023c2981f49ff088fec49a1c14c76
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50571893"
---
# <a name="compiler-error-c3373"></a>Erro do compilador C3373

o atributo 'attribute' não recebe argumentos exceto em uma coclass

Alguns atributos podem ser aplicados a mais de uma construção C++, mas os argumentos para o atributo podem ser permitido apenas em algumas construções.

O exemplo a seguir gera C3373:

```
// C3373.cpp
#include <windows.h>

[module(name="MyModule")];

[ object, uuid(373a1a4c-469b-11d3-a6b0-00c04f79ae8f) ]
__interface IMyIface
{
   // arguments to source and restricted are not allowed when
   // these attributes are applied to an interface
   [source(IMyIface)] HRESULT f1();
   [restricted(IMyIface)] HRESULT f2(); // C3373
};

[ coclass, uuid(373a1a4d-469b-11d3-a6b0-00c04f79ae8f) ]
class CMyClass : public IMyIface {
};

int main() {
}
```