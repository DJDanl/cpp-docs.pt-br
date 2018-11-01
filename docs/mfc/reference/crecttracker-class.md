---
title: Classe CRectTracker
ms.date: 11/04/2016
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
ms.openlocfilehash: 519f88a3706812ae77d7dbd77e199b3e3ef4e97a
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50473366"
---
# <a name="crecttracker-class"></a>Classe CRectTracker

Permite que um item seja exibido, movido e redimensionado em formas diferentes.

## <a name="syntax"></a>Sintaxe

```
class CRectTracker
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores Públicos

|Nome|Descrição|
|----------|-----------------|
|[CRectTracker::CRectTracker](#crecttracker)|Constrói um objeto `CRectTracker`.|

### <a name="public-methods"></a>Métodos Públicos

|Nome|Descrição|
|----------|-----------------|
|[CRectTracker::AdjustRect](#adjustrect)|Chamado quando o retângulo é redimensionado.|
|[CRectTracker::Draw](#draw)|Renderiza o retângulo.|
|[CRectTracker::DrawTrackerRect](#drawtrackerrect)|Chamado ao desenhar a borda de um `CRectTracker` objeto.|
|[CRectTracker::GetHandleMask](#gethandlemask)|Chamado para obter a máscara de um `CRectTracker` alças de redimensionamento do item.|
|[CRectTracker::GetTrueRect](#gettruerect)|Retorna a largura e altura do retângulo, incluindo as alças de redimensionamento.|
|[CRectTracker::HitTest](#hittest)|Retorna a posição atual do cursor relacionado ao `CRectTracker` objeto.|
|[CRectTracker::NormalizeHit](#normalizehit)|Normaliza um código de teste de clique.|
|[CRectTracker::OnChangedRect](#onchangedrect)|Chamado quando o retângulo foi redimensionado ou movido.|
|[CRectTracker::SetCursor](#setcursor)|Define o cursor, dependendo da sua posição ao longo do retângulo.|
|[CRectTracker::Track](#track)|Permite ao usuário manipular o retângulo.|
|[CRectTracker::TrackRubberBand](#trackrubberband)|Permite que o usuário "elástica" a seleção.|

### <a name="public-data-members"></a>Membros de Dados Públicos

|Nome|Descrição|
|----------|-----------------|
|[CRectTracker::m_nHandleSize](#m_nhandlesize)|Determina o tamanho das alças de redimensionamento.|
|[CRectTracker::m_nStyle](#m_nstyle)|Podem atual do controlador.|
|[CRectTracker::m_rect](#m_rect)|Posição atual (em pixels) do retângulo.|
|[CRectTracker::m_sizeMin](#m_sizemin)|Determina a altura e largura do retângulo mínimo.|

## <a name="remarks"></a>Comentários

`CRectTracker` não tem uma classe base.

Embora o `CRectTracker` classe é projetada para permitir que o usuário interagir com itens OLE usando uma interface gráfica, seu uso não está restrito a aplicativos habilitados pelo OLE. Ele pode ser usado em qualquer lugar que tal uma interface do usuário é necessária.

`CRectTracker` as bordas podem ter uma base sólidas ou linhas pontilhadas. O item pode ser dado uma borda hachurada ou sobreposto com um padrão hachurado para indicar diferentes estados do item. Você pode colocar oito alças de redimensionamento na parte externa ou interna borda do item. (Para obter uma explicação das alças de redimensionamento, consulte [GetHandleMask](#gethandlemask).) Por fim, um `CRectTracker` permite que você altere a orientação de um item durante o redimensionamento.

Para usar `CRectTracker`, construa um `CRectTracker` do objeto e especificar quais estados de exibição são inicializados. Em seguida, você pode usar essa interface para fornecer o feedback visual do usuário sobre o status atual do item OLE associado com o `CRectTracker` objeto.

Para obter mais informações sobre como usar `CRectTracker`, consulte o artigo [rastreadores](../../mfc/trackers.md).

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`CRectTracker`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxext.h

##  <a name="adjustrect"></a>  CRectTracker::AdjustRect

Chamado pelo framework quando o retângulo de controle é redimensionado usando uma alça de redimensionamento.

```
virtual void AdjustRect(
    int nHandle,
    LPRECT lpRect);
