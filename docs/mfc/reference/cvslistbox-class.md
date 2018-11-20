---
title: Classe CVSListBox
ms.date: 11/19/2018
f1_keywords:
- CVSListBox
- AFXVSLISTBOX/CVSListBox
- AFXVSLISTBOX/CVSListBox::CVSListBox
- AFXVSLISTBOX/CVSListBox::AddItem
- AFXVSLISTBOX/CVSListBox::EditItem
- AFXVSLISTBOX/CVSListBox::GetCount
- AFXVSLISTBOX/CVSListBox::GetItemData
- AFXVSLISTBOX/CVSListBox::GetItemText
- AFXVSLISTBOX/CVSListBox::GetSelItem
- AFXVSLISTBOX/CVSListBox::RemoveItem
- AFXVSLISTBOX/CVSListBox::SelectItem
- AFXVSLISTBOX/CVSListBox::SetItemData
- AFXVSLISTBOX/CVSListBox::GetListHwnd
helpviewer_keywords:
- CVSListBox [MFC], CVSListBox
- CVSListBox [MFC], AddItem
- CVSListBox [MFC], EditItem
- CVSListBox [MFC], GetCount
- CVSListBox [MFC], GetItemData
- CVSListBox [MFC], GetItemText
- CVSListBox [MFC], GetSelItem
- CVSListBox [MFC], RemoveItem
- CVSListBox [MFC], SelectItem
- CVSListBox [MFC], SetItemData
- CVSListBox [MFC], GetListHwnd
ms.assetid: c79be7b4-46ed-4af8-a41e-68962782d8ef
ms.openlocfilehash: fb12f17aec43653931343e80926d59560d879c3a
ms.sourcegitcommit: 9e891eb17b73d98f9086d9d4bfe9ca50415d9a37
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 11/20/2018
ms.locfileid: "52176206"
---
# <a name="cvslistbox-class"></a>Classe CVSListBox

O `CVSListBox` classe dá suporte a um controle de lista editável.

## <a name="syntax"></a>Sintaxe

