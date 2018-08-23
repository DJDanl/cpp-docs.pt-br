---
title: fonte (C++) | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: reference
f1_keywords:
- vc-attr.source
dev_langs:
- C++
helpviewer_keywords:
- source attribute
ms.assetid: 1878d05d-7709-4e97-b114-c62f38f5140e
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 921510a548f638f06953f95abe79f825e57e179b
ms.sourcegitcommit: 6f8dd98de57bb80bf4c9852abafef1c35a7600f1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/22/2018
ms.locfileid: "42586852"
---
# <a name="source-c"></a>source (C++)

Em uma classe, especifica as interfaces de origem do objeto COM para pontos de conexão. Em uma propriedade ou método, indica que o membro retorna um objeto ou uma VARIANTE que é uma origem de eventos.

## <a name="syntax"></a>Sintaxe

```cpp
[ source(
   interfaces
) ]
```

### <a name="parameters"></a>Parâmetros

*interfaces*  
Uma ou mais interfaces que você especifique quando você aplica a origem do atributo a uma classe. Esse parâmetro não é usado quando o código-fonte é aplicada a uma propriedade ou método.

## <a name="remarks"></a>Comentários

O **fonte** atributo C++ tem a mesma funcionalidade que o [origem](http://msdn.microsoft.com/library/windows/desktop/aa367166) atributo MIDL.

Você pode usar o [padrão](../windows/default-cpp.md) atributo para especificar a interface de origem padrão para um objeto.

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

### <a name="attribute-context"></a>Atributo de contexto

|||
|-|-|
|**Aplica-se a**|**classe**, **struct**, **interface**|
|**Repetível**|Não|
|**Atributos obrigatórios**|`coclass` (quando aplicado à classe ou struct)|
|**Atributos inválidos**|Nenhum|

Para obter mais informações sobre os contextos de atributo, consulte [contextos de atributo](../windows/attribute-contexts.md).

## <a name="see-also"></a>Consulte também

[Atributos de IDL](../windows/idl-attributes.md)  
[Atributos de classe](../windows/class-attributes.md)  
[Atributos de método](../windows/method-attributes.md)  
[coclass](../windows/coclass.md)  