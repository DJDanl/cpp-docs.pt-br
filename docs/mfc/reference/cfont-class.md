---
title: Classe Cfont
ms.date: 11/04/2016
f1_keywords:
- CFont
- AFXWIN/CFont
- AFXWIN/CFont::CFont
- AFXWIN/CFont::CreateFont
- AFXWIN/CFont::CreateFontIndirect
- AFXWIN/CFont::CreatePointFont
- AFXWIN/CFont::CreatePointFontIndirect
- AFXWIN/CFont::FromHandle
- AFXWIN/CFont::GetLogFont
helpviewer_keywords:
- CFont [MFC], CFont
- CFont [MFC], CreateFont
- CFont [MFC], CreateFontIndirect
- CFont [MFC], CreatePointFont
- CFont [MFC], CreatePointFontIndirect
- CFont [MFC], FromHandle
- CFont [MFC], GetLogFont
ms.assetid: 3fad6bfe-d6ce-4ab9-967a-5ce0aa102800
ms.openlocfilehash: 36fd469b182d5f3e0d3449112d04c1a8623d7526
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81373839"
---
# <a name="cfont-class"></a>Classe Cfont

Encapsula uma fonte GDI (Windows Graphics Device Interface, interface de dispositivo gráfico) e fornece funções de membro para manipular a fonte.

## <a name="syntax"></a>Sintaxe

```
class CFont : public CGdiObject
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[CFont::CFont](#cfont)|Constrói um objeto `CFont`.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CFont::CreateFont](#createfont)|Inicializa a `CFont` com as características especificadas.|
|[cfont::CreateFontIndirect](#createfontindirect)|Inicializa um `CFont` objeto com as `LOGFONT` características dadas em uma estrutura.|
|[cfont::CreatePointFont](#createpointfont)|Inicializa um `CFont` com a altura especificada, medida em décimos de um ponto, e tipodeponto.|
|[cfont::CreatePointFontIndirect](#createpointfontindirect)|O `CreateFontIndirect` mesmo que exceto que a altura da fonte é medida em décimos de um ponto em vez de unidades lógicas.|
|[cfont::FromHandle](#fromhandle)|Retorna um ponteiro `CFont` para um objeto quando dado um Windows HFONT.|
|[fonte de texto::getlogfont](#getlogfont)|Preenche um `LOGFONT` com informações sobre a fonte `CFont` lógica anexada ao objeto.|

### <a name="public-operators"></a>Operadores públicos

|Nome|Descrição|
|----------|-----------------|
|[CFont::operador HFONT](#operator_hfont)|Retorna a alça de fonte Do `CFont` Windows GDI anexada ao objeto.|

## <a name="remarks"></a>Comentários

Para usar `CFont` um objeto, construa `CFont` um objeto e conecte uma fonte do Windows a ele com [CreateFont,](#createfont) [CreateFontIndirect,](#createfontindirect) [CreatePointFont](#createpointfont)ou [CreatePointFontIndirect](#createpointfontindirect)e use as funções de membro do objeto para manipular a fonte.

As `CreatePointFont` `CreatePointFontIndirect` funções e funções `CreateFont` são `CreateFontIndirect` muitas vezes mais fáceis de usar do que ou uma vez que eles fazem a conversão para a altura da fonte de um tamanho de ponto para unidades lógicas automaticamente.

Para obter `CFont`mais informações sobre , consulte [Objetos Gráficos](../../mfc/graphic-objects.md).

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[Cobject](../../mfc/reference/cobject-class.md)

[Cgdiobject](../../mfc/reference/cgdiobject-class.md)

`CFont`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxwin.h

## <a name="cfontcfont"></a><a name="cfont"></a>CFont::CFont

Constrói um objeto `CFont`.

```
CFont();
```

### <a name="remarks"></a>Comentários

O objeto resultante deve ser `CreateFont` `CreateFontIndirect`inicializado `CreatePointFontIndirect` com , ou `CreatePointFont`antes de poder ser usado.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCDocView#70](../../mfc/codesnippet/cpp/cfont-class_1.cpp)]

## <a name="cfontcreatefont"></a><a name="createfont"></a>CFont::CreateFont

Inicializa um `CFont` objeto com as características especificadas.

```
BOOL CreateFont(
    int nHeight,
    int nWidth,
    int nEscapement,
    int nOrientation,
    int nWeight,
    BYTE bItalic,
    BYTE bUnderline,
    BYTE cStrikeOut,
    BYTE nCharSet,
    BYTE nOutPrecision,
    BYTE nClipPrecision,
    BYTE nQuality,
    BYTE nPitchAndFamily,
    LPCTSTR lpszFacename);
