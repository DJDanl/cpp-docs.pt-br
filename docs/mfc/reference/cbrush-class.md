---
title: Classe CBrush
ms.date: 11/04/2016
f1_keywords:
- CBrush
- AFXWIN/CBrush
- AFXWIN/CBrush::CBrush
- AFXWIN/CBrush::CreateBrushIndirect
- AFXWIN/CBrush::CreateDIBPatternBrush
- AFXWIN/CBrush::CreateHatchBrush
- AFXWIN/CBrush::CreatePatternBrush
- AFXWIN/CBrush::CreateSolidBrush
- AFXWIN/CBrush::CreateSysColorBrush
- AFXWIN/CBrush::FromHandle
- AFXWIN/CBrush::GetLogBrush
helpviewer_keywords:
- CBrush [MFC], CBrush
- CBrush [MFC], CreateBrushIndirect
- CBrush [MFC], CreateDIBPatternBrush
- CBrush [MFC], CreateHatchBrush
- CBrush [MFC], CreatePatternBrush
- CBrush [MFC], CreateSolidBrush
- CBrush [MFC], CreateSysColorBrush
- CBrush [MFC], FromHandle
- CBrush [MFC], GetLogBrush
ms.assetid: e5ef2c62-dd95-4973-9090-f52f605900e1
ms.openlocfilehash: 15132bb5497886638edfe431ae769dd446785df8
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81352486"
---
# <a name="cbrush-class"></a>Classe CBrush

Encapsula um pincel gdi (Windows graphics device interface) de interface de dispositivo gráfico.

## <a name="syntax"></a>Sintaxe

