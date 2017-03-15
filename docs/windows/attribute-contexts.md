---
title: "Attribute Contexts | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "language-reference"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "attributes [C++], contexts"
ms.assetid: 3086351f-77a8-4048-99e9-3b6b041b9437
caps.latest.revision: 8
caps.handback.revision: 8
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Attribute Contexts
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Atributos de C\+\+ podem ser descritos usando quatro campos básicos: o destino, elas podem ser aplicadas a \(**Aplica\-se a**\), se elas são passíveis de repetição ou não \(**Repeatable**\), o necessário a presença de outros atributos \(**Atributos necessários**\) e incompatibilidades com outros atributos \(**Atributos inválidos**\).  Esses campos são listados em uma tabela que o acompanha no tópico de referência de cada atributo.  Cada um desses campos é descrita abaixo.  
  
## Aplicável a  
 Este campo descreve os diferentes elementos de linguagem C\+\+ que são alvos legais para o atributo especificado.  Por exemplo, se um atributo especifica "class" no  **Aplica\-se a** campo, isso indica que o atributo só pode ser aplicado a uma classe do C\+\+ legal.  Se o atributo é aplicado a uma função de membro de uma classe, um erro de sintaxe resultaria.  
  
 Para obter mais informações, consulte  [atributos por uso de](../windows/attributes-by-usage.md).  
  
## Reproduzíveis  
 Este campo informa se o atributo pode ser aplicado várias vezes para o mesmo destino.  A maioria dos atributos não são reproduzidos.  
  
## Atributos obrigatórios  
 Esse campo lista outros atributos que precisam estar presente \(ou seja, aplicada para o mesmo destino\) para o atributo especificado funcionar corretamente.  É raro que um atributo para que todas as entradas para esse campo.  
  
## Atributos inválidos  
 Esse campo lista outros atributos que são incompatíveis com o atributo especificado.  É raro que um atributo para que todas as entradas para esse campo.  
  
## Consulte também  
 [C\+\+ Attributes Reference](../windows/cpp-attributes-reference.md)