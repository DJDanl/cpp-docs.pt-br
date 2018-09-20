---
title: Classe CPalette | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: reference
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
dev_langs:
- C++
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
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: d4a2b161368b39f586c6393bbf1916d64dacd833
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46381394"
---
# <a name="cpalette-class"></a>Classe CPalette

Encapsula uma paleta de cores do Windows.

## <a name="syntax"></a>Sintaxe

```
class CPalette : public CGdiObject
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores Públicos

|Nome|Descrição|
|----------|-----------------|
|[CPalette::CPalette](#cpalette)|Constrói um `CPalette` objeto com nenhuma paleta Windows anexada. Você deve inicializar o `CPalette` objeto com uma das funções de membro de inicialização antes que ele pode ser usado.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CPalette::AnimatePalette](#animatepalette)|Substitui as entradas da paleta lógica identificado pelo `CPalette` objeto. O aplicativo não precisa atualizar sua área de cliente, como Windows mapeia as novas entradas na paleta do sistema imediatamente.|
|[CPalette::CreateHalftonePalette](#createhalftonepalette)|Cria uma paleta de meio-tom para o contexto de dispositivo e anexa-o para o `CPalette` objeto.|
|[CPalette::CreatePalette](#createpalette)|Cria uma paleta de cores do Windows e anexa-o para o `CPalette` objeto.|
|[CPalette::FromHandle](#fromhandle)|Retorna um ponteiro para um `CPalette` objeto quando recebe um identificador para um objeto de paleta do Windows.|
|[CPalette::GetEntryCount](#getentrycount)|Recupera o número de entradas da paleta em uma paleta lógica.|
|[CPalette::GetNearestPaletteIndex](#getnearestpaletteindex)|Retorna o índice da entrada na paleta lógica mais parecido com um valor de cor.|
|[CPalette::GetPaletteEntries](#getpaletteentries)|Recupera um intervalo de entradas da paleta em uma paleta lógica.|
|[CPalette::ResizePalette](#resizepalette)|Altera o tamanho da paleta lógica especificada pelo `CPalette` objeto para o número especificado de entradas.|
|[CPalette::SetPaletteEntries](#setpaletteentries)|Define os sinalizadores e valores de cor RGB em um intervalo de entradas em uma paleta lógica.|

### <a name="public-operators"></a>Operadores públicos

|Nome|Descrição|
|----------|-----------------|
|[CPalette::operator HPALETTE](#operator_hpalette)|Retorna o HPALETTE anexado para o `CPalette`.|

## <a name="remarks"></a>Comentários

Uma paleta fornece uma interface entre um aplicativo e um dispositivo de saída de cor (por exemplo, um dispositivo de vídeo). A interface permite que o aplicativo para aproveitar ao máximo os recursos de cores do dispositivo de saída sem gravemente interferir com as cores exibidas por outros aplicativos. Windows usa a paleta de lógica do aplicativo (uma lista de cores necessárias) e a paleta do sistema (que define as cores disponíveis) para determinar as cores usadas.

Um `CPalette` objeto fornece funções de membro para manipular a paleta referido pelo objeto. Construir um `CPalette` do objeto e usar as funções de membro para criar a paleta real, um objeto de interface (GDI) do dispositivo de gráficos e manipular suas entradas e outras propriedades.

Para obter mais informações sobre como usar `CPalette`, consulte [objetos gráficos](../../mfc/graphic-objects.md).

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[CObject](../../mfc/reference/cobject-class.md)

[CGdiObject](../../mfc/reference/cgdiobject-class.md)

`CPalette`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxwin. h

##  <a name="animatepalette"></a>  CPalette::AnimatePalette

Substitui as entradas da paleta lógica anexado ao `CPalette` objeto.

```
void AnimatePalette(
    UINT nStartIndex,
    UINT nNumEntries,
    LPPALETTEENTRY lpPaletteColors);
