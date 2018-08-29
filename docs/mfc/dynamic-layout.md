---
title: Layout dinâmico | Microsoft Docs
ms.custom: ''
ms.date: 06/25/2018
ms.technology:
- cpp-mfc
ms.topic: conceptual
dev_langs:
- C++
ms.assetid: 8598cfb2-c8d4-4f5a-bf2b-59dc4653e042
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: a6976669127dca79be59b85efbd15273b0f580a1
ms.sourcegitcommit: f7703076b850c717c33d72fb0755fbb2215c5ddc
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/28/2018
ms.locfileid: "43132056"
---
# <a name="dynamic-layout"></a>Layout dinâmico

Com o MFC no Visual Studio 2015, você pode criar caixas de diálogo que o usuário pode redimensionar, e você pode controlar a maneira que o layout será ajustado para a alteração no tamanho. Por exemplo, você pode anexar botões na parte inferior de uma caixa de diálogo para a borda inferior para que eles fiquem sempre na parte inferior. Você também pode definir alguns controles como caixas de listagem, editboxes e campos de texto para expandir conforme o usuário expande a caixa de diálogo.

## <a name="specifying-dynamic-layout-settings-for-an-mfc-dialog-box"></a>Especificando configurações de layout dinâmico para uma caixa de diálogo do MFC

Quando o usuário redimensiona uma caixa de diálogo, os controles na caixa de diálogo podem redimensionar ou mover nas direções X e Y. A alteração no tamanho ou posição de um controle quando o usuário redimensiona uma caixa de diálogo é chamada de layout dinâmico. Por exemplo, o seguinte é uma caixa de diálogo antes que está sendo redimensionada:

![Caixa de diálogo antes que está sendo redimensionada. ](../mfc/media/mfcdynamiclayout4.png "mfcdynamiclayout4")

Depois que está sendo redimensionada, a área da caixa de listagem é aumentada para mostrar mais itens, e os botões são movidos juntamente com o canto inferior direito:

![Caixa de diálogo depois que está sendo redimensionada. ](../mfc/media/mfcdynamiclayout5.png "mfcdynamiclayout5")

Você pode controlar o layout dinâmico, especificando os detalhes de cada controle no Editor de recursos no IDE ou você pode fazer então programaticamente acessando o `CMFCDynamicLayout` do objeto para um determinado controle e definir as propriedades.

### <a name="setting-dynamic-layout-properties-in-the-resource-editor"></a>Definindo propriedades de layout dinâmico no editor de recursos

Você pode definir o comportamento de layout dinâmico para uma caixa de diálogo sem precisar escrever nenhum código, usando o editor de recursos.

#### <a name="to-set-dynamic-layout-properties-in-the-resource-editor"></a>Para definir propriedades de layout dinâmico no editor de recursos

1. Com um projeto MFC aberto, abra a caixa de diálogo que você deseja trabalhar no editor de caixa de diálogo.

     ![Abra a caixa de diálogo no editor de recursos. ](../mfc/media/mfcdynamiclayout3.png "mfcdynamiclayout3")

2. Selecione um controle e na janela Propriedades, defina as propriedades de layout dinâmico. O **Layout dinâmico** seção na janela de propriedades contém as propriedades **tipo de movimentação**, **tipo de dimensionamento**e, dependendo dos valores selecionados para essas propriedades, propriedades específicas que definem quanto controles mover ou alterar o tamanho. **Mover tipo** determina como um controle é movido conforme o tamanho da caixa de diálogo é alterado; **Tipo de dimensionamento** determina como um controle é redimensionado conforme o tamanho da caixa de diálogo é alterado. **Tipo móvel** e **tipo de dimensionamento** pode ser **Horizontal**, **Vertical**, **ambos**, ou **None**dependendo das dimensões que você deseja alterar dinamicamente. O dimensionamento horizontal é dimensão X. Vertical é a direção de Y.

3. Se você quiser um controle como um botão para estar em um tamanho fixo e permanecer em vigor na parte inferior direita, como é comum para o **Okey** ou **Cancelar** conjunto de botões, o **tipo de dimensionamento** para  **None**e defina o **tipo de movimentação** para **ambos**. Para o **X movendo** e **movendo Y** valores sob **mover tipo**, conjunto de 100% para fazer com que o controle para se manter uma distância fixa da parte inferior direito canto.

     ![Layout dinâmico](../mfc/media/mfcdynamiclayout1.png "mfcdynamiclayout1")

4. Suponha que você também tem um controle que você deseja expandir à medida que expande a caixa de diálogo. Normalmente, um usuário pode expandir uma caixa de diálogo para expandir uma caixa de edição de várias linhas para aumentar o tamanho da área de texto, ou elas podem expandir um controle de lista para ver mais dados. Nesse caso, defina a **tipo de dimensionamento** como "ambas" e defina o **mover tipo** como none. Em seguida, defina as **X dimensionamento** e **dimensionamento Y** valores como 100.

     ![Configurações de Layout dinâmico](../mfc/media/mfcdynamiclayout2.png "mfcdynamiclayout2")

5. Experimente com outros valores que talvez faça sentido para seus controles. Uma caixa de diálogo com uma caixa de texto uma linha pode ter o **tipo de dimensionamento** definido como **Horizontal** apenas, por exemplo.

### <a name="setting-dynamic-layout-properties-programmatically"></a>Definir as propriedades de layout dinâmico programaticamente

O procedimento anterior é útil para especificar propriedades de layout dinâmico para uma caixa de diálogo em tempo de design, mas se você quiser controlar o layout dinâmico em tempo de execução, você pode definir propriedades de layout dinâmico por meio de programação.

#### <a name="to-set-dynamic-layout-properties-programmatically"></a>Para definir propriedades de layout dinâmico por meio de programação

