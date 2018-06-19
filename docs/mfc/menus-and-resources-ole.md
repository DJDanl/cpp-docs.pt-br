---
title: Menus e recursos (OLE) | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- OLE visual editing servers [MFC]
- status bars [MFC], OLE document applications
- visual editing [MFC], application menus and resources
- string tables [MFC], visual editing applications
- OLE containers [MFC], menus and resources
- OLE applications [MFC], menus and resources
- OLE server applications [MFC], menus and resources
- toolbars [MFC], OLE document applications
- string editing [MFC], visual editing applications
- server applications [MFC], OLE menus and resources
- applications [OLE], menus and resources
- menus [MFC], OLE document applications
- in-place activation [MFC], OLE menus and resources
- containers [MFC], OLE container applications
- OLE menus and resources [MFC]
ms.assetid: 52bfa086-7d3d-466f-94c7-c7061f3bdb3a
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 54cc874fd3c95123446ab81b920bfe0fce52df5e
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33347088"
---
# <a name="menus-and-resources-ole"></a>Menus e recursos (OLE)
Este grupo de artigos explica o uso de menus e recursos em aplicativos de documento OLE do MFC.  
  
 OLE edição visual coloca requisitos adicionais no menu e outros recursos fornecidos por aplicativos de documento OLE porque há um número de modos de contêiner no qual ambos os e aplicativos de servidor (componente) podem ser iniciados e usados. Por exemplo, um aplicativo de servidor completo pode executar em qualquer um destes três modos:  
  
-   Autônomo.  
  
-   No local, para a edição de um item dentro do contexto de um contêiner.  
  
-   Abrir para editar um item fora do contexto de seu contêiner, geralmente em uma janela separada.  
  
 Isso exige três layouts de menu separadas, uma para cada modo possíveis do aplicativo. Tabelas de teclas aceleradoras também são necessárias para cada novo modo. Um aplicativo de contêiner pode ou não dar suporte a ativação no local; em caso afirmativo, ele precisa de uma nova estrutura de menu e associadas a tabelas de teclas aceleradoras.  
  
 Ativação no local requer que os aplicativos de contêiner e servidor devem negociar para espaço de barra de menu, barra de ferramentas e status. Todos os recursos devem ser criados com isso em mente. O artigo [Menus e recursos: mesclagem de Menu](../mfc/menus-and-resources-menu-merging.md) aborda esse tópico em detalhes.  
  
 Devido a esses problemas, aplicativos de documento OLE criados com o Assistente de aplicativo podem ter até quatro menus separados e recursos de tabela do acelerador. Eles são usados pelos seguintes motivos:  
  
|Nome do recurso|Use|  
|-------------------|---------|  
|**IDR_MAINFRAME**|Usado em um aplicativo MDI se nenhum arquivo estiver aberto, ou em um aplicativo SDI independentemente de arquivos abertos. Esse é o menu padrão usado em aplicativos OLE não.|  
|**IDR\<projeto > tipo**|Usado em um aplicativo MDI se arquivos estiverem abertos. Usado quando um aplicativo está em execução autônomo. Esse é o menu padrão usado em aplicativos OLE não.|  
|**IDR\<projeto > TYPE_SRVR_IP**|Usado pelo servidor ou contêiner quando um objeto é aberto no lugar.|  
|**IDR\<projeto > TYPE_SRVR_EMB**|Usado por um aplicativo de servidor se um objeto for aberto sem usar a ativação no local.|  
  
 Cada um desses nomes de recurso representa um menu e, geralmente, uma tabela de aceleradores. Um esquema semelhante deve ser usado em aplicativos MFC que não são criados com o Assistente de aplicativo.  
  
 Os artigos a seguir abordam tópicos relacionados a contêineres, servidores e o menu de mesclagem necessárias para implementar a ativação no local:  
  
-   [Menus e recursos: adições de contêiner](../mfc/menus-and-resources-container-additions.md)  
  
-   [Menus e recursos: adições de servidor](../mfc/menus-and-resources-server-additions.md)  
  
-   [Menus e recursos: mesclagem de menu](../mfc/menus-and-resources-menu-merging.md)  
  
## <a name="see-also"></a>Consulte também  
 [OLE](../mfc/ole-in-mfc.md)

