---
title: Classe CCmdTarget
ms.date: 11/04/2016
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
helpviewer_keywords:
- CCmdTarget [MFC], CCmdTarget
- CCmdTarget [MFC], BeginWaitCursor
- CCmdTarget [MFC], DoOleVerb
- CCmdTarget [MFC], EnableAutomation
- CCmdTarget [MFC], EnableConnections
- CCmdTarget [MFC], EnableTypeLib
- CCmdTarget [MFC], EndWaitCursor
- CCmdTarget [MFC], EnumOleVerbs
- CCmdTarget [MFC], FromIDispatch
- CCmdTarget [MFC], GetDispatchIID
- CCmdTarget [MFC], GetIDispatch
- CCmdTarget [MFC], GetTypeInfoCount
- CCmdTarget [MFC], GetTypeInfoOfGuid
- CCmdTarget [MFC], GetTypeLib
- CCmdTarget [MFC], GetTypeLibCache
- CCmdTarget [MFC], IsInvokeAllowed
- CCmdTarget [MFC], IsResultExpected
- CCmdTarget [MFC], OnCmdMsg
- CCmdTarget [MFC], OnFinalRelease
- CCmdTarget [MFC], RestoreWaitCursor
ms.assetid: 8883b132-2057-4ce0-a5f2-88979f8f2b13
ms.openlocfilehash: 9314717fab53b1a89b87d657ec617a4c6bd45b8b
ms.sourcegitcommit: 72583d30170d6ef29ea5c6848dc00169f2c909aa
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/18/2019
ms.locfileid: "58776187"
---
# <a name="ccmdtarget-class"></a>Classe CCmdTarget

A classe base para a arquitetura de mapa de mensagem da biblioteca Microsoft Foundation Class.

## <a name="syntax"></a>Sintaxe

