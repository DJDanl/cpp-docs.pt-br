---
title: 'Tela de fundo OLE: Contêineres e servidores'
ms.date: 11/04/2016
helpviewer_keywords:
- OLE full-server applications [MFC]
- server applications [MFC], communication with containers
- full-server [MFC]
- server applications [MFC], requirements
- server applications [MFC], defined
- OLE server applications [MFC], about server applications
- server applications [MFC], full-server vs. mini-server
- OLE server applications [MFC], mini-server applications
- OLE containers [MFC], container applications
- containers [MFC], OLE container applications
- server applications [MFC]
ms.assetid: dafbb31d-096c-4654-b774-12900d832919
ms.openlocfilehash: c154562e58cf8f37d77df61556fe25b19ca54c70
ms.sourcegitcommit: c6f8e6c2daec40ff4effd8ca99a7014a3b41ef33
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/24/2019
ms.locfileid: "64346107"
---
# <a name="ole-background-containers-and-servers"></a>Tela de fundo OLE: Contêineres e servidores

Um aplicativo de contêiner é um aplicativo que pode incorporar itens inseridos ou vinculados em seus próprios documentos. Os documentos gerenciados por um aplicativo de contêiner devem ser capazes de armazenar e exibir componentes de documento OLE, bem como os dados criados pelo próprio aplicativo. Um aplicativo de contêiner também deve permitir que os usuários a inserir novos itens ou editar itens existentes por meio da ativação de aplicativos de servidor quando necessário. Os requisitos de interface do usuário de um aplicativo de contêiner estão listados no artigo [contêineres: Problemas da Interface do usuário](../mfc/containers-user-interface-issues.md).

Um servidor de aplicativo ou componente é um aplicativo que pode criar componentes de documento OLE para uso por aplicativos de contêiner. Aplicativos de servidor geralmente oferecem suporte a arrastar e soltar ou copiar seus dados na área de transferência, de modo que um aplicativo de contêiner pode inserir os dados como um item vinculado ou inserido. Um aplicativo pode ser um contêiner e um servidor.

A maioria dos servidores são aplicativos autônomos ou servidores completos; Eles também podem ser executados como aplicativos autônomos ou podem ser iniciados por um aplicativo de contêiner. Um miniserver é um tipo especial de aplicativo de servidor que pode ser iniciado apenas por um contêiner. Ele não pode ser executado como um aplicativo autônomo. Servidores Microsoft Draw e o Microsoft Graph são exemplos de miniservers.

Contêineres e servidores não se comunicam diretamente. Em vez disso, eles se comunicam por meio de bibliotecas de vínculo dinâmico (DLL) do sistema OLE. Essas DLLs fornecem funções que chamam a contêineres e servidores e os contêineres e servidores fornecem funções de retorno de chamada que chamam as DLLs.

Usando esse meios de comunicação, um contêiner não precisa saber os detalhes da implementação do aplicativo de servidor. Ele permite que um contêiner aceitar itens criados por qualquer servidor sem ter que definir os tipos de servidores com o qual ele pode funcionar. Como resultado, o usuário de um aplicativo de contêiner pode tirar proveito dos formatos de dados e aplicativos futuros. Se esses novos aplicativos são componentes do OLE, em seguida, um documento composto poderá incorporar os itens criados por esses aplicativos.

## <a name="see-also"></a>Consulte também

[Tela de fundo OLE](../mfc/ole-background.md)<br/>
[Tela de fundo OLE: implementação do MFC](../mfc/ole-background-mfc-implementation.md)<br/>
[Contêineres](../mfc/containers.md)<br/>
[Servidores](../mfc/servers.md)<br/>
[Contêineres: itens de cliente](../mfc/containers-client-items.md)<br/>
[Servidores: itens de servidor](../mfc/servers-server-items.md)
