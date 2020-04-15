---
title: Classe CPalette
ms.date: 11/04/2016
f1_keywords:
- CPalette
- AFXWIN/CPalette
- AFXWIN/CPalette::CPalette
- AFXWIN/CPalette::AnimatePalette
- AFXWIN/CPalette::CreateHalftonePalette
- AFXWIN/CPalette::CreatePalette
- AFXWIN/CPalette::FromHandle
- AFXWIN/CPalette::GetEntryCount
- AFXWIN/CPalette::GetNearestPaletteIndex
- AFXWIN/CPalette::GetPaletteEntries
- AFXWIN/CPalette::ResizePalette
- AFXWIN/CPalette::SetPaletteEntries
helpviewer_keywords:
- CPalette [MFC], CPalette
- CPalette [MFC], AnimatePalette
- CPalette [MFC], CreateHalftonePalette
- CPalette [MFC], CreatePalette
- CPalette [MFC], FromHandle
- CPalette [MFC], GetEntryCount
- CPalette [MFC], GetNearestPaletteIndex
- CPalette [MFC], GetPaletteEntries
- CPalette [MFC], ResizePalette
- CPalette [MFC], SetPaletteEntries
ms.assetid: 8cd95498-53ed-4852-85e1-70e522541114
ms.openlocfilehash: 83cd125fa7ab64aa39c606bc048022400d158e72
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81374756"
---
# <a name="cpalette-class"></a>Classe CPalette

Encapsula uma paleta de cores do Windows.

## <a name="syntax"></a>Sintaxe

```
class CPalette : public CGdiObject
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[Paleta::CPalette](#cpalette)|Constrói um `CPalette` objeto sem paleta de Windows anexada. Você deve inicializar o `CPalette` objeto com uma das funções do membro de inicialização antes que ele possa ser usado.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CPalette::AnimatePalette](#animatepalette)|Substitui as entradas na paleta `CPalette` lógica identificada pelo objeto. O aplicativo não precisa atualizar sua área cliente, pois o Windows mapeia as novas entradas na paleta do sistema imediatamente.|
|[CPaleta::CriarPaleta de tonshalf](#createhalftonepalette)|Cria uma paleta de meio tom para o `CPalette` contexto do dispositivo e anexa-a ao objeto.|
|[Paleta de c::Criarpaleta](#createpalette)|Cria uma paleta de cores do `CPalette` Windows e a anexa ao objeto.|
|[Paleta::FromHandle](#fromhandle)|Retorna um ponteiro `CPalette` para um objeto quando dado uma alça a um objeto de paleta do Windows.|
|[Cpalette::GetEntryCount](#getentrycount)|Recupera o número de entradas da paleta em uma paleta lógica.|
|[CPalette::GetNearestPaletteIndex](#getnearestpaletteindex)|Retorna o índice da entrada na paleta lógica que mais combina com um valor de cor.|
|[CPalette::GetPaletteEntries](#getpaletteentries)|Recupera uma série de entradas de paleta em uma paleta lógica.|
|[Paleta de c::Redimensionarpaleta](#resizepalette)|Altera o tamanho da paleta lógica `CPalette` especificada pelo objeto para o número especificado de entradas.|
|[CPalette::SetPaletteEntries](#setpaletteentries)|Define valores de cores RGB e sinalizadores em uma variedade de entradas em uma paleta lógica.|

### <a name="public-operators"></a>Operadores públicos

|Nome|Descrição|
|----------|-----------------|
|[CPalette::operador HPALETTE](#operator_hpalette)|Retorna o HPALETTE anexado ao `CPalette`.|

## <a name="remarks"></a>Comentários

Uma paleta fornece uma interface entre um aplicativo e um dispositivo de saída de cores (como um dispositivo de exibição). A interface permite que o aplicativo aproveite ao máximo os recursos de cor do dispositivo de saída sem interferir severamente com as cores exibidas por outros aplicativos. O Windows usa a paleta lógica do aplicativo (uma lista de cores necessárias) e a paleta do sistema (que define as cores disponíveis) para determinar as cores usadas.

Um `CPalette` objeto fornece funções de membro para manipular a paleta referida pelo objeto. Construa `CPalette` um objeto e use suas funções de membro para criar a paleta real, um objeto de interface de dispositivo gráfico (GDI) e manipular suas entradas e outras propriedades.

Para obter mais `CPalette`informações sobre como usar, consulte [Objetos Gráficos](../../mfc/graphic-objects.md).

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[Cobject](../../mfc/reference/cobject-class.md)

[Cgdiobject](../../mfc/reference/cgdiobject-class.md)

`CPalette`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxwin.h

## <a name="cpaletteanimatepalette"></a><a name="animatepalette"></a>CPalette::AnimatePalette

Substitui as entradas na paleta lógica `CPalette` anexada ao objeto.

```
void AnimatePalette(
    UINT nStartIndex,
    UINT nNumEntries,
    LPPALETTEENTRY lpPaletteColors);
