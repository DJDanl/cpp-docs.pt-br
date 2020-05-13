---
title: Classe CSpinButtonCtrl
ms.date: 11/04/2016
f1_keywords:
- CSpinButtonCtrl
- AFXCMN/CSpinButtonCtrl
- AFXCMN/CSpinButtonCtrl::CSpinButtonCtrl
- AFXCMN/CSpinButtonCtrl::Create
- AFXCMN/CSpinButtonCtrl::CreateEx
- AFXCMN/CSpinButtonCtrl::GetAccel
- AFXCMN/CSpinButtonCtrl::GetBase
- AFXCMN/CSpinButtonCtrl::GetBuddy
- AFXCMN/CSpinButtonCtrl::GetPos
- AFXCMN/CSpinButtonCtrl::GetRange
- AFXCMN/CSpinButtonCtrl::SetAccel
- AFXCMN/CSpinButtonCtrl::SetBase
- AFXCMN/CSpinButtonCtrl::SetBuddy
- AFXCMN/CSpinButtonCtrl::SetPos
- AFXCMN/CSpinButtonCtrl::SetRange
helpviewer_keywords:
- CSpinButtonCtrl [MFC], CSpinButtonCtrl
- CSpinButtonCtrl [MFC], Create
- CSpinButtonCtrl [MFC], CreateEx
- CSpinButtonCtrl [MFC], GetAccel
- CSpinButtonCtrl [MFC], GetBase
- CSpinButtonCtrl [MFC], GetBuddy
- CSpinButtonCtrl [MFC], GetPos
- CSpinButtonCtrl [MFC], GetRange
- CSpinButtonCtrl [MFC], SetAccel
- CSpinButtonCtrl [MFC], SetBase
- CSpinButtonCtrl [MFC], SetBuddy
- CSpinButtonCtrl [MFC], SetPos
- CSpinButtonCtrl [MFC], SetRange
ms.assetid: 509bfd76-1c5a-4af6-973f-e133c0b87734
ms.openlocfilehash: cedfe16a6870bc779121e8e864866cfcb711b148
ms.sourcegitcommit: 7a6116e48c3c11b97371b8ae4ecc23adce1f092d
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/22/2020
ms.locfileid: "81753109"
---
# <a name="cspinbuttonctrl-class"></a>Classe CSpinButtonCtrl

Fornece a funcionalidade do controle do botão de giro comum do Windows.

## <a name="syntax"></a>Sintaxe

