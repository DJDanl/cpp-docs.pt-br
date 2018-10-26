---
title: Classe CPen | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: reference
f1_keywords:
- CPen
- AFXWIN/CPen
- AFXWIN/CPen::CPen
- AFXWIN/CPen::CreatePen
- AFXWIN/CPen::CreatePenIndirect
- AFXWIN/CPen::FromHandle
- AFXWIN/CPen::GetExtLogPen
- AFXWIN/CPen::GetLogPen
dev_langs:
- C++
helpviewer_keywords:
- CPen [MFC], CPen
- CPen [MFC], CreatePen
- CPen [MFC], CreatePenIndirect
- CPen [MFC], FromHandle
- CPen [MFC], GetExtLogPen
- CPen [MFC], GetLogPen
ms.assetid: 93175a3a-d46c-4768-be8d-863254f97a5f
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 1ec2e3253b4d26bc6773ffc4005100edfbec1bff
ms.sourcegitcommit: a9dcbcc85b4c28eed280d8e451c494a00d8c4c25
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/25/2018
ms.locfileid: "50077517"
---
# <a name="cpen-class"></a>Classe CPen

Encapsula uma caneta de interface (GDI) do dispositivo de gráficos Windows.

## <a name="syntax"></a>Sintaxe

```
class CPen : public CGdiObject
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores Públicos

|Nome|Descrição|
|----------|-----------------|
|[CPen::CPen](#cpen)|Constrói um objeto `CPen`.|

### <a name="public-methods"></a>Métodos Públicos

|Nome|Descrição|
|----------|-----------------|
|[CPen::CreatePen](#createpen)|Cria uma caneta superficial ou geométrica lógica com o estilo especificado, largura e atributos de pincel e anexa-o para o `CPen` objeto.|
|[CPen::CreatePenIndirect](#createpenindirect)|Cria uma caneta com o estilo, largura e cor fornecida um [LOGPEN](/windows/desktop/api/wingdi/ns-wingdi-taglogpen) estruturar e anexa-o para o `CPen` objeto.|
|[CPen::FromHandle](#fromhandle)|Retorna um ponteiro para um `CPen` quando é fornecido um HPEN do Windows do objeto.|
|[CPen::GetExtLogPen](#getextlogpen)|Obtém uma [EXTLOGPEN](/windows/desktop/api/wingdi/ns-wingdi-tagextlogpen) estrutura subjacente.|
|[CPen::GetLogPen](#getlogpen)|Obtém uma [LOGPEN](/windows/desktop/api/wingdi/ns-wingdi-taglogpen) estrutura subjacente.|

### <a name="public-operators"></a>Operadores públicos

|Nome|Descrição|
|----------|-----------------|
|[CPen::operator HPEN](#operator_hpen)|Retorna o identificador do Windows anexado ao `CPen` objeto.|

## <a name="remarks"></a>Comentários

Para obter mais informações sobre como usar `CPen`, consulte [objetos gráficos](../../mfc/graphic-objects.md).

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[CObject](../../mfc/reference/cobject-class.md)

[CGdiObject](../../mfc/reference/cgdiobject-class.md)

`CPen`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxwin. h

##  <a name="cpen"></a>  CPen::CPen

Constrói um objeto `CPen`.

```
CPen();

CPen(
    int nPenStyle,
    int nWidth,
    COLORREF crColor);

CPen(
    int nPenStyle,
    int nWidth,
    const LOGBRUSH* pLogBrush,
    int nStyleCount = 0,
    const DWORD* lpStyle = NULL);
