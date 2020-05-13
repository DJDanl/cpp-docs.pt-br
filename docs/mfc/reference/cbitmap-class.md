---
title: Classe CBitmap
ms.date: 11/04/2016
f1_keywords:
- CBitmap
- AFXWIN/CBitmap
- AFXWIN/CBitmap::CBitmap
- AFXWIN/CBitmap::CreateBitmap
- AFXWIN/CBitmap::CreateBitmapIndirect
- AFXWIN/CBitmap::CreateCompatibleBitmap
- AFXWIN/CBitmap::CreateDiscardableBitmap
- AFXWIN/CBitmap::FromHandle
- AFXWIN/CBitmap::GetBitmap
- AFXWIN/CBitmap::GetBitmapBits
- AFXWIN/CBitmap::GetBitmapDimension
- AFXWIN/CBitmap::LoadBitmap
- AFXWIN/CBitmap::LoadMappedBitmap
- AFXWIN/CBitmap::LoadOEMBitmap
- AFXWIN/CBitmap::SetBitmapBits
- AFXWIN/CBitmap::SetBitmapDimension
helpviewer_keywords:
- CBitmap [MFC], CBitmap
- CBitmap [MFC], CreateBitmap
- CBitmap [MFC], CreateBitmapIndirect
- CBitmap [MFC], CreateCompatibleBitmap
- CBitmap [MFC], CreateDiscardableBitmap
- CBitmap [MFC], FromHandle
- CBitmap [MFC], GetBitmap
- CBitmap [MFC], GetBitmapBits
- CBitmap [MFC], GetBitmapDimension
- CBitmap [MFC], LoadBitmap
- CBitmap [MFC], LoadMappedBitmap
- CBitmap [MFC], LoadOEMBitmap
- CBitmap [MFC], SetBitmapBits
- CBitmap [MFC], SetBitmapDimension
ms.assetid: 3980616a-c59d-495a-86e6-62bd3889c84c
ms.openlocfilehash: 9a33a6e1bea601422e043d7f2a80029c72d97e50
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81352737"
---
# <a name="cbitmap-class"></a>Classe CBitmap

Encapsula um bitmap de interface de dispositivo gráfico do Windows (GDI) e fornece funções de membro para manipular o bitmap.

## <a name="syntax"></a>Sintaxe

