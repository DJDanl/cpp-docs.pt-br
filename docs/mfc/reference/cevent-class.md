---
title: "Classe de CEvent | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "reference"
f1_keywords: 
  - "CEvent"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe de CEvent"
  - "classes de sincronização, Classe de CEvent"
  - "objetos de sincronização, Evento "
ms.assetid: df676042-ce27-4702-800a-e73ff4f44395
caps.latest.revision: 27
caps.handback.revision: 16
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe de CEvent
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Representa um evento, que é um objeto de sincronização que permite que um segmento para notificar outros que um evento ocorreu.  
  
## Sintaxe  
  
```  
class CEvent : public CSyncObject  
```  
  
## Membros  
  
### Construtores public  
  
|Nome|Descrição|  
|----------|---------------|  
|[CEvent::CEvent](../Topic/CEvent::CEvent.md)|Constrói um objeto de `CEvent` .|  
  
### Métodos públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[CEvent::PulseEvent](../Topic/CEvent::PulseEvent.md)|Defina o evento para disponível \(sinalizar\), as versões que esperam segmentos, e define o evento para disponível \(não não sinalizado\).|  
|[CEvent::ResetEvent](../Topic/CEvent::ResetEvent.md)|Defina o evento para nonsignaled \(não disponível\).|  
|[CEvent::SetEvent](../Topic/CEvent::SetEvent.md)|Defina o evento para disponível \(sinalizar\) e para versões todos os segmentos de espera.|  
|[CEvent::Unlock](../Topic/CEvent::Unlock.md)|Libera o objeto de evento.|  
  
## Comentários  
 Os eventos são úteis quando um segmento deve saber quando executar a tarefa.  Por exemplo, um segmento que copia dados em um arquivo arquivamento de dados deve ser notificado quando novos dados estão disponíveis.  Usando um objeto de `CEvent` para notificar a cópia encadeamento de dados quando novos estão disponíveis, o segmento pode executar a tarefa o mais rápido possível.  
  
 Os objetos de`CEvent` têm dois tipos: manual e automático.  
  
 Um objeto automática de `CEvent` retorna automaticamente a um estado \(não disponível\) não sinalizado após pelo menos um segmento é liberado.  Por padrão, um objeto de `CEvent` é automática a menos que você `TRUE` passar para o parâmetro de `bManualReset` durante a compilação.  
  
 Um objeto de `CEvent` manuais fica no estado definido por [SetEvent](../Topic/CEvent::SetEvent.md) ou por [ResetEvent](../Topic/CEvent::ResetEvent.md) até que a outra função é chamada.  Para criar um objeto manual de `CEvent` , `TRUE` passar para o parâmetro de `bManualReset` durante a compilação.  
  
 Para usar um objeto de `CEvent` , construir o objeto de `CEvent` quando for necessário.  Especificar o nome do evento que você deseja aguardar no, e também especifica que o aplicativo deve possuir o inicialmente.  Você pode acessar o evento quando o construtor retorna.  Chame [SetEvent](../Topic/CEvent::SetEvent.md) para sinalizar \(disponibiliza\) o objeto de evento e chamar em [desbloquear](../Topic/CEvent::Unlock.md) quando você terminar ao acessar o recurso controlado.  
  
 Um método alternativo para usar objetos de `CEvent` é adicionar uma variável do tipo `CEvent` como um membro de dados para a classe que você deseja controlar.  Durante a compilação do objeto controlada, chamar o construtor do membro de dados de `CEvent` e especifica se o evento é sinalizado inicialmente, e também tipo de specifythe de objeto de evento que você deseja, o nome do evento \(se será usado fora dos limites de processo\), e todos os atributos de segurança você deseja.  
  
 Para acessar um recurso controlado por um objeto de `CEvent` de essa maneira, primeiro crie uma variável do tipo [CSingleLock](../../mfc/reference/csinglelock-class.md) ou digite [CMultiLock](../../mfc/reference/cmultilock-class.md) no método de acesso do recurso.  Chame o método de `Lock` do objeto de bloqueio \(por exemplo, [CMultiLock::Lock](../Topic/CMultiLock::Lock.md)\).  Em este ponto, o segmento acederá ao recurso espera, para que o recurso seja liberado e acederá, ou esperará o recurso a ser liberados, o tempo limite, e a falha obter acesso ao recurso.  Em qualquer caso, o recurso foi acessado de uma maneira segura.  Para liberar o recurso, chame `SetEvent` para sinalizar o objeto de evento em seguida, use o método de `Unlock` do objeto de bloqueio \(por exemplo, [CMultiLock::Unlock](../Topic/CMultiLock::Unlock.md)\), ou deixe o bloqueio objeto a queda fora do escopo.  
  
 Para obter mais informações sobre como usar objetos de `CEvent` , consulte [Multithread: como usar as classes de sincronização](../../parallel/multithreading-how-to-use-the-synchronization-classes.md).  
  
## Exemplo  
 [!code-cpp[NVC_MFC_Utilities#45](../../mfc/codesnippet/CPP/cevent-class_1.cpp)]  
  
 [!code-cpp[NVC_MFC_Utilities#46](../../mfc/codesnippet/CPP/cevent-class_2.cpp)]  
  
## Hierarquia de herança  
 [CObject](../Topic/CObject%20Class.md)  
  
 [CSyncObject](../../mfc/reference/csyncobject-class.md)  
  
 `CEvent`  
  
## Requisitos  
 **Cabeçalho:** afxmt.h  
  
## Consulte também  
 [Classe de CSyncObject](../../mfc/reference/csyncobject-class.md)   
 [Gráfico da hierarquia](../../mfc/hierarchy-chart.md)