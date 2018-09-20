---
title: Servidores | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- OLE server applications [MFC]
- OLE server applications [MFC], activation
- full-server
- servers
- mini-server
- OLE server applications [MFC], server types
- server applications [MFC]
ms.assetid: e45172e8-eae3-400a-8139-0fa009a42fdc
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: dee0fd14e2e2d87155bfafefca6fa17e1d77135f
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46375372"
---
# <a name="servers"></a>Servidores

Um aplicativo de servidor (ou o aplicativo de componente) cria OLE itens (ou componentes) para uso por aplicativos de contêiner. Um aplicativo de servidor de edição visual também dá suporte à edição visual ou ativação in-loco. Outra forma de servidor OLE é um [servidor de automação](../mfc/automation-servers.md). Alguns aplicativos de servidor suportam apenas a criação de itens inseridos; outros suportam a criação de itens vinculados e inseridos. Alguns oferecem suporte a vinculação apenas, embora isso seja raro. Todos os aplicativos de servidor devem dar suporte à ativação por aplicativos de contêiner quando o usuário desejar editar um item. Um aplicativo pode ser um contêiner e um servidor. Em outras palavras, ele pode ambos incorporar dados em seus documentos e criar dados que possam ser incorporados como itens em documentos de outros aplicativos.

Um miniserver é um tipo especial de aplicativo de servidor que pode ser iniciado apenas por um contêiner. Microsoft Draw e o Microsoft Graph são exemplos de miniservers. Um miniserver não armazena documentos como arquivos no disco. Em vez disso, ele lê seus documentos do e grava-as em itens em documentos que pertencem a contêineres. Como resultado, um miniserver dá suporte à inserção de apenas, não vinculação.

Um servidor completo pode ser executado como um aplicativo autônomo ou iniciado por um aplicativo de contêiner. Um servidor completo pode armazenar documentos como arquivos no disco. Ele pode dar suporte a incorporação apenas, ambos os recursos de incorporação e vinculação ou vinculação apenas. O usuário de um aplicativo de contêiner pode criar um item inserido, escolhendo o comando Recortar ou copiar no servidor e o comando Colar no contêiner. Um item vinculado é criado, escolhendo o comando de cópia no servidor e o comando Colar vínculo no contêiner. Como alternativa, o usuário pode criar um item vinculado ou inserido usando a caixa de diálogo Inserir objeto.

A tabela a seguir resume as características de diferentes tipos de servidores:

### <a name="server-characteristics"></a>Características do servidor

|Tipo de servidor|Dá suporte a várias instâncias|Itens por documento|Documentos por instância|
|--------------------|---------------------------------|------------------------|----------------------------|
|Miniserver|Sim|1|1|
|Servidor de SDI completo|Sim|1 (se houver suporte para a vinculação, 1 ou mais)|1|
|Servidor completo do MDI|Nenhum (não obrigatório)|1 (se houver suporte para a vinculação, 1 ou mais)|0 ou mais|

Um aplicativo de servidor deve dar suporte a vários contêineres ao mesmo tempo, que será usado mais de um contêiner para editar um item vinculado ou inserido. Se o servidor for um aplicativo SDI (ou um miniserver com uma interface de caixa de diálogo), várias instâncias do servidor devem ser capazes de executar simultaneamente. Isso permite que uma instância separada do aplicativo para lidar com cada solicitação de contêiner.

Se o servidor for um aplicativo MDI, ele pode criar uma nova janela filho MDI sempre que precisa de um contêiner para editar um item. Dessa forma, uma única instância do aplicativo pode dar suporte a vários contêineres.

O aplicativo de servidor deve informar as DLLs do sistema OLE o que fazer se uma instância do servidor já está em execução quando outro contêiner solicita seus serviços: ele deve iniciar uma nova instância do servidor ou direcionar as solicitações de todos os contêineres para uma instância das servidor.

Para obter mais detalhes sobre servidores, consulte:

- [Servidores: implementando um servidor](../mfc/servers-implementing-a-server.md)

- [Servidores: implementando documentos de servidor](../mfc/servers-implementing-server-documents.md)

- [Servidores: implementando janelas de quadro in-loco](../mfc/servers-implementing-in-place-frame-windows.md)

- [Servidores: itens de servidor](../mfc/servers-server-items.md)

- [Servidores: problemas da interface do usuário](../mfc/servers-user-interface-issues.md)

## <a name="see-also"></a>Consulte também

[OLE](../mfc/ole-in-mfc.md)<br/>
[Contêineres](../mfc/containers.md)<br/>
[Contêineres: funcionalidades avançadas](../mfc/containers-advanced-features.md)<br/>
[Menus e recursos (OLE)](../mfc/menus-and-resources-ole.md)<br/>
[Registro](../mfc/registration.md)<br/>
[Servidores de automação](../mfc/automation-servers.md)

