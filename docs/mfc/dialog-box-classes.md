---
title: "Classes de caixa de diálogo | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- vc.classes.dialog
dev_langs:
- C++
helpviewer_keywords:
- property sheet classes
- dialog box classes
- OLE common dialog classes
- common dialog classes [MFC]
- tab dialog boxes
ms.assetid: db75da23-4eff-4c6c-beae-79cf046fbce9
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 6d51529e5d04a8297c0d3824ab38c7d2045bc866
ms.sourcegitcommit: a5916b48541f804a79891ff04e246628b5f9a24a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/09/2018
---
# <a name="dialog-box-classes"></a>Classes da caixa de diálogo
Classe `CDialog` e suas classes derivadas encapsulam funcionalidades de caixa de diálogo. Como uma caixa de diálogo é um tipo especial de janela, `CDialog` é derivado de `CWnd`. Derivar suas classes de caixa de diálogo de `CDialog` ou use uma das classes de caixa de diálogo comum para as caixas de diálogo padrão, como abrir ou salvar um arquivo, impressão, selecionando uma fonte ou a cor, iniciando uma operação de pesquisa e substituição, ou executando vários relacionadas a OLE operações.  
  
 [CDialog](../mfc/reference/cdialog-class.md)  
 A classe base para todas as caixas de diálogo modais e sem janela restrita.  
  
 [CDataExchange](../mfc/reference/cdataexchange-class.md)  
 Fornece informações de troca e validação de dados para caixas de diálogo.  
  
## <a name="common-dialogs"></a>Caixas de diálogo comuns  
 Essas classes de caixa de diálogo encapsulam as caixas de diálogo comuns do Windows. Eles fornecem as implementações de fácil de usar de caixas de diálogo complicadas.  
  
 [CCommonDialog](../mfc/reference/ccommondialog-class.md)  
 Classe base para todas as caixas de diálogo comuns.  
  
 [CFileDialog](../mfc/reference/cfiledialog-class.md)  
 Fornece uma caixa de diálogo padrão para abrir ou salvar um arquivo.  
  
 [CColorDialog](../mfc/reference/ccolordialog-class.md)  
 Fornece uma caixa de diálogo padrão para selecionar uma cor.  
  
 [CFontDialog](../mfc/reference/cfontdialog-class.md)  
 Fornece uma caixa de diálogo padrão para selecionar uma fonte.  
  
 [CFindReplaceDialog](../mfc/reference/cfindreplacedialog-class.md)  
 Fornece uma caixa de diálogo padrão para uma operação de pesquisa e substituição.  
  
 [CPrintDialog](../mfc/reference/cprintdialog-class.md)  
 Fornece uma caixa de diálogo padrão para imprimir um arquivo.  
  
 [CPrintDialogEx](../mfc/reference/cprintdialogex-class.md)  
 Fornece uma folha de propriedades de impressão do Windows.  
  
 [CPageSetupDialog](../mfc/reference/cpagesetupdialog-class.md)  
 Encapsula os serviços fornecidos pela caixa de diálogo de configuração de página comuns do Windows com suporte adicional para configuração e modificar as margens de impressão.  
  
## <a name="ole-common-dialogs"></a>Caixas de diálogo comuns OLE  
 OLE adiciona várias caixas de diálogo comuns para Windows. Essas classes encapsulam as caixas de diálogo comuns OLE.  
  
 [COleDialog](../mfc/reference/coledialog-class.md)  
 Usado pelo framework para conter implementações comuns para todas as caixas de diálogo OLE. Todas as classes de caixa de diálogo na categoria de interface do usuário são derivadas desta classe base. `COleDialog`não pode ser usada diretamente.  
  
 [COleInsertDialog](../mfc/reference/coleinsertdialog-class.md)  
 Exibe a caixa de diálogo Inserir objeto, a interface de usuário padrão para inserir novos OLE vinculados ou incorporados itens.  
  
 [COlePasteSpecialDialog](../mfc/reference/colepastespecialdialog-class.md)  
 Exibe a caixa de diálogo Colar especial, a interface de usuário padrão para implementar o comando Editar Colar especial.  
  
 [COleLinksDialog](../mfc/reference/colelinksdialog-class.md)  
 Exibe a caixa de diálogo Editar Links, a interface de usuário padrão para modificar informações sobre itens vinculados.  
  
 [COleChangeIconDialog](../mfc/reference/colechangeicondialog-class.md)  
 Exibe a caixa de diálogo Alterar ícone, a interface de usuário padrão para alterar o ícone associado a uma OLE inserido ou item vinculado.  
  
 [COleConvertDialog](../mfc/reference/coleconvertdialog-class.md)  
 Exibe a caixa de diálogo Converter, a interface de usuário padrão para converter itens OLE de um tipo para outro.  
  
 [COlePropertiesDialog](../mfc/reference/colepropertiesdialog-class.md)  
 Encapsula a caixa de diálogo de propriedades OLE comuns do Windows. Caixas de diálogo comuns OLE propriedades fornecem uma maneira fácil de exibir e modificar as propriedades de um item do documento OLE de maneira consistente com os padrões do Windows.  
  
 [COleUpdateDialog](../mfc/reference/coleupdatedialog-class.md)  
 Exibe a caixa de diálogo de atualização, a interface de usuário padrão para a atualização de todos os links em um documento. A caixa de diálogo contém um indicador de progresso para indicar como fechar o procedimento de atualização até a conclusão.  
  
 [COleChangeSourceDialog](../mfc/reference/colechangesourcedialog-class.md)  
 Exibe a caixa de diálogo Alterar origem, a interface de usuário padrão para alterar o destino ou origem de um link.  
  
 [COleBusyDialog](../mfc/reference/colebusydialog-class.md)  
 Exibe as caixas de diálogo servidor ocupado e o servidor não responder, a interface de usuário padrão para lidar com chamadas para aplicativos ocupados. Normalmente são exibidos automaticamente pelo [COleMessageFilter](../mfc/reference/colemessagefilter-class.md) implementação.  
  
