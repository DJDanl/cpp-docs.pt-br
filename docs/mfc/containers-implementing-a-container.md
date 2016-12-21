---
title: "Cont&#234;ineres: implementando um cont&#234;iner | Microsoft Docs"
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
  - "aplicativos [OLE], Contêiner OLE"
  - "Contêineres OLE, implementando"
ms.assetid: af1e2079-619a-4eac-9327-985ad875823a
caps.latest.revision: 10
caps.handback.revision: 6
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Cont&#234;ineres: implementando um cont&#234;iner
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Este artigo resume o procedimento para implementar um contêiner e aponte para outros artigos que fornecem mais explicações detalhadas sobre como implementar contêiner.  Também lista alguns recursos opcionais do que você pode querer implementar e os artigos que descrevem esses recursos.  
  
#### Para preparar a classe CWinApp\- derivada  
  
1.  Inicializar as bibliotecas do chamando **AfxOleInit** na função de membro de `InitInstance` .  
  
2.  Chame `CDocTemplate::SetContainerInfo` em `InitInstance` para atribuir o menu e os recursos de acelerador usados quando um item é inserido no local ativado.  Para obter mais informações sobre esse tópico, consulte [Ativação](../mfc/activation-cpp.md).  
  
 Esses recursos são fornecidos para você automaticamente quando você usa o assistente de aplicativo MFC para criar um aplicativo do contêiner.  Consulte [Criando um programa MFC EXE](../Topic/MFC%20Application%20Wizard.md).  
  
#### Para preparar a classe de exibição  
  
1.  Keep selecionou track dois itens mantendo um ponteiro, ou lista de ponteiros se você oferece suporte a várias seleções, os itens selecionados.  A função de `OnDraw` deve chamar todos os itens com OLE DB.  
  
2.  Substituir `IsSelected` para verificar se o item transmitido a ele está selecionado no momento.  
  
3.  Implementar um manipulador de mensagens de **OnInsertObject** para exibir a caixa de diálogo de **Inserir objeto** .  
  
4.  Implementar um manipulador de mensagens de `OnSetFocus` para transferir o foco de exibição para um item inserido no local OLE ativa.  
  
5.  Implementar um manipulador de mensagens de `OnSize` para informar um item inserido OLE que precisa alterar o retângulo para refletir em tamanho a alteração da exibição contentor.  
  
 Como a implementação desses recursos variar radicalmente de um aplicativo à seguinte, o assistente do aplicativo fornece apenas uma implementação básica.  Você provavelmente terá que personalizar essas funções para obter seu aplicativo funcionem corretamente.  Para obter um exemplo, consulte o exemplo de [CONTÊINER](../top/visual-cpp-samples.md) .  
  
#### Para tratar itens digitados e vinculados  
  
1.  Derivar uma classe de [COleClientItem](../mfc/reference/coleclientitem-class.md).  Os objetos dessa classe representa os itens que foram inseridos em ou vinculados ao documento OLE.  
  
2.  Substituição **OnChange**, `OnChangeItemPosition`, e `OnGetItemPosition`.  Essas funções tratam o tamanho, o posicionamento, e a alteração de itens digitados e vinculados.  
  
 O assistente de aplicativo derivará a classe para você, mas você precisará provavelmente de substituir **OnChange** e outras funções listadas a ele na etapa 2 do procedimento anterior.  As implementações do esqueleto precisam ser personalizadas para a maioria dos aplicativos, porque essas funções são implementadas diferente de um aplicativo a seguir.  Para obter exemplos disso, consulte os exemplos [DRAWCLI](../top/visual-cpp-samples.md) e [CONTÊINER](../top/visual-cpp-samples.md)MFC.  
  
 Você deve adicionar um número de itens de menu à estrutura de aplicativo de contêineres para dar suporte a OLE.  Para obter mais informações sobre esses [Menus e recursos: Adições do contêiner](../mfc/menus-and-resources-container-additions.md), consulte.  
  
 Talvez você também queira oferecer suporte a alguns dos seguintes recursos em seu aplicativo de contêineres:  
  
-   Ativação no local ao editar um item inserido.  
  
     Para obter mais informações, consulte [Ativação](../mfc/activation-cpp.md).  
  
-   Criação de itens com OLE DB arrastando e removendo uma seleção de um aplicativo de servidor.  
  
     Para obter mais informações, consulte [Arraste e solte \(OLE\)](../mfc/drag-and-drop-ole.md).  
  
-   Links para objetos inseridos ou ao contêiner da combinação\/aplicativos para servidores.  
  
     Para obter mais informações, consulte [Contêiner: Recursos avançados](../mfc/containers-advanced-features.md).  
  
## Consulte também  
 [Contêineres](../mfc/containers.md)   
 [Contêineres: itens clientes](../mfc/containers-client-items.md)