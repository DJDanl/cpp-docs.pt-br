---
title: Classe CProgressCtrl
ms.date: 11/04/2016
f1_keywords:
- CProgressCtrl
- AFXCMN/CProgressCtrl
- AFXCMN/CProgressCtrl::CProgressCtrl
- AFXCMN/CProgressCtrl::Create
- AFXCMN/CProgressCtrl::CreateEx
- AFXCMN/CProgressCtrl::GetBarColor
- AFXCMN/CProgressCtrl::GetBkColor
- AFXCMN/CProgressCtrl::GetPos
- AFXCMN/CProgressCtrl::GetRange
- AFXCMN/CProgressCtrl::GetState
- AFXCMN/CProgressCtrl::GetStep
- AFXCMN/CProgressCtrl::OffsetPos
- AFXCMN/CProgressCtrl::SetBarColor
- AFXCMN/CProgressCtrl::SetBkColor
- AFXCMN/CProgressCtrl::SetMarquee
- AFXCMN/CProgressCtrl::SetPos
- AFXCMN/CProgressCtrl::SetRange
- AFXCMN/CProgressCtrl::SetState
- AFXCMN/CProgressCtrl::SetStep
- AFXCMN/CProgressCtrl::StepIt
helpviewer_keywords:
- CProgressCtrl [MFC], CProgressCtrl
- CProgressCtrl [MFC], Create
- CProgressCtrl [MFC], CreateEx
- CProgressCtrl [MFC], GetBarColor
- CProgressCtrl [MFC], GetBkColor
- CProgressCtrl [MFC], GetPos
- CProgressCtrl [MFC], GetRange
- CProgressCtrl [MFC], GetState
- CProgressCtrl [MFC], GetStep
- CProgressCtrl [MFC], OffsetPos
- CProgressCtrl [MFC], SetBarColor
- CProgressCtrl [MFC], SetBkColor
- CProgressCtrl [MFC], SetMarquee
- CProgressCtrl [MFC], SetPos
- CProgressCtrl [MFC], SetRange
- CProgressCtrl [MFC], SetState
- CProgressCtrl [MFC], SetStep
- CProgressCtrl [MFC], StepIt
ms.assetid: 222630f4-1598-4026-8198-51649b1192ab
ms.openlocfilehash: c9e94e334318b32efcf8c9de681a78349ab12151
ms.sourcegitcommit: 7a6116e48c3c11b97371b8ae4ecc23adce1f092d
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/22/2020
ms.locfileid: "81751130"
---
# <a name="cprogressctrl-class"></a>Classe CProgressCtrl

Fornece a funcionalidade do controle da barra de progresso comum do Windows.

## <a name="syntax"></a>Sintaxe

