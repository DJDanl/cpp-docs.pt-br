---
title: Aviso do compilador (nível 1) C4086
ms.date: 11/04/2016
f1_keywords:
- C4086
helpviewer_keywords:
- C4086
ms.assetid: 9248831b-22bf-47af-8684-bfadb17e94fc
ms.openlocfilehash: 596d70e08694b50b7aa6b743bce11f03a47df822
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80200142"
---
# <a name="compiler-warning-level-1-c4086"></a>Aviso do compilador (nível 1) C4086

esperado parâmetro de pragma como ' 1 ', ' 2 ', ' 4 ', ' 8 ' ou ' 16 '

O parâmetro pragma não tem o valor necessário (1, 2, 4, 8 ou 16).

## <a name="example"></a>Exemplo

```cpp
// C4086.cpp
// compile with: /W1 /LD
#pragma pack( 3 ) // C4086
```
