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
ms.openlocfilehash: 107f791505bc41b8dbf9c0374c5e3821abbc0fe3
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50669060"
---
# <a name="casyncmonikerfile-class"></a>Classe CAsyncMonikerFile

Fornece a funcionalidade para o uso de monikers assíncronos em controles ActiveX (anteriormente conhecido como controles OLE).

## <a name="syntax"></a>Sintaxe

```
class CAsyncMonikerFile : public CMonikerFile
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores Públicos

|Nome|Descrição|
|----------|-----------------|
|[CAsyncMonikerFile::CAsyncMonikerFile](#casyncmonikerfile)|Constrói um objeto `CAsyncMonikerFile`.|

### <a name="public-methods"></a>Métodos Públicos

|Nome|Descrição|
|----------|-----------------|
|[CAsyncMonikerFile::Close](#close)|Fecha e libera todos os recursos.|
|[CAsyncMonikerFile::GetBinding](#getbinding)|Recupera um ponteiro para a transferência assíncrona de associação.|
|[CAsyncMonikerFile::GetFormatEtc](#getformatetc)|Recupera o formato dos dados no fluxo.|
|[CAsyncMonikerFile::Open](#open)|Abre um arquivo de forma assíncrona.|

### <a name="protected-methods"></a>Métodos Protegidos

|Nome|Descrição|
|----------|-----------------|
|[CAsyncMonikerFile::CreateBindStatusCallback](#createbindstatuscallback)|Cria um objeto COM que implementa `IBindStatusCallback`.|
|[CAsyncMonikerFile::GetBindInfo](#getbindinfo)|Chamado pela biblioteca do sistema OLE para solicitar informações sobre o tipo de associação a ser criado.|
|[CAsyncMonikerFile::GetPriority](#getpriority)|Chamado pela biblioteca do sistema OLE para obter a prioridade da associação.|
|[CAsyncMonikerFile::OnDataAvailable](#ondataavailable)|Chamado para fornecer dados assim que estiverem disponíveis para o cliente durante as operações de ligação assíncrona.|
|[CAsyncMonikerFile::OnLowResource](#onlowresource)|Chamado quando os recursos são insuficientes.|
|[CAsyncMonikerFile::OnProgress](#onprogress)|Chamado para indicar progresso no processo de download dos dados.|
|[CAsyncMonikerFile::OnStartBinding](#onstartbinding)|Chamado quando a associação está sendo inicializado.|
|[CAsyncMonikerFile::OnStopBinding](#onstopbinding)|Chamado quando a transferência assíncrona é interrompida.|

## <a name="remarks"></a>Comentários

Derivado [CMonikerFile](../../mfc/reference/cmonikerfile-class.md), que por sua vez é derivado de [COleStreamFile](../../mfc/reference/colestreamfile-class.md), `CAsyncMonikerFile` usa os [IMoniker](/windows/desktop/api/objidl/nn-objidl-imoniker) interface para acessar qualquer fluxo de dados de forma assíncrona, incluindo carregar arquivos de forma assíncrona de uma URL. Os arquivos podem ser propriedades de caminho de dados de controles ActiveX.

Monikers assíncronos são usados principalmente em aplicativos habilitados para Internet e controles ActiveX para fornecer uma interface de usuário responsiva durante transferências de arquivos. Um exemplo perfeito disso é o uso de [CDataPathProperty](../../mfc/reference/cdatapathproperty-class.md) para fornecer propriedades assíncronas para controles ActiveX. O `CDataPathProperty` objeto repetidamente receberá um retorno de chamada para indicar a disponibilidade de novos dados durante o processo de troca propriedade longo.

Para obter mais informações sobre como usar controles ActiveX e monikers assíncronos em aplicativos da Internet, consulte os seguintes artigos:

- [Internet primeiras etapas: Monikers assíncronos](../../mfc/asynchronous-monikers-on-the-internet.md)

- [Internet primeiras etapas: Controles ActiveX](../../mfc/activex-controls-on-the-internet.md)

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[CObject](../../mfc/reference/cobject-class.md)

[CFile](../../mfc/reference/cfile-class.md)

[COleStreamFile](../../mfc/reference/colestreamfile-class.md)

[CMonikerFile](../../mfc/reference/cmonikerfile-class.md)

`CAsyncMonikerFile`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxole.h

##  <a name="casyncmonikerfile"></a>  CAsyncMonikerFile::CAsyncMonikerFile

Constrói um objeto `CAsyncMonikerFile`.

```
CAsyncMonikerFile();
```

### <a name="remarks"></a>Comentários

Ele não cria o `IBindHost` interface. `IBindHost` é usado somente se você fornecer no `Open` função de membro.

Para obter uma descrição de `IBindHost` interface, consulte o SDK do Windows.

##  <a name="close"></a>  CAsyncMonikerFile::Close

Chame essa função para fechar e liberar todos os recursos.

```
virtual void Close();
```

### <a name="remarks"></a>Comentários

Pode ser chamado em arquivos não abertos ou fechados já.

##  <a name="createbindstatuscallback"></a>  CAsyncMonikerFile::CreateBindStatusCallback

Cria um objeto COM que implementa `IBindStatusCallback`.

```
virtual IUnknown* CreateBindStatusCallback(IUnknown* pUnkControlling);
```

### <a name="parameters"></a>Parâmetros

*pUnkControlling*<br/>
Um ponteiro para o controle desconhecido (externo `IUnknown`) ou nulo se a agregação não está sendo usada.

### <a name="return-value"></a>Valor de retorno

Se *pUnkControlling* não for nulo, a função retorna um ponteiro à exceção interna `IUnknown` em um objeto COM novo suporte a `IBindStatusCallback`. Se `pUnkControlling` for NULL, a função retorna um ponteiro para um `IUnknown` em um objeto COM novo suporte a `IBindStatusCallback`.

### <a name="remarks"></a>Comentários

`CAsyncMonikerFile` requer um objeto COM que implementa `IBindStatusCallback`. MFC implementa esse objeto e é agregável. Você pode substituir `CreateBindStatusCallback` para retornar o objeto COM. O objeto COM pode agregar a implementação do MFC chamando `CreateBindStatusCallback` com o controle desconhecido do objeto COM. Objetos COM implementado usando o `CCmdTarget` suporte COM pode recuperar o controle usando desconhecido `CCmdTarget::GetControllingUnknown`.

Como alternativa, seu objeto COM pode delegar a implementação do MFC chamando `CreateBindStatusCallback( NULL )`.

[CAsyncMonikerFile::Open](#open) chamadas `CreateBindStatusCallback`.

Para obter mais informações sobre monikers assíncronos e vinculação assíncrona, consulte o [IBindStatusCallback](https://msdn.microsoft.com/library/ie/ms775060) interface e [como a vinculação assíncrona e o trabalho de armazenamento](/windows/desktop/Stg/how-asynchronous-binding-and-storage-work). Para uma discussão de agregação, consulte [agregação](/windows/desktop/com/aggregation). Todos os três tópicos são no SDK do Windows.

##  <a name="getbindinfo"></a>  CAsyncMonikerFile::GetBindInfo

Chamado pelo cliente de um moniker assíncrono para informar o moniker assíncrono como ele deseja associar.

```
virtual DWORD GetBindInfo() const;
```

### <a name="return-value"></a>Valor de retorno

Recupera as definições para `IBindStatusCallBack`. Para obter uma descrição de `IBindStatusCallback` interface, consulte o SDK do Windows.

### <a name="remarks"></a>Comentários

A implementação padrão define a associação seja assíncrona, para usar uma mídia de armazenamento (um fluxo) e usar o modelo de push de dados. Substitua essa função se você quiser alterar o comportamento da associação.

Um motivo para fazer isso seria estabelecer uma ligação usando o modelo de pull de dados em vez do modelo de push de dados. Em um modelo de pull de dados, o cliente conduz a operação de associação e o moniker apenas fornece dados para o cliente quando ele é lido. Em um modelo de push de dados, o moniker conduz a operação de vinculação assíncrona e continuamente notifica o cliente sempre que novos dados estão disponíveis.

##  <a name="getbinding"></a>  CAsyncMonikerFile::GetBinding

Chame essa função para recuperar um ponteiro para a transferência assíncrona de associação.

```
IBinding* GetBinding() const;
```

### <a name="return-value"></a>Valor de retorno

Um ponteiro para o `IBinding` interface fornecida quando começa a transferência assíncrona. Retornará NULL se por algum motivo, a transferência não pode ser feitas de forma assíncrona.

### <a name="remarks"></a>Comentários

Isso permite que você controle o processo por meio de transferência de dados do `IBinding` interface, por exemplo, com `IBinding::Abort`, `IBinding::Pause`, e `IBinding::Resume`.

Para obter uma descrição de `IBinding` interface, consulte o SDK do Windows.

##  <a name="getformatetc"></a>  CAsyncMonikerFile::GetFormatEtc

Chame essa função para recuperar o formato dos dados no fluxo.

```
FORMATETC* GetFormatEtc() const;
```

### <a name="return-value"></a>Valor de retorno

Um ponteiro para a estrutura do Windows [FORMATETC](/windows/desktop/api/objidl/ns-objidl-tagformatetc) para o fluxo aberto atualmente. Retorna NULL se o moniker não foi associado, se não for assíncrona, ou se a operação assíncrona não começou.

##  <a name="getpriority"></a>  CAsyncMonikerFile::GetPriority

Chamada do cliente de um moniker assíncrono como o processo de associação começa a receber a prioridade dada ao thread para a operação de associação.

```
virtual LONG GetPriority() const;
```

### <a name="return-value"></a>Valor de retorno

A prioridade na qual será realizada a transferência assíncrona. Um dos sinalizadores de prioridade do thread padrão: THREAD_PRIORITY_ABOVE_NORMAL, THREAD_PRIORITY_BELOW_NORMAL, THREAD_PRIORITY_HIGHEST, THREAD_PRIORITY_IDLE, THREAD_PRIORITY_LOWEST, THREAD_PRIORITY_NORMAL e THREAD_PRIORITY_TIME_CRITICAL. Consulte a função do Windows [SetThreadPriority](/windows/desktop/api/processthreadsapi/nf-processthreadsapi-setthreadpriority) para obter uma descrição desses valores.

### <a name="remarks"></a>Comentários

`GetPriority` não deve ser chamado diretamente. THREAD_PRIORITY_NORMAL é retornado pela implementação do padrão.

##  <a name="ondataavailable"></a>  CAsyncMonikerFile::OnDataAvailable

Um moniker assíncrono chama `OnDataAvailable` para fornecer dados para o cliente assim que estiverem disponíveis, durante a assíncrona associar operações.

```
virtual void OnDataAvailable(DWORD dwSize, DWORD bscfFlag);
```

### <a name="parameters"></a>Parâmetros

*dwSize*<br/>
A quantidade cumulativa (em bytes) de dados disponíveis desde o início da associação. Pode ser zero, indicando que a quantidade de dados não é relevante para a operação ou que nenhum valor específico se tornou disponível.

*bscfFlag*<br/>
Um valor de enumeração BSCF. Pode ser um ou mais dos seguintes valores:

- BSCF_FIRSTDATANOTIFICATION identifica a primeira chamada para `OnDataAvailable` para uma operação de ligação determinado.

- BSCF_INTERMEDIATEDATANOTIFICATION identifica uma chamada intermediária para `OnDataAvailable` para uma operação de ligação.

- BSCF_LASTDATANOTIFICATION identifica a última chamada para `OnDataAvailable` para uma operação de ligação.

### <a name="remarks"></a>Comentários

A implementação padrão dessa função não faz nada. Consulte o exemplo a seguir para uma implementação de exemplo.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCWinInet#5](../../mfc/codesnippet/cpp/casyncmonikerfile-class_1.cpp)]

##  <a name="onlowresource"></a>  CAsyncMonikerFile::OnLowResource

Chamado pelo moniker quando os recursos são insuficientes.

```
virtual void OnLowResource();
```

### <a name="remarks"></a>Comentários

A implementação padrão chama `GetBinding( )-> Abort( )`.

##  <a name="onprogress"></a>  CAsyncMonikerFile::OnProgress

Chamado pelo moniker repetidamente para indicar o progresso atual dessa operação de associação, normalmente em intervalos razoáveis durante uma operação demorada.

```
virtual void OnProgress(
    ULONG ulProgress,
    ULONG ulProgressMax,
    ULONG ulStatusCode,
    LPCTSTR szStatusText);
