---
title: Classe CImageList
ms.date: 11/04/2016
f1_keywords:
- CImageList
- AFXCMN/CImageList
- AFXCMN/CImageList::CImageList
- AFXCMN/CImageList::Add
- AFXCMN/CImageList::Attach
- AFXCMN/CImageList::BeginDrag
- AFXCMN/CImageList::Copy
- AFXCMN/CImageList::Create
- AFXCMN/CImageList::DeleteImageList
- AFXCMN/CImageList::DeleteTempMap
- AFXCMN/CImageList::Detach
- AFXCMN/CImageList::DragEnter
- AFXCMN/CImageList::DragLeave
- AFXCMN/CImageList::DragMove
- AFXCMN/CImageList::DragShowNolock
- AFXCMN/CImageList::Draw
- AFXCMN/CImageList::DrawEx
- AFXCMN/CImageList::DrawIndirect
- AFXCMN/CImageList::EndDrag
- AFXCMN/CImageList::ExtractIcon
- AFXCMN/CImageList::FromHandle
- AFXCMN/CImageList::FromHandlePermanent
- AFXCMN/CImageList::GetBkColor
- AFXCMN/CImageList::GetDragImage
- AFXCMN/CImageList::GetImageCount
- AFXCMN/CImageList::GetImageInfo
- AFXCMN/CImageList::GetSafeHandle
- AFXCMN/CImageList::Read
- AFXCMN/CImageList::Remove
- AFXCMN/CImageList::Replace
- AFXCMN/CImageList::SetBkColor
- AFXCMN/CImageList::SetDragCursorImage
- AFXCMN/CImageList::SetImageCount
- AFXCMN/CImageList::SetOverlayImage
- AFXCMN/CImageList::Write
- AFXCMN/CImageList::m_hImageList
helpviewer_keywords:
- CImageList [MFC], CImageList
- CImageList [MFC], Add
- CImageList [MFC], Attach
- CImageList [MFC], BeginDrag
- CImageList [MFC], Copy
- CImageList [MFC], Create
- CImageList [MFC], DeleteImageList
- CImageList [MFC], DeleteTempMap
- CImageList [MFC], Detach
- CImageList [MFC], DragEnter
- CImageList [MFC], DragLeave
- CImageList [MFC], DragMove
- CImageList [MFC], DragShowNolock
- CImageList [MFC], Draw
- CImageList [MFC], DrawEx
- CImageList [MFC], DrawIndirect
- CImageList [MFC], EndDrag
- CImageList [MFC], ExtractIcon
- CImageList [MFC], FromHandle
- CImageList [MFC], FromHandlePermanent
- CImageList [MFC], GetBkColor
- CImageList [MFC], GetDragImage
- CImageList [MFC], GetImageCount
- CImageList [MFC], GetImageInfo
- CImageList [MFC], GetSafeHandle
- CImageList [MFC], Read
- CImageList [MFC], Remove
- CImageList [MFC], Replace
- CImageList [MFC], SetBkColor
- CImageList [MFC], SetDragCursorImage
- CImageList [MFC], SetImageCount
- CImageList [MFC], SetOverlayImage
- CImageList [MFC], Write
- CImageList [MFC], m_hImageList
ms.assetid: b6d1a704-1c82-4548-8a8f-77972adc98a5
ms.openlocfilehash: eff2d0c1de88ebd9d949ebe197563c87c17e5b05
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81372443"
---
# <a name="cimagelist-class"></a>Classe CImageList

Fornece a funcionalidade do controle de lista de imagens comum do Windows.

## <a name="syntax"></a>Sintaxe

