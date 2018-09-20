---
title: Classe COleStreamFile | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: reference
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
dev_langs:
- C++
helpviewer_keywords:
- COleStreamFile [MFC], COleStreamFile
- COleStreamFile [MFC], Attach
- COleStreamFile [MFC], CreateMemoryStream
- COleStreamFile [MFC], CreateStream
- COleStreamFile [MFC], Detach
- COleStreamFile [MFC], GetStream
- COleStreamFile [MFC], OpenStream
ms.assetid: e4f93698-e17c-4a18-a7c0-4b4df8eb4d93
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: f93b367b207730f331e4a9ae16b191f7a5314e4d
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46399594"
---
# <a name="colestreamfile-class"></a>Classe COleStreamFile

Representa um fluxo de dados (`IStream`) em um arquivo composto como parte de armazenamento estruturado OLE.

## <a name="syntax"></a>Sintaxe

```
class COleStreamFile : public CFile
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores Públicos

|Nome|Descrição|
|----------|-----------------|
|[COleStreamFile::COleStreamFile](#colestreamfile)|Constrói um objeto `COleStreamFile`.|

### <a name="public-methods"></a>Métodos Públicos

|Nome|Descrição|
|----------|-----------------|
|[COleStreamFile::Attach](#attach)|Associa um fluxo com o objeto.|
|[COleStreamFile::CreateMemoryStream](#creatememorystream)|Cria um fluxo de memória global e a associa com o objeto.|
|[COleStreamFile::CreateStream](#createstream)|Cria um fluxo e a associa com o objeto.|
|[COleStreamFile::Detach](#detach)|Desassocia o fluxo do objeto.|
|[COleStreamFile::GetStream](#getstream)|Retorna o fluxo atual.|
|[COleStreamFile::OpenStream](#openstream)|Abre um fluxo e associa o objeto com segurança.|

## <a name="remarks"></a>Comentários

Um `IStorage` objeto deve existir antes do fluxo pode ser aberto ou criado, a menos que ele é um fluxo de memória.

`COleStreamFile` os objetos são manipulados exatamente como [CFile](../../mfc/reference/cfile-class.md) objetos.

Para obter mais informações sobre a manipulação de fluxos e armazenamentos, consulte o artigo [contêineres: arquivos compostos](../../mfc/containers-compound-files.md)...

Para obter mais informações, consulte [IStream](/windows/desktop/api/objidl/nn-objidl-istream) e [IStorage](/windows/desktop/api/objidl/nn-objidl-istorage) no SDK do Windows.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[CObject](../../mfc/reference/cobject-class.md)

[CFile](../../mfc/reference/cfile-class.md)

`COleStreamFile`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxole.h

##  <a name="attach"></a>  COleStreamFile::Attach

Associa o fluxo OLE fornecido com o `COleStreamFile` objeto.

```
void Attach(LPSTREAM lpStream);
```

### <a name="parameters"></a>Parâmetros

*lpStream*<br/>
Aponta para o fluxo OLE (`IStream`) a ser associado com o objeto. Não pode ser NULL.

### <a name="remarks"></a>Comentários

O objeto não já deve estar associado um fluxo de OLE.

Para obter mais informações, consulte [IStream](/windows/desktop/api/objidl/nn-objidl-istream) no SDK do Windows.

##  <a name="colestreamfile"></a>  COleStreamFile::COleStreamFile

Cria um objeto `COleStreamFile`.

```
COleStreamFile(LPSTREAM lpStream = NULL);
```

### <a name="parameters"></a>Parâmetros

*lpStream*<br/>
Ponteiro para o fluxo OLE a ser associado com o objeto.

### <a name="remarks"></a>Comentários

Se *lpStream* for NULL, o objeto não está associado um fluxo de OLE, caso contrário, o objeto está associado com o fluxo fornecido do OLE.

Para obter mais informações, consulte [IStream](/windows/desktop/api/objidl/nn-objidl-istream) no SDK do Windows.

##  <a name="creatememorystream"></a>  COleStreamFile::CreateMemoryStream

Com segurança cria um novo fluxo fora da memória global e compartilhada em que uma falha é uma condição normal, esperada.

```
BOOL CreateMemoryStream(CFileException* pError = NULL);
```

### <a name="parameters"></a>Parâmetros

*pError*<br/>
Aponta para um [CFileException](../../mfc/reference/cfileexception-class.md) objeto ou nulo que indica o status de conclusão da operação criar. Forneça esse parâmetro se você quiser monitorar possíveis exceções geradas pela tentativa de criar o fluxo.

### <a name="return-value"></a>Valor de retorno

Diferente de zero se o fluxo é criado com êxito; Caso contrário, 0.

### <a name="remarks"></a>Comentários

A memória é alocada pelo subsistema de OLE.

Para obter mais informações, consulte [CreateStreamOnHGlobal](/windows/desktop/api/combaseapi/nf-combaseapi-createstreamonhglobal) no SDK do Windows.

##  <a name="createstream"></a>  COleStreamFile::CreateStream

Com segurança, cria um novo fluxo no objeto de armazenamento fornecida em que uma falha é uma condição normal, esperada.

```
BOOL CreateStream(
    LPSTORAGE lpStorage,
    LPCTSTR lpszStreamName,
    DWORD nOpenFlags = modeReadWrite|shareExclusive|modeCreate,
    CFileException* pError = NULL);