```
class CBrush : public CGdiObject
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[CBrush::CBrush](#cbrush)|Constrói um objeto `CBrush`.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[Cbrush::CreateBrushIndirect](#createbrushindirect)|Inicializa um pincel com o estilo, cor e padrão especificados em uma estrutura [LOGBRUSH.](/windows/win32/api/wingdi/ns-wingdi-logbrush)|
|[Cbrush::CreateDIBPatternBrush](#createdibpatternbrush)|Inicializa um pincel com um padrão especificado por um bitmap independente do dispositivo (DIB).|
|[Cbrush::CreateHatchBrush](#createhatchbrush)|Inicializa um pincel com o padrão e a cor eclodidos especificados.|
|[Cbrush::CreatePatternBrush](#createpatternbrush)|Inicializa um pincel com um padrão especificado por um bitmap.|
|[Cbrush::CreateSolidBrush](#createsolidbrush)|Inicializa um pincel com a cor sólida especificada.|
|[CBrush::CreateSysColorBrush](#createsyscolorbrush)|Cria um pincel que é a cor padrão do sistema.|
|[Cbrush::FromHandle](#fromhandle)|Retorna um ponteiro `CBrush` para um objeto quando `HBRUSH` dado uma alça a um objeto do Windows.|
|[Cbrush::GetLogbrush](#getlogbrush)|Obtém uma estrutura [LOGBRUSH.](/windows/win32/api/wingdi/ns-wingdi-logbrush)|

### <a name="public-operators"></a>Operadores públicos

|Nome|Descrição|
|----------|-----------------|
|[CBrush::operador HBRUSH](#operator_hbrush)|Retorna a alça do `CBrush` Windows anexada ao objeto.|

## <a name="remarks"></a>Comentários

Para usar `CBrush` um objeto, construa `CBrush` um `CDC` objeto e passe-o para qualquer função de membro que exija um pincel.

Os pincéis podem ser sólidos, eclodidos ou padronizados.

Para obter `CBrush`mais informações sobre , consulte [Objetos Gráficos](../../mfc/graphic-objects.md).

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[Cobject](../../mfc/reference/cobject-class.md)

[Cgdiobject](../../mfc/reference/cgdiobject-class.md)

`CBrush`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxwin.h

## <a name="cbrushcbrush"></a><a name="cbrush"></a>CBrush::CBrush

Constrói um objeto `CBrush`.

```
CBrush();
CBrush(COLORREF crColor);
CBrush(int nIndex, COLORREF crColor);
explicit CBrush(CBitmap* pBitmap);
```

### <a name="parameters"></a>Parâmetros

*Crcolor*<br/>
Especifica a cor do primeiro plano do pincel como uma cor RGB. Se a escova for eclodida, este parâmetro especifica a cor da eclosão.

*nIndex*<br/>
Especifica o estilo de escotilha do pincel. Pode ser qualquer um dos seguintes valores:

- HS_BDIAGONAL escotilha para baixo (da esquerda para a direita) a 45 graus

- HS_CROSS crosshatch horizontal e vertical

- HS_DIAGCROSS Crosshatch a 45 graus

- HS_FDIAGONAL escotilha ascendente (da esquerda para a direita) a 45 graus

- escotilha horizontal HS_HORIZONTAL

- escotilha vertical HS_VERTICAL

*Pbitmap*<br/>
Aponta para `CBitmap` um objeto que especifica um bitmap com o qual o pincel pinta.

### <a name="remarks"></a>Comentários

`CBrush`tem quatro construtores sobrecarregados. O construtor sem argumentos constrói um `CBrush` objeto não inicializado que deve ser inicializado antes de ser usado.

Se você usar o construtor sem argumentos, você `CBrush` deve inicializar o objeto resultante com [CreateSolidBrush,](#createsolidbrush) [CreateHatchBrush,](#createhatchbrush) [CreateBrushIndirect,](#createbrushindirect) [CreatePatternBrush](#createpatternbrush)ou [CreateDIBPatternBrush](#createdibpatternbrush). Se você usar um dos construtores que toma argumentos, então nenhuma inicialização adicional é necessária. Os construtores com argumentos podem abrir uma exceção se os erros forem encontrados, enquanto o construtor sem argumentos sempre terá sucesso.

O construtor com um único parâmetro [COLORREF](/windows/win32/gdi/colorref) constrói um pincel sólido com a cor especificada. A cor especifica um valor RGB e pode ser construída com a macro RGB no WINDOWS. H.

O construtor com dois parâmetros constrói uma escova de escotilha. O parâmetro *nIndex* especifica o índice de um padrão eclodido. O parâmetro *crColor* especifica a cor.

O construtor com `CBitmap` um parâmetro constrói um pincel padronizado. O parâmetro identifica um bitmap. Presume-se que o bitmap tenha sido criado usando [CBitmap::CreateBitmap,](../../mfc/reference/cbitmap-class.md#createbitmap) [CBitmap::CreateBitmapIndirect,](../../mfc/reference/cbitmap-class.md#createbitmapindirect) [CBitmap:LoadBitmap](../../mfc/reference/cbitmap-class.md#loadbitmap)ou [CBitmap:CreateCompatibleBitmap](../../mfc/reference/cbitmap-class.md#createcompatiblebitmap). O tamanho mínimo para um bitmap ser usado em um padrão de preenchimento é de 8 pixels por 8 pixels.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCDocView#21](../../mfc/codesnippet/cpp/cbrush-class_1.cpp)]

## <a name="cbrushcreatebrushindirect"></a><a name="createbrushindirect"></a>Cbrush::CreateBrushIndirect

Inicializa um pincel com um estilo, cor e padrão especificados em uma estrutura [LOGBRUSH.](/windows/win32/api/wingdi/ns-wingdi-logbrush)

```
BOOL CreateBrushIndirect(const LOGBRUSH* lpLogBrush);
```

### <a name="parameters"></a>Parâmetros

*lpLogbrush*<br/>
Aponta para uma estrutura [LOGBRUSH](/windows/win32/api/wingdi/ns-wingdi-logbrush) que contém informações sobre o pincel.

### <a name="return-value"></a>Valor retornado

Diferente de zero se a função for bem-sucedida; caso contrário, 0.

### <a name="remarks"></a>Comentários

O pincel pode ser selecionado posteriormente como o pincel atual para qualquer contexto do dispositivo.

Um pincel criado usando um bitmap monocromático (1 plano, 1 bit por pixel) é desenhado usando as cores de texto e fundo atuais. Os pixels representados por um bit definido para 0 serão desenhados com a cor de texto atual. Os pixels representados por um bit definido para 1 serão desenhados com a cor de fundo atual.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCDocView#22](../../mfc/codesnippet/cpp/cbrush-class_2.cpp)]

## <a name="cbrushcreatedibpatternbrush"></a><a name="createdibpatternbrush"></a>Cbrush::CreateDIBPatternBrush

Inicializa um pincel com o padrão especificado por um bitmap independente do dispositivo (DIB).

```
BOOL CreateDIBPatternBrush(
    HGLOBAL hPackedDIB,
    UINT nUsage);

