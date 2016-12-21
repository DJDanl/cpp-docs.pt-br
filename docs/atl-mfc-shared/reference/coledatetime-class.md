---
title: "Classe de COleDateTime | Microsoft Docs"
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
  - "COleDateTime"
  - "ATL.COleDateTime"
  - "ATL::COleDateTime"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe de COleDateTime"
  - "tipo de dados de Data, Encapsulamento de MFC"
  - "datas, tratamento no MFC"
  - "classes compartilhadas, COleDateTime"
  - "time, tratamento no MFC"
  - "valores hora - somente"
ms.assetid: e718f294-16ec-4649-88b6-a4dbae5178fb
caps.latest.revision: 34
caps.handback.revision: 26
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe de COleDateTime
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Encapsula o tipo de dados de `DATE` que é usado na automação OLE.  
  
## Sintaxe  
  
```  
class COleDateTime  
```  
  
## Membros  
  
### Construtores public  
  
|Nome|Descrição|  
|----------|---------------|  
|[COleDateTime::COleDateTime](../Topic/COleDateTime::COleDateTime.md)|constrói um objeto de `COleDateTime` .|  
  
### métodos públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[COleDateTime::Format](../Topic/COleDateTime::Format.md)|Produz uma representação de cadeia de caracteres formatada de um objeto de `COleDateTime` .|  
|[COleDateTime::GetAsDBTIMESTAMP](../Topic/COleDateTime::GetAsDBTIMESTAMP.md)|Chamar esse método para obter o tempo no objeto de `COleDateTime` como uma estrutura de dados de **DBTIMESTAMP** .|  
|[COleDateTime::GetAsSystemTime](../Topic/COleDateTime::GetAsSystemTime.md)|Chamar esse método para obter o tempo no objeto de `COleDateTime` como uma estrutura de dados de [SYSTEMTIME](http://msdn.microsoft.com/library/windows/desktop/ms724950) .|  
|[COleDateTime::GetAsUDATE](../Topic/COleDateTime::GetAsUDATE.md)|Chamar esse método para obter o tempo em `COleDateTime` como uma estrutura de dados de **UDATE** .|  
|[COleDateTime::GetCurrentTime](../Topic/COleDateTime::GetCurrentTime.md)|Cria um objeto de `COleDateTime` que representa a hora atual \(função de membro estático\).|  
|[COleDateTime::GetDay](../Topic/COleDateTime::GetDay.md)|Retorna o dia onde esse objeto de `COleDateTime` representa 1 \(– 31\).|  
|[COleDateTime::GetDayOfWeek](../Topic/COleDateTime::GetDayOfWeek.md)|Retorna o dia da semana onde esse objeto de `COleDateTime` representa domingo \(\= 1\).|  
|[COleDateTime::GetDayOfYear](../Topic/COleDateTime::GetDayOfYear.md)|Retorna o dia do ano onde esse objeto de `COleDateTime` representa \(1º de janeiro \= 1\).|  
|[COleDateTime::GetHour](../Topic/COleDateTime::GetHour.md)|Retorna a hora em este objeto de `COleDateTime` representa 0 \(– 23\).|  
|[COleDateTime::GetMinute](../Topic/COleDateTime::GetMinute.md)|Retorna o minuto onde esse objeto de `COleDateTime` representa 0 \(– 59\).|  
|[COleDateTime::GetMonth](../Topic/COleDateTime::GetMonth.md)|Retorna o mês que este objeto de `COleDateTime` representa 1 \(– 12\).|  
|[COleDateTime::GetSecond](../Topic/COleDateTime::GetSecond.md)|Retorna o segundo este objeto de `COleDateTime` representa 0 \(– 59\).|  
|[COleDateTime::GetStatus](../Topic/COleDateTime::GetStatus.md)|Obtém o status \(\) validade de esse objeto de `COleDateTime` .|  
|[COleDateTime::GetYear](../Topic/COleDateTime::GetYear.md)|Retorna o ano onde esse objeto de `COleDateTime` representa.|  
|[COleDateTime::ParseDateTime](../Topic/COleDateTime::ParseDateTime.md)|Ler um valor de data\/hora de uma cadeia de caracteres e defina o valor de `COleDateTime`.|  
|[COleDateTime::SetDate](../Topic/COleDateTime::SetDate.md)|Defina o valor de esse objeto de `COleDateTime` para o valor especificado de data \- somente.|  
|[COleDateTime::SetDateTime](../Topic/COleDateTime::SetDateTime.md)|Defina o valor de esse objeto de `COleDateTime` para o valor especificado de data\/hora.|  
|[COleDateTime::SetStatus](../Topic/COleDateTime::SetStatus.md)|Define o status \(\) validade de esse objeto de `COleDateTime` .|  
|[COleDateTime::SetTime](../Topic/COleDateTime::SetTime.md)|Defina o valor de esse objeto de `COleDateTime` para o valor especificado hora somente.|  
  
### operadores públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[\=\= De COleDateTime::operator, COleDateTime::operator \<, etc..](../Topic/COleDateTime%20Relational%20Operators.md)|compare dois valores de `COleDateTime` .|  
|[COleDateTime::operator \+, \- COleDateTime::operator](../Topic/COleDateTime::operator%20+,%20-.md)|Adicionar ou subtrair valores de `COleDateTime` .|  
|[COleDateTime::operator \+\=, COleDateTime::operator \- \=](../Topic/COleDateTime::operator%20+=,%20-=.md)|Adicionar ou subtrair um valor de `COleDateTime` de esse objeto de `COleDateTime` .|  
|[COleDateTime::operator \=](../Topic/COleDateTime::operator%20=.md)|copia um valor de `COleDateTime` .|  
|[DATA de COleDateTime::operator, COleDateTime::operator Date\*](../Topic/COleDateTime::operator%20DATE.md)|Converter um valor de `COleDateTime` em `DATE` ou em `DATE*`.|  
  
### Membros públicos de dados  
  
|Nome|Descrição|  
|----------|---------------|  
|[COleDateTime::m\_dt](../Topic/COleDateTime::m_dt.md)|Contém **DATA** subjacente para este objeto de `COleDateTime` .|  
|[COleDateTime::m\_status](../Topic/COleDateTime::m_status.md)|Contém o status de esse objeto de `COleDateTime` .|  
  
## Comentários  
 `COleDateTime` não tem uma classe base.  
  
 É um dos tipos possíveis para o tipo de dados de [VARIANTE](http://msdn.microsoft.com/pt-br/e305240e-9e11-4006-98cc-26f4932d2118) de automação OLE.  Um valor de `COleDateTime` representa um valor de data e hora absoluto.  
  
 o tipo de `DATE` é implementado como um valor de ponto flutuante.  Os dias são medidos desde o 30 de dezembro de 1899, na meia\-noite.  A tabela a seguir mostra certas datas e seus valores associados:  
  
|Date|Valor|  
|----------|-----------|  
|29 de dezembro de 1899, Meia\-noite|\-1.0|  
|29 de dezembro de 1899, M A 6.|\-1.25|  
|30 de dezembro de 1899, Meia\-noite|0.0|  
|31 de dezembro de 1899, Meia\-noite|1.0|  
|1º de janeiro de 1900, 6 AM..|2.25|  
  
> [!CAUTION]
>  Observação na tabela anterior do que embora os valores de eles se tornem negativos dia antes da meia\-noite o 30 de dezembro de 1899, valores de hora não.  Por exemplo, o 6:00 AM sempre é representado por um valor fracionário 0,25 independentemente se o número inteiro que representa o dia for positivo \(depois do 30 de dezembro de 1899\) ou negativo \(antes do 30 de dezembro de 1899\).  Isso significa que uma comparação simples de ponto flutuante classificaria erroneamente que representa o `COleDateTime` 6:00 AM em 12\/29\/1899 porque **later** de um 7:00 de representação AM no mesmo dia.  
  
 A classe trata de `COleDateTime` datas desde o 1º de janeiro, 100, 9999., até o 31 de dezembro  a classe de `COleDateTime` usa o calendário gregoriano; não suporta datas julianas.  `COleDateTime` ignora o horário de verão.  \(Consulte\) [Data e hora: Suporte de automação](../Topic/Date%20and%20Time:%20Automation%20Support.md).  
  
> [!NOTE]
>  você pode usar o formato de `%y` para recuperar um ano de dois dígitos somente por datas que começa em 1900.  Se você usar o formato de `%y` em uma data antes de 1900, o código gera uma falha AFIRMAR.  
  
 Este tipo também é usado para representar valores de data \- somente ou hora somente.  Por convenção, a data 0 \(30 de dezembro de 1899\) é usada para valores hora somente o e 00:00 de tempo \(meia\-noite\) é usada para valores de data \- somente.  
  
 Se você criar um objeto de `COleDateTime` usando uma data menor que 100, a data for aceita, mas chamadas subseqüentes a `GetYear`, `GetMonth`, `GetDay`, `GetHour`, `GetMinute`, e falha de `GetSecond` e retorne \-1.  Anteriormente, você pode usar datas de dois dígitos, mas as datas devem ser 100 ou maior em MFC 4,2 e posterior.  
  
 Para evitar problemas, especifique uma data de quatro dígitos.  Por exemplo:  
  
 [!code-cpp[NVC_ATLMFC_Utilities#1](../../atl-mfc-shared/codesnippet/CPP/coledatetime-class_1.cpp)]  
  
 Operações aritméticas básicas para os valores de `COleDateTime` usam a classe complementar [COleDateTimeSpan](../Topic/COleDateTimeSpan%20Class.md).  os valores de`COleDateTimeSpan` definem um intervalo de tempo.  A relação entre essas classes é semelhante a aquela entre [CTime](../Topic/CTime%20Class.md) e [CTimeSpan](../../atl-mfc-shared/reference/ctimespan-class.md).  
  
 Para obter mais informações sobre as classes de `COleDateTime` e de `COleDateTimeSpan` , consulte o artigo [Data e hora: Suporte de automação](../Topic/Date%20and%20Time:%20Automation%20Support.md).  
  
## Requisitos  
 **Cabeçalho:** ATLComTime.h  
  
## Consulte também  
 [Classe de COleVariant](../../mfc/reference/colevariant-class.md)   
 [Classe de CTime](../Topic/CTime%20Class.md)   
 [Classe de CTimeSpan](../../atl-mfc-shared/reference/ctimespan-class.md)   
 [Gráfico da hierarquia](../../mfc/hierarchy-chart.md)   
 [ATL\/MFC compartilhasse classes](../../atl-mfc-shared/atl-mfc-shared-classes.md)