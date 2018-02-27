---
title: OLE no MFC | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
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
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: d13baf7960b329e56cfce24011f4c15599cdda8b
ms.sourcegitcommit: 6002df0ac79bde5d5cab7bbeb9d8e0ef9920da4a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/14/2018
---
# <a name="ole-in-mfc"></a>OLE no MFC
Esses artigos explicam os fundamentos da programação OLE usando MFC. MFC fornece a maneira mais fácil para gravar programas que usam OLE:  
  
-   Para usar OLE visual edição (ativação no local).  
  
-   Para funcionar como servidores ou contêineres OLE.  
  
-   Para implementar a funcionalidade de arrastar e soltar.  
  
-   Para trabalhar com dados de data e hora.  
  
-   Para gerenciar os dados de estado do MFC módulos, incluindo exportados pontos de entrada da função DLL, pontos de entrada da interface OLE/COM e pontos de entrada do procedimento de janela.  
  
 Você também pode usar [automação](../mfc/automation.md).  
  
> [!NOTE]
>  O termo que OLE indica as tecnologias associadas vinculando e inserindo, incluindo contêineres OLE, servidores OLE, itens OLE, ativação no local (ou edição visual), controladores, arrastar e soltar e mesclagem de menu. O termo Active aplica-se ao modelo de objeto de componente (COM) e COM base em objetos, como controles ActiveX. Automação OLE agora é chamada de automação.  
  
## <a name="in-this-section"></a>Nesta seção  
 [Tela de fundo OLE](../mfc/ole-background.md)  
 Discute OLE e fornece informações conceituais sobre como ele funciona.  
  
 [Ativação](../mfc/activation-cpp.md)  
 Descreve a função de ativação na edição de itens OLE.  
  
 [Contêineres](../mfc/containers.md)  
 Fornece links para o uso de contêineres em OLE.  
  
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
  
 [Componentes COM de contêiner/servidor](../mfc/containers-advanced-features.md)  
 Descreve as etapas necessárias para incorporar recursos avançados opcionais em aplicativos existentes do contêiner.  
  
 [O modelo de objeto do componente](http://msdn.microsoft.com/library/windows/desktop/ms694363)  
 Descreve como usar OLE sem MFC.  
  
## <a name="see-also"></a>Consulte também  
 [Conceitos](../mfc/mfc-concepts.md)

