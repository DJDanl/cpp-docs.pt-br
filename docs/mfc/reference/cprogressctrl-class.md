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
ms.openlocfilehash: 15241485278f09d16c86fc7274f2fc1d85a7a2f7
ms.sourcegitcommit: c7f90df497e6261764893f9cc04b5d1f1bf0b64b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/05/2019
ms.locfileid: "58778943"
---
# <a name="cprogressctrl-class"></a>Classe CProgressCtrl

Fornece a funcionalidade do controle de barra de progresso comuns do Windows.

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
|[CProgressCtrl::Create](#create)|Cria um controle de barra de progresso e anexa-o para um `CProgressCtrl` objeto.|
|[CProgressCtrl::CreateEx](#createex)|Cria um controle de progresso com os estilos estendidos do Windows especificados e anexa-o para um `CProgressCtrl` objeto.|
|[CProgressCtrl::GetBarColor](#getbarcolor)|Obtém a cor da barra do indicador de progresso para o controle de barra de progresso atual.|
|[CProgressCtrl::GetBkColor](#getbkcolor)|Obtém a cor do plano de fundo da barra de progresso atual.|
|[CProgressCtrl::GetPos](#getpos)|Obtém a posição atual da barra de progresso.|
|[CProgressCtrl::GetRange](#getrange)|Obtém os limites superiores e inferiores do intervalo de controle de barra de progresso.|
|[CProgressCtrl::GetState](#getstate)|Obtém o estado do controle de barra de progresso atual.|
|[CProgressCtrl::GetStep](#getstep)|Recupera o incremento de etapa para a barra de progresso do controle de barra de progresso atual.|
|[CProgressCtrl::OffsetPos](#offsetpos)|Avança a posição atual de um controle de barra de progresso por um incremento especificado e o redesenha a barra para refletir a nova posição.|
|[CProgressCtrl::SetBarColor](#setbarcolor)|Define a cor da barra do indicador de progresso no controle de barra de progresso atual.|
|[CProgressCtrl::SetBkColor](#setbkcolor)|Define a cor de plano de fundo para a barra de progresso.|
|[CProgressCtrl::SetMarquee](#setmarquee)|Desativa o modo de marca de seleção ativada ou desativada para o controle de barra de progresso atual.|
|[CProgressCtrl::SetPos](#setpos)|Define a posição atual para um controle de barra de progresso e o redesenha a barra para refletir a nova posição.|
|[CProgressCtrl::SetRange](#setrange)|Define os intervalos mínimos e máximo para um controle de barra de progresso e o redesenha a barra para refletir os novos intervalos.|
|[CProgressCtrl::SetState](#setstate)|Define o estado do controle de barra de progresso atual.|
|[CProgressCtrl::SetStep](#setstep)|Especifica o incremento de etapa de um controle de barra de progresso.|
|[CProgressCtrl::StepIt](#stepit)|Avança a posição atual para um controle de barra de progresso até o incremento de etapa (consulte [SetStep](#setstep)) e o redesenha a barra para refletir a nova posição.|

## <a name="remarks"></a>Comentários

Um controle de barra de progresso é uma janela que um aplicativo pode usar para indicar o progresso de uma operação demorada. Ele consiste em um retângulo que é preenchido, da esquerda para a direita, com o sistema de cor de realce como uma operação progride.

Um controle de barra de progresso tem um intervalo e uma posição atual. O intervalo representa a duração total da operação e a posição atual representa o progresso que o aplicativo fez para concluir a operação. O procedimento de janela usa o intervalo e a posição atual para determinar a porcentagem da barra de progresso para preencher com a cor de realce. Porque o intervalo e os valores de posição atual são expressas como inteiros com sinal, o intervalo possível de valores de posição atual é de -2.147.483.648 a 2.147.483.647 inclusivo.

Para obter mais informações sobre como usar `CProgressCtrl`, consulte [controles](../../mfc/controls-mfc.md) e [usando CProgressCtrl](../../mfc/using-cprogressctrl.md).

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[CObject](../../mfc/reference/cobject-class.md)

[CCmdTarget](../../mfc/reference/ccmdtarget-class.md)

[CWnd](../../mfc/reference/cwnd-class.md)

`CProgressCtrl`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxcmn. h

##  <a name="cprogressctrl"></a>  CProgressCtrl::CProgressCtrl

Constrói um objeto `CProgressCtrl`.

```
CProgressCtrl();
```

### <a name="remarks"></a>Comentários

Depois de construir o `CProgressCtrl` do objeto, chame `CProgressCtrl::Create` para criar o controle de barra de progresso.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CProgressCtrl#1](../../mfc/reference/codesnippet/cpp/cprogressctrl-class_1.cpp)]

##  <a name="create"></a>  CProgressCtrl::Create

Cria um controle de barra de progresso e anexa-o para um `CProgressCtrl` objeto.

```
virtual BOOL Create(
    DWORD dwStyle,
    const RECT& rect,
    CWnd* pParentWnd,
    UINT nID);
```

### <a name="parameters"></a>Parâmetros

*dwStyle*<br/>
Especifica o estilo do controle de barra de progresso. Aplicar qualquer combinação de janela stylesdescribed na [CreateWindow](/windows/desktop/api/winuser/nf-winuser-createwindowa) no SDK do Windows, além de barra estilos de controle para o controle de progresso seguinte:

- PBS_VERTICAL exibe informações de andamento verticalmente, de cima para baixo. Sem esse sinalizador, o controle de barra de progresso exibe horizontalmente, da esquerda para a direita.

- Gradual de PBS_SMOOTH exibe, suave de preenchimento no controle de barra de progresso. Sem esse sinalizador, o controle preencherá com blocos.

*rect*<br/>
Especifica o tamanho e a posição do controle de barra de progresso. Ela pode ser um [CRect](../../atl-mfc-shared/reference/crect-class.md) objeto ou uma [RECT](/previous-versions/dd162897\(v=vs.85\)) estrutura. Como o controle deve ser uma janela filho, as coordenadas especificadas são em relação à área do cliente do *pParentWnd*.

*pParentWnd*<br/>
Especifica o barra de progresso da janela do pai do controle, geralmente um `CDialog`. Ele não deve ser NULL.

*nID*<br/>
Especifica a ID. do controle de barra de progresso

### <a name="return-value"></a>Valor de retorno

TRUE se o `CProgressCtrl` objeto for criado com êxito; caso contrário, FALSE.

### <a name="remarks"></a>Comentários

Você constrói um `CProgressCtrl` objeto em duas etapas. Primeiro, chame o construtor, que cria o `CProgressCtrl` do objeto e, em seguida, chame `Create`, que cria o controle de barra de progresso.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CProgressCtrl#2](../../mfc/reference/codesnippet/cpp/cprogressctrl-class_2.cpp)]

##  <a name="createex"></a>  CProgressCtrl::CreateEx

Cria um controle (uma janela filho) e o associa a `CProgressCtrl` objeto.

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
Especifica o estilo do controle de barra de progresso. Aplicar qualquer combinação de estilos de janela descrito em [CreateWindow](/windows/desktop/api/winuser/nf-winuser-createwindowa) no SDK do Windows.

*rect*<br/>
Uma referência a um [RECT](/previous-versions/dd162897\(v=vs.85\)) estrutura que descreve o tamanho e posição da janela a ser criado, em coordenadas do cliente do *pParentWnd*.

*pParentWnd*<br/>
Um ponteiro para a janela que é o pai do controle.

*nID*<br/>
ID da janela filho. do controle

### <a name="return-value"></a>Valor de retorno

Diferente de zero se bem-sucedido; Caso contrário, 0.

### <a name="remarks"></a>Comentários

Use `CreateEx` em vez de [Create](#create) para aplicar estilos estendidos do Windows, especificados pelo prefácio de estilo estendido do Windows **WS_EX_**.

##  <a name="getbarcolor"></a>  CProgressCtrl::GetBarColor

Obtém a cor da barra do indicador de progresso para o controle de barra de progresso atual.

```
COLORREF GetBarColor() const;
```

### <a name="return-value"></a>Valor de retorno

A cor da barra de progresso atual, representado como uma [COLORREF](/windows/desktop/gdi/colorref) valor ou CLR_DEFAULT se a cor de barra do indicador de progresso é a cor padrão.

### <a name="remarks"></a>Comentários

Esse método envia o [PBM_GETBARCOLOR](/windows/desktop/Controls/pbm-getbarcolor) mensagem, que é descrita no SDK do Windows.

##  <a name="getbkcolor"></a>  CProgressCtrl::GetBkColor

Obtém a cor do plano de fundo da barra de progresso atual.

```
COLORREF GetBkColor() const;
```

### <a name="return-value"></a>Valor de retorno

A cor do plano de fundo da barra de progresso atual, representado como uma [COLORREF](/windows/desktop/gdi/colorref) valor.

### <a name="remarks"></a>Comentários

Esse método envia o [PBM_GETBKCOLOR](/windows/desktop/Controls/pbm-getbkcolor) mensagem, que é descrita no SDK do Windows.

##  <a name="getpos"></a>  CProgressCtrl::GetPos

Recupera a posição atual da barra de progresso.

```
int GetPos();
```

### <a name="return-value"></a>Valor de retorno

A posição do controle de barra de progresso.

### <a name="remarks"></a>Comentários

A posição do controle de barra de progresso não é o local físico na tela, mas em vez disso, entre a parte superior e inferior intervalo indicado na [SetRange](#setrange).

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CProgressCtrl#3](../../mfc/reference/codesnippet/cpp/cprogressctrl-class_3.cpp)]

##  <a name="getrange"></a>  CProgressCtrl::GetRange

Obtém a atuais limites superiores e inferiores ou intervalo do controle de barra de progresso.

```
void GetRange(
    int& nLower,
    int& nUpper);
```

### <a name="parameters"></a>Parâmetros

*nLower*<br/>
Uma referência a um número inteiro recebendo o limite inferior do controle de barra de progresso.

*nUpper*<br/>
Uma referência a um número inteiro recebendo o limite superior do controle de barra de progresso.

### <a name="remarks"></a>Comentários

Esta função copia os valores dos limites superiores e inferiores para os inteiros referenciados pelo *nLower* e *nUpper*, respectivamente.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CProgressCtrl#4](../../mfc/reference/codesnippet/cpp/cprogressctrl-class_4.cpp)]

##  <a name="getstate"></a>  CProgressCtrl::GetState

Obtém o estado do controle de barra de progresso atual.

```
int GetState() const;
```

### <a name="return-value"></a>Valor de retorno

O estado do controle de barra de progresso atual, que é um dos seguintes valores:

|Valor|Estado|
|-----------|-----------|
|PBST_NORMAL|Em andamento|
|PBST_ERROR|Erro|
|PBST_PAUSED|Paused|

### <a name="remarks"></a>Comentários

Esse método envia o [PBM_GETSTATE](/windows/desktop/Controls/pbm-getstate) mensagem, que é descrita no SDK do Windows.

### <a name="example"></a>Exemplo

O exemplo de código a seguir define a variável `m_progressCtrl`, que é usado para acessar programaticamente o controle de barra de progresso. Essa variável é usada no exemplo a seguir.

[!code-cpp[NVC_MFC_CProgressCtrl_s1#9](../../mfc/reference/codesnippet/cpp/cprogressctrl-class_5.h)]

### <a name="example"></a>Exemplo

O exemplo de código a seguir recupera o estado do controle de barra de progresso atual.

[!code-cpp[NVC_MFC_CProgressCtrl_s1#5](../../mfc/reference/codesnippet/cpp/cprogressctrl-class_6.cpp)]

##  <a name="getstep"></a>  CProgressCtrl::GetStep

Recupera o incremento de etapa para a barra de progresso do controle de barra de progresso atual.

```
int GetStep() const;
```

### <a name="return-value"></a>Valor de retorno

O incremento de etapa da barra de progresso.

### <a name="remarks"></a>Comentários

O incremento de etapa é a quantidade pela qual uma chamada para [CProgressCtrl::StepIt](#stepit) aumenta a posição atual da barra de progresso.

Esse método envia o [PBM_GETSTEP](/windows/desktop/Controls/pbm-getstep) mensagem, que é descrita no SDK do Windows.

### <a name="example"></a>Exemplo

O exemplo de código a seguir define a variável `m_progressCtrl`, que é usado para acessar programaticamente o controle de barra de progresso. Essa variável é usada no exemplo a seguir.

[!code-cpp[NVC_MFC_CProgressCtrl_s1#9](../../mfc/reference/codesnippet/cpp/cprogressctrl-class_5.h)]

### <a name="example"></a>Exemplo

O exemplo de código a seguir recupera o incremento de etapa de controle de barra de progresso atual.

[!code-cpp[NVC_MFC_CProgressCtrl_s1#3](../../mfc/reference/codesnippet/cpp/cprogressctrl-class_7.cpp)]

##  <a name="offsetpos"></a>  CProgressCtrl::OffsetPos

Avança o barra de progresso da posição atual do controle o incremento especificado por *nPos* e redesenha a barra para refletir a nova posição.

```
int OffsetPos(int nPos);
```

### <a name="parameters"></a>Parâmetros

*nPos*<br/>
Valor para Avançar a posição.

### <a name="return-value"></a>Valor de retorno

A posição anterior do controle de barra de progresso.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CProgressCtrl#5](../../mfc/reference/codesnippet/cpp/cprogressctrl-class_8.cpp)]

##  <a name="setbarcolor"></a>  CProgressCtrl::SetBarColor

Define a cor da barra do indicador de progresso no controle de barra de progresso atual.

```
COLORREF SetBarColor(COLORREF clrBar);
```

### <a name="parameters"></a>Parâmetros

|Parâmetro|Descrição|
|---------------|-----------------|
|*clrBar*|[in] Um [COLORREF](/windows/desktop/gdi/colorref) valor que especifica a nova cor da barra do indicador de progresso. Especifique CLR_DEFAULT para fazer com que a barra de progresso usar sua cor padrão.|

### <a name="return-value"></a>Valor de retorno

A cor anterior da barra do indicador de progresso, representado como uma [COLORREF](/windows/desktop/gdi/colorref) valor ou CLR_DEFAULT se a cor da barra do indicador de progresso é a cor padrão.

### <a name="remarks"></a>Comentários

O `SetBarColor` método define o barra de progresso da somente se de cor de um Windows Vista [tema](/windows/desktop/Controls/visual-styles-overview) não está em vigor.

Esse método envia o [PBM_SETBARCOLOR](/windows/desktop/Controls/pbm-setbarcolor) mensagem, que é descrita no SDK do Windows.

### <a name="example"></a>Exemplo

O exemplo de código a seguir define a variável `m_progressCtrl`, que é usado para acessar programaticamente o controle de barra de progresso. Essa variável é usada no exemplo a seguir.

[!code-cpp[NVC_MFC_CProgressCtrl_s1#9](../../mfc/reference/codesnippet/cpp/cprogressctrl-class_5.h)]

### <a name="example"></a>Exemplo

O exemplo de código a seguir altera a cor da barra de progresso para vermelho, verde, azul ou o padrão.

[!code-cpp[NVC_MFC_CProgressCtrl_s1#1](../../mfc/reference/codesnippet/cpp/cprogressctrl-class_9.cpp)]

##  <a name="setbkcolor"></a>  CProgressCtrl::SetBkColor

Define a cor de plano de fundo para a barra de progresso.

```
COLORREF SetBkColor(COLORREF clrNew);
```

### <a name="parameters"></a>Parâmetros

*clrNew*<br/>
Um valor COLORREF que especifica a nova cor de plano de fundo. Especifique o valor CLR_DEFAULT para usar a cor de plano de fundo padrão para a barra de progresso.

### <a name="return-value"></a>Valor de retorno

O [COLORREF](/windows/desktop/gdi/colorref) valor que indica a cor de plano de fundo anterior ou CLR_DEFAULT, se a cor do plano de fundo é a cor padrão.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CProgressCtrl#6](../../mfc/reference/codesnippet/cpp/cprogressctrl-class_10.cpp)]

##  <a name="setmarquee"></a>  CProgressCtrl::SetMarquee

Desativa o modo de marca de seleção ativada ou desativada para o controle de barra de progresso atual.

```
BOOL SetMarquee(
    BOOL fMarqueeMode,
    int nInterval);
```

### <a name="parameters"></a>Parâmetros

|Parâmetro|Descrição|
|---------------|-----------------|
|*fMarqueeMode*|[in] True para ativar modo de marca de seleção em, ou FALSE para desativar o modo de marca de seleção.|
|*nInterval*|[in] Tempo em milissegundos entre as atualizações da animação do letreiro.|

### <a name="return-value"></a>Valor de retorno

Esse método sempre retorna TRUE.

### <a name="remarks"></a>Comentários

Quando o modo de marca de seleção está ativado, a barra de progresso é animada e rola, como um sinal de um letreiro de teatro.

Esse método envia o [PBM_SETMARQUEE](/windows/desktop/Controls/pbm-setmarquee) mensagem, que é descrita no SDK do Windows.

### <a name="example"></a>Exemplo

O exemplo de código a seguir define a variável `m_progressCtrl`, que é usado para acessar programaticamente o controle de barra de progresso. Essa variável é usada no exemplo a seguir.

[!code-cpp[NVC_MFC_CProgressCtrl_s1#9](../../mfc/reference/codesnippet/cpp/cprogressctrl-class_5.h)]

### <a name="example"></a>Exemplo

O exemplo de código a seguir inicia e interrompe o animação de letreiro digital.

[!code-cpp[NVC_MFC_CProgressCtrl_s1#2](../../mfc/reference/codesnippet/cpp/cprogressctrl-class_11.cpp)]

##  <a name="setpos"></a>  CProgressCtrl::SetPos

Define o progresso da barra a posição atual do controle conforme especificado por *nPos* e redesenha a barra para refletir a nova posição.

```
int SetPos(int nPos);
```

### <a name="parameters"></a>Parâmetros

*nPos*<br/>
Nova posição do controle de barra de progresso.

### <a name="return-value"></a>Valor de retorno

A posição anterior do controle de barra de progresso.

### <a name="remarks"></a>Comentários

A posição do controle de barra de progresso não é o local físico na tela, mas em vez disso, entre a parte superior e inferior intervalo indicado na [SetRange](#setrange).

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CProgressCtrl#7](../../mfc/reference/codesnippet/cpp/cprogressctrl-class_12.cpp)]

##  <a name="setrange"></a>  CProgressCtrl::SetRange

Define os limites superiores e inferiores da barra de intervalo do controle de progresso e o redesenha a barra para refletir os novos intervalos.

```
void SetRange(
    short nLower,
    short nUpper);

void SetRange32(
    int nLower,
    int nUpper);
```

### <a name="parameters"></a>Parâmetros

*nLower*<br/>
Especifica o limite inferior do intervalo (o padrão é zero).

*nUpper*<br/>
Especifica o limite superior do intervalo (o padrão é 100).

### <a name="remarks"></a>Comentários

A função de membro `SetRange32` define o intervalo de 32 bits para o controle de progresso.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CProgressCtrl#8](../../mfc/reference/codesnippet/cpp/cprogressctrl-class_13.cpp)]

##  <a name="setstate"></a>  CProgressCtrl::SetState

Define o estado do controle de barra de progresso atual.

```
int SetState(int iState);
```

### <a name="parameters"></a>Parâmetros

|Parâmetro|Descrição|
|---------------|-----------------|
|*iState*|[in] O estado para definir a barra de progresso. Use um dos seguintes valores:<br /><br /> -PBST_NORMAL - em andamento<br />-PBST_ERROR - erro<br />- PBST_PAUSED - Paused|

### <a name="return-value"></a>Valor de retorno

O estado anterior do controle de barra de progresso atual.

### <a name="remarks"></a>Comentários

Esse método envia o [PBM_SETSTATE](/windows/desktop/Controls/pbm-setstate) mensagem, que é descrita no SDK do Windows.

### <a name="example"></a>Exemplo

O exemplo de código a seguir define a variável `m_progressCtrl`, que é usado para acessar programaticamente o controle de barra de progresso. Essa variável é usada no exemplo a seguir.

[!code-cpp[NVC_MFC_CProgressCtrl_s1#9](../../mfc/reference/codesnippet/cpp/cprogressctrl-class_5.h)]

### <a name="example"></a>Exemplo

O exemplo de código a seguir define o estado do controle de barra de progresso atual em pausa ou em andamento.

[!code-cpp[NVC_MFC_CProgressCtrl_s1#4](../../mfc/reference/codesnippet/cpp/cprogressctrl-class_14.cpp)]

##  <a name="setstep"></a>  CProgressCtrl::SetStep

Especifica o incremento de etapa de um controle de barra de progresso.

```
int SetStep(int nStep);
```

### <a name="parameters"></a>Parâmetros

*nStep*<br/>
Incremento de etapa nova.

### <a name="return-value"></a>Valor de retorno

O incremento da etapa anterior.

### <a name="remarks"></a>Comentários

O incremento de etapa é a quantidade pela qual uma chamada para `CProgressCtrl::StepIt` aumenta o andamento da barra da posição atual.

O incremento de etapa de padrão é 10.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CProgressCtrl#9](../../mfc/reference/codesnippet/cpp/cprogressctrl-class_15.cpp)]

##  <a name="stepit"></a>  CProgressCtrl::StepIt

Avança a posição atual para um controle de barra de progresso até o incremento de etapa e redesenha a barra para refletir a nova posição.

```
int StepIt();
```

### <a name="return-value"></a>Valor de retorno

A posição anterior do controle de barra de progresso.

### <a name="remarks"></a>Comentários

O incremento de etapa é definido pelo `CProgressCtrl::SetStep` função de membro.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CProgressCtrl#10](../../mfc/reference/codesnippet/cpp/cprogressctrl-class_16.cpp)]

## <a name="see-also"></a>Consulte também

[CMNCTRL2 de exemplo do MFC](../../overview/visual-cpp-samples.md)<br/>
[Classe CWnd](../../mfc/reference/cwnd-class.md)<br/>
[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)
