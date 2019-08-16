---
title: Classe CMFCShellListCtrl
ms.date: 11/04/2016
f1_keywords:
- CMFCShellListCtrl
- AFXSHELLLISTCTRL/CMFCShellListCtrl
- AFXSHELLLISTCTRL/CMFCShellListCtrl::DisplayFolder
- AFXSHELLLISTCTRL/CMFCShellListCtrl::DisplayParentFolder
- AFXSHELLLISTCTRL/CMFCShellListCtrl::EnableShellContextMenu
- AFXSHELLLISTCTRL/CMFCShellListCtrl::GetCurrentFolder
- AFXSHELLLISTCTRL/CMFCShellListCtrl::GetCurrentFolderName
- AFXSHELLLISTCTRL/CMFCShellListCtrl::GetCurrentItemIdList
- AFXSHELLLISTCTRL/CMFCShellListCtrl::GetCurrentShellFolder
- AFXSHELLLISTCTRL/CMFCShellListCtrl::GetItemPath
- AFXSHELLLISTCTRL/CMFCShellListCtrl::GetItemTypes
- AFXSHELLLISTCTRL/CMFCShellListCtrl::IsDesktop
- AFXSHELLLISTCTRL/CMFCShellListCtrl::OnCompareItems
- AFXSHELLLISTCTRL/CMFCShellListCtrl::OnFormatFileDate
- AFXSHELLLISTCTRL/CMFCShellListCtrl::OnFormatFileSize
- AFXSHELLLISTCTRL/CMFCShellListCtrl::OnGetItemIcon
- AFXSHELLLISTCTRL/CMFCShellListCtrl::OnGetItemText
- AFXSHELLLISTCTRL/CMFCShellListCtrl::OnSetColumns
- AFXSHELLLISTCTRL/CMFCShellListCtrl::Refresh
- AFXSHELLLISTCTRL/CMFCShellListCtrl::SetItemTypes
helpviewer_keywords:
- CMFCShellListCtrl [MFC], DisplayFolder
- CMFCShellListCtrl [MFC], DisplayParentFolder
- CMFCShellListCtrl [MFC], EnableShellContextMenu
- CMFCShellListCtrl [MFC], GetCurrentFolder
- CMFCShellListCtrl [MFC], GetCurrentFolderName
- CMFCShellListCtrl [MFC], GetCurrentItemIdList
- CMFCShellListCtrl [MFC], GetCurrentShellFolder
- CMFCShellListCtrl [MFC], GetItemPath
- CMFCShellListCtrl [MFC], GetItemTypes
- CMFCShellListCtrl [MFC], IsDesktop
- CMFCShellListCtrl [MFC], OnCompareItems
- CMFCShellListCtrl [MFC], OnFormatFileDate
- CMFCShellListCtrl [MFC], OnFormatFileSize
- CMFCShellListCtrl [MFC], OnGetItemIcon
- CMFCShellListCtrl [MFC], OnGetItemText
- CMFCShellListCtrl [MFC], OnSetColumns
- CMFCShellListCtrl [MFC], Refresh
- CMFCShellListCtrl [MFC], SetItemTypes
ms.assetid: ad472958-5586-4c50-aadf-1844c30bf6e7
ms.openlocfilehash: 02d4883c6b5445515d891c5e76ccf10b6bb35bba
ms.sourcegitcommit: fcb48824f9ca24b1f8bd37d647a4d592de1cc925
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/15/2019
ms.locfileid: "69504916"
---
# <a name="cmfcshelllistctrl-class"></a>Classe CMFCShellListCtrl

A `CMFCShellListCtrl` classe fornece a funcionalidade de controle de lista do Windows e a expande, incluindo a capacidade de exibir uma lista de itens de Shell.

## <a name="syntax"></a>Sintaxe

```
class CMFCShellListCtrl : public CMFCListCtrl
```

## <a name="members"></a>Membros

### <a name="public-methods"></a>Métodos Públicos

