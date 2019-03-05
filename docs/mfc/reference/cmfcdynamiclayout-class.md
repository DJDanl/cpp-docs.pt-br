---
title: Classe CMFCDynamicLayout
ms.date: 11/04/2016
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
ms.openlocfilehash: 40dedbe2737a79b7531b8acd47870ce7cb788604
ms.sourcegitcommit: c3093251193944840e3d0a068ecc30e6449624ba
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/04/2019
ms.locfileid: "57288396"
---
# <a name="cmfcdynamiclayout-class"></a>Classe CMFCDynamicLayout

Especifica como os controles em uma janela são movidos e redimensionados conforme o usuário redimensiona a janela.

## <a name="syntax"></a>Sintaxe

```
class CMFCDynamicLayout : public CObject
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores Públicos

|Nome|Descrição|
|----------|-----------------|
|`CMFCDynamicLayout::CMFCDynamicLayout`|Constrói um objeto `CMFCDynamicLayout`.|
|`CMFCDynamicLayout::~CMFCDynamicLayout`|Destruidor.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CMFCDynamicLayout::AddItem](#additem)|Adiciona uma janela filho, geralmente, um controle, a lista de janelas que são controlados pelo Gerenciador de layout dinâmico.|
|[CMFCDynamicLayout::Adjust](#adjust)|Adiciona uma janela filho, geralmente, um controle, a lista de janelas que são controlados pelo Gerenciador de layout dinâmico.|
|[CMFCDynamicLayout::Create](#create)|Armazena e valida a janela do host.|
|[CMFCDynamicLayout::GetHostWnd](#gethostwnd)|Retorna um ponteiro para uma janela de host.|
|[CMFCDynamicLayout::GetMinSize](#getminsize)|Retorna o tamanho da janela abaixo do qual o layout não é ajustado.|
|[CMFCDynamicLayout::GetWindowRect](#getwindowrect)|Recupera o retângulo para a área de cliente da janela atual.|
|[CMFCDynamicLayout::HasItem](#hasitem)|Verifica se um controle filho foi adicionado ao layout dinâmico.|
|[CMFCDynamicLayout::IsEmpty](#isempty)|Verifica se um layout dinâmico não tem nenhuma janela filho adicionada.|
|[CMFCDynamicLayout::LoadResource](#loadresource)|Lê o layout dinâmico do recurso AFX_DIALOG_LAYOUT e, em seguida, aplica o layout para a janela do host.|
|estático [CMFCDynamicLayout::MoveHorizontal](#movehorizontal)|Obtém uma [MoveSettings](#movesettings_structure) valor que define o quanto um controle filho é movido horizontalmente quando o usuário redimensiona a janela de hospedagem.|
|estático [CMFCDynamicLayout::MoveHorizontalAndVertical](#movehorizontalandvertical)|Obtém uma [MoveSettings](#movesettings_structure) valor que define o quanto um controle filho é movido horizontalmente quando o usuário redimensiona a janela de hospedagem.|
|estático [CMFCDynamicLayout::MoveNone](#movenone)|Obtém uma [MoveSettings](#movesettings_structure) valor que não representa nenhum movimento vertical ou horizontal, para um controle filho.|
|estático [CMFCDynamicLayout::MoveVertical](#movevertical)|Obtém uma [MoveSettings](#movesettings_structure) valor que define o quanto um controle filho é movido verticalmente quando o usuário redimensiona a janela de hospedagem.|
|[CMFCDynamicLayout::SetMinSize](#setminsize)|Define o tamanho da janela abaixo do qual o layout não é ajustado.|
|estático [CMFCDynamicLayout::SizeHorizontal](#sizehorizontal)|Obtém uma [SizeSettings](#sizesettings_structure) valor que define o quanto um controle filho é redimensionado horizontalmente quando o usuário o redimensiona sua janela de hospedagem.|
|estático [CMFCDynamicLayout::SizeHorizontalAndVertical](#sizehorizontalandvertical)|Obtém uma [SizeSettings](#sizesettings_structure) valor que define o quanto um controle filho é redimensionado horizontalmente quando o usuário o redimensiona sua janela de hospedagem.|
|estático [CMFCDynamicLayout::SizeNone](#sizenone)|Obtém uma [SizeSettings](#sizesettings_structure) valor que não representa nenhuma alteração no tamanho de um controle filho.|
|estático [CMFCDynamicLayout::SizeVertical](#sizevertical)|Obtém uma [SizeSettings](#sizesettings_structure) valor que define o quanto um controle filho é redimensionado verticalmente quando o usuário o redimensiona sua janela de hospedagem.|

## <a name="nested-types"></a>Tipos aninhados

|Nome|Descrição|
|----------|-----------------|
|[Estrutura cmfcdynamiclayout:: Movesettings](#movesettings_structure)|Encapsula a mover dados para controles em um layout dinâmico.|
|[Estrutura CMFCDynamicLayout::SizeSettings](#sizesettings_structure)|Encapsula os dados de alteração de tamanho para controles em um layout dinâmico.|

## <a name="remarks"></a>Comentários

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[CObject](../../mfc/reference/cobject-class.md)

[CMFCDynamicLayout](../../mfc/reference/cmfctoolbarbutton-class.md)

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxlayout.h

##  <a name="additem"></a>  CMFCDynamicLayout::AddItem

Adiciona uma janela filho, geralmente, um controle, a lista de janelas que são controlados pelo Gerenciador de layout dinâmico.

```
BOOL AddItem(
    HWND hwnd,
    MoveSettings moveSettings SizeSettings sizeSettings);

