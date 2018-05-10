---
title: 2.7.2.5 padrão de | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-parallel
ms.topic: conceptual
dev_langs:
- C++
ms.assetid: c856df07-705c-4ad3-9105-a268dd33e939
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: c054c7f0ac7d1d73768d84613524afc979fecaa5
ms.sourcegitcommit: 7019081488f68abdd5b2935a3b36e2a5e8c571f8
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/07/2018
---
# <a name="2725-default"></a>2.7.2.5 default
O **padrão** cláusula permite que o usuário afetar os atributos de compartilhamento de dados de variáveis. A sintaxe do **padrão** cláusula é o seguinte:  
  
```  
default(shared | none)  
```  
  
 Especificando **default(shared)** é equivalente a listagem explícita de cada variável visível no momento em um **compartilhado** cláusula, a menos que ele seja **threadprivate** ou **contras**`t`-qualificado. Na ausência de uma explícita **padrão** cláusula, o comportamento padrão é o mesmo que se **default(shared)** foram especificadas.  
  
 Especificando **default (none)** requer que pelo menos um dos seguintes deve ser verdadeiro para todas as referências a uma variável na extensão de léxica da construção paralela:  
  
-   A variável é listada explicitamente em uma cláusula de atributo de compartilhamento de dados de uma construção que contém a referência.  
  
-   A variável é declarada dentro da construção paralela.  
  
-   A variável é **threadprivate**.  
  
-   A variável tiver um **const**-qualificado do tipo.  
  
-   A variável é a variável de controle de loop for para um **para** loop que segue imediatamente um **para** ou **paralelo para** diretiva e a referência de variável é exibido dentro do loop .  
  
 Especificando uma variável em uma **firstprivate**, **lastprivate**, ou **redução** cláusula de uma diretiva anexada faz com que uma referência implícita para a variável de circunscrição contexto. Essas referências implícita também estão sujeitos aos requisitos listados acima.  
  
 Um único **padrão** cláusula pode ser especificada em uma **paralela** diretiva.  
  
 Padrão de uma variável atributo de compartilhamento de dados pode ser substituído usando o **privada**, **firstprivate**, **lastprivate**, **redução**, e **compartilhado** cláusulas, como demonstrado pelo exemplo a seguir:  
  
```  
#pragma  omp  parallel  for  default(shared)  firstprivate(i)\  
   private(x)  private(r)  lastprivate(i)  
```