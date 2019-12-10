---
title: Aviso D9043 (linha de comando)
ms.date: 11/04/2016
f1_keywords:
- D9043
helpviewer_keywords:
- D9043
ms.assetid: 9263e28d-217b-414c-bfb6-86efd3c27a77
ms.openlocfilehash: 747f3cadd050b8f36c13fd28ae123f7a6dbdfb05
ms.sourcegitcommit: 573b36b52b0de7be5cae309d45b68ac7ecf9a6d8
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/10/2019
ms.locfileid: "74992104"
---
# <a name="command-line-warning-d9043"></a>Aviso D9043 (linha de comando)

valor inválido ' warning_level ' para ' compiler_option '; assumindo ' 4999 '; Os avisos de análise de código não estão associados aos níveis de aviso

## <a name="example"></a>Exemplo

O exemplo a seguir gera C9043.

```cpp
// D9043.cpp
// compile with: /analyze /w16001
// D9043 warning expected
int main() {}
```