```
class CSpinButtonCtrl : public CWnd
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[CSpinButtonCtrl::CSpinButtonCtrl](#cspinbuttonctrl)|Constrói um objeto `CSpinButtonCtrl`.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CSpinButtonCtrl::Criar](#create)|Cria um controle de botão de `CSpinButtonCtrl` giro e o prende a um objeto.|
|[CSpinButtonCtrl::CreateEx](#createex)|Cria um controle de botão de giro com os `CSpinButtonCtrl` estilos estendidos do Windows especificados e o anexa a um objeto.|
|[CSpinButtonCtrl::GetAccel](#getaccel)|Recupera informações de aceleração para um controle de botão de giro.|
|[CSpinButtonCtrl::GetBase](#getbase)|Recupera a base atual para um controle de botão de giro.|
|[CSpinButtonCtrl::GetBuddy](#getbuddy)|Recupera um ponteiro para a janela atual do amigo.|
|[CSpinButtonCtrl::GetPos](#getpos)|Recupera a posição atual de um controle de botão de giro.|
|[CSpinButtonCtrl::GetRange](#getrange)|Recupera os limites superior e inferior (intervalo) para um controle de botão de giro.|
|[CSpinButtonCtrl::SetAccel](#setaccel)|Define a aceleração para um controle de botão de giro.|
|[CSpinButtonCtrl::SetBase](#setbase)|Define a base para um controle de botão de giro.|
|[CSpinButtonCtrl::SetBuddy](#setbuddy)|Define a janela do amigo para um controle de botão de giro.|
|[CSpinButtonCtrl::SetPos](#setpos)|Define a posição atual para o controle.|
|[CSpinButtonCtrl::SetRange](#setrange)|Define os limites superior e inferior (intervalo) para um controle de botão de giro.|

## <a name="remarks"></a>Comentários

Um "controle de botão de giro" (também conhecido como controle para cima) é um par de botões de seta que o usuário pode clicar para incrementar ou diminuir um valor, como uma posição de rolagem ou um número exibido em um controle de companheiro. O valor associado a um controle de botão de giro é chamado de posição atual. Um controle de botão de giro é mais frequentemente usado com um controle de companheiro, chamado de "janela de amigo".

Este controle (e, `CSpinButtonCtrl` portanto, a classe) está disponível apenas para programas em execução sob windows 95/98 e Windows NT versão 3.51 e posterior.

Para o usuário, um controle de botão de giro e sua janela de amigo muitas vezes se parecem com um único controle. Você pode especificar que um controle de botão de giro se posicione automaticamente ao lado de sua janela de amigos, e que ele defina automaticamente a legenda da janela do amigo para sua posição atual. Você pode usar um controle de botão de giro com um controle de edição para solicitar ao usuário uma entrada numérica.

Clicar na seta para cima move a posição atual em direção ao máximo e clicar na seta para baixo move a posição atual em direção ao mínimo. Por padrão, o mínimo é 100 e o máximo é 0. Sempre que a configuração mínima for maior do que a configuração máxima (por exemplo, quando as configurações padrão são usadas), clicar na seta para cima diminui o valor de posição e clicar na seta para baixo aumenta-a.

Um controle de botão de giro sem uma janela de amigo funciona como uma espécie de barra de rolagem simplificada. Por exemplo, um controle de guia susceptível de exibir um controle de botão de giro para permitir que o usuário role guias adicionais para a exibição.

Para obter mais `CSpinButtonCtrl`informações sobre como usar, consulte [Controles](../../mfc/controls-mfc.md) e [Usando CSpinButtonCtrl](../../mfc/using-cspinbuttonctrl.md).

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[Cobject](../../mfc/reference/cobject-class.md)

[Ccmdtarget](../../mfc/reference/ccmdtarget-class.md)

[CWnd](../../mfc/reference/cwnd-class.md)

`CSpinButtonCtrl`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxcmn.h

## <a name="cspinbuttonctrlcreate"></a><a name="create"></a>CSpinButtonCtrl::Criar

Cria um controle de botão de `CSpinButtonCtrl` giro e o prende a um objeto..

```
virtual BOOL Create(
    DWORD dwStyle,
    const RECT& rect,
    CWnd* pParentWnd,
    UINT nID);
```

### <a name="parameters"></a>Parâmetros

*Dwstyle*<br/>
Especifica o estilo do controle do botão de giro. Aplique qualquer combinação de estilos de controle do botão de giro ao controle. Esses estilos são descritos em [Estilos de controle de up-down](/windows/win32/Controls/up-down-control-styles) no SDK do Windows.

*Rect*<br/>
Especifica o tamanho e a posição do controle do botão de giro. Pode ser um objeto [CRect](../../atl-mfc-shared/reference/crect-class.md) ou uma estrutura [RECT](/windows/win32/api/windef/ns-windef-rect)

*Pparentwnd*<br/>
Um ponteiro para a janela pai do `CDialog`controle do botão de giro, geralmente um . Não deve ser NULO.

*nID*<br/>
Especifica o ID do controle do botão de giro.

### <a name="return-value"></a>Valor retornado

Não zero se a inicialização foi bem sucedida; caso contrário, 0.

### <a name="remarks"></a>Comentários

Você constrói `CSpinButtonCtrl` um objeto em dois passos Primeiro, `Create`chame o construtor e, em seguida, chame, que cria o controle do botão de giro e o anexa ao `CSpinButtonCtrl` objeto.

Para criar um controle de botão de giro com estilos de janela `Create`estendidos, chame [CSpinButtonCtrl::CreateEx](#createex) em vez de .

## <a name="cspinbuttonctrlcreateex"></a><a name="createex"></a>CSpinButtonCtrl::CreateEx

Cria um controle (uma janela filho) `CSpinButtonCtrl` e o associa ao objeto.

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
Especifica o estilo estendido do controle que está sendo criado. Para obter uma lista de estilos de janelas estendidos, consulte o parâmetro *dwExStyle* para [CreateWindowEx](/windows/win32/api/winuser/nf-winuser-createwindowexw) no SDK do Windows.

*Dwstyle*<br/>
Especifica o estilo do controle do botão de giro. Aplique qualquer combinação de estilos de controle do botão de giro ao controle. Esses estilos são descritos em [Estilos de controle de up-down](/windows/win32/Controls/up-down-control-styles) no SDK do Windows.

*Rect*<br/>
Uma referência a uma estrutura [RECT](/windows/win32/api/windef/ns-windef-rect) descrevendo o tamanho e a posição da janela a ser criada, em coordenadas de cliente de *pParentWnd*.

*Pparentwnd*<br/>
Um ponteiro para a janela que é o pai do controle.

*nID*<br/>
A id da janela infantil do controle.

### <a name="return-value"></a>Valor retornado

Não zero se bem sucedido; caso contrário, 0.

### <a name="remarks"></a>Comentários

Use `CreateEx` em vez de [Criar](#create) para aplicar estilos estendidos do Windows, especificados pelo prefácio de estilo estendido do Windows WS_EX_.

## <a name="cspinbuttonctrlcspinbuttonctrl"></a><a name="cspinbuttonctrl"></a>CSpinButtonCtrl::CSpinButtonCtrl

Constrói um objeto `CSpinButtonCtrl`.

```
CSpinButtonCtrl();
```

## <a name="cspinbuttonctrlgetaccel"></a><a name="getaccel"></a>CSpinButtonCtrl::GetAccel

Recupera informações de aceleração para um controle de botão de giro.

```
UINT GetAccel(
    int nAccel,
    UDACCEL* pAccel) const;
