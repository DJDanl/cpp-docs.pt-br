---
title: Suporte a IDispEventImpl
ms.date: 11/04/2016
helpviewer_keywords:
- event sink maps, declaring
- IDispEventImpl class, advising and unadvising
- SINK_ENTRY macro
- type libraries, importing
- ATL, IDispEventImpl support in COM objects
- BEGIN_SINK_MAP macro
- IDispEventImpl class, declaring
ms.assetid: b957f930-6a5b-4598-8e4d-8027759957e7
ms.openlocfilehash: 3652aae2a6c84833ed32e52599d3834d6e66a5ee
ms.sourcegitcommit: 8105b7003b89b73b4359644ff4281e1595352dda
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/14/2019
ms.locfileid: "57812324"
---
# <a name="supporting-idispeventimpl"></a>Suporte a IDispEventImpl

A classe de modelo [IDispEventImpl](../atl/reference/idispeventimpl-class.md) pode ser usado para fornecer suporte para Coletores de ponto de conexão em sua classe ATL. Um coletor de ponto de conexão permite que sua classe manipular eventos acionados dos objetos de COM externos. Esses coletores de ponto de conexão são mapeados com um mapa coletor de evento, fornecido por sua classe.

Para implementar corretamente um coletor de ponto de conexão para sua classe, as etapas a seguir devem ser concluídas:

- Importe as bibliotecas de tipo para cada objeto externo

- Declare o `IDispEventImpl` interfaces

- Declarar um mapa coletor de evento

- Avisar e não recomendar os pontos de conexão

As etapas envolvidas na implementação de um coletor de ponto de conexão são realizadas ao modificar apenas o arquivo de cabeçalho (. h) de sua classe.

## <a name="importing-the-type-libraries"></a>Importar as bibliotecas de tipos

Para cada objeto externo cujos eventos você deseja manipular, você deve importar a biblioteca de tipos. Esta etapa define os eventos que podem ser manipulados e fornece informações que são usadas ao declarar o mapa do coletor de evento. O [#import](../preprocessor/hash-import-directive-cpp.md) diretiva pode ser usada para fazer isso. Adicionar o necessário `#import` linhas diretivas para cada interface de expedição você dará suporte para o arquivo de cabeçalho (. h) de sua classe.

O exemplo a seguir importa a biblioteca de tipos de um servidor de COM externos (`MSCAL.Calendar.7`):

[!code-cpp[NVC_ATL_Windowing#141](../atl/codesnippet/cpp/supporting-idispeventimpl_1.h)]

> [!NOTE]
>  Você deve ter um separado `#import` instrução para cada biblioteca de tipo externo que você dará suporte.

## <a name="declaring-the-idispeventimpl-interfaces"></a>Declarando Interfaces IDispEventImpl

Agora que você importou as bibliotecas de tipo de cada interface de expedição, você precisa declarar separado `IDispEventImpl` interfaces para cada interface de expedição externo. Modifique a declaração de sua classe adicionando um `IDispEventImpl` interface de declaração para cada objeto externo. Para obter mais informações sobre os parâmetros, consulte [IDispEventImpl](../atl/reference/idispeventimpl-class.md).

O código a seguir declara dois Coletores de ponto de conexão, para o `DCalendarEvents` interface para o objeto COM implementado pela classe `CMyCompositCtrl2`:

[!code-cpp[NVC_ATL_Windowing#142](../atl/codesnippet/cpp/supporting-idispeventimpl_2.h)]

## <a name="declaring-an-event-sink-map"></a>Declarando um mapa coletor de evento

Para as notificações de eventos a serem manipuladas pela função adequada que, sua classe deve rotear cada evento para seu manipulador correto. Isso é feito por meio da declaração de um mapa coletor de evento.

Várias macros, a ATL fornece [BEGIN_SINK_MAP](reference/composite-control-macros.md#begin_sink_map), [END_SINK_MAP](reference/composite-control-macros.md#end_sink_map), e [SINK_ENTRY_EX](reference/composite-control-macros.md#sink_entry_ex), que facilitam esse mapeamento. O formato padrão é o seguinte:

```cpp
BEGIN_SINK_MAP(comClass)
  SINK_ENTRY_EX(id, iid, dispid, func)
  . . . //additional external event entries
END_SINK_MAP()
```

O exemplo a seguir declara um mapa coletor de evento com dois manipuladores de eventos:

[!code-cpp[NVC_ATL_Windowing#136](../atl/codesnippet/cpp/supporting-idispeventimpl_3.h)]

A implementação é quase completa. A última etapa diz respeito a assessoria e unadvising das interfaces externas.

## <a name="advising-and-unadvising-the-idispeventimpl-interfaces"></a>Conselho administrativo e Unadvising as Interfaces IDispEventImpl

A etapa final é implementar um método que será recomendar (ou não recomendar) todos os pontos de conexão nos momentos apropriados. Esse conselho administrativo deve ser feito antes da comunicação entre os clientes externos e seu objeto possa ocorrer. Antes de seu objeto se torna visível, cada interface de expedição externa suportada por seu objeto é consultado para interfaces de saída. Uma conexão é estabelecida e uma referência para a interface de saída é usada para manipular eventos do objeto. Esse procedimento é chamado de "conselho administrativo".

Depois que o objeto for concluído com as interfaces externas, as interfaces de saída devem ser notificadas de que eles não são mais usados por sua classe. Esse processo é conhecido como "unadvising".

Devido à natureza exclusiva de objetos COM, esse procedimento varia, em detalhes e execução entre implementações. Esses detalhes estão além do escopo deste tópico e não são abordados.

## <a name="see-also"></a>Consulte também

[Princípios básicos de objetos COM da ATL](../atl/fundamentals-of-atl-com-objects.md)
