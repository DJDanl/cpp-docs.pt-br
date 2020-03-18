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
ms.openlocfilehash: 1555209ce0f1c2caacbfb4b01107775db948d230
ms.sourcegitcommit: 7ecd91d8ce18088a956917cdaf3a3565bd128510
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/16/2020
ms.locfileid: "79420354"
---
# <a name="cimagelist-class"></a>Classe CImageList

Fornece a funcionalidade do controle de lista de imagens comuns do Windows.

## <a name="syntax"></a>Sintaxe

```
class CImageList : public CObject
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|DESCRIÇÃO|
|----------|-----------------|
|[CImageList::CImageList](#cimagelist)|Constrói um objeto `CImageList`.|

### <a name="public-methods"></a>Métodos públicos

|Nome|DESCRIÇÃO|
|----------|-----------------|
|[CImageList:: Adicionar](#add)|Adiciona uma imagem ou imagens a uma lista de imagens.|
|[CImageList:: Attach](#attach)|Anexa uma lista de imagens a um objeto `CImageList`.|
|[CImageList::BeginDrag](#begindrag)|Começa a arrastar uma imagem.|
|[CImageList:: copiar](#copy)|Copia uma imagem dentro de um objeto `CImageList`.|
|[CImageList:: criar](#create)|Inicializa uma lista de imagens e a anexa a um objeto `CImageList`.|
|[CImageList::D eleteImageList](#deleteimagelist)|Exclui uma lista de imagens.|
|[CImageList::D eleteTempMap](#deletetempmap)|Chamado pelo manipulador de tempo ocioso [CWinApp](../../mfc/reference/cwinapp-class.md) para excluir qualquer objeto de `CImageList` temporário criado por `FromHandle`.|
|[CImageList::D Etach](#detach)|Desanexa um objeto de lista de imagens de um objeto `CImageList` e retorna um identificador para uma lista de imagens.|
|[CImageList::D ragEnter](#dragenter)|Bloqueia atualizações durante uma operação de arrastar e exibe a imagem de arrastar em uma posição especificada.|
|[CImageList::D ragLeave](#dragleave)|Desbloqueia a janela e oculta a imagem de arrastar para que a janela possa ser atualizada.|
|[CImageList::D ragMove](#dragmove)|Move a imagem que está sendo arrastada durante uma operação de arrastar e soltar.|
|[CImageList::D ragShowNolock](#dragshownolock)|Mostra ou oculta a imagem de arrastar durante uma operação de arrastar, sem bloquear a janela.|
|[CImageList::D bruto](#draw)|Desenha a imagem que está sendo arrastada durante uma operação de arrastar e soltar.|
|[CImageList::D rawEx](#drawex)|Desenha um item de lista de imagens no contexto de dispositivo especificado. A função usa o estilo de desenho especificado e mistura a imagem com a cor especificada.|
|[CImageList::D rawIndirect](#drawindirect)|Desenha uma imagem de uma lista de imagens.|
|[CImageList:: endarrastar](#enddrag)|Finaliza uma operação de arrastar.|
|[CImageList::ExtractIcon](#extracticon)|Cria um ícone com base em uma imagem e uma máscara em uma lista de imagens.|
|[CImageList:: FromHandle](#fromhandle)|Retorna um ponteiro para um objeto `CImageList` quando um identificador para uma lista de imagens é fornecido. Se um objeto `CImageList` não estiver anexado ao identificador, um objeto de `CImageList` temporário será criado e anexado.|
|[CImageList::FromHandlePermanent](#fromhandlepermanent)|Retorna um ponteiro para um objeto `CImageList` quando um identificador para uma lista de imagens é fornecido. Se um objeto `CImageList` não estiver anexado ao identificador, NULL será retornado.|
|[CImageList::GetBkColor](#getbkcolor)|Recupera a cor do plano de fundo atual de uma lista de imagens.|
|[CImageList::GetDragImage](#getdragimage)|Obtém a lista de imagens temporárias usada para arrastar.|
|[CImageList::GetImageCount](#getimagecount)|Recupera o número de imagens em uma lista de imagens.|
|[CImageList::GetImageInfo](#getimageinfo)|Recupera informações sobre uma imagem.|
|[CImageList:: GetSafeHandle](#getsafehandle)|Recupera `m_hImageList`.|
|[CImageList:: ler](#read)|Lê uma lista de imagens de um arquivo morto.|
|[CImageList:: Remove](#remove)|Remove uma imagem de uma lista de imagens.|
|[CImageList:: Replace](#replace)|Substitui uma imagem em uma lista de imagens por uma nova imagem.|
|[CImageList::SetBkColor](#setbkcolor)|Define a cor do plano de fundo para uma lista de imagens.|
|[CImageList::SetDragCursorImage](#setdragcursorimage)|Cria uma nova imagem de arrastar.|
|[CImageList::SetImageCount](#setimagecount)|Redefine a contagem de imagens em uma lista de imagens.|
|[CImageList::SetOverlayImage](#setoverlayimage)|Adiciona o índice de base zero de uma imagem à lista de imagens a serem usadas como máscaras de sobreposição.|
|[CImageList:: Write](#write)|Grava uma lista de imagens em um arquivo morto.|

### <a name="public-operators"></a>Operadores públicos

|Nome|DESCRIÇÃO|
|----------|-----------------|
|[Operador CImageList:: Operator HIMAGELIST](#operator_himagelist)|Retorna o HIMAGELIST anexado ao `CImageList`.|

### <a name="public-data-members"></a>Membros de Dados Públicos

|Nome|DESCRIÇÃO|
|----------|-----------------|
|[CImageList:: m_hImageList](#m_himagelist)|Um identificador que contém a lista de imagens anexada a este objeto.|

## <a name="remarks"></a>Comentários

Uma "lista de imagens" é uma coleção de imagens de mesmo tamanho, cada uma das quais pode ser referenciada por seu índice de base zero. As listas de imagens são usadas para gerenciar com eficiência grandes conjuntos de ícones ou bitmaps. Todas as imagens em uma lista de imagens estão contidas em um único bitmap largo no formato de dispositivo de tela. Uma lista de imagens também pode incluir um bitmap monocromático que contém máscaras usadas para desenhar imagens de forma transparente (estilo de ícone). A API (interface de programação de aplicativo) do Microsoft Win32 fornece funções de lista de imagens que permitem desenhar imagens, criar e destruir listas de imagens, adicionar e remover imagens, substituir imagens, mesclar imagens e arrastar imagens.

Esse controle (e, portanto, a classe `CImageList`) está disponível somente para programas em execução no Windows 95/98 e no Windows NT versão 3,51 e posterior.

Para obter mais informações sobre como usar `CImageList`, consulte [controles](../../mfc/controls-mfc.md) e [usando CImageList](../../mfc/using-cimagelist.md).

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[CObject](../../mfc/reference/cobject-class.md)

`CImageList`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxcmn. h

##  <a name="add"></a>CImageList:: Adicionar

Chame essa função para adicionar uma ou mais imagens ou um ícone a uma lista de imagens.

```
int Add(
    CBitmap* pbmImage,
    CBitmap* pbmMask);

