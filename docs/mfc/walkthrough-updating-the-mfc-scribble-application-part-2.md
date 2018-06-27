---
title: 'Passo a passo: Atualizando o aplicativo de rabisco MFC (parte 2) | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
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
ms.openlocfilehash: 83caf353ca4a45e3ae834a41062de955a91dbb8a
ms.sourcegitcommit: c6b095c5f3de7533fd535d679bfee0503e5a1d91
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/26/2018
ms.locfileid: "36952412"
---
# <a name="walkthrough-updating-the-mfc-scribble-application-part-2"></a>Instruções passo a passo: atualizando o aplicativo de rabisco MFC (parte 2)
[Parte 1](../mfc/walkthrough-updating-the-mfc-scribble-application-part-1.md) deste passo a passo mostrada como adicionar uma faixa de opções do Office Fluent para clássica Rabisco aplicativo. Esta parte mostra como adicionar painéis de faixa de opções e os controles que os usuários podem usar em vez de menus e comandos.  
  
## <a name="prerequisites"></a>Pré-requisitos  
 [Exemplos do Visual C++](../visual-cpp-samples.md)  
  
##  <a name="top"></a> Seções  
 Esta parte do passo a passo tem as seguintes seções:  
  
- [Adicionando novos painéis a faixa de opções](#addnewpanel)  
  
- [Adicionar um painel de ajuda para a faixa de opções](#addhelppanel)  
  
- [Adicionando um painel de caneta a faixa de opções](#addpenpanel)  
  
- [Adicionar um botão de cor para a faixa de opções](#addcolorbutton)  
  
- [Adicionando um membro de cor para a classe de documento](#addcolormember)  
  
- [Inicializando canetas e preferências para salvar](#initpensave)  
  
##  <a name="addnewpanel"></a> Adicionando novos painéis a faixa de opções  
 Estas etapas mostram como adicionar um **exibição** painel que contém duas caixas de seleção que controlam a visibilidade da barra de ferramentas e barra de status, e também um **janela** painel que contém uma divisão orientação vertical botão que controla a criação e a organização das janelas de interface de documentos múltiplos (MDI).  
  
#### <a name="to-add-a-view-panel-and-window-panel-to-the-ribbon-bar"></a>Para adicionar um painel de exibição e o painel de janela para a barra de faixa de opções  
  
1.  Criar um painel chamado *exibição*, que tem duas caixas de seleção que alternar a barra de status e a barra de ferramentas.  
  
    1.  Do **caixa de ferramentas**, arraste um **painel** para o **início** categoria. Em seguida, arraste dois **caixas de seleção** ao painel.  
  
    2.  Clique no painel para modificar suas propriedades. Alterar **legenda** para *exibição*.  
  
    3.  Clique na primeira caixa de seleção para modificar suas propriedades. Alterar **ID** para *ID_VIEW_TOOLBAR* e **legenda** para *barra de ferramentas*.  
  
    4.  Clique na segunda caixa para modificar suas propriedades. Alterar **ID** para *ID_VIEW_STATUS_BAR* e **legenda** para *barra de Status*.  
  
2.  Criar um painel chamado *janela* que tem um botão de divisão. Quando um usuário clica no botão de divisão, um menu de atalho exibe três comandos que já estão definidos no aplicativo de rabisco.  
  
    1.  Do **caixa de ferramentas**, arraste um **painel** para o **início** categoria. Em seguida, arraste um **botão** ao painel.  
  
    2.  Clique no painel para modificar suas propriedades. Alterar **legenda** para *janela*.  
  
    3.  Clique no botão. Alterar **legenda** para *Windows*, **chaves** para *w*, **índice de imagem grande** para *1* , e **modo de divisão** para *False*. Em seguida, clique no botão de reticências (**...** ) ao lado de **itens de Menu** para abrir o **itens Editor** caixa de diálogo.  
  
    4.  Clique em **adicionar** três vezes para adicionar três botões.  
  
    5.  Clique no primeiro botão e, em seguida, alterar **legenda** para *nova janela*, e **ID** para *ID_WINDOW_NEW*.  
  
    6.  Clique no segundo botão e, em seguida, alterar **legenda** para *Cascade*, e **ID** para *ID_WINDOW_CASCADE*.  
  
    7.  Clique no botão de terceiro e, em seguida, alterar **legenda** para *bloco*, e **ID** para *ID_WINDOW_TILE_HORZ*.  
  
3.  Salvar as alterações e, em seguida, compilar e executar o aplicativo. O **exibição** e **janela** painéis devem ser exibidos. Clique nos botões para confirmar que funcionem corretamente.  
  
 [[Seções](#top)]  
  
##  <a name="addhelppanel"></a> Adicionar um painel de ajuda para a faixa de opções  
 Agora, você pode atribuir dois itens de menu que são definidos no aplicativo de rabisco para botões da faixa de opções que são nomeados **tópicos da Ajuda** e **sobre Rabisco**. Os botões são adicionados a um novo painel chamado **ajuda**.  
  
#### <a name="to-add-a-help-panel"></a>Para adicionar um painel de ajuda  
  
1.  Do **caixa de ferramentas**, arraste um **painel** para o **início** categoria. Em seguida, arraste dois **botões** ao painel.  
  
2.  Clique no painel para modificar suas propriedades. Alterar **legenda** para *ajuda*.  
  
3.  Clique no primeiro botão. Alterar **legenda** para *tópicos da Ajuda*, e **ID** para *ID_HELP_FINDER*.  
  
4.  Clique no botão de segundo. Alterar **legenda** para *sobre Rabisco...* , e **ID** para *ID_APP_ABOUT*.  
  
5.  Salvar as alterações e, em seguida, compilar e executar o aplicativo. Um **ajuda** painel que contém dois botões da faixa de opções deve ser exibido.  
  
    > [!IMPORTANT]
    >  Quando você clica o **tópicos da Ajuda** botão, o aplicativo de rabisco abre um arquivo de ajuda HTML (. chm) compactado chamado *your_project_name*. chm. Consequentemente, se seu projeto não é chamado rabisco, você deve renomear o arquivo de ajuda para o nome do projeto.  
  
 [[Seções](#top)]  
  
##  <a name="addpenpanel"></a> Adicionando um painel de caneta a faixa de opções  
 Agora, adicione um painel para exibir botões que controlam a espessura e a cor da caneta. Este painel contém uma caixa de seleção que alterna entre canetas espessas e dinâmico. Sua funcionalidade é semelhante do **linha espessa** item de menu do aplicativo de rabisco.  
  
 O aplicativo de rabisco original permite que o usuário selecione larguras de caneta na caixa de diálogo que aparece quando o usuário clica **larguras de caneta** no menu. Como a barra de faixa de opções tem bastante espaço para novos controles, você pode substituir a caixa de diálogo usando duas caixas de combinação na faixa de opções. Uma caixa de combinação ajusta a largura da caneta fina e caixa de combinação ajusta a largura da caneta espessa.  
  
#### <a name="to-add-a-pen-panel-and-combo-boxes-to-the-ribbon"></a>Para adicionar um painel de caneta e combinação caixas à faixa de opções  
  
1.  Do **caixa de ferramentas**, arraste um **painel** para o **início** categoria. Em seguida, arraste um **caixa de seleção** e dois **caixas de combinação** ao painel.  
  
2.  Clique no painel para modificar suas propriedades. Alterar **legenda** para *caneta*.  
  
3.  Clique na caixa de seleção. Alterar **legenda** para *usar espesso*, e **ID** para *ID_PEN_THICK_OR_THIN*.  
  
4.  Clique na primeira caixa de combinação. Alterar **legenda** para *fino caneta*, **ID** para *ID_PEN_THIN_WIDTH*, **texto** para *2* , **Tipo** para *lista suspensa*, e **dados** para *1; 2; 3; 4; 5; 6; 7; 8; 9;*.  
  
5.  Clique na segunda caixa de combinação. Alterar **legenda** para *caneta espessa*, **ID** para *ID_PEN_THICK_WIDTH*, **texto** para  *5*, **tipo** para *lista suspensa*, e **dados** para *5, 6, 7; 8; 9; 10; 11; 12; 13; 14; 15; 16; 17; 18; 19, 20;*.  
  
6.  As novas caixas de combinação não corresponde a qualquer item de menu existente. Portanto, você deve criar um item de menu para cada opção de caneta.  
  
    1.  No **exibição recursos** janela, abra o recurso de menu IDR_SCRIBBTYPE.  
  
    2.  Clique em **caneta** para abrir o p**en** menu. Em seguida, clique em **tipo aqui** e tipo *est & Caneta n*.  
  
    3.  Clique o texto que você acabou de digitar para abrir o **propriedades** janela e, em seguida, alterar a ID de propriedade para *ID_PEN_THIN_WIDTH*.  
  
    4.  Você também deve criar um manipulador de eventos para cada item de menu de caneta. Clique com botão direito do **est & Caneta n** item de menu que você acabou de criar e, em seguida, clique em **Adicionar manipulador de eventos**. O **Assistente de manipulador de eventos** é exibido.  
  
    5.  No **lista de classes** caixa no assistente, selecione **CScribbleDoc** e, em seguida, clique em **adicionar e editar**. Isso cria um manipulador de eventos chamado `CScribbleDoc::OnPenThinWidth`.  
  
    6.  Adicione o código a seguir ao `CScribbleDoc::OnPenThinWidth`.  
  
 ``` *Obter um ponteiro para a faixa de opções barra CMFCRibbonBar* pRibbon = ((CMDIFrameWndEx*) AfxGetMainWnd()) -> GetRibbonBar(); ASSERT_VALID(pRibbon); */ / Obter um ponteiro para a caixa de combinação da largura Thin CMFCRibbonComboBox* pThinComboBox = DYNAMIC_DOWNCAST (CMFCRibbonComboBox, pRibbon FindByID(ID_PEN_THIN_WIDTH)); -> * //Get o valor selecionado  
    int nCurSel = pThinComboBox -> GetCurSel(); Se (nCurSel > = 0)  
{  
m_nThinWidth = atoi (pThinComboBox -> GetItem(nCurSel));

 } * / / Crie uma nova caneta usando a largura selecionada  
    ReplacePen();

 ```  
  
7.  Next, create a menu item and event handlers for the thick pen.  
  
    1.  In the **Resource View** window, open the IDR_SCRIBBTYPE menu resource.  
  
    2.  Click **Pen** to open the pen menu. Then click **Type Here** and type *Thic&k Pen*.  
  
    3.  Right-click the text that you just typed to display the **Properties** window. Change the ID property to *ID_PEN_THICK_WIDTH*.  
  
    4.  Right-click the **Thick Pen** menu item that you just created and then click **Add Event Handler**. The **Event Handler Wizard** is displayed.  
  
    5.  In the **Class list** box of the wizard, select **CScribbleDoc** and then click **Add and Edit**. This creates an event handler named `CScribbleDoc::OnPenThickWidth`.  
  
    6.  Add the following code to `CScribbleDoc::OnPenThickWidth`.  
  
 ``` *// Get a pointer to the ribbon bar  
    CMFCRibbonBar* pRibbon = ((CMDIFrameWndEx *) AfxGetMainWnd())->GetRibbonBar();
ASSERT_VALID(pRibbon);

 CMFCRibbonComboBox* pThickComboBox = DYNAMIC_DOWNCAST(
    CMFCRibbonComboBox, pRibbon->FindByID(ID_PEN_THICK_WIDTH));
*// Get the selected value  
    int nCurSel = pThickComboBox->GetCurSel();
if (nCurSel>= 0)  
 {  
    m_nThickWidth = atoi(pThickComboBox->GetItem(nCurSel));

 } *// Create a new pen using the selected width  
    ReplacePen();

 ```  
  
8.  Salvar as alterações e, em seguida, compilar e executar o aplicativo. Novos botões e caixas de combinação devem ser exibidas. Tente usar larguras de caneta diferentes Rabisco.  
  
 [[Seções](#top)]  
  
##  <a name="addcolorbutton"></a> Adicionar um botão de cor para o painel de caneta  
 Em seguida, adicione um [CMFCRibbonColorButton](../mfc/reference/cmfcribboncolorbutton-class.md) objeto que permite que o usuário Rabisco cor.  
  
#### <a name="to-add-a-color-button-to-the-pen-panel"></a>Para adicionar um botão de cor para o painel de caneta  
  
1.  Antes de adicionar o botão de cor, crie um item de menu para ele. No **exibição recursos** janela, abra o recurso de menu IDR_SCRIBBTYPE. Clique o **caneta** item de menu para abrir o menu de caneta. Em seguida, clique em **tipo aqui** e tipo *& cor*. Clique o texto que você acabou de digitar para exibir o **propriedades** janela. Alterar a ID para *ID_PEN_COLOR*.  
  
2.  Agora, adicione o botão de cor. Do **caixa de ferramentas**, arraste um **botão de cor** para o **caneta** painel.  
  
3.  Clique no botão de cor. Alterar **legenda** para *cor*, **ID** para *ID_PEN_COLOR*, **SimpleLook** para  *True*, **índice de imagem grande** para *1*, e **modo de divisão** para *False*.  
  
4.  Salvar as alterações e, em seguida, compilar e executar o aplicativo. O novo botão de cor deve ser exibido no **caneta** painel. No entanto, ele não pode ser usado porque ele ainda não tiver um manipulador de eventos. As próximas etapas mostram como adicionar um manipulador de eventos para o botão de cor.  
  
 [[Seções](#top)]  
  
##  <a name="addcolormember"></a> Adicionando um membro de cor para a classe de documento  
 Como o aplicativo de rabisco original não têm canetas de cor, você deve escrever uma implementação para eles. Para armazenar a cor da caneta do documento, adicionar um novo membro para a classe de documento `CscribbleDoc.`  
  
#### <a name="to-add-a-color-member-to-the-document-class"></a>Para adicionar um membro de cor para a classe de documento  
  
1.  Em scribdoc.h, no `CScribbleDoc` classe, localize o `// Attributes` seção. Adicione as seguintes linhas de código após a definição do `m_nThickWidth` membro de dados.  
  
 ' ' * / / Cor da caneta atual  
    COLORREF m_penColor;  
 ```  
  
2.  Every document contains a list of stokes that the user has already drawn. Every stroke is defined by a `CStroke` object. The `CStroke` class does not include information about pen color. Therefore, you must modify the class. In scribdoc.h, in the `CStroke` class, add the following lines of code after the definition of the `m_nPenWidth` data member.  
  
 ``` *// Pen color for the stroke  
    COLORREF m_penColor;  
 ```  
  
3.  Scribdoc.h, adicione um novo `CStroke` construtor cujos parâmetros especificam uma largura e cor. Adicione a seguinte linha de código após a `CStroke(UINT nPenWidth);` instrução.  
  
 ```  
    CStroke(UINT nPenWidth, COLORREF penColor);

 ```  
  
4.  Em scribdoc.cpp, adicione a implementação do novo `CStroke` construtor. Adicione o seguinte código após a implementação do `CStroke::CStroke(UINT nPenWidth)` construtor.  
  
 ' ' * / / Atual do construtor que usa o documento de largura e a cor  
    CStroke::CStroke (UINT nPenWidth, penColor COLORREF)  
 {  
    m_nPenWidth = nPenWidth;  
    m_penColor = penColor;  
    m_rectBounding.SetRectEmpty();

 }  
 ```  
  
5.  Change the second line of the `CStroke::DrawStroke` method as follows.  
  
 ```  
    Se (! penStroke.CreatePen (PS_SOLID, m_nPenWidth, m_penColor))  
 ```  
  
6.  Set the default pen color for the document class. In scribdoc.cpp, add the following lines to `CScribbleDoc::InitDocument`, after the `m_nThickWidth = 5;` statement.  
  
 ``` *// default pen color is black  
    m_penColor = RGB(0,
    0,
    0);

 ```  
  
7.  Em scribdoc.cpp, altere a primeira linha do `CScribbleDoc::NewStroke` método a seguir.  
  
 ```  
    CStroke* pStrokeItem = new CStroke(m_nPenWidth, m_penColor);

 ```  
  
8.  Alterar a última linha do `CScribbleDoc::ReplacePen` método a seguir.  
  
 ```  
    m_penCur.CreatePen(PS_SOLID,
    m_nPenWidth,
    m_penColor);

 ```  
  
9. Você adicionou o `m_penColor` membro em uma etapa anterior. Agora, crie um manipulador de eventos para o botão de cor que define o membro.  
  
    1.  No **exibição recursos** janela, abra o recurso de menu IDR_SCRIBBTYPE.  
  
    2.  Clique com botão direito do **cor** item de menu e clique em **Adicionar manipulador de eventos**. O **Assistente de manipulador de eventos** é exibida.  
  
    3.  No **lista de classes** caixa no assistente, selecione **CScribbleDoc** e, em seguida, clique no **adicionar e editar** botão. Isso cria o `CScribbleDoc::OnPenColor` stub do manipulador de eventos.  
  
10. Substituir o stub para o `CScribbleDoc::OnPenColor` manipulador de eventos com o código a seguir.  
  
 ```  
    void CScribbleDoc::OnPenColor()  
 { *// Change pen color to reflect color button's current selection  
    CMFCRibbonBar* pRibbon = ((CMDIFrameWndEx*) AfxGetMainWnd())->GetRibbonBar();
ASSERT_VALID(pRibbon);

 CMFCRibbonColorButton* pColorBtn = DYNAMIC_DOWNCAST(
    CMFCRibbonColorButton, pRibbon->FindByID(ID_PEN_COLOR));

    m_penColor = pColorBtn->GetColor();
*// Create new pen using the selected color  
    ReplacePen();

 }  
 ```  
  
11. Salvar as alterações e, em seguida, compilar e executar o aplicativo. Você poderá pressionar o botão de cor e alterar a cor da caneta.  
  
 [[Seções](#top)]  
  
##  <a name="initpensave"></a> Inicializando canetas e preferências para salvar  
 Em seguida, inicialize a cor e a largura das canetas. Por fim, salve e carregue uma cor de desenho de um arquivo.  
  
#### <a name="to-initialize-controls-on-the-ribbon-bar"></a>Controles da barra de faixa de opções de inicialização  
  
1.  Inicialize canetas na barra de faixa de opções.  
  
     Adicione o seguinte código ao scribdoc.cpp, no `CScribbleDoc::InitDocument` método, após o `m_sizeDoc = CSize(200,200)` instrução.  
  
 ``` *Redefinir a faixa de opções da interface do usuário para seus valores iniciais CMFCRibbonBar* pRibbon = ((CMDIFrameWndEx*) AfxGetMainWnd()) -> GetRibbonBar(); ASSERT_VALID(pRibbon);

 CMFCRibbonColorButton * pColorBtn = DYNAMIC_DOWNCAST (CMFCRibbonColorButton, pRibbon -> FindByID(ID_PEN_COLOR)); * / / Definir ColorButton para preto  
    pColorBtn -> SetColor (RGB (0, 0, 0)).

 CMFCRibbonComboBox * pThinComboBox = DYNAMIC_DOWNCAST (CMFCRibbonComboBox, pRibbon -> FindByID(ID_PEN_THIN_WIDTH)); * / / Conjunto dinâmico caneta combobox para 2  
    pThinComboBox -> SelectItem(1);

 CMFCRibbonComboBox * pThickComboBox = DYNAMIC_DOWNCAST (CMFCRibbonComboBox, pRibbon -> FindByID(ID_PEN_THICK_WIDTH)); * / / Definir caneta espesso combobox para 5  
    pThickComboBox -> SelectItem(0);

 ```  
  
2.  Save a color drawing to a file. Add the following statement to scribdoc.cpp, in the `CStroke::Serialize` method, after the `ar << (WORD)m_nPenWidth;` statement.  
  
 ```  
    ar << m_penColor (COLORREF);  
 ```  
  
3.  Finally, load a color drawing from a file. Add the following line of code, in the `CStroke::Serialize` method, after the `m_nPenWidth = w;` statement.  
  
 ```  
    ar >> m_penColor;  
 ```  
  
4.  Now scribble in color and save your drawing to a file.  
  
 [[Sections](#top)]  
  
## Conclusion  
 You have updated the MFC Scribble application. Use this walkthrough as a guide when you modify your existing applications.  
  
## See Also  
 [Walkthroughs](../mfc/walkthroughs-mfc.md)   
 [Walkthrough: Updating the MFC Scribble Application (Part 1)](../mfc/walkthrough-updating-the-mfc-scribble-application-part-1.md)

