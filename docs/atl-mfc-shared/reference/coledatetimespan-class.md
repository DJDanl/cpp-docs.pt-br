---
title: Classe COleDateTimeSpan | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- COleDateTimeSpan
- ATLCOMTIME/ATL::COleDateTimeSpan
- ATLCOMTIME/ATL::COleDateTimeSpan::COleDateTimeSpan
- ATLCOMTIME/ATL::COleDateTimeSpan::Format
- ATLCOMTIME/ATL::COleDateTimeSpan::GetDays
- ATLCOMTIME/ATL::COleDateTimeSpan::GetHours
- ATLCOMTIME/ATL::COleDateTimeSpan::GetMinutes
- ATLCOMTIME/ATL::COleDateTimeSpan::GetSeconds
- ATLCOMTIME/ATL::COleDateTimeSpan::GetStatus
- ATLCOMTIME/ATL::COleDateTimeSpan::GetTotalDays
- ATLCOMTIME/ATL::COleDateTimeSpan::GetTotalHours
- ATLCOMTIME/ATL::COleDateTimeSpan::GetTotalMinutes
- ATLCOMTIME/ATL::COleDateTimeSpan::GetTotalSeconds
- ATLCOMTIME/ATL::COleDateTimeSpan::SetDateTimeSpan
- ATLCOMTIME/ATL::COleDateTimeSpan::SetStatus
- ATLCOMTIME/ATL::COleDateTimeSpan::m_span
- ATLCOMTIME/ATL::COleDateTimeSpan::m_status
dev_langs:
- C++
helpviewer_keywords:
- timespan
- time span
- shared classes, COleDateTimeSpan
- Date data type, MFC encapsulation of
- COleDateTimeSpan class
ms.assetid: 7441526d-a30a-4019-8fb3-3fee6f897cbe
caps.latest.revision: 19
author: mikeblome
ms.author: mblome
manager: ghogen
translation.priority.ht:
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- ru-ru
- zh-cn
- zh-tw
translation.priority.mt:
- cs-cz
- pl-pl
- pt-br
- tr-tr
translationtype: Machine Translation
ms.sourcegitcommit: 0e0c08ddc57d437c51872b5186ae3fc983bb0199
ms.openlocfilehash: 4091ca2c766d56d8398119413778af0a0405b8ab
ms.lasthandoff: 02/25/2017

---
# <a name="coledatetimespan-class"></a>Classe COleDateTimeSpan
Representa um tempo relativo, um período de tempo.  
  
## <a name="syntax"></a>Sintaxe  
  