int Add(
    CBitmap* pbmImage,
    COLORREF crMask);

int Add(HICON hIcon);
```

### <a name="parameters"></a>parâmetros

*pbmImage*<br/>
Ponteiro para o bitmap que contém a imagem ou imagens. O número de imagens é inferido da largura do bitmap.

*pbmMask*<br/>
Ponteiro para o bitmap que contém a máscara. Se nenhuma máscara for usada com a lista de imagens, esse parâmetro será ignorado.

*crMask*<br/>
Cor usada para gerar a máscara. Cada pixel dessa cor no bitmap fornecido é alterado para preto e o bit correspondente na máscara é definido como um.

*hIcon*<br/>
Identificador do ícone que contém o bitmap e a máscara da nova imagem.

### <a name="return-value"></a>Valor retornado

O índice de base zero da primeira nova imagem se for bem-sucedido; caso contrário,-1.

### <a name="remarks"></a>Comentários

Você é responsável por liberar a alça de ícone quando terminar.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CImageList#1](../../mfc/reference/codesnippet/cpp/cimagelist-class_1.cpp)]

##  <a name="attach"></a>CImageList:: Attach

Chame essa função para anexar uma lista de imagens a um objeto `CImageList`.

```
BOOL Attach(HIMAGELIST hImageList);
```

### <a name="parameters"></a>parâmetros

*hImageList*<br/>
Um identificador para um objeto de lista de imagens.

### <a name="return-value"></a>Valor retornado

Diferente de zero se o anexo tiver sido bem-sucedido; caso contrário, 0.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CImageList#2](../../mfc/reference/codesnippet/cpp/cimagelist-class_2.cpp)]

##  <a name="begindrag"></a>CImageList::BeginDrag

Chame essa função para começar a arrastar uma imagem.

```
BOOL BeginDrag(
    int nImage,
    CPoint ptHotSpot);
