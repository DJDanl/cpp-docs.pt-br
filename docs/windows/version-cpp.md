---
title: "version (C++) | Microsoft Docs"
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
  - "vc-attr.version"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "version attribute"
  - "version information, version attribute"
ms.assetid: db6ce5d8-82c2-4329-b1a8-8ca2f67342cb
caps.latest.revision: 10
caps.handback.revision: 10
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# version (C++)
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Identifica uma versão específica entre várias versões de uma classe.  
  
## Sintaxe  
  
```  
  
      [ version(  
   "version"  
) ]  
```  
  
#### Parâmetros  
 *versão*  
 O número de versão do coclass.  Se não for especificado, será colocado no arquivo. idl 1.0.  
  
## Comentários  
 O  **versão** o atributo do C\+\+ tem a mesma funcionalidade que o  [versão](http://msdn.microsoft.com/library/windows/desktop/aa367306) atributo MIDL e é passada para o arquivo. idl gerado.  
  
## Exemplo  
 Consulte o  [vinculáveis](../windows/bindable.md) exemplo para um uso de amostra de  **versão**.  
  
## Requisitos  
  
### Contexto de atributo  
  
|||  
|-|-|  
|**Se aplica a**|**classe**,`struct`|  
|**Reproduzíveis**|Não|  
|**Atributos obrigatórios**|**coclass**|  
|**Atributos inválidos**|Nenhum|  
  
 Para obter mais informações sobre os contextos de atributo, consulte  [Atributo contextos](../windows/attribute-contexts.md).  
  
## Consulte também  
 [Compiler Attributes](../windows/compiler-attributes.md)   
 [Class Attributes](../windows/class-attributes.md)   
 [Attributes Samples](http://msdn.microsoft.com/pt-br/558ebdb2-082f-44dc-b442-d8d33bf7bdb8)