1. Localizar ou criar um local no código de implementação da sua classe de caixa de diálogo onde você deseja especificar o layout dinâmico para a caixa de diálogo. Por exemplo, você talvez queira adicionar um método, como `AdjustLayout` em sua caixa de diálogo e chame-o de locais onde o layout precisa ser alterado. Você pode chamar isso pela primeira vez ou depois de fazer alterações na caixa de diálogo do construtor.

2. Para a caixa de diálogo, chame [GetDynamicLayout](../mfc/reference/cwnd-class.md#getdynamiclayout), um método da `CWnd` classe. `GetDynamicLayout` Retorna um ponteiro para um `CMFCDynamicLayout` objeto.

    ```cpp
    CMFCDynamicLayout* dynamicLayout = pDialog->GetDynamicLayout();
    ```

3. Para o primeiro controle ao qual você deseja adicionar comportamento dinâmico, use os métodos estáticos na classe de layout dinâmico para criar o [MoveSettings](../mfc/reference/cmfcdynamiclayout-class.md#movesettings_structure) estrutura que codifica a maneira como o controle deve ser ajustado. Você pode fazer isso selecionando primeiro o método estático apropriado: [CMFCDynamicLayout::MoveHorizontal](../mfc/reference/cmfcdynamiclayout-class.md#movehorizontal), [CMFCDynamicLayout::MoveVertical](../mfc/reference/cmfcdynamiclayout-class.md#movevertical), [CMFCDynamicLayout::MoveNone](../mfc/reference/cmfcdynamiclayout-class.md#movenone), ou [CMFCDynamicLayout::MoveHorizontalAndVertical](../mfc/reference/cmfcdynamiclayout-class.md#movehorizontalandvertical). Você passa uma porcentagem para os aspectos de horizontais e/ou verticais da mudança. Todos esses métodos estáticos retornam um objeto recém-criado MoveSettings que você pode usar para especificar o comportamento de movimentação de um controle.

   Tenha em mente que se movem de 100 significa que exatamente como a caixa de diálogo muda de tamanho, o que faz com que a borda do controle para se manter uma distância fixa da nova borda.

    ```cpp
    MoveSettings moveSettings = CMFCDynamicLayout::MoveHorizontal(100);
    ```

4. Fazer a mesma coisa para o comportamento de tamanho, que usa o [SizeSettings](../mfc/reference/cmfcdynamiclayout-class.md#sizesettings_structure) tipo. Por exemplo, para especificar que um controle não altera tamanho quando a caixa de diálogo é redimensionado, use o seguinte código:

    ```cpp
    SizeSettings sizeSettings = CMFCDynamicLayout::SizeNone();
    ```

5. Adicionar o controle para o Gerenciador de layout dinâmico usando o [CMFCDynamicLayout::AddItem](../mfc/reference/cmfcdynamiclayout-class.md#additem) método. Há duas sobrecargas para as diferentes maneiras de especificar o controle desejado. Uma usa o identificador do controle de janela (HWND), e a outra usa a ID do controle.

    ```cpp
    dynamicLayout->AddItem(hWndControl,
    moveSettings,
    sizeSettings);
    ```

6. Repita para cada controle que precisa ser movida ou redimensionada.

7. Se necessário, poderá usar o [CMFCDynamicLayout::HasItem](../mfc/reference/cmfcdynamiclayout-class.md#hasitem) método para determinar se um controle já está na lista de controles sujeitas a alterações de layout dyamic, ou o [CMFCDynamicLayout::IsEmpty](../mfc/reference/cmfcdynamiclayout-class.md#isempty) método para determinar se há quaisquer controles que estão sujeitos a alterações.

8. Para habilitar o layout da caixa de diálogo, chame o [CWnd::EnableDynamicLayout](../mfc/reference/cwnd-class.md#enabledynamiclayout) método.

    ```cpp
    pDialog->EnableDynamicLayout(TRUE);
    ```

9. Na próxima vez que o usuário o redimensiona a caixa de diálogo, o [CMFCDynamicLayout::Adjust](../mfc/reference/cmfcdynamiclayout-class.md#adjust) método é chamado, que realmente aplica as configurações.

10. Se você quiser desabilitar layout dinâmico, chame [CWnd::EnableDynamicLayout](../mfc/reference/cwnd-class.md#enabledynamiclayout) com **falso** usada para o *bAtivado* parâmetro.

    ```cpp
    pDialog->EnableDynamicLayout(FALSE);
    ```

#### <a name="to-set-the-dynamic-layout-programmatically-from-a-resource-file"></a>Para definir o layout dinâmico por meio de programação de um arquivo de recurso

1. Use o [CMFCDynamicLayout::MoveHorizontalAndVertical](../mfc/reference/cmfcdynamiclayout-class.md#movehorizontalandvertical) método para especificar um nome de recurso no arquivo de script de recurso relevante (arquivo. rc) que especifica as informações de layout dinâmico, como no exemplo a seguir:

    ```cpp
    dynamicLayout->LoadResource("IDD_DIALOG1");
    ```

     O recurso denominado deve fazer referência a uma caixa de diálogo que contém informações de layout na forma de um **AFX_DIALOG_LAYOUT** entrada no arquivo de recurso, como no exemplo a seguir:

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

[Classe CMFCDynamicLayout](../mfc/reference/cmfcdynamiclayout-class.md)  
[Classes de controle](../mfc/control-classes.md)  
[Classes da caixa de diálogo](../mfc/dialog-box-classes.md)  
[Editor de caixa de diálogo](../windows/dialog-editor.md)  
[Layout do diálogo dinâmico para MFC no Visual C++ 2015](https://mariusbancila.ro/blog/2015/07/27/dynamic-dialog-layout-for-mfc-in-visual-c-2015/)
