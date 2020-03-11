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
ms.openlocfilehash: 583b685295bf77910ef134776c1c4fa39baf93ad
ms.sourcegitcommit: 3e8fa01f323bc5043a48a0c18b855d38af3648d4
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/06/2020
ms.locfileid: "78867022"
---
# <a name="ccmdtarget-class"></a>Classe CCmdTarget

A classe base para o biblioteca MFC a arquitetura do mapa de mensagens.

## <a name="syntax"></a>Sintaxe

```
class CCmdTarget : public CObject
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|DESCRIÇÃO|
|----------|-----------------|
|[CCmdTarget:: CCmdTarget](#ccmdtarget)|Constrói um objeto `CCmdTarget`.|

### <a name="public-methods"></a>Métodos públicos

|Nome|DESCRIÇÃO|
|----------|-----------------|
|[CCmdTarget:: BeginWaitCursor](#beginwaitcursor)|Exibe o cursor como um cursor de ampulheta.|
|[CCmdTarget::D oOleVerb](#dooleverb)|Faz com que uma ação especificada por um verbo OLE seja executada.|
|[CCmdTarget:: EnableAutomation](#enableautomation)|Permite a automação OLE para o objeto `CCmdTarget`.|
|[CCmdTarget:: EnableConnections](#enableconnections)|Habilita o acionamento de eventos em pontos de conexão.|
|[CCmdTarget:: EnableTypeLib](#enabletypelib)|Habilita a biblioteca de tipos de um objeto.|
|[CCmdTarget:: EndWaitCursor](#endwaitcursor)|Retorna ao cursor anterior.|
|[CCmdTarget:: EnumOleVerbs](#enumoleverbs)|Enumera os verbos OLE de um objeto.|
|[CCmdTarget:: FromIDispatch](#fromidispatch)|Retorna um ponteiro para o objeto `CCmdTarget` associado ao ponteiro `IDispatch`.|
|[CCmdTarget:: GetDispatchIID](#getdispatchiid)|Obtém a ID da interface de expedição primária.|
|[CCmdTarget:: GetIDispatch](#getidispatch)|Retorna um ponteiro para o objeto `IDispatch` associado ao objeto `CCmdTarget`.|
|[CCmdTarget:: GetTypeInfoCount](#gettypeinfocount)|Recupera o número de interfaces de informações de tipo que um objeto fornece.|
|[CCmdTarget:: GetTypeInfoOfGuid](#gettypeinfoofguid)|Recupera a descrição de tipo que corresponde ao GUID especificado.|
|[CCmdTarget:: GetTypeLib](#gettypelib)|Obtém um ponteiro para uma biblioteca de tipos.|
|[CCmdTarget:: GetTypeLibCache](#gettypelibcache)|Obtém o cache da biblioteca de tipos.|
|[CCmdTarget:: IsInvokeAllowed](#isinvokeallowed)|Habilita a invocação de método de automação.|
|[CCmdTarget:: IsResultExpected](#isresultexpected)|Retorna zero se uma função de automação deve retornar um valor.|
|[CCmdTarget:: OnCmdMsg](#oncmdmsg)|Roteia e despacha mensagens de comando.|
|[CCmdTarget:: OnFinalRelease](#onfinalrelease)|Limpa após a liberação da última referência OLE.|
|[CCmdTarget:: RestoreWaitCursor](#restorewaitcursor)|Restaura o cursor de ampulheta.|

## <a name="remarks"></a>Comentários

Um mapa de mensagens roteia comandos ou mensagens para as funções de membro que você escreve para tratá-los. (Um comando é uma mensagem de um item de menu, botão de comando ou tecla de aceleração.)

Classes de estrutura-chave derivadas de `CCmdTarget` incluem [cvisualização](../../mfc/reference/cview-class.md), [CWinApp](../../mfc/reference/cwinapp-class.md), [CDocument](../../mfc/reference/cdocument-class.md), [CWnd](../../mfc/reference/cwnd-class.md)e [CFrameWnd](../../mfc/reference/cframewnd-class.md). Se você pretende que uma nova classe manipule mensagens, derive a classe de uma dessas classes derivadas de `CCmdTarget`. Você raramente vai derivar uma classe de `CCmdTarget` diretamente.

Para obter uma visão geral dos destinos de comando e do roteamento de `OnCmdMsg`, consulte [destinos de comando](../../mfc/command-targets.md), [Roteamento de comando](../../mfc/command-routing.md)e mensagens de [mapeamento](../../mfc/mapping-messages.md).

`CCmdTarget` inclui funções de membro que manipulam a exibição de um cursor de ampulheta. Exiba o cursor de ampulheta quando você espera que um comando leve um intervalo de tempo perceptível para ser executado.

Os mapas de expedição, semelhantes aos mapas de mensagem, são usados para expor a funcionalidade de `IDispatch` de automação OLE. Ao expor essa interface, outros aplicativos (como Visual Basic) podem chamar seu aplicativo.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[CObject](../../mfc/reference/cobject-class.md)

`CCmdTarget`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** Afxwin. h

##  <a name="beginwaitcursor"></a>CCmdTarget:: BeginWaitCursor

Chame essa função para exibir o cursor como uma ampulheta quando você espera que um comando leve um intervalo de tempo perceptível para ser executado.

```
void BeginWaitCursor();
```

### <a name="remarks"></a>Comentários

A estrutura chama essa função para mostrar ao usuário que ele está ocupado, como quando um objeto de `CDocument` carrega ou se salva em um arquivo.

As ações de `BeginWaitCursor` nem sempre são eficazes fora de um único manipulador de mensagem, pois outras ações, como a manipulação de `OnSetCursor`, podem alterar o cursor.

Chame `EndWaitCursor` para restaurar o cursor anterior.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCDocView#43](../../mfc/codesnippet/cpp/ccmdtarget-class_1.cpp)]

##  <a name="ccmdtarget"></a>CCmdTarget:: CCmdTarget

Constrói um objeto `CCmdTarget`.

```
CCmdTarget();
```

##  <a name="dooleverb"></a>CCmdTarget::D oOleVerb

Faz com que uma ação especificada por um verbo OLE seja executada.

```
BOOL DoOleVerb(
    LONG iVerb,
    LPMSG lpMsg,
    HWND hWndParent,
    LPCRECT lpRect);
