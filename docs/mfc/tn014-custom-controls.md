---
title: 'TN014: Controles personalizados'
ms.date: 06/28/2018
f1_keywords:
- vc.controls
helpviewer_keywords:
- TN014
- custom controls [MFC]
ms.assetid: 1917a498-f643-457c-b570-9a0af7dbf7bb
ms.openlocfilehash: 2960c5b8585519adb535e5611315ec4ececcf53e
ms.sourcegitcommit: fcb48824f9ca24b1f8bd37d647a4d592de1cc925
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/15/2019
ms.locfileid: "69511188"
---
# <a name="tn014-custom-controls"></a>TN014: Controles personalizados

Esta observação descreve o suporte do MFC para controles personalizados e de autodesenho. Ele também descreve a subclasse dinâmica e descreve a relação entre objetos [CWnd](../mfc/reference/cwnd-class.md) e `HWND`s.

O aplicativo de exemplo MFC CTRLTEST ilustra como usar muitos controles personalizados. Consulte o código-fonte do exemplo de [CTRLTEST](../overview/visual-cpp-samples.md) geral e a ajuda online do MFC.

## <a name="owner-draw-controlsmenus"></a>Controles/menus de desenho proprietário

O Windows oferece suporte para controles e menus de desenho proprietário usando mensagens do Windows. A janela pai de qualquer controle ou menu recebe essas mensagens e chama funções em resposta. Você pode substituir essas funções para personalizar a aparência visual e o comportamento de seu menu ou controle de desenho proprietário.

O MFC dá suporte diretamente ao desenho de proprietário com as seguintes funções:

- [CWnd::OnDrawItem](../mfc/reference/cwnd-class.md#ondrawitem)

- [CWnd::OnMeasureItem](../mfc/reference/cwnd-class.md#onmeasureitem)

- [CWnd::OnCompareItem](../mfc/reference/cwnd-class.md#oncompareitem)

- [CWnd::OnDeleteItem](../mfc/reference/cwnd-class.md#ondeleteitem)

Você pode substituir essas funções em sua `CWnd` classe derivada para implementar o comportamento de desenho personalizado.

Essa abordagem não leva a um código reutilizável. Se você tiver dois controles semelhantes em duas classes `CWnd` diferentes, deverá implementar o comportamento de controle personalizado em dois locais. A arquitetura de controle de autodesenho com suporte do MFC resolve esse problema.

## <a name="self-draw-controls-and-menus"></a>Menus e controles de desenho automático

O MFC fornece uma implementação padrão (nas `CWnd` classes e [CMenu](../mfc/reference/cmenu-class.md) ) para as mensagens padrão de desenho proprietário. Essa implementação padrão decodificará os parâmetros de desenho proprietário e delegará as mensagens de desenho proprietário para os controles ou menu. Isso é chamado de auto-draw porque o código de desenho está na classe do controle ou menu, e não na janela do proprietário.

Usando controles de desenho automático, você pode criar classes de controle reutilizáveis que usam semântica de desenho proprietário para exibir o controle. O código para desenhar o controle está na classe de controle, não no seu pai. Essa é uma abordagem orientada a objeto para a programação de controle personalizado. Adicione a seguinte lista de funções às suas classes de desenho automático:

- Para botões de autodesenho:

    ```cpp
    CButton:DrawItem(LPDRAWITEMSTRUCT);
    // insert code to draw this button
    ```

- Para menus de desenho automático:

    ```cpp
    CMenu:MeasureItem(LPMEASUREITEMSTRUCT);
    // insert code to measure the size of an item in this menu
    CMenu:DrawItem(LPDRAWITEMSTRUCT);
    // insert code to draw an item in this menu
    ```

- Para as caixas de listagem de desenho automático:

    ```cpp
    CListBox:MeasureItem(LPMEASUREITEMSTRUCT);
    // insert code to measure the size of an item in this list box
    CListBox:DrawItem(LPDRAWITEMSTRUCT);
    // insert code to draw an item in this list box

    CListBox:CompareItem(LPCOMPAREITEMSTRUCT);
    // insert code to compare two items in this list box if LBS_SORT
    CListBox:DeleteItem(LPDELETEITEMSTRUCT);
    // insert code to delete an item from this list box
    ```

- Para caixas de combinação de desenho automático:

    ```cpp
    CComboBox:MeasureItem(LPMEASUREITEMSTRUCT);
    // insert code to measure the size of an item in this combo box
    CComboBox:DrawItem(LPDRAWITEMSTRUCT);
    // insert code to draw an item in this combo box

    CComboBox:CompareItem(LPCOMPAREITEMSTRUCT);
    // insert code to compare two items in this combo box if CBS_SORT
    CComboBox:DeleteItem(LPDELETEITEMSTRUCT);
    // insert code to delete an item from this combo box
    ```

Para obter detalhes sobre as estruturas de desenho proprietário ([DRAWITEMSTRUCT](/windows/win32/api/winuser/ns-winuser-drawitemstruct), [MEASUREITEMSTRUCT](/windows/win32/api/winuser/ns-winuser-measureitemstruct), [COMPAREITEMSTRUCT](/windows/win32/api/winuser/ns-winuser-compareitemstruct)e [DELETEITEMSTRUCT](/windows/win32/api/winuser/ns-winuser-deleteitemstruct)), consulte a documentação do `CWnd::OnDrawItem`MFC para `CWnd::OnCompareItem`, `CWnd::OnMeasureItem`, e `CWnd::OnDeleteItem` respectivamente.

## <a name="using-self-draw-controls-and-menus"></a>Usando controles e menus de desenho automático

Para menus de desenho automático, você deve substituir os `OnMeasureItem` métodos e. `OnDrawItem`

Para caixas de listagem e caixas de combinação de desenho automático, você `OnMeasureItem` deve `OnDrawItem`substituir e. Você deve especificar o estilo LBS_OWNERDRAWVARIABLE para as caixas de listagem ou o estilo CBS_OWNERDRAWVARIABLE para caixas de combinação no modelo de caixa de diálogo. O estilo OWNERDRAWFIXED não funcionará com itens de desenho automático porque a altura fixa do item é determinada antes de os controles de desenho automático serem anexados à caixa de listagem. (Você pode usar os métodos [CListBox:: SetItemHeight](../mfc/reference/clistbox-class.md#setitemheight) e [CComboBox:: SetItemHeight](../mfc/reference/ccombobox-class.md#setitemheight) para superar essa limitação.)

Alternar para um estilo OWNERDRAWVARIABLE forçará o sistema a aplicar o estilo NOINTEGRALHEIGHT ao controle. Como o controle não pode calcular uma altura integral com itens de tamanho variável, o estilo padrão de INTEGRALHEIGHT é ignorado e o controle é sempre NOINTEGRALHEIGHT. Se os itens forem de altura fixa, você poderá impedir que itens parciais sejam desenhados especificando o tamanho do controle como um multiplicador inteiro do tamanho do item.

Para caixas de listagem e caixas de combinação de autodesenho com o estilo LBS_SORT ou CBS_SORT, você deve `OnCompareItem` substituir o método.

Para caixas de listagem e caixas de combinação de autodesenho, `OnDeleteItem` geralmente não é substituído. Você pode substituir `OnDeleteItem` se desejar executar qualquer processamento especial. Um caso em que isso seria aplicável é quando memória adicional ou outros recursos são armazenados com cada caixa de listagem ou item de caixa de combinação.

## <a name="examples-of-self-drawing-controls-and-menus"></a>Exemplos de menus e controles de autodesenho

O exemplo de [CTRLTEST](../overview/visual-cpp-samples.md) geral do MFC fornece exemplos de um menu de desenho automático e uma caixa de listagem de desenho automático.

O exemplo mais comum de um botão de autodesenho é um botão de bitmap. Um botão de bitmap é um botão que mostra uma, duas ou três imagens de bitmap para os diferentes Estados. Um exemplo disso é fornecido na classe MFC [CBitmapButton](../mfc/reference/cbitmapbutton-class.md).

## <a name="dynamic-subclassing"></a>Subclasse dinâmica

Ocasionalmente, você desejará alterar a funcionalidade de um objeto que já existe. Os exemplos anteriores exigiam que você personalizasse os controles antes que eles fossem criados. A criação dinâmica de subclasses permite que você personalize um controle que já foi criado.

A subclasse é o termo do Windows para substituir <xref:System.Windows.Forms.Control.WndProc%2A> o de uma janela por um `WndProc` personalizado e chamar o `WndProc` antigo para a funcionalidade padrão.

Isso não deve ser confundido C++ com a derivação de classe. Para esclarecimentos, C++ a *classe base* terms e a *classe derivada* são análogas à superclasse e subclasse no modelo de objeto do Windows. C++a derivação com o MFC e a subclasse do Windows são funcionalmente semelhantes, exceto pelo fato C++ de não oferecer suporte a subclasses dinâmicas.

A `CWnd` classe fornece a conexão entre um C++ objeto (derivado de `CWnd`) e um objeto de janela do Windows (conhecido `HWND`como um).

Há três maneiras comuns de se relacionar:

- `CWnd`cria o `HWND`. Você pode modificar o comportamento em uma classe derivada criando uma classe derivada de `CWnd`. O `HWND` é criado quando seu aplicativo chama [CWnd:: Create](../mfc/reference/cwnd-class.md#create).

- O aplicativo anexa um `CWnd` a um existente. `HWND` O comportamento da janela existente não é modificado. Esse é um caso de delegação e torna-se possível chamando [CWnd:: Attach](../mfc/reference/cwnd-class.md#attach) ao alias de um `HWND` existente para `CWnd` um objeto.

- `CWnd`é anexado a um existente `HWND` e você pode modificar o comportamento em uma classe derivada. Isso é chamado de subclasse dinâmica porque estamos alterando o comportamento e, portanto, a classe de um objeto do Windows em tempo de execução.

Você pode obter uma subclasse dinâmica usando os métodos [CWnd:: SubclassWindow](../mfc/reference/cwnd-class.md#subclasswindow) e[CWnd:: SubclassDlgItem](../mfc/reference/cwnd-class.md#subclassdlgitem).

Ambas as rotinas `CWnd` anexam um objeto `HWND`a um existente. `SubclassWindow`usa o `HWND` diretamente. `SubclassDlgItem`é uma função auxiliar que usa uma ID de controle e a janela pai. `SubclassDlgItem`foi projetado para anexar C++ objetos a controles de caixa de diálogo criados a partir de um modelo de caixa de diálogo.

Consulte o exemplo de [CTRLTEST](../overview/visual-cpp-samples.md) para obter vários exemplos de quando `SubclassWindow` usar `SubclassDlgItem`e.

## <a name="see-also"></a>Consulte também

[Observações técnicas por número](../mfc/technical-notes-by-number.md)<br/>
[Observações técnicas por categoria](../mfc/technical-notes-by-category.md)
