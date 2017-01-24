---
title: "aggregates | Microsoft Docs"
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
  - "vc-attr.aggregates"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "atributo de agregações"
  - "agregação [C++]"
  - "objetos agregados [C++], atributo de agregações"
  - "agregações [C++]"
ms.assetid: 67a084c9-941f-474b-a029-9c93b38ebe9a
caps.latest.revision: 9
caps.handback.revision: 9
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# aggregates
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Indica que o objeto agrega o objeto especificado pelo CLSID.  
  
## Sintaxe  
  
```  
  
[ aggregates(  
clsid,  
variable_name  
) ]  
  
```  
  
#### Parâmetros  
 `clsid`  
 Especifica o CLSID do objeto agregável.  
  
 `variable_name`  
 O nome da variável deve ser inserido. Essa variável contém o **IUnknown** do objeto que está sendo agregado.  
  
## Comentários  
 Quando aplicado a um objeto, o **agregações** atributo C\+\+ implementa um wrapper externo para o objeto que está sendo agregado \(especificada por `clsid`\).  
  
 Este atributo requer que o [coclass](../windows/coclass.md), [progid](../Topic/progid.md), ou [vi\_progid](../windows/vi-progid.md) atributo \(ou outro atributo implica um desses\) também ser aplicada ao mesmo elemento. Se qualquer atributo único é usado, os outros dois serão aplicados automaticamente. Por exemplo, se **progid** é aplicado, **vi\_progid** e **coclass** também são aplicadas.  
  
 **Projetos ATL**  
  
 Se esse atributo for usado em um projeto que usa o ATL, altera o comportamento do atributo. Primeiro, a seguinte entrada é adicionada ao mapa de COM do objeto de destino:  
  
```  
COM_INTERFACE_ENTRY_AUTOAGGREGATE_BLIND(_m_spAttrXXX, clsid)  
```  
  
 Segundo, o [DECLARE\_GET\_CONTROLLING\_UNKNOWN](../Topic/DECLARE_GET_CONTROLLING_UNKNOWN.md) macro também é adicionada.  
  
## Exemplo  
  
```  
// cpp_attr_ref_aggregates.cpp  
// compile with: /LD  
#define _ATL_ATTRIBUTES  
#include "atlbase.h"  
#include "atlcom.h"  
  
// requires 'aggregatable.dll'  
// see aggregatable attribute to create 'aggregatable.dll'  
class DECLSPEC_UUID("1a8369cc-1c91-42c4-befa-5a5d8c9d2529") CMyClass;  
  
[module (name="MYObject")];  
[object, uuid("ab006d85-e754-47c5-9ef4-2744ff32a20c")]  
__interface IObject  
{  
};  
  
[ coclass, aggregates(__uuidof(CMyClass)),   
  uuid("91cb2c06-8931-432a-baac-206e55c4edfb")]  
struct CObject : IObject  
{  
   int i;  
};  
```  
  
## Requisitos  
  
### Contexto de atributo  
  
|||  
|-|-|  
|**Aplica\-se a**|**class**, `struct`|  
|**Repetível**|Sim|  
|**Atributos necessários**|Um ou mais dos seguintes: **coclass**, **progid**, ou **vi\_progid**.|  
|**Atributos inválidos**|Nenhum|  
  
 Para obter mais informações sobre os contextos de atributo, consulte [contextos de atributo](../windows/attribute-contexts.md).  
  
## Consulte também  
 [COM Attributes](../Topic/COM%20Attributes.md)   
 [Class Attributes](../windows/class-attributes.md)   
 [Typedef, Enum, Union, and Struct Attributes](../windows/typedef-enum-union-and-struct-attributes.md)   
 [Agregação](http://msdn.microsoft.com/library/windows/desktop/ms686558)   
 [Agregável](http://msdn.microsoft.com/library/windows/desktop/aa366721)   
 [COM\_INTERFACE\_ENTRY\_AUTOAGGREGATE\_BLIND](../Topic/COM_INTERFACE_ENTRY_AUTOAGGREGATE_BLIND.md)   
 [Attributes Samples](http://msdn.microsoft.com/pt-br/558ebdb2-082f-44dc-b442-d8d33bf7bdb8)