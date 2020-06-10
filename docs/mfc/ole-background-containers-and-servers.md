---
title: 'tela de fundo OLE: contêineres e servidores'
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
ms.openlocfilehash: 7c3130ab9d8dff6551ef0ecbec43e5422dbdc4c4
ms.sourcegitcommit: c21b05042debc97d14875e019ee9d698691ffc0b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/09/2020
ms.locfileid: "84617906"
---
# <a name="ole-background-containers-and-servers"></a>tela de fundo OLE: contêineres e servidores

Um aplicativo de contêiner é um aplicativo que pode incorporar itens incorporados ou vinculados em seus próprios documentos. Os documentos gerenciados por um aplicativo de contêiner devem ser capazes de armazenar e exibir componentes de documento OLE, bem como os dados criados pelo próprio aplicativo. Um aplicativo de contêiner também deve permitir que os usuários insiram novos itens ou editem itens existentes ativando aplicativos de servidor quando necessário. Os requisitos de interface do usuário de um aplicativo de contêiner são listados no artigo [contêineres: problemas de interface do usuário](containers-user-interface-issues.md).

Um aplicativo de servidor ou de componente é um aplicativo que pode criar componentes de documento OLE para uso por aplicativos de contêiner. Os aplicativos de servidor geralmente dão suporte a arrastar e soltar ou copiar seus dados para a área de transferência para que um aplicativo de contêiner possa inserir os dados como um item incorporado ou vinculado. Um aplicativo pode ser um contêiner e um servidor.

A maioria dos servidores são aplicativos autônomos ou servidores completos; Eles podem ser executados como aplicativos autônomos ou podem ser iniciados por um aplicativo de contêiner. Um miniserver é um tipo especial de aplicativo de servidor que pode ser iniciado somente por um contêiner. Ele não pode ser executado como um aplicativo autônomo. Os servidores Microsoft Draw e Microsoft Graph são exemplos de miniservers.

Os contêineres e os servidores não se comunicam diretamente. Em vez disso, eles se comunicam por meio das bibliotecas de vínculo dinâmico (DLL) do sistema OLE. Essas DLLs fornecem funções que os contêineres e servidores chamam, e os contêineres e os servidores fornecem funções de retorno de chamada que as DLLs chamam.

Usando esse meio de comunicação, um contêiner não precisa saber os detalhes de implementação do aplicativo de servidor. Ele permite que um contêiner aceite itens criados por qualquer servidor sem precisar definir os tipos de servidores com os quais ele pode funcionar. Como resultado, o usuário de um aplicativo de contêiner pode tirar proveito de aplicativos e formatos de dados futuros. Se esses novos aplicativos forem componentes OLE, um documento composto poderá incorporar itens criados por esses aplicativos.

## <a name="see-also"></a>Consulte também

[tela de fundo OLE](ole-background.md)<br/>
[tela de fundo OLE: implementação MFC](ole-background-mfc-implementation.md)<br/>
[Contêineres](containers.md)<br/>
[Servidores](servers.md)<br/>
[Contêineres: itens clientes](containers-client-items.md)<br/>
[Servidores: itens de servidor](servers-server-items.md)