BOOL CreateDIBPatternBrush(
    const void* lpPackedDIB,
    UINT nUsage);
```

### <a name="parameters"></a>Parâmetros

*hPackedDIB*<br/>
Identifica um objeto de memória global contendo um bitmap (DIB) empacotado e independente de dispositivo.

*nUso*<br/>
Especifica se `bmiColors[]` os campos da estrutura de dados [BITMAPINFO](/windows/win32/api/wingdi/ns-wingdi-bitmapinfo) (uma parte do "DIB embalado") contêm valores ou índices Explícitos de RGB na paleta lógica realizada atualmente. O parâmetro deve ser um dos seguintes valores:

- DIB_PAL_COLORS A tabela de cores consiste em uma matriz de índices de 16 bits.

- DIB_RGB_COLORS A tabela de cores contém valores RGB literais.

*lpPackedDIB*<br/>
Aponta para um DIB embalado `BITMAPINFO` que consiste em uma estrutura imediatamente seguida por uma matriz de bytes definindo os pixels do bitmap.

### <a name="return-value"></a>Valor retornado

Não zero se bem sucedido; caso contrário, 0.

### <a name="remarks"></a>Comentários

O pincel pode ser selecionado posteriormente para qualquer contexto de dispositivo que suporte operações de raster.

As duas versões diferem na maneira como você lida com o DIB:

- Na primeira versão, para obter uma alça para `GlobalAlloc` o DIB, você chama a função Windows para alocar um bloco de memória global e, em seguida, preencher a memória com o DIB embalado.

- Na segunda versão, não é `GlobalAlloc` necessário ligar para alocar memória para o DIB embalado.

Um DIB embalado consiste `BITMAPINFO` em uma estrutura de dados imediatamente seguida pela matriz de bytes que define os pixels do bitmap. Os bitmaps usados como padrões de preenchimento devem ser de 8 pixels por 8 pixels. Se o bitmap for maior, o Windows criará um padrão de preenchimento usando apenas os bits correspondentes às primeiras 8 linhas e 8 colunas de pixels no canto superior esquerdo do bitmap.

Quando um aplicativo seleciona um pincel de padrão DIB de duas cores em um contexto de dispositivo monocromático, o Windows ignora as cores especificadas no DIB e, em vez disso, exibe o pincel padrão usando as cores de texto e de fundo atuais do contexto do dispositivo. Os pixels mapeados para a primeira cor (no offset 0 na tabela de cores DIB) do DIB são exibidos usando a cor do texto. Os pixels mapeados para a segunda cor (no offset 1 na tabela de cores) são exibidos usando a cor de fundo.

Para obter informações sobre como usar as seguintes funções do Windows, consulte o SDK do Windows:

- [CreateDIBPatternBrush](/windows/win32/api/wingdi/nf-wingdi-createdibpatternbrush) (Esta função é fornecida apenas para compatibilidade com aplicativos gravados para versões do Windows anteriores a 3.0; use a `CreateDIBPatternBrushPt` função.)

- [CreateDIBPatternBrushPt](/windows/win32/api/wingdi/nf-wingdi-createdibpatternbrushpt) (Esta função deve ser usada para aplicativos baseados no Win32.)

- [Globalalloc](/windows/win32/api/winbase/nf-winbase-globalalloc)

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCDocView#23](../../mfc/codesnippet/cpp/cbrush-class_3.cpp)]

## <a name="cbrushcreatehatchbrush"></a><a name="createhatchbrush"></a>Cbrush::CreateHatchBrush

Inicializa um pincel com o padrão e a cor eclodidos especificados.

```
BOOL CreateHatchBrush(
    int nIndex,
    COLORREF crColor);
