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
ms.openlocfilehash: 009a17342cb92025d67bf2fe0df1b9d5c7c0c6f0
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81373954"
---
# <a name="cevent-class"></a>Classe CEvent

Representa um evento, que é um objeto de sincronização que permite que um segmento notifique outro de que ocorreu um evento.

## <a name="syntax"></a>Sintaxe

```
class CEvent : public CSyncObject
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[CEvent::CEvent](#cevent)|Constrói um objeto `CEvent`.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CEvent::PulseEvent](#pulseevent)|Define o evento como disponível (sinalizado), libera segmentos de espera e define o evento como indisponível (não sinalizado).|
|[CEvent::ResetEvent](#resetevent)|Define o evento como indisponível (não sinalizado).|
|[CEvent::SetEvent](#setevent)|Define o evento como disponível (sinalizado) e libera quaisquer roscas de espera.|
|[CEvent::Unlock](#unlock)|Libera o objeto do evento.|

## <a name="remarks"></a>Comentários

Eventos são úteis quando um segmento deve saber quando executar sua tarefa. Por exemplo, um segmento que copia dados para um arquivo de dados deve ser notificado quando novos dados estão disponíveis. Ao usar `CEvent` um objeto para notificar o segmento de cópia quando novos dados estão disponíveis, o segmento pode executar sua tarefa o mais rápido possível.

`CEvent`objetos têm dois tipos: manual e automático.

Um `CEvent` objeto automático retorna automaticamente a um estado não sinalizado (indisponível) depois que pelo menos um segmento é liberado. Por padrão, `CEvent` um objeto é `TRUE` automático a menos que você passe pelo parâmetro *bManualReset* durante a construção.

Um `CEvent` objeto manual permanece no estado definido por [SetEvent](#setevent) ou [ResetEvent](#resetevent) até que a outra função seja chamada. Para criar `CEvent` um objeto `TRUE` manual, passe para o parâmetro durante a `bManualReset` construção.

Para usar `CEvent` um objeto, construa o `CEvent` objeto quando necessário. Especifique o nome do evento que deseja aguardar e também especifique que seu aplicativo deve inicialmente possuí-lo. Em seguida, você pode acessar o evento quando o construtor retorna. Call [SetEvent](#setevent) para sinalizar (disponibilizar) o objeto do evento e, em seguida, chamar [Desbloquear](#unlock) quando você terminar de acessar o recurso controlado.

Um método alternativo `CEvent` para o uso de `CEvent` objetos é adicionar uma variável de tipo como membro de dados à classe que você deseja controlar. Durante a construção do objeto controlado, `CEvent` ligue para o construtor do membro de dados e especifique se o evento está sinalizado inicialmente, e também especifique o tipo de objeto de evento que deseja, o nome do evento (se ele será usado através dos limites do processo) e quaisquer atributos de segurança que você deseja.

Para acessar um recurso `CEvent` controlado por um objeto dessa maneira, primeiro crie uma variável do tipo [CSingleLock](../../mfc/reference/csinglelock-class.md) ou digite [CMultiLock](../../mfc/reference/cmultilock-class.md) no método de acesso do seu recurso. Em seguida, chame o `Lock` método do objeto de bloqueio (por exemplo, [CMultiLock::Lock](../../mfc/reference/cmultilock-class.md#lock)). Neste ponto, seu thread ganhará acesso ao recurso, aguardará o recurso ser liberado e terá acesso, ou esperará que o recurso seja liberado, o tempo de saída e não terá acesso ao recurso. De qualquer forma, seu recurso foi acessado de forma segura. Para liberar o `SetEvent` recurso, ligue para sinalizar o `Unlock` objeto de evento e, em seguida, use o método do objeto de bloqueio (por exemplo, [CMultiLock::Unlock),](../../mfc/reference/cmultilock-class.md#unlock)ou deixe o objeto de bloqueio cair fora do escopo.

Para obter mais informações `CEvent` sobre como usar objetos, consulte [Multithreading: Como usar as classes de sincronização](../../parallel/multithreading-how-to-use-the-synchronization-classes.md).

## <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_Utilities#45](../../mfc/codesnippet/cpp/cevent-class_1.cpp)]

[!code-cpp[NVC_MFC_Utilities#46](../../mfc/codesnippet/cpp/cevent-class_2.cpp)]

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[Cobject](../../mfc/reference/cobject-class.md)

[Csyncobject](../../mfc/reference/csyncobject-class.md)

`CEvent`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxmt.h

## <a name="ceventcevent"></a><a name="cevent"></a>CEvent::CEvent

Constrói um objeto nomeado `CEvent` ou sem nome.

```
CEvent(
    BOOL bInitiallyOwn = FALSE,
    BOOL bManualReset = FALSE,
    LPCTSTR lpszName = NULL,
    LPSECURITY_ATTRIBUTES lpsaAttribute = NULL);
