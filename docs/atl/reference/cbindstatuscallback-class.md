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
ms.openlocfilehash: 89c65ff034cf7471c379b28116a741b62269a00c
ms.sourcegitcommit: fcb48824f9ca24b1f8bd37d647a4d592de1cc925
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/15/2019
ms.locfileid: "69497610"
---
# <a name="cbindstatuscallback-class"></a>Classe CBindStatusCallback

Essa classe implementa a `IBindStatusCallback` interface.

> [!IMPORTANT]
>  Essa classe e seus membros não podem ser usados em aplicativos que são executados no Windows Runtime.

## <a name="syntax"></a>Sintaxe

```
template <class T,
    int nBindFlags = BINDF_ASYNCHRONOUS | BINDF_ASYNCSTORAGE | BINDF_GETNEWESTVERSION | BINDF_NOWRITECACHE>
class ATL_NO_VTABLE CBindStatusCallback : public CComObjectRootEx <T ::_ThreadModel::ThreadModelNoCS>,
    public IBindStatusCallbackImpl<T>
```

#### <a name="parameters"></a>Parâmetros

*T*<br/>
Sua classe que contém a função que será chamada conforme os dados são recebidos.

*nBindFlags*<br/>
Especifica os sinalizadores de associação que são retornados por [GetBindInfo](#getbindinfo). A implementação padrão define a associação como assíncrona, recupera a versão mais recente do objeto/dados e não armazena os dados recuperados no cache de disco.

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[CBindStatusCallback::CBindStatusCallback](#cbindstatuscallback)|O construtor.|
|[CBindStatusCallback:: ~ CBindStatusCallback](#dtor)|O destruidor.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CBindStatusCallback::Download](#download)|Método estático que inicia o processo de download, cria `CBindStatusCallback` um objeto e chama `StartAsyncDownload`.|
|[CBindStatusCallback::GetBindInfo](#getbindinfo)|Chamado pelo moniker assíncrono para solicitar informações sobre o tipo de associação a ser criado.|
|[CBindStatusCallback::GetPriority](#getpriority)|Chamado pelo moniker assíncrono para obter a prioridade da operação de associação. A implementação da ATL `E_NOTIMPL`retorna.|
|[CBindStatusCallback::OnDataAvailable](#ondataavailable)|Chamado para fornecer dados ao seu aplicativo conforme ele se torna disponível. Lê os dados e, em seguida, chama a função passada para ele para usar os dados.|
|[CBindStatusCallback::OnLowResource](#onlowresource)|Chamado quando os recursos estão baixos. A implementação da ATL retorna S_OK.|
|[CBindStatusCallback::OnObjectAvailable](#onobjectavailable)|Chamado pelo moniker assíncrono para passar um ponteiro de interface de objeto para seu aplicativo. A implementação da ATL retorna S_OK.|
|[CBindStatusCallback::OnProgress](#onprogress)|Chamado para indicar o progresso de um processo de download de dados. A implementação da ATL retorna S_OK.|
|[CBindStatusCallback::OnStartBinding](#onstartbinding)|Chamado quando a associação é iniciada.|
|[CBindStatusCallback::OnStopBinding](#onstopbinding)|Chamado quando a transferência de dados assíncrona é interrompida.|
|[CBindStatusCallback::StartAsyncDownload](#startasyncdownload)|Inicializa os bytes disponíveis e bytes lidos para zero, cria um objeto de fluxo de tipo push a partir de uma `OnDataAvailable` URL e chama cada vez que os dados estão disponíveis.|

### <a name="public-data-members"></a>Membros de Dados Públicos

|Nome|Descrição|
|----------|-----------------|
|[CBindStatusCallback::m_dwAvailableToRead](#m_dwavailabletoread)|Número de bytes disponíveis para leitura.|
|[CBindStatusCallback::m_dwTotalRead](#m_dwtotalread)|Número total de bytes lidos.|
|[CBindStatusCallback::m_pFunc](#m_pfunc)|Ponteiro para a função chamada quando os dados estão disponíveis.|
|[CBindStatusCallback::m_pT](#m_pt)|Ponteiro para o objeto que solicita a transferência de dados assíncrona.|
|[CBindStatusCallback::m_spBindCtx](#m_spbindctx)|Ponteiro para a interface [IBindCtx](/windows/win32/api/objidl/nn-objidl-ibindctx) para a operação de associação atual.|
|[CBindStatusCallback::m_spBinding](#m_spbinding)|Ponteiro para a `IBinding` interface da operação de associação atual.|
|[CBindStatusCallback::m_spMoniker](#m_spmoniker)|Ponteiro para a interface [IMoniker](/windows/win32/api/objidl/nn-objidl-imoniker) para a URL a ser usada.|
|[CBindStatusCallback::m_spStream](#m_spstream)|Ponteiro para a interface [IStream](/windows/win32/api/objidl/nn-objidl-istream) para a transferência de dados.|

## <a name="remarks"></a>Comentários

A classe `CBindStatusCallback` implementa a interface `IBindStatusCallback`. `IBindStatusCallback`deve ser implementado pelo seu aplicativo para que ele possa receber notificações de uma transferência de dados assíncrona. O moniker assíncrono fornecido pelo sistema usa `IBindStatusCallback` métodos para enviar e receber informações sobre a transferência de dados assíncrona de e para o seu objeto.

Normalmente, o `CBindStatusCallback` objeto é associado a uma operação de ligação específica. Por exemplo, no exemplo [Async](../../overview/visual-cpp-samples.md) , quando você define a propriedade URL, ele cria um `CBindStatusCallback` objeto na chamada para: `Download`

[!code-cpp[NVC_ATL_Windowing#86](../../atl/codesnippet/cpp/cbindstatuscallback-class_1.h)]

O moniker assíncrono usa a função `OnData` de retorno de chamada para chamar seu aplicativo quando ele tem dados. O moniker assíncrono é fornecido pelo sistema.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`CComObjectRootBase`

`IBindStatusCallback`

[CComObjectRootEx](../../atl/reference/ccomobjectrootex-class.md)

`CBindStatusCallback`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlctl. h

##  <a name="cbindstatuscallback"></a>CBindStatusCallback::CBindStatusCallback

O construtor.

```
CBindStatusCallback();
```

### <a name="remarks"></a>Comentários

Cria um objeto para receber notificações relacionadas à transferência de dados assíncronas. Normalmente, um objeto é criado para cada operação de ligação.

O Construtor também inicializa [m_pT](#m_pt) e [m_pFunc](#m_pfunc) como NULL.

##  <a name="dtor"></a>CBindStatusCallback:: ~ CBindStatusCallback

O destruidor.

```
~CBindStatusCallback();
```

### <a name="remarks"></a>Comentários

Libera todos os recursos alocados.

##  <a name="download"></a>CBindStatusCallback::D aixar

Cria um `CBindStatusCallback` objeto e chama `StartAsyncDownload` para iniciar o download de dados de forma assíncrona da URL especificada.

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
no Um ponteiro para o objeto que solicita a transferência de dados assíncrona. O `CBindStatusCallback` objeto é modelos na classe desse objeto.

*pFunc*<br/>
no Um ponteiro para a função que recebe os dados que são lidos. A função é um membro da classe de tipo `T`do seu objeto. Consulte [StartAsyncDownload](#startasyncdownload) para obter a sintaxe e um exemplo.

*bstrURL*<br/>
no A URL da qual obter dados. Pode ser qualquer URL ou nome de arquivo válido. Não pode ser NULL. Por exemplo:

`CComBSTR mybstr =_T("http://somesite/data.htm")`

*pUnkContainer*<br/>
no O `IUnknown` do contêiner. NULL por padrão.

*bRelative*<br/>
no Um sinalizador que indica se a URL é relativa ou absoluta. FALSE por padrão, o que significa que a URL é absoluta.

### <a name="return-value"></a>Valor de retorno

Um dos valores de HRESULT padrão.

### <a name="remarks"></a>Comentários

Cada vez que os dados estão disponíveis, eles são enviados ao `OnDataAvailable`objeto por meio do. `OnDataAvailable`lê os dados e chama a função apontada por *pFunc* (por exemplo, para armazenar os dados ou imprimi-los na tela).

##  <a name="getbindinfo"></a>  CBindStatusCallback::GetBindInfo

Chamado para informar ao moniker como associar.

```
STDMETHOD(GetBindInfo)(
    DWORD* pgrfBSCF,
    BINDINFO* pbindinfo);
```

### <a name="parameters"></a>Parâmetros

*pgrfBSCF*<br/>
fora Um ponteiro para BINDF valores de enumeração indicando como a operação de associação deve ocorrer. Por padrão, defina com os seguintes valores de enumeração:

Download assíncrono do BINDF_ASYNCHRONOUS.

BINDF_ASYNCSTORAGE `OnDataAvailable` retorna E_PENDING quando os dados ainda não estão disponíveis em vez de serem bloqueados até que os dados estejam disponíveis.

BINDF_GETNEWESTVERSION a operação de associação deve recuperar a versão mais recente dos dados.

BINDF_NOWRITECACHE a operação de associação não deve armazenar os dados recuperados no cache de disco.

*pbindinfo*<br/>
[entrada, saída] Um ponteiro para a `BINDINFO` estrutura que oferece mais informações sobre como o objeto quer que a ligação ocorra.

### <a name="return-value"></a>Valor de retorno

Um dos valores de HRESULT padrão.

### <a name="remarks"></a>Comentários

A implementação padrão define a associação como assíncrona e para usar o modelo de envio de dados por push. No modelo de envio de dados por push, o moniker orienta a operação de vinculação assíncrona e notifica continuamente o cliente sempre que novos dados estiverem disponíveis.

##  <a name="getpriority"></a>CBindStatusCallback:: getanteriority

Chamado pelo moniker assíncrono para obter a prioridade da operação de associação.

```
STDMETHOD(GetPriority)(LONG* pnPriority);
```

### <a name="parameters"></a>Parâmetros

*pnPriority*<br/>
fora Endereço da variável **longa** que, em caso de êxito, recebe a prioridade.

### <a name="return-value"></a>Valor de retorno

Retorna E_NOTIMPL.

##  <a name="m_dwavailabletoread"></a>  CBindStatusCallback::m_dwAvailableToRead

Pode ser usado para armazenar o número de bytes disponíveis a serem lidos.

```
DWORD m_dwAvailableToRead;
```

### <a name="remarks"></a>Comentários

Inicializado para zero `StartAsyncDownload`em.

##  <a name="m_dwtotalread"></a>  CBindStatusCallback::m_dwTotalRead

O total cumulativo de bytes lidos na transferência de dados assíncrona.

```
DWORD m_dwTotalRead;
```

### <a name="remarks"></a>Comentários

Incrementado toda vez `OnDataAvailable` é chamado pelo número de bytes realmente lidos. Inicializado para zero `StartAsyncDownload`em.

##  <a name="m_pfunc"></a>  CBindStatusCallback::m_pFunc

A função apontada por `m_pFunc` é chamada por `OnDataAvailable` depois de ler os dados disponíveis (por exemplo, para armazenar os dados ou imprimi-los na tela).

```
ATL_PDATAAVAILABLE m_pFunc;
```

### <a name="remarks"></a>Comentários

A função apontada pelo `m_pFunc` é um membro da classe do seu objeto e tem a seguinte sintaxe:

```
void Function_Name(
   CBindStatusCallback<T>* pbsc,
   BYTE* pBytes,
   DWORD dwSize
   );
```

##  <a name="m_pt"></a>  CBindStatusCallback::m_pT

Um ponteiro para o objeto que solicita a transferência de dados assíncrona.

```
T* m_pT;
```

### <a name="remarks"></a>Comentários

O `CBindStatusCallback` objeto é modelos na classe desse objeto.

##  <a name="m_spbindctx"></a>  CBindStatusCallback::m_spBindCtx

Um ponteiro para uma interface [IBindCtx](/windows/win32/api/objidl/nn-objidl-ibindctx) que fornece acesso ao contexto de associação (um objeto que armazena informações sobre uma operação de associação de moniker específica).

```
CComPtr<IBindCtx> m_spBindCtx;
```

### <a name="remarks"></a>Comentários

Inicializado `StartAsyncDownload`em.

##  <a name="m_spbinding"></a>  CBindStatusCallback::m_spBinding

Um ponteiro para a `IBinding` interface da operação de associação atual.

```
CComPtr<IBinding> m_spBinding;
```

### <a name="remarks"></a>Comentários

`OnStopBinding`Inicializado `OnStartBinding` e liberado no.

##  <a name="m_spmoniker"></a>  CBindStatusCallback::m_spMoniker

Um ponteiro para a interface [IMoniker](/windows/win32/api/objidl/nn-objidl-imoniker) para a URL a ser usada.

```
CComPtr<IMoniker> m_spMoniker;
```

### <a name="remarks"></a>Comentários

Inicializado `StartAsyncDownload`em.

##  <a name="m_spstream"></a>  CBindStatusCallback::m_spStream

Um ponteiro para a interface [IStream](/windows/win32/api/objidl/nn-objidl-istream) da operação de associação atual.

```
CComPtr<IStream> m_spStream;
```

### <a name="remarks"></a>Comentários

Inicializado a `STGMEDIUM` partirdaestruturaquandoosinalizadorBCSFéBCSF_FIRSTDATANOTIFICATIONeliberadoquandoosinalizadorBCSFéBCSF_LASTDATANOTIFICATION.`OnDataAvailable`

##  <a name="ondataavailable"></a>  CBindStatusCallback::OnDataAvailable

As chamadas `OnDataAvailable` de moniker assíncronas fornecidas pelo sistema para fornecer dados ao objeto conforme ele se torna disponível.

```
STDMETHOD(
    OnDataAvailable)(DWORD grfBSCF,
    DWORD dwSize,
    FORMATETC* /* pformatetc */,
    STGMEDIUM* pstgmed);
```

### <a name="parameters"></a>Parâmetros

*grfBSCF*<br/>
no Um valor de enumeração BSCF. Um ou mais dos seguintes: BSCF_FIRSTDATANOTIFICATION, BSCF_INTERMEDIARYDATANOTIFICATION ou BSCF_LASTDATANOTIFICATION.

*dwSize*<br/>
no A quantidade cumulativa (em bytes) de dados disponíveis desde o início da associação. Pode ser zero, indicando que a quantidade de dados não é relevante ou que nenhum valor específico se tornou disponível.

*pformatetc*<br/>
no Ponteiro para a estrutura [FORMATETC](/windows/win32/com/the-formatetc-structure) que contém o formato dos dados disponíveis. Se não houver nenhum formato, poderá ser CF_NULL.

*pstgmed*<br/>
no Ponteiro para a estrutura [STGMEDIUM](/windows/win32/com/the-stgmedium-structure) que mantém os dados reais agora disponíveis.

### <a name="return-value"></a>Valor de retorno

Um dos valores de HRESULT padrão.

### <a name="remarks"></a>Comentários

`OnDataAvailable`lê os dados e, em seguida, chama um método da classe do seu objeto (por exemplo, para armazenar os dados ou imprimi-los na tela). Consulte [CBindStatusCallback:: StartAsyncDownload](#startasyncdownload) para obter detalhes.

##  <a name="onlowresource"></a>  CBindStatusCallback::OnLowResource

Chamado quando os recursos estão baixos.

```
STDMETHOD(OnLowResource)(DWORD /* dwReserved */);
```

### <a name="parameters"></a>Parâmetros

*dwReserved*<br/>
Reservado.

### <a name="return-value"></a>Valor de retorno

Retorna S_OK.

##  <a name="onobjectavailable"></a>  CBindStatusCallback::OnObjectAvailable

Chamado pelo moniker assíncrono para passar um ponteiro de interface de objeto para seu aplicativo.

```
STDMETHOD(OnObjectAvailable)(REFID /* riid */, IUnknown* /* punk */);
```

### <a name="parameters"></a>Parâmetros

*riid*<br/>
Identificador de interface da interface solicitada. Não utilizado.

*punk*<br/>
Endereço da interface IUnknown. Não utilizado.

### <a name="return-value"></a>Valor de retorno

Retorna S_OK.

##  <a name="onprogress"></a>  CBindStatusCallback::OnProgress

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
Inteiro longo sem sinal. Não utilizado.

*ulProgressMax*<br/>
Inteiro longo sem sinal não utilizado.

*ulStatusCode*<br/>
Inteiro longo sem sinal. Não utilizado.

*szStatusText*<br/>
Endereço de um valor de cadeia de caracteres. Não utilizado.

### <a name="return-value"></a>Valor de retorno

Retorna S_OK.

##  <a name="onstartbinding"></a>CBindStatusCallback:: OnStart

Define o membro de dados [m_spBinding](#m_spbinding) para `IBinding` o ponteiro em *pBinding*.

```
STDMETHOD(OnStartBinding)(DWORD /* dwReserved */, IBinding* pBinding);
```

### <a name="parameters"></a>Parâmetros

*dwReserved*<br/>
Reservado para uso futuro.

*pBinding*<br/>
no Endereço da interface IBinding da operação de associação atual. Isso não pode ser nulo. O cliente deve chamar AddRef nesse ponteiro para manter uma referência ao objeto de associação.

##  <a name="onstopbinding"></a>CBindStatusCallback:: OnStopBinding

Libera o `IBinding` ponteiro no membro de dados [m_spBinding](#m_spbinding).

```
STDMETHOD(OnStopBinding)(HRESULT hresult, LPCWSTR /* szError */);
```

### <a name="parameters"></a>Parâmetros

*hresult*<br/>
Código de status retornado da operação de associação.

*szError*<br/>
Endereço de um valor de cadeia de caracteres. Não utilizado.

### <a name="remarks"></a>Comentários

Chamado pelo moniker assíncrono fornecido pelo sistema para indicar o fim da operação de associação.

##  <a name="startasyncdownload"></a>  CBindStatusCallback::StartAsyncDownload

Inicia o download de dados de forma assíncrona da URL especificada.

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
no Um ponteiro para o objeto que solicita a transferência de dados assíncrona. O `CBindStatusCallback` objeto é modelos na classe desse objeto.

*pFunc*<br/>
no Um ponteiro para a função que recebe os dados que estão sendo lidos. A função é um membro da classe de tipo `T`do seu objeto. Consulte **comentários** para obter a sintaxe e um exemplo.

*bstrURL*<br/>
no A URL da qual obter dados. Pode ser qualquer URL ou nome de arquivo válido. Não pode ser NULL. Por exemplo:

`CComBSTR mybstr =_T("http://somesite/data.htm")`

*pUnkContainer*<br/>
no O `IUnknown` do contêiner. NULL por padrão.

*bRelative*<br/>
no Um sinalizador que indica se a URL é relativa ou absoluta. FALSE por padrão, o que significa que a URL é absoluta.

### <a name="return-value"></a>Valor de retorno

Um dos valores de HRESULT padrão.

### <a name="remarks"></a>Comentários

Cada vez que os dados estão disponíveis, eles são enviados ao `OnDataAvailable`objeto por meio do. `OnDataAvailable`lê os dados e chama a função apontada por *pFunc* (por exemplo, para armazenar os dados ou imprimi-los na tela).

A função apontada por *pFunc* é um membro da classe do seu objeto e tem a seguinte sintaxe:

```
void Function_Name(
    CBindStatusCallback<T>* pbsc,
    BYTE* pBytes,
    DWORD dwSize);
```

No exemplo a seguir (extraído do exemplo [assíncrono](../../overview/visual-cpp-samples.md) ), a função `OnData` grava os dados recebidos em uma caixa de texto.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATL_Windowing#87](../../atl/codesnippet/cpp/cbindstatuscallback-class_2.h)]

## <a name="see-also"></a>Consulte também

[Visão geral da classe](../../atl/atl-class-overview.md)
