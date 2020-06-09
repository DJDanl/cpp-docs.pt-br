---
title: Classes da caixa de diálogo
ms.date: 11/04/2016
f1_keywords:
- vc.classes.dialog
helpviewer_keywords:
- property sheet classes
- dialog box classes
- OLE common dialog classes
- common dialog classes [MFC]
- tab dialog boxes
ms.assetid: db75da23-4eff-4c6c-beae-79cf046fbce9
ms.openlocfilehash: 2399b27fc081dcc810277079729b0e62ef80d603
ms.sourcegitcommit: c21b05042debc97d14875e019ee9d698691ffc0b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/09/2020
ms.locfileid: "84616944"
---
# <a name="dialog-box-classes"></a>Classes da caixa de diálogo

`CDialog`A classe e suas classes derivadas encapsulam a funcionalidade da caixa de diálogo. Como uma caixa de diálogo é um tipo especial de janela, `CDialog` é derivada de `CWnd` . Derive suas classes de caixa de diálogo do `CDialog` ou use uma das classes de diálogo comuns para caixas de diálogo padrão, como abrir ou salvar um arquivo, imprimir, selecionar uma fonte ou cor, iniciar uma operação de pesquisa e substituição ou executar várias operações relacionadas a OLE.

[CDialog](reference/cdialog-class.md)<br/>
A classe base para todas as caixas de diálogo, modal e sem janela restrita.

[CDataExchange](reference/cdataexchange-class.md)<br/>
Fornece troca de dados e informações de validação para caixas de diálogo.

## <a name="common-dialogs"></a>Caixas de diálogo comuns

Essas classes de caixa de diálogo encapsulam as caixas de diálogo comuns do Windows. Eles fornecem implementações fáceis de usar de caixas de diálogo complicadas.

[CCommonDialog](reference/ccommondialog-class.md)<br/>
Classe base para todas as caixas de diálogo comuns.

[CFileDialog](reference/cfiledialog-class.md)<br/>
Fornece uma caixa de diálogo padrão para abrir ou salvar um arquivo.

[CColorDialog](reference/ccolordialog-class.md)<br/>
Fornece uma caixa de diálogo padrão para selecionar uma cor.

[CFontDialog](reference/cfontdialog-class.md)<br/>
Fornece uma caixa de diálogo padrão para selecionar uma fonte.

[CFindReplaceDialog](reference/cfindreplacedialog-class.md)<br/>
Fornece uma caixa de diálogo padrão para uma operação de pesquisa e substituição.

[CPrintDialog](reference/cprintdialog-class.md)<br/>
Fornece uma caixa de diálogo padrão para imprimir um arquivo.

[CPrintDialogEx](reference/cprintdialogex-class.md)<br/>
Fornece uma folha de propriedades de impressão do Windows.

[CPageSetupDialog](reference/cpagesetupdialog-class.md)<br/>
Encapsula os serviços fornecidos pela caixa de diálogo configuração de página comum do Windows com suporte adicional para definir e modificar as margens de impressão.

## <a name="ole-common-dialogs"></a>Caixas de diálogo comuns de OLE

O OLE adiciona várias caixas de diálogo comuns ao Windows. Essas classes encapsulam as caixas de diálogo OLE comuns.

[COleDialog](reference/coledialog-class.md)<br/>
Usado pela estrutura para conter implementações comuns para todas as caixas de diálogo OLE. Todas as classes da caixa de diálogo na categoria user-interface são derivadas dessa classe base. `COleDialog`Não pode ser usado diretamente.

[COleInsertDialog](reference/coleinsertdialog-class.md)<br/>
Exibe a caixa de diálogo Inserir objeto, a interface do usuário padrão para inserir novos itens vinculados OLE ou incorporados.

[COlePasteSpecialDialog](reference/colepastespecialdialog-class.md)<br/>
Exibe a caixa de diálogo colar especial, a interface do usuário padrão para implementar o comando Editar Colar especial.

[COleLinksDialog](reference/colelinksdialog-class.md)<br/>
Exibe a caixa de diálogo Editar links, a interface do usuário padrão para modificar informações sobre itens vinculados.

[COleChangeIconDialog](reference/colechangeicondialog-class.md)<br/>
Exibe a caixa de diálogo Alterar ícone, a interface do usuário padrão para alterar o ícone associado a um item OLE inserido ou vinculado.

