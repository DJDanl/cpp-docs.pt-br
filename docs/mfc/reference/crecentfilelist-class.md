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
ms.openlocfilehash: 2f8f3d1b4be06caeacc86718eafed432979b0c59
ms.sourcegitcommit: a9dcbcc85b4c28eed280d8e451c494a00d8c4c25
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/25/2018
ms.locfileid: "50069419"
---
# <a name="crecentfilelist-class"></a>Classe CRecentFileList

Dá suporte ao controle de lista de arquivos usada mais recentemente (MRU).

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
|[CRecentFileList::GetDisplayName](#getdisplayname)|Fornece um nome de exibição para a exibição do menu de um nome de arquivo do MRU.|
|[CRecentFileList::GetSize](#getsize)|Recupera o número de arquivos na lista de arquivos MRU.|
|[CRecentFileList::ReadList](#readlist)|Lê a lista de arquivos MRU do registro ou. Arquivo INI.|
|[CRecentFileList::Remove](#remove)|Remove um arquivo da lista de arquivos MRU.|
|[CRecentFileList::UpdateMenu](#updatemenu)|Atualiza a exibição do menu da lista de arquivos MRU.|
|[CRecentFileList::WriteList](#writelist)|Grava a lista de arquivos MRU do registro ou. Arquivo INI.|

### <a name="public-operators"></a>Operadores públicos

|Nome|Descrição|
|----------|-----------------|
|[[CRecentFileList::operator]](#operator_at)|Retorna um `CString` objeto em uma posição especificada.|

## <a name="remarks"></a>Comentários

Arquivos podem ser adicionados ao ou excluídos da lista de arquivos MRU, a lista de arquivos pode ser lido ou gravada no registro ou um. Arquivo INI e o menu Exibir a lista de arquivos MRU podem ser atualizado.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`CRecentFileList`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxadv.h

##  <a name="add"></a>  CRecentFileList::Add

Adiciona um arquivo à lista de arquivos usada mais recentemente (MRU).

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

*lpszPathName*<br/>
Especifica o nome do caminho a ser adicionado à lista.

*lpszAppID*<br/>
Especifica a ID de modelo de usuário do aplicativo para o aplicativo.

*pItem*<br/>
Especifica um ponteiro para o Shell do Item a ser adicionado à lista.

*pLink*<br/>
Especifica um ponteiro para o Shell do Link a ser adicionado à lista.

*PIDL*<br/>
Especifica o IDLIST para o item de shell que deve ser adicionado à pasta de documentos recentes.

### <a name="remarks"></a>Comentários

O nome do arquivo será adicionado à parte superior da lista MRU. Se o nome do arquivo já existir na lista MRU, ele será movido para a parte superior.

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

*Ncomeçar*<br/>
Deslocamento para a numeração na tela do menu de lista de arquivos MRU (recentemente usado).

*lpszSection*<br/>
Aponta para o nome da seção do registro ou do aplicativo. Arquivo INI no qual a lista de arquivos MRU é lido e/ou gravada.

*lpszEntryFormat*<br/>
Aponta para uma cadeia de caracteres de formato a ser usado para os nomes das entradas armazenadas no registro ou do aplicativo. Arquivo INI.

*nSize*<br/>
Número máximo de arquivos na lista de arquivos MRU.

*nMaxDispLen*<br/>
Comprimento máximo em caracteres, disponíveis para a exibição do menu de um nome de arquivo na lista de arquivos MRU.

### <a name="remarks"></a>Comentários

A cadeia de caracteres de formato apontada por *lpszEntryFormat* deve conter "%d", que será usado para substituir o índice de cada item MRU. Por exemplo, se a cadeia de caracteres de formato estiver `"file%d"` e em seguida, as entradas serão nomeadas `file0`, `file1`e assim por diante.

##  <a name="getdisplayname"></a>  CRecentFileList::GetDisplayName

Obtém um nome de exibição para um arquivo na lista de arquivos MRU, para uso na tela do menu de lista MRU.

```
virtual BOOL GetDisplayName(
    CString& strName,
    int nIndex,
    LPCTSTR lpszCurDir,
    int nCurDir,
    BOOL bAtLeastName = TRUE) const;
```

### <a name="parameters"></a>Parâmetros

*strName*<br/>
Caminho completo do arquivo cujo nome é a ser exibido na lista de arquivos MRU de menu.

*nIndex*<br/>
Índice baseado em zero do arquivo na lista de arquivos MRU.

*lpszCurDir*<br/>
Cadeia de caracteres que contém o diretório atual.

*nCurDir*<br/>
Comprimento da cadeia de caracteres de diretório atual.

*bAtLeastName*<br/>
Se for diferente de zero, indica que o nome base do arquivo deve ser retornado, mesmo se ele exceder o comprimento máximo de exibição (passado como o *nMaxDispLen* parâmetro para o `CRecentFileList` construtor).

### <a name="return-value"></a>Valor de retorno

**FALSE** não se há nenhum nome de arquivo no índice especificado na lista de arquivos usada mais recentemente (MRU).

### <a name="remarks"></a>Comentários

Se o arquivo estiver no diretório atual, a função deixa o diretório desativa a exibição. Se o nome do arquivo é muito longo, o diretório e a extensão são eliminados. Se o nome do arquivo ainda é muito longo, o nome de exibição é definido como uma cadeia de caracteres vazia, a menos que *bAtLeastName* é diferente de zero.

##  <a name="getsize"></a>  CRecentFileList::GetSize

Recupera o número de arquivos na lista de arquivos MRU.

```
int GetSize() const;
```

### <a name="return-value"></a>Valor de retorno

O número de arquivos atual usados mais recentemente a lista de arquivos (MRU).

##  <a name="operator_at"></a>  [CRecentFileList::operator]

O subscrito sobrecarregado (`[]`) operador retorna uma única `CString` especificado pelo índice baseado em zero na *nIndex*.

```
CString& operator[ ](int nindex);
```

### <a name="parameters"></a>Parâmetros

*nIndex*<br/>
O índice baseado em zero de um `CString` em um conjunto de `CString`s.

##  <a name="readlist"></a>  CRecentFileList::ReadList

Lê a lista de arquivos (MRU) do registro ou o aplicativo o mais usados recentemente. Arquivo INI.

```
virtual void ReadList();
```

##  <a name="remove"></a>  CRecentFileList::Remove

Remove um arquivo da lista de arquivos MRU.

```
virtual void Remove(int nIndex);
```

### <a name="parameters"></a>Parâmetros

*nIndex*<br/>
Índice baseado em zero do arquivo a ser removido da lista de arquivos usada mais recentemente (MRU).

##  <a name="updatemenu"></a>  CRecentFileList::UpdateMenu

Atualiza a exibição do menu da lista de arquivos MRU.

```
virtual void UpdateMenu(CCmdUI* pCmdUI);
```

### <a name="parameters"></a>Parâmetros

*pCmdUI*<br/>
Um ponteiro para o [CCmdUI](../../mfc/reference/ccmdui-class.md) objeto para o menu de lista de arquivos usado mais recentemente (MRU).

##  <a name="writelist"></a>  CRecentFileList::WriteList

Grava a lista mais usados recentemente (MRU) arquivos no registro ou do aplicativo. Arquivo INI.

```
virtual void WriteList();
```

## <a name="see-also"></a>Consulte também

[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)