```
class CVSListBox : public CVSListBoxBase
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores Públicos

|Nome|Descrição|
|----------|-----------------|
|[CVSListBox::CVSListBox](#cvslistbox)|Constrói um objeto `CVSListBox`.|
|`CVSListBox::~CVSListBox`|Destruidor.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CVSListBox::AddItem](#additem)|Adiciona uma cadeia de caracteres para um controle de lista. (Substitui `CVSListBoxBase::AddItem`.)|
|[CVSListBox::EditItem](#edititem)|Inicia uma operação de edição no texto de um item de controle de lista. (Substitui `CVSListBoxBase::EditItem`.)|
|[CVSListBox::GetCount](#getcount)|Recupera o número de cadeias de caracteres em um controle de lista editável. (Substitui `CVSListBoxBase::GetCount`.)|
|[CVSListBox::GetItemData](#getitemdata)|Recupera um valor de 32 bits específicos do aplicativo que está associado um item de controle de lista editável. (Substitui `CVSListBoxBase::GetItemData`.)|
|[CVSListBox::GetItemText](#getitemtext)|Recupera o texto de um item de controle de lista editável. (Substitui `CVSListBoxBase::GetItemText`.)|
|[CVSListBox::GetSelItem](#getselitem)|Recupera o índice baseado em zero do item atualmente selecionado em um controle de lista editável. (Substitui `CVSListBoxBase::GetSelItem`.)|
|`CVSListBox::PreTranslateMessage`|Converte as mensagens da janela antes de serem expedidas para o [TranslateMessage](/windows/desktop/api/winuser/nf-winuser-translatemessage) e [DispatchMessage](/windows/desktop/api/winuser/nf-winuser-dispatchmessage) funções do Windows. Para obter mais informações e a sintaxe de método, consulte [CWnd::PreTranslateMessage](../../mfc/reference/cwnd-class.md#pretranslatemessage). (Substitui `CVSListBoxBase::PreTranslateMessage`.)|
|[CVSListBox::RemoveItem](#removeitem)|Remove um item de um controle de lista editável. (Substitui `CVSListBoxBase::RemoveItem`.)|
|[CVSListBox::SelectItem](#selectitem)|Seleciona uma cadeia de caracteres de controle de lista editável. (Substitui `CVSListBoxBase::SelectItem`.)|
|[CVSListBox::SetItemData](#setitemdata)|Associa um valor de 32 bits específicos do aplicativo com um item de controle de lista editável. (Substitui `CVSListBoxBase::SetItemData`.)|

### <a name="protected-methods"></a>Métodos Protegidos

|Nome|Descrição|
|----------|-----------------|
|[CVSListBox::GetListHwnd](#getlisthwnd)|Retorna o identificador para o controle de exibição de lista inserida atual.|

## <a name="remarks"></a>Comentários

O `CVSListBox` classe fornece um conjunto de botões de edição que permitem ao usuário criar, modificar, excluir ou reorganizar os itens em um controle de lista.

A seguir está uma imagem do controle de lista editável. A segunda entrada da lista, que é intitulada "Item2", é selecionada para edição.

![Controle CVSListBox](../../mfc/reference/media/cvslistbox.png "controle CVSListBox")

Se você usar o editor de recurso para adicionar um controle de lista editável, observe que o **caixa de ferramentas** painel do editor não oferece um controle de lista editável predefinida. Em vez disso, adicione um controle estático, como o **caixa de grupo** controle. A estrutura usa o controle estático como um espaço reservado para especificar o tamanho e posição do controle de lista editável.

Para usar um controle de lista editável em um modelo de caixa de diálogo, declare um `CVSListBox` variável em sua classe de caixa de diálogo. Para oferecer suporte a troca de dados entre a variável e o controle, defina uma `DDX_Control` entrada de macro no `DoDataExchange` método da caixa de diálogo. Por padrão, o controle de lista editável é criado sem botões de edição. Use o método CVSListBoxBase::SetStandardButtons herdado para habilitar os botões de edição.

Para obter mais informações, consulte o diretório de exemplos, o `New Controls` de exemplo, os arquivos Page3.cpp e Page3.h.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[CObject](../../mfc/reference/cobject-class.md)

[CCmdTarget](../../mfc/reference/ccmdtarget-class.md)

[CWnd](../../mfc/reference/cwnd-class.md)

[CStatic](../../mfc/reference/cstatic-class.md)

`CVSListBoxBase`

[CVSListBox](../../mfc/reference/cvslistbox-class.md)

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxvslistbox.h

##  <a name="additem"></a>  CVSListBox::AddItem

Adiciona uma cadeia de caracteres para um controle de lista.

```
virtual int AddItem(
    const CString& strIext,
    DWORD_PTR dwData=0,
    int iIndex=-1);
