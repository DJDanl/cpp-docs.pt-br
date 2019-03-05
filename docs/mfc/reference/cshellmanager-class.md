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
ms.openlocfilehash: 3f58492c6adbb6c183d6498e4a58f3ce639d7d18
ms.sourcegitcommit: c3093251193944840e3d0a068ecc30e6449624ba
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/04/2019
ms.locfileid: "57269377"
---
# <a name="cshellmanager-class"></a>Classe CShellManager

Implementa vários métodos que permitem que você trabalhe com ponteiros para listas de identificadores (PIDLs).

## <a name="syntax"></a>Sintaxe

```
class CShellManager : public CObject
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores Públicos

|Nome|Descrição|
|----------|-----------------|
|[CShellManager::CShellManager](#cshellmanager)|Constrói um objeto `CShellManager`.|

### <a name="public-methods"></a>Métodos Públicos

|Nome|Descrição|
|----------|-----------------|
|[CShellManager::BrowseForFolder](#browseforfolder)|Exibe uma caixa de diálogo que permite ao usuário selecionar uma pasta do shell.|
|[CShellManager::ConcatenateItem](#concatenateitem)|Concatena duas PIDLs.|
|[CShellManager::CopyItem](#copyitem)|Cria um novo PIDL e copia o PIDL fornecido a ele.|
|[CShellManager::CreateItem](#createitem)|Cria um novo PIDL do tamanho especificado.|
|[CShellManager::FreeItem](#freeitem)|Exclui o PIDL fornecido.|
|[CShellManager::GetItemCount](#getitemcount)|Retorna o número de itens no PIDL fornecido.|
|[CShellManager::GetItemSize](#getitemsize)|Retorna o tamanho do PIDL fornecido.|
|[CShellManager::GetNextItem](#getnextitem)|Retorna o próximo item do PIDL.|
|[CShellManager::GetParentItem](#getparentitem)|Recupera o item pai do item fornecido.|
|[CShellManager::ItemFromPath](#itemfrompath)|Recupera o PIDL para o item identificado pelo caminho fornecido.|

## <a name="remarks"></a>Comentários

Os métodos do `CShellManager` para tratar todos os PIDLs de classe. Um PIDL é um identificador exclusivo para um objeto shell.

Você não deve criar um `CShellManager` objeto manualmente. Ele será criado automaticamente pela estrutura do seu aplicativo. No entanto, você deve chamar [CWinAppEx::InitShellManager](../../mfc/reference/cwinappex-class.md#initshellmanager) durante o processo de inicialização do seu aplicativo. Para obter um ponteiro para o Gerenciador de shell para seu aplicativo, chame [CWinAppEx::GetShellManager](../../mfc/reference/cwinappex-class.md#getshellmanager).

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[CObject](../../mfc/reference/cobject-class.md)

[CShellManager](../../mfc/reference/cshellmanager-class.md)

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxshellmanager.h

##  <a name="browseforfolder"></a>  CShellManager::BrowseForFolder

Exibe uma caixa de diálogo que permite ao usuário selecionar uma pasta do shell.

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
[out] A cadeia de caracteres usada pelo método para armazenar o caminho da pasta selecionada.

*pWndParent*<br/>
[in] Um ponteiro para a janela pai.

*lplszInitialFolder*<br/>
[in] Uma cadeia de caracteres que contém a pasta que é selecionada por padrão, quando a caixa de diálogo é exibida.

*lpszTitle*<br/>
[in] O título da caixa de diálogo.

*ulFlags*<br/>
[in] Sinalizadores que especificam as opções para a caixa de diálogo. Ver [BROWSEINFO](/windows/desktop/api/shlobj_core/ns-shlobj_core-_browseinfoa) para a descrição detalhada.

*piFolderImage*<br/>
[out] Um ponteiro para o valor de inteiro em que o método grava o índice de imagem da pasta selecionada.

### <a name="return-value"></a>Valor de retorno

Diferente de zero se o usuário seleciona uma pasta na caixa de diálogo; Caso contrário, 0.

### <a name="remarks"></a>Comentários

Quando você chama esse método, o aplicativo cria e mostra uma caixa de diálogo que permite que o usuário selecione uma pasta. O método gravará o caminho da pasta para o *strOutFolder* parâmetro.

### <a name="example"></a>Exemplo

O exemplo a seguir demonstra como recuperar uma referência a um `CShellManager` objeto usando o `CWinAppEx::GetShellManager` método e como usar o `BrowseForFolder` método. Este trecho de código faz parte de [amostra do Gerenciador de](../../visual-cpp-samples.md).

[!code-cpp[NVC_MFC_Explorer#6](../../mfc/reference/codesnippet/cpp/cshellmanager-class_1.cpp)]

##  <a name="concatenateitem"></a>  CShellManager::ConcatenateItem

Cria uma nova lista que contém duas PIDLs.

```
LPITEMIDLIST ConcatenateItem(
    LPCITEMIDLIST pidl1,
    LPCITEMIDLIST pidl2);
