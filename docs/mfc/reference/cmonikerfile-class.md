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
ms.openlocfilehash: fc74ad2499fcde63faa2c5859a87fd9ffd2846eb
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81319780"
---
# <a name="cmonikerfile-class"></a>Classe CMonikerFile

Representa um fluxo de dados [(IStream)](/windows/win32/api/objidl/nn-objidl-istream)nomeado por um [IMoniker](/windows/win32/api/objidl/nn-objidl-imoniker).

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
|[CMonikerFile::Fechar](#close)|Destaca-se e libera o fluxo e libera o apelido.|
|[CMonikerFile::Detach](#detach)|Destaca-se `IMoniker` deste `CMonikerFile` objeto.|
|[CMonikerFile::GetMoniker](#getmoniker)|Retorna o apelido atual.|
|[CMonikerFile::Aberto](#open)|Abre o arquivo especificado para obter um fluxo.|

### <a name="protected-methods"></a>Métodos Protegidos

|Nome|Descrição|
|----------|-----------------|
|[CMonikerFile::CreateBindContext](#createbindcontext)|Obtém o contexto de vinculação ou cria um contexto de vinculação inicializado padrão.|

## <a name="remarks"></a>Comentários

Um apelido contém informações muito semelhantes a um nome de caminho para um arquivo. Se você tiver um ponteiro para `IMoniker` a interface de um objeto de apelido, você pode obter acesso ao arquivo identificado sem ter qualquer outra informação específica sobre onde o arquivo está realmente localizado.

Derivado de `COleStreamFile` `CMonikerFile` , leva um apelido ou uma representação de corda que pode fazer em um apelido e se liga ao fluxo para o qual o apelido é um nome. Você pode então ler e escrever para esse fluxo. O objetivo `CMonikerFile` real é fornecer `IStream`acesso simples `IMoniker`ao s nomeado por para que você não `CFile` tenha que se vincular a um fluxo você mesmo, mas ainda ter funcionalidade para o fluxo.

`CMonikerFile`não pode ser usado para se ligar a qualquer outra coisa que não seja um fluxo. Se você quiser vincular-se ao armazenamento ou `IMoniker` a um objeto, você deve usar a interface diretamente.

Para obter mais informações sobre fluxos e apelidos, consulte [COleStreamFile](../../mfc/reference/colestreamfile-class.md) no *MFC Reference* e [IStream](/windows/win32/api/objidl/nn-objidl-istream) e [IMoniker](/windows/win32/api/objidl/nn-objidl-imoniker) no Windows SDK.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[Cobject](../../mfc/reference/cobject-class.md)

[Cfile](../../mfc/reference/cfile-class.md)

[Colestreamfile](../../mfc/reference/colestreamfile-class.md)

`CMonikerFile`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxole.h

## <a name="cmonikerfileclose"></a><a name="close"></a>CMonikerFile::Fechar

Chame esta função para desprender e liberar o fluxo e para liberar o apelido.

```
virtual void Close();
```

### <a name="remarks"></a>Comentários

Pode ser chamado em fluxos fechados ou já fechados.

## <a name="cmonikerfilecmonikerfile"></a><a name="cmonikerfile"></a>CMonikerFile::CMonikerFile

Constrói um objeto `CMonikerFile`.

```
CMonikerFile();
```

## <a name="cmonikerfilecreatebindcontext"></a><a name="createbindcontext"></a>CMonikerFile::CreateBindContext

Chame essa função para criar um contexto de vinculação inicializado padrão.

```
IBindCtx* CreateBindContext(CFileException* pError);
```

### <a name="parameters"></a>Parâmetros

*pError*<br/>
Um ponteiro para uma exceção de arquivo. Em caso de erro, ele será definido para a causa.

### <a name="return-value"></a>Valor retornado

Um ponteiro para o contexto de vinculação [IBindCtx](/windows/win32/api/objidl/nn-objidl-ibindctx) para vincular-se se for bem-sucedido; caso contrário, NULL. Se a instância foi `IBindHost` aberta com uma interface, `IBindHost`o contexto de vinculação será recuperado do . Se não `IBindHost` houver interface ou a interface não retornar um contexto de vinculação, um contexto de vinculação será criado. Para obter uma descrição da interface [IBindHost,](/previous-versions/windows/internet-explorer/ie-developer/platform-apis/ms775076\(v=vs.85\)) consulte o SDK do Windows.

### <a name="remarks"></a>Comentários

Um contexto de vinculação é um objeto que armazena informações sobre uma determinada operação de vinculação de apelidos. Você pode substituir essa função para fornecer um contexto de vinculação personalizado.

## <a name="cmonikerfiledetach"></a><a name="detach"></a>CMonikerFile::Detach

Chame esta função para fechar o fluxo.

```
BOOL Detach(CFileException* pError = NULL);
```

### <a name="parameters"></a>Parâmetros

*pError*<br/>
Um ponteiro para uma exceção de arquivo. Em caso de erro, ele será definido para a causa.

### <a name="return-value"></a>Valor retornado

Não zero se bem sucedido; caso contrário, 0.

## <a name="cmonikerfilegetmoniker"></a><a name="getmoniker"></a>CMonikerFile::GetMoniker

Chame esta função para recuperar um ponteiro para o apelido atual.

```
IMoniker* GetMoniker() const;
```

### <a name="return-value"></a>Valor retornado

Um ponteiro para a interface de apelido atual [(IMoniker).](/windows/win32/api/objidl/nn-objidl-imoniker)

### <a name="remarks"></a>Comentários

Como `CMonikerFile` não é uma interface, o ponteiro retornado não incrementa a contagem de `CMonikerFile` referência (através de [AddRef),](/windows/win32/api/unknwn/nf-unknwn-iunknown-addref)e o apelido é liberado quando o objeto é liberado. Se você quiser manter o apelido ou soltá-lo você mesmo, você deve. `AddRef`

## <a name="cmonikerfileopen"></a><a name="open"></a>CMonikerFile::Aberto

Ligue para esta função de membro para abrir um objeto de arquivo ou apelido.

```
virtual BOOL Open(
    LPCTSTR lpszURL,
    CFileException* pError = NULL);

virtual BOOL Open(
    IMoniker* pMoniker,
    CFileException* pError = NULL);
```

### <a name="parameters"></a>Parâmetros

*Lpszurl*<br/>
Uma URL ou nome de arquivo do arquivo a ser aberto.

*pError*<br/>
Um ponteiro para uma exceção de arquivo. Em caso de erro, ele será definido para a causa.

*pMoniker*<br/>
Um ponteiro para a `IMoniker` interface de apelido a ser usado para obter um fluxo.

### <a name="return-value"></a>Valor retornado

Não zero se bem sucedido; caso contrário, 0.

### <a name="remarks"></a>Comentários

O parâmetro *lpszURL* não pode ser usado em um Macintosh. Apenas a forma *pMoniker* de `Open` pode ser usada em um Macintosh.

Você pode usar uma URL ou um nome de arquivo para o parâmetro *lpszURL.* Por exemplo:

[!code-cpp[NVC_MFCWinInet#6](../../mfc/codesnippet/cpp/cmonikerfile-class_1.cpp)]

\- ou –

[!code-cpp[NVC_MFCWinInet#7](../../mfc/codesnippet/cpp/cmonikerfile-class_2.cpp)]

## <a name="see-also"></a>Confira também

[Classe COleStreamFile](../../mfc/reference/colestreamfile-class.md)<br/>
[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classe CAsyncMonikerFile](../../mfc/reference/casyncmonikerfile-class.md)
