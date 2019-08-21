---
title: Usando o IDispEventImpl (ATL)
ms.date: 08/19/2019
helpviewer_keywords:
- IDispEventImpl class, using
ms.assetid: 82d53b61-9d0d-45c5-aff9-2fafa468a9ca
ms.openlocfilehash: 9684781ba99d96e2c58d450ee0ff892374e33aef
ms.sourcegitcommit: 9d4ffb8e6e0d70520a1e1a77805785878d445b8a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/20/2019
ms.locfileid: "69630592"
---
# <a name="using-idispeventimpl"></a>Como usar IDispEventImpl

Ao usar `IDispEventImpl` o para lidar com eventos, você precisará:

- Derive sua classe de [IDispEventImpl](../atl/reference/idispeventimpl-class.md).

- Adicione um mapa de coletor de eventos à sua classe.

- Adicione entradas ao mapa do coletor de eventos usando a macro [SINK_ENTRY](reference/composite-control-macros.md#sink_entry) ou [SINK_ENTRY_EX](reference/composite-control-macros.md#sink_entry_ex) .

- Implemente os métodos que você está interessado em manipular.

- Avise e aconselhe a origem do evento.

## <a name="example"></a>Exemplo

O exemplo a seguir mostra como tratar o `DocumentChange` evento disparado pelo objeto **Application** do Word. Esse evento é definido como um método na `ApplicationEvents` dispinterface.

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

[!code-cpp[NVC_ATL_EventHandlingSample#1](../atl/codesnippet/cpp/using-idispeventimpl_1.h)]

O código a seguir aparece em NotSoSimple. h. O código relevante é observado por comentários:

[!code-cpp[NVC_ATL_EventHandlingSample#2](../atl/codesnippet/cpp/using-idispeventimpl_2.h)]

## <a name="see-also"></a>Consulte também

[Manipulação de eventos](../atl/event-handling-and-atl.md)<br/>
[Exemplo de ATLEventHandling](../overview/visual-cpp-samples.md)
