---
title: Menus e recursos (OLE)
ms.date: 11/04/2016
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
ms.openlocfilehash: e705f28476df7b594f9648aee8317759211c66c9
ms.sourcegitcommit: c21b05042debc97d14875e019ee9d698691ffc0b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/09/2020
ms.locfileid: "84626206"
---
# <a name="menus-and-resources-ole"></a>Menus e recursos (OLE)

Este grupo de artigos explica o uso de menus e recursos em aplicativos de documentos OLE do MFC.

A edição Visual OLE coloca requisitos adicionais no menu e em outros recursos fornecidos por aplicativos de documento OLE, pois há vários modos nos quais os aplicativos de contêiner e servidor (componente) podem ser iniciados e usados. Por exemplo, um aplicativo de servidor completo pode ser executado em qualquer um destes três modos:

- Autônomo.

- Em vigor, para editar um item dentro do contexto de um contêiner.

- Aberto, para editar um item fora do contexto de seu contêiner, geralmente em uma janela separada.

Isso requer três layouts de menu separados, um para cada modo possível do aplicativo. As tabelas de acelerador também são necessárias para cada novo modo. Um aplicativo de contêiner pode ou não oferecer suporte à ativação in-loco; Se tiver, precisará de uma nova estrutura de menu e de tabelas de acelerador associadas.

A ativação in-loco requer que os aplicativos de contêiner e servidor do sejam negociados para o menu, barra de ferramentas e espaço de barra de status. Todos os recursos devem ser projetados com isso em mente. Os [menus e recursos do artigo: a mesclagem de menus](menus-and-resources-menu-merging.md) aborda esse tópico em detalhes.

Devido a esses problemas, os aplicativos de documento OLE criados com o assistente de aplicativo podem ter até quatro menus separados e recursos de tabela de aceleração. Eles são usados pelos seguintes motivos:

|Nome do recurso|Uso|
|-------------------|---------|
|IDR_MAINFRAME|Usado em um aplicativo MDI se nenhum arquivo estiver aberto ou em um aplicativo SDI, independentemente dos arquivos abertos. Este é o menu padrão usado em aplicativos não OLE.|
|tipo de IDR_ \<project>|Usado em um aplicativo MDI se os arquivos estiverem abertos. Usado quando um aplicativo é executado de forma autônoma. Este é o menu padrão usado em aplicativos não OLE.|
|IDR_ \<project> TYPE_SRVR_IP|Usado pelo servidor ou contêiner quando um objeto é aberto no local.|
|IDR_ \<project> TYPE_SRVR_EMB|Usado por um aplicativo de servidor se um objeto for aberto sem usar a ativação in-loco.|

Cada um desses nomes de recursos representa um menu e, geralmente, uma tabela de acelerador. Um esquema semelhante deve ser usado em aplicativos MFC que não são criados com o assistente de aplicativo.

Os artigos a seguir discutem tópicos relacionados a contêineres, servidores e a mesclagem de menu necessária para implementar a ativação in-loco:

- [Menus e recursos: adições de contêiner](menus-and-resources-container-additions.md)

- [Menus e recursos: adições de servidor](menus-and-resources-server-additions.md)

- [Menus e recursos: mesclagem de menu](menus-and-resources-menu-merging.md)

## <a name="see-also"></a>Consulte também

[OLE](ole-in-mfc.md)
