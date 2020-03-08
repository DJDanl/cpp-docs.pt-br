---
title: Classe CComboBoxEx
ms.date: 11/04/2016
f1_keywords:
- CComboBoxEx
- AFXCMN/CComboBoxEx
- AFXCMN/CComboBoxEx::CComboBoxEx
- AFXCMN/CComboBoxEx::Create
- AFXCMN/CComboBoxEx::CreateEx
- AFXCMN/CComboBoxEx::DeleteItem
- AFXCMN/CComboBoxEx::GetComboBoxCtrl
- AFXCMN/CComboBoxEx::GetEditCtrl
- AFXCMN/CComboBoxEx::GetExtendedStyle
- AFXCMN/CComboBoxEx::GetImageList
- AFXCMN/CComboBoxEx::GetItem
- AFXCMN/CComboBoxEx::HasEditChanged
- AFXCMN/CComboBoxEx::InsertItem
- AFXCMN/CComboBoxEx::SetExtendedStyle
- AFXCMN/CComboBoxEx::SetImageList
- AFXCMN/CComboBoxEx::SetItem
- AFXCMN/CComboBoxEx::SetWindowTheme
helpviewer_keywords:
- CComboBoxEx [MFC], CComboBoxEx
- CComboBoxEx [MFC], Create
- CComboBoxEx [MFC], CreateEx
- CComboBoxEx [MFC], DeleteItem
- CComboBoxEx [MFC], GetComboBoxCtrl
- CComboBoxEx [MFC], GetEditCtrl
- CComboBoxEx [MFC], GetExtendedStyle
- CComboBoxEx [MFC], GetImageList
- CComboBoxEx [MFC], GetItem
- CComboBoxEx [MFC], HasEditChanged
- CComboBoxEx [MFC], InsertItem
- CComboBoxEx [MFC], SetExtendedStyle
- CComboBoxEx [MFC], SetImageList
- CComboBoxEx [MFC], SetItem
- CComboBoxEx [MFC], SetWindowTheme
ms.assetid: 33ca960a-2409-478c-84a4-a2ee8ecfe8f7
ms.openlocfilehash: 7d46f175a62cda7f1ff08327830f1dffe2967727
ms.sourcegitcommit: 3e8fa01f323bc5043a48a0c18b855d38af3648d4
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/06/2020
ms.locfileid: "78865542"
---
# <a name="ccomboboxex-class"></a>Classe CComboBoxEx

Estende o controle de caixa de combinação fornecendo suporte para listas de imagens.

## <a name="syntax"></a>Sintaxe

