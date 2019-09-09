---
title: Classe CHotKeyCtrl
ms.date: 11/04/2016
f1_keywords:
- CHotKeyCtrl
- AFXCMN/CHotKeyCtrl
- AFXCMN/CHotKeyCtrl::CHotKeyCtrl
- AFXCMN/CHotKeyCtrl::Create
- AFXCMN/CHotKeyCtrl::CreateEx
- AFXCMN/CHotKeyCtrl::GetHotKey
- AFXCMN/CHotKeyCtrl::GetHotKeyName
- AFXCMN/CHotKeyCtrl::GetKeyName
- AFXCMN/CHotKeyCtrl::SetHotKey
- AFXCMN/CHotKeyCtrl::SetRules
helpviewer_keywords:
- CHotKeyCtrl [MFC], CHotKeyCtrl
- CHotKeyCtrl [MFC], Create
- CHotKeyCtrl [MFC], CreateEx
- CHotKeyCtrl [MFC], GetHotKey
- CHotKeyCtrl [MFC], GetHotKeyName
- CHotKeyCtrl [MFC], GetKeyName
- CHotKeyCtrl [MFC], SetHotKey
- CHotKeyCtrl [MFC], SetRules
ms.assetid: 896f9766-0718-4f58-aab2-20325e118ca6
ms.openlocfilehash: 9818c32a7779d646ca5a9485a1331dfa393408ba
ms.sourcegitcommit: fcb48824f9ca24b1f8bd37d647a4d592de1cc925
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/15/2019
ms.locfileid: "69506155"
---
# <a name="chotkeyctrl-class"></a>Classe CHotKeyCtrl

Fornece a funcionalidade do controle de chave de acesso comum do Windows.

## <a name="syntax"></a>Sintaxe

```
class CHotKeyCtrl : public CWnd
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[CHotKeyCtrl::CHotKeyCtrl](#chotkeyctrl)|Constrói um objeto `CHotKeyCtrl`.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CHotKeyCtrl::Create](#create)|Cria um controle de tecla quente e o anexa a um `CHotKeyCtrl` objeto.|
|[CHotKeyCtrl::CreateEx](#createex)|Cria um controle de teclas de acesso com os estilos estendidos do Windows especificados e o `CHotKeyCtrl` anexa a um objeto.|
|[CHotKeyCtrl::GetHotKey](#gethotkey)|Recupera o código de chave virtual e os sinalizadores de modificador de uma tecla de atalho de um controle de tecla de atalho.|
|[CHotKeyCtrl::GetHotKeyName](#gethotkeyname)|Recupera o nome da chave, no conjunto de caracteres local, atribuído a uma tecla de acesso.|
|[CHotKeyCtrl::GetKeyName](#getkeyname)|Recupera o nome da chave, no conjunto de caracteres local, atribuído ao código de chave virtual especificado.|
|[CHotKeyCtrl::SetHotKey](#sethotkey)|Define a combinação de teclas de acesso para um controle de tecla quente.|
|[CHotKeyCtrl::SetRules](#setrules)|Define as combinações inválidas e a combinação de modificador padrão para um controle de tecla de acesso.|

## <a name="remarks"></a>Comentários

Um "controle de teclas de acesso" é uma janela que permite ao usuário criar uma tecla de atalho. Uma "tecla de atalho" é uma combinação de teclas que o usuário pode pressionar para executar uma ação rapidamente. (Por exemplo, um usuário pode criar uma tecla de atalho que ativa uma determinada janela e a leva para a parte superior da ordem Z.) O controle de teclas de acesso exibe as opções do usuário e garante que o usuário selecione uma combinação de teclas válida.

Esse controle (e, portanto `CHotKeyCtrl` , a classe) está disponível somente para programas em execução no Windows 95/98 e no Windows NT versão 3,51 e posterior.

Quando o usuário tiver escolhido uma combinação de teclas, o aplicativo poderá recuperar a combinação de chaves especificada do controle e usar a mensagem WM_SETHOTKEY para configurar a tecla de acesso no sistema. Sempre que o usuário pressionar a tecla de atalho posteriormente, de qualquer parte do sistema, a janela especificada na mensagem WM_SETHOTKEY receberá uma mensagem WM_SYSCOMMAND especificando SC_HOTKEY. Essa mensagem ativa a janela que a recebe. A tecla de acesso permanece válida até que o aplicativo que chamou WM_SETHOTKEY saia.

Esse mecanismo é diferente do suporte a teclas de acesso que depende da mensagem WM_HOTKEY e das funções [RegisterHotKey](/windows/win32/api/winuser/nf-winuser-registerhotkey) e [UnregisterHotKey](/windows/win32/api/winuser/nf-winuser-unregisterhotkey) do Windows.

Para obter mais informações sobre `CHotKeyCtrl`como usar o, consulte [controles](../../mfc/controls-mfc.md) e [usando CHotKeyCtrl](../../mfc/using-chotkeyctrl.md).

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[CObject](../../mfc/reference/cobject-class.md)

[CCmdTarget](../../mfc/reference/ccmdtarget-class.md)

[CWnd](../../mfc/reference/cwnd-class.md)

`CHotKeyCtrl`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxcmn. h

##  <a name="chotkeyctrl"></a>  CHotKeyCtrl::CHotKeyCtrl

Constrói um objeto `CHotKeyCtrl`.

```
CHotKeyCtrl();
```

##  <a name="create"></a>  CHotKeyCtrl::Create

Cria um controle de tecla quente e o anexa a um `CHotKeyCtrl` objeto.

```
virtual BOOL Create(
    DWORD dwStyle,
    const RECT& rect,
    CWnd* pParentWnd,
    UINT nID);