BOOL AddItem(
    int nID,
    MoveSettings moveSettings SizeSettings sizeSettings);
```

### <a name="parameters"></a>Parâmetros

*hwnd*<br/>
O identificador para a janela para adicionar.

*nID*<br/>
A ID do controle filho para adicionar.

*moveSettings*<br/>
Uma estrutura que descreve como o controle deve ser movido como as alterações de tamanho de janela.

*sizeSettings*<br/>
Uma estrutura que descreve como o controle deve ser redimensionado como as alterações de tamanho de janela.

### <a name="return-value"></a>Valor de retorno

TRUE se o item foi adicionado com êxito; Caso contrário, FALSE.

### <a name="remarks"></a>Comentários

A posição e tamanho de um controle filho é alterada dinamicamente quando uma janela de hospedagem está sendo redimensionada.

##  <a name="adjust"></a>  CMFCDynamicLayout::Adjust

Adiciona uma janela filho, geralmente, um controle, a lista de janelas que são controlados pelo Gerenciador de layout dinâmico.

```
void Adjust();
```

### <a name="remarks"></a>Comentários

A posição e tamanho de um controle filho é alterada dinamicamente quando uma janela de hospedagem está sendo redimensionada.

##  <a name="create"></a>  CMFCDynamicLayout::Create

Armazena e valida a janela do host.

```
BOOL Create(CWnd* pHostWnd);
```

### <a name="parameters"></a>Parâmetros

*pHostWnd*<br/>
Um ponteiro para a janela do host.

### <a name="return-value"></a>Valor de retorno

TRUE se a criação for bem-sucedida; Caso contrário, FALSE.

### <a name="remarks"></a>Comentários

##  <a name="gethostwnd"></a>  CMFCDynamicLayout::GetHostWnd

Retorna um ponteiro para uma janela de host.

```
CWnd* GetHostWnd();
```

### <a name="return-value"></a>Valor de retorno

Um ponteiro para a janela do host.

### <a name="remarks"></a>Comentários

Por padrão todas as posições de controle filho é recalculado em relação a esta janela.

##  <a name="getminsize"></a>  CMFCDynamicLayout::GetMinSize

Retorna o tamanho da janela abaixo do qual o layout não é ajustado.

```
CSize GetMinSize();
```

### <a name="return-value"></a>Valor de retorno

O tamanho da janela abaixo do qual o layout não é ajustado.

### <a name="remarks"></a>Comentários

A posição e tamanho de um controle filho é alterada dinamicamente quando uma janela de hospedagem está sendo redimensionada, mas há um tamanho mínimo abaixo do qual o layout não é ajustado. O usuário pode redimensionar a janela para um tamanho menor, mas partes da janela, em seguida, ficam ocultas da exibição.

##  <a name="getwindowrect"></a>  CMFCDynamicLayout::GetWindowRect

Recupera o retângulo para a área de cliente da janela atual.

```
void GetHostWndRect(CRect& rect,);
```

### <a name="parameters"></a>Parâmetros

*rect*<br/>
Depois que a função retornar, este parâmetro conterá o retângulo delimitador da área de layout. Isso é um parâmetro de saída; o valor de entrada será substituído.

### <a name="remarks"></a>Comentários

##  <a name="hasitem"></a>  CMFCDynamicLayout::HasItem

Verifica se um controle filho foi adicionado ao layout dinâmico.

```
BOOL HasItem(HWND hwnd);
```

### <a name="parameters"></a>Parâmetros

*hwnd*<br/>
O identificador de janela para o controle.

### <a name="return-value"></a>Valor de retorno

TRUE se o layout já tem este item; Caso contrário, FALSE.

### <a name="remarks"></a>Comentários

##  <a name="isempty"></a>  CMFCDynamicLayout::IsEmpty

Verifica se um layout dinâmico não tem nenhuma janela filho adicionada.

```
BOOL IsEmpty();
```

### <a name="return-value"></a>Valor de retorno

TRUE se o layout não tiver nenhum item; Caso contrário, FALSE.

### <a name="remarks"></a>Comentários

##  <a name="loadresource"></a>  CMFCDynamicLayout::LoadResource

Lê o layout dinâmico do recurso AFX_DIALOG_LAYOUT e, em seguida, aplica o layout para a janela do host.

```
static BOOL LoadResource(CWnd* pHostWnd,
    LPVOID lpResource,
    DWORD dwSize);
