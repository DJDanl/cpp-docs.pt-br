---
title: Classe CCmdUI
ms.date: 09/06/2019
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
ms.openlocfilehash: 42aec2937cd81ebbb50482321b8deae001723d3a
ms.sourcegitcommit: 3caf5261b3ea80d9cf14038c116ba981d655cd13
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/11/2019
ms.locfileid: "70907834"
---
# <a name="ccmdui-class"></a>Classe CCmdUI

É usado somente dentro de `ON_UPDATE_COMMAND_UI` um manipulador em `CCmdTarget`uma classe derivada.

## <a name="syntax"></a>Sintaxe

```
class CCmdUI
```

## <a name="members"></a>Membros

### <a name="public-methods"></a>Métodos Públicos

|Nome|Descrição|
|----------|-----------------|
|[CCmdUI::ContinueRouting](#continuerouting)|Informa ao mecanismo de roteamento de comandos para continuar a rotear a mensagem atual para baixo na cadeia de manipuladores.|
|[CCmdUI::Enable](#enable)|Habilita ou desabilita o item de interface do usuário para este comando.|
|[CCmdUI::SetCheck](#setcheck)|Define o estado de verificação do item de interface do usuário para este comando.|
|[CCmdUI::SetRadio](#setradio)|Como a `SetCheck` função membro, mas opera em grupos de rádio.|
|[CCmdUI::SetText](#settext)|Define o texto para o item de interface do usuário para este comando.|

### <a name="public-data-members"></a>Membros de Dados Públicos

|Nome|Descrição|
|----------|-----------------|
|[CCmdUI::m_nID](#m_nid)|A ID do objeto de interface do usuário.|
|[CCmdUI::m_nIndex](#m_nindex)|O índice do objeto de interface do usuário.|
|[CCmdUI::m_pMenu](#m_pmenu)|Aponta para o menu representado pelo `CCmdUI` objeto.|
|[CCmdUI::m_pOther](#m_pother)|Aponta para o objeto de janela que enviou a notificação.|
|[CCmdUI::m_pSubMenu](#m_psubmenu)|Aponta para o submenu contido representado pelo `CCmdUI` objeto.|

## <a name="remarks"></a>Comentários

`CCmdUI`Não tem uma classe base.

Quando um usuário do seu aplicativo extrai um menu, cada item de menu precisa saber se ele deve ser exibido como habilitado ou desabilitado. O destino de um comando de menu fornece essas informações implementando um manipulador ON_UPDATE_COMMAND_UI. Para cada um dos objetos de interface de usuário de comando em seu aplicativo, use o [Assistente de classe](mfc-class-wizard.md) ou a janela **propriedades** (em **modo de exibição de classe**) para criar uma entrada de mapa de mensagem e um protótipo de função para cada manipulador.

Quando o menu é puxado, a estrutura procura e chama cada manipulador ON_UPDATE_COMMAND_UI, cada manipulador chama `CCmdUI` funções de `Enable` membro como e `Check`, e o Framework, em seguida, exibe adequadamente cada item de menu.

Um item de menu pode ser substituído por um botão de barra de controle ou outro objeto de interface de usuário de comando sem alterar `ON_UPDATE_COMMAND_UI` o código dentro do manipulador.

A tabela a seguir resume as funções `CCmdUI`de membro do efeito em vários itens de interface de usuário de comando.

|Item de interface do usuário|Habilitar|SetCheck|SetRadio|SetText|
|--------------------------|------------|--------------|--------------|-------------|
|Item de menu|Habilita ou desabilita|Verificações ou desmarcações|Verificações usando um ponto|Define o texto do item|
|Botão da barra de ferramentas|Habilita ou desabilita|Seleciona, desmarca ou indeterminado|Mesmo que `SetCheck`|(Não aplicável)|
|Painel de status-barra|Torna o texto visível ou invisível|Define pop-out ou borda normal|Mesmo que `SetCheck`|Define o texto do painel|
|Botão normal em`CDialogBar`|Habilita ou desabilita|Caixa de seleção marcações ou desmarcações|Mesmo que `SetCheck`|Define o texto do botão|
|Controle normal em`CDialogBar`|Habilita ou desabilita|(Não aplicável)|(Não aplicável)|Define o texto da janela|

Para obter mais informações sobre o uso dessa classe, consulte [como atualizar objetos da interface do usuário](../../mfc/how-to-update-user-interface-objects.md).

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`CCmdUI`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** Afxwin. h

##  <a name="continuerouting"></a>  CCmdUI::ContinueRouting

Chame essa função de membro para dizer ao mecanismo de roteamento de comandos para continuar a rotear a mensagem atual para baixo na cadeia de manipuladores.

```
void ContinueRouting();
```

### <a name="remarks"></a>Comentários

Essa é uma função de membro avançada que deve ser usada em conjunto com um manipulador ON_COMMAND_EX que retorna FALSE. Para obter mais informações, consulte a [Nota técnica 6](../../mfc/tn006-message-maps.md).

##  <a name="enable"></a>  CCmdUI::Enable

Chame essa função de membro para habilitar ou desabilitar o item de interface de usuário para este comando.

```
virtual void Enable(BOOL bOn = TRUE);
```

### <a name="parameters"></a>Parâmetros

*bOn*<br/>
TRUE para habilitar o item, FALSE para desabilitá-lo.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCDocView#46](../../mfc/codesnippet/cpp/ccmdui-class_1.cpp)]

[!code-cpp[NVC_MFCDocView#47](../../mfc/codesnippet/cpp/ccmdui-class_2.cpp)]

##  <a name="m_nid"></a>  CCmdUI::m_nID

A ID do item de menu, o botão da barra de ferramentas ou outro objeto de interface de `CCmdUI` usuário representado pelo objeto.

```
UINT m_nID;
```

##  <a name="m_nindex"></a>  CCmdUI::m_nIndex

O índice do item de menu, botão da barra de ferramentas ou outro objeto de interface de usuário `CCmdUI` representado pelo objeto.

```
UINT m_nIndex;
```

##  <a name="m_pmenu"></a>  CCmdUI::m_pMenu

Ponteiro (do `CMenu` tipo) para o menu representado `CCmdUI` pelo objeto.

```
CMenu* m_pMenu;
```

### <a name="remarks"></a>Comentários

NULL se o item não for um menu.

##  <a name="m_psubmenu"></a>  CCmdUI::m_pSubMenu

Ponteiro (do `CMenu` tipo) para o submenu contido representado `CCmdUI` pelo objeto.

```
CMenu* m_pSubMenu;
```

### <a name="remarks"></a>Comentários

NULL se o item não for um menu. Se o submenu for um pop-up, *m_nID* conterá a ID do primeiro item no menu pop-up. Para obter mais informações, consulte a [Nota técnica 21](../../mfc/tn021-command-and-message-routing.md).

##  <a name="m_pother"></a>  CCmdUI::m_pOther

Ponteiro (do tipo `CWnd`) para o objeto Window, como uma ferramenta ou barra de status, que enviou a notificação.

```
CWnd* m_pOther;
```

### <a name="remarks"></a>Comentários

NULL se o item for um menu ou um não `CWnd` objeto.

##  <a name="setcheck"></a>  CCmdUI::SetCheck

Chame essa função de membro para definir o item de interface de usuário para esse comando para o estado de verificação apropriado.

```
virtual void SetCheck(int nCheck = 1);
```

### <a name="parameters"></a>Parâmetros

*nVerifique*<br/>
Especifica o estado de verificação a ser definido. Se 0, desmarcar; Se for 1, verificará; e se 2, conjuntos indeterminados.

### <a name="remarks"></a>Comentários

Essa função de membro funciona para itens de menu e botões da barra de ferramentas. O estado indeterminado só se aplica a botões da barra de ferramentas.

##  <a name="setradio"></a>  CCmdUI::SetRadio

Chame essa função de membro para definir o item de interface de usuário para esse comando para o estado de verificação apropriado.

```
virtual void SetRadio(BOOL bOn = TRUE);
```

### <a name="parameters"></a>Parâmetros

*bOn*<br/>
TRUE para habilitar o item; caso contrário, FALSE.

### <a name="remarks"></a>Comentários

Essa função de membro funciona `SetCheck`como, exceto que ela opera em itens de interface do usuário que atuam como parte de um grupo de rádio. Desmarcar os outros itens no grupo não é automático, a menos que os próprios itens mantenham o comportamento do grupo de rádio.

##  <a name="settext"></a>  CCmdUI::SetText

Chame essa função de membro para definir o texto do item de interface de usuário para este comando.

```
virtual void SetText(LPCTSTR lpszText);
```

### <a name="parameters"></a>Parâmetros

*lpszText*<br/>
Um ponteiro para uma cadeia de texto.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCDocView#48](../../mfc/codesnippet/cpp/ccmdui-class_3.cpp)]

## <a name="see-also"></a>Consulte também

[MDI de exemplo do MFC](../../overview/visual-cpp-samples.md)<br/>
[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classe CCmdTarget](../../mfc/reference/ccmdtarget-class.md)
