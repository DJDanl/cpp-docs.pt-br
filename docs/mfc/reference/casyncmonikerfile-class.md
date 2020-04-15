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
ms.openlocfilehash: 57ab463445f249b4e9393f19af103b7588962d5e
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81377001"
---
# <a name="casyncmonikerfile-class"></a>Classe CAsyncMonikerFile

Fornece funcionalidade para o uso de apelidos assíncronos em controles ActiveX (anteriormente controles OLE).

## <a name="syntax"></a>Sintaxe

```
class CAsyncMonikerFile : public CMonikerFile
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[Arquivo CAsyncMoniker::CAsyncMonikerFile](#casyncmonikerfile)|Constrói um objeto `CAsyncMonikerFile`.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CAsyncMonikerFile::Fechar](#close)|Fecha e libera todos os recursos.|
|[CAsyncMonikerFile::GetBinding](#getbinding)|Recupera um ponteiro para a vinculação de transferência assíncrona.|
|[CAsyncMonikerFile::GetFormatEtc](#getformatetc)|Recupera o formato dos dados no fluxo.|
|[Arquivo CAsyncMoniker::Aberto](#open)|Abre um arquivo assíncronamente.|

### <a name="protected-methods"></a>Métodos Protegidos

|Nome|Descrição|
|----------|-----------------|
|[CAsyncMonikerFile::CreateBindStatusCallback](#createbindstatuscallback)|Cria um objeto COM `IBindStatusCallback`que implementa .|
|[Arquivo CAsyncMoniker::GetBindInfo](#getbindinfo)|Chamado pela biblioteca do sistema OLE para solicitar informações sobre o tipo de vínculo a ser criado.|
|[CAsyncMonikerFile::GetPriority](#getpriority)|Chamado pela biblioteca do sistema OLE para obter a prioridade da vinculação.|
|[Arquivo CAsyncMoniker::OnDataAvailable](#ondataavailable)|Chamado para fornecer dados à medida que ele fica disponível para o cliente durante operações de vinculação assíncronas.|
|[Arquivo CAsyncMoniker::OnLowResource](#onlowresource)|Chamado quando os recursos são baixos.|
|[Arquivo CAsyncMoniker::OnProgress](#onprogress)|Chamado para indicar progresso no processo de download de dados.|
|[Arquivo CAsyncMoniker::OnStartBinding](#onstartbinding)|Chamado quando a ligação está começando.|
|[Arquivo CAsyncMoniker::OnStopBinding](#onstopbinding)|Chamado quando a transferência assíncrona é interrompida.|

## <a name="remarks"></a>Comentários

Derivado do [CMonikerFile](../../mfc/reference/cmonikerfile-class.md), que por sua vez é `CAsyncMonikerFile` derivado do [COleStreamFile,](../../mfc/reference/colestreamfile-class.md)usa a interface [IMoniker](/windows/win32/api/objidl/nn-objidl-imoniker) para acessar qualquer fluxo de dados de forma assíncrona, incluindo o carregamento de arquivos assíncronamente de uma URL. Os arquivos podem ser propriedades do datapath dos controles ActiveX.

Os apelidos assíncronos são usados principalmente em aplicativos habilitados para internet e controles ActiveX para fornecer uma interface de usuário responsiva durante as transferências de arquivos. Um exemplo primordial disso é o uso do [CDataPathProperty](../../mfc/reference/cdatapathproperty-class.md) para fornecer propriedades assíncronas para controles ActiveX. O `CDataPathProperty` objeto receberá repetidamente um retorno de chamada para indicar a disponibilidade de novos dados durante um longo processo de troca de propriedades.

Para obter mais informações sobre como usar apelidos assíncronos e controles ActiveX em aplicativos da Internet, consulte os seguintes artigos:

- [Primeiros Passos da Internet: Apelidos Assíncronos](../../mfc/asynchronous-monikers-on-the-internet.md)

- [Primeiros passos da Internet: Controles ActiveX](../../mfc/activex-controls-on-the-internet.md)

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[Cobject](../../mfc/reference/cobject-class.md)

[Cfile](../../mfc/reference/cfile-class.md)

[Colestreamfile](../../mfc/reference/colestreamfile-class.md)

[Cmonikerfile](../../mfc/reference/cmonikerfile-class.md)

`CAsyncMonikerFile`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxole.h

## <a name="casyncmonikerfilecasyncmonikerfile"></a><a name="casyncmonikerfile"></a>Arquivo CAsyncMoniker::CAsyncMonikerFile

Constrói um objeto `CAsyncMonikerFile`.

```
CAsyncMonikerFile();
```

### <a name="remarks"></a>Comentários

Ele não cria `IBindHost` a interface. `IBindHost`é usado apenas se você `Open` fornecê-lo na função membro.

Para obter uma `IBindHost` descrição da interface, consulte o Windows SDK.

## <a name="casyncmonikerfileclose"></a><a name="close"></a>CAsyncMonikerFile::Fechar

Chame esta função para fechar e liberar todos os recursos.

```
virtual void Close();
```

### <a name="remarks"></a>Comentários

Pode ser chamado em arquivos não abertos ou já fechados.

## <a name="casyncmonikerfilecreatebindstatuscallback"></a><a name="createbindstatuscallback"></a>CAsyncMonikerFile::CreateBindStatusCallback

Cria um objeto COM `IBindStatusCallback`que implementa .

```
virtual IUnknown* CreateBindStatusCallback(IUnknown* pUnkControlling);
```

### <a name="parameters"></a>Parâmetros

*pUnkControlling*<br/>
Um ponteiro para o controle `IUnknown`desconhecido (o exterior ) ou NULL se a agregação não estiver sendo usada.

### <a name="return-value"></a>Valor retornado

Se *pUnkControlling* não for NULL, a função `IUnknown` retorna um ponteiro `IBindStatusCallback`para o interior em um novo objeto COM suportando . Se `pUnkControlling` for NULO, a função `IUnknown` retorna um ponteiro `IBindStatusCallback`para um novo suporte a um objeto COM .

### <a name="remarks"></a>Comentários

`CAsyncMonikerFile`requer um objeto COM `IBindStatusCallback`que implemente . O MFC implementa tal objeto, e é agregavel. Você pode `CreateBindStatusCallback` substituir para devolver seu próprio objeto COM. Seu objeto COM pode agregar a `CreateBindStatusCallback` implementação do MFC ligando com o controle desconhecido do objeto COM. Os objetos `CCmdTarget` COM implementados usando o `CCmdTarget::GetControllingUnknown`suporte COM podem recuperar o controle desconhecido usando .

Alternativamente, seu objeto COM pode delegar a `CreateBindStatusCallback( NULL )`implementação do MFC ligando .

[CAsyncMonikerFile::Open](#open) `CreateBindStatusCallback`calls .

Para obter mais informações sobre apelidos assíncronos e vinculação assíncrona, consulte a interface [IBindStatusCallback](/previous-versions/windows/internet-explorer/ie-developer/platform-apis/ms775060\(v=vs.85\)) e [como funciona a vinculação e armazenamento assíncrono](/windows/win32/Stg/how-asynchronous-binding-and-storage-work). Para uma discussão sobre agregação, consulte [Agregação](/windows/win32/com/aggregation). Todos os três tópicos estão no Windows SDK.

## <a name="casyncmonikerfilegetbindinfo"></a><a name="getbindinfo"></a>Arquivo CAsyncMoniker::GetBindInfo

Chamado do cliente de um apelido assíncrono para dizer ao apelido assíncrono como ele quer se ligar.

```
virtual DWORD GetBindInfo() const;
```

### <a name="return-value"></a>Valor retornado

Recupera as configurações `IBindStatusCallBack`para . Para obter uma `IBindStatusCallback` descrição da interface, consulte o Windows SDK.

### <a name="remarks"></a>Comentários

A implementação padrão define a vinculação como assíncrona, para usar um meio de armazenamento (um fluxo) e para usar o modelo de pressão de dados. Anular esta função se você quiser alterar o comportamento da vinculação.

Uma das razões para fazer isso seria vincular usando o modelo de puxar dados em vez do modelo de empurrão de dados. Em um modelo de tração de dados, o cliente conduz a operação de vinculação, e o apelido só fornece dados ao cliente quando ele é lido. Em um modelo de empurrão de dados, o apelido impulsiona a operação de vinculação assíncrona e notifica continuamente o cliente sempre que novos dados estão disponíveis.

## <a name="casyncmonikerfilegetbinding"></a><a name="getbinding"></a>CAsyncMonikerFile::GetBinding

Chame esta função para recuperar um ponteiro para a vinculação de transferência assíncrona.

```
IBinding* GetBinding() const;
```

### <a name="return-value"></a>Valor retornado

Um ponteiro `IBinding` para a interface fornecida quando a transferência assíncrona começa. Retorna NULO se, por qualquer motivo, a transferência não puder ser feita de forma assíncrona.

### <a name="remarks"></a>Comentários

Isso permite controlar o processo de `IBinding` transferência de dados `IBinding::Abort` `IBinding::Pause`através `IBinding::Resume`da interface, por exemplo, com , e .

Para obter uma `IBinding` descrição da interface, consulte o Windows SDK.

## <a name="casyncmonikerfilegetformatetc"></a><a name="getformatetc"></a>CAsyncMonikerFile::GetFormatEtc

Chame esta função para recuperar o formato dos dados no fluxo.

```
FORMATETC* GetFormatEtc() const;
```

### <a name="return-value"></a>Valor retornado

Um ponteiro para a estrutura do Windows [FORMATETC](/windows/win32/api/objidl/ns-objidl-formatetc) para o fluxo aberto no momento. Retorna NULO se o apelido não tiver sido vinculado, se não for assíncrono ou se a operação assíncrona não tiver sido iniciada.

## <a name="casyncmonikerfilegetpriority"></a><a name="getpriority"></a>CAsyncMonikerFile::GetPriority

Chamado do cliente de um apelido assíncrono à medida que o processo de vinculação começa a receber a prioridade dada ao segmento para a operação de vinculação.

```
virtual LONG GetPriority() const;
```

### <a name="return-value"></a>Valor retornado

A prioridade na qual ocorrerá a transferência assíncrona. Uma das bandeiras prioritárias padrão: THREAD_PRIORITY_ABOVE_NORMAL, THREAD_PRIORITY_BELOW_NORMAL, THREAD_PRIORITY_HIGHEST, THREAD_PRIORITY_IDLE, THREAD_PRIORITY_LOWEST, THREAD_PRIORITY_NORMAL e THREAD_PRIORITY_TIME_CRITICAL. Consulte a função do Windows [SetThreadPriority](/windows/win32/api/processthreadsapi/nf-processthreadsapi-setthreadpriority) para obter uma descrição desses valores.

### <a name="remarks"></a>Comentários

`GetPriority`não deve ser chamado diretamente. THREAD_PRIORITY_NORMAL é devolvido pela implementação padrão.

## <a name="casyncmonikerfileondataavailable"></a><a name="ondataavailable"></a>Arquivo CAsyncMoniker::OnDataAvailable

Um apelido assíncrono chama `OnDataAvailable` para fornecer dados ao cliente à medida que ele se torna disponível, durante operações de vinculação assíncronas.

```
virtual void OnDataAvailable(DWORD dwSize, DWORD bscfFlag);
```

### <a name="parameters"></a>Parâmetros

*Dwsize*<br/>
A quantidade acumulada (em bytes) de dados disponíveis desde o início da vinculação. Pode ser zero, indicando que a quantidade de dados não é relevante para a operação, ou que nenhuma quantidade específica se tornou disponível.

*bscfFlag*<br/>
Um valor de enumeração BSCF. Pode ser um ou mais dos seguintes valores:

- BSCF_FIRSTDATANOTIFICATION identifica a primeira `OnDataAvailable` chamada para uma determinada operação de vinculação.

- BSCF_INTERMEDIATEDATANOTIFICATION identifica uma chamada `OnDataAvailable` intermediária para uma operação de vinculação.

- BSCF_LASTDATANOTIFICATION identifica a última `OnDataAvailable` chamada para uma operação de vinculação.

### <a name="remarks"></a>Comentários

A implementação padrão desta função não faz nada. Veja o exemplo a seguir para uma implementação de amostra.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCWinInet#5](../../mfc/codesnippet/cpp/casyncmonikerfile-class_1.cpp)]

## <a name="casyncmonikerfileonlowresource"></a><a name="onlowresource"></a>Arquivo CAsyncMoniker::OnLowResource

Chamado pelo apelido quando os recursos estão baixos.

```
virtual void OnLowResource();
```

### <a name="remarks"></a>Comentários

As chamadas `GetBinding( )-> Abort( )`de implementação padrão .

## <a name="casyncmonikerfileonprogress"></a><a name="onprogress"></a>Arquivo CAsyncMoniker::OnProgress

Chamado pelo apelido repetidamente para indicar o progresso atual desta operação de ligação, tipicamente em intervalos razoáveis durante uma operação demorada.

```
virtual void OnProgress(
    ULONG ulProgress,
    ULONG ulProgressMax,
    ULONG ulStatusCode,
    LPCTSTR szStatusText);
