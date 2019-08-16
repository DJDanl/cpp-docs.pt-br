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
ms.openlocfilehash: 2668d35c24e9d95440a96c5b3eda1fab7bbf3891
ms.sourcegitcommit: fcb48824f9ca24b1f8bd37d647a4d592de1cc925
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/15/2019
ms.locfileid: "69507992"
---
# <a name="ole-in-mfc"></a>OLE no MFC

Estes artigos explicam os conceitos básicos da programação OLE usando o MFC. O MFC fornece a maneira mais fácil de escrever programas que usam OLE:

- Para usar a edição Visual OLE (ativação in-loco).

- Para trabalhar como contêineres ou servidores OLE.

- Para implementar a funcionalidade do tipo "arrastar e soltar".

- Para trabalhar com dados de data e hora.

- Para gerenciar os dados de estado dos módulos do MFC, incluindo pontos de entrada de função DLL exportados, pontos de entrada de interface OLE/COM e pontos de entrada de procedimento de janela.

Você também pode usar a [automação](../mfc/automation.md).

> [!NOTE]
>  O termo OLE denota as tecnologias associadas à vinculação e à inserção, incluindo contêineres OLE, servidores OLE, itens OLE, ativação in-loco (ou edição Visual), rastreadores, arrastar e soltar e mesclagem de menu. O termo ativo aplica-se aos objetos Component Object Model (COM) e baseado em COM, como controles ActiveX. A automação OLE agora é chamada de automação.

## <a name="in-this-section"></a>Nesta seção

[Tela de fundo OLE](../mfc/ole-background.md)<br/>
Discute o OLE e fornece informações conceituais sobre como ele funciona.

[Ativação](../mfc/activation-cpp.md)<br/>
Descreve a função de ativação na edição de itens OLE.

[Contêineres](../mfc/containers.md)<br/>
Fornece links para usar contêineres em OLE.

[Objetos de dados e fontes de dados](../mfc/data-objects-and-data-sources-ole.md)<br/>
Fornece links para tópicos que abordam o uso `COleDataObject` das `COleDataSource` classes e.

[Arrastar e soltar](../mfc/drag-and-drop-ole.md)<br/>
Discute o uso de copiar e colar com OLE.

[Recursos e menus OLE](../mfc/menus-and-resources-ole.md)<br/>
Explica o uso de menus e recursos em aplicativos de documento OLE do MFC.

[Registro](../mfc/registration.md)<br/>
Discute a instalação e a inicialização do servidor.

[Servidores](../mfc/servers.md)<br/>
Descreve como criar itens OLE (ou componentes) para uso por aplicativos de contêiner.

[Controladores](../mfc/trackers.md)<br/>
Fornece informações sobre a `CRectTracker` classe, que fornece uma interface gráfica para permitir que os usuários interajam com itens de cliente OLE.

## <a name="related-sections"></a>Seções relacionadas

[Pontos de conexão](../mfc/connection-points.md)<br/>
Explica como implementar pontos de conexão (anteriormente conhecidos como pontos de conexão OLE) usando as classes `CCmdTarget` do `CConnectionPoint`MFC e o.

[Componentes COM de contêiner/servidor](../mfc/containers-advanced-features.md)<br/>
Descreve as etapas necessárias para incorporar recursos avançados opcionais em aplicativos de contêiner existentes.

[O Component Object Model](/windows/win32/com/the-component-object-model)<br/>
Descreve o uso de OLE sem MFC.

## <a name="see-also"></a>Consulte também

[Conceitos](../mfc/mfc-concepts.md)