```

### <a name="parameters"></a>Parâmetros

*pidl1*<br/>
[in] O primeiro item.

*pidl2*<br/>
[in] O segundo item.

### <a name="return-value"></a>Valor de retorno

Um ponteiro para a nova lista de item, se a função for bem-sucedida, caso contrário, nulo.

### <a name="remarks"></a>Comentários

Esse método cria uma nova [ITEMIDLIST](/windows/desktop/api/shtypes/ns-shtypes-_itemidlist) grande o suficiente para conter as duas *pidl1* e *pidl2*. Em seguida, ele copia *pidl1* e *pidl2* para a nova lista.

##  <a name="copyitem"></a>  CShellManager::CopyItem

Copia uma lista de itens.

```
LPITEMIDLIST CopyItem(LPCITEMIDLIST pidlSource);
```

### <a name="parameters"></a>Parâmetros

*pidlSource*<br/>
[in] A lista de item original.

### <a name="return-value"></a>Valor de retorno

Um ponteiro para a lista de itens recentemente criado se bem-sucedido; Caso contrário, nulo.

### <a name="remarks"></a>Comentários

A lista de item recém-criado tem o mesmo tamanho que a lista de itens de origem.

##  <a name="createitem"></a>  CShellManager::CreateItem

Cria um novo PIDL.

```
LPITEMIDLIST CreateItem(UINT cbSize);
```

### <a name="parameters"></a>Parâmetros

*cbSize*<br/>
[in] O tamanho da lista de itens.

### <a name="return-value"></a>Valor de retorno

Um ponteiro para a lista de item criado se bem-sucedido; Caso contrário, nulo.

##  <a name="cshellmanager"></a>  CShellManager::CShellManager

Constrói um objeto `CShellManager`.

```
CShellManager();
```

### <a name="remarks"></a>Comentários

Na maioria dos casos, você não precisa criar um `CShellManager` diretamente. Por padrão, a estrutura criará um para você. Para obter um ponteiro para o `CShellManager`, chame [CWinAppEx::GetShellManager](../../mfc/reference/cwinappex-class.md#getshellmanager). Se você criar uma `CShellManager` manualmente, você deve inicializá-lo com o método [CWinAppEx::InitShellManager](../../mfc/reference/cwinappex-class.md#initshellmanager).

##  <a name="freeitem"></a>  CShellManager::FreeItem

Exclui uma lista de itens.

```
void FreeItem(LPITEMIDLIST pidl);
```

### <a name="parameters"></a>Parâmetros

*pidl*<br/>
[in] Uma lista de itens para excluir.

##  <a name="getitemcount"></a>  CShellManager::GetItemCount

Retorna o número de itens em uma lista de itens.

```
UINT GetItemCount(LPCITEMIDLIST pidl);
```

### <a name="parameters"></a>Parâmetros

*pidl*<br/>
[in] Um ponteiro para uma lista de itens.

### <a name="return-value"></a>Valor de retorno

O número de itens na lista de itens.

##  <a name="getitemsize"></a>  CShellManager::GetItemSize

Retorna o tamanho de uma lista de itens.

```
UINT GetItemSize(LPCITEMIDLIST pidl);
```

### <a name="parameters"></a>Parâmetros

*pidl*<br/>
[in] Um ponteiro para uma lista de itens.

### <a name="return-value"></a>Valor de retorno

O tamanho da lista de itens.

##  <a name="getnextitem"></a>  CShellManager::GetNextItem

Recupera o próximo item de um ponteiro para uma lista de identificadores de item (PIDL).

```
LPITEMIDLIST GetNextItem(LPCITEMIDLIST pidl);
```

### <a name="parameters"></a>Parâmetros

*pidl*<br/>
[in] A lista de itens para iterar.

### <a name="return-value"></a>Valor de retorno

Um ponteiro para o próximo item na lista.

### <a name="remarks"></a>Comentários

Não se houver mais nenhum item na lista, esse método retornará nulo.

##  <a name="getparentitem"></a>  CShellManager::GetParentItem

Recupera o pai de um ponteiro para uma lista de identificadores de item (PIDL).

```
int GetParentItem(
    LPCITEMIDLIST lpidl,
    LPITEMIDLIST& lpidlParent);
```

### <a name="parameters"></a>Parâmetros

*lpidl*<br/>
[in] Um PIDL cujo pai será recuperado.

*lpidlParent*<br/>
[out] Uma referência a um PIDL em que o método armazenará o resultado.

### <a name="return-value"></a>Valor de retorno

O nível do pai PIDL.

### <a name="remarks"></a>Comentários

O nível de um PIDL é em relação à área de trabalho. A área de trabalho PIDL é considerado para ter um nível 0.

##  <a name="itemfrompath"></a>  CShellManager::ItemFromPath

Recupera o ponteiro para uma lista de identificadores de item (PIDL) do item identificado por um caminho de cadeia de caracteres.

```
HRESULT ItemFromPath(
    LPCTSTR lpszPath,
    LPITEMIDLIST& pidl);
```

### <a name="parameters"></a>Parâmetros

*lpszPath*<br/>
[in] Uma cadeia de caracteres que especifica o caminho para o item.

*pidl*<br/>
[out] Uma referência a um PIDL. O método usa esse PIDL para armazenar o ponteiro para seu valor de retorno.

### <a name="return-value"></a>Valor de retorno

Retorna NOERROR se bem-sucedido; um valor de erro definidas pelo OLE.

## <a name="see-also"></a>Consulte também

[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classes](../../mfc/reference/mfc-classes.md)
