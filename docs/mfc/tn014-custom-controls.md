---
title: 'TN014: Controles personalizados | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
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
ms.openlocfilehash: 9625b3eafa75bdafff7d17ea63db8904d9b49529
ms.sourcegitcommit: c6b095c5f3de7533fd535d679bfee0503e5a1d91
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/26/2018
ms.locfileid: "36956841"
---
# <a name="tn014-custom-controls"></a>TN014: controles personalizados
Esta anotação descreve o suporte do MFC para controles personalizados e desenho automaticamente. Ele também descreve subclassificação dinâmica e descreve a relação entre [CWnd](../mfc/reference/cwnd-class.md) objetos e `HWND`s.  
  
 O aplicativo de exemplo do MFC CTRLTEST ilustra como usar vários controles personalizados. Consulte o código-fonte para o exemplo de MFC geral [CTRLTEST](../visual-cpp-samples.md) e a Ajuda online.  
  
## <a name="owner-draw-controlsmenus"></a>Controles/Menus de desenho proprietário  
 Windows fornece suporte para controles de desenho do proprietário e menus usando mensagens do Windows. A janela pai de qualquer menu ou controle recebe essas mensagens e chamadas de funções na resposta. Você pode substituir essas funções para personalizar a aparência e o comportamento do menu ou controle de desenho proprietário.  
  
 MFC suporta desenho proprietário diretamente com as seguintes funções:  
  
