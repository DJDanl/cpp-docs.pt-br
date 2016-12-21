---
title: "Classe de CFileTime | Microsoft Docs"
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
  - "ATL::CFileTime"
  - "CFileTime"
  - "ATL.CFileTime"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe de CFileTime"
  - "classes compartilhadas, CFileTime"
ms.assetid: 1a358a65-1383-4124-b0d4-59b026e6860f
caps.latest.revision: 18
caps.handback.revision: 9
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe de CFileTime
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Essa classe fornece métodos para gerenciar valores de data e hora associado a um arquivo.  
  
## Sintaxe  
  
```  
  
   class CFileTime :   
public FILETIME  
```  
  
## Membros  
  
### Construtores public  
  
|Nome|Descrição|  
|----------|---------------|  
|[CFileTime::CFileTime](../Topic/CFileTime::CFileTime.md)|o construtor.|  
  
### Métodos públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[CFileTime::GetCurrentTime](../Topic/CFileTime::GetCurrentTime.md)|Chamar essa função estática para recuperar um objeto de `CFileTime` que representa a data e hora atuais do sistema.|  
|[CFileTime::GetTime](../Topic/CFileTime::GetTime.md)|Chamar esse método para recuperar o horário do objeto de `CFileTime` .|  
|[CFileTime::LocalToUTC](../Topic/CFileTime::LocalToUTC.md)|Chamar esse método para converter uma hora local do arquivo a uma hora do arquivo com base no Tempo Universal Coordenado \(UTC\).|  
|[CFileTime::SetTime](../Topic/CFileTime::SetTime.md)|Chamar esse método para definir a data e hora armazenadas pelo objeto de `CFileTime` .|  
|[CFileTime::UTCToLocal](../Topic/CFileTime::UTCToLocal.md)|Chamar esse método para converter a hora com base em Tempo Universal Coordenado \(UTC\) para a hora locais de arquivo.|  
  
### Operadores públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[CFileTime::operator \-](../Topic/CFileTime::operator%20-.md)|O operador é usado para executar a subtração em um objeto de `CFileTime` ou de `CFileTimeSpan` .|  
|[CFileTime::operator\! \=](../Topic/CFileTime::operator%20!=.md)|Este operador compara dois objetos de `CFileTime` para desigualdade.|  
|[CFileTime::operator \+](../Topic/CFileTime::operator%20+.md)|O operador é usado para executar a adição de um objeto de `CFileTimeSpan` .|  
|[CFileTime::operator \+\=](../Topic/CFileTime::operator%20+=.md)|O operador é usado para executar a adição de um objeto de `CFileTimeSpan` e atribuir o resultado ao objeto atual.|  
|[CFileTime::operator \<](../Topic/CFileTime::operator%20%3C.md)|Este operador compara dois objetos de `CFileTime` para determinar o menos.|  
|[\<\= De CFileTime::operator](../Topic/CFileTime::operator%20%3C=.md)|Este operador compara dois objetos de `CFileTime` para determinar igualdade ou as menos.|  
|[CFileTime::operator \=](../Topic/CFileTime::operator%20=.md)|o operador de atribuição.|  
|[CFileTime::operator \- \=](../Topic/CFileTime::operator%20-=.md)|O operador é usado para executar a subtração em um objeto de `CFileTimeSpan` e atribuir o resultado ao objeto atual.|  
|[\=\= De CFileTime::operator](../Topic/CFileTime::operator%20==.md)|Este operador compara dois objetos de `CFileTime` para igualdade.|  
|[CFileTime::operator \>](../Topic/CFileTime::operator%20%3E.md)|Este operador compara dois objetos de `CFileTime` para determinar o maior.|  
|[\>\= De CFileTime::operator](../Topic/CFileTime::operator%20%3E=.md)|Este operador compara dois objetos de `CFileTime` para determinar igualdade ou maior.|  
  
### Constantes públicas  
  
|Nome|Descrição|  
|----------|---------------|  
|[CFileTime::Day](../Topic/CFileTime::Day.md)|Um membro de dados estáticos que armazena o número de 100 intervalos de nanossegundo que compõem um dia.|  
|[CFileTime::Hour](../Topic/CFileTime::Hour.md)|Um membro de dados estáticos que armazena o número de 100 intervalos de nanossegundo que compõem uma hora.|  
|[CFileTime::Millisecond](../Topic/CFileTime::Millisecond.md)|Um membro de dados estáticos que armazena o número de 100 intervalos de nanossegundo que compõem um milissegundo.|  
|[CFileTime::Minute](../Topic/CFileTime::Minute.md)|Um membro de dados estáticos que armazena o número de 100 intervalos de nanossegundo que compõem um minuto.|  
|[CFileTime::Second](../Topic/CFileTime::Second.md)|Um membro de dados estáticos que armazena o número de 100 intervalos de nanossegundo que compõem um segundo.|  
|[CFileTime::Week](../Topic/CFileTime::Week.md)|Um membro de dados estáticos que armazena o número de 100 intervalos de nanossegundo que compõem uma semana.|  
  
## Comentários  
 Essa classe fornece métodos para gerenciar valores de data e hora associados com a criação, acesso e a modificação de arquivos.  Os métodos e os dados de essa classe são freqüentemente usados em conjunto com objetos de `CFileTimeSpan` , que lidam com os valores de tempo relacionados.  
  
 O valor de data e tempo são armazenados como um valor de 64 bits que representa o número de intervalos de 100. nanossegundo desde o 1º de janeiro de 1601  Este é o formato do Tempo Universal Coordenado \(UTC\).  
  
 Os seguintes variáveis estáticas de membro const são fornecidos para simplificar cálculos:  
  
|Variável de membro|Número de 100 intervalos de nanossegundo|  
|------------------------|----------------------------------------------|  
|Milissegundo|10,000|  
|Segundo|\* 1.000 Milissegundos|  
|Minuto|Segundo \* 60|  
|Hora|Minuto \* 60|  
|Dia|Hora \* 24|  
|Semana|Dia \* 7|  
  
 **Observação** Nem todos os sistemas de arquivos pode hora da criação e o último do registro e nem todos os sistemas de arquivos gravar\-los da mesma forma.  Por exemplo, no sistema de arquivo FAT do Windows NT, crie tempo tem uma resolução de 10 milissegundos, o tempo de escrita têm uma resolução de 2 segundos, e hora de acesso têm uma resolução de 1 dias \(a data do access\).  Em o, última hora de acesso têm uma resolução de 1 hora.  Além de isso, hora de registros GORDOS em disco em tempo da hora local, mas de registros NTFS em disco em UTC.  Para obter mais informações, consulte [Tempo de Arquivo](http://msdn.microsoft.com/library/windows/desktop/ms724290).  
  
## Hierarquia de herança  
 `FILETIME`  
  
 `CFileTime`  
  
## Requisitos  
 **Cabeçalho:** atltime.h  
  
## Consulte também  
 [FILETIME](http://msdn.microsoft.com/library/windows/desktop/ms724284)   
 [Classe de CFileTimeSpan](../../atl-mfc-shared/reference/cfiletimespan-class.md)   
 [Gráfico da hierarquia](../../mfc/hierarchy-chart.md)   
 [ATL\/MFC compartilhasse classes](../../atl-mfc-shared/atl-mfc-shared-classes.md)