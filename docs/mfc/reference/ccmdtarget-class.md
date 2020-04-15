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
ms.openlocfilehash: 5ee4101302322a5212a80b32f095cdd13d9769e0
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81352285"
---
# <a name="ccmdtarget-class"></a>Classe CCmdTarget

A classe base da arquitetura de mapa de mensagens da Microsoft Foundation Class Library.

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
|[CCmdTarget::DoOleVerbo](#dooleverb)|Faz com que uma ação especificada por um verbo OLE seja realizada.|
|[CCmdTarget::Ativarautomação](#enableautomation)|Permite a automação `CCmdTarget` oLE para o objeto.|
|[CCmdTarget::Ativar conexões](#enableconnections)|Permite o disparo de eventos sobre pontos de conexão.|
|[CCmdTarget::HabilitaçãoTypeLib](#enabletypelib)|Habilita a biblioteca do tipo de um objeto.|
|[CCmdTarget::EndWaitCursor](#endwaitcursor)|Retorna ao cursor anterior.|
|[CCmdTarget::EnumOleVerbs](#enumoleverbs)|Enumera os verbos OLE de um objeto.|
|[CCmdTarget::FromIDispatch](#fromidispatch)|Retorna um ponteiro `CCmdTarget` para o `IDispatch` objeto associado ao ponteiro.|
|[CCmdTarget::GetDispatchIID](#getdispatchiid)|Obtém o ID da interface de despacho primário.|
|[CCmdTarget::GetIDispatch](#getidispatch)|Retorna um ponteiro `IDispatch` para o `CCmdTarget` objeto associado ao objeto.|
|[CCmdTarget::GetTypeInfoCount](#gettypeinfocount)|Recupera o número de interfaces de informações de tipo que um objeto fornece.|
|[CCmdTarget::GetTypeInfoOfGuid](#gettypeinfoofguid)|Recupera a descrição de tipo que corresponde ao GUID especificado.|
|[CCmdTarget::GetTypeLib](#gettypelib)|Recebe um ponteiro para uma biblioteca de tipos.|
|[CCmdTarget::GetTypeLibCache](#gettypelibcache)|Obtém o cache da biblioteca do tipo.|
|[CCmdTarget::IsInvokeAllowed](#isinvokeallowed)|Permite a invocação do método de automação.|
|[CCmdTarget::IsResultExpected](#isresultexpected)|Retorna não zero se uma função de automação retornar um valor.|
|[CCmdTarget::OnCmdMsg](#oncmdmsg)|Rotas e despachos de mensagens de comando.|
|[CCmdTarget::OnFinalRelease](#onfinalrelease)|Limpa depois que a última referência OLE é lançada.|
|[CCmdTarget::RestoreWaitCursor](#restorewaitcursor)|Restaura o cursor de ampulheta.|

## <a name="remarks"></a>Comentários

Um mapa de mensagens roteia comandos ou mensagens para as funções de membro que você escreve para manuseá-las. (Um comando é uma mensagem de um item do menu, botão de comando ou chave do acelerador.)

As principais classes `CCmdTarget` de framework derivadas incluem [CView,](../../mfc/reference/cview-class.md) [CWinApp,](../../mfc/reference/cwinapp-class.md) [CDocument,](../../mfc/reference/cdocument-class.md) [CWnd](../../mfc/reference/cwnd-class.md)e [CFrameWnd](../../mfc/reference/cframewnd-class.md). Se você pretende uma nova classe para lidar com mensagens, obtenha a classe de uma dessas `CCmdTarget`classes derivadas. Você raramente derivará `CCmdTarget` uma classe diretamente.

Para obter uma visão geral `OnCmdMsg` dos alvos de comando e do roteamento, consulte [Alvos de comando,](../../mfc/command-targets.md) [roteamento de comando](../../mfc/command-routing.md)e [mensagens de mapeamento](../../mfc/mapping-messages.md).

`CCmdTarget`inclui funções de membro que lidam com a exibição de um cursor de ampulheta. Exiba o cursor de ampulheta quando espera que um comando demora um intervalo de tempo perceptível para ser executado.

Mapas de despacho, semelhantes aos mapas de `IDispatch` mensagens, são usados para expor a funcionalidade de automação oLE. Ao expor essa interface, outros aplicativos (como o Visual Basic) podem chamar para o seu aplicativo.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[Cobject](../../mfc/reference/cobject-class.md)

`CCmdTarget`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxwin.h

## <a name="ccmdtargetbeginwaitcursor"></a><a name="beginwaitcursor"></a>CCmdTarget::BeginWaitCursor

Chame esta função para exibir o cursor como uma ampulheta quando você espera que um comando tome um intervalo de tempo perceptível para ser executado.

```
void BeginWaitCursor();
```

### <a name="remarks"></a>Comentários

A estrutura chama essa função para mostrar ao usuário `CDocument` que ele está ocupado, como quando um objeto carrega ou se salva em um arquivo.

As ações `BeginWaitCursor` de nem sempre são eficazes fora de `OnSetCursor` um único manipulador de mensagens, pois outras ações, como o manuseio, poderiam mudar o cursor.

Chamada `EndWaitCursor` para restaurar o cursor anterior.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCDocView#43](../../mfc/codesnippet/cpp/ccmdtarget-class_1.cpp)]

## <a name="ccmdtargetccmdtarget"></a><a name="ccmdtarget"></a>CCmdTarget::CCmdTarget

Constrói um objeto `CCmdTarget`.

```
CCmdTarget();
```

## <a name="ccmdtargetdooleverb"></a><a name="dooleverb"></a>CCmdTarget::DoOleVerbo

Faz com que uma ação especificada por um verbo OLE seja realizada.

```
BOOL DoOleVerb(
    LONG iVerb,
    LPMSG lpMsg,
    HWND hWndParent,
    LPCRECT lpRect);
```

### <a name="parameters"></a>Parâmetros

*Iverb*<br/>
Identificador numérico do verbo.

*Lpmsg*<br/>
Ponteiro para a estrutura do [MSG](/windows/win32/api/winuser/ns-winuser-msg) descrevendo o evento (como um duplo clique) que invocou o verbo.

*Hwndparent*<br/>
Alça da janela do documento que contém o objeto.

*Lprect*<br/>
Ponteiro para a estrutura [RECT](/previous-versions/dd162897\(v=vs.85\)) contendo as coordenadas, em pixels, que definem o retângulo delimitador de um objeto em *hwndParent*.

### <a name="return-value"></a>Valor retornado

VERDADE se bem sucedido, caso contrário FALSO.

### <a name="remarks"></a>Comentários

Esta função de membro é basicamente uma implementação do [IOleObject::DoVerb](/windows/win32/api/oleidl/nf-oleidl-ioleobject-doverb). As possíveis ações são enumeradas por [CCmdTarget::EnumOleVerbs](#enumoleverbs).

## <a name="ccmdtargetenableautomation"></a><a name="enableautomation"></a>CCmdTarget::Ativarautomação

Chame esta função para ativar a automação OLE para um objeto.

```
void EnableAutomation();
```

### <a name="remarks"></a>Comentários

Esta função é tipicamente chamada do construtor do seu objeto e só deve ser chamada se um mapa de despacho tiver sido declarado para a classe. Para obter mais informações sobre automação, consulte os artigos [Automação Clientes](../../mfc/automation-clients.md) e [Servidores de Automação.](../../mfc/automation-servers.md)

## <a name="ccmdtargetenableconnections"></a><a name="enableconnections"></a>CCmdTarget::Ativar conexões

Permite o disparo de eventos sobre pontos de conexão.

```
void EnableConnections();
```

### <a name="remarks"></a>Comentários

Para habilitar pontos de conexão, chame esta função de membro no construtor de sua classe derivada.

## <a name="ccmdtargetenabletypelib"></a><a name="enabletypelib"></a>CCmdTarget::HabilitaçãoTypeLib

Habilita a biblioteca do tipo de um objeto.

```
void EnableTypeLib();
```

### <a name="remarks"></a>Comentários

Chame esta função de membro `CCmdTarget`no construtor do objeto derivado se ele fornecer informações de tipo.

## <a name="ccmdtargetendwaitcursor"></a><a name="endwaitcursor"></a>CCmdTarget::EndWaitCursor

Ligue para esta função `BeginWaitCursor` depois de ter chamado a função de membro para retornar do cursor de ampulheta para o cursor anterior.

```
void EndWaitCursor();
```

### <a name="remarks"></a>Comentários

A estrutura também chama essa função de membro depois de ter chamado de cursor de ampulheta.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCDocView#43](../../mfc/codesnippet/cpp/ccmdtarget-class_1.cpp)]

## <a name="ccmdtargetenumoleverbs"></a><a name="enumoleverbs"></a>CCmdTarget::EnumOleVerbs

Enumera os verbos OLE de um objeto.

```
BOOL EnumOleVerbs(LPENUMOLEVERB* ppenumOleVerb);
```

### <a name="parameters"></a>Parâmetros

*ppenumOleVerb*<br/>
Um ponteiro para um ponteiro para uma interface [IEnumOLEVERB.](/windows/win32/api/oleidl/nn-oleidl-ienumoleverb)

### <a name="return-value"></a>Valor retornado

TRUE se o objeto suportar pelo menos um verbo OLE (nesse \* *caso, ppenumOleVerb* aponta para uma `IEnumOLEVERB` interface enumerador), caso contrário, FALSE.

### <a name="remarks"></a>Comentários

Esta função de membro é basicamente uma implementação do [IOleObject::EnumVerbs](/windows/win32/api/oleidl/nf-oleidl-ioleobject-enumverbs).

## <a name="ccmdtargetfromidispatch"></a><a name="fromidispatch"></a>CCmdTarget::FromIDispatch

Chame esta função `IDispatch` para mapear um ponteiro, recebido das funções dos membros de automação de uma classe, no `CCmdTarget` objeto que implementa as interfaces do `IDispatch` objeto.

```
static CCmdTarget* PASCAL FromIDispatch(LPDISPATCH lpDispatch);
```

### <a name="parameters"></a>Parâmetros

*LpDispatch*<br/>
Um ponteiro para um objeto `IDispatch`.

### <a name="return-value"></a>Valor retornado

Um ponteiro `CCmdTarget` para o objeto associado ao *lpDispatch*. Essa função retorna `IDispatch` NULL se o objeto não `IDispatch` for reconhecido como um objeto Microsoft Foundation Class.

### <a name="remarks"></a>Comentários

O resultado desta função é o inverso de `GetIDispatch`uma chamada para a função do membro .

## <a name="ccmdtargetgetdispatchiid"></a><a name="getdispatchiid"></a>CCmdTarget::GetDispatchIID

Obtém o ID da interface de despacho primário.

```
virtual BOOL GetDispatchIID(IID* pIID);
```

### <a name="parameters"></a>Parâmetros

*Piid*<br/>
Um ponteiro para um ID de interface (um [GUID](/previous-versions/cc317743(v%3dmsdn.10)).

### <a name="return-value"></a>Valor retornado

VERDADE se bem sucedido, caso contrário FALSO. Se for \* bem-sucedido, *o pIID* será definido como iD da interface de despacho principal.

### <a name="remarks"></a>Comentários

As classes derivadas devem substituir essa função de `GetDispatchIID` membro (se não for substituída, retorna FALSA). Ver [COleControl](../../mfc/reference/colecontrol-class.md).

## <a name="ccmdtargetgetidispatch"></a><a name="getidispatch"></a>CCmdTarget::GetIDispatch

Ligue para esta função `IDispatch` de membro para recuperar `IDispatch` o ponteiro `IDispatch` de um método de automação que retorna um ponteiro ou leva um ponteiro por referência.

```
LPDISPATCH GetIDispatch(BOOL bAddRef);
```

### <a name="parameters"></a>Parâmetros

*bAddRef*<br/>
Especifica se incrementa a contagem de referência para o objeto.

### <a name="return-value"></a>Valor retornado

O `IDispatch` ponteiro associado com o objeto.

### <a name="remarks"></a>Comentários

Para objetos `EnableAutomation` que chamam seus construtores, tornando-os habilitados para automação, `IDispatch` essa função retorna um `IDispatch` ponteiro para a implementação da Classe Fundação que é usada por clientes que se comunicam através da interface. Chamar essa função adiciona automaticamente uma referência ao ponteiro, de modo que não é necessário fazer uma chamada para [IUnknown::AddRef](/windows/win32/api/unknwn/nf-unknwn-iunknown-addref).

## <a name="ccmdtargetgettypeinfocount"></a><a name="gettypeinfocount"></a>CCmdTarget::GetTypeInfoCount

Recupera o número de interfaces de informações de tipo que um objeto fornece.

```
virtual UINT GetTypeInfoCount();
```

### <a name="return-value"></a>Valor retornado

O número de interfaces de informações de tipo.

### <a name="remarks"></a>Comentários

Essa função de membro basicamente implementa [o IDispatch::GetTypeInfoCount](/windows/win32/api/oaidl/nf-oaidl-idispatch-gettypeinfocount).

As classes derivadas devem substituir esta função para retornar o número de interfaces de informações de tipo fornecidas (0 ou 1). Se não for `GetTypeInfoCount` substituído, retorna 0. Para substituir, use a [IMPLEMENT_OLETYPELIB](../../mfc/reference/type-library-access.md#implement_oletypelib) macro, `GetTypeLib` `GetTypeLibCache`que também implementa e .

## <a name="ccmdtargetgettypeinfoofguid"></a><a name="gettypeinfoofguid"></a>CCmdTarget::GetTypeInfoOfGuid

Recupera a descrição de tipo que corresponde ao GUID especificado.

```
HRESULT GetTypeInfoOfGuid(
    LCID lcid,
    const GUID& guid,
    LPTYPEINFO* ppTypeInfo);
```

### <a name="parameters"></a>Parâmetros

*Lcid*<br/>
Um identificador local `LCID`().

*Guid*<br/>
O [GUID](/previous-versions/cc317743(v%3dmsdn.10)) da descrição do tipo.

*ppTypeInfo*<br/>
Ponteiro para um `ITypeInfo` ponteiro para a interface.

### <a name="return-value"></a>Valor retornado

Um HRESULT indicando o sucesso ou o fracasso da chamada. Se for \* bem-sucedido, *ppTypeInfo* aponta para a interface de informações do tipo.

## <a name="ccmdtargetgettypelib"></a><a name="gettypelib"></a>CCmdTarget::GetTypeLib

Recebe um ponteiro para uma biblioteca de tipos.

```
virtual HRESULT GetTypeLib(
    LCID lcid,
    LPTYPELIB* ppTypeLib);
```

### <a name="parameters"></a>Parâmetros

*Lcid*<br/>
Um LCID (ID de localidade).

*ppTypeLib*<br/>
Um ponteiro para um `ITypeLib` ponteiro para a interface.

### <a name="return-value"></a>Valor retornado

Um HRESULT indicando o sucesso ou o fracasso da chamada. Se for \* bem-sucedido, *ppTypeLib* aponta para a interface de biblioteca do tipo.

### <a name="remarks"></a>Comentários

As classes derivadas devem substituir esta função de `GetTypeLib` membro (se não for substituída, retorna TYPE_E_CANTLOADLIBRARY). Use a [macro IMPLEMENT_OLETYPELIB,](../../mfc/reference/type-library-access.md#implement_oletypelib) `GetTypeInfoCount` que `GetTypeLibCache`também implementa e .

## <a name="ccmdtargetgettypelibcache"></a><a name="gettypelibcache"></a>CCmdTarget::GetTypeLibCache

Obtém o cache da biblioteca do tipo.

```
virtual CTypeLibCache* GetTypeLibCache();
```

### <a name="return-value"></a>Valor retornado

Um ponteiro para um objeto `CTypeLibCache`.

### <a name="remarks"></a>Comentários

As classes derivadas devem substituir esta função de `GetTypeLibCache` membro (se não for substituída, retorna NULL). Use a [macro IMPLEMENT_OLETYPELIB,](../../mfc/reference/type-library-access.md#implement_oletypelib) `GetTypeInfoCount` que `GetTypeLib`também implementa e .

## <a name="ccmdtargetisinvokeallowed"></a><a name="isinvokeallowed"></a>CCmdTarget::IsInvokeAllowed

Esta função é chamada pela implementação da MFC para determinar se um determinado método de `IDispatch::Invoke` automação (identificado por *dispid)* pode ser invocado.

```
virtual BOOL IsInvokeAllowed(DISPID dispid);
```

### <a name="parameters"></a>Parâmetros

*Dispid*<br/>
Uma imd.d.

### <a name="return-value"></a>Valor retornado

VERDADE se o método pode ser invocado, caso contrário FALSO.

### <a name="remarks"></a>Comentários

Se `IsInvokeAllowed` retornar `Invoke` TRUE, passa a chamar o método; caso contrário, `Invoke` falhará, retornando E_UNEXPECTED.

As classes derivadas podem substituir essa função para retornar `IsInvokeAllowed` valores apropriados (se não forem substituídos, retorna TRUE). Veja em particular [COleControl::IsInvokeAllowed](../../mfc/reference/colecontrol-class.md#isinvokeallowed).

## <a name="ccmdtargetisresultexpected"></a><a name="isresultexpected"></a>CCmdTarget::IsResultExpected

Use `IsResultExpected` para verificar se um cliente espera um valor de retorno de sua chamada para uma função de automação.

```
BOOL IsResultExpected();
```

### <a name="return-value"></a>Valor retornado

Não zero se uma função de automação retornar um valor; caso contrário, 0.

### <a name="remarks"></a>Comentários

A interface OLE fornece informações ao MFC sobre se o cliente está usando ou ignorando o resultado de uma chamada `IsResultExpected`de função, e o MFC, por sua vez, usa essas informações para determinar o resultado de uma chamada para . Se a produção de um valor de retorno for de tempo ou de recursos intensivo, você pode aumentar a eficiência chamando essa função antes de calcular o valor de retorno.

Esta função retorna 0 apenas uma vez para que você obtenha valores de retorno válidos de outras funções de automação se você chamá-los da função de automação que o cliente chamou.

`IsResultExpected`retorna um valor não zero se chamado quando uma chamada de função de automação não está em andamento.

## <a name="ccmdtargetoncmdmsg"></a><a name="oncmdmsg"></a>CCmdTarget::OnCmdMsg

Chamado pela estrutura para enviar e enviar mensagens de comando e para lidar com a atualização de objetos de interface de usuário de comando.

```
virtual BOOL OnCmdMsg(
    UINT nID,
    int nCode,
    void* pExtra,
    AFX_CMDHANDLERINFO* pHandlerInfo);
```

### <a name="parameters"></a>Parâmetros

*nID*<br/>
Contém o ID de comando.

*Ncode*<br/>
Identifica o código de notificação de comando. Consulte **Observações** para obter mais informações sobre valores para *nCode*.

*Pextra*<br/>
Usado de acordo com o valor do *nCode*. Consulte **Observações** para obter mais informações sobre *o pExtra*.

*pHandlerInfo*<br/>
Se não `OnCmdMsg` FOR NULO, preenche os membros *pTarget* e *pmf* da estrutura *pHandlerInfo* em vez de despachar o comando. Normalmente, este parâmetro deve ser NULO.

### <a name="return-value"></a>Valor retornado

Não zero se a mensagem for tratada; caso contrário, 0.

### <a name="remarks"></a>Comentários

Esta é a principal rotina de implementação da arquitetura de comando framework.

No tempo `OnCmdMsg` de execução, despacha um comando para outros `CCmdTarget::OnCmdMsg`objetos ou manipula o comando em si chamando a classe raiz , que faz a procurar mapa de mensagem real. Para obter uma descrição completa do roteamento padrão do comando, consulte [Tópicos de manipulação e mapeamento de mensagens](../../mfc/message-handling-and-mapping.md).

Em raras ocasiões, você pode querer substituir essa função de membro para estender o roteamento padrão de comando da estrutura. Consulte a [Nota Técnica 21](../../mfc/tn021-command-and-message-routing.md) para obter detalhes avançados da arquitetura de roteamento de comando.

Se você `OnCmdMsg`substituir, você deve fornecer o valor apropriado para *nCode*, o código de notificação de comando e *pExtra*, que depende do valor do *nCode*. A tabela a seguir lista seus valores correspondentes:

|*valor nCode*|*valor pExtra*|
|-------------------|--------------------|
|CN_COMMAND|[Ccmdui](../../mfc/reference/ccmdui-class.md)\*|
|CN_EVENT|AFX_EVENT\*|
|CN_UPDATE_COMMAND_UI|Ccmdui\*|
|CN_OLECOMMAND|[Colecmdui](../../mfc/reference/colecmdui-class.md)\*|
|CN_OLE_UNREGISTER|NULO|

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCDocView#44](../../mfc/codesnippet/cpp/ccmdtarget-class_2.cpp)]

[!code-cpp[NVC_MFCDocView#45](../../mfc/codesnippet/cpp/ccmdtarget-class_3.cpp)]

## <a name="ccmdtargetonfinalrelease"></a><a name="onfinalrelease"></a>CCmdTarget::OnFinalRelease

Chamado pela estrutura quando a última referência OLE para ou a partir do objeto é liberada.

```
virtual void OnFinalRelease();
```

### <a name="remarks"></a>Comentários

Anular esta função para fornecer um tratamento especial para esta situação. A implementação padrão exclui o objeto.

## <a name="ccmdtargetrestorewaitcursor"></a><a name="restorewaitcursor"></a>CCmdTarget::RestoreWaitCursor

Chame esta função para restaurar o cursor de ampulheta apropriado depois que o cursor do sistema tiver sido alterado (por exemplo, depois que uma caixa de mensagem for aberta e depois fechada no meio de uma operação demorada).

```
void RestoreWaitCursor();
```

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCDocView#43](../../mfc/codesnippet/cpp/ccmdtarget-class_1.cpp)]

## <a name="see-also"></a>Confira também

[MFC Amostra ACDUAL](../../overview/visual-cpp-samples.md)<br/>
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
