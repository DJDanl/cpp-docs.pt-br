---
title: 'Passo a passo: Atualizando o aplicativo de rabisco MFC (parte 2) | Microsoft Docs'
ms.custom: ''
ms.date: 06/28/2018
ms.technology:
- cpp-mfc
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- walkthroughs [MFC]
ms.assetid: 602df5c2-17d4-4cd9-8cf6-dff652c4cae5
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 351aea09376d6cba7f091828225fd337fa3f68e1
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46423140"
---
# <a name="walkthrough-updating-the-mfc-scribble-application-part-2"></a>Instruções passo a passo: atualizando o aplicativo de rabisco MFC (parte 2)

[Parte 1](../mfc/walkthrough-updating-the-mfc-scribble-application-part-1.md) deste passo a passo mostrado como adicionar uma faixa de opções Fluent do Office para o clássico Scribble do aplicativo. Esta parte mostra como adicionar painéis de faixa de opções e controles que os usuários podem usar em vez de menus e comandos.

## <a name="prerequisites"></a>Pré-requisitos

[Exemplos do Visual C++](../visual-cpp-samples.md)

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

   2. Clique no painel para modificar suas propriedades. Alteração **legenda** para `View`.

   3. Clique na primeira caixa de seleção para modificar suas propriedades. Alteração **identificação** à `ID_VIEW_TOOLBAR` e **legenda** para `Toolbar`.

   4. Clique na segunda caixa para modificar suas propriedades. Alteração **identificação** à `ID_VIEW_STATUS_BAR` e **legenda** para `Status Bar`.

2. Criar um painel chamado `Window` que tem um botão de divisão. Quando um usuário clica no botão de divisão, um menu de atalho exibe três comandos que já estão definidos no aplicativo de rabisco.

   1. Dos **caixa de ferramentas**, arraste um **painel** para o **Home** categoria. Em seguida, arraste uma **botão** ao painel.

   2. Clique no painel para modificar suas propriedades. Alteração **legenda** para `Window`.

   3. Clique no botão. Alteração **legenda** à `Windows`, **chaves** para `w`, **índice de imagem grandes** para `1`, e **modo de divisão** para `False`. Em seguida, clique no botão de reticências (**...** ) ao lado **itens de Menu** para abrir o **Editor itens** caixa de diálogo.

   4. Clique em **adicionar** três vezes para adicionar três botões.

   5. Clique no primeiro botão e, em seguida, altere **legenda** à `New Window`, e **ID** para `ID_WINDOW_NEW`.

   6. Clique no segundo botão e, em seguida, altere **legenda** à `Cascade`, e **ID** para `ID_WINDOW_CASCADE`.

   7. Clique no terceiro botão e, em seguida, altere **legenda** à `Tile`, e **ID** para `ID_WINDOW_TILE_HORZ`.

3. Salve as alterações e, em seguida, compilar e executar o aplicativo. O **modo de exibição** e **janela** painéis devem ser exibidos. Clique nos botões para confirmar se eles funcionam corretamente.

