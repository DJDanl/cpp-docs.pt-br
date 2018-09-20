---
title: Classe CBitmap | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: reference
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
dev_langs:
- C++
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
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 322b13ee62e61a836d6b0c66ab619a11348adeae
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46375635"
---
# <a name="cbitmap-class"></a>Classe CBitmap

Encapsula um bitmap de interface (GDI) do dispositivo de gráficos Windows e fornece funções de membro para manipular o bitmap.

## <a name="syntax"></a>Sintaxe

```
class CBitmap : public CGdiObject
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores Públicos

|Nome|Descrição|
|----------|-----------------|
|[CBitmap::CBitmap](#cbitmap)|Constrói um objeto `CBitmap`.|

### <a name="public-methods"></a>Métodos Públicos

|Nome|Descrição|
|----------|-----------------|
|[CBitmap::CreateBitmap](#createbitmap)|Inicializa o objeto com um bitmap dependente de dispositivo de memória que tem uma largura especificada, a altura e o padrão de bit.|
|[CBitmap::CreateBitmapIndirect](#createbitmapindirect)|Inicializa o objeto com um bitmap com a largura, altura e padrão de bit (se uma for especificada) fornecido em um `BITMAP` estrutura.|
|[CBitmap::CreateCompatibleBitmap](#createcompatiblebitmap)|Inicializa o objeto com um bitmap para que ele seja compatível com um dispositivo especificado.|
|[CBitmap::CreateDiscardableBitmap](#creatediscardablebitmap)|Inicializa o objeto com um bitmap descartável que é compatível com um dispositivo especificado.|
|[CBitmap::FromHandle](#fromhandle)|Retorna um ponteiro para um `CBitmap` do objeto quando é fornecido um identificador para um Windows `HBITMAP` bitmap.|
|[CBitmap::GetBitmap](#getbitmap)|Preenche um `BITMAP` estrutura com informações sobre o bitmap.|
|[CBitmap::GetBitmapBits](#getbitmapbits)|Copia os bits do bitmap especificado no buffer especificado.|
|[CBitmap::GetBitmapDimension](#getbitmapdimension)|Retorna a largura e altura do bitmap. A altura e largura são considerados tiver sido definido anteriormente o [SetBitmapDimension](#setbitmapdimension) função de membro.|
|[CBitmap::LoadBitmap](#loadbitmap)|Inicializa o objeto de carregamento de um recurso de bitmap nomeado do arquivo executável do aplicativo e anexando o bitmap para o objeto.|
|[CBitmap::LoadMappedBitmap](#loadmappedbitmap)|Carrega um bitmap e mapeia as cores para as cores do sistema atual.|
|[CBitmap::LoadOEMBitmap](#loadoembitmap)|Inicializa o objeto de carregamento de um bitmap do Windows predefinido e anexando o bitmap ao objeto.|
|[CBitmap::SetBitmapBits](#setbitmapbits)|Define os bits de um bitmap com os valores de bit especificado.|
|[CBitmap::SetBitmapDimension](#setbitmapdimension)|Atribui uma largura e altura em um bitmap em unidades de 0,1 milímetro.|

### <a name="public-operators"></a>Operadores públicos

|Nome|Descrição|
|----------|-----------------|
|[CBitmap::operator HBITMAP](#operator_hbitmap)|Retorna o identificador do Windows anexado ao `CBitmap` objeto.|

## <a name="remarks"></a>Comentários

Para usar um `CBitmap` do objeto, construir o objeto, anexe um identificador de bitmap a ele com uma das funções de membro de inicialização e chamar funções de membro do objeto.

Para obter mais informações sobre como usar objetos gráficos, como `CBitmap`, consulte [objetos de gráfico](../../mfc/graphic-objects.md).

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[CObject](../../mfc/reference/cobject-class.md)

[CGdiObject](../../mfc/reference/cgdiobject-class.md)

`CBitmap`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxwin. h

##  <a name="cbitmap"></a>  CBitmap::CBitmap

Constrói um objeto `CBitmap`.

```
CBitmap();
```

### <a name="remarks"></a>Comentários

O objeto resultante deve ser inicializado com uma das funções de membro de inicialização.

##  <a name="createbitmap"></a>  CBitmap::CreateBitmap

Inicializa um bitmap dependente de dispositivo de memória que tem o padrão de bit, altura e largura especificadas.

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
Especifica o número de bits de cores por pixel de exibição.

*lpBits*<br/>
Aponta para uma matriz de bytes que contém os valores de bit de bitmap inicial. Se for NULL, o novo bitmap for deixado não inicializado.

### <a name="return-value"></a>Valor de retorno

Diferente de zero se bem-sucedido; Caso contrário, 0.

### <a name="remarks"></a>Comentários

Para um bitmap de cor, ambos os *nPlanes* ou *nBitcount* parâmetro deve ser definido como 1. Se ambos os parâmetros são definidos como 1, `CreateBitmap` cria um bitmap monocromático.

Embora um bitmap não pode ser selecionado diretamente para um dispositivo de vídeo, ele pode ser selecionado como o bitmap atual para um contexto de dispositivo"memória" usando [CDC::SelectObject](../../mfc/reference/cdc-class.md#selectobject) e copiados para qualquer contexto de dispositivo compatíveis usando o [CDC::BitBlt](../../mfc/reference/cdc-class.md#bitblt) função.

Quando você terminar com o `CBitmap` objeto criado pelo `CreateBitmap` funcionar, primeiro selecione o bitmap fora do contexto de dispositivo e excluir o `CBitmap` objeto.

Para obter mais informações, consulte a descrição do `bmBits` campo o `BITMAP` estrutura. O [BITMAP](../../mfc/reference/bitmap-structure.md) estrutura é descrita na [CBitmap::CreateBitmapIndirect](#createbitmapindirect) função de membro.

##  <a name="createbitmapindirect"></a>  CBitmap::CreateBitmapIndirect

Inicializa um bitmap que possui a largura, altura e padrão de bit (se uma for especificada) fornecidas na estrutura apontada por *lpBitmap*.

```
BOOL CreateBitmapIndirect(LPBITMAP lpBitmap);
```

### <a name="parameters"></a>Parâmetros

*lpBitmap*<br/>
Aponta para um [BITMAP](../../mfc/reference/bitmap-structure.md) estrutura que contém informações sobre o bitmap.

### <a name="return-value"></a>Valor de retorno

Diferente de zero se bem-sucedido; Caso contrário, 0.

### <a name="remarks"></a>Comentários

Embora um bitmap não pode ser selecionado diretamente para um dispositivo de vídeo, ele pode ser selecionado como o bitmap atual para um contexto de dispositivo de memória usando [CDC::SelectObject](../../mfc/reference/cdc-class.md#selectobject) e copiados para qualquer contexto de dispositivo compatíveis usando o [CDC::BitBlt](../../mfc/reference/cdc-class.md#bitblt) ou [CDC::StretchBlt](../../mfc/reference/cdc-class.md#stretchblt) função. (O [CDC::PatBlt](../../mfc/reference/cdc-class.md#patblt) função pode copiar o bitmap do pincel atual diretamente para o contexto de dispositivo de exibição.)

Se o `BITMAP` estrutura apontada pela *lpBitmap* parâmetro tiver sido preenchido usando o `GetObject` função, os bits de bitmap não forem especificados e o bitmap não foi inicializado. Para inicializar o bitmap, um aplicativo pode usar uma função, como [CDC::BitBlt](../../mfc/reference/cdc-class.md#bitblt) ou [SetDIBits](/windows/desktop/api/wingdi/nf-wingdi-setdibits) para copiar os bits de bitmap identificado pelo primeiro parâmetro do `CGdiObject::GetObject` no bitmap criado por `CreateBitmapIndirect`.

Quando você terminar com o `CBitmap` objeto criado com `CreateBitmapIndirect` funcionar, primeiro selecione o bitmap fora do contexto de dispositivo e excluir o `CBitmap` objeto.

##  <a name="createcompatiblebitmap"></a>  CBitmap::CreateCompatibleBitmap

Inicializa um bitmap que é compatível com o dispositivo especificado pelo *pDC*.

```
BOOL CreateCompatibleBitmap(
    CDC* pDC,
    int nWidth,
    int nHeight);
