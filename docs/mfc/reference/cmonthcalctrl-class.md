---
title: Classe CMonthCalCtrl | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- CMonthCalCtrl
dev_langs:
- C++
helpviewer_keywords:
- month calendar controls, CMonthCalCtrl class
- common controls, Internet Explorer 4.0
- CMonthCalCtrl class
- Internet Explorer 4.0 common controls
- month calendar controls
ms.assetid: a42f6bd6-ab5c-4335-82f8-839982fc64a2
caps.latest.revision: 23
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
ms.openlocfilehash: 96cefbeb7692a07088f596fe08fec2bf179b98bc
ms.lasthandoff: 02/25/2017

---
# <a name="cmonthcalctrl-class"></a>Classe CMonthCalCtrl
Encapsula a funcionalidade de um controle de calendário mensal.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class CMonthCalCtrl : public CWnd  
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CMonthCalCtrl::CMonthCalCtrl](#cmonthcalctrl)|Constrói um objeto `CMonthCalCtrl`.|  
  
### <a name="public-methods"></a>Métodos Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CMonthCalCtrl::Create](#create)|Cria um controle de calendário mensal e anexa-o para o `CMonthCalCtrl` objeto.|  
|[CMonthCalCtrl::GetCalendarBorder](#getcalendarborder)|Recupera a largura da borda do controle de calendário do mês atual.|  
|[CMonthCalCtrl::GetCalendarCount](#getcalendarcount)|Recupera o número de calendários exibidos no controle de calendário do mês atual.|  
|[CMonthCalCtrl::GetCalendarGridInfo](#getcalendargridinfo)|Recupera informações sobre o controle de calendário do mês atual.|  
|[CMonthCalCtrl::GetCalID](#getcalid)|Recupera o identificador de calendário para o controle de calendário do mês atual.|  
|[CMonthCalCtrl::GetColor](#getcolor)|Obtém a cor de uma área especificada de um controle de calendário mensal.|  
|[CMonthCalCtrl::GetCurrentView](#getcurrentview)|Recupera o modo de exibição que está sendo exibido pelo controle de calendário do mês atual.|  
|[CMonthCalCtrl::GetCurSel](#getcursel)|Recupera a hora do sistema conforme indicado pela data selecionada no momento.|  
|[CMonthCalCtrl::GetFirstDayOfWeek](#getfirstdayofweek)|Obtém o primeiro dia da semana a ser exibido na coluna mais à esquerda do calendário.|  
|[CMonthCalCtrl::GetMaxSelCount](#getmaxselcount)|Recupera o atual número máximo de dias que podem ser selecionados em um controle de calendário mensal.|  
|[CMonthCalCtrl::GetMaxTodayWidth](#getmaxtodaywidth)|Recupera a largura máxima da sequência "Hoje" para o controle de calendário do mês atual.|  
|[CMonthCalCtrl::GetMinReqRect](#getminreqrect)|Recupera o tamanho mínimo necessário para mostrar um mês completo em um controle de calendário mensal.|  
|[CMonthCalCtrl::GetMonthDelta](#getmonthdelta)|Recupera a taxa de rolagem de um controle de calendário mensal.|  
|[CMonthCalCtrl::GetMonthRange](#getmonthrange)|Recupera as informações que representa os limites superior e inferior da exibição do controle de calendário um mês da data.|  
|[CMonthCalCtrl::GetRange](#getrange)|Recupera as datas de mínimas e máxima atuais definidas em um controle de calendário mensal.|  
|[CMonthCalCtrl::GetSelRange](#getselrange)|Recupera as informações de data que representa os limites superiores e inferiores do intervalo de datas selecionado atualmente pelo usuário.|  
|[CMonthCalCtrl::GetToday](#gettoday)|Recupera as informações de data para a data especificada como "hoje" para um controle de calendário mensal.|  
|[CMonthCalCtrl::HitTest](#hittest)|Determina qual seção de um controle de calendário mensal em um determinado ponto na tela.|  
|[CMonthCalCtrl::IsCenturyView](#iscenturyview)|Indica se o modo de exibição atual do controle de calendário do mês atual é o modo de exibição do século.|  
|[CMonthCalCtrl::IsDecadeView](#isdecadeview)|Indica se o modo de exibição atual do controle de calendário do mês atual é o modo de exibição da década.|  
|[CMonthCalCtrl::IsMonthView](#ismonthview)|Indica se o modo de exibição atual do controle de calendário do mês atual é o modo de exibição mês.|  
|[CMonthCalCtrl::IsYearView](#isyearview)|Indica se o modo de exibição atual do controle de calendário do mês atual é o modo de exibição de ano.|  
|[CMonthCalCtrl::SetCalendarBorder](#setcalendarborder)|Define a largura da borda do controle de calendário do mês atual.|  
|[CMonthCalCtrl::SetCalendarBorderDefault](#setcalendarborderdefault)|Define a largura padrão da borda do controle de calendário do mês atual.|  
|[CMonthCalCtrl::SetCalID](#setcalid)|Define o identificador de calendário para o controle de calendário do mês atual.|  
|[CMonthCalCtrl::SetCenturyView](#setcenturyview)|Define o controle de calendário do mês atual para mostrar a exibição do século.|  
|[CMonthCalCtrl::SetColor](#setcolor)|Define a cor de uma área especificada de um controle de calendário mensal.|  
|[CMonthCalCtrl::SetCurrentView](#setcurrentview)|Define o controle de calendário do mês atual para exibir o modo de exibição especificado.|  
|[CMonthCalCtrl::SetCurSel](#setcursel)|Define a data selecionada no momento para um controle de calendário mensal.|  
|[CMonthCalCtrl::SetDayState](#setdaystate)|Define a exibição de dias em um controle de calendário mensal.|  
|[CMonthCalCtrl::SetDecadeView](#setdecadeview)|Conjuntos de controle Calendário do mês atual para a exibição da década.|  
|[CMonthCalCtrl::SetFirstDayOfWeek](#setfirstdayofweek)|Define o dia da semana a ser exibido na coluna mais à esquerda do calendário.|  
|[CMonthCalCtrl::SetMaxSelCount](#setmaxselcount)|Define o número máximo de dias que podem ser selecionados em um controle de calendário mensal.|  
|[CMonthCalCtrl::SetMonthDelta](#setmonthdelta)|Define a taxa de rolagem de um controle de calendário mensal.|  
|[CMonthCalCtrl::SetMonthView](#setmonthview)|Define o controle de calendário do mês atual para mostrar a exibição de mês.|  
|[CMonthCalCtrl::SetRange](#setrange)|Define o mínimo e o máximo permitido de datas para um controle de calendário mensal.|  
|[CMonthCalCtrl::SetSelRange](#setselrange)|Conjuntos de controlar a seleção de um calendário do mês para um determinado intervalo de datas.|  
|[CMonthCalCtrl::SetToday](#settoday)|Define o controle de calendário para o dia atual.|  
|[CMonthCalCtrl::SetYearView](#setyearview)|Conjuntos de calendário do mês atual controlar a exibição de ano.|  
|[CMonthCalCtrl::SizeMinReq](#sizeminreq)|Controle de calendário mensal repintada ao seu tamanho mínimo, um mês.|  
|[CMonthCalCtrl::SizeRectToMin](#sizerecttomin)|Para o controle de calendário do mês atual, calcula o menor retângulo que pode conter todos os calendários que se encaixam em um retângulo especificado.|  
  
## <a name="remarks"></a>Comentários  
 O controle de calendário mensal fornece ao usuário uma interface simples de calendário, na qual o usuário pode selecionar uma data. O usuário pode alterar a exibição por:  
  
-   Rolar para trás e para frente, do mês a mês.  
  
-   Clicando no texto de hoje para exibir o dia atual (se o **MCS_NOTODAY** estilo não for usado).  
  
-   Escolher um mês ou um ano em um menu pop-up.  
  
 Você pode personalizar o mês do calendário controle aplicando uma variedade de estilos para o objeto quando você criá-lo. Esses estilos são descritos em [estilos de controle de calendário do mês](http://msdn.microsoft.com/library/windows/desktop/bb760919) no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
 O controle de calendário mensal pode exibir mais de um mês, e pode indicar dias especiais (como feriados) por negrito a data.  
  
 Para obter mais informações sobre como usar o controle de calendário mensal, consulte [CMonthCalCtrl usando](../../mfc/using-cmonthcalctrl.md).  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 [CObject](../../mfc/reference/cobject-class.md)  
  
 [CCmdTarget](../../mfc/reference/ccmdtarget-class.md)  
  
 [CWnd](../../mfc/reference/cwnd-class.md)  
  
 `CMonthCalCtrl`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxdtctl.h  
  
##  <a name="a-namecmonthcalctrla--cmonthcalctrlcmonthcalctrl"></a><a name="cmonthcalctrl"></a>CMonthCalCtrl::CMonthCalCtrl  
 Constrói um objeto `CMonthCalCtrl`.  
  
```  
CMonthCalCtrl();
```  
  
### <a name="remarks"></a>Comentários  
 Você deve chamar **criar** depois de construir o objeto.  
  
##  <a name="a-namecreatea--cmonthcalctrlcreate"></a><a name="create"></a>CMonthCalCtrl::Create  
 Cria um controle de calendário mensal e anexa-o para o `CMonthCalCtrl` objeto.  
  
```  
virtual BOOL Create(
    DWORD dwStyle,  
    const RECT& rect,  
    CWnd* pParentWnd,  
    UINT nID);

 
virtual BOOL Create(
    DWORD dwStyle,  
    const POINT& pt,  
    CWnd* pParentWnd,  
    UINT nID);
```  
  
### <a name="parameters"></a>Parâmetros  
 `dwStyle`  
 Especifica a combinação de estilos do Windows aplicada para o controle de calendário mensal. Consulte [estilos de controle de calendário do mês](http://msdn.microsoft.com/library/windows/desktop/bb760919) no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)] para obter mais informações sobre os estilos.  
  
 `rect`  
 Uma referência a um [RECT](http://msdn.microsoft.com/library/windows/desktop/dd162897) estrutura. Contém a posição e o tamanho do controle de calendário do mês.  
  
 `pt`  
 Uma referência a um [ponto](http://msdn.microsoft.com/library/windows/desktop/dd162805) estrutura que identifica o local do controle de calendário do mês.  
  
 `pParentWnd`  
 Um ponteiro para um [CWnd](../../mfc/reference/cwnd-class.md) objeto que é a janela pai do controle de calendário do mês. Ele não deve ser **nulo**.  
  
 `nID`  
 Especifica a ID do controle. do controle de calendário mensal  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se a inicialização foi bem sucedida; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Criar um mês do calendário controle em duas etapas:  
  
1.  Chamar [CMonthCalCtrl](../../mfc/reference/cmonthcalctrl-class.md) para construir uma `CMonthCalCtrl` objeto.  
  
2.  Chame essa função de membro, que cria um controle de calendário mensal e anexa-o para o `CMonthCalCtrl` objeto.  
  
 Quando você chama **criar**, os controles comuns são inicializados. A versão do **criar** você chamada determina como ele é dimensionado:  
  
-   Para que o MFC dimensione automaticamente o controle para um mês, chame a substituição que usa o `pt` parâmetro.  
  
-   Para dimensionar o controle, chame a substituição dessa função que usa o `rect` parâmetro.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFC_CMonthCalCtrl n º&1;](../../mfc/reference/codesnippet/cpp/cmonthcalctrl-class_1.cpp)]  
  
##  <a name="a-namegetcalendarbordera--cmonthcalctrlgetcalendarborder"></a><a name="getcalendarborder"></a>CMonthCalCtrl::GetCalendarBorder  
 Recupera a largura da borda do controle de calendário do mês atual.  
  
```  
int GetCalendarBorder() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 A largura da borda do controle em pixels.  
  
### <a name="remarks"></a>Comentários  
 Esse método envia o [MCM_GETCALENDARBORDER](http://msdn.microsoft.com/library/windows/desktop/bb760945) mensagem, que é descrita o [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
##  <a name="a-namegetcalendarcounta--cmonthcalctrlgetcalendarcount"></a><a name="getcalendarcount"></a>CMonthCalCtrl::GetCalendarCount  
 Recupera o número de calendários exibidos no controle de calendário do mês atual.  
  
```  
int GetCalendarCount() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 O número de calendários exibido atualmente no controle de calendário do mês. O número máximo permitido de calendários é 12.  
  
### <a name="remarks"></a>Comentários  
 Esse método envia o [MCM_GETCALENDARCOUNT](http://msdn.microsoft.com/library/windows/desktop/bb760947) mensagem, que é descrita o [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
##  <a name="a-namegetcalendargridinfoa--cmonthcalctrlgetcalendargridinfo"></a><a name="getcalendargridinfo"></a>CMonthCalCtrl::GetCalendarGridInfo  
 Recupera informações sobre o controle de calendário do mês atual.  
  
```  
BOOL GetCalendarGridInfo(PMCGRIDINFO pmcGridInfo) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
  
|Parâmetro|Descrição|  
|---------------|-----------------|  
|[out] `pmcGridInfo`|Ponteiro para uma [MCGRIDINFO](http://msdn.microsoft.com/library/windows/desktop/bb760925) estrutura que recebe informações sobre o controle de calendário do mês atual. O chamador é responsável por alocar e inicializando essa estrutura.|  
  
### <a name="return-value"></a>Valor de retorno  
 `true`Se esse método for bem-sucedida; Caso contrário, `false`.  
  
### <a name="remarks"></a>Comentários  
 Esse método envia o [MCM_GETCALENDARGRIDINFO](http://msdn.microsoft.com/library/windows/desktop/bb760949) mensagem, que é descrita o [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
### <a name="example"></a>Exemplo  
 O exemplo de código a seguir define a variável `m_monthCalCtrl`, que é usado para acessar programaticamente o controle de calendário mensal. Essa variável é usada no exemplo a seguir.  
  
 [!code-cpp[NVC_MFC_CMonthCalCtrl_s1 n º&9;](../../mfc/reference/codesnippet/cpp/cmonthcalctrl-class_2.h)]  
  
### <a name="example"></a>Exemplo  
 O seguinte exemplo de código usa o `GetCalendarGridInfo` método para recuperar a data do calendário que exibe o controle de calendário do mês atual.  
  
 [!code-cpp[NVC_MFC_CMonthCalCtrl_s1 n º&3;](../../mfc/reference/codesnippet/cpp/cmonthcalctrl-class_3.cpp)]  
  
##  <a name="a-namegetcalida--cmonthcalctrlgetcalid"></a><a name="getcalid"></a>CMonthCalCtrl::GetCalID  
 Recupera o identificador de calendário para o controle de calendário do mês atual.  
  
```  
CALID GetCalID() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um do [identificador de calendário](http://msdn.microsoft.com/library/windows/desktop/dd317732) constantes.  
  
### <a name="remarks"></a>Comentários  
 Um identificador de calendário denota um calendário específico de região, como o calendário Gregoriano (localizado), japonês ou islâmico calendários. Seu aplicativo pode usar um identificador de calendário que tem vários idiomas oferecem suporte a funções.  
  
 Esse método envia o [MCM_GETCALID](http://msdn.microsoft.com/library/windows/desktop/bb760951) mensagem, que é descrita o [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
##  <a name="a-namegetcolora--cmonthcalctrlgetcolor"></a><a name="getcolor"></a>CMonthCalCtrl::GetColor  
 Recupera a cor de uma área do mês do calendário controle especificado pelo `nRegion`.  
  
```  
COLORREF GetColor(int nRegion) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 `nRegion`  
 A região do controle de calendário de mês do que a cor é recuperada. Para obter uma lista de valores, consulte o `nRegion` parâmetro do [SetColor](#setcolor).  
  
### <a name="return-value"></a>Valor de retorno  
 A [COLORREF](http://msdn.microsoft.com/library/windows/desktop/dd183449) valor que especifica a cor associada a parte do controle de calendário mensal, se for bem-sucedido. Caso contrário, essa função membro retorna -1.  
  
##  <a name="a-namegetcurrentviewa--cmonthcalctrlgetcurrentview"></a><a name="getcurrentview"></a>CMonthCalCtrl::GetCurrentView  
 Recupera o modo de exibição que está sendo exibido pelo controle de calendário do mês atual.  
  
```  
DWORD GetCurrentView() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 O modo de exibição atual, que é indicado por um dos seguintes valores:  
  
|Valor|Significado|  
|-----------|-------------|  
|`MCMV_MONTH`|Exibição mensal|  
|`MCMV_YEAR`|Modo de exibição anual|  
|`MCMV_DECADE`|Exibição da década|  
|`MCMV_CENTURY`|Exibição do século|  
  
### <a name="remarks"></a>Comentários  
 Esse método envia o [MCM_GETCURRENTVIEW](http://msdn.microsoft.com/library/windows/desktop/bb760955) mensagem, que é descrita o [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
### <a name="example"></a>Exemplo  
 O exemplo de código a seguir define a variável `m_monthCalCtrl`, que é usado para acessar programaticamente o controle de calendário mensal. Essa variável é usada no exemplo a seguir.  
  
 [!code-cpp[NVC_MFC_CMonthCalCtrl_s1 n º&9;](../../mfc/reference/codesnippet/cpp/cmonthcalctrl-class_2.h)]  
  
### <a name="example"></a>Exemplo  
 Os seguintes relatórios de exemplo de código que exibirem o calendário do mês no momento do controle exibe.  
  
 [!code-cpp[NVC_MFC_CMonthCalCtrl_s&#1;7](../../mfc/reference/codesnippet/cpp/cmonthcalctrl-class_4.cpp)]  
  
##  <a name="a-namegetcursela--cmonthcalctrlgetcursel"></a><a name="getcursel"></a>CMonthCalCtrl::GetCurSel  
 Recupera a hora do sistema conforme indicado pela data selecionada no momento.  
  
```  
BOOL GetCurSel(COleDateTime& refDateTime) const;  BOOL GetCurSel(CTime& refDateTime) const;  
   
BOOL GetCurSel(LPSYSTEMTIME pDateTime) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 `refDateTime`  
 Uma referência a um [COleDateTime](../../atl-mfc-shared/reference/coledatetime-class.md) objeto ou um [CTime](../../atl-mfc-shared/reference/ctime-class.md) objeto. Recebe a hora atual.  
  
 `pDateTime`  
 Um ponteiro para um [SYSTEMTIME](http://msdn.microsoft.com/library/windows/desktop/ms724950) estrutura que receberá as informações de data selecionado no momento. Esse parâmetro deve ser um endereço válido e não pode ser **nulo**.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se for bem-sucedida; otherwize 0.  
  
### <a name="remarks"></a>Comentários  
 Essa função de membro implementa o comportamento da mensagem Win32 [MCM_GETCURSEL](http://msdn.microsoft.com/library/windows/desktop/bb760957), conforme descrito na [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
> [!NOTE]
>  Essa função de membro falhará se o estilo **MCS_MULTISELECT** está definido.  
  
 Na implementação do MFC `GetCurSel`, você pode especificar um `COleDateTime` uso, uma `CTime` uso, ou um `SYSTEMTIME` uso de estrutura.  
  
##  <a name="a-namegetfirstdayofweeka--cmonthcalctrlgetfirstdayofweek"></a><a name="getfirstdayofweek"></a>CMonthCalCtrl::GetFirstDayOfWeek  
 Obtém o primeiro dia da semana a ser exibido na coluna mais à esquerda do calendário.  
  
```  
int GetFirstDayOfWeek(BOOL* pbLocal = NULL) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 *pbLocal*  
 Um ponteiro para um **BOOL** valor. Se o valor for diferente de zero, a configuração do controle não corresponder à configuração no painel de controle.  
  
### <a name="return-value"></a>Valor de retorno  
 Um valor inteiro que representa o primeiro dia da semana. Consulte **comentários** para obter mais informações sobre o que representam esses inteiros.  
  
### <a name="remarks"></a>Comentários  
 Essa função de membro implementa o comportamento da mensagem Win32 [MCM_GETFIRSTDAYOFWEEK](http://msdn.microsoft.com/library/windows/desktop/bb760958), conforme descrito na [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)]. Os dias da semana são representados como números inteiros, da seguinte maneira.  
  
|Valor|Dia da semana|  
|-----------|---------------------|  
|0|Segunda-feira|  
|1|Terça-feira|  
|2|Quarta-feira|  
|3|Quinta-feira|  
|4|Sexta-feira|  
|5|Sábado|  
|6|Domingo|  
  
### <a name="example"></a>Exemplo  
  Veja o exemplo de [CMonthCalCtrl::SetFirstDayOfWeek](#setfirstdayofweek).  
  
##  <a name="a-namegetmaxselcounta--cmonthcalctrlgetmaxselcount"></a><a name="getmaxselcount"></a>CMonthCalCtrl::GetMaxSelCount  
 Recupera o atual número máximo de dias que podem ser selecionados em um controle de calendário mensal.  
  
```  
int GetMaxSelCount() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um valor inteiro que representa o número total de dias que podem ser selecionadas para o controle.  
  
### <a name="remarks"></a>Comentários  
 Essa função de membro implementa o comportamento da mensagem Win32 [MCM_GETMAXSELCOUNT](http://msdn.microsoft.com/library/windows/desktop/bb760960), conforme descrito na [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)]. Use esta função de membro para controles com o **MCS_MULTISELECT** conjunto de estilos.  
  
### <a name="example"></a>Exemplo  
  Veja o exemplo de [CMonthCalCtrl::SetMaxSelCount](#setmaxselcount).  
  
##  <a name="a-namegetmaxtodaywidtha--cmonthcalctrlgetmaxtodaywidth"></a><a name="getmaxtodaywidth"></a>CMonthCalCtrl::GetMaxTodayWidth  
 Recupera a largura máxima da sequência "Hoje" para o controle de calendário do mês atual.  
  
```  
DWORD GetMaxTodayWidth() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 A largura da cadeia "Hoje", em pixels.  
  
### <a name="example"></a>Exemplo  
 O exemplo de código a seguir define a variável `m_monthCalCtrl`, que é usado para acessar programaticamente o controle de calendário mensal. Essa variável é usada no exemplo a seguir.  
  
 [!code-cpp[NVC_MFC_CMonthCalCtrl_s1 n º&9;](../../mfc/reference/codesnippet/cpp/cmonthcalctrl-class_2.h)]  
  
### <a name="example"></a>Exemplo  
 O exemplo de código a seguir demonstra o `GetMaxTodayWidth` método.  
  
 [!code-cpp[NVC_MFC_CMonthCalCtrl_s1 n º&1;](../../mfc/reference/codesnippet/cpp/cmonthcalctrl-class_5.cpp)]  
  
### <a name="remarks"></a>Comentários  
 O usuário pode retornar para a data atual clicando em sequência "Hoje", que é exibida na parte inferior do controle de calendário do mês. A cadeia de caracteres "Hoje" inclui o texto do rótulo e texto de data.  
  
 Esse método envia o [MCM_GETMAXTODAYWIDTH](http://msdn.microsoft.com/library/windows/desktop/bb760962) mensagem, que é descrita o [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
##  <a name="a-namegetminreqrecta--cmonthcalctrlgetminreqrect"></a><a name="getminreqrect"></a>CMonthCalCtrl::GetMinReqRect  
 Recupera o tamanho mínimo necessário para mostrar um mês completo em um controle de calendário mensal.  
  
```  
BOOL GetMinReqRect(RECT* pRect) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 `pRect`  
 Um ponteiro para um [RECT](http://msdn.microsoft.com/library/windows/desktop/dd162897) estrutura que receberá informações de retângulo delimitador. Esse parâmetro deve ser um endereço válido e não pode ser **nulo**.  
  
### <a name="return-value"></a>Valor de retorno  
 Se for bem-sucedida, essa função membro retorna zero e `lpRect` recebe informações delimitadoras. Se não for bem-sucedida, a função de membro retorna 0.  
  
### <a name="remarks"></a>Comentários  
 Essa função de membro implementa o comportamento da mensagem Win32 [MCM_GETMINREQRECT](http://msdn.microsoft.com/library/windows/desktop/bb760978), conforme descrito na [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
##  <a name="a-namegetmonthdeltaa--cmonthcalctrlgetmonthdelta"></a><a name="getmonthdelta"></a>CMonthCalCtrl::GetMonthDelta  
 Recupera a taxa de rolagem de um controle de calendário mensal.  
  
```  
int GetMonthDelta() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 A taxa de rolagem para o controle de calendário mensal. A taxa de rolagem é o número de meses que o controle se move sua exibição quando o usuário clica em um botão de rolagem uma vez.  
  
### <a name="remarks"></a>Comentários  
 Essa função de membro implementa o comportamento da mensagem Win32 [MCM_GETMONTHDELTA](http://msdn.microsoft.com/library/windows/desktop/bb760980), conforme descrito na [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
##  <a name="a-namegetmonthrangea--cmonthcalctrlgetmonthrange"></a><a name="getmonthrange"></a>CMonthCalCtrl::GetMonthRange  
 Recupera as informações que representa os limites superior e inferior da exibição do controle de calendário um mês da data.  
  
```  
int GetMonthRange(
    COleDateTime& refMinRange,  
    COleDateTime& refMaxRange,  
    DWORD dwFlags) const;  
  
int GetMonthRange(
    CTime& refMinRange,  
    CTime& refMaxRange,  
    DWORD dwFlags) const;  
  
int GetMonthRange(
    LPSYSTEMTIME pMinRange,  
    LPSYSTEMTIME pMaxRange,  
    DWORD dwFlags) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 `refMinRange`  
 Uma referência a um [COleDateTime](../../atl-mfc-shared/reference/coledatetime-class.md) ou [CTime](../../atl-mfc-shared/reference/ctime-class.md) objeto que contém a data mínima permitida.  
  
 `refMaxRange`  
 Uma referência a um `COleDateTime` ou `CTime` objeto que contém a data máxima permitida.  
  
 `pMinRange`  
 Um ponteiro para um [SYSTEMTIME](http://msdn.microsoft.com/library/windows/desktop/ms724950) estrutura que contém a data final mais baixo do intervalo.  
  
 `pMaxRange`  
 Um ponteiro para um `SYSTEMTIME` estrutura que contém a data final mais alto do intervalo.  
  
 `dwFlags`  
 Valor que especifica o escopo dos limites de intervalo a ser recuperado. Esse valor deve ser um destes procedimentos.  
  
|Valor|Significado|  
|-----------|-------------|  
|GMR_DAYSTATE|Inclua anteriores e à direita meses do intervalo visível que são exibidos apenas parcialmente.|  
|GMR_VISIBLE|Inclua apenas esses meses totalmente exibidos.|  
  
### <a name="return-value"></a>Valor de retorno  
 Um inteiro que representa o intervalo, em meses, incluídas por dois limites indicado por `refMinRange` e `refMaxRange` nas versões do primeira e segunda, ou `pMinRange` e `pMaxRange` na terceira versão.  
  
### <a name="remarks"></a>Comentários  
 Essa função de membro implementa o comportamento da mensagem Win32 [MCM_GETMONTHRANGE](http://msdn.microsoft.com/library/windows/desktop/bb760981), conforme descrito na [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)]. Na implementação do MFC `GetMonthRange`, você pode especificar `COleDateTime` uso, uma `CTime` uso, ou um `SYSTEMTIME` uso de estrutura.  
  
### <a name="example"></a>Exemplo  
  Veja o exemplo de [CMonthCalCtrl::SetDayState](#setdaystate).  
  
##  <a name="a-namegetrangea--cmonthcalctrlgetrange"></a><a name="getrange"></a>CMonthCalCtrl::GetRange  
 Recupera as datas de mínimas e máxima atuais definidas em um controle de calendário mensal.  
  
```  
DWORD GetRange(
    COleDateTime* pMinRange,  
    COleDateTime* pMaxRange) const;  
  
DWORD GetRange(
    CTime* pMinRange,  
    CTime* pMaxRange) const;  
  
DWORD GetRange(
    LPSYSTEMTIME pMinRange,  
    LPSYSTEMTIME pMaxRange) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 `pMinRange`  
 Um ponteiro para um `COleDateTime` objeto, um `CTime` objeto, ou [SYSTEMTIME](http://msdn.microsoft.com/library/windows/desktop/ms724950) estrutura que contém a data final mais baixo do intervalo.  
  
 `pMaxRange`  
 Um ponteiro para um `COleDateTime` objeto, um `CTime` objeto, ou [SYSTEMTIME](http://msdn.microsoft.com/library/windows/desktop/ms724950) estrutura que contém a data final mais alto do intervalo.  
  
### <a name="return-value"></a>Valor de retorno  
 Um `DWORD` que pode ser zero (sem limites são definidos) ou uma combinação dos seguintes valores que especificam informações de limite.  
  
|Valor|Significado|  
|-----------|-------------|  
|GDTR_MAX|Um limite máximo é definido para o controle; `pMaxRange` é válido e contém as informações de data aplicável.|  
|GDTR_MIN|Um limite mínimo é definido para o controle; `pMinRange` é válido e contém as informações de data aplicável.|  
  
### <a name="remarks"></a>Comentários  
 Essa função de membro implementa o comportamento da mensagem Win32 [MCM_GETRANGE](http://msdn.microsoft.com/library/windows/desktop/bb760983), conforme descrito na [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)]. Na implementação do MFC `GetRange`, você pode especificar um `COleDateTime` uso, uma `CTime` uso, ou um `SYSTEMTIME` uso de estrutura.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFC_CMonthCalCtrl n º&2;](../../mfc/reference/codesnippet/cpp/cmonthcalctrl-class_6.cpp)]  
  
##  <a name="a-namegetselrangea--cmonthcalctrlgetselrange"></a><a name="getselrange"></a>CMonthCalCtrl::GetSelRange  
 Recupera as informações de data que representa os limites superiores e inferiores do intervalo de datas selecionado atualmente pelo usuário.  
  
```  
BOOL GetSelRange(
    COleDateTime& refMinRange,  
    COleDateTime& refMaxRange) const;  
  
BOOL GetSelRange(
    CTime& refMinRange,  
    CTime& refMaxRange) const;  
  
BOOL GetSelRange(
    LPSYSTEMTIME pMinRange,  
    LPSYSTEMTIME pMaxRange) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 `refMinRange`  
 Uma referência a um [COleDateTime](../../atl-mfc-shared/reference/coledatetime-class.md) ou [CTime](../../atl-mfc-shared/reference/ctime-class.md) objeto que contém a data mínima permitida.  
  
 `refMaxRange`  
 Uma referência a um `COleDateTime` ou `CTime` objeto que contém a data máxima permitida.  
  
 `pMinRange`  
 Um ponteiro para um [SYSTEMTIME](http://msdn.microsoft.com/library/windows/desktop/ms724950) estrutura que contém a data final mais baixo do intervalo.  
  
 `pMaxRange`  
 Um ponteiro para um `SYSTEMTIME` estrutura que contém a data final mais alto do intervalo.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se for bem-sucedida; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Essa função de membro implementa o comportamento da mensagem Win32 [MCM_GETSELRANGE](http://msdn.microsoft.com/library/windows/desktop/bb760985), conforme descrito na [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)]. `GetSelRange`falhará se aplicada a um controle de calendário mensal que não use o **MCS_MULTISELECT** estilo.  
  
 Na implementação do MFC `GetSelRange`, você pode especificar `COleDateTime` uso, uma `CTime` uso, ou um `SYSTEMTIME` uso de estrutura.  
  
##  <a name="a-namegettodaya--cmonthcalctrlgettoday"></a><a name="gettoday"></a>CMonthCalCtrl::GetToday  
 Recupera as informações de data para a data especificada como "hoje" para um controle de calendário mensal.  
  
```  
BOOL GetToday(COleDateTime& refDateTime) const;  BOOL GetToday(COleDateTime& refDateTime) const;  
   
BOOL GetToday(LPSYSTEMTIME pDateTime) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 `refDateTime`  
 Uma referência a um [COleDateTime](../../atl-mfc-shared/reference/coledatetime-class.md) ou [CTime](../../atl-mfc-shared/reference/ctime-class.md) objeto indicando o dia atual.  
  
 `pDateTime`  
 Um ponteiro para um [SYSTEMTIME](http://msdn.microsoft.com/library/windows/desktop/ms724950) estrutura que receberá as informações de data. Esse parâmetro deve ser um endereço válido e não pode ser **nulo**.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se for bem-sucedida; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Essa função de membro implementa o comportamento da mensagem Win32 [MCM_GETTODAY](http://msdn.microsoft.com/library/windows/desktop/bb760987), conforme descrito na [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)]. Na implementação do MFC `GetToday`, você pode especificar um `COleDateTime` uso, uma `CTime` uso, ou um `SYSTEMTIME` uso de estrutura.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFC_CMonthCalCtrl n º&3;](../../mfc/reference/codesnippet/cpp/cmonthcalctrl-class_7.cpp)]  
  
##  <a name="a-namehittesta--cmonthcalctrlhittest"></a><a name="hittest"></a>CMonthCalCtrl::HitTest  
 Determina qual controle de calendário mensal, se houver, está em uma posição especificada.  
  
```  
DWORD HitTest(PMCHITTESTINFO pMCHitTest);
```  
  
### <a name="parameters"></a>Parâmetros  
 *pMCHitTest*  
 Um ponteiro para um [MCHITTESTINFO](http://msdn.microsoft.com/library/windows/desktop/bb760927) estrutura que contém o teste de hit aponta para o controle de calendário mensal.  
  
### <a name="return-value"></a>Valor de retorno  
 Um valor `DWORD`. Igual a **uHit** membro do **MCHITTESTINFO** estrutura.  
  
### <a name="remarks"></a>Comentários  
 `HitTest`usa o **MCHITTESTINFO** estrutura, que contém informações sobre o teste de clique.  
  
##  <a name="a-nameiscenturyviewa--cmonthcalctrliscenturyview"></a><a name="iscenturyview"></a>CMonthCalCtrl::IsCenturyView  
 Indica se o modo de exibição atual do controle de calendário do mês atual é o modo de exibição do século.  
  
```  
BOOL IsCenturyView() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 `true`Se o modo de exibição atual for o modo de exibição do século; Caso contrário, `false`.  
  
### <a name="remarks"></a>Comentários  
 Esse método envia o [MCM_GETCURRENTVIEW](http://msdn.microsoft.com/library/windows/desktop/bb760955) mensagem, que é descrita o [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)]. Se que mensagem retorna `MCMV_CENTURY`, esse método retornará `true`.  
  
##  <a name="a-nameisdecadeviewa--cmonthcalctrlisdecadeview"></a><a name="isdecadeview"></a>CMonthCalCtrl::IsDecadeView  
 Indica se o modo de exibição atual do controle de calendário do mês atual é o modo de exibição da década.  
  
```  
BOOL IsDecadeView() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 `true`Se o modo de exibição atual for o modo de exibição da década; Caso contrário, `false`.  
  
### <a name="remarks"></a>Comentários  
 Esse método envia o [MCM_GETCURRENTVIEW](http://msdn.microsoft.com/library/windows/desktop/bb760955) mensagem, que é descrita o [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)]. Se que mensagem retorna `MCMV_DECADE`, esse método retornará `true`.  
  
##  <a name="a-nameismonthviewa--cmonthcalctrlismonthview"></a><a name="ismonthview"></a>CMonthCalCtrl::IsMonthView  
 Indica se o modo de exibição atual do controle de calendário do mês atual é o modo de exibição mês.  
  
```  
BOOL IsMonthView() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 `true`Se o modo de exibição atual for o modo de exibição mês; Caso contrário, `false`.  
  
### <a name="remarks"></a>Comentários  
 Esse método envia o [MCM_GETCURRENTVIEW](http://msdn.microsoft.com/library/windows/desktop/bb760955) mensagem, que é descrita o [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)]. Se que mensagem retorna `MCMV_MONTH`, esse método retornará `true`.  
  
##  <a name="a-nameisyearviewa--cmonthcalctrlisyearview"></a><a name="isyearview"></a>CMonthCalCtrl::IsYearView  
 Indica se o modo de exibição atual do controle de calendário do mês atual é o modo de exibição de ano.  
  
```  
BOOL IsYearView() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 `true`Se a exibição atual é o ano; Caso contrário, `false`.  
  
### <a name="remarks"></a>Comentários  
 Esse método envia o [MCM_GETCURRENTVIEW](http://msdn.microsoft.com/library/windows/desktop/bb760955) mensagem, que é descrita o [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)]. Se que mensagem retorna `MCMV_YEAR`, esse método retornará `true`.  
  
##  <a name="a-namesetcalendarbordera--cmonthcalctrlsetcalendarborder"></a><a name="setcalendarborder"></a>CMonthCalCtrl::SetCalendarBorder  
 Define a largura da borda do controle de calendário do mês atual.  
  
```  
void SetCalendarBorder(int cxyBorder);
```  
  
### <a name="parameters"></a>Parâmetros  
  
|Parâmetro|Descrição|  
|---------------|-----------------|  
|[in] `cxyBorder`|A largura da borda, em pixels.|  
  
### <a name="remarks"></a>Comentários  
 Se esse método for bem-sucedido, a largura da borda é definida como o `cxyBorder` parâmetro. Caso contrário, a largura da borda é redefinida para o valor padrão é especificado pela atual [tema](https://msdn.microsoft.com/library/windows/desktop/hh270423.aspx), ou zero se temas não são usados.  
  
 Esse método envia o [MCM_SETCALENDARBORDER](http://msdn.microsoft.com/library/windows/desktop/bb760993) mensagem, que é descrita o [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
### <a name="example"></a>Exemplo  
 O exemplo de código a seguir define a variável `m_monthCalCtrl`, que é usado para acessar programaticamente o controle de calendário mensal. Essa variável é usada no exemplo a seguir.  
  
 [!code-cpp[NVC_MFC_CMonthCalCtrl_s1 n º&9;](../../mfc/reference/codesnippet/cpp/cmonthcalctrl-class_2.h)]  
  
### <a name="example"></a>Exemplo  
 O código exemplo seguinte define a largura da borda do calendário do mês de controle para oito pixels. Use o [CMonthCalCtrl::GetCalendarBorder](#getcalendarborder) método para determinar se esse método foi bem-sucedida.  
  
 [!code-cpp[NVC_MFC_CMonthCalCtrl_s1 n º&6;](../../mfc/reference/codesnippet/cpp/cmonthcalctrl-class_8.cpp)]  
  
##  <a name="a-namesetcalendarborderdefaulta--cmonthcalctrlsetcalendarborderdefault"></a><a name="setcalendarborderdefault"></a>CMonthCalCtrl::SetCalendarBorderDefault  
 Define a largura padrão da borda do controle de calendário do mês atual.  
  
```  
void SetCalendarBorderDefault();
```  
  
### <a name="remarks"></a>Comentários  
 A largura da borda é definida como o valor padrão especificado pelo atual [tema](https://msdn.microsoft.com/library/windows/desktop/hh270423.aspx), ou zero se temas não são usados.  
  
 Esse método envia o [MCM_SETCALENDARBORDER](http://msdn.microsoft.com/library/windows/desktop/bb760993) mensagem, que é descrita o [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
##  <a name="a-namesetcalida--cmonthcalctrlsetcalid"></a><a name="setcalid"></a>CMonthCalCtrl::SetCalID  
 Define o identificador de calendário para o controle de calendário do mês atual.  
  
```  
BOOL SetCalID(CALID calid);
```  
  
### <a name="parameters"></a>Parâmetros  
  
|Parâmetro|Descrição|  
|---------------|-----------------|  
|[in] `calid`|Um do [identificador de calendário](http://msdn.microsoft.com/library/windows/desktop/dd317732) constantes.|  
  
### <a name="return-value"></a>Valor de retorno  
 `true`Se esse método for bem-sucedida; Caso contrário, `false`.  
  
### <a name="remarks"></a>Comentários  
 Um identificador de calendário Especifica um calendário específico de região, como o calendário Gregoriano (localizado), japonês ou islâmico calendários. Use o `SetCalID` método para exibir um calendário que é especificado pelo `calid` parâmetro se a localidade que contém o calendário é instalada em seu computador.  
  
 Esse método envia o [MCM_SETCALID](http://msdn.microsoft.com/library/windows/desktop/bb760995) mensagem, que é descrita o [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
### <a name="example"></a>Exemplo  
 O exemplo de código a seguir define a variável `m_monthCalCtrl`, que é usado para acessar programaticamente o controle de calendário mensal. Essa variável é usada no exemplo a seguir.  
  
 [!code-cpp[NVC_MFC_CMonthCalCtrl_s1 n º&9;](../../mfc/reference/codesnippet/cpp/cmonthcalctrl-class_2.h)]  
  
### <a name="example"></a>Exemplo  
 O exemplo de código a seguir define o controle de calendário mensal para exibir o calendário Era imperial japonesa. O `SetCalID` método é realizada somente se o calendário é instalado em seu computador.  
  
 [!code-cpp[NVC_MFC_CMonthCalCtrl_s1 n º&4;](../../mfc/reference/codesnippet/cpp/cmonthcalctrl-class_9.cpp)]  
  
##  <a name="a-namesetcenturyviewa--cmonthcalctrlsetcenturyview"></a><a name="setcenturyview"></a>CMonthCalCtrl::SetCenturyView  
 Define o controle de calendário do mês atual para mostrar a exibição do século.  
  
```  
BOOL SetCenturyView();
```  
  
### <a name="return-value"></a>Valor de retorno  
 `true`Se esse método for bem-sucedida; Caso contrário, `false`.  
  
### <a name="remarks"></a>Comentários  
 Esse método usa o [CMonthCalCtrl::SetCurrentView](#setcurrentview) método para definir o modo de exibição `MCMV_CENTURY`, que representa o modo de exibição do século.  
  
##  <a name="a-namesetcolora--cmonthcalctrlsetcolor"></a><a name="setcolor"></a>CMonthCalCtrl::SetColor  
 Define a cor de uma área especificada de um controle de calendário mensal.  
  
```  
COLORREF SetColor(
    int nRegion,  
    COLORREF ref);
```  
  
### <a name="parameters"></a>Parâmetros  
 `nRegion`  
 Um valor inteiro que especifica a cor do calendário do mês para definir. Esse valor pode ser uma das seguintes opções:  
  
|Valor|Significado|  
|-----------|-------------|  
|MCSC_BACKGROUND|A cor de plano de fundo exibida entre meses.|  
|MCSC_MONTHBK|A cor da tela de fundo exibida no mês.|  
|MCSC_TEXT|A cor usada para exibir texto em um mês.|  
|MCSC_TITLEBK|A cor da tela de fundo exibida no título do calendário.|  
|MCSC_TITLETEXT|A cor usada para exibir texto no título do calendário.|  
|MCSC_TRAILINGTEXT|A cor usada para exibir o texto do cabeçalho e dia à direita. Dias seguinte e anterior são os dias dos meses anteriores e seguintes exibidos no calendário atual.|  
  
 `ref`  
 A **COLORREF** valor para a nova configuração de cor para a parte especificada do controle de calendário do mês.  
  
### <a name="return-value"></a>Valor de retorno  
 A **COLORREF** valor que representa a configuração de cor anterior para a parte especificada do controle de calendário mensal, se for bem-sucedido. Caso contrário, essa mensagem retorna -1.  
  
### <a name="remarks"></a>Comentários  
 Essa função de membro implementa o comportamento da mensagem Win32 [MCM_SETCOLOR](http://msdn.microsoft.com/library/windows/desktop/bb760997), conforme descrito na [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFC_CMonthCalCtrl n º&4;](../../mfc/reference/codesnippet/cpp/cmonthcalctrl-class_10.cpp)]  
  
##  <a name="a-namesetcurrentviewa--cmonthcalctrlsetcurrentview"></a><a name="setcurrentview"></a>CMonthCalCtrl::SetCurrentView  
 Define o controle de calendário do mês atual para exibir o modo de exibição especificado.  
  
```  
BOOL SetCurrentView(DWORD dwNewView);
```  
  
### <a name="parameters"></a>Parâmetros  
  
|Parâmetro|Descrição|  
|---------------|-----------------|  
|[in] `dwNewView`|Um dos valores a seguir que especifica um mensal, anual, década ou modo de exibição do século.<br /><br /> MCMV_MONTH: Exibição mensal<br /><br /> MCMV_YEAR: Modo de exibição anual<br /><br /> MCMV_DECADE: Exibição da década<br /><br /> MCMV_CENTURY: Exibição do século|  
  
### <a name="return-value"></a>Valor de retorno  
 `true`Se esse método for bem-sucedida; Caso contrário, `false`.  
  
### <a name="remarks"></a>Comentários  
 Esse método envia o [MCM_SETCURRENTVIEW](http://msdn.microsoft.com/library/windows/desktop/bb760998) mensagem, que é descrita o [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
##  <a name="a-namesetcursela--cmonthcalctrlsetcursel"></a><a name="setcursel"></a>CMonthCalCtrl::SetCurSel  
 Define a data selecionada no momento para um controle de calendário mensal.  
  
```  
BOOL SetCurSel(const COleDateTime& refDateTime);  
BOOL SetCurSel(const CTime& refDateTime);  
  BOOL SetCurSel(const LPSYSTEMTIME pDateTime);
```  
  
### <a name="parameters"></a>Parâmetros  
 `refDateTime`  
 Uma referência a um [COleDateTime](../../atl-mfc-shared/reference/coledatetime-class.md) ou [CTime](../../atl-mfc-shared/reference/ctime-class.md) objeto indicando que o controle de calendário do mês selecionado no momento.  
  
 `pDateTime`  
 Ponteiro para uma [SYSTEMTIME](http://msdn.microsoft.com/library/windows/desktop/ms724950) estrutura que contém a data a ser definida como a seleção atual.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se for bem-sucedida; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Essa função de membro implementa o comportamento da mensagem Win32 [MCM_SETCURSEL](http://msdn.microsoft.com/library/windows/desktop/bb761002), conforme descrito na [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)]. Na implementação do MFC `SetCurSel`, você pode especificar um `COleDateTime` uso, uma `CTime` uso, ou um `SYSTEMTIME` uso de estrutura.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFC_CMonthCalCtrl n º&5;](../../mfc/reference/codesnippet/cpp/cmonthcalctrl-class_11.cpp)]  
  
##  <a name="a-namesetdaystatea--cmonthcalctrlsetdaystate"></a><a name="setdaystate"></a>CMonthCalCtrl::SetDayState  
 Define a exibição de dias em um controle de calendário mensal.  
  
```  
BOOL SetDayState(
    int nMonths,  
    LPMONTHDAYSTATE pStates);
```  
  
### <a name="parameters"></a>Parâmetros  
 *nMonths*  
 Valor que indica quantos elementos na matriz que `pStates` aponta.  
  
 `pStates`  
 Um ponteiro para um [MONTHDAYSTATE](http://msdn.microsoft.com/library/windows/desktop/bb760915) matriz de valores que definem como o controle de calendário mensal desenhará a cada dia em sua exibição. O **MONTHDAYSTATE** tipo de dados é um campo de bits, onde cada bit (1 a 31) representa o estado de um dia de um mês. Se um bit estiver ativado, o dia correspondente será exibido em negrito; Caso contrário, ele será exibido com nenhuma ênfase.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se for bem-sucedida; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Essa função de membro implementa o comportamento da mensagem Win32 [MCM_SETDAYSTATE](http://msdn.microsoft.com/library/windows/desktop/bb761004), conforme descrito na [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFC_CMonthCalCtrl n º&6;](../../mfc/reference/codesnippet/cpp/cmonthcalctrl-class_12.cpp)]  
  
##  <a name="a-namesetdecadeviewa--cmonthcalctrlsetdecadeview"></a><a name="setdecadeview"></a>CMonthCalCtrl::SetDecadeView  
 Conjuntos de controle Calendário do mês atual para a exibição da década.  
  
```  
BOOL SetDecadeView();
```  
  
### <a name="return-value"></a>Valor de retorno  
 `true`Se esse método for bem-sucedida; Caso contrário, `false`.  
  
### <a name="remarks"></a>Comentários  
 Esse método usa o [CMonthCalCtrl::SetCurrentView](#setcurrentview) método para definir o modo de exibição `MCMV_DECADE`, que representa o modo de exibição da década.  
  
##  <a name="a-namesetfirstdayofweeka--cmonthcalctrlsetfirstdayofweek"></a><a name="setfirstdayofweek"></a>CMonthCalCtrl::SetFirstDayOfWeek  
 Define o dia da semana a ser exibido na coluna mais à esquerda do calendário.  
  
```  
BOOL SetFirstDayOfWeek(
    int iDay,  
    int* lpnOld = NULL);
```  
  
### <a name="parameters"></a>Parâmetros  
 *iDay*  
 Um valor inteiro que representa o dia será definido como o primeiro dia da semana. Esse valor deve ser um dos números de dias. Consulte [GetFirstDayOfWeek](#getfirstdayofweek) para obter uma descrição dos números de dias.  
  
 *lpnOld*  
 Um ponteiro para um inteiro que indica o primeiro dia da semana anteriormente definido.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se o primeiro dia da semana a anterior é definido como um valor diferente de **LOCALE_IFIRSTDAYOFWEEK**, que é o dia indicado na configuração do painel de controle. Caso contrário, essa função retorna 0.  
  
### <a name="remarks"></a>Comentários  
 Essa função de membro implementa o comportamento da mensagem Win32 [MCM_SETFIRSTDAYOFWEEK](http://msdn.microsoft.com/library/windows/desktop/bb761006), conforme descrito na [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFC_CMonthCalCtrl&#7;](../../mfc/reference/codesnippet/cpp/cmonthcalctrl-class_13.cpp)]  
  
##  <a name="a-namesetmaxselcounta--cmonthcalctrlsetmaxselcount"></a><a name="setmaxselcount"></a>CMonthCalCtrl::SetMaxSelCount  
 Define o número máximo de dias que podem ser selecionados em um controle de calendário mensal.  
  
```  
BOOL SetMaxSelCount(int nMax);
```  
  
### <a name="parameters"></a>Parâmetros  
 `nMax`  
 O valor que será definido para representar o número máximo de dias selecionáveis.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se for bem-sucedida; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Essa função de membro implementa o comportamento da mensagem Win32 [MCM_SETMAXSELCOUNT](http://msdn.microsoft.com/library/windows/desktop/bb761008), conforme descrito na [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFC_CMonthCalCtrl n º&8;](../../mfc/reference/codesnippet/cpp/cmonthcalctrl-class_14.cpp)]  
  
##  <a name="a-namesetmonthdeltaa--cmonthcalctrlsetmonthdelta"></a><a name="setmonthdelta"></a>CMonthCalCtrl::SetMonthDelta  
 Define a taxa de rolagem de um controle de calendário mensal.  
  
```  
int SetMonthDelta(int iDelta);
```  
  
### <a name="parameters"></a>Parâmetros  
 *iDelta*  
 O número de meses a ser definida como a taxa de rolagem do controle. Se esse valor for zero, o delta de mês é redefinido para o padrão, que é o número de meses exibido no controle.  
  
### <a name="return-value"></a>Valor de retorno  
 A taxa de rolagem anterior. Se a taxa de rolagem não tiver sido definida anteriormente, o valor de retorno será 0.  
  
### <a name="remarks"></a>Comentários  
 Essa função de membro implementa o comportamento da mensagem Win32 [MCM_SETMONTHDELTA](http://msdn.microsoft.com/library/windows/desktop/bb761010), conforme descrito na [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
##  <a name="a-namesetmonthviewa--cmonthcalctrlsetmonthview"></a><a name="setmonthview"></a>CMonthCalCtrl::SetMonthView  
 Define o controle de calendário do mês atual para mostrar a exibição de mês.  
  
```  
BOOL SetMonthView();
```  
  
### <a name="return-value"></a>Valor de retorno  
 `true`Se esse método for bem-sucedida; Caso contrário, `false`.  
  
### <a name="remarks"></a>Comentários  
 Esse método usa o [CMonthCalCtrl::SetCurrentView](#setcurrentview) método para definir o modo de exibição `MCMV_MONTH`, que representa o modo de exibição mês.  
  
### <a name="example"></a>Exemplo  
 O exemplo de código a seguir define a variável `m_monthCalCtrl`, que é usado para acessar programaticamente o controle de calendário mensal. Essa variável é usada no exemplo a seguir.  
  
 [!code-cpp[NVC_MFC_CMonthCalCtrl_s1 n º&9;](../../mfc/reference/codesnippet/cpp/cmonthcalctrl-class_2.h)]  
  
### <a name="example"></a>Exemplo  
 O exemplo de código a seguir define o controle de calendário mensal para exibir o mês, ano, década e modos de exibição do século.  
  
 [!code-cpp[NVC_MFC_CMonthCalCtrl_s1 n º&2;](../../mfc/reference/codesnippet/cpp/cmonthcalctrl-class_15.cpp)]  
  
##  <a name="a-namesetrangea--cmonthcalctrlsetrange"></a><a name="setrange"></a>CMonthCalCtrl::SetRange  
 Define as datas mínimas e máxima permitidas para um controle de calendário mensal.  
  
```  
BOOL SetRange(
    const COleDateTime* pMinRange,  
    const COleDateTime* pMaxRange);

 
BOOL SetRange(
    const CTime* pMinRange,  
    const CTime* pMaxRange);

 
BOOL SetRange(
    const LPSYSTEMTIME pMinRange,  
    const LPSYSTEMTIME pMaxRange);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pMinRange`  
 Um ponteiro para um `COleDateTime` objeto, um `CTime` objeto, ou [SYSTEMTIME](http://msdn.microsoft.com/library/windows/desktop/ms724950) estrutura que contém a data final mais baixo do intervalo.  
  
 `pMaxRange`  
 Um ponteiro para um `COleDateTime` objeto, um `CTime` objeto, ou `SYSTEMTIME` estrutura que contém a data final mais alto do intervalo.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se for bem-sucedida; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Essa função de membro implementa o comportamento da mensagem Win32 [MCM_SETRANGE](http://msdn.microsoft.com/library/windows/desktop/bb761012), conforme descrito na [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)]. Na implementação do MFC `SetRange`, você pode especificar `COleDateTime` uso, uma `CTime` uso, ou um `SYSTEMTIME` uso de estrutura.  
  
### <a name="example"></a>Exemplo  
  Veja o exemplo de [CMonthCalCtrl::GetRange](#getrange).  
  
##  <a name="a-namesetselrangea--cmonthcalctrlsetselrange"></a><a name="setselrange"></a>CMonthCalCtrl::SetSelRange  
 Conjuntos de controlar a seleção de um calendário do mês para um determinado intervalo de datas.  
  
```  
BOOL SetSelRange(
    const COleDateTime& pMinRange,  
    const COleDateTime& pMaxRange);

 
BOOL SetSelRange(
    const CTime& pMinRange,  
    const CTime& pMaxRange);

 
BOOL SetSelRange(
    const LPSYSTEMTIME pMinRange,  
    const LPSYSTEMTIME pMaxRange);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pMinRange`  
 Um ponteiro para um `COleDateTime` objeto, um `CTime` objeto, ou [SYSTEMTIME](http://msdn.microsoft.com/library/windows/desktop/ms724950) estrutura que contém a data final mais baixo do intervalo.  
  
 `pMaxRange`  
 Um ponteiro para um `COleDateTime` objeto, um `CTime` objeto, ou `SYSTEMTIME` estrutura que contém a data final mais alto do intervalo.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se for bem-sucedida; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Essa função de membro implementa o comportamento da mensagem Win32 [MCM_SETSELRANGE](http://msdn.microsoft.com/library/windows/desktop/bb761014), conforme descrito na [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)]. Na implementação do MFC `SetSelRange`, você pode especificar `COleDateTime` uso, uma `CTime` uso, ou um `SYSTEMTIME` uso de estrutura.  
  
##  <a name="a-namesettodaya--cmonthcalctrlsettoday"></a><a name="settoday"></a>CMonthCalCtrl::SetToday  
 Define o controle de calendário para o dia atual.  
  
```  
void SetToday(const COleDateTime& refDateTime);  
void SetToday(const CTime* pDateTime);  
  void SetToday(const LPSYSTEMTIME pDateTime);
```  
  
### <a name="parameters"></a>Parâmetros  
 `refDateTime`  
 Uma referência a um [COleDateTime](../../atl-mfc-shared/reference/coledatetime-class.md) objeto que contém a data atual.  
  
 `pDateTime`  
 Na segunda versão, um ponteiro para um [CTime](../../atl-mfc-shared/reference/ctime-class.md) objeto que contém as informações de data atual. A terceira versão, um ponteiro para um [SYSTEMTIME](http://msdn.microsoft.com/library/windows/desktop/ms724950) estrutura que contém as informações de data atual.  
  
### <a name="remarks"></a>Comentários  
 Essa função de membro implementa o comportamento da mensagem Win32 [MCM_SETTODAY](http://msdn.microsoft.com/library/windows/desktop/bb761016), conforme descrito na [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
### <a name="example"></a>Exemplo  
  Veja o exemplo de [CMonthCalCtrl::GetToday](#gettoday).  
  
##  <a name="a-namesetyearviewa--cmonthcalctrlsetyearview"></a><a name="setyearview"></a>CMonthCalCtrl::SetYearView  
 Conjuntos de calendário do mês atual controlar a exibição de ano.  
  
```  
BOOL SetYearView();
```  
  
### <a name="return-value"></a>Valor de retorno  
 `true`Se esse método for bem-sucedida; Caso contrário, `false`.  
  
### <a name="remarks"></a>Comentários  
 Esse método usa o [CMonthCalCtrl::SetCurrentView](#setcurrentview) método para definir o modo de exibição `MCMV_YEAR`, que representa o modo de exibição anual.  
  
##  <a name="a-namesizeminreqa--cmonthcalctrlsizeminreq"></a><a name="sizeminreq"></a>CMonthCalCtrl::SizeMinReq  
 Exibe o mês no controle de calendário para o mínimo de tamanho que exibe um mês.  
  
```  
BOOL SizeMinReq(BOOL bRepaint = TRUE);
```  
  
### <a name="parameters"></a>Parâmetros  
 `bRepaint`  
 Especifica se o controle deve ser redesenhado. Por padrão, **TRUE**. Se **FALSE**, nenhum redesenho ocorre.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se o controle de calendário mensal é dimensionado para seu mínimo; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Chamando `SizeMinReq` exibe com êxito o controle de calendário do mês inteiro de calendário mensal.  
  
##  <a name="a-namesizerecttomina--cmonthcalctrlsizerecttomin"></a><a name="sizerecttomin"></a>CMonthCalCtrl::SizeRectToMin  
 Para o controle de calendário do mês atual, calcula o menor retângulo que pode conter todos os calendários que se encaixam em um retângulo especificado.  
  
```  
LPRECT SizeRectToMin(LPRECT lpRect);
```  
  
### <a name="parameters"></a>Parâmetros  
  
|Parâmetro|Descrição|  
|---------------|-----------------|  
|[in] `lpRect`|Ponteiro para uma [RECT](http://msdn.microsoft.com/library/windows/desktop/dd162897) estrutura que define um retângulo que contém o número desejado de calendários.|  
  
### <a name="return-value"></a>Valor de retorno  
 Ponteiro para uma [RECT](http://msdn.microsoft.com/library/windows/desktop/dd162897) estrutura que define um retângulo cujo tamanho é menor ou igual ao retângulo definido pelo `lpRect` parâmetro.  
  
### <a name="remarks"></a>Comentários  
 Esse método calcula quantos calendários podem se ajustar no retângulo especificado pelo `lpRect` parâmetro e, em seguida, retorna o menor retângulo que pode conter o número de calendários. Na verdade, esse método reduz o retângulo especificado se ajuste exatamente o número desejado de calendários.  
  
 Esse método envia o [MCM_SIZERECTTOMIN](http://msdn.microsoft.com/library/windows/desktop/bb761020) mensagem, que é descrita o [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
## <a name="see-also"></a>Consulte também  
 [CMNCTRL1 de exemplo do MFC](../../visual-cpp-samples.md)   
 [Classe CWnd](../../mfc/reference/cwnd-class.md)   
 [Gráfico de hierarquia](../../mfc/hierarchy-chart.md)   
 [Classe CDateTimeCtrl](../../mfc/reference/cdatetimectrl-class.md)