[COleConvertDialog](reference/coleconvertdialog-class.md)<br/>
Exibe a caixa de diálogo Converter, a interface do usuário padrão para converter itens OLE de um tipo para outro.

[COlePropertiesDialog](reference/colepropertiesdialog-class.md)<br/>
Encapsula a caixa de diálogo Propriedades OLE comuns do Windows. As caixas de diálogo Propriedades OLE comuns fornecem uma maneira fácil de exibir e modificar as propriedades de um item de documento OLE de maneira consistente com os padrões do Windows.

[COleUpdateDialog](reference/coleupdatedialog-class.md)<br/>
Exibe a caixa de diálogo atualizar, a interface do usuário padrão para atualizar todos os links em um documento. A caixa de diálogo contém um indicador de progresso para indicar como fechar o procedimento de atualização para conclusão.

[COleChangeSourceDialog](reference/colechangesourcedialog-class.md)<br/>
Exibe a caixa de diálogo Alterar origem, a interface do usuário padrão para alterar o destino ou a origem de um link.

[COleBusyDialog](reference/colebusydialog-class.md)<br/>
Exibe as caixas de diálogo servidor ocupado e servidor não respondendo, a interface do usuário padrão para manipular chamadas para aplicativos ocupados. Geralmente exibido automaticamente pela implementação de [COleMessageFilter](reference/colemessagefilter-class.md) .

## <a name="property-sheet-classes"></a>Classes de folha de propriedades

As classes de folha de propriedades permitem que seus aplicativos usem folhas de propriedades, também conhecidas como caixas de diálogo com guias. As folhas de propriedades são uma maneira eficiente de organizar um grande número de controles em uma única caixa de diálogo.

[CPropertyPage](reference/cpropertypage-class.md)<br/>
Fornece as páginas individuais dentro de uma folha de propriedades. Derive uma classe de `CPropertyPage` para cada página a ser adicionada à sua folha de propriedades.

[CPropertySheet](reference/cpropertysheet-class.md)<br/>
Fornece o quadro para várias páginas de propriedades. Derive sua classe de folha de propriedades de `CPropertySheet` para implementar suas folhas de propriedades rapidamente.

[COlePropertyPage](reference/colepropertypage-class.md)<br/>
Exibe as propriedades de um controle OLE em uma interface gráfica, semelhante a uma caixa de diálogo.

## <a name="html-based-dialog-classes"></a>Classes de diálogo baseadas em HTML

[CDHtmlDialog](reference/cdhtmldialog-class.md)<br/>
Usado para criar caixas de diálogo que implementam sua interface do usuário com HTML em vez de recursos de caixa de diálogo.

[CMultiPageDHtmlDialog](reference/cmultipagedhtmldialog-class.md)<br/>
Exibe várias páginas HTML sequencialmente e manipula os eventos de cada página.

## <a name="related-classes"></a>Classes relacionadas

Essas classes não são caixas de diálogo por si, mas usam modelos de caixa de diálogo e têm grande parte do comportamento de caixas de diálogo.

[CDialogBar](reference/cdialogbar-class.md)<br/>
Uma barra de controle baseada em um modelo de caixa de diálogo.

[CFormView](reference/cformview-class.md)<br/>
Uma exibição de rolagem cujo layout é definido em um modelo de caixa de diálogo. Derive uma classe de `CFormView` para implementar uma interface do usuário com base em um modelo de caixa de diálogo.

[CDaoRecordView](reference/cdaorecordview-class.md)<br/>
Fornece uma exibição de formulário diretamente conectada a um objeto Recordset do objeto de acesso a dados (DAO). Como todos os modos de exibição de formulário, um `CDaoRecordView` é baseado em um modelo de caixa de diálogo.

[CRecordView](reference/crecordview-class.md)<br/>
Fornece uma exibição de formulário diretamente conectada a um objeto Recordset Open Database Connectivity (ODBC). Como todos os modos de exibição de formulário, um `CRecordView` é baseado em um modelo de caixa de diálogo.

[CPrintInfo](reference/cprintinfo-structure.md)<br/>
Uma estrutura que contém informações sobre um trabalho de impressão ou de visualização de impressão. Usado pela arquitetura de impressão do [cvisualização](reference/cview-class.md).

## <a name="see-also"></a>Consulte também

[Visão geral da classe](class-library-overview.md)
