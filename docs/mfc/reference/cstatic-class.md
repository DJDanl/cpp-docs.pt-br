---
title: Classe CStatic
ms.date: 11/04/2016
f1_keywords:
- CStatic
- AFXWIN/CStatic
- AFXWIN/CStatic::CStatic
- AFXWIN/CStatic::Create
- AFXWIN/CStatic::DrawItem
- AFXWIN/CStatic::GetBitmap
- AFXWIN/CStatic::GetCursor
- AFXWIN/CStatic::GetEnhMetaFile
- AFXWIN/CStatic::GetIcon
- AFXWIN/CStatic::SetBitmap
- AFXWIN/CStatic::SetCursor
- AFXWIN/CStatic::SetEnhMetaFile
- AFXWIN/CStatic::SetIcon
helpviewer_keywords:
- CStatic [MFC], CStatic
- CStatic [MFC], Create
- CStatic [MFC], DrawItem
- CStatic [MFC], GetBitmap
- CStatic [MFC], GetCursor
- CStatic [MFC], GetEnhMetaFile
- CStatic [MFC], GetIcon
- CStatic [MFC], SetBitmap
- CStatic [MFC], SetCursor
- CStatic [MFC], SetEnhMetaFile
- CStatic [MFC], SetIcon
ms.assetid: e7c94cd9-5ebd-428a-aa30-b3e51f8efb95
ms.openlocfilehash: fc0164b2d0046ca2d36291696dd6137a9fcef069
ms.sourcegitcommit: 63784729604aaf526de21f6c6b62813882af930a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/17/2020
ms.locfileid: "79447424"
---
# <a name="cstatic-class"></a>Classe CStatic

Fornece a funcionalidade de um controle estático do Windows.

## <a name="syntax"></a>Sintaxe

```
class CStatic : public CWnd
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|{1&gt;Nome&lt;1}|Descrição|
|----------|-----------------|
|[CStatic::CStatic](#cstatic)|Constrói um objeto `CStatic`.|

### <a name="public-methods"></a>Métodos públicos

|{1&gt;Nome&lt;1}|Descrição|
|----------|-----------------|
|[CStatic:: criar](#create)|Cria o controle estático do Windows e o anexa ao objeto `CStatic`.|
|[CStatic::D rawItem](#drawitem)|Substituir para desenhar um controle estático desenhado pelo proprietário.|
|[CStatic:: getbitmap](#getbitmap)|Recupera o identificador do bitmap definido anteriormente com [SetBitmap](#setbitmap).|
|[CStatic:: getCursor](#getcursor)|Recupera o identificador da imagem de cursor definida anteriormente com [SetCursor](#setcursor).|
|[CStatic::GetEnhMetaFile](#getenhmetafile)|Recupera o identificador do metarquivo avançado definido anteriormente com [SetEnhMetafile](#setenhmetafile).|
|[CStatic:: GetIcon](#geticon)|Recupera o identificador do ícone definido anteriormente com [SetIcon](#seticon).|
|[CStatic:: SetBitmap](#setbitmap)|Especifica um bitmap a ser exibido no controle estático.|
|[CStatic:: SetCursor](#setcursor)|Especifica uma imagem de cursor a ser exibida no controle estático.|
|[CStatic::SetEnhMetaFile](#setenhmetafile)|Especifica um metarquivo avançado a ser exibido no controle estático.|
|[CStatic:: SetIcon](#seticon)|Especifica um ícone a ser exibido no controle estático.|

## <a name="remarks"></a>Comentários

Um controle estático exibe uma cadeia de texto, uma caixa, um retângulo, um ícone, um cursor, um bitmap ou um metarquivo avançado. Ele pode ser usado para rotular, caixar ou separar outros controles. Um controle estático normalmente não usa nenhuma entrada e não fornece nenhuma saída; no entanto, ele pode notificar seu pai sobre cliques do mouse se ele for criado com SS_NOTIFY estilo.

Crie um controle estático em duas etapas. Primeiro, chame o construtor para construir o objeto `CStatic` e, em seguida, chame a função [criar](#create) membro para criar o controle estático e anexá-lo ao objeto `CStatic`.

Se você criar um objeto `CStatic` dentro de uma caixa de diálogo (por meio de um recurso de caixa de diálogo), o objeto `CStatic` será destruído automaticamente quando o usuário fechar a caixa de diálogo.

Se você criar um objeto de `CStatic` dentro de uma janela, talvez você também precise destruí-lo. Um objeto `CStatic` criado na pilha dentro de uma janela é destruído automaticamente. Se você criar o objeto `CStatic` no heap usando a **nova** função, deverá chamar **delete** no objeto para destruí-lo quando terminar.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[CObject](../../mfc/reference/cobject-class.md)

[CCmdTarget](../../mfc/reference/ccmdtarget-class.md)

[CWnd](../../mfc/reference/cwnd-class.md)

`CStatic`

## <a name="requirements"></a>{1&gt;{2&gt;Requisitos&lt;2}&lt;1}

**Cabeçalho:** Afxwin. h

##  <a name="create"></a>CStatic:: criar

Cria o controle estático do Windows e o anexa ao objeto `CStatic`.

```
virtual BOOL Create(
    LPCTSTR lpszText,
    DWORD dwStyle,
    const RECT& rect,
    CWnd* pParentWnd,
    UINT nID = 0xffff);
