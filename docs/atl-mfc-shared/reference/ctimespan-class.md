---
title: Classe CTimeSpan | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- CTimeSpan
- ATLTIME/ATL::CTimeSpan
- ATLTIME/ATL::CTimeSpan::CTimeSpan
- ATLTIME/ATL::CTimeSpan::Format
- ATLTIME/ATL::CTimeSpan::GetDays
- ATLTIME/ATL::CTimeSpan::GetHours
- ATLTIME/ATL::CTimeSpan::GetMinutes
- ATLTIME/ATL::CTimeSpan::GetSeconds
- ATLTIME/ATL::CTimeSpan::GetTimeSpan
- ATLTIME/ATL::CTimeSpan::GetTotalHours
- ATLTIME/ATL::CTimeSpan::GetTotalMinutes
- ATLTIME/ATL::CTimeSpan::GetTotalSeconds
- ATLTIME/ATL::CTimeSpan::Serialize64
dev_langs:
- C++
helpviewer_keywords:
- elapsed time, CTimeSpan object
- timespan
- time span
- CTimeSpan class
- shared classes, CTimeSpan
- time, elapsed
ms.assetid: ee1e42f6-1839-477a-8435-fb26ad475140
caps.latest.revision: 17
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
ms.sourcegitcommit: 0e0c08ddc57d437c51872b5186ae3fc983bb0199
ms.openlocfilehash: 5c76411f6c1302d406b07cc79d9c544e3ad8c43b
ms.lasthandoff: 02/25/2017

---
# <a name="ctimespan-class"></a>Classe CTimeSpan
Um valor de tempo, que é armazenado internamente como o número de segundos no período de tempo.  
  
## <a name="syntax"></a>Sintaxe  
  
```
class CTimeSpan
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CTimeSpan::CTimeSpan](#ctimespan)|Constrói `CTimeSpan` objetos de várias maneiras.|  
  
### <a name="public-methods"></a>Métodos públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CTimeSpan::Format](#format)|Converte um `CTimeSpan` em uma cadeia de caracteres formatada.|  
|[CTimeSpan::GetDays](#getdays)|Retorna um valor que representa o número de dias completos neste `CTimeSpan`.|  
|[CTimeSpan::GetHours](#gethours)|Retorna um valor que representa o número de horas do dia atual (–23 a 23).|  
|[CTimeSpan::GetMinutes](#getminutes)|Retorna um valor que representa o número de minutos na hora atual (–59 a 59).|  
|[CTimeSpan::GetSeconds](#getseconds)|Retorna um valor que representa o número de segundos no minuto atual (–59 a 59).|  
|[CTimeSpan::GetTimeSpan](#gettimespan)|Retorna o valor da `CTimeSpan` objeto.|  
|[CTimeSpan::GetTotalHours](#gettotalhours)|Retorna um valor que representa o número total de horas completas neste `CTimeSpan`.|  
|[CTimeSpan::GetTotalMinutes](#gettotalminutes)|Retorna um valor que representa o número total de minutos completos neste `CTimeSpan`.|  
|[CTimeSpan::GetTotalSeconds](#gettotalseconds)|Retorna um valor que representa o número total de segundos completos neste `CTimeSpan`.|  
|[CTimeSpan::Serialize64](#serialize64)|Serializa os dados de ou para um arquivo morto.|  
  
### <a name="operators"></a>Operadores  
  
|||  
|-|-|  
|[operador + –](#operator_add_-)|Adiciona e subtrai `CTimeSpan` objetos.|  
|[operador + = – =](#operator_add_eq_-_eq)|Adiciona e subtrai um `CTimeSpan` objeto e neste `CTimeSpan`.|  
|[operador = =<>](#ctimespan_comparison_operators)|Compara dois valores de tempo relativo.|  
  
## <a name="remarks"></a>Comentários  
 `CTimeSpan`não tem uma classe base.  
  
 `CTimeSpan`funções convertem segundos para várias combinações de dias, horas, minutos e segundos.  
  
 O `CTimeSpan` objeto é armazenado em uma **__time64_t** estrutura, que é de 8 bytes.  
  
 Uma classe complementar, [CTime](../../atl-mfc-shared/reference/ctime-class.md), representa uma hora absoluta.  
  
 O `CTime` e `CTimeSpan` classes não são projetadas para derivação. Porque não existem funções virtuais, o tamanho dos dois `CTime` e `CTimeSpan` objetos é exatamente 8 bytes. A maioria das funções de membro são embutidas.  
  
 Para obter mais informações sobre como usar o `CTimeSpan`, consulte os artigos [data e hora](../../atl-mfc-shared/date-and-time.md), e [gerenciamento de tempo](../../c-runtime-library/time-management.md) no *referência da biblioteca de tempo de execução*.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atltime.h  
  
##  <a name="ctimespan_comparison_operators"></a>Operadores de comparação de CTimeSpan  
 Operadores de comparação.  
  
```
bool operator==(CTimeSpan span) const throw();
bool operator!=(CTimeSpan span) const throw();
bool operator<(CTimeSpan span) const throw();
bool operator>(CTimeSpan span) const throw();
bool operator<=(CTimeSpan span) const throw();
bool operator>=(CTimeSpan span) const throw();
```  
  
### <a name="parameters"></a>Parâmetros  
 `span`  
  
 O objeto a ser comparado.  
  
### <a name="return-value"></a>Valor de retorno  
 Esses operadores comparam dois valores de tempo relativo. Elas retornam **true** se a condição for true; caso contrário **false**.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_ATLMFC_Utilities&#169;](../../atl-mfc-shared/codesnippet/cpp/ctimespan-class_1.cpp)]  
  
##  <a name="ctimespan"></a>CTimeSpan::CTimeSpan  
 Constrói `CTimeSpan` objetos de várias maneiras.  
  
```
CTimeSpan() throw();
CTimeSpan(__time64_t time) throw();

