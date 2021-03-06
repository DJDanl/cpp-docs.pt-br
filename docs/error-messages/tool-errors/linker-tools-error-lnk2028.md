---
title: Erro das Ferramentas de Vinculador LNK2028
ms.date: 11/04/2016
f1_keywords:
- LNK2028
helpviewer_keywords:
- LNK2028
ms.assetid: e2b03293-6066-464d-a050-ce747bcf7f0e
ms.openlocfilehash: 29aaed167f750186d956589e9daa0d21c441149e
ms.sourcegitcommit: c1fd917a8c06c6504f66f66315ff352d0c046700
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/16/2020
ms.locfileid: "90684191"
---
# <a name="linker-tools-error-lnk2028"></a>Erro das Ferramentas de Vinculador LNK2028

"*exported_function*" (*decorated_name*) referenciado na função "*function_containing_function_call*" (*decorated_name*)

## <a name="remarks"></a>Comentários

Ao tentar importar uma função nativa em uma imagem pura, lembre-se de que as convenções implícitas de chamada diferem entre as compilações nativas e puras.

A opção de compilador **/CLR: Pure** foi preterida no visual Studio 2015 e não tem suporte no visual Studio 2017.

## <a name="examples"></a>Exemplos

Este exemplo de código gera um componente com uma função exportada, nativa, cuja Convenção de chamada é implicitamente [__cdecl](../../cpp/cdecl.md).

```cpp
// LNK2028.cpp
// compile with: /LD
__declspec(dllexport) int func() {
   return 3;
}
```

O exemplo a seguir cria um cliente puro que consome a função nativa. No entanto, a Convenção de chamada em **/CLR: Pure** é [__clrcall](../../cpp/clrcall.md). O exemplo a seguir gera LNK2028.

```cpp
// LNK2028_b.cpp
// compile with: /clr:pure lnk2028.lib
// LNK2028 expected
int func();

int main() {
   return func();
}
```
