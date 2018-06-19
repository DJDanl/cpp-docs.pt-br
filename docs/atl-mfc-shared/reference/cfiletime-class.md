---
title: Classe CFileTime | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: reference
f1_keywords:
- CFileTime
- ATLTIME/ATL::CFileTime
- ATLTIME/ATL::CFileTime::CFileTime
- ATLTIME/ATL::CFileTime::GetCurrentTime
- ATLTIME/ATL::CFileTime::GetTime
- ATLTIME/ATL::CFileTime::LocalToUTC
- ATLTIME/ATL::CFileTime::SetTime
- ATLTIME/ATL::CFileTime::UTCToLocal
- ATLTIME/ATL::CFileTime::Day
- ATLTIME/ATL::CFileTime::Hour
- ATLTIME/ATL::CFileTime::Millisecond
- ATLTIME/ATL::CFileTime::Minute
- ATLTIME/ATL::CFileTime::Second
- ATLTIME/ATL::CFileTime::Week
dev_langs:
- C++
helpviewer_keywords:
- CFileTime class
- shared classes, CFileTime
ms.assetid: 1a358a65-1383-4124-b0d4-59b026e6860f
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 92acaa02ada550f1a2dcbf33a0e0e67b88347a5d
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
ms.locfileid: "32365289"
---
# <a name="cfiletime-class"></a>Classe CFileTime
Essa classe fornece métodos para gerenciar os valores de data e hora associados a um arquivo.  
  
## <a name="syntax"></a>Sintaxe  
  
