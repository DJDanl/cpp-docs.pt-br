---
title: "agregações | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: language-reference
f1_keywords: vc-attr.aggregates
dev_langs: C++
helpviewer_keywords:
- aggregates attribute
- aggregation [C++]
- aggregate objects [C++], aggregates attribute
- aggregates [C++]
ms.assetid: 67a084c9-941f-474b-a029-9c93b38ebe9a
caps.latest.revision: "9"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: f3fc74f10e0b5900030d48b37d1918de8807d152
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="aggregates"></a>aggregates
Indica que o objeto agrega o objeto especificado pelo CLSID.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
  
      [ aggregates(  
   clsid,  
   variable_name  
) ]  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `clsid`  
 Especifica o CLSID do objeto agregável.  
  
 `variable_name`  
 O nome da variável que deve ser inserido. Essa variável contém o **IUnknown** do objeto que está sendo agregado.  
  
## <a name="remarks"></a>Comentários  
 Quando aplicado a um objeto, o **agregações** atributo C++ implementa um wrapper externo para o objeto que está sendo agregado (especificada por `clsid`).  
  
 Este atributo requer que o [coclass](../windows/coclass.md), [progid](../windows/progid.md), ou [vi_progid](../windows/vi-progid.md) atributo (ou outro atributo que implica uma destas opções) também ser aplicados ao mesmo elemento. Se qualquer atributo único for usado, os outros dois são aplicados automaticamente. Por exemplo, se **progid** é aplicado, **vi_progid** e **coclass** também são aplicadas.  
  
 **Projetos ATL**  
  
 Se esse atributo for usado em um projeto que usa ATL, altera o comportamento do atributo. Primeiro, a seguinte entrada é adicionada ao mapa COM do objeto de destino:  
  
```  
COM_INTERFACE_ENTRY_AUTOAGGREGATE_BLIND(_m_spAttrXXX, clsid)  
```  
  
 Segundo, o [DECLARE_GET_CONTROLLING_UNKNOWN](../atl/reference/aggregation-and-class-factory-macros.md#declare_get_controlling_unknown) macro também é adicionada.  
  
## <a name="example"></a>Exemplo  
  
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
  
## <a name="requirements"></a>Requisitos  
  
### <a name="attribute-context"></a>Contexto de atributo  
  
|||  
|-|-|  
|**Aplica-se a**|**classe**,`struct`|  
|**Repetível**|Sim|  
|**Atributos necessários.**|Um ou mais dos seguintes: **coclass**, **progid**, ou **vi_progid**.|  
|**Atributos inválidos**|Nenhum|  
  
 Para obter mais informações sobre os contextos de atributo, consulte [contextos de atributo](../windows/attribute-contexts.md).  
  
## <a name="see-also"></a>Consulte também  
 [Atributos COM](../windows/com-attributes.md)   
 [Atributos de classe](../windows/class-attributes.md)   
 [TypeDef, Enum, Union e Struct atributos](../windows/typedef-enum-union-and-struct-attributes.md)   
 [Agregação](http://msdn.microsoft.com/library/windows/desktop/ms686558)   
 [Agregável](http://msdn.microsoft.com/library/windows/desktop/aa366721)   
 [COM_INTERFACE_ENTRY_AUTOAGGREGATE_BLIND](../atl/reference/com-interface-entry-macros.md#com_interface_entry_autoaggregate_blind)   
 