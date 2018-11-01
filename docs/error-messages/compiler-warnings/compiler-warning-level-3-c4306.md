---
title: Compilador aviso (nível 3) C4306
ms.date: 08/27/2018
f1_keywords:
- C4306
helpviewer_keywords:
- C4306
ms.assetid: 5b2192d7-402d-4b6d-8619-08105e7dcac7
ms.openlocfilehash: 78ec291b555838b1af63287e3d24fdb809afd7c4
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50582020"
---
# <a name="compiler-warning-level-3-c4306"></a>Compilador aviso (nível 3) C4306

> '*identificador*': conversão de '*type1*'para'*type2*' de tamanho maior

O identificador é o tipo convertido para um ponteiro maior. Os bits altos não preenchidos do novo tipo serão preenchidos com zeros.

Esse aviso pode indicar uma conversão indesejada. O ponteiro resultante pode não ser válido.