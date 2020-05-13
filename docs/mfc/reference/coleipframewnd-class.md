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
ms.openlocfilehash: 01e259cf01c42add26088b0cbd2f6dab311eb9b1
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81374953"
---
# <a name="coleipframewnd-class"></a>Classe COleIPFrameWnd

A base para a janela de edição do aplicativo no local.

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
|[COleIPFrameWnd::OnCreateControlBars](#oncreatecontrolbars)|Chamado pela estrutura quando um item é ativado para edição no local.|
|[COleIPFrameWnd::ReposiçãoFrame](#repositionframe)|Chamado pela estrutura para reposicionar a janela de edição no local.|

## <a name="remarks"></a>Comentários

Essa classe cria e posiciona barras de controle dentro da janela de documento do aplicativo de contêiner. Ele também lida com notificações geradas por um objeto [COleResizeBar](../../mfc/reference/coleresizebar-class.md) incorporado quando o usuário redimensiona a janela de edição no local.

Para obter mais `COleIPFrameWnd`informações sobre como usar, consulte o artigo [Ativação](../../mfc/activation-cpp.md).

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[Cobject](../../mfc/reference/cobject-class.md)

[Ccmdtarget](../../mfc/reference/ccmdtarget-class.md)

[CWnd](../../mfc/reference/cwnd-class.md)

[CFrameWnd](../../mfc/reference/cframewnd-class.md)

`COleIPFrameWnd`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxole.h

## <a name="coleipframewndcoleipframewnd"></a><a name="coleipframewnd"></a>COleIPFrameWnd::COleIPFrameWnd

Constrói um `COleIPFrameWnd` objeto e inicializa suas informações de estado no local, que são armazenadas em uma estrutura do tipo OLEINPLACEFRAMEINFO.

```
COleIPFrameWnd();
```

### <a name="remarks"></a>Comentários

Para obter mais informações, consulte [OLEINPLACEFRAMEINFO](/windows/win32/api/oleidl/ns-oleidl-oleinplaceframeinfo) no SDK do Windows.

## <a name="coleipframewndoncreatecontrolbars"></a><a name="oncreatecontrolbars"></a>COleIPFrameWnd::OnCreateControlBars

A estrutura `OnCreateControlBars` chama a função quando um item é ativado para edição no local.

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
Ponteiro para a janela de quadro do aplicativo do contêiner.

*pWndDoc*<br/>
Ponteiro para a janela de nível de documento do contêiner. Pode ser NULO se o contêiner for uma aplicação SDI.

### <a name="return-value"></a>Valor retornado

Não zero no sucesso; caso contrário, 0.

### <a name="remarks"></a>Comentários

A implementação padrão não faz nada. Substituir esta função para executar qualquer processamento especial necessário quando as barras de controle forem criadas.

## <a name="coleipframewndrepositionframe"></a><a name="repositionframe"></a>COleIPFrameWnd::ReposiçãoFrame

A estrutura `RepositionFrame` chama a função de membro para definir as barras de controle e reposicionar a janela de edição no local para que todas elas possam ser visíveis.

```
virtual void RepositionFrame(
    LPCRECT lpPosRect,
    LPCRECT lpClipRect);
```

### <a name="parameters"></a>Parâmetros

*lpPosRect*<br/>
Ponteiro para `RECT` uma `CRect` estrutura ou um objeto contendo as coordenadas de posição atuais da janela do quadro no local, em pixels, em relação à área do cliente.

*lpClipRect*<br/>
Ponteiro para `RECT` uma `CRect` estrutura ou um objeto contendo as coordenadas de retângulo de retângulo de retângulo de retângulo de retângulo de recorte atual da janela no local, em pixels, em relação à área do cliente.

### <a name="remarks"></a>Comentários

O layout das barras de controle na janela do contêiner difere do realizado por uma janela de quadro não-OLE. A janela de quadro não-OLE calcula as posições das barras de controle e outros objetos a partir de um determinado tamanho de janela de quadro, como em uma chamada para [CFrameWnd::RecalcLayout](../../mfc/reference/cframewnd-class.md#recalclayout). A área do cliente é o que permanece após o espaço para barras de controle e outros objetos é subtraído. Uma `COleIPFrameWnd` janela, por outro lado, posiciona barras de ferramentas de acordo com uma determinada área do cliente. Em outras `CFrameWnd::RecalcLayout` palavras, funciona "de `COleIPFrameWnd::RepositionFrame` fora para dentro", enquanto funciona "de dentro para fora".

## <a name="see-also"></a>Confira também

[Amostra de MFC HIERSVR](../../overview/visual-cpp-samples.md)<br/>
[Classe CFrameWnd](../../mfc/reference/cframewnd-class.md)<br/>
[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classe CFrameWnd](../../mfc/reference/cframewnd-class.md)
