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
ms.openlocfilehash: c167745eed45b7081e62a2c3be225a33e7ee0520
ms.sourcegitcommit: fcb48824f9ca24b1f8bd37d647a4d592de1cc925
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/15/2019
ms.locfileid: "69502435"
---
# <a name="cspinbuttonctrl-class"></a>Classe CSpinButtonCtrl

Fornece a funcionalidade do controle de botão de rotação comum do Windows.

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
|[CSpinButtonCtrl::Create](#create)|Cria um controle de botão de rotação e o anexa a `CSpinButtonCtrl` um objeto.|
|[CSpinButtonCtrl::CreateEx](#createex)|Cria um controle de botão de rotação com os estilos estendidos do Windows especificados e o `CSpinButtonCtrl` anexa a um objeto.|
|[CSpinButtonCtrl::GetAccel](#getaccel)|Recupera informações de aceleração para um controle de botão de rotação.|
|[CSpinButtonCtrl::GetBase](#getbase)|Recupera a base atual para um controle de botão de rotação.|
|[CSpinButtonCtrl::GetBuddy](#getbuddy)|Recupera um ponteiro para a janela atual do Buddy.|
|[CSpinButtonCtrl::GetPos](#getpos)|Recupera a posição atual de um controle de botão de rotação.|
|[CSpinButtonCtrl::GetRange](#getrange)|Recupera os limites superior e inferior (intervalo) para um controle de botão de rotação.|
|[CSpinButtonCtrl::SetAccel](#setaccel)|Define a aceleração de um controle de botão de rotação.|
|[CSpinButtonCtrl::SetBase](#setbase)|Define a base para um controle de botão de rotação.|
|[CSpinButtonCtrl::SetBuddy](#setbuddy)|Define a janela Buddy para um controle de botão de rotação.|
|[CSpinButtonCtrl::SetPos](#setpos)|Define a posição atual do controle.|
|[CSpinButtonCtrl::SetRange](#setrange)|Define os limites superior e inferior (intervalo) para um controle de botão de rotação.|

## <a name="remarks"></a>Comentários

Um "controle de botão de rotação" (também conhecido como controle de cima para baixo) é um par de botões de seta que o usuário pode clicar para incrementar ou decrementar um valor, como uma posição de rolagem ou um número exibido em um controle complementar. O valor associado a um controle de botão de rotação é chamado de posição atual. Um controle de botão de rotação é usado com mais frequência com um controle complementar, chamado de "Buddy Window".

Esse controle (e, portanto `CSpinButtonCtrl` , a classe) está disponível somente para programas em execução no Windows 95/98 e no Windows NT versão 3,51 e posterior.

Para o usuário, um controle de botão de rotação e sua janela Buddy geralmente se parecem com um único controle. Você pode especificar que um controle de botão de rotação se Posicione automaticamente ao lado de sua janela Buddy e que ele defina automaticamente a legenda da janela Buddy para sua posição atual. Você pode usar um controle de botão de rotação com um controle de edição para solicitar ao usuário uma entrada numérica.

Clicar na seta para cima move a posição atual para o máximo e, ao clicar na seta para baixo, move a posição atual para o mínimo. Por padrão, o mínimo é 100 e o máximo é 0. Sempre que a configuração mínima for maior do que a configuração máxima (por exemplo, quando as configurações padrão forem usadas), clicar na seta para cima diminuirá o valor da posição e clicar na seta para baixo o aumentará.

Um controle botão de rotação sem uma janela Buddy funciona como um tipo de barra de rolagem simplificada. Por exemplo, um controle guia às vezes exibe um controle botão de rotação para permitir que o usuário Role as guias adicionais para a exibição.

Para obter mais informações sobre `CSpinButtonCtrl`como usar o, consulte [controles](../../mfc/controls-mfc.md) e [usando CSpinButtonCtrl](../../mfc/using-cspinbuttonctrl.md).

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[CObject](../../mfc/reference/cobject-class.md)

[CCmdTarget](../../mfc/reference/ccmdtarget-class.md)

[CWnd](../../mfc/reference/cwnd-class.md)

`CSpinButtonCtrl`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxcmn. h

##  <a name="create"></a>  CSpinButtonCtrl::Create

Cria um controle de botão de rotação e o anexa a `CSpinButtonCtrl` um objeto.

```
virtual BOOL Create(
    DWORD dwStyle,
    const RECT& rect,
    CWnd* pParentWnd,
    UINT nID);
```

### <a name="parameters"></a>Parâmetros

*dwStyle*<br/>
Especifica o estilo do controle do botão de rotação. Aplique qualquer combinação de estilos de controle de botão de rotação ao controle. Esses estilos são descritos em [estilos de controle acima e abaixo](/windows/win32/Controls/up-down-control-styles) na SDK do Windows.

*rect*<br/>
Especifica o tamanho e a posição do controle de botão de rotação. Pode ser um objeto [CRect](../../atl-mfc-shared/reference/crect-class.md) ou uma estrutura [Rect](/previous-versions/dd162897\(v=vs.85\))

*pParentWnd*<br/>
Um ponteiro para a janela pai do controle do botão de rotação, `CDialog`geralmente um. Ele não deve ser nulo.

*nID*<br/>
Especifica a ID do controle do botão de rotação.

### <a name="return-value"></a>Valor de retorno

Diferente de zero se a inicialização tiver sido bem-sucedida; caso contrário, 0.

### <a name="remarks"></a>Comentários

Primeiro, você `CSpinButtonCtrl` constrói um objeto em duas etapas, chama o construtor e, em `Create`seguida, chama, que cria o controle botão de rotação e o `CSpinButtonCtrl` anexa ao objeto.

Para criar um controle de botão de rotação com estilos de janela estendidos, chame [CSpinButtonCtrl:: CreateEx](#createex) em vez de `Create`.

##  <a name="createex"></a>  CSpinButtonCtrl::CreateEx

Cria um controle (uma janela filho) e o `CSpinButtonCtrl` associa ao objeto.

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
Especifica o estilo do controle do botão de rotação. Aplique qualquer combinação de estilos de controle de botão de rotação ao controle. Esses estilos são descritos em [estilos de controle acima e abaixo](/windows/win32/Controls/up-down-control-styles) na SDK do Windows.

*rect*<br/>
Uma referência a uma estrutura [Rect](/previous-versions/dd162897\(v=vs.85\)) que descreve o tamanho e a posição da janela a ser criada, nas coordenadas de cliente de *pParentWnd*.

*pParentWnd*<br/>
Um ponteiro para a janela que é o pai do controle.

*nID*<br/>
A ID da janela filho do controle.

### <a name="return-value"></a>Valor de retorno

Diferente de zero, se for bem-sucedido; caso contrário, 0.

### <a name="remarks"></a>Comentários

Use `CreateEx` em vez de [Create](#create) para aplicar estilos estendidos do Windows, especificados pelo estilo estendido do Windows WS_EX_ do prefácio.

##  <a name="cspinbuttonctrl"></a>  CSpinButtonCtrl::CSpinButtonCtrl

Constrói um objeto `CSpinButtonCtrl`.

```
CSpinButtonCtrl();
```

##  <a name="getaccel"></a>  CSpinButtonCtrl::GetAccel

Recupera informações de aceleração para um controle de botão de rotação.

```
UINT GetAccel(
    int nAccel,
    UDACCEL* pAccel) const;
```

### <a name="parameters"></a>Parâmetros

*nAccel*<br/>
Número de elementos na matriz especificada por *pAccel*.

*pAccel*<br/>
Ponteiro para uma matriz de estruturas [UDACCEL](/windows/win32/api/commctrl/ns-commctrl-udaccel) que recebe informações de aceleração.

### <a name="return-value"></a>Valor de retorno

Número de estruturas de acelerador recuperadas.

##  <a name="getbase"></a>  CSpinButtonCtrl::GetBase

Recupera a base atual para um controle de botão de rotação.

```
UINT GetBase() const;
```

### <a name="return-value"></a>Valor de retorno

O valor base atual.

##  <a name="getbuddy"></a>  CSpinButtonCtrl::GetBuddy

Recupera um ponteiro para a janela atual do Buddy.

```
CWnd* GetBuddy() const;
```

### <a name="return-value"></a>Valor de retorno

Um ponteiro para a janela atual do Buddy.

##  <a name="getpos"></a>  CSpinButtonCtrl::GetPos

Recupera a posição atual de um controle de botão de rotação.

```
int GetPos() const;  int GetPos32(LPBOOL lpbError = NULL) const;
```

### <a name="parameters"></a>Parâmetros

*lpbError*<br/>
Um ponteiro para um valor booliano que é definido como zero se o valor for recuperado com êxito ou diferente de zero se ocorrer um erro. Se esse parâmetro for definido como NULL, os erros não serão relatados.

### <a name="return-value"></a>Valor de retorno

A primeira versão retorna a posição atual de 16 bits na palavra de ordem inferior. A palavra de ordem superior será diferente de zero se ocorrer um erro.

A segunda versão retorna a posição de 32 bits.

### <a name="remarks"></a>Comentários

Quando ele processa o valor retornado, o controle atualiza sua posição atual com base na legenda da janela Buddy. O controle retornará um erro se não houver nenhuma janela Buddy ou se a legenda especificar um valor inválido ou fora do intervalo.

##  <a name="getrange"></a>  CSpinButtonCtrl::GetRange

Recupera os limites superior e inferior (intervalo) para um controle de botão de rotação.

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

*lower*<br/>
Referência a um inteiro que recebe o limite inferior do controle.

*upper*<br/>
Referência a um inteiro que recebe o limite superior do controle.

### <a name="return-value"></a>Valor de retorno

A primeira versão retorna um valor de 32 bits contendo os limites superior e inferior. A palavra de ordem inferior é o limite superior para o controle e a palavra de ordem superior é o limite inferior.

### <a name="remarks"></a>Comentários

A função `GetRange32` membro recupera o intervalo do controle botão de rotação como um inteiro de 32 bits.

##  <a name="setaccel"></a>  CSpinButtonCtrl::SetAccel

Define a aceleração de um controle de botão de rotação.

```
BOOL SetAccel(
    int nAccel,
    UDACCEL* pAccel);
```

### <a name="parameters"></a>Parâmetros

*nAccel*<br/>
Número de estruturas [UDACCEL](/windows/win32/api/commctrl/ns-commctrl-udaccel) especificadas por *pAccel*.

*pAccel*<br/>
Ponteiro para uma matriz de estruturas UDACCEL, que contêm informações de aceleração. Os `nSec` elementos devem ser classificados em ordem crescente com base no membro.

### <a name="return-value"></a>Valor de retorno

Diferente de zero, se for bem-sucedido; caso contrário, 0.

##  <a name="setbase"></a>  CSpinButtonCtrl::SetBase

Define a base para um controle de botão de rotação.

```
int SetBase(int nBase);
```

### <a name="parameters"></a>Parâmetros

*nBase*<br/>
Novo valor base para o controle. Pode ser 10 para decimal ou 16 para hexadecimal.

### <a name="return-value"></a>Valor de retorno

O valor base anterior se for bem-sucedido ou zero se uma base inválida for fornecida.

### <a name="remarks"></a>Comentários

O valor base determina se a janela buddy exibe números em dígitos decimais ou hexadecimais. Os números hexadecimais são sempre não assinados; números decimais são assinados.

##  <a name="setbuddy"></a>  CSpinButtonCtrl::SetBuddy

Define a janela Buddy para um controle de botão de rotação.

```
CWnd* SetBuddy(CWnd* pWndBuddy);
```

### <a name="parameters"></a>Parâmetros

*pWndBuddy*<br/>
Ponteiro para a nova janela Buddy.

### <a name="return-value"></a>Valor de retorno

Um ponteiro para a janela do Buddy anterior.

### <a name="remarks"></a>Comentários

Um controle de rotação é quase sempre associado a outra janela, como um controle de edição, que exibe algum conteúdo. Essa outra janela é chamada "Buddy" do controle de rotação.

##  <a name="setpos"></a>  CSpinButtonCtrl::SetPos

Define a posição atual de um controle de botão de rotação.

```
int SetPos(int nPos);
int SetPos32(int nPos);
```

### <a name="parameters"></a>Parâmetros

*nPos*<br/>
Nova posição para o controle. Esse valor deve estar no intervalo especificado pelos limites superior e inferior do controle.

### <a name="return-value"></a>Valor de retorno

A posição anterior (precisão de 16 bits para `SetPos`, precisão de 32 bits para `SetPos32`).

### <a name="remarks"></a>Comentários

`SetPos32`define a posição de 32 bits.

##  <a name="setrange"></a>  CSpinButtonCtrl::SetRange

Define os limites superior e inferior (intervalo) para um controle de botão de rotação.

```
void SetRange(
    short nLower,
    short nUpper);

void SetRange32(
    int nLower,
    int nUpper);
```

### <a name="parameters"></a>Parâmetros

*nLower* e *nUpper*<br/>
Limites superiores e inferiores do controle. Para `SetRange`, nenhum limite pode ser maior que UD_MAXVAL ou menor que UD_MINVAL; além disso, a diferença entre os dois limites não pode exceder UD_MAXVAL. `SetRange32`não impõe restrições nos limites; Use qualquer número inteiro.

### <a name="remarks"></a>Comentários

A função `SetRange32` membro define o intervalo de 32 bits para o controle botão de rotação.

> [!NOTE]
>  O intervalo padrão para o botão de rotação tem o máximo definido como zero (0) e o mínimo definido como 100. Como o valor máximo é menor que o valor mínimo, clicar na seta para cima diminuirá a posição e clicar na seta para baixo irá aumentá-la. Use `CSpinButtonCtrl::SetRange` para ajustar esses valores.

## <a name="see-also"></a>Consulte também

[Exemplo de CMNCTRL2 do MFC](../../overview/visual-cpp-samples.md)<br/>
[Classe CWnd](../../mfc/reference/cwnd-class.md)<br/>
[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classe CSliderCtrl](../../mfc/reference/csliderctrl-class.md)
