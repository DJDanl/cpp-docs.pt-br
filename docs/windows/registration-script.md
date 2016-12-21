---
title: "registration_script | Microsoft Docs"
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
  - "vc-attr.registration_script"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "registration_script attribute"
ms.assetid: 786f8072-9187-4163-a979-7a604dd4c888
caps.latest.revision: 10
caps.handback.revision: 10
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# registration_script
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Executa o script de registro personalizado especificado.  
  
## Sintaxe  
  
```  
  
      [ registration_script(   
   script   
) ]  
```  
  
#### Parâmetros  
 *script*  
 O caminho completo para um arquivo de script \(. rgs\) de registro personalizadas.  Um valor de  **Nenhum**, como `script = "none"`, indica que o coclass não tem nenhum requisito de registro.  
  
## Comentários  
 O  **registration\_script** atributo C\+\+ executa o script de registro personalizado especificado pelo  **script**.  Se este atributo não for especificado, um arquivo. rgs padrão \(que contém informações para registrar o componente\) é usado.  Para obter mais informações sobre arquivos. rgs, consulte  [O componente de registro de ATL \(registrador\)](../atl/atl-registry-component-registrar.md).  
  
 Este atributo requer que o  [coclass](../windows/coclass.md),  [progid](../Topic/progid.md), ou  [vi\_progid](../windows/vi-progid.md) atributo \(ou outro atributo implica um deles\) também ser aplicadas ao mesmo elemento.  
  
## Exemplo  
 O código a seguir especifica que o componente tem um script de registro chamado cpp\_attr\_ref\_registration\_script.rgs.  
  
```  
// cpp_attr_ref_registration_script.cpp  
// compile with: /LD  
#define _ATL_ATTRIBUTES  
#include "atlbase.h"  
#include "atlcom.h"  
  
[module (name="REG")];  
  
[object, uuid("d9cd196b-6836-470b-9b9b-5b04b828e5b0")]  
__interface IFace {};  
  
// requires "cpp_attr_ref_registration_script.rgs"  
// create sample .RGS file "cpp_attr_ref_registration_script.rgs" if it does not exist  
[ coclass, registration_script(script="cpp_attr_ref_registration_script.rgs"),  
  uuid("50d3ad42-3601-4f26-8cfe-0f1f26f98f67")]  
class CMyClass:public IFace {};  
```  
  
## Requisitos  
  
### Contexto de atributo  
  
|||  
|-|-|  
|**Se aplica a**|**classe**,`struct`|  
|**Reproduzíveis**|Não|  
|**Atributos obrigatórios**|Um ou mais das seguintes opções:  **coclass**,  **progid**, ou  **vi\_progid**.|  
|**Atributos inválidos**|Nenhum|  
  
 Para obter mais informações sobre os contextos de atributo, consulte  [Atributo contextos](../windows/attribute-contexts.md).  
  
## Consulte também  
 [COM Attributes](../Topic/COM%20Attributes.md)   
 [Class Attributes](../windows/class-attributes.md)   
 [rdx](../windows/rdx.md)   
 [Attributes Samples](http://msdn.microsoft.com/pt-br/558ebdb2-082f-44dc-b442-d8d33bf7bdb8)