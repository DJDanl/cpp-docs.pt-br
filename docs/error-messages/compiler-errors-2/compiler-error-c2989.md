---
title: Erro do compilador C2989
ms.date: 11/04/2016
f1_keywords:
- C2989
helpviewer_keywords:
- C2989
ms.assetid: 936303d8-eb3b-4746-82ec-2f18020a6f64
ms.openlocfilehash: 585823c2114befa3e6d432e3cf8100fa14ed1a7d
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80176722"
---
# <a name="compiler-error-c2989"></a>Erro do compilador C2989

' class ': o tipo de classe já foi declarado como um tipo que não é de classe

A classe genérica ou o modelo redefine uma classe que não é de modelo ou não genérica. Verifique se há conflitos nos arquivos de cabeçalho.

O exemplo a seguir gera C2989:

```cpp
// C2989.cpp
// compile with: /c
class C{};

template <class T>
class C{};  // C2989
class C2{};
```

C2989 também pode ocorrer ao usar genéricos:

```cpp
// C2989b.cpp
// compile with: /clr /c
ref class GC1;

generic <typename T> ref class GC1;   // C2989
template <typename T> ref class GC2;

generic <typename T> ref class GC2;   // C2989
generic <typename T> ref class GCb;
template <typename T> ref class GC2;
generic <typename T> ref class GCc;
```