```

### <a name="parameters"></a>Parâmetros

*nHandle*<br/>
Índice do identificador usado.

*lpRect*<br/>
Ponteiro para o tamanho atual do retângulo. (O tamanho de um retângulo é determinado pela sua altura e largura).

### <a name="remarks"></a>Comentários

O comportamento padrão dessa função permite que a orientação do retângulo alterar somente quando `Track` e `TrackRubberBand` são chamados com invertendo permitido.

Substitua essa função para controlar o ajuste do retângulo de controle durante uma operação de arrastar. Um método é ajustar as coordenadas especificadas por *lpRect* antes de retornar.

Recursos especiais que não são diretamente suportados pelo `CRectTracker`, tais como a grade de ajuste ou keep--taxa de proporção, pode ser implementada por esta função de substituição.

##  <a name="crecttracker"></a>  CRectTracker::CRectTracker

Cria e inicializa um objeto `CRectTracker`.

```
CRectTracker();

CRectTracker(
    LPCRECT lpSrcRect,
    UINT nStyle);
```

### <a name="parameters"></a>Parâmetros

*lpSrcRect*<br/>
As coordenadas do objeto de retângulo.

*nStyle*<br/>
Especifica o estilo do `CRectTracker` objeto. Há suporte para os seguintes estilos:

- `CRectTracker::solidLine` Use uma linha sólida para a borda do retângulo.

- `CRectTracker::dottedLine` Use uma linha pontilhada para a borda do retângulo.

- `CRectTracker::hatchedBorder` Use um padrão hachurado da borda do retângulo.

- `CRectTracker::resizeInside` Localizado dentro do retângulo de alças de redimensionamento.

- `CRectTracker::resizeOutside` Localizados fora do retângulo de alças de redimensionamento.

- `CRectTracker::hatchInside` Hatched padrão abrange todo o retângulo.

### <a name="remarks"></a>Comentários

O construtor padrão inicializa o `CRectTracker` objeto com os valores de *lpSrcRect* e inicializa a outros tamanhos para os padrões do sistema. Se o objeto é criado sem parâmetros, o `m_rect` e `m_nStyle` membros de dados são inicializados.

##  <a name="draw"></a>  CRectTracker::Draw

Chame essa função para desenhar linhas externas e a região interna do retângulo.

```
void Draw(CDC* pDC) const;
```

### <a name="parameters"></a>Parâmetros

*pDC*<br/>
Ponteiro para o contexto de dispositivo no qual desenhar.

### <a name="remarks"></a>Comentários

O estilo de rastreador determina como o desenho é feito. Consulte o construtor para `CRectTracker` para obter mais informações sobre os estilos disponíveis.

##  <a name="drawtrackerrect"></a>  CRectTracker::DrawTrackerRect

Chamado pelo framework sempre que a posição do controlador foi alterada enquanto dentro de `Track` ou `TrackRubberBand` função de membro.

```
virtual void DrawTrackerRect(
    LPCRECT lpRect,
    CWnd* pWndClipTo,
    CDC* pDC,
    CWnd* pWnd);
