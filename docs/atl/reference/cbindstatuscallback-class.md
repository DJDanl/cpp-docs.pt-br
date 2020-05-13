---
title: Classe CBindStatusCallback
ms.date: 11/04/2016
f1_keywords:
- CBindStatusCallback
- ATLCTL/ATL::CBindStatusCallback
- ATLCTL/ATL::CBindStatusCallback::CBindStatusCallback
- ATLCTL/ATL::CBindStatusCallback::Download
- ATLCTL/ATL::CBindStatusCallback::GetBindInfo
- ATLCTL/ATL::CBindStatusCallback::GetPriority
- ATLCTL/ATL::CBindStatusCallback::OnDataAvailable
- ATLCTL/ATL::CBindStatusCallback::OnLowResource
- ATLCTL/ATL::CBindStatusCallback::OnObjectAvailable
- ATLCTL/ATL::CBindStatusCallback::OnProgress
- ATLCTL/ATL::CBindStatusCallback::OnStartBinding
- ATLCTL/ATL::CBindStatusCallback::OnStopBinding
- ATLCTL/ATL::CBindStatusCallback::StartAsyncDownload
- ATLCTL/ATL::CBindStatusCallback::m_dwAvailableToRead
- ATLCTL/ATL::CBindStatusCallback::m_dwTotalRead
- ATLCTL/ATL::CBindStatusCallback::m_pFunc
- ATLCTL/ATL::CBindStatusCallback::m_pT
- ATLCTL/ATL::CBindStatusCallback::m_spBindCtx
- ATLCTL/ATL::CBindStatusCallback::m_spBinding
- ATLCTL/ATL::CBindStatusCallback::m_spMoniker
- ATLCTL/ATL::CBindStatusCallback::m_spStream
helpviewer_keywords:
- asynchronous data transfer [C++]
- data transfer [C++]
- data transfer [C++], asynchronous
- CBindStatusCallback class
ms.assetid: 0f5da276-6031-4418-b2a9-a4750ef29e77
ms.openlocfilehash: 0ae7f4fcdba18be84d99140e395b6f2ac3db792a
ms.sourcegitcommit: 7a6116e48c3c11b97371b8ae4ecc23adce1f092d
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/22/2020
ms.locfileid: "81748204"
---
# <a name="cbindstatuscallback-class"></a>Classe CBindStatusCallback

Essa classe implementa a interface `IBindStatusCallback`.

> [!IMPORTANT]
> Esta classe e seus membros não podem ser usados em aplicativos executados no Tempo de execução do Windows.

## <a name="syntax"></a>Sintaxe

```
template <class T,
    int nBindFlags = BINDF_ASYNCHRONOUS | BINDF_ASYNCSTORAGE | BINDF_GETNEWESTVERSION | BINDF_NOWRITECACHE>
class ATL_NO_VTABLE CBindStatusCallback : public CComObjectRootEx <T ::_ThreadModel::ThreadModelNoCS>,
    public IBindStatusCallbackImpl<T>
```

#### <a name="parameters"></a>Parâmetros

*T*<br/>
Sua classe contém a função que será chamada à medida que os dados são recebidos.

