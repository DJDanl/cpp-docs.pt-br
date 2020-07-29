---
title: Erro das Ferramentas de Vinculador LNK2031
ms.date: 11/04/2016
f1_keywords:
- LNK2031
helpviewer_keywords:
- LNK2031
ms.assetid: 18ed4b6e-3e75-443c-bbd8-2f6030dc89ee
ms.openlocfilehash: 326886f8de8b59cce9df46eb7b0325b7cc9eb9f2
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87225196"
---
# <a name="linker-tools-error-lnk2031"></a>Erro das Ferramentas de Vinculador LNK2031

> Não é possível gerar p/invoke para "*function_declaration*" *decorated_name*; Convenção de chamada ausente nos metadados

## <a name="remarks"></a>Comentários

Ao tentar importar uma função nativa em uma imagem pura, lembre-se de que as convenções implícitas de chamada diferem entre as compilações nativas e puras. Para obter mais informações sobre imagens puras, consulte [código puro e verificável (C++/CLI)](../../dotnet/pure-and-verifiable-code-cpp-cli.md).

A opção de compilador **/CLR: Pure** foi preterida no visual Studio 2015 e não tem suporte no visual Studio 2017.

## <a name="example"></a>Exemplo

Este exemplo de código gera um componente com uma função exportada, nativa, cuja Convenção de chamada é implicitamente [__cdecl](../../cpp/cdecl.md).

```cpp
// LNK2031.cpp
// compile with: /LD
extern "C" {
   __declspec(dllexport) int func() { return 3; }
};
```

## <a name="example"></a>Exemplo

O exemplo a seguir cria um cliente puro que consome a função nativa. No entanto, a Convenção de chamada em **/CLR: Pure** é [__clrcall](../../cpp/clrcall.md). O exemplo a seguir gera LNK2031.

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

O exemplo a seguir mostra como consumir a função nativa de uma imagem pura. Observe o **`__cdecl`** especificador de Convenção de chamada explícita.

```cpp
// LNK2031_c.cpp
// compile with: /clr:pure LNK2031.lib
extern "C" int __cdecl func();

int main() {
   return func();
}
```
