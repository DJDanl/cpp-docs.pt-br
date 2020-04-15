---
title: Classe CRectTracker
ms.date: 11/19/2018
f1_keywords:
- CRectTracker
- AFXEXT/CRectTracker
- AFXEXT/CRectTracker::CRectTracker
- AFXEXT/CRectTracker::AdjustRect
- AFXEXT/CRectTracker::Draw
- AFXEXT/CRectTracker::DrawTrackerRect
- AFXEXT/CRectTracker::GetHandleMask
- AFXEXT/CRectTracker::GetTrueRect
- AFXEXT/CRectTracker::HitTest
- AFXEXT/CRectTracker::NormalizeHit
- AFXEXT/CRectTracker::OnChangedRect
- AFXEXT/CRectTracker::SetCursor
- AFXEXT/CRectTracker::Track
- AFXEXT/CRectTracker::TrackRubberBand
- AFXEXT/CRectTracker::m_nHandleSize
- AFXEXT/CRectTracker::m_nStyle
- AFXEXT/CRectTracker::m_rect
- AFXEXT/CRectTracker::m_sizeMin
helpviewer_keywords:
- CRectTracker [MFC], CRectTracker
- CRectTracker [MFC], AdjustRect
- CRectTracker [MFC], Draw
- CRectTracker [MFC], DrawTrackerRect
- CRectTracker [MFC], GetHandleMask
- CRectTracker [MFC], GetTrueRect
- CRectTracker [MFC], HitTest
- CRectTracker [MFC], NormalizeHit
- CRectTracker [MFC], OnChangedRect
- CRectTracker [MFC], SetCursor
- CRectTracker [MFC], Track
- CRectTracker [MFC], TrackRubberBand
- CRectTracker [MFC], m_nHandleSize
- CRectTracker [MFC], m_nStyle
- CRectTracker [MFC], m_rect
- CRectTracker [MFC], m_sizeMin
ms.assetid: 99caa7f2-3c0d-4a42-bbee-e5d1d342d4ee
ms.openlocfilehash: 4d262ab5f88481d56de1c236effb66fcbf6a706a
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81368376"
---
# <a name="crecttracker-class"></a>Classe CRectTracker

Permite que um item seja exibido, movido e redimensionado de diferentes formas.

## <a name="syntax"></a>Sintaxe

```
class CRectTracker
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[CRectTracker::CRectTracker](#crecttracker)|Constrói um objeto `CRectTracker`.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CRectTracker::AdjustRectct](#adjustrect)|Chamado quando o retângulo é redimensionado.|
|[CRectTracker::Draw](#draw)|Renderiza o retângulo.|
|[CRectTracker::DrawTrackerRect](#drawtrackerrect)|Chamado ao desenhar a `CRectTracker` borda de um objeto.|
|[CRectTracker::GetHandleMask](#gethandlemask)|Chamado para obter a `CRectTracker` máscara de um item redimensionar alças.|
|[CRectTracker::GetTrueRect](#gettruerect)|Retorna largura e altura do retângulo, incluindo alças de redimensionamento.|
|[CRectTracker::HitTest](#hittest)|Retorna a posição atual do cursor relacionada ao `CRectTracker` objeto.|
|[CRectTracker::NormalizeHit](#normalizehit)|Normaliza um código de teste de sucesso.|
|[CRectTracker:OnChangedRect](#onchangedrect)|Chamado quando o retângulo foi redimensionado ou movido.|
|[CRectTracker::SetCursor](#setcursor)|Define o cursor, dependendo da posição sobre o retângulo.|
|[CRectTracker::Track](#track)|Permite que o usuário manipule o retângulo.|
|[CRectTracker::TrackRubberBand](#trackrubberband)|Permite que o usuário "rubber-band" a seleção.|

### <a name="public-data-members"></a>Membros de Dados Públicos

|Nome|Descrição|
|----------|-----------------|
|[CRectTracker::m_nHandleSize](#m_nhandlesize)|Determina o tamanho das alças de redimensionamento.|
|[CRectTracker::m_nStyle](#m_nstyle)|Estilo atual do rastreador.|
|[CRectTracker::m_rect](#m_rect)|Posição atual (em pixels) do retângulo.|
|[CRectTracker::m_sizeMin](#m_sizemin)|Determina largura e altura mínimas do retângulo.|

## <a name="remarks"></a>Comentários

`CRectTracker`não tem uma classe base.

Embora `CRectTracker` a classe tenha sido projetada para permitir que o usuário interaja com itens OLE usando uma interface gráfica, seu uso não está restrito a aplicativos habilitados para OLE. Ele pode ser usado em qualquer lugar que tal interface de usuário seja necessária.

`CRectTracker`fronteiras podem ser linhas sólidas ou pontilhadas. O item pode ser dado uma borda eclodida ou sobreposta com um padrão eclodido para indicar diferentes estados do item. Você pode colocar oito alças de redimensionamento na parte externa ou na borda interna do item. (Para obter uma explicação das alças de redimensionamento, consulte [GetHandleMask](#gethandlemask).) Finalmente, `CRectTracker` um permite que você altere a orientação de um item durante o redimensionamento.

Para `CRectTracker`usar, `CRectTracker` construa um objeto e especifique quais estados de exibição são inicializados. Em seguida, você pode usar esta interface para dar ao usuário feedback `CRectTracker` visual sobre o status atual do item OLE associado ao objeto.

Para obter mais `CRectTracker`informações sobre como usar, consulte o artigo [Trackers](../../mfc/trackers.md).

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`CRectTracker`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxext.h

## <a name="crecttrackeradjustrect"></a><a name="adjustrect"></a>CRectTracker::AdjustRectct

Chamado pela estrutura quando o retângulo de rastreamento é redimensionado usando uma alça de redimensionamento.

```
virtual void AdjustRect(
    int nHandle,
    LPRECT lpRect);