|Nome|Descrição|
|----------|-----------------|
|[CMFCShellListCtrl::DisplayFolder](#displayfolder)|Exibe uma lista de itens contidos em uma pasta fornecida.|
|[CMFCShellListCtrl::DisplayParentFolder](#displayparentfolder)|Exibe uma lista de itens contidos na pasta que é o pai da pasta exibida no momento.|
|[CMFCShellListCtrl::EnableShellContextMenu](#enableshellcontextmenu)|Habilita ou desabilita o menu de atalho.|
|[CMFCShellListCtrl::GetCurrentFolder](#getcurrentfolder)|Recupera o caminho da pasta atual.|
|[CMFCShellListCtrl::GetCurrentFolderName](#getcurrentfoldername)|Recupera o nome da pasta atual.|
|[CMFCShellListCtrl::GetCurrentItemIdList](#getcurrentitemidlist)|Retorna o PIDL do item de controle de lista atual.|
|[CMFCShellListCtrl::GetCurrentShellFolder](#getcurrentshellfolder)|Retorna um ponteiro para a pasta do shell atual.|
|[CMFCShellListCtrl::GetItemPath](#getitempath)|Retorna o caminho textual de um item.|
|[CMFCShellListCtrl::GetItemTypes](#getitemtypes)|Retorna os tipos de item de shell que são exibidos pelo controle de lista.|
|[CMFCShellListCtrl:: isdesktop](#isdesktop)|Verifica se a pasta selecionada no momento é a pasta da área de trabalho.|
|[CMFCShellListCtrl::OnCompareItems](#oncompareitems)|A estrutura chama esse método quando ele compara dois itens. (Substitui [CMFCListCtrl:: OnCompareItems](../../mfc/reference/cmfclistctrl-class.md#oncompareitems).)|
|[CMFCShellListCtrl::OnFormatFileDate](#onformatfiledate)|Chamado quando a estrutura recupera a data do arquivo exibida pelo controle de lista.|
|[CMFCShellListCtrl::OnFormatFileSize](#onformatfilesize)|Chamado quando a estrutura converte o tamanho do arquivo de um controle de lista.|
|[CMFCShellListCtrl::OnGetItemIcon](#ongetitemicon)|Chamado quando a estrutura recupera o ícone de um item de controle de lista.|
|[CMFCShellListCtrl::OnGetItemText](#ongetitemtext)|Chamado quando a estrutura converte o texto de um item de controle de lista.|
|[CMFCShellListCtrl::OnSetColumns](#onsetcolumns)|Chamado pelo Framework quando ele define os nomes das colunas.|
|[CMFCShellListCtrl:: atualizar](#refresh)|Atualiza e redesenha o controle de lista.|
|[CMFCShellListCtrl::SetItemTypes](#setitemtypes)|Define o tipo de itens exibidos pelo controle de lista.|

## <a name="remarks"></a>Comentários

A `CMFCShellListCtrl` classe estende a funcionalidade da [Classe CMFCListCtrl](../../mfc/reference/cmfclistctrl-class.md) habilitando seu programa para listar itens de shell do Windows. O formato de exibição usado é semelhante ao de uma exibição de lista para uma janela do Explorer.

Um objeto [CMFCShellTreeCtrl](../../mfc/reference/cmfcshelltreectrl-class.md) pode ser associado a um `CMFCShellListCtrl` objeto para criar uma janela completa do Explorer. Em seguida, a seleção de um `CMFCShellTreeCtrl` item no fará `CMFCShellListCtrl` com que o objeto liste o conteúdo do item selecionado.

## <a name="example"></a>Exemplo

O exemplo a seguir demonstra como criar um objeto da `CMFCShellListCtrl` classe e como exibir a pasta pai da pasta exibida no momento. Este trecho de código faz parte do [exemplo do Explorer](../../overview/visual-cpp-samples.md).

[!code-cpp[NVC_MFC_Explorer#1](../../mfc/reference/codesnippet/cpp/cmfcshelllistctrl-class_1.h)]
[!code-cpp[NVC_MFC_Explorer#2](../../mfc/reference/codesnippet/cpp/cmfcshelllistctrl-class_2.cpp)]
[!code-cpp[NVC_MFC_Explorer#3](../../mfc/reference/codesnippet/cpp/cmfcshelllistctrl-class_3.cpp)]

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[CObject](../../mfc/reference/cobject-class.md)

[CCmdTarget](../../mfc/reference/ccmdtarget-class.md)

[CWnd](../../mfc/reference/cwnd-class.md)

[CListCtrl](../../mfc/reference/clistctrl-class.md)

[CMFCListCtrl](../../mfc/reference/cmfclistctrl-class.md)

`CMFCShellListCtrl`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxshelllistCtrl. h

##  <a name="displayfolder"></a>CMFCShellListCtrl::D isplayFolder

Exibe uma lista de itens contidos na pasta fornecida.

```
virtual HRESULT DisplayFolder(LPCTSTR lpszPath);
virtual HRESULT DisplayFolder(LPAFX_SHELLITEMINFO lpItemInfo);
```

### <a name="parameters"></a>Parâmetros

*lpszPath*<br/>
no Uma cadeia de caracteres que contém o caminho de uma pasta.

*lpItemInfo*<br/>
no Um ponteiro para uma `LPAFX_SHELLITEMINFO` estrutura que descreve uma pasta a ser exibida.

### <a name="return-value"></a>Valor de retorno

S_OK se for bem-sucedido; Em caso contrário, E_FAIL.

##  <a name="displayparentfolder"></a>  CMFCShellListCtrl::DisplayParentFolder

Atualiza o objeto [CMFCShellListCtrl](../../mfc/reference/cmfcshelllistctrl-class.md) para exibir a pasta pai da pasta exibida no momento.

```
virtual HRESULT DisplayParentFolder();
```

### <a name="return-value"></a>Valor de retorno

S_OK se for bem-sucedido; Em caso contrário, E_FAIL.

##  <a name="enableshellcontextmenu"></a>  CMFCShellListCtrl::EnableShellContextMenu

Habilita o menu de atalho.

```
void EnableShellContextMenu(BOOL bEnable = TRUE);
```

### <a name="parameters"></a>Parâmetros

*bEnable*<br/>
no Um booliano que especifica se a estrutura habilita o menu de atalho.

##  <a name="getcurrentfolder"></a>  CMFCShellListCtrl::GetCurrentFolder

Recupera o caminho da pasta atualmente selecionada no objeto [CMFCShellListCtrl](../../mfc/reference/cmfcshelllistctrl-class.md) .

```
BOOL GetCurrentFolder(CString& strPath) const;
```

### <a name="parameters"></a>Parâmetros

*strPath*<br/>
fora Uma referência a um parâmetro de cadeia de caracteres em que o método grava o caminho.

### <a name="return-value"></a>Valor de retorno

Diferente de zero, se for bem-sucedido; caso contrário, 0.

### <a name="remarks"></a>Comentários

Esse método falhará se não houver nenhuma pasta selecionada no `CMFCShellListCtrl`.

##  <a name="getcurrentfoldername"></a>  CMFCShellListCtrl::GetCurrentFolderName

Recupera o nome da pasta atualmente selecionada no objeto [CMFCShellListCtrl](../../mfc/reference/cmfcshelllistctrl-class.md) .

```
BOOL GetCurrentFolderName(CString& strName) const;
```

### <a name="parameters"></a>Parâmetros

*strName*<br/>
fora Uma referência a um parâmetro de cadeia de caracteres em que o método grava o nome.

### <a name="return-value"></a>Valor de retorno

Diferente de zero, se for bem-sucedido; caso contrário, 0.

### <a name="remarks"></a>Comentários

Esse método falhará se não houver nenhuma pasta selecionada no `CMFCShellListCtrl`.

##  <a name="getcurrentitemidlist"></a>  CMFCShellListCtrl::GetCurrentItemIdList

Retorna o PIDL do item selecionado no momento.

```
LPITEMIDLIST GetCurrentItemIdList() const;
```

### <a name="return-value"></a>Valor de retorno

O PIDL do item atual.

##  <a name="getcurrentshellfolder"></a>  CMFCShellListCtrl::GetCurrentShellFolder

Obtém um ponteiro para o item atualmente selecionado no objeto [CMFCShellListCtrl](../../mfc/reference/cmfcshelllistctrl-class.md) .

```
const IShellFolder* GetCurrentShellFolder() const;
```

### <a name="return-value"></a>Valor de retorno

Um ponteiro para a [interface IShellFolder](/windows/win32/api/shobjidl_core/nn-shobjidl_core-ishellfolder) do objeto selecionado.

### <a name="remarks"></a>Comentários

Esse método retornará NULL se nenhum objeto estiver selecionado no momento.

##  <a name="getitempath"></a>CMFCShellListCtrl::GetItemPath

Recupera o caminho de um item.

```
BOOL GetItemPath(
    CString& strPath,
    int iItem) const;
```

### <a name="parameters"></a>Parâmetros

*strPath*<br/>
fora Uma referência a uma cadeia de caracteres que recebe o caminho.

*iItem*<br/>
no O índice do item de lista.

### <a name="return-value"></a>Valor de retorno

Verdadeiro se for bem-sucedido; Caso contrário, FALSE.

### <a name="remarks"></a>Comentários

O índice fornecido pelo *iItem* é baseado nos itens exibidos atualmente pelo objeto da [classe CMFCShellListCtrl](../../mfc/reference/cmfcshelllistctrl-class.md) .

##  <a name="getitemtypes"></a>  CMFCShellListCtrl::GetItemTypes

Retorna o tipo de itens exibidos pelo objeto [CMFCShellListCtrl](../../mfc/reference/cmfcshelllistctrl-class.md) .

```
SHCONTF GetItemTypes() const;
```

### <a name="return-value"></a>Valor de retorno

Um valor de [SHCONTF](/windows/win32/api/shobjidl_core/ne-shobjidl_core-_shcontf) que contém o tipo de itens listados no `CMFCShellListCtrl`.

### <a name="remarks"></a>Comentários

Para definir o tipo de itens listados em a `CMFCShellListCtrl`, chame [CMFCShellListCtrl::](#setitemtypes)SetItemTypes.

##  <a name="isdesktop"></a>CMFCShellListCtrl:: isdesktop

Determina se a pasta exibida no objeto [CMFCShellListCtrl](../../mfc/reference/cmfcshelllistctrl-class.md) é a pasta da área de trabalho.

```
BOOL IsDesktop() const;
```

### <a name="return-value"></a>Valor de retorno

TRUE se a pasta exibida for a pasta da área de trabalho; Caso contrário, FALSE.

##  <a name="oncompareitems"></a>  CMFCShellListCtrl::OnCompareItems

Para obter mais detalhes, consulte o código-fonte localizado na pasta **vc\\atlmfc\\src\\MFC** da instalação do Visual Studio.

```
virtual int OnCompareItems(
    LPARAM lParam1,
    LPARAM lParam2,
    int iColumn);
```

### <a name="parameters"></a>Parâmetros

[in] *lParam1*<br/>
[in] *lParam2*<br/>
no *IColumn*<br/>

### <a name="return-value"></a>Valor de retorno

### <a name="remarks"></a>Comentários

##  <a name="onformatfiledate"></a>  CMFCShellListCtrl::OnFormatFileDate

A estrutura chama esse método quando ele deve converter a data associada a um objeto em uma cadeia de caracteres.

```
virtual void OnFormatFileDate(
    const CTime& tmFile,
    CString& str);
```

### <a name="parameters"></a>Parâmetros

*tmFile*<br/>
no A data associada a um arquivo.

*str*<br/>
fora Uma cadeia de caracteres que contém a data do arquivo formatado.

### <a name="remarks"></a>Comentários

Quando um objeto da [classe CMFCShellListCtrl](../../mfc/reference/cmfcshelllistctrl-class.md) exibe a data associada a um arquivo, ele deve converter essa data em um formato de cadeia de caracteres. O `CMFCShellListCtrl` usa esse método para fazer essa conversão. Por padrão, esse método usa a localidade atual para formatar a data em uma cadeia de caracteres.

##  <a name="onformatfilesize"></a>  CMFCShellListCtrl::OnFormatFileSize

A estrutura chama esse método quando converte o tamanho de um objeto em uma cadeia de caracteres.

```
virtual void OnFormatFileSize(
    long lFileSize,
    CString& str);
```

### <a name="parameters"></a>Parâmetros

*lFileSize*<br/>
no O tamanho do arquivo que a estrutura exibirá.

*str*<br/>
fora Uma cadeia de caracteres que contém o tamanho do arquivo formatado.

### <a name="remarks"></a>Comentários

Quando um objeto da [classe CMFCShellListCtrl](../../mfc/reference/cmfcshelllistctrl-class.md) precisa exibir o tamanho de um arquivo, ele precisa converter o tamanho do arquivo em um formato de cadeia de caracteres. O `CMFCShellListCtrl` usa esse método para fazer essa conversão. Por padrão, esse método converte o tamanho do arquivo de bytes em kilobytes e, em seguida, usa a localidade atual para formatar o tamanho em cadeia de caracteres.

##  <a name="ongetitemicon"></a>  CMFCShellListCtrl::OnGetItemIcon

A estrutura chama esse método para recuperar o ícone associado a um item de lista de Shell.

```
virtual int OnGetItemIcon(
    int iItem,
    LPAFX_SHELLITEMINFO pItem);
```

### <a name="parameters"></a>Parâmetros

*iItem*<br/>
no O índice do item.

*pItem*<br/>
no Um parâmetro LPAFX_SHELLITEMINFO que descreve o item.

### <a name="return-value"></a>Valor de retorno

O índice da imagem do ícone, se for bem-sucedido; -1 se a função falhar.

### <a name="remarks"></a>Comentários

O índice de imagem de ícone é baseado na lista de imagens do sistema.

Por padrão, esse método depende do parâmetro *pItem* . O valor de *iItem* não é usado na implementação padrão. Você pode usar *iItem* para implementar o comportamento personalizado.

##  <a name="ongetitemtext"></a>  CMFCShellListCtrl::OnGetItemText

A estrutura chama esse método quando ele deve recuperar o texto de um item de Shell.

```
virtual CString OnGetItemText(
    int iItem,
    int iColumn,
    LPAFX_SHELLITEMINFO pItem);
```

### <a name="parameters"></a>Parâmetros

*iItem*<br/>
no O índice do item.

*iColumn*<br/>
no A coluna de interesse.

*pItem*<br/>
no Um parâmetro LPAFX_SHELLITEMINFO que descreve o item.

### <a name="return-value"></a>Valor de retorno

Um `CString` que contém o texto associado ao item.

### <a name="remarks"></a>Comentários

Cada item no `CMFCShellListCtrl` objeto pode ter texto em uma ou mais colunas. Quando a estrutura chama esse método, ela especifica a coluna em que ele está interessado. Se você chamar essa função manualmente, também deverá especificar a coluna na qual você está interessado.

Por padrão, esse método depende do parâmetro *pItem* para determinar qual item processar. O valor de *iItem* não é usado na implementação padrão.

##  <a name="onsetcolumns"></a>  CMFCShellListCtrl::OnSetColumns

A estrutura chama esse método quando define os nomes das colunas.

```
virtual void OnSetColumns();
```

### <a name="remarks"></a>Comentários

Por padrão, a estrutura cria quatro colunas em um `CMFCShellListCtrl` objeto. Os nomes dessas colunas são **nome**, **tamanho**, **tipo**e modificados. Você pode substituir esse método para personalizar o número de colunas e seus nomes.

##  <a name="refresh"></a>CMFCShellListCtrl:: atualizar

Atualiza e redesenha o objeto [CMFCShellListCtrl](../../mfc/reference/cmfcshelllistctrl-class.md) .

```
virtual HRESULT Refresh();
```

### <a name="return-value"></a>Valor de retorno

`S_OK`Se for bem-sucedido; caso contrário, um valor de erro.

### <a name="remarks"></a>Comentários

Chame esse método para atualizar a lista de itens exibidos pelo `CMFCShellListCtrl` objeto.

##  <a name="setitemtypes"></a>  CMFCShellListCtrl::SetItemTypes

Define o tipo de itens listados no objeto [CMFCShellListCtrl](../../mfc/reference/cmfcshelllistctrl-class.md) .

```
void SetItemTypes(SHCONTF nTypes);
```

### <a name="parameters"></a>Parâmetros

*nTypes*<br/>
no Uma lista de tipos de itens aos `CMFCShellListCtrl` quais o objeto dá suporte.

### <a name="remarks"></a>Comentários

Para obter mais informações sobre a lista de tipos de item, consulte [SHCONTF](/windows/win32/api/shobjidl_core/ne-shobjidl_core-_shcontf).

## <a name="see-also"></a>Consulte também

[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classes](../../mfc/reference/mfc-classes.md)<br/>
[Classe CMFCListCtrl](../../mfc/reference/cmfclistctrl-class.md)<br/>
[Classe CMFCShellTreeCtrl](../../mfc/reference/cmfcshelltreectrl-class.md)
