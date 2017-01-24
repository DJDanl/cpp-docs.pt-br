---
title: "Instru&#231;&#245;es passo a passo: atualizando o aplicativo de rabisco MFC (parte 2) | Microsoft Docs"
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
  - "explicações passo a passo [C++]"
ms.assetid: 602df5c2-17d4-4cd9-8cf6-dff652c4cae5
caps.latest.revision: 36
caps.handback.revision: 32
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Instru&#231;&#245;es passo a passo: atualizando o aplicativo de rabisco MFC (parte 2)
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

[Parte 1](../mfc/walkthrough-updating-the-mfc-scribble-application-part-1.md) deste passo a passo mostrado como adicionar o Office a Faixa De Opções fluente ao aplicativo clássico de garrancho.  Esta parte mostra como adicionar os painéis e os controles de fita que os usuários podem usar em vez de menus e os comandos.  
  
## Pré-requisitos  
 [Exemplos do Visual C\+\+](../top/visual-cpp-samples.md)  
  
##  <a name="top"></a> Seções  
 Essa parte do passo a passo tem as seguintes seções:  
  
-   [Adicionando novos painéis a Faixa De Opções](#addNewPanel)  
  
-   [Adicionando um painel de ajuda para a Faixa De Opções](#addHelpPanel)  
  
-   [Adicionando um painel de forma a Faixa De Opções](#addPenPanel)  
  
-   [Adicionar um botão de cor para a Faixa De Opções](#addColorButton)  
  
-   [Adicionando um membro da cor à classe do documento](#addColorMember)  
  
-   [Inicializando penalidades e salvar preferências](#initPenSave)  
  
##  <a name="addNewPanel"></a> Adicionando novos painéis a Faixa De Opções  
 Apresentação dessas etapas como adicionar um painel de **Exibir** que contém duas caixas de seleção que controlam a visibilidade da barra de ferramentas e da barra de status, e também um painel de **Janela** que contém um botão dividido verticalmente orientada que controlam a criação e a organização do windows \(MDI\) de interface de documentos.  
  
#### Para adicionar um painel de exibição e o painel da janela para a barra de fita  
  
1.  Cria um painel `Exibição`nomeado, que tem duas caixas de seleção que ativam \/desativar a barra de status e a barra de ferramentas.  
  
    1.  De **Caixa de Ferramentas**, arraste **Painel** a categoria de **Início** .  Em dois **Caixas de Seleção** arraste para o painel.  
  
    2.  Clique no painel para modificar suas propriedades.  Alteração **Legenda** a `Exibição`.  
  
    3.  Clique na primeira caixa de seleção para modificar suas propriedades.  Alterar **ID** a `ID_VIEW_TOOLBAR` e **Legenda** a `Barra de ferramentas`.  
  
    4.  Clique na segunda caixa de seleção para modificar suas propriedades.  Alterar **ID** a `ID_VIEW_STATUS_BAR` e **Legenda** a `Barra de status`.  
  
2.  Crie um denominado o painel `Janela` que tenha um botão de divisão.  Quando um usuário clica no botão de divisão, um menu de atalho três comandos que já estejam definidos no aplicativo de garrancho.  
  
    1.  De **Caixa de Ferramentas**, arraste **Painel** a categoria de **Início** .  Arraste **Botão** para o painel.  
  
    2.  Clique no painel para modificar suas propriedades.  Alteração **Legenda** a `Janela`.  
  
    3.  Clique no botão.  Alterar **Legenda** a `O windows`, **Chaves** a `w`, **Índice da Imagem Grande** a `1`, e **Modo de Divisão** a `False`.  Clique nas reticências \(**...**\) ao lado de **Itens de menu** para abrir a caixa de diálogo de **Editor de Itens** .  
  
    4.  Clique **Adicionar** três vezes para adicionar três botões.  
  
    5.  Clique no primeiro botão e altere **Legenda** a `Nova janela`, e **ID** a `ID_WINDOW_NEW`.  
  
    6.  Clique no segundo botão e altere **Legenda** a `Cascata`, e **ID** a `ID_WINDOW_CASCADE`.  
  
    7.  Clique no terceiro botão e altere **Legenda** a `Peça`, e **ID** a `ID_WINDOW_TILE_HORZ`.  
  
3.  Salvar as alterações, e depois criar e executar o aplicativo.  Os painéis de **Exibir** e de **Janela** devem ser exibidos.  Clique nos botões para confirmar que funcionem corretamente.  
  
 \[[Seções](#top)\]  
  
##  <a name="addHelpPanel"></a> Adicionando um painel de ajuda para a Faixa De Opções  
 Agora, você pode atribuir dois itens de menu que são definidos no aplicativo de garrancho aos botões de fita que são nomeados **Tópicos de Ajuda** e **Sobre o garrancho**.  Os botões são adicionados a um novo painel **Ajuda**nomeada.  
  
#### Para adicionar um painel de ajuda  
  
1.  De **Caixa de Ferramentas**, arraste **Painel** a categoria de **Início** .  Em dois **Botões** arraste para o painel.  
  
2.  Clique no painel para modificar suas propriedades.  Alteração **Legenda** a `Ajuda`.  
  
3.  Clique no primeiro botão.  Alteração **Legenda** a `Tópicos da Ajuda`, e **ID** a `ID_HELP_FINDER`.  
  
4.  Clique no segundo botão.  Alteração **Legenda** a `Sobre o garrancho…`, e **ID** a `ID_APP_ABOUT`.  
  
5.  Salvar as alterações, e depois criar e executar o aplicativo.  Um painel de **Ajuda** que contém dois botões de fita deve ser exibido.  
  
    > [!IMPORTANT]
    >  Quando você clica no botão de **Tópicos de Ajuda** , o aplicativo de garrancho abre uma ajuda compactado *your\_project\_name*nomeado arquivo .chm HTML \(.chm\).  Em virtude disso, se o projeto não é nomeada garrancho, você deve renomear o arquivo de ajuda no nome do projeto.  
  
 \[[Seções](#top)\]  
  
##  <a name="addPenPanel"></a> Adicionando um painel de forma a Faixa De Opções  
 Agora, adicione um painel com os botões de exibição que controlam a espessura e a cor de forma.  Este painel contém uma caixa de seleção que ative \/desativar penalidades entre grossas e finas.  Se assemelha à sua funcionalidade do item de menu de **Linha espessa** no aplicativo de garrancho.  
  
 O aplicativo original de garrancho permite que as larguras de seleção da caneta de usuário de uma caixa de diálogo que aparece quando o usuário clica em **Larguras de forma** no menu.  Como a barra de fita tem a ampla espaço para novos controles, você pode substituir a caixa de diálogo usando duas caixas de combinação na faixa de opções.  Uma caixa de combinação ajuste a largura da forma final e a outra caixa de combinação ajuste a largura da caneta espessa.  
  
#### Para adicionar uma caneta almofade e caixas de combinação em fita  
  
1.  De **Caixa de Ferramentas**, arraste **Painel** a categoria de **Início** .  Arraste **Caixa de Seleção** e dois **Caixas de Combinação** para o painel.  
  
2.  Clique no painel para modificar suas propriedades.  Alteração **Legenda** a `Caneta`.  
  
3.  Clique na caixa de seleção.  Alteração **Legenda** a `Use densamente`, e **ID** a `ID_PEN_THICK_OR_THIN`.  
  
4.  Clique na primeira caixa de combinação.  Alteração **Legenda** a `Caneta fina`, a **ID** a `ID_PEN_THIN_WIDTH`, a **Texto** a `2`, a **Tipo** a `Lista suspensa`, e a **Dados** a `1; 2; 3; 4; 5; 6; 7; 8; 9;`.  
  
5.  Clique na segunda caixa de combinação.  Alteração **Legenda** a `Caneta espessa`, a **ID** a `ID_PEN_THICK_WIDTH`, a **Texto** a `5`, a **Tipo** a `Lista suspensa`, e a **Dados** a `5; 6; 7; 8; 9; 10; 11; 12; 13; 14; 15; 16; 17; 18; 19; 20;`.  
  
6.  As novas caixas de combinação não correspondem aos itens de menu existentes.  Em virtude disso, você deve criar um item de menu para cada opção de forma.  
  
    1.  Na janela de **Modo de Exibição de Recurso** , abra o recurso no menu de IDR\_SCRIBBTYPE.  
  
    2.  Clique em **Caneta** para abrir o menu de**br** p.  Clique **Digite Aqui** e digite `Thi&caneta n`.  
  
    3.  Clique com o botão direito do mouse no texto que você digitou apenas para abrir a janela de **Propriedades** , altere a propriedade da ID `ID_PEN_THIN_WIDTH`.  
  
    4.  Você também deve criar um manipulador de eventos para cada item de menu de forma.  Clique com o botão direito do mouse no item de menu de **Thi&caneta n** que você acabou de criar e clique em **Adicionar Manipulador de Eventos**.  **Assistente do manipulador de eventos** É exibido.  
  
    5.  Na caixa de **Lista de classes** no assistente, **CScribbleDoc** selecione e clique em **Adicionar e editar**.  Isso cria um manipulador de eventos `CScribbleDoc::OnPenThinWidth`nomeada.  
  
    6.  Adicione o código a seguir ao `CScribbleDoc::OnPenThinWidth`.  
  
        ```  
        // Get a pointer to the ribbon bar  
        CMFCRibbonBar* pRibbon = ((CMDIFrameWndEx*) AfxGetMainWnd())->GetRibbonBar();  
        ASSERT_VALID(pRibbon);  
        // Get a pointer to the Thin Width combo box  
        CMFCRibbonComboBox* pThinComboBox = DYNAMIC_DOWNCAST(  
           CMFCRibbonComboBox, pRibbon->FindByID(ID_PEN_THIN_WIDTH));  
        //Get the selected value  
        int nCurSel = pThinComboBox->GetCurSel();  
        if (nCurSel >= 0)  
        {  
           m_nThinWidth = atoi(pThinComboBox->GetItem(nCurSel));  
        }  
        // Create a new pen using the selected width  
        ReplacePen();    
        ```  
  
7.  Em seguida, crie um item de menu e manipuladores de eventos para a caneta espessa.  
  
    1.  Na janela de **Modo de Exibição de Recurso** , abra o recurso no menu de IDR\_SCRIBBTYPE.  
  
    2.  Clique em **Caneta** para abrir o menu da forma.  Clique **Digite Aqui** e digite `Thic&caneta de k`.  
  
    3.  Clique com o botão direito do mouse no texto que você digitou apenas para exibir a janela de **Propriedades** .  Altere a propriedade da ID `ID_PEN_THICK_WIDTH`.  
  
    4.  Clique com o botão direito do mouse no item de menu de **Caneta espessa** que você acabou de criar e clique em **Adicionar Manipulador de Eventos**.  **Assistente do manipulador de eventos** É exibido.  
  
    5.  Na caixa de **Lista de classes** do assistente, **CScribbleDoc** selecione e clique em **Adicionar e editar**.  Isso cria um manipulador de eventos `CScribbleDoc::OnPenThickWidth`nomeada.  
  
    6.  Adicione o código a seguir ao `CScribbleDoc::OnPenThickWidth`.  
  
        ```  
        // Get a pointer to the ribbon bar  
        CMFCRibbonBar* pRibbon = ((CMDIFrameWndEx *) AfxGetMainWnd())->GetRibbonBar();  
        ASSERT_VALID(pRibbon);  
        CMFCRibbonComboBox* pThickComboBox = DYNAMIC_DOWNCAST(  
           CMFCRibbonComboBox, pRibbon->FindByID(ID_PEN_THICK_WIDTH));  
        // Get the selected value  
        int nCurSel = pThickComboBox->GetCurSel();  
        if (nCurSel >= 0)  
        {  
           m_nThickWidth = atoi(pThickComboBox->GetItem(nCurSel));  
        }  
        // Create a new pen using the selected width  
        ReplacePen();  
        ```  
  
8.  Salvar as alterações, e depois criar e executar o aplicativo.  Os novos botões e as caixas de combinação devem ser exibidos.  Tente usar larguras diferentes de forma para rabiscar.  
  
 \[[Seções](#top)\]  
  
##  <a name="addColorButton"></a> Adicionar um botão de cor para o painel de forma  
 Em seguida, adiciona um objeto de [CMFCRibbonColorButton](../mfc/reference/cmfcribboncolorbutton-class.md) que permite que o usuário rabiscar na cor.  
  
#### Para adicionar um botão de cor para o painel de forma  
  
1.  Antes de adicionar o botão de cor, crie um item de menu para ele.  Na janela de **Modo de Exibição de Recurso** , abra o recurso no menu de IDR\_SCRIBBTYPE.  Clique no item de menu de **Caneta** para abrir o menu da forma.  Clique **Digite Aqui** e digite `&Color`.  Clique com o botão direito do mouse no texto que você digitou apenas para exibir a janela de **Propriedades** .  Alterar a id a `ID_PEN_COLOR`.  
  
2.  Agora adicione o botão de cor.  **Caixa de Ferramentas**De **Botão de Cores** , arraste para o painel de **Caneta** .  
  
3.  Clique no botão de cor.  Alterar **Legenda** a `Cor`, **ID** a `ID_PEN_COLOR`, **SimplesProcure** a `Retifique`, **Índice da Imagem Grande** a `1`, e **Modo de Divisão** a `False`.  
  
4.  Salvar as alterações, e depois criar e executar o aplicativo.  O novo botão de cor deve ser exibido no painel de **Caneta** .  Porém, não pode ser usado porque ainda não tiver um manipulador de eventos.  As etapas a seguir mostram como adicionar um manipulador de eventos para o botão de cor.  
  
 \[[Seções](#top)\]  
  
##  <a name="addColorMember"></a> Adicionando um membro da cor à classe do documento  
 Como o aplicativo original de garrancho não tem penalidades de cor, você deve escrever uma implementação para eles.  Para armazenar a cor da caneta do documento, adicionar um novo membro à classe do documento, `CscribbleDoc.`  
  
#### Para adicionar um membro de cor para o documento classe  
  
1.  Em scribdoc.h, na classe de `CScribbleDoc` , localize a seção de `// Attributes` .  Adicione as seguintes linhas de código após a definição do membro de dados de `m_nThickWidth` .  
  
    ```  
    // Current pen color  
    COLORREF   m_penColor;  
    ```  
  
2.  Cada documento contém uma lista de aviva que o usuário tem desenhado nele.  Cada curso é definido por um objeto de `CStroke` .  A classe de `CStroke` não inclui informações sobre a cor de forma.  Em virtude disso, você deve alterar a classe.  Em scribdoc.h, na classe de `CStroke` , adicione as seguintes linhas de código após a definição do membro de dados de `m_nPenWidth` .  
  
    ```  
    // Pen color for the stroke  
    COLORREF   m_penColor;  
    ```  
  
3.  Em scribdoc.h, adicione um novo construtor de `CStroke` parâmetros cujos especificam uma largura e a cor.  Adicione a seguinte linha de código depois da instrução de `CStroke(UINT nPenWidth);` .  
  
    ```  
    CStroke(UINT nPenWidth, COLORREF penColor);  
    ```  
  
4.  Em scribdoc.cpp, adicione a nova implementação do construtor de `CStroke` .  Adicione o seguinte código após a implementação do construtor de `CStroke::CStroke(UINT nPenWidth)` .  
  
    ```  
    // Constructor that uses the document's current width and color  
    CStroke::CStroke(UINT nPenWidth, COLORREF penColor)  
    {  
       m_nPenWidth = nPenWidth;  
       m_penColor = penColor;  
       m_rectBounding.SetRectEmpty();  
    }  
    ```  
  
5.  Alterar a segunda linha do método de `CStroke::DrawStroke` seguinte maneira.  
  
    ```  
    if (!penStroke.CreatePen(PS_SOLID, m_nPenWidth, m_penColor))  
    ```  
  
6.  Definir a cor padrão da caneta da classe do documento.  Em scribdoc.cpp, adicione as seguintes linhas a `CScribbleDoc::InitDocument`, depois da instrução de `m_nThickWidth = 5;` .  
  
    ```  
    // default pen color is black  
    m_penColor = RGB(0,0,0);   
    ```  
  
7.  Em scribdoc.cpp, altere a primeira linha do método de `CScribbleDoc::NewStroke` a seguir.  
  
    ```  
    CStroke* pStrokeItem = new CStroke(m_nPenWidth, m_penColor);  
    ```  
  
8.  Alterar a última linha do método de `CScribbleDoc::ReplacePen` a seguir.  
  
    ```  
    m_penCur.CreatePen(PS_SOLID, m_nPenWidth, m_penColor);  
    ```  
  
9. Você adicionou o membro de `m_penColor` em uma etapa anterior.  Agora, crie um manipulador de eventos para o botão de cor que define o membro.  
  
    1.  Na janela de **Modo de Exibição de Recurso** , abra o recurso no menu de IDR\_SCRIBBTYPE.  
  
    2.  Clique com o botão direito do mouse no item de menu de **Cor** e clique **Adicionar o manipulador de eventos…**.  **Assistente do manipulador de eventos** É exibida.  
  
    3.  Na caixa de **Lista de classes** no assistente, **CScribbleDoc** selecione e clique no botão de **Adicionar e editar** .  Isso cria o stub do manipulador de eventos `CScribbleDoc::OnPenColor` .  
  
10. Substitua o stub para o manipulador de eventos de `CScribbleDoc::OnPenColor` com o código a seguir.  
  
    ```  
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
  
11. Salvar as alterações e depois criar e executar o aplicativo.  Você deve ser capaz pressionar o botão de cor e alterar a cor da forma.  
  
 \[[Seções](#top)\]  
  
##  <a name="initPenSave"></a> Inicializando penalidades e salvar preferências  
 Em seguida, inicializa a cor e a largura das penalidades.  Finalmente, salve e carrega um desenho da cor de um arquivo.  
  
#### Para inicializar controles na barra de fita  
  
1.  Inicializar as penalidades na barra de fita.  
  
     Adicione o código a scribdoc.cpp, no método de `CScribbleDoc::InitDocument` , depois da instrução de `m_sizeDoc = CSize(200,200)` .  
  
    ```  
    // Reset the ribbon UI to its initial values  
    CMFCRibbonBar* pRibbon =   
       ((CMDIFrameWndEx*) AfxGetMainWnd())->GetRibbonBar();  
    ASSERT_VALID(pRibbon);  
    CMFCRibbonColorButton* pColorBtn = DYNAMIC_DOWNCAST(  
       CMFCRibbonColorButton,   
       pRibbon->FindByID(ID_PEN_COLOR));  
    // Set ColorButton to black  
    pColorBtn->SetColor(RGB(0,0,0));    
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
  
2.  Salvar uma cor que o desenha a um arquivo.  Adicione a seguinte instrução a scribdoc.cpp, no método de `CStroke::Serialize` , depois da instrução de `ar << (WORD)m_nPenWidth;` .  
  
    ```  
    ar << (COLORREF)m_penColor;  
    ```  
  
3.  Finalmente, carregue um desenho da cor de um arquivo.  Adicione a seguinte linha de código, no método de `CStroke::Serialize` , depois da instrução de `m_nPenWidth = w;` .  
  
    ```  
    ar >> m_penColor;  
    ```  
  
4.  Agora rabiscar na cor e salvar o desenho a um arquivo.  
  
 \[[Seções](#top)\]  
  
## Conclusão  
 Atualizar o aplicativo de garrancho MFC.  Use este passo a passo como a guia quando você altera seus aplicativos existentes.  
  
## Consulte também  
 [Explicações Passo\-a\-passo](../mfc/walkthroughs-mfc.md)   
 [Instruções passo a passo: atualizando o aplicativo de rabisco MFC \(parte 1\)](../mfc/walkthrough-updating-the-mfc-scribble-application-part-1.md)