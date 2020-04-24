---
title: Classe COleStreamFile
ms.date: 11/04/2016
f1_keywords:
- COleStreamFile
- AFXOLE/COleStreamFile
- AFXOLE/COleStreamFile::COleStreamFile
- AFXOLE/COleStreamFile::Attach
- AFXOLE/COleStreamFile::CreateMemoryStream
- AFXOLE/COleStreamFile::CreateStream
- AFXOLE/COleStreamFile::Detach
- AFXOLE/COleStreamFile::GetStream
- AFXOLE/COleStreamFile::OpenStream
helpviewer_keywords:
- COleStreamFile [MFC], COleStreamFile
- COleStreamFile [MFC], Attach
- COleStreamFile [MFC], CreateMemoryStream
- COleStreamFile [MFC], CreateStream
- COleStreamFile [MFC], Detach
- COleStreamFile [MFC], GetStream
- COleStreamFile [MFC], OpenStream
ms.assetid: e4f93698-e17c-4a18-a7c0-4b4df8eb4d93
ms.openlocfilehash: 202f8381361881ce3b8b62f81da5bfb81a1f952d
ms.sourcegitcommit: 7a6116e48c3c11b97371b8ae4ecc23adce1f092d
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/22/2020
ms.locfileid: "81753749"
---
# <a name="colestreamfile-class"></a>Classe COleStreamFile

Representa um fluxo de`IStream`dados ( ) em um arquivo composto como parte do Armazenamento Estruturado OLE.

## <a name="syntax"></a>Sintaxe

```
class COleStreamFile : public CFile
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[COleStreamFile::COleStreamFile](#colestreamfile)|Constrói um objeto `COleStreamFile`.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[COleStreamFile::Anexar](#attach)|Associa um fluxo com o objeto.|
|[COleStreamFile::CreateMemoryStream](#creatememorystream)|Cria um fluxo da memória global e o associa ao objeto.|
|[COleStreamFile::CreateStream](#createstream)|Cria um fluxo e o associa ao objeto.|
|[COleStreamFile::Detach](#detach)|Desassocia o fluxo do objeto.|
|[COleStreamFile::GetStream](#getstream)|Retorna o fluxo atual.|
|[COleStreamFile::OpenStream](#openstream)|Abre com segurança um fluxo e o associa ao objeto.|

## <a name="remarks"></a>Comentários

Um `IStorage` objeto deve existir antes que o fluxo possa ser aberto ou criado, a menos que seja um fluxo de memória.

`COleStreamFile`objetos são manipulados exatamente como objetos [CFile.](../../mfc/reference/cfile-class.md)

Para obter mais informações sobre a manipulação de fluxos e armazenamentos, consulte o artigo [Containers: Compound Files](../../mfc/containers-compound-files.md)..

Para obter mais informações, consulte [IStream](/windows/win32/api/objidl/nn-objidl-istream) e [IStorage](/windows/win32/api/objidl/nn-objidl-istorage) no SDK do Windows.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[Cobject](../../mfc/reference/cobject-class.md)

[Cfile](../../mfc/reference/cfile-class.md)

`COleStreamFile`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxole.h

## <a name="colestreamfileattach"></a><a name="attach"></a>COleStreamFile::Anexar

Associa o fluxo OLE `COleStreamFile` fornecido com o objeto.

```cpp
void Attach(LPSTREAM lpStream);
```

### <a name="parameters"></a>Parâmetros

*lpStream*<br/>
Aponta para o fluxo`IStream`OLE ( ) a ser associado com o objeto. Não pode ser NULL.

### <a name="remarks"></a>Comentários

O objeto ainda não deve ser associado a um fluxo OLE.

Para obter mais informações, consulte [IStream](/windows/win32/api/objidl/nn-objidl-istream) no Windows SDK.

## <a name="colestreamfilecolestreamfile"></a><a name="colestreamfile"></a>COleStreamFile::COleStreamFile

Cria um objeto `COleStreamFile`.

```
COleStreamFile(LPSTREAM lpStream = NULL);
```

### <a name="parameters"></a>Parâmetros

*lpStream*<br/>
Ponteiro para o fluxo OLE a ser associado com o objeto.

### <a name="remarks"></a>Comentários

Se *o lpStream* for NULL, o objeto não está associado a um fluxo OLE, caso contrário, o objeto está associado ao fluxo OLE fornecido.

Para obter mais informações, consulte [IStream](/windows/win32/api/objidl/nn-objidl-istream) no Windows SDK.

## <a name="colestreamfilecreatememorystream"></a><a name="creatememorystream"></a>COleStreamFile::CreateMemoryStream

Com segurança cria um novo fluxo fora da memória global compartilhada onde uma falha é uma condição normal e esperada.

```
BOOL CreateMemoryStream(CFileException* pError = NULL);
```

### <a name="parameters"></a>Parâmetros

*pError*<br/>
Aponta para um objeto [CFileException](../../mfc/reference/cfileexception-class.md) ou NULL que indica o status de conclusão da operação criar. Forneça este parâmetro se quiser monitorar possíveis exceções geradas ao tentar criar o fluxo.

### <a name="return-value"></a>Valor retornado

Não zero se o fluxo for criado com sucesso; caso contrário, 0.

### <a name="remarks"></a>Comentários

A memória é alocada pelo subsistema OLE.

Para obter mais informações, consulte [CreateStreamOnHGlobal](/windows/win32/api/combaseapi/nf-combaseapi-createstreamonhglobal) no Windows SDK.

## <a name="colestreamfilecreatestream"></a><a name="createstream"></a>COleStreamFile::CreateStream

Cria com segurança um novo fluxo no objeto de armazenamento fornecido onde uma falha é uma condição normal e esperada.

```
BOOL CreateStream(
    LPSTORAGE lpStorage,
    LPCTSTR lpszStreamName,
    DWORD nOpenFlags = modeReadWrite|shareExclusive|modeCreate,
    CFileException* pError = NULL);
