---
title: "agregável | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: language-reference
f1_keywords:
- vc-attr.aggregatable
dev_langs:
- C++
helpviewer_keywords:
- aggregatable attribute
ms.assetid: 9253a46a-cd76-41f2-b3b6-86f709bb069c
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: ec044e18fdd8bcd21fbad8d2e46c847c876cc00d
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="aggregatable"></a>aggregatable
Indica que a classe oferece suporte à agregação.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
  
      [ aggregatable(   
   value  
) ]  
```  
  
#### <a name="parameters"></a>Parâmetros  
 *valor* (opcional)  
 Um parâmetro para indicar quando o objeto COM pode ser agregado:  
  
-   **nunca** objeto COM não pode ser agregado.  
  
-   **permitido** objeto COM pode ser criado diretamente ou que pode ser agregados. Esse é o padrão.  
  
-   **sempre** objeto COM não pode ser criado diretamente e só podem ser agregado. Quando você chama `CoCreateInstance` para esse objeto, você deve especificar o objeto de agregação **IUnknown** interface (o controlador **IUnknown**).  
  
## <a name="remarks"></a>Comentários  
 O **agregável** atributo C++ tem a mesma funcionalidade que o [agregável](http://msdn.microsoft.com/library/windows/desktop/aa366721) atributo MIDL. Isso significa que o compilador passará o **agregável** por meio de atributo para o arquivo. idl gerado.  
  
 Este atributo requer que o [coclass](../windows/coclass.md), [progid](../windows/progid.md), ou [vi_progid](../windows/vi-progid.md) atributo (ou outro atributo que implica uma destas opções) também ser aplicados ao mesmo elemento. Se qualquer atributo único for usado, os outros dois são aplicados automaticamente. Por exemplo, se **progid** é aplicado, **vi_progid** e **coclass** também são aplicadas.  
  
 **Projetos ATL**  
  
 Se esse atributo for usado em um projeto que usa ATL, altera o comportamento do atributo. Além do comportamento descrito anteriormente, o atributo também adiciona uma das seguintes macros para a classe de destino:  
  
|Valor do parâmetro|Macro inserida|  
|---------------------|--------------------|  
|**Nunca**|[DECLARE_NOT_AGGREGATABLE](../atl/reference/aggregation-and-class-factory-macros.md#declare_not_aggregatable)|  
|**Permitido**|[DECLARE_POLY_AGGREGATABLE](../atl/reference/aggregation-and-class-factory-macros.md#declare_poly_aggregatable)|  
|**Sempre**|[DECLARE_ONLY_AGGREGATABLE](../atl/reference/aggregation-and-class-factory-macros.md#declare_only_aggregatable)|  
  
## <a name="example"></a>Exemplo  
  
```  
// cpp_attr_ref_aggregatable.cpp  
// compile with: /LD  
#define _ATL_ATTRIBUTES  
#include "atlbase.h"  
#include "atlcom.h"  
  
[module(name="MyModule")];  
  
[ coclass, aggregatable(allowed),  
  uuid("1a8369cc-1c91-42c4-befa-5a5d8c9d2529")]  
class CMyClass {};  
```  
  
## <a name="requirements"></a>Requisitos  
  
### <a name="attribute-context"></a>Contexto de atributo  
  
|||  
|-|-|  
|**Aplica-se a**|**classe**,`struct`|  
|**Repetível**|Não|  
|**Atributos necessários.**|Um ou mais dos seguintes: **coclass**, **progid**, ou **vi_progid**.|  
|**Atributos inválidos**|Nenhum|  
  
 Para obter mais informações sobre os contextos de atributo, consulte [contextos de atributo](../windows/attribute-contexts.md).  
  
## <a name="see-also"></a>Consulte também  
 [Atributos IDL](../windows/idl-attributes.md)   
 [Atributos de classe](../windows/class-attributes.md)   
 [TypeDef, Enum, Union e Struct atributos](../windows/typedef-enum-union-and-struct-attributes.md)   
 [Agregação](http://msdn.microsoft.com/library/windows/desktop/ms686558)   
