---
title: 2.7.2.7 copyin | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-parallel
ms.topic: conceptual
dev_langs:
- C++
ms.assetid: 76cfb9f8-bf65-4585-adbf-fd933f5606b4
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 94b4c529b7ad6fd717be1e1dee0edd3ff9ac3ff5
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46426881"
---
# <a name="2727-copyin"></a>2.7.2.7 copyin

O **copyin** cláusula fornece um mecanismo para atribuir o mesmo valor para **threadprivate** variáveis para cada thread em que a equipe a região paralela em execução. Para cada variável especificada em uma **copyin** cláusula, o valor da variável no thread principal da equipe é copiada, como se por atribuição às cópias privadas de thread no início da região paralela. A sintaxe do **copyin** cláusula é da seguinte maneira:

```

copyin(
variable-list
)

```

As restrições para o **copyin** cláusula são da seguinte maneira:

- Uma variável que é especificada na **copyin** cláusula deve ter um operador de atribuição de cópia acessível inequívoca.

- Uma variável que é especificada na **copyin** cláusula deve ser um **threadprivate** variável.