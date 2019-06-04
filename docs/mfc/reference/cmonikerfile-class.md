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
ms.openlocfilehash: 7fb0ad3eef781be1b5ca358e825c09a88c0109e3
ms.sourcegitcommit: ecf274bcfe3a977c48745aaa243e5e731f1fdc5f
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/04/2019
ms.locfileid: "66503823"
---
# <a name="cmonikerfile-class"></a>Classe CMonikerFile

Representa um fluxo de dados ( [IStream](/windows/desktop/api/objidl/nn-objidl-istream)) nomeado por uma [IMoniker](/windows/desktop/api/objidl/nn-objidl-imoniker).

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
|[CMonikerFile::Detach](#detach)|Desanexa o `IMoniker` deste `CMonikerFile` objeto.|
|[CMonikerFile::GetMoniker](#getmoniker)|Retorna o moniker atual.|
|[CMonikerFile::Open](#open)|Abre o arquivo especificado para obter um fluxo.|

### <a name="protected-methods"></a>Métodos Protegidos

|Nome|Descrição|
|----------|-----------------|
|[CMonikerFile::CreateBindContext](#createbindcontext)|Obtém o contexto de associação ou cria um contexto de associação padrão inicializado.|

## <a name="remarks"></a>Comentários

Um identificador de origem contém informações muito parecido com um nome de caminho para um arquivo. Se você tiver um ponteiro para um objeto de moniker `IMoniker` interface, você pode obter acesso ao arquivo identificado sem a necessidade de quaisquer outras informações específicas sobre onde está localizado, na verdade, o arquivo.

Derivado `COleStreamFile`, `CMonikerFile` usa um identificador de origem ou uma representação de cadeia de caracteres que ele pode fazer em um identificador de origem e associa ao fluxo para o qual o moniker é um nome. Em seguida, você pode ler e gravar no fluxo. O verdadeiro propósito `CMonikerFile` é fornecer acesso simples às `IStream`s nomeado pelo `IMoniker`s para que você não precise associar a um fluxo por conta própria, ainda têm `CFile` funcionalidade no fluxo.

`CMonikerFile` não pode ser usado para associar a algo diferente de um fluxo. Se você deseja associar a um objeto ou de armazenamento, você deve usar o `IMoniker` interface diretamente.

Para obter mais informações sobre fluxos e identificadores de origem, consulte [COleStreamFile](../../mfc/reference/colestreamfile-class.md) na *referência da MFC* e [IStream](/windows/desktop/api/objidl/nn-objidl-istream) e [IMoniker](/windows/desktop/api/objidl/nn-objidl-imoniker) no Windows SDK.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[CObject](../../mfc/reference/cobject-class.md)

[CFile](../../mfc/reference/cfile-class.md)

[COleStreamFile](../../mfc/reference/colestreamfile-class.md)

`CMonikerFile`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxole.h

##  <a name="close"></a>  CMonikerFile::Close

Chame essa função para desanexar e liberar o fluxo de e para liberar o identificador de origem.

```
virtual void Close();
```

### <a name="remarks"></a>Comentários

Pode ser chamado em fluxos não abertos ou fechados já.

##  <a name="cmonikerfile"></a>  CMonikerFile::CMonikerFile

Constrói um objeto `CMonikerFile`.

```
CMonikerFile();
```

##  <a name="createbindcontext"></a>  CMonikerFile::CreateBindContext

Chame essa função para criar um contexto de associação padrão inicializado.

```
IBindCtx* CreateBindContext(CFileException* pError);
```

### <a name="parameters"></a>Parâmetros

*pError*<br/>
Um ponteiro para uma exceção de arquivo. Em caso de erro, ele será definido como a causa.

### <a name="return-value"></a>Valor de retorno

Um ponteiro para o contexto de associação [IBindCtx](/windows/desktop/api/objidl/nn-objidl-ibindctx) a ser associado, se for bem-sucedido; caso contrário, NULL. Se a instância foi aberta com um `IBindHost` interface, o contexto de associação é recuperado do `IBindHost`. Se não houver nenhum `IBindHost` interface ou a interface não retornar um contexto de associação, um contexto de associação é criado. Para obter uma descrição de [IBindHost](/previous-versions/windows/internet-explorer/ie-developer/platform-apis/ms775076\(v=vs.85\)) interface, consulte o SDK do Windows.

### <a name="remarks"></a>Comentários

Um contexto de associação é um objeto que armazena informações sobre uma operação de associação de moniker específico. Você pode substituir essa função para fornecer um contexto de associação personalizado.

##  <a name="detach"></a>  CMonikerFile::Detach

Chame essa função para fechar o fluxo.

```
BOOL Detach(CFileException* pError = NULL);
```

### <a name="parameters"></a>Parâmetros

*pError*<br/>
Um ponteiro para uma exceção de arquivo. Em caso de erro, ele será definido como a causa.

### <a name="return-value"></a>Valor de retorno

Diferente de zero se bem-sucedido; Caso contrário, 0.

##  <a name="getmoniker"></a>  CMonikerFile::GetMoniker

Chame essa função para recuperar um ponteiro para o moniker atual.

```
IMoniker* GetMoniker() const;
```

### <a name="return-value"></a>Valor de retorno

Um ponteiro para a interface do moniker atual ( [IMoniker](/windows/desktop/api/objidl/nn-objidl-imoniker)).

### <a name="remarks"></a>Comentários

Uma vez que `CMonikerFile` não é uma interface, o ponteiro retornado não incrementa a contagem de referência (por meio [AddRef](/windows/desktop/api/unknwn/nf-unknwn-iunknown-addref)), e o moniker é liberado quando o `CMonikerFile` objeto é liberado. Se você quiser manter o moniker ou liberá-lo, você deve `AddRef` -lo.

##  <a name="open"></a>  CMonikerFile::Open

Chame essa função de membro para abrir um objeto de arquivo ou o identificador de origem.

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
Uma URL ou o nome do arquivo a ser aberto.

*pError*<br/>
Um ponteiro para uma exceção de arquivo. Em caso de erro, ele será definido como a causa.

*pMoniker*<br/>
Um ponteiro para a interface de moniker `IMoniker` a ser usado para obter um fluxo.

### <a name="return-value"></a>Valor de retorno

Diferente de zero se bem-sucedido; Caso contrário, 0.

### <a name="remarks"></a>Comentários

O *lpszURL* parâmetro não pode ser usado em um Macintosh. Somente o *pMoniker* formulário de `Open` pode ser usado em um Macintosh.

Você pode usar uma URL ou um nome de arquivo para o *lpszURL* parâmetro. Por exemplo:

[!code-cpp[NVC_MFCWinInet#6](../../mfc/codesnippet/cpp/cmonikerfile-class_1.cpp)]

\- ou -

[!code-cpp[NVC_MFCWinInet#7](../../mfc/codesnippet/cpp/cmonikerfile-class_2.cpp)]

## <a name="see-also"></a>Consulte também

[Classe COleStreamFile](../../mfc/reference/colestreamfile-class.md)<br/>
[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classe CAsyncMonikerFile](../../mfc/reference/casyncmonikerfile-class.md)