```
class CProgressCtrl : public CWnd
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[CProgressCtrl::CProgressCtrl](#cprogressctrl)|Constrói um objeto `CProgressCtrl`.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CProgressCtrl::Criar](#create)|Cria um controle de barra de `CProgressCtrl` progresso e o anexa a um objeto.|
|[CProgressCtrl::CreateEx](#createex)|Cria um controle de progresso com os estilos estendidos do Windows especificados e o anexa a um `CProgressCtrl` objeto.|
|[CProgressCtrl::GetBarColor](#getbarcolor)|Obtém a cor da barra indicadora de progresso para o controle da barra de progresso atual.|
|[CProgressCtrl::GetBkColor](#getbkcolor)|Obtém a cor de fundo da barra de progresso atual.|
|[CProgressCtrl::GetPos](#getpos)|Obtém a posição atual da barra de progresso.|
|[CProgressCtrl::GetRange](#getrange)|Obtém os limites inferior e superior do alcance do controle da barra de progresso.|
|[CProgressCtrl::GetState](#getstate)|Obtém o estado do controle atual da barra de progresso.|
|[CProgressCtrl::GetStep](#getstep)|Recupera o incremento de passo para a barra de progresso do controle da barra de progresso atual.|
|[CProgressCtrl::OffsetPos](#offsetpos)|Avança a posição atual de um controle de barra de progresso por um incremento especificado e redesenha a barra para refletir a nova posição.|
|[CProgressCtrl::SetBarColor](#setbarcolor)|Define a cor da barra indicadora de progresso no controle da barra de progresso atual.|
|[CProgressCtrl::SetBkColor](#setbkcolor)|Define a cor de fundo para a barra de progresso.|
|[CProgressCtrl::SetMarquee](#setmarquee)|Liga ou desliga o modo letreiro para o controle da barra de progresso atual.|
|[CProgressCtrl::SetPos](#setpos)|Define a posição atual para um controle da barra de progresso e redesenha a barra para refletir a nova posição.|
|[CProgressCtrl::SetRange](#setrange)|Define as faixas mínima e máxima para um controle de barra de progresso e redesenha a barra para refletir as novas faixas.|
|[CProgressCtrl::SetState](#setstate)|Define o estado do controle atual da barra de progresso.|
|[CProgressCtrl::SetStep](#setstep)|Especifica o incremento de etapa para um controle da barra de progresso.|
|[CProgressCtrl::StepIt](#stepit)|Avança a posição atual para um controle de barra de progresso pelo incremento de passo (ver [SetStep](#setstep)) e redesenha a barra para refletir a nova posição.|

## <a name="remarks"></a>Comentários

Um controle de barra de progresso é uma janela que um aplicativo pode usar para indicar o progresso de uma operação demorada. Consiste em um retângulo que é gradualmente preenchido, da esquerda para a direita, com a cor de destaque do sistema à medida que uma operação progride.

Um controle de barra de progresso tem um alcance e uma posição atual. O intervalo representa a duração total da operação, e a posição atual representa o progresso que a aplicação fez para concluir a operação. O procedimento da janela usa o intervalo e a posição atual para determinar a porcentagem da barra de progresso para preencher com a cor de destaque. Como os valores de faixa e posição atual são expressos como inteiros assinados, a possível faixa de valores de posição atual é de -2.147.483.648 a 2.147.483.647 inclusive.

Para obter mais `CProgressCtrl`informações sobre como usar, consulte [Controles](../../mfc/controls-mfc.md) e [Utilização de CProgressCtrl](../../mfc/using-cprogressctrl.md).

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[Cobject](../../mfc/reference/cobject-class.md)

[Ccmdtarget](../../mfc/reference/ccmdtarget-class.md)

[CWnd](../../mfc/reference/cwnd-class.md)

`CProgressCtrl`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxcmn.h

## <a name="cprogressctrlcprogressctrl"></a><a name="cprogressctrl"></a>CProgressCtrl::CProgressCtrl

Constrói um objeto `CProgressCtrl`.

```
CProgressCtrl();
```

### <a name="remarks"></a>Comentários

Depois de `CProgressCtrl` construir o `CProgressCtrl::Create` objeto, chame para criar o controle da barra de progresso.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CProgressCtrl#1](../../mfc/reference/codesnippet/cpp/cprogressctrl-class_1.cpp)]

## <a name="cprogressctrlcreate"></a><a name="create"></a>CProgressCtrl::Criar

Cria um controle de barra de `CProgressCtrl` progresso e o anexa a um objeto.

```
virtual BOOL Create(
    DWORD dwStyle,
    const RECT& rect,
    CWnd* pParentWnd,
    UINT nID);