```

### <a name="parameters"></a>Parâmetros

*Nheight*<br/>
Especifica a altura desejada (em unidades lógicas) da fonte. Consulte `lfHeight` o membro da estrutura [LOGFONT](/windows/win32/api/wingdi/ns-wingdi-logfontw)no Windows SDK para obter uma descrição. O valor absoluto de *nHeight* não deve exceder 16.384 unidades de dispositivo após a conversão. Para todas as comparações de altura, o mapeador de fontes procura a maior fonte que não exceda o tamanho solicitado ou a menor fonte se todas as fontes excederem o tamanho solicitado.

*Nwidth*<br/>
Especifica a largura média (em unidades lógicas) dos caracteres na fonte. Se *nWidth* for 0, a proporção do dispositivo será comparada com a proporção de digitalização das fontes disponíveis para encontrar a correspondência mais próxima, que é determinada pelo valor absoluto da diferença.

*nEscapement*<br/>
Especifica o ângulo (em unidades de 0,1 graus) entre o vetor de escape e o eixo x da superfície do display. O vetor de fuga é a linha através das origens do primeiro e último caracteres em uma linha. O ângulo é medido no sentido anti-horário a partir do eixo x. Consulte `lfEscapement` o membro `LOGFONT` na estrutura no Windows SDK para obter mais informações.

*nOrientação*<br/>
Especifica o ângulo (em unidades de 0,1 graus) entre a linha de base de um caractere e o eixo x. O ângulo é medido no sentido anti-horário a partir do eixo x para sistemas de coordenadas nos quais a direção y está para baixo e no sentido horário do eixo x para coordenar sistemas nos quais a direção y está para cima.

*nPeso*<br/>
Especifica o peso da fonte (em pixels tatuados por 1000). Consulte o membro *lfWeight* na `LOGFONT` estrutura no SDK do Windows para obter mais informações. Os valores descritos são aproximados; a aparência real depende do tipo. Algumas fontes têm apenas FW_NORMAL, FW_REGULAR e FW_BOLD pesos. Se FW_DONTCARE for especificado, um peso padrão será usado.

*bItálico*<br/>
Especifica se a fonte é itálica.

*bSublinhado*<br/>
Especifica se a fonte está sublinhada.

*cStrikeOut*<br/>
Especifica se os caracteres na fonte são eliminados. Especifica uma fonte de strikeout se definida como um valor não zero.

*nCharSet*<br/>
Especifica o conjunto de caracteres `lfCharSet` da `LOGFONT` fonteVeja o membro na estrutura no SDK do Windows para uma lista de valores.

O conjunto de caracteres OEM é dependente do sistema.

Fontes com outros conjuntos de caracteres podem existir no sistema. Um aplicativo que usa uma fonte com um conjunto de caracteres desconhecido não deve tentar traduzir ou interpretar strings que devem ser renderizadas com essa fonte. Em vez disso, as strings devem ser passadas diretamente para o driver do dispositivo de saída.

O mapeador de fontes não usa o valor DEFAULT_CHARSET. Um aplicativo pode usar esse valor para permitir que o nome e o tamanho de uma fonte descrevam completamente a fonte lógica. Se uma fonte com o nome especificado não existir, uma fonte de qualquer conjunto de caracteres pode ser substituída pela fonte especificada. Para evitar resultados inesperados, os aplicativos devem usar o valor DEFAULT_CHARSET com moderação.

*nOutPrecision*<br/>
Especifica a precisão de saída desejada. A precisão de saída define o quão próxima a saída deve corresponder à altura, largura, orientação do caractere, escape e tom da fonte solicitada. Consulte `lfOutPrecision` o membro `LOGFONT` na estrutura no Windows SDK para obter uma lista de valores e mais informações.

*nClipPrecision*<br/>
Especifica a precisão de recorte desejada. A precisão de recorte define como cortar caracteres que estão parcialmente fora da região de recorte. Consulte `lfClipPrecision` o membro `LOGFONT` na estrutura no Windows SDK para obter uma lista de valores.

Para usar uma fonte somente leitura incorporada, um aplicativo deve especificar CLIP_ENCAPSULATE.

Para obter uma rotação consistente de fontes de dispositivo, TrueType e vetor, um aplicativo pode usar o operador OR para combinar o valor CLIP_LH_ANGLES com qualquer um dos outros valores *nClipPrecision.* Se a CLIP_LH_ANGLES bit estiver definida, a rotação para todas as fontes depende se a orientação do sistema de coordenadas é canhota ou destra. (Para obter mais informações sobre a orientação dos sistemas de coordenadas, consulte a descrição do parâmetro *nOrientation.)* Se CLIP_LH_ANGLES não estiver definida, as fontes do dispositivo sempre giram no sentido anti-horário, mas a rotação de outras fontes depende da orientação do sistema de coordenadas.

*nQualidade*<br/>
Especifica a qualidade de saída da fonte, que define o quão cuidadosamente o GDI deve tentar combinar os atributos da fonte lógica com os de uma fonte física real. Consulte `lfQuality` o membro `LOGFONT` na estrutura no Windows SDK para obter uma lista de valores.

*nPitchAndFamily*<br/>
Especifica o tom e a família da fonte. Consulte `lfPitchAndFamily` o membro `LOGFONT` na estrutura no Windows SDK para obter uma lista de valores e mais informações.

*Lpszfacename*<br/>
Um `CString` ou ponteiro para uma seqüência de seqüência de terminadas nula que especifica o nome do tipo da fonte. O comprimento desta seqüência não deve exceder 30 caracteres. A função Windows [EnumFontFamilies](/windows/win32/api/wingdi/nf-wingdi-enumfontfamiliesw) pode ser usada para enumerar todas as fontes disponíveis no momento. Se *lpszFacename* for NULL, o GDI usará um tipo de tipo independente do dispositivo.

### <a name="return-value"></a>Valor retornado

Não zero se bem sucedido; caso contrário, 0.

### <a name="remarks"></a>Comentários

A fonte pode ser selecionada posteriormente como fonte para qualquer contexto do dispositivo.

A `CreateFont` função não cria uma nova fonte Windows GDI. Ele simplesmente seleciona a correspondência mais próxima das fontes físicas disponíveis para o GDI.

Os aplicativos podem usar as configurações padrão para a maioria dos parâmetros ao criar uma fonte lógica. Os parâmetros que devem ser sempre dados valores específicos são *nHeight* e *lpszFacename*. Se *nHeight* e *lpszFacename* não forem definidos pelo aplicativo, a fonte lógica criada depende do dispositivo.

Quando você terminar `CFont` com o `CreateFont` objeto criado `CDC::SelectObject` pela função, use para selecionar uma `CFont` fonte diferente no contexto do dispositivo e, em seguida, exclua o objeto que não é mais necessário.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCDocView#71](../../mfc/codesnippet/cpp/cfont-class_2.cpp)]

## <a name="cfontcreatefontindirect"></a><a name="createfontindirect"></a>cfont::CreateFontIndirect

Inicializa um `CFont` objeto com as características dadas em uma estrutura [LOGFONT.](/windows/win32/api/wingdi/ns-wingdi-logfontw)

```
BOOL CreateFontIndirect(const LOGFONT* lpLogFont);
```

### <a name="parameters"></a>Parâmetros

*lpLogFont*<br/>
Aponta para `LOGFONT` uma estrutura que define as características da fonte lógica.

### <a name="return-value"></a>Valor retornado

Não zero se bem sucedido; caso contrário, 0.

### <a name="remarks"></a>Comentários

A fonte pode ser selecionada posteriormente como a fonte atual para qualquer dispositivo.

Esta fonte tem as características especificadas na estrutura [LOGFONT.](/windows/win32/api/wingdi/ns-wingdi-logfontw) Quando a fonte é selecionada usando a função [CDC::SelectObject](../../mfc/reference/cdc-class.md#selectobject) member, o mapeador de fonte GDI tenta combinar a fonte lógica com uma fonte física existente. Se o mapeador de fonte não encontrar uma correspondência exata para a fonte lógica, ele fornece uma fonte alternativa cujas características correspondem ao maior número possível de características solicitadas.

Quando você não `CFont` precisar mais do `CreateFontIndirect` objeto `CDC::SelectObject` criado pela função, use para selecionar `CFont` uma fonte diferente no contexto do dispositivo e, em seguida, exclua o objeto que não é mais necessário.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCDocView#72](../../mfc/codesnippet/cpp/cfont-class_3.cpp)]

## <a name="cfontcreatepointfont"></a><a name="createpointfont"></a>cfont::CreatePointFont

Esta função fornece uma maneira simples de criar uma fonte de um tipo de letra especificado e tamanho de ponto.

```
BOOL CreatePointFont(
    int nPointSize,
    LPCTSTR lpszFaceName,
    CDC* pDC = NULL);
