---
title: Classe CSplitButton
ms.date: 11/19/2018
f1_keywords:
- CSplitButton
- AFXCMN/CSplitButton
- AFXCMN/CSplitButton::CSplitButton
- AFXCMN/CSplitButton::Create
- AFXCMN/CSplitButton::SetDropDownMenu
- AFXCMN/CSplitButton::OnDropDown
helpviewer_keywords:
- CSplitButton [MFC], CSplitButton
- CSplitButton [MFC], Create
- CSplitButton [MFC], SetDropDownMenu
- CSplitButton [MFC], OnDropDown
ms.assetid: 6844d0a9-6408-4e44-9b5f-57628ed8bad6
ms.openlocfilehash: 0b54324c3c5503182add15a3dd0a9ecd07c24b18
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81318108"
---
# <a name="csplitbutton-class"></a>Classe CSplitButton

A `CSplitButton` classe representa um controle de botão dividido. O controle de botão dividido executa um comportamento padrão quando um usuário clica na parte principal do botão e exibe um menu suspenso quando um usuário clica na seta suspenso do botão.

## <a name="syntax"></a>Sintaxe

```
class CSplitButton : public CButton
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[botão csplit::CSplitButton](#csplitbutton)|Constrói um objeto `CSplitButton`.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[csplitbutton::Criar](#create)|Cria um controle de botão dividido com estilos `CSplitButton` especificados e o anexa ao objeto atual.|
|[csplitbutton::setDropDownmenu](#setdropdownmenu)|Define o menu suspenso exibido quando um usuário clica na seta suspensa do controle atual do botão dividido.|

### <a name="protected-methods"></a>Métodos Protegidos

|Nome|Descrição|
|----------|-----------------|
|[csplitbutton::OnDropDown](#ondropdown)|Lida com a notificação BCN_DROPDOWN que o sistema envia quando um usuário clica na seta baixa do controle atual do botão dividido.|

## <a name="remarks"></a>Comentários

A `CSplitButton` classe é derivada da classe [CButton.](../../mfc/reference/cbutton-class.md) O controle do botão split é um controle de botão cujo estilo é BS_SPLITBUTTON. Ele exibe um menu personalizado quando um usuário clica na seta suspenso. Para obter mais informações, consulte os estilos BS_SPLITBUTTON e BS_DEFSPLITBUTTON em [Button Styles](/windows/win32/Controls/button-styles).

A figura a seguir mostra uma caixa de diálogo que contém um controle de pager e um (1) controle de botão dividido. A seta (2) suspensa já foi clicada e o submenu (3) é exibido.

![Dialoge com um botão de divisão e controle de pager.](../../mfc/reference/media/splitbutton_pager.png "Dialoge com um botão de divisão e controle de pager.")

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[Cobject](../../mfc/reference/cobject-class.md)

[Ccmdtarget](../../mfc/reference/ccmdtarget-class.md)

[CWnd](../../mfc/reference/cwnd-class.md)

[CButton](../../mfc/reference/cbutton-class.md)

`CSplitButton`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxcmn.h

Esta classe é suportada no Windows Vista e depois.

Requisitos adicionais para esta classe são descritos em [Build Requirements for Windows Vista Common Controls](../../mfc/build-requirements-for-windows-vista-common-controls.md).

## <a name="csplitbuttoncreate"></a><a name="create"></a>csplitbutton::Criar

Cria um controle de botão dividido com estilos `CSplitButton` especificados e o anexa ao objeto atual.

```
virtual BOOL Create(
    DWORD dwStyle,
    const RECT& rect,
    CWnd* pParentWnd,
    UINT nID);
```

### <a name="parameters"></a>Parâmetros

|Parâmetro|Descrição|
|---------------|-----------------|
|*Dwstyle*|[em] Uma combinação bitwise (OR) de estilos a serem aplicados ao controle. Para obter mais informações, consulte [Button Styles](../../mfc/reference/styles-used-by-mfc.md#button-styles).|
|*Rect*|[em] Uma referência a uma estrutura [RECT](/previous-versions/dd162897\(v=vs.85\)) que contenha a posição e o tamanho do controle.|
|*Pparentwnd*|[em] Um ponteiro não nulo para um objeto [CWnd](../../mfc/reference/cwnd-class.md) que é a janela pai do controle.|
|*nID*|[em] A id do controle.|

### <a name="return-value"></a>Valor retornado

VERDADE se este método for bem sucedido; caso contrário, FALSE.

## <a name="csplitbuttoncsplitbutton"></a><a name="csplitbutton"></a>botão csplit::CSplitButton

Constrói um objeto `CSplitButton`. Os parâmetros do construtor especificam um submenu exibido quando um usuário clica na seta suspensa do controle do botão dividido.

```
CSplitButton();

CSplitButton(
    UINT nMenuId,
    UINT nSubMenuId)
CSplitButton(CMenu* pMenu)
```

### <a name="parameters"></a>Parâmetros

|Parâmetro|Descrição|
|---------------|-----------------|
|*nMenuId*|[em] O iD de recurso da barra de menu.|
|*nSubMenuId*|[em] O id de recurso de um submenu.|
|*pMenu*|[em] Um ponteiro para um objeto [CMenu](../../mfc/reference/cmenu-class.md) que especifica um submenu. O `CSplitButton` objeto exclui `CMenu` o objeto e seu `CSplitButton` HMENU associado quando o objeto sai do escopo.|

### <a name="remarks"></a>Comentários

Use o [método CSplitButton::Criar](#create) para criar um controle `CSplitButton` de botão dividido e anexá-lo ao objeto.

## <a name="csplitbuttonondropdown"></a><a name="ondropdown"></a>csplitbutton::OnDropDown

Lida com a notificação BCN_DROPDOWN que o sistema envia quando um usuário clica na seta baixa do controle atual do botão dividido.

```
afx_msg void OnDropDown(
    NMHDR* pNMHDR,
    LRESULT* pResult);
