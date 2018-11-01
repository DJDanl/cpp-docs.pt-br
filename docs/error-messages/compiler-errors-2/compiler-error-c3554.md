---
title: Erro do compilador C3554
ms.date: 11/04/2016
f1_keywords:
- C3554
helpviewer_keywords:
- C3554
ms.assetid: aede18d5-fefc-4da9-9b69-adfe90bfa742
ms.openlocfilehash: 8bc9c465d16aea4714916fa6aa2942eb81c19015
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50582293"
---
# <a name="compiler-error-c3554"></a>Erro do compilador C3554

'decltype' não pode ser combinado com qualquer outro especificador de tipo

Você não pode qualificar o `decltype()` palavra-chave com qualquer especificador de tipo. Por exemplo, o fragmento de código a seguir produz o erro C3554.

```
int x;
unsigned decltype(x); // C3554
```