```

### <a name="parameters"></a>Parâmetros

*nHandle*<br/>
Índice da alça usada.

*Lprect*<br/>
Ponteiro para o tamanho atual do retângulo. (O tamanho de um retângulo é dado pela sua altura e largura.)

### <a name="remarks"></a>Comentários

O comportamento padrão desta função permite que a orientação `Track` `TrackRubberBand` do retângulo mude apenas quando e são chamados de inverter permitido.

Anular esta função para controlar o ajuste do retângulo de rastreamento durante uma operação de arrasto. Um método é ajustar as coordenadas especificadas pelo *lpRect* antes de retornar.

Recursos especiais que não são `CRectTracker`suportados diretamente por , como snap-to-grid ou keep-aspect-ratio, podem ser implementados substituindo esta função.

## <a name="crecttrackercrecttracker"></a><a name="crecttracker"></a>CRectTracker::CRectTracker

Cria e inicializa um objeto `CRectTracker`.

```
CRectTracker();

CRectTracker(
    LPCRECT lpSrcRect,
    UINT nStyle);
```

### <a name="parameters"></a>Parâmetros

*lpSrcRect*<br/>
As coordenadas do objeto retângulo.

*nStyle*<br/>
Especifica o estilo `CRectTracker` do objeto. Há suporte para os seguintes estilos:

- `CRectTracker::solidLine`Use uma linha sólida para a borda retângulo.

- `CRectTracker::dottedLine`Use uma linha pontilhada para a borda retângulo.

- `CRectTracker::hatchedBorder`Use um padrão eclodido para a borda retângulo.

- `CRectTracker::resizeInside`Redimensione as alças localizadas dentro do retângulo.

- `CRectTracker::resizeOutside`Redimensione as alças localizadas fora do retângulo.

- `CRectTracker::hatchInside`O padrão eclodido cobre todo o retângulo.

### <a name="remarks"></a>Comentários

O construtor padrão inicializa `CRectTracker` o objeto com os valores do *lpSrcRect* e inicializa outros tamanhos para padrões do sistema. Se o objeto for criado sem parâmetros, os `m_rect` membros e `m_nStyle` dados não serão inicializados.

## <a name="crecttrackerdraw"></a><a name="draw"></a>CRectTracker::Draw

Chame esta função para desenhar as linhas externas do retângulo e a região interna.

```
void Draw(CDC* pDC) const;
```

### <a name="parameters"></a>Parâmetros

*pDC*<br/>
Ponteiro para o contexto do dispositivo sobre o qual desenhar.

### <a name="remarks"></a>Comentários

O estilo do rastreador determina como o desenho é feito. Consulte o construtor `CRectTracker` para obter mais informações sobre os estilos disponíveis.

## <a name="crecttrackerdrawtrackerrect"></a><a name="drawtrackerrect"></a>CRectTracker::DrawTrackerRect

Chamado pela estrutura sempre que a posição do `Track` `TrackRubberBand` rastreador tenha sido alterada enquanto estiver dentro da função ou membro.

```
virtual void DrawTrackerRect(
    LPCRECT lpRect,
    CWnd* pWndClipTo,
    CDC* pDC,
    CWnd* pWnd);
