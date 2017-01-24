---
title: "uuid (C++ Attributes) | Microsoft Docs"
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
  - "vc-attr.uuid"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "uuid attribute"
ms.assetid: 90562a94-5e28-451b-a4b0-cadda7f66efe
caps.latest.revision: 11
caps.handback.revision: 11
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# uuid (C++ Attributes)
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Especifica a identificação exclusiva de uma classe ou interface.  
  
## Sintaxe  
  
```  
  
      [ uuid(  
   "uuid"  
) ]  
```  
  
#### Parâmetros  
 *UUID*  
 Um identificador exclusivo, de 128 bits.  
  
## Comentários  
 Se a definição de uma interface ou classe não especifica o `uuid` o atributo de C\+\+, em seguida, o compilador Visual C\+\+ apresentará um.  Quando você especifica um `uuid`, você deve incluir as aspas.  
  
 Se você não especificar `uuid`, e em seguida, o compilador irá gerar o mesmo GUID para interfaces ou classes com o mesmo nome em projetos diferentes do atributo em uma máquina.  
  
 Você pode usar o Uuidgen. exe ou Guidgen para gerar suas próprias identificações exclusivas.  \(Para executar essas ferramentas, clique em  **Iniciar** e clique em  **Executar** no menu.  Em seguida, digite o nome da ferramenta necessária.\)  
  
 Quando usado em um projeto que também não usar a ATL, especificando a `uuid` atributo é o mesmo que especificar o  [uuid](../cpp/uuid-cpp.md) \_\_declspec modificador.  Para recuperar o `uuid` de uma classe, você pode usar  [\_\_uuidof](../cpp/uuidof-operator.md)  
  
## Exemplo  
 Consulte o  [vinculáveis](../windows/bindable.md) exemplo para um uso de amostra de `uuid`.  
  
## Requisitos  
  
### Contexto de atributo  
  
|||  
|-|-|  
|**Se aplica a**|**class**, `struct`, `interface`, **union**,`enum`|  
|**Reproduzíveis**|Não|  
|**Atributos obrigatórios**|Nenhum|  
|**Atributos inválidos**|Nenhum|  
  
 Para obter mais informações sobre os contextos de atributo, consulte  [Atributo contextos](../windows/attribute-contexts.md).  
  
## Consulte também  
 [IDL Attributes](../windows/idl-attributes.md)   
 [Interface Attributes](../windows/interface-attributes.md)   
 [Class Attributes](../windows/class-attributes.md)   
 [Typedef, Enum, Union, and Struct Attributes](../windows/typedef-enum-union-and-struct-attributes.md)   
 [uuid](http://msdn.microsoft.com/library/windows/desktop/aa367302)   
 [Attributes Samples](http://msdn.microsoft.com/pt-br/558ebdb2-082f-44dc-b442-d8d33bf7bdb8)