---
title: 2.7.2.3 lastprivate | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-parallel
ms.topic: conceptual
dev_langs:
- C++
ms.assetid: 77f6a5c9-704f-4a88-8476-29db852ed800
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 25edca8391eb094691ef4fea3c360d351f979b43
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46385957"
---
# <a name="2723-lastprivate"></a>2.7.2.3 lastprivate

O `lastprivate` cláusula fornece um superconjunto da funcionalidade fornecida pelo `private` cláusula. A sintaxe do `lastprivate` cláusula é da seguinte maneira:

```
lastprivate(variable-list)
```

As variáveis especificadas na *variável-list* ter `private` semântica de cláusula. Quando um `lastprivate` cláusula é exibida sobre a diretiva que identifica uma construção de compartilhamento de trabalho, o valor de cada `lastprivate` variável de sequencialmente última iteração de loop associado ou lexicalmente última diretiva de seção, é atribuído à objeto de original da variável. Variáveis que não são atribuídos um valor pela última iteração do **para** ou **paralela para**, ou por lexicalmente última seção a **seções** ou  **seções em paralelo** diretiva, têm valores indeterminados após a construção. Não atribuídos subobjetos também tem um valor de indeterminado após a construção.

As restrições para o `lastprivate` cláusula são da seguinte maneira:

- Todas as restrições para `private` se aplicam.

- Uma variável com um tipo de classe que é especificado como `lastprivate` deve ter um operador de atribuição de cópia acessível inequívoca.

- Variáveis que são particulares dentro de uma região paralela ou que aparecem na `reduction` cláusula de uma **paralela** diretiva não pode ser especificada em uma `lastprivate` cláusula em uma diretiva de compartilhamento de trabalho que está associado a construção parallel.