```
class CBitmap : public CGdiObject
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[CBitmap::CBitmap](#cbitmap)|Constrói um objeto `CBitmap`.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CBitmap::CreateBitmap](#createbitmap)|Inicializa o objeto com um bitmap de memória dependente do dispositivo que tem um padrão de largura, altura e bit especificado.|
|[CBitmap::CreateBitmapIndirect](#createbitmapindirect)|Inicializa o objeto com um bitmap com o padrão de largura, altura e `BITMAP` bit (se for especificado) dado em uma estrutura.|
|[CBitmap::CreateCompatibleBitmap](#createcompatiblebitmap)|Inicializa o objeto com um bitmap para que seja compatível com um dispositivo especificado.|
|[CBitmap::CreateDiscardableBitmap](#creatediscardablebitmap)|Inicializa o objeto com um bitmap descartável compatível com um dispositivo especificado.|
|[CBitmap::FromHandle](#fromhandle)|Retorna um ponteiro `CBitmap` para um objeto quando `HBITMAP` dado uma alça a um bitmap do Windows.|
|[CBitmap::GetBitmap](#getbitmap)|Preenche uma `BITMAP` estrutura com informações sobre o bitmap.|
|[CBitmap::GetBitmapBits](#getbitmapbits)|Copia os bits do bitmap especificado no buffer especificado.|
|[CBitmap::GetBitmapDimension](#getbitmapdimension)|Retorna a largura e a altura do bitmap. A altura e a largura foram definidas anteriormente pela função de membro [SetBitmapDimension.](#setbitmapdimension)|
|[CBitmap::LoadBitmap](#loadbitmap)|Inicializa o objeto carregando um recurso bitmap chamado do arquivo executável do aplicativo e anexando o bitmap ao objeto.|
|[CBitmap:LoadMappedBitmap](#loadmappedbitmap)|Carrega um bitmap e mapeia cores para as cores atuais do sistema.|
|[CBitmap::LoadOEMBitmap](#loadoembitmap)|Inicializa o objeto carregando um bitmap do Windows predefinido e anexando o bitmap ao objeto.|
|[CBitmap::SetBitmapBits](#setbitmapbits)|Define os bits de um bitmap para os valores de bit especificados.|
|[CBitmap::SetBitmapDimension](#setbitmapdimension)|Atribui uma largura e altura a um bitmap em unidades de 0,1 milímetros.|

### <a name="public-operators"></a>Operadores públicos

|Nome|Descrição|
|----------|-----------------|
|[CBitmap::operador HBITMAP](#operator_hbitmap)|Retorna a alça do `CBitmap` Windows anexada ao objeto.|

## <a name="remarks"></a>Comentários

Para usar `CBitmap` um objeto, construa o objeto, conecte uma alça de bitmap a ele com uma das funções do membro de inicialização e, em seguida, chame as funções do membro do objeto.

Para obter mais informações `CBitmap`sobre o uso de objetos gráficos como, consulte [Objetos Gráficos](../../mfc/graphic-objects.md).

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[Cobject](../../mfc/reference/cobject-class.md)

[Cgdiobject](../../mfc/reference/cgdiobject-class.md)

`CBitmap`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxwin.h

## <a name="cbitmapcbitmap"></a><a name="cbitmap"></a>CBitmap::CBitmap

Constrói um objeto `CBitmap`.

```
CBitmap();
```

### <a name="remarks"></a>Comentários

O objeto resultante deve ser inicializado com uma das funções do membro de inicialização.

## <a name="cbitmapcreatebitmap"></a><a name="createbitmap"></a>CBitmap::CreateBitmap

Inicializa um bitmap de memória dependente do dispositivo que tem o padrão de largura, altura e bit especificados.

```
BOOL CreateBitmap(
    int nWidth,
    int nHeight,
    UINT nPlanes,
    UINT nBitcount,
    const void* lpBits);
```

### <a name="parameters"></a>Parâmetros

*Nwidth*<br/>
Especifica a largura (em pixels) do bitmap.

*Nheight*<br/>
Especifica a altura (em pixels) do bitmap.

*nAviões*<br/>
Especifica o número de planos de cores no bitmap.

*nBitcount*<br/>
Especifica o número de bits de cor por pixel de exibição.

*Lpbits*<br/>
Aponta para uma matriz de bytes que contém os valores iniciais de bitmap. Se for NULL, o novo bitmap não será inicializado.

### <a name="return-value"></a>Valor retornado

Não zero se bem sucedido; caso contrário, 0.

### <a name="remarks"></a>Comentários

Para um bitmap de cores, o *parâmetro nPlanes* ou *nBitcount* deve ser definido como 1. Se ambos os parâmetros forem definidos como 1, `CreateBitmap` criará um bitmap monocromático.

Embora um bitmap não possa ser selecionado diretamente para um dispositivo de exibição, ele pode ser selecionado como o bitmap atual para um "contexto do dispositivo de memória" usando [CDC::SelectObject](../../mfc/reference/cdc-class.md#selectobject) e copiado para qualquer contexto de dispositivo compatível usando a função [CDC::BitBlt.](../../mfc/reference/cdc-class.md#bitblt)

Quando terminar com `CBitmap` o objeto `CreateBitmap` criado pela função, primeiro selecione o bitmap `CBitmap` fora do contexto do dispositivo e, em seguida, exclua o objeto.

Para obter mais informações, `bmBits` consulte a `BITMAP` descrição do campo na estrutura. A estrutura [BITMAP](/windows/win32/api/wingdi/ns-wingdi-bitmap) é descrita sob a função [CBitmap::CreateBitmapMembro indireto.](#createbitmapindirect)

## <a name="cbitmapcreatebitmapindirect"></a><a name="createbitmapindirect"></a>CBitmap::CreateBitmapIndirect

Inicializa um bitmap que tem o padrão de largura, altura e bit (se for especificado) dado na estrutura apontada pelo *lpBitmap*.

```
BOOL CreateBitmapIndirect(LPBITMAP lpBitmap);
```

### <a name="parameters"></a>Parâmetros

*Lpbitmap*<br/>
Aponta para uma estrutura [BITMAP](/windows/win32/api/wingdi/ns-wingdi-bitmap) que contém informações sobre o bitmap.

### <a name="return-value"></a>Valor retornado

Não zero se bem sucedido; caso contrário, 0.

### <a name="remarks"></a>Comentários

Embora um bitmap não possa ser selecionado diretamente para um dispositivo de exibição, ele pode ser selecionado como o bitmap atual para um contexto de dispositivo de memória usando [CDC::SelectObject](../../mfc/reference/cdc-class.md#selectobject) e copiado para qualquer contexto de dispositivo compatível usando a função [CDC::BitBlt](../../mfc/reference/cdc-class.md#bitblt) ou [CDC::StretchBlt.](../../mfc/reference/cdc-class.md#stretchblt) (A função [CDC::PatBlt](../../mfc/reference/cdc-class.md#patblt) pode copiar o bitmap para o pincel atual diretamente para o contexto do dispositivo de exibição.)

Se `BITMAP` a estrutura apontada pelo parâmetro *lpBitmap* tiver sido `GetObject` preenchida usando a função, os bits do bitmap não serão especificados e o bitmap não será inicializado. Para inicializar o bitmap, um aplicativo pode usar uma função como [CDC::BitBlt](../../mfc/reference/cdc-class.md#bitblt) ou [SetDIBits](/windows/win32/api/wingdi/nf-wingdi-setdibits) para copiar `CGdiObject::GetObject` os bits do `CreateBitmapIndirect`bitmap identificados pelo primeiro parâmetro do bitmap criado por .

Quando terminar com `CBitmap` o objeto `CreateBitmapIndirect` criado com função, primeiro selecione o bitmap fora do contexto do dispositivo e, em seguida, exclua o `CBitmap` objeto.

## <a name="cbitmapcreatecompatiblebitmap"></a><a name="createcompatiblebitmap"></a>CBitmap::CreateCompatibleBitmap

Inicializa um bitmap compatível com o dispositivo especificado pelo *pDC*.

```
BOOL CreateCompatibleBitmap(
    CDC* pDC,
    int nWidth,
    int nHeight);
