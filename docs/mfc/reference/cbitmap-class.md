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
ms.openlocfilehash: 8c19a54584390312cfd1657e88898cdb044179d0
ms.sourcegitcommit: d77159732a8e782b2a1b7abea552065f2b6f61c1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 11/04/2020
ms.locfileid: "93344573"
---
# <a name="cbitmap-class"></a>Classe CBitmap

Encapsula um bitmap da interface de dispositivo gráfico do Windows (GDI) e fornece funções de membro para manipular o bitmap.

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
|[CBitmap:: CreateBitmap](#createbitmap)|Inicializa o objeto com um bitmap de memória dependente de dispositivo que tem uma largura, altura e padrão de bits especificados.|
|[CBitmap::CreateBitmapIndirect](#createbitmapindirect)|Inicializa o objeto com um bitmap com a largura, a altura e o padrão de bits (se um for especificado) fornecido em uma `BITMAP` estrutura.|
|[CBitmap::CreateCompatibleBitmap](#createcompatiblebitmap)|Inicializa o objeto com um bitmap para que ele seja compatível com um dispositivo especificado.|
|[CBitmap::CreateDiscardableBitmap](#creatediscardablebitmap)|Inicializa o objeto com um bitmap Descartado que é compatível com um dispositivo especificado.|
|[CBitmap:: FromHandle](#fromhandle)|Retorna um ponteiro para um `CBitmap` objeto quando um identificador é fornecido a um `HBITMAP` bitmap do Windows.|
|[CBitmap:: getbitmap](#getbitmap)|Preenche uma `BITMAP` estrutura com informações sobre o bitmap.|
|[CBitmap::GetBitmapBits](#getbitmapbits)|Copia os bits do bitmap especificado no buffer especificado.|
|[CBitmap::GetBitmapDimension](#getbitmapdimension)|Retorna a largura e a altura do bitmap. Presume-se que a altura e a largura foram definidas anteriormente pela função membro [SetBitmapDimension](#setbitmapdimension) .|
|[CBitmap:: LoadBitmap](#loadbitmap)|Inicializa o objeto carregando um recurso de bitmap nomeado do arquivo executável do aplicativo e anexando o bitmap ao objeto.|
|[CBitmap::LoadMappedBitmap](#loadmappedbitmap)|Carrega um bitmap e mapeia as cores para as cores atuais do sistema.|
|[CBitmap::LoadOEMBitmap](#loadoembitmap)|Inicializa o objeto carregando um bitmap do Windows predefinido e anexando o bitmap ao objeto.|
|[CBitmap::SetBitmapBits](#setbitmapbits)|Define os bits de um bitmap para os valores de bits especificados.|
|[CBitmap::SetBitmapDimension](#setbitmapdimension)|Atribui uma largura e uma altura a um bitmap em unidades de 0,1 milímetros.|

### <a name="public-operators"></a>Operadores públicos

|Nome|Descrição|
|----------|-----------------|
|[Operador CBitmap:: Operator HBITMAP](#operator_hbitmap)|Retorna o identificador do Windows anexado ao `CBitmap` objeto.|

## <a name="remarks"></a>Comentários

Para usar um `CBitmap` objeto, construa o objeto, anexe um identificador de bitmap a ele com uma das funções de membro de inicialização e, em seguida, chame as funções de membro do objeto.

Para obter mais informações sobre como usar objetos gráficos como `CBitmap` , consulte [objetos gráficos](../../mfc/graphic-objects.md).

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[CObject](../../mfc/reference/cobject-class.md)

[CGdiObject](../../mfc/reference/cgdiobject-class.md)

`CBitmap`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** Afxwin. h

## <a name="cbitmapcbitmap"></a><a name="cbitmap"></a> CBitmap::CBitmap

Constrói um objeto `CBitmap`.

```
CBitmap();
```

### <a name="remarks"></a>Comentários

O objeto resultante deve ser inicializado com uma das funções de membro de inicialização.

## <a name="cbitmapcreatebitmap"></a><a name="createbitmap"></a> CBitmap:: CreateBitmap

Inicializa um bitmap de memória dependente de dispositivo que tem a largura, a altura e o padrão de bit especificados.

```
BOOL CreateBitmap(
    int nWidth,
    int nHeight,
    UINT nPlanes,
    UINT nBitcount,
    const void* lpBits);
```

### <a name="parameters"></a>Parâmetros

*nWidth*<br/>
Especifica a largura (em pixels) do bitmap.

*nHeight*<br/>
Especifica a altura (em pixels) do bitmap.

*nPlanes*<br/>
Especifica o número de planos de cores no bitmap.

*nBitcount*<br/>
Especifica o número de bits de cor por pixel de exibição.

*lpBits*<br/>
Aponta para uma matriz de bytes que contém os valores de bits de bitmap iniciais. Se for NULL, o novo bitmap será deixado como não inicializado.

### <a name="return-value"></a>Valor Retornado

Diferente de zero, se for bem-sucedido; caso contrário, 0.

### <a name="remarks"></a>Comentários

Para um bitmap de cor, o parâmetro *nPlanes* ou *nBitcount* deve ser definido como 1. Se ambos os parâmetros estiverem definidos como 1, `CreateBitmap` o criará um bitmap monocromático.

Embora um bitmap não possa ser selecionado diretamente para um dispositivo de vídeo, ele pode ser selecionado como o bitmap atual para um "contexto de dispositivo de memória" usando [CDC:: SelectObject](../../mfc/reference/cdc-class.md#selectobject) e copiado para qualquer contexto de dispositivo compatível usando a função [CDC:: BitBlt](../../mfc/reference/cdc-class.md#bitblt) .

Quando terminar com o `CBitmap` objeto criado pela `CreateBitmap` função, primeiro selecione o bitmap fora do contexto do dispositivo e, em seguida, exclua o `CBitmap` objeto.

Para obter mais informações, consulte a descrição do `bmBits` campo na `BITMAP` estrutura. A estrutura de [bitmap](/windows/win32/api/wingdi/ns-wingdi-bitmap) é descrita na função de membro [CBitmap:: CreateBitmapIndirect](#createbitmapindirect) .

## <a name="cbitmapcreatebitmapindirect"></a><a name="createbitmapindirect"></a> CBitmap::CreateBitmapIndirect

Inicializa um bitmap que tem a largura, a altura e o padrão de bits (se um for especificado) fornecido na estrutura apontada por *lpBitmap*.

```
BOOL CreateBitmapIndirect(LPBITMAP lpBitmap);
```

### <a name="parameters"></a>Parâmetros

*lpBitmap*<br/>
Aponta para uma estrutura de [bitmap](/windows/win32/api/wingdi/ns-wingdi-bitmap) que contém informações sobre o bitmap.

### <a name="return-value"></a>Valor Retornado

Diferente de zero, se for bem-sucedido; caso contrário, 0.

### <a name="remarks"></a>Comentários

Embora um bitmap não possa ser selecionado diretamente para um dispositivo de vídeo, ele pode ser selecionado como o bitmap atual para um contexto de dispositivo de memória usando [CDC:: SelectObject](../../mfc/reference/cdc-class.md#selectobject) e copiado para qualquer contexto de dispositivo compatível usando a função [CDC:: BitBlt](../../mfc/reference/cdc-class.md#bitblt) ou [CDC:: StretchBlt](../../mfc/reference/cdc-class.md#stretchblt) . (A função [CDC::P atblt](../../mfc/reference/cdc-class.md#patblt) pode copiar o bitmap do pincel atual diretamente para o contexto do dispositivo de vídeo.)

Se a `BITMAP` estrutura apontada pelo parâmetro *lpBitmap* tiver sido preenchida usando a `GetObject` função, os bits do bitmap não serão especificados e o bitmap não será inicializado. Para inicializar o bitmap, um aplicativo pode usar uma função como [CDC:: BitBlt](../../mfc/reference/cdc-class.md#bitblt) ou [SetDIBits](/windows/win32/api/wingdi/nf-wingdi-setdibits) para copiar os bits do bitmap identificado pelo primeiro parâmetro de `CGdiObject::GetObject` para o bitmap criado pelo `CreateBitmapIndirect` .

Quando terminar com o `CBitmap` objeto criado com a `CreateBitmapIndirect` função, primeiro selecione o bitmap fora do contexto do dispositivo e, em seguida, exclua o `CBitmap` objeto.

## <a name="cbitmapcreatecompatiblebitmap"></a><a name="createcompatiblebitmap"></a> CBitmap::CreateCompatibleBitmap

Inicializa um bitmap compatível com o dispositivo especificado pelo *PDC*.

```
BOOL CreateCompatibleBitmap(
    CDC* pDC,
    int nWidth,
    int nHeight);
```

### <a name="parameters"></a>Parâmetros

*Primário*<br/>
Especifica o contexto do dispositivo.

*nWidth*<br/>
Especifica a largura (em pixels) do bitmap.

*nHeight*<br/>
Especifica a altura (em pixels) do bitmap.

### <a name="return-value"></a>Valor Retornado

Diferente de zero, se for bem-sucedido; caso contrário, 0.

### <a name="remarks"></a>Comentários

O bitmap tem o mesmo número de planos de cores ou o mesmo formato de bits por pixel que o contexto de dispositivo especificado. Ele pode ser selecionado como o bitmap atual para qualquer dispositivo de memória compatível com aquele especificado pelo *PDC*.

Se o *PDC* for um contexto de dispositivo de memória, o bitmap retornado terá o mesmo formato que o bitmap atualmente selecionado nesse contexto de dispositivo. Um "contexto de dispositivo de memória" é um bloco de memória que representa uma superfície de exibição. Ele pode ser usado para preparar imagens na memória antes de copiá-las para a superfície de exibição real do dispositivo compatível.

Quando um contexto de dispositivo de memória é criado, o GDI seleciona automaticamente um bitmap de estoque monocromático para ele.

Como um contexto de dispositivo de memória de cor pode ter bitmaps de cor ou monocromáticos selecionados, o formato do bitmap retornado pela `CreateCompatibleBitmap` função nem sempre é o mesmo; no entanto, o formato de um bitmap compatível para um contexto de dispositivo sem memória sempre está no formato do dispositivo.

Quando terminar com o `CBitmap` objeto criado com a `CreateCompatibleBitmap` função, primeiro selecione o bitmap fora do contexto do dispositivo e, em seguida, exclua o `CBitmap` objeto.

## <a name="cbitmapcreatediscardablebitmap"></a><a name="creatediscardablebitmap"></a> CBitmap::CreateDiscardableBitmap

Inicializa um bitmap Descartado que é compatível com o contexto do dispositivo identificado pelo *PDC*.

```
BOOL CreateDiscardableBitmap(
    CDC* pDC,
    int nWidth,
    int nHeight);
```

### <a name="parameters"></a>Parâmetros

*Primário*<br/>
Especifica um contexto de dispositivo.

*nWidth*<br/>
Especifica a largura (em bits) do bitmap.

*nHeight*<br/>
Especifica a altura (em bits) do bitmap.

### <a name="return-value"></a>Valor Retornado

Diferente de zero, se for bem-sucedido; caso contrário, 0.

### <a name="remarks"></a>Comentários

O bitmap tem o mesmo número de planos de cores ou o mesmo formato de bits por pixel que o contexto de dispositivo especificado. Um aplicativo pode selecionar esse bitmap como o bitmap atual para um dispositivo de memória compatível com aquele especificado pelo *PDC*.

O Windows pode descartar um bitmap criado por essa função somente se um aplicativo não o tiver selecionado em um contexto de exibição. Se o Windows descartar o bitmap quando ele não estiver selecionado e o aplicativo tentar selecioná-lo mais tarde, a função [CDC:: SelectObject](../../mfc/reference/cdc-class.md#selectobject) retornará NULL.

Quando terminar com o `CBitmap` objeto criado com a `CreateDiscardableBitmap` função, primeiro selecione o bitmap fora do contexto do dispositivo e, em seguida, exclua o `CBitmap` objeto.

## <a name="cbitmapfromhandle"></a><a name="fromhandle"></a> CBitmap:: FromHandle

Retorna um ponteiro para um `CBitmap` objeto quando um identificador para um bitmap GDI do Windows é fornecido.

```
static CBitmap* PASCAL FromHandle(HBITMAP hBitmap);
```

### <a name="parameters"></a>Parâmetros

*hBitmap*<br/>
Especifica um bitmap GDI do Windows.

### <a name="return-value"></a>Valor Retornado

Um ponteiro para um `CBitmap` objeto se for bem-sucedido; caso contrário, NULL.

### <a name="remarks"></a>Comentários

Se um `CBitmap` objeto ainda não estiver anexado ao identificador, um objeto temporário `CBitmap` será criado e anexado. Esse `CBitmap` objeto temporário é válido somente até a próxima vez que o aplicativo tiver tempo ocioso em seu loop de eventos, quando todos os objetos gráficos temporários forem excluídos. Outra maneira de dizer isso é que o objeto temporário só é válido durante o processamento de uma mensagem de janela.

## <a name="cbitmapgetbitmap"></a><a name="getbitmap"></a> CBitmap:: getbitmap

Recupera as propriedades da imagem para o bitmap anexado.

```
int GetBitmap(BITMAP* pBitMap);
```

### <a name="parameters"></a>Parâmetros

*pBitMap*<br/>
Ponteiro para uma estrutura de [bitmap](/windows/win32/api/wingdi/ns-wingdi-bitmap) que receberá as propriedades da imagem. Esse parâmetro não deve ser nulo.

### <a name="return-value"></a>Valor Retornado

Diferente de zero se o método foi bem-sucedido; caso contrário, 0.

### <a name="remarks"></a>Comentários

## <a name="cbitmapgetbitmapbits"></a><a name="getbitmapbits"></a> CBitmap::GetBitmapBits

Copia o padrão de bits do bitmap anexado no buffer especificado.

```
DWORD GetBitmapBits(
    DWORD dwCount,
    LPVOID lpBits) const;
```

### <a name="parameters"></a>Parâmetros

*dwCount*<br/>
O número de bytes a serem copiados no buffer.

*lpBits*<br/>
Ponteiro para o buffer que receberá o bitmap.

### <a name="return-value"></a>Valor Retornado

O número de bytes copiados para o buffer se o método foi bem-sucedido; caso contrário, 0.

### <a name="remarks"></a>Comentários

Use [CBitmap:: getbitmap](#getbitmap) para determinar o tamanho de buffer necessário.

## <a name="cbitmapgetbitmapdimension"></a><a name="getbitmapdimension"></a> CBitmap::GetBitmapDimension

Retorna a largura e a altura do bitmap.

```
CSize GetBitmapDimension() const;
```

### <a name="return-value"></a>Valor Retornado

A largura e a altura do bitmap, medidas em unidades de 0,1 milímetros. A altura está no `cy` membro do `CSize` objeto e a largura está no `cx` membro. Se a largura e a altura do bitmap não tiverem sido definidas usando `SetBitmapDimension` , o valor de retorno será 0.

### <a name="remarks"></a>Comentários

Presume-se que a altura e a largura foram definidas anteriormente usando a função de membro [SetBitmapDimension](#setbitmapdimension) .

## <a name="cbitmaploadbitmap"></a><a name="loadbitmap"></a> CBitmap:: LoadBitmap

Carrega o recurso de bitmap nomeado por *lpszResourceName* ou identificado pelo número de ID em *nIDResource* do arquivo executável do aplicativo.

```
BOOL LoadBitmap(LPCTSTR lpszResourceName);
BOOL LoadBitmap(UINT nIDResource);
```

### <a name="parameters"></a>Parâmetros

*lpszResourceName*<br/>
Aponta para uma cadeia de caracteres terminada em nulo que contém o nome do recurso de bitmap.

*nIDResource*<br/>
Especifica o número de ID de recurso do recurso de bitmap.

### <a name="return-value"></a>Valor Retornado

Diferente de zero, se for bem-sucedido; caso contrário, 0.

### <a name="remarks"></a>Comentários

O bitmap carregado é anexado ao `CBitmap` objeto.

Se o bitmap identificado por *lpszResourceName* não existir ou se não houver memória suficiente para carregar o bitmap, a função retornará 0.

Você pode usar a função [CGdiObject::D eleteobject](../../mfc/reference/cgdiobject-class.md#deleteobject) para excluir o bitmap carregado pela `LoadBitmap` função ou o `CBitmap` destruidor excluirá o objeto para você.

> [!CAUTION]
> Antes de excluir o objeto, verifique se ele não está selecionado em um contexto de dispositivo.

Os seguintes bitmaps foram adicionados ao Windows versões 3,1 e posteriores:

OBM_UPARRROWIOBM_DNARROWIOBM_RGARROWIOBM_LFARROWI

Esses bitmaps não foram encontrados em drivers de dispositivo para as versões 3,0 e anteriores do Windows. Para obter uma lista completa de bitmaps e uma exibição de sua aparência, consulte a SDK do Windows.

## <a name="cbitmaploadmappedbitmap"></a><a name="loadmappedbitmap"></a> CBitmap::LoadMappedBitmap

Chame essa função de membro para carregar um bitmap e mapear as cores para as cores atuais do sistema.

```
BOOL LoadMappedBitmap(
    UINT nIDBitmap,
    UINT nFlags = 0,
    LPCOLORMAP lpColorMap = NULL,
    int nMapSize = 0);
```

### <a name="parameters"></a>Parâmetros

*nIDBitmap*<br/>
A ID do recurso de bitmap.

*nFlags*<br/>
Um sinalizador para um bitmap. Pode ser zero ou CMB_MASKED.

*lpColorMap*<br/>
Um ponteiro para uma `COLORMAP` estrutura que contém as informações de cor necessárias para mapear os bitmaps. Se esse parâmetro for nulo, a função usará o mapa de cores padrão.

*nMapSize*<br/>
O número de mapas de cores apontados por *lpColorMap*.

### <a name="return-value"></a>Valor Retornado

Diferente de zero, se for bem-sucedido; caso contrário, 0.

### <a name="remarks"></a>Comentários

Por padrão, o `LoadMappedBitmap` mapeará as cores geralmente usadas em glifos de botão.

Para obter informações sobre como criar um bitmap mapeado, consulte a função do Windows [CreateMappedBitmap](/windows/win32/api/commctrl/nf-commctrl-createmappedbitmap) e a estrutura [ColorMap](/windows/win32/api/commctrl/ns-commctrl-colormap) no SDK do Windows.

## <a name="cbitmaploadoembitmap"></a><a name="loadoembitmap"></a> CBitmap::LoadOEMBitmap

Carrega um bitmap predefinido usado pelo Windows.

```
BOOL LoadOEMBitmap(UINT nIDBitmap);
```

### <a name="parameters"></a>Parâmetros

*nIDBitmap*<br/>
Número de ID do bitmap do Windows predefinido. Os valores possíveis estão listados abaixo do WINDOWS. T

:::row:::
   :::column span="":::
      OBM_BTNCORNERS \
      OBM_BTSIZE \
      OBM_CHECK \
      OBM_CHECKBOXES \
      OBM_CLOSE \
      OBM_COMBO \
      OBM_DNARROW \
      OBM_DNARROWD \
      OBM_DNARROWI \
      OBM_LFARROW \
      OBM_LFARROWD \
      OBM_LFARROWI
   :::column-end:::
   :::column span="":::
      OBM_MNARROW \
      OBM_OLD_CLOSE \
      OBM_OLD_DNARROW \
      OBM_OLD_LFARROW \
      OBM_OLD_REDUCE \
      OBM_OLD_RESTORE \
      OBM_OLD_RGARROW \
      OBM_OLD_UPARROW \
      OBM_OLD_ZOOM \
      OBM_REDUCE \
      OBM_REDUCED
   :::column-end:::
   :::column span="":::
      OBM_RESTORE \
      OBM_RESTORED \
      OBM_RGARROW \
      OBM_RGARROWD \
      OBM_RGARROWI \
      OBM_SIZE \
      OBM_UPARROW \
      OBM_UPARROW \
      OBM_UPARROWD \
      OBM_ZOOM \
      OBM_ZOOMD
   :::column-end:::
:::row-end:::

### <a name="return-value"></a>Valor Retornado

Diferente de zero, se for bem-sucedido; caso contrário, 0.

### <a name="remarks"></a>Comentários

Os nomes de bitmap que começam com OBM_OLD representam bitmaps usados pelas versões do Windows anteriores a 3,0.

Observe que a constante OEMRESOURCE deve ser definida antes de incluir o WINDOWS. H para usar qualquer uma das constantes de **OBM_** .

## <a name="cbitmapoperator-hbitmap"></a><a name="operator_hbitmap"></a> Operador CBitmap:: Operator HBITMAP

Use esse operador para obter o identificador GDI do Windows anexado do `CBitmap` objeto.

```
operator HBITMAP() const;
```

### <a name="return-value"></a>Valor Retornado

Se for bem-sucedido, um identificador para o objeto GDI do Windows representado pelo `CBitmap` objeto; caso contrário, NULL.

### <a name="remarks"></a>Comentários

Esse operador é um operador de conversão, que dá suporte ao uso direto de um `HBITMAP` objeto.

Para obter mais informações sobre como usar objetos gráficos, consulte [objetos gráficos](/windows/win32/gdi/graphic-objects) na SDK do Windows.

## <a name="cbitmapsetbitmapbits"></a><a name="setbitmapbits"></a> CBitmap::SetBitmapBits

Define os bits de um bitmap para os valores de bits fornecidos por *lpBits*.

```
DWORD SetBitmapBits(
    DWORD dwCount,
    const void* lpBits);
```

### <a name="parameters"></a>Parâmetros

*dwCount*<br/>
Especifica o número de bytes apontados por *lpBits*.

*lpBits*<br/>
Aponta para a matriz de bytes que contém os valores de pixel a serem copiados para o `CBitmap` objeto. Para que o bitmap possa renderizar sua imagem corretamente, os valores devem ser formatados de acordo com os valores de altura, largura e profundidade de cor que foram especificados quando a instância CBitmap foi criada. Para obter mais informações, consulte [CBitmap:: CreateBitmap](#createbitmap).

### <a name="return-value"></a>Valor Retornado

O número de bytes usados na configuração dos bits de bitmap; 0 se a função falhar.

## <a name="cbitmapsetbitmapdimension"></a><a name="setbitmapdimension"></a> CBitmap::SetBitmapDimension

Atribui uma largura e uma altura a um bitmap em unidades de 0,1 milímetros.

```
CSize SetBitmapDimension(
    int nWidth,
    int nHeight);
```

### <a name="parameters"></a>Parâmetros

*nWidth*<br/>
Especifica a largura do bitmap (em unidades de 0,1 a milímetros).

*nHeight*<br/>
Especifica a altura do bitmap (em unidades de 0,1 a milímetros).

### <a name="return-value"></a>Valor Retornado

As dimensões de bitmap anteriores. A altura está na `cy` variável de membro do `CSize` objeto e a largura está na `cx` variável de membro.

### <a name="remarks"></a>Comentários

O GDI não usa esses valores, exceto para retorná-los quando um aplicativo chama a função de membro [GetBitmapDimension](#getbitmapdimension) .

## <a name="see-also"></a>Confira também

[MDI de exemplo do MFC](../../overview/visual-cpp-samples.md)<br/>
[Classe CGdiObject](../../mfc/reference/cgdiobject-class.md)<br/>
[Gráfico de hierarquia](../../mfc/hierarchy-chart.md)
