---
title: "Classe de CTimeSpan | Microsoft Docs"
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
  - "ATL.CTimeSpan"
  - "CTimeSpan"
  - "timespan"
  - "ATL::CTimeSpan"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe de CTimeSpan"
  - "o tempo decorrido, Objeto de CTimeSpan"
  - "classes compartilhadas, CTimeSpan"
  - "intervalo de tempo"
  - "time, decorrido"
  - "período"
ms.assetid: ee1e42f6-1839-477a-8435-fb26ad475140
caps.latest.revision: 17
caps.handback.revision: 8
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe de CTimeSpan
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Uma quantidade de tempo que sejam armazenadas internamente, como o número de segundos no intervalo de tempo.  
  
## Sintaxe  
  
```  
class CTimeSpan  
```  
  
## Membros  
  
### Construtores public  
  
|Nome|Descrição|  
|----------|---------------|  
|[CTimeSpan::CTimeSpan](../Topic/CTimeSpan::CTimeSpan.md)|Constrói objetos de `CTimeSpan` de várias maneiras.|  
  
### Métodos públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[CTimeSpan::Format](../Topic/CTimeSpan::Format.md)|Converte `CTimeSpan` em uma cadeia de caracteres formatada.|  
|[CTimeSpan::GetDays](../Topic/CTimeSpan::GetDays.md)|Retorna um valor que representa o número de dias completos em este `CTimeSpan`.|  
|[CTimeSpan::GetHours](../Topic/CTimeSpan::GetHours.md)|Retorna um valor que representa o número de hora no dia atual \(– 23 a 23\).|  
|[CTimeSpan::GetMinutes](../Topic/CTimeSpan::GetMinutes.md)|Retorna um valor que representa o número de minutos a hora atual \(– 59 a 59\).|  
|[CTimeSpan::GetSeconds](../Topic/CTimeSpan::GetSeconds.md)|Retorna um valor que representa o número de segundos no minuto do atual \(– 59 a 59\).|  
|[CTimeSpan::GetTimeSpan](../Topic/CTimeSpan::GetTimeSpan.md)|Retorna o valor do objeto de `CTimeSpan` .|  
|[CTimeSpan::GetTotalHours](../Topic/CTimeSpan::GetTotalHours.md)|Retorna um valor que representa o número total de tempo em este `CTimeSpan`completos.|  
|[CTimeSpan::GetTotalMinutes](../Topic/CTimeSpan::GetTotalMinutes.md)|Retorna um valor que representa o número de minutos inteiros em este `CTimeSpan`.|  
|[CTimeSpan::GetTotalSeconds](../Topic/CTimeSpan::GetTotalSeconds.md)|Retorna um valor que representa o número de segundos inteiros em este `CTimeSpan`.|  
|[CTimeSpan::Serialize64](../Topic/CTimeSpan::Serialize64.md)|Serializa a dados ou um arquivo neutro.|  
  
### Operadores  
  
|||  
|-|-|  
|[operador \+ –](../Topic/CTimeSpan::operator%20+,%20-.md)|Adiciona e subtrai objetos de `CTimeSpan` .|  
|[operador \+\= – \=](../Topic/CTimeSpan::operator%20+=,%20-=.md)|Adiciona e subtrai um objeto de `CTimeSpan` a e essa `CTimeSpan`.|  
|[\=\= de operador \< etc..](../Topic/CTimeSpan%20Comparison%20Operators.md)|Compara dois valores de tempo relacionados.|  
  
## Comentários  
 `CTimeSpan` não tem uma classe base.  
  
 Funções de`CTimeSpan` convertem segundos para várias combinações de dias, de tempo, de minutos, e de segundos.  
  
 O objeto de `CTimeSpan` é armazenado em uma estrutura de **\_\_time64\_t** , que é 8 bytes.  
  
 Uma classe, [CTime](../Topic/CTime%20Class.md)complementar, representa um horário absolutas.  
  
 As classes de `CTime` e de `CTimeSpan` não são criadas para a derivação.  Como não há nenhuma função virtual, o tamanho dos dois objetos de `CTime` e de `CTimeSpan` é exatamente 8 bytes.  A maioria das funções de membro são embutidas.  
  
 Para obter mais informações sobre como usar `CTimeSpan`, consulte os artigos [Data e Hora](../../atl-mfc-shared/date-and-time.md), e [Gerenciamento de tempo](../../c-runtime-library/time-management.md)*na referência da biblioteca em tempo de execução*.  
  
## Requisitos  
 **Cabeçalho:** atltime.h  
  
## Consulte também  
 [asctime, \_wasctime](../../c-runtime-library/reference/asctime-wasctime.md)   
 [\_ftime, \_ftime32, \_ftime64](../../c-runtime-library/reference/ftime-ftime32-ftime64.md)   
 [gmtime, \_gmtime32, \_gmtime64](../../c-runtime-library/reference/gmtime-gmtime32-gmtime64.md)   
 [localtime, \_localtime32, \_localtime64](../../c-runtime-library/reference/localtime-localtime32-localtime64.md)   
 [strftime, wcsftime, \_strftime\_l, \_wcsftime\_l](../../c-runtime-library/reference/strftime-wcsftime-strftime-l-wcsftime-l.md)   
 [time, \_time32, \_time64](../Topic/time,%20_time32,%20_time64.md)   
 [Gráfico da hierarquia](../../mfc/hierarchy-chart.md)   
 [ATL\/MFC compartilhasse classes](../../atl-mfc-shared/atl-mfc-shared-classes.md)