```

### <a name="parameters"></a>Parâmetros

*Dwstyle*<br/>
Especifica o estilo do controle da barra de progresso. Aplique qualquer combinação de estilos de janeladescritos no [CreateWindow](/windows/win32/api/winuser/nf-winuser-createwindoww) no SDK do Windows, além dos seguintes estilos de controle de barras de progresso, ao controle:

- PBS_VERTICAL exibe informações de progresso verticalmente, de cima para baixo. Sem esta bandeira, o controle da barra de progresso é exibido horizontalmente, da esquerda para a direita.

- PBS_SMOOTH Exibe o preenchimento gradual e suave no controle da barra de progresso. Sem esta bandeira, o controle se encherá de blocos.

*Rect*<br/>
Especifica o tamanho e a posição da barra de progresso. Pode ser um objeto [CRect](../../atl-mfc-shared/reference/crect-class.md) ou uma estrutura [RECT.](/windows/win32/api/windef/ns-windef-rect) Como o controle deve ser uma janela filho, as coordenadas especificadas são relativas à área cliente do *pParentWnd*.

*Pparentwnd*<br/>
Especifica a janela pai da barra de `CDialog`progresso, geralmente a . Não deve ser NULO.

*nID*<br/>
Especifica o ID da barra de progresso.

### <a name="return-value"></a>Valor retornado

TRUE se `CProgressCtrl` o objeto for criado com sucesso; caso contrário, FALSO.

### <a name="remarks"></a>Comentários

Você constrói `CProgressCtrl` um objeto em dois passos. Primeiro, chame o construtor, `CProgressCtrl` que cria o `Create`objeto, e depois chame , o que cria o controle da barra de progresso.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CProgressCtrl#2](../../mfc/reference/codesnippet/cpp/cprogressctrl-class_2.cpp)]

## <a name="cprogressctrlcreateex"></a><a name="createex"></a>CProgressCtrl::CreateEx

Cria um controle (uma janela filho) `CProgressCtrl` e o associa ao objeto.

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
Especifica o estilo do controle da barra de progresso. Aplique qualquer combinação de estilos de janela descritos no [CreateWindow](/windows/win32/api/winuser/nf-winuser-createwindoww) no Windows SDK.

*Rect*<br/>
Uma referência a uma estrutura [RECT](/windows/win32/api/windef/ns-windef-rect) descrevendo o tamanho e a posição da janela a ser criada, em coordenadas de cliente de *pParentWnd*.

*Pparentwnd*<br/>
Um ponteiro para a janela que é o pai do controle.

*nID*<br/>
A id da janela infantil do controle.

### <a name="return-value"></a>Valor retornado

Não zero se bem sucedido; caso contrário, 0.

### <a name="remarks"></a>Comentários

Use `CreateEx` em vez de [Criar](#create) para aplicar estilos estendidos do Windows, especificados pelo prefácio de estilo estendido do Windows **WS_EX_**.

## <a name="cprogressctrlgetbarcolor"></a><a name="getbarcolor"></a>CProgressCtrl::GetBarColor

Obtém a cor da barra indicadora de progresso para o controle da barra de progresso atual.

```
COLORREF GetBarColor() const;
```

### <a name="return-value"></a>Valor retornado

A cor da barra de progresso atual, representada como um valor [COLORREF,](/windows/win32/gdi/colorref) ou CLR_DEFAULT se a cor da barra indicadora de progresso for a cor padrão.

### <a name="remarks"></a>Comentários

Este método envia a mensagem [PBM_GETBARCOLOR,](/windows/win32/Controls/pbm-getbarcolor) que é descrita no SDK do Windows.

## <a name="cprogressctrlgetbkcolor"></a><a name="getbkcolor"></a>CProgressCtrl::GetBkColor

Obtém a cor de fundo da barra de progresso atual.

```
COLORREF GetBkColor() const;
```

### <a name="return-value"></a>Valor retornado

A cor de fundo da barra de progresso atual, representada como um valor [COLORREF.](/windows/win32/gdi/colorref)

### <a name="remarks"></a>Comentários

Este método envia a mensagem [PBM_GETBKCOLOR,](/windows/win32/Controls/pbm-getbkcolor) que é descrita no SDK do Windows.

## <a name="cprogressctrlgetpos"></a><a name="getpos"></a>CProgressCtrl::GetPos

Recupera a posição atual da barra de progresso.

```
int GetPos();
```

### <a name="return-value"></a>Valor retornado

A posição do controle da barra de progresso.

### <a name="remarks"></a>Comentários

A posição do controle da barra de progresso não é a localização física na tela, mas sim entre a faixa superior e inferior indicada em [SetRange](#setrange).

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CProgressCtrl#3](../../mfc/reference/codesnippet/cpp/cprogressctrl-class_3.cpp)]

## <a name="cprogressctrlgetrange"></a><a name="getrange"></a>CProgressCtrl::GetRange

Obtém os limites inferiores e superiores atuais, ou alcance, do controle da barra de progresso.

```cpp
void GetRange(
    int& nLower,
    int& nUpper);