```

### <a name="parameters"></a>Parâmetros

*nPenStyle*<br/>
Especifica o estilo de caneta. Esse parâmetro na primeira versão do construtor pode ser um dos seguintes valores:

- PS_SOLID cria uma caneta sólida.

- PS_DASH cria uma caneta tracejada. Válido somente quando a largura da caneta é de unidades de 1 ou menos, no dispositivo.

- PS_DOT cria uma caneta pontilhada. Válido somente quando a largura da caneta é de unidades de 1 ou menos, no dispositivo.

- PS_DASHDOT cria pontos e traços de caneta com alternadas. Válido somente quando a largura da caneta é de unidades de 1 ou menos, no dispositivo.

- PS_DASHDOTDOT cria uma caneta com traços alternados e dos pontos duplos. Válido somente quando a largura da caneta é de unidades de 1 ou menos, no dispositivo.

- PS_NULL cria uma caneta de nula.

- Funções que especificam um retângulo delimitador de saída de PS_INSIDEFRAME cria uma caneta que desenha uma linha dentro do quadro de formas fechadas produzida pela GDI do Windows (por exemplo, o `Ellipse`, `Rectangle`, `RoundRect`, `Pie`e `Chord`funções de membro). Quando esse estilo é usado com funções de saída de GDI do Windows que não especificam um retângulo delimitador (por exemplo, o `LineTo` função de membro), a área de desenho da caneta não é limitada por um quadro.

A segunda versão do `CPen` construtor Especifica uma combinação de tipo, estilo, limite final e atributos de associação. Os valores de cada categoria devem ser combinados usando o operador OR bit a bit (&#124;). O tipo de caneta pode ser um dos seguintes valores:

- PS_GEOMETRIC cria uma caneta geométrica.

- PS_COSMETIC cria uma caneta superficial.

   A segunda versão dos `CPen` construtor adiciona os seguintes estilos de caneta para *nPenStyle*:

- PS_ALTERNATE cria uma caneta que define todos os outros pixels. (Esse estilo é aplicável somente a canetas superficiais).

- PS_USERSTYLE cria uma caneta que usa uma matriz de estilo fornecido pelo usuário.

   O limite de extremidade pode ser um dos seguintes valores:

- PS_ENDCAP_ROUND delimitada é redonda.

- PS_ENDCAP_SQUARE delimitada é quadrada.

- PS_ENDCAP_FLAT delimitada é simples.

   A junção pode ser um dos seguintes valores:

- Une PS_JOIN_BEVEL são biselada.

- Une PS_JOIN_MITER estão em Malhete quando estes estiverem dentro do limite atual definido pela [SetMiterLimit](/windows/desktop/api/wingdi/nf-wingdi-setmiterlimit) função. Se a junção exceder esse limite, ele é biselado.

- Une PS_JOIN_ROUND são redonda.

*nWidth*<br/>
Especifica a largura da caneta.

- Para a primeira versão do construtor, se esse valor for 0, a largura em unidades de dispositivo é sempre 1 pixel, independentemente do modo de mapeamento.

- Para a segunda versão do construtor, se *nPenStyle* é PS_GEOMETRIC, a largura é fornecida em unidades lógicas. Se *nPenStyle* é PS_COSMETIC, a largura deve ser definida como 1.

*crColor*<br/>
Contém uma cor RGB para a caneta.

*pLogBrush*<br/>
Aponta para um `LOGBRUSH` estrutura. Se *nPenStyle* é PS_COSMETIC, o *lbColor* membro do `LOGBRUSH` estrutura Especifica a cor da caneta e o *lbStyle* membro do `LOGBRUSH` estrutura deve ser definida como BS_SOLID. Se *nPenStyle* é PS_GEOMETRIC, todos os membros devem ser usados para especificar os atributos de pincel da caneta.

*nStyleCount*<br/>
Especifica o comprimento, em unidades de palavras duplas, do *lpStyle* matriz. Esse valor deve ser zero se *nPenStyle* não é PS_USERSTYLE.

*lpStyle*<br/>
Aponta para uma matriz de valores de palavras duplas. O primeiro valor Especifica o comprimento do traço primeiro em um estilo definido pelo usuário, o segundo valor Especifica o comprimento do primeiro espaço e assim por diante. Esse ponteiro deve ser NULL se *nPenStyle* não é PS_USERSTYLE.

### <a name="remarks"></a>Comentários

Se você usar o construtor sem argumentos, você deve inicializar resultante `CPen` do objeto com o `CreatePen`, `CreatePenIndirect`, ou `CreateStockObject` funções de membro.

Se você usar o construtor que aceita argumentos, nenhuma inicialização adicional é necessária. O construtor com argumentos pode lançar uma exceção se forem encontrados erros, enquanto o construtor sem argumentos sempre terá êxito.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCDocView#99](../../mfc/codesnippet/cpp/cpen-class_1.cpp)]

##  <a name="createpen"></a>  CPen::CreatePen

Cria uma caneta superficial ou geométrica lógica com o estilo especificado, largura e atributos de pincel e anexa-o para o `CPen` objeto.

```
BOOL CreatePen(
    int nPenStyle,
    int nWidth,
    COLORREF crColor);

