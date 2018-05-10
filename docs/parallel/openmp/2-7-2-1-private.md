---
title: 2.7.2.1 privada | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-parallel
ms.topic: conceptual
dev_langs:
- C++
ms.assetid: 079b4b84-f2b3-4050-a0ac-289493c36b3d
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 25ada9c89243ccc23201eb1939337068e77263c7
ms.sourcegitcommit: 7019081488f68abdd5b2935a3b36e2a5e8c571f8
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/07/2018
---
# <a name="2721-private"></a>2.7.2.1 private
O `private` cláusula declara as variáveis na lista de variável para ser privados para cada thread em uma equipe. A sintaxe de `private` cláusula é o seguinte:  
  
```  
private(variable-list)  
```  
  
 O comportamento de uma variável especificada em um `private` cláusula é da seguinte maneira. Um novo objeto com duração de armazenamento automática é alocado para a construção. O tamanho e o alinhamento do novo objeto são determinados pelo tipo da variável. Essa alocação ocorre uma vez para cada thread na equipe, e um construtor padrão é invocado para um objeto de classe, se necessário; Caso contrário, o valor inicial é indeterminado.  Referenciado pela variável de objeto original tem um valor indeterminado durante a entrada para a construção, não deve ser modificado dentro a extensão dinâmica da construção e tem um valor indeterminado ao sair de construção.  
  
 Na extensão de léxica de construção de diretiva, a variável referenciar o novo objeto particular alocado pelo thread.  
  
 As restrições para o `private` cláusula são da seguinte maneira:  
  
-   Uma variável com um tipo de classe especificado em um `private` cláusula deve ter um construtor padrão não ambígua, acessível.  
  
-   Uma variável especificada em uma `private` cláusula não deve ter um **const**-qualificado tipo, a menos que ele tem uma classe de tipo com um `mutable` membro.  
  
-   Uma variável especificada em um `private` cláusula não deve ter um tipo incompleto ou um tipo de referência.  
  
-   Variáveis que aparecem no `reduction` cláusula de um **paralela** diretiva não pode ser especificada um `private` cláusula em uma diretiva de compartilhamento de trabalho que vincula-se para a construção paralela.