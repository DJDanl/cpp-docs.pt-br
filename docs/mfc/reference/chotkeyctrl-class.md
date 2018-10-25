---
title: Classe CHotKeyCtrl | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: reference
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
dev_langs:
- C++
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
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 12aa039e0beede4f395da3de6eea4e6c956f9373
ms.sourcegitcommit: a9dcbcc85b4c28eed280d8e451c494a00d8c4c25
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/25/2018
ms.locfileid: "50074456"
---
# <a name="chotkeyctrl-class"></a>Classe CHotKeyCtrl

Fornece a funcionalidade do controle de tecla hot comuns de Windows.

## <a name="syntax"></a>Sintaxe

```
class CHotKeyCtrl : public CWnd
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores Públicos

|Nome|Descrição|
|----------|-----------------|
|[CHotKeyCtrl::CHotKeyCtrl](#chotkeyctrl)|Constrói um objeto `CHotKeyCtrl`.|

### <a name="public-methods"></a>Métodos Públicos

|Nome|Descrição|
|----------|-----------------|
|[CHotKeyCtrl::Create](#create)|Cria um controle de acesso de chave e anexa-o para um `CHotKeyCtrl` objeto.|
|[CHotKeyCtrl::CreateEx](#createex)|Cria um controle de acesso de chave com os estilos estendidos do Windows especificados e anexa-o para um `CHotKeyCtrl` objeto.|
|[CHotKeyCtrl::GetHotKey](#gethotkey)|Recupera os virtuais sinalizadores principais de código e o modificador de uma tecla de acesso de um controle de acesso de chave.|
|[CHotKeyCtrl::GetHotKeyName](#gethotkeyname)|Recupera o nome da chave no conjunto de caracteres local, atribuído a uma tecla de acesso.|
|[CHotKeyCtrl::GetKeyName](#getkeyname)|Recupera o nome da chave no conjunto de caracteres local, atribuído para o código de tecla virtual especificado.|
|[CHotKeyCtrl::SetHotKey](#sethotkey)|Define a combinação de teclas ativa para um controle de acesso de chave.|
|[CHotKeyCtrl::SetRules](#setrules)|Define as combinações inválidas e a combinação do modificador padrão para um controle de acesso de chave.|

## <a name="remarks"></a>Comentários

Um "chave controle de acesso" é uma janela que permite ao usuário criar uma tecla de acesso. Uma "tecla de acesso" é uma combinação de teclas que o usuário pode pressionar para executar uma ação rapidamente. (Por exemplo, um usuário pode criar uma tecla de acesso que ativa uma determinada janela e coloca-o na parte superior da ordem Z.) O controle de chave de acesso exibe as opções do usuário e garante que o usuário seleciona uma combinação válida de chave.

Esse controle (e, portanto, o `CHotKeyCtrl` classe) está disponível somente para programas executados na versão do Windows 95/98 e Windows NT 3.51 e posterior.

Quando o usuário escolheu uma combinação de teclas, o aplicativo pode recuperar a combinação de chave especificada do controle e usar a mensagem WM_SETHOTKEY para configurar a tecla de acesso no sistema. Sempre que o usuário pressiona a tecla de atalho daí em diante, de qualquer parte do sistema, a janela especificada na mensagem WM_SETHOTKEY recebe uma mensagem WM_SYSCOMMAND especificando SC_HOTKEY. Essa mensagem ativa a janela que recebe a ele. A tecla de acesso permanece válida até o aplicativo que chamou WM_SETHOTKEY sai.

Esse mecanismo é diferente do que o suporte a chaves hot que depende da mensagem WM_HOTKEY e o Windows [RegisterHotKey](https://msdn.microsoft.com/library/windows/desktop/ms646309) e [UnregisterHotKey](https://msdn.microsoft.com/library/windows/desktop/ms646327) funções.

Para obter mais informações sobre como usar `CHotKeyCtrl`, consulte [controles](../../mfc/controls-mfc.md) e [usando CHotKeyCtrl](../../mfc/using-chotkeyctrl.md).

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

Cria um controle de acesso de chave e anexa-o para um `CHotKeyCtrl` objeto.

```
virtual BOOL Create(
    DWORD dwStyle,
    const RECT& rect,
    CWnd* pParentWnd,
    UINT nID);