CTimeSpan(  
 LONG lDays,
 int nHours,
 int nMins,
 int nSecs) throw();
```  
  
### <a name="parameters"></a>Parâmetros  
 *timeSpanSrc*  
 Um `CTimeSpan` objeto já existe.  
  
 `time`  
 A **__time64_t** valor de tempo, que é o número de segundos no período de tempo. Em versões do Visual C++ 6.0 e anteriores, `time` era um valor de `time_t`. Visual C++ .NET ou posterior silenciosamente converte uma `time_t` parâmetro **__time64_t**.  
  
 `lDays`, `nHours`, `nMins`, `nSecs`  
 Dias, horas, minutos e segundos, respectivamente.  
  
### <a name="remarks"></a>Comentários  
 Todos esses construtores criam um novo `CTimeSpan` objeto inicializado com o tempo relativo especificado. Cada construtor é descrito abaixo:  
  
- **CTimeSpan (); ** Constrói uma inicializado `CTimeSpan` objeto.  
  
- **CTimeSpan (const CTimeSpan < /); ** Constrói uma `CTimeSpan` objeto de outro `CTimeSpan` valor.  
  
- **CTimeSpan (__time64_t); ** Constrói uma `CTimeSpan` de objeto um **__time64_t** tipo.  
  
- **CTimeSpan (longo**, **int, int, int);** Constrói uma `CTimeSpan` objeto dos componentes com cada componente restrito a intervalos a seguir:  
  
    |Componente|Intervalo|  
    |---------------|-----------|  
    |`lDays`|0 –&25;.000 (aproximadamente)|  
    |`nHours`|0–23|  
    |`nMins`|0–59|  
    |`nSecs`|0–59|  
  
 Observe que a versão de depuração da Microsoft Foundation Class Library afirma se um ou mais dos componentes de hora do dia está fora do intervalo. É sua responsabilidade para validar os argumentos antes de chamar.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_ATLMFC_Utilities&#162;](../../atl-mfc-shared/codesnippet/cpp/ctimespan-class_2.cpp)]  
  
##  <a name="format"></a>CTimeSpan::Format  
 Gera uma cadeia de caracteres formatada que corresponde a esta `CTimeSpan`.  
  
```
CString Format(LPCSTR pFormat) const;
CString Format(LPCTSTR pszFormat) const;
CString Format(UINT nID) const;
```  
  
### <a name="parameters"></a>Parâmetros  
 `pFormat`, `pszFormat`  
 Uma formatação de cadeia de caracteres semelhante de `printf` formatação de cadeia de caracteres. Códigos de formatação, precedidos por uma porcentagem ( `%`) entre, são substituídos por correspondente `CTimeSpan` componente. Outros caracteres na cadeia de formatação são copiados inalterado de cadeia de caracteres retornada. O valor e o significado dos códigos de formatação para **formato** estão listadas abaixo:  
  
- **%D** total de dias em que isso`CTimeSpan`  
  
- **%H** horas do dia atual  
  
- **%M** minutos na hora atual  
  
- **%S** segundos no minuto atual  
  
- **%%**Sinal de porcentagem  
  
 `nID`  
 A ID da cadeia de caracteres que identifica esse formato.  
  
### <a name="return-value"></a>Valor de retorno  
 Um `CString` objeto que contém a hora formatada.  
  
### <a name="remarks"></a>Comentários  
 A versão de depuração da biblioteca verifica os códigos de formatação e declara se o código não estiver na lista acima.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_ATLMFC_Utilities&#163;](../../atl-mfc-shared/codesnippet/cpp/ctimespan-class_3.cpp)]  
  
##  <a name="getdays"></a>CTimeSpan::GetDays  
 Retorna um valor que representa o número de dias completos neste `CTimeSpan`.  
  
```
LONGLONG GetDays() const throw();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna o número de dias completos de 24 horas no período de tempo. Esse valor pode ser negativo se o período de tempo for negativo.  
  
