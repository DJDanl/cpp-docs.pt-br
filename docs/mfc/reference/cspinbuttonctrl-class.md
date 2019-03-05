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
ms.openlocfilehash: 3c973d92550469804a5389b84f53005e4f2c154f
ms.sourcegitcommit: c3093251193944840e3d0a068ecc30e6449624ba
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/04/2019
ms.locfileid: "57290424"
---
# <a name="cspinbuttonctrl-class"></a>Classe CSpinButtonCtrl

Fornece a funcionalidade do controle de botão de rotação comum do Windows.

## <a name="syntax"></a>Sintaxe

```
class CSpinButtonCtrl : public CWnd
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores Públicos

|Nome|Descrição|
|----------|-----------------|
|[CSpinButtonCtrl::CSpinButtonCtrl](#cspinbuttonctrl)|Constrói um objeto `CSpinButtonCtrl`.|

### <a name="public-methods"></a>Métodos Públicos

|Nome|Descrição|
|----------|-----------------|
|[CSpinButtonCtrl::Create](#create)|Cria um controle de botão de rotação e anexa-o para um `CSpinButtonCtrl` objeto.|
|[CSpinButtonCtrl::CreateEx](#createex)|Cria um controle de botão de rotação com os estilos estendidos do Windows especificados e anexa-o para um `CSpinButtonCtrl` objeto.|
|[CSpinButtonCtrl::GetAccel](#getaccel)|Recupera informações de aceleração para um controle de botão de rotação.|
|[CSpinButtonCtrl::GetBase](#getbase)|Recupera a base atual para um controle de botão de rotação.|
|[CSpinButtonCtrl::GetBuddy](#getbuddy)|Recupera um ponteiro para a janela buddy atual.|
|[CSpinButtonCtrl::GetPos](#getpos)|Recupera a posição atual de um controle de botão de rotação.|
|[CSpinButtonCtrl::GetRange](#getrange)|Recupera os limites superiores e inferiores (intervalo) para um controle de botão de rotação.|
|[CSpinButtonCtrl::SetAccel](#setaccel)|Define a aceleração de um controle de botão de rotação.|
|[CSpinButtonCtrl::SetBase](#setbase)|Define a base para um controle de botão de rotação.|
|[CSpinButtonCtrl::SetBuddy](#setbuddy)|Define a janela buddy para um controle de botão de rotação.|
|[CSpinButtonCtrl::SetPos](#setpos)|Define a posição atual para o controle.|
|[CSpinButtonCtrl::SetRange](#setrange)|Define os limites superiores e inferiores (intervalo) para um controle de botão de rotação.|

## <a name="remarks"></a>Comentários

Um "botão controle de rotação" (também conhecido como um controle superior / inferior) é um par de botões de seta para que o usuário pode clicar para incrementar ou decrementar um valor, como uma posição de rolagem ou um número exibido em um controle complementar. O valor associado a um controle de botão de rotação é chamado de sua posição atual. Um controle de botão de rotação com mais frequência é usado com um controle complementar, chamado de "janela secundária".

Esse controle (e, portanto, o `CSpinButtonCtrl` classe) está disponível somente para programas executados na versão do Windows 95/98 e Windows NT 3.51 e posterior.

Para o usuário, um controle de botão de rotação e sua janela buddy muitas vezes parecer um único controle. Você pode especificar que um controle de botão de rotação automaticamente se posiciona ao lado de sua janela buddy e que ela definir automaticamente a legenda da janela buddy na posição atual. Você pode usar um controle de botão de rotação com um controle de edição para solicitar ao usuário para entrada numérica.

Clicar na seta para cima move a posição atual em direção ao máximo e clicar na seta para baixo move a posição atual em direção ao mínimo. Por padrão, o mínimo é de 100 e o máximo é de 0. Sempre que a configuração mínima é maior que o máximo de configuração (por exemplo, quando são usadas as configurações padrão), clicando no diminui de seta para cima o valor da posição e clicando na seta para baixo aumenta a ele.

Um controle de botão de rotação sem uma janela buddy funciona como uma espécie de barra de rolagem simplificada. Por exemplo, um controle guia, às vezes, exibe um controle de botão de rotação para permitir que o usuário rolar guias adicionais no modo de exibição.

Para obter mais informações sobre como usar `CSpinButtonCtrl`, consulte [controles](../../mfc/controls-mfc.md) e [usando CSpinButtonCtrl](../../mfc/using-cspinbuttonctrl.md).

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[CObject](../../mfc/reference/cobject-class.md)

[CCmdTarget](../../mfc/reference/ccmdtarget-class.md)

[CWnd](../../mfc/reference/cwnd-class.md)

`CSpinButtonCtrl`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxcmn. h

##  <a name="create"></a>  CSpinButtonCtrl::Create

Cria um controle de botão de rotação e anexa-o para um `CSpinButtonCtrl` objeto...

```
virtual BOOL Create(
    DWORD dwStyle,
    const RECT& rect,
    CWnd* pParentWnd,
    UINT nID);