```

### <a name="parameters"></a>Parâmetros

*strIext*<br/>
[in] Uma referência a uma cadeia de caracteres.

*dwData*<br/>
[in] Um valor de 32 bits específicos do aplicativo que está associado com a cadeia de caracteres. O valor padrão é 0.

*iIndex*<br/>
[in] O índice baseado em zero da posição que conterá a cadeia de caracteres. Se o *iIndex* parâmetro for -1, a cadeia de caracteres é adicionada ao final da lista. O valor padrão é -1.

### <a name="return-value"></a>Valor de retorno

O índice baseado em zero da posição da cadeia de caracteres no controle de lista.

### <a name="remarks"></a>Comentários

Use o [CVSListBox::GetItemData](#getitemdata) método para recuperar o valor especificado pelo *dwData* parâmetro. Esse valor pode ser um inteiro de específicos do aplicativo ou um ponteiro para outros dados.

##  <a name="cvslistbox"></a>  CVSListBox::CVSListBox

Constrói um objeto `CVSListBox`.

```
CVSListBox();
```

### <a name="return-value"></a>Valor de retorno

### <a name="remarks"></a>Comentários

##  <a name="edititem"></a>  CVSListBox::EditItem

Inicia uma operação de edição no texto de um item de controle de lista.

```
virtual BOOL EditItem(int iIndex);
```

### <a name="parameters"></a>Parâmetros

*iIndex*<br/>
[in] Índice baseado em zero de um item de controle de lista.

### <a name="return-value"></a>Valor de retorno

TRUE se a operação de edição é iniciado com êxito; Caso contrário, FALSE.

### <a name="remarks"></a>Comentários

O usuário inicia uma operação de edição clicando duas vezes o rótulo de um item ou ao pressionar o **F2** ou **barra de espaços** chave quando um item tem o foco.

##  <a name="getcount"></a>  CVSListBox::GetCount

Recupera o número de cadeias de caracteres em um controle de lista editável.

```
virtual int GetCount() const;
```

### <a name="return-value"></a>Valor de retorno

O número de itens no controle de lista.

### <a name="remarks"></a>Comentários

Observe que a contagem é maior do que o valor de índice do último item porque o índice é baseado em zero.

##  <a name="getitemdata"></a>  CVSListBox::GetItemData

Recupera um valor de 32 bits específicos do aplicativo que está associado um item de controle de lista editável.

```
virtual DWORD_PTR GetItemData(int iIndex) const;
```

### <a name="parameters"></a>Parâmetros

*iIndex*<br/>
[in] O índice baseado em zero de um item de controle de lista editável.

### <a name="return-value"></a>Valor de retorno

O valor de 32 bits que está associado com o item especificado.

### <a name="remarks"></a>Comentários

Use o [CVSListBox::SetItemData](#setitemdata) ou [CVSListBox::AddItem](#additem) método para associar o valor de 32 bits com o item de controle de lista. Esse valor pode ser um inteiro de específicos do aplicativo ou um ponteiro para outros dados.

##  <a name="getitemtext"></a>  CVSListBox::GetItemText

Recupera o texto de um item de controle de lista editável.

```
virtual CString GetItemText(int iIndex) const;
```

### <a name="parameters"></a>Parâmetros

*iIndex*<br/>
[in] O índice baseado em zero de um item de controle de lista editável.

### <a name="return-value"></a>Valor de retorno

Um [CString](../../atl-mfc-shared/reference/cstringt-class.md) objeto que contém o texto do item especificado.

### <a name="remarks"></a>Comentários

##  <a name="getlisthwnd"></a>  CVSListBox::GetListHwnd

Retorna o identificador para o controle de exibição de lista inserida atual.

```
virtual HWND GetListHwnd() const;
```

### <a name="return-value"></a>Valor de retorno

Um identificador para o controle de exibição de lista inseridas.

### <a name="remarks"></a>Comentários

Use esse método para recuperar um identificador para o controle de exibição de lista incorporada que dá suporte a `CVSListBox` classe.

##  <a name="getselitem"></a>  CVSListBox::GetSelItem

Recupera o índice baseado em zero do item atualmente selecionado em um controle de lista editável.

```
virtual int GetSelItem() const;
```

### <a name="return-value"></a>Valor de retorno

Se esse método for bem-sucedida, o índice baseado em zero do item selecionado no momento; Caso contrário, -1.

### <a name="remarks"></a>Comentários

##  <a name="removeitem"></a>  CVSListBox::RemoveItem

Remove um item de um controle de lista editável.

```
virtual BOOL RemoveItem(int iIndex);
```

### <a name="parameters"></a>Parâmetros

*iIndex*<br/>
[in] O índice baseado em zero de um item de controle de lista editável.

### <a name="return-value"></a>Valor de retorno

TRUE se o item especificado for removido; Caso contrário, FALSE.

### <a name="remarks"></a>Comentários

##  <a name="selectitem"></a>  CVSListBox::SelectItem

Seleciona uma cadeia de caracteres de controle de lista editável.

```
virtual BOOL SelectItem(int iItem);
```

### <a name="parameters"></a>Parâmetros

*iItem*<br/>
[in] O índice baseado em zero de um item de controle de lista editável.

### <a name="return-value"></a>Valor de retorno

TRUE se esse método for bem-sucedida; Caso contrário, FALSE.

### <a name="remarks"></a>Comentários

Esse método seleciona o item especificado e se for necessário, rola o item na exibição.

##  <a name="setitemdata"></a>  CVSListBox::SetItemData

Associa um valor de 32 bits específicos do aplicativo com um item de controle de lista editável.

```
virtual void SetItemData(
    int iIndex,
    DWORD_PTR dwData);
```

### <a name="parameters"></a>Parâmetros

*iIndex*<br/>
[in] O índice baseado em zero de um item de controle de lista editável.

*dwData*<br/>
[in] Um valor de 32 bits. Esse valor pode ser um inteiro de específicos do aplicativo ou um ponteiro para outros dados.

### <a name="remarks"></a>Comentários

## <a name="see-also"></a>Consulte também

[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classes](../../mfc/reference/mfc-classes.md)