```
class CComboBoxEx : public CComboBox
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|{1&gt;Nome&lt;1}|Descrição|
|----------|-----------------|
|[CComboBoxEx::CComboBoxEx](#ccomboboxex)|Constrói um objeto `CComboBoxEx`.|

### <a name="public-methods"></a>Métodos públicos

|{1&gt;Nome&lt;1}|Descrição|
|----------|-----------------|
|[CComboBoxEx:: criar](#create)|Cria a caixa de combinação e a anexa ao objeto `CComboBoxEx`.|
|[CComboBoxEx::CreateEx](#createex)|Cria uma caixa de combinação com os estilos estendidos do Windows especificados e anexa-o a um objeto `ComboBoxEx`.|
|[CComboBoxEx::D eleteItem](#deleteitem)|Remove um item de um controle `ComboBoxEx`.|
|[CComboBoxEx::GetComboBoxCtrl](#getcomboboxctrl)|Recupera um ponteiro para o controle da caixa de combinação filho.|
|[CComboBoxEx::GetEditCtrl](#geteditctrl)|Recupera o identificador para a parte de controle de edição de um controle de `ComboBoxEx`.|
|[CComboBoxEx:: Extended](#getextendedstyle)|Recupera os estilos estendidos que estão em uso para um controle de `ComboBoxEx`.|
|[CComboBoxEx:: GetImageList](#getimagelist)|Recupera um ponteiro para a lista de imagens atribuída a um controle de `ComboBoxEx`.|
|[CComboBoxEx:: GetItem](#getitem)|Recupera informações de item para um determinado item de `ComboBoxEx`.|
|[CComboBoxEx::HasEditChanged](#haseditchanged)|Determina se o usuário alterou o conteúdo do `ComboBoxEx` controle de edição digitando.|
|[CComboBoxEx:: InsertItem](#insertitem)|Insere um novo item em um controle de `ComboBoxEx`.|
|[CComboBoxEx:: Extended](#setextendedstyle)|Define os estilos estendidos dentro de um controle de `ComboBoxEx`.|
|[CComboBoxEx:: SetImageList](#setimagelist)|Define uma lista de imagens para um controle de `ComboBoxEx`.|
|[CComboBoxEx::SetItem](#setitem)|Define os atributos de um item em um controle de `ComboBoxEx`.|
|[CComboBoxEx:: SetWindowTheme](#setwindowtheme)|Define o estilo visual do controle da caixa de combinação estendida.|

## <a name="remarks"></a>Comentários

Usando `CComboBoxEx` para criar controles de caixa de combinação, você não precisa mais implementar seu próprio código de desenho de imagem. Em vez disso, use `CComboBoxEx` para acessar imagens de uma lista de imagens.

## <a name="image-list-support"></a>Suporte à lista de imagens

Em uma caixa de combinação padrão, o proprietário da caixa de combinação é responsável por desenhar uma imagem criando a caixa de combinação como um controle de desenho proprietário. Quando você usa `CComboBoxEx`, não é necessário definir os estilos de desenho CBS_OWNERDRAWFIXED e CBS_HASSTRINGS porque eles são implícitos. Caso contrário, você deve escrever código para executar operações de desenho. Um controle de `CComboBoxEx` dá suporte a até três imagens por item: uma para um estado selecionado, uma para um estado não selecionado e outra para uma imagem de sobreposição.

## <a name="styles"></a>Estilos

`CComboBoxEx` dá suporte aos estilos CBS_SIMPLE, CBS_DROPDOWN, CBS_DROPDOWNLIST e WS_CHILD. Todos os outros estilos passados quando você cria a janela são ignorados pelo controle. Depois que a janela for criada, você poderá fornecer outros estilos de caixa de combinação chamando a função membro `CComboBoxEx` [setextendedattribute](#setextendedstyle). Com esses estilos, você pode:

- Defina as pesquisas de cadeia de caracteres na lista para diferenciar maiúsculas de minúsculas.

- Crie um controle de caixa de combinação que use a barra ('/'), a barra invertida ('\\') e os caracteres de ponto ('. ') como delimitadores de palavras. Isso permite que os usuários saltem do Word para o Word, usando o atalho de teclado CTRL + seta.

- Defina o controle caixa de combinação como exibir ou não exibir uma imagem. Se nenhuma imagem for exibida, a caixa de combinação poderá remover o recuo de texto que acomoda uma imagem.

- Crie um controle de caixa de combinação estreito, incluindo dimensioná-lo para que ele corte a caixa de combinação mais larga que ele contém.

Esses sinalizadores de estilo são descritos mais detalhadamente no [uso de CComboBoxEx](../../mfc/using-ccomboboxex.md).

## <a name="item-retention-and-callback-item-attributes"></a>Atributos de item de retorno e de retenção de item

As informações do item, como índices para itens e imagens, valores de recuo e cadeias de caracteres de texto, são armazenadas na estrutura do Win32 [COMBOBOXEXITEM](/windows/win32/api/commctrl/ns-commctrl-comboboxexitemw), conforme descrito na SDK do Windows. A estrutura também contém membros que correspondem aos sinalizadores de retorno de chamada.

Para obter uma discussão conceitual e detalhada, consulte [usando CComboBoxEx](../../mfc/using-ccomboboxex.md).

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[CObject](../../mfc/reference/cobject-class.md)

[CCmdTarget](../../mfc/reference/ccmdtarget-class.md)

[CWnd](../../mfc/reference/cwnd-class.md)

[CComboBox](../../mfc/reference/ccombobox-class.md)

`CComboBoxEx`

## <a name="requirements"></a>{1&gt;{2&gt;Requisitos&lt;2}&lt;1}

**Cabeçalho:** afxcmn. h

##  <a name="ccomboboxex"></a>CComboBoxEx::CComboBoxEx

Chame essa função de membro para criar um objeto de `CComboBoxEx`.

```
CComboBoxEx();
```

##  <a name="create"></a>CComboBoxEx:: criar

Cria a caixa de combinação e a anexa ao objeto `CComboBoxEx`.

```
virtual BOOL Create(
    DWORD dwStyle,
    const RECT& rect,
    CWnd* pParentWnd,
    UINT nID);
