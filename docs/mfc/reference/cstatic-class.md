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
ms.openlocfilehash: e5c3705c0aa2fd90e73cb54ba5a97c252ed2cf83
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81371639"
---
# <a name="cstatic-class"></a>Classe CStatic

Fornece a funcionalidade de um controle estático do Windows.

## <a name="syntax"></a>Sintaxe

```
class CStatic : public CWnd
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[Cstatic::Cstatic](#cstatic)|Constrói um objeto `CStatic`.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[Cstatic::Criar](#create)|Cria o controle estático do `CStatic` Windows e o anexa ao objeto.|
|[CStatic::DrawItem](#drawitem)|Anular para desenhar um controle estático desenhado pelo proprietário.|
|[CStatic::GetBitmap](#getbitmap)|Recupera a alça do bitmap previamente definida com [SetBitmap](#setbitmap).|
|[CStatic::GetCursor](#getcursor)|Recupera a alça da imagem do cursor previamente definida com [SetCursor](#setcursor).|
|[CStatic::GetEnhMetaFile](#getenhmetafile)|Recupera a alça do metaarquivo aprimorado previamente definido com [SetEnhMetaFile](#setenhmetafile).|
|[Cstatic::Geticon](#geticon)|Recupera a alça do ícone previamente definido com [SetIcon](#seticon).|
|[CStatic::SetBitmap](#setbitmap)|Especifica um bitmap a ser exibido no controle estático.|
|[CStatic::SetCursor](#setcursor)|Especifica uma imagem do cursor a ser exibida no controle estático.|
|[CStatic::SetEnhMetaFile](#setenhmetafile)|Especifica um metaarquivo aprimorado a ser exibido no controle estático.|
|[Cstatic::Seticon](#seticon)|Especifica um ícone a ser exibido no controle estático.|

## <a name="remarks"></a>Comentários

Um controle estático exibe uma seqüência de texto, caixa, retângulo, ícone, cursor, bitmap ou metaarquivo aprimorado. Pode ser usado para rotular, caixa ou separar outros controles. Um controle estático normalmente não leva nenhuma entrada e não fornece saída; no entanto, ele pode notificar seu pai de cliques do mouse se ele for criado com SS_NOTIFY estilo.

Crie um controle estático em dois passos. Primeiro, chame o construtor `CStatic` para construir o objeto, em seguida, chame a `CStatic` função [Criar](#create) membro para criar o controle estático e anexá-lo ao objeto.

Se você `CStatic` criar um objeto dentro de uma `CStatic` caixa de diálogo (através de um recurso de diálogo), o objeto será automaticamente destruído quando o usuário fechar a caixa de diálogo.

Se você `CStatic` criar um objeto dentro de uma janela, você também pode precisar destruí-lo. Um `CStatic` objeto criado na pilha dentro de uma janela é automaticamente destruído. Se você `CStatic` criar o objeto no heap usando a **nova** função, você deve chamar **excluir** no objeto para destruí-lo quando você terminar com ele.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[Cobject](../../mfc/reference/cobject-class.md)

[Ccmdtarget](../../mfc/reference/ccmdtarget-class.md)

[CWnd](../../mfc/reference/cwnd-class.md)

`CStatic`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxwin.h

## <a name="cstaticcreate"></a><a name="create"></a>Cstatic::Criar

Cria o controle estático do `CStatic` Windows e o anexa ao objeto.

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
Especifica o texto a ser colocado no controle. Se NULO, nenhum texto será visível.

*Dwstyle*<br/>
Especifica o estilo da janela do controle estático. Aplique qualquer combinação de estilos de [controle estático séstico](../../mfc/reference/styles-used-by-mfc.md#static-styles) susceptem ao controle.

*Rect*<br/>
Especifica a posição e o tamanho do controle estático. Pode ser uma `RECT` estrutura `CRect` ou um objeto.

*Pparentwnd*<br/>
Especifica a `CStatic` janela pai, `CDialog` geralmente um objeto. Não deve ser NULO.

*nID*<br/>
Especifica o ID de controle estático.

### <a name="return-value"></a>Valor retornado

Não zero se bem sucedido; caso contrário, 0.

### <a name="remarks"></a>Comentários

Construa `CStatic` um objeto em dois passos. Primeiro, chame o `CStatic`construtor , `Create`e depois chame , que cria `CStatic` o controle estático do Windows e o anexa ao objeto.

Aplique os [seguintes estilos de janela](../../mfc/reference/styles-used-by-mfc.md#window-styles) a um controle estático:

- WS_CHILD Sempre

- WS_VISIBLE Normalmente

- WS_DISABLED raramente

Se você vai exibir um bitmap, cursor, ícone ou metaarquivo no controle estático, você precisará aplicar um dos [seguintes estilos estáticos:](../../mfc/reference/styles-used-by-mfc.md#static-styles)

- SS_BITMAP Use este estilo para bitmaps.

- SS_ICON Use este estilo para cursores e ícones.

- SS_ENHMETAFILE Use este estilo para metaarquivos aprimorados.

Para cursors, bitmaps ou ícones, você também pode querer usar o seguinte estilo:

- SS_CENTERIMAGE Usar para centralizar a imagem no controle estático.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CStatic#1](../../mfc/reference/codesnippet/cpp/cstatic-class_1.cpp)]

## <a name="cstaticcstatic"></a><a name="cstatic"></a>Cstatic::Cstatic

Constrói um objeto `CStatic`.

```
CStatic();
```

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CStatic#2](../../mfc/reference/codesnippet/cpp/cstatic-class_2.cpp)]

## <a name="cstaticdrawitem"></a><a name="drawitem"></a>CStatic::DrawItem

Chamado pela estrutura para desenhar um controle estático desenhado pelo proprietário.

```
virtual void DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct);
```

### <a name="parameters"></a>Parâmetros

*Lpdrawitemstruct*<br/>
Um ponteiro para uma estrutura [DRAWITEMSTRUCT.](/windows/win32/api/winuser/ns-winuser-drawitemstruct) A estrutura contém informações sobre o item a ser sorteado e o tipo de desenho necessário.

### <a name="remarks"></a>Comentários

Substituir esta função para implementar o `CStatic` desenho para um objeto desenhado pelo proprietário (o controle tem o estilo SS_OWNERDRAW).

## <a name="cstaticgetbitmap"></a><a name="getbitmap"></a>CStatic::GetBitmap

Obtém a alça do bitmap, previamente definida com `CStatic` [SetBitmap,](#setbitmap)que está associada a .

```
HBITMAP GetBitmap() const;
```

### <a name="return-value"></a>Valor retornado

Uma alça para o bitmap atual ou NULL se nenhum bitmap tiver sido definido.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CStatic#3](../../mfc/reference/codesnippet/cpp/cstatic-class_3.cpp)]

## <a name="cstaticgetcursor"></a><a name="getcursor"></a>CStatic::GetCursor

Obtém a pega do cursor, previamente definida com `CStatic` [SetCursor,](#setcursor)que está associada a .

```
HCURSOR GetCursor();
```

### <a name="return-value"></a>Valor retornado

Uma alça para o cursor atual, ou NULL se nenhum cursor foi definido.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CStatic#4](../../mfc/reference/codesnippet/cpp/cstatic-class_4.cpp)]

## <a name="cstaticgetenhmetafile"></a><a name="getenhmetafile"></a>CStatic::GetEnhMetaFile

Obtém a alça do metaarquivo aprimorado, previamente definido com [SetEnhMetafile](#setenhmetafile), que está associado `CStatic`a .

```
HENHMETAFILE GetEnhMetaFile() const;
```

### <a name="return-value"></a>Valor retornado

Uma alça para o metaarquivo aprimorado atual ou NULL se nenhum meta-arquivo aprimorado tiver sido definido.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CStatic#5](../../mfc/reference/codesnippet/cpp/cstatic-class_5.cpp)]

## <a name="cstaticgeticon"></a><a name="geticon"></a>Cstatic::Geticon

Obtém a alça do ícone, previamente definida com `CStatic` [SetIcon](#seticon), que está associada a .

```
HICON GetIcon() const;
```

### <a name="return-value"></a>Valor retornado

Uma alça para o ícone atual ou NULL se nenhum ícone tiver sido definido.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CStatic#6](../../mfc/reference/codesnippet/cpp/cstatic-class_6.cpp)]

## <a name="cstaticsetbitmap"></a><a name="setbitmap"></a>CStatic::SetBitmap

Associa um novo bitmap com o controle estático.

```
HBITMAP SetBitmap(HBITMAP hBitmap);
```

### <a name="parameters"></a>Parâmetros

*Hbitmap*<br/>
Alça do bitmap a ser desenhado no controle estático.

### <a name="return-value"></a>Valor retornado

A alça do bitmap que anteriormente estava associada ao controle estático, ou NULL se nenhum bitmap estava associado ao controle estático.

### <a name="remarks"></a>Comentários

O bitmap será desenhado automaticamente no controle estático. Por padrão, ele será desenhado no canto superior esquerdo e o controle estático será redimensionado para o tamanho do bitmap.

Você pode usar vários estilos de controle de janela e estática, incluindo estes:

- SS_BITMAP Use este estilo sempre para bitmaps.

- SS_CENTERIMAGE Usar para centralizar a imagem no controle estático. Se a imagem for maior que o controle estático, ela será cortada. Se for menor que o controle estático, o espaço vazio ao redor da imagem será preenchido pela cor do pixel no canto superior esquerdo do bitmap.

- O MFC `CBitmap`fornece a classe , que você pode usar quando você tem que `LoadBitmap`fazer mais com uma imagem bitmap do que apenas chamar a função Win32 . `CBitmap`, que contém um tipo de objeto GDI, é frequentemente usado em cooperação com `CStatic`, que é uma `CWnd` classe que é usada para exibir um objeto gráfico como um controle estático.

`CImage`é uma classe ATL/MFC que permite trabalhar mais facilmente com bitmaps independentes de dispositivos (DIB). Para obter mais informações, consulte [CImage Class](../../atl-mfc-shared/reference/cimage-class.md).

- O uso típico `CStatic::SetBitmap` é dar um objeto GDI que é `CBitmap` devolvido `CImage` pelo operador HBITMAP de um ou objeto. O código para fazer isso se assemelha à seguinte linha.

```
MyStaticControl.SetBitmap(HBITMAP(MyBitmap));
```

O exemplo a `CStatic` seguir cria dois objetos no heap. Em seguida, ele carrega um `CBitmap::LoadOEMBitmap` com um bitmap `CImage::Load`do sistema usando e o outro a partir de um arquivo usando .

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CStatic#3](../../mfc/reference/codesnippet/cpp/cstatic-class_3.cpp)]

## <a name="cstaticsetcursor"></a><a name="setcursor"></a>CStatic::SetCursor

Associa uma nova imagem do cursor com o controle estático.

```
HCURSOR SetCursor(HCURSOR hCursor);
```

### <a name="parameters"></a>Parâmetros

*Hcursor*<br/>
Alça do cursor a ser desenhado no controle estático.

### <a name="return-value"></a>Valor retornado

A alça do cursor anteriormente associada ao controle estático, ou NULL, se nenhum cursor foi associado ao controle estático.

### <a name="remarks"></a>Comentários

O cursor será desenhado automaticamente no controle estático. Por padrão, ele será desenhado no canto superior esquerdo e o controle estático será redimensionado para o tamanho do cursor.

Você pode usar vários estilos de controle de janela e estática, incluindo o seguinte:

- SS_ICON Use este estilo sempre para cursores e ícones.

- SS_CENTERIMAGE Usar para centralizar no controle estático. Se a imagem for maior que o controle estático, ela será cortada. Se for menor que o controle estático, o espaço vazio ao redor da imagem será preenchido com a cor de fundo do controle estático.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CStatic#4](../../mfc/reference/codesnippet/cpp/cstatic-class_4.cpp)]

## <a name="cstaticsetenhmetafile"></a><a name="setenhmetafile"></a>CStatic::SetEnhMetaFile

Associa uma nova imagem de metaarquivo aprimorada com o controle estático.

```
HENHMETAFILE SetEnhMetaFile(HENHMETAFILE hMetaFile);
```

### <a name="parameters"></a>Parâmetros

*hMetaFile*<br/>
Alça do metaarquivo aprimorado a ser desenhado no controle estático.

### <a name="return-value"></a>Valor retornado

A alça do metaarquivo aprimorado anteriormente associada ao controle estático, ou NULL se nenhum metaarquivo aprimorado foi associado ao controle estático.

### <a name="remarks"></a>Comentários

O metaarquivo aprimorado será desenhado automaticamente no controle estático. O metaarquivo aprimorado é dimensionado para se adequar ao tamanho do controle estático.

Você pode usar vários estilos de controle de janela e estática, incluindo o seguinte:

- SS_ENHMETAFILE Use este estilo sempre para metaarquivos aprimorados.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CStatic#5](../../mfc/reference/codesnippet/cpp/cstatic-class_5.cpp)]

## <a name="cstaticseticon"></a><a name="seticon"></a>Cstatic::Seticon

Associa uma nova imagem de ícone com o controle estático.

```
HICON SetIcon(HICON hIcon);
```

### <a name="parameters"></a>Parâmetros

*Hicon*<br/>
Alça do ícone a ser desenhado no controle estático.

### <a name="return-value"></a>Valor retornado

A alça do ícone anteriormente associada ao controle estático, ou NULL, se nenhum ícone estivesse associado ao controle estático.

### <a name="remarks"></a>Comentários

O ícone será desenhado automaticamente no controle estático. Por padrão, ele será desenhado no canto superior esquerdo e o controle estático será redimensionado para o tamanho do ícone.

Você pode usar vários estilos de controle de janela e estática, incluindo o seguinte:

- SS_ICON Use este estilo sempre para cursores e ícones.

- SS_CENTERIMAGE Usar para centralizar no controle estático. Se a imagem for maior que o controle estático, ela será cortada. Se for menor que o controle estático, o espaço vazio ao redor da imagem será preenchido com a cor de fundo do controle estático.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CStatic#6](../../mfc/reference/codesnippet/cpp/cstatic-class_6.cpp)]

## <a name="see-also"></a>Confira também

[Classe CWnd](../../mfc/reference/cwnd-class.md)<br/>
[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classe CWnd](../../mfc/reference/cwnd-class.md)<br/>
[Classe CButton](../../mfc/reference/cbutton-class.md)<br/>
[Classe CComboBox](../../mfc/reference/ccombobox-class.md)<br/>
[Classe CEdit](../../mfc/reference/cedit-class.md)<br/>
[Classe CListBox](../../mfc/reference/clistbox-class.md)<br/>
[Classe CScrollBar](../../mfc/reference/cscrollbar-class.md)<br/>
[Classe CDialog](../../mfc/reference/cdialog-class.md)
