---
title: Compilador aviso (nível 1) C4176
ms.date: 11/04/2016
f1_keywords:
- C4176
helpviewer_keywords:
- C4176
ms.assetid: cfffb934-219a-4a63-9df6-ba54405bf766
ms.openlocfilehash: 44f2dea9b5f0afb5b97867f9137f420ad92c388a
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50443115"
---
# <a name="compiler-warning-level-1-c4176"></a>Compilador aviso (nível 1) C4176

'subcomponente': subcomponente desconhecido para o navegador de componentes #pragma

O **componente** pragma contém um subcomponente inválido. Para excluir as referências a um nome específico, você deve usar o **referências** opção antes do nome.

## <a name="example"></a>Exemplo

```
// C4176.cpp
// compile with: /W1 /LD
#pragma component(browser, off, i)  // C4176
#pragma component(browser, off, references, i) // ok
```