```

### <a name="parameters"></a>Parâmetros

*nAccel*<br/>
Número de elementos na matriz especificada por *pAccel*.

*pAccel*<br/>
Ponteiro para um conjunto de estruturas [UDACCEL](/windows/win32/api/commctrl/ns-commctrl-udaccel) que recebe informações de aceleração.

### <a name="return-value"></a>Valor retornado

Número de estruturas do acelerador recuperadas.

## <a name="cspinbuttonctrlgetbase"></a><a name="getbase"></a>CSpinButtonCtrl::GetBase

Recupera a base atual para um controle de botão de giro.

```
UINT GetBase() const;
```

### <a name="return-value"></a>Valor retornado

O valor base atual.

## <a name="cspinbuttonctrlgetbuddy"></a><a name="getbuddy"></a>CSpinButtonCtrl::GetBuddy

Recupera um ponteiro para a janela atual do amigo.

```
CWnd* GetBuddy() const;
```

### <a name="return-value"></a>Valor retornado

Um ponteiro para a janela atual do amigo.

## <a name="cspinbuttonctrlgetpos"></a><a name="getpos"></a>CSpinButtonCtrl::GetPos

Recupera a posição atual de um controle de botão de giro.

```
int GetPos() const;  int GetPos32(LPBOOL lpbError = NULL) const;
```

### <a name="parameters"></a>Parâmetros

*lpbError*<br/>
Um ponteiro para um valor booleano definido como zero se o valor for recuperado com sucesso ou não se ocorrer um erro. Se este parâmetro estiver definido como NULL, erros não serão reportados.

### <a name="return-value"></a>Valor retornado

A primeira versão retorna a posição atual de 16 bits na palavra de baixa ordem. A palavra de alta ordem não é zero se ocorreu um erro.

A segunda versão retorna a posição de 32 bits.

### <a name="remarks"></a>Comentários

Quando processa o valor retornado, o controle atualiza sua posição atual com base na legenda da janela buddy. O controle retorna um erro se não houver janela de amigo ou se a legenda especificar um valor inválido ou fora de alcance.

## <a name="cspinbuttonctrlgetrange"></a><a name="getrange"></a>CSpinButtonCtrl::GetRange

Recupera os limites superior e inferior (intervalo) para um controle de botão de giro.

```
DWORD GetRange() const;

void GetRange(
    int& lower,
    int& upper) const;

void GetRange32(
    int& lower,
    int &upper) const;
```

### <a name="parameters"></a>Parâmetros

*Inferior*<br/>
Referência a um inteiro que recebe o limite inferior para o controle.

*Superior*<br/>
Referência a um inteiro que recebe o limite superior para o controle.

### <a name="return-value"></a>Valor retornado

A primeira versão retorna um valor de 32 bits contendo os limites superior e inferior. A palavra de baixa ordem é o limite superior para o controle, e a palavra de alta ordem é o limite inferior.

### <a name="remarks"></a>Comentários

A função `GetRange32` membro recupera o alcance do controle do botão de giro como um inteiro de 32 bits.

## <a name="cspinbuttonctrlsetaccel"></a><a name="setaccel"></a>CSpinButtonCtrl::SetAccel

Define a aceleração para um controle de botão de giro.

```
BOOL SetAccel(
    int nAccel,
    UDACCEL* pAccel);