```

### <a name="parameters"></a>parâmetros

*iVerb*<br/>
Identificador numérico do verbo.

*lpMsg*<br/>
Ponteiro para a estrutura [msg](/windows/win32/api/winuser/ns-winuser-msg) que descreve o evento (como um clique duplo) que invocou o verbo.

*hWndParent*<br/>
Identificador da janela do documento que contém o objeto.

*lpRect*<br/>
Ponteiro para a estrutura [Rect](/previous-versions/dd162897\(v=vs.85\)) que contém as coordenadas, em pixels, que definem o retângulo delimitador de um objeto em *hwndParent*.

### <a name="return-value"></a>Valor retornado

TRUE se for bem-sucedido; caso contrário, FALSE.

### <a name="remarks"></a>Comentários

Essa função de membro é basicamente uma implementação de [IOleObject::D overb](/windows/win32/api/oleidl/nf-oleidl-ioleobject-doverb). As ações possíveis são enumeradas por [CCmdTarget:: EnumOleVerbs](#enumoleverbs).

##  <a name="enableautomation"></a>CCmdTarget:: EnableAutomation

Chame essa função para habilitar a automação OLE para um objeto.

```
void EnableAutomation();
```

### <a name="remarks"></a>Comentários

Essa função é normalmente chamada do construtor do seu objeto e só deve ser chamada se um mapa de expedição tiver sido declarado para a classe. Para obter mais informações sobre automação, consulte os artigos [clientes de automação](../../mfc/automation-clients.md) e [servidores de automação](../../mfc/automation-servers.md).

##  <a name="enableconnections"></a>CCmdTarget:: EnableConnections

Habilita o acionamento de eventos em pontos de conexão.

```
void EnableConnections();
```

### <a name="remarks"></a>Comentários

Para habilitar pontos de conexão, chame essa função de membro no construtor da classe derivada.

##  <a name="enabletypelib"></a>CCmdTarget:: EnableTypeLib

Habilita a biblioteca de tipos de um objeto.

```
void EnableTypeLib();
```

### <a name="remarks"></a>Comentários

Chame essa função de membro no construtor do objeto derivado de `CCmdTarget`se ele fornecer informações de tipo.

##  <a name="endwaitcursor"></a>CCmdTarget:: EndWaitCursor

Chame essa função depois de ter chamado a função membro `BeginWaitCursor` para retornar do cursor de ampulheta para o cursor anterior.

```
void EndWaitCursor();
```

### <a name="remarks"></a>Comentários

A estrutura também chama essa função de membro depois de chamar o cursor de ampulheta.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCDocView#43](../../mfc/codesnippet/cpp/ccmdtarget-class_1.cpp)]

##  <a name="enumoleverbs"></a>CCmdTarget:: EnumOleVerbs

Enumera os verbos OLE de um objeto.

```
BOOL EnumOleVerbs(LPENUMOLEVERB* ppenumOleVerb);
```

### <a name="parameters"></a>parâmetros

*ppenumOleVerb*<br/>
Um ponteiro para um ponteiro para uma interface [IEnumOLEVERB](/windows/win32/api/oleidl/nn-oleidl-ienumoleverb) .

### <a name="return-value"></a>Valor retornado

TRUE se o objeto der suporte a pelo menos um verbo OLE (nesse caso \* *ppEnumOleVerb* aponta para uma interface de enumerador `IEnumOLEVERB`); caso contrário, false.

### <a name="remarks"></a>Comentários

Essa função de membro é basicamente uma implementação de [IOleObject:: EnumVerbs](/windows/win32/api/oleidl/nf-oleidl-ioleobject-enumverbs).

##  <a name="fromidispatch"></a>CCmdTarget:: FromIDispatch

Chame essa função para mapear um ponteiro de `IDispatch`, recebido de funções de membro de automação de uma classe, para o objeto `CCmdTarget` que implementa as interfaces do objeto `IDispatch`.

```
static CCmdTarget* PASCAL FromIDispatch(LPDISPATCH lpDispatch);
```

### <a name="parameters"></a>parâmetros

*lpDispatch*<br/>
Um ponteiro para um objeto `IDispatch`.

### <a name="return-value"></a>Valor retornado

Um ponteiro para o objeto `CCmdTarget` associado a *LPDISPATCH*. Essa função retornará NULL se o objeto `IDispatch` não for reconhecido como um objeto Microsoft Foundation Class `IDispatch`.

### <a name="remarks"></a>Comentários

O resultado dessa função é o inverso de uma chamada para a função membro `GetIDispatch`.

##  <a name="getdispatchiid"></a>CCmdTarget:: GetDispatchIID

Obtém a ID da interface de expedição primária.

```
virtual BOOL GetDispatchIID(IID* pIID);
```

### <a name="parameters"></a>parâmetros

*pIID*<br/>
Um ponteiro para uma ID de interface (um [GUID](/previous-versions/cc317743(v%3dmsdn.10)).

### <a name="return-value"></a>Valor retornado

TRUE se for bem-sucedido; caso contrário, FALSE. Se for bem-sucedido, \* *piid* será definido como a ID da interface de expedição primária.

### <a name="remarks"></a>Comentários

Classes derivadas devem substituir essa função de membro (se não for substituída, `GetDispatchIID` retorna FALSE). Consulte [COleControl](../../mfc/reference/colecontrol-class.md).

##  <a name="getidispatch"></a>CCmdTarget:: GetIDispatch

Chame essa função de membro para recuperar o ponteiro de `IDispatch` de um método de automação que retorna um ponteiro de `IDispatch` ou usa um ponteiro de `IDispatch` por referência.

```
LPDISPATCH GetIDispatch(BOOL bAddRef);
```

### <a name="parameters"></a>parâmetros

*bAddRef*<br/>
Especifica se a contagem de referência para o objeto deve ser incrementada.

### <a name="return-value"></a>Valor retornado

O ponteiro de `IDispatch` associado ao objeto.

### <a name="remarks"></a>Comentários

Para objetos que chamam `EnableAutomation` em seus construtores, tornando-os habilitados, essa função retorna um ponteiro para a implementação da classe Foundation de `IDispatch` que é usada por clientes que se comunicam por meio da interface `IDispatch`. Chamar essa função automaticamente adiciona uma referência ao ponteiro, portanto, não é necessário fazer uma chamada para [IUnknown:: AddRef](/windows/win32/api/unknwn/nf-unknwn-iunknown-addref).

##  <a name="gettypeinfocount"></a>CCmdTarget:: GetTypeInfoCount

Recupera o número de interfaces de informações de tipo que um objeto fornece.

```
virtual UINT GetTypeInfoCount();
```

### <a name="return-value"></a>Valor retornado

O número de interfaces de informações de tipo.

### <a name="remarks"></a>Comentários

Essa função de membro basicamente implementa [IDispatch:: GetTypeInfoCount](/windows/win32/api/oaidl/nf-oaidl-idispatch-gettypeinfocount).

Classes derivadas devem substituir essa função para retornar o número de interfaces de informações de tipo fornecidas (0 ou 1). Se não for substituído, `GetTypeInfoCount` retornará 0. Para substituir, use a macro [IMPLEMENT_OLETYPELIB](../../mfc/reference/type-library-access.md#implement_oletypelib) , que também implementa `GetTypeLib` e `GetTypeLibCache`.

##  <a name="gettypeinfoofguid"></a>CCmdTarget:: GetTypeInfoOfGuid

Recupera a descrição de tipo que corresponde ao GUID especificado.

```
HRESULT GetTypeInfoOfGuid(
    LCID lcid,
    const GUID& guid,
    LPTYPEINFO* ppTypeInfo);