```

### <a name="parameters"></a>Parâmetros

*lpRect*<br/>
Ponteiro para o `RECT` que contém o retângulo a ser desenhado.

*pWndClipTo*<br/>
Ponteiro para a janela a ser usado no retângulo de recorte.

*pDC*<br/>
Ponteiro para o contexto de dispositivo no qual desenhar.

*Apropriei*<br/>
Ponteiro para a janela na qual o desenho ocorrerá.

### <a name="remarks"></a>Comentários

A implementação padrão faz uma chamada para `CDC::DrawFocusRect`, que desenha um retângulo pontilhado.

Substitua essa função para fornecer comentários diferente durante a operação de acompanhamento.

##  <a name="gethandlemask"></a>  CRectTracker::GetHandleMask

O framework chama essa função de membro para recuperar a máscara de alças de redimensionamento de um retângulo.

```
virtual UINT GetHandleMask() const;
```

### <a name="return-value"></a>Valor de retorno

A máscara de um `CRectTracker` alças de redimensionamento do item.

### <a name="remarks"></a>Comentários

As alças de redimensionamento aparecem das laterais e cantos do retângulo e permitir que o usuário controlar a forma e o tamanho do retângulo.

Um retângulo tem 8 alças de redimensionamento numeradas de 0 a 7. Cada alça de redimensionamento é representada por um bit na máscara; o valor desse bit é 2 ^ *n*, onde *n* é o número da alça de redimensionamento. Bits de 0 a 3 correspondem às alças de redimensionamento de canto, começando na parte superior esquerda movimentação no sentido horário. Começando do topo no sentido horário de alças de redimensionamento de bits correspondem ao lado de 4 a 7. A ilustração a seguir mostra as alças de redimensionamento de um retângulo e suas respectivas redimensionar o identificador de números e valores:

![Redimensionar os números de identificador](../../mfc/reference/media/vc35dp1.gif "vc35dp1")

A implementação padrão de `GetHandleMask` retorna a máscara de bits para que sejam exibidas as alças de redimensionamento. Se o bit único estiver ativado, a alça de redimensionamento correspondente será desenhada.

Substitua essa função de membro para ocultar ou mostrar que alças de redimensionamento indicado.

##  <a name="gettruerect"></a>  CRectTracker::GetTrueRect

Chame essa função para recuperar as coordenadas do retângulo.

```
void GetTrueRect(LPRECT lpTrueRect) const;
```

### <a name="parameters"></a>Parâmetros

*lpTrueRect*<br/>
Ponteiro para o `RECT` coordena a estrutura que conterá o dispositivo do `CRectTracker` objeto.

### <a name="remarks"></a>Comentários

As dimensões do retângulo incluem a altura e largura de qualquer alças de redimensionamento localizadas na borda externa. Ao retornar, *lpTrueRect* é sempre um retângulo normalizado em coordenadas do dispositivo.

##  <a name="hittest"></a>  CRectTracker::HitTest

Chame essa função para descobrir se o usuário tem pegou uma alça de redimensionamento.

```
int HitTest(CPoint point) const;
```

### <a name="parameters"></a>Parâmetros

*ponto*<br/>
O ponto em coordenadas de dispositivo, para testar.

### <a name="return-value"></a>Valor de retorno

O valor retornado é baseado no tipo enumerado `CRectTracker::TrackerHit` e pode ter um dos seguintes valores:

- `CRectTracker::hitNothing` -1

- `CRectTracker::hitTopLeft` 0

- `CRectTracker::hitTopRight` 1

- `CRectTracker::hitBottomRight` 2

- `CRectTracker::hitBottomLeft` 3

- `CRectTracker::hitTop` 4

- `CRectTracker::hitRight` 5

- `CRectTracker::hitBottom` 6

- `CRectTracker::hitLeft` 7

- `CRectTracker::hitMiddle` 8

##  <a name="m_nhandlesize"></a>  CRectTracker::m_nHandleSize

O tamanho, em pixels, da `CRectTracker` alças de redimensionamento.

```
int m_nHandleSize;
```

### <a name="remarks"></a>Comentários

Inicializado com o valor padrão do sistema.

##  <a name="m_rect"></a>  CRectTracker::m_rect

A posição atual do retângulo em coordenadas do cliente (pixels).

```
CRect m_rect;
```

##  <a name="m_sizemin"></a>  CRectTracker::m_sizeMin

O tamanho mínimo do retângulo.

```
CSize m_sizeMin;
```

### <a name="remarks"></a>Comentários

Ambos os valores padrão, `cx` e `cy`, são calculados a partir do valor padrão do sistema para a largura da borda. Este membro de dados é usado somente pelo `AdjustRect` função de membro.

##  <a name="m_nstyle"></a>  CRectTracker::m_nStyle

Estilo atual do retângulo.

```
UINT m_nStyle;
```

### <a name="remarks"></a>Comentários

Ver [CRectTracker::CRectTracker](#crecttracker) para obter uma lista de possíveis estilos.

##  <a name="normalizehit"></a>  CRectTracker::NormalizeHit

Chame essa função para converter um identificador potencialmente invertido.

```
int NormalizeHit(int nHandle) const;
```

### <a name="parameters"></a>Parâmetros

*nHandle*<br/>
Identificador selecionado pelo usuário.

### <a name="return-value"></a>Valor de retorno

O índice do identificador normalizado.

### <a name="remarks"></a>Comentários

Quando `CRectTracker::Track` ou `CRectTracker::TrackRubberBand` é chamado com a inversão de permissão, é possível para o retângulo deve ser invertida no eixo x, y ou ambos. Quando isso acontece, `HitTest` retornará alças que também são invertidas em relação ao retângulo. Isso é apropriado para o desenho comentários de cursor porque os comentários depende a posição da tela do retângulo, não a parte da estrutura de dados de retângulo que será modificada.

##  <a name="onchangedrect"></a>  CRectTracker::OnChangedRect

Chamado pelo framework sempre que o retângulo de rastreador foi alterada durante uma chamada para `Track`.

```
virtual void OnChangedRect(const CRect& rectOld);
```

### <a name="parameters"></a>Parâmetros

*rectOld*<br/>
Contém as coordenadas do dispositivo antigo do `CRectTracker` objeto.

### <a name="remarks"></a>Comentários

No momento essa função é chamada, e todos os comentários desenhado com `DrawTrackerRect` foi removido. A implementação padrão dessa função não faz nada.

Substitua essa função quando você deseja executar quaisquer ações depois que o retângulo foi redimensionado.

##  <a name="setcursor"></a>  CRectTracker::SetCursor

Chame essa função para alterar a forma de cursor enquanto está sobre o `CRectTracker` região do objeto.

```
BOOL SetCursor(
    CWnd* pWnd,
    UINT nHitTest) const;
