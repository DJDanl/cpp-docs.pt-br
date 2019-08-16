---
title: origem (C++ atributo com)
ms.date: 10/02/2018
f1_keywords:
- vc-attr.source
helpviewer_keywords:
- source attribute
ms.assetid: 1878d05d-7709-4e97-b114-c62f38f5140e
ms.openlocfilehash: 79614a345e6c07b03df351da93a847fe12e4b110
ms.sourcegitcommit: fcb48824f9ca24b1f8bd37d647a4d592de1cc925
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/15/2019
ms.locfileid: "69514026"
---
# <a name="source-c"></a>source (C++)

Em uma classe, especifica as interfaces de origem do objeto COM para pontos de conexão. Em uma propriedade ou método, indica que o membro retorna um objeto ou uma variante que é uma fonte de eventos.

## <a name="syntax"></a>Sintaxe

```cpp
[ source(interfaces) ]
```

### <a name="parameters"></a>Parâmetros

*interfaces*<br/>
Uma ou mais interfaces que você especifica ao aplicar o atributo de origem a uma classe. Esse parâmetro não é usado quando a origem é aplicada a uma propriedade ou um método.

## <a name="remarks"></a>Comentários

O atributo de **origem** C++ tem a mesma funcionalidade que o atributo MIDL de [origem](/windows/win32/Midl/source) .

Você pode usar o atributo [padrão](default-cpp.md) para especificar a interface de origem padrão para um objeto.

## <a name="example"></a>Exemplo

```cpp
// cpp_attr_ref_source.cpp
// compile with: /LD
#include "windows.h"
#include "unknwn.h"
[module(name="MyLib")];

[object, uuid(11111111-1111-1111-1111-111111111111)]
__interface b
{
   [id(0), propget, bindable, displaybind, defaultbind, requestedit]
   HRESULT get_I([out, retval]long *i);
};

[object, uuid(11111111-1111-1111-1111-111111111131)]
__interface c
{
   [id(0), propget, bindable, displaybind, defaultbind, requestedit]
   HRESULT et_I([out, retval]long *i);
};

[coclass, default(c), uuid(11111111-1111-1111-1111-111111111132)]
class N : public b
{
};

[coclass, source(c), default(b, c), uuid(11111111-1111-1111-1111-111111111133)]
class NN : public b
{
};
```

## <a name="requirements"></a>Requisitos

### <a name="attribute-context"></a>Contexto de atributo

|||
|-|-|
|**Aplica-se a**|**class**, **struct**, **interface**|
|**Repetível**|Não|
|**Atributos necessários**|`coclass`(quando aplicado à classe ou estrutura)|
|**Atributos inválidos**|Nenhum|

Para obter mais informações sobre os contextos de atributo, consulte contextos de [atributo](cpp-attributes-com-net.md#contexts).

## <a name="see-also"></a>Consulte também

[Atributos de IDL](idl-attributes.md)<br/>
[Atributos de classe](class-attributes.md)<br/>
[Atributos de método](method-attributes.md)<br/>
[coclass](coclass.md)