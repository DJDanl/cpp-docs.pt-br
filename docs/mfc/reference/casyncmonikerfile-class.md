---
title: Classe CAsyncMonikerFile
ms.date: 11/04/2016
f1_keywords:
- CAsyncMonikerFile
- AFXOLE/CAsyncMonikerFile
- AFXOLE/CAsyncMonikerFile::CAsyncMonikerFile
- AFXOLE/CAsyncMonikerFile::Close
- AFXOLE/CAsyncMonikerFile::GetBinding
- AFXOLE/CAsyncMonikerFile::GetFormatEtc
- AFXOLE/CAsyncMonikerFile::Open
- AFXOLE/CAsyncMonikerFile::CreateBindStatusCallback
- AFXOLE/CAsyncMonikerFile::GetBindInfo
- AFXOLE/CAsyncMonikerFile::GetPriority
- AFXOLE/CAsyncMonikerFile::OnDataAvailable
- AFXOLE/CAsyncMonikerFile::OnLowResource
- AFXOLE/CAsyncMonikerFile::OnProgress
- AFXOLE/CAsyncMonikerFile::OnStartBinding
- AFXOLE/CAsyncMonikerFile::OnStopBinding
helpviewer_keywords:
- CAsyncMonikerFile [MFC], CAsyncMonikerFile
- CAsyncMonikerFile [MFC], Close
- CAsyncMonikerFile [MFC], GetBinding
- CAsyncMonikerFile [MFC], GetFormatEtc
- CAsyncMonikerFile [MFC], Open
- CAsyncMonikerFile [MFC], CreateBindStatusCallback
- CAsyncMonikerFile [MFC], GetBindInfo
- CAsyncMonikerFile [MFC], GetPriority
- CAsyncMonikerFile [MFC], OnDataAvailable
- CAsyncMonikerFile [MFC], OnLowResource
- CAsyncMonikerFile [MFC], OnProgress
- CAsyncMonikerFile [MFC], OnStartBinding
- CAsyncMonikerFile [MFC], OnStopBinding
ms.assetid: 17378b66-a49a-4b67-88e3-7756ad26a2fc
ms.openlocfilehash: cd399368e46e4e9a86b4c6260e07aee07b80defb
ms.sourcegitcommit: fcb48824f9ca24b1f8bd37d647a4d592de1cc925
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/15/2019
ms.locfileid: "69507494"
---
# <a name="casyncmonikerfile-class"></a>Classe CAsyncMonikerFile

Fornece a funcionalidade para o uso de monikers assíncronos em controles ActiveX (anteriormente conhecido como controles OLE).

## <a name="syntax"></a>Sintaxe

