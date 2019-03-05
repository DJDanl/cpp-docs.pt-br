---
title: Classe CCmdUI
ms.date: 11/04/2016
f1_keywords:
- CCmdUI
- AFXWIN/CCmdUI
- AFXWIN/CCmdUI::ContinueRouting
- AFXWIN/CCmdUI::Enable
- AFXWIN/CCmdUI::SetCheck
- AFXWIN/CCmdUI::SetRadio
- AFXWIN/CCmdUI::SetText
- AFXWIN/CCmdUI::m_nID
- AFXWIN/CCmdUI::m_nIndex
- AFXWIN/CCmdUI::m_pMenu
- AFXWIN/CCmdUI::m_pOther
- AFXWIN/CCmdUI::m_pSubMenu
helpviewer_keywords:
- CCmdUI [MFC], ContinueRouting
- CCmdUI [MFC], Enable
- CCmdUI [MFC], SetCheck
- CCmdUI [MFC], SetRadio
- CCmdUI [MFC], SetText
- CCmdUI [MFC], m_nID
- CCmdUI [MFC], m_nIndex
- CCmdUI [MFC], m_pMenu
- CCmdUI [MFC], m_pOther
- CCmdUI [MFC], m_pSubMenu
ms.assetid: 04eaaaf5-f510-48ab-b425-94665ba24766
ms.openlocfilehash: 12d9ead736a84d89b04f7b68ed76da8ccea22d0c
ms.sourcegitcommit: c3093251193944840e3d0a068ecc30e6449624ba
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/04/2019
ms.locfileid: "57302865"
---
# <a name="ccmdui-class"></a>Classe CCmdUI

É usado somente em um `ON_UPDATE_COMMAND_UI` manipulador em um `CCmdTarget`-classe derivada.

## <a name="syntax"></a>Sintaxe

```
class CCmdUI
```

## <a name="members"></a>Membros

### <a name="public-methods"></a>Métodos Públicos

