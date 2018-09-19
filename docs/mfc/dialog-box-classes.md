---
title: Classes de caixa de diálogo | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: conceptual
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
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 177e6f7ab0787ba3eccfe963f08963697747145e
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46399503"
---
# <a name="dialog-box-classes"></a>Classes da caixa de diálogo

Classe `CDialog` e suas classes derivadas encapsulam a funcionalidade de caixa de diálogo. Uma vez que uma caixa de diálogo é um tipo especial de janela, `CDialog` é derivado de `CWnd`. Derivar suas classes de caixa de diálogo de `CDialog` ou use uma das classes de caixa de diálogo comum para caixas de diálogo padrão, como abrir ou salvar um arquivo, impressão, selecionando uma fonte ou cor, iniciando uma operação de pesquisa e substituição ou executem várias relacionadas a OLE operações.

[CDialog](../mfc/reference/cdialog-class.md)<br/>
A classe base para todas as caixas de diálogo modais e sem janela restrita.

[CDataExchange](../mfc/reference/cdataexchange-class.md)<br/>
Fornece informações de troca e validação de dados para caixas de diálogo.

## <a name="common-dialogs"></a>Caixas de diálogo comuns

Essas classes de caixa de diálogo encapsulam as caixas de diálogo comuns do Windows. Elas fornecem implementações de fácil de usar de caixas de diálogo complicada.

[CCommonDialog](../mfc/reference/ccommondialog-class.md)<br/>
Classe base para todas as caixas de diálogo comuns.

[CFileDialog](../mfc/reference/cfiledialog-class.md)<br/>
Fornece uma caixa de diálogo padrão para abrir ou salvar um arquivo.

[CColorDialog](../mfc/reference/ccolordialog-class.md)<br/>
Fornece uma caixa de diálogo padrão para selecionar uma cor.

[CFontDialog](../mfc/reference/cfontdialog-class.md)<br/>
Fornece uma caixa de diálogo padrão para selecionar uma fonte.

[CFindReplaceDialog](../mfc/reference/cfindreplacedialog-class.md)<br/>
Fornece uma caixa de diálogo padrão para uma operação de pesquisa e substituição.

[CPrintDialog](../mfc/reference/cprintdialog-class.md)<br/>
Fornece uma caixa de diálogo padrão para imprimir um arquivo.

[CPrintDialogEx](../mfc/reference/cprintdialogex-class.md)<br/>
Fornece uma folha de propriedades de impressão do Windows.

[CPageSetupDialog](../mfc/reference/cpagesetupdialog-class.md)<br/>
Encapsula os serviços fornecidos pela caixa de diálogo Configurar página comum do Windows com suporte adicional para definir e modificar as margens de impressão.

## <a name="ole-common-dialogs"></a>Caixas de diálogo comuns OLE

OLE adiciona várias caixas de diálogo comuns para Windows. Essas classes encapsulam as caixas de diálogo comuns OLE.

[COleDialog](../mfc/reference/coledialog-class.md)<br/>
Usado pelo framework para conter implementações comuns para todas as caixas de diálogo OLE. Todas as classes de caixa de diálogo, na categoria de interface do usuário são derivadas dessa classe base. `COleDialog` não pode ser usado diretamente.

[COleInsertDialog](../mfc/reference/coleinsertdialog-class.md)<br/>
Exibe a caixa de diálogo Inserir objeto, a interface de usuário padrão para inserção OLE novo vinculado ou inserido itens.

[COlePasteSpecialDialog](../mfc/reference/colepastespecialdialog-class.md)<br/>
Exibe a caixa de diálogo Colar especial, a interface de usuário padrão para implementar o comando Editar Colar especial.

[COleLinksDialog](../mfc/reference/colelinksdialog-class.md)<br/>
Exibe a caixa de diálogo Editar Links, a interface de usuário padrão para modificar informações sobre itens vinculados.

[COleChangeIconDialog](../mfc/reference/colechangeicondialog-class.md)<br/>
Exibe a caixa de diálogo Alterar ícone, a interface de usuário padrão para alterar o ícone associado a uma OLE inserido ou item vinculado.

[COleConvertDialog](../mfc/reference/coleconvertdialog-class.md)<br/>
Exibe a caixa de diálogo Converter, a interface de usuário padrão para itens OLE convertendo um tipo para outro.

