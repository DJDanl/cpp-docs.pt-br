---
title: "Servidores | Microsoft Docs"
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
  - "servidor completo"
  - "miniservidor"
  - "aplicativos de servidor OLE"
  - "aplicativos de servidor OLE, ativação"
  - "aplicativos de servidor OLE, tipos de servidor"
  - "aplicativos de servidor"
  - "servidores"
ms.assetid: e45172e8-eae3-400a-8139-0fa009a42fdc
caps.latest.revision: 9
caps.handback.revision: 5
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Servidores
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Um aplicativo de servidor \(ou o aplicativo componente\) criam itens com OLE DB \(ou componentes\) para o uso de aplicativos do contêiner.  Um aplicativo de servidor visual da edição também da suporte à edição ou o ativação in\-loco visual.  Outra forma de servidor OLE é [servidor de automação](../mfc/automation-servers.md).  Alguns aplicativos para servidores só dão suporte à criação de itens digitados; outro oferecem suporte à criação de itens digitados e vinculados.  Alguns vincular só dão suporte, embora isso é raro.  Todos os aplicativos de servidor devem oferecer suporte à ativação por aplicativos de contêiner quando o usuário deseja editar um item.  Um aplicativo pode ser um contêiner e um servidor.  Ou é possível inserir dados em seus documentos, e cria os dados que podem ser inseridos como itens nos documentos de outros aplicativos.  
  
 Um miniserver é um tipo especial de aplicativo de servidor que pode ser iniciado apenas por um contêiner.  Um descompasso da Microsoft e o gráfico do Microsoft são exemplos de miniservers.  Um miniserver não armazena documentos como arquivos em disco.  Em vez disso, a leitura de seus documentos de escreve\-os e aos itens em documentos que pertencem a contêiner.  No resultado, um miniserver oferece suporte a inserir apenas, não vinculando.  
  
 Um servidor completo pode ser executado como um aplicativo autônomo ou ser iniciado por um aplicativo do contêiner.  Um servidor completo pode armazenar documentos como arquivos em disco.  Pode suportar inserir apenas, inserção e vincular, ou vincular somente.  O usuário de um aplicativo de contêiner pode criar um item inserido escolhendo o comando recortar ou de cópia no servidor e o comando da pasta no contêiner.  Um item vinculado é criado escolhendo o comando imprimir do servidor e o comando do link da pasta no contêiner.  Como alternativa, o usuário pode criar um item inserido ou vinculado usando a caixa de diálogo do objeto de inserção.  
  
 A tabela a seguir resume as características dos diferentes tipos de servidores:  
  
### Características do servidor  
  
|Tipo de servidor|Oferece suporte a várias instâncias|Itens pelo documento|Documentos pela instância|  
|----------------------|-----------------------------------------|--------------------------|-------------------------------|  
|Miniserver|Sim|1|1|  
|O servidor de SDI completo|Sim|1 \(se vincular tem suporte, 1 ou mais\)|1|  
|Servidor full\-scale MDI|Nenhum \(não obrigatória\)|1 \(se vincular tem suporte, 1 ou mais\)|0 ou mais|  
  
 Um aplicativo de servidor deve oferecer suporte a vários contêineres simultaneamente, se mais de um contêiner é usado para editar um item inserido ou vinculado.  Se o servidor é um aplicativo de SDI \(ou um miniserver com uma interface da caixa de diálogo\), várias instâncias de servidor devem poder executar simultaneamente.  Isso permite uma instância separada do aplicativo controlar cada solicitação do contêiner.  
  
 Se o servidor é um aplicativo MDI, pode criar uma nova janela filho MDI cada vez que um contêiner precisa editar um item.  Dessa forma, uma única instância do aplicativo poderá oferecer suporte a vários contêineres.  
  
 Seu aplicativo de servidor deve informar a DLL do sistema do que fazer se uma instância de servidor já está sendo executada enquanto outro contêiner solicitar seus serviços: se deve iniciar uma nova instância do servidor ou direcionar solicitações de todos os contêineres a uma instância do servidor.  
  
 Para obter mais detalhes sobre servidores, consulte:  
  
-   [Servidores: Implementando um servidor](../mfc/servers-implementing-a-server.md)  
  
-   [Servidores: Implementando documentos do servidor](../mfc/servers-implementing-server-documents.md)  
  
-   [Servidores: Implementando o windows no local do quadro](../Topic/Servers:%20Implementing%20In-Place%20Frame%20Windows.md)  
  
-   [Servidores: Itens do servidor](../mfc/servers-server-items.md)  
  
-   [Servidores: Problemas da interface do usuário](../mfc/servers-user-interface-issues.md)  
  
## Consulte também  
 [OLE](../mfc/ole-in-mfc.md)   
 [Contêineres](../mfc/containers.md)   
 [Contêineres: recursos avançados](../mfc/containers-advanced-features.md)   
 [Menus e recursos \(OLE\)](../mfc/menus-and-resources-ole.md)   
 [Registro](../mfc/registration.md)   
 [Servidores de automação](../mfc/automation-servers.md)