```

### <a name="parameters"></a>Parâmetros

*Nstartindex*<br/>
Especifica a primeira entrada na paleta a ser animada.

*Nnumentries*<br/>
Especifica o número de entradas na paleta a ser animada.

*lpPaletteCores*<br/>
Aponta para o primeiro membro de uma matriz de estruturas [PALETTEENTRY](/previous-versions/dd162769\(v=vs.85\)) para substituir as entradas de paleta identificadas por *nStartIndex* e *nNumEntries*.

### <a name="remarks"></a>Comentários

Quando um `AnimatePalette`aplicativo chama, ele não precisa atualizar sua área cliente, porque o Windows mapeia as novas entradas na paleta do sistema imediatamente.

A `AnimatePalette` função só mudará as entradas com `palPaletteEntry` o PC_RESERVED sinalizador definido no membro `CPalette` correspondente da estrutura [LOGPALETTE](/windows/win32/api/wingdi/ns-wingdi-logpalette) que está anexado ao objeto. Consulte LOGPALETTE no Windows SDK para obter mais informações sobre essa estrutura.

## <a name="cpalettecpalette"></a><a name="cpalette"></a>Paleta::CPalette

Constrói um objeto `CPalette`.

```
CPalette();
```

### <a name="remarks"></a>Comentários

O objeto não tem paleta `CreatePalette` anexada até que você ligue para anexar um.

## <a name="cpalettecreatehalftonepalette"></a><a name="createhalftonepalette"></a>CPaleta::CriarPaleta de tonshalf

Cria uma paleta de meio tom para o contexto do dispositivo.

```
BOOL CreateHalftonePalette(CDC* pDC);
```

### <a name="parameters"></a>Parâmetros

*pDC*<br/>
Identifica o contexto do dispositivo.

### <a name="return-value"></a>Valor retornado

Diferente de zero se a função for bem-sucedida; caso contrário, 0.

### <a name="remarks"></a>Comentários

Um aplicativo deve criar uma paleta de meio tom quando o modo de alongamento de um contexto de dispositivo estiver definido como HALFTONE. A paleta de meio tons lógica retornada pela função de membro [CreateHalftonePalette](/windows/win32/api/wingdi/nf-wingdi-createhalftonepalette) deve então ser selecionada e realizada no contexto do dispositivo antes que a função [CDC::StretchBlt](../../mfc/reference/cdc-class.md#stretchblt) ou [StretchDIBits](/windows/win32/api/wingdi/nf-wingdi-stretchdibits) seja chamada.

Consulte o Windows SDK `CreateHalftonePalette` para `StretchDIBits`obter mais informações sobre e .

## <a name="cpalettecreatepalette"></a><a name="createpalette"></a>Paleta de c::Criarpaleta

Inicializa um `CPalette` objeto criando uma paleta de cores lógica `CPalette` do Windows e anexando-o ao objeto.

```
BOOL CreatePalette(LPLOGPALETTE lpLogPalette);
```

### <a name="parameters"></a>Parâmetros

*paleta de p.p.P.P.P*<br/>
Aponta para uma estrutura [LOGPALETTE](/windows/win32/api/wingdi/ns-wingdi-logpalette) que contém informações sobre as cores na paleta lógica.

### <a name="return-value"></a>Valor retornado

Não zero se bem sucedido; caso contrário, 0.

### <a name="remarks"></a>Comentários

Consulte o Windows SDK para `LOGPALETTE` obter mais informações sobre a estrutura.

## <a name="cpalettefromhandle"></a><a name="fromhandle"></a>Paleta::FromHandle

Retorna um ponteiro `CPalette` para um objeto quando dado uma alça a um objeto de paleta do Windows.

```
static CPalette* PASCAL FromHandle(HPALETTE hPalette);
```

### <a name="parameters"></a>Parâmetros

*Hpalette*<br/>
Uma alça para uma paleta de cores Windows GDI.

### <a name="return-value"></a>Valor retornado

Um ponteiro `CPalette` para um objeto se for bem sucedido; caso contrário, NULL.

### <a name="remarks"></a>Comentários

Se `CPalette` um objeto ainda não estiver conectado à `CPalette` paleta do Windows, um objeto temporário será criado e anexado. Este `CPalette` objeto temporário só é válido até a próxima vez que o aplicativo tiver tempo ocioso em seu loop de evento, momento em que todos os objetos gráficos temporários são excluídos. Em outras palavras, o objeto temporário é válido apenas durante o processamento de uma mensagem de janela.

## <a name="cpalettegetentrycount"></a><a name="getentrycount"></a>Cpalette::GetEntryCount

Ligue para esta função de membro para recuperar o número de entradas em uma determinada paleta lógica.

```
int GetEntryCount();
```

### <a name="return-value"></a>Valor retornado

Número de entradas em uma paleta lógica.

## <a name="cpalettegetnearestpaletteindex"></a><a name="getnearestpaletteindex"></a>CPalette::GetNearestPaletteIndex

Retorna o índice da entrada na paleta lógica que mais corresponde ao valor de cor especificado.

```
UINT GetNearestPaletteIndex(COLORREF crColor) const;
```

### <a name="parameters"></a>Parâmetros

*Crcolor*<br/>
Especifica a cor a ser combinada.

### <a name="return-value"></a>Valor retornado

O índice de uma entrada em uma paleta lógica. A entrada contém a cor que mais corresponde à cor especificada.

## <a name="cpalettegetpaletteentries"></a><a name="getpaletteentries"></a>CPalette::GetPaletteEntries

Recupera uma série de entradas de paleta em uma paleta lógica.

```
UINT GetPaletteEntries(
    UINT nStartIndex,
    UINT nNumEntries,
    LPPALETTEENTRY lpPaletteColors) const;