```
class CCmdTarget : public CObject
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[CCmdTarget::CCmdTarget](#ccmdtarget)|Constrói um objeto `CCmdTarget`.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CCmdTarget::BeginWaitCursor](#beginwaitcursor)|Exibe o cursor como um cursor de ampulheta.|
|[CCmdTarget::DoOleVerb](#dooleverb)|Faz com que uma ação especificada por um verbo OLE a ser executada.|
|[CCmdTarget::EnableAutomation](#enableautomation)|Permite a automação OLE para o `CCmdTarget` objeto.|
|[CCmdTarget::EnableConnections](#enableconnections)|Habilita o acionamento do evento sobre pontos de conexão.|
|[CCmdTarget::EnableTypeLib](#enabletypelib)|Permite que a biblioteca de tipos do objeto.|
|[CCmdTarget::EndWaitCursor](#endwaitcursor)|Retorna o cursor anterior.|
|[CCmdTarget::EnumOleVerbs](#enumoleverbs)|Enumera os verbos do objeto OLE.|
|[CCmdTarget::FromIDispatch](#fromidispatch)|Retorna um ponteiro para o `CCmdTarget` objeto associado com o `IDispatch` ponteiro.|
|[CCmdTarget::GetDispatchIID](#getdispatchiid)|Obtém a ID de interface de expedição primária.|
|[CCmdTarget::GetIDispatch](#getidispatch)|Retorna um ponteiro para o `IDispatch` objeto associado com o `CCmdTarget` objeto.|
|[CCmdTarget::GetTypeInfoCount](#gettypeinfocount)|Recupera o número de interfaces de informações de tipo que fornece um objeto.|
|[CCmdTarget::GetTypeInfoOfGuid](#gettypeinfoofguid)|Recupera a descrição de tipo que corresponde ao GUID especificado.|
|[CCmdTarget::GetTypeLib](#gettypelib)|Obtém um ponteiro para uma biblioteca de tipos.|
|[CCmdTarget::GetTypeLibCache](#gettypelibcache)|Obtém o cache de biblioteca de tipos.|
|[CCmdTarget::IsInvokeAllowed](#isinvokeallowed)|Permite a invocação de método de automação.|
|[CCmdTarget::IsResultExpected](#isresultexpected)|Retorna diferente de zero se uma função de automação deve retornar um valor.|
|[CCmdTarget::OnCmdMsg](#oncmdmsg)|As rotas e expede mensagens de comando.|
|[CCmdTarget::OnFinalRelease](#onfinalrelease)|Limpa após a última referência OLE é liberada.|
|[CCmdTarget::RestoreWaitCursor](#restorewaitcursor)|Restaura o cursor de ampulheta.|

## <a name="remarks"></a>Comentários

Um mapa de mensagem roteia comandos ou mensagens para as funções de membro que você escreve para lidar com eles. (Um comando é uma mensagem de um item de menu, um botão de comando ou uma tecla de aceleração.)

As classes de estrutura de chaves derivadas `CCmdTarget` incluem [CView](../../mfc/reference/cview-class.md), [CWinApp](../../mfc/reference/cwinapp-class.md), [CDocument](../../mfc/reference/cdocument-class.md), [CWnd](../../mfc/reference/cwnd-class.md), e [ CFrameWnd](../../mfc/reference/cframewnd-class.md). Se você pretende para uma nova classe lidar com mensagens, derive a classe de uma destas opções `CCmdTarget`-as classes derivadas. Você raramente será derive uma classe de `CCmdTarget` diretamente.

Para obter uma visão geral de destinos de comando e `OnCmdMsg` roteamento, consulte [destinos de comando](../../mfc/command-targets.md), [roteamento de comando](../../mfc/command-routing.md), e [mapeando mensagens](../../mfc/mapping-messages.md).

`CCmdTarget` inclui funções de membro que lidam com a exibição de um cursor de ampulheta. Quando você espera que um comando para colocar um intervalo de tempo considerável para executar, exiba o cursor de ampulheta.

Expedição de mapas, semelhantes a mapas de mensagem, são usados para expor automação OLE `IDispatch` funcionalidade. Ao expor essa interface, outros aplicativos (como o Visual Basic) podem chamar seu aplicativo.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[CObject](../../mfc/reference/cobject-class.md)

`CCmdTarget`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxwin. h

##  <a name="beginwaitcursor"></a>  CCmdTarget::BeginWaitCursor

Chame essa função para exibir o cursor como uma ampulheta, quando você espera que um comando para colocar um intervalo de tempo considerável para executar.

```
void BeginWaitCursor();
```

### <a name="remarks"></a>Comentários

O framework chama essa função para mostrar ao usuário que ele está ocupado, por exemplo, quando um `CDocument` objeto carrega ou salva um arquivo a mesma.

As ações de `BeginWaitCursor` nem sempre são efetivas fora de um manipulador de mensagem único como outras ações, tais como `OnSetCursor` tratamento, foi possível alterar o cursor.

Chamar `EndWaitCursor` para restaurar o cursor anterior.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCDocView#43](../../mfc/codesnippet/cpp/ccmdtarget-class_1.cpp)]

##  <a name="ccmdtarget"></a>  CCmdTarget::CCmdTarget

Constrói um objeto `CCmdTarget`.

```
CCmdTarget();
```

##  <a name="dooleverb"></a>  CCmdTarget::DoOleVerb

Faz com que uma ação especificada por um verbo OLE a ser executada.

```
BOOL DoOleVerb(
    LONG iVerb,
    LPMSG lpMsg,
    HWND hWndParent,
    LPCRECT lpRect);
