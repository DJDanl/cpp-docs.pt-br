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
ms.openlocfilehash: 6a33f5b64c5094bfe2ca2ff259b5cd8654058ed3
ms.sourcegitcommit: 389c559918d9bfaf303d262ee5430d787a662e92
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/25/2019
ms.locfileid: "69502228"
---
# <a name="cvslistbox-class"></a>Classe CVSListBox

A `CVSListBox` classe oferece suporte a um controle de lista editável.

## <a name="syntax"></a>Sintaxe

```
class CVSListBox : public CVSListBoxBase
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[CVSListBox::CVSListBox](#cvslistbox)|Constrói um objeto `CVSListBox`.|
|`CVSListBox::~CVSListBox`|Destruidor.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CVSListBox::AddItem](#additem)|Adiciona uma cadeia de caracteres a um controle de lista. (Substitui `CVSListBoxBase::AddItem`.)|
|[CVSListBox::EditItem](#edititem)|Inicia uma operação de edição no texto de um item de controle de lista. (Substitui `CVSListBoxBase::EditItem`.)|
|[CVSListBox::GetCount](#getcount)|Recupera o número de cadeias de caracteres em um controle de lista editável. (Substitui `CVSListBoxBase::GetCount`.)|
|[CVSListBox::GetItemData](#getitemdata)|Recupera um valor de 32 bits específico do aplicativo que está associado a um item de controle de lista editável. (Substitui `CVSListBoxBase::GetItemData`.)|
|[CVSListBox::GetItemText](#getitemtext)|Recupera o texto de um item de controle de lista editável. (Substitui `CVSListBoxBase::GetItemText`.)|
|[CVSListBox::GetSelItem](#getselitem)|Recupera o índice de base zero do item selecionado no momento em um controle de lista editável. (Substitui `CVSListBoxBase::GetSelItem`.)|
|`CVSListBox::PreTranslateMessage`|Traduz mensagens de janela antes de serem expedidas para as funções do Windows [TranslateMessage](/windows/win32/api/winuser/nf-winuser-translatemessage) e [DispatchMessage](/windows/win32/api/winuser/nf-winuser-dispatchmessage) . Para obter mais informações e sintaxe de método, consulte [CWnd::P retranslatemessage](../../mfc/reference/cwnd-class.md#pretranslatemessage). (Substitui `CVSListBoxBase::PreTranslateMessage`.)|
|[CVSListBox::RemoveItem](#removeitem)|Remove um item de um controle de lista editável. (Substitui `CVSListBoxBase::RemoveItem`.)|
|[CVSListBox::SelectItem](#selectitem)|Seleciona uma cadeia de caracteres de controle de lista editável. (Substitui `CVSListBoxBase::SelectItem`.)|
|[CVSListBox::SetItemData](#setitemdata)|Associa um valor de 32 bits específico do aplicativo a um item de controle de lista editável. (Substitui `CVSListBoxBase::SetItemData`.)|

### <a name="protected-methods"></a>Métodos Protegidos

|Nome|Descrição|
|----------|-----------------|
|[CVSListBox::GetListHwnd](#getlisthwnd)|Retorna o identificador para o controle de exibição de lista inserido atual.|

## <a name="remarks"></a>Comentários

A `CVSListBox` classe fornece um conjunto de botões de edição que permitem ao usuário criar, modificar, excluir ou reorganizar os itens em um controle de lista.

Veja a seguir uma imagem do controle de lista editável. A segunda entrada de lista, denominada "Item2", está selecionada para edição.

![Controle CVSListBox](../../mfc/reference/media/cvslistbox.png "Controle CVSListBox")

Se você usar o editor de recursos para adicionar um controle de lista editável, observe que o painel **caixa de ferramentas** do editor não fornece um controle de lista editável predefinido. Em vez disso, adicione um controle estático, como o controle **caixa de grupo** . A estrutura usa o controle estático como um espaço reservado para especificar o tamanho e a posição do controle de lista editável.

Para usar um controle de lista editável em um modelo de caixa de diálogo `CVSListBox` , declare uma variável na sua classe de caixa de diálogo. Para dar suporte à troca de dados entre a variável e o controle `DDX_Control` , defina uma entrada `DoDataExchange` de macro no método da caixa de diálogo. Por padrão, o controle de lista editável é criado sem botões de edição. Use o método herdado CVSListBoxBase:: SetStandardButtons para habilitar os botões de edição.

Para obter mais informações, consulte o diretório de exemplos `New Controls` , o exemplo, os arquivos page3. cpp e page3. h.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[CObject](../../mfc/reference/cobject-class.md)

[CCmdTarget](../../mfc/reference/ccmdtarget-class.md)

[CWnd](../../mfc/reference/cwnd-class.md)

[CStatic](../../mfc/reference/cstatic-class.md)

`CVSListBoxBase`

[CVSListBox](../../mfc/reference/cvslistbox-class.md)

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxvslistbox. h

##  <a name="additem"></a>  CVSListBox::AddItem

Adiciona uma cadeia de caracteres a um controle de lista.

```
virtual int AddItem(
    const CString& strIext,
    DWORD_PTR dwData=0,
    int iIndex=-1);
