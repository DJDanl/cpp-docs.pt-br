---
title: Classe CRecentFileList
ms.date: 11/04/2016
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
ms.openlocfilehash: a2102c6a39c14c548828e57ad1c49de6a5bc03dd
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81370904"
---
# <a name="crecentfilelist-class"></a>Classe CRecentFileList

Suporta o controle da lista de arquivos mais recentemente usada (MRU).

## <a name="syntax"></a>Sintaxe

```
class CRecentFileList
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[cRecentFilelist::CRecentFileList](#crecentfilelist)|Constrói um objeto `CRecentFileList`.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[cRecentFilelist::Add](#add)|Adiciona um arquivo à lista de arquivos MRU.|
|[cRecentFileList::GetDisplayName](#getdisplayname)|Fornece um nome de exibição para exibição de menu de um nome de arquivo MRU.|
|[cRecentFilelist::GetSize](#getsize)|Recupera o número de arquivos na lista de arquivos MRU.|
|[cRecentFileList::ReadList](#readlist)|Lê a lista de arquivos MRU do registro ou . Arquivo INI.|
|[cRecentFileList::Remove](#remove)|Remove um arquivo da lista de arquivos MRU.|
|[CRecentFileList::UpdateMenu](#updatemenu)|Atualiza a exibição do menu da lista de arquivos MRU.|
|[CRecentFileList::WriteList](#writelist)|Escreve a lista de arquivos MRU do registro ou . Arquivo INI.|

### <a name="public-operators"></a>Operadores públicos

|Nome|Descrição|
|----------|-----------------|
|[CRecentFileList::operador \[\]](#operator_at)|Retorna `CString` um objeto em uma determinada posição.|

## <a name="remarks"></a>Comentários

Os arquivos podem ser adicionados ou excluídos da lista de arquivos MRU, a lista de arquivos pode ser lida ou escrita no registro ou em . O arquivo INI e o menu exibindo a lista de arquivos MRU podem ser atualizados.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`CRecentFileList`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxadv.h

## <a name="crecentfilelistadd"></a><a name="add"></a>cRecentFilelist::Add

Adiciona um arquivo à lista de arquivos mais recentemente usada (MRU).

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

*Lpszpathname*<br/>
Especifica o nome do caminho a ser adicionado à lista.

*lpszAppID*<br/>
Especifica o ID do modelo do usuário do aplicativo para o aplicativo.

*Pitem*<br/>
Especifica um ponteiro para o Item Shell a ser adicionado à lista.

*Plink*<br/>
Especifica um ponteiro para Shell Link a ser adicionado à lista.

*Pidl*<br/>
Especifica o IDLIST para o item shell que deve ser adicionado à pasta de documentos recentes.

### <a name="remarks"></a>Comentários

O nome do arquivo será adicionado ao topo da lista MRU. Se o nome do arquivo já existir na lista MRU, ele será movido para o topo.

## <a name="crecentfilelistcrecentfilelist"></a><a name="crecentfilelist"></a>cRecentFilelist::CRecentFileList

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

*Nstart*<br/>
Deslocamento para a numeração na exibição de menu da lista de arquivos MRU (mais recentemente usada).

*Lpszsection*<br/>
Aponta para o nome da seção do registro ou do aplicativo. Arquivo INI onde a lista de arquivos MRU é lida e/ou escrita.

*lpszEntryFormat*<br/>
Aponta para uma seqüência de formato a ser usada para os nomes das entradas armazenadas no registro ou no aplicativo. Arquivo INI.

*Nsize*<br/>
Número máximo de arquivos na lista de arquivos MRU.

*nMaxDispLen*<br/>
Comprimento máximo, em caracteres, disponível para a exibição do menu de um nome de arquivo na lista de arquivos MRU.

### <a name="remarks"></a>Comentários

A seqüência de formato salientada por *lpszEntryFormat* deve conter "%d", que será usado para substituir o índice de cada item MRU. Por exemplo, se a `"file%d"` seqüência de `file0`formato `file1`for então, as entradas serão nomeadas , e assim por diante.

## <a name="crecentfilelistgetdisplayname"></a><a name="getdisplayname"></a>cRecentFileList::GetDisplayName

Obtém um nome de exibição para um arquivo na lista de arquivos MRU, para uso na exibição de menu da lista MRU.

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
Caminho completo do arquivo cujo nome deve ser exibido na lista de menus de arquivos MRU.

*nIndex*<br/>
Índice baseado em zero do arquivo na lista de arquivos MRU.

*lpszCurDir*<br/>
String segurando o diretório atual.

*nCurDir*<br/>
Comprimento da seqüência de diretório atual.

*bAtLeastName*<br/>
Se não zero, indica que o nome base do arquivo deve ser devolvido, mesmo que exceda o comprimento `CRecentFileList` máximo de exibição (passado como o parâmetro *nMaxDispLen* para o construtor).

### <a name="return-value"></a>Valor retornado

**FALSO** se não houver nome de arquivo no índice especificado na lista de arquivos mais recentemente usada (MRU).

### <a name="remarks"></a>Comentários

Se o arquivo estiver no diretório atual, a função deixa o diretório fora do visor. Se o nome do arquivo for muito longo, o diretório e a extensão serão despojados. Se o nome do arquivo ainda for muito longo, o nome de exibição será definido como uma seqüência de string vazia, a menos que *bAtLeastName* não seja zero.

## <a name="crecentfilelistgetsize"></a><a name="getsize"></a>cRecentFilelist::GetSize

Recupera o número de arquivos na lista de arquivos MRU.

```
int GetSize() const;
```

### <a name="return-value"></a>Valor retornado

O número de arquivos na lista de arquivos mais recentemente usada (MRU).

## <a name="crecentfilelistoperator--"></a><a name="operator_at"></a>CRecentFileList::operador [ ]

O operador de`[]`subscrição sobrecarregado `CString` retorna um único especificado pelo índice baseado em zero no *nIndex*.

```
CString& operator[ ](int nindex);
```

### <a name="parameters"></a>Parâmetros

*nIndex*<br/>
Índice baseado em `CString` zero de `CString`a em um conjunto de s.

## <a name="crecentfilelistreadlist"></a><a name="readlist"></a>cRecentFileList::ReadList

Lê a lista de arquivos mais recentemente usada (MRU) do registro ou do aplicativo . Arquivo INI.

```
virtual void ReadList();
```

## <a name="crecentfilelistremove"></a><a name="remove"></a>cRecentFileList::Remove

Remove um arquivo da lista de arquivos MRU.

```
virtual void Remove(int nIndex);
```

### <a name="parameters"></a>Parâmetros

*nIndex*<br/>
Índice baseado em zero do arquivo a ser removido da lista de arquivos mais recentemente usada (MRU).

## <a name="crecentfilelistupdatemenu"></a><a name="updatemenu"></a>CRecentFileList::UpdateMenu

Atualiza a exibição do menu da lista de arquivos MRU.

```
virtual void UpdateMenu(CCmdUI* pCmdUI);
```

### <a name="parameters"></a>Parâmetros

*pCmdUI*<br/>
Um ponteiro para o objeto [CCmdUI](../../mfc/reference/ccmdui-class.md) para o menu de lista de arquivos mais recentemente usado (MRU).

## <a name="crecentfilelistwritelist"></a><a name="writelist"></a>CRecentFileList::WriteList

Escreve a lista de arquivos mais recentemente usada (MRU) no registro ou no aplicativo . Arquivo INI.

```
virtual void WriteList();
```

## <a name="see-also"></a>Confira também

[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)