```

### <a name="parameters"></a>Parâmetros

*Lprect*<br/>
Ponteiro para `RECT` o que contém o retângulo para desenhar.

*pWndClipTo*<br/>
Pointer para a janela para usar no recorte do retângulo.

*pDC*<br/>
Ponteiro para o contexto do dispositivo sobre o qual desenhar.

*Pwnd*<br/>
Ponteiro para a janela em que o desenho ocorrerá.

### <a name="remarks"></a>Comentários

A implementação padrão `CDC::DrawFocusRect`faz uma chamada para , que desenha um retângulo pontilhado.

Anular esta função para fornecer feedback diferente durante a operação de rastreamento.

## <a name="crecttrackergethandlemask"></a><a name="gethandlemask"></a>CRectTracker::GetHandleMask

A estrutura chama essa função de membro para recuperar a máscara para as alças de redimensionamento de um retângulo.

```
virtual UINT GetHandleMask() const;
```

### <a name="return-value"></a>Valor retornado

A máscara `CRectTracker` das alças de redimensionamento de um item.

### <a name="remarks"></a>Comentários

As alças de redimensionamento aparecem nas laterais e cantos do retângulo e permitem que o usuário controle a forma e o tamanho do retângulo.

Um retângulo tem 8 alças de redimensionamento numeradas de 0 a 7. Cada alça de redimensionamento é representada por um pouco na máscara; o valor dessa broca é 2^ *n*, onde *n* é o número da alça de redimensionamento. Os bits 0-3 correspondem às alças de redimensionamento do canto, começando no sentido superior esquerdo no sentido horário. Os bits 4-7 correspondem às alças laterais de redimensionamento a partir do sentido horário superior. A ilustração a seguir mostra as alças de redimensionamento de um retângulo e seus números e valores correspondentes de redimensionamento:

![Redimensionar números da alça](../../mfc/reference/media/vc35dp1.gif "Redimensionar números da alça")

A implementação `GetHandleMask` padrão do retorna a máscara dos bits para que as alças de redimensionamento apareçam. Se a única broca estiver em tona, a alça de redimensionamento correspondente será desenhada.

Substituir esta função de membro para ocultar ou mostrar as alças de redimensionamento indicadas.

## <a name="crecttrackergettruerect"></a><a name="gettruerect"></a>CRectTracker::GetTrueRect

Chame esta função para recuperar as coordenadas do retângulo.

```
void GetTrueRect(LPRECT lpTrueRect) const;
```

### <a name="parameters"></a>Parâmetros

*lpTrueRect*<br/>
Ponteiro para `RECT` a estrutura que conterá `CRectTracker` as coordenadas do dispositivo do objeto.

### <a name="remarks"></a>Comentários

As dimensões do retângulo incluem a altura e a largura de quaisquer alças de redimensionamento localizadas na borda externa. Ao retornar, *lpTrueRect* é sempre um retângulo normalizado nas coordenadas do dispositivo.

## <a name="crecttrackerhittest"></a><a name="hittest"></a>CRectTracker::HitTest

Ligue para esta função para descobrir se o usuário pegou uma alça de redimensionamento.

```
int HitTest(CPoint point) const;
```

### <a name="parameters"></a>Parâmetros

*Ponto*<br/>
O ponto, nas coordenadas do dispositivo, para testar.

### <a name="return-value"></a>Valor retornado

O valor retornado é baseado no `CRectTracker::TrackerHit` tipo enumerado e pode ter um dos seguintes valores:

- `CRectTracker::hitNothing`-1

- `CRectTracker::hitTopLeft` 0

- `CRectTracker::hitTopRight`1

- `CRectTracker::hitBottomRight`2

- `CRectTracker::hitBottomLeft`3

- `CRectTracker::hitTop`4

- `CRectTracker::hitRight`5

- `CRectTracker::hitBottom`6

- `CRectTracker::hitLeft`7

- `CRectTracker::hitMiddle`8

## <a name="crecttrackerm_nhandlesize"></a><a name="m_nhandlesize"></a>CRectTracker::m_nHandleSize

O tamanho, em pixels, das `CRectTracker` alças de redimensionamento.

```
int m_nHandleSize;
```

### <a name="remarks"></a>Comentários

Inicializado com o valor padrão do sistema.

## <a name="crecttrackerm_rect"></a><a name="m_rect"></a>CRectTracker::m_rect

A posição atual do retângulo nas coordenadas do cliente (pixels).

```
CRect m_rect;
```

## <a name="crecttrackerm_sizemin"></a><a name="m_sizemin"></a>CRectTracker::m_sizeMin

O tamanho mínimo do retângulo.

```
CSize m_sizeMin;
```

### <a name="remarks"></a>Comentários

Ambos os `cx` valores padrão, e `cy`, são calculados a partir do valor padrão do sistema para a largura da borda. Este membro de dados `AdjustRect` é usado apenas pela função membro.

## <a name="crecttrackerm_nstyle"></a><a name="m_nstyle"></a>CRectTracker::m_nStyle

Estilo atual do retângulo.

```
UINT m_nStyle;
```

### <a name="remarks"></a>Comentários

Consulte [CRectTracker::CRectTracker](#crecttracker) para obter uma lista de estilos possíveis.

## <a name="crecttrackernormalizehit"></a><a name="normalizehit"></a>CRectTracker::NormalizeHit

Chame esta função para converter uma alça potencialmente invertida.

```
int NormalizeHit(int nHandle) const;
```

### <a name="parameters"></a>Parâmetros

*nHandle*<br/>
Cabo selecionado pelo usuário.

### <a name="return-value"></a>Valor retornado

O índice da alça normalizada.

### <a name="remarks"></a>Comentários

Quando `CRectTracker::Track` `CRectTracker::TrackRubberBand` ou é chamado com inverter permitido, é possível que o retângulo seja invertido no eixo x, no eixo y ou ambos. Quando isso `HitTest` acontecer, retornará as alças que também são invertidas em relação ao retângulo. Isso é inapropriado para desenhar feedback do cursor porque o feedback depende da posição da tela do retângulo, não da parte da estrutura de dados retângulo que será modificada.

## <a name="crecttrackeronchangedrect"></a><a name="onchangedrect"></a>CRectTracker:OnChangedRect

Chamado pela estrutura sempre que o retângulo `Track`do rastreador foi alterado durante uma chamada para .

```
virtual void OnChangedRect(const CRect& rectOld);
```

### <a name="parameters"></a>Parâmetros

*rectOld*<br/>
Contém as antigas coordenadas `CRectTracker` do dispositivo do objeto.

### <a name="remarks"></a>Comentários

No momento em que esta função `DrawTrackerRect` é chamada, todos os feedbacks desenhados com foi removido. A implementação padrão desta função não faz nada.

Anular esta função quando você deseja executar quaisquer ações depois que o retângulo tiver sido redimensionado.

## <a name="crecttrackersetcursor"></a><a name="setcursor"></a>CRectTracker::SetCursor

Chame esta função para alterar a forma `CRectTracker` do cursor enquanto estiver sobre a região do objeto.

```
BOOL SetCursor(
    CWnd* pWnd,
    UINT nHitTest) const;
