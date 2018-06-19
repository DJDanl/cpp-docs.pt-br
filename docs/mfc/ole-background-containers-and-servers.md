---
title: 'Plano de fundo OLE: Contêineres e servidores | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: conceptual
dev_langs:
- C++
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
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: f9f15ef532ba61a089f8adec9ed20f737c07eae2
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33348541"
---
# <a name="ole-background-containers-and-servers"></a>tela de fundo OLE: contêineres e servidores
Um aplicativo de contêiner é um aplicativo que pode incorporar itens incorporados ou vinculados em seus próprios documentos. Os documentos gerenciados por um aplicativo de contêiner devem ser capazes de armazenar e exibir os componentes de documento OLE, bem como os dados criados pelo próprio aplicativo. Um aplicativo de contêiner também deve permitir que os usuários inserir novos itens ou editar itens existentes Ativando aplicativos de servidor quando necessário. Os requisitos de interface do usuário de um aplicativo de contêiner estão listados no artigo [contêineres: emissões de Interface do usuário](../mfc/containers-user-interface-issues.md).  
  
 Um servidor de aplicativo ou componente é um aplicativo que pode criar componentes de documento OLE para uso por aplicativos de contêiner. Aplicativos de servidor geralmente oferecem suporte a arrastar e soltar ou copiar os dados na área de transferência para que um aplicativo de contêiner pode inserir os dados como um item inserido ou vinculado. Um aplicativo pode ser um contêiner e um servidor.  
  
 A maioria dos servidores são aplicativos autônomos ou servidores completos. eles ou podem ser executados como aplicativos autônomos ou podem ser iniciados por um aplicativo de contêiner. Um miniserver é um tipo especial de aplicativo de servidor que pode ser iniciado apenas por um contêiner. Ele não pode ser executado como um aplicativo autônomo. Servidores Microsoft Draw e Microsoft Graph são exemplos de miniservers.  
  
 Contêineres e servidores não se comunicam diretamente. Em vez disso, eles se comunicam por meio de bibliotecas de vínculo dinâmico do sistema OLE (DLL). Essas DLLs fornecem funções que chamam contêineres e servidores, e os contêineres e servidores fornecem funções de retorno de chamada que chamam as DLLs.  
  
 Usando essa forma de comunicação, um contêiner não precisa saber os detalhes da implementação do aplicativo de servidor. Ele permite que um contêiner aceitar os itens criados por qualquer servidor sem a necessidade de definir os tipos de servidores com a qual ele possa trabalhar. Como resultado, o usuário de um aplicativo de contêiner pode tirar proveito dos formatos de dados e aplicativos futuros. Se esses aplicativos novos componentes OLE, um documento composto será capaz de incorporar itens criados por esses aplicativos.  
  
## <a name="see-also"></a>Consulte também  
 [Plano de fundo OLE](../mfc/ole-background.md)   
 [Plano de fundo OLE: Implementação de MFC](../mfc/ole-background-mfc-implementation.md)   
 [Contêineres](../mfc/containers.md)   
 [Servidores](../mfc/servers.md)   
 [Contêineres: Itens clientes](../mfc/containers-client-items.md)   
 [Servidores: itens de servidor](../mfc/servers-server-items.md)

