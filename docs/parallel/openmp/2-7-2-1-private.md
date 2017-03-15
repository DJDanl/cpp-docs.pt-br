---
title: "2.7.2.1 private | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
dev_langs: 
  - "C++"
ms.assetid: 079b4b84-f2b3-4050-a0ac-289493c36b3d
caps.latest.revision: 6
caps.handback.revision: 6
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# 2.7.2.1 private
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

O `private` cláusula declara as variáveis na lista de variável ser particulares para cada segmento de uma equipe.  A sintaxe do `private` cláusula é da seguinte maneira:  
  
```  
private(variable-list)  
```  
  
 O comportamento de uma variável especificado em um `private` cláusula é da seguinte maneira.  Um novo objeto com duração de armazenamento automático é alocado para a construção.  O tamanho e o alinhamento do novo objeto são determinados pelo tipo da variável.  Essa alocação ocorre uma vez para cada segmento na equipe e um construtor padrão é invocado para um objeto de classe, se necessário. Caso contrário, o valor inicial é indeterminado.  O objeto original referido pela variável tem um valor indeterminado na entrada para a construção, não deve ser modificado dentro da extensão dinâmica a construção e tem um valor indeterminado ao sair da construção.  
  
 Na extensão da diretiva construção lexical, a variável referencia o novo objeto particular alocado pelo thread.  
  
 As restrições para o `private` cláusula são os seguintes:  
  
-   Uma variável com um tipo de classe é especificado em um `private` cláusula deve ter um construtor padrão acessível e objetiva.  
  
-   Uma variável especificada em um `private` cláusula não deve ter um  **const**\-qualificado tipo, a menos que tenha uma classe de tipo com uma `mutable` membro.  
  
-   Uma variável especificada em um `private` cláusula não deve ter um tipo incompleto ou um tipo de referência.  
  
-   Variáveis que aparecem a `reduction` cláusula de um  **paralela** diretiva não pode ser especificada um `private` cláusula em uma diretiva de compartilhamento de trabalho que vincula a construção parallel.