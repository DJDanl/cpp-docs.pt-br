---
title: "Controles ActiveX MFC: adicionando m&#233;todos de estoque | Microsoft Docs"
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
  - "Método DoClick"
  - "Controles ActiveX MFC, métodos"
  - "Controles ActiveX MFC, métodos de estoque"
ms.assetid: bc4fad78-cabd-4cc0-a798-464b1a682f0b
caps.latest.revision: 10
caps.handback.revision: 6
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Controles ActiveX MFC: adicionando m&#233;todos de estoque
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Um método de estoque difere de um método personalizado que já está implementado pela classe [COleControl](../mfc/reference/colecontrol-class.md).  Por exemplo, `COleControl` contém uma função de membro predefinida que da suporte ao método update do controle.  A entrada do mapa de distribuição para esse método de estoque é **DISP\_STOCKFUNC\_REFRESH**.  
  
 da suporte`COleControl` dois métodos de estoque: DoClick e atualização.  A atualização é invocada pelo usuário de controle para atualização imediata a aparência do controle; DoClick é invocado para acionar o evento no controle.  
  
|Método|Entrada do mapa de distribuição|Comment|  
|------------|-------------------------------------|-------------|  
|`DoClick`|**DISP\_STOCKPROP\_DOCLICK \(\)**|Dispara um evento clique em.|  
|**Atualizar**|**DISP\_STOCKPROP\_REFRESH \(\)**|Atualiza imediatamente a aparência do controle.|  
  
##  <a name="_core_adding_a_stock_method_using_classwizard"></a> Adicionando um método de estoque usando o assistente de método add  
 Adicione um método de estoque é simples usando [Adicionar o assistente do método](../ide/add-method-wizard.md).  O procedimento a seguir demonstra como adicionar o método de atualização em um controle criado usando o assistente de controle ActiveX de MFC.  
  
#### Para adicionar o método de ações de atualização usando o assistente de método add  
  
1.  Carregar o projeto do controle.  
  
2.  Na exibição da classe, expanda o nó da biblioteca do controle.  
  
3.  Clique com o botão direito do mouse no nó da interface para o controle \(o segundo nó do nó da biblioteca\) para abrir o menu de atalho.  
  
4.  No menu de atalho, clique **Adicionar** e clique em **Adicionar método**.  
  
     Isso abre o assistente do método ser adicionado.  
  
5.  Na caixa de **Nome do Método** , clique **Atualizar**.  
  
6.  Clique em **Concluir**.  
  
##  <a name="_core_classwizard_changes_for_stock_methods"></a> Adicionar alterações do assistente do método para os métodos de estoque  
 Como o método de ações de atualização é suportado pela classe base de controle, **Assistente de Adição de Método** não altera a declaração de classe do controle de nenhuma forma.  Adiciona uma entrada para o método no mapa da expedição de controle e seu arquivo de .IDL.  A seguinte linha é adicionada ao mapa de expedição de controle, localizado no arquivo de implementação \(.CPP\):  
  
 [!code-cpp[NVC_MFC_AxUI#16](../mfc/codesnippet/CPP/mfc-activex-controls-adding-stock-methods_1.cpp)]  
  
 Isso torna o método de atualização disponível para usuários do controle.  
  
 A seguinte linha é adicionada ao arquivo de .IDL de controle:  
  
 [!code-cpp[NVC_MFC_AxUI#17](../mfc/codesnippet/CPP/mfc-activex-controls-adding-stock-methods_2.idl)]  
  
 Essa linha atribui ao método update um o número de identificação específico.  
  
## Consulte também  
 [Controles ActiveX MFC](../mfc/mfc-activex-controls.md)