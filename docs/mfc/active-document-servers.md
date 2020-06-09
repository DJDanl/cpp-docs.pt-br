---
title: Servidores de documentos ativos
ms.date: 11/04/2016
helpviewer_keywords:
- active documents [MFC], servers
- servers [MFC], active document
- active document servers [MFC]
ms.assetid: 131fec1e-02a0-4305-a7ab-903b911232a7
ms.openlocfilehash: 58f2a63a8c640e6ae31640af680894763603e1d0
ms.sourcegitcommit: c21b05042debc97d14875e019ee9d698691ffc0b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/09/2020
ms.locfileid: "84619148"
---
# <a name="active-document-servers"></a>Servidores de documentos ativos

Servidores de documentos ativos, como documentos de host do Word, Excel ou PowerPoint de outros tipos de aplicativos chamados de documentos ativos. Ao contrário dos objetos OLE incorporados (que são simplesmente exibidos dentro da página de outro documento), os documentos ativos fornecem a interface completa e a funcionalidade nativa completa do aplicativo de servidor que os cria. Os usuários podem criar documentos usando todo o potencial de seus aplicativos favoritos (se estiverem habilitados para o documento ativo), mas podem tratar o projeto resultante como uma única entidade.

Os documentos ativos podem ter mais de uma página e sempre estão ativos no local. Os documentos ativos controlam parte da interface do usuário, mesclando seus menus com os menus **arquivo** e **ajuda** do contêiner. Eles ocupam toda a área de edição do contêiner e controlam as exibições e o layout da página da impressora (margens, rodapés e assim por diante).

O MFC implementa servidores de documentos ativos com interfaces de documento/exibição, mapas de expedição de comandos, impressão, gerenciamento de menus e gerenciamento de registro. Os requisitos de programação específicos são discutidos em [documentos ativos](active-documents.md).

O MFC dá suporte a documentos ativos com a classe [CDocObjectServer](reference/cdocobjectserver-class.md) , derivada de [CCmdTarget](reference/ccmdtarget-class.md)e [CDocObjectServerItem](reference/cdocobjectserveritem-class.md), derivada de [COleServerItem](reference/coleserveritem-class.md). O MFC dá suporte a contêineres de documento ativos com a classe [COleDocObjectItem](reference/coledocobjectitem-class.md) , derivada de [COleClientItem](reference/coleclientitem-class.md).

`CDocObjectServer`mapeia as interfaces de documento ativas e inicializa e ativa um documento ativo. O MFC também fornece macros para manipular o roteamento de comandos em documentos ativos. Para usar documentos ativos em seu aplicativo, inclua AfxDocOb. h em seu arquivo StdAfx. h.

Um servidor MFC regular conecta sua própria `COleServerItem` classe derivada. O assistente de aplicativo do MFC gera essa classe para você se você marcar a caixa de seleção **Mini-Server** ou **Full-Server** para fornecer suporte ao documento composto do servidor de aplicativos. Se você também marcar a caixa de seleção **servidor de documentos ativo** , o assistente de aplicativo MFC gerará uma classe derivada de `CDocObjectServerItem` em vez disso.

A `COleDocObjectItem` classe permite que um contêiner OLE se torne um contêiner de documento ativo. Você pode usar o assistente de aplicativo MFC para criar um contêiner de documento ativo marcando a caixa de seleção **contêiner de documento ativo** na página suporte de documento composto do assistente de aplicativo MFC. Para obter mais informações, consulte [criando um aplicativo de contêiner de documento ativo](creating-an-active-document-container-application.md).

## <a name="see-also"></a>Consulte também

[Contenção de documentos ativos](active-document-containment.md)
