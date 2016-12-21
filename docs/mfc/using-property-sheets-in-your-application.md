---
title: "Usando folhas de propriedade no aplicativo | Microsoft Docs"
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
  - "Método AddPage"
  - "Classe CPropertyPage, estilos"
  - "Método Create [C++], folhas de propriedade"
  - "recursos da caixa de diálogo"
  - "modelos de caixa de diálogo, folhas de propriedade"
  - "Folhas de propriedade do método DoModal"
  - "páginas de propriedade, folhas de propriedade"
  - "folhas de propriedade, sobre folhas de propriedade"
ms.assetid: 240654d4-152b-4e3f-af7b-44234339206e
caps.latest.revision: 10
caps.handback.revision: 6
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Usando folhas de propriedade no aplicativo
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Para usar uma folha de propriedade em seu aplicativo, conclua as seguintes etapas:  
  
1.  Crie um recurso do modelo da caixa de diálogo para cada página de propriedades.  Tenha em mente que o usuário pode alternar de uma página para outra, assim que apresentam cada página tão consistentemente possível.  
  
     Os modelos da caixa de diálogo para todas as páginas não precisam ser o mesmo tamanho.  A estrutura usa o tamanho da maior página para determinar a quantidade de espaço a ser atribuído a folha de propriedade para as páginas de propriedades.  
  
     Quando você cria o recurso de modelo da caixa de diálogo para uma página de propriedades, você deve especificar os seguintes estilos na folha de propriedades propriedades da caixa de diálogo:  
  
    -   Defina a caixa de edição de **Legenda** na página de **Geral** o texto que você deseja aparecer na guia da página.  
  
    -   Defina a caixa de listagem de **Estilo** na página de **Estilos** a **Filho**.  
  
    -   Defina a caixa de listagem de **Borda** na página de **Estilos** a **Fino**.  
  
    -   Verifique se a caixa de seleção de **Titlebar** na página de **Estilos** está selecionada.  
  
    -   Verifique se a caixa de seleção de **Desabilitado** na página de **Mais Estilos** está selecionada.  
  
2.  Crie [CPropertyPage](../mfc/reference/cpropertypage-class.md)\- classe derivada que corresponde a cada modelo da caixa de diálogo da página de propriedades.  Consulte [Adicionando uma classe](../Topic/Adding%20a%20Class%20\(Visual%20C++\).md).  Escolha `CPropertyPage` como a classe base.  
  
3.  Crie variáveis de membro para manter os valores dessa página de propriedades.  O processo para adicionar variáveis de membro a uma página de propriedades é exatamente igual ao adicionar variáveis de membro a uma caixa de diálogo, para uma página de propriedades é uma caixa de diálogo especializada.  Para obter mais informações, consulte [Definindo variáveis de membro para controles da caixa de diálogo](../mfc/defining-member-variables-for-dialog-controls.md).  
  
4.  Construir um objeto de [CPropertySheet](../mfc/reference/cpropertysheet-class.md) em seu código\-fonte.  Em geral, você constrói o objeto de `CPropertySheet` no manipulador para o comando que exibe a folha de propriedades.  Esse objeto representa a folha de propriedade inteira.  Se você criar uma folha de propriedades modal com a função de [DoModal](../Topic/CPropertySheet::DoModal.md) , a estrutura fornece três botões de comando por padrão: OK, cancel, e se aplica.  A estrutura não cria nenhum botão de comando para as folhas de propriedades modeless criadas com a função de [Crie](../Topic/CPropertySheet::Create.md) .  Você não precisa gerar uma classe de `CPropertySheet` a menos que você deseje que a adicionar outros controles \(como uma janela de visualização\) ou exibir uma folha de propriedade modeless.  Esta etapa é necessária para folhas de propriedades modeless porque não contêm nenhum controle padrão que podem ser usados para fechar a folha de propriedades.  
  
5.  Para cada página é adicionada à folha de propriedade, faça o seguinte:  
  
    -   Construir um objeto para cada `CPropertyPage`\- classe derivada que você criou anteriormente neste processo.  
  
    -   Chame [CPropertySheet::AddPage](../Topic/CPropertySheet::AddPage.md) para cada página.  
  
     Normalmente, o objeto que cria `CPropertySheet` também cria os objetos de `CPropertyPage` nesta etapa.  No entanto, se você implementa `CPropertySheet`\- classe derivada, você pode inserir os objetos de `CPropertyPage` no objeto de `CPropertySheet` e chamar `AddPage` para cada página de `CPropertySheet`\- construtor de classe derivada.  `AddPage` adiciona o objeto de `CPropertyPage` à lista de folha de propriedade de páginas realmente mas não cria a janela para essa página.  Consequentemente, não é necessário esperar até a criação da janela de folha de propriedade para chamar `AddPage`; você pode chamar `AddPage` do construtor de folha de propriedades.  
  
     Por padrão, se uma folha de propriedade tem mais das guias que caberá em uma única linha de folha de propriedade, os guias empilharão em várias linhas.  Para desabilitar pilha, chame [CPropertySheet::EnableStackedTabs](../Topic/CPropertySheet::EnableStackedTabs.md) com o parâmetro definido como **Falso**.  Você deve chamar `EnableStackedTabs` quando você cria a folha de propriedades.  
  
6.  Chame [CPropertySheet::DoModal](../Topic/CPropertySheet::DoModal.md) ou [Crie](../Topic/CPropertySheet::Create.md) para exibir a folha de propriedades.  Chame `DoModal` para criar uma folha de propriedade como uma caixa de diálogo modal.  Chame **Criar** para criar a folha de propriedades como uma caixa de diálogo modeless.  
  
7.  Dados do Exchange entre páginas de propriedades e o proprietário da folha de propriedades.  Isso é explicado no artigo [Troca de dados](../mfc/exchanging-data.md).  
  
 Para obter um exemplo de como usar folhas de propriedades, consulte o exemplo [PROPDLG](../top/visual-cpp-samples.md)gerais de MFC.  
  
## Consulte também  
 [Folhas de propriedade](../mfc/property-sheets-mfc.md)