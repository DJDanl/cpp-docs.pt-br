---
title: Classe CEvent | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- CEvent
dev_langs:
- C++
helpviewer_keywords:
- synchronization objects, event
- synchronization classes, CEvent class
- CEvent class
ms.assetid: df676042-ce27-4702-800a-e73ff4f44395
caps.latest.revision: 27
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
translationtype: Machine Translation
ms.sourcegitcommit: 040985df34f2613b4e4fae29498721aef15d50cb
ms.openlocfilehash: 9edadeec87cf04ae6166c173c65463d1509eb1d8
ms.lasthandoff: 02/25/2017

---
# <a name="cevent-class"></a>Classe CEvent
Representa um evento, que é um objeto de sincronização que permite que um thread para notificar outro que ocorreu um evento.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class CEvent : public CSyncObject  
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CEvent::CEvent](#cevent)|Constrói um objeto `CEvent`.|  
  
### <a name="public-methods"></a>Métodos Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CEvent::PulseEvent](#pulseevent)|Define o evento disponíveis (sinalizado), libera threads em espera e define o evento como indisponível (não sinalizado).|  
|[CEvent::ResetEvent](#resetevent)|Define o evento como indisponível (não sinalizado).|  
|[CEvent::SetEvent](#setevent)|Define o evento disponíveis (sinalizado) e libera os threads em espera.|  
|[CEvent::Unlock](#unlock)|Libera o objeto de evento.|  
  
## <a name="remarks"></a>Comentários  
 Eventos são úteis quando um thread deve saber quando executar a tarefa. Por exemplo, um thread que copia dados para um arquivo de dados deve ser notificado quando novos dados estão disponíveis. Usando um `CEvent` objeto para notificar o thread de cópia quando novos dados estão disponíveis, o thread pode executar sua tarefa assim que possível.  
  
 `CEvent`objetos têm dois tipos: manual e automática.  
  
 Automático `CEvent` objeto automaticamente retorna ao estado (não disponível) não sinalizado depois que pelo menos um thread é liberado. Por padrão, uma `CEvent` objeto é automático, a menos que você passe `TRUE` para o `bManualReset` parâmetro durante a construção.  
  
 Um manual `CEvent` objeto permanece no estado definido pela [SetEvent](#setevent) ou [ResetEvent](#resetevent) até que a outra função seja chamada. Para criar um manual `CEvent` de objeto, passe `TRUE` para o `bManualReset` parâmetro durante a construção.  
  
 Para usar um `CEvent` de objeto, construir o `CEvent` objeto quando ele é necessário. Especifique o nome do evento que você deseja aguardar e também especificar que seu aplicativo deve inicialmente o possui. Você pode acessar o evento quando o construtor retorna. Chamar [SetEvent](#setevent) ao sinal (disponibilizar) o objeto de evento e em seguida, chame [Unlock](#unlock) quando você terminar o acesso ao recurso controlado.  
  
 Um método alternativo para o uso de `CEvent` objetos é adicionar uma variável do tipo `CEvent` como um membro de dados para a classe que você deseja controlar. Durante a construção do objeto controlado, chame o construtor do `CEvent` membro de dados e especificar se o evento é sinalizado inicialmente e specifythe tipo do objeto de evento desejado, o nome do evento (se ele será usado nos limites do processo), e os atributos de segurança desejado.  
  
 Para acessar um recurso controlado por um `CEvent` objeto dessa maneira, primeiro crie uma variável de qualquer tipo [CSingleLock](../../mfc/reference/csinglelock-class.md) ou tipo [CMultiLock](../../mfc/reference/cmultilock-class.md) no método de acesso do recurso. Em seguida, chame o `Lock` método do objeto de bloqueio (por exemplo, [CMultiLock::Lock](../../mfc/reference/cmultilock-class.md#lock)). Neste ponto, o thread será obter acesso ao recurso, aguarde o recurso a ser lançado e obter acesso ou aguarde o recurso a ser lançado, tempo limite e falha obter acesso ao recurso. Em qualquer caso, o recurso foi acessado de forma segura para thread. Para liberar o recurso, chame `SetEvent` para sinalizar o objeto de evento e, em seguida, usar o `Unlock` método do objeto de bloqueio (por exemplo, [CMultiLock::Unlock](../../mfc/reference/cmultilock-class.md#unlock)), ou permitir que o objeto de bloqueio estão fora do escopo.  
  
 Para obter mais informações sobre como usar `CEvent` objetos, consulte [Multithreading: como usar as Classes de sincronização](../../parallel/multithreading-how-to-use-the-synchronization-classes.md).  
  
## <a name="example"></a>Exemplo  
 [!code-cpp[45 NVC_MFC_Utilities](../../mfc/codesnippet/cpp/cevent-class_1.cpp)]  
  
 [!code-cpp[46 NVC_MFC_Utilities](../../mfc/codesnippet/cpp/cevent-class_2.cpp)]  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 [CObject](../../mfc/reference/cobject-class.md)  
  
 [CSyncObject](../../mfc/reference/csyncobject-class.md)  
  
 `CEvent`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxmt.h  
  
##  <a name="a-nameceventa--ceventcevent"></a><a name="cevent"></a>CEvent::CEvent  
 Constrói um nome ou sem nome `CEvent` objeto.  
  
```  
CEvent(
    BOOL bInitiallyOwn = FALSE,  
    BOOL bManualReset = FALSE,  
    LPCTSTR lpszName = NULL,  
    LPSECURITY_ATTRIBUTES lpsaAttribute = NULL);
```  
  
### <a name="parameters"></a>Parâmetros  
 `bInitiallyOwn`  
 Se **TRUE**, o thread para o **CMultilock** ou `CSingleLock` objeto está habilitado. Caso contrário, todos os threads que desejam acessar o recurso devem esperar.  
  
 *bManualReset*  
 Se **TRUE**, especifica que o objeto de evento é um evento manual, caso contrário, o objeto de evento é um evento automático.  
  
 `lpszName`  
 Nome do objeto de `CEvent` . Deve ser fornecido se o objeto será usado nos limites do processo. Se o nome corresponde a um evento existente, o construtor cria um novo `CEvent` objeto que referencia o evento desse nome. Se o nome corresponde a um objeto de sincronização existente que não é um evento, a construção falhará. Se **nulo**, o nome será nulo.  
  
 `lpsaAttribute`  
 Atributos de segurança para o objeto de evento. Para obter uma descrição completa dessa estrutura, consulte [SECURITY_ATTRIBUTES](http://msdn.microsoft.com/library/windows/desktop/aa379560) no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
### <a name="remarks"></a>Comentários  
 Para acessar ou liberar um `CEvent` de objeto, criar um [CMultiLock](../../mfc/reference/cmultilock-class.md) ou [CSingleLock](../../mfc/reference/csinglelock-class.md) objeto e chamar seu [bloqueio](../../mfc/reference/csinglelock-class.md#lock) e [Unlock](../../mfc/reference/csinglelock-class.md#unlock) funções de membro.  
  
 Para alterar o estado de um `CEvent` objeto sinalizado (threads não precisam esperar), chame [SetEvent](#setevent) ou [PulseEvent](#pulseevent). Para definir o estado de um `CEvent` objeto sinalizado (segmentos devem aguardar), chame [ResetEvent](#resetevent).  
  
> [!IMPORTANT]
>  Depois de criar o `CEvent` de objeto, use [GetLastError](http://msdn.microsoft.com/library/windows/desktop/ms679360) para garantir que o mutex não existe. Se o mutex existia inesperadamente, isso pode indicar um processo não autorizado é apropriação indevida e pode ser pretende usar o mutex de maneira mal-intencionada. Nesse caso, o procedimento sensível à segurança recomendado é fechar o identificador e continuará como se houve uma falha na criação do objeto.  
  
##  <a name="a-namepulseeventa--ceventpulseevent"></a><a name="pulseevent"></a>CEvent::PulseEvent  
 Define o estado do evento para sinalizar (disponível), libera os threads em espera e ela não sinalizado (não disponível) é redefinido automaticamente.  
  
```  
BOOL PulseEvent();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se a função foi bem-sucedida; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Se o evento for manual, todos os threads em espera forem lançados, o evento é definido para não sinalizado e `PulseEvent` retorna. Se o evento for automático, um único thread é liberado, o evento é definido para não sinalizado e `PulseEvent` retorna.  
  
 Se nenhum segmento estiver aguardando, ou nenhum thread pode ser liberado imediatamente, `PulseEvent` define o estado do evento a ser sinalizado e a retorna.  
  
 `PulseEvent`usa o Win32 subjacente `PulseEvent` função, que pode ser momentaneamente removida do estado de espera por uma chamada de procedimento assíncrona de modo kernel. Portanto, `PulseEvent` não é confiável e não deve ser usado por aplicativos novos. Para obter mais informações, consulte o [PulseEvent função](http://msdn.microsoft.com/library/windows/desktop/ms684914).  
  
##  <a name="a-namereseteventa--ceventresetevent"></a><a name="resetevent"></a>CEvent::ResetEvent  
 Define o estado do evento para não sinalizado até à sinalizado por definir explicitamente o [SetEvent](#setevent) função de membro.  
  
```  
BOOL ResetEvent();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se a função foi bem-sucedida; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Isso faz com que todos os threads que desejam acessar esse evento de espera.  
  
 Essa função de membro não é usada pelos eventos automática.  
  
##  <a name="a-nameseteventa--ceventsetevent"></a><a name="setevent"></a>CEvent::SetEvent  
 Define o estado do evento a ser sinalizado, liberando os threads em espera.  
  
```  
BOOL SetEvent();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se a função foi bem-sucedida, caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Se o evento for manual, o evento permanecerá sinalizado até [ResetEvent](#resetevent) é chamado. Mais de um thread pode ser liberado nesse caso. Se o evento for automático, o evento permanecerá sinalizado até que um único thread seja liberado. O sistema, em seguida, definirá o estado do evento para não sinalizado. Se nenhum segmento estiver aguardando, o estado permanece sinalizado até que um thread seja liberado.  
  
##  <a name="a-nameunlocka--ceventunlock"></a><a name="unlock"></a>CEvent::Unlock  
 Libera o objeto de evento.  
  
```  
BOOL Unlock();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se o segmento proprietário do objeto de evento e o evento for um evento automático. Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Essa função de membro é chamada por threads que atualmente possuem um evento automática para liberá-lo depois de terminar, se seu objeto de bloqueio deve ser reutilizado. Se o objeto de bloqueio não precisarem ser reutilizado, essa função será chamada pelo destruidor do objeto de bloqueio.  
  
## <a name="see-also"></a>Consulte também  
 [Classe CSyncObject](../../mfc/reference/csyncobject-class.md)   
 [Gráfico de hierarquia](../../mfc/hierarchy-chart.md)