```

### <a name="parameters"></a>Parâmetros

*Nstartindex*<br/>
Especifica a primeira entrada na paleta lógica a ser recuperada.

*Nnumentries*<br/>
Especifica o número de entradas na paleta lógica a ser recuperada.

*lpPaletteCores*<br/>
Aponta para um conjunto de estruturas de dados [PALETTEENTRY](/previous-versions/dd162769\(v=vs.85\)) para receber as entradas da paleta. A matriz deve conter pelo menos tantas estruturas de dados especificadas por *nNumEntries*.

### <a name="return-value"></a>Valor retornado

O número de entradas recuperadas da paleta lógica; 0 se a função falhar.

## <a name="cpaletteoperator-hpalette"></a><a name="operator_hpalette"></a>CPalette::operador HPALETTE

Use este operador para obter a alça `CPalette` Windows GDI anexada do objeto.

```
operator HPALETTE() const;
```

### <a name="return-value"></a>Valor retornado

Se for bem-sucedido, uma alça para `CPalette` o objeto GDI do Windows representado pelo objeto; caso contrário, NULL.

### <a name="remarks"></a>Comentários

Este operador é um operador de fundição, que suporta o uso direto de um objeto HPALETTE.

Para obter mais informações sobre o uso de objetos gráficos, consulte o artigo [Objetos Gráficos](/windows/win32/gdi/graphic-objects) no SDK do Windows.

## <a name="cpaletteresizepalette"></a><a name="resizepalette"></a>Paleta de c::Redimensionarpaleta

Altera o tamanho da paleta lógica `CPalette` anexada ao objeto ao número de entradas especificadas por *nNumEntries*.

```
BOOL ResizePalette(UINT nNumEntries);
```

### <a name="parameters"></a>Parâmetros

*Nnumentries*<br/>
Especifica o número de entradas na paleta depois de redimensionada.

### <a name="return-value"></a>Valor retornado

Não zero se a paleta foi redimensionada com sucesso; caso contrário, 0.

### <a name="remarks"></a>Comentários

Se um `ResizePalette` aplicativo chamar para reduzir o tamanho da paleta, as entradas restantes na paleta redimensionada serão inalteradas. Se o `ResizePalette` aplicativo chamar para ampliar a paleta, as entradas adicionais da paleta serão definidas como pretas (os valores vermelho, verde e azul são todos 0) e as bandeiras para todas as entradas adicionais serão definidas como 0.

Para obter mais informações `ResizePalette`sobre a API do Windows, consulte [RedimensionPalette](/windows/win32/api/wingdi/nf-wingdi-resizepalette) no Windows SDK.

## <a name="cpalettesetpaletteentries"></a><a name="setpaletteentries"></a>CPalette::SetPaletteEntries

Define valores de cores RGB e sinalizadores em uma variedade de entradas em uma paleta lógica.

```
UINT SetPaletteEntries(
    UINT nStartIndex,
    UINT nNumEntries,
    LPPALETTEENTRY lpPaletteColors);
```

### <a name="parameters"></a>Parâmetros

*Nstartindex*<br/>
Especifica a primeira entrada na paleta lógica a ser definida.

*Nnumentries*<br/>
Especifica o número de entradas na paleta lógica a ser definida.

*lpPaletteCores*<br/>
Aponta para um conjunto de estruturas de dados [PALETTEENTRY](/previous-versions/dd162769\(v=vs.85\)) para receber as entradas da paleta. A matriz deve conter pelo menos tantas estruturas de dados especificadas por *nNumEntries*.

### <a name="return-value"></a>Valor retornado

O número de entradas definidas na paleta lógica; 0 se a função falhar.

### <a name="remarks"></a>Comentários

Se a paleta lógica for selecionada em `SetPaletteEntries`um contexto de dispositivo quando o aplicativo chamar, as alterações não entrarão em vigor até que o aplicativo chame [CDC::RealizePalette](../../mfc/reference/cdc-class.md#realizepalette).

Para obter mais informações, consulte [PALETTEENTRY](/previous-versions/dd162769\(v=vs.85\)) no SDK do Windows.

## <a name="see-also"></a>Confira também

[Amostra de MFC DIBLOOK](../../overview/visual-cpp-samples.md)<br/>
[Classe CGdiObject](../../mfc/reference/cgdiobject-class.md)<br/>
[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[CPalette::GetPaletteEntries](#getpaletteentries)<br/>
[CPalette::SetPaletteEntries](#setpaletteentries)
