---
title: Classe CDateTimeCtrl | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- CDateTimeCtrl
- AFXDTCTL/CDateTimeCtrl
- AFXDTCTL/CDateTimeCtrl::CDateTimeCtrl
- AFXDTCTL/CDateTimeCtrl::CloseMonthCal
- AFXDTCTL/CDateTimeCtrl::Create
- AFXDTCTL/CDateTimeCtrl::GetDateTimePickerInfo
- AFXDTCTL/CDateTimeCtrl::GetIdealSize
- AFXDTCTL/CDateTimeCtrl::GetMonthCalColor
- AFXDTCTL/CDateTimeCtrl::GetMonthCalCtrl
- AFXDTCTL/CDateTimeCtrl::GetMonthCalFont
- AFXDTCTL/CDateTimeCtrl::GetMonthCalStyle
- AFXDTCTL/CDateTimeCtrl::GetRange
- AFXDTCTL/CDateTimeCtrl::GetTime
- AFXDTCTL/CDateTimeCtrl::SetFormat
- AFXDTCTL/CDateTimeCtrl::SetMonthCalColor
- AFXDTCTL/CDateTimeCtrl::SetMonthCalFont
- AFXDTCTL/CDateTimeCtrl::SetMonthCalStyle
- AFXDTCTL/CDateTimeCtrl::SetRange
- AFXDTCTL/CDateTimeCtrl::SetTime
dev_langs: C++
helpviewer_keywords:
- CDateTimeCtrl [MFC], CDateTimeCtrl
- CDateTimeCtrl [MFC], CloseMonthCal
- CDateTimeCtrl [MFC], Create
- CDateTimeCtrl [MFC], GetDateTimePickerInfo
- CDateTimeCtrl [MFC], GetIdealSize
- CDateTimeCtrl [MFC], GetMonthCalColor
- CDateTimeCtrl [MFC], GetMonthCalCtrl
- CDateTimeCtrl [MFC], GetMonthCalFont
- CDateTimeCtrl [MFC], GetMonthCalStyle
- CDateTimeCtrl [MFC], GetRange
- CDateTimeCtrl [MFC], GetTime
- CDateTimeCtrl [MFC], SetFormat
- CDateTimeCtrl [MFC], SetMonthCalColor
- CDateTimeCtrl [MFC], SetMonthCalFont
- CDateTimeCtrl [MFC], SetMonthCalStyle
- CDateTimeCtrl [MFC], SetRange
- CDateTimeCtrl [MFC], SetTime
ms.assetid: 7113993b-5d37-4148-939f-500a190c5bdc
caps.latest.revision: "23"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 3359b506217d2828207e06341fbf1fe53b3c0719
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="cdatetimectrl-class"></a>Classe CDateTimeCtrl
Encapsula a funcionalidade de um controle de seletor de data e hora.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class CDateTimeCtrl : public CWnd  
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CDateTimeCtrl::CDateTimeCtrl](#cdatetimectrl)|Constrói um objeto `CDateTimeCtrl`.|  
  
### <a name="public-methods"></a>Métodos Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CDateTimeCtrl::CloseMonthCal](#closemonthcal)|Fecha o controle de seletor de data e hora atual.|  
|[CDateTimeCtrl::Create](#create)|Cria o controle de seletor de data e hora e anexa-o para o `CDateTimeCtrl` objeto.|  
|[CDateTimeCtrl::GetDateTimePickerInfo](#getdatetimepickerinfo)|Recupera informações sobre o controle de seletor de data e hora atual.|  
|[CDateTimeCtrl::GetIdealSize](#getidealsize)|Retorna o tamanho ideal do controle de seletor de data e hora em que é necessário para exibir a data ou hora atual.|  
|[CDateTimeCtrl::GetMonthCalColor](#getmonthcalcolor)|Recupera a cor de uma determinada parte do calendário mensal dentro do controle de seletor de data e hora.|  
|[CDateTimeCtrl::GetMonthCalCtrl](#getmonthcalctrl)|Recupera o `CMonthCalCtrl` objeto associado com o controle de seletor de data e hora.|  
|[CDateTimeCtrl::GetMonthCalFont](#getmonthcalfont)|Recupera a fonte usada no momento, a data e o controle de calendário de mês de filho do controle de seletor de tempo.|  
|[CDateTimeCtrl::GetMonthCalStyle](#getmonthcalstyle)|Obtém o estilo do controle de seletor de data e hora atual.|  
|[CDateTimeCtrl::GetRange](#getrange)|Recupera o atual mínimo e máximo permitido horários do sistema para um controle de seletor de data e hora.|  
|[CDateTimeCtrl::GetTime](#gettime)|Recupera o tempo selecionado de um controle de seletor de data e hora e o coloca em um especificado `SYSTEMTIME` estrutura.|  
|[CDateTimeCtrl::SetFormat](#setformat)|Define a exibição de um controle de seletor de data e hora de acordo com uma cadeia de caracteres de formato fornecido.|  
|[CDateTimeCtrl::SetMonthCalColor](#setmonthcalcolor)|Define a cor de uma determinada parte do calendário de mês em um controle de seletor de data e hora.|  
|[CDateTimeCtrl::SetMonthCalFont](#setmonthcalfont)|Define a fonte que usará o controle de calendário do mês de filho de data e hora seletor do controle.|  
|[CDateTimeCtrl::SetMonthCalStyle](#setmonthcalstyle)|Define o estilo do controle de seletor de data e hora atual.|  
|[CDateTimeCtrl::SetRange](#setrange)|Define os horários do sistema de permitido mínimo e máximo para um controle de seletor de data e hora.|  
|[CDateTimeCtrl::SetTime](#settime)|Define o tempo em um controle de seletor de data e hora.|  
  
## <a name="remarks"></a>Comentários  
 O controle de seletor data e hora (controle DTP) fornece uma interface simples para trocar informações de data e hora com um usuário. Essa interface contém campos, cada um deles exibe uma parte das informações de data e hora armazenadas no controle. O usuário pode alterar as informações armazenadas no controle alterando o conteúdo da cadeia de caracteres em um determinado campo. O usuário pode mover de um campo para usar o mouse ou o teclado.  
  
 Você pode personalizar o controle de seletor de data e hora, aplicando uma variedade de estilos para o objeto quando você criá-lo. Consulte [data e hora estilos de controle de seletor](http://msdn.microsoft.com/library/windows/desktop/bb761728) no SDK do Windows para obter mais informações sobre estilos específicos para o controle de seletor de data e hora. Você pode definir o formato de exibição do controle DTP usando estilos de formato. Esses estilos de formato são descritos em "Estilos de formato" no tópico SDK do Windows [data e hora estilos de controle de seletor](http://msdn.microsoft.com/library/windows/desktop/bb761728).  
  
 O controle de seletor de data e hora também usa notificações e retornos de chamada, que são descritos em [usando CDateTimeCtrl](../../mfc/using-cdatetimectrl.md).  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 [CObject](../../mfc/reference/cobject-class.md)  
  
 [CCmdTarget](../../mfc/reference/ccmdtarget-class.md)  
  
 [CWnd](../../mfc/reference/cwnd-class.md)  
  
 `CDateTimeCtrl`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxdtctl.h  
  
##  <a name="cdatetimectrl"></a>CDateTimeCtrl::CDateTimeCtrl  
 Constrói um objeto `CDateTimeCtrl`.  
  
```  
CDateTimeCtrl();
```  
  
##  <a name="closemonthcal"></a>CDateTimeCtrl::CloseMonthCal  
 Fecha o controle de seletor de data e hora atual.  
  
```  
void CloseMonthCal() const;  
```  
  
### <a name="remarks"></a>Comentários  
 Esse método envia o [DTM_CLOSEMONTHCAL](http://msdn.microsoft.com/library/windows/desktop/bb761753) mensagem, que é descrita no SDK do Windows.  
  
### <a name="example"></a>Exemplo  
 O exemplo de código a seguir define a variável `m_dateTimeCtrl`, que é usado para acessar programaticamente o controle de seletor de data e hora. Essa variável é usada no exemplo a seguir.  
  
 [!code-cpp[NVC_MFC_CDateTimeCtrl_s1#1](../../mfc/reference/codesnippet/cpp/cdatetimectrl-class_1.h)]  
  
### <a name="example"></a>Exemplo  
 O exemplo de código a seguir fecha o calendário suspenso para o controle de seletor de data e hora atual.  
  
 [!code-cpp[NVC_MFC_CDateTimeCtrl_s1#5](../../mfc/reference/codesnippet/cpp/cdatetimectrl-class_2.cpp)]  
  
##  <a name="create"></a>CDateTimeCtrl::Create  
 Cria o controle de seletor de data e hora e anexa-o para o `CDateTimeCtrl` objeto.  
  
```  
virtual BOOL Create(
    DWORD dwStyle,  
    const RECT& rect,  
    CWnd* pParentWnd,  
    UINT nID);
```  
  
### <a name="parameters"></a>Parâmetros  
 `dwStyle`  
 Especifica a combinação de estilos de controle de tempo de data. Consulte [data e hora estilos de controle de seletor](http://msdn.microsoft.com/library/windows/desktop/bb761728) no SDK do Windows para obter mais informações sobre estilos de seletor de data e hora.  
  
 `rect`  
 Uma referência a um [RECT](http://msdn.microsoft.com/library/windows/desktop/dd162897) estrutura, que é a posição e o tamanho do controle de seletor de data e hora.  
  
 `pParentWnd`  
 Um ponteiro para um [CWnd](../../mfc/reference/cwnd-class.md) objeto que é a janela pai do controle de seletor de data e hora. Ele não deve ser **nulo**.  
  
 `nID`  
 Especifica a ID de controle de. Data e hora seletor do controle  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se a criação foi bem-sucedida; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
  
##### <a name="to-create-a-date-and-time-picker-control"></a>Para criar um controle de seletor de data e hora  
  
1.  Chamar [CDateTimeCtrl](#cdatetimectrl) para construir um `CDateTimeCtrl` objeto.  
  
2.  Chamar essa função de membro, que cria o controle de seletor de data e hora do Windows e a anexa ao `CDateTimeCtrl` objeto.  
  
 Quando você chama **criar**, os controles comuns são inicializados.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFC_CDateTimeCtrl#1](../../mfc/reference/codesnippet/cpp/cdatetimectrl-class_3.cpp)]  
  
##  <a name="getdatetimepickerinfo"></a>CDateTimeCtrl::GetDateTimePickerInfo  
 Recupera informações sobre o controle de seletor de data e hora atual.  
  
```   
BOOL GetDateTimePickerInfo(LPDATETIMEPICKERINFO pDateTimePickerInfo) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
  
|Parâmetro|Descrição|  
|---------------|-----------------|  
|[out] `pDateTimePickerInfo`|Um ponteiro para um [DATETIMEPICKERINFO](http://msdn.microsoft.com/library/windows/desktop/bb761729) estrutura que recebe uma descrição do que o controle de seletor de data e hora atual.<br /><br /> O chamador é responsável pela alocação essa estrutura. No entanto, esse método inicializa o `cbSize` membro da estrutura.|  
  
### <a name="return-value"></a>Valor de retorno  
 `true`Se esse método for bem-sucedida; Caso contrário, `false`.  
  
### <a name="remarks"></a>Comentários  
 Esse método envia o [DTM_GETDATETIMEPICKERINFO](http://msdn.microsoft.com/library/windows/desktop/bb761755) mensagem, que é descrita no SDK do Windows.  
  
### <a name="example"></a>Exemplo  
 O exemplo de código a seguir define a variável `m_dateTimeCtrl`, que é usado para acessar programaticamente o controle de seletor de data e hora. Essa variável é usada no exemplo a seguir.  
  
 [!code-cpp[NVC_MFC_CDateTimeCtrl_s1#1](../../mfc/reference/codesnippet/cpp/cdatetimectrl-class_1.h)]  
  
### <a name="example"></a>Exemplo  
 O exemplo de código a seguir indica se, com êxito, ele recupera informações sobre o controle de seletor de data e hora atual.  
  
 [!code-cpp[NVC_MFC_CDateTimeCtrl_s1#4](../../mfc/reference/codesnippet/cpp/cdatetimectrl-class_4.cpp)]  
  
##  <a name="getmonthcalcolor"></a>CDateTimeCtrl::GetMonthCalColor  
 Recupera a cor de uma determinada parte do calendário mensal dentro do controle de seletor de data e hora.  
  
```  
COLORREF GetMonthCalColor(int iColor) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 `iColor`  
 Um `int` valor que especifica qual área de cor do calendário de mês para recuperar. Para obter uma lista de valores, consulte o `iColor` parâmetro [SetMonthCalColor](#setmonthcalcolor).  
  
### <a name="return-value"></a>Valor de retorno  
 Um **COLORREF** valor que representa a configuração de cor para a parte especificada do controle de calendário do mês, se for bem-sucedido. A função retornará -1 se não houver êxito.  
  
### <a name="remarks"></a>Comentários  
 Essa função de membro implementa o comportamento da mensagem de Win32 [DTM_GETMCCOLOR](http://msdn.microsoft.com/library/windows/desktop/bb761759), conforme descrito no SDK do Windows.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFC_CDateTimeCtrl#2](../../mfc/reference/codesnippet/cpp/cdatetimectrl-class_5.cpp)]  
  
##  <a name="getmonthcalctrl"></a>CDateTimeCtrl::GetMonthCalCtrl  
 Recupera o `CMonthCalCtrl` objeto associado com o controle de seletor de data e hora.  
  
```  
CMonthCalCtrl* GetMonthCalCtrl() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um ponteiro para um [CMonthCalCtrl](../../mfc/reference/cmonthcalctrl-class.md) objeto, ou **nulo** se não houver êxito ou se a janela não estiver visível.  
  
### <a name="remarks"></a>Comentários  
 Controles de seletor de data e hora criar um controle de calendário mensal filho quando o usuário clica na seta suspensa. Quando o `CMonthCalCtrl` objeto não for mais necessário, destruído, para que seu aplicativo não deve depender armazenar o objeto que representa o calendário de mês de tempo controle seletor de data filho.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFC_CDateTimeCtrl#3](../../mfc/reference/codesnippet/cpp/cdatetimectrl-class_6.cpp)]  
  
##  <a name="getmonthcalfont"></a>CDateTimeCtrl::GetMonthCalFont  
 Obtém a fonte usada no momento, a data e o controle de calendário mensal do controle do seletor de tempo.  
  
```  
CFont* GetMonthCalFont() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um ponteiro para um [CFont](../../mfc/reference/cfont-class.md) objeto, ou **nulo** se não houver êxito.  
  
### <a name="remarks"></a>Comentários  
 O `CFont` objeto apontado pelo valor de retorno é um objeto temporário e é destruído durante o próximo tempo de processamento ocioso.  
  
##  <a name="getmonthcalstyle"></a>CDateTimeCtrl::GetMonthCalStyle  
 Obtém o estilo do controle de calendário de mês suspenso que está associado com o controle de seletor de data e hora atual.  
  
```  
DWORD GetMonthCalStyle() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 O estilo do controle de calendário suspenso mês, que é uma combinação bit a bit (ou) de estilos de controle de seletor de data e hora. Para obter mais informações, consulte [estilos de controle de calendário de mês](http://msdn.microsoft.com/library/windows/desktop/bb760919).  
  
### <a name="remarks"></a>Comentários  
 Esse método envia o [DTM_GETMCSTYLE](http://msdn.microsoft.com/library/windows/desktop/bb761763) mensagem, que é descrita no SDK do Windows.  
  
##  <a name="getrange"></a>CDateTimeCtrl::GetRange  
 Recupera o atual mínimo e máximo permitido horários do sistema para um controle de seletor de data e hora.  
  
```  
DWORD GetRange(
    COleDateTime* pMinRange,  
    COleDateTime* pMaxRange) const;  
  
DWORD GetRange(
    CTime* pMinRange,  
    CTime* pMaxRange) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 `pMinRange`  
 Um ponteiro para um [COleDateTime](../../atl-mfc-shared/reference/coledatetime-class.md) objeto ou um [CTime](../../atl-mfc-shared/reference/ctime-class.md) objeto que contém a hora mais antiga permitida no `CDateTimeCtrl` objeto.  
  
 `pMaxRange`  
 Um ponteiro para um `COleDateTime` objeto ou um `CTime` objeto que contém a hora mais recente permitida no `CDateTimeCtrl` objeto.  
  
### <a name="return-value"></a>Valor de retorno  
 Um `DWORD` valor que contém sinalizadores que indicam quais intervalos são definidos. If  
  
 `return value & GDTR_MAX` == 0  
  
 em seguida, o segundo parâmetro é válido. Da mesma forma, se  
  
 `return value & GDTR_MIN` == 0  
  
 em seguida, o primeiro parâmetro é válido.  
  
### <a name="remarks"></a>Comentários  
 Essa função de membro implementa o comportamento da mensagem de Win32 [DTM_GETRANGE](http://msdn.microsoft.com/library/windows/desktop/bb761767), conforme descrito no SDK do Windows. Na implementação do MFC, você pode especificar `COleDateTime` ou `CTime` usos.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFC_CDateTimeCtrl#4](../../mfc/reference/codesnippet/cpp/cdatetimectrl-class_7.cpp)]  
  
##  <a name="gettime"></a>CDateTimeCtrl::GetTime  
 Recupera o tempo selecionado de um controle de seletor de data e hora e o coloca em um especificado `SYSTEMTIME` estrutura.  
  
```  
BOOL GetTime(COleDateTime& timeDest) const;  
DWORD GetTime(CTime& timeDest) const;  
DWORD GetTime(LPSYSTEMTIME pTimeDest) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 *timeDest*  
 Na primeira versão, uma referência a um [COleDateTime](../../atl-mfc-shared/reference/coledatetime-class.md) objeto que receberá as informações de hora do sistema. Na segunda versão, uma referência a um [CTime](../../atl-mfc-shared/reference/ctime-class.md) objeto que receberá as informações de hora do sistema.  
  
 *pTimeDest*  
 Um ponteiro para o [SYSTEMTIME](http://msdn.microsoft.com/library/windows/desktop/ms724950) estrutura para receber as informações de hora do sistema. Não deve ser **nulo**.  
  
### <a name="return-value"></a>Valor de retorno  
 Na primeira versão, diferente de zero se a hora é gravada com êxito o `COleDateTime` objeto; caso contrário, 0. Nas versões do segunda e terceira, um `DWORD` valor igual ao **Dwfrag** conjunto de membros de [NMDATETIMECHANGE](http://msdn.microsoft.com/library/windows/desktop/bb761730) estrutura. Consulte o **comentários** seção abaixo para obter mais informações.  
  
### <a name="remarks"></a>Comentários  
 Essa função de membro implementa o comportamento da mensagem de Win32 [DTM_GETSYSTEMTIME](http://msdn.microsoft.com/library/windows/desktop/bb761769), conforme descrito no SDK do Windows. Na implementação do MFC **GetTime**, você pode usar `COleDateTime` ou `CTime` classes, ou você pode usar um `SYSTEMTIME` estrutura, para armazenar as informações de tempo.  
  
 O valor de retorno `DWORD` nas versões do segunda e terceira, acima, indica se o controle de seletor de data e hora é definido como o status de "nenhuma data", conforme indicado no [NMDATETIMECHANGE](http://msdn.microsoft.com/library/windows/desktop/bb761730) membro de estrutura `dwFlags`. Se o valor retornado é igual a **GDT_NONE**, o controle é definido para o status de "nenhuma data" e usa o **DTS_SHOWNONE** estilo. Se o valor retornado é igual a **GDT_VALID**, a hora do sistema com êxito é armazenada no local de destino.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFC_CDateTimeCtrl#5](../../mfc/reference/codesnippet/cpp/cdatetimectrl-class_8.cpp)]  
  
##  <a name="getidealsize"></a>CDateTimeCtrl::GetIdealSize  
 Retorna o tamanho ideal do controle de seletor de data e hora em que é necessário para exibir a data ou hora atual.  
  
```  
BOOL GetIdealSize(LPSIZE psize) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
  
|Parâmetro|Descrição|  
|---------------|-----------------|  
|[out] `psize`|Ponteiro para um [tamanho](http://msdn.microsoft.com/library/windows/desktop/dd145106) estrutura que contém o tamanho ideal para o controle.|  
  
### <a name="return-value"></a>Valor de retorno  
 O valor retornado é sempre `true`.  
  
### <a name="remarks"></a>Comentários  
 Esse método envia o [DTM_GETIDEALSIZE](http://msdn.microsoft.com/library/windows/desktop/bb761757) mensagem, que é descrita no SDK do Windows.  
  
### <a name="example"></a>Exemplo  
 O exemplo de código a seguir define a variável `m_dateTimeCtrl`, que é usado para acessar programaticamente o controle de seletor de data e hora. Essa variável é usada no exemplo a seguir.  
  
 [!code-cpp[NVC_MFC_CDateTimeCtrl_s1#1](../../mfc/reference/codesnippet/cpp/cdatetimectrl-class_1.h)]  
  
### <a name="example"></a>Exemplo  
 O exemplo de código a seguir recupera o tamanho ideal para exibir o controle de seletor de data e hora.  
  
 [!code-cpp[NVC_MFC_CDateTimeCtrl_s1#2](../../mfc/reference/codesnippet/cpp/cdatetimectrl-class_9.cpp)]  
  
##  <a name="setformat"></a>CDateTimeCtrl::SetFormat  
 Define a exibição de um controle de seletor de data e hora de acordo com uma cadeia de caracteres de formato fornecido.  
  
```  
BOOL SetFormat(LPCTSTR pstrFormat);
```  
  
### <a name="parameters"></a>Parâmetros  
 *pstrFormat*  
 Um ponteiro para uma cadeia de caracteres de formato terminada em zero que define a exibição desejada. Definir esse parâmetro para **nulo** redefinirá o controle para a cadeia de caracteres de formato padrão para o estilo atual.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se for bem-sucedida; Caso contrário, 0.  
  
> [!NOTE]
>  Entrada do usuário não determina o êxito ou falha para esta chamada.  
  
### <a name="remarks"></a>Comentários  
 Essa função de membro implementa o comportamento da mensagem de Win32 [DTM_SETFORMAT](http://msdn.microsoft.com/library/windows/desktop/bb761771), conforme descrito no SDK do Windows.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFC_CDateTimeCtrl#6](../../mfc/reference/codesnippet/cpp/cdatetimectrl-class_10.cpp)]  
  
##  <a name="setmonthcalcolor"></a>CDateTimeCtrl::SetMonthCalColor  
 Define a cor de uma determinada parte do calendário de mês em um controle de seletor de data e hora.  
  
```  
COLORREF SetMonthCalColor(
    int iColor,  
    COLORREF ref);
```  
  
### <a name="parameters"></a>Parâmetros  
 `iColor`  
 `int`valor que especifica qual área do controle de calendário de mês para definir. Esse valor pode ser uma das seguintes opções:  
  
|Valor|Significado|  
|-----------|-------------|  
|MCSC_BACKGROUND|Defina a cor de plano de fundo exibida entre os meses.|  
|MCSC_MONTHBK|Defina a cor de plano de fundo exibida dentro de um mês.|  
|MCSC_TEXT|Define a cor usada para exibir o texto dentro de um mês.|  
|MCSC_TITLEBK|Defina a cor de plano de fundo exibida no título do calendário.|  
|MCSC_TITLETEXT|Defina a cor usada para exibir texto no título do calendário.|  
|MCSC_TRAILINGTEXT|Define a cor usada para exibir o cabeçalho e o texto do dia à direita. Dias seguinte e anterior são os dias dos meses anteriores e seguintes exibidos no calendário atual.|  
  
 `ref`  
 Um **COLORREF** valor que representa a cor que será definida para a área especificada de calendário mensal.  
  
### <a name="return-value"></a>Valor de retorno  
 Um **COLORREF** valor que representa a configuração anterior de cor para a parte especificada do controle de calendário do mês, se for bem-sucedido. Caso contrário, a mensagem retornará -1.  
  
### <a name="remarks"></a>Comentários  
 Essa função de membro implementa o comportamento da mensagem de Win32 [DTM_SETMCCOLOR](http://msdn.microsoft.com/library/windows/desktop/bb761773), conforme descrito no SDK do Windows.  
  
### <a name="example"></a>Exemplo  
  Consulte o exemplo para [CDateTimeCtrl::GetMonthCalColor](#getmonthcalcolor).  
  
##  <a name="setmonthcalfont"></a>CDateTimeCtrl::SetMonthCalFont  
 Define a fonte que usará o controle de calendário do mês de filho de data e hora seletor do controle.  
  
```  
void SetMonthCalFont(
    HFONT hFont,  
    BOOL bRedraw = TRUE);
```  
  
### <a name="parameters"></a>Parâmetros  
 `hFont`  
 Identificador para a fonte que será definida.  
  
 `bRedraw`  
 Especifica se o controle deve ser redesenhado imediatamente após a definição da fonte. Definir esse parâmetro para **TRUE** faz com que o controle redesenhado.  
  
### <a name="remarks"></a>Comentários  
 Essa função de membro implementa o comportamento da mensagem de Win32 [DTM_SETMCFONT](http://msdn.microsoft.com/library/windows/desktop/bb761775), conforme descrito no SDK do Windows.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFC_CDateTimeCtrl#7](../../mfc/reference/codesnippet/cpp/cdatetimectrl-class_11.cpp)]  
  
> [!NOTE]
>  Se você usar esse código, você desejará tornar um membro de seu `CDialog`-chamado de classe derivada `m_MonthFont` do tipo **CFont**.  
  
##  <a name="setmonthcalstyle"></a>CDateTimeCtrl::SetMonthCalStyle  
 Define o estilo do controle de calendário de mês suspenso que está associado com o controle de seletor de data e hora atual.  
  
```  
DWORD SetMonthCalStyle(DWORD dwStyle);
```  
  
### <a name="parameters"></a>Parâmetros  
  
|Parâmetro|Descrição|  
|---------------|-----------------|  
|[in] `dwStyle`|Estilo de controle, que é uma combinação bit a bit (ou) de estilos de controle de calendário do mês do calendário de um novo mês. Para obter mais informações, consulte [estilos de controle de calendário de mês](http://msdn.microsoft.com/library/windows/desktop/bb760919).|  
  
### <a name="return-value"></a>Valor de retorno  
 O estilo anterior do controle de calendário de mês de lista suspensa.  
  
### <a name="remarks"></a>Comentários  
 Esse método envia o [DTM_SETMCSTYLE](http://msdn.microsoft.com/library/windows/desktop/bb761778) mensagem, que é descrita no SDK do Windows.  
  
### <a name="example"></a>Exemplo  
 O exemplo de código a seguir define a variável `m_dateTimeCtrl`, que é usado para acessar programaticamente o controle de seletor de data e hora. Essa variável é usada no exemplo a seguir.  
  
 [!code-cpp[NVC_MFC_CDateTimeCtrl_s1#1](../../mfc/reference/codesnippet/cpp/cdatetimectrl-class_1.h)]  
  
### <a name="example"></a>Exemplo  
 O exemplo de código a seguir define o controle de seletor de data e hora para exibir números de semana, nomes abreviados de dias da semana e nenhum indicador hoje.  
  
 [!code-cpp[NVC_MFC_CDateTimeCtrl_s1#3](../../mfc/reference/codesnippet/cpp/cdatetimectrl-class_12.cpp)]  
  
##  <a name="setrange"></a>CDateTimeCtrl::SetRange  
 Define os horários do sistema de permitido mínimo e máximo para um controle de seletor de data e hora.  
  
```  
BOOL SetRange(
    const COleDateTime* pMinRange,  
    const COleDateTime* pMaxRange);

 
BOOL SetRange(
    const CTime* pMinRange,  
    const CTime* pMaxRange);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pMinRange`  
 Um ponteiro para um [COleDateTime](../../atl-mfc-shared/reference/coledatetime-class.md) objeto ou um [CTime](../../atl-mfc-shared/reference/ctime-class.md) objeto que contém a hora mais antiga permitida no `CDateTimeCtrl` objeto.  
  
 `pMaxRange`  
 Um ponteiro para um `COleDateTime` objeto ou um `CTime` objeto que contém a hora mais recente permitida no `CDateTimeCtrl` objeto.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se for bem-sucedida; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Essa função de membro implementa o comportamento da mensagem de Win32 [DTM_SETRANGE](http://msdn.microsoft.com/library/windows/desktop/bb761780), conforme descrito no SDK do Windows. Na implementação do MFC, você pode especificar `COleDateTime` ou `CTime` usos. Se o `COleDateTime` objeto tem um **nulo** status, o intervalo será removido. Se o `CTime` ponteiro ou `COleDateTime` ponteiro é **nulo**, o intervalo será removido.  
  
### <a name="example"></a>Exemplo  
  Consulte o exemplo para [CDateTimeCtrl::GetRange](#getrange).  
  
##  <a name="settime"></a>CDateTimeCtrl::SetTime  
 Define o tempo em um controle de seletor de data e hora.  
  
```  
BOOL SetTime(const COleDateTime& timeNew);  
BOOL SetTime(const CTime* pTimeNew);  
BOOL SetTime(LPSYSTEMTIME pTimeNew = NULL);
```  
  
### <a name="parameters"></a>Parâmetros  
 *timeNew*  
 Uma referência a um [COleDateTime](../../atl-mfc-shared/reference/coledatetime-class.md) objeto contendo o para que o controle será definido.  
  
 *pTimeNew*  
 Na segunda versão acima, um ponteiro para um [CTime](../../atl-mfc-shared/reference/ctime-class.md) objeto que contém a hora em que o controle será definido. Na terceira versão acima, um ponteiro para um [SYSTEMTIME](http://msdn.microsoft.com/library/windows/desktop/ms724950) estrutura que contém a hora em que o controle será definido.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se for bem-sucedida; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Essa função de membro implementa o comportamento da mensagem de Win32 [DTM_SETSYSTEMTIME](http://msdn.microsoft.com/library/windows/desktop/bb761782), conforme descrito no SDK do Windows. Na implementação do MFC **SetTime**, você pode usar o `COleDateTime` ou `CTime` classes, ou você pode usar um `SYSTEMTIME` estrutura para definir as informações de tempo.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFC_CDateTimeCtrl#8](../../mfc/reference/codesnippet/cpp/cdatetimectrl-class_13.cpp)]  
  
## <a name="see-also"></a>Consulte também  
 [CMNCTRL1 de exemplo do MFC](../../visual-cpp-samples.md)   
 [Classe CWnd](../../mfc/reference/cwnd-class.md)   
 [Gráfico de hierarquia](../../mfc/hierarchy-chart.md)   
 [Classe CMonthCalCtrl](../../mfc/reference/cmonthcalctrl-class.md)
