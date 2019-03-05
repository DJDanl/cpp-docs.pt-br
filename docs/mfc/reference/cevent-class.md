---
title: Classe CEvent
ms.date: 11/04/2016
f1_keywords:
- CEvent
- AFXMT/CEvent
- AFXMT/CEvent::CEvent
- AFXMT/CEvent::PulseEvent
- AFXMT/CEvent::ResetEvent
- AFXMT/CEvent::SetEvent
- AFXMT/CEvent::Unlock
helpviewer_keywords:
- CEvent [MFC], CEvent
- CEvent [MFC], PulseEvent
- CEvent [MFC], ResetEvent
- CEvent [MFC], SetEvent
- CEvent [MFC], Unlock
ms.assetid: df676042-ce27-4702-800a-e73ff4f44395
ms.openlocfilehash: d7731c87c6d6b0ebdec9a0c72c24b04334aa0662
ms.sourcegitcommit: c3093251193944840e3d0a068ecc30e6449624ba
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/04/2019
ms.locfileid: "57300265"
---
# <a name="cevent-class"></a>Classe CEvent

Representa um evento, que é um objeto de sincronização que permite que um thread notifique outro que ocorreu um evento.

## <a name="syntax"></a>Sintaxe

```
class CEvent : public CSyncObject
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores Públicos

|Nome|Descrição|
|----------|-----------------|
|[CEvent::CEvent](#cevent)|Constrói um objeto `CEvent`.|

### <a name="public-methods"></a>Métodos Públicos

|Nome|Descrição|
|----------|-----------------|
|[CEvent::PulseEvent](#pulseevent)|Define o evento disponível (sinalizado), libera threads em espera e define o evento como não disponível (como não sinalizado).|
|[CEvent::ResetEvent](#resetevent)|Define o evento como indisponível (não sinalizado).|
|[CEvent::SetEvent](#setevent)|Define o evento como disponíveis (sinalizado) e libera quaisquer threads em espera.|
|[CEvent::Unlock](#unlock)|Libera o objeto de evento.|

## <a name="remarks"></a>Comentários

Eventos são úteis quando um thread deve saber quando realizar sua tarefa. Por exemplo, um thread que copia dados para um arquivo de dados deve ser notificado quando novos dados estão disponíveis. Usando um `CEvent` objeto notifique o thread de cópia quando novos dados estão disponíveis, o thread pode executar sua tarefa assim que possível.

`CEvent` objetos têm dois tipos: manual e automático.

Automático `CEvent` objeto retorna automaticamente para um estado não sinalizado para (não disponível) após o lançamento de pelo menos um thread. Por padrão, uma `CEvent` objeto é automático, a menos que você passar `TRUE` para o *bManualReset* parâmetro durante a construção.

Um manual `CEvent` objeto permanece no estado definido por [SetEvent](#setevent) ou [ResetEvent](#resetevent) até que a outra função seja chamada. Para criar um manual `CEvent` do objeto, passe `TRUE` para o `bManualReset` parâmetro durante a construção.

Para usar um `CEvent` do objeto, construa o `CEvent` objeto quando ele for necessário. Especifique o nome do evento que você deseja esperar e também especificar que seu aplicativo deve inicialmente o possui. Em seguida, você pode acessar o evento quando o construtor retorna. Chame [SetEvent](#setevent) ao sinal (tornar disponível) o objeto de evento e em seguida, chame [Unlock](#unlock) quando você terminar o acesso ao recurso controlado.

Um método alternativo para usar `CEvent` objetos é adicionar uma variável do tipo `CEvent` como um membro de dados para a classe que você deseja controlar. Durante a construção do objeto controlado, chame o construtor do `CEvent` membro de dados e especificar o evento é sinalizado inicialmente e também specifythe tipo de objeto de evento que deseja, o nome do evento (se ele será usado pelo processo limites) e quaisquer atributos de segurança que você deseja.

Para acessar um recurso controlado por um `CEvent` objeto dessa maneira, primeiro crie uma variável do tipo [CSingleLock](../../mfc/reference/csinglelock-class.md) ou o tipo [CMultiLock](../../mfc/reference/cmultilock-class.md) no método de acesso do recurso. Em seguida, chame o `Lock` método do objeto de bloqueio (por exemplo, [CMultiLock::Lock](../../mfc/reference/cmultilock-class.md#lock)). Neste ponto, o thread será obter acesso ao recurso, aguarde até que o recurso a ser lançado e obter acesso ou aguarde até que o recurso seja liberado, tempo limite e não conseguir acessar o recurso. Em qualquer caso, o recurso tiver sido acessado de forma thread-safe. Para liberar o recurso, chame `SetEvent` sinalizar o objeto de evento e, em seguida, usar o `Unlock` método do objeto de bloqueio (por exemplo, [CMultiLock::Unlock](../../mfc/reference/cmultilock-class.md#unlock)), ou permitir que o objeto de bloqueio estão fora de escopo.

Para obter mais informações sobre como usar `CEvent` objetos, consulte [Multithreading: Como usar as Classes de sincronização](../../parallel/multithreading-how-to-use-the-synchronization-classes.md).

## <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_Utilities#45](../../mfc/codesnippet/cpp/cevent-class_1.cpp)]

[!code-cpp[NVC_MFC_Utilities#46](../../mfc/codesnippet/cpp/cevent-class_2.cpp)]

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[CObject](../../mfc/reference/cobject-class.md)

[CSyncObject](../../mfc/reference/csyncobject-class.md)

`CEvent`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxmt.h

##  <a name="cevent"></a>  CEvent::CEvent

Constrói um nomeado ou sem nome `CEvent` objeto.

```
CEvent(
    BOOL bInitiallyOwn = FALSE,
    BOOL bManualReset = FALSE,
    LPCTSTR lpszName = NULL,
    LPSECURITY_ATTRIBUTES lpsaAttribute = NULL);
