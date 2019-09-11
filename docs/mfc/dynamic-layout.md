---
title: Layout dinâmico
ms.date: 09/09/2019
ms.assetid: 8598cfb2-c8d4-4f5a-bf2b-59dc4653e042
ms.openlocfilehash: 1b0d035d3c551fd309d515ccb8b22159218c1b0a
ms.sourcegitcommit: 3caf5261b3ea80d9cf14038c116ba981d655cd13
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/11/2019
ms.locfileid: "70907555"
---
# <a name="dynamic-layout"></a>Layout dinâmico

Com o MFC no Visual Studio 2015, você pode criar caixas de diálogo que o usuário pode redimensionar e controlar a maneira como o layout é ajustado para a alteração no tamanho. Por exemplo, você pode anexar botões na parte inferior de uma caixa de diálogo à borda inferior para que fiquem sempre na parte inferior. Você também pode configurar determinados controles, como ListBoxes, EditBoxes e campos de texto para expandir à medida que o usuário expande a caixa de diálogo.

## <a name="specifying-dynamic-layout-settings-for-an-mfc-dialog-box"></a>Especificando configurações de layout dinâmico para uma caixa de diálogo MFC

Quando o usuário redimensiona uma caixa de diálogo, os controles na caixa de diálogo podem redimensionar ou mover nas direções X e Y. A alteração no tamanho ou na posição de um controle quando o usuário redimensiona uma caixa de diálogo é chamada layout dinâmico. Por exemplo, a seguir está uma caixa de diálogo antes de ser redimensionada:

![Caixa de diálogo antes de ser redimensionada.](../mfc/media/mfcdynamiclayout4.png "Caixa de diálogo antes de ser redimensionada.")

Após ser redimensionado, a área da caixa de listagem é aumentada para mostrar mais itens e os botões são movidos junto com o canto inferior direito:

![Depois de ser redimensionado.](../mfc/media/mfcdynamiclayout5.png "Depois de ser redimensionado.")

Você pode controlar o layout dinâmico especificando os detalhes de cada controle no editor de recursos no IDE ou pode fazer isso programaticamente acessando o `CMFCDynamicLayout` objeto para um controle específico e definindo as propriedades.

### <a name="setting-dynamic-layout-properties-in-the-resource-editor"></a>Definindo propriedades de layout dinâmico no editor de recursos

Você pode definir o comportamento de layout dinâmico para uma caixa de diálogo sem precisar escrever nenhum código, usando o editor de recursos.

#### <a name="to-set-dynamic-layout-properties-in-the-resource-editor"></a>Para definir propriedades de layout dinâmico no editor de recursos

1. Com um projeto do MFC aberto, abra a caixa de diálogo com a qual você deseja trabalhar no editor de caixa de diálogo.

   ![Abra a caixa de diálogo no editor de recursos.](../mfc/media/mfcdynamiclayout3.png "Abra a caixa de diálogo no editor de recursos.")

1. Selecione um controle e, na janela **Propriedades** (em **modo de exibição de classe**), defina suas propriedades de layout dinâmico. A seção **layout dinâmico** na janela **Propriedades** contém as propriedades **tipo de movimentação**, **tipo de dimensionamento**e, dependendo dos valores selecionados para essas propriedades, propriedades específicas que definem a quantidade de controles a serem movidos ou alterar o tamanho. O **tipo de movimentação** determina como um controle é movido conforme o tamanho da caixa de diálogo é alterado; **Tipo de dimensionamento** determina como um controle é redimensionado conforme o tamanho da caixa de diálogo é alterado. **A movimentação do tipo** e do tipo de **dimensionamento** pode ser **horizontal**, **vertical**, **ambos**ou **nenhum** , dependendo das dimensões que você deseja alterar dinamicamente. Horizontal é a dimensão X; Vertical é a direção Y.

