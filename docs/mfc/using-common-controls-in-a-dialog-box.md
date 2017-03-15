---
title: "Usando controles comuns em uma caixa de di&#225;logo | Microsoft Docs"
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
  - "controles comuns [C++], em caixas de diálogo"
  - "controles de caixas de diálogo [C++], controles comuns"
  - "controles comuns do Windows [C++], em caixas de diálogo"
ms.assetid: 17713caf-09f8-484a-bf54-5f48bf09cce9
caps.latest.revision: 11
caps.handback.revision: 7
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Usando controles comuns em uma caixa de di&#225;logo
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Os controles comum do windows podem ser usados em [caixas de diálogo](../mfc/dialog-boxes.md), formam exibições, do registro, e qualquer outra janela com base em um modelo da caixa de diálogo.  O procedimento a seguir, com pequenas modificações, funcionará para formulários também.  
  
## Procedimentos  
  
#### Para usar um controle comuns em uma caixa de diálogo  
  
1.  Coloque o controle no modelo [usando o editor da caixa de diálogo](../mfc/using-the-dialog-editor-to-add-controls.md)da caixa de diálogo.  
  
2.  Adicionar à classe da caixa de diálogo uma variável de membro que representa o controle.  Na caixa de diálogo de **Adicionar Variável de Membro** , verifique **Control variable** e verifique se está selecionado **Controle** para **Categoria**.  
  
3.  Se esse controle comuns está fornecendo a entrada para o programa, declarar variáveis do membro adicional na classe da caixa de diálogo para tratar esses valores de entrada.  
  
    > [!NOTE]
    >  Você pode adicionar essas variáveis do membro usando o menu de contexto na exibição da classe [Adicionando uma variável de membro](../ide/adding-a-member-variable-visual-cpp.md)\(consulte\).  
  
4.  Em [OnInitDialog](../Topic/CDialog::OnInitDialog.md) para a sua classe da caixa de diálogo, defina as condições iniciais para o controle comuns.  Usando variável de membro criado na etapa anterior, use as funções de membro para definir o valor inicial e as outras configurações.  Consulte as descrições a seguir de controles para obter detalhes sobre configurações.  
  
     Você também pode usar [caixa de diálogo de troca de dados](../mfc/dialog-data-exchange-and-validation.md) \(DDX\) para inicializar controles em uma caixa de diálogo.  
  
5.  Os manipuladores para controles na caixa de diálogo, use a variável de membro para manipular o controle.  Consulte as descrições a seguir de controles para obter detalhes sobre métodos.  
  
    > [!NOTE]
    >  A variável de membro existirá apenas quando a caixa de diálogo própria existe.  Você não poderá ver o controle para valores de entrada depois que a caixa de diálogo foi fechada.  Para trabalhar com valores de entrada de um controle comum, substitua `OnOK` em sua classe da caixa de diálogo.  Em sua substituição, consulte o controle para valores de entrada e armazenar esses valores em variáveis de membro da classe da caixa de diálogo.  
  
    > [!NOTE]
    >  Você também pode usar a caixa de diálogo de troca de dados para definir ou recuperar valores dos controles em uma caixa de diálogo.  
  
## Comentários  
 A adição de alguns controles comuns a uma caixa de diálogo fará a caixa de diálogo a não funciona.  Consulte [A adição de controles a uma caixa de diálogo faz a caixa de diálogo deixar de funcionar](../mfc/adding-controls-to-a-dialog-causes-the-dialog-to-no-longer-function.md) para obter mais informações sobre como tratar essa situação.  
  
## O que você deseja fazer?  
  
-   [Adicionar controles para uma caixa de diálogo a mão em vez do com o publicador da caixa de diálogo](../mfc/adding-controls-by-hand.md)  
  
-   [Derivar o controle de um dos controles comum do windows padrão](../mfc/deriving-controls-from-a-standard-control.md)  
  
-   [Use um controle comuns como uma janela filho](../mfc/using-a-common-control-as-a-child-window.md)  
  
-   [Receber notificações de um controle](../Topic/Receiving%20Notification%20from%20Common%20Controls.md)  
  
-   [Use a caixa de diálogo de troca de dados \(DDX\)](../mfc/dialog-data-exchange-and-validation.md)  
  
## Consulte também  
 [Criando e usando controles](../mfc/making-and-using-controls.md)   
 [Controles](../mfc/controls-mfc.md)