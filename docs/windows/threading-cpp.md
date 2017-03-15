---
title: "threading (C++) | Microsoft Docs"
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
  - "vc-attr.threading"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "threading attribute"
ms.assetid: 9b558cd6-fbf0-4602-aed5-31c068550ce3
caps.latest.revision: 10
caps.handback.revision: 10
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# threading (C++)
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Especifica o modelo de segmentação para um objeto COM.  
  
## Sintaxe  
  
```  
  
      [ threading(  
   model=enumeration  
) ]  
```  
  
#### Parâmetros  
 ***modelo*** \(opcional\)  
 Um dos seguintes modelos de segmentação:  
  
-   **apartamento** \(modelo apartment threading\)  
  
-   **neutro** \(.NET Framework components sem interface do usuário\)  
  
-   **único** \(threading simples\)  
  
-   **livre** \(free threading\)  
  
-   **ambos** \(apartamento e segmentação livre\)  
  
 O valor padrão é  **apartamento**.  
  
## Comentários  
 O  **threading** atributo C\+\+ não aparecer no arquivo. idl gerado, mas será usado na implementação do seu objeto COM.  
  
 Em projetos ATL, se o  [coclass](../windows/coclass.md) atributo também estiver presente, o modelo de threading especificado por  *modelo* é passado como o parâmetro de modelo para o  [CComObjectRootEx](../atl/reference/ccomobjectrootex-class.md) classe, inserida pelo  **coclass** atributo.  
  
 O  **threading** atributo também protege o acesso a uma  [event\_source](../windows/event-source.md).  
  
## Exemplo  
 Consulte o  [licenciado](../windows/licensed.md) exemplo para um uso de amostra de  **threading**.  
  
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
 [COM Attributes](../Topic/COM%20Attributes.md)   
 [Typedef, Enum, Union, and Struct Attributes](../windows/typedef-enum-union-and-struct-attributes.md)   
 [Class Attributes](../windows/class-attributes.md)   
 [Suporte multithread para código anterior \(Visual C\+\+\)](../parallel/multithreading-support-for-older-code-visual-cpp.md)   
 [Neutral Apartments](http://msdn.microsoft.com/library/windows/desktop/ms681813)   
 [Attributes Samples](http://msdn.microsoft.com/pt-br/558ebdb2-082f-44dc-b442-d8d33bf7bdb8)