```
class CFileTime :  public FILETIME
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CFileTime::CFileTime](#cfiletime)|O construtor.|  
  
### <a name="public-methods"></a>Métodos públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CFileTime::GetCurrentTime](#getcurrenttime)|Chame a função estática para recuperar um `CFileTime` objeto que representa a data atual do sistema e a hora.|  
|[CFileTime::GetTime](#gettime)|Chame esse método para recuperar a hora do `CFileTime` objeto.|  
|[CFileTime::LocalToUTC](#localtoutc)|Chame esse método para converter um horário de arquivo local para uma hora de arquivo com base no tempo Universal Coordenado (UTC).|  
|[CFileTime::SetTime](#settime)|Chame este método para definir a data e hora armazenados pelo `CFileTime` objeto.|  
|[CFileTime::UTCToLocal](#utctolocal)|Chame este método para converter a hora com base no tempo Universal Coordenado (UTC) para o horário de arquivo local.|  
  
### <a name="public-operators"></a>Operadores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CFileTime::operator-](#operator_-)|Esse operador é usado para executar a subtração em um `CFileTime` ou `CFileTimeSpan` objeto.|  
|[CFileTime::operator! =](#operator_neq)|Este operador compara dois `CFileTime` objetos desigualdade.|  
|[CFileTime::operator +](#operator_add)|Esse operador é usado para executar uma adição em um `CFileTimeSpan` objeto.|  
|[+ CFileTime::operator =](#operator_add_eq)|Esse operador é usado para executar uma adição em um `CFileTimeSpan` de objeto e atribuir o resultado para o objeto atual.|  
|[CFileTime::operator &lt;](#operator_lt)|Este operador compara dois `CFileTime` objetos para determinar o menor.|  
|[CFileTime::operator &lt;=](#operator_lt_eq)|Este operador compara dois `CFileTime` objetos para determinar igualdade ou o menor.|  
|[CFileTime::operator =](#operator_eq)|O operador de atribuição.|  
|[CFileTime::operator =](#operator_-_eq)|Esse operador é usado para executar a subtração em um `CFileTimeSpan` de objeto e atribuir o resultado para o objeto atual.|  
|[CFileTime::operator = =](#operator_eq_eq)|Este operador compara dois `CFileTime` objetos para igualdade.|  
|[CFileTime::operator &gt;](#operator_gt)|Este operador compara dois `CFileTime` objetos para determinar o maior.|  
|[CFileTime::operator &gt;=](#operator_gt_eq)|Este operador compara dois `CFileTime` objetos para determinar igualdade ou maior.|  
  
### <a name="public-constants"></a>Constantes públicas  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CFileTime::Day](#day)|Um membro de dados estáticos armazenando o número de intervalos de 100 nanossegundos que compõem um dia.|  
|[CFileTime::Hour](#hour)|Um membro de dados estáticos armazenando o número de intervalos de 100 nanossegundos que compõem uma hora.|  
|[CFileTime::Millisecond](#millisecond)|Um membro de dados estáticos armazenando o número de intervalos de 100 nanossegundos que compõem um milissegundo.|  
|[CFileTime::Minute](#minute)|Um membro de dados estáticos armazenando o número de intervalos de 100 nanossegundos que compõem um minuto.|  
|[CFileTime::Second](#second)|Um membro de dados estáticos armazenando o número de intervalos de 100 nanossegundos que compõem um segundo.|  
|[CFileTime::Week](#week)|Um membro de dados estáticos armazenando o número de intervalos de 100 nanossegundos que compõem uma semana.|  
  
## <a name="remarks"></a>Comentários  
 Essa classe fornece métodos para gerenciar os valores de data e hora associados com a criação, o acesso e a modificação de arquivos. Os métodos e os dados dessa classe são frequentemente usados em conjunto com `CFileTimeSpan` objetos, que lidam com valores de tempo relativo.  
  
 O valor de data e hora é armazenado como um valor de 64 bits que representa o número de intervalos de 100 nanossegundos desde 1 de janeiro de 1601. Este é o formato de tempo Universal Coordenado (UTC).  
  
 As seguintes variáveis de membro constantes estáticos são fornecidas para simplificar os cálculos:  
  
|Variável de membro|Número de intervalos de 100 nanossegundos|  
|---------------------|-----------------------------------------|  
|Milissegundo|10,000|  
|Segundo|Milissegundo * 1.000|  
|Minuto|Segundo * 60|  
|Hora|Minuto * 60|  
|Dia|Hora * 24|  
|Semana|Dia * 7|  
  
 **Observação** nem todos os sistemas de arquivos podem gravar criação e a hora do último acesso e nem todos os sistemas de arquivos registrá-los da mesma maneira. Por exemplo, no sistema de arquivos FAT do Windows NT, criar tempo com uma resolução de 10 milissegundos, tempo de gravação com uma resolução de 2 segundos e tempo de acesso com uma resolução de 1 dia (a data de acesso). Em NTFS, o tempo de acesso com uma resolução de 1 hora. Além disso, FAT registra vezes no disco no horário local, mas NTFS registra vezes no disco em UTC. Para obter mais informações, consulte [arquivo vezes](http://msdn.microsoft.com/library/windows/desktop/ms724290).  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 `FILETIME`  
  
 `CFileTime`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atltime.h  
  
##  <a name="cfiletime"></a>  CFileTime::CFileTime  
 O construtor.  
  
```
CFileTime() throw();
CFileTime(const FILETIME& ft) throw();
CFileTime(ULONGLONG nTime) throw();
```  
  
### <a name="parameters"></a>Parâmetros  
 `ft`  
 Um [FILETIME](http://msdn.microsoft.com/library/windows/desktop/ms724284) estrutura.  
  
 `nTime`  
 A data e hora expressada como um valor de 64 bits.  
  
### <a name="remarks"></a>Comentários  
 O `CFileTime` objeto pode ser criado usando uma existente de data e hora de um `FILETIME` estrutura ou expresso como um valor de 64 bits (no local ou formatos de hora (UTC) Tempo Universal Coordenado). O construtor padrão define a hora como 0.  
  
##  <a name="day"></a>  CFileTime::Day  
 Um membro de dados estáticos armazenando o número de intervalos de 100 nanossegundos que compõem um dia.  
  
```
static const ULONGLONG Day = Hour* 24;
```  
  
### <a name="example"></a>Exemplo  
 Consulte o exemplo para [CFileTime::Millisecond](#millisecond).  
  
##  <a name="getcurrenttime"></a>  CFileTime::GetCurrentTime  
 Chame a função estática para recuperar um `CFileTime` objeto que representa a data atual do sistema e a hora.  
  
```
static CFileTime GetCurrentTime() throw();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna a data atual do sistema e a hora no formato Tempo Universal Coordenado (UTC).  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFCFiles#41](../../atl-mfc-shared/reference/codesnippet/cpp/cfiletime-class_1.cpp)]  
  
##  <a name="gettime"></a>  CFileTime::GetTime  
 Chame esse método para recuperar a hora do `CFileTime` objeto.  
  
