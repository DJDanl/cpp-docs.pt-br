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
ms.openlocfilehash: 09d80e7c45875ad2e6ed8b599d4e01d2110d562f
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62378306"
---
# <a name="ole-in-mfc"></a>OLE no MFC

Estes artigos explicam os conceitos básicos da programação de OLE usando o MFC. MFC fornece a maneira mais fácil escrever programas que usam OLE:

- Para usar OLE visual edição (ativação in-loco).

- Para funcionar como contêineres OLE ou servidores.

- Para implementar a funcionalidade de arrastar e soltar.

- Para trabalhar com dados de data e hora.

- Para gerenciar os dados de estado do MFC, módulos, incluindo exportados pontos de entrada da função DLL, pontos de entrada da interface OLE/COM e pontos de entrada do procedimento de janela.

Você também pode usar [automação](../mfc/automation.md).

> [!NOTE]
>  O termo que OLE denota as tecnologias associadas com a vinculação e incorporação, incluindo contêineres OLE, servidores OLE, itens OLE, ativação no local (ou edição visual), rastreadores, arrastar e soltar e mesclagem de menu. O termo ativo se aplica ao modelo COM (Component Object) e COM base em objetos, como controles ActiveX. Automação OLE agora é chamada de automação.

## <a name="in-this-section"></a>Nesta seção

[Tela de fundo OLE](../mfc/ole-background.md)<br/>
Discute OLE e fornece informações conceituais sobre como ele funciona.

[Ativação](../mfc/activation-cpp.md)<br/>
Descreve a função de ativação na edição de itens OLE.

[Contêineres](../mfc/containers.md)<br/>
Fornece links para o uso de contêineres OLE.

[Objetos de dados e fontes de dados](../mfc/data-objects-and-data-sources-ole.md)<br/>
Fornece links para tópicos que abordam o uso do `COleDataObject` e `COleDataSource` classes.

[Arrastar e soltar](../mfc/drag-and-drop-ole.md)<br/>
Discute o uso de copiar e colar com OLE.

[Menus e recursos OLE](../mfc/menus-and-resources-ole.md)<br/>
Explica o uso de menus e recursos em aplicativos de documento OLE do MFC.

[Registro](../mfc/registration.md)<br/>
Discute a inicialização e instalação do servidor.

[Servidores](../mfc/servers.md)<br/>
Descreve como criar OLE itens (ou componentes) para uso por aplicativos de contêiner.

[Controladores](../mfc/trackers.md)<br/>
Fornece informações sobre o `CRectTracker` classe, que fornece uma interface gráfica para permitir que os usuários interagem com itens de cliente OLE.

## <a name="related-sections"></a>Seções relacionadas

[Pontos de conexão](../mfc/connection-points.md)<br/>
Explica como implementar pontos de conexão (anteriormente conhecidos como pontos de conexão OLE) usando as classes MFC `CCmdTarget` e `CConnectionPoint`.

[Componentes do contêiner/servidor COM](../mfc/containers-advanced-features.md)<br/>
Descreve as etapas necessárias para incorporar recursos avançados opcionais em aplicativos de contêiner existentes.

[O Component Object Model](/windows/desktop/com/the-component-object-model)<br/>
Descreve como usar o OLE sem MFC.

## <a name="see-also"></a>Consulte também

[Conceitos](../mfc/mfc-concepts.md)