```

### <a name="parameters"></a>Parâmetros

*dwStyle*<br/>
Especifica o estilo do controle de botão de rotação. Aplica qualquer combinação de estilos de controle de botão de rotação para o controle. Esses estilos são descritos em [estilos de controle para cima para baixo](/windows/desktop/Controls/up-down-control-styles) no SDK do Windows.

*rect*<br/>
Especifica o tamanho e a posição do controle de botão de rotação. Ela pode ser um [CRect](../../atl-mfc-shared/reference/crect-class.md) objeto ou uma [RECT](https://msdn.microsoft.com/library/windows/desktop/dd162897) estrutura

*pParentWnd*<br/>
Um ponteiro para a janela do pai do controle de botão de rotação, geralmente um `CDialog`. Ele não deve ser NULL.

*nID*<br/>
Especifica a ID. do controle de botão de rotação

### <a name="return-value"></a>Valor de retorno

Diferente de zero se a inicialização foi bem-sucedida; Caso contrário, 0.

### <a name="remarks"></a>Comentários

Você constrói uma `CSpinButtonCtrl` pela primeira vez do objeto em duas etapas, chame o construtor e, em seguida, chamar `Create`, que cria o controle de botão de rotação e anexa-o para o `CSpinButtonCtrl` objeto.

Para criar um controle de botão de rotação com estilos de janela estendidos, chame [CSpinButtonCtrl::CreateEx](#createex) em vez de `Create`.

##  <a name="createex"></a>  CSpinButtonCtrl::CreateEx

Cria um controle (uma janela filho) e o associa a `CSpinButtonCtrl` objeto.

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
Especifica o estilo estendido do controle que está sendo criado. Para obter uma lista dos estilos estendidos do windows, consulte o *dwExStyle* parâmetro para [CreateWindowEx](/windows/desktop/api/winuser/nf-winuser-createwindowexa) no SDK do Windows.

*dwStyle*<br/>
Especifica o estilo do controle de botão de rotação. Aplica qualquer combinação de estilos de controle de botão de rotação para o controle. Esses estilos são descritos em [estilos de controle para cima para baixo](/windows/desktop/Controls/up-down-control-styles) no SDK do Windows.

*rect*<br/>
Uma referência a um [RECT](https://msdn.microsoft.com/library/windows/desktop/dd162897) estrutura que descreve o tamanho e posição da janela a ser criado, em coordenadas do cliente do *pParentWnd*.

*pParentWnd*<br/>
Um ponteiro para a janela que é o pai do controle.

*nID*<br/>
ID da janela filho. do controle

### <a name="return-value"></a>Valor de retorno

Diferente de zero se bem-sucedido; Caso contrário, 0.

### <a name="remarks"></a>Comentários

Use `CreateEx` em vez de [criar](#create) para aplicar estilos estendidos do Windows, especificados pelo prefácio de estilo estendido do Windows WS_EX_.

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
Ponteiro para uma matriz de [UDACCEL](/windows/desktop/api/commctrl/ns-commctrl-_udaccel) estruturas que recebe informações de aceleração.

### <a name="return-value"></a>Valor de retorno

Número de estruturas de acelerador recuperados.

##  <a name="getbase"></a>  CSpinButtonCtrl::GetBase

Recupera a base atual para um controle de botão de rotação.

```
UINT GetBase() const;
```

### <a name="return-value"></a>Valor de retorno

O valor base atual.

##  <a name="getbuddy"></a>  CSpinButtonCtrl::GetBuddy

Recupera um ponteiro para a janela buddy atual.

```
CWnd* GetBuddy() const;
```

### <a name="return-value"></a>Valor de retorno

Um ponteiro para a janela buddy atual.

##  <a name="getpos"></a>  CSpinButtonCtrl::GetPos

Recupera a posição atual de um controle de botão de rotação.

```
int GetPos() const;  int GetPos32(LPBOOL lpbError = NULL) const;
```

### <a name="parameters"></a>Parâmetros

*lpbError*<br/>
Um ponteiro para um valor booliano que é definido como zero se o valor é recuperado com êxito ou zero se ocorrer um erro. Se esse parâmetro for definido como NULL, não são relatados erros.

### <a name="return-value"></a>Valor de retorno

A primeira versão retorna a posição atual de 16 bits da palavra de ordem inferior. A palavra de ordem alta é diferente de zero se ocorreu um erro.

A segunda versão retorna a posição de 32 bits.

### <a name="remarks"></a>Comentários

Quando ele processa o valor retornado, o controle atualiza sua posição atual com base na legenda de janela buddy. O controle retornará um erro se não houver nenhuma janela buddy ou se a legenda Especifica um valor inválido ou fora do intervalo.

##  <a name="getrange"></a>  CSpinButtonCtrl::GetRange

Recupera os limites superiores e inferiores (intervalo) para um controle de botão de rotação.

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
Referência a um número inteiro que recebe o limite inferior para o controle.

*upper*<br/>
Referência a um número inteiro que recebe o limite superior para o controle.

### <a name="return-value"></a>Valor de retorno

A primeira versão retorna um valor de 32 bits que contém os limites superiores e inferiores. A palavra de ordem inferior é o limite superior para o controle e a palavra de ordem superior é o limite inferior.

### <a name="remarks"></a>Comentários

A função de membro `GetRange32` recupera o intervalo do controle de botão de rotação como um inteiro de 32 bits.

##  <a name="setaccel"></a>  CSpinButtonCtrl::SetAccel

Define a aceleração de um controle de botão de rotação.

```
BOOL SetAccel(
    int nAccel,
    UDACCEL* pAccel);
