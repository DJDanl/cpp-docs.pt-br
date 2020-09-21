---
title: Classe CMFCDynamicLayout
ms.date: 08/29/2019
f1_keywords:
- CMFCDynamicLayout
- AFXLAYOUT/CMFCDynamicLayout
- AFXLAYOUT/CMFCDynamicLayout::AddItem
- AFXLAYOUT/CMFCDynamicLayout::Adjust
- AFXLAYOUT/CMFCDynamicLayout::Create
- AFXLAYOUT/CMFCDynamicLayout::GetHostWnd
- AFXLAYOUT/CMFCDynamicLayout::GetMinSize
- AFXLAYOUT/CMFCDynamicLayout::GetWindowRect
- AFXLAYOUT/CMFCDynamicLayout::HasItem
- AFXLAYOUT/CMFCDynamicLayout::IsEmpty
- AFXLAYOUT/CMFCDynamicLayout::LoadResource
- AFXLAYOUT/CMFCDynamicLayout::SetMinSize
ms.assetid: c2df2976-f049-47fc-9cf0-abe3e01948bc
ms.openlocfilehash: 1c5d73897f7028768476c82824f8c0b6d530aea2
ms.sourcegitcommit: 72161bcd21d1ad9cc3f12261aa84a5b026884afa
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/17/2020
ms.locfileid: "90742899"
---
# <a name="cmfcdynamiclayout-class"></a>Classe CMFCDynamicLayout

Especifica como os controles em uma janela são movidos e redimensionados conforme o usuário redimensiona a janela.

## <a name="syntax"></a>Sintaxe

```
class CMFCDynamicLayout : public CObject
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|`CMFCDynamicLayout::CMFCDynamicLayout`|Constrói um objeto `CMFCDynamicLayout`.|
|`CMFCDynamicLayout::~CMFCDynamicLayout`|Destruidor.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CMFCDynamicLayout::AddItem](#additem)|Adiciona uma janela filho, normalmente um controle, à lista de janelas que são controladas pelo Gerenciador de layout dinâmico.|
|[CMFCDynamicLayout::Adjust](#adjust)|Adiciona uma janela filho, normalmente um controle, à lista de janelas que são controladas pelo Gerenciador de layout dinâmico.|
|[CMFCDynamicLayout::Create](#create)|Armazena e valida a janela do host.|
|[CMFCDynamicLayout::GetHostWnd](#gethostwnd)|Retorna um ponteiro para uma janela de host.|
|[CMFCDynamicLayout::GetMinSize](#getminsize)|Retorna o tamanho da janela abaixo do qual o layout não é ajustado.|
|[CMFCDynamicLayout::GetWindowRect](#getwindowrect)|Recupera o retângulo da área do cliente atual da janela.|
|[CMFCDynamicLayout::HasItem](#hasitem)|Verifica se um controle filho foi adicionado ao layout dinâmico.|
|[CMFCDynamicLayout::IsEmpty](#isempty)|Verifica se um layout dinâmico não tem nenhuma janela filho adicionada.|
|[CMFCDynamicLayout::LoadResource](#loadresource)|Lê o layout dinâmico de AFX_DIALOG_LAYOUT recurso e, em seguida, aplica o layout à janela do host.|
|[CMFCDynamicLayout estático:: MoveHorizontal](#movehorizontal)|Obtém um valor [MoveSettings](#movesettings_structure) que define o quanto um controle filho é movido horizontalmente quando o usuário redimensiona sua janela de hospedagem.|
|[CMFCDynamicLayout estático:: MoveHorizontalAndVertical](#movehorizontalandvertical)|Obtém um valor [MoveSettings](#movesettings_structure) que define o quanto um controle filho é movido horizontalmente quando o usuário redimensiona sua janela de hospedagem.|
|[CMFCDynamicLayout estático:: MoveNone](#movenone)|Obtém um valor [MoveSettings](#movesettings_structure) que não representa movimento, vertical ou horizontal, para um controle filho.|
|[CMFCDynamicLayout estático:: MoveVertical](#movevertical)|Obtém um valor [MoveSettings](#movesettings_structure) que define o quanto um controle filho é movido verticalmente quando o usuário redimensiona sua janela de hospedagem.|
|[CMFCDynamicLayout::SetMinSize](#setminsize)|Define o tamanho da janela abaixo do qual o layout não é ajustado.|
|[CMFCDynamicLayout estático:: SizeHorizontal](#sizehorizontal)|Obtém um valor [SizeSettings](#sizesettings_structure) que define o quanto um controle filho é redimensionado horizontalmente quando o usuário redimensiona sua janela de hospedagem.|
|[CMFCDynamicLayout estático:: SizeHorizontalAndVertical](#sizehorizontalandvertical)|Obtém um valor [SizeSettings](#sizesettings_structure) que define o quanto um controle filho é redimensionado horizontalmente quando o usuário redimensiona sua janela de hospedagem.|
|[CMFCDynamicLayout estático:: SizeNone](#sizenone)|Obtém um valor [SizeSettings](#sizesettings_structure) que não representa nenhuma alteração no tamanho de um controle filho.|
|[CMFCDynamicLayout estático:: SizeVertical](#sizevertical)|Obtém um valor [SizeSettings](#sizesettings_structure) que define o quanto um controle filho é redimensionado verticalmente quando o usuário redimensiona sua janela de hospedagem.|

## <a name="nested-types"></a>Tipos aninhados

|Nome|Descrição|
|----------|-----------------|
|[Estrutura CMFCDynamicLayout::MoveSettings](#movesettings_structure)|Encapsula os dados de movimentação para controles em um layout dinâmico.|
|[CMFCDynamicLayout::SizeSettings Structure](#sizesettings_structure)|Encapsula dados de alteração de tamanho para controles em um layout dinâmico.|

## <a name="remarks"></a>Comentários

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[CObject](../../mfc/reference/cobject-class.md)

[CMFCDynamicLayout](../../mfc/reference/cmfctoolbarbutton-class.md)

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxlayout. h

## <a name="cmfcdynamiclayoutadditem"></a><a name="additem"></a> CMFCDynamicLayout:: AddItem

Adiciona uma janela filho, normalmente um controle, à lista de janelas que são controladas pelo Gerenciador de layout dinâmico.

```
BOOL AddItem(
    HWND hwnd,
    MoveSettings moveSettings SizeSettings sizeSettings);