```
class CImageList : public CObject
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[CImageList::CImageList](#cimagelist)|Constrói um objeto `CImageList`.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CImageList::Adicionar](#add)|Adiciona uma imagem ou imagens a uma lista de imagens.|
|[CImageList::Anexo](#attach)|Anexa uma lista de `CImageList` imagens a um objeto.|
|[CImageList::BeginDrag](#begindrag)|Começa a arrastar uma imagem.|
|[CImageList::Copiar](#copy)|Copia uma imagem `CImageList` dentro de um objeto.|
|[CImageList::Criar](#create)|Inicializa uma lista de imagens `CImageList` e a anexa a um objeto.|
|[CImageList::DeleteImageList](#deleteimagelist)|Exclui uma lista de imagens.|
|[CImageList::DeleteTempMap](#deletetempmap)|Chamado pelo manipulador de tempo ocioso [CWinApp](../../mfc/reference/cwinapp-class.md) para excluir qualquer objeto temporário `CImageList` criado por `FromHandle`.|
|[CImageList::Detach](#detach)|Destaca um objeto da lista `CImageList` de imagens de um objeto e retorna uma alça para uma lista de imagens.|
|[CImageList::DragEnter](#dragenter)|Bloqueia as atualizações durante uma operação de arrastar e exibe a imagem de arrasto em uma posição especificada.|
|[CImageList::DragLeave](#dragleave)|Desbloqueia a janela e oculta a imagem de arrasto para que a janela possa ser atualizada.|
|[CImageList::DragMove](#dragmove)|Move a imagem que está sendo arrastada durante uma operação de arrastar e soltar.|
|[CImageList::DragShowNolock](#dragshownolock)|Mostra ou esconde a imagem de arrasto durante uma operação de arrasto, sem travar a janela.|
|[CImageList::Draw](#draw)|Desenha a imagem que está sendo arrastada durante uma operação de arrastar e soltar.|
|[CImageList::DrawEx](#drawex)|Desenha um item da lista de imagens no contexto do dispositivo especificado. A função usa o estilo de desenho especificado e combina a imagem com a cor especificada.|
|[CImageList::DrawIndirect](#drawindirect)|Desenha uma imagem de uma lista de imagens.|
|[CImageList::EndDrag](#enddrag)|Termina uma operação de arrasto.|
|[CImageList::ExtractIcon](#extracticon)|Cria um ícone baseado em uma imagem e máscara em uma lista de imagens.|
|[CImageList::FromHandle](#fromhandle)|Retorna um ponteiro `CImageList` a um objeto quando dado uma alça a uma lista de imagens. Se `CImageList` um objeto não estiver conectado à `CImageList` alça, um objeto temporário será criado e anexado.|
|[CImageList::FromHandlePermanent](#fromhandlepermanent)|Retorna um ponteiro `CImageList` a um objeto quando dado uma alça a uma lista de imagens. Se `CImageList` um objeto não estiver conectado à alça, NULL será devolvido.|
|[CImageList::GetBkColor](#getbkcolor)|Recupera a cor de fundo atual para uma lista de imagens.|
|[CImageList::GetDragImage](#getdragimage)|Obtém a lista de imagens temporárias que é usada para arrastar.|
|[CImageList::GetImageCount](#getimagecount)|Recupera o número de imagens em uma lista de imagens.|
|[CImageList::GetImageInfo](#getimageinfo)|Recupera informações sobre uma imagem.|
|[CImageList::GetSafeHandle](#getsafehandle)|Recupera `m_hImageList`.|
|[CImageList::Read](#read)|Lê uma lista de imagens de um arquivo.|
|[CImageList::Remove](#remove)|Remove uma imagem de uma lista de imagens.|
|[CImageList::Substituir](#replace)|Substitui uma imagem em uma lista de imagens por uma nova imagem.|
|[CImageList::SetBkColor](#setbkcolor)|Define a cor de fundo para uma lista de imagens.|
|[CImageList::SetDragCursorImage](#setdragcursorimage)|Cria uma nova imagem de arrasto.|
|[CImageList::SetImageCount](#setimagecount)|Redefine a contagem de imagens em uma lista de imagens.|
|[CImageList::SetOverlayImage](#setoverlayimage)|Adiciona o índice baseado em zero de uma imagem à lista de imagens a serem usadas como máscaras de sobreposição.|
|[CImageList::Write](#write)|Grava uma lista de imagens em um arquivo.|

### <a name="public-operators"></a>Operadores públicos

|Nome|Descrição|
|----------|-----------------|
|[CImageList::operador HIMAGELIST](#operator_himagelist)|Retorna o HIMAGELIST anexado ao `CImageList`.|

### <a name="public-data-members"></a>Membros de Dados Públicos

|Nome|Descrição|
|----------|-----------------|
|[CImageList::m_hImageList](#m_himagelist)|Uma alça contendo a lista de imagens anexada a este objeto.|

## <a name="remarks"></a>Comentários

Uma "lista de imagens" é uma coleção de imagens do mesmo tamanho, cada uma das quais pode ser referida pelo seu índice baseado em zero. As listas de imagens são usadas para gerenciar eficientemente grandes conjuntos de ícones ou bitmaps. Todas as imagens em uma lista de imagens estão contidas em um único bitmap largo no formato do dispositivo de tela. Uma lista de imagens também pode incluir um bitmap monocromático que contém máscaras usadas para desenhar imagens de forma transparente (estilo de ícone). A API (Application Programming Interface, interface de programação de aplicativos do Microsoft Win32) fornece funções de lista de imagens que permitem desenhar imagens, criar e destruir listas de imagens, adicionar e remover imagens, substituir imagens, mesclar imagens e arrastar imagens.

Este controle (e, `CImageList` portanto, a classe) está disponível apenas para programas em execução sob windows 95/98 e Windows NT versão 3.51 e posterior.

Para obter mais `CImageList`informações sobre como usar, consulte [Controles](../../mfc/controls-mfc.md) e [Usando CImageList](../../mfc/using-cimagelist.md).

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[Cobject](../../mfc/reference/cobject-class.md)

`CImageList`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxcmn.h

## <a name="cimagelistadd"></a><a name="add"></a>CImageList::Adicionar

Chame esta função para adicionar uma ou mais imagens ou um ícone a uma lista de imagens.

```
int Add(
    CBitmap* pbmImage,
    CBitmap* pbmMask);

int Add(
    CBitmap* pbmImage,
    COLORREF crMask);

int Add(HICON hIcon);
```

### <a name="parameters"></a>Parâmetros

*pbmImage*<br/>
Ponteiro para o bitmap contendo a imagem ou imagens. O número de imagens é inferido a partir da largura do bitmap.

*pbmMask*<br/>
Ponteiro para o bitmap contendo a máscara. Se nenhuma máscara for usada com a lista de imagens, este parâmetro será ignorado.

*crMask*<br/>
Cor usada para gerar a máscara. Cada pixel dessa cor no bitmap dado é alterado para preto e a parte correspondente na máscara é definida como uma.

*Hicon*<br/>
Manuseie o ícone que contém o bitmap e a máscara para a nova imagem.

### <a name="return-value"></a>Valor retornado

Índice baseado em zero da primeira nova imagem se for bem sucedido; caso contrário - 1.

### <a name="remarks"></a>Comentários

Você é responsável por liberar a alça do ícone quando terminar com ela.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CImageList#1](../../mfc/reference/codesnippet/cpp/cimagelist-class_1.cpp)]

## <a name="cimagelistattach"></a><a name="attach"></a>CImageList::Anexo

Chame esta função para anexar `CImageList` uma lista de imagens a um objeto.

```
BOOL Attach(HIMAGELIST hImageList);
```

### <a name="parameters"></a>Parâmetros

*Himagelist*<br/>
Uma alça para um objeto de lista de imagens.

### <a name="return-value"></a>Valor retornado

Não zero se o anexo foi bem sucedido; caso contrário, 0.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CImageList#2](../../mfc/reference/codesnippet/cpp/cimagelist-class_2.cpp)]

## <a name="cimagelistbegindrag"></a><a name="begindrag"></a>CImageList::BeginDrag

Chame esta função para começar a arrastar uma imagem.

```
BOOL BeginDrag(
    int nImage,
    CPoint ptHotSpot);
