---
title: Servidores de documentos ativos | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- active documents [MFC], servers
- servers [MFC], active document
- active document servers [MFC]
ms.assetid: 131fec1e-02a0-4305-a7ab-903b911232a7
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 7cc207541bda3084db6bc8ab3896f46761587169
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="active-document-servers"></a>Servidores de documentos ativos
Servidores de documentos ativos como Word, Excel ou PowerPoint documentos de host de outros tipos de aplicativo chamam documentos ativos. Ao contrário de OLE objetos incorporados (que são exibidos apenas dentro da página de outro documento), documentos ativos fornecem a interface completa e a funcionalidade nativa completa do aplicativo de servidor que cria. Os usuários podem criar documentos usando todo o potencial dos seus aplicativos favoritos (se eles estiverem documento ativo habilitado), ainda pode tratar o projeto resultante como uma única entidade.  
  
 Documentos ativos podem ter mais de uma página e são sempre ativo no local. Documentos ativos controlam parte da interface do usuário, mesclando seus menus com o **arquivo** e **ajuda** menus do contêiner. Eles ocupam toda a área edição do contêiner e controlam os modos de exibição e o layout da página da impressora (margens, rodapés e assim por diante).  
  
 MFC implementa servidores do documento ativo com interfaces de exibição de documentos, mapas de expedição de comando, impressão, gerenciamento de menu e gerenciamento de registro. Requisitos de programação específicos são discutidos em [documentos ativos](../mfc/active-documents.md).  
  
 MFC dá suporte a documentos ativos com o [CDocObjectServer](../mfc/reference/cdocobjectserver-class.md) classe derivada de [CCmdTarget](../mfc/reference/ccmdtarget-class.md), e [CDocObjectServerItem](../mfc/reference/cdocobjectserveritem-class.md), derivada de [ COleServerItem](../mfc/reference/coleserveritem-class.md). Oferece suporte a MFC contêineres de documento ativo com o [COleDocObjectItem](../mfc/reference/coledocobjectitem-class.md) classe derivada de [COleClientItem](../mfc/reference/coleclientitem-class.md).  
  
 `CDocObjectServer` mapeia as interfaces do documento ativo e inicializa e ativa um documento ativo. MFC também fornece macros para lidar com o roteamento de comando em documentos ativos. Para usar documentos ativos em seu aplicativo, inclua AfxDocOb.h em seu arquivo Stdafx. H.  
  
 Um servidor MFC regular conecta seu próprio `COleServerItem`-classe derivada. O Assistente de aplicativo MFC gera essa classe para você, se você selecionar o **miniservidor** ou **servidor completo** caixa de seleção para dar suporte a documentos compostos de seu servidor de aplicativos. Se você selecionar também o **server documento ativo** caixa de seleção, o Assistente de aplicativo MFC gera uma classe derivada de `CDocObjectServerItem` em vez disso.  
  
 O `COleDocObjectItem` classe permite que um contêiner OLE para se tornar um contêiner de documento ativo. Você pode usar o Assistente de aplicativo MFC para criar um contêiner de documento ativo selecionando o **contêiner de documento ativo** caixa de seleção na página de suporte a documentos compostos do Assistente de aplicativo MFC. Para obter mais informações, consulte [criando um aplicativo de contêiner de documento ativo](../mfc/creating-an-active-document-container-application.md).  
  
## <a name="see-also"></a>Consulte também  
 [Contenção de documentos ativos](../mfc/active-document-containment.md)

