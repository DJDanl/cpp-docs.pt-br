---
title: Classe CMonikerFile
ms.date: 11/04/2016
f1_keywords:
- CMonikerFile
- AFXOLE/CMonikerFile
- AFXOLE/CMonikerFile::CMonikerFile
- AFXOLE/CMonikerFile::Close
- AFXOLE/CMonikerFile::Detach
- AFXOLE/CMonikerFile::GetMoniker
- AFXOLE/CMonikerFile::Open
- AFXOLE/CMonikerFile::CreateBindContext
helpviewer_keywords:
- CMonikerFile [MFC], CMonikerFile
- CMonikerFile [MFC], Close
- CMonikerFile [MFC], Detach
- CMonikerFile [MFC], GetMoniker
- CMonikerFile [MFC], Open
- CMonikerFile [MFC], CreateBindContext
ms.assetid: 87be5966-f4f7-4235-bce2-1fa39e9417de
ms.openlocfilehash: 56283b56a1c0832d34ce23c7db47c47d9480aec8
ms.sourcegitcommit: fcb48824f9ca24b1f8bd37d647a4d592de1cc925
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/15/2019
ms.locfileid: "69504576"
---
# <a name="cmonikerfile-class"></a>Classe CMonikerFile

Representa um fluxo de dados ( [IStream](/windows/win32/api/objidl/nn-objidl-istream)) nomeado por um [IMoniker](/windows/win32/api/objidl/nn-objidl-imoniker).

## <a name="syntax"></a>Sintaxe

