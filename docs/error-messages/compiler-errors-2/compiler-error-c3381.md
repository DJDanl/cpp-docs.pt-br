---
title: Erro do compilador C3381 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C3381
dev_langs:
- C++
helpviewer_keywords:
- C3381
ms.assetid: d276c89f-8377-4cb6-a8d4-7770885f06c4
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 7bd6c1d641f7476d3c372939b948931a306e0f80
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46080708"
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