### <a name="remarks"></a>Comentários  
 Observe que pode fazer com que o horário de verão `GetDays` para retornar um resultado potencialmente surpreendente. Por exemplo, ao horário de verão está em vigor, **GetDays** relata o número de dias entre 1º de abril e 1 de maio como 29, 30 não, porque um dia em abril é reduzido por uma hora e, portanto, não contam como um dia completo.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_ATLMFC_Utilities&#164;](../../atl-mfc-shared/codesnippet/cpp/ctimespan-class_4.cpp)]  
  
##  <a name="gethours"></a>CTimeSpan::GetHours  
 Retorna um valor que representa o número de horas do dia atual (–23 a 23).  
  
```
LONG GetHours() const throw();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna o número de horas do dia atual. O intervalo é –23 a 23.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_ATLMFC_Utilities&#165;](../../atl-mfc-shared/codesnippet/cpp/ctimespan-class_5.cpp)]  
  
##  <a name="getminutes"></a>CTimeSpan::GetMinutes  
 Retorna um valor que representa o número de minutos na hora atual (–59 a 59).  
  
```
LONG GetMinutes() const throw();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna o número de minutos na hora atual. O intervalo é –59 a 59.  
  
### <a name="example"></a>Exemplo  
 Veja o exemplo de [GetHours](#gethours).  
  
##  <a name="getseconds"></a>CTimeSpan::GetSeconds  
 Retorna um valor que representa o número de segundos no minuto atual (–59 a 59).  
  
```
LONG GetSeconds() const throw();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna o número de segundos no minuto atual. O intervalo é –59 a 59.  
  
### <a name="example"></a>Exemplo  
 Veja o exemplo de [GetHours](#gethours).  
  
##  <a name="gettimespan"></a>CTimeSpan::GetTimeSpan  
 Retorna o valor da `CTimeSpan` objeto.  
  
```
__ time64_t GetTimeSpan() const throw();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna o valor atual de `CTimeSpan` objeto.  
  
##  <a name="gettotalhours"></a>CTimeSpan::GetTotalHours  
 Retorna um valor que representa o número total de horas completas neste `CTimeSpan`.  
  
```
LONGLONG GetTotalHours() const throw();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna o número total de horas completas neste `CTimeSpan`.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_ATLMFC_Utilities&#166;](../../atl-mfc-shared/codesnippet/cpp/ctimespan-class_6.cpp)]  
  
##  <a name="gettotalminutes"></a>CTimeSpan::GetTotalMinutes  
 Retorna um valor que representa o número total de minutos completos neste `CTimeSpan`.  
  
```
LONGLONG GetTotalMinutes() const throw();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna o número total de minutos completos neste `CTimeSpan`.  
  
### <a name="example"></a>Exemplo  
 Veja o exemplo de [GetTotalHours](#gettotalhours).  
  
##  <a name="gettotalseconds"></a>CTimeSpan::GetTotalSeconds  
 Retorna um valor que representa o número total de segundos completos neste `CTimeSpan`.  
  
```
LONGLONG GetTotalSeconds() const throw();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna o número total de segundos completos neste `CTimeSpan`.  
  
### <a name="example"></a>Exemplo  
 Veja o exemplo de [GetTotalHours](#gettotalhours).  
  
##  <a name="operator_add_-"></a>CTimeSpan::operator +, -  
 Adiciona e subtrai `CTimeSpan` objetos.  
  
```
CTimeSpan operator+(CTimeSpan span) const throw();
CTimeSpan operator-(CTimeSpan span) const throw();
```  
  
### <a name="parameters"></a>Parâmetros  
 `span`  
 O valor a ser adicionado para o `CTimeSpan` objeto.  
  
### <a name="return-value"></a>Valor de retorno  
 Um `CTimeSpan` objeto que representa o resultado da operação.  
  
### <a name="remarks"></a>Comentários  
 Esses dois operadores permitem que você adicionar e subtrair `CTimeSpan` objetos para e entre si.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_ATLMFC_Utilities&#167;](../../atl-mfc-shared/codesnippet/cpp/ctimespan-class_7.cpp)]  
  
##  <a name="operator_add_eq_-_eq"></a>+ = CTimeSpan::operator-=  
 Adiciona e subtrai um `CTimeSpan` objeto e neste `CTimeSpan`.  
  
```
CTimeSpan& operator+=(CTimeSpan span) throw();
CTimeSpan& operator-=(CTimeSpan span) throw();
```  
  
### <a name="parameters"></a>Parâmetros  
 `span`  
 O valor a ser adicionado para o `CTimeSpan` objeto.  
  
### <a name="return-value"></a>Valor de retorno  
 A atualização `CTimeSpan` objeto.  
  
### <a name="remarks"></a>Comentários  
 Esses operadores permitem que você adicionar e subtrair um `CTimeSpan` objeto e neste `CTimeSpan`.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_ATLMFC_Utilities&#168;](../../atl-mfc-shared/codesnippet/cpp/ctimespan-class_8.cpp)]  
  
##  <a name="serialize64"></a>CTimeSpan::Serialize64  
  
> [!NOTE]
>  Este método só está disponível em projetos MFC.  
  
 Serializa os dados associados com a variável de membro de um arquivo.  
  
```
CArchive& Serialize64(CArchive& ar);
```  
  
### <a name="parameters"></a>Parâmetros  
 `ar`  
 O `CArchive` objeto que você deseja atualizar.  
  
### <a name="return-value"></a>Valor de retorno  
 A atualização `CArchive` objeto.  
  
## <a name="see-also"></a>Consulte também  
 [asctime, _wasctime](../../c-runtime-library/reference/asctime-wasctime.md)   
 [_ftime, _ftime32, _ftime64](../../c-runtime-library/reference/ftime-ftime32-ftime64.md)   
 [gmtime, _gmtime32, _gmtime64](../../c-runtime-library/reference/gmtime-gmtime32-gmtime64.md)   
 [localtime, _localtime32, _localtime64](../../c-runtime-library/reference/localtime-localtime32-localtime64.md)   
 [strftime, wcsftime, _strftime_l, _wcsftime_l](../../c-runtime-library/reference/strftime-wcsftime-strftime-l-wcsftime-l.md)   
 [time, _time32, _time64](../../c-runtime-library/reference/time-time32-time64.md)   
 [Gráfico de hierarquia](../../mfc/hierarchy-chart.md)   
 [Classes compartilhadas do ATL/MFC](../../atl-mfc-shared/atl-mfc-shared-classes.md)



