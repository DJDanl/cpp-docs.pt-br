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
ms.openlocfilehash: 758fb78fbd4e25a0e2fb8cea300c5371ece04fb4
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81366879"
---
# <a name="chotkeyctrl-class"></a>Classe CHotKeyCtrl

Fornece a funcionalidade do controle de tecla quente comum do Windows.

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
|[CHotKeyCtrl::Criar](#create)|Cria um controle de tecla `CHotKeyCtrl` quente e o anexa a um objeto.|
|[CHotKeyCtrl::CreateEx](#createex)|Cria um controle de tecla quente com os estilos `CHotKeyCtrl` estendidos do Windows especificados e o anexa a um objeto.|
|[CHotKeyCtrl::GetHotKey](#gethotkey)|Recupera o código de chave virtual e os sinalizadores modificadores de uma tecla quente a partir de um controle de tecla quente.|
|[CHotKeyCtrl::GetHotKeyName](#gethotkeyname)|Recupera o nome-chave, no conjunto de caracteres local, atribuído a uma tecla quente.|
|[CHotKeyCtrl::GetKeyName](#getkeyname)|Recupera o nome da chave, no conjunto de caracteres local, atribuído ao código de chave virtual especificado.|
|[CHotKeyCtrl::SetHotKey](#sethotkey)|Define a combinação de tecla quente para um controle de tecla quente.|
|[CHotKeyCtrl::SetRules](#setrules)|Define as combinações inválidas e a combinação do modificador padrão para um controle de tecla quente.|

## <a name="remarks"></a>Comentários

Um "controle de tecla quente" é uma janela que permite ao usuário criar uma chave quente. Uma "tecla quente" é uma combinação de teclas que o usuário pode pressionar para executar uma ação rapidamente. (Por exemplo, um usuário pode criar uma chave quente que ativa uma determinada janela e a traz para o topo da ordem Z.) O controle de tecla quente exibe as escolhas do usuário e garante que o usuário selecione uma combinação de teclas válida.

Este controle (e, `CHotKeyCtrl` portanto, a classe) está disponível apenas para programas em execução sob windows 95/98 e Windows NT versão 3.51 e posterior.

Quando o usuário escolhe uma combinação de teclas, o aplicativo pode recuperar a combinação de teclas especificada do controle e usar a mensagem WM_SETHOTKEY para configurar a chave quente no sistema. Sempre que o usuário pressiona a tecla quente posteriormente, de qualquer parte do sistema, a janela especificada na mensagem WM_SETHOTKEY recebe uma mensagem WM_SYSCOMMAND especificando SC_HOTKEY. Esta mensagem ativa a janela que a recebe. A tecla quente permanece válida até que o aplicativo que chamou WM_SETHOTKEY saia.

Este mecanismo é diferente do suporte de chave quente que depende da mensagem WM_HOTKEY e das funções Windows [RegisterHotKey](/windows/win32/api/winuser/nf-winuser-registerhotkey) e [UnregisterHotKey.](/windows/win32/api/winuser/nf-winuser-unregisterhotkey)

Para obter mais `CHotKeyCtrl`informações sobre como usar, consulte [Controles](../../mfc/controls-mfc.md) e [Usando CHotKeyCtrl](../../mfc/using-chotkeyctrl.md).

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[Cobject](../../mfc/reference/cobject-class.md)

[Ccmdtarget](../../mfc/reference/ccmdtarget-class.md)

[CWnd](../../mfc/reference/cwnd-class.md)

`CHotKeyCtrl`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxcmn.h

## <a name="chotkeyctrlchotkeyctrl"></a><a name="chotkeyctrl"></a>CHotKeyCtrl::CHotKeyCtrl

Constrói um objeto `CHotKeyCtrl`.

```
CHotKeyCtrl();
```

## <a name="chotkeyctrlcreate"></a><a name="create"></a>CHotKeyCtrl::Criar

Cria um controle de tecla `CHotKeyCtrl` quente e o anexa a um objeto.

```
virtual BOOL Create(
    DWORD dwStyle,
    const RECT& rect,
    CWnd* pParentWnd,
    UINT nID);
```

### <a name="parameters"></a>Parâmetros

*Dwstyle*<br/>
Especifica o estilo do controle de tecla quente. Aplique qualquer combinação de estilos de controle. Consulte [Estilos de controle comuns](/windows/win32/Controls/common-control-styles) no SDK do Windows para obter mais informações.

*Rect*<br/>
Especifica o tamanho e a posição do controle da tecla quente. Pode ser um objeto [CRect](../../atl-mfc-shared/reference/crect-class.md) ou uma [estrutura RECT](/windows/win32/api/windef/ns-windef-rect).

*Pparentwnd*<br/>
Especifica a janela pai do controle de tecla quente, geralmente um [CDialog](../../mfc/reference/cdialog-class.md). Não deve ser NULO.

*nID*<br/>
Especifica o ID do controle da tecla quente.

### <a name="return-value"></a>Valor retornado

Não zero, se a inicialização foi bem sucedida; caso contrário, 0.

### <a name="remarks"></a>Comentários

Você constrói `CHotKeyCtrl` um objeto em dois passos. Primeiro, ligue para o `Create`construtor e, em seguida, ligue, `CHotKeyCtrl` que cria o controle de tecla quente e o anexa ao objeto.

Se você quiser usar estilos de janelas estendidos `Create`com o controle, chame [CreateEx](#createex) em vez de .

## <a name="chotkeyctrlcreateex"></a><a name="createex"></a>CHotKeyCtrl::CreateEx

Chame esta função para criar um controle (uma `CHotKeyCtrl` janela filho) e associá-la com o objeto.

```
virtual BOOL CreateEx(
    DWORD dwExStyle,
    DWORD dwStyle,
    const RECT& rect,
    CWnd* pParentWnd,
    UINT nID);
```

### <a name="parameters"></a>Parâmetros

*Dwexstyle*<br/>
Especifica o estilo estendido do controle que está sendo criado. Para obter uma lista de estilos estendidos do Windows, consulte o parâmetro *dwExStyle* para [CreateWindowEx](/windows/win32/api/winuser/nf-winuser-createwindowexw) no SDK do Windows.

*Dwstyle*<br/>
Especifica o estilo do controle de tecla quente. Aplique qualquer combinação de estilos de controle. Para obter mais informações, consulte [Estilos de controle comuns](/windows/win32/Controls/common-control-styles) no SDK do Windows.

*Rect*<br/>
Uma referência a uma estrutura [RECT](/previous-versions/dd162897\(v=vs.85\)) descrevendo o tamanho e a posição da janela a ser criada, em coordenadas de cliente de *pParentWnd*.

*Pparentwnd*<br/>
Um ponteiro para a janela que é o pai do controle.

*nID*<br/>
A id da janela infantil do controle.

### <a name="return-value"></a>Valor retornado

Não zero se bem sucedido; caso contrário, 0.

### <a name="remarks"></a>Comentários

Use `CreateEx` em vez de [Criar](#create) para aplicar estilos estendidos do Windows, especificados pelo prefácio de estilo estendido do Windows **WS_EX_**.

## <a name="chotkeyctrlgethotkey"></a><a name="gethotkey"></a>CHotKeyCtrl::GetHotKey

Recupera o código de tecla virtual e os sinalizadores modificadores de um atalho de teclado a partir de um controle de tecla quente.

```
DWORD GetHotKey() const;

void GetHotKey(
    WORD& wVirtualKeyCode,
    WORD& wModifiers) const;
```

### <a name="parameters"></a>Parâmetros

*wVirtualKeyCode*<br/>
[fora] Código de tecla virtual do atalho do teclado. Para obter uma lista de códigos-chave virtuais padrão, consulte Winuser.h.

*wModifiers*<br/>
[fora] Uma combinação bitwise (OR) de sinalizadores que indicam as teclas modificadoras no atalho do teclado.

As bandeiras modificadoras são as seguintes:

|Sinalizador|Chave correspondente|
|----------|-----------------------|
|HOTKEYF_ALT|tecla ALT|
|HOTKEYF_CONTROL|Tecla CTRL|
|HOTKEYF_EXT|Chave estendida|
|HOTKEYF_SHIFT|Chave SHIFT|

### <a name="return-value"></a>Valor retornado

No primeiro método sobrecarregado, um DWORD que contém o código de chave virtual e sinalizadores modificadores. O byte de baixa ordem da palavra de baixa ordem contém o código de chave virtual, o byte de alta ordem da palavra de baixa ordem contém os sinalizadores modificadores, e a palavra de alta ordem é zero.

### <a name="remarks"></a>Comentários

O código de tecla virtual e as teclas modificadoras juntos definem o atalho do teclado.

## <a name="chotkeyctrlgethotkeyname"></a><a name="gethotkeyname"></a>CHotKeyCtrl::GetHotKeyName

Ligue para esta função de membro para obter o nome localizado da tecla quente.

```
CString GetHotKeyName() const;
```

### <a name="return-value"></a>Valor retornado

O nome localizado da tecla quente selecionada no momento. Se não houver uma `GetHotKeyName` tecla quente selecionada, retorne uma seqüência vazia.

### <a name="remarks"></a>Comentários

O nome que esta função de membro retorna vem do driver do teclado. Você pode instalar um driver de teclado não localizado em uma versão localizada do Windows, e vice-versa.

## <a name="chotkeyctrlgetkeyname"></a><a name="getkeyname"></a>CHotKeyCtrl::GetKeyName

Ligue para esta função de membro para obter o nome localizado da chave atribuída a um código de chave virtual especificado.

```
static CString GetKeyName(
    UINT vk,
    BOOL fExtended);
```

### <a name="parameters"></a>Parâmetros

*Vk*<br/>
O código-chave virtual.

*fExtended*<br/>
Se o código de chave virtual for uma chave estendida, TRUE; caso contrário, FALSO.

### <a name="return-value"></a>Valor retornado

O nome localizado da chave especificada pelo parâmetro *vk.* Se a chave não tiver `GetKeyName` um nome mapeado, retorne uma seqüência vazia.

### <a name="remarks"></a>Comentários

O nome-chave que essa função retorna vem do driver de teclado, para que você possa instalar um driver de teclado não localizado em uma versão localizada do Windows, e vice-versa.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCControlLadenDialog#69](../../mfc/codesnippet/cpp/chotkeyctrl-class_1.cpp)]

## <a name="chotkeyctrlsethotkey"></a><a name="sethotkey"></a>CHotKeyCtrl::SetHotKey

Define o atalho do teclado para um controle de tecla quente.

```
void SetHotKey(
    WORD wVirtualKeyCode,
    WORD wModifiers);
```

### <a name="parameters"></a>Parâmetros

*wVirtualKeyCode*<br/>
[em] Código de tecla virtual do atalho do teclado. Para obter uma lista de códigos-chave virtuais padrão, consulte Winuser.h.

*wModifiers*<br/>
[em] Uma combinação bitwise (OR) de sinalizadores que indicam as teclas modificadoras no atalho do teclado.

As bandeiras modificadoras são as seguintes:

|Sinalizador|Chave correspondente|
|----------|-----------------------|
|HOTKEYF_ALT|tecla ALT|
|HOTKEYF_CONTROL|Tecla CTRL|
|HOTKEYF_EXT|Chave estendida|
|HOTKEYF_SHIFT|Chave SHIFT|

### <a name="remarks"></a>Comentários

O código de tecla virtual e as teclas modificadoras juntos definem o atalho do teclado.

## <a name="chotkeyctrlsetrules"></a><a name="setrules"></a>CHotKeyCtrl::SetRules

Chame esta função para definir as combinações inválidas e a combinação do modificador padrão para um controle de tecla quente.

```
void SetRules(
    WORD wInvalidComb,
    WORD wModifiers);
```

### <a name="parameters"></a>Parâmetros

*wInvalidComb*<br/>
Matriz de sinalizadores que especifica combinações de chaves inválidas. Pode ser uma combinação dos seguintes valores:

- HKCOMB_A ALT

- HKCOMB_C CTRL

- HKCOMB_CA CTRL+ALT

- chaves HKCOMB_NONE não modificadas

- HKCOMB_S SHIFT

- HKCOMB_SA SHIFT+ALT

- HKCOMB_SC SHIFT+CTRL

- HKCOMB_SCA SHIFT+CTRL+ALT

*wModifiers*<br/>
Matriz de sinalizadores que especifica a combinação de chave a ser usada quando o usuário entra em uma combinação inválida. Para obter mais informações sobre os sinalizadores modificadores, consulte [GetHotKey](#gethotkey).

### <a name="remarks"></a>Comentários

Quando um usuário entra em uma combinação de teclas inválida, conforme definido por sinalizadores especificados no *wInvalidComb,* o sistema usa o operador OR para combinar as chaves inseridas pelo usuário com os sinalizadores especificados em *wModifiers*. A combinação de teclas resultante é convertida em uma seqüência e, em seguida, exibida no controle de tecla quente.

## <a name="see-also"></a>Confira também

[Classe CWnd](../../mfc/reference/cwnd-class.md)<br/>
[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)