```

### <a name="parameters"></a>Parâmetros

*iVerb*<br/>
Identificador numérico do verbo.

*lpMsg*<br/>
Ponteiro para o [MSG](/windows/desktop/api/winuser/ns-winuser-msg) estrutura que descreve o evento (por exemplo, um clique duplo) que invocou o verbo.

*hWndParent*<br/>
Identificador da janela do documento que contém o objeto.

*lpRect*<br/>
Ponteiro para o [RECT](/previous-versions/dd162897\(v=vs.85\)) estrutura que contém as coordenadas, em pixels, que definem um objeto do retângulo no delimitador *hwndParent*.

### <a name="return-value"></a>Valor de retorno

TRUE se bem-sucedido, caso contrário, FALSE.

### <a name="remarks"></a>Comentários

Essa função membro é basicamente uma implementação de [IOleObject:: DoVerb](/windows/desktop/api/oleidl/nf-oleidl-ioleobject-doverb). As ações possíveis são enumeradas pelo [CCmdTarget::EnumOleVerbs](#enumoleverbs).

##  <a name="enableautomation"></a>  CCmdTarget::EnableAutomation

Chame essa função para habilitar a automação OLE para um objeto.

```
void EnableAutomation();
```

### <a name="remarks"></a>Comentários

Essa função normalmente é chamada do construtor de seu objeto e só deve ser chamada se um mapa de expedição foi declarado para a classe. Para obter mais informações sobre a automação, consulte os artigos [clientes de automação](../../mfc/automation-clients.md) e [servidores de automação](../../mfc/automation-servers.md).

##  <a name="enableconnections"></a>  CCmdTarget::EnableConnections

Habilita o acionamento do evento sobre pontos de conexão.

```
void EnableConnections();
```

### <a name="remarks"></a>Comentários

Para habilitar os pontos de conexão, chame essa função membro no construtor da sua classe derivada.

##  <a name="enabletypelib"></a>  CCmdTarget::EnableTypeLib

Permite que a biblioteca de tipos do objeto.

```
void EnableTypeLib();
```

### <a name="remarks"></a>Comentários

Chame essa função de membro no construtor da sua `CCmdTarget`-objeto derivado, se ele fornece informações de tipo.

##  <a name="endwaitcursor"></a>  CCmdTarget::EndWaitCursor

Chame essa função depois que você chamou o `BeginWaitCursor` a função de membro para retornar do cursor de ampulheta até o cursor anterior.

```
void EndWaitCursor();
```

### <a name="remarks"></a>Comentários

A estrutura também chama essa função membro depois que ele tenha chamado o cursor de ampulheta.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCDocView#43](../../mfc/codesnippet/cpp/ccmdtarget-class_1.cpp)]

##  <a name="enumoleverbs"></a>  CCmdTarget::EnumOleVerbs

Enumera os verbos do objeto OLE.

```
BOOL EnumOleVerbs(LPENUMOLEVERB* ppenumOleVerb);
```

### <a name="parameters"></a>Parâmetros

*ppenumOleVerb*<br/>
Um ponteiro para um ponteiro para um [IEnumOLEVERB](/windows/desktop/api/oleidl/nn-oleidl-ienumoleverb) interface.

### <a name="return-value"></a>Valor de retorno

TRUE se o objeto dá suporte a pelo menos um verbo OLE (caso em que \* *ppenumOleVerb* aponta para um `IEnumOLEVERB` interface de enumerador), caso contrário, FALSE.

### <a name="remarks"></a>Comentários

Essa função membro é basicamente uma implementação de [IOleObject:: Enumverbs](/windows/desktop/api/oleidl/nf-oleidl-ioleobject-enumverbs).

##  <a name="fromidispatch"></a>  CCmdTarget::FromIDispatch

Chame essa função para mapear uma `IDispatch` ponteiro, recebido das funções de membro de automação de uma classe, em de `CCmdTarget` objeto que implementa as interfaces do `IDispatch` objeto.

```
static CCmdTarget* PASCAL FromIDispatch(LPDISPATCH lpDispatch);
```

### <a name="parameters"></a>Parâmetros

*lpDispatch*<br/>
Um ponteiro para um objeto `IDispatch`.

### <a name="return-value"></a>Valor de retorno

Um ponteiro para o `CCmdTarget` objeto associado *lpDispatch*. Essa função retornará NULL se o `IDispatch` objeto não é reconhecido como um Microsoft Foundation Class `IDispatch` objeto.

### <a name="remarks"></a>Comentários

O resultado dessa função é o inverso de uma chamada para a função de membro `GetIDispatch`.

##  <a name="getdispatchiid"></a>  CCmdTarget::GetDispatchIID

Obtém a ID de interface de expedição primária.

```
virtual BOOL GetDispatchIID(IID* pIID);
```

### <a name="parameters"></a>Parâmetros

*pIID*<br/>
Um ponteiro para uma ID de interface (um [GUID](https://msdn.microsoft.com/library/windows/desktop/aa373931)).

### <a name="return-value"></a>Valor de retorno

TRUE se bem-sucedido, caso contrário, FALSE. Se for bem-sucedido, \* *pIID* é definido como a ID de interface de expedição primária.

### <a name="remarks"></a>Comentários

As classes derivadas devem substituir essa função de membro (se não for substituído, `GetDispatchIID` retorna FALSE). Ver [COleControl](../../mfc/reference/colecontrol-class.md).

##  <a name="getidispatch"></a>  CCmdTarget::GetIDispatch

Chame essa função de membro para recuperar o `IDispatch` ponteiro de um método de automação que retorna um `IDispatch` ponteiro ou usa um `IDispatch` ponteiro por referência.

```
LPDISPATCH GetIDispatch(BOOL bAddRef);
```

### <a name="parameters"></a>Parâmetros

*bAddRef*<br/>
Especifica se deseja incrementar a contagem de referência para o objeto.

### <a name="return-value"></a>Valor de retorno

O `IDispatch` ponteiro associado ao objeto.

### <a name="remarks"></a>Comentários

Para objetos que chamam `EnableAutomation` em seus construtores, tornando-os automação habilitada, essa função retorna um ponteiro para a implementação da classe base `IDispatch` que é usado por clientes que se comunicam por meio de `IDispatch` interface. Chamar essa função automaticamente adiciona uma referência ao ponteiro, portanto, não é necessário fazer uma chamada para [IUnknown:: AddRef](/windows/desktop/api/unknwn/nf-unknwn-iunknown-addref).

##  <a name="gettypeinfocount"></a>  CCmdTarget::GetTypeInfoCount

Recupera o número de interfaces de informações de tipo que fornece um objeto.

```
virtual UINT GetTypeInfoCount();
```

### <a name="return-value"></a>Valor de retorno

O número de interfaces de informações de tipo.

### <a name="remarks"></a>Comentários

Essa função membro implementa basicamente [IDispatch::GetTypeInfoCount](/windows/desktop/api/oaidl/nf-oaidl-idispatch-gettypeinfocount).

As classes derivadas devem substituir essa função para retornar o número de interfaces de informações de tipo fornecido (0 ou 1). Se não for substituído, `GetTypeInfoCount` retornará 0. Para substituir, use o [IMPLEMENT_OLETYPELIB](../../mfc/reference/type-library-access.md#implement_oletypelib) macro, que também implementa `GetTypeLib` e `GetTypeLibCache`.

##  <a name="gettypeinfoofguid"></a>  CCmdTarget::GetTypeInfoOfGuid

Recupera a descrição de tipo que corresponde ao GUID especificado.

```
HRESULT GetTypeInfoOfGuid(
    LCID lcid,
    const GUID& guid,
    LPTYPEINFO* ppTypeInfo);
