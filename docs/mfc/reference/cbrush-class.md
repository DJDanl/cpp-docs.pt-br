---
title: Classe CBrush | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: reference
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
dev_langs:
- C++
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
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: c01cc08368e5c02a5513569e7230ab064d06163f
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46386711"
---
# <a name="cbrush-class"></a>Classe CBrush

Encapsula um pincel de interface (GDI) do dispositivo de gráficos Windows.

## <a name="syntax"></a>Sintaxe

```
class CBrush : public CGdiObject
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores Públicos

|Nome|Descrição|
|----------|-----------------|
|[CBrush::CBrush](#cbrush)|Constrói um objeto `CBrush`.|

### <a name="public-methods"></a>Métodos Públicos

|Nome|Descrição|
|----------|-----------------|
|[CBrush::CreateBrushIndirect](#createbrushindirect)|Inicializa um pincel com o estilo, cor e padrão especificado em um [LOGBRUSH](/windows/desktop/api/wingdi/ns-wingdi-taglogbrush) estrutura.|
|[CBrush::CreateDIBPatternBrush](#createdibpatternbrush)|Inicializa um pincel com um padrão especificado por um bitmap independente de dispositivo (DIB).|
|[CBrush::CreateHatchBrush](#createhatchbrush)|Inicializa um pincel com o padrão de hachurado especificado e a cor.|
|[CBrush::CreatePatternBrush](#createpatternbrush)|Inicializa um pincel com um padrão especificado por um bitmap.|
|[CBrush::CreateSolidBrush](#createsolidbrush)|Inicializa um pincel de cor sólida especificada.|
|[CBrush::CreateSysColorBrush](#createsyscolorbrush)|Cria um pincel que é a cor padrão do sistema.|
|[CBrush::FromHandle](#fromhandle)|Retorna um ponteiro para um `CBrush` do objeto quando é fornecido um identificador para um Windows `HBRUSH` objeto.|
|[CBrush::GetLogBrush](#getlogbrush)|Obtém uma [LOGBRUSH](/windows/desktop/api/wingdi/ns-wingdi-taglogbrush) estrutura.|

### <a name="public-operators"></a>Operadores públicos

|Nome|Descrição|
|----------|-----------------|
|[CBrush::operator HBRUSH](#operator_hbrush)|Retorna o identificador do Windows anexado ao `CBrush` objeto.|

## <a name="remarks"></a>Comentários

Para usar um `CBrush` do objeto, construa uma `CBrush` do objeto e passá-lo para qualquer `CDC` função de membro que exige um pincel.

Pincéis podem ser sólidos, hatched ou padronizado.

Para obter mais informações sobre `CBrush`, consulte [objetos gráficos](../../mfc/graphic-objects.md).

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[CObject](../../mfc/reference/cobject-class.md)

[CGdiObject](../../mfc/reference/cgdiobject-class.md)

`CBrush`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxwin. h

##  <a name="cbrush"></a>  CBrush::CBrush

Constrói um objeto `CBrush`.

```
CBrush();
CBrush(COLORREF crColor);
CBrush(int nIndex, COLORREF crColor);
explicit CBrush(CBitmap* pBitmap);
```

### <a name="parameters"></a>Parâmetros

*crColor*<br/>
Especifica a cor de primeiro plano do pincel como uma cor RGB. Se o pincel é hatched, esse parâmetro especifica a cor da hachura.

*nIndex*<br/>
Especifica o estilo de hachura do pincel. Ele pode ser qualquer um dos seguintes valores:

- Hachura HS_BDIAGONAL descendente (da esquerda para a direita) em 45 graus

- HS_CROSS Horizontal e vertical hachura

- HS_DIAGCROSS hachura a 45 graus

- HS_FDIAGONAL para cima hachura (da esquerda para a direita) em 45 graus

- Hachura Horizontal HS_HORIZONTAL

- Hachura Vertical HS_VERTICAL

*pBitmap*<br/>
Aponta para um `CBitmap` objeto que especifica um bitmap com o qual o pincel pinta.

### <a name="remarks"></a>Comentários

`CBrush` tem quatro construtores sobrecarregados. O construtor sem argumentos constrói não inicializado `CBrush` objeto deve ser inicializado antes que ele pode ser usado.

Se você usar o construtor sem argumentos, você deve inicializar resultante `CBrush` do objeto com [CreateSolidBrush](#createsolidbrush), [CreateHatchBrush](#createhatchbrush), [CreateBrushIndirect](#createbrushindirect), [CreatePatternBrush](#createpatternbrush), ou [CreateDIBPatternBrush](#createdibpatternbrush). Se você usar um dos construtores que aceita argumentos, em seguida, nenhuma outra inicialização é necessária. Os construtores com argumentos podem lançar uma exceção se forem encontrados erros, enquanto o construtor sem argumentos sempre terá êxito.

O construtor com um único [COLORREF](/windows/desktop/gdi/colorref) parâmetro constrói um pincel sólido com a cor especificada. A cor Especifica um valor de RGB e pode ser construída com a macro RGB no WINDOWS. H.

O construtor com dois parâmetros constrói um pincel de hachura. O *nIndex* parâmetro especifica o índice de um padrão de tracejada. O *crColor* parâmetro especifica a cor.

O construtor com um `CBitmap` parâmetro constrói um pincel padronizado. O parâmetro identifica um bitmap. O bitmap deve ter sido criado usando [CBitmap::CreateBitmap](../../mfc/reference/cbitmap-class.md#createbitmap), [CBitmap::CreateBitmapIndirect](../../mfc/reference/cbitmap-class.md#createbitmapindirect), [CBitmap::LoadBitmap](../../mfc/reference/cbitmap-class.md#loadbitmap), ou [ CBitmap::CreateCompatibleBitmap](../../mfc/reference/cbitmap-class.md#createcompatiblebitmap). O tamanho mínimo para um bitmap a ser usado em um padrão de preenchimento é 8 pixels por 8.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCDocView#21](../../mfc/codesnippet/cpp/cbrush-class_1.cpp)]

##  <a name="createbrushindirect"></a>  CBrush::CreateBrushIndirect

Inicializa um pincel com um estilo, cor e padrão especificado em um [LOGBRUSH](/windows/desktop/api/wingdi/ns-wingdi-taglogbrush) estrutura.

```
BOOL CreateBrushIndirect(const LOGBRUSH* lpLogBrush);
```

### <a name="parameters"></a>Parâmetros

*lpLogBrush*<br/>
Aponta para um [LOGBRUSH](/windows/desktop/api/wingdi/ns-wingdi-taglogbrush) estrutura que contém informações sobre o pincel.

### <a name="return-value"></a>Valor de retorno

Diferente de zero se a função for bem-sucedida; caso contrário, 0.

### <a name="remarks"></a>Comentários

O pincel, posteriormente, pode ser selecionado como o pincel atual para qualquer contexto de dispositivo.

Um pincel criado usando um bitmap monocromático (plano 1, 1 bit por pixel) é desenhado usando as cores de plano de fundo e texto atuais. Pixels representados por um bit definido como 0 serão desenhadas com a cor do texto atual. Pixels representados por um bit definido como 1 serão desenhadas com a cor de plano de fundo atual.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCDocView#22](../../mfc/codesnippet/cpp/cbrush-class_2.cpp)]

##  <a name="createdibpatternbrush"></a>  CBrush::CreateDIBPatternBrush

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
Identifica um objeto de memória global contendo um compactado independentes de dispositivo DIB (bitmap).

*Nuso*<br/>
Especifica se o `bmiColors[]` campos do [BITMAPINFO](../../mfc/reference/bitmapinfo-structure.md) a estrutura de dados (parte do "empacotados DIB") contêm explícita de valores RGB ou índices para a paleta lógica realizada no momento. O parâmetro deve ser um dos seguintes valores:

- A tabela de cores DIB_PAL_COLORS consiste em uma matriz de índices de 16 bits.

- A tabela de cores DIB_RGB_COLORS contém valores RGB literais.

*lpPackedDIB*<br/>
Aponta para DIB compactado consiste em um `BITMAPINFO` estrutura seguida imediatamente por uma matriz de bytes definindo os pixels do bitmap.

### <a name="return-value"></a>Valor de retorno

Diferente de zero se bem-sucedido; Caso contrário, 0.

### <a name="remarks"></a>Comentários

O pincel, posteriormente, pode ser selecionado para qualquer contexto de dispositivo que dá suporte a operações de varredura.

As duas versões diferem na maneira como você manipula o DIB:

- Na primeira versão, para obter um identificador para o DIB você chamar o Windows `GlobalAlloc` função para alocar um bloco de memória global e, em seguida, preencha a memória com o DIB compactado.

- Na segunda versão, não é necessário chamar `GlobalAlloc` alocar memória para o DIB compactado.

DIB compactado consiste em um `BITMAPINFO` seguida imediatamente por que a matriz de bytes que define os pixels do bitmap de estrutura de dados. Bitmaps usados como padrões de preenchimento deve ser 8 pixels por 8. Se o bitmap for maior, o Windows cria um padrão de preenchimento usando apenas os bits correspondentes para as 8 primeiras linhas e colunas de 8 pixels no canto superior esquerdo do bitmap.

Quando um aplicativo seleciona um pincel de padrão DIB duas cores em um contexto de dispositivo monocromático, o Windows ignora as cores especificadas no DIB e em vez disso, exibem o pincel padrão usando as cores de plano de fundo e texto atuais do contexto do dispositivo. Pixels mapeados para a primeira cor (no deslocamento 0 na tabela de cores DIB) do DIB são exibidos usando a cor do texto. Pixels mapeados para a segunda cor (no deslocamento 1 na tabela de cores) são exibidos usando a cor do plano de fundo.

Para obter informações sobre como usar as seguintes funções do Windows, consulte o SDK do Windows:

- [CreateDIBPatternBrush](/windows/desktop/api/wingdi/nf-wingdi-createdibpatternbrush) (essa função é fornecida somente para compatibilidade com aplicativos escritos para versões do Windows anteriores à 3.0; use o `CreateDIBPatternBrushPt` função.)

- [CreateDIBPatternBrushPt](/windows/desktop/api/wingdi/nf-wingdi-createdibpatternbrushpt) (essa função deve ser usada para aplicativos baseados em Win32.)

- [GlobalAlloc](/windows/desktop/api/winbase/nf-winbase-globalalloc)

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCDocView#23](../../mfc/codesnippet/cpp/cbrush-class_3.cpp)]

##  <a name="createhatchbrush"></a>  CBrush::CreateHatchBrush

Inicializa um pincel com o padrão de hachurado especificado e a cor.

```
BOOL CreateHatchBrush(
    int nIndex,
    COLORREF crColor);
