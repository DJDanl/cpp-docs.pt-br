---
title: Classe CCmdTarget | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- CCmdTarget
- AFXWIN/CCmdTarget
- AFXWIN/CCmdTarget::CCmdTarget
- AFXWIN/CCmdTarget::BeginWaitCursor
- AFXWIN/CCmdTarget::DoOleVerb
- AFXWIN/CCmdTarget::EnableAutomation
- AFXWIN/CCmdTarget::EnableConnections
- AFXWIN/CCmdTarget::EnableTypeLib
- AFXWIN/CCmdTarget::EndWaitCursor
- AFXWIN/CCmdTarget::EnumOleVerbs
- AFXWIN/CCmdTarget::FromIDispatch
- AFXWIN/CCmdTarget::GetDispatchIID
- AFXWIN/CCmdTarget::GetIDispatch
- AFXWIN/CCmdTarget::GetTypeInfoCount
- AFXWIN/CCmdTarget::GetTypeInfoOfGuid
- AFXWIN/CCmdTarget::GetTypeLib
- AFXWIN/CCmdTarget::GetTypeLibCache
- AFXWIN/CCmdTarget::IsInvokeAllowed
- AFXWIN/CCmdTarget::IsResultExpected
- AFXWIN/CCmdTarget::OnCmdMsg
- AFXWIN/CCmdTarget::OnFinalRelease
- AFXWIN/CCmdTarget::RestoreWaitCursor
dev_langs:
- C++
helpviewer_keywords:
- message maps, CCmdTarget base class
- command targets
- CCmdTarget class
- command routing, command targets
- targets, command
ms.assetid: 8883b132-2057-4ce0-a5f2-88979f8f2b13
caps.latest.revision: 23
author: mikeblome
ms.author: mblome
manager: ghogen
translation.priority.ht:
- cs-cz
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- pl-pl
- pt-br
- ru-ru
- tr-tr
- zh-cn
- zh-tw
ms.translationtype: Machine Translation
ms.sourcegitcommit: 128bd124c2536d86c8b673b54abc4b5505526b41
ms.openlocfilehash: d58ee8e02c57c48c58f13c7e826fd01a1c0d9f57
ms.contentlocale: pt-br
ms.lasthandoff: 05/10/2017