```

### <a name="parameters"></a>Parâmetros

*lcid*<br/>
Um identificador de localidade ( `LCID`).

*guid*<br/>
O [GUID](https://msdn.microsoft.com/library/windows/desktop/aa373931) da descrição de tipo.

*ppTypeInfo*<br/>
Ponteiro para um ponteiro para o `ITypeInfo` interface.

### <a name="return-value"></a>Valor de retorno

Um HRESULT indicando o êxito ou falha da chamada. Se for bem-sucedido, \* *ppTypeInfo* aponta para a interface de informações de tipo.

##  <a name="gettypelib"></a>  CCmdTarget::GetTypeLib

Obtém um ponteiro para uma biblioteca de tipos.

```
virtual HRESULT GetTypeLib(
    LCID lcid,
    LPTYPELIB* ppTypeLib);
```

### <a name="parameters"></a>Parâmetros

*lcid*<br/>
Um LCID (ID de localidade).

*ppTypeLib*<br/>
Um ponteiro para um ponteiro para o `ITypeLib` interface.

### <a name="return-value"></a>Valor de retorno

Um HRESULT indicando o êxito ou falha da chamada. Se for bem-sucedido, \* *ppTypeLib* aponta para a interface da biblioteca de tipo.

### <a name="remarks"></a>Comentários

As classes derivadas devem substituir essa função de membro (se não for substituído, `GetTypeLib` retorna TYPE_E_CANTLOADLIBRARY). Use o [IMPLEMENT_OLETYPELIB](../../mfc/reference/type-library-access.md#implement_oletypelib) macro, que também implementa `GetTypeInfoCount` e `GetTypeLibCache`.

##  <a name="gettypelibcache"></a>  CCmdTarget::GetTypeLibCache

Obtém o cache de biblioteca de tipos.

```
virtual CTypeLibCache* GetTypeLibCache();
```

### <a name="return-value"></a>Valor de retorno

Um ponteiro para um `CTypeLibCache` objeto.

### <a name="remarks"></a>Comentários

As classes derivadas devem substituir essa função de membro (se não for substituído, `GetTypeLibCache` retorna NULL). Use o [IMPLEMENT_OLETYPELIB](../../mfc/reference/type-library-access.md#implement_oletypelib) macro, que também implementa `GetTypeInfoCount` e `GetTypeLib`.

##  <a name="isinvokeallowed"></a>  CCmdTarget::IsInvokeAllowed

Essa função é chamada pela implementação do MFC do `IDispatch::Invoke` para determinar se um método de automação determinado (identificado por *dispid*) pode ser invocado.

```
virtual BOOL IsInvokeAllowed(DISPID dispid);
```

### <a name="parameters"></a>Parâmetros

*dispid*<br/>
Uma ID de expedição.

### <a name="return-value"></a>Valor de retorno

TRUE se o método pode ser invocado, caso contrário, FALSE.

### <a name="remarks"></a>Comentários

Se `IsInvokeAllowed` retorna TRUE, `Invoke` prossegue, chamando o método; caso contrário, `Invoke` falhará e retornará E_UNEXPECTED.

Classes derivadas podem substituir essa função para retornar os valores apropriados (se não for substituído, `IsInvokeAllowed` retorna TRUE). Consulte em particular [COleControl::IsInvokeAllowed](../../mfc/reference/colecontrol-class.md#isinvokeallowed).

##  <a name="isresultexpected"></a>  CCmdTarget::IsResultExpected

Use `IsResultExpected` para determinar se um cliente esperar um valor de retorno da sua chamada a uma função de automação.

```
BOOL IsResultExpected();
```

### <a name="return-value"></a>Valor de retorno

Diferente de zero se uma função de automação deve retornar um valor; Caso contrário, 0.

### <a name="remarks"></a>Comentários

A interface OLE fornece informações sobre se o cliente está usando ou ignorando o resultado de uma chamada de função para MFC e, por sua vez, o MFC usa essas informações para determinar o resultado de uma chamada para `IsResultExpected`. Se a produção de um valor de retorno intensiva de tempo ou de recurso, você pode aumentar a eficiência ao chamar essa função antes de computar o valor de retorno.

Essa função retorna 0 somente uma vez para que você obtém os valores de retorno válidos de outras funções de automação se você chamá-los da função de automação que o cliente é chamado.

`IsResultExpected` Retorna um valor diferente de zero se for chamado quando uma chamada de função de automação não está em andamento.

##  <a name="oncmdmsg"></a>  CCmdTarget::OnCmdMsg

Chamado pelo framework para rotear e distribuir mensagens de comando e para lidar com a atualização dos objetos de interface do usuário do comando.

```
virtual BOOL OnCmdMsg(
    UINT nID,
    int nCode,
    void* pExtra,
    AFX_CMDHANDLERINFO* pHandlerInfo);