1. Se você quiser que um controle como um botão esteja em um tamanho fixo e permaneça em vigor no canto inferior direito, como é comum para os botões **OK** ou **Cancelar** , defina o **tipo de dimensionamento** como **nenhum**e defina o **tipo de movimentação** como **ambos**. Para **mover X** e **mover valores Y** em **tipo de movimentação**, defina 100% para fazer com que o controle permaneça uma distância fixa do canto inferior direito.

   ![Layout dinâmico](../mfc/media/mfcdynamiclayout1.png "Layout dinâmico")

1. Suponha que você também tenha um controle que deseja expandir à medida que a caixa de diálogo se expandir. Normalmente, um usuário pode expandir um diálogo para expandir uma caixa de edição de várias linhas para aumentar o tamanho da área de texto ou pode expandir um controle de lista para ver mais dados. Para esse caso, defina o **tipo de dimensionamento** como ambos e defina o **tipo de movimentação** como nenhum. Em seguida, defina o **dimensionamento X** e o **dimensionamento** dos valores Y como 100.

   ![Configurações de layout dinâmico](../mfc/media/mfcdynamiclayout2.png "Configurações de layout dinâmico")

1. Experimente outros valores que possam fazer sentido para seus controles. Uma caixa de diálogo com uma caixa de texto de uma linha pode ter o **tipo de dimensionamento** definido como **horizontal** somente, por exemplo.

### <a name="setting-dynamic-layout-properties-programmatically"></a>Definindo propriedades de layout dinâmico programaticamente

O procedimento anterior é útil para especificar propriedades de layout dinâmico para uma caixa de diálogo em tempo de design, mas se você quiser controlar o layout dinâmico em tempo de execução, poderá definir propriedades de layout dinâmico programaticamente.

#### <a name="to-set-dynamic-layout-properties-programmatically"></a>Para definir propriedades de layout dinâmico programaticamente

1. Localize ou crie um local no código de implementação da sua classe de caixa de diálogo onde você deseja especificar o layout dinâmico para a caixa de diálogo. Por exemplo, talvez você queira adicionar um método como `AdjustLayout` em sua caixa de diálogo e chamá-lo de locais onde o layout precisa ser alterado. Você pode primeiro chamá-lo do construtor ou depois de fazer alterações na caixa de diálogo.

