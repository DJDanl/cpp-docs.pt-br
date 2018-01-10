---
title: 2.7.2.3 lastprivate | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
dev_langs: C++
ms.assetid: 77f6a5c9-704f-4a88-8476-29db852ed800
caps.latest.revision: "6"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 5caf9d870dce301c6055dcb55418b3dbbc3e741f
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="2723-lastprivate"></a>2.7.2.3 lastprivate
O `lastprivate` cláusula fornece um subconjunto da funcionalidade fornecida pelo `private` cláusula. A sintaxe de `lastprivate` cláusula é o seguinte:  
  
```  
lastprivate(variable-list)  
```  
  
 Variáveis especificadas no *lista variável* ter `private` semântica de cláusula. Quando um `lastprivate` cláusula aparece na diretiva que identifica uma construção de compartilhamento de trabalho, o valor de cada `lastprivate` variável de sequência última iteração do loop associado ou a diretiva de seção lexicalmente última é atribuído para o objeto de original da variável. Variáveis que não estão atribuídos a um valor pela última iteração do **para** ou **paralelo para**, ou por lexicalmente última seção a **seções** ou  **paralelo seções** diretiva, têm valores após a construção. Não atribuídos subobjetos também tem um valor de indeterminado após a construção.  
  
 As restrições para o `lastprivate` cláusula são da seguinte maneira:  
  
-   Todas as restrições para `private` se aplicam.  
  
-   Uma variável com um tipo de classe que é especificado como `lastprivate` deve ter um operador de atribuição de cópia não ambígua acessível.  
  
-   Variáveis que são particulares dentro de uma região parallel ou que aparecem no `reduction` cláusula de um **paralela** diretiva não pode ser especificada um `lastprivate` cláusula em uma diretiva de compartilhamento de trabalho que vincula-se para a construção paralela.