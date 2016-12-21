---
title: "Alternativas &#224; arquitetura de documento/exibi&#231;&#227;o | Microsoft Docs"
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
  - "Classe CDocument, requisitos de espaço"
  - "documentos, aplicativos sem"
  - "modos de exibição, aplicativos sem"
ms.assetid: 2c22f352-a137-45ce-9971-c142173496fb
caps.latest.revision: 9
caps.handback.revision: 5
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Alternativas &#224; arquitetura de documento/exibi&#231;&#227;o
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Os aplicativos MFC normalmente usam a arquitetura do documento\/exibição para gerenciar informações, os formatos de arquivo, e a representação visual de dados aos usuários.  Para a maioria dos aplicativos de área de trabalho, a arquitetura do documento\/exibição é uma arquitetura apropriado e eficiente de aplicativo.  Essa arquitetura separa dados de exibição e, na maioria dos casos, simplifica o aplicativo e reduz o código redundante.  
  
 No entanto, o documento\/arquitetura da exibição não é apropriado para algumas situações.  Considere esses exemplos:  
  
-   Se você estiver movendo um aplicativo escrito em C no windows, talvez você queira concluir sua porta antes de adicionar o suporte do documento\/exibição ao aplicativo.  
  
-   Se você estiver escrevendo um utilitário de peso leve, você pode descobrir que você pode fazer sem a arquitetura do documento\/exibição.  
  
-   Se seu código original já mistura o gerenciamento de dados com a exibição de dados, mova o código para o modelo de documento\/exibição não for o valor busca porque você deve desassociar os dois.  Você pode preferir deixar o código como é.  
  
 Para criar um aplicativo que não usa arquitetura do documento\/exibição, desmarque a caixa de seleção de **Document\/View architecture support** na etapa 1 do assistente de aplicativo MFC.  Consulte [Assistente do aplicativo MFC](../Topic/MFC%20Application%20Wizard.md) para obter detalhes.  
  
> [!NOTE]
>  Os aplicativos baseados Diálogo\- gerados pelo assistente de aplicativo MFC não usam a arquitetura do documento\/exibição, a caixa de seleção de **Document\/View architecture support** é desabilitada se você selecionar o tipo de aplicativo da caixa de diálogo.  
  
 Assistentes do Visual C\+\+, bem como os editores de origem e da caixa de diálogo, trabalho com o aplicativo gerado apenas como com qualquer outro aplicativo script gerado.  O aplicativo pode suportar barras de ferramentas, barras de rolagem, e uma barra de status, e tem uma caixa de **Sobre** .  Seu aplicativo não registrará nenhum modelo de documento, e não conterá uma classe do documento.  
  
 Observe que o aplicativo gerado tem uma classe de exibição, **CChildView**, derivado de `CWnd`.  O MFC cria e coloca uma instância da classe da exibição dentro do windows do quadro criadas pelo seu aplicativo.  O impõe MFC ainda usando uma janela de exibição, como simplifica o posicionamento e gerenciar o conteúdo do aplicativo.  Você pode adicionar código de pintura ao membro de `OnPaint` dessa classe.  O código deve adicionar barras de rolagem a exibição em vez do quadro.  
  
 Como a arquitetura do documento\/exibição fornecida por MFC é responsável para implementar muitos dos recursos básicos de um aplicativo, a ausência em seu projeto significa que você é responsável para implementar muitos recursos importantes de seu aplicativo:  
  
-   Conforme fornecido pelo assistente de aplicativo MFC, o menu para seu aplicativo contém apenas `New` e comandos de `Exit` no menu de **Arquivo** . \(O comando de `New` tem suporte apenas para aplicativos MDI, não aplicativos de SDI sem suporte do documento\/exibição.\) O recurso gerado a partir do menu não dará suporte a uma lista de MRU \(usado recentemente\).  
  
-   Você deve adicionar funções e implementações do manipulador para todos os comandos que seu aplicativo suporte, inclusive **Abrir** e **Salvar** no menu de **Arquivo** .  O MFC normalmente fornece código para oferecer suporte a esses recursos, mas o suporte é associado com segurança à arquitetura do documento\/exibição.  
  
-   A barra de ferramentas do aplicativo, se você solicitou um, será mínima.  
  
 É altamente recomendável que você use o assistente de aplicativo MFC para criar aplicativos sem a arquitetura do documento\/exibição, porque o assistente garante uma arquitetura correta de MFC.  No entanto, se você deve evitar usar o assistente, aqui estão várias abordagens para ignorar a arquitetura do documento\/exibição em seu código:  
  
-   Tratar o documento como um anexo não utilizados e implementar seu código de gerenciamento de dados na classe de exibição, conforme sugerido acima.  A sobrecarga para o documento é relativamente baixa.  Um único objeto de [CDocument](../Topic/CDocument%20Class.md) apresentará uma pequena quantidade de sobrecarga por si só, mais a pequena sobrecarga de classes base, de [CCmdTarget](../Topic/CCmdTarget%20Class.md) e de [CObject](../Topic/CObject%20Class.md)de **CDocument** .  Ambas as últimas classes são pequenas.  
  
     Declarado em **CDocument**:  
  
    -   Dois objetos de `CString` .  
  
    -   Três **BOOL**S.  
  
    -   Um ponteiro de `CDocTemplate` .  
  
    -   Um objeto de `CPtrList` , que contém uma lista das exibições do documento.  
  
     Além disso, o documento requer a quantidade de tempo criar o objeto de documento, seus objetos de exibição, uma janela do quadro, e um objeto de modelo de documento.  
  
-   Tratar o documento e a exibição como anexos não usado.  Coloque o seu código de gerenciamento de dados e de desenho na janela do quadro em vez da exibição.  Essa abordagem é mais próximo do modelo de programação do C \- idioma.  
  
-   Substituir as partes da estrutura de MFC que criam o documento e a exibição para eliminar a criação deless de todos eles.  O processo de criação do documento começa com uma chamada a `CWinApp::AddDocTemplate`.  Eliminar essa chamada da função de membro de `InitInstance` da classe do aplicativo e, em vez disso, crie uma janela de `InitInstance` você mesmo do quadro.  Coloque o seu código de gerenciamento de dados em sua classe da janela do quadro.  O processo de criação do documento\/exibição é ilustrado em [Documento\/criação da exibição](../mfc/document-view-creation.md).  Este é mais trabalho e requer uma compreensão mais profunda da estrutura, mas libera completamente a sobrecarga do documento\/exibição.  
  
 O artigo [MFC: Usar a base de dados de classificação sem documentos e exibições](../data/mfc-using-database-classes-without-documents-and-views.md) fornece exemplos mais concretos de backup do documento\/exibição no contexto dos aplicativos de base de dados.  
  
## Consulte também  
 [Arquitetura de documento\/exibição](../Topic/Document-View%20Architecture.md)