```

### <a name="parameters"></a>parâmetros

*Nimagem*<br/>
Índice de base zero da imagem a ser arrastado.

*ptHotSpot*<br/>
Coordenadas da posição de arrastar inicial (normalmente, a posição do cursor). As coordenadas são relativas ao canto superior esquerdo da imagem.

### <a name="return-value"></a>Valor retornado

Diferente de zero, se for bem-sucedido; caso contrário, 0.

### <a name="remarks"></a>Comentários

Essa função cria uma lista de imagens temporárias que é usada para arrastar. A imagem combina a imagem especificada e sua máscara com o cursor atual. Em resposta às mensagens de WM_MOUSEMOVE subsequentes, você pode mover a imagem de arrastar usando a função de membro `DragMove`. Para finalizar a operação de arrastar, você pode usar a função de membro `EndDrag`.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CImageList#3](../../mfc/reference/codesnippet/cpp/cimagelist-class_3.cpp)]

##  <a name="cimagelist"></a>CImageList::CImageList

Constrói um objeto `CImageList`.

```
CImageList();
```

##  <a name="copy"></a>CImageList:: copiar

Essa função de membro implementa o comportamento da função Win32 [ImageList_Copy](/windows/win32/api/commctrl/nf-commctrl-imagelist_copy), conforme descrito no SDK do Windows.

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

### <a name="parameters"></a>parâmetros

*iDst*<br/>
O índice de base zero da imagem a ser usada como o destino da operação de cópia.

*iSrc*<br/>
O índice de base zero da imagem a ser usada como a origem da operação de cópia.

*uFlags*<br/>
O valor do sinalizador de bits que especifica o tipo de operação de cópia a ser feita. Esse parâmetro pode ser um dos seguintes valores:

|Valor|Significado|
|-----------|-------------|
|ILCF_MOVE|A imagem de origem é copiada para o índice da imagem de destino. Essa operação resulta em várias instâncias de uma determinada imagem. ILCF_MOVE é o padrão.|
|ILCF_SWAP|As imagens de origem e de destino trocam posições na lista de imagens.|

*pSrc*<br/>
Um ponteiro para um objeto `CImageList` que é o destino da operação de cópia.

### <a name="return-value"></a>Valor retornado

Diferente de zero, se for bem-sucedido; caso contrário, zero.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CImageList#6](../../mfc/reference/codesnippet/cpp/cimagelist-class_4.cpp)]

##  <a name="create"></a>CImageList:: criar

Inicializa uma lista de imagens e a anexa a um objeto [CImageList](../../mfc/reference/cimagelist-class.md) .

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

### <a name="parameters"></a>parâmetros

*CX*<br/>
Dimensões de cada imagem, em pixels.

*Cy*<br/>
Dimensões de cada imagem, em pixels.

*nFlags*<br/>
Especifica o tipo de lista de imagens a ser criado. Esse parâmetro pode ser uma combinação dos valores a seguir, mas pode incluir apenas um dos valores de `ILC_COLOR`.

|Valor|Significado|
|-----------|-------------|
|ILC_COLOR|Use o comportamento padrão se nenhum dos outros sinalizadores ILC_COLOR * for especificado. Normalmente, o padrão é ILC_COLOR4; Mas, para drivers de exibição mais antigos, o padrão é ILC_COLORDDB.|
|ILC_COLOR4|Use uma seção de DIB (bitmap independente de dispositivo) de 4 bits (16 cores) como bitmap para a lista de imagens.|
|ILC_COLOR8|Use uma seção DIB de 8 bits. As cores usadas para a tabela de cores são as mesmas cores da paleta de meio-tom.|
|ILC_COLOR16|Use uma seção DIB de 16 bits (cor de 32/64k).|
|ILC_COLOR24|Use uma seção DIB de 24 bits.|
|ILC_COLOR32|Use uma seção DIB de 32 bits.|
|ILC_COLORDDB|Use um bitmap dependente de dispositivo.|
|ILC_MASK|Usa uma máscara. A lista de imagens contém dois bitmaps, um dos quais é um bitmap monocromático usado como uma máscara. Se esse valor não for incluído, a lista de imagens conterá apenas um bitmap. Consulte [desenho de imagens de uma lista](../../mfc/drawing-images-from-an-image-list.md) de imagens para obter informações adicionais sobre imagens mascaradas.|

*nInitial*<br/>
Número de imagens que a lista de imagens contém inicialmente.

*nGrow*<br/>
Número de imagens pelas quais a lista de imagens pode aumentar quando o sistema precisa redimensionar a lista para liberar espaço para novas imagens. Esse parâmetro representa o número de novas imagens que a lista de imagens redimensionada pode conter.

*nBitmapID*<br/>
IDs de recurso do bitmap a ser associado à lista de imagens.

*crMask*<br/>
Cor usada para gerar uma máscara. Cada pixel dessa cor no bitmap especificado é alterado para preto e o bit correspondente na máscara é definido como um.

*lpszBitmapID*<br/>
Uma cadeia de caracteres que contém as IDs de recurso das imagens.

*imagelist1*<br/>
Uma referência a um objeto `CImageList`.

*nImage1*<br/>
Índice da primeira imagem existente.

*imagelist2*<br/>
Uma referência a um objeto `CImageList`.

*nImage2*<br/>
Índice da segunda imagem existente.

*DX*<br/>
Deslocamento do eixo x da segunda imagem em relação à primeira imagem, em pixels.

*DY*<br/>
Deslocamento do eixo y da segunda imagem em relação à primeira imagem, em pixels.

*pImageList*<br/>
Um ponteiro para um objeto `CImageList`.

### <a name="return-value"></a>Valor retornado

Diferente de zero, se for bem-sucedido; caso contrário, 0.

### <a name="remarks"></a>Comentários

Você constrói uma `CImageList` em duas etapas. Primeiro, chame o construtor e, em seguida, chame `Create`, que cria a lista de imagens e a anexa ao objeto `CImageList`.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CImageList#7](../../mfc/reference/codesnippet/cpp/cimagelist-class_5.cpp)]

##  <a name="deleteimagelist"></a>CImageList::D eleteImageList

Chame essa função para excluir uma lista de imagens.

```
BOOL DeleteImageList();
```

### <a name="return-value"></a>Valor retornado

Diferente de zero, se for bem-sucedido; caso contrário, 0.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CImageList#8](../../mfc/reference/codesnippet/cpp/cimagelist-class_6.cpp)]

##  <a name="deletetempmap"></a>CImageList::D eleteTempMap

Chamado automaticamente pelo manipulador `CWinApp` tempo ocioso, `DeleteTempMap` exclui quaisquer objetos `CImageList` temporários criados pelo [FromHandle](#fromhandle), mas não destrói quaisquer identificadores (`hImageList`) temporariamente associados aos objetos `ImageList`.

```
static void PASCAL DeleteTempMap();
```

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CImageList#9](../../mfc/reference/codesnippet/cpp/cimagelist-class_7.cpp)]

##  <a name="detach"></a>CImageList::D Etach

Chame essa função para desanexar um objeto de lista de imagens de um objeto `CImageList`.

```
HIMAGELIST Detach();
```

### <a name="return-value"></a>Valor retornado

Um identificador para um objeto de lista de imagens.

### <a name="remarks"></a>Comentários

Essa função retorna um identificador para o objeto de lista de imagens.

### <a name="example"></a>Exemplo

  Consulte o exemplo de [CImageList:: Attach](#attach).

##  <a name="dragenter"></a>CImageList::D ragEnter

Durante uma operação de arrastar, o bloqueia as atualizações na janela especificada por *pWndLock* e exibe a imagem de arrastar na posição especificada por *ponto*.

```
static BOOL PASCAL DragEnter(
    CWnd* pWndLock,
    CPoint point);
