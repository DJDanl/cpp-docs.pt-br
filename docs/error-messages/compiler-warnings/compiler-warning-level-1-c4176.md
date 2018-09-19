---
title: Compilador aviso (nível 1) C4176 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C4176
dev_langs:
- C++
helpviewer_keywords:
- C4176
ms.assetid: cfffb934-219a-4a63-9df6-ba54405bf766
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: f173e132a2bd0d54c32fb0c2f7ae3b13dff1657d
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46085700"
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