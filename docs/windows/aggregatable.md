---
title: agregável | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: reference
f1_keywords:
- vc-attr.aggregatable
dev_langs:
- C++
helpviewer_keywords:
- aggregatable attribute
ms.assetid: 9253a46a-cd76-41f2-b3b6-86f709bb069c
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 2b18f4c38777076357170540e35fc5515025e126
ms.sourcegitcommit: 37a10996022d738135999cbe71858379386bab3d
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/08/2018
ms.locfileid: "39643001"
---
# <a name="aggregatable"></a>aggregatable
Indica que a classe oferece suporte à agregação.  
  
## <a name="syntax"></a>Sintaxe  
  
```cpp  
[ aggregatable(   
   value  
) ]  
```  
  
### <a name="parameters"></a>Parâmetros  
 *valor* (opcional)  
 Um parâmetro para indicar quando o objeto COM pode ser agregado:  
  
-   `never` O objeto COM não pode ser agregado.  
  
-   `allowed` O objeto COM pode ser criado diretamente ou eles podem ser agregados. Esse é o padrão.  
  
-   `always` O objeto COM não pode ser criado diretamente e só pode ser agregado. Quando você chama `CoCreateInstance` para esse objeto, você deve especificar o objeto de agregação `IUnknown` interface (o controlando `IUnknown`).  
  
## <a name="remarks"></a>Comentários  
 O **agregável** atributo C++ tem a mesma funcionalidade que o [agregável](http://msdn.microsoft.com/library/windows/desktop/aa366721) atributo MIDL. Isso significa que o compilador passará a **agregável** por meio do atributo para o arquivo. idl gerado.  
  
 Este atributo exige que o [coclass](../windows/coclass.md), [progid](../windows/progid.md), ou [vi_progid](../windows/vi-progid.md) atributo (ou outro atributo que implica uma destas opções) também ser aplicadas ao mesmo elemento. Se qualquer atributo único for usado, os outros dois são aplicados automaticamente. Por exemplo, se `progid` for aplicada, `vi_progid` e `coclass` também são aplicadas.  
  
### <a name="atl-projects"></a>Projetos ATL  
  
 Se esse atributo for usado em um projeto que usa ATL, altera o comportamento do atributo. Além do comportamento descrito anteriormente, o atributo também adiciona uma das macros de seguir para a classe de destino:  
  
|Valor do parâmetro|Macro inserida|  
|---------------------|--------------------|  
|`Never`|[DECLARE_NOT_AGGREGATABLE](../atl/reference/aggregation-and-class-factory-macros.md#declare_not_aggregatable)|  
|`Allowed`|[DECLARE_POLY_AGGREGATABLE](../atl/reference/aggregation-and-class-factory-macros.md#declare_poly_aggregatable)|  
|`Always`|[DECLARE_ONLY_AGGREGATABLE](../atl/reference/aggregation-and-class-factory-macros.md#declare_only_aggregatable)|  
  
## <a name="example"></a>Exemplo  
  
```cpp  
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
  
### <a name="attribute-context"></a>Atributo de contexto  
  
|||  
|-|-|  
|**Aplica-se a**|**classe**, **struct**|  
|**Repetível**|Não|  
|**Atributos obrigatórios**|Um ou mais das seguintes opções: `coclass`, `progid`, ou `vi_progid`.|  
|**Atributos inválidos**|Nenhum|  
  
 Para obter mais informações sobre os contextos de atributo, consulte [contextos de atributo](../windows/attribute-contexts.md).  
  
## <a name="see-also"></a>Consulte também  
 [Atributos IDL](../windows/idl-attributes.md)   
 [Atributos de classe](../windows/class-attributes.md)   
 [TypeDef, Enum, Union e Struct atributos](../windows/typedef-enum-union-and-struct-attributes.md)   
 [Agregação](http://msdn.microsoft.com/library/windows/desktop/ms686558)   