```

### <a name="parameters"></a>parâmetros

*pWndLock*<br/>
Ponteiro para a janela que possui a imagem de arrastar.

*empresas*<br/>
Posição na qual exibir a imagem de arrastar. As coordenadas são relativas ao canto superior esquerdo da janela (não na área do cliente).

### <a name="return-value"></a>Valor retornado

Diferente de zero, se for bem-sucedido; caso contrário, 0.

### <a name="remarks"></a>Comentários

As coordenadas são relativas ao canto superior esquerdo da janela, portanto, você deve compensar as larguras dos elementos da janela, como a borda, a barra de título e a barra de menus, ao especificar as coordenadas.

Se *pWndLock* for NULL, essa função desenhará a imagem no contexto de exibição associado à janela da área de trabalho e as coordenadas serão relativas ao canto superior esquerdo da tela.

Essa função bloqueia todas as outras atualizações na janela especificada durante a operação de arrastar. Se você precisar fazer qualquer desenho durante uma operação de arrastar, como realçar o destino de uma operação de arrastar e soltar, você poderá ocultar temporariamente a imagem arrastada usando a função [CImageList::D ragleave](#dragleave) .

### <a name="example"></a>Exemplo

  Consulte o exemplo de [CImageList:: BeginDrag](#begindrag).

##  <a name="dragleave"></a>CImageList::D ragLeave

Desbloqueia a janela especificada por *pWndLock* e oculta a imagem de arrastar, permitindo que a janela seja atualizada.

```
static BOOL PASCAL DragLeave(CWnd* pWndLock);
```

### <a name="parameters"></a>parâmetros

*pWndLock*<br/>
Ponteiro para a janela que possui a imagem de arrastar.

### <a name="return-value"></a>Valor retornado

Diferente de zero, se for bem-sucedido; caso contrário, 0.

### <a name="example"></a>Exemplo

  Consulte o exemplo de [CImageList:: endarraste](#enddrag).

##  <a name="dragmove"></a>CImageList::D ragMove

Chame essa função para mover a imagem que está sendo arrastada durante uma operação de arrastar e soltar.

```
static BOOL PASCAL DragMove(CPoint pt);
```

### <a name="parameters"></a>parâmetros

*pt*<br/>
Nova posição de arrastar.

### <a name="return-value"></a>Valor retornado

Diferente de zero, se for bem-sucedido; caso contrário, 0.

### <a name="remarks"></a>Comentários

Normalmente, essa função é chamada em resposta a uma mensagem WM_MOUSEMOVE. Para iniciar uma operação de arrastar, use a função de membro `BeginDrag`.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CImageList#4](../../mfc/reference/codesnippet/cpp/cimagelist-class_8.cpp)]

##  <a name="dragshownolock"></a>CImageList::D ragShowNolock

Mostra ou oculta a imagem de arrastar durante uma operação de arrastar, sem bloquear a janela.

```
static BOOL PASCAL DragShowNolock(BOOL bShow);
```

### <a name="parameters"></a>parâmetros

*bShow*<br/>
Especifica se a imagem de arrastar deve ser mostrada.

### <a name="return-value"></a>Valor retornado

Diferente de zero, se for bem-sucedido; caso contrário, 0.

### <a name="remarks"></a>Comentários

A função [CImageList::D ragenter](#dragenter) bloqueia todas as atualizações na janela durante uma operação de arrastar. No entanto, essa função não bloqueia a janela.

##  <a name="draw"></a>CImageList::D bruto

Chame essa função para desenhar a imagem que está sendo arrastada durante uma operação de arrastar e soltar.

```
BOOL Draw(
    CDC* pDC,
    int nImage,
    POINT pt,
    UINT nStyle);