```

### <a name="parameters"></a>Parâmetros

*Nlower*<br/>
Uma referência a um inteiro recebendo o limite inferior do controle da barra de progresso.

*Nupper*<br/>
Uma referência a um inteiro recebendo o limite superior do controle da barra de progresso.

### <a name="remarks"></a>Comentários

Esta função copia os valores dos limites inferior e superior para os inteiros referenciados por *nLower* e *nUpper,* respectivamente.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CProgressCtrl#4](../../mfc/reference/codesnippet/cpp/cprogressctrl-class_4.cpp)]

## <a name="cprogressctrlgetstate"></a><a name="getstate"></a>CProgressCtrl::GetState

Obtém o estado do controle atual da barra de progresso.

```
int GetState() const;
```

### <a name="return-value"></a>Valor retornado

O estado do controle atual da barra de progresso, que é um dos seguintes valores:

|Valor|Estado|
|-----------|-----------|
|PBST_NORMAL|Em andamento|
|PBST_ERROR|Erro|
|PBST_PAUSED|Em Pausa|

### <a name="remarks"></a>Comentários

Este método envia a [mensagem PBM_GETSTATE,](/windows/win32/Controls/pbm-getstate) que é descrita no SDK do Windows.

### <a name="example"></a>Exemplo

O exemplo de código a `m_progressCtrl`seguir define a variável, que é usada para acessar programáticamente o controle da barra de progresso. Esta variável é usada no próximo exemplo.

[!code-cpp[NVC_MFC_CProgressCtrl_s1#9](../../mfc/reference/codesnippet/cpp/cprogressctrl-class_5.h)]

### <a name="example"></a>Exemplo

O exemplo de código a seguir recupera o estado do controle atual da barra de progresso.

[!code-cpp[NVC_MFC_CProgressCtrl_s1#5](../../mfc/reference/codesnippet/cpp/cprogressctrl-class_6.cpp)]

## <a name="cprogressctrlgetstep"></a><a name="getstep"></a>CProgressCtrl::GetStep

Recupera o incremento de passo para a barra de progresso do controle da barra de progresso atual.

```
int GetStep() const;
```

### <a name="return-value"></a>Valor retornado

O incremento de passo da barra de progresso.

### <a name="remarks"></a>Comentários

O incremento de etapa é o valor pelo qual uma chamada para [CProgressCtrl::StepEle](#stepit) aumenta a posição atual da barra de progresso.

Este método envia a [mensagem PBM_GETSTEP,](/windows/win32/Controls/pbm-getstep) que é descrita no SDK do Windows.

### <a name="example"></a>Exemplo

O exemplo de código a `m_progressCtrl`seguir define a variável, que é usada para acessar programáticamente o controle da barra de progresso. Esta variável é usada no próximo exemplo.

[!code-cpp[NVC_MFC_CProgressCtrl_s1#9](../../mfc/reference/codesnippet/cpp/cprogressctrl-class_5.h)]

### <a name="example"></a>Exemplo

O exemplo de código a seguir recupera o incremento de etapa do controle da barra de progresso atual.

[!code-cpp[NVC_MFC_CProgressCtrl_s1#3](../../mfc/reference/codesnippet/cpp/cprogressctrl-class_7.cpp)]

## <a name="cprogressctrloffsetpos"></a><a name="offsetpos"></a>CProgressCtrl::OffsetPos

Avança a posição atual do controle da barra de progresso pelo incremento especificado pelos *nPos* e redesenha a barra para refletir a nova posição.

```
int OffsetPos(int nPos);
```

### <a name="parameters"></a>Parâmetros

*Npos*<br/>
Valor para adiantar a posição.

### <a name="return-value"></a>Valor retornado

A posição anterior do controle da barra de progresso.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CProgressCtrl#5](../../mfc/reference/codesnippet/cpp/cprogressctrl-class_8.cpp)]

## <a name="cprogressctrlsetbarcolor"></a><a name="setbarcolor"></a>CProgressCtrl::SetBarColor

Define a cor da barra indicadora de progresso no controle da barra de progresso atual.

```
COLORREF SetBarColor(COLORREF clrBar);
```

### <a name="parameters"></a>Parâmetros

|Parâmetro|Descrição|
|---------------|-----------------|
|*clrBar*|[em] Um valor [COLORREF](/windows/win32/gdi/colorref) que especifica a nova cor da barra indicadora de progresso. Especifique CLR_DEFAULT para fazer com que a barra de progresso use sua cor padrão.|

### <a name="return-value"></a>Valor retornado

A cor anterior da barra indicadora de progresso, representada como um valor [COLORREF,](/windows/win32/gdi/colorref) ou CLR_DEFAULT se a cor da barra indicadora de progresso for a cor padrão.

### <a name="remarks"></a>Comentários

O `SetBarColor` método define a cor da barra de progresso somente se um [tema do](/windows/win32/Controls/visual-styles-overview) Windows Vista não estiver em vigor.

Este método envia a mensagem [PBM_SETBARCOLOR,](/windows/win32/Controls/pbm-setbarcolor) que é descrita no SDK do Windows.

### <a name="example"></a>Exemplo

O exemplo de código a `m_progressCtrl`seguir define a variável, que é usada para acessar programáticamente o controle da barra de progresso. Esta variável é usada no próximo exemplo.

[!code-cpp[NVC_MFC_CProgressCtrl_s1#9](../../mfc/reference/codesnippet/cpp/cprogressctrl-class_5.h)]

### <a name="example"></a>Exemplo

O exemplo de código a seguir altera a cor da barra de progresso para vermelho, verde, azul ou padrão.

[!code-cpp[NVC_MFC_CProgressCtrl_s1#1](../../mfc/reference/codesnippet/cpp/cprogressctrl-class_9.cpp)]

## <a name="cprogressctrlsetbkcolor"></a><a name="setbkcolor"></a>CProgressCtrl::SetBkColor

Define a cor de fundo para a barra de progresso.

```
COLORREF SetBkColor(COLORREF clrNew);
```

### <a name="parameters"></a>Parâmetros

*clrNew*<br/>
Um valor COLORREF que especifica a nova cor de fundo. Especifique o valor CLR_DEFAULT para usar a cor de fundo padrão para a barra de progresso.

### <a name="return-value"></a>Valor retornado

O valor [COLORREF](/windows/win32/gdi/colorref) indica a cor de fundo anterior ou CLR_DEFAULT se a cor de fundo for a cor padrão.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CProgressCtrl#6](../../mfc/reference/codesnippet/cpp/cprogressctrl-class_10.cpp)]

## <a name="cprogressctrlsetmarquee"></a><a name="setmarquee"></a>CProgressCtrl::SetMarquee

Liga ou desliga o modo letreiro para o controle da barra de progresso atual.

```
BOOL SetMarquee(
    BOOL fMarqueeMode,
    int nInterval);
