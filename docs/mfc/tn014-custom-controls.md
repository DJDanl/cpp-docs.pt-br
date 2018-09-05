---
title: 'TN014: Controles personalizados | Microsoft Docs'
ms.custom: ''
ms.date: 06/28/2018
ms.technology:
- cpp-mfc
ms.topic: conceptual
f1_keywords:
- vc.controls
dev_langs:
- C++
helpviewer_keywords:
- TN014
- custom controls [MFC]
ms.assetid: 1917a498-f643-457c-b570-9a0af7dbf7bb
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: f3838fc2888567fa700eebd127bc7990175bdbc8
ms.sourcegitcommit: a7046aac86f1c83faba1088c80698474e25fe7c3
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/04/2018
ms.locfileid: "43693582"
---
# <a name="tn014-custom-controls"></a>TN014: controles personalizados

Essa observação descreve o suporte do MFC para controles personalizados e de desenho de Self. Ele também descreve a criação de subclasses dinâmica e descreve a relação entre [CWnd](../mfc/reference/cwnd-class.md) objetos e `HWND`s.

O aplicativo de exemplo do MFC CTRLTEST ilustra como usar muitos controles personalizados. Consulte o código-fonte para o exemplo de MFC geral [CTRLTEST](../visual-cpp-samples.md) e a Ajuda online.

## <a name="owner-draw-controlsmenus"></a>Controles/Menus de desenho proprietário

Windows fornece suporte para menus e controles desenhados pelo proprietário por meio de mensagens do Windows. A janela pai de qualquer controle ou o menu recebe essas mensagens e chamadas de funções na resposta. Você pode substituir essas funções para personalizar a aparência visual e o comportamento do seu controle de desenho proprietário ou menu.

MFC oferece suporte diretamente a desenho do proprietário com as seguintes funções:

