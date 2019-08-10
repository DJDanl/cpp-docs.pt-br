---
title: Classe CShellManager
ms.date: 11/04/2016
f1_keywords:
- CShellManager
- AFXSHELLMANAGER/CShellManager
- AFXSHELLMANAGER/CShellManager::CShellManager
- AFXSHELLMANAGER/CShellManager::BrowseForFolder
- AFXSHELLMANAGER/CShellManager::ConcatenateItem
- AFXSHELLMANAGER/CShellManager::CopyItem
- AFXSHELLMANAGER/CShellManager::CreateItem
- AFXSHELLMANAGER/CShellManager::FreeItem
- AFXSHELLMANAGER/CShellManager::GetItemCount
- AFXSHELLMANAGER/CShellManager::GetItemSize
- AFXSHELLMANAGER/CShellManager::GetNextItem
- AFXSHELLMANAGER/CShellManager::GetParentItem
- AFXSHELLMANAGER/CShellManager::ItemFromPath
helpviewer_keywords:
- CShellManager [MFC], CShellManager
- CShellManager [MFC], BrowseForFolder
- CShellManager [MFC], ConcatenateItem
- CShellManager [MFC], CopyItem
- CShellManager [MFC], CreateItem
- CShellManager [MFC], FreeItem
- CShellManager [MFC], GetItemCount
- CShellManager [MFC], GetItemSize
- CShellManager [MFC], GetNextItem
- CShellManager [MFC], GetParentItem
- CShellManager [MFC], ItemFromPath
ms.assetid: f15c4c1a-6fae-487d-9913-9b7369b33da0
ms.openlocfilehash: 14e8da573621f712ae9e27647122d305be54b7b0
ms.sourcegitcommit: 46d24d6e70c03e05484923d9efc6ed5150e96a64
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/09/2019
ms.locfileid: "68916692"
---
# <a name="cshellmanager-class"></a>Classe CShellManager

Implementa vários métodos que permitem trabalhar com ponteiros para listas de identificadores (PIDLs).

## <a name="syntax"></a>Sintaxe

```
class CShellManager : public CObject
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[CShellManager::CShellManager](#cshellmanager)|Constrói um objeto `CShellManager`.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CShellManager::BrowseForFolder](#browseforfolder)|Exibe uma caixa de diálogo que permite ao usuário selecionar uma pasta do Shell.|
|[CShellManager::ConcatenateItem](#concatenateitem)|Concatena dois PIDLs.|
|[CShellManager::CopyItem](#copyitem)|Cria um novo PIDL e copia o PIDL fornecido para ele.|
|[CShellManager::CreateItem](#createitem)|Cria um novo PIDL do tamanho especificado.|
|[CShellManager::FreeItem](#freeitem)|Exclui o PIDL fornecido.|
|[CShellManager::GetItemCount](#getitemcount)|Retorna o número de itens no PIDL fornecido.|
|[CShellManager::GetItemSize](#getitemsize)|Retorna o tamanho do PIDL fornecido.|
|[CShellManager::GetNextItem](#getnextitem)|Retorna o próximo item do PIDL.|
|[CShellManager::GetParentItem](#getparentitem)|Recupera o item pai do item fornecido.|
|[CShellManager::ItemFromPath](#itemfrompath)|Recupera o PIDL para o item identificado pelo caminho fornecido.|

## <a name="remarks"></a>Comentários

Todos os métodos da `CShellManager` classe lidam com PIDLs. Um PIDL é um identificador exclusivo para um objeto Shell.

Você não deve criar um `CShellManager` objeto manualmente. Ele será criado automaticamente pela estrutura do seu aplicativo. No entanto, você deve chamar [CWinAppEx:: InitShellManager](../../mfc/reference/cwinappex-class.md#initshellmanager) durante o processo de inicialização do seu aplicativo. Para obter um ponteiro para o Gerenciador de Shell para seu aplicativo, chame [CWinAppEx::](../../mfc/reference/cwinappex-class.md#getshellmanager)GetShellManager.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[CObject](../../mfc/reference/cobject-class.md)

[CShellManager](../../mfc/reference/cshellmanager-class.md)

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxshellmanager. h

##  <a name="browseforfolder"></a>  CShellManager::BrowseForFolder

Exibe uma caixa de diálogo que permite ao usuário selecionar uma pasta do Shell.

```
BOOL BrowseForFolder(
    CString& strOutFolder,
    CWnd* pWndParent = NULL,
    LPCTSTR lplszInitialFolder = NULL,
    LPCTSTR lpszTitle = NULL,
    UINT ulFlags = BIF_RETURNONLYFSDIRS,
    LPINT piFolderImage = NULL);