[[Seções](#top)]

##  <a name="addhelppanel"></a> Adicionar um painel de ajuda à faixa de opções

Agora, você pode atribuir dois itens de menu que são definidos no aplicativo de rabisco a botões da faixa de opções que são nomeados **tópicos da Ajuda** e **sobre o Rabisco**. Os botões são adicionados a um novo painel chamado **ajudar**.

### <a name="to-add-a-help-panel"></a>Para adicionar um painel de ajuda

1. Dos **caixa de ferramentas**, arraste um **painel** para o **Home** categoria. Em seguida, arraste dois **botões** ao painel.

2. Clique no painel para modificar suas propriedades. Alteração **legenda** para `Help`.

3. Clique no botão de primeira. Alteração **legenda** à `Help Topics`, e **ID** para `ID_HELP_FINDER`.

4. Clique no botão de segundo. Alteração **legenda** à `About Scribble...`, e **ID** para `ID_APP_ABOUT`.

5. Salve as alterações e, em seguida, compilar e executar o aplicativo. Um **ajudar** deve ser exibido o painel que contém dois botões de faixa de opções.

   > [!IMPORTANT]
   > Quando você clica o **tópicos da Ajuda** botão, o aplicativo de rabisco abre um arquivo compactado de ajuda HTML (. chm) denominado *your_project_name*. chm. Consequentemente, se seu projeto não é chamado de rabisco, você deve renomear o arquivo de ajuda para o nome do projeto.

[[Seções](#top)]

##  <a name="addpenpanel"></a> Adicionar um painel de caneta à faixa de opções

Agora, adicione um painel para exibir botões que controlam a espessura e a cor da caneta. Este painel contém uma caixa de seleção que alterna entre canetas espessas e finas. Sua funcionalidade é semelhante do **linha espessa** item de menu no aplicativo de rabisco.

O aplicativo de rabisco original permite que o usuário selecione larguras de caneta na caixa de diálogo que aparece quando o usuário clica **larguras de caneta** no menu. Como a barra de faixa de opções tem bastante espaço para novos controles, você pode substituir a caixa de diálogo usando duas caixas de combinação na faixa de opções. Uma caixa de combinação ajusta a largura da caneta fina e caixa de combinação ajusta a largura da caneta grossa.

#### <a name="to-add-a-pen-panel-and-combo-boxes-to-the-ribbon"></a>Para adicionar caixas de combinação e de painel de uma caneta à faixa de opções

1. Dos **caixa de ferramentas**, arraste um **painel** para o **Home** categoria. Em seguida, arraste uma **caixa de seleção** e duas **caixas de combinação** ao painel.

2. Clique no painel para modificar suas propriedades. Alteração **legenda** para `Pen`.

3. Clique na caixa de seleção. Alteração **legenda** à `Use Thick`, e **ID** para `ID_PEN_THICK_OR_THIN`.

4. Clique na primeira caixa de combinação. Alteração **legenda** à `Thin Pen`, **ID** para `ID_PEN_THIN_WIDTH`, **texto** para `2`, **tipo** para `Drop List`, e **dados** para `1;2;3;4;5;6;7;8;9;`.

5. Clique na segunda caixa de combinação. Alteração **legenda** à `Thick Pen`, **ID** para `ID_PEN_THICK_WIDTH`, **texto** para `5`, **tipo** para `Drop List`, e **dados** para `5;6;7;8;9;10;11;12;13;14;15;16;17;18;19;20;`.

6. As novas caixas de combinação não correspondem a qualquer item de menu existente. Portanto, você deve criar um item de menu para cada opção de caneta.

   1. No **exibição de recurso** janela, abra o recurso de menu IDR_SCRIBBTYPE.

   2. Clique em **caneta** para abrir o p**en** menu. Em seguida, clique em **tipo aqui** e digite `Thi&n Pen`.

   3. Clique com botão direito o texto que você acabou de digitar para abrir o **propriedades** janela e, em seguida, alterar a ID de propriedade para `ID_PEN_THIN_WIDTH`.

   4. Você também deve criar um manipulador de eventos para cada item de menu de caneta. Clique com botão direito do **EST a & brir n** item de menu que você acabou de criar e, em seguida, clique em **Adicionar manipulador de eventos**. O **Assistente de manipulador de eventos** é exibida.

   5. No **lista de classes** caixa no assistente, selecione **CScribbleDoc** e, em seguida, clique em **adicionar e editar**. Isso cria um manipulador de eventos chamado `CScribbleDoc::OnPenThinWidth`.

   6. Adicione o código a seguir ao `CScribbleDoc::OnPenThinWidth`.

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
        m_nThinWidth = atoi(pThinComboBox->GetItem(nCurSel));
    }

    // Create a new pen using the selected width
    ReplacePen();
    ```

7. Em seguida, crie um menu de manipuladores de eventos e de item para a caneta grossa.

   1. No **exibição de recurso** janela, abra o recurso de menu IDR_SCRIBBTYPE.

   2. Clique em **caneta** para abrir o menu de caneta. Em seguida, clique em **tipo aqui** e digite `Thic&k Pen`.

   3. Clique com botão direito o texto que você acabou de digitar para exibir o **propriedades** janela. Altere a propriedade de ID para `ID_PEN_THICK_WIDTH`.

   4. Clique com botão direito do **caneta espessa** item de menu que você acabou de criar e, em seguida, clique em **Adicionar manipulador de eventos**. O **Assistente de manipulador de eventos** é exibida.

   5. No **lista de classes** caixa do assistente, selecione **CScribbleDoc** e, em seguida, clique em **adicionar e editar**. Isso cria um manipulador de eventos chamado `CScribbleDoc::OnPenThickWidth`.

   6. Adicione o código a seguir ao `CScribbleDoc::OnPenThickWidth`.

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
          m_nThickWidth = atoi(pThickComboBox->GetItem(nCurSel));
      }

      // Create a new pen using the selected width
      ReplacePen();
      ```

8. Salve as alterações e, em seguida, compilar e executar o aplicativo. Novos botões e caixas de combinação devem ser exibidas. Tente usar larguras diferentes caneta Rabiscar.

[[Seções](#top)]

##  <a name="addcolorbutton"></a> Adicionando um botão de cor ao painel de caneta

Em seguida, adicione uma [CMFCRibbonColorButton](../mfc/reference/cmfcribboncolorbutton-class.md) objeto que permite que o usuário Rabisco em cores.

### <a name="to-add-a-color-button-to-the-pen-panel"></a>Para adicionar um botão de cor ao painel de caneta

1. Antes de adicionar o botão de cor, crie um item de menu para ele. No **exibição de recurso** janela, abra o recurso de menu IDR_SCRIBBTYPE. Clique o **caneta** item de menu para abrir o menu de caneta. Em seguida, clique em **tipo aqui** e digite `&Color`. Clique com botão direito o texto que você acabou de digitar para exibir o **propriedades** janela. Alterar a ID para `ID_PEN_COLOR`.

2. Agora, adicione o botão de cor. Dos **caixa de ferramentas**, arraste um **botão de cor** para o **caneta** painel.

3. Clique no botão de cor. Alteração **legenda** à `Color`, **ID** para `ID_PEN_COLOR`, **SimpleLook** para `True`, **índice de imagem grandes** para `1`, e **modo de divisão** para `False`.

4. Salve as alterações e, em seguida, compilar e executar o aplicativo. O novo botão de cor deve ser exibido na **caneta** painel. No entanto, ele não pode ser usado porque ele ainda não tem um manipulador de eventos. As próximas etapas mostram como adicionar um manipulador de eventos para o botão de cor.

[[Seções](#top)]

##  <a name="addcolormember"></a> Adicionar um membro de cor para a classe de documento

Porque o aplicativo de rabisco original não tem canetas de cor, você deve escrever uma implementação para eles. Para armazenar a cor da caneta do documento, adicionar um novo membro à classe de documento, `CscribbleDoc.`

### <a name="to-add-a-color-member-to-the-document-class"></a>Para adicionar um membro de cor para a classe de documento

1. No scribdoc.h, no `CScribbleDoc` , localize o `// Attributes` seção. Adicione as seguintes linhas de código após a definição do `m_nThickWidth` membro de dados.

   ```cpp
   // Current pen color
   COLORREF m_penColor;
   ```

2. Todo documento contém uma lista dos traços que o usuário já tenha criado. Cada traço é definido por um `CStroke` objeto. O `CStroke` classe inclui informações sobre a cor da caneta. Portanto, você deve modificar a classe. No scribdoc.h, no `CStroke` da classe, adicione as seguintes linhas de código após a definição do `m_nPenWidth` membro de dados.

   ```cpp
   // Pen color for the stroke
   COLORREF m_penColor;
   ```

3. Scribdoc.h, adicione um novo `CStroke` construtor cujos parâmetros especificam uma largura e cor. Adicione a seguinte linha de código após o `CStroke(UINT nPenWidth);` instrução.

   ```cpp
   CStroke(UINT nPenWidth, COLORREF penColor);
   ```

4. Em scribdoc.cpp, adicione a implementação da nova `CStroke` construtor. Adicione o seguinte código após a implementação do `CStroke::CStroke(UINT nPenWidth)` construtor.

   ```cpp
   // Constructor that uses the document's current width and color
   CStroke::CStroke(UINT nPenWidth, COLORREF penColor)
   {
       m_nPenWidth = nPenWidth;
       m_penColor = penColor;
       m_rectBounding.SetRectEmpty();
   }
   ```

5. Alterar a segunda linha do `CStroke::DrawStroke` método da seguinte maneira.

   ```cpp
   if (!penStroke.CreatePen(PS_SOLID, m_nPenWidth, m_penColor))
   ```

6. Defina a cor da caneta padrão para a classe de documento. No scribdoc.cpp, adicione as seguintes linhas ao `CScribbleDoc::InitDocument`, após o `m_nThickWidth = 5;` instrução.

   ```cpp
   // default pen color is black
   m_penColor = RGB(0, 0, 0);
   ```

7. No scribdoc.cpp, altere a primeira linha do `CScribbleDoc::NewStroke` método ao seguinte.

   ```cpp
   CStroke* pStrokeItem = new CStroke(m_nPenWidth, m_penColor);
   ```

8. Alterar a última linha do `CScribbleDoc::ReplacePen` método ao seguinte.

   ```cpp
   m_penCur.CreatePen(PS_SOLID, m_nPenWidth, m_penColor);
   ```

9. Você adicionou o `m_penColor` membro em uma etapa anterior. Agora, crie um manipulador de eventos para o botão de cor que define o membro.

   1. No **exibição de recurso** janela, abra o recurso de menu IDR_SCRIBBTYPE.

   2. Clique com botão direito do **cor** item de menu e clique em **Adicionar manipulador de eventos**. O **Assistente de manipulador de eventos** é exibida.

   3. No **lista de classes** caixa no assistente, selecione **CScribbleDoc** e, em seguida, clique no **adicionar e editar** botão. Isso cria o `CScribbleDoc::OnPenColor` stub do manipulador de eventos.

10. Substitua o stub para o `CScribbleDoc::OnPenColor` manipulador de eventos com o código a seguir.

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

11. Salve as alterações e, em seguida, compilar e executar o aplicativo. Você poderá pressionar o botão de cor e alterar a cor da caneta.

[[Seções](#top)]

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

2. Salve uma cor de desenho para um arquivo. Adicione a seguinte instrução para scribdoc.cpp, no `CStroke::Serialize` método, após o `ar << (WORD)m_nPenWidth;` instrução.

   ```cpp
   ar << (COLORREF)m_penColor;
    ```

3. Por fim, carregue uma cor de desenho de um arquivo. Adicione a seguinte linha de código, nos `CStroke::Serialize` método, após o `m_nPenWidth = w;` instrução.

   ```cpp
   ar >> m_penColor;
   ```

4. Agora, rabisco na cor e salvar seu desenho em um arquivo.

[[Seções](#top)]

## <a name="conclusion"></a>Conclusão

Você atualizou o aplicativo de rabisco MFC. Use este passo a passo como um guia quando você modificar os aplicativos existentes.

## <a name="see-also"></a>Consulte também

[Explicações Passo a Passo](../mfc/walkthroughs-mfc.md)<br/>
[Instruções passo a passo: atualizando o aplicativo de rabisco MFC (parte 1)](../mfc/walkthrough-updating-the-mfc-scribble-application-part-1.md)