```

### <a name="parameters"></a>Parâmetros

*pDC*<br/>
Especifica o contexto de dispositivo.

*nWidth*<br/>
Especifica a largura (em pixels) do bitmap.

*nHeight*<br/>
Especifica a altura (em pixels) do bitmap.

### <a name="return-value"></a>Valor de retorno

Diferente de zero se bem-sucedido; Caso contrário, 0.

### <a name="remarks"></a>Comentários

O bitmap tem o mesmo número de planos de cores ou o mesmo formato de bits por pixel como o contexto de dispositivo especificado. Ele pode ser selecionado como o bitmap atual para qualquer dispositivo de memória que é compatível com aquele especificado pelo *pDC*.

Se *pDC* é um contexto de dispositivo de memória, o bitmap retornado tem o mesmo formato que o bitmap selecionado no momento nesse contexto de dispositivo. Um contexto de dispositivo"memória" é um bloco de memória que representa uma superfície de exibição. Ele pode ser usado para preparar imagens na memória antes de copiá-los para a superfície de exibição real do dispositivo compatível.

Quando um contexto de dispositivo de memória é criado, GDI seleciona automaticamente um bitmap monocromático de estoque para ele.

Como um contexto de dispositivo de memória de cor pode ter cores ou bitmaps monocromático selecionado, o formato do bitmap retornado pela `CreateCompatibleBitmap` função nem sempre é o mesmo; no entanto, o formato de um bitmap compatível para um contexto de dispositivo nonmemory estará sempre no formato do dispositivo.

Quando você terminar com o `CBitmap` objeto criado com o `CreateCompatibleBitmap` funcionar, primeiro selecione o bitmap fora do contexto de dispositivo e excluir o `CBitmap` objeto.

##  <a name="creatediscardablebitmap"></a>  CBitmap::CreateDiscardableBitmap

Inicializa um bitmap descartável que é compatível com o contexto de dispositivo identificado por *pDC*.

```
BOOL CreateDiscardableBitmap(
    CDC* pDC,
    int nWidth,
    int nHeight);
