---
title: Erro do compilador C3268
ms.date: 11/04/2016
f1_keywords:
- C3268
helpviewer_keywords:
- C3268
ms.assetid: d74a630c-daea-4e29-9759-83efef7fb184
ms.openlocfilehash: c766488b29273f321feffa8e38a97e54454db7b1
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50480529"
---
# <a name="compiler-error-c3268"></a>Erro do compilador C3268

> '*função*': uma função genérica ou uma função de membro de uma classe genérica não pode ter uma lista de parâmetros variáveis

## <a name="remarks"></a>Comentários

O **/clr: pure** e **/CLR: safe** opções do compilador são preteridas no Visual Studio 2015 e sem suporte no Visual Studio 2017.

Ver [genéricos](../../windows/generics-cpp-component-extensions.md) para obter mais informações.

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