---
title: Classe CFont
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
ms.openlocfilehash: c37b2f657105e0065e0cddb2c508424bd6c89b0a
ms.sourcegitcommit: fcb48824f9ca24b1f8bd37d647a4d592de1cc925
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/15/2019
ms.locfileid: "69506498"
---
# <a name="cfont-class"></a>Classe CFont

Encapsula uma fonte GDI (interface gráfica do dispositivo) do Windows e fornece funções de membro para manipular a fonte.

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
|[CFont::CreateFont](#createfont)|Inicializa um `CFont` com as características especificadas.|
|[CFont::CreateFontIndirect](#createfontindirect)|Inicializa um `CFont` objeto com as características fornecidas em uma `LOGFONT` estrutura.|
|[CFont::CreatePointFont](#createpointfont)|Inicializa um `CFont` com a altura especificada, medida em décimos de um ponto e face de tipos.|
|[CFont::CreatePointFontIndirect](#createpointfontindirect)|Igual a `CreateFontIndirect` , exceto que a altura da fonte é medida em décimos de um ponto em vez de unidades lógicas.|
|[CFont:: FromHandle](#fromhandle)|Retorna um ponteiro para um `CFont` objeto quando um HFONT do Windows é fornecido.|
|[CFont::GetLogFont](#getlogfont)|Preenche um `LOGFONT` com informações sobre a fonte lógica anexada `CFont` ao objeto.|

### <a name="public-operators"></a>Operadores públicos

|Nome|Descrição|
|----------|-----------------|
|[Operador CFont:: Operator HFONT](#operator_hfont)|Retorna o identificador de fonte GDI do Windows anexado `CFont` ao objeto.|

## <a name="remarks"></a>Comentários

Para usar um `CFont` objeto, construa um `CFont` objeto e anexe uma fonte do Windows a ele com [CreateFont](#createfont), [CreateFontIndirect](#createfontindirect), [CreatePointFont](#createpointfont)ou [CreatePointFontIndirect](#createpointfontindirect)e, em seguida, use o membro do objeto funções para manipular a fonte.

As `CreatePointFont` funções `CreatePointFontIndirect` e geralmente são mais fáceis de usar `CreateFont` do `CreateFontIndirect` que ou porque fazem a conversão para a altura da fonte de um tamanho de ponto para unidades lógicas automaticamente.

Para obter mais informações `CFont`sobre o, consulte [objetos gráficos](../../mfc/graphic-objects.md).

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[CObject](../../mfc/reference/cobject-class.md)

[CGdiObject](../../mfc/reference/cgdiobject-class.md)

`CFont`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** Afxwin. h

##  <a name="cfont"></a>CFont::CFont

Constrói um objeto `CFont`.

```
CFont();
```

### <a name="remarks"></a>Comentários

O objeto resultante deve ser inicializado `CreateFont`com `CreateFontIndirect`, `CreatePointFont`, ou `CreatePointFontIndirect` antes que possa ser usado.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCDocView#70](../../mfc/codesnippet/cpp/cfont-class_1.cpp)]

##  <a name="createfont"></a>  CFont::CreateFont

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

*nHeight*<br/>
Especifica a altura desejada (em unidades lógicas) da fonte. Consulte o `lfHeight` membro da estrutura [LOGFONT](/windows/win32/api/wingdi/ns-wingdi-logfontw)no SDK do Windows para obter uma descrição. O valor absoluto de *nHeight* não deve exceder 16.384 unidades de dispositivo depois que ele é convertido. Para todas as comparações de altura, o mapeador de fontes procura a maior fonte que não exceda o tamanho solicitado ou a menor fonte se todas as fontes excederem o tamanho solicitado.

*nWidth*<br/>
Especifica a largura média (em unidades lógicas) de caracteres na fonte. Se *nWidth* for 0, a taxa de proporção do dispositivo será correspondida em relação à taxa de proporção de digitalização das fontes disponíveis para localizar a correspondência mais próxima, que é determinada pelo valor absoluto da diferença.

*nEscapement*<br/>
Especifica o ângulo (em unidades de 0,1 graus) entre o vetor de escape e o eixo x da superfície de exibição. O vetor de escape é a linha por meio das origens do primeiro e do último caracteres em uma linha. O ângulo é medido no sentido anti-horário a partir do eixo x. Consulte o `lfEscapement` membro `LOGFONT` na estrutura na SDK do Windows para obter mais informações.

*nOrientation*<br/>
Especifica o ângulo (em unidades de 0,1 graus) entre a linha de base de um caractere e o eixo x. O ângulo é medido no sentido anti-horário a partir do eixo x para sistemas de coordenadas nos quais a direção y está inoperante e no sentido horário do eixo x para sistemas de coordenadas nos quais a direção y está ativa.

*nWeight*<br/>
Especifica a espessura da fonte (em Inked pixels por 1000). Consulte o membro *lfWeight* na `LOGFONT` estrutura na SDK do Windows para obter mais informações. Os valores descritos são aproximados; a aparência real depende da face de tipos. Algumas fontes têm apenas pesos FW_NORMAL, FW_REGULAR e FW_BOLD. Se FW_DONTCARE for especificado, será usado um peso padrão.

*bItalic*<br/>
Especifica se a fonte está em itálico.

*bUnderline*<br/>
Especifica se a fonte é sublinhada.

*cStrikeOut*<br/>
Especifica se os caracteres na fonte são riscados. Especifica uma fonte de riscado se definido como um valor diferente de zero.

*nCharSet*<br/>
Especifica o conjunto de caracteres da fonte que `lfCharSet` o membro `LOGFONT` na estrutura na SDK do Windows para obter uma lista de valores.

O conjunto de caracteres OEM é dependente do sistema.

As fontes com outros conjuntos de caracteres podem existir no sistema. Um aplicativo que usa uma fonte com um conjunto de caracteres desconhecido não deve tentar converter nem interpretar cadeias de caracteres que devem ser renderizadas com essa fonte. Em vez disso, as cadeias de caracteres devem ser passadas diretamente para o driver do dispositivo de saída.

O mapeador de fontes não usa o valor DEFAULT_CHARSET. Um aplicativo pode usar esse valor para permitir que o nome e o tamanho de uma fonte descrevam totalmente a fonte lógica. Se uma fonte com o nome especificado não existir, uma fonte de qualquer conjunto de caracteres poderá ser substituída pela fonte especificada. Para evitar resultados inesperados, os aplicativos devem usar o valor DEFAULT_CHARSET com moderação.

*nOutPrecision*<br/>
Especifica a precisão de saída desejada. A precisão de saída define o quão próximo a saída deve corresponder à altura, à largura, à orientação do caractere, ao escape e à densidade da fonte solicitada. Consulte o `lfOutPrecision` membro `LOGFONT` na estrutura na SDK do Windows para obter uma lista de valores e mais informações.

*nClipPrecision*<br/>
Especifica a precisão de recorte desejada. A precisão de recorte define como recortar caracteres que estão parcialmente fora da região de recorte. Consulte o `lfClipPrecision` membro `LOGFONT` na estrutura na SDK do Windows para obter uma lista de valores.

Para usar uma fonte somente leitura inserida, um aplicativo deve especificar CLIP_ENCAPSULATE.

Para obter uma rotação consistente de fontes de dispositivo, TrueType e vetoriais, um aplicativo pode usar o operador OR para combinar o valor CLIP_LH_ANGLES com qualquer um dos outros valores de *nClipPrecision* . Se o bit CLIP_LH_ANGLES for definido, a rotação para todas as fontes dependerá se a orientação do sistema de coordenadas é à esquerda ou à direita. (Para obter mais informações sobre a orientação dos sistemas de coordenadas, consulte a descrição do parâmetro *nOrientation* .) Se CLIP_LH_ANGLES não for definido, as fontes de dispositivo sempre serão giradas no sentido anti-horário, mas a rotação de outras fontes dependerá da orientação do sistema de coordenadas.

*nQuality*<br/>
Especifica a qualidade de saída da fonte, que define com que frequência a GDI deve tentar corresponder os atributos de fonte lógica para aqueles de uma fonte física real. Consulte o `lfQuality` membro `LOGFONT` na estrutura na SDK do Windows para obter uma lista de valores.

*nPitchAndFamily*<br/>
Especifica a densidade e a família da fonte. Consulte o `lfPitchAndFamily` membro `LOGFONT` na estrutura na SDK do Windows para obter uma lista de valores e mais informações.

*lpszFacename*<br/>
Um `CString` ponteiro ou para uma cadeia de caracteres terminada em nulo que especifica o nome de tipo da fonte. O comprimento dessa cadeia de caracteres não deve exceder 30 caracteres. A função [EnumFontFamilies](/windows/win32/api/wingdi/nf-wingdi-enumfontfamiliesw) do Windows pode ser usada para enumerar todas as fontes disponíveis no momento. Se *lpszFacename* for NULL, o GDI usará um tipo independente de dispositivo.

### <a name="return-value"></a>Valor de retorno

Diferente de zero, se for bem-sucedido; caso contrário, 0.

### <a name="remarks"></a>Comentários

A fonte pode ser selecionada subseqüentemente como a fonte para qualquer contexto de dispositivo.

A `CreateFont` função não cria uma nova fonte GDI do Windows. Ele simplesmente seleciona a correspondência mais próxima das fontes físicas disponíveis para a GDI.

Os aplicativos podem usar as configurações padrão para a maioria dos parâmetros ao criar uma fonte lógica. Os parâmetros que devem sempre receber valores específicos são *nHeight* e *lpszFacename*. Se *nHeight* e *lpszFacename* não forem definidos pelo aplicativo, a fonte lógica criada será dependente do dispositivo.

Quando você terminar com o `CFont` objeto criado `CreateFont` pela função, use `CDC::SelectObject` para selecionar uma fonte diferente no contexto do dispositivo e, em seguida, `CFont` exclua o objeto que não é mais necessário.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCDocView#71](../../mfc/codesnippet/cpp/cfont-class_2.cpp)]

##  <a name="createfontindirect"></a>  CFont::CreateFontIndirect

Inicializa um `CFont` objeto com as características fornecidas em uma estrutura [LOGFONT](/windows/win32/api/wingdi/ns-wingdi-logfontw).

```
BOOL CreateFontIndirect(const LOGFONT* lpLogFont);
```

### <a name="parameters"></a>Parâmetros

*lpLogFont*<br/>
Aponta para uma `LOGFONT` estrutura que define as características da fonte lógica.

### <a name="return-value"></a>Valor de retorno

Diferente de zero, se for bem-sucedido; caso contrário, 0.

### <a name="remarks"></a>Comentários

A fonte pode ser selecionada subseqüentemente como a fonte atual para qualquer dispositivo.

Essa fonte tem as características especificadas na estrutura [LOGFONT](/windows/win32/api/wingdi/ns-wingdi-logfontw) . Quando a fonte é selecionada usando a função de membro [CDC:: SelectObject](../../mfc/reference/cdc-class.md#selectobject) , o mapeador de fontes GDI tenta corresponder a fonte lógica com uma fonte física existente. Se o mapeador de fontes não conseguir encontrar uma correspondência exata para a fonte lógica, ele fornecerá uma fonte alternativa cujas características correspondam ao máximo possível das características solicitadas.

Quando você não precisar mais do `CFont` objeto criado `CreateFontIndirect` pela função, use `CDC::SelectObject` para selecionar uma fonte diferente no contexto do dispositivo e, em seguida, `CFont` exclua o objeto que não é mais necessário.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCDocView#72](../../mfc/codesnippet/cpp/cfont-class_3.cpp)]

##  <a name="createpointfont"></a>  CFont::CreatePointFont

Essa função fornece uma maneira simples de criar uma fonte de um tipo e tamanho de ponto especificados.

```
BOOL CreatePointFont(
    int nPointSize,
    LPCTSTR lpszFaceName,
    CDC* pDC = NULL);
```

### <a name="parameters"></a>Parâmetros

*nPointSize*<br/>
Altura da fonte solicitada em décimos de um ponto. (Por exemplo, passe 120 para solicitar uma fonte de 12 pontos.)

*lpszFaceName*<br/>
Um `CString` ponteiro ou para uma cadeia de caracteres terminada em nulo que especifica o nome de tipo da fonte. O comprimento dessa cadeia de caracteres não deve exceder 30 caracteres. A função EnumFontFamilies do Windows pode ser usada para enumerar todas as fontes disponíveis no momento. Se *lpszFacename* for NULL, o GDI usará um tipo independente de dispositivo.

*pDC*<br/>
Ponteiro para o objeto [CDC](../../mfc/reference/cdc-class.md) a ser usado para converter a altura em *nPointSize* em unidades lógicas. Se for NULL, um contexto de dispositivo de tela será usado para a conversão.

### <a name="return-value"></a>Valor de retorno

Diferente de zero, se for bem-sucedido, caso contrário 0.

### <a name="remarks"></a>Comentários

Ele converte automaticamente a altura em *nPointSize* em unidades lógicas usando o objeto CDC apontado pelo *PDC*.

Quando você terminar com o `CFont` objeto criado `CreatePointFont` pela função, primeiro selecione a fonte fora do contexto do dispositivo e, em seguida, `CFont` exclua o objeto.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCDocView#73](../../mfc/codesnippet/cpp/cfont-class_4.cpp)]

##  <a name="createpointfontindirect"></a>  CFont::CreatePointFontIndirect

Essa função é igual a [CreateFontIndirect](#createfontindirect) , exceto pelo fato `lfHeight` de que o `LOGFONT` membro de é interpretado em décimos de um ponto em vez de unidades de dispositivo.

```
BOOL CreatePointFontIndirect(
    const LOGFONT* lpLogFont,
    CDC* pDC = NULL);
```

### <a name="parameters"></a>Parâmetros

*lpLogFont*<br/>
Aponta para uma estrutura [LOGFONT](/windows/win32/api/wingdi/ns-wingdi-logfontw) que define as características da fonte lógica. O `lfHeight` membro`LOGFONT` da estrutura é medido em décimos de um ponto em vez de unidades lógicas. (Por exemplo, defina `lfHeight` como 120 para solicitar uma fonte de 12 pontos.)

*pDC*<br/>
Ponteiro para o objeto [CDC](../../mfc/reference/cdc-class.md) a ser usado para converter a altura em `lfHeight` unidades lógicas. Se for NULL, um contexto de dispositivo de tela será usado para a conversão.

### <a name="return-value"></a>Valor de retorno

Diferente de zero, se for bem-sucedido, caso contrário 0.

### <a name="remarks"></a>Comentários

Essa função converte automaticamente a altura em `lfHeight` unidades lógicas usando o objeto CDC apontado pelo *PDC* antes de passar `LOGFONT` a estrutura para o Windows.

Quando você terminar com o `CFont` objeto criado `CreatePointFontIndirect` pela função, primeiro selecione a fonte fora do contexto do dispositivo e, em seguida, `CFont` exclua o objeto.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCDocView#74](../../mfc/codesnippet/cpp/cfont-class_5.cpp)]

##  <a name="fromhandle"></a>CFont:: FromHandle

Retorna um ponteiro para um `CFont` objeto quando um identificador HFONT é atribuído a um objeto de fonte GDI do Windows.

```
static CFont* PASCAL FromHandle(HFONT hFont);
```

### <a name="parameters"></a>Parâmetros

*hFont*<br/>
Um identificador HFONT para uma fonte do Windows.

### <a name="return-value"></a>Valor de retorno

Um ponteiro para um `CFont` objeto se for bem-sucedido; caso contrário, NULL.

### <a name="remarks"></a>Comentários

Se um `CFont` objeto ainda não estiver anexado ao identificador, um objeto temporário `CFont` será criado e anexado. Esse objeto `CFont` temporário é válido somente até a próxima vez que o aplicativo tiver tempo ocioso em seu loop de eventos, quando todos os objetos gráficos temporários forem excluídos. Outra maneira de dizer isso é que o objeto temporário é válido somente durante o processamento de uma mensagem de janela.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCDocView#75](../../mfc/codesnippet/cpp/cfont-class_6.cpp)]

##  <a name="getlogfont"></a>  CFont::GetLogFont

Chame essa função para recuperar uma cópia da `LOGFONT` estrutura para. `CFont`

```
int GetLogFont(LOGFONT* pLogFont);
```

### <a name="parameters"></a>Parâmetros

*pLogFont*<br/>
Ponteiro para a estrutura [LOGFONT](/windows/win32/api/wingdi/ns-wingdi-logfontw) para receber as informações da fonte.

### <a name="return-value"></a>Valor de retorno

Diferente de zero se a função for realizada com sucesso, caso contrário, 0.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCDocView#76](../../mfc/codesnippet/cpp/cfont-class_7.cpp)]

##  <a name="operator_hfont"></a>Operador CFont:: Operator HFONT

Use esse operador para obter o identificador GDI do Windows da fonte anexada ao `CFont` objeto.

```
operator HFONT() const;
```

### <a name="return-value"></a>Valor de retorno

O identificador do objeto de fonte GDI do Windows anexado `CFont` a se bem-sucedido; caso contrário, NULL.

### <a name="remarks"></a>Comentários

Como esse operador é usado automaticamente para conversões de `CFont` para [fontes e texto](/windows/win32/gdi/fonts-and-text), você pode passar `CFont` objetos para funções que esperam HFONTs.

Para obter mais informações sobre como usar objetos gráficos, consulte [objetos gráficos](/windows/win32/gdi/graphic-objects) na SDK do Windows.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCDocView#77](../../mfc/codesnippet/cpp/cfont-class_8.cpp)]

## <a name="see-also"></a>Consulte também

[Exemplo de HIERSVR do MFC](../../overview/visual-cpp-samples.md)<br/>
[Classe CGdiObject](../../mfc/reference/cgdiobject-class.md)<br/>
[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)
