---
title: 2.7.2.8 copyprivate | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
dev_langs: C++
ms.assetid: c382348c-c785-45b2-8ee6-a66b76b97f3e
caps.latest.revision: "5"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.openlocfilehash: 3dee6fb7423ba9245c1b52a8aa7b90a14d52cc9e
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
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