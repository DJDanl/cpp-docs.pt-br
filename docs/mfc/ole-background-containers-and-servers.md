---
title: "Plano de fundo OLE: cont&#234;ineres e servidores | Microsoft Docs"
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
  - "contêineres, aplicativos de contêiner OLE"
  - "servidor completo"
  - "Contêineres OLE, aplicativos de contêiner"
  - "aplicativos de servidor completo OLE"
  - "aplicativos de servidor OLE, sobre aplicativos de servidor"
  - "aplicativos de servidor OLE, aplicativos de miniservidor"
  - "aplicativos de servidor"
  - "aplicativos de servidor, comunicação com contêineres"
  - "aplicativos de servidor, definido"
  - "aplicativos de servidor, de servidor completo vs. miniservidor"
  - "aplicativos de servidor, requisitos"
ms.assetid: dafbb31d-096c-4654-b774-12900d832919
caps.latest.revision: 9
caps.handback.revision: 5
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Plano de fundo OLE: cont&#234;ineres e servidores
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Um aplicativo de contêiner é um aplicativo que pode inserir itens inseridos ou vinculados em seus próprios documentos.  Os documentos gerenciados por um aplicativo de contêiner deve ser capaz de armazenar e exibir componentes com OLE DB do documento bem como os dados criados pelo próprio aplicativo.  Um aplicativo de contêineres também deve permitir que os usuários insiram novos itens ou editar itens existentes ativando aplicativos de servidor quando necessário.  Os requisitos da interface do usuário de um aplicativo de contêineres são listados no artigo [Contêiner: Problemas da interface do usuário](../mfc/containers-user-interface-issues.md).  
  
 Um aplicativo de aplicativo de servidor ou do componente é um aplicativo que pode criar componentes com OLE DB do documento para uso por aplicativos de contêiner.  Aplicativos para servidores de suporte geralmente arraste e solte ou copiar seus dados para a área de transferência de modo que um aplicativo de contêiner pode inserir os dados como um item inserido ou vinculado.  Um aplicativo pode ser um contêiner e um servidor.  
  
 A maioria dos servidores autônomos são aplicativos ou servidores completas; podem ser executados como aplicativos autônomos ou podem ser iniciados por um aplicativo do contêiner.  Um miniserver é um tipo especial de aplicativo de servidor que pode ser iniciado apenas por um contêiner.  Não pode ser executado como um aplicativo autônomo.  Um descompasso da Microsoft e os servidores de gráfico do Microsoft são exemplos de miniservers.  
  
 Os contêineres e os servidores não se comunicam diretamente.  Em vez disso, se comunicam com OLE DB \(DLL\) em bibliotecas de vínculo dinâmico\) nativa do sistema.  Esses DLL fornecem funções que os contêineres e a chamada de servidores, e os contêineres e servidores fornece as funções de retorno de chamada que chamam as dlls.  
  
 Usar essa mídia de comunicação, um contêiner não precisa saber os detalhes de implementação do aplicativo para servidores.  Permite que um contêiner aceita os itens criados por qualquer servidor sem precisar definir os tipos de servidores com que pode trabalhar.  No resultado, o usuário de um aplicativo de contêiner pode tirar proveito dos aplicativos e formatos de dados futuros.  Se essas novos aplicativos são componentes do, um documento composto poderá inserir os itens criados por esses aplicativos.  
  
## Consulte também  
 [Plano de fundo OLE](../mfc/ole-background.md)   
 [Plano de fundo OLE: implementação MFC](../mfc/ole-background-mfc-implementation.md)   
 [Contêineres](../mfc/containers.md)   
 [Servidores](../mfc/servers.md)   
 [Contêineres: itens clientes](../mfc/containers-client-items.md)   
 [Servidores: itens de servidor](../mfc/servers-server-items.md)