```

### <a name="parameters"></a>Parâmetros

*lpStorage*<br/>
Aponta para o objeto de armazenamento OLE que contém o fluxo a ser criado. Não pode ser NULL.

*lpszStreamName*<br/>
Nome do fluxo a ser criado. Não pode ser NULL.

*nOpenFlags*<br/>
Modo de acesso a ser usado ao abrir o fluxo. Leitura/gravação exclusivo e criar modos são usados por padrão. Para obter uma lista completa dos modos disponíveis, consulte [CFile::CFile](../../mfc/reference/cfile-class.md#cfile).

*pError*<br/>
Aponta para um [CFileException](../../mfc/reference/cfileexception-class.md) objeto ou nulo. Forneça esse parâmetro se você quiser monitorar possíveis exceções geradas pela tentativa de criar o fluxo.

### <a name="return-value"></a>Valor de retorno

Diferente de zero se o fluxo é criado com êxito; Caso contrário, 0.

### <a name="remarks"></a>Comentários

Uma exceção de arquivo será gerada se abrir falhar e *pError* não é nulo.

Para obter mais informações, consulte [IStorage::CreateStream](/windows/desktop/api/objidl/nf-objidl-istorage-createstream) no SDK do Windows.

##  <a name="detach"></a>  COleStreamFile::Detach

Desassocia o fluxo do objeto sem fechar fluxos.

```
LPSTREAM Detach();
```

### <a name="return-value"></a>Valor de retorno

Um ponteiro para o fluxo (`IStream`) que foi associado ao objeto.

### <a name="remarks"></a>Comentários

O fluxo deve ser fechado de alguma outra forma, antes que o programa seja encerrado.

Para obter mais informações, consulte [IStream](/windows/desktop/api/objidl/nn-objidl-istream) no SDK do Windows.

##  <a name="getstream"></a>  COleStreamFile::GetStream

Chame essa função para retornar um ponteiro para o fluxo atual.

```
IStream* GetStream() const;
```

### <a name="return-value"></a>Valor de retorno

Um ponteiro para a interface do fluxo atual ( [IStream](/windows/desktop/api/objidl/nn-objidl-istream)).

##  <a name="openstream"></a>  COleStreamFile::OpenStream

Abre um fluxo existente.

```
BOOL OpenStream(
    LPSTORAGE lpStorage,
    LPCTSTR lpszStreamName,
    DWORD nOpenFlags = modeReadWrite|shareExclusive,
    CFileException* pError = NULL);
```

### <a name="parameters"></a>Parâmetros

*lpStorage*<br/>
Aponta para o objeto de armazenamento OLE que contém o fluxo a ser aberto. Não pode ser NULL.

*lpszStreamName*<br/>
Nome do fluxo a ser aberto. Não pode ser NULL.

*nOpenFlags*<br/>
Modo de acesso a ser usado ao abrir o fluxo. Exclusivo e leitura/gravação são utilizados por padrão. Para obter uma lista dos modos disponíveis, consulte [CFile::CFile](../../mfc/reference/cfile-class.md#cfile).

*pError*<br/>
Aponta para um [CFileException](../../mfc/reference/cfileexception-class.md) objeto ou nulo. Forneça esse parâmetro se você quiser monitorar possíveis exceções geradas pela tentativa de abrir o fluxo.

### <a name="return-value"></a>Valor de retorno

Diferente de zero se o fluxo for aberto com êxito; Caso contrário, 0.

### <a name="remarks"></a>Comentários

Uma exceção de arquivo será gerada se abrir falhar e *pError* não é nulo.

Para obter mais informações, consulte [IStorage::OpenStream](/windows/desktop/api/objidl/nf-objidl-istorage-openstream) no SDK do Windows.

## <a name="see-also"></a>Consulte também

[Classe CFile](../../mfc/reference/cfile-class.md)<br/>
[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)