```

### <a name="parameters"></a>Parâmetros

*pHostWnd*<br/>
Um ponteiro para a janela do host.

*lpResource*<br/>
Um ponteiro para o buffer que contém o recurso AFX_DIALOG_LAYOUT.

*dwSize*<br/>
O tamanho do buffer em bytes.

### <a name="return-value"></a>Valor de retorno

TRUE se o recurso é carregado e aplicado à janela do host; Caso contrário, FALSE.

### <a name="remarks"></a>Comentários

##  <a name="movehorizontal"></a>  CMFCDynamicLayout::MoveHorizontal

Obtém uma [MoveSettings](#movesettings_structure) valor que define o quanto um controle filho é movido horizontalmente quando o usuário redimensiona a janela de hospedagem.

```
static MoveSettings MoveHorizontal(int nRatio);
```

### <a name="parameters"></a>Parâmetros

*nRatio*<br/>
Define como uma porcentagem quanto um controle filho é movido horizontalmente quando o usuário redimensiona a janela do host.

### <a name="return-value"></a>Valor de retorno

Um [MoveSettings](#movesettings_structure) valor que encapsula a solicitação Mover taxa.

### <a name="remarks"></a>Comentários

##  <a name="movehorizontalandvertical"></a>  CMFCDynamicLayout::MoveHorizontalAndVertical

Obtém uma [MoveSettings](#movesettings_structure) valor que define o quanto um controle filho é movido horizontalmente quando o usuário redimensiona a janela de hospedagem.

```
static MoveSettings MoveHorizontalAndVertical(int nXRatio int nYRatio);
```

### <a name="parameters"></a>Parâmetros

*nXRatio*<br/>
Define como uma porcentagem quanto um controle filho é movido horizontalmente quando o usuário redimensiona a janela do host.

*nYRatio*<br/>
Define como uma porcentagem quanto um controle filho é movido verticalmente quando o usuário redimensiona a janela do host.

### <a name="return-value"></a>Valor de retorno

Um [MoveSettings](#movesettings_structure) valor que encapsula a solicitação Mover taxa.

### <a name="remarks"></a>Comentários

##  <a name="movenone"></a>  CMFCDynamicLayout::MoveNone

Obtém uma [MoveSettings](#movesettings_structure) valor que não representa nenhum movimento vertical ou horizontal, para um controle filho.

```
static MoveSettings MoveNone();
```

### <a name="return-value"></a>Valor de retorno

Um [MoveSettings](#movesettings_structure) valor que corrige o controle no local, para que ele não se move conforme o usuário redimensiona a janela do host.

### <a name="remarks"></a>Comentários

##  <a name="movesettings_structure"></a>  Estrutura cmfcdynamiclayout:: Movesettings

Encapsula a mover dados para controles em um layout dinâmico.

```
struct CMFCDynamicLayout::MoveSettings;
```

### <a name="remarks"></a>Comentários

Essa é uma classe aninhada dentro de `CMFCDynamicLayout`.

## <a name="cmfcdynamiclayoutmovesettingsishorizontal"></a>CMFCDynamicLayout::MoveSettings::IsHorizontal

Verifique se os dados de mudança especificam um movimento horizontal diferente de zero.

```
BOOL IsHorizontal() const
```

## <a name="return-value"></a>Valor de retorno

TRUE se o `MoveSettings` objeto Especifica um movimento horizontal diferente de zero.

## <a name="cmfcdynamiclayoutmovesettingsisnone"></a>CMFCDynamicLayout::MoveSettings::IsNone

Verifique se os dados de mudança não especificam nenhuma movimentação.

```
BOOL IsNone() const
```

## <a name="return-value"></a>Valor de retorno

TRUE se o `MoveSettings` nenhuma movimentação do objeto especifica.

## <a name="cmfcdynamiclayoutmovesettingsisvertical"></a>CMFCDynamicLayout::MoveSettings::IsVertical

  Verifique se os dados de mudança especificam um movimento vertical diferente de zero.

```
BOOL IsVertical() const
```

## <a name="return-value"></a>Valor de retorno

TRUE se o `MoveSettings` objeto Especifica um movimento vertical diferente de zero.

##  <a name="movevertical"></a>  CMFCDynamicLayout::MoveVertical

Obtém uma [MoveSettings](#movesettings_structure) valor que define o quanto um controle filho é movido verticalmente quando o usuário redimensiona a janela de hospedagem.

```
static MoveSettings MoveVertical(int nRatio);
```

### <a name="parameters"></a>Parâmetros

*nRatio*<br/>
Define como uma porcentagem quanto um controle filho é movido verticalmente quando o usuário redimensiona a janela do host.

### <a name="return-value"></a>Valor de retorno

Um [MoveSettings](#movesettings_structure) valor que encapsula a solicitação Mover taxa.

### <a name="remarks"></a>Comentários

##  <a name="setminsize"></a>  CMFCDynamicLayout::SetMinSize

Define o tamanho da janela abaixo do qual o layout não é ajustado.

```
void SetMinSize(const CSize& size);
```

### <a name="parameters"></a>Parâmetros

*size*<br/>
O tamanho desejado abaixo do qual o layout não é ajustado.

### <a name="remarks"></a>Comentários

A posição e tamanho de um controle filho é alterada dinamicamente quando uma janela de hospedagem está sendo redimensionada, mas há um tamanho mínimo abaixo do qual o layout não é ajustado. O usuário pode redimensionar a janela para um tamanho menor, mas partes da janela, em seguida, ficam ocultas da exibição.

##  <a name="sizehorizontal"></a>  CMFCDynamicLayout::SizeHorizontal

Obtém uma [SizeSettings](#sizesettings_structure) valor que define o quanto um controle filho é redimensionado horizontalmente quando o usuário o redimensiona sua janela de hospedagem.

```
static SizeSettings SizeHorizontal(int nRatio);
```

### <a name="parameters"></a>Parâmetros

*nRatio*<br/>
Define como uma porcentagem quanto um controle filho é redimensionado horizontalmente quando o usuário redimensiona a janela do host.

### <a name="return-value"></a>Valor de retorno

Um [SizeSettings](#sizesettings_structure) valor que encapsula a proporção de tamanho solicitado.

### <a name="remarks"></a>Comentários

##  <a name="sizehorizontalandvertical"></a>  CMFCDynamicLayout::SizeHorizontalAndVertical

Obtém uma [SizeSettings](#sizesettings_structure) valor que define o quanto um controle filho é redimensionado horizontalmente quando o usuário o redimensiona sua janela de hospedagem.

```
static SizeSettings SizeHorizontalAndVertical(int nXRatio int nYRatio);
```

### <a name="parameters"></a>Parâmetros

*nXRatio*<br/>
Define como uma porcentagem quanto um controle filho é redimensionado horizontalmente quando o usuário redimensiona a janela do host.

*nYRatio*<br/>
Define como uma porcentagem quanto um controle filho é redimensionado verticalmente quando o usuário redimensiona a janela do host.

### <a name="return-value"></a>Valor de retorno

Um [SizeSettings](#sizesettings_structure) valor que encapsula a proporção de tamanho solicitado.

### <a name="remarks"></a>Comentários

##  <a name="sizenone"></a>  CMFCDynamicLayout::SizeNone

Obtém uma [SizeSettings](#sizesettings_structure) valor que não representa nenhuma alteração no tamanho de um controle filho.

```
static SizeSettings SizeNone();
```

### <a name="return-value"></a>Valor de retorno

Um [SizeSettings](#sizesettings_structure) valor que corrige o controle em um determinado tamanho, para que ele não alterar o tamanho, como o usuário redimensiona a janela do host.

### <a name="remarks"></a>Comentários

##  <a name="sizesettings_structure"></a>  Estrutura CMFCDynamicLayout::SizeSettings

Encapsula os dados de alteração de tamanho para controles em um layout dinâmico.

```
struct CMFCDynamicLayout::SizeSettings;
```

### <a name="remarks"></a>Comentários

Essa é uma classe aninhada dentro de `CMFCDynamicLayout`.

## <a name="cmfcdynamiclayoutsizesettingsishorizontal"></a>CMFCDynamicLayout::SizeSettings::IsHorizontal

Verifica se os dados de redimensionamento especificam um redimensionamento horizontal diferente de zero.

```
BOOL IsHorizontal() const
```

## <a name="return-value"></a>Valor de retorno

TRUE se o `SizeSettings` objeto Especifica um redimensionamento horizontal diferente de zero.

## <a name="cmfcdynamiclayoutsizesettingsisnone"></a>CMFCDynamicLayout::SizeSettings::IsNone

Verifica se os dados de redimensionamento não especificam nenhum redimensionamento.

```
BOOL IsNone() const
```

## <a name="return-value"></a>Valor de retorno

TRUE se o `SizeSettings` objeto não especifica nenhum redimensionamento.

## <a name="cmfcdynamiclayoutsizesettingsisvertical"></a>CMFCDynamicLayout::SizeSettings::IsVertical

Verifica se os dados de redimensionamento especificam um redimensionamento vertical diferente de zero.

```
BOOL IsVertical() const
```

## <a name="return-value"></a>Valor de retorno

TRUE se o `SizeSettings` objeto Especifica um redimensionamento vertical diferente de zero.

##  <a name="sizevertical"></a>  CMFCDynamicLayout::SizeVertical

Obtém uma [SizeSettings](#sizesettings_structure) valor que define o quanto um controle filho é redimensionado verticalmente quando o usuário o redimensiona sua janela de hospedagem.

```
static SizeSettings SizeVertical(int nRatio);
```

### <a name="parameters"></a>Parâmetros

*nRatio*<br/>
Define como uma porcentagem quanto um controle filho é redimensionado verticalmente quando o usuário redimensiona a janela do host.

### <a name="return-value"></a>Valor de retorno

Um [SizeSettings](#sizesettings_structure) valor que encapsula a proporção de tamanho solicitado.

### <a name="remarks"></a>Comentários

## <a name="see-also"></a>Consulte também

[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classes](../../mfc/reference/mfc-classes.md)