*nBindFlags*<br/>
Especifica os sinalizadores de vinculação que são retornados pelo [GetBindInfo](#getbindinfo). A implementação padrão define a vinculação como assíncrona, recupera a versão mais recente dos dados/objeto e não armazena dados recuperados no cache do disco.

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[CBindStatusCallback::CBindStatusCallback](#cbindstatuscallback)|O construtor.|
|[CBindStatusCallback::~CBindStatusCallback](#dtor)|O destruidor.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CBindStatusCallback::Download](#download)|Método estático que inicia o `CBindStatusCallback` processo de `StartAsyncDownload`download, cria um objeto e chama .|
|[CBindStatusCallback::GetBindInfo](#getbindinfo)|Chamado pelo apelido assíncrono para solicitar informações sobre o tipo de vínculo a ser criado.|
|[CBindStatusCallback::GetPriority](#getpriority)|Chamado pelo apelido assíncrono para obter a prioridade da operação de ligação. O retorno `E_NOTIMPL`da implementação atl .|
|[CBindStatusCallback::OnDataAvailable](#ondataavailable)|Chamado para fornecer dados para o seu aplicativo à medida que ele se torna disponível. Lê os dados e, em seguida, chama a função passada para ele para usar os dados.|
|[CBindStatusCallback::OnLowResource](#onlowresource)|Chamado quando os recursos são baixos. A implementação da ATL retorna S_OK.|
|[CBindStatusCallback::OnObjectAvailable](#onobjectavailable)|Chamado pelo apelido assíncrono para passar um ponteiro de interface de objeto para o seu aplicativo. A implementação da ATL retorna S_OK.|
|[CBindStatusCallback::OnProgress](#onprogress)|Chamado para indicar o progresso de um processo de download de dados. A implementação da ATL retorna S_OK.|
|[CBindStatusCallback::OnStartBinding](#onstartbinding)|Chamado quando a ligação é iniciada.|
|[CBindStatusCallback::OnStopBinding](#onstopbinding)|Chamado quando a transferência de dados assíncrona é interrompida.|
|[CBindStatusCallback::StartAsyncDownload](#startasyncdownload)|Inicializa os bytes disponíveis e os bytes são lidos a zero, `OnDataAvailable` cria um objeto de fluxo do tipo push a partir de uma URL e liga toda vez que os dados estão disponíveis.|

### <a name="public-data-members"></a>Membros de Dados Públicos

|Nome|Descrição|
|----------|-----------------|
|[CBindStatusCallback::m_dwAvailableToRead](#m_dwavailabletoread)|Número de bytes disponíveis para leitura.|
|[CBindStatusCallback::m_dwTotalRead](#m_dwtotalread)|Número total de bytes lidos.|
|[CBindStatusCallback::m_pFunc](#m_pfunc)|Ponteiro para a função chamada quando os dados estão disponíveis.|
|[CBindStatusCallback::m_pT](#m_pt)|Ponteiro para o objeto que solicita a transferência de dados assíncrona.|
|[CBindStatusCallback::m_spBindCtx](#m_spbindctx)|Ponteiro para a interface [IBindCtx](/windows/win32/api/objidl/nn-objidl-ibindctx) para a operação de vinculação atual.|
|[CBindStatusCallback::m_spBinding](#m_spbinding)|Ponteiro para `IBinding` a interface para a operação de vinculação atual.|
|[Chamada de trabalho de CBindStatus::m_spMoniker](#m_spmoniker)|Ponteiro para a interface [IMoniker](/windows/win32/api/objidl/nn-objidl-imoniker) para a URL a ser usada.|
|[CBindStatusCallback::m_spStream](#m_spstream)|Ponteiro para a interface [IStream](/windows/win32/api/objidl/nn-objidl-istream) para a transferência de dados.|

## <a name="remarks"></a>Comentários

A classe `CBindStatusCallback` implementa a interface `IBindStatusCallback`. `IBindStatusCallback`deve ser implementado pelo seu aplicativo para que ele possa receber notificações de uma transferência de dados assíncrona. O apelido assíncrono fornecido pelo `IBindStatusCallback` sistema usa métodos para enviar e receber informações sobre a transferência de dados assíncrona para e do seu objeto.

Normalmente, `CBindStatusCallback` o objeto está associado a uma operação de vinculação específica. Por exemplo, na amostra [ASYNC,](../../overview/visual-cpp-samples.md) quando você define `CBindStatusCallback` a propriedade URL, ela cria um objeto na chamada para: `Download`

[!code-cpp[NVC_ATL_Windowing#86](../../atl/codesnippet/cpp/cbindstatuscallback-class_1.h)]

O apelido assíncrono usa `OnData` a função de retorno de chamada para chamar seu aplicativo quando ele tiver dados. O apelido assíncrono é fornecido pelo sistema.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`CComObjectRootBase`

`IBindStatusCallback`

[Ccomobjectrootex](../../atl/reference/ccomobjectrootex-class.md)

`CBindStatusCallback`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlctl.h

## <a name="cbindstatuscallbackcbindstatuscallback"></a><a name="cbindstatuscallback"></a>CBindStatusCallback::CBindStatusCallback

O construtor.

```
CBindStatusCallback();
```

### <a name="remarks"></a>Comentários

Cria um objeto para receber notificações sobre a transferência de dados assíncrona. Normalmente, um objeto é criado para cada operação de vinculação.

A construtora também inicia [m_pT](#m_pt) e [m_pFunc](#m_pfunc) a NULL.

## <a name="cbindstatuscallbackcbindstatuscallback"></a><a name="dtor"></a>CBindStatusCallback::~CBindStatusCallback

O destruidor.

```
~CBindStatusCallback();
```

### <a name="remarks"></a>Comentários

Libera todos os recursos alocados.

## <a name="cbindstatuscallbackdownload"></a><a name="download"></a>CBindStatusCallback::Download

Cria `CBindStatusCallback` um objeto `StartAsyncDownload` e chamadas para começar a baixar dados de forma assíncrona da URL especificada.

```
static HRESULT Download(
    T* pT,
    ATL_PDATAAVAILABLE pFunc,
    BSTR bstrURL,
    IUnknown* pUnkContainer = NULL,
    BOOL bRelative = FALSE);
```

### <a name="parameters"></a>Parâmetros

*pT*<br/>
[em] Um ponteiro para o objeto que solicita a transferência de dados assíncrona. O `CBindStatusCallback` objeto é templatizado na classe deste objeto.

*pFunc*<br/>
[em] Um ponteiro para a função que recebe os dados que são lidos. A função é um membro da classe `T`de tipo do seu objeto. Consulte [StartAsyncDownload](#startasyncdownload) para obter sintaxe e um exemplo.

*Bstrurl*<br/>
[em] A URL para obter dados. Pode ser qualquer URL ou nome de arquivo válido. Não pode ser NULL. Por exemplo:

`CComBSTR mybstr =_T("http://somesite/data.htm")`

*pUnkContainer*<br/>
[em] O `IUnknown` do recipiente. NULL por padrão.

*bRelativo*<br/>
[em] Uma bandeira indicando se a URL é relativa ou absoluta. FALSO por padrão, o que significa que a URL é absoluta.

### <a name="return-value"></a>Valor retornado

Um dos valores padrão de HRESULT.

### <a name="remarks"></a>Comentários

Toda vez que os dados estão `OnDataAvailable`disponíveis, eles são enviados para o objeto através de . `OnDataAvailable`lê os dados e chama a função apontada pelo *pFunc* (por exemplo, para armazenar os dados ou imprimi-lo na tela).

## <a name="cbindstatuscallbackgetbindinfo"></a><a name="getbindinfo"></a>CBindStatusCallback::GetBindInfo

Chamado para dizer ao apelido como se ligar.

```
STDMETHOD(GetBindInfo)(
    DWORD* pgrfBSCF,
    BINDINFO* pbindinfo);
```

### <a name="parameters"></a>Parâmetros

*PGRFBSCF*<br/>
[fora] Um ponteiro para valores de enumeração BINDF indicando como a operação de vinculação deve ocorrer. Por padrão, defina com os seguintes valores de enumeração:

BINDF_ASYNCHRONOUS download assíncrono.

BINDF_ASYNCSTORAGE `OnDataAvailable` retorna E_PENDING quando os dados ainda não estão disponíveis, em vez de bloquear até que os dados estejam disponíveis.

BINDF_GETNEWESTVERSION A operação vincular deve recuperar a versão mais recente dos dados.

BINDF_NOWRITECACHE A operação vincular não deve armazenar dados recuperados no cache do disco.

*pbindinfo*<br/>
[dentro, fora] Um ponteiro `BINDINFO` para a estrutura dando mais informações sobre como o objeto quer que a vinculação ocorra.

### <a name="return-value"></a>Valor retornado

Um dos valores padrão de HRESULT.

### <a name="remarks"></a>Comentários

A implementação padrão define a vinculação como assíncrona e para usar o modelo de empurrão de dados. No modelo de empurrão de dados, o apelido impulsiona a operação de vinculação assíncrona e notifica continuamente o cliente sempre que novos dados estão disponíveis.

## <a name="cbindstatuscallbackgetpriority"></a><a name="getpriority"></a>CBindStatusCallback::GetPriority

Chamado pelo apelido assíncrono para obter a prioridade da operação de ligação.

```
STDMETHOD(GetPriority)(LONG* pnPriority);
```

### <a name="parameters"></a>Parâmetros

*pnPriority*<br/>
[fora] Endereço da variável **LONG** que, no sucesso, recebe a prioridade.

### <a name="return-value"></a>Valor retornado

Volta E_NOTIMPL.

## <a name="cbindstatuscallbackm_dwavailabletoread"></a><a name="m_dwavailabletoread"></a>CBindStatusCallback::m_dwAvailableToRead

Pode ser usado para armazenar o número de bytes disponíveis para serem lidos.

```
DWORD m_dwAvailableToRead;
```

### <a name="remarks"></a>Comentários

Inicializado para `StartAsyncDownload`zero em .

## <a name="cbindstatuscallbackm_dwtotalread"></a><a name="m_dwtotalread"></a>CBindStatusCallback::m_dwTotalRead

O total acumulado de bytes lidos na transferência de dados assíncrona.

```
DWORD m_dwTotalRead;
```

### <a name="remarks"></a>Comentários

Incrementado `OnDataAvailable` cada vez é chamado pelo número de bytes realmente lidos. Inicializado para `StartAsyncDownload`zero em .

## <a name="cbindstatuscallbackm_pfunc"></a><a name="m_pfunc"></a>CBindStatusCallback::m_pFunc

A função apontada `m_pFunc` por `OnDataAvailable` é chamada por depois de ler os dados disponíveis (por exemplo, para armazenar os dados ou imprimi-lo na tela).

```
ATL_PDATAAVAILABLE m_pFunc;
```

### <a name="remarks"></a>Comentários

A função apontada `m_pFunc` por é um membro da classe do seu objeto e tem a seguinte sintaxe:

```cpp
void Function_Name(
   CBindStatusCallback<T>* pbsc,
   BYTE* pBytes,
   DWORD dwSize
   );
```

## <a name="cbindstatuscallbackm_pt"></a><a name="m_pt"></a>CBindStatusCallback::m_pT

Um ponteiro para o objeto que solicita a transferência de dados assíncrona.

```
T* m_pT;
```

### <a name="remarks"></a>Comentários

O `CBindStatusCallback` objeto é templatizado na classe deste objeto.

## <a name="cbindstatuscallbackm_spbindctx"></a><a name="m_spbindctx"></a>CBindStatusCallback::m_spBindCtx

Um ponteiro para uma interface [IBindCtx](/windows/win32/api/objidl/nn-objidl-ibindctx) que fornece acesso ao contexto de vinculação (um objeto que armazena informações sobre uma operação de vinculação de apelido sinuosa).

```
CComPtr<IBindCtx> m_spBindCtx;
```

### <a name="remarks"></a>Comentários

Inicializado `StartAsyncDownload`em .

## <a name="cbindstatuscallbackm_spbinding"></a><a name="m_spbinding"></a>CBindStatusCallback::m_spBinding

Um ponteiro `IBinding` para a interface da operação de ligação atual.

```
CComPtr<IBinding> m_spBinding;
```

### <a name="remarks"></a>Comentários

Inicializado `OnStartBinding` e lançado `OnStopBinding`em .

## <a name="cbindstatuscallbackm_spmoniker"></a><a name="m_spmoniker"></a>Chamada de trabalho de CBindStatus::m_spMoniker

Um ponteiro para a interface [IMoniker](/windows/win32/api/objidl/nn-objidl-imoniker) para a URL usar.

```
CComPtr<IMoniker> m_spMoniker;
```

### <a name="remarks"></a>Comentários

Inicializado `StartAsyncDownload`em .

## <a name="cbindstatuscallbackm_spstream"></a><a name="m_spstream"></a>CBindStatusCallback::m_spStream

Um ponteiro para a interface [IStream](/windows/win32/api/objidl/nn-objidl-istream) da operação de vinculação atual.

```
CComPtr<IStream> m_spStream;
```

### <a name="remarks"></a>Comentários

Inicializado `OnDataAvailable` a `STGMEDIUM` partir da estrutura quando a bandeira BCSF é BCSF_FIRSTDATANOTIFICATION e liberada quando a bandeira BCSF é BCSF_LASTDATANOTIFICATION.

## <a name="cbindstatuscallbackondataavailable"></a><a name="ondataavailable"></a>CBindStatusCallback::OnDataAvailable

O apelido assíncrono fornecido `OnDataAvailable` pelo sistema chama para fornecer dados ao objeto à medida que ele se torna disponível.

```
STDMETHOD(
    OnDataAvailable)(DWORD grfBSCF,
    DWORD dwSize,
    FORMATETC* /* pformatetc */,
    STGMEDIUM* pstgmed);
```

### <a name="parameters"></a>Parâmetros

*grfBSCF*<br/>
[em] Um valor de enumeração BSCF. Um ou mais dos seguintes: BSCF_FIRSTDATANOTIFICATION, BSCF_INTERMEDIARYDATANOTIFICATION ou BSCF_LASTDATANOTIFICATION.

*Dwsize*<br/>
[em] A quantidade acumulada (em bytes) de dados disponíveis desde o início da vinculação. Pode ser zero, indicando que a quantidade de dados não é relevante ou que nenhuma quantidade específica se tornou disponível.

*pformatetc*<br/>
[em] Pointer para a estrutura [FORMATETC](/windows/win32/com/the-formatetc-structure) que contém o formato dos dados disponíveis. Se não houver formato, pode ser CF_NULL.

*pstgmed*<br/>
[em] Ponteiro para a estrutura [STGMEDIUM](/windows/win32/com/the-stgmedium-structure) que contém os dados reais agora disponíveis.

### <a name="return-value"></a>Valor retornado

Um dos valores padrão de HRESULT.

### <a name="remarks"></a>Comentários

`OnDataAvailable`lê os dados e, em seguida, chama um método da classe do seu objeto (por exemplo, para armazenar os dados ou imprimi-lo na tela). Consulte [CBindStatusCallback::StartAsyncDownload](#startasyncdownload) para obter detalhes.

## <a name="cbindstatuscallbackonlowresource"></a><a name="onlowresource"></a>CBindStatusCallback::OnLowResource

Chamado quando os recursos são baixos.

```
STDMETHOD(OnLowResource)(DWORD /* dwReserved */);
```

### <a name="parameters"></a>Parâmetros

*dwReservado*<br/>
Reservado.

### <a name="return-value"></a>Valor retornado

Retorna S_OK.

## <a name="cbindstatuscallbackonobjectavailable"></a><a name="onobjectavailable"></a>CBindStatusCallback::OnObjectAvailable

Chamado pelo apelido assíncrono para passar um ponteiro de interface de objeto para o seu aplicativo.

```
STDMETHOD(OnObjectAvailable)(REFID /* riid */, IUnknown* /* punk */);
```

### <a name="parameters"></a>Parâmetros

*riid*<br/>
Identificador de interface da interface solicitada. Não utilizado.

*Punk*<br/>
Endereço da interface IUnknown. Não utilizado.

### <a name="return-value"></a>Valor retornado

Retorna S_OK.

## <a name="cbindstatuscallbackonprogress"></a><a name="onprogress"></a>CBindStatusCallback::OnProgress

Chamado para indicar o progresso de um processo de download de dados.

```
STDMETHOD(OnProgress)(
    ULONG /* ulProgress */,
    ULONG /* ulProgressMax */,
    ULONG /* ulStatusCode */,
    LPCWSTRONG /* szStatusText */);
```

### <a name="parameters"></a>Parâmetros

*ulProgress*<br/>
Um inteiro longo não assinado. Não utilizado.

*ulProgressMax*<br/>
Inteiro longo não assinado não usado.

*ulStatusCode*<br/>
Um inteiro longo não assinado. Não utilizado.

*Szstatustext*<br/>
Endereço de um valor de cadeia. Não utilizado.

### <a name="return-value"></a>Valor retornado

Retorna S_OK.

## <a name="cbindstatuscallbackonstartbinding"></a><a name="onstartbinding"></a>CBindStatusCallback::OnStartBinding

Define o [m_spBinding](#m_spbinding) membro de `IBinding` dados m_spBinding para o ponteiro em *pBinding*.

```
STDMETHOD(OnStartBinding)(DWORD /* dwReserved */, IBinding* pBinding);
```

### <a name="parameters"></a>Parâmetros

*dwReservado*<br/>
Reservado para uso futuro.

*pBinding*<br/>
[em] Endereço da interface IBinding da operação de vinculação atual. Isso não pode ser NULO. O cliente deve ligar para addRef neste ponteiro para manter uma referência ao objeto de vinculação.

## <a name="cbindstatuscallbackonstopbinding"></a><a name="onstopbinding"></a>CBindStatusCallback::OnStopBinding

Libera o `IBinding` ponteiro no [membro](#m_spbinding)de dados m_spBinding .

```
STDMETHOD(OnStopBinding)(HRESULT hresult, LPCWSTR /* szError */);
```

### <a name="parameters"></a>Parâmetros

*Hresult*<br/>
Código de status retornado da operação de vinculação.

*szError*<br/>
Endereço de um valor de cadeia. Não utilizado.

### <a name="remarks"></a>Comentários

Chamado pelo apelido assíncrono fornecido pelo sistema para indicar o fim da operação de vinculação.

## <a name="cbindstatuscallbackstartasyncdownload"></a><a name="startasyncdownload"></a>CBindStatusCallback::StartAsyncDownload

Começa a baixar dados assíncronamente da URL especificada.

```
HRESULT StartAsyncDownload(
    T* pT,
    ATL_PDATAAVAILABLE pFunc,
    BSTR bstrURL,
    IUnknown* pUnkContainer = NULL,
    BOOL bRelative = FALSE);
```

### <a name="parameters"></a>Parâmetros

*pT*<br/>
[em] Um ponteiro para o objeto que solicita a transferência de dados assíncrona. O `CBindStatusCallback` objeto é templatizado na classe deste objeto.

*pFunc*<br/>
[em] Um ponteiro para a função que recebe os dados que estão sendo lidos. A função é um membro da classe `T`de tipo do seu objeto. Veja **observações** para sintaxe e um exemplo.

*Bstrurl*<br/>
[em] A URL para obter dados. Pode ser qualquer URL ou nome de arquivo válido. Não pode ser NULL. Por exemplo:

`CComBSTR mybstr =_T("http://somesite/data.htm")`

*pUnkContainer*<br/>
[em] O `IUnknown` do recipiente. NULL por padrão.

*bRelativo*<br/>
[em] Uma bandeira indicando se a URL é relativa ou absoluta. FALSO por padrão, o que significa que a URL é absoluta.

### <a name="return-value"></a>Valor retornado

Um dos valores padrão de HRESULT.

### <a name="remarks"></a>Comentários

Toda vez que os dados estão `OnDataAvailable`disponíveis, eles são enviados para o objeto através de . `OnDataAvailable`lê os dados e chama a função apontada pelo *pFunc* (por exemplo, para armazenar os dados ou imprimi-lo na tela).

A função apontada pelo *pFunc* é um membro da classe do seu objeto e tem a seguinte sintaxe:

```cpp
void Function_Name(
    CBindStatusCallback<T>* pbsc,
    BYTE* pBytes,
    DWORD dwSize);
```

No exemplo a seguir (retirado da amostra `OnData` [ASYNC),](../../overview/visual-cpp-samples.md) a função grava os dados recebidos em uma caixa de texto.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATL_Windowing#87](../../atl/codesnippet/cpp/cbindstatuscallback-class_2.h)]

## <a name="see-also"></a>Confira também

[Visão geral da classe](../../atl/atl-class-overview.md)