```

### <a name="parameters"></a>Parâmetros

*nIndex*<br/>
Especifica o estilo de escotilha do pincel. Pode ser qualquer um dos seguintes valores:

- HS_BDIAGONAL escotilha para baixo (da esquerda para a direita) a 45 graus

- HS_CROSS crosshatch horizontal e vertical

- HS_DIAGCROSS Crosshatch a 45 graus

- HS_FDIAGONAL escotilha ascendente (da esquerda para a direita) a 45 graus

- escotilha horizontal HS_HORIZONTAL

- escotilha vertical HS_VERTICAL

*Crcolor*<br/>
Especifica a cor do primeiro plano do pincel como uma cor RGB (a cor dos hatches). Consulte [COLORREF](/windows/win32/gdi/colorref) no Windows SDK para obter mais informações.

### <a name="return-value"></a>Valor retornado

Não zero se bem sucedido; caso contrário, 0.

### <a name="remarks"></a>Comentários

O pincel pode ser selecionado posteriormente como o pincel atual para qualquer contexto do dispositivo.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCDocView#24](../../mfc/codesnippet/cpp/cbrush-class_4.cpp)]

## <a name="cbrushcreatepatternbrush"></a><a name="createpatternbrush"></a>Cbrush::CreatePatternBrush

Inicializa um pincel com um padrão especificado por um bitmap.

```
BOOL CreatePatternBrush(CBitmap* pBitmap);
```

### <a name="parameters"></a>Parâmetros

*Pbitmap*<br/>
Identifica um bitmap.

### <a name="return-value"></a>Valor retornado

Não zero se bem sucedido; caso contrário, 0.

### <a name="remarks"></a>Comentários

O pincel pode ser selecionado posteriormente para qualquer contexto de dispositivo que suporte operações de raster. O bitmap identificado pelo *pBitmap* é tipicamente inicializado usando a função [CBitmap::CreateBitmap,](../../mfc/reference/cbitmap-class.md#createbitmap) [CBitmap::CreateBitmapIndirect,](../../mfc/reference/cbitmap-class.md#createbitmapindirect) [CBitmap::LoadBitmap](../../mfc/reference/cbitmap-class.md#loadbitmap)ou [CBitmap:CreateCompatibleBitmap](../../mfc/reference/cbitmap-class.md#createcompatiblebitmap) function.

Os bitmaps usados como padrões de preenchimento devem ser de 8 pixels por 8 pixels. Se o bitmap for maior, o Windows usará apenas os bits correspondentes às primeiras 8 linhas e colunas de pixels no canto superior esquerdo do bitmap.

Uma escova de padrão pode ser excluída sem afetar o bitmap associado. Isso significa que o bitmap pode ser usado para criar qualquer número de pincéis padrão.

Um pincel criado usando um bitmap monocromático (1 plano de cores, 1 bit por pixel) é desenhado usando o texto atual e as cores de fundo. Os pixels representados por um bit set para 0 são desenhados com a cor de texto atual. Os pixels representados por um bit definido para 1 são desenhados com a cor de fundo atual.

Para obter informações sobre como usar [CreatePatternBrush](/windows/win32/api/wingdi/nf-wingdi-createpatternbrush), uma função do Windows, consulte o SDK do Windows.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCDocView#25](../../mfc/codesnippet/cpp/cbrush-class_5.cpp)]

## <a name="cbrushcreatesolidbrush"></a><a name="createsolidbrush"></a>Cbrush::CreateSolidBrush

Inicializa um pincel com uma cor sólida especificada.

```
BOOL CreateSolidBrush(COLORREF crColor);
```

### <a name="parameters"></a>Parâmetros

*Crcolor*<br/>
Uma [estrutura COLORREF](/windows/win32/gdi/colorref) que especifica a cor do pincel. A cor especifica um valor RGB e pode ser construída com a macro RGB no WINDOWS. H.

### <a name="return-value"></a>Valor retornado

Não zero se bem sucedido; caso contrário, 0.

### <a name="remarks"></a>Comentários

O pincel pode ser selecionado posteriormente como o pincel atual para qualquer contexto do dispositivo.

Quando um aplicativo tiver terminado usando `CreateSolidBrush`o pincel criado por , ele deve selecionar a escova fora do contexto do dispositivo.

### <a name="example"></a>Exemplo

  Veja o exemplo de [CBrush::CBrush](#cbrush).

## <a name="cbrushcreatesyscolorbrush"></a><a name="createsyscolorbrush"></a>CBrush::CreateSysColorBrush

Inicializa uma cor de pincel.

```
BOOL CreateSysColorBrush(int nIndex);
```

### <a name="parameters"></a>Parâmetros

*nIndex*<br/>
Especifica um índice de cor. Este valor corresponde à cor usada para pintar um dos 21 elementos da janela. Consulte [GetSysColor](/windows/win32/api/winuser/nf-winuser-getsyscolor) no Windows SDK para obter uma lista de valores.

### <a name="return-value"></a>Valor retornado

Não zero se bem sucedido; caso contrário, 0.

### <a name="remarks"></a>Comentários

O pincel pode ser selecionado posteriormente como o pincel atual para qualquer contexto do dispositivo.

Quando um aplicativo tiver terminado usando `CreateSysColorBrush`o pincel criado por , ele deve selecionar a escova fora do contexto do dispositivo.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCDocView#26](../../mfc/codesnippet/cpp/cbrush-class_6.cpp)]

## <a name="cbrushfromhandle"></a><a name="fromhandle"></a>Cbrush::FromHandle

Retorna um ponteiro `CBrush` para um objeto quando dado uma alça a um objeto [Windows HBRUSH.](#operator_hbrush)

```
static CBrush* PASCAL FromHandle(HBRUSH hBrush);
```

### <a name="parameters"></a>Parâmetros

*Hbrush*<br/>
Manuseie um pincel GDI do Windows.

### <a name="return-value"></a>Valor retornado

Um ponteiro `CBrush` para um objeto se for bem sucedido; caso contrário, NULL.

### <a name="remarks"></a>Comentários

Se `CBrush` um objeto ainda não estiver conectado `CBrush` à alça, um objeto temporário será criado e anexado. Este `CBrush` objeto temporário só é válido até a próxima vez que o aplicativo tiver tempo ocioso em seu loop de eventos. Neste momento, todos os objetos gráficos temporários são excluídos. Em outras palavras, o objeto temporário é válido apenas durante o processamento de uma mensagem de janela.

Para obter mais informações sobre o uso de objetos gráficos, consulte [Objetos Gráficos](/windows/win32/gdi/graphic-objects) no SDK do Windows.

### <a name="example"></a>Exemplo

  Veja o exemplo de [CBrush::CBrush](#cbrush).

## <a name="cbrushgetlogbrush"></a><a name="getlogbrush"></a>Cbrush::GetLogbrush

Ligue para esta função `LOGBRUSH` de membro para recuperar a estrutura.

```
int GetLogBrush(LOGBRUSH* pLogBrush);
```

### <a name="parameters"></a>Parâmetros

*Plogbrush*<br/>
Aponta para uma estrutura [LOGBRUSH](/windows/win32/api/wingdi/ns-wingdi-logbrush) que contém informações sobre o pincel.

### <a name="return-value"></a>Valor retornado

Se a função for bem sucedida e *o pLogBrush* for um ponteiro válido, o valor de retorno será o número de bytes armazenados no buffer.

Se a função for bem-sucedida e *o pLogBrush* for NULL, o valor de retorno é o número de bytes necessários para manter as informações que a função armazenaria no buffer.

Se a função falhar, o valor de retorno será 0.

### <a name="remarks"></a>Comentários

A `LOGBRUSH` estrutura define o estilo, a cor e o padrão de um pincel.

Por exemplo, `GetLogBrush` chamada para combinar com a cor ou padrão particular de um bitmap.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCDocView#27](../../mfc/codesnippet/cpp/cbrush-class_7.cpp)]

## <a name="cbrushoperator-hbrush"></a><a name="operator_hbrush"></a>CBrush::operador HBRUSH

Use este operador para obter a alça `CBrush` Windows GDI anexada do objeto.

```
operator HBRUSH() const;
```

### <a name="return-value"></a>Valor retornado

Se for bem-sucedido, uma alça para `CBrush` o objeto GDI do Windows representado pelo objeto; caso contrário, NULL.

### <a name="remarks"></a>Comentários

Este operador é um operador de fundição, que suporta o uso direto de um objeto HBRUSH.

Para obter mais informações sobre o uso de objetos gráficos, consulte [Objetos Gráficos](/windows/win32/gdi/graphic-objects) no SDK do Windows.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCDocView#28](../../mfc/codesnippet/cpp/cbrush-class_8.cpp)]

## <a name="see-also"></a>Confira também

[Amostra de MFC PROPDLG](../../overview/visual-cpp-samples.md)<br/>
[Classe CGdiObject](../../mfc/reference/cgdiobject-class.md)<br/>
[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classe CBitmap](../../mfc/reference/cbitmap-class.md)<br/>
[Classe CDC](../../mfc/reference/cdc-class.md)