```

### <a name="parameters"></a>Parâmetros

|Parâmetro|Descrição|
|---------------|-----------------|
|*pNMHDR*|[em] Ponteiro para uma estrutura [NMHDR](/windows/win32/api/richedit/ns-richedit-nmhdr) que contém informações sobre a notificação [BCN_DROPDOWN.](/windows/win32/Controls/bcn-dropdown)|
|*Presult*|[fora] (Não utilizado; nenhum valor é devolvido.) Valor de devolução da notificação [de BCN_DROPDOWN.](/windows/win32/Controls/bcn-dropdown)|

### <a name="remarks"></a>Comentários

Quando o usuário clica na seta baixa em um controle de botão `OnDropDown` dividido, o sistema envia uma mensagem de notificação de BCN_DROPDOWN, que o método lida. No entanto, o `CSplitButton` objeto não encaminha a notificação BCN_DROPDOWN para o controle que contém o controle do botão dividido. Consequentemente, o controle contendo não pode suportar uma ação personalizada em resposta à notificação.

Para implementar uma ação personalizada que o controle que contém suporta, use um `CSplitButton` objeto [CButton](../../mfc/reference/cbutton-class.md) com um estilo de BS_SPLITBUTTON em vez de um objeto. Em seguida, implemente um `CButton` manipulador para a notificação BCN_DROPDOWN no objeto. Para obter mais informações, consulte [Button Styles](../../mfc/reference/styles-used-by-mfc.md#button-styles).

Para implementar uma ação personalizada que o próprio controle do botão split suporta, use [a reflexão da mensagem](../../mfc/tn062-message-reflection-for-windows-controls.md). Obtenha sua própria `CSplitButton` classe da classe e nomeie-a, por exemplo, CMySplitButton. Em seguida, adicione o seguinte mapa de mensagem ao seu aplicativo para lidar com a notificação BCN_DROPDOWN:

```
BEGIN_MESSAGE_MAP(CMySplitButton,
    CSplitButton)
    ON_NOTIFY_REFLECT(BCN_DROPDOWN, &CMySplitButton::OnDropDown)
END_MESSAGE_MAP()
```

## <a name="csplitbuttonsetdropdownmenu"></a><a name="setdropdownmenu"></a>csplitbutton::setDropDownmenu

Define o menu suspenso exibido quando um usuário clica na seta suspensa do controle atual do botão dividido.

```
void SetDropDownMenu(
    UINT nMenuId,
    UINT nSubMenuId);

void SetDropDownMenu(CMenu* pMenu);
```

### <a name="parameters"></a>Parâmetros

|Parâmetro|Descrição|
|---------------|-----------------|
|*nMenuId*|[em] O iD de recurso da barra de menu.|
|*nSubMenuId*|[em] O id de recurso de um submenu.|
|*pMenu*|[em] Pointer para um objeto [CMenu](../../mfc/reference/cmenu-class.md) que especifica um submenu. O `CSplitButton` objeto exclui `CMenu` o objeto e seu `CSplitButton` HMENU associado quando o objeto sai do escopo.|

### <a name="remarks"></a>Comentários

O parâmetro *nMenuId* identifica uma barra de menu, que é uma lista horizontal de itens da barra de menu. O parâmetro *nSubMenuId* é um número de índice baseado em zero que identifica um submenu, que é a lista suspenso de itens do menu associados a cada item da barra de menu. Por exemplo, um aplicativo típico tem um menu que contém os itens da barra de menu, "Arquivo", "Editar" e "Ajuda". O item da barra de menu "Arquivo" tem um submenu que contém os itens do menu, "Abrir", "Fechar" e "Sair". Quando a seta suspensa do controle de botão dividido é clicada, o controle exibe o submenu especificado, não a barra de menu.

A figura a seguir mostra uma caixa de diálogo que contém um controle de pager e um (1) controle de botão dividido. A seta (2) suspensa já foi clicada e o submenu (3) é exibido.

![Dialoge com um botão de divisão e controle de pager.](../../mfc/reference/media/splitbutton_pager.png "Dialoge com um botão de divisão e controle de pager.")

### <a name="example"></a>Exemplo

A primeira declaração no exemplo de código a seguir demonstra o método [CSplitButton::SetDropDownMenu.](#setdropdownmenu) Criamos o menu com o editor de recursos do Visual Studio, que automaticamente nomeou o ID da barra de menu, IDR_MENU1. O parâmetro *nSubMenuId,* que é zero, refere-se ao único submenu da barra de menu.

[!code-cpp[NVC_MFC_CSplitButton_s2#1](../../mfc/reference/codesnippet/cpp/csplitbutton-class_1.cpp)]

## <a name="see-also"></a>Confira também

[Classe CSplitButton](../../mfc/reference/csplitbutton-class.md)<br/>
[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classe CButton](../../mfc/reference/cbutton-class.md)
