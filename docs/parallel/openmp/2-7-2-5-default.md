---
title: "2.7.2.5 padrão de | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
dev_langs:
- C++
ms.assetid: c856df07-705c-4ad3-9105-a268dd33e939
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 1ee328be7f9f0c4876738f8179c26e700c57702c
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
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