```

### <a name="parameters"></a>parâmetros

*pDC*<br/>
Ponteiro para o contexto do dispositivo de destino.

*Nimagem*<br/>
Índice de base zero da imagem a ser desenhada.

*pt*<br/>
Local no qual desenhar dentro do contexto do dispositivo especificado.

*nStyle*<br/>
Sinalizador que especifica o estilo de desenho. Pode ser um ou mais destes valores:

|Valor|Significado|
|-----------|-------------|
|ILD_BLEND25, ILD_FOCUS|Desenha a imagem, combinando 25 por cento com a cor de realce do sistema. Esse valor não tem efeito se a lista de imagens não contiver uma máscara.|
|ILD_BLEND50, ILD_SELECTED, ILD_BLEND|Desenha a imagem, combinando 50 por cento com a cor de realce do sistema. Esse valor não tem efeito se a lista de imagens não contiver uma máscara.|
|ILD_MASK|Desenha a máscara.|
|ILD_NORMAL|Desenha a imagem usando a cor do plano de fundo da lista de imagens. Se a cor do plano de fundo for o valor CLR_NONE, a imagem será desenhada de forma transparente usando a máscara.|
|ILD_TRANSPARENT|Desenha a imagem de forma transparente usando a máscara, independentemente da cor do plano de fundo.|

### <a name="return-value"></a>Valor retornado

Diferente de zero, se for bem-sucedido; caso contrário, 0.

### <a name="example"></a>Exemplo

  Consulte o exemplo de [CImageList:: SetOverlayImage](#setoverlayimage).

##  <a name="drawex"></a>CImageList::D rawEx

Desenha um item de lista de imagens no contexto de dispositivo especificado.

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

### <a name="parameters"></a>parâmetros

*pDC*<br/>
Ponteiro para o contexto do dispositivo de destino.

*Nimagem*<br/>
Índice de base zero da imagem a ser desenhada.

*pt*<br/>
Local no qual desenhar dentro do contexto do dispositivo especificado.

*sz*<br/>
Tamanho da parte da imagem a ser redesenhada em relação ao canto superior esquerdo da imagem. Consulte *DX* e *DY* em [ImageList_DrawEx](/windows/win32/api/commctrl/nf-commctrl-imagelist_drawex) na SDK do Windows.

*clrBk*<br/>
Cor do plano de fundo da imagem. Consulte *rgbBk* em [ImageList_DrawEx](/windows/win32/api/commctrl/nf-commctrl-imagelist_drawex) na SDK do Windows.

*clrFg*<br/>
Cor do primeiro plano da imagem. Consulte *rgbFg* em [ImageList_DrawEx](/windows/win32/api/commctrl/nf-commctrl-imagelist_drawex) na SDK do Windows.

*nStyle*<br/>
Sinalizador que especifica o estilo de desenho. Consulte *fStyle* em [ImageList_DrawEx](/windows/win32/api/commctrl/nf-commctrl-imagelist_drawex) na SDK do Windows.

### <a name="return-value"></a>Valor retornado

Diferente de zero, se for bem-sucedido; caso contrário, 0.

### <a name="remarks"></a>Comentários

A função usa o estilo de desenho especificado e mistura a imagem com a cor especificada.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CImageList#10](../../mfc/reference/codesnippet/cpp/cimagelist-class_9.cpp)]

##  <a name="drawindirect"></a>CImageList::D rawIndirect

Chame essa função de membro para desenhar uma imagem de uma lista de imagens.

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

### <a name="parameters"></a>parâmetros

*pimldp*<br/>
Um ponteiro para uma estrutura [IMAGELISTDRAWPARAMS](/windows/win32/api/commctrl/ns-commctrl-imagelistdrawparams) que contém informações sobre a operação de desenho.

*pDC*<br/>
Um ponteiro para o contexto do dispositivo de destino. Você deve excluir esse objeto [CDC](../../mfc/reference/cdc-class.md) quando terminar.

*Nimagem*<br/>
O índice de base zero da imagem a ser desenhada.

*pt*<br/>
Uma estrutura de [ponto](/previous-versions/dd162805\(v=vs.85\)) que contém as coordenadas x e y em que a imagem será desenhada.

*sz*<br/>
Uma estrutura de [tamanho](/windows/win32/api/windef/ns-windef-size) que indica o tamanho da imagem a ser desenhada.

*ptOrigin*<br/>
Uma estrutura de [ponto](/previous-versions/dd162805\(v=vs.85\)) que contém as coordenadas x e y especificando o canto superior esquerdo da operação de desenho em relação à própria imagem. Os pixels da imagem que estão à esquerda da coordenada x e acima da coordenada y não são desenhados.

*fStyle*<br/>
Sinalizador que especifica o estilo de desenho e, opcionalmente, a imagem de sobreposição. Consulte a seção comentários para obter informações sobre a imagem sobreposta. A implementação padrão do MFC, ILD_NORMAL, desenha a imagem usando a cor do plano de fundo da lista de imagens. Se a cor do plano de fundo for o valor CLR_NONE, a imagem será desenhada de forma transparente usando uma máscara.

Outros estilos possíveis são descritos no membro *fStyle* da estrutura [IMAGELISTDRAWPARAMS](/windows/win32/api/commctrl/ns-commctrl-imagelistdrawparams) .

*dwRop*<br/>
Valor que especifica um código de operação de varredura. Esses códigos definem como os dados de cor para o retângulo de origem serão combinados com os dados de cor do retângulo de destino para obter a cor final. A implementação padrão do MFC, SRCCOPY, copia o retângulo de origem diretamente para o retângulo de destino. Esse parâmetro será ignorado se o parâmetro *fStyle* não incluir o sinalizador ILD_ROP.

Outros valores possíveis são descritos sob o membro *dwRop* da estrutura [IMAGELISTDRAWPARAMS](/windows/win32/api/commctrl/ns-commctrl-imagelistdrawparams) .

*rgbBack*<br/>
A cor do plano de fundo da imagem, por padrão CLR_DEFAULT. Esse parâmetro pode ser um valor RGB definido pelo aplicativo ou um dos seguintes valores:

|Valor|Significado|
|-----------|-------------|
|CLR_DEFAULT|Cor do plano de fundo padrão. A imagem é desenhada usando a cor do plano de fundo da lista de imagens.|
|CLR_NONE|Nenhuma cor do plano de fundo. A imagem é desenhada de forma transparente.|

*rgbFore*<br/>
Cor do primeiro plano da imagem, por padrão CLR_DEFAULT. Esse parâmetro pode ser um valor RGB definido pelo aplicativo ou um dos seguintes valores:

|Valor|Significado|
|-----------|-------------|
|CLR_DEFAULT|Cor de primeiro plano padrão. A imagem é desenhada usando a cor de realce do sistema como a cor de primeiro plano.|
|CLR_NONE|Sem cor de mistura. A imagem é mesclada com a cor do contexto do dispositivo de destino.|

Esse parâmetro será usado somente se *fStyle* incluir o sinalizador ILD_BLEND25 ou ILD_BLEND50.

*fState*<br/>
Sinalizador que especifica o estado do desenho. Este membro pode conter um ou mais sinalizadores de estado da lista de imagens.

*Quadro*<br/>
Afeta o comportamento dos efeitos de saturação e de mistura de alfa.

Quando usado com ILS_SATURATE, esse membro contém o valor que é adicionado a cada componente de cor do terceto RGB para cada pixel no ícone.

Quando usado com ILS_APLHA, esse membro contém o valor para o canal alfa. Esse valor pode ser de 0 a 255, sendo que 0 é completamente transparente e 255 sendo completamente opaco.

*crEffect*<br/>
Um valor de [COLORREF](/windows/win32/gdi/colorref) usado para efeitos de brilho e sombra.

### <a name="return-value"></a>Valor retornado

TRUE se a imagem for desenhada com êxito; caso contrário, FALSE.

### <a name="remarks"></a>Comentários

Use a primeira versão se desejar preencher a estrutura do Win32 por conta própria. Use a segunda versão se desejar aproveitar um ou mais argumentos padrão do MFC ou Evite gerenciar a estrutura.

Uma imagem de sobreposição é uma imagem que é desenhada na parte superior da imagem primária, especificada nessa função de membro pelo parâmetro *nimagem* . Desenhe uma máscara de sobreposição usando a função de membro [draw](#draw) com o índice baseado em um da máscara de sobreposição especificada usando a macro [INDEXTOOVERLAYMASK](/windows/win32/api/commctrl/nf-commctrl-indextooverlaymask) .

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CImageList#11](../../mfc/reference/codesnippet/cpp/cimagelist-class_10.cpp)]

##  <a name="enddrag"></a>CImageList:: endarrastar

Chame essa função para finalizar uma operação de arrastar.

```
static void PASCAL EndDrag();
```

### <a name="remarks"></a>Comentários

Para iniciar uma operação de arrastar, use a função de membro `BeginDrag`.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CImageList#5](../../mfc/reference/codesnippet/cpp/cimagelist-class_11.cpp)]

##  <a name="extracticon"></a>CImageList::ExtractIcon

Chame essa função para criar um ícone com base em uma imagem e sua máscara relacionada em uma lista de imagens.

```
HICON ExtractIcon(int nImage);
```

### <a name="parameters"></a>parâmetros

*Nimagem*<br/>
Índice de base zero da imagem.

### <a name="return-value"></a>Valor retornado

Identificador do ícone se for bem-sucedido; caso contrário, NULL.

### <a name="remarks"></a>Comentários

Esse método depende do comportamento da macro [ImageList_ExtractIcon](/windows/win32/api/commctrl/nf-commctrl-imagelist_extracticon) para criar o ícone. Consulte a macro [ImageList_ExtractIcon](/windows/win32/api/commctrl/nf-commctrl-imagelist_extracticon) para obter mais informações sobre a criação e a limpeza de ícones.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CImageList#12](../../mfc/reference/codesnippet/cpp/cimagelist-class_12.cpp)]

##  <a name="fromhandle"></a>CImageList:: FromHandle

Retorna um ponteiro para um objeto `CImageList` quando um identificador para uma lista de imagens é fornecido.

```
static CImageList* PASCAL FromHandle(HIMAGELIST hImageList);
```

### <a name="parameters"></a>parâmetros

*hImageList*<br/>
Especifica a lista de imagens.

### <a name="return-value"></a>Valor retornado

Um ponteiro para um objeto `CImageList` se for bem-sucedido; caso contrário, NULL.

### <a name="remarks"></a>Comentários

Se um `CImageList` ainda não estiver anexado ao identificador, um objeto de `CImageList` temporário será criado e anexado. Esse objeto de `CImageList` temporário é válido somente até a próxima vez que o aplicativo tiver tempo ocioso em seu loop de eventos, quando todos os objetos temporários forem excluídos.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CImageList#13](../../mfc/reference/codesnippet/cpp/cimagelist-class_13.cpp)]

##  <a name="fromhandlepermanent"></a>CImageList::FromHandlePermanent

Retorna um ponteiro para um objeto `CImageList` quando um identificador para uma lista de imagens é fornecido.

```
static CImageList* PASCAL FromHandlePermanent(HIMAGELIST hImageList);
```

### <a name="parameters"></a>parâmetros

*hImageList*<br/>
Especifica a lista de imagens.

### <a name="return-value"></a>Valor retornado

Um ponteiro para um objeto `CImageList` se for bem-sucedido; caso contrário, NULL.

### <a name="remarks"></a>Comentários

Se um objeto `CImageList` não estiver anexado ao identificador, NULL será retornado.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CImageList#14](../../mfc/reference/codesnippet/cpp/cimagelist-class_14.cpp)]

##  <a name="getbkcolor"></a>CImageList::GetBkColor

Chame essa função para recuperar a cor de plano de fundo atual de uma lista de imagens.

```
COLORREF GetBkColor() const;
```

### <a name="return-value"></a>Valor retornado

O valor de cor RGB da cor do plano de fundo do objeto de `CImageList`.

### <a name="example"></a>Exemplo

  Consulte o exemplo de [CImageList:: SetBkColor](#setbkcolor).

##  <a name="getdragimage"></a>CImageList::GetDragImage

Obtém a lista de imagens temporárias usada para arrastar.

```
static CImageList* PASCAL GetDragImage(
    LPPOINT lpPoint,
    LPPOINT lpPointHotSpot);