```

### <a name="parameters"></a>Parâmetros

*dwStyle*<br/>
Especifica o estilo do controle de chave ativa. Aplica qualquer combinação de estilos de controle. Ver [estilos de controle comuns](/windows/desktop/Controls/common-control-styles) no SDK do Windows para obter mais informações.

*Rect*<br/>
Especifica o tamanho e a posição do controle de tecla ativo. Ela pode ser um [CRect](../../atl-mfc-shared/reference/crect-class.md) objeto ou uma [estrutura RECT](../../mfc/reference/rect-structure1.md).

*pParentWnd*<br/>
Especifica o hot chave janela pai do controle, normalmente um [CDialog](../../mfc/reference/cdialog-class.md). Ele não deve ser NULL.

*nID*<br/>
Especifica a ID. do controle de chave ativa

### <a name="return-value"></a>Valor de retorno

Diferente de zero, se a inicialização foi bem-sucedida; Caso contrário, 0.

### <a name="remarks"></a>Comentários

Você constrói um `CHotKeyCtrl` objeto em duas etapas. Primeiro, chame o construtor e, em seguida, chame `Create`, que cria o controle de chave de acesso e anexa-o para o `CHotKeyCtrl` objeto.

Se você quiser usar estilos estendidos do windows com o seu controle, chame [CreateEx](#createex) em vez de `Create`.

##  <a name="createex"></a>  CHotKeyCtrl::CreateEx

Chame essa função para criar um controle (uma janela filho) e associá-la com o `CHotKeyCtrl` objeto.

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
Especifica o estilo estendido do controle que está sendo criado. Para obter uma lista dos estilos estendidos do Windows, consulte o *dwExStyle* parâmetro para [CreateWindowEx](/windows/desktop/api/winuser/nf-winuser-createwindowexa) no SDK do Windows.

*dwStyle*<br/>
Especifica o estilo do controle de chave ativa. Aplica qualquer combinação de estilos de controle. Para obter mais informações, consulte [estilos de controle comuns](/windows/desktop/Controls/common-control-styles) no SDK do Windows.

*Rect*<br/>
Uma referência a um [RECT](https://msdn.microsoft.com/library/windows/desktop/dd162897) estrutura que descreve o tamanho e posição da janela a ser criado, em coordenadas do cliente do *pParentWnd*.

*pParentWnd*<br/>
Um ponteiro para a janela que é o pai do controle.

*nID*<br/>
ID da janela filho. do controle

### <a name="return-value"></a>Valor de retorno

Diferente de zero se bem-sucedido; Caso contrário, 0.

### <a name="remarks"></a>Comentários

Use `CreateEx` em vez de [Create](#create) para aplicar estilos estendidos do Windows, especificados pelo prefácio de estilo estendido do Windows **WS_EX_**.

##  <a name="gethotkey"></a>  CHotKeyCtrl::GetHotKey

Recupera os virtuais sinalizadores principais de código e o modificador de um atalho de teclado de um controle de acesso de chave.

```
DWORD GetHotKey() const;

void GetHotKey(
    WORD& wVirtualKeyCode,
    WORD& wModifiers) const;
```

### <a name="parameters"></a>Parâmetros

*wVirtualKeyCode*<br/>
[out] Código de tecla virtual do atalho de teclado. Para obter uma lista de códigos de tecla virtuais padrão, consulte WinUser. h.

*wModifiers*<br/>
[out] Uma combinação bit a bit (OR) de sinalizadores que indicam as teclas modificadoras no atalho do teclado.

Os sinalizadores de modificador são da seguinte maneira:

|Sinalizador|Chave correspondente|
|----------|-----------------------|
|HOTKEYF_ALT|tecla ALT|
|HOTKEYF_CONTROL|Tecla CTRL|
|HOTKEYF_EXT|Estendido de chave|
|HOTKEYF_SHIFT|Tecla SHIFT|

### <a name="return-value"></a>Valor de retorno

No primeiro método, um DWORD que contém os sinalizadores de código e o modificador chave virtuais sobrecarregado. O byte de ordem inferior da palavra de ordem inferior contém o código de tecla virtual, o byte de ordem alta da palavra de ordem inferior contém os sinalizadores de modificador e a palavra de ordem superior é zero.

### <a name="remarks"></a>Comentários

O código de tecla virtual e as teclas modificadoras juntas definem o atalho de teclado.

##  <a name="gethotkeyname"></a>  CHotKeyCtrl::GetHotKeyName

Chame essa função de membro para obter o nome localizado da tecla de acesso.

```
CString GetHotKeyName() const;
```

### <a name="return-value"></a>Valor de retorno

O nome localizado da tecla de atalho selecionado no momento. Se não houver nenhuma tecla de atalho selecionada, `GetHotKeyName` retorna uma cadeia de caracteres vazia.

### <a name="remarks"></a>Comentários

O nome que essa função membro retorna o driver de teclado é proveniente. Você pode instalar um driver de teclado não localizado em uma versão localizada do Windows e vice-versa.

##  <a name="getkeyname"></a>  CHotKeyCtrl::GetKeyName

Chame essa função de membro para obter o nome localizado da chave atribuído a um código de tecla virtual especificado.

```
static CString GetKeyName(
    UINT vk,
    BOOL fExtended);
