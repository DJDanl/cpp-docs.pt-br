---
title: Erro fatal C1308
ms.date: 11/04/2016
f1_keywords:
- C1308
helpviewer_keywords:
- C1308
ms.assetid: 46177997-069e-433a-8e20-93c846d78ffd
ms.openlocfilehash: 95e13a6914b5e02441f95dd2256532dbd1d718e5
ms.sourcegitcommit: 16fa847794b60bf40c67d20f74751a67fccb602e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/03/2019
ms.locfileid: "74747014"
---
# <a name="fatal-error-c1308"></a>Erro fatal C1308

Não há suporte para a vinculação de assemblies

Um. netmodule é permitido como entrada para o vinculador, mas um assembly não é. Esse erro pode ser gerado quando é feita uma tentativa de vincular um assembly compilado com `/clr:safe`.

Para obter mais informações, consulte [arquivos. netmodule como entrada do vinculador](../../build/reference/netmodule-files-as-linker-input.md).

O exemplo a seguir gera C1308:

```cpp
// C1308.cpp
// compile with: /clr:safe /LD
public ref class MyClass {
public:
   int i;
};
```

E, em seguida,

```cpp
// C1308b.cpp
// compile with: /clr /link C1308b.obj C1308.dll
// C1308 expected
#using "C1308.dll"
int main() {
   MyClass ^ my = gcnew MyClass();
}
```
