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
ms.openlocfilehash: 6b8e44ca52ba1f76d5b3791a1d08301bf06e7eab
ms.sourcegitcommit: 7019081488f68abdd5b2935a3b36e2a5e8c571f8
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/07/2018
---
# <a name="2722-firstprivate"></a>2.7.2.2 firstprivate
O **firstprivate** cláusula fornece um subconjunto da funcionalidade fornecida pelo **privada** cláusula. A sintaxe do **firstprivate** cláusula é o seguinte:  
  
```  
firstprivate(variable-list)  
```  
  
 Variáveis especificadas no *lista variável* ter **privada** semântica de cláusula, conforme descrito em [seção 2.7.2.1](../../parallel/openmp/2-7-2-1-private.md) na página 25. A inicialização ou a construção ocorre como se foi feita uma vez por thread, antes da execução do thread da construção. Para uma **firstprivate** cláusula em uma construção paralela, o valor inicial do novo objeto particular é o valor do objeto original que existe imediatamente antes da construção paralela para o thread que encontra. Para uma **firstprivate** cláusula em uma construção de compartilhamento de trabalho, o valor inicial do novo objeto particular para cada thread que executa a construção de compartilhamento de trabalho é o valor do objeto original que existe antes do ponto no tempo que o mesmo thread encontra a construção de compartilhamento de trabalho. Além disso, para objetos C++, o novo objeto particular para cada thread é construída a partir do objeto original de cópia.  
  
 As restrições para o **firstprivate** cláusula são da seguinte maneira:  
  
-   Uma variável especificada em uma **firstprivate** cláusula não deve ter um tipo incompleto ou um tipo de referência.  
  
-   Uma variável com um tipo de classe que é especificado como **firstprivate** deve ter um construtor de cópia não ambígua acessível.  
  
-   Variáveis que são particulares dentro de uma região parallel ou que aparecem no **redução** cláusula de um **paralela** diretiva não pode ser especificada em uma **firstprivate** cláusula em uma compartilhamento de trabalho diretiva que vincula-se para a construção paralela.