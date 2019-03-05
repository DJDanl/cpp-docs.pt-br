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
ms.openlocfilehash: b73e27097a64722afd6bad5b9bc2157655bd9aad
ms.sourcegitcommit: c3093251193944840e3d0a068ecc30e6449624ba
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/04/2019
ms.locfileid: "57274499"
---
# <a name="csplitbutton-class"></a>Classe CSplitButton

O `CSplitButton` classe representa um controle de botão de divisão. O controle de botão de divisão executa um comportamento padrão quando um usuário clica na parte principal do botão e exibe um menu suspenso quando um usuário clica na seta suspensa do botão.

## <a name="syntax"></a>Sintaxe

```
class CSplitButton : public CButton
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores Públicos

|Nome|Descrição|
|----------|-----------------|
|[CSplitButton::CSplitButton](#csplitbutton)|Constrói um objeto `CSplitButton`.|

### <a name="public-methods"></a>Métodos Públicos

|Nome|Descrição|
|----------|-----------------|
|[CSplitButton::Create](#create)|Cria um controle de botão de divisão com estilos especificados e a anexa ao atual `CSplitButton` objeto.|
|[CSplitButton::SetDropDownMenu](#setdropdownmenu)|Define o menu suspenso que é exibido quando um usuário clica na seta suspensa do controle de botão de divisão atual.|

### <a name="protected-methods"></a>Métodos Protegidos

|Nome|Descrição|
|----------|-----------------|
|[CSplitButton::OnDropDown](#ondropdown)|Lida com a notificação BCN_DROPDOWN que o sistema envia quando um usuário clica na seta suspensa do controle de botão de divisão atual.|

## <a name="remarks"></a>Comentários

O `CSplitButton` classe é derivada de [CButton](../../mfc/reference/cbutton-class.md) classe. O controle de botão de divisão é um controle de botão cujo estilo é BS_SPLITBUTTON. Ele exibe um menu personalizado quando um usuário clica na seta suspensa. Para obter mais informações, consulte os estilos BS_SPLITBUTTON e BS_DEFSPLITBUTTON no [estilos de botão](/windows/desktop/Controls/button-styles).

A figura abaixo mostra uma caixa de diálogo que contém um controle de paginação e um controle de botão de divisão (1). A seta suspensa (2) já foi clicado e o submenu (3) é exibida.

![Caixa de diálogo com um controle splitbutton e pager. ](../../mfc/reference/media/splitbutton_pager.png "Caixa de diálogo com um controle splitbutton e pager.")

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[CObject](../../mfc/reference/cobject-class.md)

[CCmdTarget](../../mfc/reference/ccmdtarget-class.md)

[CWnd](../../mfc/reference/cwnd-class.md)

[CButton](../../mfc/reference/cbutton-class.md)

`CSplitButton`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxcmn. h

Essa classe tem suporte no Windows Vista e posterior.

Requisitos adicionais para esta classe são descritos em [compilar requisitos para o Windows Vista controles comuns](../../mfc/build-requirements-for-windows-vista-common-controls.md).

##  <a name="create"></a>  CSplitButton::Create

Cria um controle de botão de divisão com estilos especificados e a anexa ao atual `CSplitButton` objeto.

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
|*dwStyle*|[in] Uma combinação bit a bit (OR) de estilos a serem aplicados ao controle. Para obter mais informações, consulte [estilos de botão](../../mfc/reference/styles-used-by-mfc.md#button-styles).|
|*rect*|[in] Uma referência a um [RECT](https://msdn.microsoft.com/library/windows/desktop/dd162897) estrutura que contém a posição e o tamanho do controle.|
|*pParentWnd*|[in] Um ponteiro não nulo para um [CWnd](../../mfc/reference/cwnd-class.md) objeto que é a janela pai do controle.|
|*nID*|[in] A ID do controle.|

### <a name="return-value"></a>Valor de retorno

TRUE se esse método for bem-sucedida; Caso contrário, FALSE.

##  <a name="csplitbutton"></a>  CSplitButton::CSplitButton

Constrói um objeto `CSplitButton`. Os parâmetros do construtor especificam um submenu que é exibido quando um usuário clica na seta suspensa do controle de botão de divisão.

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
|*nMenuId*|[in] A ID de recurso da barra de menus.|
|*nSubMenuId*|[in] A ID de recurso de um submenu.|
|*pMenu*|[in] Um ponteiro para um [CMenu](../../mfc/reference/cmenu-class.md) objeto que especifica um submenu. O `CSplitButton` exclusões de objeto de `CMenu` objeto e seu HMENU associado quando o `CSplitButton` objeto sai do escopo.|

### <a name="remarks"></a>Comentários

Use o [CSplitButton::Create](#create) método para criar um controle de botão de divisão e anexá-lo para o `CSplitButton` objeto.

##  <a name="ondropdown"></a>  CSplitButton::OnDropDown

Lida com a notificação BCN_DROPDOWN que o sistema envia quando um usuário clica na seta suspensa do controle de botão de divisão atual.

```
afx_msg void OnDropDown(
    NMHDR* pNMHDR,
    LRESULT* pResult);