```

### <a name="parameters"></a>Parâmetros

*ulProgress*<br/>
Indica o progresso atual da operação de ligação em relação ao valor máximo esperado indicado na *ulProgressMax*.

*ulProgressMax*<br/>
Indica o valor máximo esperado dos *ulProgress* para a duração de chamadas para `OnProgress` para esta operação.

*ulStatusCode*<br/>
Fornece informações adicionais sobre o progresso da operação de associação. Os valores válidos são tirados o `BINDSTATUS` enumeração. Consulte os comentários para os valores possíveis.

*szStatusText*<br/>
Informações sobre o progresso atual, dependendo do valor de *ulStatusCode*. Consulte os comentários para os valores possíveis.

### <a name="remarks"></a>Comentários

Os valores possíveis para *ulStatusCode* (e o *szStatusText* para cada valor) são:

|||
|-|-|
|BINDSTATUS_FINDINGRESOURCE  |A operação de associação é encontrar o recurso que contém o objeto ou o armazenamento que está sendo associada à. O *szStatusText* fornece o nome de exibição do recurso que está sendo pesquisado (por exemplo, "www.microsoft.com").  |
|BINDSTATUS_CONNECTING  |A operação de associação está se conectando ao recurso que contém o objeto ou o armazenamento que está sendo associada à. O *szStatusText* fornece o nome de exibição do recurso que está sendo conectado a (por exemplo, um endereço IP).  |
|BINDSTATUS_SENDINGREQUEST|A operação de associação está solicitando o objeto ou o armazenamento que está sendo associada à. O *szStatusText* fornece o nome de exibição do objeto (por exemplo, um nome de arquivo).|
|BINDSTATUS_REDIRECTING  |A operação de associação foi redirecionada para um local de dados diferentes. O *szStatusText* fornece o nome de exibição do novo local de dados.  |
|BINDSTATUS_USINGCACHEDCOPY  |A operação de associação está recuperando o objeto solicitado ou o armazenamento de uma cópia armazenada em cache. O *szStatusText* é NULL.  |
|BINDSTATUS_BEGINDOWNLOADDATA  |A operação de associação começou a receber o objeto ou o armazenamento que está sendo associada à. O *szStatusText* fornece o nome de exibição do local de dados.|
|BINDSTATUS_DOWNLOADINGDATA  |A operação de associação continua a receber o objeto ou o armazenamento que está sendo associada à. O *szStatusText* fornece o nome de exibição do local de dados.  |
|BINDSTATUS_ENDDOWNLOADDATA  |A operação de associação terminou de receber o objeto ou o armazenamento que está sendo associada à. O *szStatusText* fornece o nome de exibição do local de dados.  |
|BINDSTATUS_CLASSIDAVAILABLE  |Uma instância do objeto que está sendo associada à está prestes a ser criado. O *szStatusText* fornece o CLSID do novo objeto no formato de cadeia de caracteres, permitindo ao cliente uma oportunidade de cancelar a operação de associação, se desejado.  |

##  <a name="onstartbinding"></a>  CAsyncMonikerFile::OnStartBinding

Substitua essa função em suas classes derivadas para executar ações quando a associação está sendo inicializado.

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

*HRESULT*<br/>
Um HRESULT que é o valor de aviso ou erro.

*szErrort*<br/>
Uma cadeia de caracteres que descreve o erro.

### <a name="remarks"></a>Comentários

Substitua essa função para executar ações quando a transferência é interrompida. Por padrão, a função libera `IBinding`.

Para obter uma descrição de `IBinding` interface, consulte o SDK do Windows.

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
Um ponteiro para o arquivo a ser aberto de forma assíncrona. O arquivo pode ser qualquer URL ou o nome de arquivo válido.

*pError*<br/>
Um ponteiro para as exceções de arquivo. Em caso de erro, ele será definido como a causa.

*pMoniker*<br/>
Um ponteiro para a interface assíncrona do moniker `IMoniker`, um identificador de origem exato que é a combinação do moniker do documento, que você pode recuperar com `IOleClientSite::GetMoniker(OLEWHICHMK_CONTAINER)`e um moniker criado do nome do caminho. O controle pode usar esse moniker para associar, mas isso não é o moniker do que controle deve salvar.

*pBindHost*<br/>
Um ponteiro para o `IBindHost` interface que será usado para criar o identificador de origem a partir de um nome de caminho relativo potencialmente. Se o host de associação é inválido ou não fornece um moniker, chamada assume como padrão `Open(lpszFileName,pError)`. Para obter uma descrição de `IBindHost` interface, consulte o SDK do Windows.

*pServiceProvider*<br/>
Um ponteiro para a interface `IServiceProvider`. Se o provedor de serviço é inválido ou não fornecer o serviço para `IBindHost`, a chamada assume como padrão `Open(lpszFileName,pError)`.

*pUnknown*<br/>
Um ponteiro para a interface `IUnknown`. Se `IServiceProvider` for encontrado, a função de consulta para `IBindHost`. Se o provedor de serviço é inválido ou não fornecer o serviço para `IBindHost`, a chamada assume como padrão `Open(lpszFileName,pError)`.

### <a name="return-value"></a>Valor de retorno

Diferente de zero se o arquivo é aberto com êxito; Caso contrário, 0.

### <a name="remarks"></a>Comentários

Essa chamada inicia o processo de associação.

Você pode usar uma URL ou um nome de arquivo para o *lpszURL* parâmetro. Por exemplo:

[!code-cpp[NVC_MFCWinInet#6](../../mfc/codesnippet/cpp/casyncmonikerfile-class_2.cpp)]

\- ou -

[!code-cpp[NVC_MFCWinInet#7](../../mfc/codesnippet/cpp/casyncmonikerfile-class_3.cpp)]

## <a name="see-also"></a>Consulte também

[Classe CMonikerFile](../../mfc/reference/cmonikerfile-class.md)<br/>
[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classe CMonikerFile](../../mfc/reference/cmonikerfile-class.md)<br/>
[Classe CDataPathProperty](../../mfc/reference/cdatapathproperty-class.md)