```

### <a name="parameters"></a>Parâmetros

*Pwnd*<br/>
Aponta para a janela que contém atualmente o cursor.

*nHitTest*<br/>
Resultados do teste de acerto anterior, da mensagem WM_SETCURSOR.

### <a name="return-value"></a>Valor retornado

Não zero se o golpe anterior foi sobre o retângulo do rastreador; caso contrário, 0.

### <a name="remarks"></a>Comentários

Chame esta função de dentro da função da sua janela `OnSetCursor`que lida com a mensagem WM_SETCURSOR (normalmente ).

## <a name="crecttrackertrack"></a><a name="track"></a>CRectTracker::Track

Chame esta função para exibir a interface do usuário para redimensionar o retângulo.

```
BOOL Track(
    CWnd* pWnd,
    CPoint point,
    BOOL bAllowInvert = FALSE,
    CWnd* pWndClipTo = NULL);
```

### <a name="parameters"></a>Parâmetros

*Pwnd*<br/>
O objeto da janela que contém o retângulo.

*Ponto*<br/>
Coordenadas do dispositivo da posição atual do mouse em relação à área do cliente.

*bAllowInvert*<br/>
Se TRUE, o retângulo pode ser invertido ao longo do eixo x ou do eixo y; caso contrário, FALSO.

*pWndClipTo*<br/>
A janela para a que as operações de desenho serão cortadas. Se NULL, *pWnd* é usado como retângulo de recorte.

### <a name="return-value"></a>Valor retornado

Se a tecla ESC for pressionada, o processo de rastreamento será interrompido, o retângulo armazenado no rastreador não será alterado e 0 será devolvido. Se a alteração for cometida, movendo o mouse e soltando o botão esquerdo do mouse, a nova posição e/ou tamanho é registrada no retângulo do rastreador e não zero é devolvida.

### <a name="remarks"></a>Comentários

Isso geralmente é chamado de dentro da função `WM_LBUTTONDOWN` do seu `OnLButtonDown`aplicativo que lida com a mensagem (normalmente ).

Esta função capturará o mouse até que o usuário libere o botão esquerdo do mouse, pressione a tecla ESC ou pressione o botão direito do mouse. À medida que o usuário move o cursor do mouse, o feedback é atualizado por chamada `DrawTrackerRect` e `OnChangedRect`.

Se *bAllowInvert* for TRUE, o retângulo de rastreamento pode ser invertido no eixo x ou no eixo y.

## <a name="crecttrackertrackrubberband"></a><a name="trackrubberband"></a>CRectTracker::TrackRubberBand

Chame esta função para fazer a seleção de elásticos.

```
BOOL TrackRubberBand(
    CWnd* pWnd,
    CPoint point,
    BOOL bAllowInvert = TRUE);
