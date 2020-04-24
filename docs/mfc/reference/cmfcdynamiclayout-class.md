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
ms.openlocfilehash: 77dd3a84a0c76b92495bb062eeb83ff013933087
ms.sourcegitcommit: 7a6116e48c3c11b97371b8ae4ecc23adce1f092d
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/22/2020
ms.locfileid: "81752390"
---
# <a name="cmfcdynamiclayout-class"></a>Classe CMFCDynamicLayout

Especifica como os controles em uma janela são movidos e redimensionados à medida que o usuário redimensiona a janela.

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
|[CMFCDynamicLayout::AddItem](#additem)|Adiciona uma janela filho, tipicamente um controle, à lista de janelas que são controladas pelo gerenciador de layout dinâmico.|
|[CMFCDynamicLayout::Adjust](#adjust)|Adiciona uma janela filho, tipicamente um controle, à lista de janelas que são controladas pelo gerenciador de layout dinâmico.|
|[CMFCDynamicLayout::Create](#create)|Armazena e valida a janela de hospedagem.|
|[CMFCDynamicLayout::GetHostWnd](#gethostwnd)|Retorna um ponteiro para uma janela de host.|
|[CMFCDynamicLayout::GetMinSize](#getminsize)|Retorna o tamanho da janela abaixo do qual o layout não é ajustado.|
|[CMFCDynamicLayout::GetWindowRect](#getwindowrect)|Recupera o retângulo para a área de cliente atual da janela.|
|[CMFCDynamicLayout::HasItem](#hasitem)|Verifica se um controle infantil foi adicionado ao layout dinâmico.|
|[CMFCDynamicLayout::IsEmpty](#isempty)|Verifica se um layout dinâmico não tem janelas de criança adicionadas.|
|[CMFCDynamicLayout::LoadResource](#loadresource)|Lê o layout dinâmico do recurso AFX_DIALOG_LAYOUT e, em seguida, aplica o layout na janela do host.|
|[CMFCDynamicLayout estático::MoveHorizontal](#movehorizontal)|Obtém um valor [MoveSettings](#movesettings_structure) que define o quanto um controle de criança é movido horizontalmente quando o usuário redimensiona sua janela de hospedagem.|
|[CMFCDinâmico estáticoLayout::MoveHorizontalAndVertical](#movehorizontalandvertical)|Obtém um valor [MoveSettings](#movesettings_structure) que define o quanto um controle de criança é movido horizontalmente quando o usuário redimensiona sua janela de hospedagem.|
|[CMFCDynamicLayout estático::MoveNone](#movenone)|Obtém um valor [MoveSettings](#movesettings_structure) que não representa movimento, vertical ou horizontal, para um controle de crianças.|
|[CMFCDynamicLayout estático::MoveVertical](#movevertical)|Obtém um valor [MoveSettings](#movesettings_structure) que define o quanto um controle de filho é movido verticalmente quando o usuário redimensiona sua janela de hospedagem.|
|[CMFCDynamicLayout::SetMinSize](#setminsize)|Define o tamanho da janela abaixo do qual o layout não é ajustado.|
|[CMFCDynamicLayout estático::TamanhoHorizontal](#sizehorizontal)|Obtém um valor [TamanhoSettings](#sizesettings_structure) que define o quanto um controle de criança é redimensionado horizontalmente quando o usuário redimensiona sua janela de hospedagem.|
|[CMFCDinâmico estáticoLayout::TamanhoHorizontalandVertical](#sizehorizontalandvertical)|Obtém um valor [TamanhoSettings](#sizesettings_structure) que define o quanto um controle de criança é redimensionado horizontalmente quando o usuário redimensiona sua janela de hospedagem.|
|[CMFCDynamicLayout estático::SizeNone](#sizenone)|Obtém um valor [TamanhoSettings](#sizesettings_structure) que não representa nenhuma mudança de tamanho para um controle de criança.|
|[CMFCDinâmico estáticoLayout::TamanhoVertical](#sizevertical)|Obtém um valor [De Configurações de tamanho](#sizesettings_structure) que define o quanto um controle de criança é redimensionado verticalmente quando o usuário redimensiona sua janela de hospedagem.|

## <a name="nested-types"></a>Tipos aninhados

|Nome|Descrição|
|----------|-----------------|
|[Estrutura CMFCDynamicLayout::MoveSettings](#movesettings_structure)|Encapsula dados de movimentação para controles em um layout dinâmico.|
|[CMFCDynamicLayout::SizeSettings Structure](#sizesettings_structure)|Encapsula dados de mudança de tamanho para controles em um layout dinâmico.|

## <a name="remarks"></a>Comentários

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[Cobject](../../mfc/reference/cobject-class.md)

[CMFCDynamicLayout](../../mfc/reference/cmfctoolbarbutton-class.md)

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxlayout.h

## <a name="cmfcdynamiclayoutadditem"></a><a name="additem"></a>CMFCDynamicLayout::AddItem

Adiciona uma janela filho, tipicamente um controle, à lista de janelas que são controladas pelo gerenciador de layout dinâmico.

```
BOOL AddItem(
    HWND hwnd,
    MoveSettings moveSettings SizeSettings sizeSettings);

BOOL AddItem(
    int nID,
    MoveSettings moveSettings SizeSettings sizeSettings);
```

### <a name="parameters"></a>Parâmetros

*Hwnd*<br/>
A alça da janela para adicionar.

*nID*<br/>
A iD do controle infantil para adicionar.

*configurações de movimento*<br/>
Uma estrutura que descreve como o controle deve ser movido à medida que o tamanho da janela muda.

*tamanhoConfigurações*<br/>
Uma estrutura que descreve como o controle deve ser redimensionado à medida que o tamanho da janela muda.

### <a name="return-value"></a>Valor retornado

TRUE se o item foi adicionado com sucesso; caso contrário, FALSO.

### <a name="remarks"></a>Comentários

A posição e o tamanho de um controle de crianças são alterados dinamicamente quando uma janela de hospedagem está sendo redimensionada.

## <a name="cmfcdynamiclayoutadjust"></a><a name="adjust"></a>CMFCDynamicLayout::Ajustar

Adiciona uma janela filho, tipicamente um controle, à lista de janelas que são controladas pelo gerenciador de layout dinâmico.

```cpp
void Adjust();
```

### <a name="remarks"></a>Comentários

A posição e o tamanho de um controle de crianças são alterados dinamicamente quando uma janela de hospedagem está sendo redimensionada.

## <a name="cmfcdynamiclayoutcreate"></a><a name="create"></a>CMFCDynamicLayout::Criar

Armazena e valida a janela de hospedagem.

```
BOOL Create(CWnd* pHostWnd);
```

### <a name="parameters"></a>Parâmetros

*pHostWnd*<br/>
Um ponteiro para a janela do host.

### <a name="return-value"></a>Valor retornado

VERDADE se a criação conseguiu; caso contrário, FALSO.

### <a name="remarks"></a>Comentários

## <a name="cmfcdynamiclayoutgethostwnd"></a><a name="gethostwnd"></a>CMFCDynamicLayout::GetHostWnd

Retorna um ponteiro para uma janela de host.

```
CWnd* GetHostWnd();
```

### <a name="return-value"></a>Valor retornado

Um ponteiro para a janela do host.

### <a name="remarks"></a>Comentários

Por padrão, todas as posições de controle de crianças recalculadas em relação a esta janela.

## <a name="cmfcdynamiclayoutgetminsize"></a><a name="getminsize"></a>CMFCDynamicLayout::GetMinSize

Retorna o tamanho da janela abaixo do qual o layout não é ajustado.

```
CSize GetMinSize();
```

### <a name="return-value"></a>Valor retornado

O tamanho da janela abaixo do qual o layout não é ajustado.

### <a name="remarks"></a>Comentários

A posição e o tamanho de um controle de crianças são alterados dinamicamente quando uma janela de hospedagem está sendo redimensionada, mas há um tamanho mínimo abaixo do qual o layout não é ajustado. O usuário pode redimensionar a janela para um tamanho menor, mas partes da janela são então ocultas da vista.

## <a name="cmfcdynamiclayoutgetwindowrect"></a><a name="getwindowrect"></a>CMFCDynamicLayout::GetWindowRect

Recupera o retângulo para a área de cliente atual da janela.

```cpp
void GetHostWndRect(CRect& rect,);
```

### <a name="parameters"></a>Parâmetros

*Rect*<br/>
Após o retorno da função, este parâmetro contém o retângulo delimitador da área de layout. Este é um parâmetro para fora; o valor de entrada é substituído.

### <a name="remarks"></a>Comentários

## <a name="cmfcdynamiclayouthasitem"></a><a name="hasitem"></a>CMFCDynamicLayout::HasItem

Verifica se um controle infantil foi adicionado ao layout dinâmico.

```
BOOL HasItem(HWND hwnd);
```

### <a name="parameters"></a>Parâmetros

*Hwnd*<br/>
A alça da janela para o controle.

### <a name="return-value"></a>Valor retornado

TRUE se o layout já tiver esse item; caso contrário, FALSO.

### <a name="remarks"></a>Comentários

## <a name="cmfcdynamiclayoutisempty"></a><a name="isempty"></a>CMFCDynamiclayout::IsEmpty

Verifica se um layout dinâmico não tem janelas de criança adicionadas.

```
BOOL IsEmpty();
```

### <a name="return-value"></a>Valor retornado

TRUE se o layout não tiver itens; caso contrário, FALSO.

### <a name="remarks"></a>Comentários

## <a name="cmfcdynamiclayoutloadresource"></a><a name="loadresource"></a>CMFCDynamicLayout::Recurso de carga

Lê o layout dinâmico do recurso AFX_DIALOG_LAYOUT e, em seguida, aplica o layout na janela do host.

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

*Dwsize*<br/>
O tamanho do buffer em bytes.

### <a name="return-value"></a>Valor retornado

TRUE se o recurso for carregado e aplicado na janela do host; caso contrário, FALSO.

### <a name="remarks"></a>Comentários

## <a name="cmfcdynamiclayoutmovehorizontal"></a><a name="movehorizontal"></a>CMFCDynamicLayout::MoveHorizontal

Obtém um valor [MoveSettings](#movesettings_structure) que define o quanto um controle de criança é movido horizontalmente quando o usuário redimensiona sua janela de hospedagem.

```
static MoveSettings MoveHorizontal(int nRatio);
```

### <a name="parameters"></a>Parâmetros

*nRatio*<br/>
Define como uma porcentagem o quão longe um controle de criança é movido horizontalmente quando o usuário redimensiona a janela do host.

### <a name="return-value"></a>Valor retornado

Um valor [MoveSettings](#movesettings_structure) que encapsula a relação de movimento solicitada.

### <a name="remarks"></a>Comentários

## <a name="cmfcdynamiclayoutmovehorizontalandvertical"></a><a name="movehorizontalandvertical"></a>CMFCDynamiclayout::Moverhorizontalevertical

Obtém um valor [MoveSettings](#movesettings_structure) que define o quanto um controle de criança é movido horizontalmente quando o usuário redimensiona sua janela de hospedagem.

```
static MoveSettings MoveHorizontalAndVertical(int nXRatio int nYRatio);
```

### <a name="parameters"></a>Parâmetros

*nXRatio*<br/>
Define como uma porcentagem o quão longe um controle de criança é movido horizontalmente quando o usuário redimensiona a janela do host.

*nYRatio*<br/>
Define como uma porcentagem o quão longe um controle de criança é movido verticalmente quando o usuário redimensiona a janela do host.

### <a name="return-value"></a>Valor retornado

Um valor [MoveSettings](#movesettings_structure) que encapsula a relação de movimento solicitada.

### <a name="remarks"></a>Comentários

## <a name="cmfcdynamiclayoutmovenone"></a><a name="movenone"></a>CMFCDynamicLayout::MoveNone

Obtém um valor [MoveSettings](#movesettings_structure) que não representa movimento, vertical ou horizontal, para um controle de crianças.

```
static MoveSettings MoveNone();
```

### <a name="return-value"></a>Valor retornado

Um [valor MoveSettings](#movesettings_structure) que corrige o controle no lugar, para que ele não se mova à medida que o usuário redimensiona a janela do host.

### <a name="remarks"></a>Comentários

## <a name="cmfcdynamiclayoutmovesettings-structure"></a><a name="movesettings_structure"></a>CMFCDynamicLayout::Estrutura de configurações de movimento

Encapsula dados de movimentação para controles em um layout dinâmico.

```
struct CMFCDynamicLayout::MoveSettings;
```

### <a name="remarks"></a>Comentários

Esta é uma classe `CMFCDynamicLayout`aninhada por dentro.

## <a name="cmfcdynamiclayoutmovesettingsishorizontal"></a>CMFCDynamicLayout::Configurações de movimento::IsHorizontal

Verifique se os dados de movimento especificam um movimento horizontal não zero.

```
BOOL IsHorizontal() const
```

## <a name="return-value"></a>Valor retornado

TRUE se `MoveSettings` o objeto especificar um movimento horizontal não zero.

## <a name="cmfcdynamiclayoutmovesettingsisnone"></a>CMFCDynamicLayout::Configurações de movimento::IsNone

Verifique se os dados de movimento não especificam nenhum movimento.

```
BOOL IsNone() const
```

## <a name="return-value"></a>Valor retornado

TRUE se `MoveSettings` o objeto especificar nenhum movimento.

## <a name="cmfcdynamiclayoutmovesettingsisvertical"></a>CMFCDynamicLayout::Configurações de movimento::IsVertical

Verifique se os dados de movimento especificam um movimento vertical não zero.

```
BOOL IsVertical() const
```

## <a name="return-value"></a>Valor retornado

TRUE se `MoveSettings` o objeto especificar um movimento vertical não zero.

## <a name="cmfcdynamiclayoutmovevertical"></a><a name="movevertical"></a>CMFCDynamiclayout::MoveVertical

Obtém um valor [MoveSettings](#movesettings_structure) que define o quanto um controle de filho é movido verticalmente quando o usuário redimensiona sua janela de hospedagem.

```
static MoveSettings MoveVertical(int nRatio);
```

### <a name="parameters"></a>Parâmetros

*nRatio*<br/>
Define como uma porcentagem o quão longe um controle de criança é movido verticalmente quando o usuário redimensiona a janela do host.

### <a name="return-value"></a>Valor retornado

Um valor [MoveSettings](#movesettings_structure) que encapsula a relação de movimento solicitada.

### <a name="remarks"></a>Comentários

## <a name="cmfcdynamiclayoutsetminsize"></a><a name="setminsize"></a>CMFCDynamicLayout::SetMinSize

Define o tamanho da janela abaixo do qual o layout não é ajustado.

```cpp
void SetMinSize(const CSize& size);
```

### <a name="parameters"></a>Parâmetros

*size*<br/>
O tamanho desejado abaixo do qual o layout não é ajustado.

### <a name="remarks"></a>Comentários

A posição e o tamanho de um controle de crianças são alterados dinamicamente quando uma janela de hospedagem está sendo redimensionada, mas há um tamanho mínimo abaixo do qual o layout não é ajustado. O usuário pode redimensionar a janela para um tamanho menor, mas partes da janela são então ocultas da vista.

## <a name="cmfcdynamiclayoutsizehorizontal"></a><a name="sizehorizontal"></a>CMFCDynamicLayout::SizeHorizontal

Obtém um valor [TamanhoSettings](#sizesettings_structure) que define o quanto um controle de criança é redimensionado horizontalmente quando o usuário redimensiona sua janela de hospedagem.

```
static SizeSettings SizeHorizontal(int nRatio);
```

### <a name="parameters"></a>Parâmetros

*nRatio*<br/>
Define como uma porcentagem o quão longe um controle de criança é redimensionado horizontalmente quando o usuário redimensiona a janela do host.

### <a name="return-value"></a>Valor retornado

Um [valor TamanhoS](#sizesettings_structure) que encapsula a relação de tamanho solicitada.

### <a name="remarks"></a>Comentários

## <a name="cmfcdynamiclayoutsizehorizontalandvertical"></a><a name="sizehorizontalandvertical"></a>CMFCDynamiclayout::tamanhohorizontalevertical

Obtém um valor [TamanhoSettings](#sizesettings_structure) que define o quanto um controle de criança é redimensionado horizontalmente quando o usuário redimensiona sua janela de hospedagem.

```
static SizeSettings SizeHorizontalAndVertical(int nXRatio int nYRatio);
```

### <a name="parameters"></a>Parâmetros

*nXRatio*<br/>
Define como uma porcentagem o quão longe um controle de criança é redimensionado horizontalmente quando o usuário redimensiona a janela do host.

*nYRatio*<br/>
Define como uma porcentagem o quão longe um controle de criança é redimensionado verticalmente quando o usuário redimensiona a janela do host.

### <a name="return-value"></a>Valor retornado

Um [valor TamanhoS](#sizesettings_structure) que encapsula a relação de tamanho solicitada.

### <a name="remarks"></a>Comentários

## <a name="cmfcdynamiclayoutsizenone"></a><a name="sizenone"></a>CMFCDynamicLayout::SizeNone

Obtém um valor [TamanhoSettings](#sizesettings_structure) que não representa nenhuma mudança de tamanho para um controle de criança.

```
static SizeSettings SizeNone();
```

### <a name="return-value"></a>Valor retornado

Um [valor Tamanhos](#sizesettings_structure) que corrige o controle em um determinado tamanho, para que ele não mude de tamanho à medida que o usuário redimensiona a janela do host.

### <a name="remarks"></a>Comentários

## <a name="cmfcdynamiclayoutsizesettings-structure"></a><a name="sizesettings_structure"></a>CMFCDynamicLayout::Estrutura de configurações de tamanho

Encapsula dados de mudança de tamanho para controles em um layout dinâmico.

```
struct CMFCDynamicLayout::SizeSettings;
```

### <a name="remarks"></a>Comentários

Esta é uma classe `CMFCDynamicLayout`aninhada por dentro.

## <a name="cmfcdynamiclayoutsizesettingsishorizontal"></a>CMFCDynamicLayout::TamanhoConfigurações::IsHorizontal

Verifica se os dados de redimensionamento especificam um redimensionamento horizontal não zero.

```
BOOL IsHorizontal() const
```

## <a name="return-value"></a>Valor retornado

TRUE se `SizeSettings` o objeto especificar um redimensionamento horizontal não zero.

## <a name="cmfcdynamiclayoutsizesettingsisnone"></a>CMFCDynamicLayout::TamanhoConfigurações::IsNone

Verifica se os dados de redimensionamento não especificam redimensionamento.

```
BOOL IsNone() const
```

## <a name="return-value"></a>Valor retornado

TRUE se `SizeSettings` o objeto especificar nenhum redimensionamento.

## <a name="cmfcdynamiclayoutsizesettingsisvertical"></a>CMFCDynamicLayout::TamanhoConfigurações::IsVertical

Verifica se os dados de redimensionamento especificam um redimensionamento vertical não zero.

```
BOOL IsVertical() const
```

## <a name="return-value"></a>Valor retornado

TRUE se `SizeSettings` o objeto especificar um redimensionamento vertical não zero.

## <a name="cmfcdynamiclayoutsizevertical"></a><a name="sizevertical"></a>CMFCDynamicLayout::SizeVertical

Obtém um valor [De Configurações de tamanho](#sizesettings_structure) que define o quanto um controle de criança é redimensionado verticalmente quando o usuário redimensiona sua janela de hospedagem.

```
static SizeSettings SizeVertical(int nRatio);
```

### <a name="parameters"></a>Parâmetros

*nRatio*<br/>
Define como uma porcentagem o quão longe um controle de criança é redimensionado verticalmente quando o usuário redimensiona a janela do host.

### <a name="return-value"></a>Valor retornado

Um [valor TamanhoS](#sizesettings_structure) que encapsula a relação de tamanho solicitada.

### <a name="remarks"></a>Comentários

## <a name="see-also"></a>Confira também

[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classes](../../mfc/reference/mfc-classes.md)
