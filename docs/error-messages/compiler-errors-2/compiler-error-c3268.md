---
title: Erro do compilador C3268
ms.date: 11/04/2016
f1_keywords:
- C3268
helpviewer_keywords:
- C3268
ms.assetid: d74a630c-daea-4e29-9759-83efef7fb184
ms.openlocfilehash: d9954c12fb1065a4aa5e7afbdecd1f96758acaf9
ms.sourcegitcommit: 72583d30170d6ef29ea5c6848dc00169f2c909aa
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/18/2019
ms.locfileid: "59777751"
---
# <a name="compiler-error-c3268"></a>Erro do compilador C3268

> '*função*': uma função genérica ou uma função de membro de uma classe genérica não pode ter uma lista de parâmetros variáveis

## <a name="remarks"></a>Comentários

O **/clr: pure** e **/CLR: safe** opções do compilador são preteridas no Visual Studio 2015 e sem suporte no Visual Studio 2017.

Ver [genéricos](../../extensions/generics-cpp-component-extensions.md) para obter mais informações.

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