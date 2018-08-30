---
title: OLE no MFC | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- MFC, OLE and
- OLE items
- OLE applications [MFC], about OLE
- OLE [MFC]
- OLE containers [MFC], about OLE
- applications [OLE], about OLE
- OLE component object model (COM)
ms.assetid: 5193479d-1239-4697-aea4-e82f92c707ab
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: c6c39c47762f4ac61e3192d5d3ecef997c3078bc
ms.sourcegitcommit: 9a0905c03a73c904014ec9fd3d6e59e4fa7813cd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/29/2018
ms.locfileid: "43204108"
---
# <a name="ole-in-mfc"></a>OLE no MFC
Estes artigos explicam os conceitos básicos da programação de OLE usando o MFC. MFC fornece a maneira mais fácil escrever programas que usam OLE:  
  
-   Para usar OLE visual edição (ativação in-loco).  
  
-   Para funcionar como contêineres OLE ou servidores.  
  
-   Para implementar a funcionalidade de arrastar e soltar.  
  
-   Para trabalhar com dados de data e hora.  
  
-   Para gerenciar os dados de estado do MFC, módulos, incluindo exportados pontos de entrada da função DLL, pontos de entrada da interface OLE/COM e pontos de entrada do procedimento de janela.  
  
 Você também pode usar [automação](../mfc/automation.md).  
  
> [!NOTE]
>  O termo que OLE denota as tecnologias associadas com a vinculação e incorporação, incluindo contêineres OLE, servidores OLE, itens OLE, ativação no local (ou edição visual), rastreadores, arrastar e soltar e mesclagem de menu. O termo ativo se aplica ao modelo COM (Component Object) e COM base em objetos, como controles ActiveX. Automação OLE agora é chamada de automação.  
  
## <a name="in-this-section"></a>Nesta seção  
 [Tela de fundo OLE](../mfc/ole-background.md)  
 Discute OLE e fornece informações conceituais sobre como ele funciona.  
  
 [Ativação](../mfc/activation-cpp.md)  
 Descreve a função de ativação na edição de itens OLE.  
  
 [Contêineres](../mfc/containers.md)  
 Fornece links para o uso de contêineres OLE.  
  
 [Objetos de dados e fontes de dados](../mfc/data-objects-and-data-sources-ole.md)  
 Fornece links para tópicos que abordam o uso do `COleDataObject` e `COleDataSource` classes.  
  
 [Arrastar e soltar](../mfc/drag-and-drop-ole.md)  
 Discute o uso de copiar e colar com OLE.  
  
 [Menus e recursos OLE](../mfc/menus-and-resources-ole.md)  
 Explica o uso de menus e recursos em aplicativos de documento OLE do MFC.  
  
 [Registro](../mfc/registration.md)  
 Discute a inicialização e instalação do servidor.  
  
 [Servidores](../mfc/servers.md)  
 Descreve como criar OLE itens (ou componentes) para uso por aplicativos de contêiner.  
  
 [Controladores](../mfc/trackers.md)  
 Fornece informações sobre o `CRectTracker` classe, que fornece uma interface gráfica para permitir que os usuários interagem com itens de cliente OLE.  
  
## <a name="related-sections"></a>Seções relacionadas  
 [Pontos de conexão](../mfc/connection-points.md)  
 Explica como implementar pontos de conexão (anteriormente conhecidos como pontos de conexão OLE) usando as classes MFC `CCmdTarget` e `CConnectionPoint`.  
  
 [Componentes do contêiner/servidor COM](../mfc/containers-advanced-features.md)  
 Descreve as etapas necessárias para incorporar recursos avançados opcionais em aplicativos de contêiner existentes.  
  
 [O modelo de objeto de componente](/windows/desktop/com/the-component-object-model)  
 Descreve como usar o OLE sem MFC.  
  
## <a name="see-also"></a>Consulte também  
 [Conceitos](../mfc/mfc-concepts.md)