```

### <a name="parameters"></a>Parâmetros

*strOutFolder*<br/>
fora A cadeia de caracteres usada pelo método para armazenar o caminho da pasta selecionada.

*pWndParent*<br/>
no Um ponteiro para a janela pai.

*lplszInitialFolder*<br/>
no Uma cadeia de caracteres que contém a pasta selecionada por padrão quando a caixa de diálogo é exibida.

*lpszTitle*<br/>
no O título da caixa de diálogo.

*ulFlags*<br/>
no Sinalizadores que especificam opções para a caixa de diálogo. Consulte [BROWSEINFO](/windows/desktop/api/shlobj_core/ns-shlobj_core-browseinfoa) para obter a descrição detalhada.

*piFolderImage*<br/>
fora Um ponteiro para o valor inteiro em que o método grava o índice de imagem da pasta selecionada.

### <a name="return-value"></a>Valor de retorno

Diferente de zero se o usuário selecionar uma pasta na caixa de diálogo; caso contrário, 0.

### <a name="remarks"></a>Comentários

Quando você chama esse método, o aplicativo cria e mostra uma caixa de diálogo que permite ao usuário selecionar uma pasta. O método irá gravar o caminho da pasta no parâmetro *strOutFolder* .

### <a name="example"></a>Exemplo

O exemplo a seguir demonstra como recuperar uma referência a um `CShellManager` objeto usando o `CWinAppEx::GetShellManager` método e como usar o `BrowseForFolder` método. Este trecho de código faz parte do [exemplo do Explorer](../../overview/visual-cpp-samples.md).

[!code-cpp[NVC_MFC_Explorer#6](../../mfc/reference/codesnippet/cpp/cshellmanager-class_1.cpp)]

##  <a name="concatenateitem"></a>  CShellManager::ConcatenateItem

Cria uma nova lista contendo duas PIDLs.

```
LPITEMIDLIST ConcatenateItem(
    LPCITEMIDLIST pidl1,
    LPCITEMIDLIST pidl2);