```

### <a name="parameters"></a>Parâmetros

*Nimage*<br/>
Índice baseado em zero da imagem para arrastar.

*ptHotSpot*<br/>
Coordenadas da posição inicial de arrasto (tipicamente, a posição do cursor). As coordenadas são relativas ao canto superior esquerdo da imagem.

### <a name="return-value"></a>Valor retornado

Não zero se bem sucedido; caso contrário, 0.

### <a name="remarks"></a>Comentários

Essa função cria uma lista de imagens temporárias que é usada para arrastar. A imagem combina a imagem especificada e sua máscara com o cursor atual. Em resposta às mensagens WM_MOUSEMOVE subseqüentes, você `DragMove` pode mover a imagem de arrastar usando a função membro. Para encerrar a operação de `EndDrag` arrastar, você pode usar a função membro.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CImageList#3](../../mfc/reference/codesnippet/cpp/cimagelist-class_3.cpp)]

## <a name="cimagelistcimagelist"></a><a name="cimagelist"></a>CImageList::CImageList

Constrói um objeto `CImageList`.

```
CImageList();
```

## <a name="cimagelistcopy"></a><a name="copy"></a>CImageList::Copiar

Esta função de membro implementa o comportamento da função Win32 [ImageList_Copy](/windows/win32/api/commctrl/nf-commctrl-imagelist_copy), conforme descrito no SDK do Windows.

```
BOOL Copy(
    int iDst,
    int iSrc,
    UINT uFlags = ILCF_MOVE);

BOOL Copy(
    int iDst,
    CImageList* pSrc,
    int iSrc,
    UINT uFlags = ILCF_MOVE);
```

### <a name="parameters"></a>Parâmetros

*iDst*<br/>
O índice baseado em zero da imagem a ser usada como destino da operação de cópia.

*Isrc*<br/>
O índice baseado em zero da imagem a ser usada como fonte da operação de cópia.

*Uflags*<br/>
O valor do bit flag que especifica o tipo de operação de cópia a ser feita. Este parâmetro pode ser um dos seguintes valores:

|Valor|Significado|
|-----------|-------------|
|ILCF_MOVE|A imagem de origem é copiada para o índice da imagem de destino. Esta operação resulta em várias instâncias de uma determinada imagem. ILCF_MOVE é o padrão.|
|ILCF_SWAP|As imagens de origem e destino trocam posições dentro da lista de imagens.|

*Psrc*<br/>
Um ponteiro `CImageList` para um objeto que é o alvo da operação de cópia.

### <a name="return-value"></a>Valor retornado

Não zero se bem sucedido; caso contrário, zero.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CImageList#6](../../mfc/reference/codesnippet/cpp/cimagelist-class_4.cpp)]

## <a name="cimagelistcreate"></a><a name="create"></a>CImageList::Criar

Inicializa uma lista de imagens e a anexa a um objeto [CImageList.](../../mfc/reference/cimagelist-class.md)

```
BOOL Create(
    int cx,
    int cy,
    UINT nFlags,
    int nInitial,
    int nGrow);

BOOL Create(
    UINT nBitmapID,
    int cx,
    int nGrow,
    COLORREF crMask);

BOOL Create(
    LPCTSTR lpszBitmapID,
    int cx,
    int nGrow,
    COLORREF crMask);

BOOL Create(
    CImageList& imagelist1,
    int nImage1,
    CImageList& imagelist2,
    int nImage2,
    int dx,
    int dy);

BOOL Create(CImageList* pImageList);
```

### <a name="parameters"></a>Parâmetros

*Cx*<br/>
Dimensões de cada imagem, em pixels.

*Cy*<br/>
Dimensões de cada imagem, em pixels.

*Nflags*<br/>
Especifica o tipo de lista de imagens a ser criada. Este parâmetro pode ser uma combinação dos seguintes valores, `ILC_COLOR` mas pode incluir apenas um dos valores.

|Valor|Significado|
|-----------|-------------|
|Ilc_color|Use o comportamento padrão se nenhum dos outros sinalizadores ILC_COLOR* for especificado. Normalmente, o padrão é ILC_COLOR4; mas para drivers de exibição mais antigos, o padrão é ILC_COLORDDB.|
|ILC_COLOR4|Use uma seção dib (bitmap) independente de dispositivo de 4 bits (16 cores) como o bitmap para a lista de imagens.|
|ILC_COLOR8|Use uma seção DIB de 8 bits. As cores usadas para a tabela de cores são as mesmas da paleta de meio tom.|
|ILC_COLOR16|Use uma seção DIB de 16 bits (32/64k).|
|ILC_COLOR24|Use uma seção DIB de 24 bits.|
|ILC_COLOR32|Use uma seção DIB de 32 bits.|
|ILC_COLORDDB|Use um bitmap dependente do dispositivo.|
|ILC_MASK|Usa uma máscara. A lista de imagens contém dois bitmaps, um dos quais é um bitmap monocromático usado como máscara. Se esse valor não estiver incluído, a lista de imagens contém apenas um bitmap. Consulte [Drawing Images de uma lista de imagens](../../mfc/drawing-images-from-an-image-list.md) para obter informações adicionais sobre imagens mascaradas.|

*nInicial*<br/>
Número de imagens que a lista de imagens contém inicialmente.

*nGrow*<br/>
Número de imagens pelas quais a lista de imagens pode crescer quando o sistema precisa redimensionar a lista para abrir espaço para novas imagens. Este parâmetro representa o número de novas imagens que a lista de imagens redimensionadas pode conter.

*nBitmapID*<br/>
IDs de recursos do bitmap a serem associados à lista de imagens.

*crMask*<br/>
Cor usada para gerar uma máscara. Cada pixel dessa cor no bitmap especificado é alterado para preto, e a parte correspondente na máscara é definida como uma.

*lpszBitmapID*<br/>
Uma seqüência contendo os IDs de recursos das imagens.

*imagelist1*<br/>
Uma referência a um objeto `CImageList`.

*nImage1*<br/>
Índice da primeira imagem existente.

*imagelist2*<br/>
Uma referência a um objeto `CImageList`.

*nImage2*<br/>
Índice da segunda imagem existente.

*Dx*<br/>
Deslocamento do eixo x da segunda imagem em relação à primeira imagem, em pixels.

*Dy*<br/>
Deslocamento do eixo y da segunda imagem em relação à primeira imagem, em pixels.

*pImageList*<br/>
Um ponteiro para um objeto `CImageList`.

### <a name="return-value"></a>Valor retornado

Não zero se bem sucedido; caso contrário, 0.

### <a name="remarks"></a>Comentários

Você constrói `CImageList` um em dois passos. Primeiro, ligue para o `Create`construtor e, em seguida, chame, `CImageList` que cria a lista de imagens e a anexa ao objeto.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CImageList#7](../../mfc/reference/codesnippet/cpp/cimagelist-class_5.cpp)]

## <a name="cimagelistdeleteimagelist"></a><a name="deleteimagelist"></a>CImageList::DeleteImageList

Chame esta função para excluir uma lista de imagens.

```
BOOL DeleteImageList();
```

### <a name="return-value"></a>Valor retornado

Não zero se bem sucedido; caso contrário, 0.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CImageList#8](../../mfc/reference/codesnippet/cpp/cimagelist-class_6.cpp)]

## <a name="cimagelistdeletetempmap"></a><a name="deletetempmap"></a>CImageList::DeleteTempMap

Chamado automaticamente pelo `CWinApp` manipulador de `DeleteTempMap` tempo ocioso, exclui quaisquer objetos `CImageList` temporários criados pelo [FromHandle,](#fromhandle)mas não destrói nenhuma alça () `hImageList`temporariamente associada aos `ImageList` objetos.

```
static void PASCAL DeleteTempMap();
```

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CImageList#9](../../mfc/reference/codesnippet/cpp/cimagelist-class_7.cpp)]

## <a name="cimagelistdetach"></a><a name="detach"></a>CImageList::Detach

Chame esta função para separar um `CImageList` objeto da lista de imagens de um objeto.

```
HIMAGELIST Detach();
```

### <a name="return-value"></a>Valor retornado

Uma alça para um objeto de lista de imagens.

### <a name="remarks"></a>Comentários

Esta função retorna uma alça para o objeto da lista de imagens.

### <a name="example"></a>Exemplo

  Veja o exemplo de [CImageList::Attach](#attach).

## <a name="cimagelistdragenter"></a><a name="dragenter"></a>CImageList::DragEnter

Durante uma operação de arrastar, bloqueia as atualizações na janela especificada por *pWndLock* e exibe a imagem de arrasto na posição especificada por *ponto*.

```
static BOOL PASCAL DragEnter(
    CWnd* pWndLock,
    CPoint point);
