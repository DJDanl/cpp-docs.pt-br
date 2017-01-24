---
title: "Menus e recursos (OLE) | Microsoft Docs"
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
  - "aplicativos [OLE], menus e recursos"
  - "contêineres [C++], aplicativos de contêiner OLE"
  - "ativação no local, Menus e recursos OLE"
  - "menus [C++], Aplicativos de documento OLE"
  - "Aplicativos OLE [C++], menus e recursos"
  - "Contêineres OLE, menus e recursos"
  - "Menus e recursos OLE"
  - "aplicativos de servidor OLE, menus e recursos"
  - "Servidores de edição visual OLE"
  - "aplicativos de servidor, Menus e recursos OLE"
  - "barras de status, Aplicativos de documento OLE"
  - "edição de cadeia de caracteres, aplicativos de edição visual"
  - "tabelas de cadeias de caracteres, aplicativos de edição visual"
  - "barras de ferramentas [C++], Aplicativos de documento OLE"
  - "edição visual, menus e recursos de aplicativo"
ms.assetid: 52bfa086-7d3d-466f-94c7-c7061f3bdb3a
caps.latest.revision: 9
caps.handback.revision: 5
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Menus e recursos (OLE)
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Este grupo de artigos explica o uso de menus e recursos em aplicativos OLE do documento MFC.  
  
 Requisitos adicionais de locais visuais OLE de edição no menu e outros recursos fornecidos por aplicativos OLE do documento porque há um número de modos nos quais os aplicativos do contêiner e do servidor \(componente\) podem ser iniciados e usado.  Por exemplo, um aplicativo de servidor completo pode executar em qualquer um de três modos:  
  
-   Suporte apenas.  
  
-   No lugar, para editar um item dentro do contexto de um contêiner.  
  
-   Abrir, editando um item fora do contexto do respectivo contêiner, frequentemente em uma janela separada.  
  
 Isso exige três layouts separados no menu, um para cada modo que o aplicativo.  As tabelas de aceleração também são necessárias para cada novo modo.  Um aplicativo de contêiner pode ou não der suporte à ativação in\-loco; em caso afirmativo, precisa de uma nova estrutura de menu e tabelas de aceleração associados.  
  
 O ativação in\-loco exige que o contêiner e aplicativos para servidores devem para negociar o menu, na barra de ferramentas, e o espaço da barra de status.  Todos os recursos devem ser criados com isso em mente.  O artigo [Menus e recursos: A mesclagem de menu](../mfc/menus-and-resources-menu-merging.md) este tópico abrange em detalhes.  
  
 Devido a esses problemas, os aplicativos OLE de documentos criados com o assistente de aplicativo podem ter até quatro menus e recursos separados da tabela de aceleração.  Esses são usados pelos seguintes motivos:  
  
|Nome do recurso|Uso|  
|---------------------|---------|  
|**IDR\_MAINFRAME**|Usado em um aplicativo MDI se nenhum arquivo é aberto, ou em um aplicativo de SDI independentemente dos arquivos abertos.  Este é o menu padrão usado em aplicativos de não OLE.|  
|**IDR\_projectTYPE\<\>**|Usado em um aplicativo MDI se os arquivos estão abertos.  Usado quando um aplicativo é executado de modo autônomo.  Este é o menu padrão usado em aplicativos de não OLE.|  
|**\<\>IDR\_projectTYPE\_SRVR\_IP**|Usado pelo servidor ou do contêiner quando um objeto está aberto no lugar.|  
|**\<\>IDR\_projectTYPE\_SRVR\_EMB**|Usado por um aplicativo de servidor se um objeto é aberto sem usar a ativação local.|  
  
 Cada um desses nomes de recurso representará um menu e, geralmente, uma tabela de aceleração.  Um esquema semelhante deve ser usado em aplicativos MFC que não são criados com o assistente de aplicativo.  
  
 Os artigos a seguir discutem os tópicos relacionados aos contêineres, a servidores, e à mesclagem de menu necessário para implementar a ativação no local:  
  
-   [Menus e recursos: Adições do contêiner](../mfc/menus-and-resources-container-additions.md)  
  
-   [Menus e recursos: Adições de servidor](../mfc/menus-and-resources-server-additions.md)  
  
-   [Menus e recursos: A mesclagem de menu](../mfc/menus-and-resources-menu-merging.md)  
  
## Consulte também  
 [OLE](../mfc/ole-in-mfc.md)