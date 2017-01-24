---
title: "Classes da caixa de di&#225;logo | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
f1_keywords: 
  - "vc.classes.dialog"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "classes de caixa de diálogo comuns"
  - "classes de caixa de diálogo"
  - "classes de caixa de diálogo comuns OLE"
  - "classes de folha de propriedades"
  - "caixas de diálogo de guia"
ms.assetid: db75da23-4eff-4c6c-beae-79cf046fbce9
caps.latest.revision: 9
caps.handback.revision: 5
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classes da caixa de di&#225;logo
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

A classe `CDialog` e suas classes derivadas encapsulam a funcionalidade da caixa de diálogo.  Desde que um diálogo é um tipo especial da janela, `CDialog` é derivado de `CWnd`.  Derivar suas classes da caixa de diálogo de `CDialog` ou use uma das classes comuns da caixa de diálogo para caixas de diálogo padrão, como abrir ou salvar um arquivo, uma impressão, selecionando uma fonte ou uma cor inicial, uma operação de localização e substituição, ou ao executar várias operações OLE\- relacionados.  
  
 [CDialog](../mfc/reference/cdialog-class.md)  
 A classe base para todas as caixas de diálogo modal, e modeless.  
  
 [CDataExchange](../Topic/CDataExchange%20Class.md)  
 Fontes informações de troca de dados e de validação para caixas de diálogo.  
  
## Caixas de diálogo comum  
 Essas classes da caixa de diálogo encapsulam as caixas de diálogo comum do windows.  Fornecem implementações de fácil utilização de caixas de diálogo complicadas.  
  
 [CCommonDialog](../Topic/CCommonDialog%20Class.md)  
 Classe base para todas as caixas de diálogo comum.  
  
 [CFileDialog](../Topic/CFileDialog%20Class.md)  
 Fornece uma caixa de diálogo padrão para abrir ou salvar um arquivo.  
  
 [CColorDialog](../mfc/reference/ccolordialog-class.md)  
 Fornece uma caixa de diálogo padrão para selecionar uma cor.  
  
 [CFontDialog](../mfc/reference/cfontdialog-class.md)  
 Fornece uma caixa de diálogo padrão para selecionar uma fonte.  
  
 [CFindReplaceDialog](../Topic/CFindReplaceDialog%20Class.md)  
 Fornece uma caixa de diálogo padrão para uma operação de localização e substituição.  
  
 [CPrintDialog](../Topic/CPrintDialog%20Class.md)  
 Fornece uma caixa de diálogo padrão para imprimir um arquivo.  
  
 [CPrintDialogEx](../mfc/reference/cprintdialogex-class.md)  
 Fornece uma folha de propriedade da cópia do Windows 2000.  
  
 [CPageSetupDialog](../mfc/reference/cpagesetupdialog-class.md)  
 Encapsula os serviços fornecidos pela caixa de diálogo comum de configuração de página do windows com suporte adicional para as margens definindo e da cópia.  
  
## Caixas de diálogo comum com OLE DB  
 OLE adiciona várias caixas de diálogo comum do windows.  Essas classes encapsulam as caixas de diálogo comum com OLE DB.  
  
 [COleDialog](../mfc/reference/coledialog-class.md)  
 Usado pela estrutura para conter implementações comuns de todas as caixas de diálogo do.  Todas as classes da caixa de diálogo na categoria da interface do usuário são derivadas dessa classe base.  `COleDialog` não pode ser usado diretamente.  
  
 [COleInsertDialog](../mfc/reference/coleinsertdialog-class.md)  
 Exibe a caixa de diálogo do objeto de inserção, a interface do usuário padrão para inserir novos itens vinculados ou inseridos OLE.  
  
 [COlePasteSpecialDialog](../mfc/reference/colepastespecialdialog-class.md)  
 Exibe a caixa de diálogo especial da pasta, a interface do usuário padrão para implementar o comando especial da pasta de edição.  
  
 [COleLinksDialog](../mfc/reference/colelinksdialog-class.md)  
 Exibe a caixa de diálogo de Links de edição, a interface do usuário padrão para as informações de alteração em itens vinculados.  
  
 [COleChangeIconDialog](../mfc/reference/colechangeicondialog-class.md)  
 Exibe a caixa de diálogo de ícone de alteração, a interface do usuário padrão para alterar o ícone associado a um item inserido ou vinculado OLE.  
  
 [COleConvertDialog](../mfc/reference/coleconvertdialog-class.md)  
 Exibe a caixa de diálogo de conversão, a interface do usuário padrão para itens do converter de um tipo para outro.  
  
 [COlePropertiesDialog](../Topic/COlePropertiesDialog%20Class.md)  
 Encapsula a caixa de diálogo OLE comum das propriedades do windows.  As caixas de diálogo DE propriedades comuns fornecem uma maneira fácil de um modo exibir e modificar as propriedades de um item OLE do documento consistente com os padrões do windows.  
  
 [COleUpdateDialog](../Topic/COleUpdateDialog%20Class.md)  
 Exibe a caixa de diálogo da atualização, a interface do usuário padrão para atualizar todos os links em um documento.  A caixa de diálogo contém um indicador de progresso para indicar como o fim do procedimento de atualização é até a conclusão.  
  
 [COleChangeSourceDialog](../mfc/reference/colechangesourcedialog-class.md)  
 Exibe a caixa de diálogo origem da alteração, a interface do usuário padrão para modificar o destino ou a origem de um link.  
  
 [COleBusyDialog](../mfc/reference/colebusydialog-class.md)  
 Exibe o servidor as caixas de diálogo de resposta e ocupados do servidor, a interface do usuário padrão para tratar chamadas para os aplicativos ocupados.  Exibido normalmente automaticamente pela implementação de [COleMessageFilter](../mfc/reference/colemessagefilter-class.md) .  
  
