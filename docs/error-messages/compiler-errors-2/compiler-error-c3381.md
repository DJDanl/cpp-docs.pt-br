---
title: Erro do compilador C3381
description: Erro C3381 do compilador do Microsoft C++, suas causas e como resolvê-los.
ms.date: 09/28/2020
f1_keywords:
- C3381
helpviewer_keywords:
- C3381
ms.assetid: d276c89f-8377-4cb6-a8d4-7770885f06c4
ms.openlocfilehash: 48a6c81f9506c532333b5353b8b194d17c91043f
ms.sourcegitcommit: a1676bf6caae05ecd698f26ed80c08828722b237
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/29/2020
ms.locfileid: "91510155"
---
# <a name="compiler-error-c3381"></a>Erro do compilador C3381

> '*Identifier*': especificadores de acesso de assembly estão disponíveis somente no código compilado com uma opção/CLR

Um tipo foi declarado ou definido usando um especificador de acesso, que é permitido somente no código compilado usando **`/clr`** .

## <a name="remarks"></a>Comentários

Esse erro pode resultar de uma **`public`** **`protected`** palavra-chave incorreta, ou ou um sinal de **`private`** dois-pontos ( **`:`** ) após um especificador de acesso dentro de um **`class`** ou **`struct`** .

Em C++/CLI, os tipos nativos podem ser visíveis fora de um assembly, mas você só pode especificar o acesso de assembly para tipos nativos em uma **`/clr`** compilação. Para obter mais informações, consulte [visibilidade de tipo](../../dotnet/how-to-define-and-consume-classes-and-structs-cpp-cli.md#BKMK_Type_visibility) e [ `/clr` (compilação do Common Language Runtime)](../../build/reference/clr-common-language-runtime-compilation.md).

## <a name="example"></a>Exemplo

O exemplo a seguir gera C3381. Para corrigi-lo, primeiro remova o **`public`** especificador da `class A` definição ou compile usando a **`/clr`** opção. Em seguida, adicione dois-pontos depois **`private`** de especificar o acesso para `class B {} b;` . Isso ocorre porque uma classe aninhada não pode ter um especificador de acesso de assembly como parte de sua declaração.

```cpp
// C3381.cpp
// compile with: /c
public class A {   // C3381
    private class B {} b;   // C3381
};
```
