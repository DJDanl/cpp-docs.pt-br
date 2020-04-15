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
ms.openlocfilehash: 4ea48a263a01133419067979ee5fa3e62105c7f5
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81373188"
---
# <a name="cvslistbox-class"></a>Classe CVSListBox

A `CVSListBox` classe suporta um controle de lista editável.

## <a name="syntax"></a>Sintaxe

```
class CVSListBox : public CVSListBoxBase
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[Caixa de cvslist::CVSListBox](#cvslistbox)|Constrói um objeto `CVSListBox`.|
|`CVSListBox::~CVSListBox`|Destruidor.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CVSListBox::AddItem](#additem)|Adiciona uma seqüência a um controle de lista. (Substitui `CVSListBoxBase::AddItem`.)|
|[CVSListBox::EditItem](#edititem)|Inicia uma operação de edição no texto de um item de controle de lista. (Substitui `CVSListBoxBase::EditItem`.)|
|[CAIXA DE CVSList::Contagem de contatos](#getcount)|Recupera o número de strings em um controle de lista editável. (Substitui `CVSListBoxBase::GetCount`.)|
|[CVSListBox::GetItemData](#getitemdata)|Recupera um valor específico de 32 bits específico do aplicativo que está associado a um item de controle de lista editável. (Substitui `CVSListBoxBase::GetItemData`.)|
|[CVSListBox::GetItemText](#getitemtext)|Recupera o texto de um item de controle de lista editável. (Substitui `CVSListBoxBase::GetItemText`.)|
|[CVSListBox::GetSelItem](#getselitem)|Recupera o índice baseado em zero do item selecionado no momento em um controle de lista editável. (Substitui `CVSListBoxBase::GetSelItem`.)|
|`CVSListBox::PreTranslateMessage`|Traduz mensagens de janela antes de serem enviadas para as funções [TranslateMessage](/windows/win32/api/winuser/nf-winuser-translatemessage) e [DispatchMessage](/windows/win32/api/winuser/nf-winuser-dispatchmessage) Windows. Para obter mais informações e sintaxe do método, consulte [CWnd::PreTranslateMessage](../../mfc/reference/cwnd-class.md#pretranslatemessage). (Substitui `CVSListBoxBase::PreTranslateMessage`.)|
|[CVSListBox::RemoveItem](#removeitem)|Remove um item de um controle de lista editável. (Substitui `CVSListBoxBase::RemoveItem`.)|
|[CVSListBox::SelectItem](#selectitem)|Seleciona uma seqüência de controle de lista editável. (Substitui `CVSListBoxBase::SelectItem`.)|
|[CVSListBox::SetItemData](#setitemdata)|Associa um valor específico de aplicativo de 32 bits com um item de controle de lista editável. (Substitui `CVSListBoxBase::SetItemData`.)|

### <a name="protected-methods"></a>Métodos Protegidos

|Nome|Descrição|
|----------|-----------------|
|[CVSListBox::GetListHwnd](#getlisthwnd)|Retorna a alça ao controle de exibição de lista incorporado atual.|

## <a name="remarks"></a>Comentários

A `CVSListBox` classe fornece um conjunto de botões de edição que permitem ao usuário criar, modificar, excluir ou reorganizar os itens em um controle de lista.

A seguir está uma imagem do controle de lista editável. A segunda entrada da lista, intitulada "Item2", é selecionada para edição.

![Controle CVSListBox](../../mfc/reference/media/cvslistbox.png "Controle CVSListBox")

Se você usar o editor de recursos para adicionar um controle de lista editável, observe que o painel **Toolbox** do editor não fornece um controle de lista editável predefinido. Em vez disso, adicione um controle estático, como o controle **Da Caixa de Grupo.** A estrutura usa o controle estático como um espaço reservado para especificar o tamanho e a posição do controle de lista editável.

Para usar um controle de lista editável `CVSListBox` em um modelo de caixa de diálogo, declare uma variável na classe da caixa de diálogo. Para apoiar a troca de dados entre `DDX_Control` a variável `DoDataExchange` e o controle, defina uma entrada macro no método da caixa de diálogo. Por padrão, o controle de lista editável é criado sem botões de edição. Use o método HERDado CVSListBoxBase::SetStandardButtons para ativar os botões de edição.

Para obter mais informações, consulte `New Controls` o diretório Amostras, a amostra, os arquivos Page3.cpp e Page3.h.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[Cobject](../../mfc/reference/cobject-class.md)

[Ccmdtarget](../../mfc/reference/ccmdtarget-class.md)

[CWnd](../../mfc/reference/cwnd-class.md)

[Cstatic](../../mfc/reference/cstatic-class.md)

`CVSListBoxBase`

[Cvslistbox](../../mfc/reference/cvslistbox-class.md)

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxvslistbox.h

## <a name="cvslistboxadditem"></a><a name="additem"></a>CVSListBox::AddItem

Adiciona uma seqüência a um controle de lista.

```
virtual int AddItem(
    const CString& strIext,
    DWORD_PTR dwData=0,
    int iIndex=-1);
