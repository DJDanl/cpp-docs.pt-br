---
title: 2.7.2.3 lastprivate
ms.date: 11/04/2016
ms.assetid: 77f6a5c9-704f-4a88-8476-29db852ed800
ms.openlocfilehash: 15f9af23c4f4e1c0ce2914a979f7a41e7b4a6bc1
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50428451"
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