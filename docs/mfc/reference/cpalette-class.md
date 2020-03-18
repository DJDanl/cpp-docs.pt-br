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
ms.openlocfilehash: 27f4f14c9e93091728e256c890dcffee26a43de4
ms.sourcegitcommit: 7ecd91d8ce18088a956917cdaf3a3565bd128510
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/16/2020
ms.locfileid: "79421656"
---
# <a name="cpalette-class"></a>Classe CPalette

Encapsula uma paleta de cores do Windows.

## <a name="syntax"></a>Sintaxe

```
class CPalette : public CGdiObject
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|DESCRIÇÃO|
|----------|-----------------|
|[CPalette::CPalette](#cpalette)|Constrói um objeto `CPalette` sem nenhuma paleta do Windows anexada. Você deve inicializar o objeto `CPalette` com uma das funções de membro de inicialização antes que ela possa ser usada.|

### <a name="public-methods"></a>Métodos públicos

|Nome|DESCRIÇÃO|
|----------|-----------------|
|[CPalette::AnimatePalette](#animatepalette)|Substitui as entradas na paleta lógica identificada pelo objeto `CPalette`. O aplicativo não precisa atualizar sua área de cliente, pois o Windows mapeia as novas entradas para a paleta do sistema imediatamente.|
|[CPalette::CreateHalftonePalette](#createhalftonepalette)|Cria uma paleta de meio-tom para o contexto do dispositivo e a anexa ao objeto `CPalette`.|
|[CPalette:: CreatePalette](#createpalette)|Cria uma paleta de cores do Windows e a anexa ao objeto `CPalette`.|
|[CPalette:: FromHandle](#fromhandle)|Retorna um ponteiro para um objeto `CPalette` ao receber um identificador para um objeto de paleta do Windows.|
|[CPalette::GetEntryCount](#getentrycount)|Recupera o número de entradas da paleta em uma paleta lógica.|
|[CPalette::GetNearestPaletteIndex](#getnearestpaletteindex)|Retorna o índice da entrada na paleta lógica que mais se aproximará de um valor de cor.|
|[CPalette::GetPaletteEntries](#getpaletteentries)|Recupera um intervalo de entradas de paleta em uma paleta lógica.|
|[CPalette::ResizePalette](#resizepalette)|Altera o tamanho da paleta lógica especificada pelo objeto `CPalette` para o número especificado de entradas.|
|[CPalette::SetPaletteEntries](#setpaletteentries)|Define valores de cor RGB e sinalizadores em um intervalo de entradas em uma paleta lógica.|

### <a name="public-operators"></a>Operadores públicos

|Nome|DESCRIÇÃO|
|----------|-----------------|
|[Operador CPalette:: Operator HPALETTE](#operator_hpalette)|Retorna o HPALETTE anexado ao `CPalette`.|

## <a name="remarks"></a>Comentários

Uma paleta fornece uma interface entre um aplicativo e um dispositivo de saída de cor (como um dispositivo de vídeo). A interface permite que o aplicativo aproveite ao máximo os recursos de cores do dispositivo de saída sem interferir graves nas cores exibidas por outros aplicativos. O Windows usa a paleta lógica do aplicativo (uma lista de cores necessárias) e a paleta do sistema (que define as cores disponíveis) para determinar as cores usadas.

Um objeto `CPalette` fornece funções de membro para manipular a paleta referenciada pelo objeto. Construa um objeto de `CPalette` e use suas funções de membro para criar a paleta real, um objeto de interface de dispositivo gráfico (GDI) e manipular suas entradas e outras propriedades.

Para obter mais informações sobre como usar `CPalette`, consulte [objetos gráficos](../../mfc/graphic-objects.md).

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[CObject](../../mfc/reference/cobject-class.md)

[CGdiObject](../../mfc/reference/cgdiobject-class.md)

`CPalette`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** Afxwin. h

##  <a name="animatepalette"></a>CPalette::AnimatePalette

Substitui as entradas na paleta lógica anexada ao objeto `CPalette`.

```
void AnimatePalette(
    UINT nStartIndex,
    UINT nNumEntries,
    LPPALETTEENTRY lpPaletteColors);
