---
title: 'Passo a passo: Atualizando o aplicativo de rabisco MFC (parte 2)'
ms.date: 04/25/2019
helpviewer_keywords:
- walkthroughs [MFC]
ms.assetid: 602df5c2-17d4-4cd9-8cf6-dff652c4cae5
ms.openlocfilehash: c22a11c54b1957c1d4ac735fe8cb577d9c483d35
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62371931"
---
# <a name="walkthrough-updating-the-mfc-scribble-application-part-2"></a>Passo a passo: Atualizando o aplicativo de rabisco MFC (parte 2)

[Parte 1](../mfc/walkthrough-updating-the-mfc-scribble-application-part-1.md) deste passo a passo mostrado como adicionar uma faixa de opções Fluent do Office para o clássico Scribble do aplicativo. Esta parte mostra como adicionar painéis de faixa de opções e controles que os usuários podem usar em vez de menus e comandos.

## <a name="prerequisites"></a>Pré-requisitos

[Exemplos do Visual C++](../overview/visual-cpp-samples.md)

##  <a name="top"></a> Seções

Esta parte do passo a passo tem as seguintes seções:

- [Adicionando novos painéis à faixa de opções](#addnewpanel)

- [Adicionar um painel de ajuda à faixa de opções](#addhelppanel)

- [Adicionar um painel de caneta à faixa de opções](#addpenpanel)

- [Adicionando um botão de cor à faixa de opções](#addcolorbutton)

- [Adicionar um membro de cor para a classe de documento](#addcolormember)

- [Inicializando canetas e salvar preferências](#initpensave)

##  <a name="addnewpanel"></a> Adicionando novos painéis à faixa de opções

Estas etapas mostram como adicionar um **modo de exibição** painel que contém duas caixas de seleção que controlam a visibilidade da barra de ferramentas e barra de status, e também um **janela** painel que contém uma divisão orientada verticalmente botão que controla a criação e a organização das janelas da interface de documentos múltiplos (MDI).

### <a name="to-add-a-view-panel-and-window-panel-to-the-ribbon-bar"></a>Para adicionar um painel de exibição e o painel de janela para a barra de faixa de opções

1. Criar um painel chamado `View`, que tem duas caixas de seleção que alternar a barra de status e a barra de ferramentas.

   1. Dos **caixa de ferramentas**, arraste um **painel** para o **Home** categoria. Em seguida, arraste dois **caixas de seleção** ao painel.

   1. Clique no painel para modificar suas propriedades. Alteração **legenda** para `View`.

   1. Clique na primeira caixa de seleção para modificar suas propriedades. Alteração **identificação** à `ID_VIEW_TOOLBAR` e **legenda** para `Toolbar`.

   1. Clique na segunda caixa para modificar suas propriedades. Alteração **identificação** à `ID_VIEW_STATUS_BAR` e **legenda** para `Status Bar`.

1. Criar um painel chamado `Window` que tem um botão de divisão. Quando um usuário clica no botão de divisão, um menu de atalho exibe três comandos que já estão definidos no aplicativo de rabisco.

   1. Dos **caixa de ferramentas**, arraste um **painel** para o **Home** categoria. Em seguida, arraste uma **botão** ao painel.

   1. Clique no painel para modificar suas propriedades. Alteração **legenda** para `Window`.

   1. Clique no botão. Alteração **legenda** à `Windows`, **chaves** para `w`, **índice de imagem grandes** para `1`, e **modo de divisão** para `False`. Em seguida, clique no botão de reticências (**...** ) ao lado **itens de Menu** para abrir o **Editor itens** caixa de diálogo.

   1. Clique em **adicionar** três vezes para adicionar três botões.

   1. Clique no primeiro botão e, em seguida, altere **legenda** à `New Window`, e **ID** para `ID_WINDOW_NEW`.

   1. Clique no segundo botão e, em seguida, altere **legenda** à `Cascade`, e **ID** para `ID_WINDOW_CASCADE`.

   1. Clique no terceiro botão e, em seguida, altere **legenda** à `Tile`, e **ID** para `ID_WINDOW_TILE_HORZ`.

1. Salve as alterações e, em seguida, compilar e executar o aplicativo. O **modo de exibição** e **janela** painéis devem ser exibidos. Clique nos botões para confirmar se eles funcionam corretamente.

##  <a name="addhelppanel"></a> Adicionar um painel de ajuda à faixa de opções

Agora, você pode atribuir dois itens de menu que são definidos no aplicativo de rabisco a botões da faixa de opções que são nomeados **tópicos da Ajuda** e **sobre o Rabisco**. Os botões são adicionados a um novo painel chamado **ajudar**.

### <a name="to-add-a-help-panel"></a>Para adicionar um painel de ajuda

1. Dos **caixa de ferramentas**, arraste um **painel** para o **Home** categoria. Em seguida, arraste dois **botões** ao painel.

1. Clique no painel para modificar suas propriedades. Alteração **legenda** para `Help`.

1. Clique no botão de primeira. Alteração **legenda** à `Help Topics`, e **ID** para `ID_HELP_FINDER`.

1. Clique no botão de segundo. Alteração **legenda** à `About Scribble...`, e **ID** para `ID_APP_ABOUT`.

1. Salve as alterações e, em seguida, compilar e executar o aplicativo. Um **ajudar** deve ser exibido o painel que contém dois botões de faixa de opções.

   > [!IMPORTANT]
   > Quando você clica o **tópicos da Ajuda** botão, o aplicativo de rabisco abre um arquivo compactado de ajuda HTML (. chm) denominado *your_project_name*. chm. Consequentemente, se seu projeto não é chamado de rabisco, você deve renomear o arquivo de ajuda para o nome do projeto.

##  <a name="addpenpanel"></a> Adicionar um painel de caneta à faixa de opções

Agora, adicione um painel para exibir botões que controlam a espessura e a cor da caneta. Este painel contém uma caixa de seleção que alterna entre canetas espessas e finas. Sua funcionalidade é semelhante do **linha espessa** item de menu no aplicativo de rabisco.

O aplicativo de rabisco original permite que o usuário selecione larguras de caneta na caixa de diálogo que aparece quando o usuário clica **larguras de caneta** no menu. Como a barra de faixa de opções tem bastante espaço para novos controles, você pode substituir a caixa de diálogo usando duas caixas de combinação na faixa de opções. Uma caixa de combinação ajusta a largura da caneta fina e caixa de combinação ajusta a largura da caneta grossa.

#### <a name="to-add-a-pen-panel-and-combo-boxes-to-the-ribbon"></a>Para adicionar caixas de combinação e de painel de uma caneta à faixa de opções

1. Dos **caixa de ferramentas**, arraste um **painel** para o **Home** categoria. Em seguida, arraste uma **caixa de seleção** e duas **caixas de combinação** ao painel.

1. Clique no painel para modificar suas propriedades. Alteração **legenda** para `Pen`.

1. Clique na caixa de seleção. Alteração **legenda** à `Use Thick`, e **ID** para `ID_PEN_THICK_OR_THIN`.

1. Clique na primeira caixa de combinação. Alteração **legenda** à `Thin Pen`, **ID** para `ID_PEN_THIN_WIDTH`, **tipo** para `Drop List`, **dados** para `1;2;3;4;5;6;7;8;9;`, e **texto** para `2`.

1. Clique na segunda caixa de combinação. Alteração **legenda** à `Thick Pen`, **ID** para `ID_PEN_THICK_WIDTH`, **tipo** para `Drop List`, **dados** para `5;6;7;8;9;10;11;12;13;14;15;16;17;18;19;20;`, e **texto** para `5`.

1. As novas caixas de combinação não correspondem a qualquer item de menu existentes, então você deve criar um item de menu para cada opção de caneta.

   1. No **exibição de recurso** janela, abra o **IDR_SCRIBBTYPE** de recurso de menu.

   1. Clique em **caneta** para abrir o menu de caneta. Em seguida, clique em **tipo aqui** e digite `Thi&n Pen`.

   1. Clique com botão direito o texto que você digitou para abrir o **propriedades** janela e, em seguida, alterar a ID de propriedade para `ID_PEN_THIN_WIDTH`.

   1. Crie um manipulador de eventos para cada item de menu de caneta. Clique com botão direito do **EST a & brir n** item de menu que você criou e, em seguida, clique em **Adicionar manipulador de eventos**. O **Assistente de manipulador de eventos** é exibida.

   1. No **lista de classes** caixa no assistente, selecione **CScribbleDoc** e, em seguida, clique em **adicionar e editar**. O comando cria um manipulador de eventos chamado `CScribbleDoc::OnPenThinWidth`.

   1. Adicione o código a seguir ao `CScribbleDoc::OnPenThinWidth`.

        ```cpp
        // Get a pointer to the ribbon bar
        CMFCRibbonBar* pRibbon = ((CMDIFrameWndEx*) AfxGetMainWnd())->GetRibbonBar();
        ASSERT_VALID(pRibbon);

        // Get a pointer to the Thin Width combo box
        CMFCRibbonComboBox* pThinComboBox = DYNAMIC_DOWNCAST(
        CMFCRibbonComboBox, pRibbon->FindByID(ID_PEN_THIN_WIDTH));

        //Get the selected value
        int nCurSel = pThinComboBox->GetCurSel();
        if (nCurSel>= 0)
        {
            m_nThinWidth = atoi(CStringA(pThinComboBox->GetItem(nCurSel)));
        }

        // Create a new pen using the selected width
        ReplacePen();
        ```

1. Em seguida, crie um menu de manipuladores de eventos e de item para a caneta grossa.

   1. No **exibição de recurso** janela, abra o **IDR_SCRIBBTYPE** de recurso de menu.

   1. Clique em **caneta** para abrir o menu de caneta. Em seguida, clique em **tipo aqui** e digite `Thic&k Pen`.

   1. Clique com botão direito o texto que você digitou para exibir o **propriedades** janela. Altere a propriedade de ID para `ID_PEN_THICK_WIDTH`.

   1. Com o botão direito do **caneta espessa** item de menu que você criou e, em seguida, clique em **Adicionar manipulador de eventos**. O **Assistente de manipulador de eventos** é exibida.

   1. No **lista de classes** caixa do assistente, selecione **CScribbleDoc** e, em seguida, clique em **adicionar e editar**. O comando cria um manipulador de eventos chamado `CScribbleDoc::OnPenThickWidth`.

   1. Adicione o código a seguir ao `CScribbleDoc::OnPenThickWidth`.

        ```cpp
        // Get a pointer to the ribbon bar
        CMFCRibbonBar* pRibbon = ((CMDIFrameWndEx *) AfxGetMainWnd())->GetRibbonBar();
        ASSERT_VALID(pRibbon);

        CMFCRibbonComboBox* pThickComboBox = DYNAMIC_DOWNCAST(
            CMFCRibbonComboBox, pRibbon->FindByID(ID_PEN_THICK_WIDTH));
        // Get the selected value
        int nCurSel = pThickComboBox->GetCurSel();
        if (nCurSel>= 0)
        {
            m_nThickWidth = atoi(CStringA(pThickComboBox->GetItem(nCurSel)));
        }

        // Create a new pen using the selected width
        ReplacePen();
        ```

1. Salve as alterações e, em seguida, compilar e executar o aplicativo. Novos botões e caixas de combinação devem ser exibidas. Tente usar larguras diferentes caneta Rabiscar.

##  <a name="addcolorbutton"></a> Adicionando um botão de cor ao painel de caneta

Em seguida, adicione uma [CMFCRibbonColorButton](../mfc/reference/cmfcribboncolorbutton-class.md) objeto que permite que o usuário Rabisco em cores.

### <a name="to-add-a-color-button-to-the-pen-panel"></a>Para adicionar um botão de cor ao painel de caneta

1. Antes de adicionar o botão de cor, crie um item de menu para ele. No **exibição de recurso** janela, abra o **IDR_SCRIBBTYPE** de recurso de menu. Clique o **caneta** item de menu para abrir o menu de caneta. Em seguida, clique em **tipo aqui** e digite `&Color`. Clique com botão direito o texto que você digitou para exibir o **propriedades** janela. Alterar a ID para `ID_PEN_COLOR`.

1. Agora, adicione o botão de cor. Dos **caixa de ferramentas**, arraste um **botão de cor** para o **caneta** painel.

1. Clique no botão de cor. Alteração **legenda** à `Color`, **ID** para `ID_PEN_COLOR`, **aparência simples** para `True`, **índice de imagem grandes** para `1`, e **modo de divisão** para `False`.

1. Salve as alterações e, em seguida, compilar e executar o aplicativo. O novo botão de cor deve ser exibido na **caneta** painel. No entanto, ele não pode ser usado porque ele ainda não tem um manipulador de eventos. As próximas etapas mostram como adicionar um manipulador de eventos para o botão de cor.

##  <a name="addcolormember"></a> Adicionar um membro de cor para a classe de documento

Como o aplicativo de rabisco original não tem canetas de cor, você deve escrever uma implementação para eles. Para armazenar a cor da caneta do documento, adicionar um novo membro à classe de documento, `CscribbleDoc`.

### <a name="to-add-a-color-member-to-the-document-class"></a>Para adicionar um membro de cor para a classe de documento

1. No scribdoc.h, no `CScribbleDoc` , localize o `// Attributes` seção. Adicione as seguintes linhas de código após a definição do `m_nThickWidth` membro de dados.

   ```cpp
   // Current pen color
   COLORREF m_penColor;
   ```

1. Todo documento contém uma lista dos traços que o usuário já tenha criado. Cada traço é definido por um `CStroke` objeto. O `CStroke` classe não inclui informações sobre a cor da caneta, portanto, você deve modificar a classe. No scribdoc.h, no `CStroke` da classe, adicione as seguintes linhas de código após a definição do `m_nPenWidth` membro de dados.

   ```cpp
   // Pen color for the stroke
   COLORREF m_penColor;
   ```

1. Scribdoc.h, adicione um novo `CStroke` construtor cujos parâmetros especificam uma largura e cor. Adicione a seguinte linha de código após o `CStroke(UINT nPenWidth);` instrução.

   ```cpp
   CStroke(UINT nPenWidth, COLORREF penColor);
   ```

1. Em scribdoc.cpp, adicione a implementação da nova `CStroke` construtor. Adicione o seguinte código após a implementação do `CStroke::CStroke(UINT nPenWidth)` construtor.

   ```cpp
   // Constructor that uses the document's current width and color
   CStroke::CStroke(UINT nPenWidth, COLORREF penColor)
   {
       m_nPenWidth = nPenWidth;
       m_penColor = penColor;
       m_rectBounding.SetRectEmpty();
   }
   ```

1. Alterar a segunda linha do `CStroke::DrawStroke` método da seguinte maneira.

   ```cpp
   if (!penStroke.CreatePen(PS_SOLID, m_nPenWidth, m_penColor))
   ```

1. Defina a cor da caneta padrão para a classe de documento. No scribdoc.cpp, adicione as seguintes linhas ao `CScribbleDoc::InitDocument`, após o `m_nThickWidth = 5;` instrução.

   ```cpp
   // default pen color is black
   m_penColor = RGB(0, 0, 0);
   ```

1. No scribdoc.cpp, altere a primeira linha do `CScribbleDoc::NewStroke` método ao seguinte.

   ```cpp
   CStroke* pStrokeItem = new CStroke(m_nPenWidth, m_penColor);
   ```

1. Alterar a última linha do `CScribbleDoc::ReplacePen` método ao seguinte.

   ```cpp
   m_penCur.CreatePen(PS_SOLID, m_nPenWidth, m_penColor);
   ```

1. Você adicionou o `m_penColor` membro em uma etapa anterior. Agora, crie um manipulador de eventos para o botão de cor que define o membro.

   1. No **exibição de recurso** janela, abra o recurso de menu IDR_SCRIBBTYPE.

   1. Clique com botão direito do **cor** item de menu e clique em **Adicionar manipulador de eventos**. O **Assistente de manipulador de eventos** é exibida.

   1. No **lista de classes** caixa no assistente, selecione **CScribbleDoc** e, em seguida, clique no **adicionar e editar** botão. O comando cria o `CScribbleDoc::OnPenColor` stub do manipulador de eventos.

1. Substitua o stub para o `CScribbleDoc::OnPenColor` manipulador de eventos com o código a seguir.

   ```cpp
   void CScribbleDoc::OnPenColor()
   {
       // Change pen color to reflect color button's current selection
       CMFCRibbonBar* pRibbon = ((CMDIFrameWndEx*) AfxGetMainWnd())->GetRibbonBar();
       ASSERT_VALID(pRibbon);

       CMFCRibbonColorButton* pColorBtn = DYNAMIC_DOWNCAST(
           CMFCRibbonColorButton, pRibbon->FindByID(ID_PEN_COLOR));

       m_penColor = pColorBtn->GetColor();
       // Create new pen using the selected color
       ReplacePen();
   }
   ```

1. Salve as alterações e, em seguida, compilar e executar o aplicativo. Agora você pode pressionar o botão de cor e alterar a cor da caneta.

##  <a name="initpensave"></a> Inicializando canetas e salvar preferências

Em seguida, inicialize a cor e a largura das canetas. Por fim, salvar e carregar uma cor de desenho de um arquivo.

### <a name="to-initialize-controls-on-the-ribbon-bar"></a>Para inicializar os controles na barra de faixa de opções

1. Inicialize as canetas na barra de faixa de opções.

   Adicione o seguinte código ao scribdoc.cpp, no `CScribbleDoc::InitDocument` método, após o `m_sizeDoc = CSize(200,200)` instrução.

   ```cpp
   // Reset the ribbon UI to its initial values
   CMFCRibbonBar* pRibbon =
       ((CMDIFrameWndEx*) AfxGetMainWnd())->GetRibbonBar();
   ASSERT_VALID(pRibbon);

   CMFCRibbonColorButton* pColorBtn = DYNAMIC_DOWNCAST(
       CMFCRibbonColorButton,
       pRibbon->FindByID(ID_PEN_COLOR));

   // Set ColorButton to black
   pColorBtn->SetColor(RGB(0, 0, 0));

   CMFCRibbonComboBox* pThinComboBox = DYNAMIC_DOWNCAST(
       CMFCRibbonComboBox,
       pRibbon->FindByID(ID_PEN_THIN_WIDTH));

   // Set Thin pen combobox to 2
   pThinComboBox->SelectItem(1);

   CMFCRibbonComboBox* pThickComboBox = DYNAMIC_DOWNCAST(
       CMFCRibbonComboBox,
       pRibbon->FindByID(ID_PEN_THICK_WIDTH));

   // Set Thick pen combobox to 5
   pThickComboBox->SelectItem(0);
   ```

1. Salve uma cor de desenho para um arquivo. Adicione a seguinte instrução para scribdoc.cpp, no `CStroke::Serialize` método, após o `ar << (WORD)m_nPenWidth;` instrução.

   ```cpp
   ar << (COLORREF)m_penColor;
   ```

1. Por fim, carregue uma cor de desenho de um arquivo. Adicione a seguinte linha de código, nos `CStroke::Serialize` método, após o `m_nPenWidth = w;` instrução.

   ```cpp
   ar >> m_penColor;
   ```

1. Agora, rabisco na cor e salvar seu desenho em um arquivo.

## <a name="conclusion"></a>Conclusão

Você atualizou o aplicativo de rabisco MFC. Use este passo a passo como um guia quando você modificar os aplicativos existentes.

## <a name="see-also"></a>Consulte também

[Explicações Passo a Passo](../mfc/walkthroughs-mfc.md)<br/>
[Passo a passo: atualizar o aplicativo de rabisco MFC (parte 1)](../mfc/walkthrough-updating-the-mfc-scribble-application-part-1.md)