1. Para a caixa de diálogo, chame [GetDynamicLayout](../mfc/reference/cwnd-class.md#getdynamiclayout), um método `CWnd` da classe. `GetDynamicLayout`Retorna um ponteiro para um `CMFCDynamicLayout` objeto.

    ```cpp
    CMFCDynamicLayout* dynamicLayout = pDialog->GetDynamicLayout();
    ```

1. Para o primeiro controle ao qual você deseja adicionar comportamento dinâmico, use os métodos estáticos na classe de layout dinâmico para criar a estrutura [MoveSettings](../mfc/reference/cmfcdynamiclayout-class.md#movesettings_structure) que codifica a maneira como o controle deve ser ajustado. Você faz isso primeiro escolhendo o método estático apropriado: [CMFCDynamicLayout:: MoveHorizontal](../mfc/reference/cmfcdynamiclayout-class.md#movehorizontal), [CMFCDynamicLayout:: MoveVertical](../mfc/reference/cmfcdynamiclayout-class.md#movevertical), [CMFCDynamicLayout:: MoveNone](../mfc/reference/cmfcdynamiclayout-class.md#movenone)ou [CMFCDynamicLayout:: MoveHorizontalAndVertical](../mfc/reference/cmfcdynamiclayout-class.md#movehorizontalandvertical). Você passa uma porcentagem para os aspectos horizontais e/ou verticais da movimentação. Todos esses métodos estáticos retornam um objeto MoveSettings recém-criado que você pode usar para especificar o comportamento de movimentação de um controle.

   Tenha em mente que 100 significa mover exatamente o tamanho da caixa de diálogo, o que faz com que a borda do controle permaneça uma distância fixa da nova borda.

    ```cpp
    MoveSettings moveSettings = CMFCDynamicLayout::MoveHorizontal(100);
    ```

1. Faça a mesma coisa para o comportamento de tamanho, que usa o tipo [SizeSettings](../mfc/reference/cmfcdynamiclayout-class.md#sizesettings_structure) . Por exemplo, para especificar que um controle não altera o tamanho quando a caixa de diálogo é redimensionada, use o seguinte código:

    ```cpp
    SizeSettings sizeSettings = CMFCDynamicLayout::SizeNone();
    ```

1. Adicione o controle ao Gerenciador de layout dinâmico usando o método [CMFCDynamicLayout:: AddItem](../mfc/reference/cmfcdynamiclayout-class.md#additem) . Há duas sobrecargas para diferentes maneiras de especificar o controle desejado. Um usa o identificador de janela do controle (HWND) e o outro usa a ID de controle.

    ```cpp
    dynamicLayout->AddItem(hWndControl,
    moveSettings,
    sizeSettings);
    ```

1. Repita para cada controle que precisa ser movido ou redimensionado.

1. Se necessário, pode usar o método [CMFCDynamicLayout:: HasItem](../mfc/reference/cmfcdynamiclayout-class.md#hasitem) para determinar se um controle já está na lista de controles que estão sujeitos a alterações de layout dinâmico ou o método [CMFCDynamicLayout:: IsEmpty](../mfc/reference/cmfcdynamiclayout-class.md#isempty) para determinar se há algum controle que estão sujeitos a alterações.

1. Para habilitar o layout da caixa de diálogo, chame o método [CWnd:: EnableDynamicLayout](../mfc/reference/cwnd-class.md#enabledynamiclayout) .

    ```cpp
    pDialog->EnableDynamicLayout(TRUE);
    ```

1. Na próxima vez que o usuário redimensionar a caixa de diálogo, o método [CMFCDynamicLayout:: ADJUST](../mfc/reference/cmfcdynamiclayout-class.md#adjust) será chamado, o que realmente aplicará as configurações.

1. Se você quiser desabilitar o layout dinâmico, chame [CWnd:: EnableDynamicLayout](../mfc/reference/cwnd-class.md#enabledynamiclayout) com **false** como para o parâmetro *bEnabled* .

    ```cpp
    pDialog->EnableDynamicLayout(FALSE);
    ```

#### <a name="to-set-the-dynamic-layout-programmatically-from-a-resource-file"></a>Para definir o layout dinâmico programaticamente de um arquivo de recurso

1. Use o método [CMFCDynamicLayout:: MoveHorizontalAndVertical](../mfc/reference/cmfcdynamiclayout-class.md#movehorizontalandvertical) para especificar um nome de recurso no arquivo de script de recurso relevante (arquivo. rc) que especifica informações de layout dinâmico, como no exemplo a seguir:

    ```cpp
    dynamicLayout->LoadResource("IDD_DIALOG1");
    ```

   O recurso nomeado deve fazer referência a uma caixa de diálogo que contém informações de layout na forma de uma entrada **AFX_DIALOG_LAYOUT** no arquivo de recurso, como no exemplo a seguir:

    ```RC
    /////////////////////////////////////////////////////////////////////////////
    //
    // AFX_DIALOG_LAYOUT
    //

    IDD_MFCAPPLICATION1_DIALOG AFX_DIALOG_LAYOUT
    BEGIN
    0x0000,
    0x6400,
    0x0028,
    0x643c,
    0x0028
    END

    IDD_DIALOG1 AFX_DIALOG_LAYOUT
    BEGIN
    0x0000,
    0x6464,
    0x0000,
    0x6464,
    0x0000,
    0x0000,
    0x6464,
    0x0000,
    0x0000

    END
    ```

## <a name="see-also"></a>Consulte também

[Classe CMFCDynamicLayout](../mfc/reference/cmfcdynamiclayout-class.md)<br/>
[Classes de controle](../mfc/control-classes.md)<br/>
[Classes da caixa de diálogo](../mfc/dialog-box-classes.md)<br/>
[Editor de caixa de diálogo](../windows/dialog-editor.md)<br/>
[Layout de caixa de diálogo dinâmico para C++ MFC no Visual 2015](https://mariusbancila.ro/blog/2015/07/27/dynamic-dialog-layout-for-mfc-in-visual-c-2015/)
