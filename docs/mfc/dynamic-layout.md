---
title: "Layout dinâmico | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
dev_langs:
- C++
ms.assetid: 8598cfb2-c8d4-4f5a-bf2b-59dc4653e042
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: e309d8ef023346c0e37babeabe23f7e6e1762939
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="dynamic-layout"></a>Layout dinâmico
Com MFC no Visual Studio 2015, você pode criar caixas de diálogo que o usuário pode redimensionar e você pode controlar a forma que ajusta o layout para a alteração no tamanho. Por exemplo, você pode anexar botões na parte inferior de uma caixa de diálogo para a borda inferior para que eles permanecem sempre na parte inferior. Você também pode configurar determinados controles, como caixas de listagem, editboxes e campos de texto para expandir conforme o usuário expande a caixa de diálogo.  
  
## <a name="specifying-dynamic-layout-settings-for-an-mfc-dialog-box"></a>Especificando as configurações de layout dinâmico para uma caixa de diálogo MFC  
 Quando o usuário o redimensiona uma caixa de diálogo, os controles na caixa de diálogo podem redimensionar ou mover nas direções X e Y. A alteração no tamanho ou posição de um controle quando o usuário o redimensiona uma caixa de diálogo é chamada de layout dinâmico. Por exemplo, o seguinte é uma caixa de diálogo antes que está sendo redimensionada:  
  
 ![Caixa de diálogo antes que está sendo redimensionada. ] (../mfc/media/mfcdynamiclayout4.png "mfcdynamiclayout4")  
  
 Depois que está sendo redimensionada, a área da caixa de listagem é aumentada para mostrar mais itens e os botões são movidos juntamente com o canto inferior direito:  
  
 ![Caixa de diálogo depois que está sendo redimensionada. ] (../mfc/media/mfcdynamiclayout5.png "mfcdynamiclayout5")  
  
 Você pode controlar o layout dinâmico, especificando os detalhes para cada controle no Editor de recursos no IDE, ou você pode fazer para programaticamente ao acessar o objeto CMFCDynamicLayout para um determinado controle e definindo as propriedades.  
  
### <a name="setting-dynamic-layout-properties-in-the-resource-editor"></a>Definindo propriedades de layout dinâmico no editor de recursos  
 Você pode definir o comportamento de layout dinâmico para uma caixa de diálogo sem precisar gravar qualquer código, usando o editor de recurso.  
  
##### <a name="to-set-dynamic-layout-properties-in-the-resource-editor"></a>Para definir propriedades de layout dinâmico no editor de recursos  
  
1.  Com um projeto MFC aberto, abra a caixa de diálogo que você deseja trabalhar no editor de caixa de diálogo.  
  
     ![Abra a caixa de diálogo no editor de recursos. ] (../mfc/media/mfcdynamiclayout3.png "mfcdynamiclayout3")  
  
2.  Selecione um controle e na janela Propriedades, defina suas propriedades de layout dinâmico. O **Layout dinâmico** seção na janela de propriedades contém as propriedades **movendo tipo**, **dimensionamento tipo**e, dependendo dos valores selecionados para essas propriedades, propriedades específicas que definem como os controles mover ou alterar o tamanho. **Tipo de movimentação** determina como um controle é movido conforme o tamanho da caixa de diálogo é alterado; **Dimensionamento tipo** determina como um controle é redimensionado conforme o tamanho da caixa de diálogo é alterado. **Mover o tipo** e **dimensionamento tipo** podem ser **Horizontal**, **Vertical**, **ambos**, ou **nenhum** dependendo das dimensões que você deseja alterar dinamicamente. Horizontal é a dimensão de X; Vertical é a direção de Y.  
  
3.  Se você desejar um controle como um botão em um tamanho fixo e permanecem em vigor na parte inferior direita, como é comum para o **Okey** ou **Cancelar** botões, defina o **dimensionamento tipo** para  **Nenhum**e defina o **movendo tipo** para **ambos**. Para o **X movendo** e **Y movendo** valores em **movendo tipo**, conjunto de 100% para fazer com que o controle manter uma distância fixa da parte inferior canto direito.  
  
     ![Layout dinâmico](../mfc/media/mfcdynamiclayout1.png "mfcdynamiclayout1")  
  