```

### <a name="parameters"></a>Parâmetros

*nStartIndex*<br/>
Especifica a primeira entrada na paleta a ser animada.

*nNumEntries*<br/>
Especifica o número de entradas na paleta a ser animada.

*lpPaletteColors*<br/>
Aponta para o primeiro membro de uma matriz de [PALETTEENTRY](https://msdn.microsoft.com/library/windows/desktop/dd162769) estruturas para substituir as entradas da paleta identificadas pelo *nStartIndex* e *nNumEntries*.

### <a name="remarks"></a>Comentários

Quando um aplicativo chama `AnimatePalette`, ele não precisa atualizar sua área de cliente, porque o Windows mapeia as novas entradas na paleta do sistema imediatamente.

O `AnimatePalette` função alterará apenas entradas com o sinalizador PC_RESERVED definido nas correspondentes `palPaletteEntry` membro do [LOGPALETTE](/windows/desktop/api/wingdi/ns-wingdi-taglogpalette) estrutura que é anexada ao `CPalette` objeto. Consulte LOGPALETTE no SDK do Windows para obter mais informações sobre essa estrutura.

##  <a name="cpalette"></a>  CPalette::CPalette

Constrói um objeto `CPalette`.

```
CPalette();
```

### <a name="remarks"></a>Comentários

O objeto não tem nenhuma paleta anexada até que você chame `CreatePalette` para anexar uma.

##  <a name="createhalftonepalette"></a>  CPalette::CreateHalftonePalette

Cria uma paleta de meio-tom para o contexto de dispositivo.

```
BOOL CreateHalftonePalette(CDC* pDC);
```

### <a name="parameters"></a>Parâmetros

*pDC*<br/>
Identifica o contexto de dispositivo.

### <a name="return-value"></a>Valor de retorno

Diferente de zero se a função for bem-sucedida; caso contrário, 0.

### <a name="remarks"></a>Comentários

Um aplicativo deve criar uma paleta de meio-tom quando o modo de alongamento de um contexto de dispositivo é definido como o meio-tom. A paleta de meio-tom lógico retornada pela [CreateHalftonePalette](/windows/desktop/api/wingdi/nf-wingdi-createhalftonepalette) função de membro deve ser selecionada e realizada no contexto de dispositivo antes do [CDC::StretchBlt](../../mfc/reference/cdc-class.md#stretchblt) ou [ StretchDIBits](/windows/desktop/api/wingdi/nf-wingdi-stretchdibits) função é chamada.

Consulte o SDK do Windows para obter mais informações `CreateHalftonePalette` e `StretchDIBits`.

##  <a name="createpalette"></a>  CPalette::CreatePalette

Inicializa uma `CPalette` objeto criando uma paleta de cores lógicas do Windows e anexá-lo para o `CPalette` objeto.

```
BOOL CreatePalette(LPLOGPALETTE lpLogPalette);
```

### <a name="parameters"></a>Parâmetros

*lpLogPalette*<br/>
Aponta para um [LOGPALETTE](/windows/desktop/api/wingdi/ns-wingdi-taglogpalette) estrutura que contém informações sobre as cores da paleta lógica.

### <a name="return-value"></a>Valor de retorno

Diferente de zero se bem-sucedido; Caso contrário, 0.

### <a name="remarks"></a>Comentários

Consulte o SDK do Windows para obter mais informações o `LOGPALETTE` estrutura.

##  <a name="fromhandle"></a>  CPalette::FromHandle

Retorna um ponteiro para um `CPalette` objeto quando recebe um identificador para um objeto de paleta do Windows.

```
static CPalette* PASCAL FromHandle(HPALETTE hPalette);
```

### <a name="parameters"></a>Parâmetros

*hPalette*<br/>
Um identificador para uma paleta de cores do Windows GDI.

### <a name="return-value"></a>Valor de retorno

Um ponteiro para um `CPalette` objeto se for bem-sucedido; caso contrário, NULL.

### <a name="remarks"></a>Comentários

Se um `CPalette` objeto já não está anexado à paleta do Windows, um temporário `CPalette` objeto é criado e anexado. Esse temporário `CPalette` objeto é válido somente até a próxima vez que o aplicativo tem tempo ocioso em seu loop de eventos, em que ponto o gráfico temporário todos os objetos são excluídos. Em outras palavras, o objeto temporário é válido somente durante o processamento da mensagem de uma janela.

##  <a name="getentrycount"></a>  CPalette::GetEntryCount

Chame essa função de membro para recuperar o número de entradas em uma determinada paleta lógica.

```
int GetEntryCount();
```

### <a name="return-value"></a>Valor de retorno

Número de entradas em uma paleta lógica.

##  <a name="getnearestpaletteindex"></a>  CPalette::GetNearestPaletteIndex

Retorna o índice da entrada na paleta lógica que mais se aproxima o valor de cor especificado.

```
UINT GetNearestPaletteIndex(COLORREF crColor) const;
```

### <a name="parameters"></a>Parâmetros

*crColor*<br/>
Especifica a cor a ser correspondido.

### <a name="return-value"></a>Valor de retorno

O índice de uma entrada em uma paleta lógica. A entrada contém a cor que mais se aproxima a cor especificada.

##  <a name="getpaletteentries"></a>  CPalette::GetPaletteEntries

Recupera um intervalo de entradas da paleta em uma paleta lógica.

```
UINT GetPaletteEntries(
    UINT nStartIndex,
    UINT nNumEntries,
    LPPALETTEENTRY lpPaletteColors) const;
