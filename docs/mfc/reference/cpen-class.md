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
ms.openlocfilehash: 952d270acd47b5834a06b731f7875ea2efdd4695
ms.sourcegitcommit: fcb48824f9ca24b1f8bd37d647a4d592de1cc925
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/15/2019
ms.locfileid: "69502946"
---
# <a name="cpen-class"></a>Classe CPen

Encapsula uma caneta GDI (interface de dispositivo de gráficos do Windows).

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
|[CPen::CreatePen](#createpen)|Cria uma caneta de superficial ou geométricas com os atributos de estilo, largura e pincel especificados e anexa-os `CPen` ao objeto.|
|[CPen::CreatePenIndirect](#createpenindirect)|Cria uma caneta com o estilo, a largura e a cor fornecidos em uma estrutura [LOGPEN](/windows/win32/api/wingdi/ns-wingdi-logpen) e anexa-a ao `CPen` objeto.|
|[CPen:: FromHandle](#fromhandle)|Retorna um ponteiro para um `CPen` objeto quando um HPEN do Windows é fornecido.|
|[CPen::GetExtLogPen](#getextlogpen)|Obtém uma estrutura subjacente de [EXTLOGPEN](/windows/win32/api/wingdi/ns-wingdi-extlogpen) .|
|[CPen::GetLogPen](#getlogpen)|Obtém uma estrutura subjacente de [LOGPEN](/windows/win32/api/wingdi/ns-wingdi-logpen) .|

### <a name="public-operators"></a>Operadores públicos

|Nome|Descrição|
|----------|-----------------|
|[Operador CPen:: Operator HPEN](#operator_hpen)|Retorna o identificador do Windows anexado ao `CPen` objeto.|

## <a name="remarks"></a>Comentários

Para obter mais informações sobre `CPen`como usar o, consulte [objetos gráficos](../../mfc/graphic-objects.md).

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[CObject](../../mfc/reference/cobject-class.md)

[CGdiObject](../../mfc/reference/cgdiobject-class.md)

`CPen`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** Afxwin. h

##  <a name="cpen"></a>CPen::CPen

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
Especifica o estilo da caneta. Esse parâmetro na primeira versão do construtor pode ser um dos seguintes valores:

- PS_SOLID Cria uma caneta sólida.

- PS_DASH cria uma caneta tracejada. Válido somente quando a largura da caneta é de 1 ou menos, em unidades do dispositivo.

- PS_DOT cria uma caneta pontilhada. Válido somente quando a largura da caneta é de 1 ou menos, em unidades do dispositivo.

- PS_DASHDOT cria uma caneta com traços e pontos alternados. Válido somente quando a largura da caneta é de 1 ou menos, em unidades do dispositivo.

- PS_DASHDOTDOT Cria uma caneta com traços alternados e pontilhados duplos. Válido somente quando a largura da caneta é de 1 ou menos, em unidades do dispositivo.

- PS_NULL cria uma caneta nula.

- O `Ellipse` PS_INSIDEFRAMEcria`Rectangle`uma caneta que desenha uma linha dentro do quadro de formas fechadas produzidas pelas funções de saída do Windows GDI que especificam um retângulo delimitador (por exemplo,,,, e `RoundRect` `Pie` `Chord`funções de membro). Quando esse estilo é usado com funções de saída do Windows GDI que não especificam um retângulo delimitador (por `LineTo` exemplo, a função de membro), a área de desenho da caneta não é limitada por um quadro.

A segunda versão do `CPen` Construtor especifica uma combinação de tipo, estilo, extremidade final e atributos de junção. Os valores de cada categoria devem ser combinados usando-se o operador OR de&#124;bit (). O tipo de caneta pode ser um dos seguintes valores:

- PS_GEOMETRIC cria uma caneta geométrica.

- PS_COSMETIC cria uma caneta superficial.

   A segunda versão do `CPen` construtor adiciona os seguintes estilos de caneta para *nPenStyle*:

- PS_ALTERNATE cria uma caneta que define a cada outro pixel. (Esse estilo é aplicável somente para canetas superficiais.)

- PS_USERSTYLE Cria uma caneta que usa uma matriz de estilo fornecida pelo usuário.

   A extremidade final pode ser um dos seguintes valores:

- As tampas de extremidade PS_ENDCAP_ROUND são arredondadas.

- As tampas de extremidade PS_ENDCAP_SQUARE são quadradas.

- As tampas de extremidade PS_ENDCAP_FLAT são simples.

   A junção pode ser um dos seguintes valores:

- As junções PS_JOIN_BEVEL são chanfradas.

- As junções PS_JOIN_MITER são Mitre quando estão dentro do limite atual definido pela função [SetMiterLimit](/windows/win32/api/wingdi/nf-wingdi-setmiterlimit) . Se a junção exceder esse limite, ela será chanfrada.

- As junções do PS_JOIN_ROUND são arredondadas.

*nWidth*<br/>
Especifica a largura da caneta.

- Para a primeira versão do Construtor, se esse valor for 0, a largura nas unidades do dispositivo será sempre 1 pixel, independentemente do modo de mapeamento.

- Para a segunda versão do Construtor, se *nPenStyle* for PS_GEOMETRIC, a largura será fornecida em unidades lógicas. Se *nPenStyle* for PS_COSMETIC, a largura deverá ser definida como 1.

*crColor*<br/>
Contém uma cor RGB para a caneta.

*pLogBrush*<br/>
Aponta para uma `LOGBRUSH` estrutura. Se *nPenStyle* for PS_COSMETIC, o `LOGBRUSH` membro lbColor da estrutura especificará a cor da caneta `LOGBRUSH` e o membro *lbStyle* da estrutura deverá ser definido como BS_SOLID. Se *nPenStyle* for PS_GEOMETRIC, todos os membros deverão ser usados para especificar os atributos de pincel da caneta.

*nStyleCount*<br/>
Especifica o comprimento, em unidades doubleword, da matriz *lpStyle* . Esse valor deve ser zero se *nPenStyle* não for PS_USERSTYLE.

*lpStyle*<br/>
Aponta para uma matriz de valores de doubleword. O primeiro valor especifica o comprimento do primeiro traço em um estilo definido pelo usuário, o segundo valor especifica o comprimento do primeiro espaço e assim por diante. Esse ponteiro deve ser nulo se *nPenStyle* não for PS_USERSTYLE.

### <a name="remarks"></a>Comentários

Se você usar o construtor sem argumentos, deverá inicializar o objeto `CPen` resultante com as funções de `CreatePen`membro, `CreatePenIndirect`ou `CreateStockObject` .

Se você usar o construtor que usa argumentos, nenhuma inicialização adicional será necessária. O construtor com argumentos pode gerar uma exceção se forem encontrados erros, enquanto o construtor sem argumentos sempre terá sucesso.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCDocView#99](../../mfc/codesnippet/cpp/cpen-class_1.cpp)]

##  <a name="createpen"></a>  CPen::CreatePen

Cria uma caneta de superficial ou geométricas com os atributos de estilo, largura e pincel especificados e anexa-os `CPen` ao objeto.

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
Especifica o estilo da caneta. Para obter uma lista de valores possíveis, consulte o parâmetro *nPenStyle* no construtor [CPen](#cpen) .

*nWidth*<br/>
Especifica a largura da caneta.

- Para a primeira versão do `CreatePen`, se esse valor for 0, a largura nas unidades do dispositivo será sempre 1 pixel, independentemente do modo de mapeamento.

- Para a segunda versão do `CreatePen`, se *nPenStyle* for PS_GEOMETRIC, a largura será fornecida em unidades lógicas. Se *nPenStyle* for PS_COSMETIC, a largura deverá ser definida como 1.

*crColor*<br/>
Contém uma cor RGB para a caneta.

*pLogBrush*<br/>
Aponta para uma estrutura [LOGBRUSH](/windows/win32/api/wingdi/ns-wingdi-logbrush) . Se *nPenStyle* for PS_COSMETIC, o `lbColor` membro da `LOGBRUSH` estrutura especificará a cor da `LOGBRUSH` caneta e o membro *lbStyle* da estrutura deverá ser definido como BS_SOLID. Se nPenStyle for PS_GEOMETRIC, todos os membros deverão ser usados para especificar os atributos de pincel da caneta.

*nStyleCount*<br/>
Especifica o comprimento, em unidades doubleword, da matriz *lpStyle* . Esse valor deve ser zero se *nPenStyle* não for PS_USERSTYLE.

*lpStyle*<br/>
Aponta para uma matriz de valores de doubleword. O primeiro valor especifica o comprimento do primeiro traço em um estilo definido pelo usuário, o segundo valor especifica o comprimento do primeiro espaço e assim por diante. Esse ponteiro deve ser nulo se *nPenStyle* não for PS_USERSTYLE.

### <a name="return-value"></a>Valor de retorno

Diferente de zero, se for bem-sucedido ou zero se o método falhar.

### <a name="remarks"></a>Comentários

A primeira versão do `CreatePen` Inicializa uma caneta com o estilo, a largura e a cor especificados. A caneta pode ser subseqüentemente selecionada como a caneta atual para qualquer contexto de dispositivo.

As canetas com uma largura maior que 1 pixel sempre devem ter o estilo PS_NULL, PS_SOLID ou PS_INSIDEFRAME.

Se uma caneta tiver o estilo PS_INSIDEFRAME e uma cor que não corresponde a uma cor na tabela de cores lógica, a caneta será desenhada com uma cor dicolorido. O estilo da caneta PS_SOLID não pode ser usado para criar uma caneta com uma cor diquerda. O estilo PS_INSIDEFRAME será idêntico a PS_SOLID se a largura da caneta for menor ou igual a 1.

A segunda versão do `CreatePen` Inicializa uma caneta de comprimento lógico ou geométrica que tem os atributos de estilo, largura e pincel especificados. A largura de uma caneta superficial é sempre 1; a largura de uma caneta geométrica é sempre especificada em unidades mundiais. Depois que um aplicativo cria uma caneta lógica, ele pode selecionar essa caneta em um contexto de dispositivo chamando a função [CDC:: SelectObject](../../mfc/reference/cdc-class.md#selectobject) . Depois que uma caneta é selecionada em um contexto de dispositivo, ela pode ser usada para desenhar linhas e curvas.

- Se *nPenStyle* for PS_COSMETIC e PS_USERSTYLE, as entradas na matriz *lpStyle* especificarão comprimentos de traços e espaços em unidades de estilo. Uma unidade de estilo é definida pelo dispositivo no qual a caneta é usada para desenhar uma linha.

- Se *nPenStyle* for PS_GEOMETRIC e PS_USERSTYLE, as entradas na matriz *lpStyle* especificarão comprimentos de traços e espaços em unidades lógicas.

- Se *nPenStyle* for PS_ALTERNATE, a unidade de estilo será ignorada e todos os outros pixels serão definidos.

Quando um aplicativo não requer mais uma determinada caneta, ele deve chamar a função de membro [CGdiObject::D eleteobject](../../mfc/reference/cgdiobject-class.md#deleteobject) ou destruir `CPen` o objeto para que o recurso não esteja mais em uso. Um aplicativo não deve excluir uma caneta quando a caneta é selecionada em um contexto de dispositivo.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCDocView#100](../../mfc/codesnippet/cpp/cpen-class_2.cpp)]

##  <a name="createpenindirect"></a>CPen::CreatePenIndirect

Inicializa uma caneta que tem o estilo, a largura e a cor fornecidos na estrutura apontada por *lpLogPen*.

```
BOOL CreatePenIndirect(LPLOGPEN lpLogPen);
```

### <a name="parameters"></a>Parâmetros

*lpLogPen*<br/>
Aponta para a estrutura [LOGPEN](/windows/win32/api/Wingdi/ns-wingdi-logpen) do Windows que contém informações sobre a caneta.

### <a name="return-value"></a>Valor de retorno

Diferente de zero se a função for bem-sucedida; caso contrário, 0.

### <a name="remarks"></a>Comentários

As canetas com uma largura maior que 1 pixel sempre devem ter o estilo PS_NULL, PS_SOLID ou PS_INSIDEFRAME.

Se uma caneta tiver o estilo PS_INSIDEFRAME e uma cor que não corresponde a uma cor na tabela de cores lógica, a caneta será desenhada com uma cor dicolorido. O estilo PS_INSIDEFRAME será idêntico a PS_SOLID se a largura da caneta for menor ou igual a 1.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCDocView#101](../../mfc/codesnippet/cpp/cpen-class_3.cpp)]

##  <a name="fromhandle"></a>CPen:: FromHandle

Retorna um ponteiro para um `CPen` objeto dado um identificador a um objeto da caneta GDI do Windows.

```
static CPen* PASCAL FromHandle(HPEN hPen);
```

### <a name="parameters"></a>Parâmetros

*hPen*<br/>
`HPEN`manipule a caneta GDI do Windows.

### <a name="return-value"></a>Valor de retorno

Um ponteiro para um `CPen` objeto se for bem-sucedido; caso contrário, NULL.

### <a name="remarks"></a>Comentários

Se um `CPen` objeto não estiver anexado ao identificador, um objeto temporário `CPen` será criado e anexado. Esse objeto `CPen` temporário é válido somente até a próxima vez que o aplicativo tiver tempo ocioso em seu loop de eventos, quando todos os objetos gráficos temporários forem excluídos. Em outras palavras, o objeto temporário só é válido durante o processamento de uma mensagem de janela.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCDocView#105](../../mfc/codesnippet/cpp/cpen-class_4.cpp)]

##  <a name="getextlogpen"></a>  CPen::GetExtLogPen

Obtém uma `EXTLOGPEN` estrutura subjacente.

```
int GetExtLogPen(EXTLOGPEN* pLogPen);
```

### <a name="parameters"></a>Parâmetros

*pLogPen*<br/>
Aponta para uma estrutura [EXTLOGPEN](/windows/win32/api/wingdi/ns-wingdi-extlogpen) que contém informações sobre a caneta.

### <a name="return-value"></a>Valor de retorno

Diferente de zero, se for bem-sucedido; caso contrário, 0.

### <a name="remarks"></a>Comentários

A `EXTLOGPEN` estrutura define o estilo, a largura e os atributos de pincel de uma caneta. Por exemplo, chame `GetExtLogPen` para corresponder ao estilo específico de uma caneta.

Consulte os tópicos a seguir na SDK do Windows para obter informações sobre atributos de caneta:

- [GetObject](/windows/win32/api/wingdi/nf-wingdi-getobject)

- [EXTLOGPEN](/windows/win32/api/wingdi/ns-wingdi-extlogpen)

- [LOGPEN](/windows/win32/api/wingdi/ns-wingdi-logpen)

- [ExtCreatePen](/windows/win32/api/wingdi/nf-wingdi-extcreatepen)

### <a name="example"></a>Exemplo

O exemplo de código a seguir `GetExtLogPen` demonstra como chamar para recuperar os atributos de uma caneta e, em seguida, criar uma nova caneta superficial com a mesma cor.

[!code-cpp[NVC_MFCDocView#102](../../mfc/codesnippet/cpp/cpen-class_5.cpp)]

##  <a name="getlogpen"></a>  CPen::GetLogPen

Obtém uma `LOGPEN` estrutura subjacente.

```
int GetLogPen(LOGPEN* pLogPen);
```

### <a name="parameters"></a>Parâmetros

*pLogPen*<br/>
Aponta para uma estrutura [LOGPEN](/windows/win32/api/wingdi/ns-wingdi-logpen) para conter informações sobre a caneta.

### <a name="return-value"></a>Valor de retorno

Diferente de zero, se for bem-sucedido; caso contrário, 0.

### <a name="remarks"></a>Comentários

A `LOGPEN` estrutura define o estilo, a cor e o padrão de uma caneta.

Por exemplo, chame `GetLogPen` para corresponder ao estilo de caneta em particular.

Consulte os tópicos a seguir na SDK do Windows para obter informações sobre atributos de caneta:

- [GetObject](/windows/win32/api/wingdi/nf-wingdi-getobject)

- [LOGPEN](/windows/win32/api/wingdi/ns-wingdi-logpen)

### <a name="example"></a>Exemplo

O exemplo de código a seguir `GetLogPen` demonstra como chamar para recuperar um caractere de caneta e, em seguida, criar uma nova caneta sólida com a mesma cor.

[!code-cpp[NVC_MFCDocView#103](../../mfc/codesnippet/cpp/cpen-class_6.cpp)]

##  <a name="operator_hpen"></a>Operador CPen:: Operator HPEN

Obtém o identificador GDI do Windows anexado do `CPen` objeto.

```
operator HPEN() const;
```

### <a name="return-value"></a>Valor de retorno

Se for bem-sucedido, um identificador para o objeto GDI do Windows representado `CPen` pelo objeto; caso contrário, NULL.

### <a name="remarks"></a>Comentários

Esse operador é um operador de conversão, que dá suporte ao uso direto de um objeto HPEN.

Para obter mais informações sobre como usar objetos gráficos, consulte o artigo [objetos gráficos](/windows/win32/gdi/graphic-objects) em SDK do Windows.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCDocView#104](../../mfc/codesnippet/cpp/cpen-class_7.cpp)]

## <a name="see-also"></a>Consulte também

[Classe CGdiObject](../../mfc/reference/cgdiobject-class.md)<br/>
[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classe CBrush](../../mfc/reference/cbrush-class.md)