```

### <a name="parameters"></a>Parâmetros

*pDC*<br/>
Especifica um contexto de dispositivo.

*nWidth*<br/>
Especifica a largura (em bits) do bitmap.

*nHeight*<br/>
Especifica a altura (em bits) do bitmap.

### <a name="return-value"></a>Valor de retorno

Diferente de zero se bem-sucedido; Caso contrário, 0.

### <a name="remarks"></a>Comentários

O bitmap tem o mesmo número de planos de cores ou o mesmo formato de bits por pixel como o contexto de dispositivo especificado. Um aplicativo pode selecionar esse bitmap como o bitmap atual para um dispositivo de memória que é compatível com aquele especificado pelo *pDC*.

Windows podem descartar um bitmap criado por essa função somente se não tiver selecionado um aplicativo em um contexto de exibição. Se o Windows descarta o bitmap quando ele não está selecionado e o aplicativo mais tarde tenta selecioná-la, o [CDC::SelectObject](../../mfc/reference/cdc-class.md#selectobject) a função retornará NULL.

Quando você terminar com o `CBitmap` objeto criado com o `CreateDiscardableBitmap` funcionar, primeiro selecione o bitmap fora do contexto de dispositivo e excluir o `CBitmap` objeto.

##  <a name="fromhandle"></a>  CBitmap::FromHandle

Retorna um ponteiro para um `CBitmap` objeto quando recebe um identificador para um bitmap GDI do Windows.

```
static CBitmap* PASCAL FromHandle(HBITMAP hBitmap);
```

### <a name="parameters"></a>Parâmetros

*hBitmap*<br/>
Especifica um bitmap GDI do Windows.

### <a name="return-value"></a>Valor de retorno

Um ponteiro para um `CBitmap` objeto se for bem-sucedido; caso contrário, NULL.

### <a name="remarks"></a>Comentários

Se um `CBitmap` objeto já não está anexado ao identificador, um temporário `CBitmap` objeto é criado e anexado. Esse temporário `CBitmap` objeto é válido somente até a próxima vez que o aplicativo tem tempo ocioso em seu loop de eventos, em que ponto o gráfico temporário todos os objetos são excluídos. Outra maneira de dizer isso é que o objeto temporário só é válido durante o processamento de mensagem em uma janela.

##  <a name="getbitmap"></a>  CBitmap::GetBitmap

Recupera as propriedades da imagem de bitmap anexado.

```
int GetBitmap(BITMAP* pBitMap);
```

### <a name="parameters"></a>Parâmetros

*pBitMap*<br/>
Ponteiro para um [estrutura de BITMAP](../../mfc/reference/bitmap-structure.md) estrutura que receberá as propriedades da imagem. Esse parâmetro não deve ser NULL.

### <a name="return-value"></a>Valor de retorno

Diferente de zero se o método foi bem-sucedida; Caso contrário, 0.

### <a name="remarks"></a>Comentários

##  <a name="getbitmapbits"></a>  CBitmap::GetBitmapBits

Copia o padrão de bits do bitmap anexado para o buffer especificado.

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

### <a name="return-value"></a>Valor de retorno

O número de bytes copiados para o buffer se o método foi bem-sucedida; Caso contrário, 0.

### <a name="remarks"></a>Comentários

Use [CBitmap::GetBitmap](#getbitmap) para determinar o tamanho do buffer necessário.

##  <a name="getbitmapdimension"></a>  CBitmap::GetBitmapDimension

Retorna a largura e altura do bitmap.

```
CSize GetBitmapDimension() const;
```

### <a name="return-value"></a>Valor de retorno

A largura e altura do bitmap, medido em unidades de 0,1 milímetro. A altura é na `cy` membro do `CSize` objeto e a largura está no `cx` membro. Se a altura e largura de bitmap não tiverem sido definidos usando `SetBitmapDimension`, o valor retornado será 0.

### <a name="remarks"></a>Comentários

A altura e largura são considerados tiver sido definido anteriormente usando o [SetBitmapDimension](#setbitmapdimension) função de membro.

##  <a name="loadbitmap"></a>  CBitmap::LoadBitmap

Carrega o recurso de bitmap nomeado pelo *lpszResourceName* ou identificado pelo número de identificação no *nIDResource* do arquivo executável do aplicativo.

```
BOOL LoadBitmap(LPCTSTR lpszResourceName);
BOOL LoadBitmap(UINT nIDResource);
```

### <a name="parameters"></a>Parâmetros

*lpszResourceName*<br/>
Aponta para uma cadeia de caracteres terminada em nulo que contém o nome do recurso de bitmap.

*nIDResource*<br/>
Especifica o número de ID de recurso do recurso de bitmap.

### <a name="return-value"></a>Valor de retorno

Diferente de zero se bem-sucedido; Caso contrário, 0.

### <a name="remarks"></a>Comentários

O bitmap carregado é anexado ao `CBitmap` objeto.

Se o bitmap é identificado por *lpszResourceName* não existe ou se não houver memória insuficiente para carregar o bitmap, a função retornará 0.

Você pode usar o [CGdiObject::DeleteObject](../../mfc/reference/cgdiobject-class.md#deleteobject) função para excluir o bitmap é carregado pelo `LoadBitmap` função, ou o `CBitmap` destruidor excluirá o objeto para você.

> [!CAUTION]
>  Antes de excluir o objeto, verifique se que ele não está selecionado em um contexto de dispositivo.

Os bitmaps a seguir foram adicionados a versões do Windows 3.1 e posteriores:

OBM_UPARRROWIOBM_DNARROWIOBM_RGARROWIOBM_LFARROWI

Esses bitmaps não são encontrados nos drivers de dispositivo para as versões do Windows 3.0 e versões anteriores. Para obter uma lista completa de bitmaps e uma exibição de sua aparência, consulte o SDK do Windows.

##  <a name="loadmappedbitmap"></a>  CBitmap::LoadMappedBitmap

Chame essa função de membro para carregar um bitmap e as cores são mapeados para as cores do sistema atual.

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
Um ponteiro para um `COLORMAP` estrutura que contém as informações de cor necessárias para mapear os bitmaps. Se esse parâmetro for NULL, a função usa o mapa de cores padrão.

*nMapSize*<br/>
O número de tabelas de cores apontada por *lpColorMap*.

### <a name="return-value"></a>Valor de retorno

Diferente de zero se bem-sucedido; Caso contrário, 0.

### <a name="remarks"></a>Comentários

Por padrão, `LoadMappedBitmap` mapeará as cores usadas comumente em glifos de botão.

Para obter informações sobre como criar um bitmap mapeado, consulte a função do Windows [CreateMappedBitmap](http://go.microsoft.com/fwlink/p/?linkid=230562) e o [substituição](/windows/desktop/api/commctrl/ns-commctrl-_colormap) estrutura no SDK do Windows.

##  <a name="loadoembitmap"></a>  CBitmap::LoadOEMBitmap

Carrega um bitmap predefinido usado pelo Windows.

```
BOOL LoadOEMBitmap(UINT nIDBitmap);
```

### <a name="parameters"></a>Parâmetros

*nIDBitmap*<br/>
Número de identificação do bitmap Windows predefinido. Os valores possíveis estão listados abaixo do WINDOWS. H:

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

### <a name="return-value"></a>Valor de retorno

Diferente de zero se bem-sucedido; Caso contrário, 0.

### <a name="remarks"></a>Comentários

Nomes de bitmap que começam com OBM_OLD representam os bitmaps usados pelas versões do Windows anteriores à 3.0.

Observe que a constante OEMRESOURCE deve ser definido antes de incluir o WINDOWS. H para usar qualquer um de **OBM_** constantes.

##  <a name="operator_hbitmap"></a>  CBitmap::operator HBITMAP

Use este operador para obter o identificador do Windows GDI anexado do `CBitmap` objeto.

```
operator HBITMAP() const;
```

### <a name="return-value"></a>Valor de retorno

Se for bem-sucedido, um identificador para o objeto de GDI do Windows representado pelo `CBitmap` objeto; caso contrário, nulo.

### <a name="remarks"></a>Comentários

Este operador é um operador de conversão, que dá suporte ao uso direto de um `HBITMAP` objeto.

Para obter mais informações sobre como usar objetos gráficos, consulte [gráfico de objetos](/windows/desktop/gdi/graphic-objects) no SDK do Windows.

##  <a name="setbitmapbits"></a>  CBitmap::SetBitmapBits

Define os bits de um bitmap para os valores de bit fornecidos pelo *lpBits*.

```
DWORD SetBitmapBits(
    DWORD dwCount,
    const void* lpBits);
