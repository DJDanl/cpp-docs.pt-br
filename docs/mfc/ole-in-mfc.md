---
title: "OLE no MFC | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "aplicativos [OLE], sobre OLE"
  - "MFC [C++], OLE e"
  - "OLE [C++]"
  - "Aplicativos OLE [C++], sobre OLE"
  - "modelo de objeto de componente OLE (COM)"
  - "Contêineres OLE, sobre OLE"
  - "Itens OLE"
ms.assetid: 5193479d-1239-4697-aea4-e82f92c707ab
caps.latest.revision: 11
caps.handback.revision: 7
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# OLE no MFC
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Esses artigos a seguir explicam os conceitos básicos de programação usando o OLE MFC.  MFC O fornece a maneira mais fácil de gravar programas que usam OLE:  
  
-   Para usar a edição visual OLE \(ativação in\-loco\).  
  
-   Para trabalhar com OLE DB como contêineres ou servidores.  
  
-   Para implementar a funcionalidade de arrastar e soltar.  
  
-   Para trabalhar com dados de data e hora.  
  
-   Para gerenciar os dados do estado dos módulos de MFC, inclusive pontos de entrada exportados de pontos de entrada da função da DLL, da interface de OLE\/COM, e pontos de entrada de procedimento da janela.  
  
 Você também pode usar [Automação](../mfc/automation.md) ou [Automação remoto](../mfc/remote-automation.md) para operar outro programa do programa.  
  
> [!NOTE]
>  O termo OLE denota as tecnologias associadas com vincular e inserir, inclusive contêiner OLE, servidores com OLE DB, OLE, itens ativação local \(ou edição visual\), perseguidores, arraste e solte, e mesclar o menu.  O termo ativa se aplica ao Component Object Model \(COM\) e objetos baseados em COM como controles ActiveX.  A Automação OLE é chamada agora Automação.  
  
## Nesta seção  
 [Plano de fundo OLE](../mfc/ole-background.md)  
 Discute OLE e fornece informações conceituais sobre como funciona.  
  
 [Ativação](../mfc/activation-cpp.md)  
 Descreve a função de ativação em editar itens com OLE DB.  
  
 [Containers](../mfc/containers.md)  
 Fornece links para usar contêineres em OLE.  
  
 [Objetos de dados e fontes de dados](../mfc/data-objects-and-data-sources-ole.md)  
 Fornece links a tópicos que discutem o uso de classes de `COleDataObject` e de `COleDataSource` .  
  
 [Drag and Drop \(Arrastar e Soltar\)](../mfc/drag-and-drop-ole.md)  
 Discute usando copiar e colar com OLE.  
  
 [Menus do e recursos](../mfc/menus-and-resources-ole.md)  
 Explica o uso de menus e recursos em aplicativos OLE do documento MFC.  
  
 [Registro](../mfc/registration.md)  
 Discute a instalação e a inicialização do servidor.  
  
 [Servidores](../mfc/servers.md)  
 Descreve como criar itens com OLE DB \(ou componentes\) para o uso de aplicativos do contêiner.  
  
 [Perseguidores](../mfc/trackers.md)  
 Fornece informações sobre a classe de `CRectTracker` , que fornece uma interface gráfica para que os usuários possam interagir com os itens do cliente.  
  
## Seções relacionadas  
 [Pontos de conexão](../mfc/connection-points.md)  
 Explica como implementar os pontos de conexão \(anteriormente conhecido como pontos de conexão OLE\) que usam as classes `CCmdTarget` e `CConnectionPoint`MFC.  
  
 [Componentes COM do contêiner\/servidor](../mfc/containers-advanced-features.md)  
 Descreve as etapas necessárias para inserir recursos avançados opcionais em aplicativos de contêiner existentes.  
  
 [O Component Object Model](http://msdn.microsoft.com/library/windows/desktop/ms694363)  
 Descreve o uso de OLE sem MFC.  
  
## Consulte também  
 [Conceitos](../mfc/mfc-concepts.md)