```

### <a name="parameters"></a>parâmetros

*lcid*<br/>
Um identificador de localidade (`LCID`).

*guid*<br/>
O [GUID](/previous-versions/cc317743(v%3dmsdn.10)) da descrição do tipo.

*ppTypeInfo*<br/>
Ponteiro para um ponteiro para a interface `ITypeInfo`.

### <a name="return-value"></a>Valor retornado

Um HRESULT que indica o êxito ou a falha da chamada. Se for bem-sucedido, \* *ppTypeInfo* apontará para a interface de informações de tipo.

##  <a name="gettypelib"></a>CCmdTarget:: GetTypeLib

Obtém um ponteiro para uma biblioteca de tipos.

```
virtual HRESULT GetTypeLib(
    LCID lcid,
    LPTYPELIB* ppTypeLib);
```

### <a name="parameters"></a>parâmetros

*lcid*<br/>
Um LCID (ID de localidade).

*ppTypeLib*<br/>
Um ponteiro para um ponteiro para a interface `ITypeLib`.

### <a name="return-value"></a>Valor retornado

Um HRESULT que indica o êxito ou a falha da chamada. Se for bem-sucedido, \* *ppTypeLib* apontar para a interface de biblioteca de tipos.

### <a name="remarks"></a>Comentários

Classes derivadas devem substituir essa função de membro (se não for substituída, `GetTypeLib` retorna TYPE_E_CANTLOADLIBRARY). Use a macro [IMPLEMENT_OLETYPELIB](../../mfc/reference/type-library-access.md#implement_oletypelib) , que também implementa `GetTypeInfoCount` e `GetTypeLibCache`.

##  <a name="gettypelibcache"></a>CCmdTarget:: GetTypeLibCache

Obtém o cache da biblioteca de tipos.

```
virtual CTypeLibCache* GetTypeLibCache();
```

### <a name="return-value"></a>Valor retornado

Um ponteiro para um objeto `CTypeLibCache`.

### <a name="remarks"></a>Comentários

Classes derivadas devem substituir essa função de membro (se não for substituída, `GetTypeLibCache` retorna NULL). Use a macro [IMPLEMENT_OLETYPELIB](../../mfc/reference/type-library-access.md#implement_oletypelib) , que também implementa `GetTypeInfoCount` e `GetTypeLib`.

##  <a name="isinvokeallowed"></a>CCmdTarget:: IsInvokeAllowed

Essa função é chamada pela implementação de `IDispatch::Invoke` do MFC para determinar se um determinado método de automação (identificado por *DISPID*) pode ser invocado.

```
virtual BOOL IsInvokeAllowed(DISPID dispid);
```

### <a name="parameters"></a>parâmetros

*DISPID*<br/>
Uma ID de expedição.

### <a name="return-value"></a>Valor retornado

TRUE se o método puder ser invocado; caso contrário, FALSE.

### <a name="remarks"></a>Comentários

Se `IsInvokeAllowed` retornar TRUE, `Invoke` continuará a chamar o método; caso contrário, `Invoke` falhará, retornando E_UNEXPECTED.

Classes derivadas podem substituir essa função para retornar valores apropriados (se não for substituído, `IsInvokeAllowed` retorna TRUE). Consulte em particular [COleControl:: IsInvokeAllowed](../../mfc/reference/colecontrol-class.md#isinvokeallowed).

##  <a name="isresultexpected"></a>CCmdTarget:: IsResultExpected

Use `IsResultExpected` para verificar se um cliente espera um valor de retorno de sua chamada para uma função de automação.

```
BOOL IsResultExpected();
```

### <a name="return-value"></a>Valor retornado

Diferente de zero se uma função de automação deve retornar um valor; caso contrário, 0.

### <a name="remarks"></a>Comentários

A interface OLE fornece informações para o MFC sobre se o cliente está usando ou ignorando o resultado de uma chamada de função, e o MFC, por sua vez, usa essas informações para determinar o resultado de uma chamada para `IsResultExpected`. Se a produção de um valor de retorno for de uso intensivo de tempo ou de recursos, você poderá aumentar a eficiência chamando essa função antes de calcular o valor de retorno.

Essa função retorna 0 somente uma vez para que você obtenha valores de retorno válidos de outras funções de automação se chamá-los da função de automação que o cliente chamou.

`IsResultExpected` retornará um valor diferente de zero se chamado quando uma chamada de função de automação não estiver em andamento.

##  <a name="oncmdmsg"></a>CCmdTarget:: OnCmdMsg

Chamado pelo Framework para rotear e distribuir mensagens de comando e para manipular a atualização de objetos de interface de usuário de comando.

```
virtual BOOL OnCmdMsg(
    UINT nID,
    int nCode,
    void* pExtra,
    AFX_CMDHANDLERINFO* pHandlerInfo);