```

### <a name="parameters"></a>Parâmetros

*dwStyle*<br/>
Especifica a combinação de estilos de caixa de combinação aplicada à caixa de combinação. Consulte os **comentários** abaixo para obter mais informações sobre estilos.

*Rect*<br/>
Uma referência a uma estrutura de objeto [CRect](../../atl-mfc-shared/reference/crect-class.md) ou [Rect](/previous-versions/dd162897\(v=vs.85\)) , que é a posição e o tamanho da caixa de combinação.

*pParentWnd*<br/>
Um ponteiro para um objeto [CWnd](../../mfc/reference/cwnd-class.md) que é a janela pai da caixa de combinação (geralmente um `CDialog`). Ele não deve ser nulo.

*nID*<br/>
Especifica a ID de controle da caixa de combinação.

### <a name="return-value"></a>Valor retornado

Diferente de zero se o objeto foi criado com êxito; caso contrário, 0.

### <a name="remarks"></a>Comentários

Crie um objeto `CComboBoxEx` em duas etapas:

1. Chame [CComboBoxEx](#ccomboboxex) para construir um objeto de `CComboBoxEx`.

1. Chame essa função de membro, que cria a caixa de combinação do Windows estendida e a anexa ao objeto `CComboBoxEx`.

Quando você chama `Create`, o MFC Inicializa os controles comuns.

Ao criar a caixa de combinação, você pode especificar qualquer um dos seguintes estilos de caixa de combinação ou todos eles:

- CBS_SIMPLE

- CBS_DROPDOWN

- CBS_DROPDOWNLIST

- CBS_AUTOHSCROLL

- WS_CHILD

Todos os outros estilos passados quando você cria a janela são ignorados. O controle de `ComboBoxEx` também dá suporte a estilos estendidos que fornecem recursos adicionais. Esses estilos são descritos em [estilos estendidos do controle ComboBoxEx](/windows/win32/Controls/comboboxex-control-extended-styles), na SDK do Windows. Defina esses estilos chamando [Setextendedattributestyle](#setextendedstyle).

Se você quiser usar estilos estendidos do Windows com seu controle, chame [CreateEx](#createex) em vez de `Create`.

##  <a name="createex"></a>CComboBoxEx::CreateEx

Chame essa função para criar um controle de caixa de combinação estendida (uma janela filho) e associá-la ao objeto `CComboBoxEx`.

```
virtual BOOL CreateEx(
    DWORD dwExStyle,
    DWORD dwStyle,
    const RECT& rect,
    CWnd* pParentWnd,
    UINT nID);