```

### <a name="parameters"></a>Parâmetros

*nIndex*<br/>
Especifica o estilo de hachura do pincel. Ele pode ser qualquer um dos seguintes valores:

- Hachura HS_BDIAGONAL descendente (da esquerda para a direita) em 45 graus

- HS_CROSS Horizontal e vertical hachura

- HS_DIAGCROSS hachura a 45 graus

- HS_FDIAGONAL para cima hachura (da esquerda para a direita) em 45 graus

- Hachura Horizontal HS_HORIZONTAL

- Hachura Vertical HS_VERTICAL

*crColor*<br/>
Especifica a cor de primeiro plano do pincel como uma cor RGB (a cor das hachuras). Ver [COLORREF](/windows/desktop/gdi/colorref) no SDK do Windows para obter mais informações.

### <a name="return-value"></a>Valor de retorno

Diferente de zero se bem-sucedido; Caso contrário, 0.

### <a name="remarks"></a>Comentários

O pincel, posteriormente, pode ser selecionado como o pincel atual para qualquer contexto de dispositivo.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCDocView#24](../../mfc/codesnippet/cpp/cbrush-class_4.cpp)]

##  <a name="createpatternbrush"></a>  CBrush::CreatePatternBrush

Inicializa um pincel com um padrão especificado por um bitmap.

```
BOOL CreatePatternBrush(CBitmap* pBitmap);
```

### <a name="parameters"></a>Parâmetros

*pBitmap*<br/>
Identifica um bitmap.

### <a name="return-value"></a>Valor de retorno

Diferente de zero se bem-sucedido; Caso contrário, 0.

### <a name="remarks"></a>Comentários

O pincel, posteriormente, pode ser selecionado para qualquer contexto de dispositivo que dá suporte a operações de varredura. O bitmap identificado pelo *pBitmap* geralmente é inicializado usando o [CBitmap::CreateBitmap](../../mfc/reference/cbitmap-class.md#createbitmap), [CBitmap::CreateBitmapIndirect](../../mfc/reference/cbitmap-class.md#createbitmapindirect), [CBitmap:: LoadBitmap](../../mfc/reference/cbitmap-class.md#loadbitmap), ou [CBitmap::CreateCompatibleBitmap](../../mfc/reference/cbitmap-class.md#createcompatiblebitmap) função.

Bitmaps usados como padrões de preenchimento deve ser 8 pixels por 8. Se o bitmap for maior, o Windows usará apenas os bits correspondentes para as 8 primeiras linhas e colunas de pixels no canto superior esquerdo do bitmap.

Um pincel de padrão pode ser excluído sem afetar o bitmap associado. Isso significa que o bitmap pode ser usado para criar qualquer número de pincéis de padrão.

Um pincel criado usando um bitmap monocromático (plano 1 cor, 1 bit por pixel) é desenhado usando as cores de plano de fundo e texto atuais. Representado por um bit definido como 0 de pixels são desenhados com a cor do texto atual. Representado por um bit definido como 1 de pixels são desenhados com a cor de plano de fundo atual.

Para obter informações sobre como usar [CreatePatternBrush](/windows/desktop/api/wingdi/nf-wingdi-createpatternbrush), um Windows, consulte o SDK do Windows.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCDocView#25](../../mfc/codesnippet/cpp/cbrush-class_5.cpp)]

##  <a name="createsolidbrush"></a>  CBrush::CreateSolidBrush

Inicializa um pincel com uma cor sólida especificado.

```
BOOL CreateSolidBrush(COLORREF crColor);
```

### <a name="parameters"></a>Parâmetros

*crColor*<br/>
Um [COLORREF](/windows/desktop/gdi/colorref) estrutura que especifica a cor do pincel. A cor Especifica um valor de RGB e pode ser construída com a macro RGB no WINDOWS. H.

### <a name="return-value"></a>Valor de retorno

Diferente de zero se bem-sucedido; Caso contrário, 0.

### <a name="remarks"></a>Comentários

O pincel, posteriormente, pode ser selecionado como o pincel atual para qualquer contexto de dispositivo.

Quando um aplicativo tiver terminado de usar o pincel criado pelo `CreateSolidBrush`, ela deve selecionar o pincel fora do contexto de dispositivo.

### <a name="example"></a>Exemplo

  Veja o exemplo de [CBrush::CBrush](#cbrush).

##  <a name="createsyscolorbrush"></a>  CBrush::CreateSysColorBrush

Inicializa uma cor do pincel.

```
BOOL CreateSysColorBrush(int nIndex);
```

### <a name="parameters"></a>Parâmetros

*nIndex*<br/>
Especifica um índice de cores. Esse valor corresponde à cor usada para pintar um dos elementos da 21 janela. Ver [GetSysColor](/windows/desktop/api/winuser/nf-winuser-getsyscolor) no SDK do Windows para obter uma lista de valores.

### <a name="return-value"></a>Valor de retorno

Diferente de zero se bem-sucedido; Caso contrário, 0.

### <a name="remarks"></a>Comentários

O pincel, posteriormente, pode ser selecionado como o pincel atual para qualquer contexto de dispositivo.

Quando um aplicativo tiver terminado de usar o pincel criado pelo `CreateSysColorBrush`, ela deve selecionar o pincel fora do contexto de dispositivo.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCDocView#26](../../mfc/codesnippet/cpp/cbrush-class_6.cpp)]

##  <a name="fromhandle"></a>  CBrush::FromHandle

Retorna um ponteiro para um `CBrush` do objeto quando é fornecido um identificador para um Windows [HBRUSH](#operator_hbrush) objeto.

```
static CBrush* PASCAL FromHandle(HBRUSH hBrush);
```

### <a name="parameters"></a>Parâmetros

*hBrush*<br/>
IDENTIFICADOR para um pincel de Windows GDI.

### <a name="return-value"></a>Valor de retorno

Um ponteiro para um `CBrush` objeto se for bem-sucedido; caso contrário, NULL.

### <a name="remarks"></a>Comentários

Se um `CBrush` objeto já não está anexado ao identificador, um temporário `CBrush` objeto é criado e anexado. Esse temporário `CBrush` objeto é válido somente até a próxima vez em que o aplicativo tem tempo ocioso em seu loop de eventos. Neste momento, todos os objetos gráficos temporários são excluídos. Em outras palavras, o objeto temporário é válido somente durante o processamento da mensagem de uma janela.

Para obter mais informações sobre como usar objetos gráficos, consulte [gráfico de objetos](/windows/desktop/gdi/graphic-objects) no SDK do Windows.

### <a name="example"></a>Exemplo

  Veja o exemplo de [CBrush::CBrush](#cbrush).

##  <a name="getlogbrush"></a>  CBrush::GetLogBrush

Chame essa função de membro para recuperar o `LOGBRUSH` estrutura.

```
int GetLogBrush(LOGBRUSH* pLogBrush);
```

### <a name="parameters"></a>Parâmetros

*pLogBrush*<br/>
Aponta para um [LOGBRUSH](/windows/desktop/api/wingdi/ns-wingdi-taglogbrush) estrutura que contém informações sobre o pincel.

### <a name="return-value"></a>Valor de retorno

Se a função for bem-sucedida, e *pLogBrush* for um ponteiro válido, o valor de retorno é o número de bytes armazenados no buffer.

Se a função for bem-sucedida, e *pLogBrush* for NULL, o valor retornado é o número de bytes necessários para manter as informações de função seria armazenar em buffer.

Se a função falhar, o valor de retorno é 0.

### <a name="remarks"></a>Comentários

O `LOGBRUSH` estrutura define o estilo, cor e padrão de um pincel.

Por exemplo, chamar `GetLogBrush` para corresponder ao padrão de um bitmap ou cor específica.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCDocView#27](../../mfc/codesnippet/cpp/cbrush-class_7.cpp)]

##  <a name="operator_hbrush"></a>  CBrush::operator HBRUSH

Use este operador para obter o identificador do Windows GDI anexado do `CBrush` objeto.

```
operator HBRUSH() const;
```

### <a name="return-value"></a>Valor de retorno

Se for bem-sucedido, um identificador para o objeto de GDI do Windows representado pelo `CBrush` objeto; caso contrário, nulo.

### <a name="remarks"></a>Comentários

Esse operador é um operador de conversão, que dá suporte ao uso direto de um objeto HBRUSH.

Para obter mais informações sobre como usar objetos gráficos, consulte [gráfico de objetos](/windows/desktop/gdi/graphic-objects) no SDK do Windows.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCDocView#28](../../mfc/codesnippet/cpp/cbrush-class_8.cpp)]

## <a name="see-also"></a>Consulte também

[Exemplo MFC PROPDLG](../../visual-cpp-samples.md)<br/>
[Classe CGdiObject](../../mfc/reference/cgdiobject-class.md)<br/>
[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classe CBitmap](../../mfc/reference/cbitmap-class.md)<br/>
[Classe CDC](../../mfc/reference/cdc-class.md)
