---
title: 'Contêineres: Implementando um contêiner | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- applications [OLE], OLE container
- OLE containers [MFC], implementing
ms.assetid: af1e2079-619a-4eac-9327-985ad875823a
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 066c032a18b2fedc88884b7e6eee55f07fcf43ad
ms.sourcegitcommit: 060f381fe0807107ec26c18b46d3fcb859d8d2e7
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/25/2018
ms.locfileid: "36930069"
---
# <a name="containers-implementing-a-container"></a>Contêineres: implementando um contêiner
Este artigo resume o procedimento para implementar um contêiner e direciona para outros artigos que fornecem que mais detalhadas explicações sobre a implementação de contêineres. Ela também lista alguns recursos opcionais do OLE, que talvez você queira implementar e os artigos que descrevem esses recursos.  
  
#### <a name="to-prepare-your-cwinapp-derived-class"></a>Para preparar sua classe derivada de CWinApp  
  
1.  Inicializar as bibliotecas OLE chamando `AfxOleInit` no `InitInstance` função de membro.  
  
2.  Chamar `CDocTemplate::SetContainerInfo` na `InitInstance` para atribuir o menu e o Acelerador de recursos usados quando um item inserido está ativado no local. Para obter mais informações sobre este tópico, consulte [ativação](../mfc/activation-cpp.md).  
  
 Esses recursos são fornecidos para você automaticamente quando você usar o Assistente de aplicativo MFC para criar um aplicativo de contêiner. Consulte [criando um programa EXE do MFC](../mfc/reference/mfc-application-wizard.md).  
  
#### <a name="to-prepare-your-view-class"></a>Para preparar a sua classe de exibição  
  
1.  Manter o controle de itens selecionados, mantendo um ponteiro ou lista de ponteiros, se você oferecer suporte a seleção múltipla, para os itens selecionados. O `OnDraw` função deve desenhar todos os itens OLE.  
  
2.  Substituir `IsSelected` para verificar se o item passado para ele no momento está selecionado.  
  
3.  Implementar um `OnInsertObject` manipulador de mensagem para exibir o **Inserir objeto** caixa de diálogo.  
  
4.  Implementar um `OnSetFocus` mensagem manipulador para transferir o foco do modo de exibição para uma OLE active in-loco inseridos item.  
  
5.  Implementar um `OnSize` manipulador de mensagens para informar uma OLE item inserido que precisa alterar o retângulo para refletir a alteração no tamanho de seu modo de exibição que contém.  
  
 Como a implementação desses recursos drasticamente varia de um aplicativo para o próximo, o Assistente de aplicativo fornece apenas uma implementação básica. Provavelmente, você precisará personalizar essas funções para que seu aplicativo funcione corretamente. Para obter um exemplo disso, consulte o [CONTÊINER](../visual-cpp-samples.md) exemplo.  
  
#### <a name="to-handle-embedded-and-linked-items"></a>Para manipular itens incorporados e vinculados  
  
1.  Derive uma classe de [COleClientItem](../mfc/reference/coleclientitem-class.md). Objetos dessa classe representam os itens que foram incorporados ou vinculados ao documento OLE.  
  
2.  Substituir `OnChange`, `OnChangeItemPosition`, e `OnGetItemPosition`. Lidar com essas funções de dimensionamento, posicionamento e modificar os itens incorporados e vinculados.  
  
 O Assistente de aplicativo derivará a classe para você, mas provavelmente você precisará substituir `OnChange` e as outras funções listadas com ele na etapa 2 do procedimento anterior. As implementações de esqueleto precisam ser personalizado para a maioria dos aplicativos, porque essas funções são implementadas de forma diferente de um aplicativo para o próximo. Para obter exemplos de isso, consulte os exemplos MFC [DRAWCLI](../visual-cpp-samples.md) e [CONTÊINER](../visual-cpp-samples.md).  
  
 Você deve adicionar um número de itens a estrutura de menu do aplicativo de contêiner para dar suporte a OLE. Para obter mais informações sobre estas configurações, consulte [Menus e recursos: adições de contêiner](../mfc/menus-and-resources-container-additions.md).  
  
 Convém também oferecem suporte a alguns dos recursos a seguir em seu aplicativo de contêiner:  
  
-   Ativação no local ao editar um item inserido.  
  
     Para obter mais informações, consulte [ativação](../mfc/activation-cpp.md).  
  
-   Criação de OLE itens arrastando e soltando uma seleção de um aplicativo de servidor.  
  
     Para obter mais informações, consulte [arrastar e soltar (OLE)](../mfc/drag-and-drop-ole.md).  
  
-   Links para objetos inseridos ou aplicativos de contêiner/servidor de combinação.  
  
     Para obter mais informações, consulte [contêineres: recursos avançados](../mfc/containers-advanced-features.md).  
  
## <a name="see-also"></a>Consulte também  
 [Contêineres](../mfc/containers.md)   
 [Contêineres: itens clientes](../mfc/containers-client-items.md)