```

### <a name="parameters"></a>Parâmetros

*lpszText*<br/>
Especifica o texto a ser colocado no controle. Se for NULL, nenhum texto ficará visível.

*dwStyle*<br/>
Especifica o estilo de janela do controle estático. Aplique qualquer combinação de [estilos de controle estático](../../mfc/reference/styles-used-by-mfc.md#static-styles) ao controle.

*Rect*<br/>
Especifica a posição e o tamanho do controle estático. Pode ser uma estrutura de `RECT` ou um objeto de `CRect`.

*pParentWnd*<br/>
Especifica a `CStatic` janela pai, geralmente um objeto `CDialog`. Ele não deve ser nulo.

*nID*<br/>
Especifica a ID de controle do controle estático.

### <a name="return-value"></a>Valor retornado

Diferente de zero, se for bem-sucedido; caso contrário, 0.

### <a name="remarks"></a>Comentários

Construa um objeto `CStatic` em duas etapas. Primeiro, chame o Construtor `CStatic`e, em seguida, chame `Create`, que cria o controle estático do Windows e o anexa ao objeto `CStatic`.

Aplique os seguintes [estilos de janela](../../mfc/reference/styles-used-by-mfc.md#window-styles) a um controle estático:

- WS_CHILD sempre

- Geralmente WS_VISIBLE

- WS_DISABLED raramente

Se você for exibir um bitmap, cursor, ícone ou metarquivo no controle estático, precisará aplicar um dos seguintes [estilos estáticos](../../mfc/reference/styles-used-by-mfc.md#static-styles):

- SS_BITMAP usar esse estilo para bitmaps.

- SS_ICON use esse estilo para cursores e ícones.

- SS_ENHMETAFILE usar esse estilo para metaarquivos avançados.

Para cursores, bitmaps ou ícones, você também pode querer usar o seguinte estilo:

- SS_CENTERIMAGE usar para centralizar a imagem no controle estático.

### <a name="example"></a>{1&gt;Exemplo&lt;1}

[!code-cpp[NVC_MFC_CStatic#1](../../mfc/reference/codesnippet/cpp/cstatic-class_1.cpp)]

##  <a name="cstatic"></a>CStatic::CStatic

Constrói um objeto `CStatic`.

```
CStatic();
```

### <a name="example"></a>{1&gt;Exemplo&lt;1}

[!code-cpp[NVC_MFC_CStatic#2](../../mfc/reference/codesnippet/cpp/cstatic-class_2.cpp)]

##  <a name="drawitem"></a>CStatic::D rawItem

Chamado pelo Framework para desenhar um controle estático desenhado pelo proprietário.

```
virtual void DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct);
```

### <a name="parameters"></a>Parâmetros

*lpDrawItemStruct*<br/>
Um ponteiro para uma estrutura [DRAWITEMSTRUCT](/windows/win32/api/winuser/ns-winuser-drawitemstruct) . A estrutura contém informações sobre o item a ser desenhado e o tipo de desenho necessário.

### <a name="remarks"></a>Comentários

Substitua essa função para implementar o desenho de um objeto de `CStatic` desenhado pelo proprietário (o controle tem o estilo SS_OWNERDRAW).

##  <a name="getbitmap"></a>CStatic:: getbitmap

Obtém o identificador do bitmap, definido anteriormente com [SetBitmap](#setbitmap), que está associado a `CStatic`.

```
HBITMAP GetBitmap() const;
```

### <a name="return-value"></a>Valor retornado

Um identificador para o bitmap atual ou nulo se nenhum bitmap tiver sido definido.

### <a name="example"></a>{1&gt;Exemplo&lt;1}

[!code-cpp[NVC_MFC_CStatic#3](../../mfc/reference/codesnippet/cpp/cstatic-class_3.cpp)]

##  <a name="getcursor"></a>CStatic:: getCursor

Obtém o identificador do cursor, definido anteriormente com [SetCursor](#setcursor), que está associado a `CStatic`.

```
HCURSOR GetCursor();
```

### <a name="return-value"></a>Valor retornado

Um identificador para o cursor atual ou NULL se nenhum cursor tiver sido definido.

### <a name="example"></a>{1&gt;Exemplo&lt;1}

[!code-cpp[NVC_MFC_CStatic#4](../../mfc/reference/codesnippet/cpp/cstatic-class_4.cpp)]

##  <a name="getenhmetafile"></a>CStatic::GetEnhMetaFile

Obtém o identificador do metarquivo avançado, definido anteriormente com [SetEnhMetafile](#setenhmetafile), que está associado a `CStatic`.

```
HENHMETAFILE GetEnhMetaFile() const;
```

### <a name="return-value"></a>Valor retornado

Um identificador para o metarquivo avançado atual ou nulo se nenhum metarquivo avançado tiver sido definido.

### <a name="example"></a>{1&gt;Exemplo&lt;1}

[!code-cpp[NVC_MFC_CStatic#5](../../mfc/reference/codesnippet/cpp/cstatic-class_5.cpp)]

##  <a name="geticon"></a>CStatic:: GetIcon

Obtém o identificador do ícone, definido anteriormente com [SetIcon](#seticon), que está associado a `CStatic`.

```
HICON GetIcon() const;
```

### <a name="return-value"></a>Valor retornado

Um identificador para o ícone atual ou nulo se nenhum ícone tiver sido definido.

### <a name="example"></a>{1&gt;Exemplo&lt;1}

[!code-cpp[NVC_MFC_CStatic#6](../../mfc/reference/codesnippet/cpp/cstatic-class_6.cpp)]

##  <a name="setbitmap"></a>CStatic:: SetBitmap

Associa um novo bitmap ao controle estático.

```
HBITMAP SetBitmap(HBITMAP hBitmap);
```

### <a name="parameters"></a>Parâmetros

*hBitmap*<br/>
Identificador do bitmap a ser desenhado no controle estático.

### <a name="return-value"></a>Valor retornado

O identificador do bitmap que foi anteriormente associado ao controle estático, ou nulo, se nenhum bitmap foi associado ao controle estático.

### <a name="remarks"></a>Comentários

O bitmap será desenhado automaticamente no controle estático. Por padrão, ele será desenhado no canto superior esquerdo e o controle estático será redimensionado para o tamanho do bitmap.

Você pode usar vários estilos de janela e de controle estático, incluindo estes:

- SS_BITMAP usar esse estilo sempre para bitmaps.

- SS_CENTERIMAGE usar para centralizar a imagem no controle estático. Se a imagem for maior que o controle estático, ela será recortada. Se for menor do que o controle estático, o espaço vazio em volta da imagem será preenchido pela cor do pixel no canto superior esquerdo do bitmap.

- O MFC fornece a classe `CBitmap`, que você pode usar quando precisa fazer mais com uma imagem de bitmap do que simplesmente chamar a função do Win32 `LoadBitmap`. `CBitmap`, que contém um tipo de objeto GDI, geralmente é usado em cooperação com `CStatic`, que é uma classe `CWnd` que é usada para exibir um objeto gráfico como um controle estático.

`CImage` é uma classe ATL/MFC que permite trabalhar mais facilmente com DIB (bitmaps independentes de dispositivo). Para obter mais informações, consulte [classe CImage](../../atl-mfc-shared/reference/cimage-class.md).

- O uso típico é para dar `CStatic::SetBitmap` um objeto GDI que é retornado pelo operador HBITMAP de um objeto `CBitmap` ou `CImage`. O código para fazer isso é semelhante à linha a seguir.

```
MyStaticControl.SetBitmap(HBITMAP(MyBitmap));
```

O exemplo a seguir cria dois objetos `CStatic` no heap. Em seguida, ele carrega um com um bitmap do sistema usando `CBitmap::LoadOEMBitmap` e o outro de um arquivo usando `CImage::Load`.

### <a name="example"></a>{1&gt;Exemplo&lt;1}

[!code-cpp[NVC_MFC_CStatic#3](../../mfc/reference/codesnippet/cpp/cstatic-class_3.cpp)]

##  <a name="setcursor"></a>CStatic:: SetCursor

Associa uma nova imagem de cursor ao controle estático.

```
HCURSOR SetCursor(HCURSOR hCursor);
```

### <a name="parameters"></a>Parâmetros

*hCursor*<br/>
Identificador do cursor a ser desenhado no controle estático.

### <a name="return-value"></a>Valor retornado

O identificador do cursor anteriormente associado ao controle estático ou nulo se nenhum cursor estiver associado ao controle estático.

### <a name="remarks"></a>Comentários

O cursor será desenhado automaticamente no controle estático. Por padrão, ele será desenhado no canto superior esquerdo e o controle estático será redimensionado para o tamanho do cursor.

Você pode usar vários estilos de janela e de controle estático, incluindo o seguinte:

- SS_ICON use esse estilo sempre para cursores e ícones.

- SS_CENTERIMAGE usar para centralizar no controle estático. Se a imagem for maior que o controle estático, ela será recortada. Se for menor do que o controle estático, o espaço vazio em volta da imagem será preenchido com a cor do plano de fundo do controle estático.

### <a name="example"></a>{1&gt;Exemplo&lt;1}

[!code-cpp[NVC_MFC_CStatic#4](../../mfc/reference/codesnippet/cpp/cstatic-class_4.cpp)]

##  <a name="setenhmetafile"></a>CStatic::SetEnhMetaFile

Associa uma nova imagem de metarquivo avançado ao controle estático.

```
HENHMETAFILE SetEnhMetaFile(HENHMETAFILE hMetaFile);
```

### <a name="parameters"></a>Parâmetros

*hMetaFile*<br/>
Identificador do metarquivo avançado a ser desenhado no controle estático.

### <a name="return-value"></a>Valor retornado

O identificador do metarquivo avançado anteriormente associado ao controle estático, ou nulo, se nenhum metarquivo avançado foi associado ao controle estático.

### <a name="remarks"></a>Comentários

O metarquivo avançado será desenhado automaticamente no controle estático. O metarquivo avançado é dimensionado para se ajustar ao tamanho do controle estático.

Você pode usar vários estilos de janela e de controle estático, incluindo o seguinte:

- SS_ENHMETAFILE usar esse estilo sempre para metaarquivos avançados.

### <a name="example"></a>{1&gt;Exemplo&lt;1}

[!code-cpp[NVC_MFC_CStatic#5](../../mfc/reference/codesnippet/cpp/cstatic-class_5.cpp)]

##  <a name="seticon"></a>CStatic:: SetIcon

Associa uma nova imagem de ícone ao controle estático.

```
HICON SetIcon(HICON hIcon);
```

### <a name="parameters"></a>Parâmetros

*hIcon*<br/>
Identificador do ícone a ser desenhado no controle estático.

### <a name="return-value"></a>Valor retornado

O identificador do ícone associado anteriormente ao controle estático, ou nulo, se nenhum ícone foi associado ao controle estático.

### <a name="remarks"></a>Comentários

O ícone será desenhado automaticamente no controle estático. Por padrão, ele será desenhado no canto superior esquerdo e o controle estático será redimensionado para o tamanho do ícone.

Você pode usar vários estilos de janela e de controle estático, incluindo o seguinte:

- SS_ICON use esse estilo sempre para cursores e ícones.

- SS_CENTERIMAGE usar para centralizar no controle estático. Se a imagem for maior que o controle estático, ela será recortada. Se for menor do que o controle estático, o espaço vazio em volta da imagem será preenchido com a cor do plano de fundo do controle estático.

### <a name="example"></a>{1&gt;Exemplo&lt;1}

[!code-cpp[NVC_MFC_CStatic#6](../../mfc/reference/codesnippet/cpp/cstatic-class_6.cpp)]

## <a name="see-also"></a>Consulte também

[Classe CWnd](../../mfc/reference/cwnd-class.md)<br/>
[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classe CWnd](../../mfc/reference/cwnd-class.md)<br/>
[Classe CButton](../../mfc/reference/cbutton-class.md)<br/>
[Classe CComboBox](../../mfc/reference/ccombobox-class.md)<br/>
[Classe CEdit](../../mfc/reference/cedit-class.md)<br/>
[Classe CListBox](../../mfc/reference/clistbox-class.md)<br/>
[Classe CScrollBar](../../mfc/reference/cscrollbar-class.md)<br/>
[Classe CDialog](../../mfc/reference/cdialog-class.md)
