---
title: 2.7.2.8 copyprivate
ms.date: 11/04/2016
ms.assetid: c382348c-c785-45b2-8ee6-a66b76b97f3e
ms.openlocfilehash: d4df1b4216014d3cd15be1480d2f83334fddb72d
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50622905"
---
# <a name="2728-copyprivate"></a>2.7.2.8 copyprivate

O **copyprivate** cláusula fornece um mecanismo para usar uma variável particular para transmitir um valor de um membro de uma equipe para os outros membros. É uma alternativa ao uso de uma variável compartilhada para o valor ao fornecimento de uma variável compartilhada como seria difícil (por exemplo, em uma necessidade de uma variável diferente em cada nível de recursão). O **copyprivate** cláusula só pode aparecer na **único** diretiva.

A sintaxe do **copyprivate** cláusula é da seguinte maneira:

```

copyprivate(
variable-list
)

```

O efeito do **copyprivate** cláusula nas variáveis em sua lista de variável ocorre após a execução do bloco estruturado associado com o **único** construir e antes de qualquer um dos threads no equipe tenha deixado a barreira no final da construção. Em seguida, em todos os outros threads da equipe, para cada variável na *lista variável*, essa variável se torna definida (como se por atribuição) com o valor da variável no thread que executou a construção do estruturado bloco.

Restrições para o **copyprivate** cláusula são da seguinte maneira:

- Uma variável que é especificada na **copyprivate** cláusula não pode aparecer em uma **privada** ou **firstprivate** cláusula para o mesmo **único**diretiva.

- Se um **única** diretiva com um **copyprivate** cláusula for encontrada na extensão dinâmica de uma região paralela, todas as variáveis especificadas no **copyprivate** cláusula deve ser Private em contexto delimitador.

- Uma variável que é especificada na **copyprivate** cláusula deve ter um operador de atribuição de cópia não ambígua acessível.