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
ms.openlocfilehash: a99d8c8022d23f627320b66c3f376be803c9c839
ms.sourcegitcommit: 3e8fa01f323bc5043a48a0c18b855d38af3648d4
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/06/2020
ms.locfileid: "78876042"
---
# <a name="cbrush-class"></a>Classe CBrush

Encapsula um pincel da interface de dispositivo de gráficos do Windows (GDI).

## <a name="syntax"></a>Sintaxe

```
class CBrush : public CGdiObject
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|DESCRIÇÃO|
|----------|-----------------|
|[CBrush::CBrush](#cbrush)|Constrói um objeto `CBrush`.|

### <a name="public-methods"></a>Métodos Públicos

|Nome|DESCRIÇÃO|
|----------|-----------------|
|[CBrush::CreateBrushIndirect](#createbrushindirect)|Inicializa um pincel com o estilo, a cor e o padrão especificados em uma estrutura [LOGBRUSH](/windows/win32/api/wingdi/ns-wingdi-logbrush) .|
|[CBrush::CreateDIBPatternBrush](#createdibpatternbrush)|Inicializa um pincel com um padrão especificado por um bitmap independente de dispositivo (DIB).|
|[CBrush::CreateHatchBrush](#createhatchbrush)|Inicializa um pincel com a cor e o padrão hachurados especificados.|
|[CBrush::CreatePatternBrush](#createpatternbrush)|Inicializa um pincel com um padrão especificado por um bitmap.|
|[CBrush::CreateSolidBrush](#createsolidbrush)|Inicializa um pincel com a cor sólida especificada.|
|[CBrush::CreateSysColorBrush](#createsyscolorbrush)|Cria um pincel que é a cor padrão do sistema.|
|[CBrush:: FromHandle](#fromhandle)|Retorna um ponteiro para um objeto `CBrush` ao receber um identificador para um objeto do Windows `HBRUSH`.|
|[CBrush::GetLogBrush](#getlogbrush)|Obtém uma estrutura [LOGBRUSH](/windows/win32/api/wingdi/ns-wingdi-logbrush) .|

### <a name="public-operators"></a>Operadores públicos

|Nome|DESCRIÇÃO|
|----------|-----------------|
|[Operador CBrush:: Operator HBRUSH](#operator_hbrush)|Retorna o identificador do Windows anexado ao objeto `CBrush`.|

## <a name="remarks"></a>Comentários

Para usar um objeto `CBrush`, construa um objeto `CBrush` e passe-o para qualquer função membro `CDC` que exija um pincel.

Os pincéis podem ser sólidos, hachurados ou padronizados.

Para obter mais informações sobre `CBrush`, consulte [objetos gráficos](../../mfc/graphic-objects.md).

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[CObject](../../mfc/reference/cobject-class.md)

[CGdiObject](../../mfc/reference/cgdiobject-class.md)

`CBrush`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** Afxwin. h

##  <a name="cbrush"></a>CBrush::CBrush

Constrói um objeto `CBrush`.

```
CBrush();
CBrush(COLORREF crColor);
CBrush(int nIndex, COLORREF crColor);
explicit CBrush(CBitmap* pBitmap);
```

### <a name="parameters"></a>Parâmetros

*crColor*<br/>
Especifica a cor de primeiro plano do pincel como uma cor RGB. Se o pincel estiver hachurado, esse parâmetro especificará a cor da hachura.

*nIndex*<br/>
Especifica o estilo de hachura do pincel. Pode ser qualquer um dos seguintes valores:

- HS_BDIAGONAL Hachura vertical (da esquerda para a direita) às 45 graus

- HS_CROSS hachura horizontal e vertical

- HS_DIAGCROSS hachura com 45 graus

- HS_FDIAGONAL hachurada para cima (da esquerda para a direita) às 45 graus

- HS_HORIZONTAL hachura horizontal

- HS_VERTICAL hachura vertical

*pBitmap*<br/>
Aponta para um objeto `CBitmap` que especifica um bitmap com o qual o pincel pinta.

### <a name="remarks"></a>Comentários

`CBrush` tem quatro construtores sobrecarregados. O construtor sem argumentos constrói um objeto de `CBrush` não inicializado que deve ser inicializado antes que possa ser usado.

Se você usar o construtor sem argumentos, deverá inicializar o objeto `CBrush` resultante com [CreateSolidBrush](#createsolidbrush), [CreateHatchBrush](#createhatchbrush), [CreateBrushIndirect](#createbrushindirect), [CreatePatternBrush](#createpatternbrush)ou [CreateDIBPatternBrush](#createdibpatternbrush). Se você usar um dos construtores que usa argumentos, nenhuma inicialização adicional será necessária. Os construtores com argumentos podem gerar uma exceção se forem encontrados erros, enquanto o construtor sem argumentos sempre terá sucesso.

O construtor com um único parâmetro [COLORREF](/windows/win32/gdi/colorref) constrói um pincel sólido com a cor especificada. A cor especifica um valor RGB e pode ser construída com a macro RGB no WINDOWS. T.

O construtor com dois parâmetros constrói um pincel de hachura. O parâmetro *nIndex* especifica o índice de um padrão hachurado. O parâmetro *crColor* especifica a cor.

O construtor com um parâmetro `CBitmap` constrói um pincel padronizado. O parâmetro identifica um bitmap. Presume-se que o bitmap tenha sido criado usando [CBitmap:: CreateBitmap](../../mfc/reference/cbitmap-class.md#createbitmap), [CBitmap:: CreateBitmapIndirect](../../mfc/reference/cbitmap-class.md#createbitmapindirect), [CBitmap:: LoadBitmap](../../mfc/reference/cbitmap-class.md#loadbitmap)ou [CBitmap:: CreateCompatibleBitmap](../../mfc/reference/cbitmap-class.md#createcompatiblebitmap). O tamanho mínimo de um bitmap a ser usado em um padrão de preenchimento é 8 pixels por 8 pixels.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCDocView#21](../../mfc/codesnippet/cpp/cbrush-class_1.cpp)]

##  <a name="createbrushindirect"></a>CBrush::CreateBrushIndirect

Inicializa um pincel com um estilo, cor e padrão especificados em uma estrutura [LOGBRUSH](/windows/win32/api/wingdi/ns-wingdi-logbrush) .

```
BOOL CreateBrushIndirect(const LOGBRUSH* lpLogBrush);
```

### <a name="parameters"></a>Parâmetros

*lpLogBrush*<br/>
Aponta para uma estrutura [LOGBRUSH](/windows/win32/api/wingdi/ns-wingdi-logbrush) que contém informações sobre o pincel.

### <a name="return-value"></a>Valor retornado

Diferente de zero se a função for bem-sucedida; caso contrário, 0.

### <a name="remarks"></a>Comentários

O pincel pode ser selecionado subsequentemente como o pincel atual para qualquer contexto de dispositivo.

Um pincel criado usando um bitmap monocromático (1 plano, 1 bit por pixel) é desenhado usando o texto atual e as cores de plano de fundo. Os pixels representados por um bit definido como 0 serão desenhados com a cor do texto atual. Os pixels representados por um bit definido como 1 serão desenhados com a cor do plano de fundo atual.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCDocView#22](../../mfc/codesnippet/cpp/cbrush-class_2.cpp)]

##  <a name="createdibpatternbrush"></a>CBrush::CreateDIBPatternBrush

Inicializa um pincel com o padrão especificado por um bitmap independente de dispositivo (DIB).

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
Identifica um objeto de memória global que contém um bitmap independente de dispositivo (DIB) empacotado.

*nUsage*<br/>
Especifica se os campos de `bmiColors[]` da estrutura de dados [BITMAPINFO](/windows/win32/api/wingdi/ns-wingdi-bitmapinfo) (uma parte do "DIB compactado") contêm valores RGB explícitos ou índices na paleta lógica atualmente realizada. O parâmetro deve ser um dos seguintes valores:

- DIB_PAL_COLORS tabela de cores consiste em uma matriz de índices de 16 bits.

- DIB_RGB_COLORS tabela de cores contém valores RGB literais.

*lpPackedDIB*<br/>
Aponta para um DIB compactado que consiste em uma estrutura de `BITMAPINFO` imediatamente seguida por uma matriz de bytes que define os pixels do bitmap.

### <a name="return-value"></a>Valor retornado

Diferente de zero, se for bem-sucedido; caso contrário, 0.

### <a name="remarks"></a>Comentários

O pincel pode ser selecionado subsequentemente para qualquer contexto de dispositivo que ofereça suporte a operações de varredura.

As duas versões diferem na maneira como você lida com a DIB:

- Na primeira versão, para obter um identificador para o DIB, você chama a função `GlobalAlloc` do Windows para alocar um bloco de memória global e, em seguida, preencher a memória com o DIB embalado.

- Na segunda versão, não é necessário chamar `GlobalAlloc` para alocar memória para o DIB embalado.

Um DIB empacotado consiste em uma estrutura de dados `BITMAPINFO` imediatamente seguida pela matriz de bytes que define os pixels do bitmap. Os bitmaps usados como padrões de preenchimento devem ter 8 pixels por 8 pixels. Se o bitmap for maior, o Windows criará um padrão de preenchimento usando apenas os bits correspondentes às primeiras 8 linhas e 8 colunas de pixels no canto superior esquerdo do bitmap.

Quando um aplicativo seleciona um pincel de padrão DIB de duas cores em um contexto de dispositivo monocromático, o Windows ignora as cores especificadas na DIB e, em vez disso, exibe o pincel de padrão usando o texto atual e as cores de plano de fundo do contexto do dispositivo. Os pixels mapeados para a primeira cor (no deslocamento 0 na tabela de cores DIB) do DIB são exibidos usando a cor do texto. Os pixels mapeados para a segunda cor (no deslocamento 1 na tabela de cores) são exibidos usando a cor do plano de fundo.

Para obter informações sobre como usar as seguintes funções do Windows, consulte o SDK do Windows:

- [CreateDIBPatternBrush](/windows/win32/api/wingdi/nf-wingdi-createdibpatternbrush) (essa função é fornecida apenas para compatibilidade com aplicativos escritos para versões do Windows anteriores à 3,0; Use a função `CreateDIBPatternBrushPt`.)

- [CreateDIBPatternBrushPt](/windows/win32/api/wingdi/nf-wingdi-createdibpatternbrushpt) (essa função deve ser usada para aplicativos baseados no Win32).

- [GlobalAlloc](/windows/win32/api/winbase/nf-winbase-globalalloc)

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCDocView#23](../../mfc/codesnippet/cpp/cbrush-class_3.cpp)]

##  <a name="createhatchbrush"></a>CBrush::CreateHatchBrush

Inicializa um pincel com a cor e o padrão hachurados especificados.

```
BOOL CreateHatchBrush(
    int nIndex,
    COLORREF crColor);
