---
title: com_interface_entry (atributo COM C++)
ms.date: 10/02/2018
f1_keywords:
- vc-attr.com_interface_entry
helpviewer_keywords:
- com_interface_entry attribute
ms.assetid: 10368f81-b99b-4a0f-ba4f-a142e6911a5c
ms.openlocfilehash: 06df146ea47428ee782da7a93c2da7097e110324
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87215342"
---
# <a name="com_interface_entry-c"></a>com_interface_entry (C++)

Adiciona uma entrada de interface ao mapa COM da classe de destino.

## <a name="syntax"></a>Sintaxe

```cpp
[ com_interface_entry(
  com_interface_entry) ]
```

### <a name="parameters"></a>parâmetros

*com_interface_entry*<br/>
Uma cadeia de caracteres que contém o texto real da entrada. Para obter uma lista de valores possíveis, consulte [COM_INTERFACE_ENTRY macros](../../atl/reference/com-interface-entry-macros.md).

## <a name="remarks"></a>Comentários

O atributo **COM_INTERFACE_ENTRY** C++ insere o conteúdo Unabridged de uma cadeia de caracteres no mapa de interface com do objeto de destino. Se o atributo for aplicado uma vez ao objeto de destino, a entrada será inserida no início do mapa de interface existente. Se o atributo for aplicado repetidamente ao mesmo objeto de destino, as entradas serão inseridas no início do mapa de interface na ordem em que são recebidas.

Esse atributo requer que o atributo [coclass](coclass.md), [ProgID](progid.md)ou [vi_progid](vi-progid.md) (ou outro atributo que implica um deles) também seja aplicado ao mesmo elemento. Se qualquer atributo único for usado, os outros dois serão aplicados automaticamente. Por exemplo, se `progid` é aplicado `vi_progid` e `coclass` também é aplicado.

Como o primeiro uso de **COM_INTERFACE_ENTRY** faz com que a nova interface seja inserida no início do mapa de interface, ela deve ser um dos seguintes tipos de COM_INTERFACE_ENTRY:

- COM_INTERFACE_ENTRY

- COM_INTERFACE_ENTRY_IID

- COM_INTERFACE_ENTRY2

- COM_INTERFACE_ENTRY2_IID

Usos adicionais do atributo **COM_INTERFACE_ENTRY** podem usar todos os tipos de COM_INTERFACE_ENTRY com suporte.

Essa restrição é necessária porque a ATL usa a primeira entrada no mapa de interface como a identidade `IUnknown` ; portanto, a entrada deve ser uma interface válida. Por exemplo, o exemplo de código a seguir é inválido porque a primeira entrada no mapa de interface não especifica uma interface COM real.

```cpp
[ coclass, com_interface_entry =
    "COM_INTERFACE_ENTRY_NOINTERFACE(IDebugTest)"
]
   class CMyClass
   {
   };
```

## <a name="example"></a>Exemplo

O código a seguir adiciona duas entradas ao mapa de interface COM existente do `CMyBaseClass` . A primeira é uma interface padrão e a segunda oculta a `IDebugTest` interface.

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

O mapa de objeto COM resultante do `CMyBaseClass` é o seguinte:

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

### <a name="attribute-context"></a>Contexto de atributo

|||
|-|-|
|**Aplica-se a**|**`class`**, **`struct`**|
|**Repetível**|Sim|
|**Atributos obrigatórios**|Um ou mais dos seguintes: `coclass` , `progid` ou `vi_progid` .|
|**Atributos inválidos**|Nenhum|

Para obter mais informações sobre os contextos de atributo, consulte [contextos de atributo](cpp-attributes-com-net.md#contexts).

## <a name="see-also"></a>Confira também

[Atributos COM](com-attributes.md)<br/>
[Atributos de classe](class-attributes.md)<br/>
[Atributos typedef, enum, Union e struct](typedef-enum-union-and-struct-attributes.md)