```

### <a name="parameters"></a>parâmetros

*lpPoint*<br/>
Endereço de uma estrutura de [ponto](/previous-versions/dd162805\(v=vs.85\)) que recebe a posição de arrastar atual.

*lpPointHotSpot*<br/>
Endereço de uma estrutura de `POINT` que recebe o deslocamento da imagem de arrastar em relação à posição de arrastar.

### <a name="return-value"></a>Valor retornado

Se for bem-sucedido, um ponteiro para a lista de imagens temporárias é usado para arrastar; caso contrário, NULL.

##  <a name="getimagecount"></a>CImageList::GetImageCount

Chame essa função para recuperar o número de imagens em uma lista de imagens.

```
int GetImageCount() const;
```

### <a name="return-value"></a>Valor retornado

O número de imagens.

### <a name="example"></a>Exemplo

  Consulte o exemplo de [CImageList:: ExtractIcon](#extracticon).

##  <a name="getimageinfo"></a>CImageList::GetImageInfo

Chame essa função para recuperar informações sobre uma imagem.

```
BOOL GetImageInfo(
    int nImage,
    IMAGEINFO* pImageInfo) const;
```

### <a name="parameters"></a>parâmetros

*Nimagem*<br/>
Índice de base zero da imagem.

*pImageInfo*<br/>
Ponteiro para uma estrutura [IMAGEINFO](/windows/win32/api/commctrl/ns-commctrl-imageinfo) que recebe informações sobre a imagem. As informações contidas nessa estrutura podem ser usadas para manipular diretamente os bitmaps da imagem.

### <a name="return-value"></a>Valor retornado

Diferente de zero, se for bem-sucedido; caso contrário, 0.

### <a name="remarks"></a>Comentários

A estrutura de `IMAGEINFO` contém informações sobre uma imagem em uma lista de imagens.

##  <a name="getsafehandle"></a>CImageList:: GetSafeHandle

Chame essa função para recuperar o membro de dados de `m_hImageList`.

```
HIMAGELIST GetSafeHandle() const;
```

### <a name="return-value"></a>Valor retornado

Um identificador para a lista de imagens anexadas; caso contrário, NULL se nenhum objeto estiver anexado.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CImageList#15](../../mfc/reference/codesnippet/cpp/cimagelist-class_15.cpp)]

##  <a name="m_himagelist"></a>CImageList:: m_hImageList

Um identificador da lista de imagens anexada a este objeto.

`HIMAGELIST m_hImageList;`

### <a name="remarks"></a>Comentários

O membro de dados `m_hImageList` é uma variável pública do tipo HIMAGELIST.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CImageList#23](../../mfc/reference/codesnippet/cpp/cimagelist-class_16.cpp)]

##  <a name="operator_himagelist"></a>Operador CImageList:: Operator HIMAGELIST

Use esse operador para obter o identificador anexado do objeto `CImageList`.

```
operator HIMAGELIST() const;
```

### <a name="return-value"></a>Valor retornado

Se for bem-sucedido, um identificador para a lista de imagens representado pelo objeto `CImageList`; caso contrário, NULL.

### <a name="remarks"></a>Comentários

Esse operador é um operador de conversão, que dá suporte ao uso direto de um objeto HIMAGELIST.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CImageList#16](../../mfc/reference/codesnippet/cpp/cimagelist-class_17.cpp)]

##  <a name="read"></a>CImageList:: ler

Chame essa função para ler uma lista de imagens de um arquivo morto.

```
BOOL Read(CArchive* pArchive);
```

### <a name="parameters"></a>parâmetros

*pArchive*<br/>
Um ponteiro para um objeto `CArchive` do qual a lista de imagens deve ser lida.

### <a name="return-value"></a>Valor retornado

Diferente de zero, se for bem-sucedido; caso contrário, 0.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CImageList#18](../../mfc/reference/codesnippet/cpp/cimagelist-class_18.cpp)]

##  <a name="remove"></a>CImageList:: Remove

Chame essa função para remover uma imagem de um objeto de lista de imagens.

```
BOOL Remove(int nImage);
```

### <a name="parameters"></a>parâmetros

*Nimagem*<br/>
Índice de base zero da imagem a ser removida.

### <a name="return-value"></a>Valor retornado

Diferente de zero, se for bem-sucedido; caso contrário, 0.

### <a name="remarks"></a>Comentários

Todos os itens após *nimagem* agora se movem uma posição para baixo. Por exemplo, se uma lista de imagens contiver dois itens, a exclusão do primeiro item fará com que o item restante esteja agora na primeira posição. *nimagem*= 0 para o item na primeira posição.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CImageList#19](../../mfc/reference/codesnippet/cpp/cimagelist-class_19.cpp)]

##  <a name="replace"></a>CImageList:: Replace

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

### <a name="parameters"></a>parâmetros

*Nimagem*<br/>
Índice de base zero da imagem a ser substituída.

*pbmImage*<br/>
Um ponteiro para o bitmap que contém a imagem.

*pbmMask*<br/>
Um ponteiro para o bitmap que contém a máscara. Se nenhuma máscara for usada com a lista de imagens, esse parâmetro será ignorado.

*hIcon*<br/>
Um identificador para o ícone que contém o bitmap e a máscara da nova imagem.

### <a name="return-value"></a>Valor retornado

A versão que retorna BOOL retornará zero se for bem-sucedida; caso contrário, 0.

A versão que retorna **int** retorna o índice de base zero da imagem, se for bem-sucedida; caso contrário,-1.

### <a name="remarks"></a>Comentários

Chame essa função de membro depois de chamar [SetImageCount](#setimagecount) para atribuir as imagens novas e válidas aos números de índice de imagem de espaço reservado.

### <a name="example"></a>Exemplo

  Consulte o exemplo de [CImageList:: SetImageCount](#setimagecount).

##  <a name="setbkcolor"></a>CImageList::SetBkColor

Chame essa função para definir a cor do plano de fundo de uma lista de imagens.

```
COLORREF SetBkColor(COLORREF cr);
```

### <a name="parameters"></a>parâmetros

*CD*<br/>
Cor do plano de fundo a ser definida. Pode ser CLR_NONE. Nesse caso, as imagens são desenhadas de forma transparente usando a máscara.

### <a name="return-value"></a>Valor retornado

A cor do plano de fundo anterior se for bem-sucedida; caso contrário CLR_NONE.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CImageList#20](../../mfc/reference/codesnippet/cpp/cimagelist-class_20.cpp)]

##  <a name="setdragcursorimage"></a>CImageList::SetDragCursorImage

Cria uma nova imagem de arrastar combinando a imagem fornecida (normalmente uma imagem de cursor do mouse) com a imagem de arrastar atual.

```
BOOL SetDragCursorImage(
    int nDrag,
    CPoint ptHotSpot);
