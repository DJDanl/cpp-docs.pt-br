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
ms.openlocfilehash: 484cef2787c9e5c166a7b20b017251b559d7221c
ms.sourcegitcommit: 1839405b97036891b6e4d37c99def044d6f37eff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/18/2020
ms.locfileid: "88562539"
---
# <a name="csplitbutton-class"></a>Classe CSplitButton

A `CSplitButton` classe representa um controle de botão de divisão. O controle de botão de divisão executa um comportamento padrão quando um usuário clica na parte principal do botão e exibe um menu suspenso quando um usuário clica na seta suspensa do botão.

## <a name="syntax"></a>Sintaxe

```
class CSplitButton : public CButton
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[CSplitButton::CSplitButton](#csplitbutton)|Constrói um objeto `CSplitButton`.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CSplitButton:: criar](#create)|Cria um controle de botão de divisão com estilos especificados e anexa-o ao `CSplitButton` objeto atual.|
|[CSplitButton::SetDropDownMenu](#setdropdownmenu)|Define o menu suspenso que é exibido quando um usuário clica na seta suspensa do controle do botão de divisão atual.|

### <a name="protected-methods"></a>Métodos Protegidos

|Nome|Descrição|
|----------|-----------------|
|[CSplitButton:: OnDropDown](#ondropdown)|Manipula a notificação de BCN_DROPDOWN que o sistema envia quando um usuário clica na seta suspensa do controle do botão de divisão atual.|

## <a name="remarks"></a>Comentários

A `CSplitButton` classe é derivada da classe [CButton](../../mfc/reference/cbutton-class.md) . O controle de botão de divisão é um controle de botão cujo estilo é BS_SPLITBUTTON. Ele exibe um menu personalizado quando um usuário clica na seta suspensa. Para obter mais informações, consulte os estilos de BS_SPLITBUTTON e de BS_DEFSPLITBUTTON em [estilos de botão](/windows/win32/Controls/button-styles).

A figura a seguir descreve uma caixa de diálogo que contém um controle de pager e um controle de botão de divisão (1). A seta suspensa (2) já foi clicada e o submenu (3) é exibido.

![Caixa de diálogo com um controle SplitButton e pager.](../../mfc/reference/media/splitbutton_pager.png "Caixa de diálogo com um controle SplitButton e pager.")

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[CObject](../../mfc/reference/cobject-class.md)

[CCmdTarget](../../mfc/reference/ccmdtarget-class.md)

[CWnd](../../mfc/reference/cwnd-class.md)

[CButton](../../mfc/reference/cbutton-class.md)

`CSplitButton`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxcmn. h

Essa classe tem suporte no Windows Vista e versões posteriores.

Os requisitos adicionais para essa classe são descritos em [requisitos de compilação para controles comuns do Windows Vista](../../mfc/build-requirements-for-windows-vista-common-controls.md).

## <a name="csplitbuttoncreate"></a><a name="create"></a> CSplitButton:: criar

Cria um controle de botão de divisão com estilos especificados e anexa-o ao `CSplitButton` objeto atual.

```
virtual BOOL Create(
    DWORD dwStyle,
    const RECT& rect,
    CWnd* pParentWnd,
    UINT nID);
```

### <a name="parameters"></a>Parâmetros

*dwStyle*\
no Uma combinação de bits (ou) de estilos a ser aplicada ao controle. Para obter mais informações, consulte [estilos de botão](../../mfc/reference/styles-used-by-mfc.md#button-styles).

*Rect*\
no Uma referência a uma estrutura [Rect](/windows/win32/api/windef/ns-windef-rect) que contém a posição e o tamanho do controle.

*pParentWnd*\
no Um ponteiro não nulo para um objeto [CWnd](../../mfc/reference/cwnd-class.md) que é a janela pai do controle.

*nID*\
no A ID do controle.

### <a name="return-value"></a>Valor retornado

TRUE se esse método for bem-sucedido; caso contrário, FALSE.

## <a name="csplitbuttoncsplitbutton"></a><a name="csplitbutton"></a> CSplitButton::CSplitButton

Constrói um objeto `CSplitButton`. Os parâmetros do Construtor especificam um submenu que é exibido quando um usuário clica na seta suspensa do controle do botão de divisão.

```
CSplitButton();

CSplitButton(
    UINT nMenuId,
    UINT nSubMenuId)
CSplitButton(CMenu* pMenu)
```

### <a name="parameters"></a>Parâmetros

*nMenuId*\
no A ID de recurso da barra de menus.

*nSubMenuId*\
no A ID de recurso de um submenu.

*pMenu*\
no Um ponteiro para um objeto [CMenu](../../mfc/reference/cmenu-class.md) que especifica um submenu. O `CSplitButton` objeto exclui o `CMenu` objeto e seu HMENU associado quando o `CSplitButton` objeto sai do escopo.

### <a name="remarks"></a>Comentários

Use o método [CSplitButton:: Create](#create) para criar um controle de botão de divisão e anexá-lo ao `CSplitButton` objeto.

## <a name="csplitbuttonondropdown"></a><a name="ondropdown"></a> CSplitButton:: OnDropDown

Manipula a notificação de BCN_DROPDOWN que o sistema envia quando um usuário clica na seta suspensa do controle do botão de divisão atual.

```
afx_msg void OnDropDown(
    NMHDR* pNMHDR,
    LRESULT* pResult);
