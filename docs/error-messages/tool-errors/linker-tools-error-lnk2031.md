---
title: Erro das Ferramentas de Vinculador LNK2031
ms.date: 11/04/2016
f1_keywords:
- LNK2031
helpviewer_keywords:
- LNK2031
ms.assetid: 18ed4b6e-3e75-443c-bbd8-2f6030dc89ee
ms.openlocfilehash: 003b9a58bfb08130f034530f59e2de27efa2ae8d
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50484816"
---
# <a name="linker-tools-error-lnk2031"></a>Erro das Ferramentas de Vinculador LNK2031

> não é possível gerar p/invoke para "*function_declaration*" *decorated_name*; chamando convenção faltante nos metadados

## <a name="remarks"></a>Comentários

Ao tentar importar uma função nativa em uma imagem pura, lembre-se de que as convenções de chamada implícitas diferem entre compilações nativas e puras. Para obter mais informações sobre imagens puras, consulte [código puro e verificável (C + + / CLI)](../../dotnet/pure-and-verifiable-code-cpp-cli.md).

O **/clr: pure** opção do compilador é preterida no Visual Studio 2015 e sem suporte no Visual Studio 2017.

## <a name="example"></a>Exemplo

Este exemplo de código gera um componente com uma função exportada, nativo, cuja convenção de chamada é implicitamente [cdecl](../../cpp/cdecl.md).

```cpp
// LNK2031.cpp
// compile with: /LD
extern "C" {
   __declspec(dllexport) int func() { return 3; }
};
```

## <a name="example"></a>Exemplo

O exemplo a seguir cria um cliente puro que consome a função nativa. No entanto, a convenção de chamada sob **/clr: pure** é [clrcall](../../cpp/clrcall.md). O exemplo a seguir gera das LNK2031.

```cpp
// LNK2031_b.cpp
// compile with: /clr:pure LNK2031.lib
// LNK2031 expected
extern "C" int func();

int main() {
   return func();
}
```

## <a name="example"></a>Exemplo

O exemplo a seguir mostra como utilizar a função nativa de uma imagem pura. Observe o explícito **cdecl** especificador de convenção de chamada.

```cpp
// LNK2031_c.cpp
// compile with: /clr:pure LNK2031.lib
extern "C" int __cdecl func();

int main() {
   return func();
}
```