BOOL AddItem(
    int nID,
    MoveSettings moveSettings SizeSettings sizeSettings);
```

### <a name="parameters"></a>Parâmetros

*HWND*<br/>
O identificador para a janela a ser adicionada.

*nID*<br/>
A ID do controle filho a ser adicionada.

*moveSettings*<br/>
Uma estrutura que descreve como o controle deve ser movido conforme o tamanho da janela é alterado.

*sizeSettings*<br/>
Uma estrutura que descreve como o controle deve ser redimensionado à medida que o tamanho da janela é alterado.

### <a name="return-value"></a>Valor Retornado

TRUE se o item foi adicionado com êxito; caso contrário, FALSE.

### <a name="remarks"></a>Comentários

A posição e o tamanho de um controle filho são alterados dinamicamente quando uma janela de hospedagem está sendo redimensionada.

## <a name="cmfcdynamiclayoutadjust"></a><a name="adjust"></a> CMFCDynamicLayout:: ajustar

Adiciona uma janela filho, normalmente um controle, à lista de janelas que são controladas pelo Gerenciador de layout dinâmico.

```cpp
void Adjust();
```

### <a name="remarks"></a>Comentários

A posição e o tamanho de um controle filho são alterados dinamicamente quando uma janela de hospedagem está sendo redimensionada.

## <a name="cmfcdynamiclayoutcreate"></a><a name="create"></a> CMFCDynamicLayout:: criar

Armazena e valida a janela do host.

```
BOOL Create(CWnd* pHostWnd);
```

### <a name="parameters"></a>Parâmetros

*pHostWnd*<br/>
Um ponteiro para a janela do host.

### <a name="return-value"></a>Valor Retornado

TRUE se a criação for bem-sucedida; caso contrário, FALSE.

### <a name="remarks"></a>Comentários

## <a name="cmfcdynamiclayoutgethostwnd"></a><a name="gethostwnd"></a> CMFCDynamicLayout::GetHostWnd

Retorna um ponteiro para uma janela de host.

```
CWnd* GetHostWnd();
```

### <a name="return-value"></a>Valor Retornado

Um ponteiro para a janela do host.

### <a name="remarks"></a>Comentários

Por padrão, todas as posições de controle filho são recalculadas em relação a essa janela.

## <a name="cmfcdynamiclayoutgetminsize"></a><a name="getminsize"></a> CMFCDynamicLayout:: getminize

Retorna o tamanho da janela abaixo do qual o layout não é ajustado.

```
CSize GetMinSize();
```

### <a name="return-value"></a>Valor Retornado

O tamanho da janela abaixo do qual o layout não é ajustado.

### <a name="remarks"></a>Comentários

A posição e o tamanho de um controle filho são alterados dinamicamente quando uma janela de hospedagem está sendo redimensionada, mas há um tamanho mínimo abaixo do qual o layout não é ajustado. O usuário pode redimensionar a janela para um tamanho menor, mas partes da janela são ocultadas da exibição.

## <a name="cmfcdynamiclayoutgetwindowrect"></a><a name="getwindowrect"></a> CMFCDynamicLayout::GetWindowRect

Recupera o retângulo da área do cliente atual da janela.

```cpp
void GetHostWndRect(CRect& rect,);
```

### <a name="parameters"></a>Parâmetros

*Rect*<br/>
Depois que a função retorna, esse parâmetro contém o retângulo delimitador da área de layout. Esse é um parâmetro de saída; o valor de entrada é substituído.

### <a name="remarks"></a>Comentários

## <a name="cmfcdynamiclayouthasitem"></a><a name="hasitem"></a> CMFCDynamicLayout::HasItem

Verifica se um controle filho foi adicionado ao layout dinâmico.

```
BOOL HasItem(HWND hwnd);
```

### <a name="parameters"></a>Parâmetros

*HWND*<br/>
O identificador de janela para o controle.

### <a name="return-value"></a>Valor Retornado

TRUE se o layout já tiver este item; caso contrário, FALSE.

### <a name="remarks"></a>Comentários

## <a name="cmfcdynamiclayoutisempty"></a><a name="isempty"></a> CMFCDynamicLayout:: IsEmpty

Verifica se um layout dinâmico não tem nenhuma janela filho adicionada.

```
BOOL IsEmpty();
```

### <a name="return-value"></a>Valor Retornado

TRUE se o layout não tiver itens; caso contrário, FALSE.

### <a name="remarks"></a>Comentários

## <a name="cmfcdynamiclayoutloadresource"></a><a name="loadresource"></a> CMFCDynamicLayout:: LoadResource

Lê o layout dinâmico de AFX_DIALOG_LAYOUT recurso e, em seguida, aplica o layout à janela do host.

```
static BOOL LoadResource(CWnd* pHostWnd,
    LPVOID lpResource,
    DWORD dwSize);