```

### <a name="parameters"></a>Parâmetros

*Pwndlock*<br/>
Ponteiro para a janela que possui a imagem de arrastar.

*Ponto*<br/>
Posição na qual exibir a imagem de arrasto. As coordenadas são relativas ao canto superior esquerdo da janela (não à área do cliente).

### <a name="return-value"></a>Valor retornado

Não zero se bem sucedido; caso contrário, 0.

### <a name="remarks"></a>Comentários

As coordenadas são relativas ao canto superior esquerdo da janela, então você deve compensar as larguras dos elementos da janela, como a borda, a barra de título e a barra de menu, ao especificar as coordenadas.

Se *pWndLock* for NULL, esta função desenha a imagem no contexto de exibição associado à janela da área de trabalho e as coordenadas são relativas ao canto superior esquerdo da tela.

Esta função bloqueia todas as outras atualizações na janela dada durante a operação de arrasto. Se você precisar fazer qualquer desenho durante uma operação de arrasto, como destacar o alvo de uma operação de arrastar e soltar, você pode ocultar temporariamente a imagem arrastada usando a função [CImageList::DragLeave.](#dragleave)

### <a name="example"></a>Exemplo

  Veja o exemplo de [CImageList::BeginDrag](#begindrag).

## <a name="cimagelistdragleave"></a><a name="dragleave"></a>CImageList::DragLeave

Desbloqueia a janela especificada por *pWndLock* e oculta a imagem de arrasto, permitindo que a janela seja atualizada.

```
static BOOL PASCAL DragLeave(CWnd* pWndLock);
```

### <a name="parameters"></a>Parâmetros

*Pwndlock*<br/>
Ponteiro para a janela que possui a imagem de arrastar.

### <a name="return-value"></a>Valor retornado

Não zero se bem sucedido; caso contrário, 0.

### <a name="example"></a>Exemplo

  Veja o exemplo de [CImageList::EndDrag](#enddrag).

## <a name="cimagelistdragmove"></a><a name="dragmove"></a>CImageList::DragMove

Chame esta função para mover a imagem que está sendo arrastada durante uma operação de arrastar e soltar.

```
static BOOL PASCAL DragMove(CPoint pt);
```

### <a name="parameters"></a>Parâmetros

*pt*<br/>
Nova posição de arrasto.

### <a name="return-value"></a>Valor retornado

Não zero se bem sucedido; caso contrário, 0.

### <a name="remarks"></a>Comentários

Esta função é normalmente chamada em resposta a uma mensagem WM_MOUSEMOVE. Para iniciar uma operação `BeginDrag` de arrasto, use a função do membro.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CImageList#4](../../mfc/reference/codesnippet/cpp/cimagelist-class_8.cpp)]

## <a name="cimagelistdragshownolock"></a><a name="dragshownolock"></a>CImageList::DragShowNolock

Mostra ou esconde a imagem de arrasto durante uma operação de arrasto, sem travar a janela.

```
static BOOL PASCAL DragShowNolock(BOOL bShow);
```

### <a name="parameters"></a>Parâmetros

*Bshow*<br/>
Especifica se a imagem de arrasto deve ser mostrada.

### <a name="return-value"></a>Valor retornado

Não zero se bem sucedido; caso contrário, 0.

### <a name="remarks"></a>Comentários

A função [CImageList::DragEnter](#dragenter) bloqueia todas as atualizações na janela durante uma operação de arrasto. Esta função, no entanto, não bloqueia a janela.

## <a name="cimagelistdraw"></a><a name="draw"></a>CImageList::Draw

Chame esta função para desenhar a imagem que está sendo arrastada durante uma operação de arrastar e soltar.

```
BOOL Draw(
    CDC* pDC,
    int nImage,
    POINT pt,
    UINT nStyle);
