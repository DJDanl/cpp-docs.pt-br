---
title: 2.7.2.5 default
ms.date: 11/04/2016
ms.assetid: c856df07-705c-4ad3-9105-a268dd33e939
ms.openlocfilehash: efb10913b74ebfae37c95d057955c87bdcfca9a7
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50580190"
---
# <a name="2725-default"></a>2.7.2.5 default

O **padrão** cláusula permite que o usuário afetar os atributos de compartilhamento de dados de variáveis. A sintaxe do **padrão** cláusula é da seguinte maneira:

```
default(shared | none)
```

Especificando **default(shared)** é equivalente a listando explicitamente cada variável visível no momento em um **compartilhado** cláusula, a menos que ele seja **threadprivate** ou **contras**`t`-qualificado. Na ausência de um explícito **padrão** cláusula, o comportamento padrão é o mesmo que se **default(shared)** foram especificadas.

Especificando **default (none)** requer que pelo menos um dos seguintes deve ser verdadeiro para todas as referências a uma variável na extensão de léxico da construção paralela:

- A variável é listada explicitamente em uma cláusula de atributo de compartilhamento de dados de uma construção que contém a referência.

- A variável é declarada dentro a construção parallel.

- A variável está **threadprivate**.

- A variável tem um **const**-qualificado do tipo.

- A variável é a variável de controle de loop para um **para** loop que segue imediatamente uma **para** ou **paralela para** diretiva e a referência de variável é exibida dentro do loop .

Especificando uma variável em uma **firstprivate**, **lastprivate**, ou **redução** cláusula de uma diretiva incluída faz com que uma referência implícita a variável no fechamento contexto. Essas referências implícitas também estão sujeitos aos requisitos listados acima.

Um único **padrão** cláusula pode ser especificada em um **paralela** diretiva.

Padrão de uma variável atributo de compartilhamento de dados pode ser substituído usando o **privados**, **firstprivate**, **lastprivate**, **redução**, e **compartilhados** cláusulas, como demonstrado pelo exemplo a seguir:

```
#pragma  omp  parallel  for  default(shared)  firstprivate(i)\
   private(x)  private(r)  lastprivate(i)
```