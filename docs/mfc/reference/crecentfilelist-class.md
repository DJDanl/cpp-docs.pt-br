---
title: Classe CRecentFileList | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: reference
f1_keywords:
- CRecentFileList
- AFXADV/CRecentFileList
- AFXADV/CRecentFileList::CRecentFileList
- AFXADV/CRecentFileList::Add
- AFXADV/CRecentFileList::GetDisplayName
- AFXADV/CRecentFileList::GetSize
- AFXADV/CRecentFileList::ReadList
- AFXADV/CRecentFileList::Remove
- AFXADV/CRecentFileList::UpdateMenu
- AFXADV/CRecentFileList::WriteList
dev_langs:
- C++
helpviewer_keywords:
- CRecentFileList [MFC], CRecentFileList
- CRecentFileList [MFC], Add
- CRecentFileList [MFC], GetDisplayName
- CRecentFileList [MFC], GetSize
- CRecentFileList [MFC], ReadList
- CRecentFileList [MFC], Remove
- CRecentFileList [MFC], UpdateMenu
- CRecentFileList [MFC], WriteList
ms.assetid: a77f0524-7584-4582-849a-7e97b76d186e
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 337ecf8227f1d5c2abe0369abdea5662f882f3d2
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="crecentfilelist-class"></a>Classe CRecentFileList
Oferece suporte a controle de lista de arquivos usada recentemente (MRU).  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class CRecentFileList  
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CRecentFileList::CRecentFileList](#crecentfilelist)|Constrói um objeto `CRecentFileList`.|  
  
### <a name="public-methods"></a>Métodos Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CRecentFileList::Add](#add)|Adiciona um arquivo à lista de arquivos MRU.|  
|[CRecentFileList::GetDisplayName](#getdisplayname)|Fornece um nome para exibição para a exibição do menu de um nome de arquivo MRU.|  
|[CRecentFileList::GetSize](#getsize)|Recupera o número de arquivos na lista de arquivos MRU.|  
|[CRecentFileList::ReadList](#readlist)|Lê a lista de arquivos MRU do registro ou. Arquivo INI.|  
|[CRecentFileList::Remove](#remove)|Remove um arquivo da lista de arquivos MRU.|  
|[CRecentFileList::UpdateMenu](#updatemenu)|Atualiza a exibição do menu da lista MRU de arquivo.|  
|[CRecentFileList::WriteList](#writelist)|Grava a lista de arquivos MRU do registro ou. Arquivo INI.|  
  
### <a name="public-operators"></a>Operadores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[[CRecentFileList::operator]](#operator_at)|Retorna um `CString` objeto na posição especificada.|  
  
## <a name="remarks"></a>Comentários  
 Arquivos podem ser adicionados ao ou excluídos da lista de arquivos MRU, a lista de arquivos pode ser lido ou gravada no registro ou um. O arquivo INI e o menu Exibir a lista de arquivos MRU podem ser atualizados.  
  
 Para obter mais informações sobre os itens de menu MRU, consulte  
  
-   Artigo da Base de dados de Conhecimento Q243751: como: adicionar manipuladores de comandos de itens de Menu MRU no aplicativo do MFC  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 `CRecentFileList`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxadv.h  
  
##  <a name="add"></a>  CRecentFileList::Add  
 Adiciona um arquivo à lista de arquivos usada recentemente (MRU).  
  
```  
virtual void Add(LPCTSTR lpszPathName);

 
virtual void Add(
    LPCTSTR lpszPathName,
    LPCTSTR lpszAppID);

 
void Add(
    IShellItem* pItem,
    LPCTSTR lpszAppID);

 
void Add(
    IShellLink* pLink,
    LPCTSTR lpszAppID);

 
void Add(
    PIDLIST_ABSOLUTE pidl,
    LPCTSTR lpszAppID);
```  
  
### <a name="parameters"></a>Parâmetros  
 `lpszPathName`  
 Especifica o nome do caminho a ser adicionado à lista.  
  
 `lpszAppID`  
 Especifica a ID de modelo de usuário do aplicativo para o aplicativo.  
  
 `pItem`  
 Especifica um ponteiro para o Shell do Item a ser adicionado à lista.  
  
 `pLink`  
 Especifica um ponteiro para o Shell de Link a ser adicionado à lista.  
  
 `pidl`  
 Especifica o IDLIST do item de shell que deve ser adicionado à pasta de documentos recentes.  
  
### <a name="remarks"></a>Comentários  
 O nome do arquivo será adicionado à parte superior da lista MRU. Se o nome de arquivo já existe na lista MRU, ele será movido para a parte superior.  
  
##  <a name="crecentfilelist"></a>  CRecentFileList::CRecentFileList  
 Constrói um objeto `CRecentFileList`.  
  
```  
CRecentFileList(
    UINT nStart,  
    LPCTSTR lpszSection,  
    LPCTSTR lpszEntryFormat,  
    int nSize,  
    int nMaxDispLen = AFX_ABBREV_FILENAME_LEN);
```  
  
### <a name="parameters"></a>Parâmetros  
 `nStart`  
 Deslocamento para a numeração na exibição do menu da lista de arquivos MRU (usado mais recentemente).  
  
 `lpszSection`  
 Aponta para o nome da seção do registro ou do aplicativo. Arquivo INI onde a lista de arquivos MRU é de leitura e/ou gravada.  
  
 `lpszEntryFormat`  
 Aponta para uma cadeia de caracteres de formato a ser usado para os nomes das entradas armazenadas no registro ou do aplicativo. Arquivo INI.  
  
 `nSize`  
 Número máximo de arquivos na lista de arquivos MRU.  
  
 `nMaxDispLen`  
 Comprimento máximo em caracteres, disponíveis para a exibição do menu de um nome de arquivo na lista de arquivos MRU.  
  
### <a name="remarks"></a>Comentários  
 A cadeia de caracteres de formato apontada pelo `lpszEntryFormat` deve conter "%d", que será usada para substituir o índice de cada item MRU. Por exemplo, se a cadeia de caracteres de formato é `"file%d"` , em seguida, as entradas serão nomeadas `file0`, `file1`e assim por diante.  
  
##  <a name="getdisplayname"></a>  CRecentFileList::GetDisplayName  
 Obtém um nome de exibição para um arquivo na lista de arquivos MRU, para uso na exibição do menu da lista MRU.  
  
```  
virtual BOOL GetDisplayName(
    CString& strName,  
    int nIndex,  
    LPCTSTR lpszCurDir,  
    int nCurDir,  
    BOOL bAtLeastName = TRUE) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 `strName`  
 Caminho completo do arquivo cujo nome é exibido na lista de arquivos MRU menu.  
  
 `nIndex`  
 Índice de base zero do arquivo na lista de arquivos MRU.  
  
 *lpszCurDir*  
 Cadeia de caracteres contendo o diretório atual.  
  
 *nCurDir*  
 Comprimento da cadeia de caracteres do diretório atual.  
  
 `bAtLeastName`  
 Se for diferente de zero, indica que o nome base do arquivo deve ser retornado, mesmo se ele exceder o comprimento máximo de exibição (passado como o `nMaxDispLen` parâmetro para o `CRecentFileList` construtor).  
  
### <a name="return-value"></a>Valor de retorno  
 **FALSE** não se há nenhum nome de arquivo no índice especificado na lista de arquivos usada recentemente (MRU).  
  
### <a name="remarks"></a>Comentários  
 Se o arquivo estiver no diretório atual, a função deixa o diretório desativa a exibição. Se o nome do arquivo é muito longo, o diretório e a extensão são eliminados. Se o nome de arquivo ainda é muito longo, o nome de exibição é definido como uma cadeia de caracteres vazia, a menos que `bAtLeastName` é diferente de zero.  
  
##  <a name="getsize"></a>  CRecentFileList::GetSize  
 Recupera o número de arquivos na lista de arquivos MRU.  
  
```  
int GetSize() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 O número de arquivos atual usado mais recentemente a lista de arquivos (MRU).  
  
##  <a name="operator_at"></a>  [CRecentFileList::operator]  
 A subscrição sobrecarregada ( `[]`) operador retorna um único `CString` especificado pelo índice de base zero em `nIndex`.  
  
```  
CString& operator[ ](int nindex);
```  
  
### <a name="parameters"></a>Parâmetros  
 `nIndex`  
 Índice de base zero de um `CString` em um conjunto de `CString`s.  
  
##  <a name="readlist"></a>  CRecentFileList::ReadList  
 Lê a lista de arquivos (MRU) do registro ou do aplicativo usados mais recentemente. Arquivo INI.  
  
```  
virtual void ReadList();
```  
  
##  <a name="remove"></a>  CRecentFileList::Remove  
 Remove um arquivo da lista de arquivos MRU.  
  
```  
virtual void Remove(int nIndex);
```  
  
### <a name="parameters"></a>Parâmetros  
 `nIndex`  
 Índice de base zero do arquivo a ser removido da lista de arquivos usada recentemente (MRU).  
  
##  <a name="updatemenu"></a>  CRecentFileList::UpdateMenu  
 Atualiza a exibição do menu da lista MRU de arquivo.  
  
```  
virtual void UpdateMenu(CCmdUI* pCmdUI);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pCmdUI`  
 Um ponteiro para o [CCmdUI](../../mfc/reference/ccmdui-class.md) objeto do menu de lista de arquivos usado recentemente (MRU).  
  
##  <a name="writelist"></a>  CRecentFileList::WriteList  
 Grava a lista mais usados recentemente (MRU) arquivos no registro ou do aplicativo. Arquivo INI.  
  
```  
virtual void WriteList();
```  
  
## <a name="see-also"></a>Consulte também  
 [Gráfico da hierarquia](../../mfc/hierarchy-chart.md)



