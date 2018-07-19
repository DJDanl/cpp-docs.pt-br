---
title: Classe CTime | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: reference
f1_keywords:
- CTime
- ATLTIME/ATL::CTime
- ATLTIME/ATL::CTime::CTime
- ATLTIME/ATL::CTime::Format
- ATLTIME/ATL::CTime::FormatGmt
- ATLTIME/ATL::CTime::GetAsDBTIMESTAMP
- ATLTIME/ATL::CTime::GetAsSystemTime
- ATLTIME/ATL::CTime::GetCurrentTime
- ATLTIME/ATL::CTime::GetDay
- ATLTIME/ATL::CTime::GetDayOfWeek
- ATLTIME/ATL::CTime::GetGmtTm
- ATLTIME/ATL::CTime::GetHour
- ATLTIME/ATL::CTime::GetLocalTm
- ATLTIME/ATL::CTime::GetMinute
- ATLTIME/ATL::CTime::GetMonth
- ATLTIME/ATL::CTime::GetSecond
- ATLTIME/ATL::CTime::GetTime
- ATLTIME/ATL::CTime::GetYear
- ATLTIME/ATL::CTime::Serialize64
dev_langs:
- C++
helpviewer_keywords:
- CTime class
- shared classes, CTime
ms.assetid: 0a299544-485b-48dc-9d3c-fdc30f57d612
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 4b68ebd20d449c11ac8c62a6a01c086dbe566811
ms.sourcegitcommit: 76fd30ff3e0352e2206460503b61f45897e60e4f
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/13/2018
ms.locfileid: "39027667"
---
# <a name="ctime-class"></a>Classe CTime
Representa uma data e a hora absoluta.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class CTime  
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CTime::CTime](#ctime)|Constrói `CTime` objetos de várias maneiras.|  
  
### <a name="public-methods"></a>Métodos públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CTime::Format](#format)|Converte um `CTime` objeto em uma cadeia de caracteres formatada — com base no fuso horário local.|  
|[CTime::FormatGmt](#formatgmt)|Converte um `CTime` objeto em uma cadeia de caracteres formatada — com base em UTC.|  
|[CTime::GetAsDBTIMESTAMP](#getasdbtimestamp)|Converte as informações de hora armazenadas no `CTime` objeto a uma estrutura compatível com o Win32 DBTIMESTAMP.|  
|[CTime::GetAsSystemTime](#getassystemtime)|Converte as informações de hora armazenadas na `CTime` objeto para uma compatível com o Win32 [SYSTEMTIME](http://msdn.microsoft.com/library/windows/desktop/ms724950) estrutura.|  
|[CTime::GetCurrentTime](#getcurrenttime)|Cria um `CTime` objeto que representa a hora atual (função de membro estático).|  
|[CTime::GetDay](#getday)|Retorna representam o dia, o `CTime` objeto.|  
|[CTime::GetDayOfWeek](#getdayofweek)|Retorna o dia da semana representado pelo `CTime` objeto.|  
|[CTime::GetGmtTm](#getgmttm)|Divide um `CTime` objeto em componentes — com base em UTC.|  
|[CTime::GetHour](#gethour)|Retorna a hora representada pelo `CTime` objeto.|  
|[CTime::GetLocalTm](#getlocaltm)|Divide um `CTime` objeto em componentes — com base no fuso horário local.|  
|[CTime::GetMinute](#getminute)|Retorna o minuto representado pelo `CTime` objeto.|  
|[CTime::GetMonth](#getmonth)|Retorna o mês representado pelo `CTime` objeto.|  
|[CTime::GetSecond](#getsecond)|Retorna o segundo, representado pelo `CTime` objeto.|  
|[CTime::GetTime](#gettime)|Retorna um **__time64_t** valor para o determinado `CTime` objeto.|  
|[CTime::GetYear](#getyear)|Retorna o ano que representa o `CTime` objeto.|  
|[CTime::Serialize64](#serialize64)|Serializa os dados de ou para um arquivo morto.|  
  
### <a name="operators"></a>Operadores  
  
|||  
|-|-|  
|[operador + -](#operator_add_-)|Esses operadores adicionar e subtrair `CTimeSpan` e `CTime` objetos.|  
|[Operator + =-=](#operator_add_eq_-_eq)|Esses operadores adicionar e subtrair um `CTimeSpan` objeto e para isso `CTime` objeto.|  
|[operador =](#operator_eq)|O operador de atribuição.|  
|[operador = =, <, etc.](#ctime_comparison_operators)|Operadores de comparação.|  
  
## <a name="remarks"></a>Comentários  
 `CTime` não tem uma classe base.  
  
 `CTime` valores são baseados em (UTC) tempo universal coordenado, que é equivalente ao tempo de Universal Coordenado (hora de Greenwich, GMT). Ver [gerenciamento de tempo](../../c-runtime-library/time-management.md) para obter informações sobre como o fuso horário é determinado.  
  
 Quando você cria um `CTime` do objeto, defina o `nDST` parâmetro como 0 para indicar que o horário padrão está em vigor, ou para um valor maior que 0 para indicar que o horário de verão está em vigor, ou para um valor menor que zero para fazer o comput de código de biblioteca de tempo de execução do C e se o horário padrão ou horário de verão está em vigor. `tm_isdst` é um campo obrigatório. Se não definido, seu valor será indefinido e o valor de retorno [mktime](../../c-runtime-library/reference/mktime-mktime32-mktime64.md) é imprevisível. Se `timeptr` aponta para uma estrutura de tm retornada por uma chamada anterior a [asctime_s](../../c-runtime-library/reference/asctime-s-wasctime-s.md), [gmtime_s](../../c-runtime-library/reference/gmtime-s-gmtime32-s-gmtime64-s.md), ou [localtime_s](../../c-runtime-library/reference/localtime-s-localtime32-s-localtime64-s.md), o `tm_isdst` campo contém a valor correto.  
  
 Uma classe de complementar [CTimeSpan](../../atl-mfc-shared/reference/ctimespan-class.md), representa um intervalo de tempo.  
  
 O `CTime` e `CTimeSpan` classes não são projetadas para derivação. Porque não há nenhuma função virtual, o tamanho de `CTime` e `CTimeSpan` objects é exatamente de 8 bytes. A maioria das funções de membro são embutidos.  
  
> [!NOTE]
>  O limite superior de data é 31/12/3000. O limite inferior é 1/1/1970 12:00:00 AM GMT.  
  
 Para obter mais informações sobre como usar `CTime`, consulte os artigos [data e hora](../../atl-mfc-shared/date-and-time.md), e [gerenciamento de tempo](../../c-runtime-library/time-management.md) na referência da biblioteca de tempo de execução.  
  
> [!NOTE]
>  O `CTime` estrutura foi alterada do MFC 7.1 MFC 8.0. Se você serializar uma `CTime` estrutura usando o **operador <<** em MFC 8.0 ou posterior, o arquivo resultante não será legível em versões mais antigas do MFC.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atltime.h  
  
##  <a name="ctime_comparison_operators"></a>  Operadores de comparação CTime  
 Operadores de comparação.  
  
```  
bool operator==(CTime time) const throw(); 
bool operator!=(CTime time) const throw();
bool operator<(CTime time) const throw();
bool operator>(CTime time) const throw();
bool operator<=(CTime time) const throw();
bool operator>=(CTime time) const throw(); 
```  
  
### <a name="parameters"></a>Parâmetros  
 *time*  
 O objeto `CTime` a ser comparado.  
  
### <a name="return-value"></a>Valor de retorno  
 Esses operadores comparam duas vezes absolutos e retornará TRUE se a condição for true; Caso contrário, FALSE.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_ATLMFC_Utilities#161](../../atl-mfc-shared/codesnippet/cpp/ctime-class_1.cpp)]  
  
##  <a name="ctime"></a>  CTime::CTime  
 Cria um novo `CTime` objeto inicializado com o tempo especificado.  
  
```  
CTime() throw(); 
CTime(__time64_t time) throw();
CTime(int nYear, int nMonth, int nDay,
      int nHour, int nMin, int nSec, int nDST = -1);
CTime(WORD wDosDate, WORD wDosTime, int nDST = -1);
CTime(const SYSTEMTIME& st, int nDST = - 1) throw();
CTime(const FILETIME& ft, int nDST = - 1);
CTime(const DBTIMESTAMP& dbts,int nDST = -1) throw();
```  
  
### <a name="parameters"></a>Parâmetros  
 *timeSrc*  
 Indica um `CTime` objeto que já existe.  
  
 *time*  
 Um **__time64_t** valor de tempo, o que é o número de segundos depois de 1º de janeiro de 1970, UTC. Observe que isso será ajustado à sua hora local. Por exemplo, se você estiver em Nova York e cria uma `CTime` objeto, passando um parâmetro de 0, [CTime::GetMonth](#getmonth) retornará 12.  

  
 *nYear*, *nMonth*, *nDay*, *Nhora*, *Nmín*, *nSec*  
 Indica os valores de data e hora a ser copiado para o novo `CTime` objeto.  
  
 *nDST*  
 Indica se o horário de verão está em vigor. Pode ter um dos três valores:  
  
- *nDST* definido como tempo 0Standard está em vigor.  
  
- *nDST* definido como um valor maior que 0Daylight horário está em vigor.  
  
- *nDST* definido como um valor menor que 0The padrão. Calcula automaticamente o se horário padrão ou horário de verão está em vigor.  
  
 *wDosDate*, *wDosTime*  
 Valores de data e hora do MS-DOS para ser convertido em um valor de data/hora e copiado no novo `CTime` objeto.  
  
 *ST*  
 Um [SYSTEMTIME](https://www.microsoftonedoc.com/#/organizations/e6f6a65cf14f462597b64ac058dbe1d0/projects/3fedad16-eaf1-41a6-8f96-0c1949c68f32/containers/a3daf831-1c5f-4bbe-964d-503870caf874/tocpaths/d6609fff-1931-4818-8a26-f042630af0b0/locales/en-us) estrutura a ser convertido em um valor de data/hora e copiado no novo `CTime` objeto.  
  
 *FT*  
 Um [FILETIME](https://www.microsoftonedoc.com/#/organizations/e6f6a65cf14f462597b64ac058dbe1d0/projects/3fedad16-eaf1-41a6-8f96-0c1949c68f32/containers/a3daf831-1c5f-4bbe-964d-503870caf874/tocpaths/979ce746-dc17-4147-89f8-41d05c5fcc5f/locales/en-us) estrutura a ser convertido em um valor de data/hora e copiado no novo `CTime` objeto.  
  
 DBTS  
 Uma referência a uma estrutura DBTIMESTAMP que contém a hora local atual.  
  
### <a name="remarks"></a>Comentários  
 Cada construtor é descrita abaixo:  
  
- `CTime();` Constrói um não inicializado `CTime` objeto. Este construtor permite que você defina `CTime` matrizes de objeto. Você deve inicializar tais matrizes com horas válidas antes de usar.  
  
- `CTime( const CTime& );` Constrói uma `CTime` objeto de outro `CTime` valor.  
  
- `CTime( __time64_t );` Constrói uma `CTime` do objeto de um **__time64_t** tipo. Este construtor espera que uma hora UTC e converte o resultado em uma hora local antes de armazenar o resultado.  
  
- `CTime( int, int, ...);` Constrói um `CTime` objeto a partir de componentes de hora local com cada componente restrita para os seguintes intervalos:  
  
    |Componente|Intervalo|  
    |---------------|-----------|  
    |*nYear*|1970-3000|  
    |*nMonth*|1-12|  
    |*nDay*|1-31|  
    |*Nhora*|0-23|  
    |*Nmín*|0-59|  
    |*nSec*|0-59|  
  
     Este construtor faz a conversão apropriada para UTC. A versão de depuração da biblioteca de classes Microsoft Foundation declara se um ou mais dos componentes do tempo estão fora do intervalo. Você deve validar os argumentos antes de chamar. Este construtor espera uma hora local.  
  
- `CTime( WORD, WORD );` Constrói um `CTime` objeto entre os valores de data e hora de MS-DOS especificados. Este construtor espera uma hora local.  
  
- `CTime( const SYSTEMTIME& );` Constrói uma `CTime` do objeto de um `SYSTEMTIME` estrutura. Este construtor espera uma hora local.  
  
- `CTime( const FILETIME& );` Constrói uma `CTime` do objeto de um `FILETIME` estrutura. Você provavelmente não usará `CTime FILETIME` inicialização diretamente. Se você usar um `CFile` objeto para manipular um arquivo `CFile::GetStatus` recupera o carimbo de data / hora do arquivo para você por meio de uma `CTime` objeto inicializado com um `FILETIME` estrutura. Este construtor assume um tempo com base em UTC e converte automaticamente o valor para a hora local antes de armazenar o resultado.  
  
    > [!NOTE]
    >  O construtor usando `DBTIMESTAMP` parâmetro está disponível apenas quando OLEDB é incluído.  
  
 Para obter mais informações, consulte o [SYSTEMTIME](http://msdn.microsoft.com/library/windows/desktop/ms724950) e [FILETIME](http://msdn.microsoft.com/library/windows/desktop/ms724284) estrutura no SDK do Windows. Consulte também o [MS-DOS data e hora](http://msdn.microsoft.com/library/windows/desktop/ms724503) entrada no SDK do Windows.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_ATLMFC_Utilities#148](../../atl-mfc-shared/codesnippet/cpp/ctime-class_2.cpp)]  
  
##  <a name="format"></a>  CTime::Format  
 Chame essa função de membro para criar uma representação formatada do valor de data e hora.  
  
```  
CString Format(LPCTSTR pszFormat) const; 
CString Format(UINT nFormatID) const; 
```  
  
### <a name="parameters"></a>Parâmetros  
 *pszFormat*  
 Uma formatação de cadeia de caracteres semelhante ao `printf` cadeia de caracteres de formatação. Códigos de formatação, precedidos por uma porcentagem (`%`) entre, são substituídos por correspondente `CTime` componente. Outros caracteres na cadeia de caracteres de formatação são copiados sem alterações para a cadeia de caracteres retornada. Consulte a função de tempo de execução [strftime](../../c-runtime-library/reference/strftime-wcsftime-strftime-l-wcsftime-l.md) para obter uma lista de códigos de formatação.  
  
 *nFormatID*  
 A ID da cadeia de caracteres que identifica esse formato.  
  
### <a name="return-value"></a>Valor de retorno  
 Um [CString](../../atl-mfc-shared/reference/cstringt-class.md) que contém a hora formatada.  
  
### <a name="remarks"></a>Comentários  
 Se o status deste `CTime` objeto for nulo, o valor retornado é uma cadeia de caracteres vazia.  
  
 Esse método gera uma exceção se o valor de data e hora para o formato não varia de 1 de janeiro de 1970, por meio de 31 de dezembro de 3000 meia-noite horário coordenado Universal (UTC).  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_ATLMFC_Utilities#149](../../atl-mfc-shared/codesnippet/cpp/ctime-class_3.cpp)]  
  
##  <a name="formatgmt"></a>  CTime::FormatGmt  
 Gera uma cadeia de caracteres formatada que corresponde a este `CTime` objeto.  
  
```  
CString FormatGmt(LPCTSTR pszFormat) const; 
CString FormatGmt(UINT nFormatID) const; 
```  
  
### <a name="parameters"></a>Parâmetros  
 *pszFormat*  
 Especifica uma cadeia de formatação semelhante ao `printf` cadeia de caracteres de formatação. Consulte a função de tempo de execução [strftime](../../c-runtime-library/reference/strftime-wcsftime-strftime-l-wcsftime-l.md) para obter detalhes.  
  
 *nFormatID*  
 A ID da cadeia de caracteres que identifica esse formato.  
  
### <a name="return-value"></a>Valor de retorno  
 Um [CString](../../atl-mfc-shared/reference/cstringt-class.md) que contém a hora formatada.  
  
### <a name="remarks"></a>Comentários  
 O valor de tempo não é convertido e, portanto, reflete o UTC.  
  
 Esse método gera uma exceção se o valor de data e hora para o formato não varia de 1 de janeiro de 1970, por meio de 31 de dezembro de 3000 meia-noite horário coordenado Universal (UTC).  
  
### <a name="example"></a>Exemplo  
 Veja o exemplo de [CTime::Format](#format).  
  
##  <a name="getasdbtimestamp"></a>  CTime::GetAsDBTIMESTAMP  
 Chame essa função de membro para converter as informações de hora armazenadas no `CTime` objeto a uma estrutura compatível com o Win32 DBTIMESTAMP.  
  
```  
bool GetAsDBTIMESTAMP(DBTIMESTAMP& dbts) const throw();
```  
  
### <a name="parameters"></a>Parâmetros  
 *DBTS*  
 Uma referência a uma estrutura DBTIMESTAMP que contém a hora local atual.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se bem-sucedido; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Armazena a hora resultante em referenciado *dbts* estrutura. O `DBTIMESTAMP` estrutura de dados inicializada por essa função terá seu `fraction` membro definido como zero.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_ATLMFC_Utilities#150](../../atl-mfc-shared/codesnippet/cpp/ctime-class_4.cpp)]  
  
##  <a name="getassystemtime"></a>  CTime::GetAsSystemTime  
 Chame essa função de membro para converter as informações de hora armazenadas na `CTime` objeto para uma compatível com o Win32 [SYSTEMTIME](http://msdn.microsoft.com/library/windows/desktop/ms724950) estrutura.  
  
```  
bool GetAsSystemTime(SYSTEMTIME& st) const throw();
```  
  
### <a name="parameters"></a>Parâmetros  
 *timeDest*  
 Uma referência a um [SYSTEMTIME](http://msdn.microsoft.com/library/windows/desktop/ms724950) estrutura que conterá o valor de data/hora convertido do `CTime` objeto.  
  
### <a name="return-value"></a>Valor de retorno  
 VERDADEIRO se bem-sucedido; Caso contrário, FALSE.  
  
### <a name="remarks"></a>Comentários  
 `GetAsSystemTime` armazena a hora resultante em referenciado *timeDest* estrutura. O `SYSTEMTIME` estrutura de dados inicializada por essa função terá seu `wMilliseconds` membro definido como zero.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_ATLMFC_Utilities#151](../../atl-mfc-shared/codesnippet/cpp/ctime-class_5.cpp)]  
  
##  <a name="getcurrenttime"></a>  CTime::GetCurrentTime  
 Retorna um `CTime` objeto que representa a hora atual.  
  
```  
static CTime WINAPI GetCurrentTime() throw();
```  
  
### <a name="remarks"></a>Comentários  
 Retorna a data atual do sistema e a hora em tempo Universal Coordenado (UTC).  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_ATLMFC_Utilities#152](../../atl-mfc-shared/codesnippet/cpp/ctime-class_6.cpp)]  
  
##  <a name="getday"></a>  CTime::GetDay  
 Retorna representam o dia, o `CTime` objeto.  
  
```  
int GetDay() const throw(); 
```  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna o dia do mês, com base na hora local, no intervalo de 1 a 31.  
  
### <a name="remarks"></a>Comentários  
 Essa função chama `GetLocalTm`, que usa um buffer alocado estaticamente interno. Os dados nesse buffer são substituídos por chamadas para outros `CTime` funções de membro.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_ATLMFC_Utilities#153](../../atl-mfc-shared/codesnippet/cpp/ctime-class_7.cpp)]  
  
##  <a name="getdayofweek"></a>  CTime::GetDayOfWeek  
 Retorna o dia da semana representado pelo `CTime` objeto.  
  
```  
int GetDayOfWeek() const throw(); 
```  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna o dia da semana com base na hora local; 1 = domingo, 2 = segunda-feira, 7 = sábado.  
  
### <a name="remarks"></a>Comentários  
 Essa função chama `GetLocalTm`, que usa um interno estaticamente o buffer alocado. Os dados nesse buffer são substituídos por chamadas para outros `CTime` funções de membro.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_ATLMFC_Utilities#154](../../atl-mfc-shared/codesnippet/cpp/ctime-class_8.cpp)]  
  
##  <a name="getgmttm"></a>  CTime::GetGmtTm  
 Obtém uma **struct tm** que contém uma Decomposição de tempo contido nesse `CTime` objeto.  
  
```  
struct tm* GetGmtTm(struct tm* ptm) const; 
```  
  
### <a name="parameters"></a>Parâmetros  
 *ptm*  
 Aponta para um buffer que receberá os dados de tempo. Se esse ponteiro seja NULL, uma exceção é lançada.  
  
### <a name="return-value"></a>Valor de retorno  
 Um ponteiro para um preenchido **struct tm** conforme definido no arquivo de inclusão tempo. H. Ver [gmtime, _gmtime32, _gmtime64](../../c-runtime-library/reference/gmtime-gmtime32-gmtime64.md) para o layout da estrutura.  
  
### <a name="remarks"></a>Comentários  
 `GetGmtTm` Retorna o UTC.  
  
 *ptm* não pode ser NULL. Se você deseja reverter para o comportamento antigo, na qual *ptm* pode ser nulo para indicar que um interno, buffer alocado estaticamente deve ser usado, em seguida, excluir definições de _SECURE_ATL.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_ATLMFC_Utilities#155](../../atl-mfc-shared/codesnippet/cpp/ctime-class_9.cpp)]  
  
##  <a name="gethour"></a>  CTime::GetHour  
 Retorna a hora representada pelo `CTime` objeto.  
  
```  
int GetHour() const throw(); 
```  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna a hora, com base na hora local, no intervalo de 0 a 23.  
  
### <a name="remarks"></a>Comentários  
 Essa função chama `GetLocalTm`, que usa um interno estaticamente o buffer alocado. Os dados nesse buffer são substituídos por chamadas para outros `CTime` funções de membro.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_ATLMFC_Utilities#156](../../atl-mfc-shared/codesnippet/cpp/ctime-class_10.cpp)]  
  
##  <a name="getlocaltm"></a>  CTime::GetLocalTm  
 Obtém uma **struct tm** que contém uma Decomposição de tempo contido nesse `CTime` objeto.  
  
```  
struct tm* GetLocalTm(struct tm* ptm) const; 
```  
  
### <a name="parameters"></a>Parâmetros  
 *ptm*  
 Aponta para um buffer que receberá os dados de tempo. Se esse ponteiro seja NULL, uma exceção é lançada.  
  
### <a name="return-value"></a>Valor de retorno  
 Um ponteiro para um preenchido **struct tm** conforme definido no arquivo de inclusão tempo. H. Ver [gmtime, _gmtime32, _gmtime64](../../c-runtime-library/reference/gmtime-gmtime32-gmtime64.md) para o layout da estrutura.  
  
### <a name="remarks"></a>Comentários  
 `GetLocalTm` Retorna a hora local.  
  
 *ptm* não pode ser NULL. Se você deseja reverter para o comportamento antigo, na qual *ptm* pode ser nulo para indicar que um interno, buffer alocado estaticamente deve ser usado, em seguida, excluir definições de _SECURE_ATL.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_ATLMFC_Utilities#157](../../atl-mfc-shared/codesnippet/cpp/ctime-class_11.cpp)]  
  
##  <a name="getminute"></a>  CTime::GetMinute  
 Retorna o minuto representado pelo `CTime` objeto.  
  
```  
int GetMinute() const throw(); 
```  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna o minuto, com base na hora local, no intervalo de 0 a 59.  
  
### <a name="remarks"></a>Comentários  
 Essa função chama `GetLocalTm`, que usa um interno estaticamente o buffer alocado. Os dados nesse buffer são substituídos por chamadas para outros `CTime` funções de membro.  
  
### <a name="example"></a>Exemplo  
 Veja o exemplo de [GetHour](#gethour).  
  
##  <a name="getmonth"></a>  CTime::GetMonth  
 Retorna o mês representado pelo `CTime` objeto.  
  
```  
int GetMonth() const throw(); 
```  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna o mês, com base na hora local, no intervalo de 1 a 12 (1 = janeiro).  
  
### <a name="remarks"></a>Comentários  
 Essa função chama `GetLocalTm`, que usa um interno estaticamente o buffer alocado. Os dados nesse buffer são substituídos por chamadas para outros `CTime` funções de membro.  
  
### <a name="example"></a>Exemplo  
 Veja o exemplo de [GetDay](#getday).  
  
##  <a name="getsecond"></a>  CTime::GetSecond  
 Retorna o segundo, representado pelo `CTime` objeto.  
  
```  
int GetSecond() const throw(); 
```  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna o segundo, com base na hora local, no intervalo de 0 a 59.  
  
### <a name="remarks"></a>Comentários  
 Essa função chama `GetLocalTm`, que usa um interno estaticamente o buffer alocado. Os dados nesse buffer são substituídos por chamadas para outros `CTime` funções de membro.  
  
### <a name="example"></a>Exemplo  
 Veja o exemplo de [GetHour](#gethour).  
  
##  <a name="gettime"></a>  CTime::GetTime  
 Retorna um **__time64_t** valor para o determinado `CTime` objeto.  
  
```  
__time64_t GetTime() const throw(); 
```  
  
### <a name="return-value"></a>Valor de retorno  
 `GetTime` retornará o número de segundos entre atual `CTime` objeto e 1º de janeiro de 1970.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_ATLMFC_Utilities#158](../../atl-mfc-shared/codesnippet/cpp/ctime-class_12.cpp)]  
  
##  <a name="getyear"></a>  CTime::GetYear  
 Retorna o ano que representa o `CTime` objeto.  
  
```  
int GetYear();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna o ano, com base na hora local, no intervalo de janeiro 1,1970 para 18 de janeiro de de 2038 (inclusivo).  
  
### <a name="remarks"></a>Comentários  
 Essa função chama `GetLocalTm`, que usa um interno estaticamente o buffer alocado. Os dados nesse buffer são substituídos por chamadas para outros `CTime` funções de membro.  
  
### <a name="example"></a>Exemplo  
 Veja o exemplo de [GetDay](#getday).  
  
##  <a name="operator_eq"></a>  CTime::operator =  
 O operador de atribuição.  
  
```  
CTime& operator=(__time64_t time) throw();
```  
  
### <a name="parameters"></a>Parâmetros  
 *time*  
 O valor de data/hora de novo.  
  
### <a name="return-value"></a>Valor de retorno  
 Atualizado `CTime` objeto.  
  
### <a name="remarks"></a>Comentários  
 Esse operador de atribuição sobrecarregados copia a fonte de tempo para isso `CTime` objeto. O armazenamento interno do tempo em um `CTime` objeto é independente do fuso horário. Conversão de fuso horário não é necessário durante a atribuição.  
  
##  <a name="operator_add_-"></a>  CTime::operator +, -  
 Esses operadores adicionar e subtrair `CTimeSpan` e `CTime` objetos.  
  
```  
CTime operator+(CTimeSpan timeSpan) const throw(); 
CTime operator-(CTimeSpan timeSpan) const throw(); 
CTimeSpan operator-(CTime time) const throw(); 
```  
  
### <a name="parameters"></a>Parâmetros  
 *intervalo de tempo*  
 O `CTimeSpan` objeto a ser adicionado ou subtraído.  
  
 *time*  
 O `CTime` objeto a ser subtraído.  
  
### <a name="return-value"></a>Valor de retorno  
 Um `CTime` ou `CTimeSpan` objeto que representa o resultado da operação.  
  
### <a name="remarks"></a>Comentários  
 `CTime` os objetos representam o tempo absoluto, `CTimeSpan` objetos representam o tempo relativo. Os primeiros dois operadores permitem que você adicionar e subtrair `CTimeSpan` objetos do `CTime` objetos. O terceiro operador permite que você subtrair um `CTime` objeto de outro para produzir um `CTimeSpan` objeto.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_ATLMFC_Utilities#159](../../atl-mfc-shared/codesnippet/cpp/ctime-class_13.cpp)]  
  
##  <a name="operator_add_eq_-_eq"></a>  + = De CTime::operator-=  
 Esses operadores adicionar e subtrair um `CTimeSpan` objeto e para isso `CTime` objeto.  
  
```  
CTime& operator+=(CTimeSpan span) throw();
CTime& operator-=(CTimeSpan span) throw();
```  
  
### <a name="parameters"></a>Parâmetros  
 *SPAN*  
 O `CTimeSpan` objeto a ser adicionado ou subtraído.  
  
### <a name="return-value"></a>Valor de retorno  
 Atualizado `CTime` objeto.  
  
### <a name="remarks"></a>Comentários  
 Esses operadores permitem que você adicionar e subtrair um `CTimeSpan` objeto e para isso `CTime` objeto.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_ATLMFC_Utilities#160](../../atl-mfc-shared/codesnippet/cpp/ctime-class_14.cpp)]  
  
##  <a name="serialize64"></a>  CTime::Serialize64  
  
> [!NOTE]
>  Esse método só está disponível em projetos MFC.  
  
 Serializa os dados associados com a variável de membro para ou de um arquivo morto.  
  
```  
CArchive& Serialize64(CArchive& ar);
```  
  
### <a name="parameters"></a>Parâmetros  
 *ar*  
 O `CArchive` objeto que você deseja atualizar.  
  
### <a name="return-value"></a>Valor de retorno  
 Atualizado `CArchive` objeto.  
  
## <a name="see-also"></a>Consulte também  
 [asctime_s, _wasctime_s](../../c-runtime-library/reference/asctime-s-wasctime-s.md)   
 [ftime_s, _ftime32_s, _ftime64_s](../../c-runtime-library/reference/ftime-s-ftime32-s-ftime64-s.md)   
 [gmtime_s, _gmtime32_s, _gmtime64_s](../../c-runtime-library/reference/gmtime-s-gmtime32-s-gmtime64-s.md)   
 [localtime_s, _localtime32_s, _localtime64_s](../../c-runtime-library/reference/localtime-s-localtime32-s-localtime64-s.md)   
 [strftime, wcsftime, _strftime_l, _wcsftime_l](../../c-runtime-library/reference/strftime-wcsftime-strftime-l-wcsftime-l.md)   
 [time, _time32, _time64](../../c-runtime-library/reference/time-time32-time64.md)   
 [Classe CTimeSpan](../../atl-mfc-shared/reference/ctimespan-class.md)   
 [Gráfico da hierarquia](../../mfc/hierarchy-chart.md)   
 [Classes compartilhadas ATL/MFC](../../atl-mfc-shared/atl-mfc-shared-classes.md)


