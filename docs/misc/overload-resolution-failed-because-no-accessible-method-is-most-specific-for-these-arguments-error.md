---
title: "Resolu&#231;&#227;o sobrecarregada falhou porque nenhum &#39;&lt; m&#233;todo acess&#237;vel &gt;&#39; &#233; o mais espec&#237;fico para estes argumentos: &lt; erro &gt; | Microsoft Docs"
ms.custom: ""
ms.date: "11/17/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-visual-basic"
ms.tgt_pltfrm: ""
ms.topic: "article"
f1_keywords: 
  - "bc30521"
  - "vbc30521"
helpviewer_keywords: 
  - "Falha de resolução"
  - "BC30521"
  - "Falha na resolução de sobrecarga"
ms.assetid: b8b41fa0-a64b-4e74-8443-be3afd2b6f11
caps.latest.revision: 9
caps.handback.revision: 9
author: "stevehoag"
ms.author: "shoag"
manager: "wpickett"
---
# Resolu&#231;&#227;o sobrecarregada falhou porque nenhum &#39;&lt; m&#233;todo acess&#237;vel &gt;&#39; &#233; o mais espec&#237;fico para estes argumentos: &lt; erro &gt;
Você fez uma chamada para um método sobrecarregado, mas o compilador encontrou duas ou mais sobrecargas com listas de parâmetros para o qual a lista de argumentos pode ser convertida e ela não pode selecioná\-las.  
  
 O compilador tenta corresponder ao máximo os tipos de dados na lista de argumentos de chamada e a lista de parâmetros de sobrecarga. Ele requer uma conversão de ampliação de cada um de seus argumentos para o seu parâmetro correspondente, se a opção de verificação de tipo \([Instrução Option Strict](../Topic/Option%20Strict%20Statement.md)\) é `On` ou `Off`.  
  
 Se o compilador encontrar mais de uma sobrecarga que satisfaça o requisito de ampliação, em seguida, procura a sobrecarga que é mais específica para os tipos de dados de argumento, ou seja, que chama o mínimo de ampliação. Ele gera essa mensagem de erro quando uma sobrecarga é mais específica para o tipo de dados de um argumento enquanto outra sobrecarga é mais específica para o tipo de dados do outro argumento. Para obter mais informações e um exemplo, consulte [Resolução de sobrecarga](../Topic/Overload%20Resolution%20\(Visual%20Basic\).md).  
  
 **ID do erro:** BC30521  
  
### Para corrigir este erro  
  
1.  Examine todas as sobrecargas do método e determinar qual deles você deseja chamar.  
  
2.  Na sua declaração de chamada, verifique os tipos de dados dos argumentos correspondem aos tipos de dados dos parâmetros definidos para a sobrecarga desejada. Talvez você precise usar o [Função CType](../Topic/CType%20Function%20\(Visual%20Basic\).md) para converter um ou mais tipos de dados para os tipos definidos.  
  
## Consulte também  
 [Sobrecarga de procedimento](../Topic/Procedure%20Overloading%20\(Visual%20Basic\).md)   
 [Considerações sobre procedimentos de sobrecarga](../Topic/Considerations%20in%20Overloading%20Procedures%20\(Visual%20Basic\).md)   
 [Resolução de sobrecarga](../Topic/Overload%20Resolution%20\(Visual%20Basic\).md)   
 [Sobrecargas](../Topic/Overloads%20\(Visual%20Basic\).md)   
 [Propriedades e métodos sobrecarregados](../Topic/Overloaded%20Properties%20and%20Methods%20\(Visual%20Basic\).md)   
 [Instrução Option Strict](../Topic/Option%20Strict%20Statement.md)   
 [Função CType](../Topic/CType%20Function%20\(Visual%20Basic\).md)