```
class COleDateTimeSpan
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[COleDateTimeSpan::COleDateTimeSpan](#coledatetimespan)|Constrói um objeto `COleDateTimeSpan`.|  
  
### <a name="public-methods"></a>Métodos Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[COleDateTimeSpan::Format](#format)|Gera uma representação de cadeia de caracteres formatada de um `COleDateTimeSpan` objeto.|  
|[COleDateTimeSpan::GetDays](#getdays)|Retorna a parte do dia do período isso `COleDateTimeSpan` objeto representa.|  
|[COleDateTimeSpan::GetHours](#gethours)|Retorna a parte de hora da extensão isso `COleDateTimeSpan` objeto representa.|  
|[COleDateTimeSpan::GetMinutes](#getminutes)|Retorna a parte do minuto da extensão isso `COleDateTimeSpan` objeto representa.|  
|[COleDateTimeSpan::GetSeconds](#getseconds)|Retorna a segunda parte da extensão isso `COleDateTimeSpan` objeto representa.|  
|[COleDateTimeSpan::GetStatus](#getstatus)|Obtém o status (validade) deste `COleDateTimeSpan` objeto.|  
|[COleDateTimeSpan::GetTotalDays](#gettotaldays)|Retorna o número de dias isso `COleDateTimeSpan` objeto representa.|  
|[COleDateTimeSpan::GetTotalHours](#gettotalhours)|Retorna o número de horas isso `COleDateTimeSpan` objeto representa.|  
|[COleDateTimeSpan::GetTotalMinutes](#gettotalminutes)|Retorna o número de minutos isso `COleDateTimeSpan` objeto representa.|  
|[COleDateTimeSpan::GetTotalSeconds](#gettotalseconds)|Retorna o número de segundos isso `COleDateTimeSpan` objeto representa.|  
|[COleDateTimeSpan::SetDateTimeSpan](#setdatetimespan)|Define o valor desse `COleDateTimeSpan` objeto.|  
|[COleDateTimeSpan::SetStatus](#setstatus)|Define o status (validade) deste `COleDateTimeSpan` objeto.|  
  
### <a name="public-operators"></a>Operadores públicos  
  
|||  
|-|-|  
|[operador +, -](#operator_add_-)|Adicionar, subtrair e alterar o sinal para `COleDateTimeSpan` valores.|  
|[operador + =-=](#operator_add_eq_-_eq)|Adicionar e subtrair um `COleDateTimeSpan` valor desse `COleDateTimeSpan` valor.|  
|[operador =](#operator_eq)|Copia uma `COleDateTimeSpan` valor.|  
|[operador = =,<,></,><>](#coledatetimespan_relational_operators)|Comparar dois `COleDateTimeSpan` valores.|  
|[operador double](#operator_double)|Converte isso `COleDateTimeSpan` valor para um **duplo**.|  
  
### <a name="public-data-members"></a>Membros de Dados Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[COleDateTimeSpan::m_span](#m_span)|Contém subjacente **duplo** para este `COleDateTimeSpan` objeto.|  
|[COleDateTimeSpan::m_status](#m_status)|Contém o status desse `COleDateTimeSpan` objeto.|  
  
## <a name="remarks"></a>Comentários  
 `COleDateTimeSpan`não tem uma classe base.  
  
 Um `COleDateTimeSpan` mantém o tempo em dias.  
  
 `COleDateTimeSpan`é usado com sua classe complementar [COleDateTime](../../atl-mfc-shared/reference/coledatetime-class.md). `COleDateTime`encapsula o **data** tipo de dados de automação OLE. `COleDateTime`representa os valores de tempo absoluto. Todos os `COleDateTime` envolvem cálculos `COleDateTimeSpan` valores. A relação entre essas classes é análoga entre [CTime](../../atl-mfc-shared/reference/ctime-class.md) e [CTimeSpan](../../atl-mfc-shared/reference/ctimespan-class.md).  
  
 Para obter mais informações sobre o `COleDateTime` e `COleDateTimeSpan` classes, consulte o artigo [data e hora: suporte de automação de](../../atl-mfc-shared/date-and-time-automation-support.md).  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** ATLComTime.h  
  
##  <a name="coledatetimespan_relational_operators"></a>Operadores relacionais COleDateTimeSpan  
 Operadores de comparação.  
  
```
bool operator==(const COleDateTimeSpan& dateSpan) const throw();
bool operator!=(const COleDateTimeSpan& dateSpan) const throw();
bool operator<(const COleDateTimeSpan& dateSpan) const throw();
bool operator>(const COleDateTimeSpan& dateSpan) const throw();
bool operator<=(const COleDateTimeSpan& dateSpan) const throw();
bool operator>=(const COleDateTimeSpan& dateSpan) const throw();
```  
  
### <a name="parameters"></a>Parâmetros  
 *dateSpan*  
 O `COleDateTimeSpan` para comparar.  
  
### <a name="return-value"></a>Valor de retorno  
 Esses operadores comparam dois valores de data/hora-extensão e retornar **true** se a condição for true; caso contrário **false**.  
  
### <a name="remarks"></a>Comentários  
  
> [!NOTE]
>  Um ATLASSERT ocorrerá se o operando é inválido.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[25 NVC_ATLMFC_Utilities](../../atl-mfc-shared/codesnippet/cpp/coledatetimespan-class_1.cpp)]  
  
 [!code-cpp[NVC_ATLMFC_Utilities&#26;](../../atl-mfc-shared/codesnippet/cpp/coledatetimespan-class_2.cpp)]  
  
##  <a name="coledatetimespan"></a>COleDateTimeSpan::COleDateTimeSpan  
 Constrói um objeto `COleDateTimeSpan`.  
  
```
COleDateTimeSpan() throw();
COleDateTimeSpan(double dblSpanSrc) throw();
COleDateTimeSpan(LONG lDays, int nHours, int nMins, int nSecs) throw();
```  
  
### <a name="parameters"></a>Parâmetros  
 `dblSpanSrc`  
 O número de dias a ser copiado para o novo `COleDateTimeSpan` objeto.  
  
 `lDays`, `nHours`, `nMins`, `nSecs`  
 Indique os valores de dia e hora a ser copiado para o novo `COleDateTimeSpan` objeto.  
  
### <a name="remarks"></a>Comentários  
 Todos esses construtores criar novos `COleDateTimeSpan` objetos inicializados com o valor especificado. Segue uma breve descrição de cada um desses construtores:  
  
- **(COleDateTimeSpan)** constrói uma `COleDateTimeSpan` objeto inicializado como 0.  
  
- **COleDateTimeSpan (** `dblSpanSrc` **)** constrói uma `COleDateTimeSpan` objeto a partir de um valor de ponto flutuante.  
  
- **COleDateTimeSpan (** `lDays` **,** `nHours` **,** `nMins` **,** `nSecs` **)** constrói uma `COleDateTimeSpan` objeto inicializado com os valores numéricos especificados.  
  
 O status da nova `COleDateTimeSpan` objeto é definido como válido.  
  
 Para obter mais informações sobre os limites de `COleDateTimeSpan` valores, consulte o artigo [data e hora: suporte de automação de](../../atl-mfc-shared/date-and-time-automation-support.md).  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_ATLMFC_Utilities&#14;](../../atl-mfc-shared/codesnippet/cpp/coledatetimespan-class_3.cpp)]  
  
##  <a name="format"></a>COleDateTimeSpan::Format  
 Gera uma representação de cadeia de caracteres formatada de um `COleDateTimeSpan` objeto.  
  
```
CString Format(LPCTSTR pFormat) const;
CString Format(UINT nID) const;
```  
  
### <a name="parameters"></a>Parâmetros  
 `pFormat`  
 Uma formatação de cadeia de caracteres semelhante de `printf` formatação de cadeia de caracteres. Códigos de formatação, precedidos por uma porcentagem ( `%`) entre, são substituídos por correspondente `COleDateTimeSpan` componente. Outros caracteres na cadeia de formatação são copiados inalterado de cadeia de caracteres retornada. O valor e o significado dos códigos de formatação para **formato** estão listadas abaixo:  
  
- **%H** horas do dia atual  
  
- **%M** minutos na hora atual  
  
- **%S** segundos no minuto atual  
  
- **%%**Sinal de porcentagem  
  
 Os códigos de formatação quatro listados acima são os códigos de somente formato aceitará.  
  
-  
  
 `nID`  
 A ID de recurso para a cadeia de caracteres de controle de formato.  
  
### <a name="return-value"></a>Valor de retorno  
 Um `CString` que contém o valor de data-período/formatado.  
  
### <a name="remarks"></a>Comentários  
 Chame essas funções para criar uma representação formatada do valor do período de tempo. Se o status dessa `COleDateTimeSpan` o objeto é nulo, o valor de retorno é uma cadeia de caracteres vazia. Se o status for inválido, a cadeia de caracteres de retornada é especificada pelo recurso de cadeia de caracteres **IDS_INVALID_DATETIMESPAN**.  
  
 Segue uma breve descrição dos formulários para esta função:  
  
 **Format(** `pFormat` **)**  
 Este formulário formata o valor usando a cadeia de caracteres de formato que contém códigos de formatação especial que são precedidos por um sinal de porcentagem (%), como em `printf`. A cadeia de caracteres de formatação é passada como um parâmetro para a função.  
  
 **Format(** `nID` **)**  
 Este formulário formata o valor usando a cadeia de caracteres de formato que contém códigos de formatação especial que são precedidos por um sinal de porcentagem (%), como em `printf`. A cadeia de caracteres de formatação é um recurso. A ID deste recurso de cadeia de caracteres é passada como o parâmetro.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_ATLMFC_Utilities&#15;](../../atl-mfc-shared/codesnippet/cpp/coledatetimespan-class_4.cpp)]  
  
##  <a name="getdays"></a>COleDateTimeSpan::GetDays  
 Recupera a parte desse valor de data-período/dia.  
  
```
LONG GetDays() const throw();
```  
  
### <a name="return-value"></a>Valor de retorno  
 A parte do dia desse valor de data/hora-período.  
  
### <a name="remarks"></a>Comentários  
 Valores de retorno desse intervalo de função entre aproximadamente – 3,615,000 e 3,615,000.  
  
 Para outras funções que consulta o valor de um `COleDateTimeSpan` de objeto, consulte as seguintes funções de membro:  
  
- [GetHours](#gethours)  
  
- [GetMinutes](#getminutes)  
  
- [GetSeconds](#getseconds)  
  
- [GetTotalDays](#gettotaldays)  
  
- [GetTotalHours](#gettotalhours)  
  
- [GetTotalMinutes](#gettotalminutes)  
  
- [GetTotalSeconds](#gettotalseconds)  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_ATLMFC_Utilities n º&16;](../../atl-mfc-shared/codesnippet/cpp/coledatetimespan-class_5.cpp)]  
  
##  <a name="gethours"></a>COleDateTimeSpan::GetHours  
 Recupera a parte de hora desse valor de data/hora-período.  
  
```
LONG GetHours() const throw();
```  
  
### <a name="return-value"></a>Valor de retorno  
 A parte de horas desse valor de data/hora-período.  
  
### <a name="remarks"></a>Comentários  
 Os valores de retorno desse intervalo de função entre – 23 e 23.  
  
 Para outras funções que consulta o valor de um `COleDateTimeSpan` de objeto, consulte as seguintes funções de membro:  
  
- [GetDays](#getdays)  
  
- [GetMinutes](#getminutes)  
  
- [GetSeconds](#getseconds)  
  
- [GetTotalDays](#gettotaldays)  
  
- [GetTotalHours](#gettotalhours)  
  
- [GetTotalMinutes](#gettotalminutes)  
  
- [GetTotalSeconds](#gettotalseconds)  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[17 NVC_ATLMFC_Utilities](../../atl-mfc-shared/codesnippet/cpp/coledatetimespan-class_6.cpp)]  
  
##  <a name="getminutes"></a>COleDateTimeSpan::GetMinutes  
 Recupera a parte desse valor de data/hora-intervalo de minutos.  
  
```
LONG GetMinutes() const throw();
```  
  
### <a name="return-value"></a>Valor de retorno  
 A parte de minutos desse valor de data/hora-período.  
  
### <a name="remarks"></a>Comentários  
 Os valores de retorno desse intervalo de função entre – 59 e 59.  
  
 Para outras funções que consulta o valor de um `COleDateTimeSpan` de objeto, consulte as seguintes funções de membro:  
  
- [GetDays](#getdays)  
  
- [GetHours](#gethours)  
  
- [GetSeconds](#getseconds)  
  
- [GetTotalDays](#gettotaldays)  
  
- [GetTotalHours](#gettotalhours)  
  
- [GetTotalMinutes](#gettotalminutes)  
  
- [GetTotalSeconds](#gettotalseconds)  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_ATLMFC_Utilities n º&18;](../../atl-mfc-shared/codesnippet/cpp/coledatetimespan-class_7.cpp)]  
  
##  <a name="getseconds"></a>COleDateTimeSpan::GetSeconds  
 Recupera a segunda parte deste valor de data/hora-período.  
  
```
LONG GetSeconds() const throw();
```  
  
### <a name="return-value"></a>Valor de retorno  
 A parte desse valor de data-período/segundos.  
  
### <a name="remarks"></a>Comentários  
 Os valores de retorno desse intervalo de função entre – 59 e 59.  
  
 Para outras funções que consulta o valor de um `COleDateTimeSpan` de objeto, consulte as seguintes funções de membro:  
  
- [GetDays](#getdays)  
  
- [GetHours](#gethours)  
  
- [GetMinutes](#getminutes)  
  
- [GetTotalDays](#gettotaldays)  
  
- [GetTotalHours](#gettotalhours)  
  
- [GetTotalMinutes](#gettotalminutes)  
  
- [GetTotalSeconds](#gettotalseconds)  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[19 NVC_ATLMFC_Utilities](../../atl-mfc-shared/codesnippet/cpp/coledatetimespan-class_8.cpp)]  
  
##  <a name="getstatus"></a>COleDateTimeSpan::GetStatus  
 Obtém o status (validade) deste `COleDateTimeSpan` objeto.  
  
```
DateTimeSpanStatus GetStatus() const throw();
```  
  
### <a name="return-value"></a>Valor de retorno  
 O status desse `COleDateTimeSpan` valor.  
  
### <a name="remarks"></a>Comentários  
 O valor de retorno é definido pelo **DateTimeSpanStatus** enumeração de tipo, que é definido dentro de `COleDateTimeSpan` classe.  
  
 `enum DateTimeSpanStatus{`  
  
 `valid = 0,`  
  
 `invalid = 1,`  
  
 `null = 2,`  
  
 `};`  
  
 Para obter uma breve descrição desses valores de status, consulte a lista a seguir:  
  
- **COleDateTimeSpan::valid** indica que esse `COleDateTimeSpan` objeto é válido.  
  
- **COleDateTimeSpan::invalid** indica que esse `COleDateTimeSpan` objeto é inválido; isto é, seu valor pode estar incorreto.  
  
- **COleDateTimeSpan::null** indica que esse `COleDateTimeSpan` objeto é nulo, ou seja, se nenhum valor foi fornecido para este objeto. (Isso é "null" no sentido de banco de dados de "não ter nenhum valor," em vez do C++ **nulo**.)  
  
 O status de uma `COleDateTimeSpan` objeto é inválido nos seguintes casos:  
  
-   Se esse objeto experimentou um estouro ou estouro negativo durante uma operação aritmética de atribuição, ou seja, `+=` ou `-=`.  
  
-   Se um valor inválido foi atribuído a esse objeto.  
  
-   Se o status desse objeto explicitamente definido como inválido usando `SetStatus`.  
  
 Para obter mais informações sobre as operações que podem definir o status para inválido, consulte [COleDateTimeSpan::operator +, -](../../atl-mfc-shared/reference/coledatetime-class.md#operator_add_-) e [+ = COleDateTimeSpan::operator,-=](../../atl-mfc-shared/reference/coledatetime-class.md#operator_add_eq_-_eq).  
  
 Para obter mais informações sobre os limites de `COleDateTimeSpan` valores, consulte o artigo [data e hora: suporte de automação de](../../atl-mfc-shared/date-and-time-automation-support.md).  
  
##  <a name="gettotaldays"></a>COleDateTimeSpan::GetTotalDays  
 Recupera o valor de data-período/expressado em dias.  
  
```
double GetTotalDays() const throw();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Esse valor de data/hora-intervalo expressada em dias. Embora essa função é um protótipo para retornar um valor double, sempre retornará um valor inteiro.  
  
