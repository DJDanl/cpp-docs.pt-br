---
title: Classe CBindStatusCallback | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
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
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 19aa979cb69bdbf8d74acbd96291fac9af78c845
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="cbindstatuscallback-class"></a>Classe CBindStatusCallback
Essa classe implementa o `IBindStatusCallback` interface.  
  
> [!IMPORTANT]
>  Essa classe e seus membros não podem ser usados em aplicativos que são executados o tempo de execução do Windows.  
  
## <a name="syntax"></a>Sintaxe  
  
```
template <class T,
    int nBindFlags = BINDF_ASYNCHRONOUS |   BINDF_ASYNCSTORAGE | BINDF_GETNEWESTVERSION | BINDF_NOWRITECACHE>  
class ATL_NO_VTABLE CBindStatusCallback : public CComObjectRootEx
 <T ::_ThreadModel::ThreadModelNoCS>,
    public IBindStatusCallbackImpl<T>
```  
  
#### <a name="parameters"></a>Parâmetros  
 `T`  
 A classe que contém a função que será chamada quando os dados são recebidos.  
  
 *nBindFlags*  
 Especifica os sinalizadores de associação que são retornados pelo [GetBindInfo](#getbindinfo). A implementação padrão define a associação será assíncrona, recupera a versão mais recente do objeto de dados/e não armazena os dados recuperados no cache de disco.  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CBindStatusCallback::CBindStatusCallback](#cbindstatuscallback)|O construtor.|  
|[CBindStatusCallback:: ~ CBindStatusCallback](#dtor)|O destruidor.|  
  
### <a name="public-methods"></a>Métodos públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CBindStatusCallback::Download](#download)|Método estático que inicia o processo de download, cria um `CBindStatusCallback` objeto e chamadas `StartAsyncDownload`.|  
|[CBindStatusCallback::GetBindInfo](#getbindinfo)|Chamado pelo moniker assíncrono para solicitar informações sobre o tipo de associação a ser criado.|  
|[CBindStatusCallback::GetPriority](#getpriority)|Chamado pelo moniker assíncrono para obter a prioridade da operação de ligação. Retorna a implementação de ATL `E_NOTIMPL`.|  
|[CBindStatusCallback::OnDataAvailable](#ondataavailable)|Chamado para fornecer dados para seu aplicativo assim que possível. Lê os dados e, em seguida, chama a função passada a ele para usar os dados.|  
|[CBindStatusCallback::OnLowResource](#onlowresource)|Chamado quando os recursos são insuficientes. Retorna a implementação de ATL `S_OK`.|  
|[CBindStatusCallback::OnObjectAvailable](#onobjectavailable)|Chamado pelo moniker assíncrono para transmitir um ponteiro de interface de objeto para seu aplicativo. Retorna a implementação de ATL `S_OK`.|  
|[CBindStatusCallback::OnProgress](#onprogress)|Chamado para indicar o progresso de um processo de download de dados. Retorna a implementação de ATL `S_OK`.|  
|[CBindStatusCallback::OnStartBinding](#onstartbinding)|Chamado quando a associação é iniciada.|  
|[CBindStatusCallback::OnStopBinding](#onstopbinding)|Chamado quando a transferência de dados assíncrono é interrompida.|  
|[CBindStatusCallback::StartAsyncDownload](#startasyncdownload)|Inicializa os bytes disponíveis e bytes de leitura para zero, cria um objeto de fluxo do tipo de envio de uma URL e chamadas `OnDataAvailable` toda vez que os dados estão disponíveis.|  
  
### <a name="public-data-members"></a>Membros de Dados Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CBindStatusCallback::m_dwAvailableToRead](#m_dwavailabletoread)|Número de bytes disponíveis para leitura.|  
|[CBindStatusCallback::m_dwTotalRead](#m_dwtotalread)|Número total de bytes lidos.|  
|[CBindStatusCallback::m_pFunc](#m_pfunc)|Ponteiro para a função de chamada quando os dados estão disponíveis.|  
|[CBindStatusCallback::m_pT](#m_pt)|Ponteiro para o objeto que solicitou a transferência de dados assíncrona.|  
|[CBindStatusCallback::m_spBindCtx](#m_spbindctx)|Ponteiro para o [IBindCtx](http://msdn.microsoft.com/library/windows/desktop/ms693755) interface para a operação de associação atual.|  
|[CBindStatusCallback::m_spBinding](#m_spbinding)|Ponteiro para o `IBinding` interface para a operação de associação atual.|  
|[CBindStatusCallback::m_spMoniker](#m_spmoniker)|Ponteiro para o [IMoniker](http://msdn.microsoft.com/library/windows/desktop/ms679705) interface para a URL a ser usado.|  
|[CBindStatusCallback::m_spStream](#m_spstream)|Ponteiro para o [IStream](http://msdn.microsoft.com/library/windows/desktop/aa380034) interface para a transferência de dados.|  
  
## <a name="remarks"></a>Comentários  
 A classe `CBindStatusCallback` implementa a interface `IBindStatusCallback`. `IBindStatusCallback`deve ser implementada por seu aplicativo para que ele pode receber notificações de uma transferência de dados assíncrona. O moniker assíncrono fornecido pelo sistema usa `IBindStatusCallback` métodos para enviar e receber informações sobre os dados assíncronas transferência de e para o objeto.  
  
 Normalmente, o `CBindStatusCallback` objeto está associado uma operação de ligação específica. Por exemplo, o [ASYNC](../../visual-cpp-samples.md) exemplo, quando você definir a propriedade de URL, ele cria um `CBindStatusCallback` objeto na chamada para `Download`:  
  
 [!code-cpp[NVC_ATL_Windowing#86](../../atl/codesnippet/cpp/cbindstatuscallback-class_1.h)]  
  
 O moniker assíncrono usa a função de retorno de chamada `OnData` para chamar o aplicativo quando ele tem dados. O moniker assíncrono é fornecido pelo sistema.  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 `CComObjectRootBase`  
  
 `IBindStatusCallback`  
  
 [CComObjectRootEx](../../atl/reference/ccomobjectrootex-class.md)  
  
 `CBindStatusCallback`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atlctl.h  
  
##  <a name="cbindstatuscallback"></a>CBindStatusCallback::CBindStatusCallback  
 O construtor.  
  
```
CBindStatusCallback();
```  
  
### <a name="remarks"></a>Comentários  
 Cria um objeto para receber notificações sobre a transferência de dados assíncrona. Normalmente, um objeto é criado para cada operação de ligação.  
  
 O construtor inicializa também [m_pT](#m_pt) e [m_pFunc](#m_pfunc) para **nulo**.  
  
##  <a name="dtor"></a>CBindStatusCallback:: ~ CBindStatusCallback  
 O destruidor.  
  
```
~CBindStatusCallback();
```  
  
### <a name="remarks"></a>Comentários  
 Libera todos os recursos alocados.  
  
##  <a name="download"></a>CBindStatusCallback::Download  
 Cria um `CBindStatusCallback` objeto e chamadas `StartAsyncDownload` para começar a baixar dados de forma assíncrona da URL especificada.  
  
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
 [in] Um ponteiro para o objeto que solicitou a transferência de dados assíncrona. O `CBindStatusCallback` objeto é transformado em modelo na classe do objeto.  
  
 *pFunc*  
 [in] Um ponteiro para a função que recebe os dados lidos. A função é um membro da classe do objeto do tipo `T`. Consulte [StartAsyncDownload](#startasyncdownload) para sintaxe e um exemplo.  
  
 `bstrURL`  
 [in] A URL para obter dados. Pode ser qualquer nome de arquivo ou URL válido. Não pode ser **nulo**. Por exemplo:  
  
 `CComBSTR mybstr =_T("http://somesite/data.htm")`  
  
 `pUnkContainer`  
 [in] O **IUnknown** do contêiner. **NULO** por padrão.  
  
 `bRelative`  
 [in] Um sinalizador que indica se a URL é relativo ou absoluto. **FALSE** por padrão, o que significa que a URL é absoluto.  
  
### <a name="return-value"></a>Valor de retorno  
 Um padrão `HRESULT` valores.  
  
### <a name="remarks"></a>Comentários  
 Sempre que os dados estão disponíveis são enviados para o objeto por meio de `OnDataAvailable`. `OnDataAvailable`lê os dados e chama a função apontada pelo *pFunc* (por exemplo, para armazenar os dados ou imprimi-lo para a tela).  
  
##  <a name="getbindinfo"></a>CBindStatusCallback::GetBindInfo  
 Chamado para informar o moniker como associar.  
  
```
STDMETHOD(GetBindInfo)(
    DWORD* pgrfBSCF,
    BINDINFO* pbindinfo);
```  
  
### <a name="parameters"></a>Parâmetros  
 *pgrfBSCF*  
 [out] Um ponteiro para **BINDF** valores de enumeração que indica como a operação de associação deve ocorrer. Por padrão, definida com os seguintes valores de enumeração:  
  
 **BINDF_ASYNCHRONOUS** download assíncrono.  
  
 **BINDF_ASYNCSTORAGE** `OnDataAvailable` retorna **E_PENDING** quando dados ainda não estão disponíveis em vez de bloqueio até que os dados estão disponíveis.  
  
 **BINDF_GETNEWESTVERSION** a operação de associação deve recuperar a versão mais recente dos dados.  
  
 **BINDF_NOWRITECACHE** a operação de associação não deve armazenar os dados recuperados no cache de disco.  
  
 *pbindinfo*  
 [out no] Um ponteiro para o **BINDINFO** estrutura fornece mais informações sobre como deseja que o objeto associação ocorra.  
  
### <a name="return-value"></a>Valor de retorno  
 Um padrão `HRESULT` valores.  
  
### <a name="remarks"></a>Comentários  
 A implementação padrão define a associação para ser assíncrona e usar o modelo de push de dados. No modelo de envio de dados, o moniker unidades de operação de vinculação assíncrona e continuamente notifica o cliente sempre que novos dados estão disponíveis.  
  
##  <a name="getpriority"></a>CBindStatusCallback::GetPriority  
 Chamado pelo moniker assíncrono para obter a prioridade da operação de ligação.  
  
```
STDMETHOD(GetPriority)(LONG* pnPriority);
```  
  
### <a name="parameters"></a>Parâmetros  
 *pnPriority*  
 [out] Endereço do **longo** variável que, em caso de sucesso, recebe a prioridade.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna **E_NOTIMPL**.  
  
##  <a name="m_dwavailabletoread"></a>CBindStatusCallback::m_dwAvailableToRead  
 Pode ser usado para armazenar o número de bytes disponíveis para serem lidos.  
  
```
DWORD m_dwAvailableToRead;
```  
  
### <a name="remarks"></a>Comentários  
 Inicializada como zero no `StartAsyncDownload`.  
  
##  <a name="m_dwtotalread"></a>CBindStatusCallback::m_dwTotalRead  
 O total acumulado de bytes lidos a transferência de dados assíncrona.  
  
```
DWORD m_dwTotalRead;
```  
  
### <a name="remarks"></a>Comentários  
 Incrementado toda vez que `OnDataAvailable` é chamado pelo número de bytes realmente lidos. Inicializada como zero no `StartAsyncDownload`.  
  
##  <a name="m_pfunc"></a>CBindStatusCallback::m_pFunc  
 A função apontada pelo `m_pFunc` é chamado pelo `OnDataAvailable` depois de ler os dados disponíveis (por exemplo, para armazenar os dados ou imprimi-lo para a tela).  
  
```
ATL_PDATAAVAILABLE m_pFunc;
```  
  
### <a name="remarks"></a>Comentários  
 A função apontada pelo `m_pFunc` é um membro da classe do objeto e tem a seguinte sintaxe:  
  
```  
void Function_Name(  
   CBindStatusCallback<T>* pbsc,  
   BYTE* pBytes,  
   DWORD dwSize  
   );  
```  
  
##  <a name="m_pt"></a>CBindStatusCallback::m_pT  
 Um ponteiro para o objeto que solicitou a transferência de dados assíncrona.  
  
```
T* m_pT;
```  
  
### <a name="remarks"></a>Comentários  
 O `CBindStatusCallback` objeto é transformado em modelo na classe do objeto.  
  
##  <a name="m_spbindctx"></a>CBindStatusCallback::m_spBindCtx  
 Um ponteiro para um [IBindCtx](http://msdn.microsoft.com/library/windows/desktop/ms693755) interface que fornece acesso ao contexto de associação (um objeto que armazena informações sobre uma operação de associação de moniker específico).  
  
```
CComPtr<IBindCtx> m_spBindCtx;
```  
  
### <a name="remarks"></a>Comentários  
 Inicializado no `StartAsyncDownload`.  
  
##  <a name="m_spbinding"></a>CBindStatusCallback::m_spBinding  
 Um ponteiro para o `IBinding` interface da operação de associação atual.  
  
```
CComPtr<IBinding> m_spBinding;
```  
  
### <a name="remarks"></a>Comentários  
 Inicializado no `OnStartBinding` e lançado em `OnStopBinding`.  
  
##  <a name="m_spmoniker"></a>CBindStatusCallback::m_spMoniker  
 Um ponteiro para o [IMoniker](http://msdn.microsoft.com/library/windows/desktop/ms679705) interface para a URL a ser usado.  
  
```
CComPtr<IMoniker> m_spMoniker;
```  
  
### <a name="remarks"></a>Comentários  
 Inicializado no `StartAsyncDownload`.  
  
##  <a name="m_spstream"></a>CBindStatusCallback::m_spStream  
 Um ponteiro para o [IStream](http://msdn.microsoft.com/library/windows/desktop/aa380034) interface da operação de associação atual.  
  
```
CComPtr<IStream> m_spStream;
```  
  
### <a name="remarks"></a>Comentários  
 Inicializado no `OnDataAvailable` do **STGMEDIUM** estrutura quando o **BCSF** sinalizador é **BCSF_FIRSTDATANOTIFICATION** e liberada quando o **BCSF**  sinalizador é **BCSF_LASTDATANOTIFICATION**.  
  
##  <a name="ondataavailable"></a>CBindStatusCallback::OnDataAvailable  
 As chamadas de fornecido pelo sistema assíncrona moniker `OnDataAvailable` para fornecer dados para o objeto assim que possível.  
  
```
STDMETHOD(  
    OnDataAvailable)(DWORD grfBSCF,
    DWORD dwSize,
    FORMATETC* /* pformatetc */,
    STGMEDIUM* pstgmed);
```  
  
### <a name="parameters"></a>Parâmetros  
 *grfBSCF*  
 [in] Um **BSCF** valor de enumeração. Um ou mais dos seguintes: **BSCF_FIRSTDATANOTIFICATION**, **BSCF_INTERMEDIARYDATANOTIFICATION**, ou **BSCF_LASTDATANOTIFICATION**.  
  
 `dwSize`  
 [in] A quantidade cumulativa (em bytes) disponíveis desde o início da associação de dados. Pode ser zero, indicando que a quantidade de dados não é relevante ou se não houver nenhum valor específico se tornaram disponível.  
  
 *pformatetc*  
 [in] Ponteiro para o [FORMATETC](http://msdn.microsoft.com/library/windows/desktop/ms682242) estrutura que contém o formato dos dados disponíveis. Se não houver nenhum formato, pode ser **CF_NULL**.  
  
 *pstgmed*  
 [in] Ponteiro para o [STGMEDIUM](http://msdn.microsoft.com/library/windows/desktop/ms695269) estrutura que contém os dados reais agora disponíveis.  
  
### <a name="return-value"></a>Valor de retorno  
 Um padrão `HRESULT` valores.  
  
### <a name="remarks"></a>Comentários  
 `OnDataAvailable`lê os dados e, em seguida, chama um método da classe do objeto (por exemplo, para armazenar os dados ou imprimi-lo para a tela). Consulte [CBindStatusCallback::StartAsyncDownload](#startasyncdownload) para obter detalhes.  
  
##  <a name="onlowresource"></a>CBindStatusCallback::OnLowResource  
 Chamado quando os recursos são insuficientes.  
  
```
STDMETHOD(OnLowResource)(DWORD /* dwReserved */);
```  
  
### <a name="parameters"></a>Parâmetros  
 `dwReserved`  
 Reservado.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna `S_OK`.  
  
##  <a name="onobjectavailable"></a>CBindStatusCallback::OnObjectAvailable  
 Chamado pelo moniker assíncrono para transmitir um ponteiro de interface de objeto para seu aplicativo.  
  
```
STDMETHOD(OnObjectAvailable)(REFID /* riid */, IUnknown* /* punk */);
```  
  
### <a name="parameters"></a>Parâmetros  
 `riid`  
 Identificador de interface da interface solicitada. Não utilizado.  
  
 `punk`  
 Endereço da interface IUnknown. Não utilizado.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna `S_OK`.  
  
##  <a name="onprogress"></a>CBindStatusCallback::OnProgress  
 Chamado para indicar o progresso de um processo de download de dados.  
  
```
STDMETHOD(OnProgress)(
    ULONG /* ulProgress */,
    ULONG /* ulProgressMax */,
    ULONG /* ulStatusCode */,
    LPCWSTRONG /* szStatusText */);
```  
  
### <a name="parameters"></a>Parâmetros  
 `ulProgress`  
 Inteiro longo não assinado. Não utilizado.  
  
 `ulProgressMax`  
 Inteiro longo não assinado não utilizado.  
  
 `ulStatusCode`  
 Inteiro longo não assinado. Não utilizado.  
  
 `szStatusText`  
 Endereço de um valor de cadeia de caracteres. Não utilizado.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna `S_OK`.  
  
##  <a name="onstartbinding"></a>CBindStatusCallback::OnStartBinding  
 Define o membro de dados [m_spBinding](#m_spbinding) para o `IBinding` ponteiro em `pBinding`.  
  
```
STDMETHOD(OnStartBinding)(DWORD /* dwReserved */, IBinding* pBinding);
```  
  
### <a name="parameters"></a>Parâmetros  
 `dwReserved`  
 Reservado para uso futuro.  
  
 `pBinding`  
 [in] Operação de vinculação do endereço da interface IBinding do atual. Isso não pode ser NULL. O cliente deve chamar AddRef esse ponteiro para manter uma referência para o objeto de associação.  
  
##  <a name="onstopbinding"></a>CBindStatusCallback::OnStopBinding  
 Versões de `IBinding` ponteiro em membro de dados [m_spBinding](#m_spbinding).  
  
```
STDMETHOD(OnStopBinding)(HRESULT hresult, LPCWSTR /* szError */);
```  
  
### <a name="parameters"></a>Parâmetros  
 `hresult`  
 Código de status retornado da operação de ligação.  
  
 szStatusText  
 Endereço de um valor de cadeia de caracteres não utilizado.  
  
### <a name="remarks"></a>Comentários  
 Chamado pelo moniker assíncrono fornecida pelo sistema para indicar o final da operação de ligação.  
  
##  <a name="startasyncdownload"></a>CBindStatusCallback::StartAsyncDownload  
 Inicia o download de forma assíncrona da URL especificada.  
  
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
 [in] Um ponteiro para o objeto que solicitou a transferência de dados assíncrona. O `CBindStatusCallback` objeto é transformado em modelo na classe do objeto.  
  
 *pFunc*  
 [in] Um ponteiro para a função que recebe os dados que está sendo lidos. A função é um membro da classe do objeto do tipo `T`. Consulte **comentários** para sintaxe e um exemplo.  
  
 `bstrURL`  
 [in] A URL para obter dados. Pode ser qualquer nome de arquivo ou URL válido. Não pode ser **nulo**. Por exemplo:  
  
 `CComBSTR mybstr =_T("http://somesite/data.htm")`  
  
 `pUnkContainer`  
 [in] O **IUnknown** do contêiner. **NULO** por padrão.  
  
 `bRelative`  
 [in] Um sinalizador que indica se a URL é relativo ou absoluto. **FALSE** por padrão, o que significa que a URL é absoluto.  
  
### <a name="return-value"></a>Valor de retorno  
 Um padrão `HRESULT` valores.  
  
### <a name="remarks"></a>Comentários  
 Sempre que os dados estão disponíveis são enviados para o objeto por meio de `OnDataAvailable`. `OnDataAvailable`lê os dados e chama a função apontada pelo *pFunc* (por exemplo, para armazenar os dados ou imprimi-lo para a tela).  
  
 A função apontada pelo *pFunc* é um membro da classe do objeto e tem a seguinte sintaxe:  
  
 `void Function_Name(`  
  
 `CBindStatusCallback<T>*``pbsc``,`  
  
 `BYTE*``pBytes``,`  
  
 `DWORD` `dwSize`  
  
 `);`  
  
 No exemplo a seguir (obtido o [ASYNC](../../visual-cpp-samples.md) exemplo), a função `OnData` grava os dados recebidos em uma caixa de texto.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_ATL_Windowing#87](../../atl/codesnippet/cpp/cbindstatuscallback-class_2.h)]  
  
## <a name="see-also"></a>Consulte também  
 [Visão geral da classe](../../atl/atl-class-overview.md)