```

### <a name="parameters"></a>Parâmetros

*pDC*<br/>
Especifica o contexto do dispositivo.

*Nwidth*<br/>
Especifica a largura (em pixels) do bitmap.

*Nheight*<br/>
Especifica a altura (em pixels) do bitmap.

### <a name="return-value"></a>Valor retornado

Não zero se bem sucedido; caso contrário, 0.

### <a name="remarks"></a>Comentários

O bitmap tem o mesmo número de planos de cores ou o mesmo formato bits por pixel do contexto do dispositivo especificado. Ele pode ser selecionado como o bitmap atual para qualquer dispositivo de memória compatível com o especificado pelo *pDC*.

Se *pDC* é um contexto de dispositivo de memória, o bitmap retornado tem o mesmo formato do bitmap selecionado no contexto do dispositivo. Um "contexto do dispositivo de memória" é um bloco de memória que representa uma superfície de exibição. Ele pode ser usado para preparar imagens na memória antes de copiá-las para a superfície real de exibição do dispositivo compatível.

Quando um contexto de dispositivo de memória é criado, o GDI seleciona automaticamente um bitmap de estoque monocromático para ele.

Uma vez que um contexto de dispositivo de memória de cor pode ter bitmaps coloridos ou monocromáticos selecionados, o formato do bitmap retornado pela `CreateCompatibleBitmap` função nem sempre é o mesmo; no entanto, o formato de um bitmap compatível para um contexto de dispositivo sem memória está sempre no formato do dispositivo.

Quando terminar com `CBitmap` o objeto `CreateCompatibleBitmap` criado com a função, primeiro selecione o `CBitmap` bitmap fora do contexto do dispositivo e, em seguida, exclua o objeto.

## <a name="cbitmapcreatediscardablebitmap"></a><a name="creatediscardablebitmap"></a>CBitmap::CreateDiscardableBitmap

Inicializa um bitmap descartável compatível com o contexto do dispositivo identificado pelo *pDC*.

```
BOOL CreateDiscardableBitmap(
    CDC* pDC,
    int nWidth,
    int nHeight);