```

### <a name="parameters"></a>Parâmetros

|Parâmetro|Descrição|
|---------------|-----------------|
|*pNMHDR*|[in] Ponteiro para um [NMHDR](/windows/desktop/api/richedit/ns-richedit-_nmhdr) estrutura que contém informações sobre o [BCN_DROPDOWN](/windows/desktop/Controls/bcn-dropdown) notificação.|
|*pResult*|[out] (Não usado; nenhum valor será retornado). Retornar o valor de [BCN_DROPDOWN](/windows/desktop/Controls/bcn-dropdown) notificação.|

### <a name="remarks"></a>Comentários

Quando o usuário clica na seta suspensa em um controle de botão de divisão, o sistema envia uma notificação BCN_DROPDOWN da mensagem, que o `OnDropDown` identificadores de método. No entanto, o `CSplitButton` objeto não encaminha a notificação BCN_DROPDOWN para o controle que contém o controle de botão de divisão. Consequentemente, contendo o controle não pode dar suporte a uma ação personalizada em resposta à notificação.

Para implementar uma ação personalizada que dá suporte ao controle que o contém, use uma [CButton](../../mfc/reference/cbutton-class.md) objeto com o estilo BS_SPLITBUTTON em vez de um `CSplitButton` objeto. Em seguida, implemente um manipulador para a notificação BCN_DROPDOWN no `CButton` objeto. Para obter mais informações, consulte [estilos de botão](../../mfc/reference/styles-used-by-mfc.md#button-styles).

Para implementar uma ação personalizada que o botão de divisão de controle em si dá suporte, use [reflexão de mensagem](../../mfc/tn062-message-reflection-for-windows-controls.md). Derivar sua própria classe a partir de `CSplitButton` classe e nomeie-o, por exemplo, CMySplitButton. Em seguida, adicione o mapa de mensagem a seguir ao seu aplicativo para manipular a notificação BCN_DROPDOWN:

```
BEGIN_MESSAGE_MAP(CMySplitButton,
    CSplitButton)
    ON_NOTIFY_REFLECT(BCN_DROPDOWN, &CMySplitButton::OnDropDown)
END_MESSAGE_MAP()
```

##  <a name="setdropdownmenu"></a>  CSplitButton::SetDropDownMenu

Define o menu suspenso que é exibido quando um usuário clica na seta suspensa do controle de botão de divisão atual.

```
void SetDropDownMenu(
    UINT nMenuId,
    UINT nSubMenuId);

void SetDropDownMenu(CMenu* pMenu);
```

### <a name="parameters"></a>Parâmetros

|Parâmetro|Descrição|
|---------------|-----------------|
|*nMenuId*|[in] A ID de recurso da barra de menus.|
|*nSubMenuId*|[in] A ID de recurso de um submenu.|
|*pMenu*|[in] Ponteiro para um [CMenu](../../mfc/reference/cmenu-class.md) objeto que especifica um submenu. O `CSplitButton` exclusões de objeto de `CMenu` objeto e seu HMENU associado quando o `CSplitButton` objeto sai do escopo.|

### <a name="remarks"></a>Comentários

O *nMenuId* parâmetro identifica uma barra de menus, que é uma lista de itens da barra de menu horizontal. O *nSubMenuId* parâmetro é um número de índice baseado em zero que identifica um submenu, que é a lista suspensa de itens de menu associado com cada item da barra de menu. Por exemplo, um aplicativo típico tem um menu que contém os itens de barra de menu, "Arquivo", "Editar" e "Help". O item de barra de menu "Arquivo" tem um submenu que contém os itens de menu "Abrir", "Fechar" e "Exit". Quando a seta suspensa do controle de botão de divisão é clicada, o controle exibe o submenu especificado, não a barra de menus.

A figura abaixo mostra uma caixa de diálogo que contém um controle de paginação e um controle de botão de divisão (1). A seta suspensa (2) já foi clicado e o submenu (3) é exibida.

![Caixa de diálogo com um controle splitbutton e pager. ](../../mfc/reference/media/splitbutton_pager.png "Caixa de diálogo com um controle splitbutton e pager.")

### <a name="example"></a>Exemplo

A primeira instrução no exemplo de código a seguir demonstra a [CSplitButton::SetDropDownMenu](#setdropdownmenu) método. Nós criamos o menu com o recurso do Visual Studio editor, que é chamado automaticamente a ID da barra de menus, IDR_MENU1. O *nSubMenuId* parâmetro, que é zero, refere-se para o submenu somente da barra de menus.

[!code-cpp[NVC_MFC_CSplitButton_s2#1](../../mfc/reference/codesnippet/cpp/csplitbutton-class_1.cpp)]

## <a name="see-also"></a>Consulte também

[Classe CSplitButton](../../mfc/reference/csplitbutton-class.md)<br/>
[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classe CButton](../../mfc/reference/cbutton-class.md)
