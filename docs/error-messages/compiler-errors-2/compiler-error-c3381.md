---
title: Erro do compilador C3381
ms.date: 11/04/2016
f1_keywords:
- C3381
helpviewer_keywords:
- C3381
ms.assetid: d276c89f-8377-4cb6-a8d4-7770885f06c4
ms.openlocfilehash: ae416d68831d1964c89d938dfcddd364e521195c
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50440268"
---
# <a name="compiler-error-c3381"></a>Erro do compilador C3381

'assembly': especificadores de acesso de assembly só estão disponíveis no código compilado com uma opção /clr

Tipos nativos podem ser visíveis fora do assembly, mas você pode especificar apenas o acesso de assembly para tipos nativos em uma **/clr** compilação.

Para obter mais informações, consulte [visibilidade de tipo](../../dotnet/how-to-define-and-consume-classes-and-structs-cpp-cli.md#BKMK_Type_visibility) e [/clr (compilação de tempo de execução de linguagem comum)](../../build/reference/clr-common-language-runtime-compilation.md).

## <a name="example"></a>Exemplo

O exemplo a seguir gera C3381.

```
// C3381.cpp
// compile with: /c
public class A {};   // C3381
```