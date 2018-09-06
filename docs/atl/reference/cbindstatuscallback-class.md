---
title: Classe CBindStatusCallback | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-atl
ms.topic: reference
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
dev_langs:
- C++
helpviewer_keywords:
- asynchronous data transfer [C++]
- data transfer [C++]
- data transfer [C++], asynchronous
- CBindStatusCallback class
ms.assetid: 0f5da276-6031-4418-b2a9-a4750ef29e77
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 58d18a6b5eae55373be9ddc71a4d856547bf420c
ms.sourcegitcommit: 92dbc4b9bf82fda96da80846c9cfcdba524035af
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/05/2018
ms.locfileid: "43758424"
---
# <a name="cbindstatuscallback-class"></a>Classe CBindStatusCallback

Essa classe implementa o `IBindStatusCallback` interface.

> [!IMPORTANT]
>  Essa classe e seus membros não podem ser usados em aplicativos executados no tempo de execução do Windows.

## <a name="syntax"></a>Sintaxe

```
template <class T,
    int nBindFlags = BINDF_ASYNCHRONOUS | BINDF_ASYNCSTORAGE | BINDF_GETNEWESTVERSION | BINDF_NOWRITECACHE>  
class ATL_NO_VTABLE CBindStatusCallback : public CComObjectRootEx <T ::_ThreadModel::ThreadModelNoCS>,
    public IBindStatusCallbackImpl<T>
```

#### <a name="parameters"></a>Parâmetros

*T*  
Sua classe que contém a função que será chamada quando os dados são recebidos.

