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
ms.openlocfilehash: 4151ea17fd3223c126715742c6149f2cf55bcbc7
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81369467"
---
# <a name="ccomboboxex-class"></a>Classe CComboBoxEx

Amplia o controle da caixa de combinação fornecendo suporte para listas de imagens.

## <a name="syntax"></a>Sintaxe

```
class CComboBoxEx : public CComboBox
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[CComboBoxEx::CComboBoxEx](#ccomboboxex)|Constrói um objeto `CComboBoxEx`.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CComboBoxEx::Criar](#create)|Cria a caixa de combinação e `CComboBoxEx` a prende ao objeto.|
|[CComboBoxEx::CreateEx](#createex)|Cria uma caixa combo com os estilos estendidos `ComboBoxEx` do Windows especificados e a anexa a um objeto.|
|[CComboBoxEx::Deleteitem](#deleteitem)|Remove um item `ComboBoxEx` de um controle.|
|[CComboBoxEx::GetComboBoxCtrl](#getcomboboxctrl)|Recupera um ponteiro para o controle da caixa de combinação de crianças.|
|[CComboBoxEx::GetEditCtrl](#geteditctrl)|Recupera a alça na parte de `ComboBoxEx` controle de edição de um controle.|
|[CComboBoxEx::GetExtendedStyle](#getextendedstyle)|Recupera os estilos estendidos que `ComboBoxEx` estão em uso para um controle.|
|[CComboBoxEx::GetImageList](#getimagelist)|Recupera um ponteiro para a lista `ComboBoxEx` de imagens atribuída a um controle.|
|[CComboBoxEx::GetItem](#getitem)|Recupera informações do item `ComboBoxEx` para um determinado item.|
|[CComboBoxEx::HasEditChanged](#haseditchanged)|Determina se o usuário alterou `ComboBoxEx` o conteúdo do controle de edição digitando.|
|[CComboBoxEx::InsertItem](#insertitem)|Insere um novo `ComboBoxEx` item em um controle.|
|[CComboBoxEx::SetExtendedStyle](#setextendedstyle)|Define estilos estendidos dentro de um `ComboBoxEx` controle.|
|[CComboBoxEx::SetImageList](#setimagelist)|Define uma lista `ComboBoxEx` de imagens para um controle.|
|[CComboBoxEx::SetItem](#setitem)|Define os atributos para `ComboBoxEx` um item em um controle.|
|[CComboBoxEx::SetWindowTheme](#setwindowtheme)|Define o estilo visual do controle de caixa de combinação estendida.|

## <a name="remarks"></a>Comentários

Ao `CComboBoxEx` usar para criar controles de caixa de combinação, você não precisa mais implementar seu próprio código de desenho de imagem. Em vez `CComboBoxEx` disso, use para acessar imagens de uma lista de imagens.

## <a name="image-list-support"></a>Suporte à lista de imagens

Em uma caixa de combinação padrão, o proprietário da caixa de combinação é responsável por desenhar uma imagem criando a caixa de combinação como um controle de sorteio do proprietário. Quando você `CComboBoxEx`usa, você não precisa definir os estilos de desenho CBS_OWNERDRAWFIXED e CBS_HASSTRINGS porque eles estão implícitos. Caso contrário, você deve escrever código para executar operações de desenho. Um `CComboBoxEx` controle suporta até três imagens por item: uma para um estado selecionado, uma para um estado não selecionado e outra para uma imagem de sobreposição.

## <a name="styles"></a>Estilos

`CComboBoxEx`apoia os estilos CBS_SIMPLE, CBS_DROPDOWN, CBS_DROPDOWNLIST e WS_CHILD. Todos os outros estilos passados quando você cria a janela são ignorados pelo controle. Depois que a janela for criada, você pode fornecer `CComboBoxEx` outros estilos de caixa de combinação chamando a função de membro [SetExtendedStyle](#setextendedstyle). Com esses estilos, você pode:

- Defina as pesquisas de seqüência na lista para serem sensíveis a maiúsculas e minúsculas.

- Crie um controle de caixa de combinação que use os\\caracteres barra ('/'), barra invertida (' ') e período ('.') como delimitadores de palavras. Isso permite que os usuários saltem de palavra em palavra, usando o atalho de teclado CTRL+ ARROW.

- Defina o controle da caixa combo para exibir ou não exibir uma imagem. Se nenhuma imagem for exibida, a caixa de combinação poderá remover o recuo de texto que acomoda uma imagem.

- Crie um controle de caixa de combinação estreito, incluindo dimensioná-lo para que ele clipe a caixa de combinação mais ampla que ele contém.

Essas bandeiras de estilo são descritas ainda mais no [uso do CComboBoxEx](../../mfc/using-ccomboboxex.md).

## <a name="item-retention-and-callback-item-attributes"></a>Atributos de itens de retenção e retorno de chamada de itens

As informações de itens, como índices para itens e imagens, valores de recuo e strings de texto, são armazenadas na estrutura Win32 [COMBOBOXEXITEM](/windows/win32/api/commctrl/ns-commctrl-comboboxexitemw), conforme descrito no SDK do Windows. A estrutura também contém membros que correspondem a bandeiras de retorno.

Para uma discussão conceitual detalhada, consulte [Usando CComboBoxEx](../../mfc/using-ccomboboxex.md).

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[Cobject](../../mfc/reference/cobject-class.md)

[Ccmdtarget](../../mfc/reference/ccmdtarget-class.md)

[CWnd](../../mfc/reference/cwnd-class.md)

[CComboBox](../../mfc/reference/ccombobox-class.md)

`CComboBoxEx`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxcmn.h

## <a name="ccomboboxexccomboboxex"></a><a name="ccomboboxex"></a>CComboBoxEx::CComboBoxEx

Chame esta função de `CComboBoxEx` membro para criar um objeto.

```
CComboBoxEx();
```

## <a name="ccomboboxexcreate"></a><a name="create"></a>CComboBoxEx::Criar

Cria a caixa de combinação e `CComboBoxEx` a prende ao objeto.

```
virtual BOOL Create(
    DWORD dwStyle,
    const RECT& rect,
    CWnd* pParentWnd,
    UINT nID);
