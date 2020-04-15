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
ms.openlocfilehash: 31beff30a067416f71029c18051f214c8d4429de
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81329317"
---
# <a name="supporting-idispeventimpl"></a>Suporte a IDispEventImpl

A classe modelo [IDispEventImpl](../atl/reference/idispeventimpl-class.md) pode ser usada para fornecer suporte para sinks de ponto de conexão em sua classe ATL. Um dissipador de ponto de conexão permite que sua classe manuseie eventos disparados de objetos COM externos. Esses dissipadores de ponto de conexão são mapeados com um mapa de dissipação de eventos, fornecido pela sua classe.

Para implementar adequadamente um dissipador de ponto de conexão para sua classe, as seguintes etapas devem ser concluídas:

- Importe as bibliotecas de tipo para cada objeto externo

- Declare `IDispEventImpl` as interfaces

- Declare um mapa de dissipação de eventos

- Aconselhar e desaconselhar os pontos de conexão

As etapas envolvidas na implementação de um dissipador de ponto de conexão são todas realizadas modificando apenas o arquivo de cabeçalho (.h) da sua classe.

## <a name="importing-the-type-libraries"></a>Importando as Bibliotecas de Tipo

Para cada objeto externo cujos eventos você deseja lidar, você deve importar a biblioteca do tipo. Esta etapa define os eventos que podem ser manipulados e fornece informações que são usadas ao declarar o mapa do dissipador de eventos. A [diretiva #import](../preprocessor/hash-import-directive-cpp.md) pode ser usada para isso. Adicione as `#import` linhas diretivas necessárias para cada interface de despacho que você suportará ao arquivo de cabeçalho (.h) da sua classe.

O exemplo a seguir importa a biblioteca`MSCAL.Calendar.7`de tipo de um servidor COM externo ( ):

[!code-cpp[NVC_ATL_Windowing#141](../atl/codesnippet/cpp/supporting-idispeventimpl_1.h)]

> [!NOTE]
> Você deve ter `#import` uma declaração separada para cada biblioteca do tipo externo que você suportará.

## <a name="declaring-the-idispeventimpl-interfaces"></a>Declarando as Interfaces IDispEventImpl

Agora que você importou as bibliotecas de tipo de `IDispEventImpl` cada interface de despacho, você precisa declarar interfaces separadas para cada interface de despacho externo. Modifique a declaração de `IDispEventImpl` sua classe adicionando uma declaração de interface para cada objeto externo. Para obter mais informações sobre os parâmetros, consulte [IDispEventImpl](../atl/reference/idispeventimpl-class.md).

O código a seguir declara dois dissipadores de ponto de conexão, para a `DCalendarEvents` interface, para o objeto COM implementado pela classe `CMyCompositCtrl2`:

[!code-cpp[NVC_ATL_Windowing#142](../atl/codesnippet/cpp/supporting-idispeventimpl_2.h)]

## <a name="declaring-an-event-sink-map"></a>Declarando um mapa de dissipação de eventos

Para que as notificações do evento sejam tratadas pela função adequada, sua classe deve encaminhar cada evento para o manipulador correto. Isso é conseguido declarando um mapa de afundamento de eventos.

A ATL fornece várias macros, [BEGIN_SINK_MAP,](reference/composite-control-macros.md#begin_sink_map) [END_SINK_MAP](reference/composite-control-macros.md#end_sink_map)e [SINK_ENTRY_EX,](reference/composite-control-macros.md#sink_entry_ex)que facilitam esse mapeamento. O formato padrão é o seguinte:

```cpp
BEGIN_SINK_MAP(comClass)
  SINK_ENTRY_EX(id, iid, dispid, func)
  . . . //additional external event entries
END_SINK_MAP()
```

O exemplo a seguir declara um mapa de sumidouro de eventos com dois manipuladores de eventos:

[!code-cpp[NVC_ATL_Windowing#136](../atl/codesnippet/cpp/supporting-idispeventimpl_3.h)]

A implementação está quase completa. A última etapa diz respeito à assessoria e desaconselhamento das interfaces externas.

## <a name="advising-and-unadvising-the-idispeventimpl-interfaces"></a>Aconselhando e desaconselhando as interfaces IDispEventImpl

O passo final é implementar um método que aconselhará (ou desaconselhará) todos os pontos de conexão nos momentos apropriados. Esta assessoria deve ser feita antes que a comunicação entre os clientes externos e seu objeto possa ocorrer. Antes que seu objeto se torne visível, cada interface de despacho externa suportada pelo seu objeto é consultada para interfaces de saída. Uma conexão é estabelecida e uma referência à interface de saída é usada para lidar com eventos do objeto. Este procedimento é chamado de "aconselhamento".

Depois que seu objeto for concluído com as interfaces externas, as interfaces de saída devem ser notificadas de que não são mais usadas pela sua classe. Esse processo é chamado de "desaconselhável".

Devido à natureza única dos objetos COM, este procedimento varia, em detalhes e execução, entre as implementações. Esses detalhes estão além do escopo deste tópico e não são abordados.

## <a name="see-also"></a>Confira também

[Fundamentos dos Objetos ATL COM](../atl/fundamentals-of-atl-com-objects.md)