```

### <a name="parameters"></a>Parâmetros

*lpArmazenamento*<br/>
Aponta para o objeto de armazenamento OLE que contém o fluxo a ser criado. Não pode ser NULL.

*lpszStreamName*<br/>
Nome do fluxo a ser criado. Não pode ser NULL.

*nOpenFlags*<br/>
Modo de acesso a ser usado ao abrir o fluxo. Os modos exclusivos, de leitura/gravação e de criação são usados por padrão. Para obter uma lista completa dos modos disponíveis, consulte [CFile::CFile](../../mfc/reference/cfile-class.md#cfile).

*pError*<br/>
Aponta para um objeto [CFileException](../../mfc/reference/cfileexception-class.md) ou NULL. Forneça este parâmetro se quiser monitorar possíveis exceções geradas ao tentar criar o fluxo.

### <a name="return-value"></a>Valor retornado

Não zero se o fluxo for criado com sucesso; caso contrário, 0.

### <a name="remarks"></a>Comentários

Uma exceção de arquivo será lançada se a abertura falhar e *pError* não for NULL.

Para obter mais informações, consulte [IStorage::CreateStream](/windows/win32/api/objidl/nf-objidl-istorage-createstream) no SDK do Windows.

## <a name="colestreamfiledetach"></a><a name="detach"></a>COleStreamFile::Detach

Desassocia o fluxo do objeto sem fechar o fluxo.

```
LPSTREAM Detach();
```

### <a name="return-value"></a>Valor retornado

Um ponteiro para`IStream`o fluxo ( ) que estava associado com o objeto.

### <a name="remarks"></a>Comentários

O fluxo deve ser fechado de alguma outra forma antes do programa terminar.

Para obter mais informações, consulte [IStream](/windows/win32/api/objidl/nn-objidl-istream) no Windows SDK.

## <a name="colestreamfilegetstream"></a><a name="getstream"></a>COleStreamFile::GetStream

Chame esta função para retornar um ponteiro ao fluxo atual.

```
IStream* GetStream() const;
```

### <a name="return-value"></a>Valor retornado

Um ponteiro para a interface de fluxo atual [(IStream).](/windows/win32/api/objidl/nn-objidl-istream)

## <a name="colestreamfileopenstream"></a><a name="openstream"></a>COleStreamFile::OpenStream

Abre um fluxo existente.

```
BOOL OpenStream(
    LPSTORAGE lpStorage,
    LPCTSTR lpszStreamName,
    DWORD nOpenFlags = modeReadWrite|shareExclusive,
    CFileException* pError = NULL);
```

### <a name="parameters"></a>Parâmetros

*lpArmazenamento*<br/>
Aponta para o objeto de armazenamento OLE que contém o fluxo a ser aberto. Não pode ser NULL.

*lpszStreamName*<br/>
Nome do córrego a ser aberto. Não pode ser NULL.

*nOpenFlags*<br/>
Modo de acesso a ser usado ao abrir o fluxo. Os modos exclusivos e de leitura/gravação são usados por padrão. Para obter a lista completa dos modos disponíveis, consulte [CFile::CFile](../../mfc/reference/cfile-class.md#cfile).

*pError*<br/>
Aponta para um objeto [CFileException](../../mfc/reference/cfileexception-class.md) ou NULL. Forneça este parâmetro se quiser monitorar possíveis exceções geradas ao tentar abrir o fluxo.

### <a name="return-value"></a>Valor retornado

Não zero se o fluxo for aberto com sucesso; caso contrário, 0.

### <a name="remarks"></a>Comentários

Uma exceção de arquivo será lançada se a abertura falhar e *pError* não for NULL.

Para obter mais informações, consulte [IStorage::OpenStream](/windows/win32/api/objidl/nf-objidl-istorage-openstream) no Windows SDK.

## <a name="see-also"></a>Confira também

[Classe CFile](../../mfc/reference/cfile-class.md)<br/>
[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)