```

### <a name="parameters"></a>Parâmetros

*nID*<br/>
Contém a ID de comando.

*nCode*<br/>
Identifica o código de notificação do comando. Ver **Remarks** para obter mais informações sobre valores *nCode*.

*pExtra*<br/>
Usada de acordo com o valor de *nCode*. Ver **Remarks** para obter mais informações sobre *pExtra*.

*pHandlerInfo*<br/>
Se não for NULL, `OnCmdMsg` preenche o *pTarget* e *pmf* os membros a *pHandlerInfo* estrutura em vez de expedir o comando. Normalmente, esse parâmetro deve ser NULL.

### <a name="return-value"></a>Valor de retorno

Diferente de zero se a mensagem é manipulada; Caso contrário, 0.

### <a name="remarks"></a>Comentários

Isso é a rotina de principais de implementação da arquitetura da estrutura de comando.

Em tempo de execução `OnCmdMsg` envia um comando para outros objetos ou manipula o comando em si, chamando a classe raiz `CCmdTarget::OnCmdMsg`, que faz a pesquisa de mapa de mensagem real. Para obter uma descrição completa do roteamento de comando padrão, consulte [manipulação de mensagens e o mapeamento de tópicos](../../mfc/message-handling-and-mapping.md).

Em raras ocasiões, você talvez queira substituir essa função de membro para estender a estrutura roteamento de comando padrão. Consulte a [21 de observação técnica](../../mfc/tn021-command-and-message-routing.md) para detalhes avançados da arquitetura de roteamento de comando.

Se você substituir `OnCmdMsg`, você deve fornecer o valor apropriado *nCode*, o código de notificação de comando, e *pExtra*, que depende do valor de *nCode* . A tabela a seguir lista os valores correspondentes:

|*nCode* valor|*pExtra* valor|
|-------------------|--------------------|
|CN_COMMAND|[CCmdUI](../../mfc/reference/ccmdui-class.md)\*|
|CN_EVENT|AFX_EVENT\*|
|CN_UPDATE_COMMAND_UI|CCmdUI\*|
|CN_OLECOMMAND|[COleCmdUI](../../mfc/reference/colecmdui-class.md)\*|
|CN_OLE_UNREGISTER|NULL|

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCDocView#44](../../mfc/codesnippet/cpp/ccmdtarget-class_2.cpp)]

[!code-cpp[NVC_MFCDocView#45](../../mfc/codesnippet/cpp/ccmdtarget-class_3.cpp)]

##  <a name="onfinalrelease"></a>  CCmdTarget::OnFinalRelease

Chamado pelo framework quando a última referência OLE para ou do objeto é liberada.

```
virtual void OnFinalRelease();
```

### <a name="remarks"></a>Comentários

Substitua essa função para fornecer tratamento especial para essa situação. A implementação padrão exclui o objeto.

##  <a name="restorewaitcursor"></a>  CCmdTarget::RestoreWaitCursor

Chame essa função para restaurar o cursor de ampulheta apropriado depois que o cursor do sistema foi alterado (por exemplo, depois que uma caixa de mensagem abertos e fechados, em seguida, no meio de uma operação demorada).

```
void RestoreWaitCursor();
```

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCDocView#43](../../mfc/codesnippet/cpp/ccmdtarget-class_1.cpp)]

## <a name="see-also"></a>Consulte também

[Exemplo MFC ACDUAL](../../overview/visual-cpp-samples.md)<br/>
[Classe CObject](../../mfc/reference/cobject-class.md)<br/>
[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classe CCmdUI](../../mfc/reference/ccmdui-class.md)<br/>
[Classe CDocument](../../mfc/reference/cdocument-class.md)<br/>
[Classe CDocTemplate](../../mfc/reference/cdoctemplate-class.md)<br/>
[Classe CWinApp](../../mfc/reference/cwinapp-class.md)<br/>
[Classe CWnd](../../mfc/reference/cwnd-class.md)<br/>
[Classe CView](../../mfc/reference/cview-class.md)<br/>
[Classe CFrameWnd](../../mfc/reference/cframewnd-class.md)<br/>
[Classe COleDispatchDriver](../../mfc/reference/coledispatchdriver-class.md)