```

### <a name="parameters"></a>Parâmetros

*pDC*<br/>
Especifica um contexto do dispositivo.

*Nwidth*<br/>
Especifica a largura (em bits) do bitmap.

*Nheight*<br/>
Especifica a altura (em bits) do bitmap.

### <a name="return-value"></a>Valor retornado

Não zero se bem sucedido; caso contrário, 0.

### <a name="remarks"></a>Comentários

O bitmap tem o mesmo número de planos de cores ou o mesmo formato bits por pixel do contexto do dispositivo especificado. Um aplicativo pode selecionar este bitmap como o bitmap atual para um dispositivo de memória compatível com o especificado pelo *pDC*.

O Windows pode descartar um bitmap criado por essa função somente se um aplicativo não o tiver selecionado em um contexto de exibição. Se o Windows descartar o bitmap quando ele não estiver selecionado e o aplicativo tentar selecioná-lo posteriormente, a função [CDC::SelectObject](../../mfc/reference/cdc-class.md#selectobject) retornará NULL.

Quando terminar com `CBitmap` o objeto `CreateDiscardableBitmap` criado com a função, primeiro selecione o `CBitmap` bitmap fora do contexto do dispositivo e, em seguida, exclua o objeto.

## <a name="cbitmapfromhandle"></a><a name="fromhandle"></a>CBitmap::FromHandle

Retorna um ponteiro `CBitmap` para um objeto quando dado uma alça a um bitmap GDI do Windows.

```
static CBitmap* PASCAL FromHandle(HBITMAP hBitmap);
```

### <a name="parameters"></a>Parâmetros

*Hbitmap*<br/>
Especifica um bitmap Windows GDI.

### <a name="return-value"></a>Valor retornado

Um ponteiro `CBitmap` para um objeto se for bem sucedido; caso contrário, NULL.

### <a name="remarks"></a>Comentários

Se `CBitmap` um objeto ainda não estiver conectado `CBitmap` à alça, um objeto temporário será criado e anexado. Este `CBitmap` objeto temporário só é válido até a próxima vez que o aplicativo tiver tempo ocioso em seu loop de evento, momento em que todos os objetos gráficos temporários são excluídos. Outra maneira de dizer isso é que o objeto temporário só é válido durante o processamento de uma mensagem de janela.

## <a name="cbitmapgetbitmap"></a><a name="getbitmap"></a>CBitmap::GetBitmap

Recupera propriedades de imagem para o bitmap anexado.

```
int GetBitmap(BITMAP* pBitMap);
```

### <a name="parameters"></a>Parâmetros

*Pbitmap*<br/>
Pointer para uma estrutura [BITMAP](/windows/win32/api/wingdi/ns-wingdi-bitmap) que receberá as propriedades da imagem. Este parâmetro não deve ser NULO.

### <a name="return-value"></a>Valor retornado

Não zero se o método foi bem sucedido; caso contrário, 0.

### <a name="remarks"></a>Comentários

## <a name="cbitmapgetbitmapbits"></a><a name="getbitmapbits"></a>CBitmap::GetBitmapBits

Copia o padrão de bits do bitmap anexado no buffer especificado.

```
DWORD GetBitmapBits(
    DWORD dwCount,
    LPVOID lpBits) const;