*nBindFlags*  
Especifica os sinalizadores de associação que são retornados pelo [GetBindInfo](#getbindinfo). A implementação padrão define a associação seja assíncrono, recupera a versão mais recente do objeto de dados/e não armazena os dados recuperados no cache de disco.

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores Públicos

|Nome|Descrição|
|----------|-----------------|
|[CBindStatusCallback::CBindStatusCallback](#cbindstatuscallback)|O construtor.|
|[CBindStatusCallback:: ~ CBindStatusCallback](#dtor)|O destruidor.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CBindStatusCallback::Download](#download)|Método estático que inicia o processo de download, cria uma `CBindStatusCallback` objeto e chamadas `StartAsyncDownload`.|
|[CBindStatusCallback::GetBindInfo](#getbindinfo)|Chamado pelo moniker assíncrono para solicitar informações sobre o tipo de associação a ser criado.|
|[CBindStatusCallback::GetPriority](#getpriority)|Chamado pelo moniker assíncrono para obter a prioridade da operação de associação. Retorna a implementação de ATL `E_NOTIMPL`.|
|[CBindStatusCallback::OnDataAvailable](#ondataavailable)|Chamado para fornecer dados para seu aplicativo conforme ele se torna disponível. Lê os dados e, em seguida, chama a função passada para ele para usar os dados.|
|[CBindStatusCallback::OnLowResource](#onlowresource)|Chamado quando os recursos são insuficientes. A implementação de ATL Retorna S_OK.|
|[CBindStatusCallback::OnObjectAvailable](#onobjectavailable)|Chamado pelo moniker assíncrono para passar um ponteiro de interface de objeto para seu aplicativo. A implementação de ATL Retorna S_OK.|
|[CBindStatusCallback::OnProgress](#onprogress)|Chamado para indicar o progresso de um processo de download de dados. A implementação de ATL Retorna S_OK.|
|[CBindStatusCallback::OnStartBinding](#onstartbinding)|Chamado quando a associação é iniciada.|
|[CBindStatusCallback::OnStopBinding](#onstopbinding)|Chamado quando a transferência de dados assíncrono é interrompida.|
|[CBindStatusCallback::StartAsyncDownload](#startasyncdownload)|Inicializa os bytes disponíveis e os bytes lidos para zero, cria um objeto de fluxo do tipo de envio de uma URL e chamadas `OnDataAvailable` toda vez que os dados estão disponíveis.|

### <a name="public-data-members"></a>Membros de Dados Públicos

|Nome|Descrição|
|----------|-----------------|
|[CBindStatusCallback::m_dwAvailableToRead](#m_dwavailabletoread)|Número de bytes disponíveis para leitura.|
|[CBindStatusCallback::m_dwTotalRead](#m_dwtotalread)|Número total de bytes lidos.|
|[CBindStatusCallback::m_pFunc](#m_pfunc)|Ponteiro para a função chamada quando os dados estão disponíveis.|
|[CBindStatusCallback::m_pT](#m_pt)|Ponteiro para o objeto que solicitou a transferência de dados assíncronos.|
|[CBindStatusCallback::m_spBindCtx](#m_spbindctx)|Ponteiro para o [IBindCtx](/windows/desktop/api/objidl/nn-objidl-ibindctx) interface para a operação de associação atual.|
|[CBindStatusCallback::m_spBinding](#m_spbinding)|Ponteiro para o `IBinding` interface para a operação de associação atual.|
|[CBindStatusCallback::m_spMoniker](#m_spmoniker)|Ponteiro para o [IMoniker](/windows/desktop/api/objidl/nn-objidl-imoniker) interface para a URL a ser usada.|
|[CBindStatusCallback::m_spStream](#m_spstream)|Ponteiro para o [IStream](/windows/desktop/api/objidl/nn-objidl-istream) interface para a transferência de dados.|

## <a name="remarks"></a>Comentários

A classe `CBindStatusCallback` implementa a interface `IBindStatusCallback`. `IBindStatusCallback` deve ser implementada pelo seu aplicativo para que ele pode receber notificações de uma transferência de dados assíncronos. Usa o moniker assíncrono fornecido pelo sistema `IBindStatusCallback` métodos para enviar e receber informações sobre os dados assíncronos de transferência / para seu objeto.

Normalmente, o `CBindStatusCallback` objeto está associado uma operação de ligação específica. Por exemplo, nos [ASYNC](../../visual-cpp-samples.md) exemplo, quando você definir a propriedade de URL, ele cria um `CBindStatusCallback` objeto na chamada para `Download`:

[!code-cpp[NVC_ATL_Windowing#86](../../atl/codesnippet/cpp/cbindstatuscallback-class_1.h)]

O moniker assíncrono usa a função de retorno de chamada `OnData` chamar seu aplicativo quando ele tem dados. O moniker assíncrono é fornecido pelo sistema.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`CComObjectRootBase`

`IBindStatusCallback`

[CComObjectRootEx](../../atl/reference/ccomobjectrootex-class.md)

`CBindStatusCallback`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlctl.h

##  <a name="cbindstatuscallback"></a>  CBindStatusCallback::CBindStatusCallback

O construtor.

```
CBindStatusCallback();
```

### <a name="remarks"></a>Comentários

Cria um objeto para receber notificações sobre a transferência de dados assíncrona. Normalmente, um objeto é criado para cada operação de ligação.

O construtor também inicializa [m_pT](#m_pt) e [m_pFunc](#m_pfunc) como NULL.

##  <a name="dtor"></a>  CBindStatusCallback:: ~ CBindStatusCallback

O destruidor.

```
~CBindStatusCallback();
```

### <a name="remarks"></a>Comentários

Libera todos os recursos alocados.

##  <a name="download"></a>  CBindStatusCallback::Download

Cria uma `CBindStatusCallback` objeto e chamadas `StartAsyncDownload` para começar a baixar os dados de forma assíncrona da URL especificada.

```
static HRESULT Download(  
    T* pT,
    ATL_PDATAAVAILABLE pFunc,
    BSTR bstrURL,
    IUnknown* pUnkContainer = NULL,
    BOOL bRelative = FALSE);
```

### <a name="parameters"></a>Parâmetros

*pT*  
[in] Um ponteiro para o objeto que solicitou a transferência de dados assíncronos. O `CBindStatusCallback` objeto é modelado na classe do objeto.

*pFunc*  
[in] Um ponteiro para a função que recebe os dados que é lido. A função é um membro de classe do objeto do tipo `T`. Ver [StartAsyncDownload](#startasyncdownload) para sintaxe e exemplos.

*bstrURL*  
[in] A URL para obter dados. Pode ser qualquer nome de arquivo ou URL válido. Não pode ser NULL. Por exemplo:

`CComBSTR mybstr =_T("http://somesite/data.htm")`

*pUnkContainer*  
[in] O `IUnknown` do contêiner. NULL por padrão.

*bRelative*  
[in] Um sinalizador que indica se a URL é relativo ou absoluto. FALSE por padrão, o que significa que a URL é absoluto.

### <a name="return-value"></a>Valor de retorno

Um dos valores HRESULT padrão.

### <a name="remarks"></a>Comentários

Sempre que os dados estão disponíveis que ela seja enviada para o objeto por meio de `OnDataAvailable`. `OnDataAvailable` lê os dados e chama a função apontada por *pFunc* (por exemplo, para armazenar os dados ou imprimi-lo na tela).

##  <a name="getbindinfo"></a>  CBindStatusCallback::GetBindInfo

Chamado para informar o moniker como associar.

```
STDMETHOD(GetBindInfo)(
    DWORD* pgrfBSCF,
    BINDINFO* pbindinfo);
```

### <a name="parameters"></a>Parâmetros

*pgrfBSCF*  
[out] Um ponteiro para os valores de enumeração BINDF indicando como a operação de associação deve ocorrer. Por padrão, definida com os seguintes valores de enumeração:

Download assíncrono BINDF_ASYNCHRONOUS.

BINDF_ASYNCSTORAGE `OnDataAvailable` retorna E_PENDING quando os dados ainda não estão disponíveis em vez de bloquear até que os dados estão disponíveis.

A operação de associação BINDF_GETNEWESTVERSION deve recuperar a versão mais recente dos dados.

BINDF_NOWRITECACHE a operação de associação não deve armazenar recuperou dados no cache de disco.

*pbindinfo*  
[no, out] Um ponteiro para o `BINDINFO` estrutura fornecendo mais informações sobre como deseja que o objeto de associação ocorra.

### <a name="return-value"></a>Valor de retorno

Um dos valores HRESULT padrão.

### <a name="remarks"></a>Comentários

A implementação padrão define a associação seja assíncrono e usar o modelo de push de dados. No modelo de push de dados, o moniker conduz a operação de vinculação assíncrona e continuamente notifica o cliente sempre que novos dados estão disponíveis.

##  <a name="getpriority"></a>  CBindStatusCallback::GetPriority

Chamado pelo moniker assíncrono para obter a prioridade da operação de associação.

```
STDMETHOD(GetPriority)(LONG* pnPriority);
```

### <a name="parameters"></a>Parâmetros

*pnPriority*  
[out] Endereço do **longo** variável que, em caso de sucesso, recebe a prioridade.

### <a name="return-value"></a>Valor de retorno

Retornará E_NOTIMPL.

##  <a name="m_dwavailabletoread"></a>  CBindStatusCallback::m_dwAvailableToRead

Pode ser usado para armazenar o número de bytes disponíveis para serem lidos.

```
DWORD m_dwAvailableToRead;
```

### <a name="remarks"></a>Comentários

Inicializado como zero `StartAsyncDownload`.

##  <a name="m_dwtotalread"></a>  CBindStatusCallback::m_dwTotalRead

O total acumulado de bytes de leitura na transferência de dados assíncronos.

```
DWORD m_dwTotalRead;
```

### <a name="remarks"></a>Comentários

Incrementado toda vez que `OnDataAvailable` é chamado pelo número de bytes realmente lidos. Inicializado como zero `StartAsyncDownload`.

##  <a name="m_pfunc"></a>  CBindStatusCallback::m_pFunc

A função apontada por `m_pFunc` é chamado pelo `OnDataAvailable` depois que ele lê os dados disponíveis (por exemplo, para armazenar os dados ou imprimi-lo na tela).

```
ATL_PDATAAVAILABLE m_pFunc;
```

### <a name="remarks"></a>Comentários

A função apontada por `m_pFunc` é um membro da classe do objeto e tem a seguinte sintaxe:

```  
void Function_Name(  
   CBindStatusCallback<T>* pbsc,  
   BYTE* pBytes,  
   DWORD dwSize  
   );  
```

##  <a name="m_pt"></a>  CBindStatusCallback::m_pT

Um ponteiro para o objeto que solicitou a transferência de dados assíncronos.

```
T* m_pT;
```

### <a name="remarks"></a>Comentários

O `CBindStatusCallback` objeto é modelado na classe do objeto.

##  <a name="m_spbindctx"></a>  CBindStatusCallback::m_spBindCtx

Um ponteiro para um [IBindCtx](/windows/desktop/api/objidl/nn-objidl-ibindctx) interface que fornece acesso ao contexto de associação (um objeto que armazena informações sobre uma operação de associação de moniker específico).

```
CComPtr<IBindCtx> m_spBindCtx;
```

### <a name="remarks"></a>Comentários

Inicializada no `StartAsyncDownload`.

##  <a name="m_spbinding"></a>  CBindStatusCallback::m_spBinding

Um ponteiro para o `IBinding` interface da operação de associação atual.

```
CComPtr<IBinding> m_spBinding;
```

### <a name="remarks"></a>Comentários

Inicializada no `OnStartBinding` e lançado em `OnStopBinding`.

##  <a name="m_spmoniker"></a>  CBindStatusCallback::m_spMoniker

Um ponteiro para o [IMoniker](/windows/desktop/api/objidl/nn-objidl-imoniker) interface para a URL a ser usada.

```
CComPtr<IMoniker> m_spMoniker;
```

### <a name="remarks"></a>Comentários

Inicializada no `StartAsyncDownload`.

##  <a name="m_spstream"></a>  CBindStatusCallback::m_spStream

Um ponteiro para o [IStream](/windows/desktop/api/objidl/nn-objidl-istream) interface da operação de associação atual.

```
CComPtr<IStream> m_spStream;
```

### <a name="remarks"></a>Comentários

Inicializada no `OnDataAvailable` do `STGMEDIUM` estrutura quando o sinalizador BCSF é BCSF_FIRSTDATANOTIFICATION e liberado quando o sinalizador BCSF é BCSF_LASTDATANOTIFICATION.

##  <a name="ondataavailable"></a>  CBindStatusCallback::OnDataAvailable

As chamadas de moniker assíncrona fornecida pelo sistema `OnDataAvailable` para fornecer dados para o objeto conforme ele se torna disponível.

```
STDMETHOD(  
    OnDataAvailable)(DWORD grfBSCF,
    DWORD dwSize,
    FORMATETC* /* pformatetc */,
    STGMEDIUM* pstgmed);
```

### <a name="parameters"></a>Parâmetros

*grfBSCF*  
[in] Um valor de enumeração BSCF. Um ou mais das seguintes opções: BSCF_FIRSTDATANOTIFICATION, BSCF_INTERMEDIARYDATANOTIFICATION ou BSCF_LASTDATANOTIFICATION.

*dwSize*  
[in] A quantidade cumulativa (em bytes) de dados disponíveis desde o início da associação. Pode ser zero, indicando que a quantidade de dados não é relevante ou que nenhum valor específico se tornou disponível.

*pformatetc*  
[in] Ponteiro para o [FORMATETC](/windows/desktop/com/the-formatetc-structure) estrutura que contém o formato dos dados disponíveis. Se não houver nenhum formato, pode ser CF_NULL.

*pstgmed*  
[in] Ponteiro para o [STGMEDIUM](/windows/desktop/com/the-stgmedium-structure) estrutura que contém os dados reais agora disponíveis.

### <a name="return-value"></a>Valor de retorno

Um dos valores HRESULT padrão.

### <a name="remarks"></a>Comentários

`OnDataAvailable` lê os dados e, em seguida, chama um método de classe do objeto (por exemplo, para armazenar os dados ou imprimi-lo na tela). Ver [CBindStatusCallback::StartAsyncDownload](#startasyncdownload) para obter detalhes.

##  <a name="onlowresource"></a>  CBindStatusCallback::OnLowResource

Chamado quando os recursos são insuficientes.

```
STDMETHOD(OnLowResource)(DWORD /* dwReserved */);
```

### <a name="parameters"></a>Parâmetros

*dwReserved*  
Reservado.

### <a name="return-value"></a>Valor de retorno

Retorna S_OK.

##  <a name="onobjectavailable"></a>  CBindStatusCallback::OnObjectAvailable

Chamado pelo moniker assíncrono para passar um ponteiro de interface de objeto para seu aplicativo.

```
STDMETHOD(OnObjectAvailable)(REFID /* riid */, IUnknown* /* punk */);
```

### <a name="parameters"></a>Parâmetros

*riid*  
Identificador de interface da interface solicitada. Não utilizado.

*punk*  
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

*ulProgress*  
Inteiro longo sem sinal. Não utilizado.

*ulProgressMax*  
Inteiro longo sem sinal não utilizado.

*ulStatusCode*  
Inteiro longo sem sinal. Não utilizado.

*szStatusText*  
Endereço de um valor de cadeia de caracteres. Não utilizado.

### <a name="return-value"></a>Valor de retorno

Retorna S_OK.

##  <a name="onstartbinding"></a>  CBindStatusCallback::OnStartBinding

Define o membro de dados [m_spBinding](#m_spbinding) para o `IBinding` ponteiro na *pBinding*.

```
STDMETHOD(OnStartBinding)(DWORD /* dwReserved */, IBinding* pBinding);
```

### <a name="parameters"></a>Parâmetros

*dwReserved*  
Reservado para uso futuro.

*pBinding*  
[in] Operação de vinculação de endereço da interface IBinding do atual. Isso não pode ser NULL. O cliente deve chamar AddRef no ponteiro this para manter uma referência para o objeto de associação.

##  <a name="onstopbinding"></a>  CBindStatusCallback::OnStopBinding

Versões do `IBinding` ponteiro em membro de dados [m_spBinding](#m_spbinding).

```
STDMETHOD(OnStopBinding)(HRESULT hresult, LPCWSTR /* szError */);
```

### <a name="parameters"></a>Parâmetros

*HRESULT*  
Código de status retornado da operação de associação.

szStatusText  
Endereço de um valor de cadeia de caracteres não utilizado.

### <a name="remarks"></a>Comentários

Chamado pelo moniker assíncrono fornecida pelo sistema para indicar o final da operação de associação.

##  <a name="startasyncdownload"></a>  CBindStatusCallback::StartAsyncDownload

Inicia a baixar os dados de forma assíncrona da URL especificada.

```
HRESULT StartAsyncDownload(  
    T* pT,
    ATL_PDATAAVAILABLE pFunc,
    BSTR bstrURL,
    IUnknown* pUnkContainer = NULL,
    BOOL bRelative = FALSE);
```

### <a name="parameters"></a>Parâmetros

*pT*  
[in] Um ponteiro para o objeto que solicitou a transferência de dados assíncronos. O `CBindStatusCallback` objeto é modelado na classe do objeto.

*pFunc*  
[in] Um ponteiro para a função que recebe os dados que está sendo lidos. A função é um membro de classe do objeto do tipo `T`. Ver **comentários** para sintaxe e exemplos.

*bstrURL*  
[in] A URL para obter dados. Pode ser qualquer nome de arquivo ou URL válido. Não pode ser NULL. Por exemplo:

`CComBSTR mybstr =_T("http://somesite/data.htm")`

*pUnkContainer*  
[in] O `IUnknown` do contêiner. NULL por padrão.

*bRelative*  
[in] Um sinalizador que indica se a URL é relativo ou absoluto. FALSE por padrão, o que significa que a URL é absoluto.

### <a name="return-value"></a>Valor de retorno

Um dos valores HRESULT padrão.

### <a name="remarks"></a>Comentários

Sempre que os dados estão disponíveis que ela seja enviada para o objeto por meio de `OnDataAvailable`. `OnDataAvailable` lê os dados e chama a função apontada por *pFunc* (por exemplo, para armazenar os dados ou imprimi-lo na tela).

A função apontada por *pFunc* é um membro da classe do objeto e tem a seguinte sintaxe:

```
void Function_Name(
    CBindStatusCallback<T>* pbsc,
    BYTE* pBytes,
    DWORD dwSize);
```

No exemplo a seguir (tiradas de [ASYNC](../../visual-cpp-samples.md) exemplo), a função `OnData` grava os dados recebidos em uma caixa de texto.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATL_Windowing#87](../../atl/codesnippet/cpp/cbindstatuscallback-class_2.h)]

## <a name="see-also"></a>Consulte também

[Visão geral da classe](../../atl/atl-class-overview.md)