```

### <a name="parameters"></a>Parâmetros

*nPointSize*<br/>
Altura da fonte solicitada em décimos de ponto. (Por exemplo, passe 120 para solicitar uma fonte de 12 pontos.)

*Lpszfacename*<br/>
Um `CString` ou ponteiro para uma seqüência de seqüência de terminadas nula que especifica o nome do tipo da fonte. O comprimento desta seqüência não deve exceder 30 caracteres. A função 'EnumFontFamilies do Windows pode ser usada para enumerar todas as fontes disponíveis no momento. Se *lpszFaceName* for NULL, o GDI usará um tipo de tipo independente do dispositivo.

*pDC*<br/>
Ponteiro para o objeto [CDC](../../mfc/reference/cdc-class.md) a ser usado para converter a altura em *nPointSize* para unidades lógicas. Se NULL, um contexto de dispositivo de tela é usado para a conversão.

### <a name="return-value"></a>Valor retornado

Não zero se bem sucedido, caso contrário 0.

### <a name="remarks"></a>Comentários

Ele converte automaticamente a altura em *nPointSize* para unidades lógicas usando o objeto CDC apontado pelo *pDC*.

Quando terminar com `CFont` o objeto `CreatePointFont` criado pela função, primeiro selecione a fonte `CFont` fora do contexto do dispositivo e, em seguida, exclua o objeto.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCDocView#73](../../mfc/codesnippet/cpp/cfont-class_4.cpp)]

## <a name="cfontcreatepointfontindirect"></a><a name="createpointfontindirect"></a>cfont::CreatePointFontIndirect

Esta função é a mesma que `lfHeight` [CreateFontIndirect,](#createfontindirect) exceto que o membro do `LOGFONT` é interpretado em décimos de um ponto em vez de unidades de dispositivo.

```
BOOL CreatePointFontIndirect(
    const LOGFONT* lpLogFont,
    CDC* pDC = NULL);
