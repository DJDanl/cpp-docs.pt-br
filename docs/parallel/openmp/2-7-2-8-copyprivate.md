---
title: 2.7.2.8 copyprivate | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-parallel
ms.topic: conceptual
dev_langs:
- C++
ms.assetid: c382348c-c785-45b2-8ee6-a66b76b97f3e
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: c809f297da5059a98915e8055dfe23f45074366f
ms.sourcegitcommit: 7019081488f68abdd5b2935a3b36e2a5e8c571f8
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/07/2018
---
# <a name="2728-copyprivate"></a>2.7.2.8 copyprivate
O **copyprivate** cláusula fornece um mecanismo para usar uma variável privada para transmitir um valor de um membro de uma equipe para os outros membros. É uma alternativa ao uso de uma variável compartilhada para o valor ao fornecer essa variável compartilhada seria difícil (por exemplo, em uma recursão de necessidade de uma variável diferente em cada nível). O **copyprivate** cláusula só pode aparecer no **único** diretiva.  
  
 A sintaxe do **copyprivate** cláusula é o seguinte:  
  
```  
  
copyprivate(  
variable-list  
)  
  
```  
  
 O efeito do **copyprivate** cláusula nas variáveis na lista de variável ocorre após a execução do bloco estruturado associado a **único** construir e antes de qualquer um dos segmentos do equipe deixaram a barreira no final da construção. Em seguida, em todos os outros threads da equipe, para cada variável no *lista variável*, essa variável torna-se definida (como se por atribuição) com o valor correspondente variável no thread que executou a construção do estruturado bloco.  
  
 Restrições para o **copyprivate** cláusula são da seguinte maneira:  
  
-   Uma variável que é especificada no **copyprivate** cláusula não deve aparecer em uma **privada** ou **firstprivate** cláusula para o mesmo **único**diretiva.  
  
-   Se um **único** diretiva com um **copyprivate** cláusula for encontrada na extensão dinâmica de uma região parallel, todas as variáveis especificadas no **copyprivate** cláusula deve ser privado no contexto de delimitador.  
  
-   Uma variável que é especificada no **copyprivate** cláusula deve ter um operador de atribuição de cópia não ambígua acessível.