```

### <a name="parameters"></a>Parâmetros

*Apropriei*<br/>
Aponta para a janela que contém o cursor.

*nHitTest*<br/>
Resultados do teste de clique anterior, da mensagem WM_SETCURSOR.

### <a name="return-value"></a>Valor de retorno

Diferente de zero se a ocorrência anterior ultrapassou o retângulo de rastreador; Caso contrário, 0.

### <a name="remarks"></a>Comentários

Chame essa função de dentro da função de janela que manipula a mensagem WM_SETCURSOR (normalmente `OnSetCursor`).

##  <a name="track"></a>  CRectTracker::Track

Chame essa função para exibir a interface do usuário para redimensionar o retângulo.

```
BOOL Track(
    CWnd* pWnd,
    CPoint point,
    BOOL bAllowInvert = FALSE,
    CWnd* pWndClipTo = NULL);
```

### <a name="parameters"></a>Parâmetros

*Apropriei*<br/>
O objeto de janela que contém o retângulo.

*ponto*<br/>
Coordenadas do dispositivo da posição atual do mouse em relação à área de cliente.

*bAllowInvert*<br/>
Se for TRUE, o retângulo pode ser invertido ao longo do eixo x ou y; Caso contrário, FALSE.

*pWndClipTo*<br/>
A janela que operações de desenho serão recortadas. Se for NULL, *Apropriei* é usado como o retângulo de recorte.

### <a name="return-value"></a>Valor de retorno

Se a tecla ESC é pressionada, o processo de rastreamento será interrompido, o retângulo armazenado no controlador não é alterado e será retornado 0. Se a alteração é confirmada, movendo o mouse e soltando o botão esquerdo do mouse, a nova posição e/ou o tamanho é registrada no retângulo do rastreador e diferente de zero será retornado.

### <a name="remarks"></a>Comentários

Isso geralmente é chamado de dentro da função do aplicativo que lida com o `WM_LBUTTONDOWN` mensagens (normalmente `OnLButtonDown`).

Esta função irá capturar o mouse até que o usuário libera o botão esquerdo do mouse, pressiona a tecla ESC ou pressiona o botão direito do mouse. Quando o usuário move o cursor do mouse, os comentários é atualizado chamando `DrawTrackerRect` e `OnChangedRect`.

Se *bAllowInvert* for TRUE, o retângulo de controle pode ser invertido no eixo x ou y.

##  <a name="trackrubberband"></a>  CRectTracker::TrackRubberBand

Chame essa função para fazer a seleção de Retângulo Elástico.

```
BOOL TrackRubberBand(
    CWnd* pWnd,
    CPoint point,
    BOOL bAllowInvert = TRUE);
```

### <a name="parameters"></a>Parâmetros

*Apropriei*<br/>
O objeto de janela que contém o retângulo.

*ponto*<br/>
Coordenadas do dispositivo da posição atual do mouse em relação à área de cliente.

*bAllowInvert*<br/>
Se for TRUE, o retângulo pode ser invertido ao longo do eixo x ou y; Caso contrário, FALSE.

### <a name="return-value"></a>Valor de retorno

Diferente de zero se o mouse foi movido e o retângulo não está vazio. Caso contrário, 0.

### <a name="remarks"></a>Comentários

Geralmente é chamado de dentro da função do seu aplicativo que manipula a mensagem WM_LBUTTONDOWN (normalmente `OnLButtonDown`).

Esta função irá capturar o mouse até que o usuário libera o botão esquerdo do mouse, pressiona a tecla ESC ou pressiona o botão direito do mouse. Quando o usuário move o cursor do mouse, os comentários é atualizado chamando `DrawTrackerRect` e `OnChangedRect`.

Acompanhamento é executado com uma seleção de tipo de faixa de borracha na alça inferior direita. Se invertendo for permitido, o retângulo pode ser dimensionado, arrastando o backup e para a esquerda ou para baixo e à direita.

## <a name="see-also"></a>Consulte também

[Exemplo MFC RASTREADOR](../../visual-cpp-samples.md)<br/>
[Exemplo MFC DRAWCLI](../../visual-cpp-samples.md)<br/>
[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classe COleResizeBar](../../mfc/reference/coleresizebar-class.md)<br/>
[Classe CRect](../../atl-mfc-shared/reference/crect-class.md)