---
# <a name="ccmdtarget-class"></a>Classe CCmdTarget
A classe base para a arquitetura de mapa de mensagem de biblioteca Microsoft Foundation Class.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class CCmdTarget : public CObject  
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CCmdTarget::CCmdTarget](#ccmdtarget)|Constrói um objeto `CCmdTarget`.|  
  
### <a name="public-methods"></a>Métodos Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CCmdTarget::BeginWaitCursor](#beginwaitcursor)|Exibe o cursor como um cursor ampulheta.|  
|[CCmdTarget::DoOleVerb](#dooleverb)|Faz com que uma ação especificada por um verbo OLE a ser executada.|  
|[CCmdTarget::EnableAutomation](#enableautomation)|Permite a automação OLE para o `CCmdTarget` objeto.|  
|[CCmdTarget::EnableConnections](#enableconnections)|Habilita o acionamento de evento em pontos de conexão.|  
|[CCmdTarget::EnableTypeLib](#enabletypelib)|Permite que a biblioteca de tipos de um objeto.|  
|[CCmdTarget::EndWaitCursor](#endwaitcursor)|Retorna o cursor anterior.|  
|[CCmdTarget::EnumOleVerbs](#enumoleverbs)|Enumera os verbos de um objeto OLE.|  
|[CCmdTarget::FromIDispatch](#fromidispatch)|Retorna um ponteiro para o `CCmdTarget` objeto associado a `IDispatch` ponteiro.|  
|[CCmdTarget::GetDispatchIID](#getdispatchiid)|Obtém a ID de interface de Despache primário.|  
|[CCmdTarget::GetIDispatch](#getidispatch)|Retorna um ponteiro para o `IDispatch` objeto associado a `CCmdTarget` objeto.|  
|[CCmdTarget::GetTypeInfoCount](#gettypeinfocount)|Recupera o número de interfaces de informações de tipo que fornece um objeto.|  
|[CCmdTarget::GetTypeInfoOfGuid](#gettypeinfoofguid)|Recupera a descrição do tipo que corresponde ao GUID especificado.|  
|[CCmdTarget::GetTypeLib](#gettypelib)|Obtém um ponteiro para uma biblioteca de tipos.|  
|[CCmdTarget::GetTypeLibCache](#gettypelibcache)|Obtém o cache de biblioteca de tipos.|  
|[CCmdTarget::IsInvokeAllowed](#isinvokeallowed)|Permite a invocação de método de automação.|  
|[CCmdTarget::IsResultExpected](#isresultexpected)|Retorna zero se uma função de automação deve retornar um valor.|  
|[CCmdTarget::OnCmdMsg](#oncmdmsg)|Encaminha e envia mensagens de comando.|  
|[CCmdTarget::OnFinalRelease](#onfinalrelease)|Limpa após a última referência OLE é liberada.|  
|[CCmdTarget::RestoreWaitCursor](#restorewaitcursor)|Restaura o cursor de ampulheta.|  
  
## <a name="remarks"></a>Comentários  
 Um mapa de mensagem encaminha mensagens ou comandos para as funções de membro que gravar tratá-los. (Um comando é uma mensagem de um item de menu, um botão de comando ou uma tecla de aceleração.)  
  
 Estrutura de chave classes derivadas de `CCmdTarget` incluem [CView](../../mfc/reference/cview-class.md), [CWinApp](../../mfc/reference/cwinapp-class.md), [CDocument](../../mfc/reference/cdocument-class.md), [CWnd](../../mfc/reference/cwnd-class.md), e [CFrameWnd](../../mfc/reference/cframewnd-class.md). Se você pretende uma nova classe manipular mensagens, derive a classe de uma destas opções `CCmdTarget`-classes derivadas. Raramente obterão uma classe de `CCmdTarget` diretamente.  
  
 Para obter uma visão geral de destinos de comando e `OnCmdMsg` roteamento, consulte [destinos de comando](../../mfc/command-targets.md), [roteamento de comando](../../mfc/command-routing.md), e [mapeamento mensagens](../../mfc/mapping-messages.md).  
  
 `CCmdTarget`inclui funções de membro que lidam com a exibição de um cursor de ampulheta. Exiba o cursor de ampulheta quando você espera que um intervalo de tempo significativo para executar um comando.  
  
 Mapas, como mapas de mensagem de expedição, são usadas para expor a automação OLE `IDispatch` funcionalidade. Expondo essa interface, outros aplicativos (como o Visual Basic) podem chamar seu aplicativo.  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 [CObject](../../mfc/reference/cobject-class.md)  
  
 `CCmdTarget`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxwin.h  
  
##  <a name="beginwaitcursor"></a>CCmdTarget::BeginWaitCursor  
 Chame essa função para exibir o cursor como uma ampulheta, quando você espera que um intervalo de tempo significativo para executar um comando.  
  
```  
void BeginWaitCursor();
```  
  
### <a name="remarks"></a>Comentários  
 O framework chama esta função para mostrar ao usuário que está ocupado, por exemplo, quando um **CDocument** objeto carrega ou salva um arquivo em si.  
  
 As ações de `BeginWaitCursor` não são sempre efetivo fora de um manipulador de mensagens único como outras ações, como `OnSetCursor` tratamento, pode alterar o cursor.  
  
 Chamar `EndWaitCursor` para restaurar o cursor anterior.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFCDocView º 43](../../mfc/codesnippet/cpp/ccmdtarget-class_1.cpp)]  
  
##  <a name="ccmdtarget"></a>CCmdTarget::CCmdTarget  
 Constrói um objeto `CCmdTarget`.  
  
```  
CCmdTarget();
```  
  
##  <a name="dooleverb"></a>CCmdTarget::DoOleVerb  
 Faz com que uma ação especificada por um verbo OLE a ser executada.  
  
```  
BOOL DoOleVerb(
    LONG iVerb,  
    LPMSG lpMsg,  
    HWND hWndParent,  
    LPCRECT lpRect);
```  
  
### <a name="parameters"></a>Parâmetros  
 `iVerb`  
 Identificador numérico do verbo.  
  
 `lpMsg`  
 Ponteiro para o [MSG](http://msdn.microsoft.com/library/windows/desktop/ms644958) estrutura que descreve o evento (por exemplo, um clique duplo) que invocou o verbo.  
  
 `hWndParent`  
 Identificador da janela do documento que contém o objeto.  
  
 `lpRect`  
 Ponteiro para o [RECT](http://msdn.microsoft.com/library/windows/desktop/dd162897) estrutura que contém as coordenadas, em pixels, que definem um objeto de limite do retângulo em *hwndParent*.  
  
### <a name="return-value"></a>Valor de retorno  
 TRUE se bem-sucedido, caso contrário, FALSE.  
  
### <a name="remarks"></a>Comentários  
 Essa função de membro é basicamente uma implementação de [IOleObject:: DoVerb](http://msdn.microsoft.com/library/windows/desktop/ms694508). As ações possíveis são enumeradas pelo [CCmdTarget::EnumOleVerbs](#enumoleverbs).  
  
##  <a name="enableautomation"></a>CCmdTarget::EnableAutomation  
 Chame essa função para habilitar a automação OLE para um objeto.  
  
```  
void EnableAutomation();
```  
  
### <a name="remarks"></a>Comentários  
 Esta função geralmente é chamada a partir do construtor do objeto e deve ser chamada somente se um mapa de expedição foi declarado para a classe. Para obter mais informações sobre a automação, consulte os artigos [clientes de automação](../../mfc/automation-clients.md) e [servidores de automação](../../mfc/automation-servers.md).  
  
##  <a name="enableconnections"></a>CCmdTarget::EnableConnections  
 Habilita o acionamento de evento em pontos de conexão.  
  
```  
void EnableConnections();
```  
  
### <a name="remarks"></a>Comentários  
 Para habilitar pontos de conexão, chame a função de membro no construtor de classe derivada.  
  
##  <a name="enabletypelib"></a>CCmdTarget::EnableTypeLib  
 Permite que a biblioteca de tipos de um objeto.  
  
```  
void EnableTypeLib();
```  
  
### <a name="remarks"></a>Comentários  
 Chamar essa função de membro no construtor de seu `CCmdTarget`-objeto derivado se ele fornece informações de tipo. Para obter mais informações, consulte o artigo da Base de dados de Conhecimento Q185720, "como: fornecer informações de tipo de um servidor de automação MFC." Artigos da Base de dados de Conhecimento estão disponíveis em [http://support.microsoft.com](http://support.microsoft.com/).  
  
##  <a name="endwaitcursor"></a>CCmdTarget::EndWaitCursor  
 Chamar essa função depois de ter chamado o `BeginWaitCursor` a função de membro para retornar do cursor ampulheta até o cursor anterior.  
  
```  
void EndWaitCursor();
```  
  
### <a name="remarks"></a>Comentários  
 A estrutura também chama essa função de membro depois que ela é chamada de cursor ampulheta.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFCDocView º 43](../../mfc/codesnippet/cpp/ccmdtarget-class_1.cpp)]  
  
##  <a name="enumoleverbs"></a>CCmdTarget::EnumOleVerbs  
 Enumera os verbos de um objeto OLE.  
  
```  
BOOL EnumOleVerbs(LPENUMOLEVERB* ppenumOleVerb);
```  
  
### <a name="parameters"></a>Parâmetros  
 `ppenumOleVerb`  
 Um ponteiro para um ponteiro para um [IEnumOLEVERB](http://msdn.microsoft.com/library/windows/desktop/ms695084) interface.  
  
### <a name="return-value"></a>Valor de retorno  
 TRUE se o objeto oferecer suporte a pelo menos um verbo OLE (neste caso \* `ppenumOleVerb` aponta para um **IEnumOLEVERB** interface enumerador), caso contrário, FALSE.  
  
### <a name="remarks"></a>Comentários  
 Essa função de membro é basicamente uma implementação de [IOleObject::EnumVerbs](http://msdn.microsoft.com/library/windows/desktop/ms692781).  
  
##  <a name="fromidispatch"></a>CCmdTarget::FromIDispatch  
 Chamar essa função para mapear um `IDispatch` ponteiro, recebido de funções de membro de automação de uma classe para o `CCmdTarget` objeto que implementa as interfaces do `IDispatch` objeto.  
  
```  
static CCmdTarget* PASCAL FromIDispatch(LPDISPATCH lpDispatch);
```  
  
### <a name="parameters"></a>Parâmetros  
 `lpDispatch`  
 Um ponteiro para um objeto `IDispatch`.  
  
### <a name="return-value"></a>Valor de retorno  
 Um ponteiro para o `CCmdTarget` objeto associado ao `lpDispatch`. Essa função retorna **nulo** se o `IDispatch` objeto não é reconhecido como um Microsoft Foundation Class `IDispatch` objeto.  
  
### <a name="remarks"></a>Comentários  
 O resultado dessa função é o inverso de uma chamada para a função de membro `GetIDispatch`.  
  
##  <a name="getdispatchiid"></a>CCmdTarget::GetDispatchIID  
 Obtém a ID de interface de Despache primário.  
  
```  
virtual BOOL GetDispatchIID(IID* pIID);
```  
  
### <a name="parameters"></a>Parâmetros  
 *pIID*  
 Um ponteiro para uma ID de interface (uma [GUID](http://msdn.microsoft.com/library/windows/desktop/aa373931)).  
  
### <a name="return-value"></a>Valor de retorno  
 TRUE se bem-sucedido, caso contrário, FALSE. Se for bem-sucedido, \* *pIID* é definida como a ID de interface de Despache primário.  
  
### <a name="remarks"></a>Comentários  
 Classes derivadas devem substituir essa função de membro (se não for substituída, `GetDispatchIID` retorna FALSE). Consulte [COleControl](../../mfc/reference/colecontrol-class.md).  
  
 Para obter mais informações, consulte o artigo da Base de dados de Conhecimento Q185720, "como: fornecer informações de tipo de um servidor de automação MFC." Artigos da Base de dados de Conhecimento estão disponíveis em [http://support.microsoft.com](http://support.microsoft.com/).  
  
##  <a name="getidispatch"></a>CCmdTarget::GetIDispatch  
 Chamar essa função de membro para recuperar o `IDispatch` ponteiro de um método de automação que retorna um `IDispatch` ponteiro ou usa um `IDispatch` ponteiro por referência.  
  
```  
LPDISPATCH GetIDispatch(BOOL bAddRef);
```  
  
### <a name="parameters"></a>Parâmetros  
 *bAddRef*  
 Especifica se deseja incrementar a contagem de referência para o objeto.  
  
### <a name="return-value"></a>Valor de retorno  
 O `IDispatch` ponteiro associado ao objeto.  
  
### <a name="remarks"></a>Comentários  
 Para objetos que chamam `EnableAutomation` em seus construtores, tornando-os automação habilitada, essa função retorna um ponteiro para a implementação da classe base `IDispatch` que é usado por clientes que se comunicam por meio de `IDispatch` interface. Chamar essa função automaticamente adiciona uma referência para o ponteiro, portanto, não é necessário fazer uma chamada para [AddRef](http://msdn.microsoft.com/library/windows/desktop/ms691379).  
  
##  <a name="gettypeinfocount"></a>CCmdTarget::GetTypeInfoCount  
 Recupera o número de interfaces de informações de tipo que fornece um objeto.  
  
```  
virtual UINT GetTypeInfoCount();
```  
  
### <a name="return-value"></a>Valor de retorno  
 O número de interfaces de informações de tipo.  
  
### <a name="remarks"></a>Comentários  
 Essa função de membro basicamente implementa [IDispatch::GetTypeInfoCount](http://msdn.microsoft.com/en-us/da876d53-cb8a-465c-a43e-c0eb272e2a12).  
  
 Classes derivadas devem substituir esta função para retornar o número de interfaces de informações de tipo fornecido (0 ou 1). Se não for substituída, **GetTypeInfoCount** retorna 0. Para substituir, use o [IMPLEMENT_OLETYPELIB](../../mfc/reference/type-library-access.md#implement_oletypelib) macro, que também implementa `GetTypeLib` e `GetTypeLibCache`.  
  
##  <a name="gettypeinfoofguid"></a>CCmdTarget::GetTypeInfoOfGuid  
 Recupera a descrição do tipo que corresponde ao GUID especificado.  
  
```  
HRESULT GetTypeInfoOfGuid(
    LCID lcid,  
    const GUID& guid,  
    LPTYPEINFO* ppTypeInfo);
```  
  
### <a name="parameters"></a>Parâmetros  
 `lcid`  
 Um identificador de localidade ( `LCID`).  
  
 `guid`  
 O [GUID](http://msdn.microsoft.com/library/windows/desktop/aa373931) da descrição de tipo.  
  
 `ppTypeInfo`  
 Ponteiro para um ponteiro para o `ITypeInfo` interface.  
  
### <a name="return-value"></a>Valor de retorno  
 Um HRESULT indicando o êxito ou falha da chamada. Se for bem-sucedido, * `ppTypeInfo` aponta para a interface de informações de tipo.  
  
##  <a name="gettypelib"></a>CCmdTarget::GetTypeLib  
 Obtém um ponteiro para uma biblioteca de tipos.  
  
```  
virtual HRESULT GetTypeLib(
    LCID lcid,  
    LPTYPELIB* ppTypeLib);
```  
  
### <a name="parameters"></a>Parâmetros  
 `lcid`  
 Um identificador de localidade ( `LCID`).  
  
 `ppTypeLib`  
 Um ponteiro para um ponteiro para o `ITypeLib` interface.  
  
### <a name="return-value"></a>Valor de retorno  
 Um HRESULT indicando o êxito ou falha da chamada. Se for bem-sucedido, * `ppTypeLib` aponta para a interface de biblioteca de tipo.  
  
### <a name="remarks"></a>Comentários  
 Classes derivadas devem substituir essa função de membro (se não for substituída, `GetTypeLib` retorna TYPE_E_CANTLOADLIBRARY). Use o [IMPLEMENT_OLETYPELIB](../../mfc/reference/type-library-access.md#implement_oletypelib) macro, que também implementa `GetTypeInfoCount` e `GetTypeLibCache`.  
  
##  <a name="gettypelibcache"></a>CCmdTarget::GetTypeLibCache  
 Obtém o cache de biblioteca de tipos.  
  
```  
virtual CTypeLibCache* GetTypeLibCache();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um ponteiro para um **CTypeLibCache** objeto.  
  
### <a name="remarks"></a>Comentários  
 Classes derivadas devem substituir essa função de membro (se não for substituída, **GetTypeLibCache** retorna NULL). Use o [IMPLEMENT_OLETYPELIB](../../mfc/reference/type-library-access.md#implement_oletypelib) macro, que também implementa `GetTypeInfoCount` e `GetTypeLib`.  
  
##  <a name="isinvokeallowed"></a>CCmdTarget::IsInvokeAllowed  
 Essa função é chamada pela implementação do MFC de **IDispatch:: Invoke** para determinar se um método de automação determinado (identificada pelo `dispid`) pode ser invocado.  
  
```  
virtual BOOL IsInvokeAllowed(DISPID dispid);
```  
  
### <a name="parameters"></a>Parâmetros  
 `dispid`  
 Uma ID de expedição.  
  
### <a name="return-value"></a>Valor de retorno  
 TRUE se o método pode ser invocado, caso contrário, FALSE.  
  
### <a name="remarks"></a>Comentários  
 Se `IsInvokeAllowed` retorna TRUE, **Invoke** prossegue para chamar o método; caso contrário, `Invoke` falhará, retornando E_UNEXPECTED.  
  
 Classes derivadas podem substituir essa função para retornar os valores apropriados (se não for substituída, `IsInvokeAllowed` retorna TRUE). Consulte em particular [COleControl::IsInvokeAllowed](../../mfc/reference/colecontrol-class.md#isinvokeallowed).  
  
##  <a name="isresultexpected"></a>CCmdTarget::IsResultExpected  
 Use `IsResultExpected` para determinar se um cliente espera um valor de retorno de chamada de uma função de automação.  
  
```  
BOOL IsResultExpected();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se uma função de automação deve retornar um valor. Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 A interface OLE fornece informações sobre se o cliente está usando ou ignorando o resultado de uma chamada de função para MFC e, por sua vez, o MFC usa essas informações para determinar o resultado de uma chamada para `IsResultExpected`. Se a produção de um valor de retorno intensiva de tempo ou de recurso, você pode aumentar a eficiência ao chamar essa função antes de calcular o valor de retorno.  
  
 Essa função retorna 0, apenas uma vez para que você obtém valores de retorno válidos de outras funções de automação se você chamá-los da função de automação que chamou o cliente.  
  
 `IsResultExpected`Retorna um valor diferente de zero se chamado quando uma chamada de função de automação não está em andamento.  
  
##  <a name="oncmdmsg"></a>CCmdTarget::OnCmdMsg  
 Chamado pelo framework para rotear e distribuir mensagens de comando e para tratar a atualização dos objetos de interface do usuário do comando.  
  
```  
virtual BOOL OnCmdMsg(
    UINT nID,  
    int nCode,  
    void* pExtra,  
    AFX_CMDHANDLERINFO* pHandlerInfo);
```  
  
### <a name="parameters"></a>Parâmetros  
 `nID`  
 Contém a ID de comando.  
  
 `nCode`  
 Identifica o código de notificação de comando. Consulte **comentários** para obter mais informações sobre os valores de `nCode`.  
  
 `pExtra`  
 Usada de acordo com o valor de `nCode`. Consulte **comentários** para obter mais informações sobre `pExtra`.  
  
 `pHandlerInfo`  
 Se não **nulo**, `OnCmdMsg` preenche o **pTarget** e **pmf** membros o `pHandlerInfo` estrutura em vez de expedir o comando. Normalmente, esse parâmetro deve ser **nulo**.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se a mensagem é lida; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Isso é a rotina principal de implementação de arquitetura de comando do framework.  
  
 Em tempo de execução `OnCmdMsg` envia um comando para outros objetos ou processar o comando chamando a classe raiz `CCmdTarget::OnCmdMsg`, que faz a pesquisa de mapa de mensagem real. Para obter uma descrição completa de como o roteamento de comando padrão, consulte [manipulação de mensagens e mapeamento de tópicos](../../mfc/message-handling-and-mapping.md).  
  
 Em raras ocasiões, talvez você queira substituir essa função de membro para estender a estrutura de roteamento de comando padrão. Consulte [21 de observação técnica](../../mfc/tn021-command-and-message-routing.md) para obter detalhes avançados da arquitetura de roteamento de comando.  
  
 Se você substituir `OnCmdMsg`, você deve fornecer o valor apropriado para `nCode`, o código de notificação de comando, e `pExtra`, que depende do valor de `nCode`. A tabela a seguir lista os valores correspondentes:  
  
|Valor `nCode`|Valor `pExtra`|  
|-------------------|--------------------|  
|CN_COMMAND|[CCmdUI](../../mfc/reference/ccmdui-class.md)*|  
|CN_EVENT|AFX_EVENT *|  
|CN_UPDATE_COMMAND_UI|CCmdUI *|  
|CN_OLECOMMAND|[COleCmdUI](../../mfc/reference/colecmdui-class.md)*|  
|CN_OLE_UNREGISTER|NULL|  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFCDocView º 44](../../mfc/codesnippet/cpp/ccmdtarget-class_2.cpp)]  
  
 [!code-cpp[45 NVC_MFCDocView](../../mfc/codesnippet/cpp/ccmdtarget-class_3.cpp)]  
  
##  <a name="onfinalrelease"></a>CCmdTarget::OnFinalRelease  
 Chamado pelo framework quando a última referência OLE para ou do objeto é liberada.  
  
```  
virtual void OnFinalRelease();
```  
  
### <a name="remarks"></a>Comentários  
 Substitua essa função para fornecer um tratamento especial para essa situação. A implementação padrão exclui o objeto.  
  
##  <a name="restorewaitcursor"></a>CCmdTarget::RestoreWaitCursor  
 Chame essa função para restaurar o cursor de ampulheta apropriado após o cursor do sistema foi alterado (por exemplo, depois que uma caixa de mensagem é aberto e fechado, em seguida, no meio de uma operação demorada).  
  
```  
void RestoreWaitCursor();
```  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFCDocView º 43](../../mfc/codesnippet/cpp/ccmdtarget-class_1.cpp)]  
  
## <a name="see-also"></a>Consulte também  
 [Exemplo MFC ACDUAL](../../visual-cpp-samples.md)   
 [Classe CObject](../../mfc/reference/cobject-class.md)   
 [Gráfico de hierarquia](../../mfc/hierarchy-chart.md)   
 [Classe CCmdUI](../../mfc/reference/ccmdui-class.md)   
 [Classe CDocument](../../mfc/reference/cdocument-class.md)   
 [Classe CDocTemplate](../../mfc/reference/cdoctemplate-class.md)   
 [Classe CWinApp](../../mfc/reference/cwinapp-class.md)   
 [Classe CWnd](../../mfc/reference/cwnd-class.md)   
 [Classe CView](../../mfc/reference/cview-class.md)   
 [Classe CFrameWnd](../../mfc/reference/cframewnd-class.md)   
 [Classe COleDispatchDriver](../../mfc/reference/coledispatchdriver-class.md)

