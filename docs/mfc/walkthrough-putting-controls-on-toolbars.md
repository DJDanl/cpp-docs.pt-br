---
title: "Instru&#231;&#245;es passo a passo: colocando controles em barras de ferramentas | Microsoft Docs"
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
  - "Caixa de diálogo Personalizar, adicionando controles"
  - "barras de ferramentas, adicionando controles"
ms.assetid: 8fc94bdf-0da7-45d9-8bc4-52b7b1edf205
caps.latest.revision: 24
caps.handback.revision: 20
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Instru&#231;&#245;es passo a passo: colocando controles em barras de ferramentas
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Este tópico descreve como adicionar um botão da barra de ferramentas que contém um controle do windows a uma barra de ferramentas.  MFC no, um botão da barra de ferramentas deve ser [Classe de CMFCToolBarButton](../mfc/reference/cmfctoolbarbutton-class.md)\- classe derivada, por exemplo [Classe de CMFCToolBarComboBoxButton](../Topic/CMFCToolBarComboBoxButton%20Class.md), [Classe de CMFCToolBarEditBoxButton](../Topic/CMFCToolBarEditBoxButton%20Class.md), [Classe de CMFCDropDownToolbarButton](../mfc/reference/cmfcdropdowntoolbarbutton-class.md), ou [Classe de CMFCToolBarMenuButton](../mfc/reference/cmfctoolbarmenubutton-class.md).  
  
## Adicionando controles barras de ferramentas  
 Para adicionar um controle para uma barra de ferramentas, siga estas etapas:  
  
1.  Permitir uma ID de recurso fictícia para o botão no recurso pai da barra de ferramentas.  Para obter mais informações sobre como criar os botões usando o editor da barra de ferramentas no Visual Studio, consulte o tópico de [Editor de Barra de Ferramentas](../mfc/toolbar-editor.md) .  
  
2.  Permitir uma imagem da barra de ferramentas \(ícone do botão\) para o botão em todos os bitmaps da barra de ferramentas pai.  
  
3.  No manipulador de mensagens que processa a mensagem de `AFX_WM_RESETTOOLBAR` , faça o seguinte:  
  
    1.  Construir o controle de botão usando `CMFCToolbarButton`\- classe derivada.  
  
    2.  Substitua o botão fictícia com o novo controle usando [CMFCToolBar::ReplaceButton](../Topic/CMFCToolBar::ReplaceButton.md).  Você pode construir o objeto botão na pilha, porque `ReplaceButton` copia o objeto do botão e mantém a cópia.  
  
> [!NOTE]
>  Se você personalização habilitado em seu aplicativo, você pode ter que redefinir a barra de ferramentas usando o botão de **Redefinir** na guia de **Barras de Ferramentas** da caixa de diálogo de **Personalizar** para ver o controle atualizado em seu aplicativo depois de recompilar.  O estado da barra de ferramentas será salvo no Registro do Windows, e as informações de Registro será carregada e aplicada depois que o método de `ReplaceButton` é executado durante a inicialização do aplicativo.  
  
## Controles da barra de ferramentas e personalização  
 O guia de **Comandos** da caixa de diálogo de **Personalizar** contém uma lista de comandos que estão disponíveis no aplicativo.  Por padrão, a caixa de diálogo de **Personalizar** processa os menus do aplicativo e cria uma lista de botões da barra de ferramentas padrão em cada categoria no menu.  Para reter a funcionalidade estendida que os controles da barra de ferramentas fornecem, você deve substituir o botão da barra de ferramentas padrão com o controle personalizado na caixa de diálogo de **Personalizar** .  
  
 Quando você habilita a personalização, a caixa de diálogo de **Personalizar** no manipulador `OnViewCustomize` de personalização usando a classe de [Classe de CMFCToolBarsCustomizeDialog](../mfc/reference/cmfctoolbarscustomizedialog-class.md) .  Antes que você exiba a caixa de diálogo de **Personalizar** chamando [CMFCToolBarsCustomizeDialog::Create](../Topic/CMFCToolBarsCustomizeDialog::Create.md), chame [CMFCToolBarsCustomizeDialog::ReplaceButton](../Topic/CMFCToolBarsCustomizeDialog::ReplaceButton.md) para substituir o botão padrão com o novo controle.  
  
## Exemplo: Criando uma caixa de combinação de localização  
 Esta seção descreve como criar um controle da caixa de combinação de `Find` que ele apareça na barra de ferramentas e contém cadeias de caracteres de pesquisa recentemente usadas.  O usuário pode digitar uma cadeia de caracteres no controle e depois pressione a tecla ENTER para pesquisar um documento, ou pressione a tecla de escape para retornar o foco para o quadro principal.  Este exemplo supõe que o documento é exibido em [Classe de CEditView](../Topic/CEditView%20Class.md)\- exibição derivada.  
  
### Criando o controle de localização  
 Primeiro, crie o controle da caixa de combinação de `Find` :  
  
1.  Botão adicionar e os comandos aos recursos de aplicativo:  
  
    1.  Os recursos do aplicativo, adicione um novo botão com uma ID de comando de `ID_EDIT_FIND` a uma barra de ferramentas no aplicativo e a todos os bitmaps associados à barra de ferramentas.  
  
    2.  Crie um novo item de menu com a ID de comando de ID\_EDIT\_FIND  
  
    3.  Adicione uma nova cadeia de caracteres “localizar o texto \\ nFind” na tabela de cadeia de caracteres e atribuem\-lhe uma ID de comando de `ID_EDIT_FIND_COMBO` Essa ID será usado como a ID de comando do botão da caixa de combinação de `Find` .  
  
        > [!NOTE]
        >  Como `ID_EDIT_FIND` é um comando padrão que foi processado por `CEditView`, você não precisa implementar um manipulador especial para este comando.  Porém, você deve implementar um manipulador para o novo comando `ID_EDIT_FIND_COMBO`.  
  