4.  Suponha que você também tem um controle que você deseja expandir à medida que se expande a caixa de diálogo. Normalmente, um usuário pode expandir uma caixa de diálogo para expandir um editbox várias linhas para aumentar o tamanho da área de texto, ou pode expandir um controle de lista para ver mais dados. Nesse caso, defina o **dimensionamento tipo** para ambos e defina o **tipo movendo** como none. Em seguida, defina o **dimensionamento X** e **dimensionamento Y** valores como 100.  
  
     ![Configurações de Layout dinâmico](../mfc/media/mfcdynamiclayout2.png "mfcdynamiclayout2")  
  
5.  Fazer experiências com outros valores que talvez faça sentido para seus controles. Uma caixa de diálogo com uma caixa de texto de uma linha pode ter o **dimensionamento tipo** definida como **Horizontal** apenas, por exemplo.  
  
### <a name="setting-dynamic-layout-properties-programmatically"></a>Definindo propriedades de layout dinâmico por meio de programação  
 O procedimento anterior é útil para especificar as propriedades de layout dinâmico para uma caixa de diálogo em tempo de design, mas se você quiser controlar o layout dinâmico no tempo de execução, você pode definir propriedades de layout dinâmico por meio de programação.  
  
##### <a name="to-set-dynamic-layout-properties-programmatically"></a>Para definir as propriedades de layout dinâmico por meio de programação  
  
1.  Localizar ou criar um local no código de implementação da sua classe de caixa de diálogo onde você deseja especificar o layout dinâmico para a caixa de diálogo. Por exemplo, você talvez queira adicionar um método como `AdjustLayout` em sua caixa de diálogo e a chamada de locais onde o layout precisa ser alterado. Você pode chamar essa primeiro a partir do construtor, ou depois de fazer alterações na caixa de diálogo.  
  