```

### <a name="parameters"></a>Parâmetros

|Parâmetro|Descrição|
|---------------|-----------------|
|*fMarqueeMode*|[em] TRUE para ativar o modo letreiro ou FALSE para desativar o modo de letreiro.|
|*nInterval*|[em] Tempo em milissegundos entre as atualizações da animação do letreiro.|

### <a name="return-value"></a>Valor retornado

Este método sempre retorna TRUE.

### <a name="remarks"></a>Comentários

Quando o modo letreiro é ligado, a barra de progresso é animada e rola como um sinal em uma marquise de teatro.

Este método envia a [mensagem PBM_SETMARQUEE,](/windows/win32/Controls/pbm-setmarquee) que é descrita no SDK do Windows.

### <a name="example"></a>Exemplo

O exemplo de código a `m_progressCtrl`seguir define a variável, que é usada para acessar programáticamente o controle da barra de progresso. Esta variável é usada no próximo exemplo.

[!code-cpp[NVC_MFC_CProgressCtrl_s1#9](../../mfc/reference/codesnippet/cpp/cprogressctrl-class_5.h)]

### <a name="example"></a>Exemplo

O exemplo de código a seguir inicia e interrompe a animação de rolagem do letreiro.

[!code-cpp[NVC_MFC_CProgressCtrl_s1#2](../../mfc/reference/codesnippet/cpp/cprogressctrl-class_11.cpp)]

## <a name="cprogressctrlsetpos"></a><a name="setpos"></a>CProgressCtrl::SetPos

Define a posição atual da barra de progresso conforme especificado por *nPos* e redesenha a barra para refletir a nova posição.

```
int SetPos(int nPos);
```

### <a name="parameters"></a>Parâmetros

*Npos*<br/>
Nova posição do controle da barra de progresso.

### <a name="return-value"></a>Valor retornado

A posição anterior do controle da barra de progresso.

### <a name="remarks"></a>Comentários

A posição do controle da barra de progresso não é a localização física na tela, mas sim entre a faixa superior e inferior indicada em [SetRange](#setrange).

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CProgressCtrl#7](../../mfc/reference/codesnippet/cpp/cprogressctrl-class_12.cpp)]

## <a name="cprogressctrlsetrange"></a><a name="setrange"></a>CProgressCtrl::SetRange

Define os limites superiore e inferior do alcance da barra de progresso e redesenha a barra para refletir as novas faixas.

```cpp
void SetRange(
    short nLower,
    short nUpper);