```

### <a name="parameters"></a>Parâmetros

*nAccel*<br/>
Número de [UDACCEL](/windows/desktop/api/commctrl/ns-commctrl-_udaccel) estruturas especificadas por *pAccel*.

*pAccel*<br/>
Ponteiro para uma matriz de estruturas UDACCEL, que contêm informações de aceleração. Elementos devem ser classificados em ordem crescente com base no `nSec` membro.

### <a name="return-value"></a>Valor de retorno

Diferente de zero se bem-sucedido; Caso contrário, 0.

##  <a name="setbase"></a>  CSpinButtonCtrl::SetBase

Define a base para um controle de botão de rotação.

```
int SetBase(int nBase);
```

### <a name="parameters"></a>Parâmetros

*nBase*<br/>
Novo valor de base para o controle. Ele pode ser 10 para decimal ou 16 para hexadecimal.

### <a name="return-value"></a>Valor de retorno

O valor base anterior, se for bem-sucedido, ou zero se for fornecida a uma base inválida.

### <a name="remarks"></a>Comentários

O valor base determina se a janela buddy exibe números em dígitos decimais ou hexadecimais. Números hexadecimais são sempre não assinados; números decimais são assinados.

##  <a name="setbuddy"></a>  CSpinButtonCtrl::SetBuddy

Define a janela buddy para um controle de botão de rotação.

```
CWnd* SetBuddy(CWnd* pWndBuddy);
```

### <a name="parameters"></a>Parâmetros

*pWndBuddy*<br/>
Ponteiro para a nova janela buddy.

### <a name="return-value"></a>Valor de retorno

Um ponteiro para a janela buddy anterior.

### <a name="remarks"></a>Comentários

Um controle de rotação é quase sempre associado a outra janela, como um controle de edição, que exibe a parte do conteúdo. Essa é outra janela é chamada de "buddy" do controle de rotação.

##  <a name="setpos"></a>  CSpinButtonCtrl::SetPos

Define a posição atual para um controle de botão de rotação.

```
int SetPos(int nPos);
int SetPos32(int nPos);
```

### <a name="parameters"></a>Parâmetros

*nPos*<br/>
Nova posição do controle. Esse valor deve estar no intervalo especificado pelos limites superiores e inferiores para o controle.

### <a name="return-value"></a>Valor de retorno

A posição anterior (16 bits de precisão para `SetPos`de 32 bits precision para `SetPos32`).

### <a name="remarks"></a>Comentários

`SetPos32` Define a posição de 32 bits.

##  <a name="setrange"></a>  CSpinButtonCtrl::SetRange

Define os limites superiores e inferiores (intervalo) para um controle de botão de rotação.

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
Limites superiores e inferiores para o controle. Para `SetRange`, nenhum limite pode ser maior que UD_MAXVAL ou menor que UD_MINVAL; Além disso, a diferença entre os dois limites não pode exceder UD_MAXVAL. `SetRange32` não coloca nenhuma restrição sobre os limites; Use números inteiros.

### <a name="remarks"></a>Comentários

A função de membro `SetRange32` define o intervalo de 32 bits para o controle de botão de rotação.

> [!NOTE]
>  O intervalo padrão para o botão de rotação tem o máximo definido como zero (0) e o mínimo definido como 100. Como o valor máximo é menor que o valor mínimo, clicando na seta para cima diminuirá a posição e clicando na seta para baixo será aumentá-lo. Use `CSpinButtonCtrl::SetRange` para ajustar esses valores.

## <a name="see-also"></a>Consulte também

[CMNCTRL2 de exemplo do MFC](../../visual-cpp-samples.md)<br/>
[Classe CWnd](../../mfc/reference/cwnd-class.md)<br/>
[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classe CSliderCtrl](../../mfc/reference/csliderctrl-class.md)