```

### <a name="parameters"></a>Parâmetros

*nIndex*<br/>
Especifica o estilo de hachura do pincel. Pode ser qualquer um dos seguintes valores:

- HS_BDIAGONAL Hachura vertical (da esquerda para a direita) às 45 graus

- HS_CROSS hachura horizontal e vertical

- HS_DIAGCROSS hachura com 45 graus

- HS_FDIAGONAL hachurada para cima (da esquerda para a direita) às 45 graus

- HS_HORIZONTAL hachura horizontal

- HS_VERTICAL hachura vertical

*crColor*<br/>
Especifica a cor de primeiro plano do pincel como uma cor RGB (a cor das hachuras). Consulte [COLORREF](/windows/win32/gdi/colorref) no SDK do Windows para obter mais informações.

### <a name="return-value"></a>Valor retornado

Diferente de zero, se for bem-sucedido; caso contrário, 0.

### <a name="remarks"></a>Comentários

O pincel pode ser selecionado subsequentemente como o pincel atual para qualquer contexto de dispositivo.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCDocView#24](../../mfc/codesnippet/cpp/cbrush-class_4.cpp)]

##  <a name="createpatternbrush"></a>CBrush::CreatePatternBrush

Inicializa um pincel com um padrão especificado por um bitmap.

```
BOOL CreatePatternBrush(CBitmap* pBitmap);
```

### <a name="parameters"></a>Parâmetros

*pBitmap*<br/>
Identifica um bitmap.

### <a name="return-value"></a>Valor retornado

Diferente de zero, se for bem-sucedido; caso contrário, 0.

### <a name="remarks"></a>Comentários

O pincel pode ser selecionado subsequentemente para qualquer contexto de dispositivo que ofereça suporte a operações de varredura. O bitmap identificado pelo *pBitmap* é normalmente inicializado usando a função [CBitmap:: CreateBitmap](../../mfc/reference/cbitmap-class.md#createbitmap), [CBitmap:: CreateBitmapIndirect](../../mfc/reference/cbitmap-class.md#createbitmapindirect), [CBitmap:: LoadBitmap](../../mfc/reference/cbitmap-class.md#loadbitmap)ou [CBitmap:: CreateCompatibleBitmap](../../mfc/reference/cbitmap-class.md#createcompatiblebitmap) .

Os bitmaps usados como padrões de preenchimento devem ter 8 pixels por 8 pixels. Se o bitmap for maior, o Windows usará apenas os bits correspondentes às primeiras 8 linhas e colunas de pixels no canto superior esquerdo do bitmap.

Um pincel de padrão pode ser excluído sem afetar o bitmap associado. Isso significa que o bitmap pode ser usado para criar qualquer número de pincéis de padrão.

Um pincel criado usando um bitmap monocromático (1 plano de cores, 1 bit por pixel) é desenhado usando o texto atual e as cores de plano de fundo. Os pixels representados por um bit definido como 0 são desenhados com a cor do texto atual. Os pixels representados por um bit definido como 1 são desenhados com a cor do plano de fundo atual.

Para obter informações sobre como usar o [CreatePatternBrush](/windows/win32/api/wingdi/nf-wingdi-createpatternbrush), uma função do Windows, consulte a SDK do Windows.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCDocView#25](../../mfc/codesnippet/cpp/cbrush-class_5.cpp)]

##  <a name="createsolidbrush"></a>CBrush::CreateSolidBrush

Inicializa um pincel com uma cor sólida especificada.

```
BOOL CreateSolidBrush(COLORREF crColor);
```

### <a name="parameters"></a>Parâmetros

*crColor*<br/>
Uma estrutura [COLORREF](/windows/win32/gdi/colorref) que especifica a cor do pincel. A cor especifica um valor RGB e pode ser construída com a macro RGB no WINDOWS. T.

### <a name="return-value"></a>Valor retornado

Diferente de zero, se for bem-sucedido; caso contrário, 0.

### <a name="remarks"></a>Comentários

O pincel pode ser selecionado subsequentemente como o pincel atual para qualquer contexto de dispositivo.

Quando um aplicativo termina de usar o pincel criado pelo `CreateSolidBrush`, ele deve selecionar o pincel fora do contexto do dispositivo.

### <a name="example"></a>Exemplo

  Consulte o exemplo de [CBrush:: CBrush](#cbrush).

##  <a name="createsyscolorbrush"></a>CBrush::CreateSysColorBrush

Inicializa uma cor de pincel.

```
BOOL CreateSysColorBrush(int nIndex);
```

### <a name="parameters"></a>Parâmetros

*nIndex*<br/>
Especifica um índice de cores. Esse valor corresponde à cor usada para pintar um dos 21 elementos da janela. Consulte [GetSysColor](/windows/win32/api/winuser/nf-winuser-getsyscolor) no SDK do Windows para obter uma lista de valores.

### <a name="return-value"></a>Valor retornado

Diferente de zero, se for bem-sucedido; caso contrário, 0.

### <a name="remarks"></a>Comentários

O pincel pode ser selecionado subsequentemente como o pincel atual para qualquer contexto de dispositivo.

Quando um aplicativo termina de usar o pincel criado pelo `CreateSysColorBrush`, ele deve selecionar o pincel fora do contexto do dispositivo.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCDocView#26](../../mfc/codesnippet/cpp/cbrush-class_6.cpp)]

##  <a name="fromhandle"></a>CBrush:: FromHandle

Retorna um ponteiro para um objeto `CBrush` ao receber um identificador para um objeto [HBRUSH](#operator_hbrush) do Windows.

```
static CBrush* PASCAL FromHandle(HBRUSH hBrush);
```

### <a name="parameters"></a>Parâmetros

*hBrush*<br/>
IDENTIFICADOR para um pincel GDI do Windows.

### <a name="return-value"></a>Valor retornado

Um ponteiro para um objeto `CBrush` se for bem-sucedido; caso contrário, NULL.

### <a name="remarks"></a>Comentários

Se um objeto `CBrush` ainda não estiver anexado ao identificador, um objeto de `CBrush` temporário será criado e anexado. Esse objeto de `CBrush` temporário é válido somente até a próxima vez que o aplicativo tiver tempo ocioso em seu loop de eventos. Neste momento, todos os objetos gráficos temporários são excluídos. Em outras palavras, o objeto temporário é válido somente durante o processamento de uma mensagem de janela.

Para obter mais informações sobre como usar objetos gráficos, consulte [objetos gráficos](/windows/win32/gdi/graphic-objects) na SDK do Windows.

### <a name="example"></a>Exemplo

  Consulte o exemplo de [CBrush:: CBrush](#cbrush).

##  <a name="getlogbrush"></a>CBrush::GetLogBrush

Chame essa função de membro para recuperar a estrutura de `LOGBRUSH`.

```
int GetLogBrush(LOGBRUSH* pLogBrush);
```

### <a name="parameters"></a>Parâmetros

*pLogBrush*<br/>
Aponta para uma estrutura [LOGBRUSH](/windows/win32/api/wingdi/ns-wingdi-logbrush) que contém informações sobre o pincel.

### <a name="return-value"></a>Valor retornado

Se a função for bem sucedido e *pLogBrush* for um ponteiro válido, o valor de retorno será o número de bytes armazenados no buffer.

Se a função for bem sucedido e *pLogBrush* for NULL, o valor de retorno será o número de bytes necessários para manter as informações que a função armazenaria no buffer.

Se a função falhar, o valor de retorno será 0.

### <a name="remarks"></a>Comentários

A estrutura de `LOGBRUSH` define o estilo, a cor e o padrão de um pincel.

Por exemplo, chame `GetLogBrush` para corresponder a cor ou padrão específico de um bitmap.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCDocView#27](../../mfc/codesnippet/cpp/cbrush-class_7.cpp)]

##  <a name="operator_hbrush"></a>Operador CBrush:: Operator HBRUSH

Use esse operador para obter o identificador GDI do Windows anexado do objeto `CBrush`.

```
operator HBRUSH() const;
```

### <a name="return-value"></a>Valor retornado

Se for bem-sucedido, um identificador para o objeto GDI do Windows representado pelo objeto `CBrush`; caso contrário, NULL.

### <a name="remarks"></a>Comentários

Esse operador é um operador de conversão, que dá suporte ao uso direto de um objeto HBRUSH.

Para obter mais informações sobre como usar objetos gráficos, consulte [objetos gráficos](/windows/win32/gdi/graphic-objects) na SDK do Windows.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCDocView#28](../../mfc/codesnippet/cpp/cbrush-class_8.cpp)]

## <a name="see-also"></a>Veja também

[Exemplo de PROPDLG do MFC](../../overview/visual-cpp-samples.md)<br/>
[Classe CGdiObject](../../mfc/reference/cgdiobject-class.md)<br/>
[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classe CBitmap](../../mfc/reference/cbitmap-class.md)<br/>
[Classe CDC](../../mfc/reference/cdc-class.md)