```

### <a name="parameters"></a>Parâmetros

*Dwstyle*<br/>
Especifica a combinação de estilos de caixa combo aplicados à caixa de combinação. Veja **observações** abaixo para obter mais informações sobre estilos.

*Rect*<br/>
Uma referência a um objeto [CRect](../../atl-mfc-shared/reference/crect-class.md) ou estrutura [RECT,](/previous-versions/dd162897\(v=vs.85\)) que é a posição e o tamanho da caixa de combinação.

*Pparentwnd*<br/>
Um ponteiro para um objeto [CWnd](../../mfc/reference/cwnd-class.md) que é a janela `CDialog`pai da caixa de combinação (geralmente a ). Não deve ser NULO.

*nID*<br/>
Especifica o ID de controle da caixa de combinação.

### <a name="return-value"></a>Valor retornado

Não zero se o objeto foi criado com sucesso; caso contrário, 0.

### <a name="remarks"></a>Comentários

Criar `CComboBoxEx` um objeto em duas etapas:

1. Ligue para [o CComboBoxEx](#ccomboboxex) para construir um `CComboBoxEx` objeto.

1. Ligue para esta função de membro, que cria a `CComboBoxEx` caixa de combinação estendida do Windows e a anexa ao objeto.

Quando você `Create`chama, o MFC inicializa os controles comuns.

Quando você cria a caixa de combinação, você pode especificar qualquer ou todos os seguintes estilos de caixa de combinação:

- Cbs_simple

- Cbs_dropdown

- Cbs_dropdownlist

- CBS_AUTOHSCROLL

- Estilo

Todos os outros estilos passados quando você cria a janela são ignorados. O `ComboBoxEx` controle também suporta estilos estendidos que fornecem recursos adicionais. Esses estilos são descritos no [controle ComboBoxEx de estilos estendidos,](/windows/win32/Controls/comboboxex-control-extended-styles)no Windows SDK. Defina esses estilos chamando [SetExtendedStyle](#setextendedstyle).

Se você quiser usar estilos de janelas estendidos `Create`com o controle, chame [CreateEx](#createex) em vez de .

## <a name="ccomboboxexcreateex"></a><a name="createex"></a>CComboBoxEx::CreateEx

Chame esta função para criar um controle de caixa de combinação `CComboBoxEx` estendido (uma janela filho) e associá-la com o objeto.

```
virtual BOOL CreateEx(
    DWORD dwExStyle,
    DWORD dwStyle,
    const RECT& rect,
    CWnd* pParentWnd,
    UINT nID);