```

### <a name="parameters"></a>Parâmetros

*pDC*<br/>
Ponteiro para o contexto do dispositivo de destino.

*Nimage*<br/>
Índice baseado em zero da imagem para desenhar.

*pt*<br/>
Localização para desenhar dentro do contexto do dispositivo especificado.

*nStyle*<br/>
Sinalizador especificando o estilo de desenho. Pode ser um ou mais desses valores:

|Valor|Significado|
|-----------|-------------|
|ILD_BLEND25 ILD_FOCUS.|Desenha a imagem, misturando 25% com a cor de destaque do sistema. Este valor não tem efeito se a lista de imagens não contiver uma máscara.|
|ILD_BLEND50, ILD_SELECTED ILD_BLEND|Desenha a imagem, misturando 50% com a cor de destaque do sistema. Este valor não tem efeito se a lista de imagens não contiver uma máscara.|
|ILD_MASK|Desenha a máscara.|
|ILD_NORMAL|Desenha a imagem usando a cor de fundo para a lista de imagens. Se a cor de fundo for o valor CLR_NONE, a imagem será desenhada de forma transparente usando a máscara.|
|ILD_TRANSPARENT|Desenha a imagem de forma transparente usando a máscara, independentemente da cor de fundo.|

### <a name="return-value"></a>Valor retornado

Não zero se bem sucedido; caso contrário, 0.

### <a name="example"></a>Exemplo

  Veja o exemplo de [CImageList::SetOverlayImage](#setoverlayimage).

## <a name="cimagelistdrawex"></a><a name="drawex"></a>CImageList::DrawEx

Desenha um item da lista de imagens no contexto do dispositivo especificado.

```
BOOL DrawEx(
    CDC* pDC,
    int nImage,
    POINT pt,
    SIZE sz,
    COLORREF clrBk,
    COLORREF clrFg,
    UINT nStyle);
```

### <a name="parameters"></a>Parâmetros

*pDC*<br/>
Ponteiro para o contexto do dispositivo de destino.

*Nimage*<br/>
Índice baseado em zero da imagem para desenhar.

*pt*<br/>
Localização para desenhar dentro do contexto do dispositivo especificado.

*Sz*<br/>
Tamanho da parte da imagem para desenhar em relação ao canto superior esquerdo da imagem. Consulte *dx* e *dy* em [ImageList_DrawEx](/windows/win32/api/commctrl/nf-commctrl-imagelist_drawex) no Windows SDK.

*clrBk*<br/>
Cor de fundo da imagem. Veja *rgbBk* em [ImageList_DrawEx](/windows/win32/api/commctrl/nf-commctrl-imagelist_drawex) no Windows SDK.

*clrFg*<br/>
Cor do primeiro plano da imagem. Veja *rgbFg* em [ImageList_DrawEx](/windows/win32/api/commctrl/nf-commctrl-imagelist_drawex) no Windows SDK.

*nStyle*<br/>
Sinalizador especificando o estilo de desenho. Consulte *fStyle* em [ImageList_DrawEx](/windows/win32/api/commctrl/nf-commctrl-imagelist_drawex) no Windows SDK.

### <a name="return-value"></a>Valor retornado

Não zero se bem sucedido; caso contrário, 0.

### <a name="remarks"></a>Comentários

A função usa o estilo de desenho especificado e combina a imagem com a cor especificada.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CImageList#10](../../mfc/reference/codesnippet/cpp/cimagelist-class_9.cpp)]

## <a name="cimagelistdrawindirect"></a><a name="drawindirect"></a>CImageList::DrawIndirect

Chame esta função de membro para desenhar uma imagem de uma lista de imagens.

```
BOOL DrawIndirect(IMAGELISTDRAWPARAMS* pimldp);

BOOL DrawIndirect(
    CDC* pDC,
    int nImage,
    POINT pt,
    SIZE sz,
    POINT ptOrigin,
    UINT fStyle = ILD_NORMAL,
    DWORD dwRop = SRCCOPY,
    COLORREF rgbBack = CLR_DEFAULT,
    COLORREF rgbFore = CLR_DEFAULT,
    DWORD fState = ILS_NORMAL,
    DWORD Frame = 0,
    COLORREF crEffect = CLR_DEFAULT);
