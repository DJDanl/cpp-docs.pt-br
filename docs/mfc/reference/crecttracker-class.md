---
title: Classe CRectTracker | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- CRectTracker
dev_langs:
- C++
helpviewer_keywords:
- displaying items
- CRectTracker class
- resizing items
ms.assetid: 99caa7f2-3c0d-4a42-bbee-e5d1d342d4ee
caps.latest.revision: 23
author: mikeblome
ms.author: mblome
manager: ghogen
translation.priority.ht:
- cs-cz
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- pl-pl
- pt-br
- ru-ru
- tr-tr
- zh-cn
- zh-tw
translationtype: Machine Translation
ms.sourcegitcommit: 0e0c08ddc57d437c51872b5186ae3fc983bb0199
ms.openlocfilehash: 444eab5969339cf2a3d5797807eae3dcad32a694
ms.lasthandoff: 02/25/2017

---
# <a name="crecttracker-class"></a>Classe CRectTracker
Permite que um item seja exibido, movido e redimensionado em modismos diferentes.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class CRectTracker  
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CRectTracker::CRectTracker](#crecttracker)|Constrói um objeto `CRectTracker`.|  
  
### <a name="public-methods"></a>Métodos Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CRectTracker::AdjustRect](#adjustrect)|Chamado quando o retângulo é redimensionado.|  
|[CRectTracker::Draw](#draw)|Renderiza o retângulo.|  
|[CRectTracker::DrawTrackerRect](#drawtrackerrect)|Chamado ao desenhar a borda de uma `CRectTracker` objeto.|  
|[CRectTracker::GetHandleMask](#gethandlemask)|Chamado para obter a máscara de uma `CRectTracker`alças de redimensionamento do item.|  
|[CRectTracker::GetTrueRect](#gettruerect)|Retorna a largura e altura do retângulo, incluindo as alças de redimensionamento.|  
|[CRectTracker::HitTest](#hittest)|Retorna a posição atual do cursor relacionado para o `CRectTracker` objeto.|  
|[CRectTracker::NormalizeHit](#normalizehit)|Normaliza um código de teste de clique.|  
|[CRectTracker::OnChangedRect](#onchangedrect)|Chamado quando o retângulo foi redimensionado ou movido.|  
|[CRectTracker::SetCursor](#setcursor)|Define o cursor, dependendo de sua posição sobre o retângulo.|  
|[CRectTracker::Track](#track)|Permite ao usuário manipular o retângulo.|  
|[CRectTracker::TrackRubberBand](#trackrubberband)|Permite que o usuário "elástica" a seleção.|  
  
### <a name="public-data-members"></a>Membros de Dados Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CRectTracker::m_nHandleSize](#m_nhandlesize)|Determina o tamanho das alças de redimensionamento.|  
|[CRectTracker::m_nStyle](#m_nstyle)|Podem atual do controlador.|  
|[CRectTracker::m_rect](#m_rect)|Posição atual do retângulo (em pixels).|  
|[CRectTracker::m_sizeMin](#m_sizemin)|Determina a altura e largura do retângulo mínimo.|  
  
## <a name="remarks"></a>Comentários  
 `CRectTracker`não tem uma classe base.  
  
 Embora o `CRectTracker` classe foi projetada para permitir que o usuário interagir com itens OLE usando uma interface gráfica, seu uso não está restrito a aplicativos habilitados pelo OLE. Ele pode ser usado em qualquer lugar tal uma interface do usuário é necessária.  
  
 `CRectTracker`bordas podem ter uma base sólidas ou linhas pontilhadas. O item pode ser fornecido uma borda tracejada ou sobreposto com um padrão hachurado para indicar estados diferentes do item. Você pode colocar oito alças de redimensionamento na parte externa ou interna borda do item. (Para obter uma explicação das alças de redimensionamento, consulte [GetHandleMask](#gethandlemask).) Por fim, um `CRectTracker` permite que você altere a orientação de um item durante o redimensionamento.  
  
 Usar `CRectTracker`, construir um `CRectTracker` do objeto e especificar quais estados de exibição são inicializados. Você pode usar essa interface para dar ao usuário feedback visual sobre o status atual do item OLE associado a `CRectTracker` objeto.  
  
 Para obter mais informações sobre como usar o `CRectTracker`, consulte o artigo [rastreadores](../../mfc/trackers.md).  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 `CRectTracker`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxext.h  
  
##  <a name="a-nameadjustrecta--crecttrackeradjustrect"></a><a name="adjustrect"></a>CRectTracker::AdjustRect  
 Chamado pela estrutura quando o retângulo do controle é redimensionado usando uma alça de redimensionamento.  
  
```  
virtual void AdjustRect(
    int nHandle,  
    LPRECT lpRect);
```  
  
### <a name="parameters"></a>Parâmetros  
 `nHandle`  
 Índice do identificador usado.  
  
 `lpRect`  
 Ponteiro para o tamanho atual do retângulo. (O tamanho de um retângulo é fornecido por sua altura e largura).  
  
### <a name="remarks"></a>Comentários  
 O comportamento padrão dessa função permite que a orientação do retângulo alterar somente quando `Track` e `TrackRubberBand` são chamados com inversão permitido.  
  
 Substitua essa função para controlar o ajuste do retângulo de controle durante uma operação de arrastar. É um método ajustar as coordenadas especificadas pelas `lpRect` antes de retornar.  
  
 Recursos especiais que não são diretamente suportados pelo `CRectTracker`, como grade de ajuste ou keep-proporção, podem ser implementados, substituindo essa função.  
  
##  <a name="a-namecrecttrackera--crecttrackercrecttracker"></a><a name="crecttracker"></a>CRectTracker::CRectTracker  
 Cria e inicializa um `CRectTracker` objeto.  
  
```  
CRectTracker();

 
CRectTracker(
    LPCRECT lpSrcRect,  
    UINT nStyle);
```  
  
### <a name="parameters"></a>Parâmetros  
 `lpSrcRect`  
 As coordenadas do objeto de retângulo.  
  
 `nStyle`  
 Especifica o estilo do `CRectTracker` objeto. Há suporte para os seguintes estilos:  
  
- **CRectTracker::solidLine** usar uma linha sólida para a borda do retângulo.  
  
- **CRectTracker::dottedLine** usar uma linha pontilhada para a borda do retângulo.  
  
- **CRectTracker::hatchedBorder** usar um padrão hachurado para a borda do retângulo.  
  
- **CRectTracker::resizeInside** localizadas dentro do retângulo de alças de redimensionamento.  
  
- **CRectTracker::resizeOutside** localizadas fora do retângulo de alças de redimensionamento.  
  
- **CRectTracker::hatchInside** Hatched padrão abrange todo o retângulo.  
  
### <a name="remarks"></a>Comentários  
 O construtor padrão inicializa o `CRectTracker` objeto com os valores de `lpSrcRect` e inicializa a outros tamanhos de padrões do sistema. Se o objeto é criado sem parâmetros, o `m_rect` e `m_nStyle` membros de dados são inicializados.  
  
##  <a name="a-namedrawa--crecttrackerdraw"></a><a name="draw"></a>CRectTracker::Draw  
 Chame essa função para desenhar linhas externas e região interna do retângulo.  
  
```  
void Draw(CDC* pDC) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 `pDC`  
 Ponteiro para o contexto de dispositivo no qual desenhar.  
  
### <a name="remarks"></a>Comentários  
 O estilo do rastreador determina como o desenho é feito. Consulte o construtor para `CRectTracker` para obter mais informações sobre os estilos disponíveis.  
  
##  <a name="a-namedrawtrackerrecta--crecttrackerdrawtrackerrect"></a><a name="drawtrackerrect"></a>CRectTracker::DrawTrackerRect  
 Chamado pela estrutura sempre que a posição do controlador foi alterado enquanto dentro do `Track` ou `TrackRubberBand` função de membro.  
  
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
 Ponteiro para a janela para usar o retângulo de corte.  
  
 `pDC`  
 Ponteiro para o contexto de dispositivo no qual desenhar.  
  
 `pWnd`  
 Ponteiro para a janela na qual o desenho ocorrerá.  
  
### <a name="remarks"></a>Comentários  
 A implementação padrão faz uma chamada para `CDC::DrawFocusRect`, que desenha um retângulo pontilhado.  
  
 Substitua essa função para fornecer comentários diferentes durante a operação de rastreamento.  
  
##  <a name="a-namegethandlemaska--crecttrackergethandlemask"></a><a name="gethandlemask"></a>CRectTracker::GetHandleMask  
 O framework chama essa função de membro para recuperar a máscara de alças de redimensionamento de um retângulo.  
  
```  
virtual UINT GetHandleMask() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 A máscara de uma `CRectTracker` alças de redimensionamento do item.  
  
### <a name="remarks"></a>Comentários  
 As alças de redimensionamento aparecem das laterais e cantos do retângulo e permitem ao usuário controlar a forma e o tamanho do retângulo.  
  
 Um retângulo tem 8 alças de redimensionamento numeradas de 0 a 7. Cada alça de redimensionamento é representada por um bit na máscara; o valor desse bit é 2 ^ *n*, onde *n* é o número do identificador de redimensionamento. Bits de 0 a 3 correspondem às alças de redimensionamento de canto, começando na parte superior esquerda movendo no sentido horário. Começando pela parte superior no sentido horário de alças de redimensionamento de bits correspondem ao lado de 4 a 7. A ilustração a seguir mostra as alças de redimensionamento do retângulo e suas respectivas redimensionar números de identificador e valores:  
  
 ![Redimensionar os números de identificador](../../mfc/reference/media/vc35dp1.gif "vc35dp1")  
  
 A implementação padrão de **GetHandleMask** retorna a máscara de bits para que sejam exibidas as alças de redimensionamento. Se o bit único estiver ativado, a alça de redimensionamento correspondente será desenhada.  
  
 Substitua essa função de membro para ocultar ou mostrar que alças de redimensionamento indicado.  
  
##  <a name="a-namegettruerecta--crecttrackergettruerect"></a><a name="gettruerect"></a>CRectTracker::GetTrueRect  
 Chame essa função para recuperar as coordenadas do retângulo.  
  
```  
void GetTrueRect(LPRECT lpTrueRect) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 `lpTrueRect`  
 Ponteiro para o `RECT` estrutura que conterá o dispositivo coordenadas do `CRectTracker` objeto.  
  
### <a name="remarks"></a>Comentários  
 As dimensões do retângulo incluem a altura e largura de qualquer alças de redimensionamento localizado na borda externa. No retorno, `lpTrueRect` é sempre um retângulo normalizado nas coordenadas do dispositivo.  
  
##  <a name="a-namehittesta--crecttrackerhittest"></a><a name="hittest"></a>CRectTracker::HitTest  
 Chame essa função para descobrir se o usuário tem pegou uma alça de redimensionamento.  
  
```  
int HitTest(CPoint point) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 `point`  
 O ponto, nas coordenadas do dispositivo, para testar.  
  
### <a name="return-value"></a>Valor de retorno  
 O valor retornado é baseado no tipo enumerado **CRectTracker::TrackerHit** e pode ter um dos seguintes valores:  
  
- **CRectTracker::hitNothing** –&1;  
  
- **CRectTracker::hitTopLeft** 0  
  
- **CRectTracker::hitTopRight** 1  
  
- **CRectTracker::hitBottomRight** 2  
  
- **CRectTracker::hitBottomLeft** 3  
  
- **CRectTracker::hitTop** 4  
  
- **CRectTracker::hitRight** 5  
  
- **CRectTracker::hitBottom** 6  
  
- **CRectTracker::hitLeft** 7  
  
- **CRectTracker::hitMiddle** 8  
  
##  <a name="a-namemnhandlesizea--crecttrackermnhandlesize"></a><a name="m_nhandlesize"></a>CRectTracker::m_nHandleSize  
 O tamanho, em pixels, do `CRectTracker` alças de redimensionamento.  
  
```  
int m_nHandleSize;  
```  
  
### <a name="remarks"></a>Comentários  
 Inicializado com o valor padrão do sistema.  
  
##  <a name="a-namemrecta--crecttrackermrect"></a><a name="m_rect"></a>CRectTracker::m_rect  
 A posição atual do retângulo nas coordenadas do cliente (pixels).  
  
```  
CRect m_rect;  
```  
  
##  <a name="a-namemsizemina--crecttrackermsizemin"></a><a name="m_sizemin"></a>CRectTracker::m_sizeMin  
 O tamanho mínimo do retângulo.  
  
```  
CSize m_sizeMin;  
```  
  
### <a name="remarks"></a>Comentários  
 Ambos os valores padrão, **cx** e **cy**, são calculados a partir do valor padrão do sistema para a largura da borda. Este membro de dados é usado somente pelo `AdjustRect` função de membro.  
  
##  <a name="a-namemnstylea--crecttrackermnstyle"></a><a name="m_nstyle"></a>CRectTracker::m_nStyle  
 Estilo atual do retângulo.  
  
```  
UINT m_nStyle;  
```  
  
### <a name="remarks"></a>Comentários  
 Consulte [CRectTracker::CRectTracker](#crecttracker) para obter uma lista dos estilos possíveis.  
  
##  <a name="a-namenormalizehita--crecttrackernormalizehit"></a><a name="normalizehit"></a>CRectTracker::NormalizeHit  
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
 Quando `CRectTracker::Track` ou `CRectTracker::TrackRubberBand` é chamado com a inversão de permissão, é possível para o retângulo deve ser invertida no eixo x, y ou ambos. Quando isso acontece, `HitTest` retornará identificadores também são invertidos em relação ao retângulo. Isso é apropriado para desenho comentários de cursor porque os comentários depende a posição da tela do retângulo, não a parte da estrutura de dados de retângulo que será modificada.  
  
##  <a name="a-nameonchangedrecta--crecttrackeronchangedrect"></a><a name="onchangedrect"></a>CRectTracker::OnChangedRect  
 Chamado pela estrutura sempre que o retângulo do controlador foi alterado durante uma chamada para `Track`.  
  
```  
virtual void OnChangedRect(const CRect& rectOld);
```  
  
### <a name="parameters"></a>Parâmetros  
 *rectOld*  
 Contém as coordenadas de dispositivo antigo do `CRectTracker` objeto.  
  
### <a name="remarks"></a>Comentários  
 Quando essa função é chamada, e todos os comentários desenhado com `DrawTrackerRect` foi removido. A implementação padrão dessa função não faz nada.  
  
 Substitua essa função quando quiser realizar as ações após o retângulo foi redimensionado.  
  
##  <a name="a-namesetcursora--crecttrackersetcursor"></a><a name="setcursor"></a>CRectTracker::SetCursor  
 Chame essa função para alterar a forma do cursor enquanto ele está sobre o `CRectTracker` região do objeto.  
  
```  
BOOL SetCursor(
    CWnd* pWnd,  
    UINT nHitTest) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 `pWnd`  
 Aponta para a janela que contém o cursor no momento.  
  
 `nHitTest`  
 Resultados do teste de clique anterior, do `WM_SETCURSOR` mensagem.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se a ocorrência anterior em retângulo tracker; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Chame essa função de dentro da função de janela que manipula o `WM_SETCURSOR` mensagem (geralmente `OnSetCursor`).  
  
##  <a name="a-nametracka--crecttrackertrack"></a><a name="track"></a>CRectTracker::Track  
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
 Coordenadas do dispositivo da posição atual do mouse com relação à área do cliente.  
  
 `bAllowInvert`  
 Se **TRUE**, o retângulo pode ser invertido ao longo do eixo x ou y; caso contrário **FALSE**.  
  
 `pWndClipTo`  
 A janela que operações de desenho serão recortadas. Se **nulo**, `pWnd` é usado como o retângulo de corte.  
  
### <a name="return-value"></a>Valor de retorno  
 Se a tecla ESC é pressionada, o processo de rastreamento é interrompido, o retângulo armazenado no controlador não é alterado e 0 é retornado. Se a alteração é confirmada, movendo o mouse e liberar o botão esquerdo do mouse, a nova posição e/ou o tamanho é registrado no retângulo do controlador e diferente de zero será retornado.  
  
### <a name="remarks"></a>Comentários  
 Isso geralmente é chamado de dentro da função de aplicativo que manipula o `WM_LBUTTONDOWN` mensagem (geralmente `OnLButtonDown`).  
  
 Esta função irá capturar o mouse até que o usuário libera o botão esquerdo, pressiona a tecla ESC ou pressiona o botão direito do mouse. Quando o usuário move o cursor do mouse, os comentários é atualizado chamando `DrawTrackerRect` e `OnChangedRect`.  
  
 Se `bAllowInvert` é **TRUE**, o retângulo de rastreamento pode ser invertido no eixo x ou y.  
  
##  <a name="a-nametrackrubberbanda--crecttrackertrackrubberband"></a><a name="trackrubberband"></a>CRectTracker::TrackRubberBand  
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
 Coordenadas do dispositivo da posição atual do mouse com relação à área do cliente.  
  
 `bAllowInvert`  
 Se **verdadeiro,** o retângulo pode ser invertido ao longo do eixo x ou y; caso contrário **FALSE**.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se o mouse foi movido e o retângulo não está vazio; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Geralmente é chamado de dentro da função de aplicativo que manipula o `WM_LBUTTONDOWN` mensagem (geralmente `OnLButtonDown`).  
  
 Esta função irá capturar o mouse até que o usuário libera o botão esquerdo, pressiona a tecla ESC ou pressiona o botão direito do mouse. Quando o usuário move o cursor do mouse, os comentários é atualizado chamando `DrawTrackerRect` e `OnChangedRect`.  
  
 Rastreamento é executado com uma seleção de tipo de faixa de borracha na alça inferior direita. Se invertendo for permitido, o retângulo pode ser dimensionado arrastando tanto para cima e para a esquerda ou para baixo e à direita.  
  
## <a name="see-also"></a>Consulte também  
 [Exemplo MFC TRACKER](../../visual-cpp-samples.md)   
 [Exemplo MFC DRAWCLI](../../visual-cpp-samples.md)   
 [Gráfico de hierarquia](../../mfc/hierarchy-chart.md)   
 [Classe COleResizeBar](../../mfc/reference/coleresizebar-class.md)   
 [Classe CRect](../../atl-mfc-shared/reference/crect-class.md)

