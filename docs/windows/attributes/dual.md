---
title: dual (C++ atributo com)
ms.date: 10/02/2018
f1_keywords:
- vc-attr.dual
helpviewer_keywords:
- dual attribute
ms.assetid: 5d4a9069-d819-42cd-ba56-bbcda17157d9
ms.openlocfilehash: 66cd6eb9141244397609cc6421ead74d1eb8547e
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80168207"
---
# <a name="dual"></a>dual

Coloca uma interface no arquivo. idl como uma interface dupla.

## <a name="syntax"></a>Sintaxe

```cpp
[dual]
```

## <a name="remarks"></a>Comentários

Quando o atributo **Dual** C++ precede uma interface, ele faz com que a interface seja colocada dentro do bloco de biblioteca no arquivo. idl gerado.

## <a name="example"></a>Exemplo

O código a seguir é um bloco de atributo que usa **Dual** antes de uma definição de interface:

```cpp
// cpp_attr_ref_dual.cpp
// compile with: /LD
#include <windows.h>
[module(name="MyLibrary")];

[uuid("2F5F63F1-16DA-11d2-9E7B-00C04FB926DA"), dual]

__interface IStatic : IDispatch
{
   HRESULT Func1(int i);
   [   propget,    id(1),    bindable,    displaybind,    defaultbind,    requestedit
   ]
   HRESULT P1([out, retval] long *nSize);
   [   propput,    id(1),    bindable,    displaybind,    defaultbind,    requestedit
   ]
   HRESULT P1([in] long nSize);
};

[cpp_quote("#include file.h")];
```

## <a name="requirements"></a>Requisitos

### <a name="attribute-context"></a>Contexto de atributo

|||
|-|-|
|**Aplica-se a**|**interface**|
|**Repetível**|Não|
|**Atributos necessários**|Nenhum|
|**Atributos inválidos**|`dispinterface`|

Para obter mais informações, consulte [contextos de atributo](cpp-attributes-com-net.md#contexts).

## <a name="see-also"></a>Confira também

[Atributos de IDL](idl-attributes.md)<br/>
[Atributos por uso](attributes-by-usage.md)<br/>
[custom](custom-cpp.md)<br/>
[dispinterface](dispinterface.md)<br/>
[object](object-cpp.md)<br/>
[__interface](../../cpp/interface.md)