- [CWnd::OnDrawItem](../mfc/reference/cwnd-class.md#ondrawitem)

- [CWnd::OnMeasureItem](../mfc/reference/cwnd-class.md#onmeasureitem)

- [CWnd::OnCompareItem](../mfc/reference/cwnd-class.md#oncompareitem)

- [CWnd::OnDeleteItem](../mfc/reference/cwnd-class.md#ondeleteitem)

Você pode substituir essas funções em seu `CWnd` derivado da classe para implementar o comportamento de desenho personalizado.

Essa abordagem não resulta em código reutilizável. Se você tiver dois controles semelhantes em duas diferentes `CWnd` classes, você deve implementar o comportamento de controle personalizado em dois locais. A arquitetura de controle com suporte do MFC Self desenho resolve esse problema.

## <a name="self-draw-controls-and-menus"></a>Self desenhar controles e Menus

O MFC fornece uma implementação padrão (na `CWnd` e [CMenu](../mfc/reference/cmenu-class.md) classes) para as mensagens de padrão de desenho do proprietário. Essa implementação padrão será decodificar os parâmetros de desenho do proprietário e delegar as mensagens de desenho do proprietário para os controles ou menu. Isso é chamado automaticamente desenhar porque o código de desenho é na classe do controle ou no menu, não na janela do proprietário.

Por meio de Self desenhar controles, você pode criar classes de controle reutilizáveis que usam a semântica de desenho do proprietário para exibir o controle. O código para desenhar o controle é na classe de controle, não é seu pai. Essa é uma abordagem orientada a objeto à programação do controle personalizado. Adicione a seguinte lista de funções às suas classes de desenhar automaticamente:

- Para desenhar os botões:

    ```cpp
    CButton:DrawItem(LPDRAWITEMSTRUCT);
    // insert code to draw this button
    ```

- Para desenhar os menus:

    ```cpp
    CMenu:MeasureItem(LPMEASUREITEMSTRUCT);
    // insert code to measure the size of an item in this menu
    CMenu:DrawItem(LPDRAWITEMSTRUCT);
    // insert code to draw an item in this menu
    ```

- Desenhar automática das caixas de listagem:

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

- Para caixas de combinação de desenhar automaticamente:

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

Para obter detalhes sobre as estruturas de desenho proprietário ([DRAWITEMSTRUCT](../mfc/reference/drawitemstruct-structure.md), [MEASUREITEMSTRUCT](../mfc/reference/measureitemstruct-structure.md), [COMPAREITEMSTRUCT](../mfc/reference/compareitemstruct-structure.md), e [DELETEITEMSTRUCT](../mfc/reference/deleteitemstruct-structure.md)) consulte a documentação da MFC `CWnd::OnDrawItem`, `CWnd::OnMeasureItem`, `CWnd::OnCompareItem`, e `CWnd::OnDeleteItem` , respectivamente.

## <a name="using-self-draw-controls-and-menus"></a>Usando menus e controles de desenhar Self

Para desenhar os menus, você deve substituir a `OnMeasureItem` e `OnDrawItem` métodos.

Para caixas de listagem Self desenhar e caixas de combinação, você deve substituir `OnMeasureItem` e `OnDrawItem`. Você deve especificar o estilo LBS_OWNERDRAWVARIABLE para caixas de listagem ou estilo CBS_OWNERDRAWVARIABLE para caixas de combinação no modelo de caixa de diálogo. O estilo OWNERDRAWFIXED não funcionará com Self desenhar itens como a altura do item fixa é determinada antes de desenhar os controles estão anexados à caixa de listagem. (Você pode usar os métodos [CListBox::SetItemHeight](../mfc/reference/clistbox-class.md#setitemheight) e [CComboBox::SetItemHeight](../mfc/reference/ccombobox-class.md#setitemheight) para superar essa limitação.)

Alternar para um estilo OWNERDRAWVARIABLE forçará o sistema para aplicar o estilo NOINTEGRALHEIGHT ao controle. Como o controle não é possível calcular uma altura integral com itens de tamanho variável, o estilo padrão dos INTEGRALHEIGHT será ignorado e o controle é sempre NOINTEGRALHEIGHT. Se seus itens corrigidos altura, você pode impedir que itens parciais que está sendo desenhado, especificando o tamanho do controle para ser um multiplicador de inteiro do tamanho do item.

Para desenhar Self caixas de listagem e caixas de combinação com o estilo LBS_SORT ou CBS_SORT, você deve substituir o `OnCompareItem` método.

Para desenhar Self caixas de listagem e caixas de combinação, `OnDeleteItem` geralmente não é substituído. Você pode substituir `OnDeleteItem` se você quiser executar qualquer processamento especial. Um caso em que isso seria aplicável é quando mais memória ou outros recursos são armazenados com cada item de caixa de combinação ou de caixa de listagem.

## <a name="examples-of-self-drawing-controls-and-menus"></a>Exemplos de controles e Menus de desenho automaticamente

O exemplo de MFC geral [CTRLTEST](../visual-cpp-samples.md) fornece exemplos de um menu Self desenhar e uma caixa de listagem Self desenhar.

O exemplo mais comum de um botão de desenho de Self é um botão de bitmap. Um botão de bitmap é um botão que mostra um, dois ou três imagens de bitmap para os diferentes estados. Um exemplo disso é fornecido na classe MFC [CBitmapButton](../mfc/reference/cbitmapbutton-class.md).

## <a name="dynamic-subclassing"></a>A criação de subclasses dinâmica

Ocasionalmente, você desejará alterar a funcionalidade de um objeto que já existe. Os exemplos anteriores exigia que você personalize os controles antes que eles foram criados. A criação de subclasses dinâmica permite que você personalize um controle que já foi criado.

A criação de subclasses é o termo do Windows para substituir a <xref:System.Windows.Forms.Control.WndProc%2A> de uma janela com um personalizado `WndProc` e chamar o antigo `WndProc` para a funcionalidade padrão.

Isso não deve ser confundido com a derivação de classe do C++. Para fins de esclarecimento, os termos de C++ *classe base* e *classe derivada* são análogas às *superclasse* e *subclasse* no Windows modelo de objeto. Derivação de C++ com a criação de classes do MFC e Windows são funcionalmente semelhante, exceto o C++ não oferece suporte para a criação de subclasses dinâmica.

O `CWnd` classe fornece a conexão entre um objeto C++ (derivado `CWnd`) e um objeto de janela do Windows (conhecido como um `HWND`).

Há três maneiras comuns, que eles estão relacionados:

- `CWnd` cria o `HWND`. Você pode modificar o comportamento em uma classe derivada, criando uma classe derivada de `CWnd`. O `HWND` é criado quando o aplicativo chama [CWnd::Create](../mfc/reference/cwnd-class.md#create).

- A aplicativo anexa uma `CWnd` a um existente `HWND`. O comportamento da janela existente não será modificado. Isso é um caso de delegação e se tornou possível chamando [CWnd::Attach](../mfc/reference/cwnd-class.md#attach) alias um existente `HWND` para um `CWnd` objeto.

- `CWnd` é anexado a um existente `HWND` e você pode modificar o comportamento em uma classe derivada. Isso é chamado dinâmico subclasses porque estamos alterando o comportamento e, portanto, a classe, de um objeto do Windows em tempo de execução.

Você pode obter a criação de subclasses dinâmica usando os métodos [CWnd::SubclassWindow](../mfc/reference/cwnd-class.md#subclasswindow) e[CWnd::SubclassDlgItem](../mfc/reference/cwnd-class.md#subclassdlgitem).

Ambas as rotinas de anexar um `CWnd` objeto a um existente `HWND`. `SubclassWindow` usa o `HWND` diretamente. `SubclassDlgItem` é uma função auxiliar que usa uma ID de controle e a janela pai. `SubclassDlgItem` foi projetado para anexar objetos C++ aos controles de caixa de diálogo criados a partir de um modelo de caixa de diálogo.

Consulte a [CTRLTEST](../visual-cpp-samples.md) exemplo para vários exemplos de quando usar `SubclassWindow` e `SubclassDlgItem`.

## <a name="see-also"></a>Consulte também

[Observações técnicas por número](../mfc/technical-notes-by-number.md)  
[Observações técnicas por categoria](../mfc/technical-notes-by-category.md)  
