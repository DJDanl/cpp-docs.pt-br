---
title: Classe CImageList | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: reference
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
dev_langs:
- C++
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
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 63e6a7a45fc119309ce99640ab74006ae44a05bf
ms.sourcegitcommit: 6408139d5f5ff8928f056bde93d20eecb3520361
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/02/2018
ms.locfileid: "37339127"
---
# <a name="cimagelist-class"></a>Classe CImageList
Fornece a funcionalidade do controle de lista de imagem comuns do Windows.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class CImageList : public CObject  
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CImageList::CImageList](#cimagelist)|Constrói um objeto `CImageList`.|  
  
### <a name="public-methods"></a>Métodos Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CImageList::Add](#add)|Adiciona uma imagem ou imagens a uma lista de imagens.|  
|[CImageList::Attach](#attach)|Anexa uma lista de imagens para um `CImageList` objeto.|  
|[CImageList::BeginDrag](#begindrag)|Começa a arrastar uma imagem.|  
|[CImageList::Copy](#copy)|Copia uma imagem dentro de um `CImageList` objeto.|  
|[CImageList::Create](#create)|Inicializa uma lista de imagens e anexa-o para um `CImageList` objeto.|  
|[CImageList::DeleteImageList](#deleteimagelist)|Exclui uma lista de imagens.|  
|[CImageList::DeleteTempMap](#deletetempmap)|Chamado pelo [CWinApp](../../mfc/reference/cwinapp-class.md) manipulador de tempo ocioso para excluir qualquer temporário `CImageList` objeto criado pelo `FromHandle`.|  
|[CImageList::Detach](#detach)|Desanexa um objeto de lista de imagem de um `CImageList` de objeto e retorna um identificador para uma lista de imagens.|  
|[CImageList::DragEnter](#dragenter)|Bloqueia as atualizações durante uma operação de arrastar e exibe a imagem de arrastar em uma posição especificada.|  
|[CImageList::DragLeave](#dragleave)|Desbloqueia a janela e oculta a imagem de arrastar para que a janela pode ser atualizada.|  
|[CImageList::DragMove](#dragmove)|Move a imagem que está sendo arrastada durante uma operação de arrastar e soltar.|  
|[CImageList::DragShowNolock](#dragshownolock)|Mostra ou oculta a imagem de arrastar durante uma operação de arrastar, sem bloquear a janela.|  
|[CImageList::Draw](#draw)|Desenha a imagem que está sendo arrastada durante uma operação de arrastar e soltar.|  
|[CImageList::DrawEx](#drawex)|Desenha um item de lista de imagem no contexto de dispositivo especificado. A função usa o estilo de desenho especificado e que combina a imagem com a cor especificada.|  
|[CImageList::DrawIndirect](#drawindirect)|Desenha uma imagem de uma lista de imagens.|  
|[CImageList::EndDrag](#enddrag)|Termina uma operação de arrastar.|  
|[CImageList::ExtractIcon](#extracticon)|Cria um ícone com base em uma imagem e uma máscara em uma lista de imagens.|  
|[CImageList::FromHandle](#fromhandle)|Retorna um ponteiro para um `CImageList` quando é fornecido um identificador para uma lista de imagens do objeto. Se um `CImageList` objeto não está anexado ao identificador, um temporário `CImageList` objeto é criado e anexado.|  
|[CImageList::FromHandlePermanent](#fromhandlepermanent)|Retorna um ponteiro para um `CImageList` quando é fornecido um identificador para uma lista de imagens do objeto. Se um `CImageList` objeto não está anexado ao identificador, NULL será retornado.|  
|[CImageList::GetBkColor](#getbkcolor)|Recupera a cor de plano de fundo atual para uma lista de imagens.|  
|[CImageList::GetDragImage](#getdragimage)|Obtém a lista de imagem temporários que é usada para arrastar.|  
|[CImageList::GetImageCount](#getimagecount)|Recupera o número de imagens em uma lista de imagens.|  
|[CImageList::GetImageInfo](#getimageinfo)|Recupera informações sobre uma imagem.|  
|[CImageList::GetSafeHandle](#getsafehandle)|Recupera `m_hImageList`.|  
|[CImageList::Read](#read)|Lê uma lista de imagens de um arquivo morto.|  
|[CImageList::Remove](#remove)|Remove uma imagem de uma lista de imagens.|  
|[CImageList::Replace](#replace)|Substitui uma imagem em uma lista de imagens com uma nova imagem.|  
|[CImageList::SetBkColor](#setbkcolor)|Define a cor de plano de fundo de uma lista de imagens.|  
|[CImageList::SetDragCursorImage](#setdragcursorimage)|Cria uma nova imagem de arrastar.|  
|[CImageList::SetImageCount](#setimagecount)|Redefine a contagem de imagens em uma lista de imagens.|  
|[CImageList::SetOverlayImage](#setoverlayimage)|Adiciona o índice baseado em zero de uma imagem à lista de imagens a serem usadas como máscaras de sobreposição.|  
|[CImageList::Write](#write)|Grava uma lista de imagens em um arquivo morto.|  
  
### <a name="public-operators"></a>Operadores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CImageList::operator HIMAGELIST](#operator_himagelist)|Retorna o HIMAGELIST anexado para o `CImageList`.|  
  
### <a name="public-data-members"></a>Membros de Dados Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CImageList::m_hImageList](#m_himagelist)|Um identificador que contém a lista de imagens anexada a este objeto.|  
  
## <a name="remarks"></a>Comentários  
 Uma "lista de imagens" é uma coleção de imagens do mesmo tamanho, cada um dos quais pode ser referenciada por seu índice baseado em zero. Listas de imagens são usadas para gerenciar com eficiência grandes conjuntos de ícones ou bitmaps. Todas as imagens em uma lista de imagens estão contidas em um bitmap único e amplo no formato de dispositivo da tela. Uma lista de imagens também pode incluir um bitmap monocromático que contém as máscaras usadas para desenhar imagens de maneira transparente (estilo de ícone). A API (interface) de programação de aplicativo do Microsoft Win32 fornece funções de lista de imagem que permitem que você desenhar imagens, criar e destruir a listas de imagens, adicionar e remover imagens, substitua imagens, imagens de mesclagem e arrastar imagens.  
  
 Esse controle (e, portanto, o `CImageList` classe) está disponível somente para programas executados na versão do Windows 95/98 e Windows NT 3.51 e posterior.  
  
 Para obter mais informações sobre como usar `CImageList`, consulte [controles](../../mfc/controls-mfc.md) e [usando CImageList](../../mfc/using-cimagelist.md).  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 [CObject](../../mfc/reference/cobject-class.md)  
  
 `CImageList`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxcmn. h  
  
##  <a name="add"></a>  CImageList::Add  
 Chame essa função para adicionar uma ou mais imagens ou um ícone para uma lista de imagens.  
  
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
 *pbmImage*  
 Ponteiro para o bitmap que contém a imagem ou imagens. O número de imagens é inferido da largura do bitmap.  
  
 *pbmMask*  
 Ponteiro para o bitmap que contém a máscara. Se nenhuma máscara for usada com a lista de imagens, este parâmetro é ignorado.  
  
 *crMask*  
 Cor usada para gerar a máscara. Cada pixel desta cor no determinado bitmap é alterada para preto e o bit correspondente na máscara é definido para um.  
  
 *hIcon*  
 Identificador do ícone que contém o bitmap e a máscara para a nova imagem.  
  
### <a name="return-value"></a>Valor de retorno  
 Índice baseado em zero da primeira imagem nova se for bem-sucedido; Caso contrário, - 1.  
  
### <a name="remarks"></a>Comentários  
 Você é responsável por liberar o identificador do ícone quando você terminar com ele.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFC_CImageList#1](../../mfc/reference/codesnippet/cpp/cimagelist-class_1.cpp)]  
  
##  <a name="attach"></a>  CImageList::Attach  
 Chame essa função para anexar uma lista de imagens para um `CImageList` objeto.  
  
```  
BOOL Attach(HIMAGELIST hImageList);
```  
  
### <a name="parameters"></a>Parâmetros  
 *hImageList*  
 Um identificador para um objeto de lista de imagem.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se o anexo foi bem-sucedida; Caso contrário, 0.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFC_CImageList#2](../../mfc/reference/codesnippet/cpp/cimagelist-class_2.cpp)]  
  
##  <a name="begindrag"></a>  CImageList::BeginDrag  
 Chame essa função para começar a arrastar uma imagem.  
  
```  
BOOL BeginDrag(
    int nImage,  
    CPoint ptHotSpot);
```  
  
### <a name="parameters"></a>Parâmetros  
 *Nimagem*  
 Índice baseado em zero da imagem para arrastar.  
  
 *ptHotSpot*  
 Coordenadas da posição inicial de arrastar (normalmente, a posição do cursor). As coordenadas são em relação ao canto superior esquerdo da imagem.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se bem-sucedido; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Essa função cria uma lista de imagem temporários que é usada para arrastar. A imagem combina a imagem especificada e a máscara com o cursor atual. Em resposta a mensagens WM_MOUSEMOVE subsequentes, você pode mover a imagem de arrastar usando o `DragMove` função de membro. Para encerrar a operação de arrastar, você pode usar o `EndDrag` função de membro.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFC_CImageList#3](../../mfc/reference/codesnippet/cpp/cimagelist-class_3.cpp)]  
  
##  <a name="cimagelist"></a>  CImageList::CImageList  
 Constrói um objeto `CImageList`.  
  
```  
CImageList();
```  
  
##  <a name="copy"></a>  CImageList::Copy  
 Essa função membro implementa o comportamento da função Win32 [ImageList_Copy](http://msdn.microsoft.com/library/windows/desktop/bb761520), conforme descrito no SDK do Windows.  
  
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
 *iDst*  
 O índice baseado em zero da imagem a ser usado como o destino da operação de cópia.  
  
 *iSrc*  
 O índice baseado em zero da imagem a ser usado como a origem da operação de cópia.  
  
 *uFlags*  
 O valor do sinalizador de bit que especifica o tipo de operação de cópia a ser feita. Esse parâmetro pode ser um dos seguintes valores:  
  
|Valor|Significado|  
|-----------|-------------|  
|ILCF_MOVE|A imagem de origem é copiada para o índice da imagem de destino. Essa operação resulta em várias instâncias de determinada imagem. ILCF_MOVE é o padrão.|  
|ILCF_SWAP|As imagens de origem e de destino do exchange posições na lista de imagens.|  
  
 *pSrc*  
 Um ponteiro para um `CImageList` objeto que é o destino da operação de cópia.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se bem-sucedido; Caso contrário, zero.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFC_CImageList#6](../../mfc/reference/codesnippet/cpp/cimagelist-class_4.cpp)]  
  
##  <a name="create"></a>  CImageList::Create  
 Inicializa uma lista de imagens e anexa-o para um [CImageList](../../mfc/reference/cimagelist-class.md) objeto.  
  
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
 *CX*  
 Dimensões de cada imagem, em pixels.  
  
 *Cy*  
 Dimensões de cada imagem, em pixels.  
  
 *nFlags*  
 Especifica o tipo da lista de imagens para criar. Esse parâmetro pode ser uma combinação dos valores a seguir, mas ele pode incluir apenas um do `ILC_COLOR` valores.  
  
|Valor|Significado|  
|-----------|-------------|  
|ILC_COLOR|Use o comportamento padrão se nenhum dos outros ILC_COLOR * sinalizadores for especificado. Normalmente, o padrão é ILC_COLOR4; mas para drivers de vídeo mais antigos, o padrão é ILC_COLORDDB.|  
|ILC_COLOR4|Use uma seção de bitmap independente de dispositivo (DIB) 4 bits (16 cores) como o bitmap para a lista de imagens.|  
|ILC_COLOR8|Use uma seção DIB de 8 bits. As cores usadas para a tabela de cores são as mesmas cores da paleta de meio-tom.|  
|ILC_COLOR16|Use de 16 bits (32 / 64k cor) seção DIB.|  
|ILC_COLOR24|Use uma seção DIB de 24 bits.|  
|ILC_COLOR32|Use uma seção DIB de 32 bits.|  
|ILC_COLORDDB|Use um bitmap dependente de dispositivo.|  
|ILC_MASK|Usa uma máscara. A lista de imagens contém dois bitmaps, um dos quais é um bitmap monocromático usado como uma máscara. Se esse valor não for incluído, a lista de imagens contém apenas um bitmap. Ver [imagens de desenho de uma lista de imagens](../../mfc/drawing-images-from-an-image-list.md) para obter mais informações sobre imagens mascaradas.|  
  
 *nInitial*  
 Número de imagens que inicialmente contém a lista de imagens.  
  
 *nGrow*  
 Número de imagens pelo qual a lista de imagens pode ser aumentada quando o sistema precisa redimensionar a lista para liberar espaço para novas imagens. Esse parâmetro representa o número de novas imagens, que a lista de imagem redimensionada pode conter.  
  
 *nBitmapID*  
 IDs de recurso do bitmap a ser associado com a lista de imagens.  
  
 *crMask*  
 Cor usada para gerar uma máscara. Cada pixel desta cor no bitmap especificado é alterada para preto e o bit correspondente na máscara é definido para um.  
  
 *lpszBitmapID*  
 Uma cadeia de caracteres que contém as IDs das imagens do recurso.  
  
 *imagelist1*  
 Uma referência a um objeto `CImageList`.  
  
 *nImage1*  
 Índice da primeira imagem existente.  
  
 *imagelist2*  
 Uma referência a um objeto `CImageList`.  
  
 *nImage2*  
 Índice da segunda imagem existente.  
  
 *DX*  
 Deslocamento do eixo x da segunda imagem em relação à primeira imagem, em pixels.  
  
 *dy*  
 Deslocamento do eixo y da segunda imagem em relação à primeira imagem, em pixels.  
  
 *pImageList*  
 Um ponteiro para um `CImageList` objeto.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se bem-sucedido; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Você constrói um `CImageList` em duas etapas. Primeiro, chame o construtor e, em seguida, chame `Create`, que cria a lista de imagens e anexa-o para o `CImageList` objeto.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFC_CImageList#7](../../mfc/reference/codesnippet/cpp/cimagelist-class_5.cpp)]  
  
##  <a name="deleteimagelist"></a>  CImageList::DeleteImageList  
 Chame essa função para excluir uma lista de imagens.  
  
```  
BOOL DeleteImageList();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se bem-sucedido; Caso contrário, 0.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFC_CImageList#8](../../mfc/reference/codesnippet/cpp/cimagelist-class_6.cpp)]  
  
##  <a name="deletetempmap"></a>  CImageList::DeleteTempMap  
 Chamado automaticamente pelo `CWinApp` manipulador de tempo ocioso `DeleteTempMap` exclui qualquer temporário `CImageList` objetos criados pelo [FromHandle](#fromhandle), mas não destrói os identificadores ( `hImageList`) temporariamente associados com o `ImageList` objetos.  
  
```  
static void PASCAL DeleteTempMap();
```  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFC_CImageList#9](../../mfc/reference/codesnippet/cpp/cimagelist-class_7.cpp)]  
  
##  <a name="detach"></a>  CImageList::Detach  
 Chame essa função para desanexar de um objeto de lista de imagem de um `CImageList` objeto.  
  
```  
HIMAGELIST Detach();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um identificador para um objeto de lista de imagem.  
  
### <a name="remarks"></a>Comentários  
 Essa função retorna um identificador para o objeto de lista de imagem.  
  
### <a name="example"></a>Exemplo  
  Veja o exemplo de [CImageList::Attach](#attach).  
  
##  <a name="dragenter"></a>  CImageList::DragEnter  
 Durante uma operação de arrastar, bloqueia as atualizações para a janela especificada pelo *pWndLock* e exibe a imagem de arrastar na posição especificada por *aponte*.  
  
```  
static BOOL PASCAL DragEnter(
    CWnd* pWndLock,  
    CPoint point);
```  
  
### <a name="parameters"></a>Parâmetros  
 *pWndLock*  
 Ponteiro para a janela que possui a imagem de arrastar.  
  
 *ponto*  
 Posição na qual exibir a imagem de arrastar. As coordenadas são em relação ao canto superior esquerdo da janela (não a área de cliente).  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se bem-sucedido; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 As coordenadas são em relação ao canto esquerdo superior da janela, portanto, você deve compensar as larguras de elementos de janela, como a borda, a barra de título e a barra de menus, ao especificar as coordenadas.  
  
 Se *pWndLock* for NULL, essa função desenha a imagem no contexto de exibição associado à janela da área de trabalho e as coordenadas são relativas ao canto superior esquerdo da tela.  
  
 Essa função bloqueia todas as outras atualizações para a janela de determinado durante a operação de arrastar. Se você precisar fazer qualquer drawing durante uma operação de arrastar, como realce o destino de uma operação de arrastar e soltar, você pode ocultar temporariamente a imagem arrastada usando o [CImageList::DragLeave](#dragleave) função.  
  
### <a name="example"></a>Exemplo  
  Veja o exemplo de [CImageList::BeginDrag](#begindrag).  
  
##  <a name="dragleave"></a>  CImageList::DragLeave  
 Desbloqueia a janela especificada pelo *pWndLock* e oculta a imagem de arrastar, permitindo que a janela a ser atualizada.  
  
```  
static BOOL PASCAL DragLeave(CWnd* pWndLock);
```  
  
### <a name="parameters"></a>Parâmetros  
 *pWndLock*  
 Ponteiro para a janela que possui a imagem de arrastar.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se bem-sucedido; Caso contrário, 0.  
  
### <a name="example"></a>Exemplo  
  Veja o exemplo de [CImageList::EndDrag](#enddrag).  
  
##  <a name="dragmove"></a>  CImageList::DragMove  
 Chame essa função para mover a imagem que está sendo arrastada durante uma operação de arrastar e soltar.  
  
```  
static BOOL PASCAL DragMove(CPoint pt);
```  
  
### <a name="parameters"></a>Parâmetros  
 *pt*  
 Nova posição de arrastar.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se bem-sucedido; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Normalmente, essa função é chamada em resposta a uma mensagem WM_MOUSEMOVE. Para começar uma operação de arrastar, use o `BeginDrag` função de membro.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFC_CImageList#4](../../mfc/reference/codesnippet/cpp/cimagelist-class_8.cpp)]  
  
##  <a name="dragshownolock"></a>  CImageList::DragShowNolock  
 Mostra ou oculta a imagem de arrastar durante uma operação de arrastar, sem bloquear a janela.  
  
```  
static BOOL PASCAL DragShowNolock(BOOL bShow);
```  
  
### <a name="parameters"></a>Parâmetros  
 *bMostrar*  
 Especifica se a imagem de arrastar deve ser mostrado.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se bem-sucedido; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 O [CImageList::DragEnter](#dragenter) função bloqueia todas as atualizações para a janela durante uma operação de arrastar. No entanto, essa função não bloqueia a janela.  
  
##  <a name="draw"></a>  CImageList::Draw  
 Chame essa função para desenhar a imagem que está sendo arrastada durante uma operação de arrastar e soltar.  
  
```  
BOOL Draw(
    CDC* pDC,  
    int nImage,  
    POINT pt,  
    UINT nStyle);
```  
  
### <a name="parameters"></a>Parâmetros  
 *pDC*  
 Ponteiro para o contexto de dispositivo de destino.  
  
 *Nimagem*  
 Índice baseado em zero da imagem a ser desenhado.  
  
 *pt*  
 Local no qual desenhar dentro do contexto de dispositivo especificado.  
  
 *nStyle*  
 Sinalizador que especifica o estilo de desenho. Ele pode ser um ou mais destes valores:  
  
|Valor|Significado|  
|-----------|-------------|  
|ILD_BLEND25, ILD_FOCUS|Desenha a imagem, a combinação de 25 por cento, com a cor de realce do sistema. Esse valor não tem efeito se a lista de imagens não contiver uma máscara.|  
|ILD_BLEND50 ILD_SELECTED, ILD_BLEND|Desenha a imagem, 50 por cento, com a cor de realce do sistema de mesclagem. Esse valor não tem efeito se a lista de imagens não contiver uma máscara.|  
|ILD_MASK|Desenha a máscara.|  
|ILD_NORMAL|Desenha a imagem usando a cor do plano de fundo para a lista de imagens. Se a cor do plano de fundo é o valor CLR_NONE, a imagem é desenhada de forma transparente usando a máscara.|  
|ILD_TRANSPARENT|Desenha a imagem de forma transparente usando a máscara, independentemente da cor do plano de fundo.|  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se bem-sucedido; Caso contrário, 0.  
  
### <a name="example"></a>Exemplo  
  Veja o exemplo de [CImageList::SetOverlayImage](#setoverlayimage).  
  
##  <a name="drawex"></a>  CImageList::DrawEx  
 Desenha um item de lista de imagem no contexto de dispositivo especificado.  
  
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
 *pDC*  
 Ponteiro para o contexto de dispositivo de destino.  
  
 *Nimagem*  
 Índice baseado em zero da imagem a ser desenhado.  
  
 *pt*  
 Local no qual desenhar dentro do contexto de dispositivo especificado.  
  
 *SZ*  
 Tamanho da parte da imagem a ser desenhado em relação ao canto superior esquerdo da imagem. Ver *dx* e *dy* na [ImageList_DrawEx](http://msdn.microsoft.com/library/windows/desktop/bb761536) no SDK do Windows.  
  
 *clrBk*  
 Cor do plano de fundo da imagem. Ver *rgbBk* na [ImageList_DrawEx](http://msdn.microsoft.com/library/windows/desktop/bb761536) no SDK do Windows.  
  
 *clrFg*  
 Cor de primeiro plano da imagem. Ver *rgbFg* na [ImageList_DrawEx](http://msdn.microsoft.com/library/windows/desktop/bb761536) no SDK do Windows.  
  
 *nStyle*  
 Sinalizador que especifica o estilo de desenho. Ver *fStyle* na [ImageList_DrawEx](http://msdn.microsoft.com/library/windows/desktop/bb761536) no SDK do Windows.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se bem-sucedido; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 A função usa o estilo de desenho especificado e que combina a imagem com a cor especificada.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFC_CImageList#10](../../mfc/reference/codesnippet/cpp/cimagelist-class_9.cpp)]  
  
##  <a name="drawindirect"></a>  CImageList::DrawIndirect  
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
  
### <a name="parameters"></a>Parâmetros  
 *pimldp*  
 Um ponteiro para um [IMAGELISTDRAWPARAMS](http://msdn.microsoft.com/library/windows/desktop/bb761395) estrutura que contém informações sobre a operação de desenho.  
  
 *pDC*  
 Um ponteiro para o contexto de dispositivo de destino. Você deve excluir esse [CDC](../../mfc/reference/cdc-class.md) objeto quando você terminar com ele.  
  
 *Nimagem*  
 O índice baseado em zero da imagem a ser desenhado.  
  
 *pt*  
 Um [ponto](http://msdn.microsoft.com/library/windows/desktop/dd162805) estrutura que contém as coordenadas x e y-onde a imagem será desenhada.  
  
 *SZ*  
 Um [tamanho](http://msdn.microsoft.com/library/windows/desktop/dd145106) estrutura que indica o tamanho da imagem a ser desenhado.  
  
 *ptOrigin*  
 Um [ponto](http://msdn.microsoft.com/library/windows/desktop/dd162805) estrutura que contém as coordenadas x e y-especificando o canto superior esquerdo da operação de desenho em relação a própria imagem. Os pixels da imagem à esquerda da coordenada x e superiores a coordenada y não são desenhados.  
  
 *fStyle*  
 Sinalizador que especifica o estilo de desenho e, opcionalmente, uma imagem de sobreposição. Consulte a seção comentários para obter informações sobre a imagem de sobreposição. A implementação padrão MFC, ILD_NORMAL, desenha a imagem usando a cor do plano de fundo para a lista de imagens. Se a cor do plano de fundo é o valor CLR_NONE, a imagem é desenhada de forma transparente usando uma máscara.  
  
 Outros estilos possíveis são descritos na *fStyle* membro a [IMAGELISTDRAWPARAMS](http://msdn.microsoft.com/library/windows/desktop/bb761395) estrutura.  
  
 *dwRop*  
 Valor que especifica um código de operação de varredura. Esses códigos definem como os dados de cor para o retângulo de origem serão combinados com os dados de cor para o retângulo de destino alcançar a cor final. A implementação padrão do MFC, {1&gt;SRCCOPY&lt;1, copia o retângulo de origem diretamente para o retângulo de destino. Esse parâmetro será ignorado se o *fStyle* parâmetro não inclui o sinalizador ILD_ROP.  
  
 Outros possíveis valores são descritos na *dwRop* membro a [IMAGELISTDRAWPARAMS](http://msdn.microsoft.com/library/windows/desktop/bb761395) estrutura.  
  
 *rgbBack*  
 A cor de plano de fundo de imagem, por padrão CLR_DEFAULT. Esse parâmetro pode ser um valor RGB definido pelo aplicativo ou um dos seguintes valores:  
  
|Valor|Significado|  
|-----------|-------------|  
|CLR_DEFAULT|Cor do plano de fundo padrão. A imagem é desenhada usando a cor de plano de fundo de lista de imagem.|  
|CLR_NONE|Nenhuma cor de plano de fundo. A imagem é desenhada de forma transparente.|  
  
 *rgbFore*  
 Cor de primeiro plano de imagem, por padrão CLR_DEFAULT. Esse parâmetro pode ser um valor RGB definido pelo aplicativo ou um dos seguintes valores:  
  
|Valor|Significado|  
|-----------|-------------|  
|CLR_DEFAULT|Cor de primeiro plano padrão. A imagem é desenhada usando a cor de realce do sistema como a cor de primeiro plano.|  
|CLR_NONE|Nenhuma cor de mesclagem. A imagem é combinada com a cor do contexto de dispositivo de destino.|  
  
 Esse parâmetro é usado somente se *fStyle* inclui o sinalizador ILD_BLEND25 ou ILD_BLEND50.  
  
 *fState*  
 Sinalizador que especifica o estado de desenho. Esse membro pode conter um ou mais sinalizadores de estado de lista de imagem.  
  
 *Quadro*  
 Afeta o comportamento de efeitos saturate e transparência.  
  
 Quando usado com ILS_SATURATE, esse membro contém o valor que é adicionado a cada componente de cor do triplo para cada pixel no ícone de RGB.  
  
 Quando usado com ILS_APLHA, esse membro contém o valor para o canal alfa. Esse valor pode ser de 0 a 255, com 0 sendo completamente transparente e 255 que estão sendo completamente opaco.  
  
 *crEffect*  
 Um [COLORREF](http://msdn.microsoft.com/library/windows/desktop/dd183449) valor usado para efeitos de sombra e brilho.  
  
### <a name="return-value"></a>Valor de retorno  
 TRUE se a imagem é desenhada com êxito; Caso contrário, FALSE.  
  
### <a name="remarks"></a>Comentários  
 Use a primeira versão, se você deseja preencher a estrutura do Win32 por conta própria. Use a segunda versão, se você quiser tirar proveito de um ou mais dos argumentos de padrão do MFC ou evitar a gerenciar a estrutura.  
  
 Uma imagem de sobreposição é uma imagem que é desenhada na parte superior a imagem principal, especificada por essa função de membro de *Nimagem* parâmetro. Desenhar uma máscara de sobreposição usando o [desenhar](#draw) função de membro com o índice baseado em um da máscara de sobreposição especificado usando o [INDEXTOOVERLAYMASK](http://msdn.microsoft.com/library/windows/desktop/bb761408) macro.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFC_CImageList#11](../../mfc/reference/codesnippet/cpp/cimagelist-class_10.cpp)]  
  
##  <a name="enddrag"></a>  CImageList::EndDrag  
 Chame essa função para finalizar uma operação de arrastar.  
  
```  
static void PASCAL EndDrag();
```  
  
### <a name="remarks"></a>Comentários  
 Para começar uma operação de arrastar, use o `BeginDrag` função de membro.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFC_CImageList#5](../../mfc/reference/codesnippet/cpp/cimagelist-class_11.cpp)]  
  
##  <a name="extracticon"></a>  CImageList::ExtractIcon  
 Chame essa função para criar um ícone com base em uma imagem e sua máscara relacionada em uma lista de imagens.  
  
```  
HICON ExtractIcon(int nImage);
```  
  
### <a name="parameters"></a>Parâmetros  
 *Nimagem*  
 Índice baseado em zero da imagem.  
  
### <a name="return-value"></a>Valor de retorno  
 Identificador do ícone se bem-sucedido; Caso contrário, nulo.  
  
### <a name="remarks"></a>Comentários  
 Esse método se baseia no comportamento do [ImageList_ExtractIcon](http://msdn.microsoft.com/library/windows/desktop/bb761401) macro para criar o ícone. Consulte a [ImageList_ExtractIcon](http://msdn.microsoft.com/library/windows/desktop/bb761401) macro para obter mais informações sobre a criação de ícone e limpeza.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFC_CImageList#12](../../mfc/reference/codesnippet/cpp/cimagelist-class_12.cpp)]  
  
##  <a name="fromhandle"></a>  CImageList::FromHandle  
 Retorna um ponteiro para um `CImageList` quando é fornecido um identificador para uma lista de imagens do objeto.  
  
```  
static CImageList* PASCAL FromHandle(HIMAGELIST hImageList);
```  
  
### <a name="parameters"></a>Parâmetros  
 *hImageList*  
 Especifica a lista de imagens.  
  
### <a name="return-value"></a>Valor de retorno  
 Um ponteiro para um `CImageList` objeto se for bem-sucedido; caso contrário, NULL.  
  
### <a name="remarks"></a>Comentários  
 Se um `CImageList` já não está anexado ao identificador, um temporário `CImageList` objeto é criado e anexado. Esse temporário `CImageList` objeto é válido somente até a próxima vez que o aplicativo tem tempo ocioso em seu loop de eventos, momento em que todos os objetos temporários serão excluídos.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFC_CImageList#13](../../mfc/reference/codesnippet/cpp/cimagelist-class_13.cpp)]  
  
##  <a name="fromhandlepermanent"></a>  CImageList::FromHandlePermanent  
 Retorna um ponteiro para um `CImageList` quando é fornecido um identificador para uma lista de imagens do objeto.  
  
```  
static CImageList* PASCAL FromHandlePermanent(HIMAGELIST hImageList);
```  
  
### <a name="parameters"></a>Parâmetros  
 *hImageList*  
 Especifica a lista de imagens.  
  
### <a name="return-value"></a>Valor de retorno  
 Um ponteiro para um `CImageList` objeto se for bem-sucedido; caso contrário, NULL.  
  
### <a name="remarks"></a>Comentários  
 Se um `CImageList` objeto não está anexado ao identificador, NULL será retornado.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFC_CImageList#14](../../mfc/reference/codesnippet/cpp/cimagelist-class_14.cpp)]  
  
##  <a name="getbkcolor"></a>  CImageList::GetBkColor  
 Chame essa função para recuperar a cor de plano de fundo atual para uma lista de imagens.  
  
```  
COLORREF GetBkColor() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 O valor de cor RGB do `CImageList` cor do plano de fundo do objeto.  
  
### <a name="example"></a>Exemplo  
  Veja o exemplo de [CImageList::SetBkColor](#setbkcolor).  
  
##  <a name="getdragimage"></a>  CImageList::GetDragImage  
 Obtém a lista de imagem temporários que é usada para arrastar.  
  
```  
static CImageList* PASCAL GetDragImage(
    LPPOINT lpPoint,  
    LPPOINT lpPointHotSpot);
```  
  
### <a name="parameters"></a>Parâmetros  
 *lpPoint*  
 Endereço de uma [ponto](http://msdn.microsoft.com/library/windows/desktop/dd162805) estrutura que recebe a atual posição de arrastar.  
  
 *lpPointHotSpot*  
 Endereço de um `POINT` estrutura que recebe o deslocamento da imagem de arrastar em relação à posição de arrastar.  
  
### <a name="return-value"></a>Valor de retorno  
 Se for bem-sucedido, um ponteiro para a imagem temporários lista que é usado para arrastar; Caso contrário, nulo.  
  
##  <a name="getimagecount"></a>  CImageList::GetImageCount  
 Chame essa função para recuperar o número de imagens em uma lista de imagens.  
  
```  
int GetImageCount() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 O número de imagens.  
  
### <a name="example"></a>Exemplo  
  Veja o exemplo de [CImageList::ExtractIcon](#extracticon).  
  
##  <a name="getimageinfo"></a>  CImageList::GetImageInfo  
 Chame essa função para recuperar informações sobre uma imagem.  
  
```  
BOOL GetImageInfo(
    int nImage,  
    IMAGEINFO* pImageInfo) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 *Nimagem*  
 Índice baseado em zero da imagem.  
  
 *pImageInfo*  
 Ponteiro para um [IMAGEINFO](http://msdn.microsoft.com/library/windows/desktop/bb761393) estrutura que recebe informações sobre a imagem. As informações nessa estrutura podem ser usadas para manipular diretamente os bitmaps para a imagem.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se bem-sucedido; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 O `IMAGEINFO` estrutura contém informações sobre uma imagem em uma lista de imagens.  
  
##  <a name="getsafehandle"></a>  CImageList::GetSafeHandle  
 Chame essa função para recuperar o `m_hImageList` membro de dados.  
  
```  
HIMAGELIST GetSafeHandle() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um identificador para a lista de imagens anexadas; Caso contrário, nulo se nenhum objeto está anexado.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFC_CImageList#15](../../mfc/reference/codesnippet/cpp/cimagelist-class_15.cpp)]  
  
##  <a name="m_himagelist"></a>  CImageList::m_hImageList  
 Um identificador da lista de imagens anexado a este objeto.  
  
 `HIMAGELIST m_hImageList;`  
  
### <a name="remarks"></a>Comentários  
 O `m_hImageList` membro de dados é uma variável pública do tipo HIMAGELIST.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFC_CImageList#23](../../mfc/reference/codesnippet/cpp/cimagelist-class_16.cpp)]  
  
##  <a name="operator_himagelist"></a>  CImageList::operator HIMAGELIST  
 Use este operador para obter o identificador anexado do `CImageList` objeto.  
  
```  
operator HIMAGELIST() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Se for bem-sucedido, um identificador para a lista de imagens representado pelo `CImageList` objeto; caso contrário, nulo.  
  
### <a name="remarks"></a>Comentários  
 Esse operador é um operador de conversão, que dá suporte ao uso direto de um objeto HIMAGELIST.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFC_CImageList#16](../../mfc/reference/codesnippet/cpp/cimagelist-class_17.cpp)]  
  
##  <a name="read"></a>  CImageList::Read  
 Chame essa função para uma lista de imagens de leitura de um arquivo.  
  
```  
BOOL Read(CArchive* pArchive);
```  
  
### <a name="parameters"></a>Parâmetros  
 *pArchive*  
 Um ponteiro para um `CArchive` objeto do qual a lista de imagens deve ser lido.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se bem-sucedido; Caso contrário, 0.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFC_CImageList#18](../../mfc/reference/codesnippet/cpp/cimagelist-class_18.cpp)]  
  
##  <a name="remove"></a>  CImageList::Remove  
 Chame essa função para remover uma imagem de um objeto de lista de imagem.  
  
```  
BOOL Remove(int nImage);
```  
  
### <a name="parameters"></a>Parâmetros  
 *Nimagem*  
 Índice baseado em zero da imagem a ser removida.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se bem-sucedido; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Todos os itens que seguem *Nimagem* agora mover uma posição para baixo. Por exemplo, se uma lista de imagens contém dois itens, excluir o primeiro item fará com que o item restante ser, agora, na primeira posição. *Nimagem*= 0 para o item na primeira posição.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFC_CImageList#19](../../mfc/reference/codesnippet/cpp/cimagelist-class_19.cpp)]  
  
##  <a name="replace"></a>  CImageList::Replace  
 Chame essa função para substituir uma imagem em uma lista de imagens com uma nova imagem.  
  
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
 *Nimagem*  
 Índice baseado em zero da imagem para substituir.  
  
 *pbmImage*  
 Um ponteiro para o bitmap que contém a imagem.  
  
 *pbmMask*  
 Um ponteiro para o bitmap que contém a máscara. Se nenhuma máscara for usada com a lista de imagens, este parâmetro é ignorado.  
  
 *hIcon*  
 Um identificador para o ícone que contém o bitmap e a máscara para a nova imagem.  
  
### <a name="return-value"></a>Valor de retorno  
 A versão retornando BOOL retorna diferente de zero se bem-sucedido; Caso contrário, 0.  
  
 A versão retornando **int** retorna o índice baseado em zero da imagem, se for bem-sucedido; caso contrário, - 1.  
  
### <a name="remarks"></a>Comentários  
 Chame essa função de membro depois de chamar [SetImageCount](#setimagecount) para atribuir o novo, números de índice de imagem de imagens válidas para o espaço reservado.  
  
### <a name="example"></a>Exemplo  
  Veja o exemplo de [CImageList::SetImageCount](#setimagecount).  
  
##  <a name="setbkcolor"></a>  CImageList::SetBkColor  
 Chame essa função para definir a cor de plano de fundo de uma lista de imagens.  
  
```  
COLORREF SetBkColor(COLORREF cr);
```  
  
### <a name="parameters"></a>Parâmetros  
 *CR*  
 Cor do plano de fundo para definir. Ele pode ser CLR_NONE. Nesse caso, imagens são desenhadas de forma transparente usando a máscara.  
  
### <a name="return-value"></a>Valor de retorno  
 A cor de plano de fundo anterior se bem-sucedido; Caso contrário, CLR_NONE.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFC_CImageList#20](../../mfc/reference/codesnippet/cpp/cimagelist-class_20.cpp)]  
  
##  <a name="setdragcursorimage"></a>  CImageList::SetDragCursorImage  
 Cria uma nova imagem de arrastar, combinando a determinada imagem (normalmente uma imagem do cursor do mouse) com a imagem atual de arrastar.  
  
```  
BOOL SetDragCursorImage(
    int nDrag,  
    CPoint ptHotSpot);
```  
  
### <a name="parameters"></a>Parâmetros  
 *narraste*  
 Índice da nova imagem a ser combinado com a imagem de arrastar.  
  
 *ptHotSpot*  
 Posição do ponto ativo dentro da nova imagem.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se bem-sucedido; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Como as funções de arrastar usam a nova imagem durante uma operação de arrastar, você deve usar o Windows [ShowCursor](http://msdn.microsoft.com/library/windows/desktop/ms648396) função para ocultar o cursor do mouse real depois de chamar `CImageList::SetDragCursorImage`. Caso contrário, o sistema pode parecer ter dois cursores de mouse para a duração da operação de arrastar.  
  
##  <a name="setimagecount"></a>  CImageList::SetImageCount  
 Chame essa função de membro para redefinir o número de imagens em um `CImageList` objeto.  
  
```  
BOOL SetImageCount(UINT uNewCount);
```  
  
### <a name="parameters"></a>Parâmetros  
 *uNewCount*  
 O valor que especifica o novo número total de imagens na lista de imagens.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se bem-sucedido; Caso contrário, zero.  
  
### <a name="remarks"></a>Comentários  
 Se você chamar essa função de membro para aumentar o número de imagens na lista de imagens, em seguida, chame [substituir](#replace) para cada imagem adicional para atribuir os novos índices imagens válidas. Se você não atribuir os índices para imagens válidas, operações de desenho que criam novas imagens será imprevisíveis.  
  
 Se você diminuir o tamanho de uma lista de imagens usando essa função, as imagens truncadas são liberadas.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFC_CImageList#21](../../mfc/reference/codesnippet/cpp/cimagelist-class_21.cpp)]  
  
##  <a name="setoverlayimage"></a>  CImageList::SetOverlayImage  
 Chame essa função para adicionar o índice baseado em zero de uma imagem à lista de imagens a serem usadas como máscaras de sobreposição.  
  
```  
BOOL SetOverlayImage(
    int nImage,  
    int nOverlay);
```  
  
### <a name="parameters"></a>Parâmetros  
 *Nimagem*  
 Índice baseado em zero da imagem para usar como uma máscara de sobreposição.  
  
 *nOverlay*  
 Baseado em um índice da máscara de sobreposição.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se bem-sucedido; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Até quatro índices podem ser adicionados à lista.  
  
 Uma máscara de sobreposição é uma imagem desenhada de forma transparente sobre outra imagem. Desenhar uma máscara de sobreposição sobre uma imagem usando o [CImageList::Draw](#draw) a função de membro com o índice baseado em um da sobreposição de máscara especificado usando a macro INDEXTOOVERLAYMASK.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFC_CImageList#22](../../mfc/reference/codesnippet/cpp/cimagelist-class_22.cpp)]  
  
##  <a name="write"></a>  CImageList::Write  
 Chame essa função para gravar um objeto de lista de imagem em um arquivo morto.  
  
```  
BOOL Write(CArchive* pArchive);
```  
  
### <a name="parameters"></a>Parâmetros  
 *pArchive*  
 Um ponteiro para um `CArchive` objeto no qual a lista de imagens deve ser armazenado.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se bem-sucedido; Caso contrário, 0.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFC_CImageList#17](../../mfc/reference/codesnippet/cpp/cimagelist-class_23.cpp)]  
  
## <a name="see-also"></a>Consulte também  
 [Classe CObject](../../mfc/reference/cobject-class.md)   
 [Gráfico da hierarquia](../../mfc/hierarchy-chart.md)   
 [Classe CListCtrl](../../mfc/reference/clistctrl-class.md)   
 [Classe CTabCtrl](../../mfc/reference/ctabctrl-class.md)