```
class CMonikerFile : public COleStreamFile
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[CMonikerFile::CMonikerFile](#cmonikerfile)|Constrói um objeto `CMonikerFile`.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CMonikerFile::Close](#close)|Desanexa e libera o fluxo e libera o moniker.|
|[CMonikerFile::Detach](#detach)|Desanexa o `IMoniker` `CMonikerFile` deste objeto.|
|[CMonikerFile::GetMoniker](#getmoniker)|Retorna o moniker atual.|
|[CMonikerFile::Open](#open)|Abre o arquivo especificado para obter um fluxo.|

### <a name="protected-methods"></a>Métodos Protegidos

|Nome|Descrição|
|----------|-----------------|
|[CMonikerFile::CreateBindContext](#createbindcontext)|Obtém o contexto de associação ou cria um contexto de associação inicializado padrão.|

## <a name="remarks"></a>Comentários

Um moniker contém informações muito parecidas com um nome de caminho para um arquivo. Se você tiver um ponteiro para a interface de um `IMoniker` objeto de moniker, poderá obter acesso ao arquivo identificado sem ter outras informações específicas sobre onde o arquivo está realmente localizado.

Derivado de `COleStreamFile`, `CMonikerFile` usa um moniker ou uma representação de cadeia de caracteres que ele pode transformar em um moniker e é associado ao fluxo para o qual o moniker é um nome. Você pode ler e gravar nesse fluxo. A verdadeira finalidade do `CMonikerFile` é fornecer acesso simples aos `IStream`s nomeados por `IMoniker`s para que você não precise se associar a um fluxo por conta própria, mas `CFile` tenha a funcionalidade para o fluxo.

`CMonikerFile`Não pode ser usado para associar qualquer coisa que não seja um fluxo. Se você quiser associar ao armazenamento ou a um objeto, deverá usar a `IMoniker` interface diretamente.

Para obter mais informações sobre fluxos e monikers, consulte [COleStreamFile](../../mfc/reference/colestreamfile-class.md) na *referência do MFC* e [IStream](/windows/win32/api/objidl/nn-objidl-istream) e [IMoniker](/windows/win32/api/objidl/nn-objidl-imoniker) no SDK do Windows.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[CObject](../../mfc/reference/cobject-class.md)

[CFile](../../mfc/reference/cfile-class.md)

[COleStreamFile](../../mfc/reference/colestreamfile-class.md)

`CMonikerFile`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** Afxole. h

##  <a name="close"></a>  CMonikerFile::Close

Chame essa função para desanexar e liberar o fluxo e liberar o moniker.

```
virtual void Close();
```

### <a name="remarks"></a>Comentários

Pode ser chamado em fluxos não abertos ou já fechados.

##  <a name="cmonikerfile"></a>  CMonikerFile::CMonikerFile

Constrói um objeto `CMonikerFile`.

```
CMonikerFile();
```

##  <a name="createbindcontext"></a>  CMonikerFile::CreateBindContext

Chame essa função para criar um contexto de ligação inicializado padrão.

```
IBindCtx* CreateBindContext(CFileException* pError);
```

### <a name="parameters"></a>Parâmetros

*pError*<br/>
Um ponteiro para uma exceção de arquivo. No caso de um erro, ele será definido como a causa.

### <a name="return-value"></a>Valor de retorno

Um ponteiro para o contexto de associação [IBindCtx](/windows/win32/api/objidl/nn-objidl-ibindctx) para associar com se bem-sucedido; caso contrário, NULL. Se a instância foi aberta com uma `IBindHost` interface, o contexto de associação é recuperado `IBindHost`do. Se não houver nenhuma `IBindHost` interface ou a interface falhar ao retornar um contexto de ligação, um contexto de associação será criado. Para obter uma descrição da interface [IBindHost](/previous-versions/windows/internet-explorer/ie-developer/platform-apis/ms775076\(v=vs.85\)) , consulte a SDK do Windows.

### <a name="remarks"></a>Comentários

Um contexto de associação é um objeto que armazena informações sobre uma operação de associação de moniker específica. Você pode substituir essa função para fornecer um contexto de associação personalizado.

##  <a name="detach"></a>  CMonikerFile::Detach

Chame essa função para fechar o fluxo.

```
BOOL Detach(CFileException* pError = NULL);
```

### <a name="parameters"></a>Parâmetros

*pError*<br/>
Um ponteiro para uma exceção de arquivo. No caso de um erro, ele será definido como a causa.

### <a name="return-value"></a>Valor de retorno

Diferente de zero, se for bem-sucedido; caso contrário, 0.

##  <a name="getmoniker"></a>  CMonikerFile::GetMoniker

Chame essa função para recuperar um ponteiro para o moniker atual.

```
IMoniker* GetMoniker() const;
```

### <a name="return-value"></a>Valor de retorno

Um ponteiro para a interface do moniker atual ( [IMoniker](/windows/win32/api/objidl/nn-objidl-imoniker)).

### <a name="remarks"></a>Comentários

Como `CMonikerFile` não é uma interface, o ponteiro retornado não incrementa a contagem de referência (por meio de [AddRef](/windows/win32/api/unknwn/nf-unknwn-iunknown-addref)) e o moniker é liberado quando `CMonikerFile` o objeto é liberado. Se você quiser manter o moniker ou liberá-lo por conta própria, deverá `AddRef` fazê-lo.

##  <a name="open"></a>  CMonikerFile::Open

Chame essa função de membro para abrir um arquivo ou objeto de moniker.

```
virtual BOOL Open(
    LPCTSTR lpszURL,
    CFileException* pError = NULL);

virtual BOOL Open(
    IMoniker* pMoniker,
    CFileException* pError = NULL);
```

### <a name="parameters"></a>Parâmetros

*lpszURL*<br/>
Uma URL ou nome do arquivo a ser aberto.

*pError*<br/>
Um ponteiro para uma exceção de arquivo. No caso de um erro, ele será definido como a causa.

*pMoniker*<br/>
Um ponteiro para a interface `IMoniker` do moniker a ser usado para obter um fluxo.

### <a name="return-value"></a>Valor de retorno

Diferente de zero, se for bem-sucedido; caso contrário, 0.

### <a name="remarks"></a>Comentários

O parâmetro *lpszUrl* não pode ser usado em um Macintosh. Somente a forma *pMoniker* de `Open` pode ser usada em um Macintosh.

Você pode usar uma URL ou um nome de arquivo para o parâmetro *lpszUrl* . Por exemplo:

[!code-cpp[NVC_MFCWinInet#6](../../mfc/codesnippet/cpp/cmonikerfile-class_1.cpp)]

\- ou -

[!code-cpp[NVC_MFCWinInet#7](../../mfc/codesnippet/cpp/cmonikerfile-class_2.cpp)]

## <a name="see-also"></a>Consulte também

[Classe COleStreamFile](../../mfc/reference/colestreamfile-class.md)<br/>
[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classe CAsyncMonikerFile](../../mfc/reference/casyncmonikerfile-class.md)
