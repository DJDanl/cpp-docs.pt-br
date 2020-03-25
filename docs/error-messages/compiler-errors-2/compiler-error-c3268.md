---
title: Erro do compilador C3268
ms.date: 11/04/2016
f1_keywords:
- C3268
helpviewer_keywords:
- C3268
ms.assetid: d74a630c-daea-4e29-9759-83efef7fb184
ms.openlocfilehash: 191456a1e290b568897ba76cd5bdccb8f83c310b
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80201455"
---
# <a name="compiler-error-c3268"></a>Erro do compilador C3268

> '*Function*': uma função genérica ou uma função membro de uma classe de Generic não pode ter uma lista de parâmetros variáveis

## <a name="remarks"></a>Comentários

As opções de compilador **/CLR: Pure** e **/CLR: safe** são preteridas no Visual Studio 2015 e sem suporte no Visual Studio 2017.

Consulte [genéricos](../../extensions/generics-cpp-component-extensions.md) para obter mais informações.

## <a name="example"></a>Exemplo

O exemplo a seguir gera C3268.

```cpp
// C3268.cpp
// compile with: /clr:pure /c
generic <class ItemType>
void Test(ItemType item, ...) {}   // C3268
// try the following line instead
// void Test(ItemType item) {}

generic <class ItemType2>
ref struct MyStruct { void Test(...){} };   // C3268
// try the following line instead
// ref struct MyStruct { void Test2(){} };   // OK
```