```

### <a name="parameters"></a>parâmetros

*nDrag*<br/>
Índice da nova imagem a ser combinada com a imagem de arrastar.

*ptHotSpot*<br/>
Posição do ponto de acesso dentro da nova imagem.

### <a name="return-value"></a>Valor retornado

Diferente de zero, se for bem-sucedido; caso contrário, 0.

### <a name="remarks"></a>Comentários

Como as funções de arrastar usam a nova imagem durante uma operação de arrastar, você deve usar a função de [descursor](/windows/win32/api/winuser/nf-winuser-showcursor) do Windows para ocultar o cursor real do mouse depois de chamar `CImageList::SetDragCursorImage`. Caso contrário, o sistema pode parecer ter dois cursores de mouse para a duração da operação de arrastar.

##  <a name="setimagecount"></a>CImageList::SetImageCount

Chame essa função de membro para redefinir o número de imagens em um objeto `CImageList`.

```
BOOL SetImageCount(UINT uNewCount);
```

### <a name="parameters"></a>parâmetros

*uNewCount*<br/>
O valor que especifica o novo número total de imagens na lista de imagens.

### <a name="return-value"></a>Valor retornado

Diferente de zero, se for bem-sucedido; caso contrário, zero.

### <a name="remarks"></a>Comentários

Se você chamar essa função de membro para aumentar o número de imagens na lista de imagens, chame [replace](#replace) para cada imagem adicional para atribuir os novos índices a imagens válidas. Se você não atribuir os índices a imagens válidas, as operações de desenho que criam as novas imagens serão imprevisíveis.

Se você diminuir o tamanho de uma lista de imagens usando essa função, as imagens truncadas serão liberadas.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CImageList#21](../../mfc/reference/codesnippet/cpp/cimagelist-class_21.cpp)]

##  <a name="setoverlayimage"></a>CImageList::SetOverlayImage

Chame essa função para adicionar o índice de base zero de uma imagem à lista de imagens a serem usadas como máscaras de sobreposição.

```
BOOL SetOverlayImage(
    int nImage,
    int nOverlay);