```

### <a name="parameters"></a>Parâmetros

*Dwexstyle*<br/>
Especifica o estilo estendido do controle que está sendo criado. Para obter uma lista de estilos estendidos do Windows, consulte o parâmetro *dwExStyle* para [CreateWindowEx](/windows/win32/api/winuser/nf-winuser-createwindowexw) no SDK do Windows.

*Dwstyle*<br/>
O estilo do controle da caixa combo. Consulte [Criar](#create) para uma lista de estilos.

*Rect*<br/>
Uma referência a uma estrutura [RECT](/previous-versions/dd162897\(v=vs.85\)) descrevendo o tamanho e a posição da janela a ser criada, em coordenadas de cliente de *pParentWnd*.

*Pparentwnd*<br/>
Um ponteiro para a janela que é o pai do controle.

*nID*<br/>
A id da janela infantil do controle.

### <a name="return-value"></a>Valor retornado

Não zero se bem sucedido; caso contrário, 0.

### <a name="remarks"></a>Comentários

Use `CreateEx` em `Create` vez de aplicar estilos estendidos do Windows, especificados pelo prefácio de estilo estendido do Windows **WS_EX_**.

`CreateEx`cria o controle com os estilos estendidos do Windows especificados pelo *dwExStyle*. Você deve definir estilos estendidos específicos para um controle de caixa de combinação estendido usando [SetExtendedStyle](#setextendedstyle). Por exemplo, `CreateEx` use para definir estilos `SetExtendedStyle` como WS_EX_CONTEXTHELP, mas use para definir estilos como CBES_EX_CASESENSITIVE. Para obter mais informações, consulte os estilos descritos no tópico [ComboBoxEx Control Extended Styles](/windows/win32/Controls/comboboxex-control-extended-styles) no Windows SDK.

## <a name="ccomboboxexdeleteitem"></a><a name="deleteitem"></a>CComboBoxEx::Deleteitem

Remove um item `ComboBoxEx` de um controle.

```
int DeleteItem(int iIndex);
```

### <a name="parameters"></a>Parâmetros

*Iindex*<br/>
Índice baseado em zero do item a ser removido.

### <a name="return-value"></a>Valor retornado

O número de itens restantes no controle. Se *o iIndex* for inválido, a função retorna CB_ERR.

### <a name="remarks"></a>Comentários

Esta função de membro implementa a funcionalidade da mensagem [CBEM_DELETEITEM,](/windows/win32/Controls/cbem-deleteitem)conforme descrito no SDK do Windows. Quando você chamar DeleteItem, uma mensagem [WM_NOTIFY](/windows/win32/controls/wm-notify) com CBEN_DELETEITEM notificação será enviada para a janela dos pais.

## <a name="ccomboboxexgetcomboboxctrl"></a><a name="getcomboboxctrl"></a>CComboBoxEx::GetComboBoxCtrl

Chame esta função de membro para obter um `CComboBoxEx` ponteiro para um controle de caixa combo dentro de um objeto.

```
CComboBox* GetComboBoxCtrl();
```

### <a name="return-value"></a>Valor retornado

Um ponteiro para um objeto `CComboBox`.

### <a name="remarks"></a>Comentários

O `CComboBoxEx` controle consiste em uma janela pai, `CComboBox`que encapsula um .

O `CComboBox` objeto apontado pelo valor de retorno é um objeto temporário e é destruído durante o próximo tempo de processamento ocioso.

## <a name="ccomboboxexgeteditctrl"></a><a name="geteditctrl"></a>CComboBoxEx::GetEditCtrl

Ligue para esta função de membro para obter um ponteiro para o controle de edição para uma caixa de combinação.

```
CEdit* GetEditCtrl();
```

### <a name="return-value"></a>Valor retornado

Um ponteiro para um objeto [CEdit.](../../mfc/reference/cedit-class.md)

### <a name="remarks"></a>Comentários

Um `CComboBoxEx` controle usa uma caixa de edição quando é criada com o estilo CBS_DROPDOWN.

O `CEdit` objeto apontado pelo valor de retorno é um objeto temporário e é destruído durante o próximo tempo de processamento ocioso.

## <a name="ccomboboxexgetextendedstyle"></a><a name="getextendedstyle"></a>CComboBoxEx::GetExtendedStyle

Ligue para esta função de membro `CComboBoxEx` para obter os estilos estendidos usados para um controle.

```
DWORD GetExtendedStyle() const;
```

### <a name="return-value"></a>Valor retornado

O valor DWORD que contém os estilos estendidos que são usados para o controle da caixa de combinação.

### <a name="remarks"></a>Comentários

Consulte [ComboBoxEx Control Extended Styles](/windows/win32/Controls/comboboxex-control-extended-styles) no Windows SDK para obter mais informações sobre esses estilos.

## <a name="ccomboboxexgetimagelist"></a><a name="getimagelist"></a>CComboBoxEx::GetImageList

Ligue para esta função de membro para obter `CComboBoxEx` um ponteiro para a lista de imagens usada por um controle.

```
CImageList* GetImageList() const;
```

### <a name="return-value"></a>Valor retornado

Um ponteiro para um objeto [CImageList.](../../mfc/reference/cimagelist-class.md) Se falhar, esta função de membro retorna NULL.

### <a name="remarks"></a>Comentários

O `CImageList` objeto apontado pelo valor de retorno é um objeto temporário e é destruído durante o próximo tempo de processamento ocioso.

## <a name="ccomboboxexgetitem"></a><a name="getitem"></a>CComboBoxEx::GetItem

Recupera informações do item `ComboBoxEx` para um determinado item.

```
BOOL GetItem(COMBOBOXEXITEM* pCBItem);
```

### <a name="parameters"></a>Parâmetros

*pCBItem*<br/>
Um ponteiro para uma estrutura [COMBOBOXEXITEM](/windows/win32/api/commctrl/ns-commctrl-comboboxexitemw) que receberá as informações do item.

### <a name="return-value"></a>Valor retornado

Não zero se a operação foi bem sucedida; caso contrário, 0.

### <a name="remarks"></a>Comentários

Esta função de membro implementa a funcionalidade da mensagem [CBEM_GETITEM,](/windows/win32/Controls/cbem-getitem)conforme descrito no SDK do Windows.

## <a name="ccomboboxexhaseditchanged"></a><a name="haseditchanged"></a>CComboBoxEx::HasEditChanged

Determina se o usuário alterou `ComboBoxEx` o conteúdo do controle de edição digitando.

```
BOOL HasEditChanged();
```

### <a name="return-value"></a>Valor retornado

Não zero se o usuário tiver digitado na caixa de edição do controle; caso contrário, 0.

### <a name="remarks"></a>Comentários

Esta função de membro implementa a funcionalidade da mensagem [CBEM_HASEDITCHANGED,](/windows/win32/Controls/cbem-haseditchanged)conforme descrito no SDK do Windows.

## <a name="ccomboboxexinsertitem"></a><a name="insertitem"></a>CComboBoxEx::InsertItem

Insere um novo `ComboBoxEx` item em um controle.

```
int InsertItem(const COMBOBOXEXITEM* pCBItem);
```

### <a name="parameters"></a>Parâmetros

*pCBItem*<br/>
Um ponteiro para uma estrutura [COMBOBOXEXITEM](/windows/win32/api/commctrl/ns-commctrl-comboboxexitemw) que receberá as informações do item. Esta estrutura contém valores de bandeira de retorno de chamada para o item.

### <a name="return-value"></a>Valor retornado

O índice no qual o novo item foi inserido se bem sucedido; caso contrário -1.

### <a name="remarks"></a>Comentários

Quando você `InsertItem`ligar, uma mensagem [WM_NOTIFY](/windows/win32/controls/wm-notify) com [CBEN_INSERTITEM](/windows/win32/Controls/cben-insertitem) notificação será enviada para a janela dos pais.

## <a name="ccomboboxexsetextendedstyle"></a><a name="setextendedstyle"></a>CComboBoxEx::SetExtendedStyle

Chame esta função de membro para definir os estilos estendidos usados para um controle estendido da caixa combo.

```
DWORD SetExtendedStyle(
    DWORD dwExMask,
    DWORD dwExStyles);
