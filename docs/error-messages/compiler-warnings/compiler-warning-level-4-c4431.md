---
title: Compilador aviso (nível 4) C4431
ms.date: 11/04/2016
f1_keywords:
- C4431
helpviewer_keywords:
- C4431
ms.assetid: 58434ab6-dd8d-427b-953a-602fb7453ae6
ms.openlocfilehash: 6a07a9ffa938d9372ebed9676847b3274115d526
ms.sourcegitcommit: 7d64c5f226f925642a25e07498567df8bebb00d4
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/08/2019
ms.locfileid: "65447026"
---
# <a name="compiler-warning-level-4-c4431"></a>Compilador aviso (nível 4) C4431

faltando especificador de tipo - int assumido. Observação: C não suporta default-int

Esse erro pode ser gerado como resultado do trabalho de conformidade do compilador que foi feito para o Visual Studio 2005: O Visual C++ não cria mais identificadores não tipados como int por padrão. O tipo de um identificador deve ser especificado explicitamente.

Esse aviso é desativado por padrão. Ver [compilador avisos que são desativado por padrão](../../preprocessor/compiler-warnings-that-are-off-by-default.md) para obter mais informações.

## <a name="example"></a>Exemplo

O exemplo a seguir gera C4431.

```
// C4431.c
// compile with: /c /W4
#pragma warning(default:4431)
i;   // C4431
int i;   // OK
```