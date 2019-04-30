---
title: Servidores de documentos ativos
ms.date: 11/04/2016
helpviewer_keywords:
- active documents [MFC], servers
- servers [MFC], active document
- active document servers [MFC]
ms.assetid: 131fec1e-02a0-4305-a7ab-903b911232a7
ms.openlocfilehash: 7050b810bb5e1f0c240222cd9b8c4922ced4238a
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62394958"
---
# <a name="active-document-servers"></a>Servidores de documentos ativos

Servidores de documento ativo, como Word, Excel ou PowerPoint documentos de host de outros tipos de aplicativos chamados de documentos ativos. Ao contrário de OLE objetos incorporados (que simplesmente são exibidos na página de outro documento), Active Directory documentos fornecem a interface completa e toda a funcionalidade nativa do aplicativo para servidores que as cria. Os usuários podem criar documentos usando todo o potencial de seus aplicativos favoritos (se forem habilitado de documento ativo), ainda pode tratar o projeto resultante como uma única entidade.

Documentos ativos podem ter mais de uma página e são sempre ativo no local. Documentos ativos controlam parte da interface do usuário, mesclando seus menus com o **arquivo** e **ajudar** menus do contêiner. Eles ocupam na área de edição inteira do contêiner e controlam os modos de exibição e o layout da página da impressora (margens, rodapés e assim por diante).

MFC implementa os servidores de documento ativo com interfaces de documento/exibição, mapas de expedição de comando, impressão, gerenciamento de menu e gerenciamento de registro. Requisitos de programação específicos são discutidos [documentos ativos](../mfc/active-documents.md).

MFC dá suporte a documentos do Active Directory com o [CDocObjectServer](../mfc/reference/cdocobjectserver-class.md) classe, derivada de [CCmdTarget](../mfc/reference/ccmdtarget-class.md), e [CDocObjectServerItem](../mfc/reference/cdocobjectserveritem-class.md), derivado do [ COleServerItem](../mfc/reference/coleserveritem-class.md). MFC dá suporte a contêineres de documento ativo com o [COleDocObjectItem](../mfc/reference/coledocobjectitem-class.md) classe, derivada de [COleClientItem](../mfc/reference/coleclientitem-class.md).

`CDocObjectServer` mapeia as interfaces do documento ativo e inicializa e ativa um documento ativo. O MFC também fornece macros para lidar com o roteamento de comando em documentos do Active Directory. Para usar documentos ativos em seu aplicativo, inclua AfxDocOb.h em seu arquivo Stdafx. H.

Um servidor MFC regular interliga seu próprio `COleServerItem`-classe derivada. O Assistente de aplicativo do MFC gera essa classe para você, se você selecionar o **miniservidor** ou **servidor completo** caixa de seleção para dar suporte a documento composto de seu servidor de aplicativos. Se você selecionar também o **servidor de documento ativo** caixa de seleção, o Assistente de aplicativo do MFC gera uma classe derivada de `CDocObjectServerItem` em vez disso.

O `COleDocObjectItem` classe permite que um contêiner OLE para se tornar um contêiner de documento ativo. Você pode usar o Assistente de aplicativo do MFC para criar um contêiner de documento ativo, selecionando o **contêiner de documento ativo** caixa de seleção na página de suporte de documento composto do Assistente de aplicativo MFC. Para obter mais informações, consulte [criando um aplicativo de contêiner do documento ativo](../mfc/creating-an-active-document-container-application.md).

## <a name="see-also"></a>Consulte também

[Contenção de documentos ativos](../mfc/active-document-containment.md)
