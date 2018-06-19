---
title: 2.7.2.7 copyin | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-parallel
ms.topic: conceptual
dev_langs:
- C++
ms.assetid: 76cfb9f8-bf65-4585-adbf-fd933f5606b4
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 7ee711bfb24e7a2a1cbada1a7e01a243e204f4a8
ms.sourcegitcommit: 7019081488f68abdd5b2935a3b36e2a5e8c571f8
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/07/2018
ms.locfileid: "33689370"
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