```

### <a name="parameters"></a>Parâmetros

*pimldp*<br/>
Um ponteiro para uma estrutura [IMAGELISTDRAWPARAMS](/windows/win32/api/commctrl/ns-commctrl-imagelistdrawparams) que contém informações sobre a operação de sorteio.

*pDC*<br/>
Um ponteiro para o contexto do dispositivo de destino. Você deve excluir este objeto [CDC](../../mfc/reference/cdc-class.md) quando terminar com ele.

*Nimage*<br/>
O índice baseado em zero da imagem a ser desenhada.

*pt*<br/>
Uma estrutura [POINT](/previous-versions/dd162805\(v=vs.85\)) contendo as coordenadas x e y onde a imagem será desenhada.

*Sz*<br/>
Uma [estrutura SIZE](/windows/win32/api/windef/ns-windef-size) indicando o tamanho da imagem a ser desenhada.

*ptOrigin*<br/>
Uma estrutura [POINT](/previous-versions/dd162805\(v=vs.85\)) contendo as coordenadas x e y especificando o canto superior esquerdo da operação de desenho em relação à própria imagem. Os pixels da imagem que estão à esquerda da coordenada x e acima da coordenada y não são desenhados.

*Fstyle*<br/>
Sinalizar especificando o estilo de desenho e, opcionalmente, a imagem de sobreposição. Consulte a seção Observações para obter informações sobre a imagem de sobreposição. A implementação padrão do MFC, ILD_NORMAL, desenha a imagem usando a cor de fundo para a lista de imagens. Se a cor de fundo for o valor CLR_NONE, a imagem será desenhada de forma transparente usando uma máscara.

Outros estilos possíveis são descritos sob o membro *fStyle* da estrutura [IMAGELISTDRAWPARAMS.](/windows/win32/api/commctrl/ns-commctrl-imagelistdrawparams)

*{1&amp;gt;dwRop&amp;lt;1}*<br/>
Valor especificando um código de operação de raster. Esses códigos definem como os dados de cor do retângulo de origem serão combinados com os dados de cor do retângulo de destino para alcançar a cor final. A implementação padrão do MFC, SRCCOPY, copia o retângulo de origem diretamente para o retângulo de destino. Este parâmetro é ignorado se o parâmetro *fStyle* não incluir a bandeira ILD_ROP.

Outros valores possíveis são descritos sob o membro *dwRop* da estrutura [IMAGELISTDRAWPARAMS.](/windows/win32/api/commctrl/ns-commctrl-imagelistdrawparams)

*rgbBack*<br/>
A cor de fundo da imagem, por padrão CLR_DEFAULT. Este parâmetro pode ser um valor RGB definido pelo aplicativo ou um dos seguintes valores:

|Valor|Significado|
|-----------|-------------|
|Clr_default|Cor de fundo padrão. A imagem é desenhada usando a cor de fundo da lista de imagens.|
|Clr_none|Sem cor de fundo. A imagem é desenhada de forma transparente.|

*rgbFore*<br/>
Cor do primeiro plano da imagem, por padrão CLR_DEFAULT. Este parâmetro pode ser um valor RGB definido pelo aplicativo ou um dos seguintes valores:

|Valor|Significado|
|-----------|-------------|
|Clr_default|Cor padrão do primeiro plano. A imagem é desenhada usando a cor de destaque do sistema como a cor do primeiro plano.|
|Clr_none|Sem cor de mistura. A imagem é misturada com a cor do contexto do dispositivo de destino.|

Este parâmetro só é usado se *fStyle* incluir a bandeira ILD_BLEND25 ou ILD_BLEND50.

*fEstado*<br/>
Bandeira especificando o estado de desenho. Este membro pode conter uma ou mais bandeiras de estado da lista de imagens.

*Quadro*<br/>
Afeta o comportamento de efeitos saturados e de mistura alfa.

Quando usado com ILS_SATURATE, este membro mantém o valor adicionado a cada componente de cor do trigêmeo RGB para cada pixel no ícone.

Quando usado com ILS_APLHA, este membro detém o valor para o canal alfa. Esse valor pode ser de 0 a 255, sendo 0 completamente transparente, sendo 255 completamente opaco.

*crEffect*<br/>
Um valor [COLORREF](/windows/win32/gdi/colorref) usado para efeitos de brilho e sombra.

### <a name="return-value"></a>Valor retornado

VERDADE se a imagem for desenhada com sucesso; caso contrário, FALSO.

### <a name="remarks"></a>Comentários

Use a primeira versão se quiser preencher a estrutura win32 você mesmo. Use a segunda versão se quiser tirar proveito de um ou mais argumentos padrão do MFC ou evitar gerenciar a estrutura.

Uma imagem sobreposição é uma imagem desenhada no topo da imagem principal, especificada nesta função de membro pelo parâmetro *nImage.* Desenhe uma máscara de sobreposição usando a função [Draw](#draw) membro com o índice único da máscara de sobreposição especificado usando a macro [INDEXTOOVERLAYMASK.](/windows/win32/api/commctrl/nf-commctrl-indextooverlaymask)

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CImageList#11](../../mfc/reference/codesnippet/cpp/cimagelist-class_10.cpp)]

## <a name="cimagelistenddrag"></a><a name="enddrag"></a>CImageList::EndDrag

Chame esta função para acabar com uma operação de arrasto.

```
static void PASCAL EndDrag();
```

### <a name="remarks"></a>Comentários

Para iniciar uma operação `BeginDrag` de arrasto, use a função do membro.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CImageList#5](../../mfc/reference/codesnippet/cpp/cimagelist-class_11.cpp)]

## <a name="cimagelistextracticon"></a><a name="extracticon"></a>CImageList::ExtractIcon

Chame essa função para criar um ícone baseado em uma imagem e sua máscara relacionada em uma lista de imagens.

```
HICON ExtractIcon(int nImage);
```

### <a name="parameters"></a>Parâmetros

*Nimage*<br/>
Índice baseado em zero da imagem.

### <a name="return-value"></a>Valor retornado

Manuseie o ícone se for bem sucedido; caso contrário, NULL.

### <a name="remarks"></a>Comentários

Este método se baseia no comportamento da [ImageList_ExtractIcon](/windows/win32/api/commctrl/nf-commctrl-imagelist_extracticon) macro para criar o ícone. Consulte a [macro ImageList_ExtractIcon](/windows/win32/api/commctrl/nf-commctrl-imagelist_extracticon) para obter mais informações sobre criação e limpeza de ícones.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CImageList#12](../../mfc/reference/codesnippet/cpp/cimagelist-class_12.cpp)]

## <a name="cimagelistfromhandle"></a><a name="fromhandle"></a>CImageList::FromHandle

Retorna um ponteiro `CImageList` a um objeto quando dado uma alça a uma lista de imagens.

```
static CImageList* PASCAL FromHandle(HIMAGELIST hImageList);
```

### <a name="parameters"></a>Parâmetros

*Himagelist*<br/>
Especifica a lista de imagens.

### <a name="return-value"></a>Valor retornado

Um ponteiro `CImageList` para um objeto se for bem sucedido; caso contrário, NULL.

### <a name="remarks"></a>Comentários

Se `CImageList` a ainda não estiver conectado à `CImageList` alça, um objeto temporário será criado e anexado. Este `CImageList` objeto temporário só é válido até a próxima vez que o aplicativo tiver tempo ocioso em seu loop de eventos, momento em que todos os objetos temporários são excluídos.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CImageList#13](../../mfc/reference/codesnippet/cpp/cimagelist-class_13.cpp)]

## <a name="cimagelistfromhandlepermanent"></a><a name="fromhandlepermanent"></a>CImageList::FromHandlePermanent

Retorna um ponteiro `CImageList` a um objeto quando dado uma alça a uma lista de imagens.

```
static CImageList* PASCAL FromHandlePermanent(HIMAGELIST hImageList);
```

### <a name="parameters"></a>Parâmetros

*Himagelist*<br/>
Especifica a lista de imagens.

### <a name="return-value"></a>Valor retornado

Um ponteiro `CImageList` para um objeto se for bem sucedido; caso contrário, NULL.

### <a name="remarks"></a>Comentários

Se `CImageList` um objeto não estiver conectado à alça, NULL será devolvido.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CImageList#14](../../mfc/reference/codesnippet/cpp/cimagelist-class_14.cpp)]

## <a name="cimagelistgetbkcolor"></a><a name="getbkcolor"></a>CImageList::GetBkColor

Chame esta função para recuperar a cor de fundo atual para uma lista de imagens.

```
COLORREF GetBkColor() const;
```

### <a name="return-value"></a>Valor retornado

O valor de cor `CImageList` RGB da cor de fundo do objeto.

### <a name="example"></a>Exemplo

  Veja o exemplo de [CImageList::SetBkColor](#setbkcolor).

## <a name="cimagelistgetdragimage"></a><a name="getdragimage"></a>CImageList::GetDragImage

Obtém a lista de imagens temporárias que é usada para arrastar.

```
static CImageList* PASCAL GetDragImage(
    LPPOINT lpPoint,
    LPPOINT lpPointHotSpot);