```
ULONGLONG GetTime() const throw();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna a data e hora como um número de 64 bits, que pode ser em formato Tempo Universal Coordenado (UTC) ou local.  
  
##  <a name="hour"></a>  CFileTime::Hour  
 Um membro de dados estáticos armazenando o número de intervalos de 100 nanossegundos que compõem uma hora.  
  
```
static const ULONGLONG Hour = Minute* 60;
```  
  
### <a name="example"></a>Exemplo  
 Consulte o exemplo para [CFileTime::Millisecond](#millisecond).  
  
##  <a name="localtoutc"></a>  CFileTime::LocalToUTC  
 Chame esse método para converter um horário de arquivo local para uma hora de arquivo com base no tempo Universal Coordenado (UTC).  
  
```
CFileTime LocalToUTC() const throw();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna um `CFileTime` objeto que contém a hora no formato UTC.  
  
### <a name="example"></a>Exemplo  
 Consulte o exemplo para [CFileTime::UTCToLocal](#utctolocal).  
  
##  <a name="millisecond"></a>  CFileTime::Millisecond  
 Um membro de dados estáticos armazenando o número de intervalos de 100 nanossegundos que compõem um milissegundo.  
  
```
static const ULONGLONG Millisecond = 10000;
```  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFCFiles#44](../../atl-mfc-shared/reference/codesnippet/cpp/cfiletime-class_2.cpp)]  
  
##  <a name="minute"></a>  CFileTime::Minute  
 Um membro de dados estáticos armazenando o número de intervalos de 100 nanossegundos que compõem um minuto.  
  
```
static const ULONGLONG Minute = Second* 60;
```  
  
### <a name="example"></a>Exemplo  
 Consulte o exemplo para [CFileTime::Millisecond](#millisecond).  
  
##  <a name="operator_-"></a>  CFileTime::operator-  
 Esse operador é usado para executar a subtração em um `CFileTime` ou `CFileTimeSpan` objeto.  
  
```
CFileTime operator-(CFileTimeSpan span) const throw();
CFileTimeSpan operator-(CFileTime ft) const throw();
```  
  
### <a name="parameters"></a>Parâmetros  
 `span`  
 Um objeto `CFileTimeSpan`.  
  
 `ft`  
 Um objeto `CFileTime`.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna um `CFileTime` objeto ou uma `CFileTimeSpan` objeto que representa o resultado da diferença de tempo entre os dois objetos.  
  
##  <a name="operator_neq"></a>  CFileTime::operator! =  
 Este operador compara dois `CFileTime` objetos desigualdade.  
  
```
bool operator!=(CFileTime ft) const throw();
```  
  
### <a name="parameters"></a>Parâmetros  
 `ft`  
 O objeto `CFileTime` a ser comparado.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna **true** se o item que estão sendo comparado não é igual a `CFileTime` objeto, caso contrário **false**.  
  
##  <a name="operator_add"></a>  CFileTime::operator +  
 Esse operador é usado para executar uma adição em um `CFileTimeSpan` objeto.  
  
```
CFileTime operator+(CFileTimeSpan span) const throw();
```  
  
### <a name="parameters"></a>Parâmetros  
 `span`  
 Um objeto `CFileTimeSpan`.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna um `CFileTime` objeto que representa o resultado da hora original mais de uma hora relativa.  
  
##  <a name="operator_add_eq"></a>  + CFileTime::operator =  
 Esse operador é usado para executar uma adição em um `CFileTimeSpan` de objeto e atribuir o resultado para o objeto atual.  
  
```
CFileTime& operator+=(CFileTimeSpan span) throw();
```  
  
### <a name="parameters"></a>Parâmetros  
 `span`  
 Um objeto `CFileTimeSpan`.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna a atualização `CFileTime` objeto, que representa o resultado da hora original mais de uma hora relativa.  
  
##  <a name="operator_lt"></a>  CFileTime::operator &lt;  
 Este operador compara dois `CFileTime` objetos para determinar o menor.  
  
```
bool operator<(CFileTime ft) const throw();
```  
  
### <a name="parameters"></a>Parâmetros  
 `ft`  
 O objeto `CFileTime` a ser comparado.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna **true** se o primeiro objeto é menor (anteriormente no tempo) que o segundo, **false** caso contrário.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFCFiles#43](../../atl-mfc-shared/reference/codesnippet/cpp/cfiletime-class_3.cpp)]  
  
##  <a name="operator_lt_eq"></a>  CFileTime::operator &lt;=  
 Este operador compara dois `CFileTime` objetos para determinar igualdade ou o menor.  
  
```
bool operator<=(CFileTime ft) const throw();
```  
  
### <a name="parameters"></a>Parâmetros  
 `ft`  
 O objeto `CFileTime` a ser comparado.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna **true** se o primeiro objeto for menor que (anterior no tempo) ou igual à segunda, caso contrário, **false**.  
  
##  <a name="operator_eq"></a>  CFileTime::operator =  
 O operador de atribuição.  
  
```
CFileTime& operator=(const FILETIME& ft) throw();
```  
  
### <a name="parameters"></a>Parâmetros  
 `ft`  
 Um `CFileTime` objeto que contém a data e hora de novo.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna a atualização `CFileTime` objeto.  
  
##  <a name="operator_-_eq"></a>  CFileTime::operator =  
 Esse operador é usado para executar a subtração em um `CFileTimeSpan` de objeto e atribuir o resultado para o objeto atual.  
  
```
CFileTime& operator-=(CFileTimeSpan span) throw();
```  
  
### <a name="parameters"></a>Parâmetros  
 `span`  
 Um `CFileTimeSpan` objeto que contém o tempo relativo a subtrair.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna a atualização `CFileTime` objeto.  
  
##  <a name="operator_eq_eq"></a>  CFileTime::operator = =  
 Este operador compara dois `CFileTime` objetos para igualdade.  
  
```
bool operator==(CFileTime ft) const throw();
```  
  
### <a name="parameters"></a>Parâmetros  
 `ft`  
 O objeto `CFileTime` a ser comparado.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna **true** se os objetos forem iguais; caso contrário, **false**.  
  
##  <a name="operator_gt"></a>  CFileTime::operator &gt;  
 Este operador compara dois `CFileTime` objetos para determinar o maior.  
  
```
bool operator>(CFileTime ft) const throw();
```  
  
### <a name="parameters"></a>Parâmetros  
 `ft`  
 O objeto `CFileTime` a ser comparado.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna **true** se o primeiro objeto for maior que (mais adiante no tempo) que a segunda, caso contrário, **false**.  
  
##  <a name="operator_gt_eq"></a>  CFileTime::operator &gt;=  
 Este operador compara dois `CFileTime` objetos para determinar igualdade ou maior.  
  
```
bool operator>=(CFileTime ft) const throw();
```  
  
### <a name="parameters"></a>Parâmetros  
 `ft`  
 O objeto `CFileTime` a ser comparado.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna **true** se o primeiro objeto for maior que (mais adiante no tempo) ou igual à segunda, caso contrário **false**.  
  
##  <a name="second"></a>  CFileTime::Second  
 Um membro de dados estáticos armazenando o número de intervalos de 100 nanossegundos que compõem um dia.  
  
```
static const ULONGLONG Second = Millisecond* 1000;
```  
  
### <a name="example"></a>Exemplo  
 Consulte o exemplo para [CFileTime::Millisecond](#millisecond).  
  
##  <a name="settime"></a>  CFileTime::SetTime  
 Chame este método para definir a data e hora armazenados pelo `CFileTime` objeto.  
  
```
void SetTime(ULONGLONG nTime) throw();
```  
  
### <a name="parameters"></a>Parâmetros  
 `nTime`  
 O valor de 64 bits que representa a data e hora no formato Tempo Universal Coordenado (UTC) ou local.  
  
##  <a name="utctolocal"></a>  CFileTime::UTCToLocal  
 Chame este método para converter a hora com base no tempo Universal Coordenado (UTC) para o horário de arquivo local.  
  
```
CFileTime UTCToLocal() const throw();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna um `CFileTime` objeto que contém a hora no formato de hora do arquivo local.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFCFiles#42](../../atl-mfc-shared/reference/codesnippet/cpp/cfiletime-class_4.cpp)]  
  
##  <a name="week"></a>  CFileTime::Week  
 Um membro de dados estáticos armazenando o número de intervalos de 100 nanossegundos que compõem uma semana.  
  
```
static const ULONGLONG Week = Day* 7;
```  
  
### <a name="example"></a>Exemplo  
 Consulte o exemplo para [CFileTime::Millisecond](#millisecond).  
  
## <a name="see-also"></a>Consulte também  
 [FILETIME](http://msdn.microsoft.com/library/windows/desktop/ms724284)   
 [Classe CFileTimeSpan](../../atl-mfc-shared/reference/cfiletimespan-class.md)   
 [Gráfico de hierarquia](../../mfc/hierarchy-chart.md)   
 [Classes compartilhadas do ATL/MFC](../../atl-mfc-shared/atl-mfc-shared-classes.md)


