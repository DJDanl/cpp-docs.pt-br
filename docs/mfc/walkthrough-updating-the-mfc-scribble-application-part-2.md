---
title: 'Instruções passo a passo: atualizando o aplicativo de rabisco MFC (parte 2)'
ms.date: 04/25/2019
helpviewer_keywords:
- walkthroughs [MFC]
ms.assetid: 602df5c2-17d4-4cd9-8cf6-dff652c4cae5
ms.openlocfilehash: bc204a152168accf3731eede8ca9ef960ab121d2
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81360223"
---
# <a name="walkthrough-updating-the-mfc-scribble-application-part-2"></a>Instruções passo a passo: atualizando o aplicativo de rabisco MFC (parte 2)

[A parte 1](../mfc/walkthrough-updating-the-mfc-scribble-application-part-1.md) deste passo a passo mostrou como adicionar uma Fita Fluente do Office ao aplicativo clássico Scribble. Esta parte mostra como adicionar painéis de fita e controles que os usuários podem usar em vez de menus e comandos.

## <a name="prerequisites"></a>Pré-requisitos

[Exemplos do Visual C++](../overview/visual-cpp-samples.md)

## <a name="sections"></a><a name="top"></a>Seções

Esta parte do passo a passo tem as seguintes seções:

- [Adicionando novos painéis à fita](#addnewpanel)

- [Adicionando um painel de ajuda à fita](#addhelppanel)

- [Adicionando um painel de caneta à fita](#addpenpanel)

- [Adicionando um botão de cor à fita](#addcolorbutton)

- [Adicionando um membro de cor à classe de documentos](#addcolormember)

- [Inicializando canetas e poupando preferências](#initpensave)

## <a name="adding-new-panels-to-the-ribbon"></a><a name="addnewpanel"></a>Adicionando novos painéis à fita

Essas etapas mostram como adicionar um painel **De exibição** que contém duas caixas de seleção que controlam a visibilidade da barra de ferramentas e da barra de status, e também um painel **de janela** que contém um botão split orientado verticalmente que controla a criação e o arranjo de janelas de interface de vários documentos (MDI).

### <a name="to-add-a-view-panel-and-window-panel-to-the-ribbon-bar"></a>Para adicionar um painel Exibir e painel janela à barra de fita

1. Crie um `View`painel chamado , que tem duas caixas de seleção que alternam a barra de status e a barra de ferramentas.

   1. Na **caixa de ferramentas,** arraste um **painel** para a categoria **Home.** Em seguida, arraste duas **caixas de seleção** para o painel.

   1. Clique no painel para modificar suas propriedades. Alterar **Caption** legenda `View`para .

   1. Clique na primeira caixa de seleção para modificar suas propriedades. Alterar **id** `ID_VIEW_TOOLBAR` para `Toolbar`e **legenda** para .

   1. Clique na segunda caixa de seleção para modificar suas propriedades. Alterar **id** `ID_VIEW_STATUS_BAR` para `Status Bar`e **legenda** para .

1. Crie um `Window` painel chamado que tenha um botão split. Quando um usuário clica no botão split, um menu de atalho exibe três comandos que já estão definidos no aplicativo Rabiscar.

   1. Na **caixa de ferramentas,** arraste um **painel** para a categoria **Home.** Em seguida, arraste um **botão** para o painel.

   1. Clique no painel para modificar suas propriedades. Alterar **Caption** legenda `Window`para .

   1. Clique no botão. Alterar **Caption** legenda `Windows`para `w`, **chaves** para `1`, Grande índice de **imagem** para , e **modo de divisão** para `False`. Em seguida, clique na elipse (**...**) ao lado **de Itens do Menu** para abrir a caixa de diálogo Editor de **itens.**

   1. Clique **em Adicionar** três vezes para adicionar três botões.

   1. Clique no primeiro botão e, em seguida, **altere Legenda** para `New Window`, e **ID** para `ID_WINDOW_NEW`.

   1. Clique no segundo botão e, em seguida, **altere Legenda** para `Cascade`, e **ID** para `ID_WINDOW_CASCADE`.

   1. Clique no terceiro botão e, em seguida, **altere Legenda** para `Tile`, e **ID** para `ID_WINDOW_TILE_HORZ`.

1. Salve as alterações e, em seguida, construa e execute o aplicativo. Os painéis **Vista** e **Janela** devem ser exibidos. Clique nos botões para confirmar se funcionam corretamente.

## <a name="adding-a-help-panel-to-the-ribbon"></a><a name="addhelppanel"></a>Adicionando um painel de ajuda à fita

Agora, você pode atribuir dois itens de menu definidos no aplicativo Rabiscar para botões de fita que são chamados **de Tópicos de Ajuda** e Sobre **Rabiscos**. Os botões são adicionados a um novo painel chamado **Help**.

### <a name="to-add-a-help-panel"></a>Para adicionar um painel de ajuda

1. Na **caixa de ferramentas,** arraste um **painel** para a categoria **Home.** Em seguida, arraste dois **botões** para o painel.

1. Clique no painel para modificar suas propriedades. Alterar **Caption** legenda `Help`para .

1. Clique no primeiro botão. Alterar **Caption** legenda `Help Topics`para , `ID_HELP_FINDER`e **id** para .

1. Clique no segundo botão. Alterar **Caption** legenda `About Scribble...`para , `ID_APP_ABOUT`e **id** para .

1. Salve as alterações e, em seguida, construa e execute o aplicativo. Um painel **de ajuda** que contenha dois botões de fita deve ser exibido.

   > [!IMPORTANT]
   > Quando você clica no botão **'Tópicos de ajuda',** o aplicativo Scribble abre um arquivo de ajuda HTML compactado (.chm) chamado *your_project_name*.chm. Consequentemente, se o seu projeto não for chamado Scribble, você deve renomear o arquivo de ajuda para o nome do projeto.

## <a name="adding-a-pen-panel-to-the-ribbon"></a><a name="addpenpanel"></a>Adicionando um painel de caneta à fita

Agora, adicione um painel para exibir botões que controlam a espessura e a cor da caneta. Este painel contém uma caixa de seleção que alterna entre canetas grossas e finas. Sua funcionalidade se assemelha à do item de menu **Linha Grossa** no aplicativo Rabiscar.

O aplicativo Scribble original permite que o usuário selecione larguras de caneta de uma caixa de diálogo que aparece quando o usuário clica em **Larguras de caneta** no menu. Como a barra de fita tem amplo espaço para novos controles, você pode substituir a caixa de diálogo usando duas caixas de combinação na fita. Uma caixa de combinação ajusta a largura da caneta fina e a outra caixa combo ajusta a largura da caneta grossa.

#### <a name="to-add-a-pen-panel-and-combo-boxes-to-the-ribbon"></a>Para adicionar um painel de caneta e caixas de combinação à fita

1. Na **caixa de ferramentas,** arraste um **painel** para a categoria **Home.** Em seguida, arraste uma **caixa de seleção** e **duas caixas de combinação** para o painel.

1. Clique no painel para modificar suas propriedades. Alterar **Caption** legenda `Pen`para .

1. Clique na caixa de seleção. Alterar **Caption** legenda `Use Thick`para , `ID_PEN_THICK_OR_THIN`e **id** para .

1. Clique na primeira caixa de combinação. Alterar **Caption** legenda `Thin Pen`para , `ID_PEN_THIN_WIDTH` **ID** para `1;2;3;4;5;6;7;8;9;`, **Digitar** para `Drop List`, **Dados** para , e **Texto** para `2`.

1. Clique na segunda caixa de combinação. Alterar **Caption** legenda `Thick Pen`para , `ID_PEN_THICK_WIDTH` **ID** para `5;6;7;8;9;10;11;12;13;14;15;16;17;18;19;20;`, **Digitar** para `Drop List`, **Dados** para , e **Texto** para `5`.

1. As novas caixas de combinação não correspondem a nenhum item de menu existente, então você deve criar um item de menu para cada opção de caneta.

   1. Na janela **'Exibição de recursos',** abra o recurso de menu **IDR_SCRIBBTYPE.**

   1. Clique **em Caneta** para abrir o menu da caneta. Em seguida, clique `Thi&n Pen`em Digitar **Aqui** e digite .

   1. Clique com o botão direito do **Properties** mouse no texto digitado para `ID_PEN_THIN_WIDTH`abrir a janela Propriedades e, em seguida, altere a propriedade ID para .

   1. Crie um manipulador de eventos para cada item do menu de caneta. Clique com o botão direito do mouse no item do menu **Thi&n Pen** que você criou e clique em **Adicionar manipulador de eventos**. O **assistente de manipulador de eventos** é exibido.

   1. Na caixa **'Classe' no** assistente, selecione **CScribbleDoc** e clique **em Adicionar e Editar**. O comando cria um `CScribbleDoc::OnPenThinWidth`manipulador de eventos chamado .

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

1. Em seguida, crie um item de menu e manipuladores de eventos para a caneta grossa.

   1. Na janela **'Exibição de recursos',** abra o recurso de menu **IDR_SCRIBBTYPE.**

   1. Clique **em Caneta** para abrir o menu da caneta. Em seguida, clique `Thic&k Pen`em Digitar **Aqui** e digite .

   1. Clique com o botão direito do mouse no texto digitado para exibir a janela **Propriedades.** Mude a propriedade `ID_PEN_THICK_WIDTH`ID para .

   1. Clique com o botão direito do mouse no item do menu **Caneta Grossa** que você criou e clique em Adicionar manipulador **de eventos**. O **assistente de manipulador de eventos** é exibido.

   1. Na caixa **de lista de** classe do assistente, selecione **CScribbleDoc** e clique **em Adicionar e Editar**. O comando cria um `CScribbleDoc::OnPenThickWidth`manipulador de eventos chamado .

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

1. Salve as alterações e, em seguida, construa e execute o aplicativo. Novos botões e caixas de combinação devem ser exibidos. Tente usar diferentes larguras de caneta para rabiscar.

## <a name="adding-a-color-button-to-the-pen-panel"></a><a name="addcolorbutton"></a>Adicionando um botão de cor ao painel da caneta

Em seguida, adicione um objeto [CMFCRibbonColorButton](../mfc/reference/cmfcribboncolorbutton-class.md) que permite que o usuário rabisque em cores.

### <a name="to-add-a-color-button-to-the-pen-panel"></a>Para adicionar um botão de cor ao painel Caneta

1. Antes de adicionar o botão de cor, crie um item do menu para ele. Na janela **'Exibição de recursos',** abra o recurso de menu **IDR_SCRIBBTYPE.** Clique no item do menu **Caneta** para abrir o menu da caneta. Em seguida, clique `&Color`em Digitar **Aqui** e digite . Clique com o botão direito do mouse no texto digitado para exibir a janela **Propriedades.** Mude o ID para `ID_PEN_COLOR`.

1. Agora adicione o botão de cor. Na **caixa de ferramentas,** arraste um **botão de cor** para o painel **Caneta.**

1. Clique no botão de cor. Alterar **Caption** legenda `Color`para , `ID_PEN_COLOR` **ID** `True`para , Simples **Olhar** para `False`, Grande Índice **de Imagem** para `1`, e Modo de **divisão** para .

1. Salve as alterações e, em seguida, construa e execute o aplicativo. O novo botão de cor deve ser exibido no painel **Caneta.** No entanto, ele não pode ser usado porque ainda não tem um manipulador de eventos. Os próximos passos mostram como adicionar um manipulador de eventos para o botão de cor.

## <a name="adding-a-color-member-to-the-document-class"></a><a name="addcolormember"></a>Adicionando um membro de cor à classe de documentos

Como o aplicativo Scribble original não tem canetas coloridas, você deve escrever uma implementação para elas. Para armazenar a cor da caneta do documento, adicione `CscribbleDoc`um novo membro à classe de documentos, .

### <a name="to-add-a-color-member-to-the-document-class"></a>Para adicionar um membro de cor à classe de documentos

1. Em scribdoc.h, `CScribbleDoc` na classe, `// Attributes` encontrar a seção. Adicione as seguintes linhas de `m_nThickWidth` código após a definição do membro de dados.

   ```cpp
   // Current pen color
   COLORREF m_penColor;
   ```

1. Cada documento contém uma lista de stokes que o usuário já desenhou. Cada golpe é `CStroke` definido por um objeto. A `CStroke` classe não inclui informações sobre a cor da caneta, então você deve modificar a classe. Em scribdoc.h, `CStroke` na classe, adicione as seguintes linhas `m_nPenWidth` de código após a definição do membro de dados.

   ```cpp
   // Pen color for the stroke
   COLORREF m_penColor;
   ```

1. Em scribdoc.h, adicione `CStroke` um novo construtor cujos parâmetros especificam uma largura e cor. Adicione a seguinte linha `CStroke(UINT nPenWidth);` de código após a declaração.

   ```cpp
   CStroke(UINT nPenWidth, COLORREF penColor);
   ```

1. Em scribdoc.cpp, adicione a `CStroke` implementação do novo construtor. Adicione o seguinte código após `CStroke::CStroke(UINT nPenWidth)` a implementação do construtor.

   ```cpp
   // Constructor that uses the document's current width and color
   CStroke::CStroke(UINT nPenWidth, COLORREF penColor)
   {
       m_nPenWidth = nPenWidth;
       m_penColor = penColor;
       m_rectBounding.SetRectEmpty();
   }
   ```

1. Mude a segunda `CStroke::DrawStroke` linha do método da seguinte forma.

   ```cpp
   if (!penStroke.CreatePen(PS_SOLID, m_nPenWidth, m_penColor))
   ```

1. Defina a cor da caneta padrão para a classe de documentos. Em scribdoc.cpp, adicione as `CScribbleDoc::InitDocument`seguintes `m_nThickWidth = 5;` linhas a , após a declaração.

   ```cpp
   // default pen color is black
   m_penColor = RGB(0, 0, 0);
   ```

1. Em scribdoc.cpp, mude a `CScribbleDoc::NewStroke` primeira linha do método para a seguinte.

   ```cpp
   CStroke* pStrokeItem = new CStroke(m_nPenWidth, m_penColor);
   ```

1. Mude a última `CScribbleDoc::ReplacePen` linha do método para a seguinte.

   ```cpp
   m_penCur.CreatePen(PS_SOLID, m_nPenWidth, m_penColor);
   ```

1. Você adicionou o `m_penColor` membro em uma etapa anterior. Agora, crie um manipulador de eventos para o botão de cor que define o membro.

   1. Na janela **'Exibição de recursos',** abra o recurso de menu IDR_SCRIBBTYPE.

   1. Clique com o botão direito do mouse no item do menu **Cor** e clique **em Adicionar manipulador de eventos**. O **assistente do manipulador de eventos** é exibido.

   1. Na caixa **'Classe' no** assistente, selecione **CScribbleDoc** e clique no botão **Adicionar e Editar.** O comando `CScribbleDoc::OnPenColor` cria o stub do manipulador de eventos.

1. Substitua o `CScribbleDoc::OnPenColor` stub pelo manipulador de eventos pelo seguinte código.

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

1. Salve as alterações e, em seguida, construa e execute o aplicativo. Agora você pode pressionar o botão de cor e mudar a cor da caneta.

## <a name="initializing-pens-and-saving-preferences"></a><a name="initpensave"></a>Inicializando canetas e poupando preferências

Em seguida, inicialize a cor e a largura das canetas. Finalmente, salve e carregue um desenho de cor de um arquivo.

### <a name="to-initialize-controls-on-the-ribbon-bar"></a>Para inicializar controles na barra de fita

1. Inicialize as canetas na barra de fita.

   Adicione o seguinte código ao scribdoc.cpp, `CScribbleDoc::InitDocument` `m_sizeDoc = CSize(200,200)` no método, após a declaração.

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

1. Salve um desenho de cores em um arquivo. Adicione a seguinte declaração ao scribdoc.cpp, no `CStroke::Serialize` método, após a `ar << (WORD)m_nPenWidth;` declaração.

   ```cpp
   ar << (COLORREF)m_penColor;
   ```

1. Finalmente, carregue um desenho de cor de um arquivo. Adicione a seguinte linha de `CStroke::Serialize` código, `m_nPenWidth = w;` no método, após a declaração.

   ```cpp
   ar >> m_penColor;
   ```

1. Agora rabisque em cores e salve seu desenho em um arquivo.

## <a name="conclusion"></a>Conclusão

Você atualizou o aplicativo MFC Scribble. Use este passo a passo como um guia quando você modificar seus aplicativos existentes.

## <a name="see-also"></a>Confira também

[Passo a passo](../mfc/walkthroughs-mfc.md)<br/>
[Instruções passo a passo: atualizando o aplicativo de rabisco MFC (parte 1)](../mfc/walkthrough-updating-the-mfc-scribble-application-part-1.md)
