---
title: Classe COleMessageFilter
ms.date: 11/04/2016
f1_keywords:
- COleMessageFilter
- AFXOLE/COleMessageFilter
- AFXOLE/COleMessageFilter::COleMessageFilter
- AFXOLE/COleMessageFilter::BeginBusyState
- AFXOLE/COleMessageFilter::EnableBusyDialog
- AFXOLE/COleMessageFilter::EnableNotRespondingDialog
- AFXOLE/COleMessageFilter::EndBusyState
- AFXOLE/COleMessageFilter::OnMessagePending
- AFXOLE/COleMessageFilter::Register
- AFXOLE/COleMessageFilter::Revoke
- AFXOLE/COleMessageFilter::SetBusyReply
- AFXOLE/COleMessageFilter::SetMessagePendingDelay
- AFXOLE/COleMessageFilter::SetRetryReply
helpviewer_keywords:
- COleMessageFilter [MFC], COleMessageFilter
- COleMessageFilter [MFC], BeginBusyState
- COleMessageFilter [MFC], EnableBusyDialog
- COleMessageFilter [MFC], EnableNotRespondingDialog
- COleMessageFilter [MFC], EndBusyState
- COleMessageFilter [MFC], OnMessagePending
- COleMessageFilter [MFC], Register
- COleMessageFilter [MFC], Revoke
- COleMessageFilter [MFC], SetBusyReply
- COleMessageFilter [MFC], SetMessagePendingDelay
- COleMessageFilter [MFC], SetRetryReply
ms.assetid: b1fd1639-fac4-4fd0-bf17-15172deba13c
ms.openlocfilehash: a06891f9413979895175808e109cc4abb7d75e09
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62224352"
---
# <a name="colemessagefilter-class"></a>Classe COleMessageFilter

Gerencia a concorrência necessária pela interação de aplicativos OLE.

## <a name="syntax"></a>Sintaxe

