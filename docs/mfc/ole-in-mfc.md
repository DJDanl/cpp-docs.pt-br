---
title: OLE no MFC
ms.date: 11/04/2016
helpviewer_keywords:
- MFC, OLE and
- OLE items
- OLE applications [MFC], about OLE
- OLE [MFC]
- OLE containers [MFC], about OLE
- applications [OLE], about OLE
- OLE component object model (COM)
ms.assetid: 5193479d-1239-4697-aea4-e82f92c707ab
ms.openlocfilehash: 2594531df63bcd62cdaec44fbc3668ea68990922
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81366891"
---
# <a name="ole-in-mfc"></a>OLE no MFC

Esses artigos explicam os fundamentos da programação oLE usando MFC. O MFC fornece a maneira mais fácil de escrever programas que usam OLE:

- Para usar a edição visual OLE (ativação no local).

- Para funcionar como contêineres ou servidores OLE.

- Para implementar a funcionalidade de arrastar e soltar.

- Para trabalhar com dados de data e hora.

- Para gerenciar os dados estaduais dos módulos MFC, incluindo pontos de entrada de função DLL exportados, pontos de entrada da interface OLE/COM e pontos de entrada do procedimento de janela.

Você também pode usar [automação](../mfc/automation.md).

> [!NOTE]
> O termo OLE denota as tecnologias associadas à vinculação e incorporação, incluindo contêineres OLE, servidores OLE, itens OLE, ativação no local (ou edição visual), rastreadores, arrastar e soltar e fusão de menus. O termo Ativo se aplica ao Modelo de Objeto Componente (COM) e objetos baseados em COM, como controles ActiveX. A Automação OLE agora se chama Automação.

## <a name="in-this-section"></a>Nesta seção

[tela de fundo OLE](../mfc/ole-background.md)<br/>
Discute o OLE e fornece informações conceituais sobre como funciona.

[Ativação](../mfc/activation-cpp.md)<br/>
Descreve o papel da ativação na edição de itens OLE.

[Contêineres](../mfc/containers.md)<br/>
Fornece links para o uso de recipientes no OLE.

[Objetos de dados e fontes de dados](../mfc/data-objects-and-data-sources-ole.md)<br/>
Fornece links para tópicos `COleDataObject` que `COleDataSource` discutem o uso do e das classes.

[Arrastar e soltar](../mfc/drag-and-drop-ole.md)<br/>
Discute-se usando cópia e cola com OLE.

[Menus e recursos oLE](../mfc/menus-and-resources-ole.md)<br/>
Explica o uso de menus e recursos em aplicativos de documentos MFC OLE.

[Registro](../mfc/registration.md)<br/>
Discute a instalação e inicialização do servidor.

[Servidores](../mfc/servers.md)<br/>
Descreve como criar itens OLE (ou componentes) para uso por aplicativos de contêiner.

[Controladores](../mfc/trackers.md)<br/>
Fornece informações `CRectTracker` sobre a classe, que fornece uma interface gráfica para permitir que os usuários interajam com itens clientes OLE.

## <a name="related-sections"></a>Seções relacionadas

[Pontos de conexão](../mfc/connection-points.md)<br/>
Explica como implementar pontos de conexão (anteriormente conhecidos como `CCmdTarget` `CConnectionPoint`pontos de conexão OLE) usando as classes MFC e .

[Componentes container/server COM](../mfc/containers-advanced-features.md)<br/>
Descreve as etapas necessárias para incorporar recursos avançados opcionais em aplicativos de contêineres existentes.

[O Component Object Model](/windows/win32/com/the-component-object-model)<br/>
Descreve o uso de OLE sem MFC.

## <a name="see-also"></a>Confira também

[Conceitos](../mfc/mfc-concepts.md)