### <a name="remarks"></a>Comentários  
 Os valores de retorno desse intervalo de função entre aproximadamente – 3.65e6 e 3.65e6.  
  
 Para outras funções que consulta o valor de um `COleDateTimeSpan` de objeto, consulte as seguintes funções de membro:  
  
- [GetDays](#getdays)  
  
- [GetHours](#gethours)  
  
- [GetMinutes](#getminutes)  
  
- [GetSeconds](#getseconds)  
  
- [GetTotalHours](#gettotalhours)  
  
- [GetTotalMinutes](#gettotalminutes)  
  
- [GetTotalSeconds](#gettotalseconds)  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[20 NVC_ATLMFC_Utilities](../../atl-mfc-shared/codesnippet/cpp/coledatetimespan-class_9.cpp)]  
  
##  <a name="gettotalhours"></a>COleDateTimeSpan::GetTotalHours  
 Recupera o valor de data-período/expressado em horas.  
  
```
double GetTotalHours() const throw();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Esse valor de data/hora-intervalo expressada em horas. Embora essa função é um protótipo para retornar um valor double, sempre retornará um valor inteiro.  
  
### <a name="remarks"></a>Comentários  
 Os valores de retorno desse intervalo de função entre aproximadamente – 8.77e7 e 8.77e7.  
  
 Para outras funções que consulta o valor de um `COleDateTimeSpan` de objeto, consulte as seguintes funções de membro:  
  
- [GetDays](#getdays)  
  
- [GetHours](#gethours)  
  
- [GetMinutes](#getminutes)  
  
- [GetSeconds](#getseconds)  
  
- [GetTotalDays](#gettotaldays)  
  
- [GetTotalMinutes](#gettotalminutes)  
  
- [GetTotalSeconds](#gettotalseconds)  
  
### <a name="example"></a>Exemplo  
 Veja o exemplo de [GetTotalDays](#gettotaldays).  
  
##  <a name="gettotalminutes"></a>COleDateTimeSpan::GetTotalMinutes  
 Recupera o valor de data-período/expressado em minutos.  
  
```
double GetTotalMinutes() const throw();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Esse valor de data/hora-intervalo expressada em minutos. Embora essa função é um protótipo para retornar um valor double, sempre retornará um valor inteiro.  
  
### <a name="remarks"></a>Comentários  
 Os valores de retorno desse intervalo de função entre aproximadamente – 5.26e9 e 5.26e9.  
  
 Para outras funções que consulta o valor de um `COleDateTimeSpan` de objeto, consulte as seguintes funções de membro:  
  
- [GetDays](#getdays)  
  
- [GetHours](#gethours)  
  
- [GetMinutes](#getminutes)  
  
- [GetSeconds](#getseconds)  
  
- [GetTotalDays](#gettotaldays)  
  
- [GetTotalHours](#gettotalhours)  
  
- [GetTotalSeconds](#gettotalseconds)  
  
### <a name="example"></a>Exemplo  
 Veja o exemplo de [GetTotalDays](#gettotaldays).  
  
##  <a name="gettotalseconds"></a>COleDateTimeSpan::GetTotalSeconds  
 Recupera o valor de data-período/expressado em segundos.  
  
```
double GetTotalSeconds() const throw();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Esse valor de data/hora-intervalo expressada em segundos. Embora essa função é um protótipo para retornar um valor double, sempre retornará um valor inteiro.  
  
### <a name="remarks"></a>Comentários  
 Os valores retornados por essa função, o intervalo entre aproximadamente – 3.16e11 para 3.16e11.  
  
 Para outras funções que consulta o valor de um `COleDateTimeSpan` de objeto, consulte as seguintes funções de membro:  
  
- [GetDays](#getdays)  
  
- [GetHours](#gethours)  
  
- [GetMinutes](#getminutes)  
  
- [GetSeconds](#getseconds)  
  
- [GetTotalDays](#gettotaldays)  
  
- [GetTotalHours](#gettotalhours)  
  
- [GetTotalMinutes](#gettotalminutes)  
  
### <a name="example"></a>Exemplo  
 Veja o exemplo de [GetTotalDays](#gettotaldays).  
  
##  <a name="m_span"></a>COleDateTimeSpan::m_span  
 Subjacente **duplo** valor `COleDateTime` objeto.  
  
```
double m_span;
```  
  
### <a name="remarks"></a>Comentários  
 Esse valor expressa o data/período de tempo em dias.  
  
> [!CAUTION]
>  Alterando o valor de **duplo** membro de dados irá alterar o valor dessa `COleDateTimeSpan` objeto. Ele não altera o status deste `COleDateTimeSpan` objeto.  
  
##  <a name="m_status"></a>COleDateTimeSpan::m_status  
 O tipo para este membro de dados é o tipo enumerado **DateTimeSpanStatus**, que é definido dentro de `COleDateTimeSpan` classe.  
  
```
DateTimeSpanStatus m_status;
```  
  
### <a name="remarks"></a>Comentários  
 `enum DateTimeSpanStatus{`  
  
 `valid = 0,`  
  
 `invalid = 1,`  
  
 `null = 2,`  
  
 `};`  
  
 Para obter uma breve descrição desses valores de status, consulte a lista a seguir:  
  
- **COleDateTimeSpan::valid** indica que esse `COleDateTimeSpan` objeto é válido.  
  
- **COleDateTimeSpan::invalid** indica que esse `COleDateTimeSpan` objeto é inválido; isto é, seu valor pode estar incorreto.  
  
- **COleDateTimeSpan::null** indica que esse `COleDateTimeSpan` objeto é nulo, ou seja, se nenhum valor foi fornecido para este objeto. (Isso é "null" no sentido de banco de dados de "não ter nenhum valor," em vez do C++ **nulo**.)  
  
 O status de uma `COleDateTimeSpan` objeto é inválido nos seguintes casos:  
  
-   Se esse objeto experimentou um estouro ou estouro negativo durante uma operação aritmética de atribuição, ou seja, `+=` ou `-=`.  
  
-   Se um valor inválido foi atribuído a esse objeto.  
  
-   Se o status desse objeto explicitamente definido como inválido usando [SetStatus](#setstatus).  
  
 Para obter mais informações sobre as operações que podem definir o status para inválido, consulte [COleDateTimeSpan::operator +, -](../../atl-mfc-shared/reference/coledatetime-class.md#operator_add_-) e [+ = COleDateTimeSpan::operator,-=](../../atl-mfc-shared/reference/coledatetime-class.md#operator_add_eq_-_eq).  
  
> [!CAUTION]
>  Este membro de dados é para situações de programação avançadas. Você deve usar as funções de membro embutidas [GetStatus](#getstatus) e [SetStatus](#setstatus). Consulte `SetStatus` para obter mais avisos sobre definir explicitamente esse membro de dados.  
  
 Para obter mais informações sobre os limites de `COleDateTimeSpan` valores, consulte o artigo [data e hora: suporte de automação de](../../atl-mfc-shared/date-and-time-automation-support.md).  
  
##  <a name="operator_eq"></a>COleDateTimeSpan::operator =  
 Copia uma `COleDateTimeSpan` valor.  
  
```
COleDateTimeSpan& operator=(double dblSpanSrc) throw();
```  
  
### <a name="remarks"></a>Comentários  
 Esse operador de atribuição sobrecarregados copia o valor de data/hora-intervalo de origem para este `COleDateTimeSpan` objeto.  
  
##  <a name="operator_add_-"></a>COleDateTimeSpan::operator +, -  
 Adicionar, subtrair e alterar o sinal para `COleDateTimeSpan` valores.  
  
```
COleDateTimeSpan operator+(const COleDateTimeSpan& dateSpan) const throw();
COleDateTimeSpan operator-(const COleDateTimeSpan& dateSpan) const throw();
COleDateTimeSpan operator-() const throw();
```  
  
### <a name="remarks"></a>Comentários  
 Os dois primeiros operadores permitem adicionar e subtrair valores de data/hora-período. O terceiro lhe permite alterar o sinal de um valor de data/hora-período.  
  
 Se qualquer um dos operandos for null, o status de resultante `COleDateTimeSpan` valor é null.  
  
 Se qualquer um dos operandos for inválido e o outro não for nulo, o status de resultante `COleDateTimeSpan` valor é inválido.  
  
 Para obter mais informações sobre os valores de status válido, inválido e nulo, consulte o [m_status](#m_status) variável de membro.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_ATLMFC_Utilities&#23;](../../atl-mfc-shared/codesnippet/cpp/coledatetimespan-class_10.cpp)]  
  
##  <a name="operator_add_eq_-_eq"></a>+ = COleDateTimeSpan::operator-=  
 Adicionar e subtrair um `COleDateTimeSpan` valor desse `COleDateTimeSpan` valor.  
  
```
COleDateTimeSpan& operator+=(const COleDateTimeSpan dateSpan) throw();
COleDateTimeSpan& operator-=(const COleDateTimeSpan dateSpan) throw();
```  
  
### <a name="remarks"></a>Comentários  
 Esses operadores permitem adicionar e subtrair valores de data/hora-período neste `COleDateTimeSpan` objeto. Se qualquer um dos operandos for null, o status de resultante `COleDateTimeSpan` valor é null.  
  
 Se qualquer um dos operandos for inválido e o outro não for nulo, o status de resultante `COleDateTimeSpan` valor é inválido.  
  
 Para obter mais informações sobre os valores de status válido, inválido e nulo, consulte o [m_status](#m_status) variável de membro.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_ATLMFC_Utilities&#24;](../../atl-mfc-shared/codesnippet/cpp/coledatetimespan-class_11.cpp)]  
  
##  <a name="operator_double"></a>COleDateTimeSpan::operator dupla  
 Converte isso `COleDateTimeSpan` valor para um **duplo**.  
  
```
operator double() const throw();
```  
  
### <a name="remarks"></a>Comentários  
 Esse operador retorna o valor desse `COleDateTimeSpan` valor como um número de ponto flutuante de dias.  
  
##  <a name="setdatetimespan"></a>COleDateTimeSpan::SetDateTimeSpan  
 Define o valor desse valor de data/hora-período.  
  
```
void SetDateTimeSpan(LONG lDays, int nHours, int nMins, int nSecs) throw();
```  
  
### <a name="parameters"></a>Parâmetros  
 `lDays`, `nHours`, `nMins`, `nSecs`  
 Indique os valores de intervalo de data e o período de tempo a ser copiado para isso `COleDateTimeSpan` objeto.  
  
### <a name="remarks"></a>Comentários  
 Para funções que consulta o valor de um `COleDateTimeSpan` de objeto, consulte as seguintes funções de membro:  
  
- [GetDays](#getdays)  
  
- [GetHours](#gethours)  
  
- [GetMinutes](#getminutes)  
  
- [GetSeconds](#getseconds)  
  
- [GetTotalDays](#gettotaldays)  
  
- [GetTotalHours](#gettotalhours)  
  
- [GetTotalMinutes](#gettotalminutes)  
  
- [GetTotalSeconds](#gettotalseconds)  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_ATLMFC_Utilities&#21;](../../atl-mfc-shared/codesnippet/cpp/coledatetimespan-class_12.cpp)]  
  
##  <a name="setstatus"></a>COleDateTimeSpan::SetStatus  
 Define o status (validade) deste `COleDateTimeSpan` objeto.  
  
```
void SetStatus(DateTimeSpanStatus status) throw();
```  
  
### <a name="parameters"></a>Parâmetros  
 *status*  
 O novo valor de status para essa `COleDateTimeSpan` objeto.  
  
### <a name="remarks"></a>Comentários  
 O *Status* o valor do parâmetro é definido pelo **DateTimeSpanStatus** enumeração de tipo, que é definido dentro de `COleDateTimeSpan` classe.  
  
 `enum DateTimeSpanStatus{`  
  
 `valid = 0,`  
  
 `invalid = 1,`  
  
 `null = 2,`  
  
 `};`  
  
 Para obter uma breve descrição desses valores de status, consulte a lista a seguir:  
  
- **COleDateTimeSpan::valid** indica que esse `COleDateTimeSpan` objeto é válido.  
  
- **COleDateTimeSpan::invalid** indica que esse `COleDateTimeSpan` objeto é inválido; isto é, seu valor pode estar incorreto.  
  
- **COleDateTimeSpan::null** indica que esse `COleDateTimeSpan` objeto é nulo, ou seja, se nenhum valor foi fornecido para este objeto. (Isso é "null" no sentido de banco de dados de "não ter nenhum valor," em vez do C++ **nulo**.)  
  
    > [!CAUTION]
    >  Essa função é para situações de programação avançadas. Essa função não alteram os dados nesse objeto. Ele geralmente será usado para definir o status como `null` ou **inválido**. Observe que o operador de atribuição ( [operador =](#eq)) e [SetDateTimeSpan](#setdatetimespan) definir o status do objeto com base em valores de origem.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_ATLMFC_Utilities&#22;](../../atl-mfc-shared/codesnippet/cpp/coledatetimespan-class_13.cpp)]  
  
## <a name="see-also"></a>Consulte também  
 [Classe COleDateTime](../../atl-mfc-shared/reference/coledatetime-class.md)   
 [Classe CTime](../../atl-mfc-shared/reference/ctime-class.md)   
 [Classe CTimeSpan](../../atl-mfc-shared/reference/ctimespan-class.md)   
 [Gráfico de hierarquia](../../mfc/hierarchy-chart.md)   
 [Classes compartilhadas do ATL/MFC](../../atl-mfc-shared/atl-mfc-shared-classes.md)



