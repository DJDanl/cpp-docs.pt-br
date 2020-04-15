---
title: Classe CPen
ms.date: 11/04/2016
f1_keywords:
- CPen
- AFXWIN/CPen
- AFXWIN/CPen::CPen
- AFXWIN/CPen::CreatePen
- AFXWIN/CPen::CreatePenIndirect
- AFXWIN/CPen::FromHandle
- AFXWIN/CPen::GetExtLogPen
- AFXWIN/CPen::GetLogPen
helpviewer_keywords:
- CPen [MFC], CPen
- CPen [MFC], CreatePen
- CPen [MFC], CreatePenIndirect
- CPen [MFC], FromHandle
- CPen [MFC], GetExtLogPen
- CPen [MFC], GetLogPen
ms.assetid: 93175a3a-d46c-4768-be8d-863254f97a5f
ms.openlocfilehash: e15dc53fafa0d80f1b52b3fe77f3635c592a4346
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81364077"
---
# <a name="cpen-class"></a>Classe CPen

Encapsula uma caneta GDI (Windows Graphics Device Interface, interface de dispositivo gráfico do Windows).

## <a name="syntax"></a>Sintaxe

```
class CPen : public CGdiObject
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[CPen::CPen](#cpen)|Constrói um objeto `CPen`.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CPen::CreatePen](#createpen)|Cria uma caneta cosmética ou geométrica lógica com os atributos `CPen` de estilo, largura e pincel especificados e a prende ao objeto.|
|[CPen::CreatePenIndirect](#createpenindirect)|Cria uma caneta com o estilo, largura e cor dadas em `CPen` uma estrutura [LOGPEN](/windows/win32/api/wingdi/ns-wingdi-logpen) e a anexa ao objeto.|
|[CPen::FromHandle](#fromhandle)|Retorna um ponteiro `CPen` para um objeto quando dado um HPEN do Windows.|
|[CPen::GetExtLogPen](#getextlogpen)|Obtém uma estrutura subjacente [EXTLOGPEN.](/windows/win32/api/wingdi/ns-wingdi-extlogpen)|
|[CPen::GetLogPen](#getlogpen)|Obtém uma estrutura subjacente [logpen.](/windows/win32/api/wingdi/ns-wingdi-logpen)|

### <a name="public-operators"></a>Operadores públicos

|Nome|Descrição|
|----------|-----------------|
|[CPen::operador HPEN](#operator_hpen)|Retorna a alça do `CPen` Windows anexada ao objeto.|

## <a name="remarks"></a>Comentários

Para obter mais `CPen`informações sobre como usar, consulte [Objetos Gráficos](../../mfc/graphic-objects.md).

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[Cobject](../../mfc/reference/cobject-class.md)

[Cgdiobject](../../mfc/reference/cgdiobject-class.md)

`CPen`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxwin.h

## <a name="cpencpen"></a><a name="cpen"></a>CPen::CPen

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

*Npenstyle*<br/>
Especifica o estilo da caneta. Este parâmetro na primeira versão do construtor pode ser um dos seguintes valores:

- PS_SOLID cria uma caneta sólida.

- PS_DASH cria uma caneta tracejada. Válido somente quando a largura da caneta for 1 ou menor, em unidades do dispositivo.

- PS_DOT cria uma caneta pontilhada. Válido somente quando a largura da caneta for 1 ou menor, em unidades do dispositivo.

- PS_DASHDOT Cria uma caneta com traços e pontilhados alternados. Válido somente quando a largura da caneta for 1 ou menor, em unidades do dispositivo.

- PS_DASHDOTDOT Cria uma caneta com traços alternados e dois pontilhados. Válido somente quando a largura da caneta for 1 ou menor, em unidades do dispositivo.

- PS_NULL cria uma caneta nula.

- PS_INSIDEFRAME Cria uma caneta que desenha uma linha dentro do quadro de formas fechadas produzidas pelas funções `RoundRect`de `Pie`saída `Chord` do Windows GDI que especificam um retângulo delimitador (por exemplo, as funções do `Ellipse` `Rectangle`membro). Quando este estilo é usado com funções de saída do Windows GDI que `LineTo` não especificam um retângulo delimitador (por exemplo, a função membro), a área de desenho da caneta não é limitada por um quadro.

A segunda versão `CPen` do construtor especifica uma combinação de tipo, estilo, tampa final e atributos de adesão. Os valores de cada categoria devem ser combinados usando o operador bitwise OR (&#124;). O tipo de caneta pode ser um dos seguintes valores:

- PS_GEOMETRIC cria uma caneta geométrica.

- PS_COSMETIC cria uma caneta cosmética.

   A segunda versão `CPen` do construtor adiciona os seguintes estilos de caneta para *nPenStyle*:

- PS_ALTERNATE Cria uma caneta que define todos os outros pixels. (Este estilo é aplicável apenas para canetas cosméticas.)

- PS_USERSTYLE Cria uma caneta que usa uma matriz de estilo fornecida pelo usuário.

   A tampa final pode ser um dos seguintes valores:

- PS_ENDCAP_ROUND tampas finais são redondas.

- PS_ENDCAP_SQUARE Tampas finais são quadradas.

- PS_ENDCAP_FLAT Tampas finais são planas.

   A adesão pode ser um dos seguintes valores:

- PS_JOIN_BEVEL Joins são chanfrados.

- PS_JOIN_MITER As Adesões são miterizadas quando estão dentro do limite atual definido pela função [SetMiterLimit.](/windows/win32/api/wingdi/nf-wingdi-setmiterlimit) Se a junta exceder esse limite, ela será chanfrada.

- PS_JOIN_ROUND Joins são redondos.

*Nwidth*<br/>
Especifica a largura da caneta.

- Para a primeira versão do construtor, se este valor for 0, a largura nas unidades do dispositivo é sempre de 1 pixel, independentemente do modo de mapeamento.

- Para a segunda versão do construtor, se *nPenStyle* for PS_GEOMETRIC, a largura é dada em unidades lógicas. Se *nPenStyle* for PS_COSMETIC, a largura deve ser definida como 1.

*Crcolor*<br/>
Contém uma cor RGB para a caneta.

*Plogbrush*<br/>
Aponta para `LOGBRUSH` uma estrutura. Se *nPenStyle* for PS_COSMETIC, o `LOGBRUSH` membro *lbColor* da estrutura especifica a cor `LOGBRUSH` da caneta e o membro *lbStyle* da estrutura deve ser definido como BS_SOLID. Se *nPenStyle* for PS_GEOMETRIC, todos os membros devem ser usados para especificar os atributos de pincel da caneta.

*nStyleCount*<br/>
Especifica o comprimento, em unidades de palavras duplas, da matriz *lpStyle.* Este valor deve ser zero se *nPenStyle* não for PS_USERSTYLE.

*lpStyle*<br/>
Aponta para uma matriz de valores de palavras duplas. O primeiro valor especifica o comprimento do primeiro traço em um estilo definido pelo usuário, o segundo valor especifica o comprimento do primeiro espaço e assim por diante. Este ponteiro deve ser NULA se *nPenStyle* não estiver PS_USERSTYLE.

### <a name="remarks"></a>Comentários

Se você usar o construtor sem argumentos, você `CPen` deve `CreatePen`inicializar o objeto resultante com as funções , `CreatePenIndirect`ou `CreateStockObject` membro.

Se você usar o construtor que toma argumentos, então nenhuma inicialização adicional é necessária. O construtor com argumentos pode abrir uma exceção se os erros forem encontrados, enquanto o construtor sem argumentos sempre terá sucesso.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCDocView#99](../../mfc/codesnippet/cpp/cpen-class_1.cpp)]

## <a name="cpencreatepen"></a><a name="createpen"></a>CPen::CreatePen

Cria uma caneta cosmética ou geométrica lógica com os atributos `CPen` de estilo, largura e pincel especificados e a prende ao objeto.

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

*Npenstyle*<br/>
Especifica o estilo para a caneta. Para obter uma lista de valores possíveis, consulte o parâmetro *nPenStyle* no construtor [CPen.](#cpen)

*Nwidth*<br/>
Especifica a largura da caneta.

- Para a primeira `CreatePen`versão de , se este valor é 0, a largura nas unidades do dispositivo é sempre de 1 pixel, independentemente do modo de mapeamento.

- Para a segunda `CreatePen`versão de , se *nPenStyle* for PS_GEOMETRIC, a largura é dada em unidades lógicas. Se *nPenStyle* for PS_COSMETIC, a largura deve ser definida como 1.

*Crcolor*<br/>
Contém uma cor RGB para a caneta.

*Plogbrush*<br/>
Aponta para uma estrutura [LOGBRUSH.](/windows/win32/api/wingdi/ns-wingdi-logbrush) Se *nPenStyle* for `lbColor` PS_COSMETIC, `LOGBRUSH` o membro da estrutura especifica a cor da `LOGBRUSH` caneta e o membro *lbStyle* da estrutura deve ser definido como BS_SOLID. Se nPenStyle for PS_GEOMETRIC, todos os membros devem ser usados para especificar os atributos de pincel da caneta.

*nStyleCount*<br/>
Especifica o comprimento, em unidades de palavras duplas, da matriz *lpStyle.* Este valor deve ser zero se *nPenStyle* não for PS_USERSTYLE.

*lpStyle*<br/>
Aponta para uma matriz de valores de palavras duplas. O primeiro valor especifica o comprimento do primeiro traço em um estilo definido pelo usuário, o segundo valor especifica o comprimento do primeiro espaço e assim por diante. Este ponteiro deve ser NULA se *nPenStyle* não estiver PS_USERSTYLE.

### <a name="return-value"></a>Valor retornado

Não zero se for bem sucedido, ou zero se o método falhar.

### <a name="remarks"></a>Comentários

A primeira `CreatePen` versão do inicializa uma caneta com o estilo, largura e cor especificados. A caneta pode ser posteriormente selecionada como a caneta atual para qualquer contexto do dispositivo.

Canetas com largura superior a 1 pixel devem sempre ter o estilo PS_NULL, PS_SOLID ou PS_INSIDEFRAME.

Se uma caneta tem o estilo PS_INSIDEFRAME e uma cor que não combina com uma cor na tabela de cores lógicas, a caneta é desenhada com uma cor dithered. O estilo de caneta PS_SOLID não pode ser usado para criar uma caneta com uma cor dithered. O estilo PS_INSIDEFRAME é idêntico ao PS_SOLID se a largura da caneta for menor ou igual a 1.

A segunda `CreatePen` versão da inicializa uma caneta cosmética lógica ou geométrica que tem os atributos de estilo, largura e pincel especificados. A largura de uma caneta cosmética é sempre 1; a largura de uma caneta geométrica é sempre especificada em unidades mundiais. Depois que um aplicativo cria uma caneta lógica, ele pode selecionar essa caneta em um contexto de dispositivo chamando a função [CDC::SelectObject.](../../mfc/reference/cdc-class.md#selectobject) Depois que uma caneta é selecionada em um contexto de dispositivo, ela pode ser usada para desenhar linhas e curvas.

- Se *nPenStyle* for PS_COSMETIC e PS_USERSTYLE, as entradas na matriz *lpStyle* especificam comprimentos de traços e espaços em unidades de estilo. Uma unidade de estilo é definida pelo dispositivo no qual a caneta é usada para desenhar uma linha.

- Se *nPenStyle* for PS_GEOMETRIC e PS_USERSTYLE, as entradas na matriz *lpStyle* especificam comprimentos de traços e espaços em unidades lógicas.

- Se *o nPenStyle* estiver PS_ALTERNATE, a unidade de estilo será ignorada e todos os outros pixels estão definidos.

Quando um aplicativo não precisa mais de uma determinada caneta, ele deve chamar a `CPen` função de membro [CGdiObject::DeleteObject](../../mfc/reference/cgdiobject-class.md#deleteobject) ou destruir o objeto para que o recurso não esteja mais em uso. Um aplicativo não deve excluir uma caneta quando a caneta é selecionada em um contexto do dispositivo.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCDocView#100](../../mfc/codesnippet/cpp/cpen-class_2.cpp)]

## <a name="cpencreatepenindirect"></a><a name="createpenindirect"></a>CPen::CreatePenIndirect

Inicializa uma caneta que tenha o estilo, largura e cor dado na estrutura apontada pelo *lpLogPen*.

```
BOOL CreatePenIndirect(LPLOGPEN lpLogPen);
```

### <a name="parameters"></a>Parâmetros

*lpLogPen*<br/>
Aponta para a estrutura do Windows [LOGPEN](/windows/win32/api/Wingdi/ns-wingdi-logpen) que contém informações sobre a caneta.

### <a name="return-value"></a>Valor retornado

Diferente de zero se a função for bem-sucedida; caso contrário, 0.

### <a name="remarks"></a>Comentários

Canetas com largura superior a 1 pixel devem sempre ter o estilo PS_NULL, PS_SOLID ou PS_INSIDEFRAME.

Se uma caneta tem o estilo PS_INSIDEFRAME e uma cor que não combina com uma cor na tabela de cores lógicas, a caneta é desenhada com uma cor dithered. O estilo PS_INSIDEFRAME é idêntico ao PS_SOLID se a largura da caneta for menor ou igual a 1.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCDocView#101](../../mfc/codesnippet/cpp/cpen-class_3.cpp)]

## <a name="cpenfromhandle"></a><a name="fromhandle"></a>CPen::FromHandle

Retorna um ponteiro `CPen` para um objeto dado uma alça a um objeto de caneta Windows GDI.

```
static CPen* PASCAL FromHandle(HPEN hPen);
```

### <a name="parameters"></a>Parâmetros

*Hpen*<br/>
`HPEN`alça para caneta Windows GDI.

### <a name="return-value"></a>Valor retornado

Um ponteiro `CPen` para um objeto se for bem sucedido; caso contrário, NULL.

### <a name="remarks"></a>Comentários

Se `CPen` um objeto não estiver conectado à `CPen` alça, um objeto temporário será criado e anexado. Este `CPen` objeto temporário só é válido até a próxima vez que o aplicativo tiver tempo ocioso em seu loop de evento, momento em que todos os objetos gráficos temporários são excluídos. Em outras palavras, o objeto temporário só é válido durante o processamento de uma mensagem de janela.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCDocView#105](../../mfc/codesnippet/cpp/cpen-class_4.cpp)]

## <a name="cpengetextlogpen"></a><a name="getextlogpen"></a>CPen::GetExtLogPen

Obtém `EXTLOGPEN` uma estrutura subjacente.

```
int GetExtLogPen(EXTLOGPEN* pLogPen);
```

### <a name="parameters"></a>Parâmetros

*pLogPen*<br/>
Aponta para uma estrutura [EXTLOGPEN](/windows/win32/api/wingdi/ns-wingdi-extlogpen) que contém informações sobre a caneta.

### <a name="return-value"></a>Valor retornado

Não zero se bem sucedido; caso contrário, 0.

### <a name="remarks"></a>Comentários

A `EXTLOGPEN` estrutura define os atributos de estilo, largura e pincel de uma caneta. Por exemplo, `GetExtLogPen` chamada para combinar com o estilo particular de uma caneta.

Consulte os seguintes tópicos no SDK do Windows para obter informações sobre atributos de caneta:

- [GetObject](/windows/win32/api/wingdi/nf-wingdi-getobject)

- [EXTLOGPEN](/windows/win32/api/wingdi/ns-wingdi-extlogpen)

- [Logpen](/windows/win32/api/wingdi/ns-wingdi-logpen)

- [ExtCreatePen](/windows/win32/api/wingdi/nf-wingdi-extcreatepen)

### <a name="example"></a>Exemplo

O exemplo de `GetExtLogPen` código a seguir demonstra a chamada para recuperar os atributos de uma caneta e, em seguida, criar uma nova caneta cosmética com a mesma cor.

[!code-cpp[NVC_MFCDocView#102](../../mfc/codesnippet/cpp/cpen-class_5.cpp)]

## <a name="cpengetlogpen"></a><a name="getlogpen"></a>CPen::GetLogPen

Obtém `LOGPEN` uma estrutura subjacente.

```
int GetLogPen(LOGPEN* pLogPen);
```

### <a name="parameters"></a>Parâmetros

*pLogPen*<br/>
Aponta para uma estrutura [LOGPEN](/windows/win32/api/wingdi/ns-wingdi-logpen) para conter informações sobre a caneta.

### <a name="return-value"></a>Valor retornado

Não zero se bem sucedido; caso contrário, 0.

### <a name="remarks"></a>Comentários

A `LOGPEN` estrutura define o estilo, cor e padrão de uma caneta.

Por exemplo, `GetLogPen` chamada para combinar com o estilo particular da caneta.

Consulte os seguintes tópicos no SDK do Windows para obter informações sobre atributos de caneta:

- [GetObject](/windows/win32/api/wingdi/nf-wingdi-getobject)

- [Logpen](/windows/win32/api/wingdi/ns-wingdi-logpen)

### <a name="example"></a>Exemplo

O exemplo de `GetLogPen` código a seguir demonstra a chamada para recuperar um caractere de caneta e, em seguida, criar uma caneta nova e sólida com a mesma cor.

[!code-cpp[NVC_MFCDocView#103](../../mfc/codesnippet/cpp/cpen-class_6.cpp)]

## <a name="cpenoperator-hpen"></a><a name="operator_hpen"></a>CPen::operador HPEN

Obtém a alça GDI `CPen` do Windows anexada do objeto.

```
operator HPEN() const;
```

### <a name="return-value"></a>Valor retornado

Se for bem-sucedido, uma alça para `CPen` o objeto GDI do Windows representado pelo objeto; caso contrário, NULL.

### <a name="remarks"></a>Comentários

Este operador é um operador de fundição, que suporta o uso direto de um objeto HPEN.

Para obter mais informações sobre o uso de objetos gráficos, consulte o artigo [Objetos Gráficos](/windows/win32/gdi/graphic-objects) no Windows SDK.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCDocView#104](../../mfc/codesnippet/cpp/cpen-class_7.cpp)]

## <a name="see-also"></a>Confira também

[Classe CGdiObject](../../mfc/reference/cgdiobject-class.md)<br/>
[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classe CBrush](../../mfc/reference/cbrush-class.md)
