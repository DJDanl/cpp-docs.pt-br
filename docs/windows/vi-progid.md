---
title: "vi_progid | Microsoft Docs"
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
  - "vc-attr.vi_progid"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "vi_progid attribute"
ms.assetid: a52449be-b93e-4111-b883-44bb8da53261
caps.latest.revision: 10
caps.handback.revision: 10
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# vi_progid
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Especifica um formulário independente de versão de ProgID.  
  
## Sintaxe  
  
```  
  
      [ vi_progid(  
   name  
) ];  
```  
  
#### Parâmetros  
 *name*  
 A versão de ProgID que representa o objeto.  
  
 ProgIDs apresente uma versão legível do identificador de classe \(CLSID\) usado para identificar objetos COM\/ActiveX.  
  
## Comentários  
 O  **vi\_progid** atributo C\+\+ permite que você especificar uma versão de ProgID para um objeto COM.  Um ProgID tem a forma  *Nome1*.*name2*.*version*.  Uma versão de ProgID não tem um  *versão*.  É possível especificar ambos os  **progid** e o  **vi\_progid** atributos em um coclass.  Se você não especificar  **vi\_progid**, a versão de ProgID é o valor especificado pelo  [progid](../Topic/progid.md) atributo.  
  
 **vi\_progid** implica a  **coclass** de atributo, ou seja, se você especificar  **vi\_progid**, é a mesma coisa que especificar o  **coclass** e  **vi\_progid** atributos.  
  
 O  **vi\_progid** atributo faz com que uma classe para ser registrado automaticamente sob o nome especificado.  O arquivo. idl gerado não exibirá o valor de ProgID.  
  
 Em projetos ATL, se o  [coclass](../windows/coclass.md) atributo também estiver presente, o ProgID especificado é usado pelo  **GetVersionIndependentProgID** função \(inserida pelo  **coclass** atributo\).  
  
## Exemplo  
 Consulte o  [coclass](../windows/coclass.md) exemplo para um uso de amostra de  **vi\_progid**.  
  
## Requisitos  
  
### Contexto de atributo  
  
|||  
|-|-|  
|**Se aplica a**|**classe**,`struct`|  
|**Reproduzíveis**|Não|  
|**Atributos obrigatórios**|Nenhum|  
|**Atributos inválidos**|Nenhum|  
  
 Para obter mais informações sobre os contextos de atributo, consulte  [Atributo contextos](../windows/attribute-contexts.md).  
  
## Consulte também  
 [IDL Attributes](../windows/idl-attributes.md)   
 [Typedef, Enum, Union, and Struct Attributes](../windows/typedef-enum-union-and-struct-attributes.md)   
 [Class Attributes](../windows/class-attributes.md)   
 [ProgID Key](http://msdn.microsoft.com/library/windows/desktop/dd542719)   
 [Attributes Samples](http://msdn.microsoft.com/pt-br/558ebdb2-082f-44dc-b442-d8d33bf7bdb8)