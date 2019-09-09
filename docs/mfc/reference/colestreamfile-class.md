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
ms.openlocfilehash: 96e8fee71f02ea750fd8b33f41fd2fd517e9081e
ms.sourcegitcommit: fcb48824f9ca24b1f8bd37d647a4d592de1cc925
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/15/2019
ms.locfileid: "69503683"
---
# <a name="colestreamfile-class"></a>Classe COleStreamFile

Representa um fluxo de dados (`IStream`) em um arquivo composto como parte do armazenamento estruturado OLE.

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
|[COleStreamFile::Attach](#attach)|Associa um fluxo ao objeto.|
|[COleStreamFile::CreateMemoryStream](#creatememorystream)|Cria um fluxo da memória global e o associa ao objeto.|
|[COleStreamFile::CreateStream](#createstream)|Cria um fluxo e o associa ao objeto.|
|[COleStreamFile::Detach](#detach)|Desassocia o fluxo do objeto.|
|[COleStreamFile::GetStream](#getstream)|Retorna o fluxo atual.|
|[COleStreamFile::OpenStream](#openstream)|Abre um fluxo com segurança e o associa ao objeto.|

## <a name="remarks"></a>Comentários

Um `IStorage` objeto deve existir antes que o fluxo possa ser aberto ou criado, a menos que seja um fluxo de memória.

`COleStreamFile`os objetos são manipulados exatamente como objetos de [testcfile](../../mfc/reference/cfile-class.md) .

Para obter mais informações sobre como manipular fluxos e armazenamentos, consulte o [artigo Contêineres: Arquivos](../../mfc/containers-compound-files.md)compostos..

Para obter mais informações, consulte [IStream](/windows/win32/api/objidl/nn-objidl-istream) e [IStorage](/windows/win32/api/objidl/nn-objidl-istorage) no SDK do Windows.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[CObject](../../mfc/reference/cobject-class.md)

[CFile](../../mfc/reference/cfile-class.md)

`COleStreamFile`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** Afxole. h

##  <a name="attach"></a>  COleStreamFile::Attach

Associa o fluxo `COleStreamFile` OLE fornecido ao objeto.

```
void Attach(LPSTREAM lpStream);
```

### <a name="parameters"></a>Parâmetros

*lpStream*<br/>
Aponta para o fluxo OLE (`IStream`) a ser associado ao objeto. Não pode ser NULL.

### <a name="remarks"></a>Comentários

O objeto ainda não deve estar associado a um fluxo OLE.

Para obter mais informações, consulte [IStream](/windows/win32/api/objidl/nn-objidl-istream) no SDK do Windows.

##  <a name="colestreamfile"></a>  COleStreamFile::COleStreamFile

Cria um objeto `COleStreamFile`.

```
COleStreamFile(LPSTREAM lpStream = NULL);
```

### <a name="parameters"></a>Parâmetros

*lpStream*<br/>
Ponteiro para o fluxo OLE a ser associado ao objeto.

### <a name="remarks"></a>Comentários

Se *lpStream* for NULL, o objeto não será associado a um fluxo OLE, caso contrário, o objeto será associado ao fluxo OLE fornecido.

Para obter mais informações, consulte [IStream](/windows/win32/api/objidl/nn-objidl-istream) no SDK do Windows.

##  <a name="creatememorystream"></a>  COleStreamFile::CreateMemoryStream

Cria com segurança um novo fluxo de memória global e compartilhada em que uma falha é uma condição normal e esperada.

```
BOOL CreateMemoryStream(CFileException* pError = NULL);
```

### <a name="parameters"></a>Parâmetros

*pError*<br/>
Aponta para um objeto [CFileException](../../mfc/reference/cfileexception-class.md) ou nulo que indica o status de conclusão da operação de criação. Forneça esse parâmetro se você quiser monitorar possíveis exceções geradas ao tentar criar o fluxo.

### <a name="return-value"></a>Valor de retorno

Diferente de zero se o fluxo for criado com êxito; caso contrário, 0.

### <a name="remarks"></a>Comentários

A memória é alocada pelo subsistema OLE.

Para obter mais informações, consulte [CreateStreamOnHGlobal](/windows/win32/api/combaseapi/nf-combaseapi-createstreamonhglobal) no SDK do Windows.

##  <a name="createstream"></a>  COleStreamFile::CreateStream

Cria com segurança um novo fluxo no objeto de armazenamento fornecido em que uma falha é uma condição normal e esperada.

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
Modo de acesso a ser usado ao abrir o fluxo. Os modos exclusivo, de leitura/gravação e de criação são usados por padrão. Para obter uma lista completa dos modos disponíveis, consulte [testcfile:: RecFile](../../mfc/reference/cfile-class.md#cfile).

*pError*<br/>
Aponta para um objeto [CFileException](../../mfc/reference/cfileexception-class.md) ou nulo. Forneça esse parâmetro se você quiser monitorar possíveis exceções geradas ao tentar criar o fluxo.

### <a name="return-value"></a>Valor de retorno

Diferente de zero se o fluxo for criado com êxito; caso contrário, 0.

### <a name="remarks"></a>Comentários

Uma exceção de arquivo será gerada se a abertura falhar e *perror* não for nula.

Para obter mais informações, consulte [IStorage:: CreateStream](/windows/win32/api/objidl/nf-objidl-istorage-createstream) no SDK do Windows.

##  <a name="detach"></a>  COleStreamFile::Detach

Desassocia o fluxo do objeto sem fechar o fluxo.

```
LPSTREAM Detach();
```

### <a name="return-value"></a>Valor de retorno

Um ponteiro para o fluxo (`IStream`) que foi associado ao objeto.

### <a name="remarks"></a>Comentários

O fluxo deve ser fechado de outra maneira antes que o programa seja encerrado.

Para obter mais informações, consulte [IStream](/windows/win32/api/objidl/nn-objidl-istream) no SDK do Windows.

##  <a name="getstream"></a>  COleStreamFile::GetStream

Chame essa função para retornar um ponteiro para o fluxo atual.

```
IStream* GetStream() const;
```

### <a name="return-value"></a>Valor de retorno

Um ponteiro para a interface de fluxo atual ( [IStream](/windows/win32/api/objidl/nn-objidl-istream)).

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
Modo de acesso a ser usado ao abrir o fluxo. Os modos exclusivo e de leitura/gravação são usados por padrão. Para obter a lista completa dos modos disponíveis, consulte [testcfile:: RecFile](../../mfc/reference/cfile-class.md#cfile).

*pError*<br/>
Aponta para um objeto [CFileException](../../mfc/reference/cfileexception-class.md) ou nulo. Forneça esse parâmetro se você quiser monitorar possíveis exceções geradas ao tentar abrir o fluxo.

### <a name="return-value"></a>Valor de retorno

Diferente de zero se o fluxo for aberto com êxito; caso contrário, 0.

### <a name="remarks"></a>Comentários

Uma exceção de arquivo será gerada se a abertura falhar e *perror* não for nula.

Para obter mais informações, consulte [IStorage:: OpenStream](/windows/win32/api/objidl/nf-objidl-istorage-openstream) na SDK do Windows.

## <a name="see-also"></a>Consulte também

[Classe CFile](../../mfc/reference/cfile-class.md)<br/>
[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)
