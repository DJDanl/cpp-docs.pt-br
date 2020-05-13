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
ms.openlocfilehash: 445556535217b0887a02227a0773c287911922a2
ms.sourcegitcommit: 7a6116e48c3c11b97371b8ae4ecc23adce1f092d
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/22/2020
ms.locfileid: "81753476"
---
# <a name="cmfcshelllistctrl-class"></a>Classe CMFCShellListCtrl

A `CMFCShellListCtrl` classe fornece a funcionalidade de controle de lista do Windows e a expande, incluindo a capacidade de exibir uma lista de itens shell.

## <a name="syntax"></a>Sintaxe

```
class CMFCShellListCtrl : public CMFCListCtrl
```

## <a name="members"></a>Membros

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CMFCShellListCtrl::DisplayFolder](#displayfolder)|Exibe uma lista de itens que estão contidos em uma pasta fornecida.|
|[CMFCShellListCtrl::DisplayParentfolder](#displayparentfolder)|Exibe uma lista de itens contidos na pasta que é o pai da pasta exibida no momento.|
|[CMFCShellListCtrl::EnableShellContextMenu](#enableshellcontextmenu)|Ativa ou desativa o menu de atalho.|
|[CMFCShellListCtrl::GetCurrentFolder](#getcurrentfolder)|Recupera o caminho da pasta atual.|
|[CMFCShellListCtrl::GetCurrentFolderName](#getcurrentfoldername)|Recupera o nome da pasta atual.|
|[CMFCShellListCtrl::GetCurrentItemIdList](#getcurrentitemidlist)|Retorna o PIDL do item de controle de lista atual.|
|[CMFCShellListCtrl::GetCurrentShellFolder](#getcurrentshellfolder)|Retorna um ponteiro para a pasta Shell atual.|
|[CMFCShellListCtrl::GetItemPath](#getitempath)|Retorna o caminho textual de um item.|
|[CMFCShellListCtrl::GetItemTypes](#getitemtypes)|Retorna os tipos de itens shell exibidos pelo controle de lista.|
|[CMFCShellListCtrl::IsDesktop](#isdesktop)|Verifica se a pasta selecionada no momento é a pasta de desktop.|
|[CMFCShellListCtrl::OnCompareItems](#oncompareitems)|A estrutura chama esse método quando compara dois itens. (Substitui [cmfclistctrl::OnCompareItems](../../mfc/reference/cmfclistctrl-class.md#oncompareitems).)|
|[CMFCShellListCtrl::OnFormatFileDate](#onformatfiledate)|Chamado quando a estrutura recupera a data do arquivo exibida pelo controle de lista.|
|[CMFCShellListCtrl:OnFormatFileSize](#onformatfilesize)|Chamado quando a estrutura converte o tamanho do arquivo de um controle de lista.|
|[CMFCShellListCtrl::OnGetItemIcon](#ongetitemicon)|Chamado quando a estrutura recupera o ícone de um item de controle de lista.|
|[CMFCShellListCtrl::OnGetItemText](#ongetitemtext)|Chamado quando o framework converte o texto de um item de controle de lista.|
|[CMFCShellListCtrl::Colunas de início](#onsetcolumns)|Chamado pela estrutura quando define os nomes das colunas.|
|[CMFCShellListCtrl::Atualização](#refresh)|Atualiza e repinta o controle da lista.|
|[CMFCShellListCtrl::SetItemTypes](#setitemtypes)|Define o tipo de itens exibidos pelo controle de lista.|

## <a name="remarks"></a>Comentários

A `CMFCShellListCtrl` classe amplia a funcionalidade da [Classe CMFCListCtrl,](../../mfc/reference/cmfclistctrl-class.md) permitindo que seu programa liste itens shell do Windows. O formato de exibição usado é como o de uma exibição de lista para uma janela do Explorer.

Um objeto [CMFCShellTreeCtrl](../../mfc/reference/cmfcshelltreectrl-class.md) pode `CMFCShellListCtrl` ser associado a um objeto para criar uma janela Explorer completa. Em seguida, selecionar um `CMFCShellTreeCtrl` item `CMFCShellListCtrl` no fará com que o objeto liste o conteúdo do item selecionado.

## <a name="example"></a>Exemplo

O exemplo a seguir demonstra como `CMFCShellListCtrl` criar um objeto da classe e como exibir a pasta-mãe da pasta exibida no momento. Este trecho de código faz parte da [amostra do Explorer](../../overview/visual-cpp-samples.md).

[!code-cpp[NVC_MFC_Explorer#1](../../mfc/reference/codesnippet/cpp/cmfcshelllistctrl-class_1.h)]
[!code-cpp[NVC_MFC_Explorer#2](../../mfc/reference/codesnippet/cpp/cmfcshelllistctrl-class_2.cpp)]
[!code-cpp[NVC_MFC_Explorer#3](../../mfc/reference/codesnippet/cpp/cmfcshelllistctrl-class_3.cpp)]

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[Cobject](../../mfc/reference/cobject-class.md)

[Ccmdtarget](../../mfc/reference/ccmdtarget-class.md)

[CWnd](../../mfc/reference/cwnd-class.md)

[CListCtrl](../../mfc/reference/clistctrl-class.md)

[CMFCListCtrl](../../mfc/reference/cmfclistctrl-class.md)

`CMFCShellListCtrl`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxshelllistCtrl.h

## <a name="cmfcshelllistctrldisplayfolder"></a><a name="displayfolder"></a>CMFCShellListCtrl::DisplayFolder

Exibe uma lista de itens contidos na pasta fornecida.

```
virtual HRESULT DisplayFolder(LPCTSTR lpszPath);
virtual HRESULT DisplayFolder(LPAFX_SHELLITEMINFO lpItemInfo);
```

### <a name="parameters"></a>Parâmetros

*lpszPath*<br/>
[em] Uma seqüência que contém o caminho de uma pasta.

*lpItemInfo*<br/>
[em] Um ponteiro `LPAFX_SHELLITEMINFO` para uma estrutura que descreve uma pasta a ser exibida.

### <a name="return-value"></a>Valor retornado

S_OK se for bem sucedido; E_FAIL o contrário.

## <a name="cmfcshelllistctrldisplayparentfolder"></a><a name="displayparentfolder"></a>CMFCShellListCtrl::DisplayParentfolder

Atualiza o objeto [CMFCShellListCtrl](../../mfc/reference/cmfcshelllistctrl-class.md) para exibir a pasta-mãe da pasta exibida no momento.

```
virtual HRESULT DisplayParentFolder();
```

### <a name="return-value"></a>Valor retornado

S_OK se for bem sucedido; E_FAIL o contrário.

## <a name="cmfcshelllistctrlenableshellcontextmenu"></a><a name="enableshellcontextmenu"></a>CMFCShellListCtrl::EnableShellContextMenu

Habilita o menu de atalho.

```cpp
void EnableShellContextMenu(BOOL bEnable = TRUE);
```

### <a name="parameters"></a>Parâmetros

*Benable*<br/>
[em] Um booleano que especifica se a estrutura habilita o menu de atalho.

## <a name="cmfcshelllistctrlgetcurrentfolder"></a><a name="getcurrentfolder"></a>CMFCShellListCtrl::GetCurrentFolder

Recupera o caminho da pasta selecionada no objeto [CMFCShellListCtrl.](../../mfc/reference/cmfcshelllistctrl-class.md)

```
BOOL GetCurrentFolder(CString& strPath) const;
```

### <a name="parameters"></a>Parâmetros

*strPath*<br/>
[fora] Uma referência a um parâmetro de seqüência onde o método escreve o caminho.

### <a name="return-value"></a>Valor retornado

Não zero se bem sucedido; 0 caso contrário.

### <a name="remarks"></a>Comentários

Este método falha se não houver `CMFCShellListCtrl`nenhuma pasta selecionada no .

## <a name="cmfcshelllistctrlgetcurrentfoldername"></a><a name="getcurrentfoldername"></a>CMFCShellListCtrl::GetCurrentFolderName

Recupera o nome da pasta selecionada no objeto [CMFCShellListCtrl.](../../mfc/reference/cmfcshelllistctrl-class.md)

```
BOOL GetCurrentFolderName(CString& strName) const;
```

### <a name="parameters"></a>Parâmetros

*strName*<br/>
[fora] Uma referência a um parâmetro de seqüência onde o método escreve o nome.

### <a name="return-value"></a>Valor retornado

Não zero se bem sucedido; 0 caso contrário.

### <a name="remarks"></a>Comentários

Este método falha se não houver `CMFCShellListCtrl`nenhuma pasta selecionada no .

## <a name="cmfcshelllistctrlgetcurrentitemidlist"></a><a name="getcurrentitemidlist"></a>CMFCShellListCtrl::GetCurrentItemIdList

Retorna o PIDL do item selecionado no momento.

```
LPITEMIDLIST GetCurrentItemIdList() const;
```

### <a name="return-value"></a>Valor retornado

O PIDL do item atual.

## <a name="cmfcshelllistctrlgetcurrentshellfolder"></a><a name="getcurrentshellfolder"></a>CMFCShellListCtrl::GetCurrentShellFolder

Obtém um ponteiro para o item selecionado no objeto [CMFCShellListCtrl.](../../mfc/reference/cmfcshelllistctrl-class.md)

```
const IShellFolder* GetCurrentShellFolder() const;
```

### <a name="return-value"></a>Valor retornado

Um ponteiro para a [interface IShellFolder](/windows/win32/api/shobjidl_core/nn-shobjidl_core-ishellfolder) para o objeto selecionado.

### <a name="remarks"></a>Comentários

Este método retorna NULL se nenhum objeto estiver selecionado no momento.

## <a name="cmfcshelllistctrlgetitempath"></a><a name="getitempath"></a>CMFCShellListCtrl::GetItemPath

Recupera o caminho para um item.

```
BOOL GetItemPath(
    CString& strPath,
    int iItem) const;
```

### <a name="parameters"></a>Parâmetros

*strPath*<br/>
[fora] Uma referência a uma string que recebe o caminho.

*Iitem*<br/>
[em] O índice do item da lista.

### <a name="return-value"></a>Valor retornado

VERDADE se bem sucedido; FALSO de outra forma.

### <a name="remarks"></a>Comentários

O índice fornecido pelo *iItem* é baseado nos itens atualmente exibidos pelo objeto [CMFCShellListCtrl Class.](../../mfc/reference/cmfcshelllistctrl-class.md)

## <a name="cmfcshelllistctrlgetitemtypes"></a><a name="getitemtypes"></a>CMFCShellListCtrl::GetItemTypes

Retorna o tipo de itens exibidos pelo objeto [CMFCShellListCtrl.](../../mfc/reference/cmfcshelllistctrl-class.md)

```
SHCONTF GetItemTypes() const;
```

### <a name="return-value"></a>Valor retornado

Um valor [SHCONTF](/windows/win32/api/shobjidl_core/ne-shobjidl_core-_shcontf) que contém o tipo `CMFCShellListCtrl`de itens listados no .

### <a name="remarks"></a>Comentários

Para definir o tipo de itens `CMFCShellListCtrl`listados em um , ligue [CMFCShellListCtrl::SetItemTypes](#setitemtypes).

## <a name="cmfcshelllistctrlisdesktop"></a><a name="isdesktop"></a>CMFCShellListCtrl::IsDesktop

Determina se a pasta exibida no objeto [CMFCShellListCtrl](../../mfc/reference/cmfcshelllistctrl-class.md) é a pasta de desktop.

```
BOOL IsDesktop() const;
```

### <a name="return-value"></a>Valor retornado

TRUE se a pasta exibida for a pasta de desktop; FALSO de outra forma.

## <a name="cmfcshelllistctrloncompareitems"></a><a name="oncompareitems"></a>CMFCShellListCtrl::OnCompareItems

Para obter mais detalhes, consulte o código-fonte localizado na pasta **VC\\atlmfc\\src\\mfc** da instalação do Visual Studio.

```
virtual int OnCompareItems(
    LPARAM lParam1,
    LPARAM lParam2,
    int iColumn);
```

### <a name="parameters"></a>Parâmetros

[em] *IParam1*<br/>
[em] *LParam2*<br/>
[em] *iColuna*<br/>

### <a name="return-value"></a>Valor retornado

### <a name="remarks"></a>Comentários

## <a name="cmfcshelllistctrlonformatfiledate"></a><a name="onformatfiledate"></a>CMFCShellListCtrl::OnFormatFileDate

A estrutura chama esse método quando ele deve converter a data associada a um objeto em uma string.

```
virtual void OnFormatFileDate(
    const CTime& tmFile,
    CString& str);
```

### <a name="parameters"></a>Parâmetros

*tmFile*<br/>
[em] A data associada a um arquivo.

*Str*<br/>
[fora] Uma seqüência que contém a data do arquivo formatado.

### <a name="remarks"></a>Comentários

Quando um objeto [CMFCShellListCtrl Class](../../mfc/reference/cmfcshelllistctrl-class.md) exibe a data associada a um arquivo, ele deve converter essa data em um formato de seqüência. O `CMFCShellListCtrl` uso deste método para fazer essa conversão. Por padrão, este método usa o local atual para formatar a data em uma seqüência de string.

## <a name="cmfcshelllistctrlonformatfilesize"></a><a name="onformatfilesize"></a>CMFCShellListCtrl:OnFormatFileSize

A estrutura chama esse método quando converte o tamanho de um objeto em uma string.

```
virtual void OnFormatFileSize(
    long lFileSize,
    CString& str);
```

### <a name="parameters"></a>Parâmetros

*lFileSize*<br/>
[em] O tamanho do arquivo que a estrutura exibirá.

*Str*<br/>
[fora] Uma seqüência que contém o tamanho do arquivo formatado.

### <a name="remarks"></a>Comentários

Quando um objeto [CMFCShellListCtrl Class](../../mfc/reference/cmfcshelllistctrl-class.md) precisa exibir o tamanho de um arquivo, ele precisa converter o tamanho do arquivo em um formato de string. O `CMFCShellListCtrl` uso deste método para fazer essa conversão. Por padrão, este método converte o tamanho do arquivo de bytes em kilobytes e, em seguida, usa o local atual para formatar o tamanho em string.

## <a name="cmfcshelllistctrlongetitemicon"></a><a name="ongetitemicon"></a>CMFCShellListCtrl::OnGetItemIcon

A estrutura chama esse método para recuperar o ícone associado a um item da lista shell.

```
virtual int OnGetItemIcon(
    int iItem,
    LPAFX_SHELLITEMINFO pItem);
```

### <a name="parameters"></a>Parâmetros

*Iitem*<br/>
[em] O índice de itens.

*Pitem*<br/>
[em] Um parâmetro LPAFX_SHELLITEMINFO que descreve o item.

### <a name="return-value"></a>Valor retornado

O índice da imagem do ícone se for bem sucedido; -1 se a função falhar.

### <a name="remarks"></a>Comentários

O índice de imagem do ícone é baseado na lista de imagens do sistema.

Por padrão, este método se baseia no parâmetro *pItem.* O valor do *iItem* não é usado na implementação padrão. Você pode usar *o iItem* para implementar comportamento personalizado.

## <a name="cmfcshelllistctrlongetitemtext"></a><a name="ongetitemtext"></a>CMFCShellListCtrl::OnGetItemText

A estrutura chama esse método quando deve recuperar o texto de um item shell.

```
virtual CString OnGetItemText(
    int iItem,
    int iColumn,
    LPAFX_SHELLITEMINFO pItem);
```

### <a name="parameters"></a>Parâmetros

*Iitem*<br/>
[em] O índice de itens.

*Icolumn*<br/>
[em] A coluna de interesse.

*Pitem*<br/>
[em] Um parâmetro LPAFX_SHELLITEMINFO que descreve o item.

### <a name="return-value"></a>Valor retornado

A `CString` que contém o texto associado ao item.

### <a name="remarks"></a>Comentários

Cada item `CMFCShellListCtrl` no objeto pode ter texto em uma ou mais colunas. Quando o framework chama esse método, ele especifica a coluna em que está interessado. Se você chamar esta função manualmente, você também deve especificar a coluna em que você está interessado.

Por padrão, este método conta com o parâmetro *pItem* para determinar qual item processar. O valor do *iItem* não é usado na implementação padrão.

## <a name="cmfcshelllistctrlonsetcolumns"></a><a name="onsetcolumns"></a>CMFCShellListCtrl::Colunas de início

A estrutura chama esse método quando define os nomes das colunas.

```
virtual void OnSetColumns();
```

### <a name="remarks"></a>Comentários

Por padrão, a estrutura cria `CMFCShellListCtrl` quatro colunas em um objeto. Os nomes dessas colunas são **Nome,** **Tamanho,** **Tipo**e **Modificado**. Você pode substituir este método para personalizar o número de colunas e seus nomes.

## <a name="cmfcshelllistctrlrefresh"></a><a name="refresh"></a>CMFCShellListCtrl::Atualização

Atualiza e repinta o objeto [CMFCShellListCtrl.](../../mfc/reference/cmfcshelllistctrl-class.md)

```
virtual HRESULT Refresh();
```

### <a name="return-value"></a>Valor retornado

`S_OK`se for bem sucedido; caso contrário, um valor de erro.

### <a name="remarks"></a>Comentários

Chame este método para atualizar a lista de `CMFCShellListCtrl` itens exibidos pelo objeto.

## <a name="cmfcshelllistctrlsetitemtypes"></a><a name="setitemtypes"></a>CMFCShellListCtrl::SetItemTypes

Define o tipo de itens listados no objeto [CMFCShellListCtrl.](../../mfc/reference/cmfcshelllistctrl-class.md)

```cpp
void SetItemTypes(SHCONTF nTypes);
```

### <a name="parameters"></a>Parâmetros

*nTipos*<br/>
[em] Uma lista de tipos `CMFCShellListCtrl` de itens que o objeto suporta.

### <a name="remarks"></a>Comentários

Para obter mais informações sobre a lista de tipos de itens, consulte [SHCONTF](/windows/win32/api/shobjidl_core/ne-shobjidl_core-_shcontf).

## <a name="see-also"></a>Confira também

[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classes](../../mfc/reference/mfc-classes.md)<br/>
[Classe CMFCListCtrl](../../mfc/reference/cmfclistctrl-class.md)<br/>
[Classe CMFCShellTreeCtrl](../../mfc/reference/cmfcshelltreectrl-class.md)