```
class CAsyncMonikerFile : public CMonikerFile
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[CAsyncMonikerFile::CAsyncMonikerFile](#casyncmonikerfile)|Constrói um objeto `CAsyncMonikerFile`.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CAsyncMonikerFile::Close](#close)|Fecha e libera todos os recursos.|
|[CAsyncMonikerFile::GetBinding](#getbinding)|Recupera um ponteiro para a associação de transferência assíncrona.|
|[CAsyncMonikerFile::GetFormatEtc](#getformatetc)|Recupera o formato dos dados no fluxo.|
|[CAsyncMonikerFile::Open](#open)|Abre um arquivo de forma assíncrona.|

### <a name="protected-methods"></a>Métodos Protegidos

|Nome|Descrição|
|----------|-----------------|
|[CAsyncMonikerFile::CreateBindStatusCallback](#createbindstatuscallback)|Cria um objeto COM que implementa `IBindStatusCallback`.|
|[CAsyncMonikerFile::GetBindInfo](#getbindinfo)|Chamado pela biblioteca do sistema OLE para solicitar informações sobre o tipo de associação a ser criado.|
|[CAsyncMonikerFile::GetPriority](#getpriority)|Chamado pela biblioteca do sistema OLE para obter a prioridade da associação.|
|[CAsyncMonikerFile::OnDataAvailable](#ondataavailable)|Chamado para fornecer dados conforme eles ficam disponíveis para o cliente durante operações de ligação assíncronas.|
|[CAsyncMonikerFile::OnLowResource](#onlowresource)|Chamado quando os recursos estão baixos.|
|[CAsyncMonikerFile::OnProgress](#onprogress)|Chamado para indicar o progresso no processo de download de dados.|
|[CAsyncMonikerFile::OnStartBinding](#onstartbinding)|Chamado quando a associação está sendo iniciada.|
|[CAsyncMonikerFile::OnStopBinding](#onstopbinding)|Chamado quando a transferência assíncrona é interrompida.|

## <a name="remarks"></a>Comentários

Derivado de [CMonikerFile](../../mfc/reference/cmonikerfile-class.md), que, por sua vez, é derivado de [COleStreamFile](../../mfc/reference/colestreamfile-class.md), `CAsyncMonikerFile` usa a interface [IMoniker](/windows/win32/api/objidl/nn-objidl-imoniker) para acessar qualquer fluxo de dados de forma assíncrona, incluindo carregar arquivos de forma assíncrona de uma URL. Os arquivos podem ser Propriedades DataPath de controles ActiveX.

Os monikers assíncronos são usados principalmente em aplicativos habilitados para Internet e controles ActiveX para fornecer uma interface de usuário responsiva durante as transferências de arquivos. Um exemplo primo disso é o uso de [CDataPathProperty](../../mfc/reference/cdatapathproperty-class.md) para fornecer propriedades assíncronas para controles ActiveX. O `CDataPathProperty` objeto receberá repetidamente um retorno de chamada para indicar a disponibilidade de novos dados durante um processo de troca de propriedade demorada.

Para obter mais informações sobre como usar monikers assíncronos e controles ActiveX em aplicativos de Internet, consulte os seguintes artigos:

- [Primeiras etapas da Internet: Monikers assíncronos](../../mfc/asynchronous-monikers-on-the-internet.md)

- [Primeiras etapas da Internet: Controles ActiveX](../../mfc/activex-controls-on-the-internet.md)

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[CObject](../../mfc/reference/cobject-class.md)

[CFile](../../mfc/reference/cfile-class.md)

[COleStreamFile](../../mfc/reference/colestreamfile-class.md)

[CMonikerFile](../../mfc/reference/cmonikerfile-class.md)

`CAsyncMonikerFile`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** Afxole. h

##  <a name="casyncmonikerfile"></a>  CAsyncMonikerFile::CAsyncMonikerFile

Constrói um objeto `CAsyncMonikerFile`.

```
CAsyncMonikerFile();
```

### <a name="remarks"></a>Comentários

Ele não cria a `IBindHost` interface. `IBindHost`será usado somente se você fornecê-lo na `Open` função de membro.

Para obter uma descrição da `IBindHost` interface, consulte a SDK do Windows.

##  <a name="close"></a>  CAsyncMonikerFile::Close

Chame essa função para fechar e liberar todos os recursos.

```
virtual void Close();
```

### <a name="remarks"></a>Comentários

Pode ser chamado em arquivos não abertos ou já fechados.

##  <a name="createbindstatuscallback"></a>  CAsyncMonikerFile::CreateBindStatusCallback

Cria um objeto COM que implementa `IBindStatusCallback`.

```
virtual IUnknown* CreateBindStatusCallback(IUnknown* pUnkControlling);
```

### <a name="parameters"></a>Parâmetros

*pUnkControlling*<br/>
Um ponteiro para o controle desconhecido (o externo `IUnknown`) ou nulo se a agregação não estiver sendo usada.

### <a name="return-value"></a>Valor de retorno

Se *pUnkControlling* não for NULL, a função retornará um ponteiro para o interior `IUnknown` em um novo objeto com com `IBindStatusCallback`suporte para. Se `pUnkControlling` for NULL, a função retornará um ponteiro para um `IUnknown` em um novo objeto com com `IBindStatusCallback`suporte para.

### <a name="remarks"></a>Comentários

`CAsyncMonikerFile`requer um objeto COM que implementa `IBindStatusCallback`. O MFC implementa tal objeto e é agregável. Você pode substituir `CreateBindStatusCallback` para retornar seu próprio objeto com. O objeto com pode agregar a implementação do MFC `CreateBindStatusCallback` chamando com o controle desconhecido do seu objeto com. Objetos com implementados usando `CCmdTarget` o suporte com podem recuperar o controle desconhecido `CCmdTarget::GetControllingUnknown`usando.

Como alternativa, o objeto COM pode ser delegado à implementação do MFC chamando `CreateBindStatusCallback( NULL )`.

Chamadas`CreateBindStatusCallback` [CAsyncMonikerFile:: Open](#open) .

Para obter mais informações sobre monikers assíncronos e Associação assíncrona, consulte a interface [IBindStatusCallback](/previous-versions/windows/internet-explorer/ie-developer/platform-apis/ms775060\(v=vs.85\)) e [como funciona a associação assíncrona e o armazenamento](/windows/win32/Stg/how-asynchronous-binding-and-storage-work). Para obter uma discussão sobre agregação, consulte [agregação](/windows/win32/com/aggregation). Todos os três tópicos estão no SDK do Windows.

##  <a name="getbindinfo"></a>  CAsyncMonikerFile::GetBindInfo

Chamado do cliente de um moniker assíncrono para informar ao moniker assíncrono como ele deseja associar.

```
virtual DWORD GetBindInfo() const;
```

### <a name="return-value"></a>Valor de retorno

Recupera as configurações para `IBindStatusCallBack`. Para obter uma descrição da `IBindStatusCallback` interface, consulte a SDK do Windows.

### <a name="remarks"></a>Comentários

A implementação padrão define a associação como assíncrona, para usar um meio de armazenamento (um fluxo) e para usar o modelo de envio de dados por push. Substitua essa função se desejar alterar o comportamento da associação.

Um motivo para fazer isso seria ligar usando o modelo de pull de dados em vez do modelo de envio de dados por push. Em um modelo de pull de dados, o cliente orienta a operação de associação e o moniker só fornece dados ao cliente quando ele é lido. Em um modelo de push de dados, o moniker orienta a operação de vinculação assíncrona e notifica continuamente o cliente sempre que novos dados estiverem disponíveis.

##  <a name="getbinding"></a>  CAsyncMonikerFile::GetBinding

Chame essa função para recuperar um ponteiro para a associação de transferência assíncrona.

```
IBinding* GetBinding() const;
```

### <a name="return-value"></a>Valor de retorno

Um ponteiro para a `IBinding` interface fornecida quando a transferência assíncrona é iniciada. Retornará NULL se por algum motivo a transferência não puder ser feita de forma assíncrona.

### <a name="remarks"></a>Comentários

Isso permite que você controle o processo de transferência de dados `IBinding` por meio da interface, por `IBinding::Abort`exemplo `IBinding::Pause`, com `IBinding::Resume`, e.

Para obter uma descrição da `IBinding` interface, consulte a SDK do Windows.

##  <a name="getformatetc"></a>  CAsyncMonikerFile::GetFormatEtc

Chame essa função para recuperar o formato dos dados no fluxo.

```
FORMATETC* GetFormatEtc() const;
```

### <a name="return-value"></a>Valor de retorno

Um ponteiro para o [FORMATETC](/windows/win32/api/objidl/ns-objidl-formatetc) de estrutura do Windows para o fluxo aberto no momento. Retornará NULL se o moniker não tiver sido associado, se não for assíncrono, ou se a operação assíncrona não tiver começado.

##  <a name="getpriority"></a>  CAsyncMonikerFile::GetPriority

Chamado do cliente de um moniker assíncrono, pois o processo de associação começa a receber a prioridade dada ao thread para a operação de associação.

```
virtual LONG GetPriority() const;
```

### <a name="return-value"></a>Valor de retorno

A prioridade na qual a transferência assíncrona ocorrerá. Um dos sinalizadores de prioridade de thread padrão: THREAD_PRIORITY_ABOVE_NORMAL, THREAD_PRIORITY_BELOW_NORMAL, THREAD_PRIORITY_HIGHEST, THREAD_PRIORITY_IDLE, THREAD_PRIORITY_LOWEST, THREAD_PRIORITY_NORMAL e THREAD_PRIORITY_TIME_CRITICAL. Consulte a função [SetThreadPriority](/windows/win32/api/processthreadsapi/nf-processthreadsapi-setthreadpriority) do Windows para obter uma descrição desses valores.

### <a name="remarks"></a>Comentários

`GetPriority`Não deve ser chamado diretamente. THREAD_PRIORITY_NORMAL é retornado pela implementação padrão.

##  <a name="ondataavailable"></a>  CAsyncMonikerFile::OnDataAvailable

Um moniker assíncrono chama `OnDataAvailable` para fornecer dados ao cliente conforme ele se torna disponível, durante operações de ligação assíncronas.

```
virtual void OnDataAvailable(DWORD dwSize, DWORD bscfFlag);
```

### <a name="parameters"></a>Parâmetros

*dwSize*<br/>
A quantidade cumulativa (em bytes) de dados disponíveis desde o início da associação. Pode ser zero, indicando que a quantidade de dados não é relevante para a operação ou que nenhum valor específico se tornou disponível.

*bscfFlag*<br/>
Um valor de enumeração BSCF. Pode ser um ou mais dos seguintes valores:

- BSCF_FIRSTDATANOTIFICATION identifica a primeira chamada para `OnDataAvailable` para uma determinada operação de ligação.

- BSCF_INTERMEDIATEDATANOTIFICATION identifica uma chamada intermediária para `OnDataAvailable` para uma operação de associação.

- BSCF_LASTDATANOTIFICATION identifica a última chamada para `OnDataAvailable` para uma operação de associação.

### <a name="remarks"></a>Comentários

A implementação padrão dessa função não faz nada. Consulte o exemplo a seguir para obter uma implementação de exemplo.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCWinInet#5](../../mfc/codesnippet/cpp/casyncmonikerfile-class_1.cpp)]

##  <a name="onlowresource"></a>  CAsyncMonikerFile::OnLowResource

Chamado pelo moniker quando os recursos estão baixos.

```
virtual void OnLowResource();
```

### <a name="remarks"></a>Comentários

As chamadas `GetBinding( )-> Abort( )`de implementação padrão.

##  <a name="onprogress"></a>  CAsyncMonikerFile::OnProgress

Chamado pelo moniker repetidamente para indicar o progresso atual dessa operação de ligação, normalmente em intervalos razoáveis durante uma operação demorada.

```
virtual void OnProgress(
    ULONG ulProgress,
    ULONG ulProgressMax,
    ULONG ulStatusCode,
    LPCTSTR szStatusText);