```

### <a name="parameters"></a>Parâmetros

*dwExStyle*<br/>
Especifica o estilo estendido do controle que está sendo criado. Para obter uma lista de estilos estendidos do Windows, consulte o parâmetro *dwExStyle* para [CreateWindowEx](/windows/win32/api/winuser/nf-winuser-createwindowexw) no SDK do Windows.

*dwStyle*<br/>
O estilo do controle da caixa de combinação. Consulte [criar](#create) para obter uma lista de estilos.

*Rect*<br/>
Uma referência a uma estrutura [Rect](/previous-versions/dd162897\(v=vs.85\)) que descreve o tamanho e a posição da janela a ser criada, nas coordenadas de cliente de *pParentWnd*.

*pParentWnd*<br/>
Um ponteiro para a janela que é o pai do controle.

*nID*<br/>
A ID da janela filho do controle.

### <a name="return-value"></a>Valor retornado

Diferente de zero, se for bem-sucedido; caso contrário, 0.

### <a name="remarks"></a>Comentários

Use `CreateEx` em vez de `Create` para aplicar estilos estendidos do Windows, especificados pelo **WS_EX_** de prefácio de estilo estendido do Windows.

`CreateEx` cria o controle com os estilos estendidos do Windows especificados por *dwExStyle*. Você deve definir estilos estendidos específicos para um controle de caixa de combinação estendida usando [Setextendedattributestyle](#setextendedstyle). Por exemplo, use `CreateEx` para definir esses estilos como WS_EX_CONTEXTHELP, mas use `SetExtendedStyle` para definir esses estilos como CBES_EX_CASESENSITIVE. Para obter mais informações, consulte os estilos descritos no tópico [ComboBoxEx controlar estilos estendidos](/windows/win32/Controls/comboboxex-control-extended-styles) na SDK do Windows.

##  <a name="deleteitem"></a>CComboBoxEx::D eleteItem

Remove um item de um controle `ComboBoxEx`.

```
int DeleteItem(int iIndex);
```

### <a name="parameters"></a>Parâmetros

*iIndex*<br/>
Índice de base zero do item a ser removido.

### <a name="return-value"></a>Valor retornado

O número de itens restantes no controle. Se *iIndex* for inválido, a função retornará CB_ERR.

### <a name="remarks"></a>Comentários

Essa função de membro implementa a funcionalidade da mensagem [CBEM_DELETEITEM](/windows/win32/Controls/cbem-deleteitem), conforme descrito na SDK do Windows. Quando você chama DeleteItem, uma mensagem [WM_NOTIFY](/windows/win32/controls/wm-notify) com CBEN_DELETEITEM notificação será enviada para a janela pai.

##  <a name="getcomboboxctrl"></a>CComboBoxEx::GetComboBoxCtrl

Chame essa função de membro para obter um ponteiro para um controle de caixa de combinação dentro de um objeto `CComboBoxEx`.

```
CComboBox* GetComboBoxCtrl();
```

### <a name="return-value"></a>Valor retornado

Um ponteiro para um objeto `CComboBox`.

### <a name="remarks"></a>Comentários

O controle de `CComboBoxEx` consiste em uma janela pai, que encapsula um `CComboBox`.

O objeto de `CComboBox` apontado pelo valor de retorno é um objeto temporário e é destruído durante o próximo tempo de processamento ocioso.

##  <a name="geteditctrl"></a>CComboBoxEx::GetEditCtrl

Chame essa função de membro para obter um ponteiro para o controle de edição de uma caixa de combinação.

```
CEdit* GetEditCtrl();
```

### <a name="return-value"></a>Valor retornado

Um ponteiro para um objeto [CEdit](../../mfc/reference/cedit-class.md) .

### <a name="remarks"></a>Comentários

Um controle de `CComboBoxEx` usa uma caixa de edição quando ela é criada com o estilo de CBS_DROPDOWN.

O objeto de `CEdit` apontado pelo valor de retorno é um objeto temporário e é destruído durante o próximo tempo de processamento ocioso.

##  <a name="getextendedstyle"></a>CComboBoxEx:: Extended

Chame essa função de membro para obter os estilos estendidos usados para um controle de `CComboBoxEx`.

```
DWORD GetExtendedStyle() const;
```

### <a name="return-value"></a>Valor retornado

O valor DWORD que contém os estilos estendidos que são usados para o controle da caixa de combinação.

### <a name="remarks"></a>Comentários

Consulte [ComboBoxEx Control Extended Styles](/windows/win32/Controls/comboboxex-control-extended-styles) no SDK do Windows para obter mais informações sobre esses estilos.

##  <a name="getimagelist"></a>CComboBoxEx:: GetImageList

Chame essa função de membro para obter um ponteiro para a lista de imagens usada por um controle de `CComboBoxEx`.

```
CImageList* GetImageList() const;
```

### <a name="return-value"></a>Valor retornado

Um ponteiro para um objeto [CImageList](../../mfc/reference/cimagelist-class.md) . Se falhar, essa função de membro retornará NULL.

### <a name="remarks"></a>Comentários

O objeto de `CImageList` apontado pelo valor de retorno é um objeto temporário e é destruído durante o próximo tempo de processamento ocioso.

##  <a name="getitem"></a>CComboBoxEx:: GetItem

Recupera informações de item para um determinado item de `ComboBoxEx`.

```
BOOL GetItem(COMBOBOXEXITEM* pCBItem);
```

### <a name="parameters"></a>Parâmetros

*pCBItem*<br/>
Um ponteiro para uma estrutura [COMBOBOXEXITEM](/windows/win32/api/commctrl/ns-commctrl-comboboxexitemw) que receberá as informações do item.

### <a name="return-value"></a>Valor retornado

Diferente de zero se a operação foi bem-sucedida; caso contrário, 0.

### <a name="remarks"></a>Comentários

Essa função de membro implementa a funcionalidade da mensagem [CBEM_GETITEM](/windows/win32/Controls/cbem-getitem), conforme descrito na SDK do Windows.

##  <a name="haseditchanged"></a>CComboBoxEx::HasEditChanged

Determina se o usuário alterou o conteúdo do `ComboBoxEx` controle de edição digitando.

```
BOOL HasEditChanged();
```

### <a name="return-value"></a>Valor retornado

Diferente de zero se o usuário tiver digitado na caixa de edição do controle; caso contrário, 0.

### <a name="remarks"></a>Comentários

Essa função de membro implementa a funcionalidade da mensagem [CBEM_HASEDITCHANGED](/windows/win32/Controls/cbem-haseditchanged), conforme descrito na SDK do Windows.

##  <a name="insertitem"></a>CComboBoxEx:: InsertItem

Insere um novo item em um controle de `ComboBoxEx`.

```
int InsertItem(const COMBOBOXEXITEM* pCBItem);
```

### <a name="parameters"></a>Parâmetros

*pCBItem*<br/>
Um ponteiro para uma estrutura [COMBOBOXEXITEM](/windows/win32/api/commctrl/ns-commctrl-comboboxexitemw) que receberá as informações do item. Esta estrutura contém valores de sinalizador de retorno de chamada para o item.

### <a name="return-value"></a>Valor retornado

O índice no qual o novo item foi inserido, se bem-sucedido; caso contrário,-1.

### <a name="remarks"></a>Comentários

Quando você chama `InsertItem`, uma mensagem [WM_NOTIFY](/windows/win32/controls/wm-notify) com [CBEN_INSERTITEM](/windows/win32/Controls/cben-insertitem) notificação será enviada para a janela pai.

##  <a name="setextendedstyle"></a>CComboBoxEx:: Extended

Chame essa função de membro para definir os estilos estendidos usados para um controle estendido de caixa de combinação.

```
DWORD SetExtendedStyle(
    DWORD dwExMask,
    DWORD dwExStyles);
