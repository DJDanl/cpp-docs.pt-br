---
title: Erro fatal C1311 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C1311
dev_langs:
- C++
helpviewer_keywords:
- C1311
ms.assetid: 6590a06c-ce9d-4f17-8f62-c809343143b8
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: d93aa28d0cef3c07fd469349d485c4009fa4771d
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46091056"
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