```

### <a name="parameters"></a>Parâmetros

*pHostWnd*<br/>
Um ponteiro para a janela do host.

*lpResource*<br/>
Um ponteiro para o buffer que contém o recurso de AFX_DIALOG_LAYOUT.

*dwSize*<br/>
O tamanho do buffer em bytes.

### <a name="return-value"></a>Valor Retornado

TRUE se o recurso for carregado e aplicado à janela do host; caso contrário, FALSE.

### <a name="remarks"></a>Comentários

## <a name="cmfcdynamiclayoutmovehorizontal"></a><a name="movehorizontal"></a> CMFCDynamicLayout::MoveHorizontal

Obtém um valor [MoveSettings](#movesettings_structure) que define o quanto um controle filho é movido horizontalmente quando o usuário redimensiona sua janela de hospedagem.

```
static MoveSettings MoveHorizontal(int nRatio);
```

### <a name="parameters"></a>Parâmetros

*nRatio*<br/>
Define como um percentual até o qual um controle filho é movido horizontalmente quando o usuário redimensiona a janela do host.

### <a name="return-value"></a>Valor Retornado

Um valor de [MoveSettings](#movesettings_structure) que encapsula a taxa de movimentação solicitada.

### <a name="remarks"></a>Comentários

## <a name="cmfcdynamiclayoutmovehorizontalandvertical"></a><a name="movehorizontalandvertical"></a> CMFCDynamicLayout::MoveHorizontalAndVertical

Obtém um valor [MoveSettings](#movesettings_structure) que define o quanto um controle filho é movido horizontalmente quando o usuário redimensiona sua janela de hospedagem.

```
static MoveSettings MoveHorizontalAndVertical(int nXRatio int nYRatio);
```

### <a name="parameters"></a>Parâmetros

*nXRatio*<br/>
Define como um percentual até o qual um controle filho é movido horizontalmente quando o usuário redimensiona a janela do host.

*nYRatio*<br/>
Define como um percentual até o qual um controle filho é movido verticalmente quando o usuário redimensiona a janela do host.

### <a name="return-value"></a>Valor Retornado

Um valor de [MoveSettings](#movesettings_structure) que encapsula a taxa de movimentação solicitada.

### <a name="remarks"></a>Comentários

## <a name="cmfcdynamiclayoutmovenone"></a><a name="movenone"></a> CMFCDynamicLayout::MoveNone

Obtém um valor [MoveSettings](#movesettings_structure) que não representa movimento, vertical ou horizontal, para um controle filho.

```
static MoveSettings MoveNone();
```

### <a name="return-value"></a>Valor Retornado

Um valor de [MoveSettings](#movesettings_structure) que corrige o controle em vigor, para que ele não se mova enquanto o usuário redimensiona a janela do host.

### <a name="remarks"></a>Comentários

## <a name="cmfcdynamiclayoutmovesettings-structure"></a><a name="movesettings_structure"></a> Estrutura CMFCDynamicLayout:: MoveSettings

Encapsula os dados de movimentação para controles em um layout dinâmico.

```
struct CMFCDynamicLayout::MoveSettings;
```

### <a name="remarks"></a>Comentários

Esta é uma classe aninhada dentro do `CMFCDynamicLayout` .

## <a name="cmfcdynamiclayoutmovesettingsishorizontal"></a>CMFCDynamicLayout:: MoveSettings:: IsHorizontal

Verifique se os dados de movimentação especificam uma movimentação horizontal diferente de zero.

```
BOOL IsHorizontal() const
```

### <a name="return-value"></a>Valor Retornado

TRUE se o `MoveSettings` objeto especificar uma movimentação horizontal diferente de zero.

## <a name="cmfcdynamiclayoutmovesettingsisnone"></a>CMFCDynamicLayout:: MoveSettings:: IsNone

Verifique se os dados de movimentação não especificam movimento.

```
BOOL IsNone() const
```

### <a name="return-value"></a>Valor Retornado

TRUE se o `MoveSettings` objeto não especificar nenhum movimento.

## <a name="cmfcdynamiclayoutmovesettingsisvertical"></a>CMFCDynamicLayout:: MoveSettings:: IsVertical

Verifique se os dados de movimentação especificam um movimento vertical diferente de zero.

```
BOOL IsVertical() const
```

### <a name="return-value"></a>Valor Retornado

TRUE se o `MoveSettings` objeto especificar um movimento vertical diferente de zero.

## <a name="cmfcdynamiclayoutmovevertical"></a><a name="movevertical"></a> CMFCDynamicLayout::MoveVertical

Obtém um valor [MoveSettings](#movesettings_structure) que define o quanto um controle filho é movido verticalmente quando o usuário redimensiona sua janela de hospedagem.

```
static MoveSettings MoveVertical(int nRatio);
```

### <a name="parameters"></a>Parâmetros

*nRatio*<br/>
Define como um percentual até o qual um controle filho é movido verticalmente quando o usuário redimensiona a janela do host.

### <a name="return-value"></a>Valor Retornado

Um valor de [MoveSettings](#movesettings_structure) que encapsula a taxa de movimentação solicitada.

### <a name="remarks"></a>Comentários

## <a name="cmfcdynamiclayoutsetminsize"></a><a name="setminsize"></a> CMFCDynamicLayout:: setminize

Define o tamanho da janela abaixo do qual o layout não é ajustado.

```cpp
void SetMinSize(const CSize& size);
```

### <a name="parameters"></a>Parâmetros

*size*<br/>
O tamanho desejado abaixo do qual o layout não é ajustado.

### <a name="remarks"></a>Comentários

A posição e o tamanho de um controle filho são alterados dinamicamente quando uma janela de hospedagem está sendo redimensionada, mas há um tamanho mínimo abaixo do qual o layout não é ajustado. O usuário pode redimensionar a janela para um tamanho menor, mas partes da janela são ocultadas da exibição.

## <a name="cmfcdynamiclayoutsizehorizontal"></a><a name="sizehorizontal"></a> CMFCDynamicLayout::SizeHorizontal

Obtém um valor [SizeSettings](#sizesettings_structure) que define o quanto um controle filho é redimensionado horizontalmente quando o usuário redimensiona sua janela de hospedagem.

```
static SizeSettings SizeHorizontal(int nRatio);
```

### <a name="parameters"></a>Parâmetros

*nRatio*<br/>
Define como um percentual até o qual um controle filho é redimensionado horizontalmente quando o usuário redimensiona a janela do host.

### <a name="return-value"></a>Valor Retornado

Um valor [SizeSettings](#sizesettings_structure) que encapsula a taxa de tamanho solicitada.

### <a name="remarks"></a>Comentários

## <a name="cmfcdynamiclayoutsizehorizontalandvertical"></a><a name="sizehorizontalandvertical"></a> CMFCDynamicLayout::SizeHorizontalAndVertical

Obtém um valor [SizeSettings](#sizesettings_structure) que define o quanto um controle filho é redimensionado horizontalmente quando o usuário redimensiona sua janela de hospedagem.

```
static SizeSettings SizeHorizontalAndVertical(int nXRatio int nYRatio);
```

### <a name="parameters"></a>Parâmetros

*nXRatio*<br/>
Define como um percentual até o qual um controle filho é redimensionado horizontalmente quando o usuário redimensiona a janela do host.

*nYRatio*<br/>
Define como um percentual até o qual um controle filho é redimensionado verticalmente quando o usuário redimensiona a janela do host.

### <a name="return-value"></a>Valor Retornado

Um valor [SizeSettings](#sizesettings_structure) que encapsula a taxa de tamanho solicitada.

### <a name="remarks"></a>Comentários

## <a name="cmfcdynamiclayoutsizenone"></a><a name="sizenone"></a> CMFCDynamicLayout::SizeNone

Obtém um valor [SizeSettings](#sizesettings_structure) que não representa nenhuma alteração no tamanho de um controle filho.

```
static SizeSettings SizeNone();
```

### <a name="return-value"></a>Valor Retornado

Um valor [SizeSettings](#sizesettings_structure) que corrige o controle em um determinado tamanho, para que ele não altere o tamanho à medida que o usuário redimensiona a janela do host.

### <a name="remarks"></a>Comentários

## <a name="cmfcdynamiclayoutsizesettings-structure"></a><a name="sizesettings_structure"></a> Estrutura CMFCDynamicLayout:: SizeSettings

Encapsula dados de alteração de tamanho para controles em um layout dinâmico.

```
struct CMFCDynamicLayout::SizeSettings;
```

### <a name="remarks"></a>Comentários

Esta é uma classe aninhada dentro do `CMFCDynamicLayout` .

## <a name="cmfcdynamiclayoutsizesettingsishorizontal"></a>CMFCDynamicLayout:: SizeSettings:: IsHorizontal

Verifica se os dados de redimensionamento especificam um redimensionamento horizontal diferente de zero.

```
BOOL IsHorizontal() const
```

### <a name="return-value"></a>Valor Retornado

TRUE se o `SizeSettings` objeto especificar um redimensionamento horizontal diferente de zero.

## <a name="cmfcdynamiclayoutsizesettingsisnone"></a>CMFCDynamicLayout:: SizeSettings:: IsNone

Verifica se os dados de redimensionamento não especificam redimensionamento.

```
BOOL IsNone() const
```

### <a name="return-value"></a>Valor Retornado

TRUE se o `SizeSettings` objeto não especificar nenhum redimensionamento.

## <a name="cmfcdynamiclayoutsizesettingsisvertical"></a>CMFCDynamicLayout:: SizeSettings:: IsVertical

Verifica se os dados de redimensionamento especificam um redimensionamento vertical diferente de zero.

```
BOOL IsVertical() const
```

### <a name="return-value"></a>Valor Retornado

TRUE se o `SizeSettings` objeto especificar um redimensionamento vertical diferente de zero.

## <a name="cmfcdynamiclayoutsizevertical"></a><a name="sizevertical"></a> CMFCDynamicLayout::SizeVertical

Obtém um valor [SizeSettings](#sizesettings_structure) que define o quanto um controle filho é redimensionado verticalmente quando o usuário redimensiona sua janela de hospedagem.

```
static SizeSettings SizeVertical(int nRatio);
```

### <a name="parameters"></a>Parâmetros

*nRatio*<br/>
Define como um percentual até o qual um controle filho é redimensionado verticalmente quando o usuário redimensiona a janela do host.

### <a name="return-value"></a>Valor Retornado

Um valor [SizeSettings](#sizesettings_structure) que encapsula a taxa de tamanho solicitada.

### <a name="remarks"></a>Comentários

## <a name="see-also"></a>Confira também

[Gráfico de hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classes](../../mfc/reference/mfc-classes.md)
