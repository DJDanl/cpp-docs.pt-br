---
title: 2.7.2.2 firstprivate | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-parallel
ms.topic: conceptual
dev_langs:
- C++
ms.assetid: ece6ff12-2be1-4e4f-866c-d39345fd87b5
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 0d3e6ad966f4cf895da9374798f6c9a4079ccc2f
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46400959"
---
# <a name="2722-firstprivate"></a>2.7.2.2 firstprivate

O **firstprivate** cláusula fornece um superconjunto da funcionalidade fornecida pelo **privada** cláusula. A sintaxe do **firstprivate** cláusula é da seguinte maneira:

```
firstprivate(variable-list)
```

As variáveis especificadas no *variável-list* têm **privada** semântica de cláusula, conforme descrito na [seção 2.7.2.1](../../parallel/openmp/2-7-2-1-private.md) na página 25. A inicialização ou na construção ocorre como se ele foi feito uma vez por thread, antes da execução do thread da construção. Para um **firstprivate** cláusula em uma construção paralela, o valor inicial do novo objeto privado é o valor do objeto original que existe imediatamente antes da construção paralela para o thread que encontra. Para um **firstprivate** cláusula em uma construção de compartilhamento de trabalho, o valor inicial do novo objeto privado para cada thread que executa a construção de compartilhamento de trabalho é o valor do objeto original que existe antes do ponto no tempo que o mesmo thread encontra a construção de compartilhamento de trabalho. Além disso, para objetos de C++, o novo objeto privado para cada thread é cópia criada do objeto original.

As restrições para o **firstprivate** cláusula são da seguinte maneira:

- Uma variável especificada em uma **firstprivate** cláusula não deve ter um tipo incompleto ou um tipo de referência.

- Uma variável com um tipo de classe que é especificado como **firstprivate** devem ter um construtor de cópia acessível inequívoca.

- Variáveis que são particulares dentro de uma região paralela ou que aparecem na **redução** cláusula de uma **paralela** diretiva não pode ser especificada em um **firstprivate** cláusula em uma compartilhamento de trabalho diretiva que vincula-se para a construção parallel.