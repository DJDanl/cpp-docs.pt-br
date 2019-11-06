---
title: Aviso do compilador (nível 1) C4176
ms.date: 11/04/2016
f1_keywords:
- C4176
helpviewer_keywords:
- C4176
ms.assetid: cfffb934-219a-4a63-9df6-ba54405bf766
ms.openlocfilehash: 6e0f7ab75309994ab306f5caed54724f32e388b1
ms.sourcegitcommit: 0cfc43f90a6cc8b97b24c42efcf5fb9c18762a42
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 11/05/2019
ms.locfileid: "73624798"
---
# <a name="compiler-warning-level-1-c4176"></a>Aviso do compilador (nível 1) C4176

' subcomponente ': subcomponente desconhecido para #pragma navegador de componentes

O **componente** pragma contém um subcomponente inválido. Para excluir referências a um nome específico, você deve usar a opção **References** antes do nome.

## <a name="example"></a>Exemplo

```cpp
// C4176.cpp
// compile with: /W1 /LD
#pragma component(browser, off, i)  // C4176
#pragma component(browser, off, references, i) // ok
```