```

### <a name="parameters"></a>Parâmetros

*dwStyle*<br/>
Especifica o estilo do controle de tecla de atalho. Aplique qualquer combinação de estilos de controle. Consulte [estilos de controle comuns](/windows/win32/Controls/common-control-styles) na SDK do Windows para obter mais informações.

*rect*<br/>
Especifica o tamanho e a posição do controle de teclas de atalho. Pode ser um objeto [CRect](../../atl-mfc-shared/reference/crect-class.md) ou uma [estrutura RECT](/windows/win32/api/windef/ns-windef-rect).

*pParentWnd*<br/>
Especifica a janela pai do controle de teclas de atalho, geralmente um [CDialog](../../mfc/reference/cdialog-class.md). Ele não deve ser nulo.

*nID*<br/>
Especifica a ID do controle de tecla de atalho.

### <a name="return-value"></a>Valor de retorno

Diferente de zero, se a inicialização tiver sido bem-sucedida; caso contrário, 0.

### <a name="remarks"></a>Comentários

Você constrói um `CHotKeyCtrl` objeto em duas etapas. Primeiro, chame o construtor e, em `Create`seguida, chame, que cria o controle de tecla quente e o `CHotKeyCtrl` anexa ao objeto.

Se você quiser usar estilos estendidos do Windows com seu controle, chame [CreateEx](#createex) em `Create`vez de.

##  <a name="createex"></a>  CHotKeyCtrl::CreateEx

Chame essa função para criar um controle (uma janela filho) e associá-lo `CHotKeyCtrl` ao objeto.

```
virtual BOOL CreateEx(
    DWORD dwExStyle,
    DWORD dwStyle,
    const RECT& rect,
    CWnd* pParentWnd,
    UINT nID);
```

### <a name="parameters"></a>Parâmetros

*dwExStyle*<br/>
Especifica o estilo estendido do controle que está sendo criado. Para obter uma lista de estilos estendidos do Windows, consulte o parâmetro *dwExStyle* para [CreateWindowEx](/windows/win32/api/winuser/nf-winuser-createwindowexw) no SDK do Windows.

*dwStyle*<br/>
Especifica o estilo do controle de tecla de atalho. Aplique qualquer combinação de estilos de controle. Para obter mais informações, consulte [estilos comuns de controle](/windows/win32/Controls/common-control-styles) na SDK do Windows.

*rect*<br/>
Uma referência a uma estrutura [Rect](/previous-versions/dd162897\(v=vs.85\)) que descreve o tamanho e a posição da janela a ser criada, nas coordenadas de cliente de *pParentWnd*.

*pParentWnd*<br/>
Um ponteiro para a janela que é o pai do controle.

*nID*<br/>
A ID da janela filho do controle.

### <a name="return-value"></a>Valor de retorno

Diferente de zero, se for bem-sucedido; caso contrário, 0.

### <a name="remarks"></a>Comentários

Use `CreateEx` em vez de [Create](#create) para aplicar estilos estendidos do Windows, especificados pelo estilo estendido do Windows **WS_EX_** do prefácio.

##  <a name="gethotkey"></a>  CHotKeyCtrl::GetHotKey

Recupera o código de chave virtual e os sinalizadores de modificador de um atalho de teclado de um controle de tecla de acesso.

```
DWORD GetHotKey() const;

void GetHotKey(
    WORD& wVirtualKeyCode,
    WORD& wModifiers) const;
