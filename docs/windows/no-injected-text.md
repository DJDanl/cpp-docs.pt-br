---
title: "no_injected_text | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "language-reference"
f1_keywords: 
  - "vc-attr.no_injected_text"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "no_injected_text attribute"
ms.assetid: 5256f808-e41e-4f4a-9ea5-e447919f5696
caps.latest.revision: 10
caps.handback.revision: 10
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# no_injected_text
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Impede que o compilador de injeção de código como resultado do uso do atributo.  
  
## Sintaxe  
  
```  
  
      [ no_injected_text(  
   boolean  
) ];  
```  
  
#### Parâmetros  
 `boolean`\(opcional\)  
 **True** se você não quiser que nenhum código injetado,  **false** para permitir que o código injetado.  **True** é o padrão.  
  
## Comentários  
 O uso mais comum da  **no\_injected\_text** atributo C\+\+ é o  [\/Fx](../build/reference/fx-merge-injected-code.md) opção de compilador, que insere o  **no\_injected\_text** atributo para o arquivo. mrg.  
  
## Requisitos  
  
### Contexto de atributo  
  
|||  
|-|-|  
|**Se aplica a**|Em qualquer lugar|  
|**Reproduzíveis**|Não|  
|**Atributos obrigatórios**|Nenhum|  
|**Atributos inválidos**|Nenhum|  
  
 Para obter mais informações sobre os contextos de atributo, consulte  [Atributo contextos](../windows/attribute-contexts.md).  
  
## Consulte também  
 [Compiler Attributes](../windows/compiler-attributes.md)   
 [Attributes Samples](http://msdn.microsoft.com/pt-br/558ebdb2-082f-44dc-b442-d8d33bf7bdb8)