```

### <a name="parameters"></a>Parâmetros

*Dwcount*<br/>
O número de bytes a serem copiados no buffer.

*Lpbits*<br/>
Ponteiro para o buffer que receberá o bitmap.

### <a name="return-value"></a>Valor retornado

O número de bytes copiados para o buffer se o método foi bem sucedido; caso contrário, 0.

### <a name="remarks"></a>Comentários

Use [CBitmap::GetBitmap](#getbitmap) para determinar o tamanho de buffer necessário.

## <a name="cbitmapgetbitmapdimension"></a><a name="getbitmapdimension"></a>CBitmap::GetBitmapDimension

Retorna a largura e a altura do bitmap.

```
CSize GetBitmapDimension() const;
```

### <a name="return-value"></a>Valor retornado

A largura e altura do bitmap, medido susterem unidades de 0,1 milímetros. A altura está `cy` no `CSize` membro do objeto, e `cx` a largura está no membro. Se a largura e a altura do `SetBitmapDimension`bitmap não tiverem sido definidas usando, o valor de retorno será 0.

### <a name="remarks"></a>Comentários

Presume-se que a altura e a largura tenham sido definidas anteriormente usando a função de membro [SetBitmapDimension.](#setbitmapdimension)

## <a name="cbitmaploadbitmap"></a><a name="loadbitmap"></a>CBitmap::LoadBitmap

Carrega o recurso bitmap nomeado por *lpszResourceName* ou identificado pelo número de Identificação no *nIDResource* do arquivo executável do aplicativo.

```
BOOL LoadBitmap(LPCTSTR lpszResourceName);
BOOL LoadBitmap(UINT nIDResource);
```

### <a name="parameters"></a>Parâmetros

*Lpszresourcename*<br/>
Aponta para uma seqüência de terminadas nula que contém o nome do recurso bitmap.

*Nidresource*<br/>
Especifica o número de ID de recurso do recurso bitmap.

### <a name="return-value"></a>Valor retornado

Não zero se bem sucedido; caso contrário, 0.

### <a name="remarks"></a>Comentários

O bitmap carregado é anexado ao `CBitmap` objeto.

Se o bitmap identificado por *lpszResourceName* não existir ou se houver memória insuficiente para carregar o bitmap, a função reame 2.

Você pode usar a função [CGdiObject::DeleteObject](../../mfc/reference/cgdiobject-class.md#deleteobject) para `LoadBitmap` excluir bitmap `CBitmap` carregado pela função, ou o destruidor excluirá o objeto para você.

> [!CAUTION]
> Antes de excluir o objeto, certifique-se de que ele não está selecionado em um contexto do dispositivo.

Os seguintes bitmaps foram adicionados às versões 3.1 do Windows e posteriores:

OBM_UPARRROWIOBM_DNARROWIOBM_RGARROWIOBM_LFARROWI

Esses bitmaps não são encontrados em drivers de dispositivos para as versões 3.0 do Windows e anteriores. Para obter uma lista completa de bitmaps e uma exibição de sua aparência, consulte o Windows SDK.

## <a name="cbitmaploadmappedbitmap"></a><a name="loadmappedbitmap"></a>CBitmap:LoadMappedBitmap

Ligue para esta função de membro para carregar um bitmap e mapear as cores para as cores atuais do sistema.

```
BOOL LoadMappedBitmap(
    UINT nIDBitmap,
    UINT nFlags = 0,
    LPCOLORMAP lpColorMap = NULL,
    int nMapSize = 0);