```

### <a name="parameters"></a>parâmetros

*nStartIndex*<br/>
Especifica a primeira entrada na paleta a ser animada.

*nNumEntries*<br/>
Especifica o número de entradas na paleta a serem animadas.

*lpPaletteColors*<br/>
Aponta para o primeiro membro de uma matriz de estruturas [PaletteEntry](/previous-versions/dd162769\(v=vs.85\)) para substituir as entradas de paleta identificadas por *nStartIndex* e *nNumEntries*.

### <a name="remarks"></a>Comentários

Quando um aplicativo chama `AnimatePalette`, ele não precisa atualizar sua área de cliente, pois o Windows mapeia as novas entradas para a paleta do sistema imediatamente.

A função `AnimatePalette` só alterará as entradas com o sinalizador de PC_RESERVED definido no membro `palPaletteEntry` correspondente da estrutura [LOGPALETTE](/windows/win32/api/wingdi/ns-wingdi-logpalette) que está anexada ao objeto `CPalette`. Consulte LOGPALETTE no SDK do Windows para obter mais informações sobre esta estrutura.

##  <a name="cpalette"></a>CPalette::CPalette

Constrói um objeto `CPalette`.

```
CPalette();
```

### <a name="remarks"></a>Comentários

O objeto não tem paleta anexada até que você chame `CreatePalette` para anexar um.

##  <a name="createhalftonepalette"></a>CPalette::CreateHalftonePalette

Cria uma paleta de meio-tom para o contexto do dispositivo.

```
BOOL CreateHalftonePalette(CDC* pDC);
```

### <a name="parameters"></a>parâmetros

*pDC*<br/>
Identifica o contexto do dispositivo.

### <a name="return-value"></a>Valor retornado

Diferente de zero se a função for bem-sucedida; caso contrário, 0.

### <a name="remarks"></a>Comentários

Um aplicativo deve criar uma paleta de meio-tom quando o modo de alongamento de um contexto de dispositivo é definido como meio-tom. A paleta de retícula lógica retornada pela função membro [CreateHalftonePalette](/windows/win32/api/wingdi/nf-wingdi-createhalftonepalette) deve ser selecionada e realizada no contexto do dispositivo antes que a função [CDC:: StretchBlt](../../mfc/reference/cdc-class.md#stretchblt) ou [StretchDIBits](/windows/win32/api/wingdi/nf-wingdi-stretchdibits) seja chamada.

Consulte a SDK do Windows para obter mais informações sobre `CreateHalftonePalette` e `StretchDIBits`.

##  <a name="createpalette"></a>CPalette:: CreatePalette

Inicializa um objeto `CPalette` criando uma paleta de cores lógicas do Windows e anexando-a ao objeto `CPalette`.

```
BOOL CreatePalette(LPLOGPALETTE lpLogPalette);
```

### <a name="parameters"></a>parâmetros

*lpLogPalette*<br/>
Aponta para uma estrutura [LOGPALETTE](/windows/win32/api/wingdi/ns-wingdi-logpalette) que contém informações sobre as cores na paleta lógica.

### <a name="return-value"></a>Valor retornado

Diferente de zero, se for bem-sucedido; caso contrário, 0.

### <a name="remarks"></a>Comentários

Consulte a SDK do Windows para obter mais informações sobre a estrutura de `LOGPALETTE`.

##  <a name="fromhandle"></a>CPalette:: FromHandle

Retorna um ponteiro para um objeto `CPalette` ao receber um identificador para um objeto de paleta do Windows.

```
static CPalette* PASCAL FromHandle(HPALETTE hPalette);
```

### <a name="parameters"></a>parâmetros

*hPalette*<br/>
Um identificador para uma paleta de cores GDI do Windows.

### <a name="return-value"></a>Valor retornado

Um ponteiro para um objeto `CPalette` se for bem-sucedido; caso contrário, NULL.

### <a name="remarks"></a>Comentários

Se um objeto `CPalette` ainda não estiver anexado à paleta do Windows, um objeto de `CPalette` temporário será criado e anexado. Esse objeto de `CPalette` temporário é válido somente até a próxima vez que o aplicativo tiver tempo ocioso em seu loop de eventos, quando todos os objetos gráficos temporários forem excluídos. Em outras palavras, o objeto temporário é válido somente durante o processamento de uma mensagem de janela.

##  <a name="getentrycount"></a>CPalette::GetEntryCount

Chame essa função de membro para recuperar o número de entradas em uma determinada paleta lógica.

```
int GetEntryCount();
```

### <a name="return-value"></a>Valor retornado

Número de entradas em uma paleta lógica.

##  <a name="getnearestpaletteindex"></a>CPalette::GetNearestPaletteIndex

Retorna o índice da entrada na paleta lógica que mais se assemelha ao valor de cor especificado.

```
UINT GetNearestPaletteIndex(COLORREF crColor) const;
```

### <a name="parameters"></a>parâmetros

*crColor*<br/>
Especifica a cor a ser correspondida.

### <a name="return-value"></a>Valor retornado

O índice de uma entrada em uma paleta lógica. A entrada contém a cor que quase corresponde à cor especificada.

##  <a name="getpaletteentries"></a>CPalette::GetPaletteEntries

Recupera um intervalo de entradas de paleta em uma paleta lógica.

```
UINT GetPaletteEntries(
    UINT nStartIndex,
    UINT nNumEntries,
    LPPALETTEENTRY lpPaletteColors) const;