```

### <a name="parameters"></a>Parâmetros

*ulProgress*<br/>
Indica o progresso atual da operação de associação relativa ao máximo esperado indicado em *ulProgressMax*.

*ulProgressMax*<br/>
Indica o valor máximo esperado de *ulProgress* para a duração de chamadas para `OnProgress` para esta operação.

*ulStatusCode*<br/>
Fornece informações adicionais sobre o progresso da operação de associação. Os `BINDSTATUS` valores válidos são obtidos da enumeração. Consulte comentários para obter os valores possíveis.

*szStatusText*<br/>
Informações sobre o progresso atual, dependendo do valor de *ulStatusCode*. Consulte comentários para obter os valores possíveis.

### <a name="remarks"></a>Comentários

Os valores possíveis para *ulStatusCode* (e *szStatusText* para cada valor) são:

|||
|-|-|
|BINDSTATUS_FINDINGRESOURCE  |A operação de associação está encontrando o recurso que contém o objeto ou armazenamento ao qual está sendo associado. O *szStatusText* fornece o nome de exibição do recurso que está sendo pesquisado (por exemplo, "www.Microsoft.com").  |
|BINDSTATUS_CONNECTING  |A operação de associação está se conectando ao recurso que contém o objeto ou armazenamento que está sendo associado. O *szStatusText* fornece o nome de exibição do recurso que está sendo conectado (por exemplo, um endereço IP).  |
|BINDSTATUS_SENDINGREQUEST|A operação de associação está solicitando o objeto ou armazenamento que está sendo associado. O *szStatusText* fornece o nome de exibição do objeto (por exemplo, um nome de arquivo).|
|BINDSTATUS_REDIRECTING  |A operação de associação foi redirecionada para um local de dados diferente. O *szStatusText* fornece o nome de exibição do novo local de dados.  |
|BINDSTATUS_USINGCACHEDCOPY  |A operação de associação está recuperando o objeto ou armazenamento solicitado de uma cópia armazenada em cache. O *szStatusText* é nulo.  |
|BINDSTATUS_BEGINDOWNLOADDATA  |A operação de associação começou a receber o objeto ou armazenamento que está sendo associado. O *szStatusText* fornece o nome de exibição do local de dados.|
|BINDSTATUS_DOWNLOADINGDATA  |A operação de Associação continua a receber o objeto ou armazenamento que está sendo associado. O *szStatusText* fornece o nome de exibição do local de dados.  |
|BINDSTATUS_ENDDOWNLOADDATA  |A operação de associação terminou de receber o objeto ou armazenamento que está sendo associado. O *szStatusText* fornece o nome de exibição do local de dados.  |
|BINDSTATUS_CLASSIDAVAILABLE  |Uma instância do objeto que está sendo associado está prestes a ser criada. O *szStatusText* fornece o CLSID do novo objeto no formato de cadeia de caracteres, permitindo ao cliente uma oportunidade de cancelar a operação de associação, se desejado.  |

##  <a name="onstartbinding"></a>  CAsyncMonikerFile::OnStartBinding

Substitua essa função em suas classes derivadas para executar ações quando a associação estiver sendo iniciada.

```
virtual void OnStartBinding();
```

### <a name="remarks"></a>Comentários

Essa função é chamada de volta pelo moniker. A implementação padrão não faz nada.

##  <a name="onstopbinding"></a>  CAsyncMonikerFile::OnStopBinding

Chamado pelo moniker no final da operação de associação.

```
virtual void OnStopBinding(HRESULT hresult, LPCTSTR szError);
```

### <a name="parameters"></a>Parâmetros

*hresult*<br/>
Um HRESULT que é o valor de erro ou de aviso.

*szErrort*<br/>
Uma cadeia de caracteres que descreve o erro.

### <a name="remarks"></a>Comentários

Substitua essa função para executar ações quando a transferência for interrompida. Por padrão, a função é `IBinding`liberada.

Para obter uma descrição da `IBinding` interface, consulte a SDK do Windows.

##  <a name="open"></a>  CAsyncMonikerFile::Open

Chame essa função de membro para abrir um arquivo de forma assíncrona.

```
virtual BOOL Open(
    LPCTSTR lpszURL,
    CFileException* pError = NULL);