```

### <a name="parameters"></a>Parâmetros

*Pwnd*<br/>
O objeto da janela que contém o retângulo.

*Ponto*<br/>
Coordenadas do dispositivo da posição atual do mouse em relação à área do cliente.

*bAllowInvert*<br/>
Se TRUE, o retângulo pode ser invertido ao longo do eixo x ou do eixo y; caso contrário, FALSO.

### <a name="return-value"></a>Valor retornado

Não zero se o mouse se moveu e o retângulo não está vazio; caso contrário, 0.

### <a name="remarks"></a>Comentários

Geralmente é chamado de dentro da função do seu aplicativo `OnLButtonDown`que lida com a mensagem WM_LBUTTONDOWN (tipicamente ).

Esta função capturará o mouse até que o usuário libere o botão esquerdo do mouse, pressione a tecla ESC ou pressione o botão direito do mouse. À medida que o usuário move o cursor do mouse, o feedback é atualizado por chamada `DrawTrackerRect` e `OnChangedRect`.

O rastreamento é realizado com uma seleção do tipo banda de borracha da alça inferior direita. Se a inversão for permitida, o retângulo pode ser dimensionado arrastando-se para cima e para a esquerda ou para baixo e para a direita.

## <a name="see-also"></a>Confira também

[Rastreador de amostra MFC](../../overview/visual-cpp-samples.md)<br/>
[Amostra de MFC DRAWCLI](../../overview/visual-cpp-samples.md)<br/>
[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classe COleResizeBar](../../mfc/reference/coleresizebar-class.md)<br/>
[Classe CRect](../../atl-mfc-shared/reference/crect-class.md)
