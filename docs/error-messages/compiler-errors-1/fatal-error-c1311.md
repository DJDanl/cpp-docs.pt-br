---
title: Erro fatal C1311
ms.date: 11/04/2016
f1_keywords:
- C1311
helpviewer_keywords:
- C1311
ms.assetid: 6590a06c-ce9d-4f17-8f62-c809343143b8
ms.openlocfilehash: ba2b797c9bf521533e7c2ccff8d358b6216d392f
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50637899"
---
# <a name="fatal-error-c1311"></a>Erro fatal C1311

Formato COFF estaticamente não é possível inicializar 'var' com número bytes de um endereço

Um endereço cujo valor não é conhecido em tempo de compilação não pode ser atribuído estaticamente a uma variável cujo tipo tem um armazenamento de menos de quatro bytes.

Esse erro pode ocorrer no código que não C++ válido.

O exemplo a seguir mostra uma condição que possa causar C1311.

```
char c = (char)"Hello, world";   // C1311
char *d = (char*)"Hello, world";   // OK
```