BOOL CreatePen(
    int nPenStyle,
    int nWidth,
    const LOGBRUSH* pLogBrush,
    int nStyleCount = 0,
    const DWORD* lpStyle = NULL);
```

### <a name="parameters"></a>Parâmetros

*nPenStyle*<br/>
Especifica o estilo para a caneta. Para obter uma lista de valores possíveis, consulte o *nPenStyle* parâmetro na [CPen](#cpen) construtor.

*nWidth*<br/>
Especifica a largura da caneta.

- Para a primeira versão do `CreatePen`, se esse valor for 0, a largura em unidades de dispositivo é sempre 1 pixel, independentemente do modo de mapeamento.

- Para a segunda versão do `CreatePen`, se *nPenStyle* é PS_GEOMETRIC, a largura é fornecida em unidades lógicas. Se *nPenStyle* é PS_COSMETIC, a largura deve ser definida como 1.

*crColor*<br/>
Contém uma cor RGB para a caneta.

*pLogBrush*<br/>
Aponta para um [LOGBRUSH](/windows/desktop/api/wingdi/ns-wingdi-taglogbrush) estrutura. Se *nPenStyle* é PS_COSMETIC, o `lbColor` membro do `LOGBRUSH` estrutura Especifica a cor da caneta e o *lbStyle* membro do `LOGBRUSH` estrutura deve ser definida como BS_ SÓLIDA. Se nPenStyle for PS_GEOMETRIC, todos os membros devem ser usados para especificar os atributos de pincel da caneta.

*nStyleCount*<br/>
Especifica o comprimento, em unidades de palavras duplas, do *lpStyle* matriz. Esse valor deve ser zero se *nPenStyle* não é PS_USERSTYLE.

*lpStyle*<br/>
Aponta para uma matriz de valores de palavras duplas. O primeiro valor Especifica o comprimento do traço primeiro em um estilo definido pelo usuário, o segundo valor Especifica o comprimento do primeiro espaço e assim por diante. Esse ponteiro deve ser NULL se *nPenStyle* não é PS_USERSTYLE.

### <a name="return-value"></a>Valor de retorno

Diferente de zero se for bem-sucedido, ou zero se o método falhar.

### <a name="remarks"></a>Comentários

A primeira versão do `CreatePen` inicializa de uma caneta com o estilo especificado, largura e cor. A caneta, posteriormente, pode ser selecionada como a caneta atual para qualquer contexto de dispositivo.

Canetas que têm uma largura maior que 1 pixel sempre devem ter o estilo PS_NULL, PS_SOLID ou PS_INSIDEFRAME.

Se uma caneta tem o estilo PS_INSIDEFRAME e uma cor que não coincide com uma cor na tabela de cores lógicas, a caneta é desenhada com uma cor pontilhada. O estilo de caneta PS_SOLID não pode ser usado para criar uma caneta com uma cor pontilhada. O estilo PS_INSIDEFRAME é idêntico ao PS_SOLID se a largura da caneta é menor ou igual a 1.

A segunda versão do `CreatePen` inicializa de uma caneta superficial ou geométrica lógica que foi especificado o estilo, largura e atributos de pincel. A largura da caneta superficial é sempre 1; a largura da caneta geométrica é sempre especificada em unidades do mundo. Depois que um aplicativo cria uma caneta lógica, pode selecionar essa caneta em um contexto de dispositivo chamando o [CDC::SelectObject](../../mfc/reference/cdc-class.md#selectobject) função. Depois de uma caneta está selecionada em um contexto de dispositivo, ele pode ser usado para desenhar linhas e curvas.

- Se *nPenStyle* é PS_COSMETIC e PS_USERSTYLE, as entradas na *lpStyle* matriz especificar comprimentos dos traços e espaços em unidades de estilo. Uma unidade de estilo é definida pelo dispositivo em que a caneta é usada para desenhar uma linha.

- Se *nPenStyle* é PS_GEOMETRIC e PS_USERSTYLE, as entradas na *lpStyle* matriz especifique os comprimentos dos traços e espaços em unidades lógicas.

- Se *nPenStyle* é PS_ALTERNATE, a unidade de estilo é ignorada e todos os outros pixels é definida.

Quando um aplicativo não exige mais uma caneta determinada, ele deverá chamar o [CGdiObject::DeleteObject](../../mfc/reference/cgdiobject-class.md#deleteobject) membro de função ou destruir o `CPen` do objeto para que o recurso não está mais em uso. Um aplicativo não deve excluir uma caneta quando a caneta é selecionada em um contexto de dispositivo.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCDocView#100](../../mfc/codesnippet/cpp/cpen-class_2.cpp)]

##  <a name="createpenindirect"></a>  CPen::CreatePenIndirect

Inicializa uma caneta que tem o estilo, largura e cor fornecida na estrutura apontada por *lpLogPen*.

```
BOOL CreatePenIndirect(LPLOGPEN lpLogPen);
```

### <a name="parameters"></a>Parâmetros

*lpLogPen*<br/>
Aponta para o Windows [LOGPEN](../../mfc/reference/logpen-structure.md) estrutura que contém informações sobre a caneta.

### <a name="return-value"></a>Valor de retorno

Diferente de zero se a função for bem-sucedida; caso contrário, 0.

### <a name="remarks"></a>Comentários

Canetas que têm uma largura maior que 1 pixel sempre devem ter o estilo PS_NULL, PS_SOLID ou PS_INSIDEFRAME.

Se uma caneta tem o estilo PS_INSIDEFRAME e uma cor que não coincide com uma cor na tabela de cores lógicas, a caneta é desenhada com uma cor pontilhada. O estilo PS_INSIDEFRAME é idêntico ao PS_SOLID se a largura da caneta é menor ou igual a 1.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCDocView#101](../../mfc/codesnippet/cpp/cpen-class_3.cpp)]

##  <a name="fromhandle"></a>  CPen::FromHandle

Retorna um ponteiro para um `CPen` objeto dado um identificador para um objeto de caneta GDI do Windows.

```
static CPen* PASCAL FromHandle(HPEN hPen);
```

### <a name="parameters"></a>Parâmetros

*hPen*<br/>
`HPEN` identificador para a caneta GDI do Windows.

### <a name="return-value"></a>Valor de retorno

Um ponteiro para um `CPen` objeto se for bem-sucedido; caso contrário, NULL.

### <a name="remarks"></a>Comentários

Se um `CPen` objeto não está anexado ao identificador, um temporário `CPen` objeto é criado e anexado. Esse temporário `CPen` objeto é válido somente até a próxima vez que o aplicativo tem tempo ocioso em seu loop de eventos, em que ponto o gráfico temporário todos os objetos são excluídos. Em outras palavras, o objeto temporário só é válido durante o processamento de mensagem em uma janela.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCDocView#105](../../mfc/codesnippet/cpp/cpen-class_4.cpp)]

##  <a name="getextlogpen"></a>  CPen::GetExtLogPen

Obtém um `EXTLOGPEN` estrutura subjacente.

```
int GetExtLogPen(EXTLOGPEN* pLogPen);
```

### <a name="parameters"></a>Parâmetros

*pLogPen*<br/>
Aponta para um [EXTLOGPEN](/windows/desktop/api/wingdi/ns-wingdi-tagextlogpen) estrutura que contém informações sobre a caneta.

### <a name="return-value"></a>Valor de retorno

Diferente de zero se bem-sucedido; Caso contrário, 0.

### <a name="remarks"></a>Comentários

O `EXTLOGPEN` estrutura define o estilo, a largura e o pincel de atributos de uma caneta. Por exemplo, chamar `GetExtLogPen` para coincidir com o estilo específico de uma caneta.

Consulte os tópicos a seguir no SDK do Windows para obter informações sobre atributos de caneta:

- [GetObject](/windows/desktop/api/wingdi/nf-wingdi-getobject)

- [EXTLOGPEN](/windows/desktop/api/wingdi/ns-wingdi-tagextlogpen)

- [LOGPEN](/windows/desktop/api/wingdi/ns-wingdi-taglogpen)

- [ExtCreatePen](/windows/desktop/api/wingdi/nf-wingdi-extcreatepen)

### <a name="example"></a>Exemplo

O exemplo de código a seguir demonstra a chamada `GetExtLogPen` para recuperar os atributos de uma caneta e, em seguida, criar uma caneta de novo, superficial com a mesma cor.

[!code-cpp[NVC_MFCDocView#102](../../mfc/codesnippet/cpp/cpen-class_5.cpp)]

##  <a name="getlogpen"></a>  CPen::GetLogPen

Obtém um `LOGPEN` estrutura subjacente.

```
int GetLogPen(LOGPEN* pLogPen);
```

### <a name="parameters"></a>Parâmetros

*pLogPen*<br/>
Aponta para um [LOGPEN](/windows/desktop/api/wingdi/ns-wingdi-taglogpen) estrutura para conter informações sobre a caneta.

### <a name="return-value"></a>Valor de retorno

Diferente de zero se bem-sucedido; Caso contrário, 0.

### <a name="remarks"></a>Comentários

O `LOGPEN` estrutura define o estilo, cor e padrão de uma caneta.

Por exemplo, chamar `GetLogPen` para coincidir com o estilo específico da caneta.

Consulte os tópicos a seguir no SDK do Windows para obter informações sobre atributos de caneta:

- [GetObject](/windows/desktop/api/wingdi/nf-wingdi-getobject)

- [LOGPEN](/windows/desktop/api/wingdi/ns-wingdi-taglogpen)

### <a name="example"></a>Exemplo

O exemplo de código a seguir demonstra a chamada `GetLogPen` para recuperar um caractere de caneta e, em seguida, criar uma caneta de novo e sólida com a mesma cor.

[!code-cpp[NVC_MFCDocView#103](../../mfc/codesnippet/cpp/cpen-class_6.cpp)]

##  <a name="operator_hpen"></a>  CPen::operator HPEN

Obtém o identificador do Windows GDI anexado do `CPen` objeto.

```
operator HPEN() const;
```

### <a name="return-value"></a>Valor de retorno

Se for bem-sucedido, um identificador para o objeto de GDI do Windows representado pelo `CPen` objeto; caso contrário, nulo.

### <a name="remarks"></a>Comentários

Esse operador é um operador de conversão, que dá suporte ao uso direto de um objeto HPEN.

Para obter mais informações sobre como usar objetos gráficos, consulte o artigo [gráfico de objetos](/windows/desktop/gdi/graphic-objects) no SDK do Windows.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCDocView#104](../../mfc/codesnippet/cpp/cpen-class_7.cpp)]

## <a name="see-also"></a>Consulte também

[Classe CGdiObject](../../mfc/reference/cgdiobject-class.md)<br/>
[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classe CBrush](../../mfc/reference/cbrush-class.md)