```

### <a name="parameters"></a>Parâmetros

*vk*<br/>
O código de tecla virtual.

*fExtended*<br/>
Se o código de tecla virtual é uma chave estendida, TRUE; Caso contrário, FALSE.

### <a name="return-value"></a>Valor de retorno

O nome localizado da chave especificado pela *vk* parâmetro. Se a chave não tem nenhum nome mapeada, `GetKeyName` retorna uma cadeia de caracteres vazia.

### <a name="remarks"></a>Comentários

O nome da chave que essa função retorna é proveniente do driver de teclado, para que você possa instalar um driver de teclado não localizado em uma versão localizada do Windows e vice-versa.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCControlLadenDialog#69](../../mfc/codesnippet/cpp/chotkeyctrl-class_1.cpp)]

##  <a name="sethotkey"></a>  CHotKeyCtrl::SetHotKey

Define o atalho de teclado para um controle de acesso de chave.

```
void SetHotKey(
    WORD wVirtualKeyCode,
    WORD wModifiers);
```

### <a name="parameters"></a>Parâmetros

*wVirtualKeyCode*<br/>
[in] Código de tecla virtual do atalho de teclado. Para obter uma lista de códigos de tecla virtuais padrão, consulte WinUser. h.

*wModifiers*<br/>
[in] Uma combinação bit a bit (OR) de sinalizadores que indicam as teclas modificadoras no atalho do teclado.

Os sinalizadores de modificador são da seguinte maneira:

|Sinalizador|Chave correspondente|
|----------|-----------------------|
|HOTKEYF_ALT|tecla ALT|
|HOTKEYF_CONTROL|Tecla CTRL|
|HOTKEYF_EXT|Estendido de chave|
|HOTKEYF_SHIFT|Tecla SHIFT|

### <a name="remarks"></a>Comentários

O código de tecla virtual e as teclas modificadoras juntas definem o atalho de teclado.

##  <a name="setrules"></a>  CHotKeyCtrl::SetRules

Chame essa função para definir as combinações inválidas e a combinação do modificador padrão para um controle de acesso de chave.

```
void SetRules(
    WORD wInvalidComb,
    WORD wModifiers);
```

### <a name="parameters"></a>Parâmetros

*wInvalidComb*<br/>
Matriz de sinalizadores que especifica as combinações de chave inválidas. Ele pode ser uma combinação dos seguintes valores:

- HKCOMB_A ALT

- HKCOMB_C CTRL

- CTRL + ALT HKCOMB_CA

- Chaves HKCOMB_NONE não modificado

- HKCOMB_S SHIFT

- SHIFT + ALT HKCOMB_SA

- SHIFT + CTRL HKCOMB_SC

- SHIFT + CTRL + ALT HKCOMB_SCA

*wModifiers*<br/>
Matriz de sinalizadores que especifica a combinação de teclas para usar quando o usuário insere uma combinação inválida. Para obter mais informações sobre os sinalizadores de modificador, consulte [GetHotKey](#gethotkey).

### <a name="remarks"></a>Comentários

Quando um usuário insere uma combinação de chave inválida, conforme definido pelos sinalizadores especificados na *wInvalidComb*, o sistema usa o operador OR para combinar as chaves inseridas pelo usuário com os sinalizadores especificados na *wModifiers*. A combinação de teclas resultante é convertida em uma cadeia de caracteres e, em seguida, é exibida no controle de chave de acesso.

## <a name="see-also"></a>Consulte também

[Classe CWnd](../../mfc/reference/cwnd-class.md)<br/>
[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)

