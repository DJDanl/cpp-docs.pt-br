---
title: (C++ COM atributo vinculável) | Microsoft Docs
ms.custom: ''
ms.date: 10/02/2018
ms.technology:
- cpp-windows
ms.topic: reference
f1_keywords:
- vc-attr.bindable
dev_langs:
- C++
helpviewer_keywords:
- bindable attribute
ms.assetid: a2360f92-927b-4af8-98cc-6eca7f4ec954
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 7f30ab333a2f50c845b8cf66179da05863fa67d7
ms.sourcegitcommit: a9dcbcc85b4c28eed280d8e451c494a00d8c4c25
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/25/2018
ms.locfileid: "50073000"
---
# <a name="bindable"></a>bindable

Indica que a propriedade dá suporte à associação de dados.

## <a name="syntax"></a>Sintaxe

```cpp
[bindable]
```

## <a name="remarks"></a>Comentários

O **associável** atributo C++ tem a mesma funcionalidade que o [associável](/windows/desktop/Midl/bindable) atributo MIDL. Você pode usá-lo nas propriedades definidas com o [propget](propget.md), [propput](propput.md), ou [propputref](propputref.md) atributos, ou você pode definir um método associável manualmente.

Os exemplos MFC a seguir mostram o uso do **associável**:

- [Exemplos de controles: Controles do ActiveX do MFC com base](https://github.com/Microsoft/VCSamples/tree/master/VC2010Samples/MFC/controls)

- [Exemplo c: Controle ActiveX](https://github.com/Microsoft/VCSamples/tree/master/VC2010Samples/MFC/controls)

- [TESTHELP exemplo: Controle de ActiveX com dicas de ferramenta e a Ajuda](https://github.com/Microsoft/VCSamples/tree/master/VC2010Samples/MFC/controls)

## <a name="example"></a>Exemplo

O código a seguir mostra como você pode usar **associável** em uma propriedade:

```cpp
// cpp_attr_ref_bindable.cpp
// compile with: /LD
#include <windows.h>
[
   uuid("479B29E3-9A2C-11D0-B696-00A0C903487A"), dispinterface, helpstring("property demo Interface")
]
__interface IPropDemo : IDispatch {

   [propget, id(1), bindable, displaybind, defaultbind, requestedit] HRESULT P1([out, retval] long *nSize);
   [propput, id(1), bindable, displaybind, defaultbind, requestedit] HRESULT P1([in] long nSize);
   [id(3), bindable, propget] HRESULT Object([out, retval] IDispatch **ppObj);
   [id(3), bindable, propputref] HRESULT Object([in] IDispatch* pObj);
   [id(-552), helpstring("method AboutBox")] HRESULT AboutBox();
};

[ module(name="PropDemoLib", uuid="479B29E2-9A2C-11D0-B696-00A0C903487A", version="1.0", helpstring="property demo") ];
```

## <a name="requirements"></a>Requisitos

### <a name="attribute-context"></a>Atributo de contexto

|||
|-|-|
|**Aplica-se a**|Método de interface|
|**Repetível**|Não|
|**Atributos obrigatórios**|Nenhum|
|**Atributos inválidos**|Nenhum|

Para obter mais informações sobre os contextos de atributo, consulte [contextos de atributo](cpp-attributes-com-net.md#contexts).

## <a name="see-also"></a>Consulte também

[Atributos de IDL](idl-attributes.md)<br/>
[Atributos de método](method-attributes.md)<br/>
[defaultbind](defaultbind.md)<br/>
[displaybind](displaybind.md)<br/>
[immediatebind](immediatebind.md)<br/>
[requestedit](requestedit.md)