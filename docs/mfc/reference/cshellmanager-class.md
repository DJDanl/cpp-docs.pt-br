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
ms.openlocfilehash: 1c2f9ac1658f50f0ec5bd9e2f53d270c09bfcb6a
ms.sourcegitcommit: 7a6116e48c3c11b97371b8ae4ecc23adce1f092d
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/22/2020
ms.locfileid: "81750327"
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
|[CShellManager::BrowseForFolder](#browseforfolder)|Exibe uma caixa de diálogo que permite ao usuário selecionar uma pasta shell.|
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

Os métodos `CShellManager` da classe lidam com PIDLs. Um PIDL é um identificador único para um objeto shell.

Você não deve `CShellManager` criar um objeto manualmente. Ele será criado automaticamente pela estrutura de sua aplicação. No entanto, você deve ligar para [CWinAppEx::InitShellManager](../../mfc/reference/cwinappex-class.md#initshellmanager) durante o processo de inicialização do seu aplicativo. Para obter um ponteiro para o gerenciador de shell para o seu aplicativo, ligue para [CWinAppEx::GetShellManager](../../mfc/reference/cwinappex-class.md#getshellmanager).

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[Cobject](../../mfc/reference/cobject-class.md)

[Cshellmanager](../../mfc/reference/cshellmanager-class.md)

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxshellmanager.h

## <a name="cshellmanagerbrowseforfolder"></a><a name="browseforfolder"></a>CShellManager::BrowseForFolder

Exibe uma caixa de diálogo que permite ao usuário selecionar uma pasta shell.

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
[fora] A seqüência usada pelo método para armazenar o caminho da pasta selecionada.

*pWndParent*<br/>
[em] Um ponteiro para a janela dos pais.

*iplszPastainicial*<br/>
[em] Uma seqüência de string que contém a pasta selecionada por padrão quando a caixa de diálogo é exibida.

*lpszTitle*<br/>
[em] O título da caixa de diálogo.

*Ulflags*<br/>
[em] Sinalizadores especificando opções para a caixa de diálogo. Consulte [BROWSEINFO](/windows/win32/api/shlobj_core/ns-shlobj_core-browseinfow) para obter a descrição detalhada.

*piFolderImage*<br/>
[fora] Um ponteiro para o valor inteiro onde o método grava o índice de imagem da pasta selecionada.

### <a name="return-value"></a>Valor retornado

Não zero se o usuário selecionar uma pasta na caixa de diálogo; caso contrário, 0.

### <a name="remarks"></a>Comentários

Quando você chama esse método, o aplicativo cria e mostra uma caixa de diálogo que permite ao usuário selecionar uma pasta. O método escreverá o caminho da pasta no parâmetro *strOutFolder.*

### <a name="example"></a>Exemplo

O exemplo a seguir demonstra como `CShellManager` recuperar uma `CWinAppEx::GetShellManager` referência a um `BrowseForFolder` objeto usando o método e como usar o método. Este trecho de código faz parte da [amostra do Explorer](../../overview/visual-cpp-samples.md).

[!code-cpp[NVC_MFC_Explorer#6](../../mfc/reference/codesnippet/cpp/cshellmanager-class_1.cpp)]

## <a name="cshellmanagerconcatenateitem"></a><a name="concatenateitem"></a>CShellManager::ConcatenateItem

Cria uma nova lista contendo dois PIDLs.

```
LPITEMIDLIST ConcatenateItem(
    LPCITEMIDLIST pidl1,
    LPCITEMIDLIST pidl2);
```

### <a name="parameters"></a>Parâmetros

*pidl1*<br/>
[em] O primeiro item.

*pidl2*<br/>
[em] O segundo item.

### <a name="return-value"></a>Valor retornado

Um ponteiro para a nova lista de itens se a função for bem sucedida, caso contrário, NULL.

### <a name="remarks"></a>Comentários

Este método cria um novo [ITEMIDLIST](/windows/win32/api/shtypes/ns-shtypes-itemidlist) grande o suficiente para conter *pidl1* e *pidl2*. Em seguida, copia *pidl1* e *pidl2* para a nova lista.

## <a name="cshellmanagercopyitem"></a><a name="copyitem"></a>CShellManager::CopyItem

Copia uma lista de itens.

```
LPITEMIDLIST CopyItem(LPCITEMIDLIST pidlSource);
```

### <a name="parameters"></a>Parâmetros

*pidlSource*<br/>
[em] A lista de itens originais.

### <a name="return-value"></a>Valor retornado

Um ponteiro para a lista de itens recém-criada se for bem-sucedido; caso contrário, NULL.

### <a name="remarks"></a>Comentários

A lista de itens recém-criada tem o mesmo tamanho da lista de itens de origem.

## <a name="cshellmanagercreateitem"></a><a name="createitem"></a>CShellManager::CreateItem

Cria um novo PIDL.

```
LPITEMIDLIST CreateItem(UINT cbSize);
```

### <a name="parameters"></a>Parâmetros

*cbSize*<br/>
[em] O tamanho da lista de itens.

### <a name="return-value"></a>Valor retornado

Um ponteiro para a lista de itens criados se for bem-sucedido; caso contrário, NULL.

## <a name="cshellmanagercshellmanager"></a><a name="cshellmanager"></a>CShellManager::CShellManager

Constrói um objeto `CShellManager`.

```
CShellManager();
```

### <a name="remarks"></a>Comentários

Na maioria dos casos, você `CShellManager` não precisa criar um diretamente. Por padrão, a estrutura cria uma para você. Para obter um `CShellManager`ponteiro para o , ligue [cWinAppEx::GetShellManager](../../mfc/reference/cwinappex-class.md#getshellmanager). Se você criar `CShellManager` um manualmente, você deve inicializá-lo com o método [CWinAppEx::InitShellManager](../../mfc/reference/cwinappex-class.md#initshellmanager).

## <a name="cshellmanagerfreeitem"></a><a name="freeitem"></a>CShellManager::FreeItem

Exclui uma lista de itens.

```cpp
void FreeItem(LPITEMIDLIST pidl);
```

### <a name="parameters"></a>Parâmetros

*Pidl*<br/>
[em] Uma lista de itens para excluir.

## <a name="cshellmanagergetitemcount"></a><a name="getitemcount"></a>CShellManager::GetItemCount

Retorna o número de itens em uma lista de itens.

```
UINT GetItemCount(LPCITEMIDLIST pidl);
```

### <a name="parameters"></a>Parâmetros

*Pidl*<br/>
[em] Um ponteiro para uma lista de itens.

### <a name="return-value"></a>Valor retornado

O número de itens na lista de itens.

## <a name="cshellmanagergetitemsize"></a><a name="getitemsize"></a>CShellManager::GetItemSize

Retorna o tamanho de uma lista de itens.

```
UINT GetItemSize(LPCITEMIDLIST pidl);
```

### <a name="parameters"></a>Parâmetros

*Pidl*<br/>
[em] Um ponteiro para uma lista de itens.

### <a name="return-value"></a>Valor retornado

O tamanho da lista de itens.

## <a name="cshellmanagergetnextitem"></a><a name="getnextitem"></a>CShellManager::GetNextItem

Recupera o próximo item de um ponteiro para uma lista de identificadores de itens (PIDL).

```
LPITEMIDLIST GetNextItem(LPCITEMIDLIST pidl);
```

### <a name="parameters"></a>Parâmetros

*Pidl*<br/>
[em] A lista de itens para iterar.

### <a name="return-value"></a>Valor retornado

Um ponteiro para o próximo item da lista.

### <a name="remarks"></a>Comentários

Se não houver mais itens na lista, este método retorna NULL.

## <a name="cshellmanagergetparentitem"></a><a name="getparentitem"></a>CShellManager::GetParentItem

Recupera o pai de um ponteiro para uma lista de identificadores de itens (PIDL).

```
int GetParentItem(
    LPCITEMIDLIST lpidl,
    LPITEMIDLIST& lpidlParent);
```

### <a name="parameters"></a>Parâmetros

*Rio Ipidl*<br/>
[em] Um PIDL cujo pai será recuperado.

*lpidlParent*<br/>
[fora] Uma referência a um PIDL onde o método armazenará o resultado.

### <a name="return-value"></a>Valor retornado

O nível do PIDL pai.

### <a name="remarks"></a>Comentários

O nível de um PIDL é relativo à área de trabalho. O PIDL da área de trabalho é considerado com um nível de 0.

## <a name="cshellmanageritemfrompath"></a><a name="itemfrompath"></a>CShellManager::ItemFromPath

Recupera o ponteiro para uma lista de identificadores de itens (PIDL) do item identificado por um caminho de strings.

```
HRESULT ItemFromPath(
    LPCTSTR lpszPath,
    LPITEMIDLIST& pidl);
```

### <a name="parameters"></a>Parâmetros

*lpszPath*<br/>
[em] Uma seqüência que especifica o caminho para o item.

*Pidl*<br/>
[fora] Uma referência a um PIDL. O método usa este PIDL para armazenar o ponteiro ao seu valor de retorno.

### <a name="return-value"></a>Valor retornado

Retorna NOERROR se for bem sucedido; um valor de erro definido pelo OLE.

## <a name="see-also"></a>Confira também

[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classes](../../mfc/reference/mfc-classes.md)