```

### <a name="parameters"></a>Parâmetros

*bInicialmentePossuir*<br/>
Se TRUE, o `CMultilock` segmento `CSingleLock` para o objeto ou objeto estiver ativado. Caso contrário, todos os segmentos que desejam acessar o recurso devem esperar.

*Bmanualreset*<br/>
Se TRUE, especificar que o objeto de evento é um evento manual, caso contrário, o objeto de evento é um evento automático.

*lpszName*<br/>
Nome do objeto de `CEvent` . Deve ser fornecido se o objeto for usado através dos limites do processo. Se o nome corresponder a um evento existente, `CEvent` o construtor construirá um novo objeto que faz referência ao evento desse nome. Se o nome corresponder a um objeto de sincronização existente que não seja um evento, a construção falhará. Se NULO, o nome será nulo.

*lpsaAttribute*<br/>
Atributos de segurança para o objeto de evento. Para obter uma descrição completa desta estrutura, consulte [SECURITY_ATTRIBUTES](/previous-versions/windows/desktop/legacy/aa379560\(v=vs.85\)) no SDK do Windows.

### <a name="remarks"></a>Comentários

Para acessar ou `CEvent` liberar um objeto, crie um objeto [CMultiLock](../../mfc/reference/cmultilock-class.md) ou [CSingleLock](../../mfc/reference/csinglelock-class.md) e chame suas funções de membro [Bloquear](../../mfc/reference/csinglelock-class.md#lock) e [Desbloquear.](../../mfc/reference/csinglelock-class.md#unlock)

Para alterar o `CEvent` estado de um objeto para sinalizado (os segmentos não têm que esperar), ligue para [SetEvent](#setevent) ou [PulseEvent](#pulseevent). Para definir o `CEvent` estado de um objeto como não sinalizado (os segmentos devem esperar), chame [ResetEvent](#resetevent).

> [!IMPORTANT]
> Depois de `CEvent` criar o objeto, use [GetLastError](/windows/win32/api/errhandlingapi/nf-errhandlingapi-getlasterror) para garantir que o mutex já não existisse. Se o mutex existiu inesperadamente, pode indicar que um processo desonesto está agachado e pode estar pretendendo usar o mutex maliciosamente. Neste caso, o procedimento recomendado para a segurança é fechar a alça e continuar como se houvesse uma falha na criação do objeto.

## <a name="ceventpulseevent"></a><a name="pulseevent"></a>CEvent::PulseEvent

Define o estado do evento como sinalizado (disponível), libera quaisquer segmentos de espera e redefine-o automaticamente para não sinalizado (indisponível).

```
BOOL PulseEvent();
```

### <a name="return-value"></a>Valor retornado

Não zero se a função foi bem sucedida; caso contrário, 0.

### <a name="remarks"></a>Comentários

Se o evento for manual, todos os segmentos de espera são `PulseEvent` liberados, o evento é definido como não sinalizado e retorna. Se o evento for automático, um único segmento será liberado, `PulseEvent` o evento será definido como não sinalizado e retorna.

Se nenhum segmento estiver esperando ou nenhum segmento `PulseEvent` puder ser liberado imediatamente, define o estado do evento como não sinalizado e retorna.

`PulseEvent`usa a função Win32 `PulseEvent` subjacente, que pode ser momentaneamente removida do estado de espera por uma chamada de procedimento assíncrono no modo kernel. Portanto, `PulseEvent` não é confiável e não deve ser usado por novos aplicativos. Para obter mais informações, consulte a [função PulseEvent](/windows/win32/api/winbase/nf-winbase-pulseevent).

## <a name="ceventresetevent"></a><a name="resetevent"></a>CEvent::ResetEvent

Define o estado do evento como não sinalizado até explicitamente definido como sinalizado pela função de membro [SetEvent.](#setevent)

```
BOOL ResetEvent();
```

### <a name="return-value"></a>Valor retornado

Não zero se a função foi bem sucedida; caso contrário, 0.

### <a name="remarks"></a>Comentários

Isso faz com que todos os segmentos que desejam acessar este evento aguardem.

Esta função de membro não é usada por eventos automáticos.

## <a name="ceventsetevent"></a><a name="setevent"></a>CEvent::SetEvent

Define o estado do evento como sinalizado, liberando quaisquer roscas de espera.

```
BOOL SetEvent();
```

### <a name="return-value"></a>Valor retornado

Não zero se a função foi bem sucedida, caso contrário 0.

### <a name="remarks"></a>Comentários

Se o evento for manual, o evento permanecerá sinalizado até [que o ResetEvent](#resetevent) seja chamado. Mais de um segmento pode ser liberado neste caso. Se o evento for automático, o evento permanecerá sinalizado até que um único segmento seja liberado. Em seguida, o sistema definirá o estado do evento como não sinalizado. Se nenhum fio estiver esperando, o estado permanece sinalizado até que um fio seja liberado.

## <a name="ceventunlock"></a><a name="unlock"></a>CEvent::Unlock

Libera o objeto do evento.

```
BOOL Unlock();
```

### <a name="return-value"></a>Valor retornado

Não zero se o segmento possuísse o objeto de evento e o evento fosse um evento automático; caso contrário, 0.

### <a name="remarks"></a>Comentários

Essa função de membro é chamada por threads que atualmente possuem um evento automático para liberá-lo depois que eles são feitos, se seu objeto de bloqueio deve ser reutilizado. Se o objeto de bloqueio não for reutilizado, esta função será chamada pelo destruidor do objeto de bloqueio.

## <a name="see-also"></a>Confira também

[Classe CSyncObject](../../mfc/reference/csyncobject-class.md)<br/>
[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)
