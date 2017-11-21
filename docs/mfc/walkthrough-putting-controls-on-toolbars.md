---
title: 'Passo a passo: Colocando controles em barras de ferramentas | Microsoft Docs'
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
dev_langs: C++
helpviewer_keywords:
- Customize dialog box, adding controls
- toolbars [MFC], adding controls
ms.assetid: 8fc94bdf-0da7-45d9-8bc4-52b7b1edf205
caps.latest.revision: "24"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.openlocfilehash: 62c2b658f21552ace07863e8fc93827e60de1c3f
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="walkthrough-putting-controls-on-toolbars"></a>Instruções passo a passo: colocando controles em barras de ferramentas
Este tópico descreve como adicionar um botão de barra de ferramentas que contém um controle do Windows para uma barra de ferramentas. Em MFC, um botão de barra de ferramentas deve ser um [CMFCToolBarButton classe](../mfc/reference/cmfctoolbarbutton-class.md)-derivado de classe, por exemplo [CMFCToolBarComboBoxButton classe](../mfc/reference/cmfctoolbarcomboboxbutton-class.md), [CMFCToolBarEditBoxButton classe](../mfc/reference/cmfctoolbareditboxbutton-class.md), [CMFCDropDownToolbarButton classe](../mfc/reference/cmfcdropdowntoolbarbutton-class.md), ou [CMFCToolBarMenuButton classe](../mfc/reference/cmfctoolbarmenubutton-class.md).  
  
## <a name="adding-controls-to-toolbars"></a>Adicionando controles em barras de ferramentas  
 Para adicionar um controle a uma barra de ferramentas, siga estas etapas:  
  
1.  Reserve uma ID de recurso fictício do botão no recurso pai da barra de ferramentas. Para obter mais informações sobre como criar botões usando o Editor de barra de ferramentas no Visual Studio, consulte o [Editor de barra de ferramentas](../windows/toolbar-editor.md) tópico.  
  
2.  Reserve uma imagem da barra de ferramentas (ícone do botão) para o botão em todos os bitmaps da barra de ferramentas do pai.  
  