```

### <a name="parameters"></a>Parâmetros

*dwExMask*<br/>
Um valor DWORD que indica quais estilos em *dwExStyles* devem ser afetados. Somente os estilos estendidos em *dwExMask* serão alterados. Todos os outros estilos serão mantidos como estão. Se esse parâmetro for zero, todos os estilos em *dwExStyles* serão afetados.

*dwExStyles*<br/>
Um valor DWORD que contém os estilos estendidos do controle de caixa de combinação a ser definido para o controle.

### <a name="return-value"></a>Valor retornado

Um valor DWORD que contém os estilos estendidos usados anteriormente para o controle.

### <a name="remarks"></a>Comentários

Consulte [ComboBoxEx Control Extended Styles](/windows/win32/Controls/comboboxex-control-extended-styles) no SDK do Windows para obter mais informações sobre esses estilos.

Para criar um controle estendido de caixa de combinação com estilos estendidos do Windows, use [CreateEx](#createex).

##  <a name="setimagelist"></a>CComboBoxEx:: SetImageList

Define uma lista de imagens para um controle de `ComboBoxEx`.

```
CImageList* SetImageList(CImageList* pImageList);
```

### <a name="parameters"></a>Parâmetros

*pImageList*<br/>
Um ponteiro para um objeto de `CImageList` que contém as imagens a serem usadas com o controle de `CComboBoxEx`.

### <a name="return-value"></a>Valor retornado

Um ponteiro para um objeto [CImageList](../../mfc/reference/cimagelist-class.md) que contém as imagens usadas anteriormente pelo controle de `CComboBoxEx`. NULL se nenhuma lista de imagens tiver sido definida anteriormente.

### <a name="remarks"></a>Comentários

Essa função de membro implementa a funcionalidade da mensagem [CBEM_SETIMAGELIST](/windows/win32/Controls/cbem-setimagelist), conforme descrito na SDK do Windows. Se você alterar a altura do controle de edição padrão, chame a função do Win32 [SetWindowPos](/windows/win32/api/winuser/nf-winuser-setwindowpos) para redimensionar o controle depois de chamar `SetImageList`ou ele não será exibido corretamente.

O objeto de `CImageList` apontado pelo valor de retorno é um objeto temporário e é destruído durante o próximo tempo de processamento ocioso.

##  <a name="setitem"></a>CComboBoxEx::SetItem

Define os atributos de um item em um controle de `ComboBoxEx`.

```
BOOL SetItem(const COMBOBOXEXITEM* pCBItem);
```

### <a name="parameters"></a>Parâmetros

*pCBItem*<br/>
Um ponteiro para uma estrutura [COMBOBOXEXITEM](/windows/win32/api/commctrl/ns-commctrl-comboboxexitemw) que receberá as informações do item.

### <a name="return-value"></a>Valor retornado

Diferente de zero se a operação foi bem-sucedida; caso contrário, 0.

### <a name="remarks"></a>Comentários

Essa função de membro implementa a funcionalidade da mensagem [CBEM_SETITEM](/windows/win32/Controls/cbem-setitem), conforme descrito na SDK do Windows.

##  <a name="setwindowtheme"></a>CComboBoxEx:: SetWindowTheme

Define o estilo visual do controle da caixa de combinação estendida.

```
HRESULT SetWindowTheme(LPCWSTR pszSubAppName);
```

### <a name="parameters"></a>Parâmetros

*pszSubAppName*<br/>
Um ponteiro para uma cadeia de caracteres Unicode que contém o estilo visual da caixa de combinação estendida a ser definido.

### <a name="return-value"></a>Valor retornado

O valor de retorno não é usado.

### <a name="remarks"></a>Comentários

Essa função de membro emula a funcionalidade da [CBEM_SETWINDOWTHEME](/windows/win32/Controls/cbem-setwindowtheme) mensagem, conforme descrito na SDK do Windows.

## <a name="see-also"></a>Consulte também

[Exemplo de MFCIE do MFC](../../overview/visual-cpp-samples.md)<br/>
[Classe CComboBox](../../mfc/reference/ccombobox-class.md)<br/>
[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classe CComboBox](../../mfc/reference/ccombobox-class.md)