```

### <a name="parameters"></a>Parâmetros

*pidl1*<br/>
no O primeiro item.

*pidl2*<br/>
no O segundo item.

### <a name="return-value"></a>Valor de retorno

Um ponteiro para a nova lista de itens se a função tiver sucesso, caso contrário, NULL.

### <a name="remarks"></a>Comentários

Esse método cria uma nova [ITEMIDLIST](/windows/desktop/api/shtypes/ns-shtypes-itemidlist) grande o suficiente para conter *pidl1* e *pidl2*. Em seguida, ele copia *pidl1* e *pidl2* para a nova lista.

##  <a name="copyitem"></a>  CShellManager::CopyItem

Copia uma lista de itens.

```
LPITEMIDLIST CopyItem(LPCITEMIDLIST pidlSource);
```

### <a name="parameters"></a>Parâmetros

*pidlSource*<br/>
no A lista de itens original.

### <a name="return-value"></a>Valor de retorno

Um ponteiro para a lista de itens recém-criada se for bem-sucedido; caso contrário, NULL.

### <a name="remarks"></a>Comentários

A lista de itens recém-criadas tem o mesmo tamanho da lista de itens de origem.

##  <a name="createitem"></a>  CShellManager::CreateItem

Cria um novo PIDL.

```
LPITEMIDLIST CreateItem(UINT cbSize);
```

### <a name="parameters"></a>Parâmetros

*cbSize*<br/>
no O tamanho da lista de itens.

### <a name="return-value"></a>Valor de retorno

Um ponteiro para a lista de itens criados se for bem-sucedido; caso contrário, NULL.

##  <a name="cshellmanager"></a>  CShellManager::CShellManager

Constrói um objeto `CShellManager`.

```
CShellManager();
```

### <a name="remarks"></a>Comentários

Na maioria dos casos, você não precisa criar um `CShellManager` diretamente. Por padrão, a estrutura cria uma para você. Para obter um ponteiro para o `CShellManager`, chame [CWinAppEx::](../../mfc/reference/cwinappex-class.md#getshellmanager)GetShellManager. Se você criar um `CShellManager` manualmente, deverá inicializá-lo com o método [CWinAppEx:: InitShellManager](../../mfc/reference/cwinappex-class.md#initshellmanager).

##  <a name="freeitem"></a>  CShellManager::FreeItem

Exclui uma lista de itens.

```
void FreeItem(LPITEMIDLIST pidl);
```

### <a name="parameters"></a>Parâmetros

*pidl*<br/>
no Uma lista de itens a ser excluída.

##  <a name="getitemcount"></a>  CShellManager::GetItemCount

Retorna o número de itens em uma lista de itens.

```
UINT GetItemCount(LPCITEMIDLIST pidl);
```

### <a name="parameters"></a>Parâmetros

*pidl*<br/>
no Um ponteiro para uma lista de itens.

### <a name="return-value"></a>Valor de retorno

O número de itens na lista de itens.

##  <a name="getitemsize"></a>  CShellManager::GetItemSize

Retorna o tamanho de uma lista de itens.

```
UINT GetItemSize(LPCITEMIDLIST pidl);
```

### <a name="parameters"></a>Parâmetros

*pidl*<br/>
no Um ponteiro para uma lista de itens.

### <a name="return-value"></a>Valor de retorno

O tamanho da lista de itens.

##  <a name="getnextitem"></a>  CShellManager::GetNextItem

Recupera o próximo item de um ponteiro para uma lista de identificadores de item (PIDL).

```
LPITEMIDLIST GetNextItem(LPCITEMIDLIST pidl);
```

### <a name="parameters"></a>Parâmetros

*pidl*<br/>
no A lista de itens a iterar.

### <a name="return-value"></a>Valor de retorno

Um ponteiro para o próximo item da lista.

### <a name="remarks"></a>Comentários

Se não houver mais itens na lista, esse método retornará NULL.

##  <a name="getparentitem"></a>  CShellManager::GetParentItem

Recupera o pai de um ponteiro para uma lista de identificadores de item (PIDL).

```
int GetParentItem(
    LPCITEMIDLIST lpidl,
    LPITEMIDLIST& lpidlParent);
```

### <a name="parameters"></a>Parâmetros

*lpidl*<br/>
no Um PIDL cujo pai será recuperado.

*lpidlParent*<br/>
fora Uma referência a um PIDL onde o método irá armazenar o resultado.

### <a name="return-value"></a>Valor de retorno

O nível do PIDL pai.

### <a name="remarks"></a>Comentários

O nível de um PIDL é relativo à área de trabalho. O PIDL da área de trabalho é considerado com um nível de 0.

##  <a name="itemfrompath"></a>  CShellManager::ItemFromPath

Recupera o ponteiro para uma lista de identificadores de item (PIDL) do item identificado por um caminho de cadeia de caracteres.

```
HRESULT ItemFromPath(
    LPCTSTR lpszPath,
    LPITEMIDLIST& pidl);
```

### <a name="parameters"></a>Parâmetros

*lpszPath*<br/>
no Uma cadeia de caracteres que especifica o caminho para o item.

*pidl*<br/>
fora Uma referência a um PIDL. O método usa esse PIDL para armazenar o ponteiro para seu valor de retorno.

### <a name="return-value"></a>Valor de retorno

Retorna NOERROR se for bem-sucedido; um valor de erro definido por OLE.

## <a name="see-also"></a>Consulte também

[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classes](../../mfc/reference/mfc-classes.md)