## Classes de folha de propriedade  
 As classes da folha de propriedades permitem seus aplicativos para usar as folhas de propriedades, também conhecidas como caixas de diálogo com guias.  As folhas de propriedades são um modo eficiente de organizar grandes quantidades controles em uma única caixa de diálogo.  
  
 [CPropertyPage](../mfc/reference/cpropertypage-class.md)  
 Fornece páginas individuais em uma folha de propriedades.  Derivar uma classe de `CPropertyPage` para cada página é adicionada à folha de propriedades.  
  
 [CPropertySheet](../mfc/reference/cpropertysheet-class.md)  
 Fornece o quadro para várias páginas de propriedades.  Derivar a sua classe de folha de propriedade de `CPropertySheet` para implementar rapidamente as folhas de propriedades.  
  
 [COlePropertyPage](../mfc/reference/colepropertypage-class.md)  
 Exibe as propriedades de um controlador OLE em uma interface gráfica, semelhantes a uma caixa de diálogo.  
  
## Classes HTML \- base na caixa de diálogo  
 [CDHtmlDialog](../Topic/CDHtmlDialog%20Class.md)  
 Usado para criar as caixas de diálogo que implementam sua interface de usuário com HTML em vez de recursos da caixa de diálogo.  
  
 [CMultiPageDHtmlDialog](../mfc/reference/cmultipagedhtmldialog-class.md)  
 Exibe várias páginas HTML em sequência e trata os eventos de cada página.  
  
## Classes relacionadas  
 Essas classes não são caixas de diálogo por si mesmo, mas usam modelos da caixa de diálogo e têm muito do comportamento das caixas de diálogo.  
  
 [CDialogBar](../mfc/reference/cdialogbar-class.md)  
 Uma barra de controle que é baseado em um modelo da caixa de diálogo.  
  
 [CFormView](../mfc/reference/cformview-class.md)  
 Uma exibição de rolagem cujo layout é definido em um modelo da caixa de diálogo.  Derivar uma classe de `CFormView` para implementar uma interface do usuário com base em um modelo da caixa de diálogo.  
  
 [CDaoRecordView](../mfc/reference/cdaorecordview-class.md)  
 Fornece uma exibição de formulário conectada diretamente a um objeto do conjunto de registros \(DAO\) de objeto de acesso a dados.  Como todas as exibições de formulário, `CDaoRecordView` é baseado em um modelo da caixa de diálogo.  
  
 [CRecordView](../mfc/reference/crecordview-class.md)  
 Fornece uma exibição de formulário conectada diretamente a um objeto do conjunto de registros de ODBC.  Como todas as exibições de formulário, `CRecordView` é baseado em um modelo da caixa de diálogo.  
  
 [CPrintInfo](../mfc/reference/cprintinfo-structure.md)  
 Uma estrutura que contém informações sobre um trabalho de cópia ou visualização de impressão.  Usado pela arquitetura de impressão de [CView](../Topic/CView%20Class.md).  
  
## Consulte também  
 [Visão geral da classe](../mfc/class-library-overview.md)