```

### <a name="parameters"></a>parâmetros

*nStartIndex*<br/>
Especifica a primeira entrada na paleta lógica a ser recuperada.

*nNumEntries*<br/>
Especifica o número de entradas na paleta lógica a ser recuperada.

*lpPaletteColors*<br/>
Aponta para uma matriz de estruturas de dados [PaletteEntry](/previous-versions/dd162769\(v=vs.85\)) para receber as entradas da paleta. A matriz deve conter pelo menos tantas estruturas de dados quantas forem especificadas por *nNumEntries*.

### <a name="return-value"></a>Valor retornado

O número de entradas recuperadas da paleta lógica; 0 se a função falhar.

##  <a name="operator_hpalette"></a>Operador CPalette:: Operator HPALETTE

Use esse operador para obter o identificador GDI do Windows anexado do objeto `CPalette`.

```
operator HPALETTE() const;
```

### <a name="return-value"></a>Valor retornado

Se for bem-sucedido, um identificador para o objeto GDI do Windows representado pelo objeto `CPalette`; caso contrário, NULL.

### <a name="remarks"></a>Comentários

Esse operador é um operador de conversão, que dá suporte ao uso direto de um objeto HPALETTE.

Para obter mais informações sobre como usar objetos gráficos, consulte o artigo [objetos gráficos](/windows/win32/gdi/graphic-objects) na SDK do Windows.

##  <a name="resizepalette"></a>CPalette::ResizePalette

Altera o tamanho da paleta lógica anexada ao objeto `CPalette` para o número de entradas especificado por *nNumEntries*.

```
BOOL ResizePalette(UINT nNumEntries);
```

### <a name="parameters"></a>parâmetros

*nNumEntries*<br/>
Especifica o número de entradas na paleta depois que ela é redimensionada.

### <a name="return-value"></a>Valor retornado

Diferente de zero se a paleta tiver sido redimensionada com êxito; caso contrário, 0.

### <a name="remarks"></a>Comentários

Se um aplicativo chamar `ResizePalette` para reduzir o tamanho da paleta, as entradas restantes na paleta redimensionada não serão alteradas. Se o aplicativo chamar `ResizePalette` para ampliar a paleta, as entradas de paleta adicionais serão definidas como preto (os valores vermelho, verde e azul serão todos 0) e os sinalizadores para todas as entradas adicionais serão definidos como 0.

Para obter mais informações sobre a `ResizePalette`de API do Windows, consulte [ResizePalette](/windows/win32/api/wingdi/nf-wingdi-resizepalette) no SDK do Windows.

##  <a name="setpaletteentries"></a>CPalette::SetPaletteEntries

Define valores de cor RGB e sinalizadores em um intervalo de entradas em uma paleta lógica.

```
UINT SetPaletteEntries(
    UINT nStartIndex,
    UINT nNumEntries,
    LPPALETTEENTRY lpPaletteColors);
```

### <a name="parameters"></a>parâmetros

*nStartIndex*<br/>
Especifica a primeira entrada na paleta lógica a ser definida.

*nNumEntries*<br/>
Especifica o número de entradas na paleta lógica a serem definidas.

*lpPaletteColors*<br/>
Aponta para uma matriz de estruturas de dados [PaletteEntry](/previous-versions/dd162769\(v=vs.85\)) para receber as entradas da paleta. A matriz deve conter pelo menos tantas estruturas de dados quantas forem especificadas por *nNumEntries*.

### <a name="return-value"></a>Valor retornado

O número de entradas definidas na paleta lógica; 0 se a função falhar.

### <a name="remarks"></a>Comentários

Se a paleta lógica for selecionada em um contexto de dispositivo quando o aplicativo chamar `SetPaletteEntries`, as alterações não entrarão em vigor até que o aplicativo chame [CDC:: RealizePalette](../../mfc/reference/cdc-class.md#realizepalette).

Para obter mais informações, consulte [PaletteEntry](/previous-versions/dd162769\(v=vs.85\)) no SDK do Windows.

## <a name="see-also"></a>Confira também

[Exemplo de DIBLOOK do MFC](../../overview/visual-cpp-samples.md)<br/>
[Classe CGdiObject](../../mfc/reference/cgdiobject-class.md)<br/>
[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[CPalette::GetPaletteEntries](#getpaletteentries)<br/>
[CPalette::SetPaletteEntries](#setpaletteentries)