```
class COleMessageFilter : public CCmdTarget
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[COleMessageFilter::COleMessageFilter](#colemessagefilter)|Constrói um objeto `COleMessageFilter`.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[COleMessageFilter::BeginBusyState](#beginbusystate)|Coloque o aplicativo no estado ocupado.|
|[COleMessageFilter::EnableBusyDialog](#enablebusydialog)|Habilita e desabilita a caixa de diálogo que aparece quando um aplicativo de chamada está ocupado.|
|[COleMessageFilter::EnableNotRespondingDialog](#enablenotrespondingdialog)|Habilita e desabilita a caixa de diálogo que aparece quando um aplicativo de chamada não está respondendo.|
|[COleMessageFilter::EndBusyState](#endbusystate)|Encerra o estado do aplicativo ocupado.|
|[COleMessageFilter::OnMessagePending](#onmessagepending)|Chamado pelo framework para processar mensagens enquanto uma chamada OLE estiver em andamento.|
|[COleMessageFilter::Register](#register)|Registra o filtro de mensagem com as DLLs do sistema OLE.|
|[COleMessageFilter::Revoke](#revoke)|Revoga o registro do filtro de mensagem com as DLLs do sistema OLE.|
|[COleMessageFilter::SetBusyReply](#setbusyreply)|Determina a resposta do aplicativo ocupado para uma chamada OLE.|
|[COleMessageFilter::SetMessagePendingDelay](#setmessagependingdelay)|Determina por quanto tempo o aplicativo aguarda uma resposta a uma chamada OLE.|
|[COleMessageFilter::SetRetryReply](#setretryreply)|Determina a resposta do aplicativo de chamada para um aplicativo ocupado.|

## <a name="remarks"></a>Comentários

O `COleMessageFilter` classe é útil em aplicativos de servidor e o contêiner de edição visual, bem como aplicativos de automação OLE. Para aplicativos de servidor que estão sendo chamados, essa classe pode ser usada para tornar o aplicativo "ocupado" para que as chamadas recebidas de outros aplicativos de contêiner são canceladas ou tentada novamente mais tarde. Essa classe também pode ser usada para determinar a ação a ser tomada por um aplicativo de chamada quando o aplicativo de chamada está ocupado.

Uso comum é para um aplicativo de servidor para chamar [BeginBusyState](#beginbusystate) e [EndBusyState](#endbusystate) quando seria perigoso para um documento ou outro objeto acessível de OLE a ser destruído. Essas chamadas são feitas no [CWinApp::OnIdle](../../mfc/reference/cwinapp-class.md#onidle) durante as atualizações da interface do usuário.

Por padrão, um `COleMessageFilter` objeto é alocado quando o aplicativo é inicializado. Ele pode ser recuperado com [AfxOleGetMessageFilter](application-control.md#afxolegetmessagefilter).

Esta é uma classe avançada; Você raramente precisa trabalhar diretamente com ela.

Para obter mais informações, consulte o artigo [servidores: Implementação de um servidor](../../mfc/servers-implementing-a-server.md).

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[CObject](../../mfc/reference/cobject-class.md)

[CCmdTarget](../../mfc/reference/ccmdtarget-class.md)

`COleMessageFilter`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxole.h

##  <a name="beginbusystate"></a>  COleMessageFilter::BeginBusyState

Chame essa função para começar a um estado ocupado.

```
virtual void BeginBusyState();
```

### <a name="remarks"></a>Comentários

Ele funciona em conjunto com [EndBusyState](#endbusystate) para controlar o estado do aplicativo ocupado. A função [SetBusyReply](#setbusyreply) determina a resposta do aplicativo para aplicativos de chamada quando ele está ocupado.

O `BeginBusyState` e `EndBusyState` chamadas incrementar e diminuir, respectivamente, um contador que determina se o aplicativo está ocupado. Por exemplo, duas chamadas para `BeginBusyState` e uma chamada para `EndBusyState` ainda resultarão em um estado ocupado. Para cancelar um estado ocupado, é necessário chamar `EndBusyState` o mesmo número de vezes que `BeginBusyState` foi chamado.

Por padrão, a estrutura entra no estado de ocupado durante o processamento ocioso, o que é executado pelo [CWinApp::OnIdle](../../mfc/reference/cwinapp-class.md#onidle). Enquanto o aplicativo está manipulando notificações de ON_COMMANDUPDATEUI, chamadas de entrada são tratadas mais tarde, após a conclusão do processamento ocioso.

##  <a name="colemessagefilter"></a>  COleMessageFilter::COleMessageFilter

Cria um objeto `COleMessageFilter`.

```
COleMessageFilter();
```

##  <a name="enablebusydialog"></a>  COleMessageFilter::EnableBusyDialog

Habilita e desabilita a caixa de diálogo ocupado, o que é exibida quando o atraso pendente de mensagem expira (consulte [SetRetryReply](#setretryreply)) durante uma chamada OLE.

```
void EnableBusyDialog(BOOL bEnableBusy = TRUE);
```

### <a name="parameters"></a>Parâmetros

*bEnableBusy*<br/>
Especifica se a caixa de diálogo "ocupado" é habilitada ou desabilitada.

##  <a name="enablenotrespondingdialog"></a>  COleMessageFilter::EnableNotRespondingDialog

Habilita e desabilita a caixa de diálogo "não está respondendo", que será exibida se uma mensagem do teclado ou mouse está pendente durante uma OLE chamada e a chamada foi atingido.

```
void EnableNotRespondingDialog(BOOL bEnableNotResponding = TRUE);
```

### <a name="parameters"></a>Parâmetros

*bEnableNotResponding*<br/>
Especifica se a caixa de diálogo "não está respondendo" está habilitada ou desabilitada.

##  <a name="endbusystate"></a>  COleMessageFilter::EndBusyState

Chame essa função para encerrar um estado ocupado.

```
virtual void EndBusyState();
```

### <a name="remarks"></a>Comentários

Ele funciona em conjunto com [BeginBusyState](#beginbusystate) para controlar o estado do aplicativo ocupado. A função [SetBusyReply](#setbusyreply) determina a resposta do aplicativo para aplicativos de chamada quando ele está ocupado.

O `BeginBusyState` e `EndBusyState` chamadas incrementar e diminuir, respectivamente, um contador que determina se o aplicativo está ocupado. Por exemplo, duas chamadas para `BeginBusyState` e uma chamada para `EndBusyState` ainda resultarão em um estado ocupado. Para cancelar um estado ocupado, é necessário chamar `EndBusyState` o mesmo número de vezes que `BeginBusyState` foi chamado.

Por padrão, a estrutura entra no estado de ocupado durante o processamento ocioso, o que é executado pelo [CWinApp::OnIdle](../../mfc/reference/cwinapp-class.md#onidle). Enquanto o aplicativo está manipulando notificações de ON_UPDATE_COMMAND_UI, chamadas de entrada são manipuladas após a conclusão do processamento ocioso.

##  <a name="onmessagepending"></a>  COleMessageFilter::OnMessagePending

Chamado pelo framework para processar mensagens enquanto uma chamada OLE estiver em andamento.

```
virtual BOOL OnMessagePending(const MSG* pMsg);
```

### <a name="parameters"></a>Parâmetros

*pMsg*<br/>
Ponteiro para a mensagem pendente.

### <a name="return-value"></a>Valor de retorno

Diferente de zero em caso de êxito; Caso contrário, 0.

### <a name="remarks"></a>Comentários

Quando um aplicativo de chamada está aguardando uma chamada para ser concluída, o framework chama `OnMessagePending` com um ponteiro para a mensagem pendente. Por padrão, o framework expede mensagens WM_PAINT, para que a janela atualizações podem ocorrer durante uma chamada que está demorando muito tempo.

Você deve registrar seu filtro de mensagem por meio de uma chamada para [registrar](#register) antes que ele pode se tornar ativo.

##  <a name="register"></a>  COleMessageFilter::Register

Registra o filtro de mensagem com as DLLs do sistema OLE.

```
BOOL Register();
```

### <a name="return-value"></a>Valor de retorno

Diferente de zero em caso de êxito; Caso contrário, 0.

### <a name="remarks"></a>Comentários

Um filtro de mensagem não tem nenhum efeito a menos que ele é registrado com as DLLs do sistema. Geralmente, o código de inicialização do seu aplicativo registra o filtro de mensagens do aplicativo. Qualquer outro filtro de mensagem registrado pelo seu aplicativo deve ser revogado antes que o programa seja encerrado por uma chamada para [revogar](#revoke).

Filtro de mensagem padrão da estrutura é automaticamente registrado durante a inicialização e revogado no encerramento.

##  <a name="revoke"></a>  COleMessageFilter::Revoke

Revoga um registro anterior executado por uma chamada para [registrar](#register).

```
void Revoke();
```

### <a name="remarks"></a>Comentários

Um filtro de mensagem deve ser revogado antes que o programa seja encerrado.

O filtro de mensagem padrão, que é criado e registrado automaticamente pela estrutura, automaticamente é revogado.

##  <a name="setbusyreply"></a>  COleMessageFilter::SetBusyReply

Essa função define a "ocupado responder." caixa de diálogo

```
void SetBusyReply(SERVERCALL nBusyReply);
```

### <a name="parameters"></a>Parâmetros

*nBusyReply*<br/>
Um valor da `SERVERCALL` enumeração, que é definida no COMPOBJ. H. Ele pode ter qualquer um dos seguintes valores:

- SERVERCALL_ISHANDLED o aplicativo pode aceitar chamadas, mas pode falhar no processamento de uma chamada específica.

- SERVERCALL_REJECTED o aplicativo provavelmente nunca será capaz de processar uma chamada.

- SERVERCALL_RETRYLATER o aplicativo está temporariamente em um estado em que não é possível processar uma chamada.

### <a name="remarks"></a>Comentários

O [BeginBusyState](#beginbusystate) e [EndBusyState](#endbusystate) funções controlam o estado do aplicativo ocupado.

Quando um aplicativo se tornou ocupado com uma chamada para `BeginBusyState`, ele responde a chamadas de DLLs do sistema OLE com um valor determinado pela configuração da última `SetBusyReply`. O aplicativo de chamada usa esta resposta ocupada para determinar qual ação será tomada.

Por padrão, a resposta ocupada é SERVERCALL_RETRYLATER. Esta resposta faz com que o aplicativo de chamada repetir a chamada assim que possível.

##  <a name="setmessagependingdelay"></a>  COleMessageFilter::SetMessagePendingDelay

Determina quanto tempo o aplicativo de chamada aguarda uma resposta do aplicativo chamado antes de realizar outras ações.

```
void SetMessagePendingDelay(DWORD nTimeout = 5000);
```

### <a name="parameters"></a>Parâmetros

*nTimeout*<br/>
Número de milissegundos para o atraso de mensagens pendentes.

### <a name="remarks"></a>Comentários

Essa função trabalha em conjunto com [SetRetryReply](#setretryreply).

##  <a name="setretryreply"></a>  COleMessageFilter::SetRetryReply

Determina a ação do aplicativo de chamada quando ele recebe uma resposta ocupado em um aplicativo de chamada.

```
void SetRetryReply(DWORD nRetryReply = 0);
```

### <a name="parameters"></a>Parâmetros

*nRetryReply*<br/>
Número de milissegundos entre as repetições.

### <a name="remarks"></a>Comentários

Quando um aplicativo chamado indica que ele está ocupado, o aplicativo de chamada pode decidir aguardar até que o servidor não está mais ocupado, repetir imediatamente, ou tentar novamente após um intervalo especificado. Ele também pode decidir cancelá-la completamente.

Resposta do chamador é controlada pelas funções `SetRetryReply` e [SetMessagePendingDelay](#setmessagependingdelay). `SetRetryReply` Determina quanto tempo o aplicativo de chamada deve aguardar entre as repetições de uma determinada chamada. `SetMessagePendingDelay` Determina quanto tempo o aplicativo de chamada aguarda uma resposta do servidor antes de executar uma ação adicional.

Normalmente, os padrões são aceitáveis e não precisa ser alterado. A estrutura repetirá a chamada cada *nRetryReply* milissegundos até que a chamada passa por ou o atraso pendente de mensagem expirou. Um valor de 0 para *nRetryReply* Especifica uma repetição imediata e - 1 Especifica o cancelamento da chamada.

Quando o atraso de mensagens pendentes tiver expirado, a OLE "caixa de diálogo ocupado" (consulte [COleBusyDialog](../../mfc/reference/colebusydialog-class.md)) é exibida para que o usuário pode optar por cancelar ou repetir a chamada. Chame [EnableBusyDialog](#enablebusydialog) para habilitar ou desabilitar essa caixa de diálogo.

Quando uma mensagem do teclado ou mouse fica pendente durante uma chamada e a chamada foi atingido (excedido o atraso de mensagens pendentes), a caixa de diálogo "não está respondendo" é exibida. Chame [EnableNotRespondingDialog](#enablenotrespondingdialog) para habilitar ou desabilitar essa caixa de diálogo. Normalmente, esse estado de assuntos indica que algo deu errado e o usuário está obtendo impaciente.

Quando as caixas de diálogo estão desabilitadas, o atual "Repetir resposta" é sempre usado para chamadas para aplicativos de ocupado.

## <a name="see-also"></a>Consulte também

[Classe CCmdTarget](../../mfc/reference/ccmdtarget-class.md)<br/>
[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classe CCmdTarget](../../mfc/reference/ccmdtarget-class.md)