```

### <a name="parameters"></a>Parâmetros

*Dwexmask*<br/>
Um valor DWORD que indica quais estilos em *dwExStyles* devem ser afetados. Apenas os estilos estendidos no *dwExMask* serão alterados. Todos os outros estilos serão mantidos como estão. Se este parâmetro for zero, todos os estilos em *dwExStyles* serão afetados.

*Dwexstyles*<br/>
Um valor DWORD que contém o controle de caixa de combinação de estilos estendidos para definir para o controle.

### <a name="return-value"></a>Valor retornado

Um valor DWORD que contém os estilos estendidos usados anteriormente para o controle.

### <a name="remarks"></a>Comentários

Consulte [ComboBoxEx Control Extended Styles](/windows/win32/Controls/comboboxex-control-extended-styles) no Windows SDK para obter mais informações sobre esses estilos.

Para criar um controle estendido de caixa com bo com estilos de janelas estendidos, use [CreateEx](#createex).

## <a name="ccomboboxexsetimagelist"></a><a name="setimagelist"></a>CComboBoxEx::SetImageList

Define uma lista `ComboBoxEx` de imagens para um controle.

```
CImageList* SetImageList(CImageList* pImageList);
```

### <a name="parameters"></a>Parâmetros

*pImageList*<br/>
Um ponteiro `CImageList` para um objeto contendo as `CComboBoxEx` imagens para usar com o controle.

### <a name="return-value"></a>Valor retornado

Um ponteiro para um objeto [CImageList](../../mfc/reference/cimagelist-class.md) contendo as `CComboBoxEx` imagens usadas anteriormente pelo controle. NULL se nenhuma lista de imagens foi definida anteriormente.

### <a name="remarks"></a>Comentários

Esta função de membro implementa a funcionalidade da mensagem [CBEM_SETIMAGELIST,](/windows/win32/Controls/cbem-setimagelist)conforme descrito no SDK do Windows. Se você alterar a altura do controle de edição padrão, chame a função Win32 [SetWindowPos](/windows/win32/api/winuser/nf-winuser-setwindowpos) para redimensionar seu controle após a chamada, `SetImageList`ou ele não será exibido corretamente.

O `CImageList` objeto apontado pelo valor de retorno é um objeto temporário e é destruído durante o próximo tempo de processamento ocioso.

## <a name="ccomboboxexsetitem"></a><a name="setitem"></a>CComboBoxEx::SetItem

Define os atributos para `ComboBoxEx` um item em um controle.

```
BOOL SetItem(const COMBOBOXEXITEM* pCBItem);
```

### <a name="parameters"></a>Parâmetros

*pCBItem*<br/>
Um ponteiro para uma estrutura [COMBOBOXEXITEM](/windows/win32/api/commctrl/ns-commctrl-comboboxexitemw) que receberá as informações do item.

### <a name="return-value"></a>Valor retornado

Não zero se a operação foi bem sucedida; caso contrário, 0.

### <a name="remarks"></a>Comentários

Esta função de membro implementa a funcionalidade da mensagem [CBEM_SETITEM,](/windows/win32/Controls/cbem-setitem)conforme descrito no SDK do Windows.

## <a name="ccomboboxexsetwindowtheme"></a><a name="setwindowtheme"></a>CComboBoxEx::SetWindowTheme

Define o estilo visual do controle de caixa de combinação estendida.

```
HRESULT SetWindowTheme(LPCWSTR pszSubAppName);
```

### <a name="parameters"></a>Parâmetros

*pszSubAppName*<br/>
Um ponteiro para uma seqüência Unicode que contém o estilo visual de caixa de combinação estendida a definir.

### <a name="return-value"></a>Valor retornado

O valor de retorno não é usado.

### <a name="remarks"></a>Comentários

Esta função membro emula a funcionalidade da mensagem [CBEM_SETWINDOWTHEME,](/windows/win32/Controls/cbem-setwindowtheme) conforme descrito no SDK do Windows.

## <a name="see-also"></a>Confira também

[MFC Amostra MFCIE](../../overview/visual-cpp-samples.md)<br/>
[Classe CComboBox](../../mfc/reference/ccombobox-class.md)<br/>
[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classe CComboBox](../../mfc/reference/ccombobox-class.md)
