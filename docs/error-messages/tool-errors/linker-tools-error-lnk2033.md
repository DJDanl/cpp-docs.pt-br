---
title: Erro das Ferramentas de Vinculador LNK2033
ms.date: 11/04/2016
f1_keywords:
- LNK2033
helpviewer_keywords:
- LNK2033
ms.assetid: d61db467-9328-4788-bf54-e2a20537f13f
ms.openlocfilehash: 7e95823e23215848ff3e5d201171523c9009eb2d
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50571880"
---
# <a name="linker-tools-error-lnk2033"></a>Erro das Ferramentas de Vinculador LNK2033

token typeref indefinido (token) para 'type'

Um tipo não tem uma definição em metadados MSIL.

Das LNK2033 podem ocorrer durante a compilação com **/CLR: safe** e onde há apenas uma declaração de encaminhamento para um tipo em um módulo MSIL, em que o tipo é referenciado no módulo MSIL.

O tipo deve ser definido em **/CLR: safe**.

Para obter mais informações, consulte [/clr (compilação de Common Language Runtime)](../../build/reference/clr-common-language-runtime-compilation.md).

## <a name="example"></a>Exemplo

O exemplo a seguir gera das LNK2033.

```
// LNK2033.cpp
// compile with: /clr:safe
// LNK2033 expected
ref class A;
ref class B {};

int main() {
   A ^ aa = nullptr;
   B ^ bb = nullptr;   // OK
};
```