## <a name="property-sheet-classes"></a>Classes de folha de propriedades  
 As classes de folha de propriedades permitem que os aplicativos usem folhas de propriedades, também conhecido como com guias de caixas de diálogo. Folhas de propriedades são uma maneira eficiente para organizar um grande número de controles em uma única caixa de diálogo.  
  
 [CPropertyPage](../mfc/reference/cpropertypage-class.md)  
 Fornece as páginas individuais dentro de uma folha de propriedades. Derive uma classe de `CPropertyPage` para cada página a ser adicionado à sua folha de propriedades.  
  
 [CPropertySheet](../mfc/reference/cpropertysheet-class.md)  
 Fornece o quadro para várias páginas de propriedades. Derive sua classe de folha de propriedade da `CPropertySheet` para implementar suas folhas de propriedade rapidamente.  
  
 [COlePropertyPage](../mfc/reference/colepropertypage-class.md)  
 Exibe as propriedades de uma OLE controlam em uma interface gráfica, semelhante a uma caixa de diálogo.  
  
## <a name="html-based-dialog-classes"></a>Classes de caixa de diálogo com base em HTML  
 [CDHtmlDialog](../mfc/reference/cdhtmldialog-class.md)  
 Usado para criar caixas de diálogo que implementam sua interface do usuário com recursos HTML, em vez da caixa de diálogo.  
  
 [CMultiPageDHtmlDialog](../mfc/reference/cmultipagedhtmldialog-class.md)  
 Exibe várias páginas HTML sequencialmente e trata os eventos de cada página.  
  
## <a name="related-classes"></a>Classes relacionadas  
 Essas classes não são caixas de diálogo propriamente dita, mas usar modelos de caixa de diálogo e tem muito o comportamento de caixas de diálogo.  
  
 [CDialogBar](../mfc/reference/cdialogbar-class.md)  
 Uma barra de controle que é baseada em um modelo de caixa de diálogo.  
  
 [CFormView](../mfc/reference/cformview-class.md)  
 Um modo de exibição de rolagem cujo layout é definido em um modelo de caixa de diálogo. Derive uma classe de `CFormView` para implementar uma interface de usuário com base em um modelo de caixa de diálogo.  
  
 [CDaoRecordView](../mfc/reference/cdaorecordview-class.md)  
 Fornece um formulário de exibição conectada diretamente a um objeto de conjunto de registros do objeto de acesso a dados (DAO). Como todos os modos de exibição de formulário, um `CDaoRecordView` baseia-se em um modelo de caixa de diálogo.  
  
 [CRecordView](../mfc/reference/crecordview-class.md)  
 Fornece um formulário de exibição conectada diretamente a um objeto de conjunto de registros de conectividade de banco de dados aberto (ODBC). Como todos os modos de exibição de formulário, um `CRecordView` baseia-se em um modelo de caixa de diálogo.  
  
 [CPrintInfo](../mfc/reference/cprintinfo-structure.md)  
 Uma estrutura que contém informações sobre um trabalho de visualização de impressão ou impressão. Usado pela arquitetura de impressão do [CView](../mfc/reference/cview-class.md).  
  
## <a name="see-also"></a>Consulte também  
 [Visão geral da classe](../mfc/class-library-overview.md)