```

### <a name="parameters"></a>Parâmetros

*nStartIndex*<br/>
Especifica a primeira entrada na paleta lógica a ser recuperado.

*nNumEntries*<br/>
Especifica o número de entradas na paleta lógica a ser recuperado.

*lpPaletteColors*<br/>
Aponta para uma matriz de [PALETTEENTRY](https://msdn.microsoft.com/library/windows/desktop/dd162769) estruturas de dados para receber as entradas da paleta. A matriz deve conter pelo menos o mesmo número de estruturas de dados conforme especificado por *nNumEntries*.

### <a name="return-value"></a>Valor de retorno

O número de entradas recuperados da paleta lógica; 0 se a função falhou.

##  <a name="operator_hpalette"></a>  CPalette::operator HPALETTE

Use este operador para obter o identificador do Windows GDI anexado do `CPalette` objeto.

```
operator HPALETTE() const;
```

### <a name="return-value"></a>Valor de retorno

Se for bem-sucedido, um identificador para o objeto de GDI do Windows representado pelo `CPalette` objeto; caso contrário, nulo.

### <a name="remarks"></a>Comentários

Esse operador é um operador de conversão, que dá suporte ao uso direto de um objeto HPALETTE.

Para obter mais informações sobre como usar objetos gráficos, consulte o artigo [gráfico de objetos](/windows/desktop/gdi/graphic-objects) no SDK do Windows.

##  <a name="resizepalette"></a>  CPalette::ResizePalette

Altera o tamanho da paleta lógica anexado para o `CPalette` objeto para o número de entradas especificado pelo *nNumEntries*.

```
BOOL ResizePalette(UINT nNumEntries);
```

### <a name="parameters"></a>Parâmetros

*nNumEntries*<br/>
Especifica o número de entradas da paleta depois que ele foi redimensionado.

### <a name="return-value"></a>Valor de retorno

Diferente de zero se a paleta foi redimensionada com êxito; Caso contrário, 0.

### <a name="remarks"></a>Comentários

Se um aplicativo chamar `ResizePalette` para reduzir o tamanho da paleta, as entradas restantes na paleta redimensionada são as mesmas. Se o aplicativo chama `ResizePalette` para aumentar a paleta, as entradas da paleta adicionais são definidas para preto (os valores de vermelhos, verdes e azuis são todos 0) e os sinalizadores para todas as entradas adicionais são definidos como 0.

Para obter mais informações sobre a API do Windows `ResizePalette`, consulte [ResizePalette](/windows/desktop/api/wingdi/nf-wingdi-resizepalette) no SDK do Windows.

##  <a name="setpaletteentries"></a>  CPalette::SetPaletteEntries

Define os sinalizadores e valores de cor RGB em um intervalo de entradas em uma paleta lógica.

```
UINT SetPaletteEntries(
    UINT nStartIndex,
    UINT nNumEntries,
    LPPALETTEENTRY lpPaletteColors);
```

### <a name="parameters"></a>Parâmetros

*nStartIndex*<br/>
Especifica a primeira entrada na paleta lógica a ser definido.

*nNumEntries*<br/>
Especifica o número de entradas na paleta lógica a ser definido.

*lpPaletteColors*<br/>
Aponta para uma matriz de [PALETTEENTRY](https://msdn.microsoft.com/library/windows/desktop/dd162769) estruturas de dados para receber as entradas da paleta. A matriz deve conter pelo menos o mesmo número de estruturas de dados conforme especificado por *nNumEntries*.

### <a name="return-value"></a>Valor de retorno

O número de entradas definido na paleta lógica; 0 se a função falhou.

### <a name="remarks"></a>Comentários

Se a paleta lógica está selecionada em um contexto de dispositivo quando o aplicativo chama `SetPaletteEntries`, as alterações não entrarão em vigor até que o aplicativo chama [CDC::RealizePalette](../../mfc/reference/cdc-class.md#realizepalette).

Para obter mais informações sobre a estrutura do Windows `PALETTEENTRY`, consulte [PALETTEENTRY](https://msdn.microsoft.com/library/windows/desktop/dd162769) no SDK do Windows.

## <a name="see-also"></a>Consulte também

[Exemplo MFC DIBLOOK](../../visual-cpp-samples.md)<br/>
[Classe CGdiObject](../../mfc/reference/cgdiobject-class.md)<br/>
[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[CPalette::GetPaletteEntries](#getpaletteentries)<br/>
[CPalette::SetPaletteEntries](#setpaletteentries)



