---
title: "Caixas de di&#225;logo em OLE | Microsoft Docs"
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
  - "caixas de diálogo"
  - "caixas de diálogo, sobre caixas de diálogo"
  - "caixas de diálogo, OLE"
  - "Objeto Insert"
  - "caixas de diálogo MFC, Caixas de diálogo OLE"
  - "Caixas de diálogo OLE"
  - "Caixas de diálogo OLE, sobre caixas de diálogo OLE"
ms.assetid: 73c41eb8-738a-4d02-9212-d3395bb09a3a
caps.latest.revision: 10
caps.handback.revision: 6
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Caixas de di&#225;logo em OLE
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Quando um usuário executa um aplicativo OLE\- habilitado, existem ocasiões em que o aplicativo precisa de informações do usuário para realizar a operação.  As classes DE MFC fornecem várias caixas de diálogo para coletar informações necessárias.  Este tópico lista as tarefas tratadas pela caixas de diálogo do e as classes necessárias para exibir essas caixas de diálogo.  Para obter detalhes sobre caixas de diálogo com OLE DB e em estruturas usadas para personalizar seu comportamento, consulte [Referência de MFC](../mfc/mfc-desktop-applications.md).  
  
 *Inserir o objeto*  
 Essa caixa de diálogo permite que o usuário insira objetos criados recentemente ou existentes no documento composto.  Também permite que o usuário escolha para exibir o item como um ícone e habilita o botão de comando do ícone de alteração.  Exibir essa caixa de diálogo quando o usuário escolhe o objeto de inserção do menu editar.  Use a classe de [COleInsertDialog](../mfc/reference/coleinsertdialog-class.md) para exibir essa caixa de diálogo.  Observe que você não pode inserir um aplicativo MDI no outro.  Um aplicativo que é um contêiner\/servidor não pode ser inserido em se a menos que seja um aplicativo de SDI.  
  
 *Cole o especiais*  
 Essa caixa de diálogo permite que o usuário controlar o formato usado para colar dados em um documento composto.  O usuário pode escolher o formato de dados, se digitar ou vincular os dados, e se exibi\-lo como um ícone.  Exibir essa caixa de diálogo quando o usuário escolhe o especiais da pasta de menu editar.  Use a classe de [COlePasteSpecialDialog](../mfc/reference/colepastespecialdialog-class.md) para exibir essa caixa de diálogo.  
  
 *Ícone de alteração*  
 Essa caixa de diálogo permite que o usuário selecione o ícone é exibido para representar o item vinculado ou inserido.  Exibir essa caixa de diálogo quando o usuário escolhe o ícone de alteração de menu editar ou escolha o botão de ícone especial de alteração na pasta ou converter caixas de diálogo.  Também exibição quando o usuário abre a caixa de diálogo do objeto de inserção e escolher a exibição como o ícone.  Use a classe de [COleChangeIconDialog](../mfc/reference/colechangeicondialog-class.md) para exibir essa caixa de diálogo.  
  
 *Converta*  
 Essa caixa de diálogo permite que o usuário altere o tipo de um item inserido ou vinculado.  Por exemplo, se você tiver um metarquivo em um documento composto e a quer posteriormente para usar outro aplicativo alterar o metarquivo inserido, você pode usar a caixa de diálogo de conversão.  Essa caixa de diálogo é exibida geralmente clicando no objeto *de tipo de item* no menu editar e, no menu em cascata, clicando no conversão.  Use a classe de [COleConvertDialog](../mfc/reference/coleconvertdialog-class.md) para exibir essa caixa de diálogo.  Para obter um exemplo, executar o exemplo [OCLIENT](../top/visual-cpp-samples.md)MFC OLE.  
  
 *Editar Links ou atualizar Links*  
 A caixa de diálogo de Links de edição permite que o usuário altere informações sobre a origem de um objeto vinculado.  A caixa de diálogo de Links de atualização verifica as origens de todos os itens vinculados na caixa de diálogo atual e exibe a caixa de diálogo de Links de edição se necessário.  Exibir a caixa de diálogo de Links de edição quando o usuário escolhe Links de menu editar.  A caixa de diálogo de Links de atualização é exibida geralmente quando um documento composto é aberto pela primeira vez.  Use [COleLinksDialog](../mfc/reference/colelinksdialog-class.md) ou a classe de [COleUpdateDialog](../Topic/COleUpdateDialog%20Class.md) , dependendo da caixa de diálogo você deseja exibir.  
  
 *Servidor ocupado ou servidor que não responde*  
 A caixa de diálogo ocupado do servidor será exibida quando o usuário tenta ativar um item e o servidor estiver atualmente puder tratar a solicitação, normalmente porque o servidor está em uso por outro usuário ou tarefa.  A caixa de diálogo de resposta do servidor será exibida se o servidor não responde à solicitação de ativação de todos eles.  Essas caixas de diálogo são exibidas através de `COleMessageFilter`, com base em uma implementação da interface OLE **IMessageFilter**, e o usuário pode decidir se tentar a ativação solicitará novamente.  Use a classe de [COleBusyDialog](../mfc/reference/colebusydialog-class.md) para exibir essa caixa de diálogo.  
  
## Consulte também  
 [Caixas de diálogo](../mfc/dialog-boxes.md)   
 [Ciclo de vida de uma caixa de diálogo](../mfc/life-cycle-of-a-dialog-box.md)   
 [OLE](../mfc/ole-in-mfc.md)