```

### <a name="parameters"></a>Parâmetros

*dwCount*<br/>
Especifica o número de bytes apontados por *lpBits*.

*lpBits*<br/>
Aponta para a matriz de bytes que contém os valores de pixel a ser copiado para o `CBitmap` objeto. Na ordem para o bitmap a ser capaz de renderizar sua imagem corretamente, os valores devem ser formatados de acordo com os valores de profundidade de altura, largura e cor especificados quando a instância CBitmap foi criada. Para obter mais informações, consulte [CBitmap::CreateBitmap](#createbitmap).

### <a name="return-value"></a>Valor de retorno

O número de bytes usada ao configurar os bits do bitmap; 0 se a função falhar.

##  <a name="setbitmapdimension"></a>  CBitmap::SetBitmapDimension

Atribui uma largura e altura em um bitmap em unidades de 0,1 milímetro.

```
CSize SetBitmapDimension(
    int nWidth,
    int nHeight);
```

### <a name="parameters"></a>Parâmetros

*nWidth*<br/>
Especifica a largura do bitmap (em unidades de 0,1 milímetro).

*nHeight*<br/>
Especifica a altura do bitmap (em unidades de 0,1 milímetro).

### <a name="return-value"></a>Valor de retorno

As dimensões do bitmap anterior. Altura é na `cy` variável de membro do `CSize` objeto e a largura está no `cx` variável de membro.

### <a name="remarks"></a>Comentários

A GDI não usa esses valores, exceto to retorná-los quando um aplicativo chama o [GetBitmapDimension](#getbitmapdimension) função de membro.

## <a name="see-also"></a>Consulte também

[Exemplo MFC MDI](../../visual-cpp-samples.md)<br/>
[Classe CGdiObject](../../mfc/reference/cgdiobject-class.md)<br/>
[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)