```

### <a name="parameters"></a>Parâmetros

*strIext*<br/>
no Uma referência a uma cadeia de caracteres.

*dwData*<br/>
no Um valor de 32 bits específico do aplicativo que está associado à cadeia de caracteres. O valor padrão é 0.

*iIndex*<br/>
no O índice de base zero da posição que irá conter a cadeia de caracteres. Se o parâmetro *iIndex* for-1, a cadeia de caracteres será adicionada ao final da lista. O valor padrão é -1.

### <a name="return-value"></a>Valor de retorno

O índice de base zero da posição da cadeia de caracteres no controle de lista.

### <a name="remarks"></a>Comentários

Use o método [CVSListBox:: GetItemData](#getitemdata) para recuperar o valor especificado pelo parâmetro *dwData* . Esse valor pode ser um inteiro específico do aplicativo ou um ponteiro para outros dados.

##  <a name="cvslistbox"></a>CVSListBox::CVSListBox

Constrói um objeto `CVSListBox`.

```
CVSListBox();
```

### <a name="return-value"></a>Valor de retorno

### <a name="remarks"></a>Comentários

##  <a name="edititem"></a>CVSListBox::EditItem

Inicia uma operação de edição no texto de um item de controle de lista.

```
virtual BOOL EditItem(int iIndex);
```

### <a name="parameters"></a>Parâmetros

*iIndex*<br/>
no Índice de base zero de um item de controle de lista.

### <a name="return-value"></a>Valor de retorno

TRUE se a operação de edição iniciar com êxito; caso contrário, FALSE.

### <a name="remarks"></a>Comentários

O usuário inicia uma operação de edição clicando duas vezes no rótulo de um item ou pressionando a tecla **F2** ou a **barra de espaços** quando um item tem o foco.

##  <a name="getcount"></a>CVSListBox:: GetCount

Recupera o número de cadeias de caracteres em um controle de lista editável.

```
virtual int GetCount() const;
```

### <a name="return-value"></a>Valor de retorno

O número de itens no controle de lista.

### <a name="remarks"></a>Comentários

Observe que a contagem é uma maior que o valor de índice do último item, pois o índice é baseado em zero.

##  <a name="getitemdata"></a>  CVSListBox::GetItemData

Recupera um valor de 32 bits específico do aplicativo que está associado a um item de controle de lista editável.

```
virtual DWORD_PTR GetItemData(int iIndex) const;
```

### <a name="parameters"></a>Parâmetros

*iIndex*<br/>
no O índice de base zero de um item de controle de lista editável.

### <a name="return-value"></a>Valor de retorno

O valor de 32 bits que está associado ao item especificado.

### <a name="remarks"></a>Comentários

Use o método [CVSListBox:: SetItemData](#setitemdata) ou [CVSListBox:: AddItem](#additem) para associar o valor de 32 bits ao item de controle de lista. Esse valor pode ser um inteiro específico do aplicativo ou um ponteiro para outros dados.

##  <a name="getitemtext"></a>  CVSListBox::GetItemText

Recupera o texto de um item de controle de lista editável.

```
virtual CString GetItemText(int iIndex) const;
```

### <a name="parameters"></a>Parâmetros

*iIndex*<br/>
no O índice de base zero de um item de controle de lista editável.

### <a name="return-value"></a>Valor de retorno

Um objeto [CString](../../atl-mfc-shared/reference/cstringt-class.md) que contém o texto do item especificado.

### <a name="remarks"></a>Comentários

##  <a name="getlisthwnd"></a>  CVSListBox::GetListHwnd

Retorna o identificador para o controle de exibição de lista inserido atual.

```
virtual HWND GetListHwnd() const;
```

### <a name="return-value"></a>Valor de retorno

Um identificador para o controle de exibição de lista inserido.

### <a name="remarks"></a>Comentários

Use este método para recuperar um identificador para o controle de exibição de lista inserido que `CVSListBox` oferece suporte à classe.

##  <a name="getselitem"></a>  CVSListBox::GetSelItem

Recupera o índice de base zero do item selecionado no momento em um controle de lista editável.

```
virtual int GetSelItem() const;
```

### <a name="return-value"></a>Valor de retorno

Se esse método for bem-sucedido, o índice de base zero do item selecionado no momento; caso contrário,-1.

### <a name="remarks"></a>Comentários

##  <a name="removeitem"></a>  CVSListBox::RemoveItem

Remove um item de um controle de lista editável.

```
virtual BOOL RemoveItem(int iIndex);
```

### <a name="parameters"></a>Parâmetros

*iIndex*<br/>
no O índice de base zero de um item de controle de lista editável.

### <a name="return-value"></a>Valor de retorno

TRUE se o item especificado for removido; caso contrário, FALSE.

### <a name="remarks"></a>Comentários

##  <a name="selectitem"></a>CVSListBox::SelectItem

Seleciona uma cadeia de caracteres de controle de lista editável.

```
virtual BOOL SelectItem(int iItem);
```

### <a name="parameters"></a>Parâmetros

*iItem*<br/>
no O índice de base zero de um item de controle de lista editável.

### <a name="return-value"></a>Valor de retorno

TRUE se esse método for bem-sucedido; caso contrário, FALSE.

### <a name="remarks"></a>Comentários

Esse método seleciona o item especificado e, se necessário, rola o item para a exibição.

##  <a name="setitemdata"></a>  CVSListBox::SetItemData

Associa um valor de 32 bits específico do aplicativo a um item de controle de lista editável.

```
virtual void SetItemData(
    int iIndex,
    DWORD_PTR dwData);
```

### <a name="parameters"></a>Parâmetros

*iIndex*<br/>
no O índice de base zero de um item de controle de lista editável.

*dwData*<br/>
no Um valor de 32 bits. Esse valor pode ser um inteiro específico do aplicativo ou um ponteiro para outros dados.

### <a name="remarks"></a>Comentários

## <a name="see-also"></a>Consulte também

[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classes](../../mfc/reference/mfc-classes.md)
