---
title: Aviso do compilador (nível 4) C4092
ms.date: 11/04/2016
f1_keywords:
- C4092
helpviewer_keywords:
- C4092
ms.assetid: 396ae826-a892-4327-bd66-f4762376d72b
ms.openlocfilehash: 675e6ccbc516734a405620aa74eaa04ff2f75087
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87219983"
---
# <a name="compiler-warning-level-4-c4092"></a>Aviso do compilador (nível 4) C4092

> sizeof retorna ' sem sinal Long '

O operando do **`sizeof`** operador era muito grande, portanto, **`sizeof`** retornou um **`unsigned long`** . Esse aviso ocorre sob as extensões da Microsoft ( [`/Ze`](../../build/reference/za-ze-disable-language-extensions.md) ). Em vez de compatibilidade com ANSI ( **`/Za`** ), o resultado é truncado.
