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
ms.openlocfilehash: fbf2d834163199107aae44bd5723ceff79e36f91
ms.sourcegitcommit: fcb48824f9ca24b1f8bd37d647a4d592de1cc925
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/15/2019
ms.locfileid: "69506684"
---
# <a name="cevent-class"></a>Classe CEvent

Representa um evento, que é um objeto de sincronização que permite que um thread notifique outro que ocorreu um evento.

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
|[CEvent::PulseEvent](#pulseevent)|Define o evento como disponível (sinalizado), libera threads em espera e define o evento como indisponível (não sinalizado).|
|[CEvent::ResetEvent](#resetevent)|Define o evento como indisponível (não sinalizado).|
|[CEvent::SetEvent](#setevent)|Define o evento como disponível (sinalizado) e libera todos os threads em espera.|
|[CEvent::Unlock](#unlock)|Libera o objeto de evento.|

## <a name="remarks"></a>Comentários

Os eventos são úteis quando um thread deve saber quando executar sua tarefa. Por exemplo, um thread que copia dados para um arquivo de dados deve ser notificado quando novos dados estiverem disponíveis. Usando um `CEvent` objeto para notificar o thread de cópia quando novos dados estão disponíveis, o thread pode executar sua tarefa assim que possível.

`CEvent`os objetos têm dois tipos: manual e automático.

Um objeto `CEvent` automático retorna automaticamente para um estado não sinalizado (não disponível) após o lançamento de pelo menos um thread. Por padrão, um `CEvent` objeto é automático, a menos `TRUE` que você passe para o parâmetro *bManualReset* durante a construção.

Um objeto `CEvent` manual permanece no estado definido por [SetEvent](#setevent) ou [ResetEvent](#resetevent) até que a outra função seja chamada. Para criar um objeto `CEvent` manual, passe `TRUE` para o `bManualReset` parâmetro durante a construção.

Para usar um `CEvent` objeto, construa o `CEvent` objeto quando ele for necessário. Especifique o nome do evento que você deseja aguardar e especifique também que seu aplicativo deve ser proprietário inicialmente. Em seguida, você pode acessar o evento quando o Construtor retornar. Chame [SetEvent](#setevent) para sinalizar (tornar disponível) o objeto de evento e, em seguida, chame [Unlock](#unlock) quando terminar de acessar o recurso controlado.

Um método alternativo para usar `CEvent` objetos é adicionar uma variável do tipo `CEvent` como um membro de dados à classe que você deseja controlar. Durante a construção do objeto controlado, chame o construtor do membro `CEvent` de dados e especifique se o evento é inicialmente sinalizado e também specifythe tipo de objeto de evento que você deseja, o nome do evento (se ele será usado em todo o processo limites) e todos os atributos de segurança desejados.

Para acessar um recurso controlado por um `CEvent` objeto dessa maneira, primeiro crie uma variável de um dos tipos [CSingleLock](../../mfc/reference/csinglelock-class.md) ou digite [CMultiLock](../../mfc/reference/cmultilock-class.md) no método de acesso do recurso. Em seguida, `Lock` chame o método do objeto de bloqueio (por exemplo, [CMultiLock:: Lock](../../mfc/reference/cmultilock-class.md#lock)). Neste ponto, seu thread obterá acesso ao recurso, aguardará que o recurso seja liberado e obterá acesso, ou aguardará o recurso ser liberado, atingirá o tempo limite e falhará ao obter acesso ao recurso. Em qualquer caso, o recurso foi acessado de forma segura para thread. Para liberar o recurso, chame `SetEvent` para sinalizar o objeto de evento e, em `Unlock` seguida, use o método do objeto de bloqueio (por exemplo, [CMultiLock:: Unlock](../../mfc/reference/cmultilock-class.md#unlock)) ou deixe o objeto de bloqueio ficar fora do escopo.

Para obter mais informações sobre como usar `CEvent` objetos, consulte [multithreading: Como usar as classes](../../parallel/multithreading-how-to-use-the-synchronization-classes.md)de sincronização.

## <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_Utilities#45](../../mfc/codesnippet/cpp/cevent-class_1.cpp)]

[!code-cpp[NVC_MFC_Utilities#46](../../mfc/codesnippet/cpp/cevent-class_2.cpp)]

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[CObject](../../mfc/reference/cobject-class.md)

[CSyncObject](../../mfc/reference/csyncobject-class.md)

`CEvent`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxmt. h

##  <a name="cevent"></a>CEvent::CEvent

Constrói um `CEvent` objeto nomeado ou sem nome.

```
CEvent(
    BOOL bInitiallyOwn = FALSE,
    BOOL bManualReset = FALSE,
    LPCTSTR lpszName = NULL,
    LPSECURITY_ATTRIBUTES lpsaAttribute = NULL);
```

### <a name="parameters"></a>Parâmetros

*bInitiallyOwn*<br/>
Se for true, o thread para `CMultilock` o `CSingleLock` objeto ou será habilitado. Caso contrário, todos os threads que desejam acessar o recurso devem aguardar.

*bManualReset*<br/>
Se for TRUE, especifica que o objeto de evento é um evento manual, caso contrário, o objeto de evento será um evento automático.

*lpszName*<br/>
Nome do objeto de `CEvent` . Deverá ser fornecido se o objeto for usado em limites de processo. Se o nome corresponder a um evento existente, o Construtor criará `CEvent` um novo objeto que faz referência ao evento desse nome. Se o nome corresponder a um objeto de sincronização existente que não é um evento, a construção falhará. Se for NULL, o nome será NULL.

*lpsaAttribute*<br/>
Atributos de segurança para o objeto de evento. Para obter uma descrição completa dessa estrutura, consulte [SECURITY_ATTRIBUTES](/previous-versions/windows/desktop/legacy/aa379560\(v=vs.85\)) no SDK do Windows.

### <a name="remarks"></a>Comentários

Para acessar ou liberar um `CEvent` objeto, crie um objeto [CMultiLock](../../mfc/reference/cmultilock-class.md) ou [CSingleLock](../../mfc/reference/csinglelock-class.md) e chame suas funções de membro [Lock](../../mfc/reference/csinglelock-class.md#lock) e [Unlock](../../mfc/reference/csinglelock-class.md#unlock) .

Para alterar o estado de um `CEvent` objeto para sinalizado (os threads não precisam esperar), chame [SetEvent](#setevent) ou [PulseEvent](#pulseevent). Para definir o estado de um `CEvent` objeto como não sinalizado (os threads devem aguardar), chame [ResetEvent](#resetevent).

> [!IMPORTANT]
>  Depois de criar `CEvent` o objeto, use [GetLastError](/windows/win32/api/errhandlingapi/nf-errhandlingapi-getlasterror) para garantir que o mutex ainda não exista. Se o mutex existia inesperadamente, ele pode indicar que um processo não autorizado é de apropriação indevida e pode estar pretendendo usar o mutex de forma mal-intencionada. Nesse caso, o procedimento de consciência de segurança recomendado é fechar a alça e continuar como se houvesse uma falha na criação do objeto.

##  <a name="pulseevent"></a>  CEvent::PulseEvent

Define o estado do evento a ser sinalizado (disponível), libera todos os threads em espera e os redefine para não sinalizado (não disponível) automaticamente.

```
BOOL PulseEvent();
```

### <a name="return-value"></a>Valor de retorno

Diferente de zero se a função foi bem-sucedida; caso contrário, 0.

### <a name="remarks"></a>Comentários

Se o evento for manual, todos os threads em espera serão liberados, o evento será definido como não `PulseEvent` sinalizado e retornará. Se o evento for automático, um único thread será liberado, o evento será definido como não sinalizado e `PulseEvent` retornará.

Se nenhum thread estiver aguardando ou nenhum thread puder ser liberado imediatamente, `PulseEvent` o definirá o estado do evento como não sinalizado e retornará.

`PulseEvent`usa a função Win32 `PulseEvent` subjacente, que pode ser removida momentaneamente do estado de espera por uma chamada de procedimento assíncrono do modo kernel. Portanto, `PulseEvent` o não é confiável e não deve ser usado por novos aplicativos. Para obter mais informações, consulte a [função PulseEvent](/windows/win32/api/winbase/nf-winbase-pulseevent).

##  <a name="resetevent"></a>  CEvent::ResetEvent

Define o estado do evento como não sinalizado até que explicitamente definido como sinalizado pela função [de membro](#setevent) do.

```
BOOL ResetEvent();
```

### <a name="return-value"></a>Valor de retorno

Diferente de zero se a função foi bem-sucedida; caso contrário, 0.

### <a name="remarks"></a>Comentários

Isso faz com que todos os threads que desejam acessar esse evento aguardem.

Essa função de membro não é usada por eventos automáticos.

##  <a name="setevent"></a>  CEvent::SetEvent

Define o estado do evento a ser sinalizado, liberando todos os threads em espera.

```
BOOL SetEvent();
```

### <a name="return-value"></a>Valor de retorno

Diferente de zero se a função foi bem-sucedida, caso contrário, 0.

### <a name="remarks"></a>Comentários

Se o evento for manual, o evento permanecerá sinalizado até que [ResetEvent](#resetevent) seja chamado. Mais de um thread pode ser liberado nesse caso. Se o evento for automático, o evento permanecerá sinalizado até que um único thread seja liberado. Em seguida, o sistema definirá o estado do evento como não sinalizado. Se nenhum thread estiver aguardando, o estado permanecerá sinalizado até que um thread seja liberado.

##  <a name="unlock"></a>CEvent:: desbloquear

Libera o objeto de evento.

```
BOOL Unlock();
```

### <a name="return-value"></a>Valor de retorno

Diferente de zero se o thread pertencer ao objeto de evento e o evento for um evento automático; caso contrário, 0.

### <a name="remarks"></a>Comentários

Essa função de membro é chamada por threads que atualmente possuem um evento automático para liberá-lo depois que eles forem concluídos, se o objeto de bloqueio for reutilizado. Se o objeto de bloqueio não for reutilizado, essa função será chamada pelo destruidor do objeto de bloqueio.

## <a name="see-also"></a>Consulte também

[Classe CSyncObject](../../mfc/reference/csyncobject-class.md)<br/>
[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)
