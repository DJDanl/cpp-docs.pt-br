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
ms.openlocfilehash: 8a6c160a76ae27059238c3e8e26b5bea87a87f7f
ms.sourcegitcommit: 7a6116e48c3c11b97371b8ae4ecc23adce1f092d
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/22/2020
ms.locfileid: "81753837"
---
# <a name="colemessagefilter-class"></a>Classe COleMessageFilter

Gerencia a concorrência necessária pela interação dos aplicativos OLE.

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
|[COleMessageFilter::BeginBusyState](#beginbusystate)|Coloca a aplicação no estado ocupado.|
|[COleMessageFilter::AtivarDiálogo ocupada](#enablebusydialog)|Ativa e desativa a caixa de diálogo que aparece quando um aplicativo chamado está ocupado.|
|[COleMessageFilter::AtivarNãoresponderDiálogo](#enablenotrespondingdialog)|Ativa e desativa a caixa de diálogo que aparece quando um aplicativo chamado não está respondendo.|
|[COleMessageFilter::EndBusyState](#endbusystate)|Termina o estado ocupado do aplicativo.|
|[COleMessageFilter::OnMessagePending](#onmessagepending)|Chamado pela estrutura para processar mensagens enquanto uma chamada OLE está em andamento.|
|[COleMessageFilter::Register](#register)|Registra o filtro de mensagem com os DLLs do sistema OLE.|
|[COleMessageFilter::Revogar](#revoke)|Revoga o registro do filtro de mensagem com os DLLs do sistema OLE.|
|[COleMessageFilter::SetBusyReply](#setbusyreply)|Determina a resposta do aplicativo ocupado a uma chamada OLE.|
|[COleMessageFilter::SetMessagePendingDelay](#setmessagependingdelay)|Determina quanto tempo o aplicativo espera por uma resposta a uma chamada oLE.|
|[COleMessageFilter::SetRetryReply](#setretryreply)|Determina a resposta do aplicativo de chamada a um aplicativo ocupado.|

## <a name="remarks"></a>Comentários

A `COleMessageFilter` classe é útil em aplicativos de servidor de edição visual e contêiner, bem como aplicativos de automação OLE. Para aplicativos de servidor que estão sendo chamados, essa classe pode ser usada para tornar o aplicativo "ocupado" para que as chamadas recebidas de outros aplicativos de contêiner sejam canceladas ou repetidas posteriormente. Essa classe também pode ser usada para determinar a ação a ser tomada por um aplicativo de chamada quando o aplicativo chamado estiver ocupado.

O uso comum é para um aplicativo de servidor chamar [BeginBusyState](#beginbusystate) e [EndBusyState](#endbusystate) quando seria perigoso para um documento ou outro objeto acessível ao OLE ser destruído. Essas chamadas são feitas em [CWinApp::OnIdle](../../mfc/reference/cwinapp-class.md#onidle) durante as atualizações da interface do usuário.

Por padrão, `COleMessageFilter` um objeto é alocado quando o aplicativo é inicializado. Ele pode ser recuperado com [AfxOleGetMessageFilter](application-control.md#afxolegetmessagefilter).

Esta é uma classe avançada; raramente precisa trabalhar diretamente com ele.

Para obter mais informações, consulte o artigo [Servidores: Implementando um Servidor](../../mfc/servers-implementing-a-server.md).

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[Cobject](../../mfc/reference/cobject-class.md)

[Ccmdtarget](../../mfc/reference/ccmdtarget-class.md)

`COleMessageFilter`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxole.h

## <a name="colemessagefilterbeginbusystate"></a><a name="beginbusystate"></a>COleMessageFilter::BeginBusyState

Chame esta função para começar um estado ocupado.

```
virtual void BeginBusyState();
```

### <a name="remarks"></a>Comentários

Ele funciona em conjunto com [endbusystate](#endbusystate) para controlar o estado ocupado do aplicativo. A função [SetBusyReply](#setbusyreply) determina a resposta do aplicativo aos aplicativos de chamada quando ele está ocupado.

O `BeginBusyState` `EndBusyState` e chama incremento e decrésia, respectivamente, um contador que determina se a aplicação está ocupada. Por exemplo, duas `BeginBusyState` chamadas para `EndBusyState` e uma chamada para ainda resultar em um estado ocupado. Para cancelar um estado ocupado `EndBusyState` é necessário ligar `BeginBusyState` para o mesmo número de vezes que foi chamado.

Por padrão, o framework insere o estado ocupado durante o processamento ocioso, que é realizado por [CWinApp::OnIdle](../../mfc/reference/cwinapp-class.md#onidle). Enquanto o aplicativo está lidando com notificações ON_COMMANDUPDATEUI, as chamadas recebidas são tratadas posteriormente, após o processamento ocioso ser concluído.

## <a name="colemessagefiltercolemessagefilter"></a><a name="colemessagefilter"></a>COleMessageFilter::COleMessageFilter

Cria um objeto `COleMessageFilter`.

```
COleMessageFilter();
```

## <a name="colemessagefilterenablebusydialog"></a><a name="enablebusydialog"></a>COleMessageFilter::AtivarDiálogo ocupada

Ativa e desativa a caixa de diálogo ocupada, que é exibida quando o atraso pendente de mensagem expira (consulte [SetRetryReply](#setretryreply)) durante uma chamada OLE.

```cpp
void EnableBusyDialog(BOOL bEnableBusy = TRUE);
```

### <a name="parameters"></a>Parâmetros

*bEnableBusy*<br/>
Especifica se a caixa de diálogo "ocupada" está ativada ou desativada.

## <a name="colemessagefilterenablenotrespondingdialog"></a><a name="enablenotrespondingdialog"></a>COleMessageFilter::AtivarNãoresponderDiálogo

Ativa e desativa a caixa de diálogo "não respondendo", que é exibida se uma mensagem de teclado ou mouse estiver pendente durante uma chamada OLE e a chamada tiver sido cronometrada.

```cpp
void EnableNotRespondingDialog(BOOL bEnableNotResponding = TRUE);
```

### <a name="parameters"></a>Parâmetros

*bEnableNotResponding*<br/>
Especifica se a caixa de diálogo "não respondendo" está ativada ou desativada.

## <a name="colemessagefilterendbusystate"></a><a name="endbusystate"></a>COleMessageFilter::EndBusyState

Chame esta função para acabar com um estado ocupado.

```
virtual void EndBusyState();
```

### <a name="remarks"></a>Comentários

Ele funciona em conjunto com [o BeginBusyState](#beginbusystate) para controlar o estado ocupado do aplicativo. A função [SetBusyReply](#setbusyreply) determina a resposta do aplicativo aos aplicativos de chamada quando ele está ocupado.

O `BeginBusyState` `EndBusyState` e chama incremento e decrésia, respectivamente, um contador que determina se a aplicação está ocupada. Por exemplo, duas `BeginBusyState` chamadas para `EndBusyState` e uma chamada para ainda resultar em um estado ocupado. Para cancelar um estado ocupado `EndBusyState` é necessário ligar `BeginBusyState` para o mesmo número de vezes que foi chamado.

Por padrão, o framework insere o estado ocupado durante o processamento ocioso, que é realizado por [CWinApp::OnIdle](../../mfc/reference/cwinapp-class.md#onidle). Enquanto o aplicativo está lidando com notificações ON_UPDATE_COMMAND_UI, as chamadas recebidas são tratadas após o processamento ocioso ser concluído.

## <a name="colemessagefilteronmessagepending"></a><a name="onmessagepending"></a>COleMessageFilter::OnMessagePending

Chamado pela estrutura para processar mensagens enquanto uma chamada OLE está em andamento.

```
virtual BOOL OnMessagePending(const MSG* pMsg);
```

### <a name="parameters"></a>Parâmetros

*pMsg*<br/>
Ponteiro para a mensagem pendente.

### <a name="return-value"></a>Valor retornado

Não zero no sucesso; caso contrário, 0.

### <a name="remarks"></a>Comentários

Quando um aplicativo de chamada está esperando uma `OnMessagePending` chamada ser concluída, o framework liga com um ponteiro para a mensagem pendente. Por padrão, o framework despacha WM_PAINT mensagens, para que as atualizações de janelas possam ocorrer durante uma chamada que está demorando muito.

Você deve registrar seu filtro de mensagem por meio de uma chamada para [registrar](#register) antes que ele possa se tornar ativo.

## <a name="colemessagefilterregister"></a><a name="register"></a>COleMessageFilter::Register

Registra o filtro de mensagem com os DLLs do sistema OLE.

```
BOOL Register();
```

### <a name="return-value"></a>Valor retornado

Não zero no sucesso; caso contrário, 0.

### <a name="remarks"></a>Comentários

Um filtro de mensagem não tem efeito a menos que seja registrado nos DLLs do sistema. Normalmente, o código de inicialização do aplicativo registra o filtro de mensagens do aplicativo. Qualquer outro filtro de mensagem registrado pelo seu aplicativo deve ser revogado antes que o programa termine por uma chamada para [Revogar](#revoke).

O filtro de mensagem padrão do framework é automaticamente registrado durante a inicialização e revogado na rescisão.

## <a name="colemessagefilterrevoke"></a><a name="revoke"></a>COleMessageFilter::Revogar

Revoga um registro prévio realizado por uma chamada para [Registrar](#register).

```cpp
void Revoke();
```

### <a name="remarks"></a>Comentários

Um filtro de mensagem deve ser revogado antes que o programa termine.

O filtro de mensagem padrão, que é criado e registrado automaticamente pelo framework, também é automaticamente revogado.

## <a name="colemessagefiltersetbusyreply"></a><a name="setbusyreply"></a>COleMessageFilter::SetBusyReply

Esta função define a "resposta ocupada" do aplicativo.

```cpp
void SetBusyReply(SERVERCALL nBusyReply);
```

### <a name="parameters"></a>Parâmetros

*nBusyReply*<br/>
Um valor `SERVERCALL` da enumeração, que é definido no COMPOBJ. H. Ele pode ter qualquer um dos seguintes valores:

- SERVERCALL_ISHANDLED O aplicativo pode aceitar chamadas, mas pode falhar no processamento de uma determinada chamada.

- SERVERCALL_REJECTED O aplicativo provavelmente nunca será capaz de processar uma chamada.

- SERVERCALL_RETRYLATER O aplicativo está temporariamente em um estado no qual não pode processar uma chamada.

### <a name="remarks"></a>Comentários

As funções [BeginBusyState](#beginbusystate) e [EndBusyState](#endbusystate) controlam o estado ocupado do aplicativo.

Quando um aplicativo é feito ocupado `BeginBusyState`com uma chamada para , ele responde a chamadas dos DLLs do sistema OLE com um valor determinado pela última configuração de `SetBusyReply`. O aplicativo de chamada usa essa resposta ocupada para determinar que ação tomar.

Por padrão, a resposta ocupada é SERVERCALL_RETRYLATER. Esta resposta faz com que o aplicativo de chamada tente novamente a chamada o mais rápido possível.

## <a name="colemessagefiltersetmessagependingdelay"></a><a name="setmessagependingdelay"></a>COleMessageFilter::SetMessagePendingDelay

Determina quanto tempo o aplicativo de chamada espera por uma resposta do aplicativo chamado antes de tomar outras medidas.

```cpp
void SetMessagePendingDelay(DWORD nTimeout = 5000);
```

### <a name="parameters"></a>Parâmetros

*nTimeout*<br/>
Número de milissegundos para o atraso pendente de mensagem.

### <a name="remarks"></a>Comentários

Esta função funciona em conjunto com [SetRetryReply](#setretryreply).

## <a name="colemessagefiltersetretryreply"></a><a name="setretryreply"></a>COleMessageFilter::SetRetryReply

Determina a ação do aplicativo de chamada quando recebe uma resposta ocupada de um aplicativo chamado.

```cpp
void SetRetryReply(DWORD nRetryReply = 0);
```

### <a name="parameters"></a>Parâmetros

*nRetryReply*<br/>
Número de milissegundos entre tentativas.

### <a name="remarks"></a>Comentários

Quando um aplicativo chamado indica que está ocupado, o aplicativo de chamada pode decidir esperar até que o servidor não esteja mais ocupado, para tentar novamente imediatamente ou para tentar novamente após um intervalo especificado. Também pode decidir cancelar a chamada completamente.

A resposta do chamador é `SetRetryReply` controlada pelas funções e [setMessagePendingDelay](#setmessagependingdelay). `SetRetryReply`determina quanto tempo o aplicativo de chamada deve esperar entre tentativas de uma determinada chamada. `SetMessagePendingDelay`determina quanto tempo o aplicativo de chamada espera por uma resposta do servidor antes de tomar novas medidas.

Normalmente os padrões são aceitáveis e não precisam ser alterados. A estrutura tenta novamente a chamada a cada *milissegundos de nRetryReply* até que a chamada seja terminada ou o atraso pendente de mensagem tenha expirado. Um valor de 0 para *nRetryReply* especifica uma repetição imediata e - 1 especifica o cancelamento da chamada.

Quando o atraso pendente de mensagem expirar, a "caixa de diálogo ocupada" oLE (ver [COleBusyDialog](../../mfc/reference/colebusydialog-class.md)) é exibida para que o usuário possa cancelar ou tentar novamente a chamada. Chamada [AtivarDiálogo ocupado](#enablebusydialog) para ativar ou desativar esta caixa de diálogo.

Quando uma mensagem de teclado ou mouse está pendente durante uma chamada e a chamada é cronometrada (excedeu o atraso pendente de mensagem), a caixa de diálogo "não respondendo" é exibida. Chamada [AtivarNãoresponderDiálogo](#enablenotrespondingdialog) para ativar ou desativar esta caixa de diálogo. Geralmente esse estado de coisas indica que algo deu errado e o usuário está ficando impaciente.

Quando as diálogos são desativadas, a "resposta de repetição" atual é sempre usada para chamadas para aplicativos ocupados.

## <a name="see-also"></a>Confira também

[Classe CCmdTarget](../../mfc/reference/ccmdtarget-class.md)<br/>
[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classe CCmdTarget](../../mfc/reference/ccmdtarget-class.md)