```

### <a name="parameters"></a>Parâmetros

*lpLogFont*<br/>
Aponta para uma estrutura [LOGFONT](/windows/win32/api/wingdi/ns-wingdi-logfontw) que define as características da fonte lógica. O `lfHeight` membro `LOGFONT` da estrutura é medido em décimos de um ponto em vez de unidades lógicas. (Por exemplo, `lfHeight` defina para 120 para solicitar uma fonte de 12 pontos.)

*pDC*<br/>
Ponteiro para o objeto [CDC](../../mfc/reference/cdc-class.md) a ser `lfHeight` usado para converter a altura em unidades lógicas. Se NULL, um contexto de dispositivo de tela é usado para a conversão.

### <a name="return-value"></a>Valor retornado

Não zero se bem sucedido, caso contrário 0.

### <a name="remarks"></a>Comentários

Esta função converte automaticamente `lfHeight` a altura em unidades lógicas usando o `LOGFONT` objeto CDC apontado pelo *pDC* antes de passar a estrutura para o Windows.

Quando terminar com `CFont` o objeto `CreatePointFontIndirect` criado pela função, primeiro selecione a fonte `CFont` fora do contexto do dispositivo e, em seguida, exclua o objeto.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCDocView#74](../../mfc/codesnippet/cpp/cfont-class_5.cpp)]

## <a name="cfontfromhandle"></a><a name="fromhandle"></a>cfont::FromHandle

Retorna um ponteiro `CFont` a um objeto quando dado uma alça HFONT a um objeto de fonte Windows GDI.

```
static CFont* PASCAL FromHandle(HFONT hFont);
```

### <a name="parameters"></a>Parâmetros

*Hfont*<br/>
Uma alça HFONT para uma fonte do Windows.

### <a name="return-value"></a>Valor retornado

Um ponteiro `CFont` para um objeto se for bem sucedido; caso contrário, NULL.

### <a name="remarks"></a>Comentários

Se `CFont` um objeto ainda não estiver conectado `CFont` à alça, um objeto temporário será criado e anexado. Este `CFont` objeto temporário só é válido até a próxima vez que o aplicativo tiver tempo ocioso em seu loop de evento, momento em que todos os objetos gráficos temporários são excluídos. Outra maneira de dizer isso é que o objeto temporário é válido apenas durante o processamento de uma mensagem de janela.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCDocView#75](../../mfc/codesnippet/cpp/cfont-class_6.cpp)]

## <a name="cfontgetlogfont"></a><a name="getlogfont"></a>fonte de texto::getlogfont

Chame esta função para recuperar `LOGFONT` uma `CFont`cópia da estrutura para .

```
int GetLogFont(LOGFONT* pLogFont);
```

### <a name="parameters"></a>Parâmetros

*pLogFont*<br/>
Ponteiro para a estrutura [LOGFONT](/windows/win32/api/wingdi/ns-wingdi-logfontw) para receber as informações da fonte.

### <a name="return-value"></a>Valor retornado

Não zero se a função for bem sucedida, caso contrário 0.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCDocView#76](../../mfc/codesnippet/cpp/cfont-class_7.cpp)]

## <a name="cfontoperator-hfont"></a><a name="operator_hfont"></a>CFont::operador HFONT

Use este operador para obter a alça Windows GDI da fonte anexada ao `CFont` objeto.

```
operator HFONT() const;
```

### <a name="return-value"></a>Valor retornado

A alça do objeto de fonte `CFont` Windows GDI anexado se for bem-sucedido; caso contrário, NULL.

### <a name="remarks"></a>Comentários

Uma vez que este operador é `CFont` usado automaticamente para conversões `CFont` de fontes e [texto,](/windows/win32/gdi/fonts-and-text)você pode passar objetos para funções que esperam HFONTs.

Para obter mais informações sobre o uso de objetos gráficos, consulte [Objetos Gráficos](/windows/win32/gdi/graphic-objects) no SDK do Windows.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCDocView#77](../../mfc/codesnippet/cpp/cfont-class_8.cpp)]

## <a name="see-also"></a>Confira também

[Amostra de MFC HIERSVR](../../overview/visual-cpp-samples.md)<br/>
[Classe CGdiObject](../../mfc/reference/cgdiobject-class.md)<br/>
[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)