3.  No manipulador de mensagens que processa o `AFX_WM_RESETTOOLBAR` da mensagem, faça o seguinte:  
  
    1.  Construir o controle de botão usando um `CMFCToolbarButton`-classe derivada.  
  
    2.  Substitua o botão fictício com o novo controle usando [CMFCToolBar::ReplaceButton](../mfc/reference/cmfctoolbar-class.md#replacebutton). Você pode construir o objeto botão na pilha, porque `ReplaceButton` copia o objeto de botão e mantém a cópia.  
  
> [!NOTE]
>  Se você tiver habilitado personalização no seu aplicativo, talvez você precise redefinir a barra de ferramentas usando o **redefinir** botão o **barras de ferramentas** guia do **personalizar** caixa de diálogo para ver o atualizar o controle em seu aplicativo depois de recompilar. O estado da barra de ferramentas é salva no registro do Windows, e as informações de registro são carregadas e aplicadas após a `ReplaceButton` o método é executado durante a inicialização do aplicativo.  
  
## <a name="toolbar-controls-and-customization"></a>Personalização e controles de barra de ferramentas  
 O **comandos** guia o **personalizar** caixa de diálogo contém uma lista de comandos que estão disponíveis no aplicativo. Por padrão, o **personalizar** caixa de diálogo processa os menus do aplicativo e cria uma lista de botões de barra de ferramentas padrão em cada categoria de menu. Para manter a funcionalidade estendida que fornecem os controles de barra de ferramentas, você deve substituir o botão da barra de ferramentas padrão com o controle personalizado no **personalizar** caixa de diálogo.  
  
 Quando você habilita a personalização, você cria o **personalizar** caixa de diálogo no manipulador de personalização `OnViewCustomize` usando o [CMFCToolBarsCustomizeDialog classe](../mfc/reference/cmfctoolbarscustomizedialog-class.md) classe. Antes de exibir o **personalizar** caixa de diálogo chamando [CMFCToolBarsCustomizeDialog::Create](../mfc/reference/cmfctoolbarscustomizedialog-class.md#create), chame [CMFCToolBarsCustomizeDialog::ReplaceButton](../mfc/reference/cmfctoolbarscustomizedialog-class.md#replacebutton) para substituir o botão padrão com o novo controle.  
  
## <a name="example-creating-a-find-combo-box"></a>Exemplo: Criando uma caixa de combinação localizar  
 Esta seção descreve como criar um `Find` controle de caixa de combinação que aparece na barra de ferramentas e contém cadeias de caracteres de pesquisa usados recentemente. O usuário pode digitar uma cadeia de caracteres no controle e, em seguida, pressione a tecla enter para pesquisar um documento ou pressione escape para retornar o foco para o quadro principal. Este exemplo supõe que o documento é exibido em uma [CEditView classe](../mfc/reference/ceditview-class.md)-derivado de exibição.  
  
### <a name="creating-the-find-control"></a>Criando o controle de localização  
 Primeiro, crie o `Find` controle caixa de combinação:  
  
1.  Adicione o botão e seus comandos para os recursos de aplicativos:  
  
    1.  Nos recursos do aplicativo, adicione um novo botão com um `ID_EDIT_FIND` ID de comando para uma barra de ferramentas em seu aplicativo e qualquer bitmaps associado com a barra de ferramentas.  
  
    2.  Criar um novo item de menu com a ID de comando ID_EDIT_FIND.  
  
    3.  Adicione uma nova cadeia de caracteres "Localizar o text\nFind" à tabela de cadeia de caracteres e atribua um `ID_EDIT_FIND_COMBO` comando ID. Essa ID será usada como a ID de comando de `Find` botão da caixa de combinação.  
  
        > [!NOTE]
        >  Porque `ID_EDIT_FIND` é um comando padrão que é processado pelo `CEditView`, não é necessário para implementar um manipulador especial para esse comando.  No entanto, você deve implementar um manipulador para o novo comando `ID_EDIT_FIND_COMBO`.  
  
2.  Criar uma nova classe, `CFindComboBox`, derivada de [classe CComboBox](../mfc/reference/ccombobox-class.md).  
  
3.  No `CFindComboBox` classe, substitua o `PreTranslateMessage` método virtual. Este método permitirá que a caixa de combinação processar o [WM_KEYDOWN](http://msdn.microsoft.com/library/windows/desktop/ms646280) mensagem. Se o usuário pressiona a tecla escape (`VK_ESCAPE`), retorna o foco para a janela do quadro principal. Se o usuário pressiona a tecla Enter (`VK_ENTER`), post para a janela do quadro principal um `WM_COMMAND` mensagem que contém o `ID_EDIT_FIND_COMBO` comando ID.  
  
4.  Crie uma classe para o `Find` botão da caixa de combinação, derivado do [CMFCToolBarComboBoxButton classe](../mfc/reference/cmfctoolbarcomboboxbutton-class.md). Neste exemplo, o nome usado é `CFindComboButton`.  
  
5.  O construtor de `CMFCToolbarComboBoxButton` usa três parâmetros: a ID de comando do botão, o índice de imagem do botão e o estilo da caixa de combinação. Defina esses parâmetros da seguinte maneira:  
  
    1.  Passar o `ID_EDIT_FIND_COMBO` como a ID de comando.  
  
    2.  Use [CCommandManager::GetCmdImage](http://msdn.microsoft.com/en-us/4094d08e-de74-4398-a483-76d27a742dca) com `ID_EDIT_FIND` para obter o índice de imagem.  
  
    3.  Para obter uma lista de estilos de caixa de combinação disponíveis, consulte [estilos de caixa de combinação](../mfc/reference/styles-used-by-mfc.md#combo-box-styles).  
  
6.  No `CFindComboButton` classe, substitua o `CMFCToolbarComboBoxButton::CreateCombo` método. Aqui você deve criar o `CFindComboButton` de objeto e retornar um ponteiro para ele.  
  
7.  Use o [IMPLEMENT_SERIAL](../mfc/reference/run-time-object-model-services.md#implement_serial) macro para que o botão de combinação persistente. O Gerenciador de espaço de trabalho automaticamente carrega e salva o estado do botão no registro do Windows.  
  
8.  Implementar o `ID_EDIT_FIND_COMBO` manipulador no modo de exibição de documento. Use [CMFCToolBar::GetCommandButtons](../mfc/reference/cmfctoolbar-class.md#getcommandbuttons) com `ID_EDIT_FIND_COMBO` para recuperar todas `Find` botões da caixa de combinação. Pode haver várias cópias de um botão com a mesma ID de comando devido a personalização.  
  
9. No manipulador de mensagens ID_EDIT_FIND `OnFind`, use [CMFCToolBar::IsLastCommandFromButton](../mfc/reference/cmfctoolbar-class.md#islastcommandfrombutton) para determinar se o comando Localizar foi enviado do `Find` botão da caixa de combinação. Nesse caso, localizar o texto e adicione a cadeia de caracteres de pesquisa à caixa de combinação.  
  
### <a name="adding-the-find-control-to-the-main-toolbar"></a>Adicionar o controle de localizar a barra de ferramentas principal  
 Para adicionar o botão de caixa de combinação na barra de ferramentas, siga estas etapas:  
  
1.  Implementar o `AFX_WM_RESETTOOLBAR` manipulador de mensagens `OnToolbarReset` na janela do quadro principal.  
  
    > [!NOTE]
    >  A estrutura envia essa mensagem para a janela do quadro principal quando uma barra de ferramentas é inicializada durante a inicialização do aplicativo, ou quando uma barra de ferramentas é redefinida durante a personalização. Em ambos os casos, você deve substituir o botão da barra de ferramentas padrão com personalizado `Find` botão da caixa de combinação.  
  
2.  No `AFX_WM_RESETTOOLBAR` manipulador, examine a ID de barra de ferramentas, ou seja, o `WPARAM` do `AFX_WM_RESETTOOLBAR` mensagem. Se a ID de barra de ferramentas é igual da barra de ferramentas que contém o `Find` botão da caixa de combinação, chamada [CMFCToolBar::ReplaceButton](../mfc/reference/cmfctoolbar-class.md#replacebutton) para substituir o `Find` botão (ou seja, o botão com a ID de comando `ID_EDIT_FIND)` com um `CFindComboButton` objeto.  
  
    > [!NOTE]
    >  Você pode construir um `CFindComboBox` o objeto na pilha, pois `ReplaceButton` copia o objeto de botão e mantém a cópia.  
  
### <a name="adding-the-find-control-to-the-customize-dialog-box"></a>Adicionar o controle de localizar a caixa de diálogo Personalizar  
 No manipulador de personalização `OnViewCustomize`, chame [CMFCToolBarsCustomizeDialog::ReplaceButton](../mfc/reference/cmfctoolbarscustomizedialog-class.md#replacebutton) para substituir o `Find` botão (ou seja, o botão com a ID de comando `ID_EDIT_FIND)` com um `CFindComboButton` objeto.  
  
## <a name="see-also"></a>Consulte também  
 [Gráfico de hierarquia](../mfc/hierarchy-chart.md)   
 [Classes](../mfc/reference/mfc-classes.md)   
 [Classe CMFCToolBar](../mfc/reference/cmfctoolbar-class.md)   
 [Classe CMFCToolBarButton](../mfc/reference/cmfctoolbarbutton-class.md)   
 [Classe CMFCToolBarComboBoxButton](../mfc/reference/cmfctoolbarcomboboxbutton-class.md)   
 [Classe CMFCToolBarsCustomizeDialog](../mfc/reference/cmfctoolbarscustomizedialog-class.md)