2.  Crie uma nova classe, `CFindComboBox`, derivado de [Classe de CComboBox](../mfc/reference/ccombobox-class.md).  
  
3.  A classe de `CFindComboBox` , substitua o método virtual de `PreTranslateMessage` .  Esse método habilitará a caixa de combinação para processar a mensagem de [WM\_KEYDOWN](http://msdn.microsoft.com/library/windows/desktop/ms646280) .  Se o usuário acessa a chave de escape \(`VK_ESCAPE`\), retornar o foco para a janela principal do quadro.  Se o usuário acessa a tecla ENTER`VK_ENTER`\(\), postar a janela principal do quadro uma mensagem de `WM_COMMAND` que contém a ID de comando de `ID_EDIT_FIND_COMBO`  
  
4.  Crie uma classe para o botão da caixa de combinação de `Find` , derivado de [Classe de CMFCToolBarComboBoxButton](../Topic/CMFCToolBarComboBoxButton%20Class.md).  Neste exemplo, é nomeado `CFindComboButton`.  
  
5.  O construtor de `CMFCToolbarComboBoxButton` usa três parâmetros: a ID de comando do botão, do índice da imagem do botão, e o estilo da caixa de combinação.  Definir esses parâmetros da seguinte maneira:  
  
    1.  Passe `ID_EDIT_FIND_COMBO` como ID de comando  
  
    2.  Use [CCommandManager::GetCmdImage](http://msdn.microsoft.com/pt-br/4094d08e-de74-4398-a483-76d27a742dca) com `ID_EDIT_FIND` para obter o índice da imagem.  
  
    3.  Para obter uma lista de estilos disponíveis na caixa de combinação, consulte [Estilos de caixa de combinação](../mfc/reference/combo-box-styles.md).  
  
6.  A classe de `CFindComboButton` , substitua o método de `CMFCToolbarComboBoxButton::CreateCombo` .  Aqui você deve criar o objeto de `CFindComboButton` e retornar um ponteiro a ele.  
  
7.  Use a macro de [IMPLEMENT\_SERIAL](../Topic/IMPLEMENT_SERIAL.md) para fazer o botão combinado persistente.  O gerenciador de espaço de trabalho automaticamente carrega e salva o estado do botão no Registro do Windows.  
  
8.  Implementar o manipulador de `ID_EDIT_FIND_COMBO` na exibição de documento.  Use [CMFCToolBar::GetCommandButtons](../Topic/CMFCToolBar::GetCommandButtons.md) com `ID_EDIT_FIND_COMBO` para recuperar todos os botões da caixa de combinação de `Find` .  Pode haver várias cópias de um botão com a mesma ID do comando devido à personalização.  
  
9. No manipulador de mensagens `OnFind`de ID\_EDIT\_FIND, use [CMFCToolBar::IsLastCommandFromButton](../Topic/CMFCToolBar::IsLastCommandFromButton.md) determinar se o comando de localização esteve enviado do botão da caixa de combinação de `Find` .  Nesse caso, localize o texto e adicionar a cadeia de caracteres de pesquisa na caixa de combinação.  
  
### Adicionando o controle de localizar à barra de ferramentas principal  
 Para adicionar o botão da caixa de combinação à barra de ferramentas, siga estas etapas:  
  
1.  Implementar o manipulador de mensagens `OnToolbarReset` de `AFX_WM_RESETTOOLBAR` na janela principal do quadro.  
  
    > [!NOTE]
    >  A estrutura envia essa mensagem à janela principal do quadro quando uma barra de ferramentas será inicializada durante a inicialização do aplicativo, ou quando uma barra de ferramentas são redefinidas durante a personalização.  Em ambos os casos, você deve substituir o botão da barra de ferramentas padrão com o botão da caixa de combinação de `Find` personalizadas.  
  
2.  No manipulador de `AFX_WM_RESETTOOLBAR` , examine a ID da barra de ferramentas, ou seja, `WPARAM` da mensagem de `AFX_WM_RESETTOOLBAR` .  Se a ID da barra de ferramentas é igual a da barra de ferramentas que contém o botão da caixa de combinação de `Find` , chame [CMFCToolBar::ReplaceButton](../Topic/CMFCToolBar::ReplaceButton.md) para substituir o botão de `Find` \(isto é, o botão com a ID `ID_EDIT_FIND)` de comando com um objeto de `CFindComboButton` .  
  
    > [!NOTE]
    >  Você pode construir um objeto de `CFindComboBox` na pilha, porque `ReplaceButton` copia o objeto do botão e mantém a cópia.  
  
### Adicionando o controle de localização na caixa de diálogo personalizar  
 No manipulador `OnViewCustomize`de personalização, chame [CMFCToolBarsCustomizeDialog::ReplaceButton](../Topic/CMFCToolBarsCustomizeDialog::ReplaceButton.md) para substituir o botão de `Find` \(isto é, o botão com a ID `ID_EDIT_FIND)` de comando com um objeto de `CFindComboButton` .  
  
## Consulte também  
 [Gráfico da hierarquia](../mfc/hierarchy-chart.md)   
 [Classes](../Topic/MFC%20Classes.md)   
 [Classe de CMFCToolBar](../mfc/reference/cmfctoolbar-class.md)   
 [Classe de CMFCToolBarButton](../mfc/reference/cmfctoolbarbutton-class.md)   
 [Classe de CMFCToolBarComboBoxButton](../Topic/CMFCToolBarComboBoxButton%20Class.md)   
 [Classe de CMFCToolBarsCustomizeDialog](../mfc/reference/cmfctoolbarscustomizedialog-class.md)