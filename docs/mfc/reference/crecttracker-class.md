---
title: Classe CRectTracker | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: reference
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
dev_langs:
- C++
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
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: eff57e1fde0af6e794c2c47db7d1e31daf545715
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="crecttracker-class"></a>Classe CRectTracker
Permite que um item para ser exibida, movida e redimensionada fashions diferentes.  
  
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
|[CRectTracker::GetHandleMask](#gethandlemask)|Chamado para obter a máscara de uma `CRectTracker` alças de redimensionamento do item.|  
|[CRectTracker::GetTrueRect](#gettruerect)|Retorna a largura e altura do retângulo, incluindo as alças de redimensionamento.|  
|[CRectTracker::HitTest](#hittest)|Retorna a posição atual do cursor relacionado para o `CRectTracker` objeto.|  
|[CRectTracker::NormalizeHit](#normalizehit)|Normaliza um código de teste de hit.|  
|[CRectTracker::OnChangedRect](#onchangedrect)|Chamado quando o retângulo foi redimensionado ou movido.|  
|[CRectTracker::SetCursor](#setcursor)|Define o cursor, dependendo de sua posição sobre o retângulo.|  
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
  
 Embora o `CRectTracker` classe foi projetada para permitir que o usuário interage com itens OLE usando uma interface gráfica, seu uso não está restrito a aplicativos habilitados pelo OLE. Ele pode ser usado em qualquer lugar, cada uma interface do usuário é necessária.  
  
 `CRectTracker` as bordas podem ser sólidas ou linhas pontilhadas. O item pode ser fornecido a uma borda tracejada ou marcado com um padrão hachurado para indicar estados diferentes do item. Você pode colocar oito alças de redimensionamento em dentro ou fora borda do item. (Para obter uma explicação das alças de redimensionamento, consulte [GetHandleMask](#gethandlemask).) Por fim, um `CRectTracker` permite que você altere a orientação de um item durante o redimensionamento.  
  
 Para usar `CRectTracker`, construir um `CRectTracker` de objeto e especificar quais estados de exibição são inicializados. Você pode usar esta interface para oferecer os comentários visuais do usuário sobre o status atual do item OLE associado a `CRectTracker` objeto.  
  
 Para obter mais informações sobre como usar `CRectTracker`, consulte o artigo [controladores](../../mfc/trackers.md).  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 `CRectTracker`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxext.h  
  
##  <a name="adjustrect"></a>  CRectTracker::AdjustRect  
 Chamado pelo framework quando o retângulo do controle é redimensionado usando uma alça de redimensionamento.  
  
```  
virtual void AdjustRect(
    int nHandle,  
    LPRECT lpRect);
```  
  
### <a name="parameters"></a>Parâmetros  
 `nHandle`  
 Índice do identificador usado.  
  
 `lpRect`  
 Ponteiro para o tamanho atual do retângulo. (O tamanho de um retângulo é determinado pela altura e largura).  
  
### <a name="remarks"></a>Comentários  
 O comportamento padrão dessa função permite que a orientação do retângulo alterar somente quando `Track` e `TrackRubberBand` são chamados com invertendo permitido.  
  
 Substitua essa função para controlar o ajuste do retângulo de controle durante uma operação de arrastar. É um método ajustar as coordenadas especificadas pelas `lpRect` antes de retornar.  
  
 Recursos especiais que não são diretamente suportados por `CRectTracker`, como a grade de ajuste ou mantenha--taxa de proporção, pode ser implementada por esta função de substituição.  
  
##  <a name="crecttracker"></a>  CRectTracker::CRectTracker  
 Cria e inicializa um objeto `CRectTracker`.  
  
```  
CRectTracker();

 
CRectTracker(
    LPCRECT lpSrcRect,  
    UINT nStyle);
```  
  
### <a name="parameters"></a>Parâmetros  
 `lpSrcRect`  
 As coordenadas do objeto retângulo.  
  
 `nStyle`  
 Especifica o estilo do `CRectTracker` objeto. Há suporte para os seguintes estilos:  
  
- **CRectTracker::solidLine** usar uma linha sólida para a borda do retângulo.  
  
- **CRectTracker::dottedLine** usar uma linha pontilhada para a borda do retângulo.  
  
- **CRectTracker::hatchedBorder** usar um padrão hachurado para a borda do retângulo.  
  
- **CRectTracker::resizeInside** localizadas dentro do retângulo de alças de redimensionamento.  
  
- **CRectTracker::resizeOutside** localizadas fora do retângulo de alças de redimensionamento.  
  
- **CRectTracker::hatchInside** Hatched padrão abrange todo o retângulo.  
  
### <a name="remarks"></a>Comentários  
 O construtor padrão inicializa o `CRectTracker` objeto com os valores de `lpSrcRect` e inicializa os outros tamanhos para os padrões do sistema. Se o objeto é criado sem parâmetros, o `m_rect` e `m_nStyle` membros de dados são inicializados.  
  
##  <a name="draw"></a>  CRectTracker::Draw  
 Chame essa função para desenhar linhas externas e a região interna do retângulo.  
  
```  
void Draw(CDC* pDC) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 `pDC`  
 Ponteiro para o contexto de dispositivo no qual desenhar.  
  
### <a name="remarks"></a>Comentários  
 O estilo do controlador determina como o desenho é feito. Consulte o construtor para `CRectTracker` para obter mais informações sobre os estilos disponíveis.  
  
##  <a name="drawtrackerrect"></a>  CRectTracker::DrawTrackerRect  
 Chamado pelo framework sempre que a posição do controlador foi alterado enquanto dentro de `Track` ou `TrackRubberBand` função de membro.  
  
```  
virtual void DrawTrackerRect(
    LPCRECT lpRect,  
    CWnd* pWndClipTo,  
    CDC* pDC,  
    CWnd* pWnd);
```  
  
### <a name="parameters"></a>Parâmetros  
 `lpRect`  
 Ponteiro para o `RECT` que contém o retângulo para desenhar.  
  
 `pWndClipTo`  
 Ponteiro para a janela para usar no retângulo de recorte.  
  
 `pDC`  
 Ponteiro para o contexto de dispositivo no qual desenhar.  
  
 `pWnd`  
 Ponteiro para a janela na qual o desenho ocorrerá.  
  
### <a name="remarks"></a>Comentários  
 A implementação padrão faz uma chamada para `CDC::DrawFocusRect`, que desenha um retângulo pontilhado.  
  
 Substitua esta função para fornecer comentários diferente durante a operação de controle.  
  
##  <a name="gethandlemask"></a>  CRectTracker::GetHandleMask  
 O framework chama esta função de membro para recuperar a máscara para um retângulo alças de redimensionamento.  
  
```  
virtual UINT GetHandleMask() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 A máscara de uma `CRectTracker` alças de redimensionamento do item.  
  
### <a name="remarks"></a>Comentários  
 As alças de redimensionamento aparecem das laterais e cantos do retângulo e permitir que o usuário controlar a forma e o tamanho do retângulo.  
  
 Um retângulo possui 8 alças de redimensionamento numeradas de 0 a 7. Cada alça de redimensionamento é representada por um bit da máscara; o valor desse bit é 2 ^ *n*, onde *n* é o número do identificador de redimensionamento. Bits 0-3 correspondem às alças de redimensionamento do canto, começando na parte superior esquerda movendo no sentido horário. Iniciando na parte superior no sentido horário de alças de redimensionamento do bits correspondem ao lado de 4 a 7. A ilustração a seguir mostra as alças de redimensionamento do retângulo e seus correspondente redimensionar o identificador de números e valores:  
  
 ![Redimensionar os números de identificador](../../mfc/reference/media/vc35dp1.gif "vc35dp1")  
  
 A implementação padrão de **GetHandleMask** retorna a máscara de bits para que sejam exibidas as alças de redimensionamento. Se for o único bit no, a alça de redimensionamento correspondente será desenhada.  
  
 Substitua essa função de membro para ocultar ou mostrar que o indicado alças de redimensionamento.  
  
##  <a name="gettruerect"></a>  CRectTracker::GetTrueRect  
 Chame essa função para recuperar as coordenadas do retângulo.  
  
```  
void GetTrueRect(LPRECT lpTrueRect) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 `lpTrueRect`  
 Ponteiro para o `RECT` estrutura que contém o dispositivo coordenadas do `CRectTracker` objeto.  
  
### <a name="remarks"></a>Comentários  
 As dimensões do retângulo incluem a altura e largura de qualquer alças de redimensionamento localizado na borda externa. No retorno, `lpTrueRect` é sempre um retângulo normalizado nas coordenadas do dispositivo.  
  
##  <a name="hittest"></a>  CRectTracker::HitTest  
 Chame essa função para descobrir se o usuário foi capturado uma alça de redimensionamento.  
  
```  
int HitTest(CPoint point) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 `point`  
 O ponto, nas coordenadas do dispositivo, para testar.  
  
### <a name="return-value"></a>Valor de retorno  
 O valor retornado é baseado no tipo enumerado **CRectTracker::TrackerHit** e pode ter um dos seguintes valores:  
  
- **CRectTracker::hitNothing** -1  
  
- **CRectTracker::hitTopLeft** 0  
  
- **CRectTracker::hitTopRight** 1  
  
- **CRectTracker::hitBottomRight** 2  
  
- **CRectTracker::hitBottomLeft** 3  
  
- **CRectTracker::hitTop** 4  
  
- **CRectTracker::hitRight** 5  
  
- **CRectTracker::hitBottom** 6  
  
- **CRectTracker::hitLeft** 7  
  
- **CRectTracker::hitMiddle** 8  
  
##  <a name="m_nhandlesize"></a>  CRectTracker::m_nHandleSize  
 O tamanho, em pixels, do `CRectTracker` alças de redimensionamento.  
  
```  
int m_nHandleSize;  
```  
  
### <a name="remarks"></a>Comentários  
 Inicializado com o valor padrão do sistema.  
  
##  <a name="m_rect"></a>  CRectTracker::m_rect  
 A posição atual do retângulo em coordenadas do cliente (em pixels).  
  
```  
CRect m_rect;  
```  
  
##  <a name="m_sizemin"></a>  CRectTracker::m_sizeMin  
 O tamanho mínimo do retângulo.  
  
```  
CSize m_sizeMin;  
```  
  
### <a name="remarks"></a>Comentários  
 Ambos os valores padrão, **cx** e **cy**, são calculados do valor padrão de sistema para a largura da borda. Este membro de dados é usado somente pelo `AdjustRect` função de membro.  
  
##  <a name="m_nstyle"></a>  CRectTracker::m_nStyle  
 Estilo atual do retângulo.  
  
```  
UINT m_nStyle;  
```  
  
### <a name="remarks"></a>Comentários  
 Consulte [CRectTracker::CRectTracker](#crecttracker) para obter uma lista de estilos possíveis.  
  
##  <a name="normalizehit"></a>  CRectTracker::NormalizeHit  
 Chame essa função para converter um identificador potencialmente invertido.  
  
```  
int NormalizeHit(int nHandle) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 `nHandle`  
 Identificador selecionado pelo usuário.  
  
### <a name="return-value"></a>Valor de retorno  
 O índice do identificador normalizado.  
  
### <a name="remarks"></a>Comentários  
 Quando `CRectTracker::Track` ou `CRectTracker::TrackRubberBand` é chamado com invertendo permitido, é possível para o retângulo deve ser invertida no eixo x, y ou ambos. Quando isso acontece, `HitTest` retornará identificadores também são invertidos em relação ao retângulo. Isso é apropriado para desenho comentários de cursor porque os comentários depende a posição da tela do retângulo, não a parte da estrutura de dados de retângulo que será modificada.  
  
##  <a name="onchangedrect"></a>  CRectTracker::OnChangedRect  
 Chamado pelo framework quando o retângulo do controlador foi alterada durante uma chamada para `Track`.  
  
```  
virtual void OnChangedRect(const CRect& rectOld);
```  
  
### <a name="parameters"></a>Parâmetros  
 *rectOld*  
 Contém as coordenadas do dispositivo antigo do `CRectTracker` objeto.  
  
### <a name="remarks"></a>Comentários  
 No momento em que essa função é chamada, todos os comentários desenhado com `DrawTrackerRect` foi removido. A implementação padrão dessa função não faz nada.  
  
 Substitua essa função quando quiser realizar nenhuma ação após o retângulo foi redimensionado.  
  
##  <a name="setcursor"></a>  CRectTracker::SetCursor  
 Chamar essa função para alterar a forma do cursor enquanto ele está sobre o `CRectTracker` região do objeto.  
  
```  
BOOL SetCursor(
    CWnd* pWnd,  
    UINT nHitTest) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 `pWnd`  
 Aponta para a janela que contém o cursor.  
  
 `nHitTest`  
 Resultados do teste de clique anterior, do `WM_SETCURSOR` mensagem.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se a ocorrência anterior no retângulo do rastreador; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Chamar essa função de dentro da função de janela que manipula o `WM_SETCURSOR` mensagem (geralmente `OnSetCursor`).  
  
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
 `pWnd`  
 O objeto de janela que contém o retângulo.  
  
 `point`  
 Coordenadas do dispositivo da posição atual do mouse relativas à área do cliente.  
  
 `bAllowInvert`  
 Se **TRUE**, o retângulo pode ser invertida ao longo do eixo x ou y; caso contrário **FALSE**.  
  
 `pWndClipTo`  
 A janela que as operações de desenho serão recortadas. Se **nulo**, `pWnd` é usado como o retângulo de recorte.  
  
### <a name="return-value"></a>Valor de retorno  
 Se for pressionada a tecla ESC, o processo de rastreamento é interrompido, o retângulo armazenado no controlador não é alterado e será retornado 0. Se a alteração é confirmada, movendo o mouse e liberar o botão esquerdo do mouse, a nova posição e/ou o tamanho é registrado no retângulo do controlador e diferente de zero será retornado.  
  
### <a name="remarks"></a>Comentários  
 Isso é geralmente chamado de dentro da função de aplicativo que manipula o `WM_LBUTTONDOWN` mensagem (geralmente `OnLButtonDown`).  
  
 Essa função capturará o mouse até que o usuário libera o botão esquerdo do mouse, pressiona a tecla ESC ou pressiona o botão direito do mouse. Quando o usuário move o cursor do mouse, os comentários é atualizado chamando `DrawTrackerRect` e `OnChangedRect`.  
  
 Se `bAllowInvert` é **TRUE**, o retângulo de controle pode ser invertido no eixo x ou y.  
  
##  <a name="trackrubberband"></a>  CRectTracker::TrackRubberBand  
 Chame essa função para fazer a seleção Elástico.  
  
```  
BOOL TrackRubberBand(
    CWnd* pWnd,  
    CPoint point,  
    BOOL bAllowInvert = TRUE);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pWnd`  
 O objeto de janela que contém o retângulo.  
  
 `point`  
 Coordenadas do dispositivo da posição atual do mouse relativas à área do cliente.  
  
 `bAllowInvert`  
 Se **verdadeiro,** o retângulo pode ser invertida ao longo do eixo x ou y; caso contrário **FALSE**.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se moveu o mouse e o retângulo não está vazio. Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Geralmente é chamado de dentro da função de aplicativo que manipula o `WM_LBUTTONDOWN` mensagem (geralmente `OnLButtonDown`).  
  
 Essa função capturará o mouse até que o usuário libera o botão esquerdo do mouse, pressiona a tecla ESC ou pressiona o botão direito do mouse. Quando o usuário move o cursor do mouse, os comentários é atualizado chamando `DrawTrackerRect` e `OnChangedRect`.  
  
 Controle é executado com uma seleção de tipo de faixa de borracha da alça inferior direito. Se invertendo for permitido, o retângulo pode ser dimensionado, arrastando o backup e para a esquerda ou para baixo e para a direita.  
  
## <a name="see-also"></a>Consulte também  
 [Exemplo MFC RASTREADOR](../../visual-cpp-samples.md)   
 [Exemplo MFC DRAWCLI](../../visual-cpp-samples.md)   
 [Gráfico de hierarquia](../../mfc/hierarchy-chart.md)   
 [Classe COleResizeBar](../../mfc/reference/coleresizebar-class.md)   
 [Classe CRect](../../atl-mfc-shared/reference/crect-class.md)
