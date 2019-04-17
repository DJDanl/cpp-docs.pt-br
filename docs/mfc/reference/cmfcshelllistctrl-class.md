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
ms.openlocfilehash: a513a5e85ae5cf00f7ea874967a709245e016b34
ms.sourcegitcommit: 5cecccba0a96c1b4ccea1f7a1cfd91f259cc5bde
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/01/2019
ms.locfileid: "58772105"
---
# <a name="cmfcshelllistctrl-class"></a>Classe CMFCShellListCtrl

O `CMFCShellListCtrl` classe fornece funcionalidade de controle de lista do Windows e expandi-la incluindo a capacidade de exibir uma lista de itens de shell.

## <a name="syntax"></a>Sintaxe

```
class CMFCShellListCtrl : public CMFCListCtrl
```

## <a name="members"></a>Membros

### <a name="public-methods"></a>Métodos Públicos

|Nome|Descrição|
|----------|-----------------|
|[CMFCShellListCtrl::DisplayFolder](#displayfolder)|Exibe uma lista de itens que estão contidos em uma pasta fornecida.|
|[CMFCShellListCtrl::DisplayParentFolder](#displayparentfolder)|Exibe uma lista de itens que estão contidos na pasta que é o pai da pasta exibida no momento.|
|[CMFCShellListCtrl::EnableShellContextMenu](#enableshellcontextmenu)|Habilita ou desabilita o menu de atalho.|
|[CMFCShellListCtrl::GetCurrentFolder](#getcurrentfolder)|Recupera o caminho da pasta atual.|
|[CMFCShellListCtrl::GetCurrentFolderName](#getcurrentfoldername)|Recupera o nome da pasta atual.|
|[CMFCShellListCtrl::GetCurrentItemIdList](#getcurrentitemidlist)|Retorna o PIDL do item atual do controle de lista.|
|[CMFCShellListCtrl::GetCurrentShellFolder](#getcurrentshellfolder)|Retorna um ponteiro para a pasta do Shell atual.|
|[CMFCShellListCtrl::GetItemPath](#getitempath)|Retorna o caminho textual de um item.|
|[CMFCShellListCtrl::GetItemTypes](#getitemtypes)|Retorna os tipos de item do Shell que são exibidos pelo controle de lista.|
|[CMFCShellListCtrl::IsDesktop](#isdesktop)|Verifica se a pasta selecionada atualmente é a pasta da área de trabalho.|
|[CMFCShellListCtrl::OnCompareItems](#oncompareitems)|O framework chama esse método quando ele compara dois itens. (Substitui [CMFCListCtrl::OnCompareItems](../../mfc/reference/cmfclistctrl-class.md#oncompareitems).)|
|[CMFCShellListCtrl::OnFormatFileDate](#onformatfiledate)|Chamado quando o framework recupera a data do arquivo exibida pelo controle de lista.|
|[CMFCShellListCtrl::OnFormatFileSize](#onformatfilesize)|Chamado quando o framework converte o tamanho do arquivo de um controle de lista.|
|[CMFCShellListCtrl::OnGetItemIcon](#ongetitemicon)|Chamado quando o framework recupera o ícone de um item de controle de lista.|
|[CMFCShellListCtrl::OnGetItemText](#ongetitemtext)|Chamado quando o framework converte o texto de um item de controle de lista.|
|[CMFCShellListCtrl::OnSetColumns](#onsetcolumns)|Chamado pelo framework quando ele define os nomes das colunas.|
|[CMFCShellListCtrl::Refresh](#refresh)|Atualiza e redesenha o controle de lista.|
|[CMFCShellListCtrl::SetItemTypes](#setitemtypes)|Define o tipo de itens exibidos pelo controle de lista.|

## <a name="remarks"></a>Comentários

O `CMFCShellListCtrl` classe estende a funcionalidade dos [classe CMFCListCtrl](../../mfc/reference/cmfclistctrl-class.md) , permitindo que seu programa listar itens de shell do Windows. O formato de exibição que é usado é semelhante à de uma exibição de lista para uma janela do Explorer.

Um [CMFCShellTreeCtrl](../../mfc/reference/cmfcshelltreectrl-class.md) objeto pode ser associado com um `CMFCShellListCtrl` objeto para criar uma janela do Explorer completa. Em seguida, selecionando um item na `CMFCShellTreeCtrl` fará com que o `CMFCShellListCtrl` objeto listar o conteúdo do item selecionado.

## <a name="example"></a>Exemplo

O exemplo a seguir demonstra como criar um objeto do `CMFCShellListCtrl` classe e como exibir a pasta pai da pasta exibida no momento. Este trecho de código faz parte de [amostra do Gerenciador de](../../overview/visual-cpp-samples.md).

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

**Header:** afxshelllistCtrl.h

##  <a name="displayfolder"></a>  CMFCShellListCtrl::DisplayFolder

Exibe uma lista de itens que estão contidos na pasta fornecida.

```
virtual HRESULT DisplayFolder(LPCTSTR lpszPath);
virtual HRESULT DisplayFolder(LPAFX_SHELLITEMINFO lpItemInfo);
```

### <a name="parameters"></a>Parâmetros

*lpszPath*<br/>
[in] Uma cadeia de caracteres que contém o caminho de uma pasta.

*lpItemInfo*<br/>
[in] Um ponteiro para um `LPAFX_SHELLITEMINFO` estrutura que descreve uma pasta para exibir.

### <a name="return-value"></a>Valor de retorno

S_OK se bem-sucedido; E_FAIL caso contrário.

##  <a name="displayparentfolder"></a>  CMFCShellListCtrl::DisplayParentFolder

Atualizações do [CMFCShellListCtrl](../../mfc/reference/cmfcshelllistctrl-class.md) objeto para exibir a pasta pai da pasta exibida no momento.

```
virtual HRESULT DisplayParentFolder();
```

### <a name="return-value"></a>Valor de retorno

S_OK se bem-sucedido; E_FAIL caso contrário.

##  <a name="enableshellcontextmenu"></a>  CMFCShellListCtrl::EnableShellContextMenu

Permite que o menu de atalho.

```
void EnableShellContextMenu(BOOL bEnable = TRUE);
```

### <a name="parameters"></a>Parâmetros

*bEnable*<br/>
[in] Um booliano que especifica se o framework permite que o menu de atalho.

##  <a name="getcurrentfolder"></a>  CMFCShellListCtrl::GetCurrentFolder

Recupera o caminho da pasta selecionada no momento na [CMFCShellListCtrl](../../mfc/reference/cmfcshelllistctrl-class.md) objeto.

```
BOOL GetCurrentFolder(CString& strPath) const;
```

### <a name="parameters"></a>Parâmetros

*strPath*<br/>
[out] Uma referência a um parâmetro de cadeia de caracteres em que o método grava o caminho.

### <a name="return-value"></a>Valor de retorno

Diferente de zero se bem-sucedido; Caso contrário, 0.

### <a name="remarks"></a>Comentários

Esse método falhar se não houver nenhuma pasta selecionada no `CMFCShellListCtrl`.

##  <a name="getcurrentfoldername"></a>  CMFCShellListCtrl::GetCurrentFolderName

Recupera o nome da pasta selecionada no momento na [CMFCShellListCtrl](../../mfc/reference/cmfcshelllistctrl-class.md) objeto.

```
BOOL GetCurrentFolderName(CString& strName) const;
```

### <a name="parameters"></a>Parâmetros

*strName*<br/>
[out] Uma referência a um parâmetro de cadeia de caracteres em que o método grava o nome.

### <a name="return-value"></a>Valor de retorno

Diferente de zero se bem-sucedido; Caso contrário, 0.

### <a name="remarks"></a>Comentários

Esse método falhar se não houver nenhuma pasta selecionada no `CMFCShellListCtrl`.

##  <a name="getcurrentitemidlist"></a>  CMFCShellListCtrl::GetCurrentItemIdList

Retorna o PIDL do item atualmente selecionado.

```
LPITEMIDLIST GetCurrentItemIdList() const;
```

### <a name="return-value"></a>Valor de retorno

PIDL do item atual.

##  <a name="getcurrentshellfolder"></a>  CMFCShellListCtrl::GetCurrentShellFolder

Obtém um ponteiro para o item atualmente selecionado na [CMFCShellListCtrl](../../mfc/reference/cmfcshelllistctrl-class.md) objeto.

```
const IShellFolder* GetCurrentShellFolder() const;
```

### <a name="return-value"></a>Valor de retorno

Um ponteiro para o [IShellFolder Interface](/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellfolder) para o objeto selecionado.

### <a name="remarks"></a>Comentários

Esse método retornará nulo se nenhum objeto está selecionado no momento.

##  <a name="getitempath"></a>  CMFCShellListCtrl::GetItemPath

Recupera o caminho para um item.

```
BOOL GetItemPath(
    CString& strPath,
    int iItem) const;
```

### <a name="parameters"></a>Parâmetros

*strPath*<br/>
[out] Uma referência a uma cadeia de caracteres que recebe o caminho.

*iItem*<br/>
[in] O índice do item de lista.

### <a name="return-value"></a>Valor de retorno

VERDADEIRO se bem-sucedido; FALSE caso contrário.

### <a name="remarks"></a>Comentários

O índice fornecido pelo *iItem* baseia-se nos itens atualmente exibidos pelo [classe CMFCShellListCtrl](../../mfc/reference/cmfcshelllistctrl-class.md) objeto.

##  <a name="getitemtypes"></a>  CMFCShellListCtrl::GetItemTypes

Retorna o tipo de itens exibidos pela [CMFCShellListCtrl](../../mfc/reference/cmfcshelllistctrl-class.md) objeto.

```
SHCONTF GetItemTypes() const;
```

### <a name="return-value"></a>Valor de retorno

Um [SHCONTF](/windows/desktop/api/shobjidl_core/ne-shobjidl_core-_shcontf) que contém o tipo dos itens listados no valor de `CMFCShellListCtrl`.

### <a name="remarks"></a>Comentários

Para definir o tipo dos itens listados em uma `CMFCShellListCtrl`, chame [CMFCShellListCtrl::SetItemTypes](#setitemtypes).

##  <a name="isdesktop"></a>  CMFCShellListCtrl::IsDesktop

Determina se a pasta que será exibido na [CMFCShellListCtrl](../../mfc/reference/cmfcshelllistctrl-class.md) objeto é a pasta da área de trabalho.

```
BOOL IsDesktop() const;
```

### <a name="return-value"></a>Valor de retorno

TRUE se a pasta exibida é a pasta da área de trabalho; FALSE caso contrário.

##  <a name="oncompareitems"></a>  CMFCShellListCtrl::OnCompareItems

Para obter mais detalhes, consulte o código-fonte localizado na **VC\\atlmfc\\src\\mfc** pasta de instalação do Visual Studio.

```
virtual int OnCompareItems(
    LPARAM lParam1,
    LPARAM lParam2,
    int iColumn);
```

### <a name="parameters"></a>Parâmetros

[in] *lParam1*<br/>
[in] *lParam2*<br/>
[in] *iColumn*<br/>

### <a name="return-value"></a>Valor de retorno

### <a name="remarks"></a>Comentários

##  <a name="onformatfiledate"></a>  CMFCShellListCtrl::OnFormatFileDate

O framework chama esse método quando ele deve converter a data associada a um objeto em uma cadeia de caracteres.

```
virtual void OnFormatFileDate(
    const CTime& tmFile,
    CString& str);
```

### <a name="parameters"></a>Parâmetros

*tmFile*<br/>
[in] A data associada com um arquivo.

*str*<br/>
[out] Uma cadeia de caracteres que contém a data do arquivo formatado.

### <a name="remarks"></a>Comentários

Quando um [classe CMFCShellListCtrl](../../mfc/reference/cmfcshelllistctrl-class.md) objeto exibe a data associada a um arquivo, ele deve converter a data em um formato de cadeia de caracteres. O `CMFCShellListCtrl` usa esse método para fazer essa conversão. Por padrão, esse método usa a localidade atual para formatar a data em uma cadeia de caracteres.

##  <a name="onformatfilesize"></a>  CMFCShellListCtrl::OnFormatFileSize

O framework chama esse método quando ele converte o tamanho de um objeto em uma cadeia de caracteres.

```
virtual void OnFormatFileSize(
    long lFileSize,
    CString& str);
```

### <a name="parameters"></a>Parâmetros

*lFileSize*<br/>
[in] O tamanho do arquivo que exibirá a estrutura.

*str*<br/>
[out] Uma cadeia de caracteres que contém o tamanho do arquivo formatado.

### <a name="remarks"></a>Comentários

Quando um [classe CMFCShellListCtrl](../../mfc/reference/cmfcshelllistctrl-class.md) objeto precisa exibir o tamanho de um arquivo, ele precisa converter o tamanho do arquivo em um formato de cadeia de caracteres. O `CMFCShellListCtrl` usa esse método para fazer essa conversão. Por padrão, esse método converte o tamanho do arquivo de bytes em quilobytes e, em seguida, usa a localidade atual para formatar tamanho em cadeia de caracteres.

##  <a name="ongetitemicon"></a>  CMFCShellListCtrl::OnGetItemIcon

O framework chama esse método para recuperar o ícone associado a um item de lista de shell.

```
virtual int OnGetItemIcon(
    int iItem,
    LPAFX_SHELLITEMINFO pItem);
```

### <a name="parameters"></a>Parâmetros

*iItem*<br/>
[in] O índice do item.

*pItem*<br/>
[in] Um parâmetro LPAFX_SHELLITEMINFO que descreve o item.

### <a name="return-value"></a>Valor de retorno

O índice da imagem do ícone se bem-sucedido; -1 se a função falhar.

### <a name="remarks"></a>Comentários

O índice de imagem de ícone baseia-se a lista de imagens do sistema.

Por padrão, esse método conta com o *pItem* parâmetro. O valor de *iItem* não é usada na implementação do padrão. Você pode usar *iItem* implementar comportamento personalizado.

##  <a name="ongetitemtext"></a>  CMFCShellListCtrl::OnGetItemText

O framework chama esse método quando ele deve recuperar o texto de um item de shell.

```
virtual CString OnGetItemText(
    int iItem,
    int iColumn,
    LPAFX_SHELLITEMINFO pItem);
```

### <a name="parameters"></a>Parâmetros

*iItem*<br/>
[in] O índice do item.

*iColumn*<br/>
[in] A coluna de interesse.

*pItem*<br/>
[in] Um parâmetro LPAFX_SHELLITEMINFO que descreve o item.

### <a name="return-value"></a>Valor de retorno

Um `CString` que contém o texto associado ao item.

### <a name="remarks"></a>Comentários

Cada item no `CMFCShellListCtrl` objeto pode ter o texto em uma ou mais colunas. Quando o framework chama esse método, ele especifica a coluna que está interessado. Se você chamar essa função manualmente, você também deve especificar a coluna que você está interessado.

Por padrão, esse método conta com o *pItem* parâmetro para determinar qual item ao processo. O valor de *iItem* não é usada na implementação do padrão.

##  <a name="onsetcolumns"></a>  CMFCShellListCtrl::OnSetColumns

O framework chama esse método quando ele define os nomes das colunas.

```
virtual void OnSetColumns();
```

### <a name="remarks"></a>Comentários

Por padrão, o framework cria quatro colunas em um `CMFCShellListCtrl` objeto. Os nomes dessas colunas são **nome**, **tamanho**, **tipo**, e **modificado**. Você pode substituir esse método para personalizar o número de colunas e seus nomes.

##  <a name="refresh"></a>  CMFCShellListCtrl::Refresh

Atualiza e redesenha o [CMFCShellListCtrl](../../mfc/reference/cmfcshelllistctrl-class.md) objeto.

```
virtual HRESULT Refresh();
```

### <a name="return-value"></a>Valor de retorno

`S_OK` Se for bem-sucedido; Caso contrário, um valor de erro.

### <a name="remarks"></a>Comentários

Chame esse método para atualizar a lista de itens exibidos pelo `CMFCShellListCtrl` objeto.

##  <a name="setitemtypes"></a>  CMFCShellListCtrl::SetItemTypes

Define o tipo de itens que são listadas na [CMFCShellListCtrl](../../mfc/reference/cmfcshelllistctrl-class.md) objeto.

```
void SetItemTypes(SHCONTF nTypes);
```

### <a name="parameters"></a>Parâmetros

*nTypes*<br/>
[in] Tipos de uma lista de itens que o `CMFCShellListCtrl` objeto dá suporte.

### <a name="remarks"></a>Comentários

Para obter mais informações sobre a lista de tipos de item, consulte [SHCONTF](/windows/desktop/api/shobjidl_core/ne-shobjidl_core-_shcontf).

## <a name="see-also"></a>Consulte também

[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classes](../../mfc/reference/mfc-classes.md)<br/>
[Classe CMFCListCtrl](../../mfc/reference/cmfclistctrl-class.md)<br/>
[Classe CMFCShellTreeCtrl](../../mfc/reference/cmfcshelltreectrl-class.md)