```

### <a name="parameters"></a>Parâmetros

*nAccel*<br/>
Número de estruturas [UDACCEL](/windows/win32/api/commctrl/ns-commctrl-udaccel) especificadas por *pAccel*.

*pAccel*<br/>
Ponteiro para um conjunto de estruturas UDACCEL, que contêm informações de aceleração. Os elementos devem ser classificados `nSec` em ordem ascendente com base no membro.

### <a name="return-value"></a>Valor retornado

Não zero se bem sucedido; caso contrário, 0.

## <a name="cspinbuttonctrlsetbase"></a><a name="setbase"></a>CSpinButtonCtrl::SetBase

Define a base para um controle de botão de giro.

```
int SetBase(int nBase);
```

### <a name="parameters"></a>Parâmetros

*nBase*<br/>
Novo valor base para o controle. Pode ser 10 para decimal ou 16 para hexadecimal.

### <a name="return-value"></a>Valor retornado

O valor base anterior, se bem sucedido, ou zero se uma base inválida for dada.

### <a name="remarks"></a>Comentários

O valor base determina se a janela do amigo exibe números em dígitos decimais ou hexadecimais. Números hexadecimais são sempre não assinados; números decimais são assinados.

## <a name="cspinbuttonctrlsetbuddy"></a><a name="setbuddy"></a>CSpinButtonCtrl::SetBuddy

Define a janela do amigo para um controle de botão de giro.

```
CWnd* SetBuddy(CWnd* pWndBuddy);
```

### <a name="parameters"></a>Parâmetros

*pWndBuddy*<br/>
Ponteiro para a nova janela de amigos.

### <a name="return-value"></a>Valor retornado

Um ponteiro para a janela do amigo anterior.

### <a name="remarks"></a>Comentários

Um controle de spin é quase sempre associado a outra janela, como um controle de edição, que exibe algum conteúdo. Esta outra janela é chamada de "amigo" do controle de giro.

## <a name="cspinbuttonctrlsetpos"></a><a name="setpos"></a>CSpinButtonCtrl::SetPos

Define a posição atual para um controle de botão de giro.

```
int SetPos(int nPos);
int SetPos32(int nPos);
```

### <a name="parameters"></a>Parâmetros

*Npos*<br/>
Nova posição para o controle. Este valor deve estar na faixa especificada pelos limites superior e inferior para o controle.

### <a name="return-value"></a>Valor retornado

A posição anterior (precisão de `SetPos`16 bits `SetPos32`para precisão de 32 bits para ).

### <a name="remarks"></a>Comentários

`SetPos32`define a posição de 32 bits.

## <a name="cspinbuttonctrlsetrange"></a><a name="setrange"></a>CSpinButtonCtrl::SetRange

Define os limites superior e inferior (intervalo) para um controle de botão de giro.

```cpp
void SetRange(
    short nLower,
    short nUpper);

void SetRange32(
    int nLower,
    int nUpper);
```

### <a name="parameters"></a>Parâmetros

*nLower* e *nUpper*<br/>
Limites superiores e inferiores para o controle. Pois, `SetRange`nenhum limite pode ser maior do que UD_MAXVAL ou menor do que UD_MINVAL; além disso, a diferença entre os dois limites não pode exceder UD_MAXVAL. `SetRange32`não impõe restrições aos limites; usar quaisquer inteiros.

### <a name="remarks"></a>Comentários

A função `SetRange32` do membro define o intervalo de 32 bits para o controle do botão de giro.

> [!NOTE]
> O intervalo padrão para o botão de giro tem o máximo definido como zero (0) e o mínimo definido para 100. Como o valor máximo é menor que o valor mínimo, clicar na seta para cima diminuirá a posição e clicar na seta para baixo irá aumentá-la. Use `CSpinButtonCtrl::SetRange` para ajustar esses valores.

## <a name="see-also"></a>Confira também

[Amostra de MFC CMNCTRL2](../../overview/visual-cpp-samples.md)<br/>
[Classe CWnd](../../mfc/reference/cwnd-class.md)<br/>
[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classe CSliderCtrl](../../mfc/reference/csliderctrl-class.md)