virtual BOOL Open(
    IMoniker* pMoniker,
    CFileException* pError = NULL);

virtual BOOL Open(
    LPCTSTR lpszURL,
    IBindHost* pBindHost,
    CFileException* pError = NULL);

virtual BOOL Open(
    IMoniker* pMoniker,
    IBindHost* pBindHost,
    CFileException* pError = NULL);

virtual BOOL Open(
    LPCTSTR lpszURL,
    IServiceProvider* pServiceProvider,
    CFileException* pError = NULL);

virtual BOOL Open(
    IMoniker* pMoniker,
    IServiceProvider* pServiceProvider,
    CFileException* pError = NULL);

virtual BOOL Open(
    LPCTSTR lpszURL,
    IUnknown* pUnknown,
    CFileException* pError = NULL);

virtual BOOL Open(
    IMoniker* pMoniker,
    IUnknown* pUnknown,
    CFileException* pError = NULL);
```

### <a name="parameters"></a>Parâmetros

*lpszURL*<br/>
Um ponteiro para o arquivo a ser aberto de forma assíncrona. O arquivo pode ser qualquer URL ou nome de arquivo válido.

*pError*<br/>
Um ponteiro para as exceções de arquivo. No caso de um erro, ele será definido como a causa.

*pMoniker*<br/>
Um ponteiro para a interface `IMoniker`de moniker assíncrona, um moniker preciso que é a combinação do próprio moniker do documento, que você pode recuperar com `IOleClientSite::GetMoniker(OLEWHICHMK_CONTAINER)`e um moniker criado a partir do nome do caminho. O controle pode usar esse moniker para associar, mas esse não é o moniker que o controle deve salvar.

*pBindHost*<br/>
Um ponteiro para a `IBindHost` interface que será usado para criar o moniker a partir de um nome de caminho potencialmente relativo. Se o host de associação for inválido ou não fornecer um moniker, a chamada será padronizada `Open(lpszFileName,pError)`como. Para obter uma descrição da `IBindHost` interface, consulte a SDK do Windows.

*pServiceProvider*<br/>
Um ponteiro para a interface `IServiceProvider`. Se o provedor de serviços for inválido ou não fornecer o serviço para `IBindHost`, a chamada será padronizada `Open(lpszFileName,pError)`como.

*pUnknown*<br/>
Um ponteiro para a interface `IUnknown`. Se `IServiceProvider` for encontrado, a função consultará `IBindHost`para. Se o provedor de serviços for inválido ou não fornecer o serviço para `IBindHost`, a chamada será padronizada `Open(lpszFileName,pError)`como.

### <a name="return-value"></a>Valor de retorno

Diferente de zero se o arquivo for aberto com êxito; caso contrário, 0.

### <a name="remarks"></a>Comentários

Essa chamada inicia o processo de associação.

Você pode usar uma URL ou um nome de arquivo para o parâmetro *lpszUrl* . Por exemplo:

[!code-cpp[NVC_MFCWinInet#6](../../mfc/codesnippet/cpp/casyncmonikerfile-class_2.cpp)]

\- ou -

[!code-cpp[NVC_MFCWinInet#7](../../mfc/codesnippet/cpp/casyncmonikerfile-class_3.cpp)]

## <a name="see-also"></a>Consulte também

[Classe CMonikerFile](../../mfc/reference/cmonikerfile-class.md)<br/>
[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classe CMonikerFile](../../mfc/reference/cmonikerfile-class.md)<br/>
[Classe CDataPathProperty](../../mfc/reference/cdatapathproperty-class.md)
