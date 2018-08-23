---
title: com_interface_entry (C++) | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: reference
f1_keywords:
- vc-attr.com_interface_entry
dev_langs:
- C++
helpviewer_keywords:
- com_interface_entry attribute
ms.assetid: 10368f81-b99b-4a0f-ba4f-a142e6911a5c
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 9c0b2c53bf06a748be522606f5904f307cc00df8
ms.sourcegitcommit: 6f8dd98de57bb80bf4c9852abafef1c35a7600f1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/22/2018
ms.locfileid: "42591350"
---
# <a name="cominterfaceentry-c"></a>com_interface_entry (C++)

Adiciona uma entrada de interface do mapa COM da classe de destino.

## <a name="syntax"></a>Sintaxe

```cpp
[ com_interface_entry(
  com_interface_entry
) ]
```

### <a name="parameters"></a>Parâmetros

*com_interface_entry*  
Uma cadeia de caracteres que contém o texto real da entrada. Para obter uma lista de valores possíveis, consulte [COM_INTERFACE_ENTRY Macros](../atl/reference/com-interface-entry-macros.md).

## <a name="remarks"></a>Comentários

O **com_interface_entry** atributo C++ insere o conteúdo unabridged de uma cadeia de caracteres para o mapa de interface COM do objeto de destino. Se o atributo é aplicado de uma vez para o objeto de destino, a entrada será inserida no início do mapa de interface existente. Se o atributo é aplicado várias vezes ao mesmo objeto de destino, as entradas são inseridas no início do mapa de interface na ordem em que elas são recebidas.

Este atributo exige que o [coclass](../windows/coclass.md), [progid](../windows/progid.md), ou [vi_progid](../windows/vi-progid.md) atributo (ou outro atributo que implica uma destas opções) também ser aplicadas ao mesmo elemento. Se qualquer atributo único for usado, os outros dois são aplicados automaticamente. Por exemplo, se `progid` for aplicada, `vi_progid` e `coclass` também são aplicadas.

Porque o primeiro uso **com_interface_entry** faz com que a nova interface a ser inserido no início do mapa de interface, ele deve ser um dos seguintes tipos de COM_INTERFACE_ENTRY:

- COM_INTERFACE_ENTRY

- COM_INTERFACE_ENTRY_IID

- COM_INTERFACE_ENTRY2

- COM_INTERFACE_ENTRY2_IID

Usos adicionais a **com_interface_entry** atributo pode usar todos os COM_INTERFACE_ENTRY tipos suportados.

Essa restrição é necessária porque o ATL usa a primeira entrada no mapa de interface como a identidade `IUnknown`; portanto, a entrada deve ser uma interface válida. Por exemplo, o exemplo de código a seguir é inválido porque a primeira entrada no mapa de interface não especifica uma interface COM real.

```cpp
[ coclass, com_interface_entry =
    "COM_INTERFACE_ENTRY_NOINTERFACE(IDebugTest)"
]
   class CMyClass
   {
   };
```

## <a name="example"></a>Exemplo

O código a seguir adiciona duas entradas para o mapa de interface COM existente de `CMyBaseClass`. A primeira é uma interface padrão e o segundo oculta o `IDebugTest` interface.

```cpp
// cpp_attr_ref_com_interface_entry.cpp
// compile with: /LD
#define _ATL_ATTRIBUTES
#include "atlbase.h"
#include "atlcom.h"

[module (name ="ldld")];

[ object,
  uuid("7dbebed3-d636-4917-af62-c767a720a5b9")]
__interface IDebugTest{};

[ object,
  uuid("2875ceac-f94b-4087-8e13-d13dc167fcfc")]
__interface IMyClass{};

[ coclass,
  com_interface_entry ("COM_INTERFACE_ENTRY (IMyClass)"),
  com_interface_entry ("COM_INTERFACE_ENTRY_NOINTERFACE(IDebugTest)"),
  uuid("b85f8626-e76e-4775-b6a0-4826a9e94af2")  
]

class CMyClass: public IMyClass, public IDebugTest
{
};
```

O mapa de objeto COM resultante para `CMyBaseClass` é da seguinte maneira:

```cpp
BEGIN_COM_MAP(CMyClass)  
    COM_INTERFACE_ENTRY (IMyClass)  
    COM_INTERFACE_ENTRY_NOINTERFACE(IDebugTest)  
    COM_INTERFACE_ENTRY(IMyClass)  
    COM_INTERFACE_ENTRY2(IDispatch, IMyClass)  
    COM_INTERFACE_ENTRY(IDebugTest)  
    COM_INTERFACE_ENTRY(IProvideClassInfo)  
END_COM_MAP()  
```

## <a name="requirements"></a>Requisitos

### <a name="attribute-context"></a>Atributo de contexto

|||
|-|-|
|**Aplica-se a**|**classe**, **struct**|
|**Repetível**|Sim|
|**Atributos obrigatórios**|Um ou mais das seguintes opções: `coclass`, `progid`, ou `vi_progid`.|
|**Atributos inválidos**|Nenhum|

Para obter mais informações sobre os contextos de atributo, consulte [contextos de atributo](../windows/attribute-contexts.md).

## <a name="see-also"></a>Consulte também

[Atributos de COM](../windows/com-attributes.md)  
[Atributos de classe](../windows/class-attributes.md)  
[Atributos Typedef, Enum, Union e Struct](../windows/typedef-enum-union-and-struct-attributes.md)  