```

### <a name="parameters"></a>parâmetros

*Nimagem*<br/>
Índice de base zero da imagem a ser usado como máscara de sobreposição.

*nOverlay*<br/>
Índice baseado em um da máscara de sobreposição.

### <a name="return-value"></a>Valor retornado

Diferente de zero, se for bem-sucedido; caso contrário, 0.

### <a name="remarks"></a>Comentários

Até quatro índices podem ser adicionados à lista.

Uma máscara de sobreposição é uma imagem desenhada de forma transparente sobre outra imagem. Desenhe uma máscara de sobreposição sobre uma imagem usando a função de membro [CImageList::D RAW](#draw) com o índice baseado em um da máscara de sobreposição especificada usando a macro INDEXTOOVERLAYMASK.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CImageList#22](../../mfc/reference/codesnippet/cpp/cimagelist-class_22.cpp)]

##  <a name="write"></a>CImageList:: Write

Chame essa função para gravar um objeto de lista de imagens em um arquivo morto.

```
BOOL Write(CArchive* pArchive);
```

### <a name="parameters"></a>parâmetros

*pArchive*<br/>
Um ponteiro para um objeto `CArchive` no qual a lista de imagens deve ser armazenada.

### <a name="return-value"></a>Valor retornado

Diferente de zero, se for bem-sucedido; caso contrário, 0.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CImageList#17](../../mfc/reference/codesnippet/cpp/cimagelist-class_23.cpp)]

## <a name="see-also"></a>Confira também

[Classe CObject](../../mfc/reference/cobject-class.md)<br/>
[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classe CListCtrl](../../mfc/reference/clistctrl-class.md)<br/>
[Classe CTabCtrl](../../mfc/reference/ctabctrl-class.md)