void SetRange32(
    int nLower,
    int nUpper);
```

### <a name="parameters"></a>Parâmetros

*Nlower*<br/>
Especifica o limite inferior do intervalo (padrão é zero).

*Nupper*<br/>
Especifica o limite superior do intervalo (padrão é 100).

### <a name="remarks"></a>Comentários

A função `SetRange32` do membro define o intervalo de 32 bits para o controle de progresso.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CProgressCtrl#8](../../mfc/reference/codesnippet/cpp/cprogressctrl-class_13.cpp)]

## <a name="cprogressctrlsetstate"></a><a name="setstate"></a>CProgressCtrl::SetState

Define o estado do controle atual da barra de progresso.

```
int SetState(int iState);
```

### <a name="parameters"></a>Parâmetros

|Parâmetro|Descrição|
|---------------|-----------------|
|*Istate*|[em] O Estado para definir a barra de progresso. Use um dos seguintes valores:<br /><br /> - PBST_NORMAL - Em andamento<br />- PBST_ERROR - Erro<br />- PBST_PAUSED - Pausado|

### <a name="return-value"></a>Valor retornado

O estado anterior do controle atual da barra de progresso.

### <a name="remarks"></a>Comentários

Este método envia a mensagem [PBM_SETSTATE,](/windows/win32/Controls/pbm-setstate) que é descrita no SDK do Windows.

### <a name="example"></a>Exemplo

O exemplo de código a `m_progressCtrl`seguir define a variável, que é usada para acessar programáticamente o controle da barra de progresso. Esta variável é usada no próximo exemplo.

[!code-cpp[NVC_MFC_CProgressCtrl_s1#9](../../mfc/reference/codesnippet/cpp/cprogressctrl-class_5.h)]

### <a name="example"></a>Exemplo

O exemplo de código a seguir define o estado do controle da barra de progresso atual para Pausado ou Em Andamento.

[!code-cpp[NVC_MFC_CProgressCtrl_s1#4](../../mfc/reference/codesnippet/cpp/cprogressctrl-class_14.cpp)]

## <a name="cprogressctrlsetstep"></a><a name="setstep"></a>CProgressCtrl::SetStep

Especifica o incremento de etapa para um controle da barra de progresso.

```
int SetStep(int nStep);
```

### <a name="parameters"></a>Parâmetros

*nStep*<br/>
Novo incremento de passo.

### <a name="return-value"></a>Valor retornado

O incremento da etapa anterior.

### <a name="remarks"></a>Comentários

O incremento de passo é `CProgressCtrl::StepIt` o valor pelo qual uma chamada para aumentar a posição atual da barra de progresso.

O incremento da etapa padrão é de 10.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CProgressCtrl#9](../../mfc/reference/codesnippet/cpp/cprogressctrl-class_15.cpp)]

## <a name="cprogressctrlstepit"></a><a name="stepit"></a>CProgressCtrl::StepIt

Avança a posição atual para um controle da barra de progresso pelo incremento da etapa e redesenha a barra para refletir a nova posição.

```
int StepIt();
```

### <a name="return-value"></a>Valor retornado

A posição anterior do controle da barra de progresso.

### <a name="remarks"></a>Comentários

O incremento de `CProgressCtrl::SetStep` passo é definido pela função do membro.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CProgressCtrl#10](../../mfc/reference/codesnippet/cpp/cprogressctrl-class_16.cpp)]

## <a name="see-also"></a>Confira também

[Amostra de MFC CMNCTRL2](../../overview/visual-cpp-samples.md)<br/>
[Classe CWnd](../../mfc/reference/cwnd-class.md)<br/>
[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)
