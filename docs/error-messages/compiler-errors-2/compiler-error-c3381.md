---
title: Erro do compilador C3381
ms.date: 11/04/2016
f1_keywords:
- C3381
helpviewer_keywords:
- C3381
ms.assetid: d276c89f-8377-4cb6-a8d4-7770885f06c4
ms.openlocfilehash: eadc9b45b4cd4f2d9b533f387dadd66be8acc963
ms.sourcegitcommit: 16fa847794b60bf40c67d20f74751a67fccb602e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/03/2019
ms.locfileid: "74749562"
---
# <a name="compiler-error-c3381"></a>Erro do compilador C3381

' assembly ': especificadores de acesso de assembly só estão disponíveis no código compilado com uma opção/CLR

Tipos nativos podem ser visíveis fora do assembly, mas você só pode especificar o acesso de assembly para tipos nativos em uma compilação **/CLR** .

Para obter mais informações, consulte [visibilidade de tipo](../../dotnet/how-to-define-and-consume-classes-and-structs-cpp-cli.md#BKMK_Type_visibility) e [/CLR (compilação em tempo de execução de linguagem comum)](../../build/reference/clr-common-language-runtime-compilation.md).

## <a name="example"></a>Exemplo

O exemplo a seguir gera C3381.

```cpp
// C3381.cpp
// compile with: /c
public class A {};   // C3381
```
