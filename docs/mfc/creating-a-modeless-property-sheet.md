---
title: "Criando uma folha de propriedades sem janela restrita | Microsoft Docs"
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
  - "Método Create [C++], folhas de propriedade"
  - "folhas de propriedades sem modo"
  - "folhas de propriedade, sem modo"
ms.assetid: eafd8a92-cc67-4a69-a5fb-742c920d1ae8
caps.latest.revision: 9
caps.handback.revision: 5
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Criando uma folha de propriedades sem janela restrita
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Normalmente, as folhas da propriedade que você cria serão modal.  Ao usar uma folha de propriedades modal, o usuário deve fechar a folha de propriedades antes de usar qualquer outra parte do aplicativo.  Este artigo descreve métodos que você pode usar para criar uma folha de propriedade modeless que permite que o usuário mantém a folha de propriedades aberta para usar outras partes do aplicativo.  
  
 Para exibir uma folha de propriedade como uma caixa de diálogo modeless em vez de como uma caixa de diálogo modal, chame [CPropertySheet::Create](../Topic/CPropertySheet::Create.md) em vez de [DoModal](../Topic/CPropertySheet::DoModal.md).  Você também deve implementar algumas tarefas adicionais para dar suporte a uma folha de propriedade modeless.  
  
 Uma das tarefas adicionais são dados de troca entre a folha de propriedades e o objeto que externo está alterando quando a folha de propriedades está aberta.  Essa é geralmente a mesma tarefa que para caixas de diálogo modeless padrão.  A parte desta tarefa estiver implementando um canal de comunicação entre a folha de propriedades modeless e o objeto externo ao qual as configurações de propriedade se aplica.  Essa implementação é muito mais fácil se você deve derivar uma classe de [CPropertySheet](../mfc/reference/cpropertysheet-class.md) para a folha de propriedades modeless.  Este artigo que você tiver feito isso.  
  
 Um método para comunicação entre a folha de propriedades modeless e o objeto externa \(a seleção atual em uma exibição, por exemplo\) é definir um ponteiro de folha de propriedade do objeto externo.  Defina uma função \(chamada algo como `SetMyExternalObject`\) em `CPropertySheet`\- classe derivada para alterar o ponteiro sempre que o foco for alterada de um objeto externa para outro.  A função de `SetMyExternalObject` precisará redefinir as configurações para que cada página de propriedades reflita o objeto externo recentemente selecionado.  Para fazer isso, a função de `SetMyExternalObject` deve poder acessar os objetos de [CPropertyPage](../mfc/reference/cpropertypage-class.md) que pertencem à classe de `CPropertySheet` .  
  
 A maneira mais conveniente de fornecer acesso às páginas de propriedades em uma folha de propriedade é inserir os objetos em `CPropertySheet`\- objeto derivado de `CPropertyPage` .  A inserção `CPropertyPage` objetos em `CPropertySheet`\- o objeto derivado difere de design típico para as caixas de diálogo modal, onde o proprietário da folha de propriedades cria os objetos de `CPropertyPage` e os passa para a folha de propriedade por meio de [CPropertySheet::AddPage](../Topic/CPropertySheet::AddPage.md).  
  
 Há muitas alternativas da interface do usuário para determinar quando as configurações de folha de propriedade modeless devem ser aplicadas a um objeto externo.  Uma alternativa é aplicar as configurações da página de propriedades atual sempre que o usuário modifica qualquer valor.  Outra alternativa é fornecer um botão ser aplicado, que permite que o usuário acumule alterações nas páginas de propriedades antes de confirmar ao objeto externo.  Para obter informações sobre as maneiras para controlar o botão aplicados, consulte o artigo [Tratando o botão ser aplicado](../mfc/handling-the-apply-button.md).  
  
## Consulte também  
 [Folhas de propriedade](../mfc/property-sheets-mfc.md)   
 [Trocando dados](../mfc/exchanging-data.md)   
 [Ciclo de vida de uma caixa de diálogo](../mfc/life-cycle-of-a-dialog-box.md)