2.  Para a caixa de diálogo, chame [GetDynamicLayout](../mfc/reference/cwnd-class.md#getdynamiclayout), um método da classe CWnd. GetDynamicLayout retorna um ponteiro para um objeto CMFCDynamicLayout.  
  
 ```  
    CMFCDynamicLayout* dynamicLayout = pDialog->GetDynamicLayout();

 ```  
  
3.  Para o primeiro controle para o qual você deseja adicionar o comportamento dinâmico, use os métodos estáticos da classe de layout dinâmico para criar o [MoveSettings](../mfc/reference/cmfcdynamiclayout-class.md#movesettings_structure) estrutura que codifica a maneira como o controle deve ser ajustado. Para fazer isso, primeiro escolha o método estático apropriado: [CMFCDynamicLayout::MoveHorizontal](../mfc/reference/cmfcdynamiclayout-class.md#movehorizontal), [CMFCDynamicLayout::MoveVertical](../mfc/reference/cmfcdynamiclayout-class.md#movevertical), [CMFCDynamicLayout::MoveNone](../mfc/reference/cmfcdynamiclayout-class.md#movenone), ou [CMFCDynamicLayout::MoveHorizontalAndVertical](../mfc/reference/cmfcdynamiclayout-class.md#movehorizontalandvertical). Você passar uma porcentagem para os aspectos verticais e/ou horizontais do movimento. Todos esses métodos estáticos retornam um objeto recém-criado do MoveSettings que você pode usar para especificar o comportamento de movimentação do controle.  
  
     Tenha em mente que se movem de 100 significa exatamente o que a caixa de diálogo altera o tamanho, o que faz com que a borda do controle manter uma distância fixa da nova borda.  
  
 ```  
    MoveSettings moveSettings = CMFCDynamicLayout::MoveHorizontal(100);

 ```  
  
4.  Faça o mesmo para o comportamento de tamanho, que usa o [SizeSettings](../mfc/reference/cmfcdynamiclayout-class.md#sizesettings_structure) tipo. Por exemplo, para especificar que um controle não alterar tamanho quando a caixa de diálogo for redimensionado, use o código a seguir:  
  
 ```  
    SizeSettings sizeSettings = CMFCDynamicLayout::SizeNone();

 ```  
  
5.  Adicione o controle para o Gerenciador de layout dinâmico usando o [CMFCDynamicLayout::AddItem](../mfc/reference/cmfcdynamiclayout-class.md#additem) método. Há duas sobrecargas de diferentes maneiras de especificar o controle desejado. Entra em um identificador de janela do controle (HWND) e o outro usa o ID de controle.  
  
 ```  
    dynamicLayout->AddItem(hWndControl,
    moveSettings,
    sizeSettings);

 ```  
  
6.  Repita para cada controle que precisa ser movido ou redimensionado.  
  
7.  Se necessário, pode usar o [CMFCDynamicLayout::HasItem](../mfc/reference/cmfcdynamiclayout-class.md#hasitem) método para determinar se um controle já está na lista de controles sujeitadas a alterações de layout dyamic, ou o [CMFCDynamicLayout::IsEmpty](../mfc/reference/cmfcdynamiclayout-class.md#isempty) método para determinar se há quaisquer controles que estão sujeitos a alterações.  
  
8.  Para habilitar o layout da caixa de diálogo, chame o [CWnd::EnableDynamicLayout](../mfc/reference/cwnd-class.md#enabledynamiclayout) método.  
  
 ```  
    pDialog->EnableDynamicLayout(TRUE);

 ```  
  
9. Na próxima vez que o usuário o redimensiona a caixa de diálogo, o [CMFCDynamicLayout::Adjust](../mfc/reference/cmfcdynamiclayout-class.md#adjust) método é chamado que realmente aplica as configurações.  
  
10. Se você quiser desabilitar layout dinâmico, chame [CWnd::EnableDynamicLayout](../mfc/reference/cwnd-class.md#enabledynamiclayout) com `FALSE` para o `bEnabled` parâmetro.  
  
 ```  
    pDialog->EnableDynamicLayout(FALSE);

 ```  
  
##### <a name="to-set-the-dynamic-layout-programmatically-from-a-resource-file"></a>Para definir o layout dinâmico por meio de programação de um arquivo de recurso  
  
1.  Use o [CMFCDynamicLayout::MoveHorizontalAndVertical](../mfc/reference/cmfcdynamiclayout-class.md#movehorizontalandvertical) método para especificar um nome de recurso no arquivo de script de recursos relevantes (arquivo. rc) que especifica informações de layout dinâmico, como no exemplo a seguir:  
  
 ```  
    dynamicLayout->LoadResource("IDD_DIALOG1");

 ```  
  
     O recurso denominado deve fazer referência a uma caixa de diálogo que contém informações de layout na forma de uma entrada AFX_DIALOG_LAYOUT no arquivo de recurso, como no exemplo a seguir:  
  
 ' ' * / / / * / / * / / AFX_DIALOG_LAYOUT * / /  
 
    IDD_MFCAPPLICATION1_DIALOG AFX_DIALOG_LAYOUT  
    COMEÇAR 0X0000, 0X6400, 0X0028, 0X643C, 0X0028  
    END 
 
    IDD_DIALOG1 AFX_DIALOG_LAYOUT  
    COMEÇAR 0X0000, 0X6464, 0X0000, 0X6464, 0X0000, 0X0000, 0X6464, 0X0000, 0X0000  
 
    END 
 ```  
  
## See Also  
 [CMFCDynamicLayout Class](../mfc/reference/cmfcdynamiclayout-class.md)   
 [Control Classes](../mfc/control-classes.md)   
 [Dialog Box Classes](../mfc/dialog-box-classes.md)   
 [Dialog Editor](../windows/dialog-editor.md)