```

### <a name="parameters"></a>parâmetros

*nID*<br/>
Contém a ID de comando.

*nCode*<br/>
Identifica o código de notificação do comando. Consulte **comentários** para obter mais informações sobre os valores de *nCode*.

*pExtra*<br/>
Usado de acordo com o valor de *nCode*. Consulte **comentários** para obter mais informações sobre *pExtra*.

*pHandlerInfo*<br/>
Se não for NULL, `OnCmdMsg` preencherá os membros *pTarget* e *PMF* da estrutura *pHandlerInfo* em vez de expedir o comando. Normalmente, esse parâmetro deve ser nulo.

### <a name="return-value"></a>Valor retornado

Diferente de zero se a mensagem for tratada; caso contrário, 0.

### <a name="remarks"></a>Comentários

Essa é a principal rotina de implementação da arquitetura de comando do Framework.

Em tempo de execução, `OnCmdMsg` despacha um comando para outros objetos ou manipula o próprio comando chamando a classe raiz `CCmdTarget::OnCmdMsg`, que faz a pesquisa real do mapa de mensagens. Para obter uma descrição completa do roteamento de comandos padrão, consulte [tópicos sobre manipulação de mensagens e mapeamento](../../mfc/message-handling-and-mapping.md).

Em raras ocasiões, talvez você queira substituir essa função de membro para estender o roteamento de comandos padrão da estrutura. Consulte a [Nota técnica 21](../../mfc/tn021-command-and-message-routing.md) para obter detalhes avançados sobre a arquitetura de roteamento de comando.

Se você substituir `OnCmdMsg`, deverá fornecer o valor apropriado para *nCode*, o código de notificação de comando e *pExtra*, que depende do valor de *nCode*. A tabela a seguir lista os valores correspondentes:

|valor de *nCode*|valor de *pExtra*|
|-------------------|--------------------|
|CN_COMMAND|\* [CCmdUI](../../mfc/reference/ccmdui-class.md)|
|CN_EVENT|AFX_EVENT\*|
|CN_UPDATE_COMMAND_UI|\* CCmdUI|
|CN_OLECOMMAND|\* [COleCmdUI](../../mfc/reference/colecmdui-class.md)|
|CN_OLE_UNREGISTER|NULO|

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCDocView#44](../../mfc/codesnippet/cpp/ccmdtarget-class_2.cpp)]

[!code-cpp[NVC_MFCDocView#45](../../mfc/codesnippet/cpp/ccmdtarget-class_3.cpp)]

##  <a name="onfinalrelease"></a>CCmdTarget:: OnFinalRelease

Chamado pelo Framework quando a última referência OLE de ou para o objeto é liberada.

```
virtual void OnFinalRelease();
```

### <a name="remarks"></a>Comentários

Substitua essa função para fornecer tratamento especial para essa situação. A implementação padrão exclui o objeto.

##  <a name="restorewaitcursor"></a>CCmdTarget:: RestoreWaitCursor

Chame essa função para restaurar o cursor de ampulheta apropriado após a alteração do cursor do sistema (por exemplo, depois que uma caixa de mensagem tiver sido aberta e fechada enquanto estiver no meio de uma operação demorada).

```
void RestoreWaitCursor();
```

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCDocView#43](../../mfc/codesnippet/cpp/ccmdtarget-class_1.cpp)]

## <a name="see-also"></a>Confira também

[Exemplo de ACDUAL do MFC](../../overview/visual-cpp-samples.md)<br/>
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
