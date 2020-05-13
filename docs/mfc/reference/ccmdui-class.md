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
ms.openlocfilehash: 3e167d9e305481e05808f5e553222c10abbc88de
ms.sourcegitcommit: 7a6116e48c3c11b97371b8ae4ecc23adce1f092d
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/22/2020
ms.locfileid: "81752734"
---
# <a name="ccmdui-class"></a>Classe CCmdUI

É usado apenas `ON_UPDATE_COMMAND_UI` dentro `CCmdTarget`de um manipulador em uma classe derivada.

## <a name="syntax"></a>Sintaxe

```
class CCmdUI
```

## <a name="members"></a>Membros

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CCmdUI::Continuarde](#continuerouting)|Diz ao mecanismo de roteamento de comando para continuar encaminhando a mensagem atual para baixo da cadeia de manipuladores.|
|[CCmdUI::Ativar](#enable)|Ativa ou desativa o item de interface do usuário para este comando.|
|[CCmdUI::SetCheck](#setcheck)|Define o estado de verificação do item de interface do usuário para este comando.|
|[CCmdUI::SetRadio](#setradio)|Como `SetCheck` a função de membro, mas opera em grupos de rádio.|
|[CCmdUI::SetText](#settext)|Define o texto para o item de interface do usuário para este comando.|

### <a name="public-data-members"></a>Membros de Dados Públicos

|Nome|Descrição|
|----------|-----------------|
|[CCmdUI::m_nID](#m_nid)|O ID do objeto de interface de usuário.|
|[CCmdUI::m_nIndex](#m_nindex)|O índice do objeto de interface de usuário.|
|[CCmdUI::m_pMenu](#m_pmenu)|Aponta para o menu `CCmdUI` representado pelo objeto.|
|[CCmdUI::m_pOther](#m_pother)|Aponta para o objeto da janela que enviou a notificação.|
|[CCmdUI::m_pSubMenu](#m_psubmenu)|Aponta para o submenu contido `CCmdUI` representado pelo objeto.|

## <a name="remarks"></a>Comentários

`CCmdUI`não tem uma classe base.

Quando um usuário do seu aplicativo puxa um menu, cada item do menu precisa saber se ele deve ser exibido como ativado ou desativado. O alvo de um comando de menu fornece essas informações implementando um manipulador de ON_UPDATE_COMMAND_UI. Para cada um dos objetos de interface de usuário de comando em seu aplicativo, use a janela [Assistente de classe](mfc-class-wizard.md) ou **propriedades** (em **Exibição de**classe) para criar um protótipo de entrada e função de mapa de mensagem para cada manipulador.

Quando o menu é puxado para baixo, a estrutura procura `CCmdUI` e chama `Enable` cada `Check`manipulador de ON_UPDATE_COMMAND_UI, cada manipulador chama funções do membro, como e , e a estrutura, em seguida, exibe adequadamente cada item do menu.

Um item do menu pode ser substituído por um botão de barra de `ON_UPDATE_COMMAND_UI` controle ou outro objeto de interface de usuário de comando sem alterar o código dentro do manipulador.

A tabela a seguir `CCmdUI`resume o efeito que as funções de membro têm em vários itens de interface de usuário de comando.

|Item de interface do usuário|Habilitar|Setcheck|SetRadio|Settext|
|--------------------------|------------|--------------|--------------|-------------|
|Item de menu|Habilita ou desativa|Verificações ou desverificações|Verifica usando um pontilhado|Define texto do item|
|Botão da barra de ferramentas|Habilita ou desativa|Seleciona, desmarca ou indeterminado|O mesmo que `SetCheck`|(Não aplicável)|
|Painel de barras de status|Torna o texto visível ou invisível|Define pop-out ou fronteira normal|O mesmo que `SetCheck`|Define texto de painel|
|Botão normal em`CDialogBar`|Habilita ou desativa|Verifica ou desverifica caixa de seleção|O mesmo que `SetCheck`|Define texto do botão|
|Controle normal em`CDialogBar`|Habilita ou desativa|(Não aplicável)|(Não aplicável)|Define texto da janela|

Para obter mais informações sobre o uso desta classe, consulte [Como atualizar objetos de interface de usuário](../../mfc/how-to-update-user-interface-objects.md).

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`CCmdUI`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxwin.h

## <a name="ccmduicontinuerouting"></a><a name="continuerouting"></a>CCmdUI::Continuarde

Ligue para esta função de membro para dizer ao mecanismo de roteamento de comando para continuar roteando a mensagem atual pela cadeia de manipuladores.

```cpp
void ContinueRouting();
```

### <a name="remarks"></a>Comentários

Esta é uma função de membro avançado que deve ser usada em conjunto com um manipulador de ON_COMMAND_EX que retorna FALSE. Para obter mais informações, consulte [Nota Técnica 6](../../mfc/tn006-message-maps.md).

## <a name="ccmduienable"></a><a name="enable"></a>CCmdUI::Ativar

Chame esta função de membro para ativar ou desativar o item de interface do usuário para este comando.

```
virtual void Enable(BOOL bOn = TRUE);
```

### <a name="parameters"></a>Parâmetros

*Bon*<br/>
TRUE para habilitar o item, FALSE para desativá-lo.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCDocView#46](../../mfc/codesnippet/cpp/ccmdui-class_1.cpp)]

[!code-cpp[NVC_MFCDocView#47](../../mfc/codesnippet/cpp/ccmdui-class_2.cpp)]

## <a name="ccmduim_nid"></a><a name="m_nid"></a>CCmdUI::m_nID

O ID do item do menu, o botão da barra `CCmdUI` de ferramentas ou outro objeto de interface do usuário representado pelo objeto.

```
UINT m_nID;
```

## <a name="ccmduim_nindex"></a><a name="m_nindex"></a>CCmdUI::m_nIndex

O índice do item do menu, do botão da barra `CCmdUI` de ferramentas ou de outro objeto de interface de usuário representado pelo objeto.

```
UINT m_nIndex;
```

## <a name="ccmduim_pmenu"></a><a name="m_pmenu"></a>CCmdUI::m_pMenu

Ponteiro (de `CMenu` tipo) para o `CCmdUI` menu representado pelo objeto.

```
CMenu* m_pMenu;
```

### <a name="remarks"></a>Comentários

NULL se o item não for um menu.

## <a name="ccmduim_psubmenu"></a><a name="m_psubmenu"></a>CCmdUI::m_pSubMenu

Ponteiro (de `CMenu` tipo) para o submenu `CCmdUI` contido representado pelo objeto.

```
CMenu* m_pSubMenu;
```

### <a name="remarks"></a>Comentários

NULL se o item não for um menu. Se o menu sub for um pop-up, *m_nID* contém o ID do primeiro item no menu pop-up. Para obter mais informações, consulte [nota técnica 21](../../mfc/tn021-command-and-message-routing.md).

## <a name="ccmduim_pother"></a><a name="m_pother"></a>CCmdUI::m_pOther

Ponteiro (do `CWnd`tipo ) para o objeto da janela, como uma ferramenta ou barra de status, que enviou a notificação.

```
CWnd* m_pOther;
```

### <a name="remarks"></a>Comentários

NULL se o item for um `CWnd` menu ou um não-objeto.

## <a name="ccmduisetcheck"></a><a name="setcheck"></a>CCmdUI::SetCheck

Ligue para esta função de membro para definir o item de interface do usuário para este comando para o estado de verificação apropriado.

```
virtual void SetCheck(int nCheck = 1);
```

### <a name="parameters"></a>Parâmetros

*Ncheck*<br/>
Especifica o estado de verificação a ser definido. Se 0, descheca; se 1, verifica; e se 2, define indeterminado.

### <a name="remarks"></a>Comentários

Esta função de membro funciona para itens de menu e botões de barra de ferramentas. O estado indeterminado aplica-se apenas aos botões da barra de ferramentas.

## <a name="ccmduisetradio"></a><a name="setradio"></a>CCmdUI::SetRadio

Ligue para esta função de membro para definir o item de interface do usuário para este comando para o estado de verificação apropriado.

```
virtual void SetRadio(BOOL bOn = TRUE);
```

### <a name="parameters"></a>Parâmetros

*Bon*<br/>
TRUE para habilitar o item; caso contrário, FALSO.

### <a name="remarks"></a>Comentários

Esta função de `SetCheck`membro funciona como , exceto que opera em itens de interface de usuário agindo como parte de um grupo de rádio. A desverificação dos outros itens do grupo não é automática, a menos que os próprios itens mantenham o comportamento do grupo de rádio.

## <a name="ccmduisettext"></a><a name="settext"></a>CCmdUI::SetText

Chame esta função de membro para definir o texto do item de interface do usuário para este comando.

```
virtual void SetText(LPCTSTR lpszText);
```

### <a name="parameters"></a>Parâmetros

*lpszText*<br/>
Um ponteiro para uma seqüência de texto.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCDocView#48](../../mfc/codesnippet/cpp/ccmdui-class_3.cpp)]

## <a name="see-also"></a>Confira também

[MDI amostra MFC](../../overview/visual-cpp-samples.md)<br/>
[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classe CCmdTarget](../../mfc/reference/ccmdtarget-class.md)
