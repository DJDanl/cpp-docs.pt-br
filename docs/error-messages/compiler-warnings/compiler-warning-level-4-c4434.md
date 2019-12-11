---
title: Aviso do compilador (nível 4) C4434
ms.date: 11/04/2016
f1_keywords:
- C4434
helpviewer_keywords:
- C4434
ms.assetid: 24b8785e-353a-4c37-8bed-ed61001a871d
ms.openlocfilehash: fccc37ec531768adbe332ddf9fd91ceb708c7185
ms.sourcegitcommit: 573b36b52b0de7be5cae309d45b68ac7ecf9a6d8
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/10/2019
ms.locfileid: "74990818"
---
# <a name="compiler-warning-level-4-c4434"></a>Aviso do compilador (nível 4) C4434

um construtor de classe deve ter acessibilidade privada; alterando para acesso privado

C4434 indica que o compilador alterou a acessibilidade de um construtor estático. Construtores estáticos devem ter acessibilidade privada, pois eles são destinados apenas para serem chamados pelo Common Language Runtime. Para obter mais informações, consulte [construtores estáticos](../../dotnet/how-to-define-and-consume-classes-and-structs-cpp-cli.md#BKMK_Static_constructors).

## <a name="example"></a>Exemplo

O exemplo a seguir gera C4434.

```cpp
// C4434.cpp
// compile with: /W4 /c /clr
public ref struct R {
   static R(){}   // C4434
};
```