```

### <a name="parameters"></a>Parâmetros

*nIDBitmap*<br/>
O ID do recurso bitmap.

*Nflags*<br/>
Uma bandeira para um mapa. Pode ser zero ou CMB_MASKED.

*lpColorMap*<br/>
Um ponteiro `COLORMAP` para uma estrutura que contém as informações de cores necessárias para mapear os bitmaps. Se este parâmetro for NULO, a função usará o mapa de cores padrão.

*nMapSize*<br/>
O número de mapas de cores apontados por *lpColorMap*.

### <a name="return-value"></a>Valor retornado

Não zero se bem sucedido; caso contrário, 0.

### <a name="remarks"></a>Comentários

Por padrão, `LoadMappedBitmap` mapeará cores comumente usadas em glifos de botão.

Para obter informações sobre como criar um bitmap mapeado, consulte a função do Windows [CreateMappedBitmap](https://go.microsoft.com/fwlink/p/?linkid=230562) e a estrutura [COLORMAP](/windows/win32/api/commctrl/ns-commctrl-colormap) no SDK do Windows.

## <a name="cbitmaploadoembitmap"></a><a name="loadoembitmap"></a>CBitmap::LoadOEMBitmap

Carrega um bitmap predefinido usado pelo Windows.

```
BOOL LoadOEMBitmap(UINT nIDBitmap);
```

### <a name="parameters"></a>Parâmetros

*nIDBitmap*<br/>
Número de id do bitmap predefinido do Windows. Os possíveis valores estão listados abaixo do WINDOWS. H:

|||
|-|-|
|OBM_BTNCORNERS|OBM_OLD_RESTORE|
|OBM_BTSIZE|OBM_OLD_RGARROW|
|OBM_CHECK|OBM_OLD_UPARROW|
|OBM_CHECKBOXES|OBM_OLD_ZOOM|
|OBM_CLOSE|OBM_REDUCE|
|OBM_COMBO|OBM_REDUCED|
|OBM_DNARROW|OBM_RESTORE|
|OBM_DNARROWD|OBM_RESTORED|
|OBM_DNARROWI|OBM_RGARROW|
|OBM_LFARROW|OBM_RGARROWD|
|OBM_LFARROWD|OBM_RGARROWI|
|OBM_LFARROWI|OBM_SIZE|
|OBM_MNARROW|OBM_UPARROW|
|OBM_OLD_CLOSE|OBM_UPARROWD|
|OBM_OLD_DNARROW|OBM_UPARROW|
|OBM_OLD_LFARROW|OBM_ZOOM|
|OBM_OLD_REDUCE|OBM_ZOOMD|

### <a name="return-value"></a>Valor retornado

Não zero se bem sucedido; caso contrário, 0.

### <a name="remarks"></a>Comentários

Os nomes do Bitmap que começam com OBM_OLD representam bitmaps usados pelas versões do Windows antes do 3.0.

Observe que o OEMRESOURCE constante deve ser definido antes de incluir o WINDOWS. H para usar qualquer uma das **constantes OBM_.**

## <a name="cbitmapoperator-hbitmap"></a><a name="operator_hbitmap"></a>CBitmap::operador HBITMAP

Use este operador para obter a alça `CBitmap` Windows GDI anexada do objeto.

```
operator HBITMAP() const;
```

### <a name="return-value"></a>Valor retornado

Se for bem-sucedido, uma alça para `CBitmap` o objeto GDI do Windows representado pelo objeto; caso contrário, NULL.

### <a name="remarks"></a>Comentários

Este operador é um operador de fundição, que suporta o uso direto de um `HBITMAP` objeto.

Para obter mais informações sobre o uso de objetos gráficos, consulte [Objetos Gráficos](/windows/win32/gdi/graphic-objects) no SDK do Windows.

## <a name="cbitmapsetbitmapbits"></a><a name="setbitmapbits"></a>CBitmap::SetBitmapBits

Define os bits de um bitmap para os valores de bits dados pelos *lpBits*.

```
DWORD SetBitmapBits(
    DWORD dwCount,
    const void* lpBits);
```

### <a name="parameters"></a>Parâmetros

*Dwcount*<br/>
Especifica o número de bytes apontados por *lpBits*.

*Lpbits*<br/>
Aponta para a matriz BYTE que contém os `CBitmap` valores de pixel a serem copiados para o objeto. Para que o bitmap possa renderizar sua imagem corretamente, os valores devem ser formatados para se adequar aos valores de altura, largura e profundidade de cor que foram especificados quando a instância cBitmap foi criada. Para obter mais informações, consulte [CBitmap::CreateBitmap](#createbitmap).

### <a name="return-value"></a>Valor retornado

O número de bytes usados na definição dos bits do bitmap; 0 se a função falhar.

## <a name="cbitmapsetbitmapdimension"></a><a name="setbitmapdimension"></a>CBitmap::SetBitmapDimension

Atribui uma largura e altura a um bitmap em unidades de 0,1 milímetros.

```
CSize SetBitmapDimension(
    int nWidth,
    int nHeight);
```

### <a name="parameters"></a>Parâmetros

*Nwidth*<br/>
Especifica a largura do bitmap (em unidades de 0,1 milímetros).

*Nheight*<br/>
Especifica a altura do bitmap (em unidades de 0,1 milímetros).

### <a name="return-value"></a>Valor retornado

As dimensões anteriores do bitmap. A altura `cy` está na `CSize` variável membro do objeto, e a largura está na `cx` variável membro.

### <a name="remarks"></a>Comentários

O GDI não usa esses valores, exceto para devolvê-los quando um aplicativo chama a função membro [GetBitmapDimension.](#getbitmapdimension)

## <a name="see-also"></a>Confira também

[MDI amostra MFC](../../overview/visual-cpp-samples.md)<br/>
[Classe CGdiObject](../../mfc/reference/cgdiobject-class.md)<br/>
[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)