```

### <a name="parameters"></a>Parâmetros

*pNMHDR*\
no Ponteiro para uma estrutura [NMHDR](/windows/win32/api/richedit/ns-richedit-nmhdr) que contém informações sobre a notificação de [BCN_DROPDOWN](/windows/win32/Controls/bcn-dropdown) .

*pResult*\
fora (Não usado; nenhum valor é retornado.) Valor de retorno da notificação de [BCN_DROPDOWN](/windows/win32/Controls/bcn-dropdown) .

### <a name="remarks"></a>Comentários

Quando o usuário clica na seta suspensa em um controle de botão de divisão, o sistema envia uma mensagem de notificação BCN_DROPDOWN, que o `OnDropDown` método manipula. No entanto, o `CSplitButton` objeto não encaminha a notificação de BCN_DROPDOWN para o controle que contém o controle do botão de divisão. Consequentemente, o controle recipiente não pode dar suporte a uma ação personalizada em resposta à notificação.

Para implementar uma ação personalizada que o controle recipiente suporta, use um objeto [CButton](../../mfc/reference/cbutton-class.md) com um estilo de BS_SPLITBUTTON em vez de um `CSplitButton` objeto. Em seguida, implemente um manipulador para a notificação de BCN_DROPDOWN no `CButton` objeto. Para obter mais informações, consulte [estilos de botão](../../mfc/reference/styles-used-by-mfc.md#button-styles).

Para implementar uma ação personalizada que o próprio controle de botão de divisão suporta, use a [reflexão de mensagem](../../mfc/tn062-message-reflection-for-windows-controls.md). Derive sua própria classe da `CSplitButton` classe e nomeie-a, por exemplo, CMySplitButton. Em seguida, adicione o seguinte mapa de mensagem ao seu aplicativo para manipular a notificação de BCN_DROPDOWN:

```
BEGIN_MESSAGE_MAP(CMySplitButton,
    CSplitButton)
    ON_NOTIFY_REFLECT(BCN_DROPDOWN, &CMySplitButton::OnDropDown)
END_MESSAGE_MAP()
```

## <a name="csplitbuttonsetdropdownmenu"></a><a name="setdropdownmenu"></a> CSplitButton::SetDropDownMenu

Define o menu suspenso que é exibido quando um usuário clica na seta suspensa do controle do botão de divisão atual.

```cpp
void SetDropDownMenu(
    UINT nMenuId,
    UINT nSubMenuId);

void SetDropDownMenu(CMenu* pMenu);
```

### <a name="parameters"></a>Parâmetros

*nMenuId*\
no A ID de recurso da barra de menus.

*nSubMenuId*\
no A ID de recurso de um submenu.

*pMenu*\
no Ponteiro para um objeto [CMenu](../../mfc/reference/cmenu-class.md) que especifica um submenu. O `CSplitButton` objeto exclui o `CMenu` objeto e seu HMENU associado quando o `CSplitButton` objeto sai do escopo.

### <a name="remarks"></a>Comentários

O parâmetro *nMenuId* identifica uma barra de menus, que é uma lista horizontal de itens da barra de menus. O parâmetro *nSubMenuId* é um número de índice baseado em zero que identifica um submenu, que é a lista suspensa de itens de menu associados a cada item da barra de menus. Por exemplo, um aplicativo típico tem um menu que contém os itens da barra de menus, "arquivo", "Editar" e "ajuda". O item da barra de menus "arquivo" tem um submenu que contém os itens de menu, "abrir", "fechar" e "sair". Quando a seta suspensa do controle do botão de divisão é clicada, o controle exibe o submenu especificado, não a barra de menus.

A figura a seguir descreve uma caixa de diálogo que contém um controle de pager e um controle de botão de divisão (1). A seta suspensa (2) já foi clicada e o submenu (3) é exibido.

![Caixa de diálogo com um controle SplitButton e pager.](../../mfc/reference/media/splitbutton_pager.png "Caixa de diálogo com um controle SplitButton e pager.")

### <a name="example"></a>Exemplo

A primeira instrução no exemplo de código a seguir demonstra o método [CSplitButton:: SetDropDownMenu](#setdropdownmenu) . Criamos o menu com o editor de recursos do Visual Studio, que é chamado automaticamente de ID de barra de menus, IDR_MENU1. O parâmetro *nSubMenuId* , que é zero, refere-se ao único submenu da barra de menus.

[!code-cpp[NVC_MFC_CSplitButton_s2#1](../../mfc/reference/codesnippet/cpp/csplitbutton-class_1.cpp)]

## <a name="see-also"></a>Confira também

[Classe CSplitButton](../../mfc/reference/csplitbutton-class.md)<br/>
[Gráfico de hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classe CButton](../../mfc/reference/cbutton-class.md)