```

### <a name="parameters"></a>Parâmetros

*Lppoint*<br/>
Endereço de uma estrutura [POINT](/previous-versions/dd162805\(v=vs.85\)) que recebe a posição de arrasto atual.

*lpPointHotSpot*<br/>
Endereço de `POINT` uma estrutura que recebe o deslocamento da imagem de arrasto em relação à posição de arrastar.

### <a name="return-value"></a>Valor retornado

Se for bem-sucedido, um ponteiro para a lista de imagens temporárias usada para arrastar; caso contrário, NULL.

## <a name="cimagelistgetimagecount"></a><a name="getimagecount"></a>CImageList::GetImageCount

Ligue para esta função para recuperar o número de imagens em uma lista de imagens.

```
int GetImageCount() const;
```

### <a name="return-value"></a>Valor retornado

O número de imagens.

### <a name="example"></a>Exemplo

  Veja o exemplo de [CImageList::ExtractIcon](#extracticon).

## <a name="cimagelistgetimageinfo"></a><a name="getimageinfo"></a>CImageList::GetImageInfo

Ligue para esta função para recuperar informações sobre uma imagem.

```
BOOL GetImageInfo(
    int nImage,
    IMAGEINFO* pImageInfo) const;
```

### <a name="parameters"></a>Parâmetros

*Nimage*<br/>
Índice baseado em zero da imagem.

*pImageInfo*<br/>
Pointer para uma estrutura [IMAGEINFO](/windows/win32/api/commctrl/ns-commctrl-imageinfo) que recebe informações sobre a imagem. As informações nesta estrutura podem ser usadas para manipular diretamente os bitmaps para a imagem.

### <a name="return-value"></a>Valor retornado

Não zero se bem sucedido; caso contrário, 0.

### <a name="remarks"></a>Comentários

A `IMAGEINFO` estrutura contém informações sobre uma imagem em uma lista de imagens.

## <a name="cimagelistgetsafehandle"></a><a name="getsafehandle"></a>CImageList::GetSafeHandle

Ligue para esta `m_hImageList` função para recuperar o membro de dados.

```
HIMAGELIST GetSafeHandle() const;
```

### <a name="return-value"></a>Valor retornado

Uma alça para a lista de imagens anexada; caso contrário, NULL se nenhum objeto for anexado.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CImageList#15](../../mfc/reference/codesnippet/cpp/cimagelist-class_15.cpp)]

## <a name="cimagelistm_himagelist"></a><a name="m_himagelist"></a>CImageList::m_hImageList

Uma alça da lista de imagens anexada a este objeto.

`HIMAGELIST m_hImageList;`

### <a name="remarks"></a>Comentários

O `m_hImageList` membro de dados é uma variável pública do tipo HIMAGELIST.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CImageList#23](../../mfc/reference/codesnippet/cpp/cimagelist-class_16.cpp)]

## <a name="cimagelistoperator-himagelist"></a><a name="operator_himagelist"></a>CImageList::operador HIMAGELIST

Use este operador para obter a `CImageList` alça anexada do objeto.

```
operator HIMAGELIST() const;
```

### <a name="return-value"></a>Valor retornado

Se for bem-sucedido, uma alça `CImageList` para a lista de imagens representada pelo objeto; caso contrário, NULL.

### <a name="remarks"></a>Comentários

Este operador é um operador de fundição, que suporta o uso direto de um objeto HIMAGELIST.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CImageList#16](../../mfc/reference/codesnippet/cpp/cimagelist-class_17.cpp)]

## <a name="cimagelistread"></a><a name="read"></a>CImageList::Read

Chame esta função para ler uma lista de imagens de um arquivo.

```
BOOL Read(CArchive* pArchive);
```

### <a name="parameters"></a>Parâmetros

*pArchive*<br/>
Um ponteiro `CArchive` para um objeto do qual a lista de imagens deve ser lida.

### <a name="return-value"></a>Valor retornado

Não zero se bem sucedido; caso contrário, 0.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CImageList#18](../../mfc/reference/codesnippet/cpp/cimagelist-class_18.cpp)]

## <a name="cimagelistremove"></a><a name="remove"></a>CImageList::Remove

Chame esta função para remover uma imagem de um objeto de lista de imagens.

```
BOOL Remove(int nImage);
```

### <a name="parameters"></a>Parâmetros

*Nimage*<br/>
Índice baseado em zero da imagem para remover.

### <a name="return-value"></a>Valor retornado

Não zero se bem sucedido; caso contrário, 0.

### <a name="remarks"></a>Comentários

Todos os itens que seguem *nImage* agora descem uma posição. Por exemplo, se uma lista de imagens contiver dois itens, a exclusão do primeiro item fará com que o item restante esteja agora na primeira posição. *nImage*=0 para o item na primeira posição.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CImageList#19](../../mfc/reference/codesnippet/cpp/cimagelist-class_19.cpp)]

## <a name="cimagelistreplace"></a><a name="replace"></a>CImageList::Substituir

Chame essa função para substituir uma imagem em uma lista de imagens por uma nova imagem.

```
BOOL Replace(
    int nImage,
    CBitmap* pbmImage,
    CBitmap* pbmMask);

