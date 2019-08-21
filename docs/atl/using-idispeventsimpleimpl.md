---
title: Usando o IDispEventSimpleImpl (ATL)
ms.date: 08/19/2019
helpviewer_keywords:
- IDispEventSimpleImpl class, using
ms.assetid: 8640ad1a-4bd0-40a5-b5e4-7322685d7aab
ms.openlocfilehash: 8a5e64093d2687efc6c6c5e9b0ce89402d2b99a4
ms.sourcegitcommit: 9d4ffb8e6e0d70520a1e1a77805785878d445b8a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/20/2019
ms.locfileid: "69630580"
---
# <a name="using-idispeventsimpleimpl"></a>Como usar IDispEventSimpleImpl

Ao usar `IDispEventSimpleImpl` o para lidar com eventos, você precisará:

- Derive sua classe de [IDispEventSimpleImpl](../atl/reference/idispeventsimpleimpl-class.md).

- Adicione um mapa de coletor de eventos à sua classe.

- Defina estruturas [_ATL_FUNC_INFO](../atl/reference/atl-func-info-structure.md) que descrevam os eventos.

- Adicione entradas ao mapa do coletor de eventos usando a macro [SINK_ENTRY_INFO](reference/composite-control-macros.md#sink_entry_info) .

- Implemente os métodos que você está interessado em manipular.

- Avise e aconselhe a origem do evento.

## <a name="example"></a>Exemplo

O exemplo a seguir mostra como lidar com o `DocumentChange` evento disparado pelo objeto de **aplicativo** do Word. Esse evento é definido como um método na `ApplicationEvents` dispinterface.

O exemplo é do [exemplo ATLEventHandling](../overview/visual-cpp-samples.md).

```cpp
[ uuid(000209F7-0000-0000-C000-000000000046), hidden ]
dispinterface ApplicationEvents {
properties:
methods:
    [id(0x00000001), restricted, hidden]
    void Startup();

    [id(0x00000002)]
    void Quit();

    [id(0x00000003)]
    void DocumentChange();
};
```

O exemplo usa `#import` para gerar os arquivos de cabeçalho necessários da biblioteca de tipos do Word. Se você quiser usar este exemplo com outras versões do Word, deverá especificar o arquivo dll correto do Mso. Por exemplo, o Office 2000 fornece Mso9. dll e o OfficeXP fornece Mso. dll. Esse código é simplificado de *PCH. h* (*stdafx. h* no Visual Studio 2017 e anterior):

[!code-cpp[NVC_ATL_EventHandlingSample#1](../atl/codesnippet/cpp/using-idispeventsimpleimpl_1.h)]

A única informação da biblioteca de tipos realmente usada neste exemplo é o CLSID do objeto do Word `Application` e o IID `ApplicationEvents` da interface. Essas informações só são usadas no momento da compilação.

O código a seguir aparece em Simple. h. O código relevante é observado por comentários:

[!code-cpp[NVC_ATL_EventHandlingSample#3](../atl/codesnippet/cpp/using-idispeventsimpleimpl_2.h)]

O código a seguir é de Simple. cpp:

[!code-cpp[NVC_ATL_EventHandlingSample#4](../atl/codesnippet/cpp/using-idispeventsimpleimpl_3.cpp)]

## <a name="see-also"></a>Consulte também

[Manipulação de eventos](../atl/event-handling-and-atl.md)<br/>
[Exemplo de ATLEventHandling](../overview/visual-cpp-samples.md)