- [CWnd::OnDrawItem](../mfc/reference/cwnd-class.md#ondrawitem)  
  
- [CWnd::OnMeasureItem](../mfc/reference/cwnd-class.md#onmeasureitem)  
  
- [CWnd::OnCompareItem](../mfc/reference/cwnd-class.md#oncompareitem)  
  
- [CWnd::OnDeleteItem](../mfc/reference/cwnd-class.md#ondeleteitem)  
  
 Você pode substituir essas funções em sua `CWnd` derivado da classe para implementar o comportamento de desenho personalizadas.  
  
 Essa abordagem não resulta em código reutilizável. Se você tiver dois controles semelhantes em duas diferentes `CWnd` classes, você deve implementar o comportamento do controle personalizado em dois locais. A arquitetura de controle Self desenho suporte MFC resolve esse problema.  
  
## <a name="self-draw-controls-and-menus"></a>Desenhar os controles e Menus  
 MFC fornece uma implementação padrão (no `CWnd` e [CMenu](../mfc/reference/cmenu-class.md) classes) para as mensagens de desenho do proprietário padrão. Esta implementação padrão será decodificar os parâmetros de desenho do proprietário e delegar as mensagens de desenho proprietário para os controles ou menu. Isso é chamado automaticamente desenhar porque o código de desenho é na classe de controle ou no menu, não na janela do proprietário.  
  
 Usando controles desenhar automaticamente, você pode criar classes de controle reutilizável que usam a semântica de desenho proprietário para exibir o controle. O código para desenhar o controle é da classe de controle, não é seu pai. Essa é uma abordagem orientada a objeto para programação de controle personalizado. Adicione a seguinte lista de funções para suas classes desenhar automaticamente:  
  
-   Para desenhar os botões:  
  
 ```  
    CButton:DrawItem(LPDRAWITEMSTRUCT);
*// insert code to draw this button  
 ```  
  
-   Para desenhar os menus:  
  
 ```  
    CMenu:MeasureItem(LPMEASUREITEMSTRUCT);
*// insert code to measure the size of an item in this menu  
    CMenu:DrawItem(LPDRAWITEMSTRUCT);
*// insert code to draw an item in this menu  
 ```  
  
-   Desenhar automática das caixas de listagem:  
  
 ```  
    CListBox:MeasureItem(LPMEASUREITEMSTRUCT);
*// insert code to measure the size of an item in this list box  
    CListBox:DrawItem(LPDRAWITEMSTRUCT);
*// insert code to draw an item in this list box  
 
    CListBox:CompareItem(LPCOMPAREITEMSTRUCT);
*// insert code to compare two items in this list box if LBS_SORT  
    CListBox:DeleteItem(LPDELETEITEMSTRUCT);
*// insert code to delete an item from this list box  
 ```  
  
-   Para caixas de combinação desenhar automaticamente:  
  
 ```  
    CComboBox:MeasureItem(LPMEASUREITEMSTRUCT);
*// insert code to measure the size of an item in this combo box  
    CComboBox:DrawItem(LPDRAWITEMSTRUCT);
*// insert code to draw an item in this combo box  
 
    CComboBox:CompareItem(LPCOMPAREITEMSTRUCT);
*// insert code to compare two items in this combo box if CBS_SORT  
    CComboBox:DeleteItem(LPDELETEITEMSTRUCT);
*// insert code to delete an item from this combo box  
 ```  
  
 Para obter detalhes sobre as estruturas de desenho proprietário ([DRAWITEMSTRUCT](../mfc/reference/drawitemstruct-structure.md), [MEASUREITEMSTRUCT](../mfc/reference/measureitemstruct-structure.md), [COMPAREITEMSTRUCT](../mfc/reference/compareitemstruct-structure.md), e [DELETEITEMSTRUCT](../mfc/reference/deleteitemstruct-structure.md)) consulte a documentação do MFC para `CWnd::OnDrawItem`, `CWnd::OnMeasureItem`, `CWnd::OnCompareItem`, e `CWnd::OnDeleteItem` respectivamente.  
  
## <a name="using-self-draw-controls-and-menus"></a>Usando os menus e desenhar os controles  
 Para desenhar os menus, você deve substituir o `OnMeasureItem` e `OnDrawItem` métodos.  
  
 Para caixas de listagem desenhar automaticamente e caixas de combinação, você deve substituir `OnMeasureItem` e `OnDrawItem`. Você deve especificar o estilo LBS_OWNERDRAWVARIABLE para caixas de listagem ou CBS_OWNERDRAWVARIABLE para caixas de combinação no modelo de caixa de diálogo. O estilo OWNERDRAWFIXED não funcionará com automaticamente desenhar itens porque a altura do item fixa é determinada para que desenhar os controles estão anexados à caixa de listagem. (Você pode usar os métodos [CListBox::SetItemHeight](../mfc/reference/clistbox-class.md#setitemheight) e [CComboBox::SetItemHeight](../mfc/reference/ccombobox-class.md#setitemheight) para superar essa limitação.)  
  
 Alternar para um estilo OWNERDRAWVARIABLE forçará o sistema para aplicar o estilo NOINTEGRALHEIGHT ao controle. Porque o controle não pode calcular uma altura integral com itens de tamanhos variável, o estilo padrão de INTEGRALHEIGHT será ignorado e o controle é sempre NOINTEGRALHEIGHT. Se os itens são uma altura fixa, você pode impedir que itens parciais desenhada, especificando o tamanho do controle para ser um multiplicador de inteiro do tamanho do item.  
  
 Para caixas de listagem e caixas de combinação com o estilo LBS_SORT ou CBS_SORT de desenho automaticamente, você deve substituir o `OnCompareItem` método.  
  
 Para desenhar automaticamente caixas de listagem e caixas de combinação, `OnDeleteItem` geralmente não é substituída. Você pode substituir `OnDeleteItem` se você quiser executar qualquer processamento especial. Um caso onde isso seria aplicável é quando mais memória ou outros recursos são armazenados com cada item de caixa de combinação ou de caixa de listagem.  
  
## <a name="examples-of-self-drawing-controls-and-menus"></a>Exemplos de desenho automaticamente controles e Menus  
 O exemplo de MFC geral [CTRLTEST](../visual-cpp-samples.md) fornece exemplos de um menu Desenhar automaticamente e uma caixa de listagem desenhar automaticamente.  
  
 O exemplo mais comum de um botão de desenho automática é um botão de bitmap. Um botão de bitmap é um botão que mostra uma, duas ou três imagens de bitmap para os diferentes estados. Um exemplo disso é fornecido na classe MFC [CBitmapButton](../mfc/reference/cbitmapbutton-class.md).  
  
## <a name="dynamic-subclassing"></a>Subclassificação dinâmica  
 Ocasionalmente, você deve alterar a funcionalidade de um objeto que já existe. Os exemplos anteriores necessitavam personalizar os controles antes que eles foram criados. Subclassificação dinâmica permite que você personalize a um controle que já foi criado.  
  
 Subclassificação é o termo do Windows para substituir o [WndProc](http://msdn.microsoft.com/en-us/94ba8ffa-3c36-46d4-ac74-9bd10b1ffd26) de uma janela com um personalizado `WndProc` e chamando o antigo `WndProc` para a funcionalidade padrão.  
  
 Isso não deve ser confundido com a derivação de classe C++. Para fins de esclarecimento, os termos de C++ *classe base* e *classe derivada* são análogos a *superclasse* e *subclasse* nas janelas modelo de objeto. Derivação de C++ com MFC e Windows subclassificação são funcionalmente semelhante, exceto o C++ não suporta subclassificação dinâmica.  
  
 O `CWnd` classe fornece a conexão entre um objeto C++ (derivado de `CWnd`) e um objeto de janela do Windows (conhecida como uma `HWND`).  
  
 Há três maneiras comuns que eles estão relacionados:  
  
- `CWnd` cria o `HWND`. Você pode modificar o comportamento em uma classe derivada, criando uma classe derivada de `CWnd`. O `HWND` é criado quando o aplicativo chama [CWnd::Create](../mfc/reference/cwnd-class.md#create).  
  
-   A aplicativo anexa uma `CWnd` um existente `HWND`. O comportamento da janela existente não é modificado. Este é um caso de delegação e é possibilitado chamando [CWnd::Attach](../mfc/reference/cwnd-class.md#attach) alias um existente `HWND` para um `CWnd` objeto.  
  
- `CWnd` é anexado a um existente `HWND` e você pode modificar o comportamento em uma classe derivada. Isso é chamado dinâmico subclasses porque nós estamos alterando o comportamento e, portanto, a classe, de um objeto em tempo de execução do Windows.  
  
 Você pode obter subclassificação dinâmica usando os métodos [CWnd::SubclassWindow](../mfc/reference/cwnd-class.md#subclasswindow) e[CWnd::SubclassDlgItem](../mfc/reference/cwnd-class.md#subclassdlgitem).  
  
 Ambas as rotinas de anexar um `CWnd` objeto um existente `HWND`. `SubclassWindow` usa o `HWND` diretamente. `SubclassDlgItem` é uma função auxiliar que usa uma ID de controle e a janela pai. `SubclassDlgItem` foi projetado para anexar objetos C++ para controles de caixa de diálogo criados de um modelo de caixa de diálogo.  
  
 Consulte o [CTRLTEST](../visual-cpp-samples.md) exemplo para examinar vários exemplos de quando usar `SubclassWindow` e `SubclassDlgItem`.  
  
## <a name="see-also"></a>Consulte também  
 [Observações técnicas por número](../mfc/technical-notes-by-number.md)   
 [Observações técnicas por categoria](../mfc/technical-notes-by-category.md)

