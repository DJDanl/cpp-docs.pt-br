---
title: Aviso D9043 (linha de comando)
ms.date: 11/04/2016
f1_keywords:
- D9043
helpviewer_keywords:
- D9043
ms.assetid: 9263e28d-217b-414c-bfb6-86efd3c27a77
ms.openlocfilehash: 62834c5f245bc1c0f6197638e4608b7fe71e7eb1
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50586024"
---
# <a name="command-line-warning-d9043"></a>Aviso D9043 (linha de comando)

valor inválido 'warning_level' para 'compiler_option'; Supondo que '4999'; Avisos da análise de código não estão associados com níveis de aviso

## <a name="example"></a>Exemplo

O exemplo a seguir gera C9043.

```
// D9043.cpp
// compile with: /analyze /w16001
// D9043 warning expected
int main() {}
```