```

### <a name="parameters"></a>Parâmetros

*wVirtualKeyCode*<br/>
fora Código de chave virtual do atalho de teclado. Para obter uma lista de códigos de chave virtual padrão, consulte WinUser. h.

*wModifiers*<br/>
fora Uma combinação de bits (ou) de sinalizadores que indica as teclas modificadoras no atalho de teclado.

Os sinalizadores de modificador são os seguintes:

|Sinalizador|Chave correspondente|
|----------|-----------------------|
|HOTKEYF_ALT|tecla ALT|
|HOTKEYF_CONTROL|Tecla CTRL|
|HOTKEYF_EXT|Chave estendida|
|HOTKEYF_SHIFT|Tecla SHIFT|

### <a name="return-value"></a>Valor de retorno

No primeiro método sobrecarregado, um DWORD que contém o código de chave virtual e os sinalizadores de modificador. O byte de ordem inferior da palavra de ordem inferior contém o código de chave virtual, o byte de ordem superior da palavra de ordem inferior contém os sinalizadores de modificador e a palavra de ordem superior é zero.

### <a name="remarks"></a>Comentários

O código de chave virtual e as chaves modificadoras juntas definem o atalho de teclado.

##  <a name="gethotkeyname"></a>  CHotKeyCtrl::GetHotKeyName

Chame essa função de membro para obter o nome localizado da tecla de atalho.

```
CString GetHotKeyName() const;
```

### <a name="return-value"></a>Valor de retorno

O nome localizado da tecla de acesso selecionada no momento. Se não houver nenhuma tecla de acesso selecionada `GetHotKeyName` , retornará uma cadeia de caracteres vazia.

### <a name="remarks"></a>Comentários

O nome que essa função de membro retorna vem do driver de teclado. Você pode instalar um driver de teclado não localizado em uma versão localizada do Windows e vice-versa.

##  <a name="getkeyname"></a>  CHotKeyCtrl::GetKeyName

Chame essa função de membro para obter o nome localizado da chave atribuída a um código de chave virtual especificado.

```
static CString GetKeyName(
    UINT vk,
    BOOL fExtended);
```

### <a name="parameters"></a>Parâmetros

*vk*<br/>
O código de chave virtual.

*fExtended*<br/>
Se o código de chave virtual for uma chave estendida, TRUE; caso contrário, FALSE.

### <a name="return-value"></a>Valor de retorno

O nome localizado da chave especificada pelo parâmetro *VK* . Se a chave não tiver nenhum nome mapeado `GetKeyName` , retornará uma cadeia de caracteres vazia.

### <a name="remarks"></a>Comentários

O nome da chave que essa função retorna vem do driver de teclado, para que você possa instalar um driver de teclado não localizado em uma versão localizada do Windows e vice-versa.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCControlLadenDialog#69](../../mfc/codesnippet/cpp/chotkeyctrl-class_1.cpp)]

##  <a name="sethotkey"></a>  CHotKeyCtrl::SetHotKey

Define o atalho de teclado para um controle de teclas de atalho.

```
void SetHotKey(
    WORD wVirtualKeyCode,
    WORD wModifiers);
```

### <a name="parameters"></a>Parâmetros

*wVirtualKeyCode*<br/>
no Código de chave virtual do atalho de teclado. Para obter uma lista de códigos de chave virtual padrão, consulte WinUser. h.

*wModifiers*<br/>
no Uma combinação de bits (ou) de sinalizadores que indica as teclas modificadoras no atalho de teclado.

Os sinalizadores de modificador são os seguintes:

|Sinalizador|Chave correspondente|
|----------|-----------------------|
|HOTKEYF_ALT|tecla ALT|
|HOTKEYF_CONTROL|Tecla CTRL|
|HOTKEYF_EXT|Chave estendida|
|HOTKEYF_SHIFT|Tecla SHIFT|

### <a name="remarks"></a>Comentários

O código de chave virtual e as chaves modificadoras juntas definem o atalho de teclado.

##  <a name="setrules"></a>  CHotKeyCtrl::SetRules

Chame essa função para definir as combinações inválidas e a combinação de modificador padrão para um controle de tecla de atalho.

```
void SetRules(
    WORD wInvalidComb,
    WORD wModifiers);
```

### <a name="parameters"></a>Parâmetros

*wInvalidComb*<br/>
Matriz de sinalizadores que especifica combinações de chaves inválidas. Pode ser uma combinação dos seguintes valores:

- ALT HKCOMB_A

- HKCOMB_C CTRL

- HKCOMB_CA CTRL + ALT

- HKCOMB_NONE Chaves não modificadas

- HKCOMB_S SHIFT

- HKCOMB_SA SHIFT + ALT

- HKCOMB_SC SHIFT + CTRL

- HKCOMB_SCA SHIFT + CTRL + ALT

*wModifiers*<br/>
Matriz de sinalizadores que especifica a combinação de teclas a ser usada quando o usuário insere uma combinação inválida. Para obter mais informações sobre os sinalizadores de modificador [, consulte](#gethotkey).

### <a name="remarks"></a>Comentários

Quando um usuário insere uma combinação de teclas inválida, conforme definido pelos sinalizadores especificados em *wInvalidComb*, o sistema usa o operador OR para combinar as chaves inseridas pelo usuário com os sinalizadores especificados em *wModifiers*. A combinação de chave resultante é convertida em uma cadeia de caracteres e, em seguida, exibida no controle de tecla de acesso.

## <a name="see-also"></a>Consulte também

[Classe CWnd](../../mfc/reference/cwnd-class.md)<br/>
[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)