```

### <a name="parameters"></a>Parâmetros

*bInitiallyOwn*<br/>
Se for TRUE, o thread para o `CMultilock` ou `CSingleLock` objeto está habilitado. Caso contrário, todos os threads que desejam acessar o recurso devem esperar.

*bManualReset*<br/>
Se for TRUE, especifica que o objeto de evento é um evento manual, caso contrário, o objeto de evento é um evento automático.

*lpszName*<br/>
Nome do objeto de `CEvent` . Deve ser fornecido se o objeto será usado em limites de processo. Se o nome corresponder a um evento existente, o construtor cria um novo `CEvent` objeto que referencia o evento desse nome. Se o nome corresponder a um objeto de sincronização existente que não é um evento, a construção falhará. Se for NULL, o nome será nulo.

*lpsaAttribute*<br/>
Atributos de segurança para o objeto de evento. Para obter uma descrição completa dessa estrutura, consulte [SECURITY_ATTRIBUTES](https://msdn.microsoft.com/library/windows/desktop/aa379560) no SDK do Windows.

### <a name="remarks"></a>Comentários

Para acessar ou liberar um `CEvent` do objeto, crie um [CMultiLock](../../mfc/reference/cmultilock-class.md) ou [CSingleLock](../../mfc/reference/csinglelock-class.md) objeto e chame seu [bloqueio](../../mfc/reference/csinglelock-class.md#lock) e [Unlock](../../mfc/reference/csinglelock-class.md#unlock) funções de membro.

Para alterar o estado de um `CEvent` objeto sinalizado (threads é preciso esperar), chame [SetEvent](#setevent) ou [PulseEvent](#pulseevent). Para definir o estado de um `CEvent` objeto como não sinalizado (segmentos devem aguardar), chame [ResetEvent](#resetevent).

> [!IMPORTANT]
>  Depois de criar o `CEvent` do objeto, use [GetLastError](https://msdn.microsoft.com/library/windows/desktop/ms679360) para garantir que o mutex já não existia. Se o mutex existia inesperadamente, isso poderá indicar um processo não autorizado é apropriação indevida e pode ser pretendendo usar o mutex de maneira mal-intencionada. Nesse caso, o procedimento recomendado de valorizam a segurança é fechar o identificador e continuará como se houve uma falha na criação do objeto.

##  <a name="pulseevent"></a>  CEvent::PulseEvent

Define o estado do evento a ser sinalizado (disponível), libera quaisquer threads em espera e ele será redefinido como não sinalizado (indisponível) automaticamente.

```
BOOL PulseEvent();
```

### <a name="return-value"></a>Valor de retorno

Diferente de zero se a função for bem-sucedida; Caso contrário, 0.

### <a name="remarks"></a>Comentários

Se o evento é manual, todos os threads em espera são lançados, o evento é definido como não sinalizado, e `PulseEvent` retorna. Se o evento é automático, um único thread é liberado, o evento é definido como não sinalizado, e `PulseEvent` retorna.

Se nenhum thread estiver aguardando, ou se nenhum thread pode ser liberado imediatamente, `PulseEvent` define o estado do evento a ser não sinalizado e retorna.

`PulseEvent` usa o Win32 subjacente `PulseEvent` função, que pode ser momentaneamente removida do estado de espera por uma chamada de procedimento assíncrona de modo kernel. Portanto, `PulseEvent` não é confiável e não deve ser usado por aplicativos novos. Para obter mais informações, consulte o [PulseEvent função](/windows/desktop/api/winbase/nf-winbase-pulseevent).

##  <a name="resetevent"></a>  CEvent::ResetEvent

Define o estado do evento a ser não sinalizado até definir explicitamente a sinalizado pelo [SetEvent](#setevent) função de membro.

```
BOOL ResetEvent();
```

### <a name="return-value"></a>Valor de retorno

Diferente de zero se a função for bem-sucedida; Caso contrário, 0.

### <a name="remarks"></a>Comentários

Isso faz com que todos os threads que desejam acessar esse evento de espera.

Essa função de membro não é usada pelos eventos automática.

##  <a name="setevent"></a>  CEvent::SetEvent

Define o estado do evento a ser sinalizado, liberando os threads em espera.

```
BOOL SetEvent();
```

### <a name="return-value"></a>Valor de retorno

Diferente de zero se a função for bem-sucedida, caso contrário, 0.

### <a name="remarks"></a>Comentários

Se o evento é manual, o evento permanece sinalizado até que [ResetEvent](#resetevent) é chamado. Mais de um thread pode ser liberado nesse caso. Se o evento é automático, o evento permanece sinalizado até que um único thread seja liberado. O sistema, em seguida, definirá o estado do evento como não sinalizado. Se nenhum thread estiver aguardando, o estado permanece sinalizado até que um thread seja liberado.

##  <a name="unlock"></a>  CEvent::Unlock

Libera o objeto de evento.

```
BOOL Unlock();
```

### <a name="return-value"></a>Valor de retorno

Diferente de zero se o objeto de evento e o evento de propriedade de thread é um evento automático; Caso contrário, 0.

### <a name="remarks"></a>Comentários

Essa função de membro é chamada por threads que atualmente possuem um evento automático para liberá-la depois que eles, se seu objeto de bloqueio é reutilizado. Se o objeto de bloqueio não é reutilizado, essa função será chamada pelo destruidor do objeto de bloqueio.

## <a name="see-also"></a>Consulte também

[Classe CSyncObject](../../mfc/reference/csyncobject-class.md)<br/>
[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)
