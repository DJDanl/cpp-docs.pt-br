---
title: Erro fatal C1311
ms.date: 11/04/2016
f1_keywords:
- C1311
helpviewer_keywords:
- C1311
ms.assetid: 6590a06c-ce9d-4f17-8f62-c809343143b8
ms.openlocfilehash: ba2b797c9bf521533e7c2ccff8d358b6216d392f
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62266460"
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