```

### <a name="parameters"></a>Parâmetros

*ulProgress*<br/>
Indica o progresso atual da operação de vinculação em relação ao máximo esperado indicado no *ulProgressMax*.

*ulProgressMax*<br/>
Indica o valor máximo esperado de *ulProgress* para a duração das chamadas para `OnProgress` esta operação.

*ulStatusCode*<br/>
Fornece informações adicionais sobre o andamento da operação de vinculação. Os valores válidos são retirados da `BINDSTATUS` enumeração. Veja observações para possíveis valores.

*Szstatustext*<br/>
Informações sobre o progresso atual, dependendo do valor de *ulStatusCode*. Veja observações para possíveis valores.

### <a name="remarks"></a>Comentários

Os valores possíveis para *ulStatusCode* (e o *szStatusText* para cada valor) são:

|||
|-|-|
|BINDSTATUS_FINDINGRESOURCE  |A operação vinculação é encontrar o recurso que mantém o objeto ou armazenamento vinculado. O *szStatusText* fornece o nome de exibição do recurso que está sendo pesquisado (por exemplo, "www.microsoft.com").  |
|BINDSTATUS_CONNECTING  |A operação vinculação está se conectando ao recurso que mantém o objeto ou armazenamento vinculado. O *szStatusText* fornece o nome de exibição do recurso que está sendo conectado (por exemplo, um endereço IP).  |
|BINDSTATUS_SENDINGREQUEST|A operação de vinculação está solicitando que o objeto ou o armazenamento sejam vinculados. O *szStatusText* fornece o nome de exibição do objeto (por exemplo, um nome de arquivo).|
|BINDSTATUS_REDIRECTING  |A operação de vinculação foi redirecionada para um local de dados diferente. O *szStatusText* fornece o nome de exibição do novo local de dados.  |
|BINDSTATUS_USINGCACHEDCOPY  |A operação vinculação está recuperando o objeto ou o armazenamento solicitados de uma cópia armazenada em cache. O *szStatusText* é NULL.  |
|BINDSTATUS_BEGINDOWNLOADDATA  |A operação de vinculação começou a receber o objeto ou armazenamento vinculado. O *szStatusText* fornece o nome de exibição do local de dados.|
|BINDSTATUS_DOWNLOADINGDATA  |A operação de vinculação continua a receber o objeto ou armazenamento vinculado. O *szStatusText* fornece o nome de exibição do local de dados.  |
|BINDSTATUS_ENDDOWNLOADDATA  |A operação de vinculação terminou de receber o objeto ou o armazenamento a ser vinculado. O *szStatusText* fornece o nome de exibição do local de dados.  |
|BINDSTATUS_CLASSIDAVAILABLE  |Um exemplo do objeto que está sendo vinculado está prestes a ser criado. O *szStatusText* fornece o CLSID do novo objeto em formato de string, permitindo ao cliente a oportunidade de cancelar a operação de vinculação, se desejar.  |

## <a name="casyncmonikerfileonstartbinding"></a><a name="onstartbinding"></a>Arquivo CAsyncMoniker::OnStartBinding

Anular essa função em suas classes derivadas para executar ações quando a vinculação estiver sendo inicializada.

```
virtual void OnStartBinding();
```

### <a name="remarks"></a>Comentários

Esta função é chamada de volta pelo apelido. A implementação padrão não faz nada.

## <a name="casyncmonikerfileonstopbinding"></a><a name="onstopbinding"></a>Arquivo CAsyncMoniker::OnStopBinding

Chamado pelo apelido no final da operação de ligação.

```
virtual void OnStopBinding(HRESULT hresult, LPCTSTR szError);
```

### <a name="parameters"></a>Parâmetros

*Hresult*<br/>
Um HRESULT que é o valor de erro ou aviso.

*szErrort*<br/>
Uma seqüência de caracteres descrevendo o erro.

### <a name="remarks"></a>Comentários

Anular esta função para executar ações quando a transferência é interrompida. Por padrão, a `IBinding`função é liberada .

Para obter uma `IBinding` descrição da interface, consulte o Windows SDK.

## <a name="casyncmonikerfileopen"></a><a name="open"></a>Arquivo CAsyncMoniker::Aberto

Chame esta função de membro para abrir um arquivo assíncronamente.

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

*Lpszurl*<br/>
Um ponteiro para arquivar a ser aberto assíncronamente. O arquivo pode ser qualquer URL ou nome de arquivo válido.

*pError*<br/>
Um ponteiro para as exceções de arquivo. Em caso de erro, ele será definido para a causa.

*pMoniker*<br/>
Um ponteiro para a interface `IMoniker`de apelido assíncrono , um apelido preciso que é a `IOleClientSite::GetMoniker(OLEWHICHMK_CONTAINER)`combinação do próprio apelido do documento, que você pode recuperar com , e um apelido criado a partir do nome do caminho. O controle pode usar este apelido para vincular, mas este não é o apelido que o controle deve salvar.

*pBindHost*<br/>
Um ponteiro `IBindHost` para a interface que será usado para criar o apelido a partir de um nome de caminho potencialmente relativo. Se o host de vinculação for inválido ou não `Open(lpszFileName,pError)`fornecer um apelido, a chamada será padrão para . Para obter uma `IBindHost` descrição da interface, consulte o Windows SDK.

*pServiceProvider*<br/>
Um ponteiro para a interface `IServiceProvider`. Se o provedor de serviço for inválido `IBindHost`ou não fornecer `Open(lpszFileName,pError)`o serviço para , a chamada é padrão para .

*pUnknown*<br/>
Um ponteiro para a interface `IUnknown`. Se `IServiceProvider` for encontrado, as `IBindHost`consultas de função para . Se o provedor de serviço for inválido `IBindHost`ou não fornecer `Open(lpszFileName,pError)`o serviço para , a chamada é padrão para .

### <a name="return-value"></a>Valor retornado

Não zero se o arquivo for aberto com sucesso; caso contrário, 0.

### <a name="remarks"></a>Comentários

Esta chamada inicia o processo de vinculação.

Você pode usar uma URL ou um nome de arquivo para o parâmetro *lpszURL.* Por exemplo:

[!code-cpp[NVC_MFCWinInet#6](../../mfc/codesnippet/cpp/casyncmonikerfile-class_2.cpp)]

\- ou –

[!code-cpp[NVC_MFCWinInet#7](../../mfc/codesnippet/cpp/casyncmonikerfile-class_3.cpp)]

## <a name="see-also"></a>Confira também

[Classe CMonikerFile](../../mfc/reference/cmonikerfile-class.md)<br/>
[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classe CMonikerFile](../../mfc/reference/cmonikerfile-class.md)<br/>
[Classe CDataPathProperty](../../mfc/reference/cdatapathproperty-class.md)
