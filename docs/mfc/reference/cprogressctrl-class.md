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
ms.openlocfilehash: 9d63a1113e521eb73c99c47b335eb7ab00ccd753
ms.sourcegitcommit: fcb48824f9ca24b1f8bd37d647a4d592de1cc925
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/15/2019
ms.locfileid: "69502859"
---
# <a name="cprogressctrl-class"></a>Classe CProgressCtrl

Fornece a funcionalidade do controle de barra de progresso comum do Windows.

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
|[CProgressCtrl::Create](#create)|Cria um controle de barra de progresso e o anexa a `CProgressCtrl` um objeto.|
|[CProgressCtrl::CreateEx](#createex)|Cria um controle de progresso com os estilos estendidos do Windows especificados e o anexa `CProgressCtrl` a um objeto.|
|[CProgressCtrl::GetBarColor](#getbarcolor)|Obtém a cor da barra de indicador de progresso para o controle da barra de progresso atual.|
|[CProgressCtrl::GetBkColor](#getbkcolor)|Obtém a cor do plano de fundo da barra de progresso atual.|
|[CProgressCtrl::GetPos](#getpos)|Obtém a posição atual da barra de progresso.|
|[CProgressCtrl::GetRange](#getrange)|Obtém os limites inferior e superior do intervalo do controle da barra de progresso.|
|[CProgressCtrl::GetState](#getstate)|Obtém o estado do controle da barra de progresso atual.|
|[CProgressCtrl::GetStep](#getstep)|Recupera o incremento de etapa da barra de progresso do controle de barra de progresso atual.|
|[CProgressCtrl::OffsetPos](#offsetpos)|Avança a posição atual de um controle de barra de progresso por um incremento especificado e redesenha a barra para refletir a nova posição.|
|[CProgressCtrl::SetBarColor](#setbarcolor)|Define a cor da barra de indicadores de progresso no controle da barra de progresso atual.|
|[CProgressCtrl::SetBkColor](#setbkcolor)|Define a cor do plano de fundo da barra de progresso.|
|[CProgressCtrl::SetMarquee](#setmarquee)|Ativa ou desativa o modo de letreiro para o controle de barra de progresso atual.|
|[CProgressCtrl::SetPos](#setpos)|Define a posição atual para um controle de barra de progresso e redesenha a barra para refletir a nova posição.|
|[CProgressCtrl::SetRange](#setrange)|Define os intervalos mínimo e máximo para um controle de barra de progresso e redesenha a barra para refletir os novos intervalos.|
|[CProgressCtrl::SetState](#setstate)|Define o estado do controle da barra de progresso atual.|
|[CProgressCtrl::SetStep](#setstep)|Especifica o incremento de etapa para um controle de barra de progresso.|
|[CProgressCtrl::StepIt](#stepit)|Avança a posição atual de um controle de barra de progresso pelo incremento Step (consulte [SetStep](#setstep)) e redesenha a barra para refletir a nova posição.|

## <a name="remarks"></a>Comentários

Um controle de barra de progresso é uma janela que um aplicativo pode usar para indicar o progresso de uma operação demorada. Ele consiste em um retângulo que é gradualmente preenchido, da esquerda para a direita, com a cor de realce do sistema conforme uma operação progride.

Um controle de barra de progresso tem um intervalo e uma posição atual. O intervalo representa a duração total da operação e a posição atual representa o progresso que o aplicativo fez para concluir a operação. O procedimento de janela usa o intervalo e a posição atual para determinar a porcentagem da barra de progresso a ser preenchida com a cor de realce. Como os valores de intervalo e posição atual são expressos como inteiros assinados, o intervalo possível de valores de posição atual é de-2.147.483.648 a 2.147.483.647, inclusive.

Para obter mais informações sobre `CProgressCtrl`como usar o, consulte [controles](../../mfc/controls-mfc.md) e [usando CProgressCtrl](../../mfc/using-cprogressctrl.md).

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

Depois de construir o `CProgressCtrl` objeto, chame `CProgressCtrl::Create` para criar o controle da barra de progresso.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CProgressCtrl#1](../../mfc/reference/codesnippet/cpp/cprogressctrl-class_1.cpp)]

##  <a name="create"></a>  CProgressCtrl::Create

Cria um controle de barra de progresso e o anexa a `CProgressCtrl` um objeto.

```
virtual BOOL Create(
    DWORD dwStyle,
    const RECT& rect,
    CWnd* pParentWnd,
    UINT nID);
```

### <a name="parameters"></a>Parâmetros

*dwStyle*<br/>
Especifica o estilo do controle da barra de progresso. Aplique qualquer combinação de stylesdescribed de janela no [CreateWindow](/windows/win32/api/winuser/nf-winuser-createwindoww) no SDK do Windows, além dos seguintes estilos de controle de barra de progresso, ao controle:

- PBS_VERTICAL exibe as informações de progresso verticalmente, de cima para baixo. Sem esse sinalizador, o controle da barra de progresso é exibido horizontalmente, da esquerda para a direita.

- PBS_SMOOTH Exibe o preenchimento gradual e suave no controle da barra de progresso. Sem esse sinalizador, o controle será preenchido com blocos.

*rect*<br/>
Especifica o tamanho e a posição do controle da barra de progresso. Pode ser um objeto [CRect](../../atl-mfc-shared/reference/crect-class.md) ou uma estrutura [Rect](/previous-versions/dd162897\(v=vs.85\)) . Como o controle deve ser uma janela filho, as coordenadas especificadas são relativas à área do cliente do *pParentWnd*.

*pParentWnd*<br/>
Especifica a janela pai do controle da barra de progresso, `CDialog`geralmente um. Ele não deve ser nulo.

*nID*<br/>
Especifica a ID do controle da barra de progresso.

### <a name="return-value"></a>Valor de retorno

TRUE se o `CProgressCtrl` objeto for criado com êxito; caso contrário, false.

### <a name="remarks"></a>Comentários

Você constrói um `CProgressCtrl` objeto em duas etapas. Primeiro, chame o construtor, que cria o `CProgressCtrl` objeto e, em seguida `Create`, chame, que cria o controle da barra de progresso.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CProgressCtrl#2](../../mfc/reference/codesnippet/cpp/cprogressctrl-class_2.cpp)]

##  <a name="createex"></a>  CProgressCtrl::CreateEx

Cria um controle (uma janela filho) e o `CProgressCtrl` associa ao objeto.

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
Especifica o estilo do controle da barra de progresso. Aplique qualquer combinação de estilos de janela descrita na [CreateWindow](/windows/win32/api/winuser/nf-winuser-createwindoww) na SDK do Windows.

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

##  <a name="getbarcolor"></a>  CProgressCtrl::GetBarColor

Obtém a cor da barra de indicador de progresso para o controle da barra de progresso atual.

```
COLORREF GetBarColor() const;
```

### <a name="return-value"></a>Valor de retorno

A cor da barra de progresso atual, representada como um valor de [COLORREF](/windows/win32/gdi/colorref) ou CLR_DEFAULT se a cor da barra de indicador de progresso for a cor padrão.

### <a name="remarks"></a>Comentários

Esse método envia a mensagem [PBM_GETBARCOLOR](/windows/win32/Controls/pbm-getbarcolor) , que é descrita na SDK do Windows.

##  <a name="getbkcolor"></a>  CProgressCtrl::GetBkColor

Obtém a cor do plano de fundo da barra de progresso atual.

```
COLORREF GetBkColor() const;
```

### <a name="return-value"></a>Valor de retorno

A cor do plano de fundo da barra de progresso atual, representada como um valor de [COLORREF](/windows/win32/gdi/colorref) .

### <a name="remarks"></a>Comentários

Esse método envia a mensagem [PBM_GETBKCOLOR](/windows/win32/Controls/pbm-getbkcolor) , que é descrita na SDK do Windows.

##  <a name="getpos"></a>  CProgressCtrl::GetPos

Recupera a posição atual da barra de progresso.

```
int GetPos();
```

### <a name="return-value"></a>Valor de retorno

A posição do controle da barra de progresso.

### <a name="remarks"></a>Comentários

A posição do controle da barra de progresso não é o local físico na tela, mas sim entre o intervalo superior e inferior indicado em [SetRange](#setrange).

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CProgressCtrl#3](../../mfc/reference/codesnippet/cpp/cprogressctrl-class_3.cpp)]

##  <a name="getrange"></a>  CProgressCtrl::GetRange

Obtém os limites inferior e superior atual, ou intervalo, do controle da barra de progresso.

```
void GetRange(
    int& nLower,
    int& nUpper);
```

### <a name="parameters"></a>Parâmetros

*nLower*<br/>
Uma referência a um inteiro que recebe o limite inferior do controle da barra de progresso.

*nUpper*<br/>
Uma referência a um inteiro que recebe o limite superior do controle de barra de progresso.

### <a name="remarks"></a>Comentários

Essa função copia os valores dos limites inferior e superior para os inteiros referenciados por *nLower* e *nUpper*, respectivamente.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CProgressCtrl#4](../../mfc/reference/codesnippet/cpp/cprogressctrl-class_4.cpp)]

##  <a name="getstate"></a>  CProgressCtrl::GetState

Obtém o estado do controle da barra de progresso atual.

```
int GetState() const;
```

### <a name="return-value"></a>Valor de retorno

O estado do controle da barra de progresso atual, que é um dos seguintes valores:

|Valor|Estado|
|-----------|-----------|
|PBST_NORMAL|Em andamento|
|PBST_ERROR|Erro|
|PBST_PAUSED|Paused|

### <a name="remarks"></a>Comentários

Esse método envia a mensagem [PBM_GETSTATE](/windows/win32/Controls/pbm-getstate) , que é descrita na SDK do Windows.

### <a name="example"></a>Exemplo

O exemplo de código a seguir define a `m_progressCtrl`variável,, que é usada para acessar programaticamente o controle da barra de progresso. Essa variável é usada no exemplo a seguir.

[!code-cpp[NVC_MFC_CProgressCtrl_s1#9](../../mfc/reference/codesnippet/cpp/cprogressctrl-class_5.h)]

### <a name="example"></a>Exemplo

O exemplo de código a seguir recupera o estado do controle de barra de progresso atual.

[!code-cpp[NVC_MFC_CProgressCtrl_s1#5](../../mfc/reference/codesnippet/cpp/cprogressctrl-class_6.cpp)]

##  <a name="getstep"></a>  CProgressCtrl::GetStep

Recupera o incremento de etapa da barra de progresso do controle de barra de progresso atual.

```
int GetStep() const;
```

### <a name="return-value"></a>Valor de retorno

O incremento de etapa da barra de progresso.

### <a name="remarks"></a>Comentários

A etapa incremento é a quantidade pela qual uma chamada para [CProgressCtrl:: StepIt](#stepit) aumenta a posição atual da barra de progresso.

Esse método envia a mensagem [PBM_GETSTEP](/windows/win32/Controls/pbm-getstep) , que é descrita na SDK do Windows.

### <a name="example"></a>Exemplo

O exemplo de código a seguir define a `m_progressCtrl`variável,, que é usada para acessar programaticamente o controle da barra de progresso. Essa variável é usada no exemplo a seguir.

[!code-cpp[NVC_MFC_CProgressCtrl_s1#9](../../mfc/reference/codesnippet/cpp/cprogressctrl-class_5.h)]

### <a name="example"></a>Exemplo

O exemplo de código a seguir recupera o incremento de etapa do controle de barra de progresso atual.

[!code-cpp[NVC_MFC_CProgressCtrl_s1#3](../../mfc/reference/codesnippet/cpp/cprogressctrl-class_7.cpp)]

##  <a name="offsetpos"></a>  CProgressCtrl::OffsetPos

Avança a posição atual do controle de barra de progresso pelo incremento especificado por *nPos* e redesenha a barra para refletir a nova posição.

```
int OffsetPos(int nPos);
```

### <a name="parameters"></a>Parâmetros

*nPos*<br/>
Valor para avançar a posição.

### <a name="return-value"></a>Valor de retorno

A posição anterior do controle da barra de progresso.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CProgressCtrl#5](../../mfc/reference/codesnippet/cpp/cprogressctrl-class_8.cpp)]

##  <a name="setbarcolor"></a>  CProgressCtrl::SetBarColor

Define a cor da barra de indicadores de progresso no controle da barra de progresso atual.

```
COLORREF SetBarColor(COLORREF clrBar);
```

### <a name="parameters"></a>Parâmetros

|Parâmetro|Descrição|
|---------------|-----------------|
|*clrBar*|no Um valor de [COLORREF](/windows/win32/gdi/colorref) que especifica a nova cor da barra de indicador de progresso. Especifique CLR_DEFAULT para fazer com que a barra de progresso Use sua cor padrão.|

### <a name="return-value"></a>Valor de retorno

A cor anterior da barra de indicador de progresso, representada como um valor de [COLORREF](/windows/win32/gdi/colorref) ou CLR_DEFAULT se a cor da barra de indicador de progresso for a cor padrão.

### <a name="remarks"></a>Comentários

O `SetBarColor` método definirá a cor da barra de progresso somente se um [tema](/windows/win32/Controls/visual-styles-overview) do Windows Vista não estiver em vigor.

Esse método envia a mensagem [PBM_SETBARCOLOR](/windows/win32/Controls/pbm-setbarcolor) , que é descrita na SDK do Windows.

### <a name="example"></a>Exemplo

O exemplo de código a seguir define a `m_progressCtrl`variável,, que é usada para acessar programaticamente o controle da barra de progresso. Essa variável é usada no exemplo a seguir.

[!code-cpp[NVC_MFC_CProgressCtrl_s1#9](../../mfc/reference/codesnippet/cpp/cprogressctrl-class_5.h)]

### <a name="example"></a>Exemplo

O exemplo de código a seguir altera a cor da barra de progresso para vermelho, verde, azul ou o padrão.

[!code-cpp[NVC_MFC_CProgressCtrl_s1#1](../../mfc/reference/codesnippet/cpp/cprogressctrl-class_9.cpp)]

##  <a name="setbkcolor"></a>  CProgressCtrl::SetBkColor

Define a cor do plano de fundo da barra de progresso.

```
COLORREF SetBkColor(COLORREF clrNew);
```

### <a name="parameters"></a>Parâmetros

*clrNew*<br/>
Um valor COLORREF que especifica a nova cor do plano de fundo. Especifique o valor de CLR_DEFAULT para usar a cor de plano de fundo padrão para a barra de progresso.

### <a name="return-value"></a>Valor de retorno

O valor [COLORREF](/windows/win32/gdi/colorref) indicando a cor do plano de fundo anterior ou CLR_DEFAULT se a cor do plano de fundo for a cor padrão.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CProgressCtrl#6](../../mfc/reference/codesnippet/cpp/cprogressctrl-class_10.cpp)]

##  <a name="setmarquee"></a>  CProgressCtrl::SetMarquee

Ativa ou desativa o modo de letreiro para o controle de barra de progresso atual.

```
BOOL SetMarquee(
    BOOL fMarqueeMode,
    int nInterval);
```

### <a name="parameters"></a>Parâmetros

|Parâmetro|Descrição|
|---------------|-----------------|
|*fMarqueeMode*|no TRUE para ativar o modo de letreiro ou FALSE para ativar o modo de letreiro.|
|*nInterval*|no Tempo em milissegundos entre as atualizações da animação do letreiro digital.|

### <a name="return-value"></a>Valor de retorno

Esse método sempre retorna TRUE.

### <a name="remarks"></a>Comentários

Quando o modo de letreiro é ativado, a barra de progresso é animada e rola como um sinal em um letreiro de teatro.

Esse método envia a mensagem [PBM_SETMARQUEE](/windows/win32/Controls/pbm-setmarquee) , que é descrita na SDK do Windows.

### <a name="example"></a>Exemplo

O exemplo de código a seguir define a `m_progressCtrl`variável,, que é usada para acessar programaticamente o controle da barra de progresso. Essa variável é usada no exemplo a seguir.

[!code-cpp[NVC_MFC_CProgressCtrl_s1#9](../../mfc/reference/codesnippet/cpp/cprogressctrl-class_5.h)]

### <a name="example"></a>Exemplo

O exemplo de código a seguir inicia e interrompe a animação de rolagem de letreiro.

[!code-cpp[NVC_MFC_CProgressCtrl_s1#2](../../mfc/reference/codesnippet/cpp/cprogressctrl-class_11.cpp)]

##  <a name="setpos"></a>  CProgressCtrl::SetPos

Define a posição atual do controle da barra de progresso como especificado por *nPos* e redesenha a barra para refletir a nova posição.

```
int SetPos(int nPos);
```

### <a name="parameters"></a>Parâmetros

*nPos*<br/>
Nova posição do controle da barra de progresso.

### <a name="return-value"></a>Valor de retorno

A posição anterior do controle da barra de progresso.

### <a name="remarks"></a>Comentários

A posição do controle da barra de progresso não é o local físico na tela, mas sim entre o intervalo superior e inferior indicado em [SetRange](#setrange).

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CProgressCtrl#7](../../mfc/reference/codesnippet/cpp/cprogressctrl-class_12.cpp)]

##  <a name="setrange"></a>  CProgressCtrl::SetRange

Define os limites superior e inferior do intervalo do controle da barra de progresso e redesenha a barra para refletir os novos intervalos.

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

A função `SetRange32` membro define o intervalo de 32 bits para o controle de progresso.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CProgressCtrl#8](../../mfc/reference/codesnippet/cpp/cprogressctrl-class_13.cpp)]

##  <a name="setstate"></a>  CProgressCtrl::SetState

Define o estado do controle da barra de progresso atual.

```
int SetState(int iState);
```

### <a name="parameters"></a>Parâmetros

|Parâmetro|Descrição|
|---------------|-----------------|
|*iState*|no O estado para definir a barra de progresso. Use um dos seguintes valores:<br /><br /> -PBST_NORMAL-em andamento<br />-PBST_ERROR-erro<br />-PBST_PAUSED-em pausa|

### <a name="return-value"></a>Valor de retorno

O estado anterior do controle da barra de progresso atual.

### <a name="remarks"></a>Comentários

Esse método envia a mensagem [PBM_SETSTATE](/windows/win32/Controls/pbm-setstate) , que é descrita na SDK do Windows.

### <a name="example"></a>Exemplo

O exemplo de código a seguir define a `m_progressCtrl`variável,, que é usada para acessar programaticamente o controle da barra de progresso. Essa variável é usada no exemplo a seguir.

[!code-cpp[NVC_MFC_CProgressCtrl_s1#9](../../mfc/reference/codesnippet/cpp/cprogressctrl-class_5.h)]

### <a name="example"></a>Exemplo

O exemplo de código a seguir define o estado do controle da barra de progresso atual como pausado ou em andamento.

[!code-cpp[NVC_MFC_CProgressCtrl_s1#4](../../mfc/reference/codesnippet/cpp/cprogressctrl-class_14.cpp)]

##  <a name="setstep"></a>  CProgressCtrl::SetStep

Especifica o incremento de etapa para um controle de barra de progresso.

```
int SetStep(int nStep);
```

### <a name="parameters"></a>Parâmetros

*nStep*<br/>
Incremento de nova etapa.

### <a name="return-value"></a>Valor de retorno

O incremento da etapa anterior.

### <a name="remarks"></a>Comentários

A etapa incremento é a quantidade pela qual uma chamada `CProgressCtrl::StepIt` aumenta a posição atual da barra de progresso.

O incremento da etapa padrão é 10.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CProgressCtrl#9](../../mfc/reference/codesnippet/cpp/cprogressctrl-class_15.cpp)]

##  <a name="stepit"></a>  CProgressCtrl::StepIt

Avança a posição atual de um controle de barra de progresso pelo incremento de etapa e redesenha a barra para refletir a nova posição.

```
int StepIt();
```

### <a name="return-value"></a>Valor de retorno

A posição anterior do controle da barra de progresso.

### <a name="remarks"></a>Comentários

O incremento Step é definido pela `CProgressCtrl::SetStep` função membro.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CProgressCtrl#10](../../mfc/reference/codesnippet/cpp/cprogressctrl-class_16.cpp)]

## <a name="see-also"></a>Consulte também

[Exemplo de CMNCTRL2 do MFC](../../overview/visual-cpp-samples.md)<br/>
[Classe CWnd](../../mfc/reference/cwnd-class.md)<br/>
[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)