int Replace(
    int nImage,
    HICON hIcon);
```

### <a name="parameters"></a>Parâmetros

*Nimage*<br/>
Índice baseado em zero da imagem para substituir.

*pbmImage*<br/>
Um ponteiro para o bitmap que contém a imagem.

*pbmMask*<br/>
Um ponteiro para o bitmap contendo a máscara. Se nenhuma máscara for usada com a lista de imagens, este parâmetro será ignorado.

*Hicon*<br/>
Uma alça para o ícone que contém o bitmap e a máscara para a nova imagem.

### <a name="return-value"></a>Valor retornado

A versão que retorna BOOL retorna sem zero se for bem sucedida; caso contrário, 0.

A versão que retorna **int** retorna o índice baseado em zero da imagem se for bem-sucedida; caso contrário - 1.

### <a name="remarks"></a>Comentários

Ligue para esta função de membro depois de ligar para [SetImageCount](#setimagecount) para atribuir as novas imagens válidas aos números de índice de imagem do espaço reservado.

### <a name="example"></a>Exemplo

  Veja o exemplo de [CImageList::SetImageCount](#setimagecount).

## <a name="cimagelistsetbkcolor"></a><a name="setbkcolor"></a>CImageList::SetBkColor

Chame esta função para definir a cor de fundo de uma lista de imagens.

```
COLORREF SetBkColor(COLORREF cr);
```

### <a name="parameters"></a>Parâmetros

*Cr*<br/>
Cor de fundo a definir. Pode ser CLR_NONE. Nesse caso, as imagens são desenhadas de forma transparente usando a máscara.

### <a name="return-value"></a>Valor retornado

A cor de fundo anterior se for bem sucedida; caso contrário, CLR_NONE.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CImageList#20](../../mfc/reference/codesnippet/cpp/cimagelist-class_20.cpp)]

## <a name="cimagelistsetdragcursorimage"></a><a name="setdragcursorimage"></a>CImageList::SetDragCursorImage

Cria uma nova imagem de arrasto combinando a imagem dada (tipicamente uma imagem do cursor do mouse) com a imagem de arrasto atual.

```
BOOL SetDragCursorImage(
    int nDrag,
    CPoint ptHotSpot);
```

### <a name="parameters"></a>Parâmetros

*nDrag*<br/>
Índice da nova imagem a ser combinada com a imagem de arrasto.

*ptHotSpot*<br/>
Posição do ponto quente dentro da nova imagem.

### <a name="return-value"></a>Valor retornado

Não zero se bem sucedido; caso contrário, 0.

### <a name="remarks"></a>Comentários

Como as funções de arrasto usam a nova imagem durante uma operação de arrastar, você `CImageList::SetDragCursorImage`deve usar a função Windows [ShowCursor](/windows/win32/api/winuser/nf-winuser-showcursor) para ocultar o cursor do mouse real depois de chamar . Caso contrário, o sistema pode parecer ter dois cursores de mouse durante a operação de arrasto.

## <a name="cimagelistsetimagecount"></a><a name="setimagecount"></a>CImageList::SetImageCount

Ligue para esta função de membro para `CImageList` redefinir o número de imagens em um objeto.

```
BOOL SetImageCount(UINT uNewCount);
```

### <a name="parameters"></a>Parâmetros

*uNewCount*<br/>
O valor especificando o novo número total de imagens na lista de imagens.

### <a name="return-value"></a>Valor retornado

Não zero se bem sucedido; caso contrário, zero.

### <a name="remarks"></a>Comentários

Se você chamar essa função de membro para aumentar o número de imagens na lista de imagens, então chame [Substituir](#replace) para cada imagem adicional para atribuir os novos índices a imagens válidas. Se você não atribuir os índices a imagens válidas, as operações de desenho que criam as novas imagens serão imprevisíveis.

Se você diminuir o tamanho de uma lista de imagens usando esta função, as imagens truncadas serão liberadas.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CImageList#21](../../mfc/reference/codesnippet/cpp/cimagelist-class_21.cpp)]

## <a name="cimagelistsetoverlayimage"></a><a name="setoverlayimage"></a>CImageList::SetOverlayImage

Chame esta função para adicionar o índice baseado em zero de uma imagem à lista de imagens a serem usadas como máscaras de sobreposição.

```
BOOL SetOverlayImage(
    int nImage,
    int nOverlay);
```

### <a name="parameters"></a>Parâmetros

*Nimage*<br/>
Índice baseado em zero da imagem para usar como máscara de sobreposição.

*nOverlay*<br/>
Índice baseado em uma da máscara de sobreposição.

### <a name="return-value"></a>Valor retornado

Não zero se bem sucedido; caso contrário, 0.

### <a name="remarks"></a>Comentários

Até quatro índices podem ser adicionados à lista.

Uma máscara de sobreposição é uma imagem desenhada de forma transparente sobre outra imagem. Desenhe uma máscara de sobreposição sobre uma imagem usando a função [cimageList::Draw](#draw) membro com o índice único da máscara de sobreposição especificado usando a macro INDEXTOOVERLAYMASK.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CImageList#22](../../mfc/reference/codesnippet/cpp/cimagelist-class_22.cpp)]

## <a name="cimagelistwrite"></a><a name="write"></a>CImageList::Write

Chame esta função para escrever um objeto de lista de imagens para um arquivo.

```
BOOL Write(CArchive* pArchive);
```

### <a name="parameters"></a>Parâmetros

*pArchive*<br/>
Um ponteiro `CArchive` para um objeto no qual a lista de imagens deve ser armazenada.

### <a name="return-value"></a>Valor retornado

Não zero se bem sucedido; caso contrário, 0.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CImageList#17](../../mfc/reference/codesnippet/cpp/cimagelist-class_23.cpp)]

## <a name="see-also"></a>Confira também

[Classe CObject](../../mfc/reference/cobject-class.md)<br/>
[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classe CListCtrl](../../mfc/reference/clistctrl-class.md)<br/>
[Classe CTabCtrl](../../mfc/reference/ctabctrl-class.md)