```

### <a name="parameters"></a>Parâmetros

*strIext*<br/>
[em] Uma referência a uma corda.

*Dwdata*<br/>
[em] Um valor específico de aplicativo de 32 bits que está associado à string. O valor padrão é 0.

*Iindex*<br/>
[em] O índice baseado em zero da posição que segurará a string. Se o parâmetro *iIndex* for -1, a seqüência será adicionada ao final da lista. O valor padrão é -1.

### <a name="return-value"></a>Valor retornado

O índice baseado em zero da posição da string no controle de lista.

### <a name="remarks"></a>Comentários

Use o método [CVSListBox::GetItemData](#getitemdata) para recuperar o valor especificado pelo parâmetro *dwData.* Esse valor pode ser um inteiro específico de aplicativo ou um ponteiro para outros dados.

## <a name="cvslistboxcvslistbox"></a><a name="cvslistbox"></a>Caixa de cvslist::CVSListBox

Constrói um objeto `CVSListBox`.

```
CVSListBox();
```

### <a name="return-value"></a>Valor retornado

### <a name="remarks"></a>Comentários

## <a name="cvslistboxedititem"></a><a name="edititem"></a>CVSListBox::EditItem

Inicia uma operação de edição no texto de um item de controle de lista.

```
virtual BOOL EditItem(int iIndex);
```

### <a name="parameters"></a>Parâmetros

*Iindex*<br/>
[em] Índice baseado em zero de um item de controle de lista.

### <a name="return-value"></a>Valor retornado

TRUE se a operação de edição for iniciada com sucesso; caso contrário, FALSE.

### <a name="remarks"></a>Comentários

O usuário inicia uma operação de edição clicando duas vezes na etiqueta de um item ou pressionando a tecla **F2** ou **SPACEBAR** quando um item tem o foco.

## <a name="cvslistboxgetcount"></a><a name="getcount"></a>CAIXA DE CVSList::Contagem de contatos

Recupera o número de strings em um controle de lista editável.

```
virtual int GetCount() const;
```

### <a name="return-value"></a>Valor retornado

O número de itens no controle da lista.

### <a name="remarks"></a>Comentários

Observe que a contagem é maior que o valor do índice do último item porque o índice é baseado em zero.

## <a name="cvslistboxgetitemdata"></a><a name="getitemdata"></a>CVSListBox::GetItemData

Recupera um valor específico de 32 bits específico do aplicativo que está associado a um item de controle de lista editável.

```
virtual DWORD_PTR GetItemData(int iIndex) const;
```

### <a name="parameters"></a>Parâmetros

*Iindex*<br/>
[em] O índice baseado em zero de um item de controle de lista editável.

### <a name="return-value"></a>Valor retornado

O valor de 32 bits que está associado ao item especificado.

### <a name="remarks"></a>Comentários

Use o [método CVSListBox::SetItemData](#setitemdata) ou [CVSListBox::AddItem](#additem) para associar o valor de 32 bits ao item de controle de lista. Esse valor pode ser um inteiro específico de aplicativo ou um ponteiro para outros dados.

## <a name="cvslistboxgetitemtext"></a><a name="getitemtext"></a>CVSListBox::GetItemText

Recupera o texto de um item de controle de lista editável.

```
virtual CString GetItemText(int iIndex) const;
```

### <a name="parameters"></a>Parâmetros

*Iindex*<br/>
[em] O índice baseado em zero de um item de controle de lista editável.

### <a name="return-value"></a>Valor retornado

Um objeto [CString](../../atl-mfc-shared/reference/cstringt-class.md) que contém o texto do item especificado.

### <a name="remarks"></a>Comentários

## <a name="cvslistboxgetlisthwnd"></a><a name="getlisthwnd"></a>CVSListBox::GetListHwnd

Retorna a alça ao controle de exibição de lista incorporado atual.

```
virtual HWND GetListHwnd() const;
```

### <a name="return-value"></a>Valor retornado

Uma alça para o controle de exibição de lista incorporada.

### <a name="remarks"></a>Comentários

Use este método para recuperar uma alça no controle `CVSListBox` de exibição de lista incorporado que suporta a classe.

## <a name="cvslistboxgetselitem"></a><a name="getselitem"></a>CVSListBox::GetSelItem

Recupera o índice baseado em zero do item selecionado no momento em um controle de lista editável.

```
virtual int GetSelItem() const;
```

### <a name="return-value"></a>Valor retornado

Se esse método for bem sucedido, o índice baseado em zero do item selecionado no momento; caso contrário, -1.

### <a name="remarks"></a>Comentários

## <a name="cvslistboxremoveitem"></a><a name="removeitem"></a>CVSListBox::RemoveItem

Remove um item de um controle de lista editável.

```
virtual BOOL RemoveItem(int iIndex);
```

### <a name="parameters"></a>Parâmetros

*Iindex*<br/>
[em] O índice baseado em zero de um item de controle de lista editável.

### <a name="return-value"></a>Valor retornado

TRUE se o item especificado for removido; caso contrário, FALSE.

### <a name="remarks"></a>Comentários

## <a name="cvslistboxselectitem"></a><a name="selectitem"></a>CVSListBox::SelectItem

Seleciona uma seqüência de controle de lista editável.

```
virtual BOOL SelectItem(int iItem);
```

### <a name="parameters"></a>Parâmetros

*Iitem*<br/>
[em] O índice baseado em zero de um item de controle de lista editável.

### <a name="return-value"></a>Valor retornado

VERDADE se este método for bem sucedido; caso contrário, FALSE.

### <a name="remarks"></a>Comentários

Este método seleciona o item especificado e, se necessário, rola o item para a exibição.

## <a name="cvslistboxsetitemdata"></a><a name="setitemdata"></a>CVSListBox::SetItemData

Associa um valor específico de aplicativo de 32 bits com um item de controle de lista editável.

```
virtual void SetItemData(
    int iIndex,
    DWORD_PTR dwData);
```

### <a name="parameters"></a>Parâmetros

*Iindex*<br/>
[em] O índice baseado em zero de um item de controle de lista editável.

*Dwdata*<br/>
[em] Um valor de 32 bits. Esse valor pode ser um inteiro específico de aplicativo ou um ponteiro para outros dados.

### <a name="remarks"></a>Comentários

## <a name="see-also"></a>Confira também

[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classes](../../mfc/reference/mfc-classes.md)