|Nome|Descrição|
|----------|-----------------|
|[CCmdUI::ContinueRouting](#continuerouting)|Informa ao mecanismo de roteamento de comando para continua a rotear a mensagem atual a cadeia de manipuladores.|
|[CCmdUI::Enable](#enable)|Habilita ou desabilita o item de interface do usuário para esse comando.|
|[CCmdUI::SetCheck](#setcheck)|Define o estado de seleção do item de interface do usuário para esse comando.|
|[CCmdUI::SetRadio](#setradio)|Como o `SetCheck` função de membro, mas opera em grupos de rádio.|
|[CCmdUI::SetText](#settext)|Define o texto do item de interface do usuário para esse comando.|

### <a name="public-data-members"></a>Membros de Dados Públicos

|Nome|Descrição|
|----------|-----------------|
|[CCmdUI::m_nID](#m_nid)|A ID do objeto de interface do usuário.|
|[CCmdUI::m_nIndex](#m_nindex)|O índice do objeto de interface do usuário.|
|[CCmdUI::m_pMenu](#m_pmenu)|Aponta para o menu representado pelo `CCmdUI` objeto.|
|[CCmdUI::m_pOther](#m_pother)|Aponta para o objeto de janela que enviou a notificação.|
|[CCmdUI::m_pSubMenu](#m_psubmenu)|Aponta para o submenu independente representado pelo `CCmdUI` objeto.|

## <a name="remarks"></a>Comentários

`CCmdUI` não tem uma classe base.

Quando um usuário de seu aplicativo puxa um menu, cada item de menu precisa saber se ele deve ser exibido como habilitado ou desabilitado. O destino de um comando de menu fornece essas informações com a implementação de um manipulador de ON_UPDATE_COMMAND_UI. Para cada um dos objetos de interface do usuário do comando em seu aplicativo, use a janela Propriedades para criar um protótipo de entrada e a função de mapa de mensagem para cada manipulador.

Quando o menu é puxado para baixo, o framework pesquisa e chama cada manipulador ON_UPDATE_COMMAND_UI, as chamadas de cada manipulador `CCmdUI` funções de membro, como `Enable` e `Check`, e a estrutura adequadamente exibe cada item de menu.

Um item de menu pode ser substituído por um botão da barra de controle ou outro objeto de interface do usuário do comando sem alterar o código dentro de `ON_UPDATE_COMMAND_UI` manipulador.

A tabela a seguir resume o efeito `CCmdUI`de funções de membro têm nos diversos itens de interface do usuário do comando.

|Item de Interface do usuário|Habilitar|SetCheck|SetRadio|SetText|
|--------------------------|------------|--------------|--------------|-------------|
|Item de menu|Habilita ou desabilita|Marca ou desmarca|Usando um ponto de verificações|Texto de item de conjuntos|
|Botão de barra de ferramentas|Habilita ou desabilita|Seleciona e desmarca, ou deixar indeterminada|Mesmo que `SetCheck`|(Não aplicável)|
|Painel da barra de status|Torna o texto visível ou invisível|Borda de pop-out ou normal de conjuntos|Mesmo que `SetCheck`|Define o texto do painel|
|Botão normal em `CDialogBar`|Habilita ou desabilita|Marca ou desmarca a caixa de seleção|Mesmo que `SetCheck`|Conjuntos de texto de botão|
|Controle normal em `CDialogBar`|Habilita ou desabilita|(Não aplicável)|(Não aplicável)|Define o texto da janela|

Para obter mais informações sobre o uso dessa classe, consulte [como objetos de atualização de Interface do usuário](../../mfc/how-to-update-user-interface-objects.md).

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`CCmdUI`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxwin. h

##  <a name="continuerouting"></a>  CCmdUI::ContinueRouting

Chame essa função de membro para informar o mecanismo de roteamento de comando continua a rotear a mensagem atual a cadeia de manipuladores.

```
void ContinueRouting();
```

### <a name="remarks"></a>Comentários

Essa é uma função de membro avançado que deve ser usada em conjunto com um manipulador de ON_COMMAND_EX que retorna FALSE. Para obter mais informações, consulte [6 de observação técnica](../../mfc/tn006-message-maps.md).

##  <a name="enable"></a>  CCmdUI::Enable

Chame essa função de membro para habilitar ou desabilitar o item de interface do usuário para esse comando.

```
virtual void Enable(BOOL bOn = TRUE);
```

### <a name="parameters"></a>Parâmetros

*bOn*<br/>
True para habilitar o item, FALSE para desabilitá-lo.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCDocView#46](../../mfc/codesnippet/cpp/ccmdui-class_1.cpp)]

[!code-cpp[NVC_MFCDocView#47](../../mfc/codesnippet/cpp/ccmdui-class_2.cpp)]

##  <a name="m_nid"></a>  CCmdUI::m_nID

A ID do item de menu, botão de barra de ferramentas ou outro objeto de interface do usuário representado pelo `CCmdUI` objeto.

```
UINT m_nID;
```

##  <a name="m_nindex"></a>  CCmdUI::m_nIndex

O índice do item de menu, botão de barra de ferramentas ou outro objeto de interface do usuário representado pelo `CCmdUI` objeto.

```
UINT m_nIndex;
```

##  <a name="m_pmenu"></a>  CCmdUI::m_pMenu

Ponteiro (de `CMenu` tipo) para o menu representado pelo `CCmdUI` objeto.

```
CMenu* m_pMenu;
```

### <a name="remarks"></a>Comentários

NULL se o item não é um menu.

##  <a name="m_psubmenu"></a>  CCmdUI::m_pSubMenu

Ponteiro (de `CMenu` tipo) para o submenu independente representado pelo `CCmdUI` objeto.

```
CMenu* m_pSubMenu;
```

### <a name="remarks"></a>Comentários

NULL se o item não é um menu. Se o submenu é um pop-up *m_nID* contém a ID do primeiro item no menu pop-up. Para obter mais informações, consulte [21 de observação técnica](../../mfc/tn021-command-and-message-routing.md).

##  <a name="m_pother"></a>  CCmdUI::m_pOther

Ponteiro (do tipo `CWnd`) para o objeto de janela, como uma barra de status ou ferramenta que enviou a notificação.

```
CWnd* m_pOther;
```

### <a name="remarks"></a>Comentários

NULL se o item for um menu ou um não - `CWnd` objeto.

##  <a name="setcheck"></a>  CCmdUI::SetCheck

Chame essa função de membro para definir o item de interface do usuário para esse comando para o estado de seleção apropriadas.

```
virtual void SetCheck(int nCheck = 1);
```

### <a name="parameters"></a>Parâmetros

*nCheck*<br/>
Especifica o estado de seleção para definir. Se 0, desmarca; Se 1, verifica; e se for 2, define indeterminado.

### <a name="remarks"></a>Comentários

Essa função de membro funciona em itens de menu e botões da barra de ferramentas. O estado indeterminado se aplica somente aos botões de barra de ferramentas.

##  <a name="setradio"></a>  CCmdUI::SetRadio

Chame essa função de membro para definir o item de interface do usuário para esse comando para o estado de seleção apropriadas.

```
virtual void SetRadio(BOOL bOn = TRUE);
```

### <a name="parameters"></a>Parâmetros

*bOn*<br/>
TRUE para habilitar o item; Caso contrário, FALSE.

### <a name="remarks"></a>Comentários

Essa função de membro opera como `SetCheck`, exceto que ele opera em itens de interface do usuário, atuando como parte de um grupo de opção. Desmarcar os outros itens no grupo não é automática, a menos que os próprios itens mantêm o comportamento do grupo de opção.

##  <a name="settext"></a>  CCmdUI::SetText

Chame essa função de membro para definir o texto do item de interface do usuário para esse comando.

```
virtual void SetText(LPCTSTR lpszText);
```

### <a name="parameters"></a>Parâmetros

*lpszText*<br/>
Um ponteiro para uma cadeia de caracteres de texto.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCDocView#48](../../mfc/codesnippet/cpp/ccmdui-class_3.cpp)]

## <a name="see-also"></a>Consulte também

[Exemplo MFC MDI](../../visual-cpp-samples.md)<br/>
[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classe CCmdTarget](../../mfc/reference/ccmdtarget-class.md)
