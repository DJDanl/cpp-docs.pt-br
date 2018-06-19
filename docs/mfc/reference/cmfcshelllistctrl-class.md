---
title: Classe CMFCShellListCtrl | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: reference
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
dev_langs:
- C++
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
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 9073c3443b1c74a27c9de9be142c67fab7f40ba8
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33374957"
---
# <a name="cmfcshelllistctrl-class"></a>Classe CMFCShellListCtrl
O `CMFCShellListCtrl` classe fornece funcionalidade de controle de lista do Windows e expande, incluindo a capacidade de exibir uma lista de itens de shell.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class CMFCShellListCtrl : public CMFCListCtrl  
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-methods"></a>Métodos Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CMFCShellListCtrl::DisplayFolder](#displayfolder)|Exibe uma lista de itens que estão contidos em uma pasta fornecida.|  
|[CMFCShellListCtrl::DisplayParentFolder](#displayparentfolder)|Exibe uma lista de itens que estão contidos na pasta que é o pai da pasta exibido no momento.|  
|[CMFCShellListCtrl::EnableShellContextMenu](#enableshellcontextmenu)|Habilita ou desabilita o menu de atalho.|  
|[CMFCShellListCtrl::GetCurrentFolder](#getcurrentfolder)|Recupera o caminho da pasta atual.|  
|[CMFCShellListCtrl::GetCurrentFolderName](#getcurrentfoldername)|Recupera o nome da pasta atual.|  
|[CMFCShellListCtrl::GetCurrentItemIdList](#getcurrentitemidlist)|Retorna o PIDL do item atual do controle de lista.|  
|[CMFCShellListCtrl::GetCurrentShellFolder](#getcurrentshellfolder)|Retorna um ponteiro para a pasta do Shell atual.|  
|[CMFCShellListCtrl::GetItemPath](#getitempath)|Retorna o caminho textual de um item.|  
|[CMFCShellListCtrl::GetItemTypes](#getitemtypes)|Retorna os tipos de item de Shell que são exibidos pelo controle de lista.|  
|[CMFCShellListCtrl::IsDesktop](#isdesktop)|Verifica se a pasta selecionada atualmente na pasta área de trabalho.|  
|[CMFCShellListCtrl::OnCompareItems](#oncompareitems)|O framework chama este método quando ele se compara dois itens. (Substitui [CMFCListCtrl::OnCompareItems](../../mfc/reference/cmfclistctrl-class.md#oncompareitems).)|  
|[CMFCShellListCtrl::OnFormatFileDate](#onformatfiledate)|Chamado quando a estrutura recupera a data do arquivo exibida pelo controle de lista.|  
|[CMFCShellListCtrl::OnFormatFileSize](#onformatfilesize)|Chamado quando o framework converte o tamanho do arquivo de um controle de lista.|  
|[CMFCShellListCtrl::OnGetItemIcon](#ongetitemicon)|Chamado quando a estrutura recupera o ícone de um item de controle de lista.|  
|[CMFCShellListCtrl::OnGetItemText](#ongetitemtext)|Chamado quando o framework converte o texto de um item de controle de lista.|  
|[CMFCShellListCtrl::OnSetColumns](#onsetcolumns)|Chamado pelo framework quando ele define os nomes das colunas.|  
|[CMFCShellListCtrl::Refresh](#refresh)|Atualiza e redesenha o controle de lista.|  
|[CMFCShellListCtrl::SetItemTypes](#setitemtypes)|Define o tipo de itens exibidos pelo controle de lista.|  
  
## <a name="remarks"></a>Comentários  
 O `CMFCShellListCtrl` classe estende a funcionalidade do [CMFCListCtrl classe](../../mfc/reference/cmfclistctrl-class.md) , permitindo que seu programa listar os itens de shell do Windows. É o formato de exibição que é usado como um modo de exibição de lista em uma janela do Explorer.  
  
 Um [CMFCShellTreeCtrl](../../mfc/reference/cmfcshelltreectrl-class.md) objeto pode ser associado com um `CMFCShellListCtrl` objeto para criar uma janela do Explorer concluída. Em seguida, selecionando um item no `CMFCShellTreeCtrl` fará com que o `CMFCShellListCtrl` objeto listar o conteúdo do item selecionado.  
  
## <a name="example"></a>Exemplo  
 O exemplo a seguir demonstra como criar um objeto de `CMFCShellListCtrl` classe e como exibir a pasta pai da pasta exibida no momento. Este trecho de código é parte do [exemplo do Gerenciador de](../../visual-cpp-samples.md).  
  
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
 **Cabeçalho:** afxshelllistCtrl.h  
  
##  <a name="displayfolder"></a>  CMFCShellListCtrl::DisplayFolder  
 Exibe uma lista de itens que estão contidos na pasta fornecida.  
  
```  
virtual HRESULT DisplayFolder(LPCTSTR lpszPath);
virtual HRESULT DisplayFolder(LPAFX_SHELLITEMINFO lpItemInfo);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `lpszPath`  
 Uma cadeia de caracteres que contém o caminho de uma pasta.  
  
 [in] `lpItemInfo`  
 Um ponteiro para um `LPAFX_SHELLITEMINFO` estrutura que descreve uma pasta para exibir.  
  
### <a name="return-value"></a>Valor de retorno  
 `S_OK` Se for bem-sucedida; `E_FAIL` caso contrário.  
  
##  <a name="displayparentfolder"></a>  CMFCShellListCtrl::DisplayParentFolder  
 Atualizações de [CMFCShellListCtrl](../../mfc/reference/cmfcshelllistctrl-class.md) objeto para exibir a pasta pai da pasta exibida no momento.  
  
```  
virtual HRESULT DisplayParentFolder();
```  
  
### <a name="return-value"></a>Valor de retorno  
 `S_OK` Se for bem-sucedida; `E_FAIL` caso contrário.  
  
##  <a name="enableshellcontextmenu"></a>  CMFCShellListCtrl::EnableShellContextMenu  
 Permite que o menu de atalho.  
  
```  
void EnableShellContextMenu(BOOL bEnable = TRUE);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `bEnable`  
 Um valor booleano que especifica se a estrutura permite que o menu de atalho.  
  
##  <a name="getcurrentfolder"></a>  CMFCShellListCtrl::GetCurrentFolder  
 Recupera o caminho da pasta selecionada atualmente no [CMFCShellListCtrl](../../mfc/reference/cmfcshelllistctrl-class.md) objeto.  
  
```  
BOOL GetCurrentFolder(CString& strPath) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 [out] `strPath`  
 Uma referência a um parâmetro de cadeia de caracteres onde o método grava o caminho.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se for bem-sucedida; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Esse método falhar se não houver nenhuma pasta selecionada no `CMFCShellListCtrl`.  
  
##  <a name="getcurrentfoldername"></a>  CMFCShellListCtrl::GetCurrentFolderName  
 Recupera o nome da pasta selecionada atualmente no [CMFCShellListCtrl](../../mfc/reference/cmfcshelllistctrl-class.md) objeto.  
  
```  
BOOL GetCurrentFolderName(CString& strName) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 [out] `strName`  
 Uma referência a um parâmetro de cadeia de caracteres onde o método grava o nome.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se for bem-sucedida; Caso contrário, 0.  
  
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
 Obtém um ponteiro para o item selecionado atualmente no [CMFCShellListCtrl](../../mfc/reference/cmfcshelllistctrl-class.md) objeto.  
  
```  
const IShellFolder* GetCurrentShellFolder() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um ponteiro para o [IShellFolder Interface](http://msdn.microsoft.com/library/windows/desktop/bb775075) do objeto selecionado.  
  
### <a name="remarks"></a>Comentários  
 Este método retorna `NULL` se nenhum objeto está selecionado no momento.  
  
##  <a name="getitempath"></a>  CMFCShellListCtrl::GetItemPath  
 Recupera o caminho para um item.  
  
```  
BOOL GetItemPath(
    CString& strPath,  
    int iItem) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 [out] `strPath`  
 Uma referência a uma cadeia de caracteres que recebe o caminho.  
  
 [in] `iItem`  
 O índice do item da lista.  
  
### <a name="return-value"></a>Valor de retorno  
 `TRUE` Se for bem-sucedida; `FALSE` caso contrário.  
  
### <a name="remarks"></a>Comentários  
 O índice fornecido pelo `iItem` baseia-se nos itens atualmente exibidos pelo [CMFCShellListCtrl classe](../../mfc/reference/cmfcshelllistctrl-class.md) objeto.  
  
##  <a name="getitemtypes"></a>  CMFCShellListCtrl::GetItemTypes  
 Retorna o tipo de itens exibidos pelo [CMFCShellListCtrl](../../mfc/reference/cmfcshelllistctrl-class.md) objeto.  
  
```  
SHCONTF GetItemTypes() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um [SHCONTF](http://msdn.microsoft.com/library/windows/desktop/bb762539) que contém o tipo dos itens listados no valor de `CMFCShellListCtrl`.  
  
### <a name="remarks"></a>Comentários  
 Para definir o tipo dos itens listados em uma `CMFCShellListCtrl`, chame [CMFCShellListCtrl::SetItemTypes](#setitemtypes).  
  
##  <a name="isdesktop"></a>  CMFCShellListCtrl::IsDesktop  
 Determina se a pasta que será exibido no [CMFCShellListCtrl](../../mfc/reference/cmfcshelllistctrl-class.md) objeto é a pasta da área de trabalho.  
  
```  
BOOL IsDesktop() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 `TRUE` Se a pasta exibida é a pasta da área de trabalho; `FALSE` caso contrário.  
  
##  <a name="oncompareitems"></a>  CMFCShellListCtrl::OnCompareItems  
 [!INCLUDE[cpp_fp_under_construction](../../mfc/reference/includes/cpp_fp_under_construction_md.md)]  
  
```  
virtual int OnCompareItems(
    LPARAM lParam1,  
    LPARAM lParam2,  
    int iColumn);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `lParam1`  
 [in] `lParam2`  
 [in] `iColumn`  
  
### <a name="return-value"></a>Valor de retorno  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="onformatfiledate"></a>  CMFCShellListCtrl::OnFormatFileDate  
 O framework chama este método quando ele deve converter a data associada a um objeto em uma cadeia de caracteres.  
  
```  
virtual void OnFormatFileDate(
    const CTime& tmFile,  
    CString& str);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `tmFile`  
 A data associada a um arquivo.  
  
 [out] `str`  
 Uma cadeia de caracteres que contém a data do arquivo formatado.  
  
### <a name="remarks"></a>Comentários  
 Quando um [CMFCShellListCtrl classe](../../mfc/reference/cmfcshelllistctrl-class.md) objeto exibe a data associada a um arquivo, ele deve converter a data em um formato de cadeia de caracteres. O `CMFCShellListCtrl` usa esse método para fazer essa conversão. Por padrão, esse método usa a localidade atual para formatar a data em uma cadeia de caracteres.  
  
##  <a name="onformatfilesize"></a>  CMFCShellListCtrl::OnFormatFileSize  
 O framework chama este método quando ele converte o tamanho de um objeto em uma cadeia de caracteres.  
  
```  
virtual void OnFormatFileSize(
    long lFileSize,  
    CString& str);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `lFileSize`  
 O tamanho do arquivo que exibirá a estrutura.  
  
 [out] `str`  
 Uma cadeia de caracteres que contém o tamanho do arquivo formatado.  
  
### <a name="remarks"></a>Comentários  
 Quando um [CMFCShellListCtrl classe](../../mfc/reference/cmfcshelllistctrl-class.md) objeto precisa exibir o tamanho de um arquivo, ele precisa converter o tamanho do arquivo em um formato de cadeia de caracteres. O `CMFCShellListCtrl` usa esse método para fazer essa conversão. Por padrão, este método converte o tamanho do arquivo de bytes em quilobytes e, em seguida, usa a localidade atual para formatar tamanho em cadeia de caracteres.  
  
##  <a name="ongetitemicon"></a>  CMFCShellListCtrl::OnGetItemIcon  
 O framework chama esse método para recuperar o ícone associado a um item de lista do shell.  
  
```  
virtual int OnGetItemIcon(
    int iItem,  
    LPAFX_SHELLITEMINFO pItem);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `iItem`  
 O índice do item.  
  
 [in] `pItem`  
 Um `LPAFX_SHELLITEMINFO` parâmetro que descreve o item.  
  
### <a name="return-value"></a>Valor de retorno  
 O índice da imagem do ícone se bem-sucedido; -1 se a função falhar.  
  
### <a name="remarks"></a>Comentários  
 O índice de imagem de ícone baseia-se a lista de imagens do sistema.  
  
 Por padrão, esse método depende de `pItem` parâmetro. O valor de `iItem` não é usada na implementação do padrão. Você pode usar `iItem` para implementar o comportamento personalizado.  
  
##  <a name="ongetitemtext"></a>  CMFCShellListCtrl::OnGetItemText  
 O framework chama este método quando ele deve recuperar o texto de um item de shell.  
  
```  
virtual CString OnGetItemText(
    int iItem,  
    int iColumn,  
    LPAFX_SHELLITEMINFO pItem);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `iItem`  
 O índice do item.  
  
 [in] `iColumn`  
 A coluna de interesse.  
  
 [in] `pItem`  
 Um `LPAFX_SHELLITEMINFO` parâmetro que descreve o item.  
  
### <a name="return-value"></a>Valor de retorno  
 Um `CString` que contém o texto associado ao item.  
  
### <a name="remarks"></a>Comentários  
 Cada item de `CMFCShellListCtrl` objeto pode ter o texto em uma ou mais colunas. Quando o framework chama esse método, especifica a coluna que está interessado. Se você chamar esta função manualmente, você também deve especificar a coluna que você está interessado.  
  
 Por padrão, esse método depende de `pItem` parâmetro para determinar qual item ao processo. O valor de `iItem` não é usada na implementação do padrão.  
  
##  <a name="onsetcolumns"></a>  CMFCShellListCtrl::OnSetColumns  
 O framework chama este método quando ele define os nomes das colunas.  
  
```  
virtual void OnSetColumns();
```  
  
### <a name="remarks"></a>Comentários  
 Por padrão, o framework cria quatro colunas em um `CMFCShellListCtrl` objeto. Os nomes dessas colunas são `Name`, `Size`, `Type`, e `Modified`. Você pode substituir esse método para personalizar o número de colunas e seus nomes.  
  
##  <a name="refresh"></a>  CMFCShellListCtrl::Refresh  
 Atualiza e redesenha o [CMFCShellListCtrl](../../mfc/reference/cmfcshelllistctrl-class.md) objeto.  
  
```  
virtual HRESULT Refresh();
```  
  
### <a name="return-value"></a>Valor de retorno  
 `S_OK` Se for bem-sucedida; Caso contrário, um valor de erro.  
  
### <a name="remarks"></a>Comentários  
 Chame este método para atualizar a lista de itens exibidos pelo `CMFCShellListCtrl` objeto.  
  
##  <a name="setitemtypes"></a>  CMFCShellListCtrl::SetItemTypes  
 Define o tipo de itens que são listados no [CMFCShellListCtrl](../../mfc/reference/cmfcshelllistctrl-class.md) objeto.  
  
```  
void SetItemTypes(SHCONTF nTypes);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `nTypes`  
 Tipos de uma lista de itens que o `CMFCShellListCtrl` objeto oferece suporte.  
  
### <a name="remarks"></a>Comentários  
 Para obter mais informações sobre a lista de tipos de item, consulte [SHCONTF](http://msdn.microsoft.com/library/windows/desktop/bb762539).  
  
## <a name="see-also"></a>Consulte também  
 [Gráfico de hierarquia](../../mfc/hierarchy-chart.md)   
 [Classes](../../mfc/reference/mfc-classes.md)   
 [Classe CMFCListCtrl](../../mfc/reference/cmfclistctrl-class.md)   
 [Classe CMFCShellTreeCtrl](../../mfc/reference/cmfcshelltreectrl-class.md)
