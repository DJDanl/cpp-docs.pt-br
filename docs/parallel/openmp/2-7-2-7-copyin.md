---
title: 2.7.2.7 copyin | Microsoft Docs
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
ms.assetid: 76cfb9f8-bf65-4585-adbf-fd933f5606b4
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 5ba09b70b3a3591b1f8b427ac107576cfcac7935
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="2727-copyin"></a>2.7.2.7 copyin
O **copyin** cláusula fornece um mecanismo para atribuir o mesmo valor para **threadprivate** variáveis para cada thread na equipe de região paralela em execução. Para cada variável especificada em uma **copyin** cláusula, o valor da variável no thread principal da equipe é copiada, como se fosse pela atribuição nas cópias de thread privado no início da região de dados paralela. A sintaxe do **copyin** cláusula é o seguinte:  
  
```  
  
copyin(  
variable-list  
)  
  
```  
  
 As restrições para o **copyin** cláusula são da seguinte maneira:  
  
-   Uma variável que é especificada no **copyin** cláusula deve ter um operador de atribuição de cópia não ambígua acessível.  
  
-   Uma variável que é especificada no **copyin** cláusula deve ser um **threadprivate** variável.