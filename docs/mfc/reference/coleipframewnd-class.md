---
title: Classe COleIPFrameWnd
ms.date: 11/04/2016
f1_keywords:
- COleIPFrameWnd
- AFXOLE/COleIPFrameWnd
- AFXOLE/COleIPFrameWnd::COleIPFrameWnd
- AFXOLE/COleIPFrameWnd::OnCreateControlBars
- AFXOLE/COleIPFrameWnd::RepositionFrame
helpviewer_keywords:
- COleIPFrameWnd [MFC], COleIPFrameWnd
- COleIPFrameWnd [MFC], OnCreateControlBars
- COleIPFrameWnd [MFC], RepositionFrame
ms.assetid: 24abb2cb-826c-4dda-a287-d8a8900a5763
ms.openlocfilehash: 8eab2ddfc778900b53d77105f1d8215a2c095e9f
ms.sourcegitcommit: 180f63704f6ddd07a4172a93b179cf0733fd952d
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/06/2019
ms.locfileid: "70741566"
---
# <a name="coleipframewnd-class"></a>Classe COleIPFrameWnd

A base para a janela de edição in-loco do seu aplicativo.

## <a name="syntax"></a>Sintaxe

```
class COleIPFrameWnd : public CFrameWnd
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[COleIPFrameWnd::COleIPFrameWnd](#coleipframewnd)|Constrói um objeto `COleIPFrameWnd`.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[COleIPFrameWnd::OnCreateControlBars](#oncreatecontrolbars)|Chamado pelo Framework quando um item é ativado para edição in-loco.|
|[COleIPFrameWnd::RepositionFrame](#repositionframe)|Chamado pelo Framework para reposicionar a janela de edição in-loco.|

## <a name="remarks"></a>Comentários

Essa classe cria e posiciona barras de controle na janela de documento do aplicativo de contêiner. Ele também manipula as notificações geradas por um objeto [COleResizeBar](../../mfc/reference/coleresizebar-class.md) inserido quando o usuário redimensiona a janela de edição in-loco.

Para obter mais informações sobre `COleIPFrameWnd`como usar o, consulte o artigo [ativação](../../mfc/activation-cpp.md).

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[CObject](../../mfc/reference/cobject-class.md)

[CCmdTarget](../../mfc/reference/ccmdtarget-class.md)

[CWnd](../../mfc/reference/cwnd-class.md)

[CFrameWnd](../../mfc/reference/cframewnd-class.md)

`COleIPFrameWnd`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** Afxole. h

##  <a name="coleipframewnd"></a>  COleIPFrameWnd::COleIPFrameWnd

Constrói um `COleIPFrameWnd` objeto e inicializa suas informações de estado in-loco, que são armazenadas em uma estrutura do tipo OLEINPLACEFRAMEINFO.

```
COleIPFrameWnd();
```

### <a name="remarks"></a>Comentários

Para obter mais informações, consulte [OLEINPLACEFRAMEINFO](/windows/win32/api/oleidl/ns-oleidl-oleinplaceframeinfo) no SDK do Windows.

##  <a name="oncreatecontrolbars"></a>  COleIPFrameWnd::OnCreateControlBars

A estrutura chama a `OnCreateControlBars` função quando um item é ativado para edição in-loco.

```
virtual BOOL OnCreateControlBars(
    CWnd* pWndFrame,
    CWnd* pWndDoc);

virtual BOOL OnCreateControlBars(
    CFrameWnd* pWndFrame,
    CFrameWnd* pWndDoc);
```

### <a name="parameters"></a>Parâmetros

*pWndFrame*<br/>
Ponteiro para a janela do quadro do aplicativo de contêiner.

*pWndDoc*<br/>
Ponteiro para a janela de nível de documento do contêiner. Poderá ser NULL se o contêiner for um aplicativo SDI.

### <a name="return-value"></a>Valor de retorno

Diferente de zero em caso de êxito; caso contrário, 0.

### <a name="remarks"></a>Comentários

A implementação padrão não faz nada. Substitua essa função para executar qualquer processamento especial necessário quando as barras de controle forem criadas.

##  <a name="repositionframe"></a>  COleIPFrameWnd::RepositionFrame

A estrutura chama a `RepositionFrame` função de membro para dispor barras de controle e reposicionar a janela de edição in-loco para que tudo fique visível.

```
virtual void RepositionFrame(
    LPCRECT lpPosRect,
    LPCRECT lpClipRect);
```

### <a name="parameters"></a>Parâmetros

*lpPosRect*<br/>
Ponteiro para uma `RECT` estrutura ou um `CRect` objeto que contém as coordenadas da posição atual da janela do quadro no local, em pixels, em relação à área do cliente.

*lpClipRect*<br/>
Ponteiro para uma `RECT` estrutura ou um `CRect` objeto que contém as coordenadas do retângulo de recorte atual da janela de quadro no local, em pixels, em relação à área do cliente.

### <a name="remarks"></a>Comentários

O layout das barras de controle na janela do contêiner é diferente daquele executado por uma janela de quadro não OLE. A janela de quadro não OLE calcula as posições das barras de controle e outros objetos de um determinado tamanho de janela de quadro, como em uma chamada para [CFrameWnd:: RecalcLayout](../../mfc/reference/cframewnd-class.md#recalclayout). A área do cliente é o que permanece depois que o espaço para barras de controle e outros objetos é subtraído. Uma `COleIPFrameWnd` janela, por outro lado, posiciona barras de ferramentas de acordo com uma determinada área do cliente. Em outras palavras, `CFrameWnd::RecalcLayout` funciona "de fora em", enquanto `COleIPFrameWnd::RepositionFrame` funciona "de dentro para fora".

## <a name="see-also"></a>Consulte também

[Exemplo de HIERSVR do MFC](../../overview/visual-cpp-samples.md)<br/>
[Classe CFrameWnd](../../mfc/reference/cframewnd-class.md)<br/>
[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classe CFrameWnd](../../mfc/reference/cframewnd-class.md)