[COlePropertiesDialog](../mfc/reference/colepropertiesdialog-class.md)<br/>
Encapsula a caixa de diálogo de propriedades OLE comum do Windows. Caixas de diálogo comuns OLE propriedades fornecem uma maneira fácil de exibir e modificar as propriedades de um item de documento OLE de maneira consistente com os padrões do Windows.

[COleUpdateDialog](../mfc/reference/coleupdatedialog-class.md)<br/>
Exibe a caixa de diálogo de atualização, a interface de usuário padrão para a atualização de todos os links em um documento. A caixa de diálogo contém um indicador de progresso para indicar o quão próximo o procedimento de atualização é até a conclusão.

[COleChangeSourceDialog](../mfc/reference/colechangesourcedialog-class.md)<br/>
Exibe a caixa de diálogo Alterar origem, a interface de usuário padrão para alterar o destino ou origem de um link.

[COleBusyDialog](../mfc/reference/colebusydialog-class.md)<br/>
Exibe as caixas de diálogo servidor ocupado e o servidor não responder, a interface de usuário padrão para lidar com chamadas para aplicativos de ocupado. Normalmente é exibida automaticamente pelo [COleMessageFilter](../mfc/reference/colemessagefilter-class.md) implementação.

## <a name="property-sheet-classes"></a>Classes de folha de propriedades

As classes de folha de propriedades permitem que os aplicativos usem folhas de propriedades, também conhecido como com guias de caixas de diálogo. Folhas de propriedades são uma maneira eficiente de organizar um grande número de controles em uma única caixa de diálogo.

[CPropertyPage](../mfc/reference/cpropertypage-class.md)<br/>
Fornece as páginas individuais dentro de uma folha de propriedades. Derive uma classe de `CPropertyPage` para cada página a ser adicionado à sua folha de propriedades.

[CPropertySheet](../mfc/reference/cpropertysheet-class.md)<br/>
Fornece o quadro para várias páginas de propriedade. Derive sua classe de folha de propriedade da `CPropertySheet` implementar suas folhas de propriedades rapidamente.

[COlePropertyPage](../mfc/reference/colepropertypage-class.md)<br/>
Exibe as propriedades de uma OLE controlam em uma interface gráfica, semelhante a uma caixa de diálogo.

## <a name="html-based-dialog-classes"></a>Classes de caixa de diálogo baseada em HTML

[CDHtmlDialog](../mfc/reference/cdhtmldialog-class.md)<br/>
Usado para criar caixas de diálogo que implementam sua interface do usuário com os recursos HTML, em vez da caixa de diálogo.

[CMultiPageDHtmlDialog](../mfc/reference/cmultipagedhtmldialog-class.md)<br/>
Exibe várias páginas HTML em sequência e trata os eventos de cada página.

## <a name="related-classes"></a>Classes relacionadas

Essas classes não são caixas de diálogo por si só, mas usar modelos de caixa de diálogo e têm muito do comportamento de caixas de diálogo.

[CDialogBar](../mfc/reference/cdialogbar-class.md)<br/>
Uma barra de controle que se baseia em um modelo de caixa de diálogo.

[CFormView](../mfc/reference/cformview-class.md)<br/>
Um modo de exibição de rolagem cujo layout é definido em um modelo de caixa de diálogo. Derive uma classe de `CFormView` para implementar uma interface do usuário com base em um modelo de caixa de diálogo.

[CDaoRecordView](../mfc/reference/cdaorecordview-class.md)<br/>
Fornece um formulário de exibição diretamente conectada a um objeto de conjunto de registros do objeto de acesso de dados (DAO). Como todos os modos de exibição de formulário, um `CDaoRecordView` baseia-se em um modelo de caixa de diálogo.

[CRecordView](../mfc/reference/crecordview-class.md)<br/>
Fornece um formulário de exibição conectada diretamente a um objeto de conjunto de registros de conectividade de banco de dados aberto (ODBC). Como todos os modos de exibição de formulário, um `CRecordView` baseia-se em um modelo de caixa de diálogo.

[CPrintInfo](../mfc/reference/cprintinfo-structure.md)<br/>
Uma estrutura que contém informações sobre um trabalho de impressão ou visualização de impressão. Usado pela arquitetura de impressão [CView](../mfc/reference/cview-class.md).

## <a name="see-also"></a>Consulte também

[Visão geral da classe](../mfc/class-library-overview.md)

