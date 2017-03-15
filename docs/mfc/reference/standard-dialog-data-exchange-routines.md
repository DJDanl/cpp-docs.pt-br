---
title: "Rotinas de troca de dados de caixa de diálogo padrão | Documentos do Microsoft"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: article
dev_langs:
- C++
helpviewer_keywords:
- standard dialog, data exchange routines
ms.assetid: c6adb7f3-f9af-4cc5-a9ea-315c5b60ad1a
caps.latest.revision: 13
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
ms.sourcegitcommit: 17a158366f94d27b7a46917282425d652e6b9042
ms.openlocfilehash: 15bd88000a7a035ed416b7e1c0640488039079ab
ms.lasthandoff: 02/25/2017

---
# <a name="standard-dialog-data-exchange-routines"></a>Rotinas de troca dos dados da caixa de diálogo padrão
Este tópico lista as rotinas de exchange (DDX) de dados padrão da caixa de diálogo usadas para controles de caixa de diálogo comuns do MFC.  
  
> [!NOTE]
>  As rotinas de troca de dados de caixa de diálogo padrão são definidas no afxdd_.h de arquivo de cabeçalho. No entanto, os aplicativos devem incluir afxwin. h.  
  
### <a name="ddx-functions"></a>Funções DDX  
  
|||  
|-|-|  
|[DDX_CBIndex](#ddx_cbindex)|Inicializa ou recupera o índice da seleção atual de um controle de caixa de combinação.|  
|[DDX_CBString](#ddx_cbstring)|Inicializa ou recupera o conteúdo atual do campo de edição de um controle de caixa de combinação.|  
|[DDX_CBStringExact](#ddx_cbstringexact)|Inicializa ou recupera o conteúdo atual do campo de edição de um controle de caixa de combinação.|  
|[DDX_Check](#ddx_check)|Inicializa ou recupera o estado atual de um controle de caixa de seleção.|  
|[DDX_Control](#ddx_control)|Subclasses de um dado controle em uma caixa de diálogo.|  
|[DDX_DateTimeCtrl](#ddx_datetimectrl)|Inicializa ou recupera dados de data / hora de um controle de selecionador de data e hora.|  
|[DDX_IPAddress](#ddx_ipaddress)|Inicializa ou recupera o valor atual de um controle de endereço IP.|  
|[DDX_LBIndex](#ddx_lbindex)|Inicializa ou recupera o índice da seleção atual de um controle de caixa de listagem.|  
|[DDX_LBString](#ddx_lbstring)|Inicializa ou recupera a seleção atual em um controle de caixa de listagem.|  
|[DDX_LBStringExact](#ddx_lbstringexact)|Inicializa ou recupera a seleção atual em um controle de caixa de listagem.|  
|[DDX_MonthCalCtrl](#ddx_monthcalctrl)|Inicializa ou recupera o valor atual de um controle de calendário mensal.|  
|[DDX_Radio](#ddx_radio)|Inicializa ou recupera o índice baseado em 0 do controle de rádio que atualmente é verificado dentro de um grupo de controle de rádio.|  
|[DDX_Scroll](#ddx_scroll)|Inicializa ou recupera a posição atual do elevador de um controle rolagem.|  
|[DDX_Slider](#ddx_slider)|Inicializa ou recupera a posição atual do elevador de um controle deslizante.|  
|[DDX_Text](#ddx_text)|Inicializa ou recupera o valor atual de um controle de edição.|  
  
##  <a name="a-nameddxcbindexa--ddxcbindex"></a><a name="ddx_cbindex"></a>DDX_CBIndex  
 O `DDX_CBIndex` função gerencia a transferência de `int` dados entre um controle de caixa de combinação em uma caixa de diálogo, exibição ou objeto de exibição de controle de formulário e um `int` membro de dados do objeto de exibição de controle, exibição de formulário ou caixa de diálogo.  
  
```  
void AFXAPI DDX_CBIndex(
    CDataExchange* pDX,  
    int nIDC,  
    int& index);  
```  
  
### <a name="parameters"></a>Parâmetros  
 `pDX`  
 Um ponteiro para um `CDataExchange` objeto. O framework fornece esse objeto para estabelecer o contexto de troca de dados, incluindo sua direção.  
  
 `nIDC`  
 A ID de controle de caixa de combinação associado com a propriedade de controle de recursos.  
  
 *índice*  
 Uma referência a uma variável de membro do objeto de exibição de controle com o qual os dados são trocados, exibição de formulário ou caixa de diálogo.  
  
### <a name="remarks"></a>Comentários  
 Quando `DDX_CBIndex` é chamado, *índice* é definida para o índice da seleção atual de caixa de combinação. Se nenhum item é selecionado, *índice* é definido como 0.  
  
 Para obter mais informações sobre DDX, consulte [troca de dados de caixa de diálogo e validação](../../mfc/dialog-data-exchange-and-validation.md).  
  
### <a name="requirements"></a>Requisitos  
  **Cabeçalho** afxdd_.h  
  
##  <a name="a-nameddxcbstringa--ddxcbstring"></a><a name="ddx_cbstring"></a>DDX_CBString  
 O `DDX_CBString` função gerencia a transferência de `CString` dados entre o controle de edição de um controle de caixa de combinação em uma caixa de diálogo, exibição ou objeto de exibição de controle de formulário e um `CString` membro de dados do objeto de exibição de controle, exibição de formulário ou caixa de diálogo.  
  
```  
void AFXAPI DDX_CBString(
    CDataExchange* pDX,  
    int nIDC,  
    CString& value);  
```  
  
### <a name="parameters"></a>Parâmetros  
 `pDX`  
 Um ponteiro para um `CDataExchange` objeto. O framework fornece esse objeto para estabelecer o contexto de troca de dados, incluindo sua direção.  
  
 `nIDC`  
 A ID de controle de caixa de combinação associado com a propriedade de controle de recursos.  
  
 *value*  
 Uma referência a uma variável de membro do objeto de exibição de controle com o qual os dados são trocados, exibição de formulário ou caixa de diálogo.  
  
### <a name="remarks"></a>Comentários  
 Quando `DDX_CBString` é chamado, *valor* está definido para a seleção atual da caixa de combinação. Se nenhum item é selecionado, *valor* é definido como uma cadeia de caracteres de comprimento zero.  
  
> [!NOTE]
>  Se a caixa de combinação é uma caixa de listagem suspensa, o valor trocado é limitado a 255 caracteres.  
  
 Para obter mais informações sobre DDX, consulte [troca de dados de caixa de diálogo e validação](../../mfc/dialog-data-exchange-and-validation.md).  
  
### <a name="requirements"></a>Requisitos  
  **Cabeçalho** afxdd_.h  
  
##  <a name="a-nameddxcbstringexacta--ddxcbstringexact"></a><a name="ddx_cbstringexact"></a>DDX_CBStringExact  
 O `DDX_CBStringExact` função gerencia a transferência de `CString` dados entre o controle de edição de um controle de caixa de combinação em uma caixa de diálogo, exibição ou objeto de exibição de controle de formulário e um `CString` membro de dados do objeto de exibição de controle, exibição de formulário ou caixa de diálogo.  
  
```  
void AFXAPI DDX_CBStringExact(
    CDataExchange* pDX,  
    int nIDC,  
    CString& value);  
```  
  
### <a name="parameters"></a>Parâmetros  
 `pDX`  
 Um ponteiro para um `CDataExchange` objeto. O framework fornece esse objeto para estabelecer o contexto de troca de dados, incluindo sua direção.  
  
 `nIDC`  
 A ID de controle de caixa de combinação associado com a propriedade de controle de recursos.  
  
 *value*  
 Uma referência a uma variável de membro do objeto de exibição de controle com o qual os dados são trocados, exibição de formulário ou caixa de diálogo.  
  
### <a name="remarks"></a>Comentários  
 Quando `DDX_CBStringExact` é chamado, *valor* está definido para a seleção atual da caixa de combinação. Se nenhum item é selecionado, *valor* é definido como uma cadeia de caracteres de comprimento zero.  
  
> [!NOTE]
>  Se a caixa de combinação é uma caixa de listagem suspensa, o valor trocado é limitado a 255 caracteres.  
  
 Para obter mais informações sobre DDX, consulte [troca de dados de caixa de diálogo e validação](../../mfc/dialog-data-exchange-and-validation.md).  
  
### <a name="requirements"></a>Requisitos  
  **Cabeçalho** afxdd_.h  
  
##  <a name="a-nameddxchecka--ddxcheck"></a><a name="ddx_check"></a>DDX_Check  
 O `DDX_Check` função gerencia a transferência de `int` dados entre um controle de caixa de seleção em uma caixa de diálogo, exibição ou objeto de exibição de controle de formulário e um `int` membro de dados do objeto de exibição de controle, exibição de formulário ou caixa de diálogo.  
  
```  
void AFXAPI DDX_Check(
    CDataExchange* pDX,  
    int nIDC,  
    int& value);  
```  
  
### <a name="parameters"></a>Parâmetros  
 `pDX`  
 Um ponteiro para um `CDataExchange` objeto. O framework fornece esse objeto para estabelecer o contexto de troca de dados, incluindo sua direção.  
  
 `nIDC`  
 A ID de recurso do controle de caixa de seleção associada com a propriedade de controle.  
  
 *value*  
 Uma referência a uma variável de membro do objeto de exibição de controle com o qual os dados são trocados, exibição de formulário ou caixa de diálogo.  
  
### <a name="remarks"></a>Comentários  
 Quando `DDX_Check` é chamado, *valor* está definido para o estado atual do controle caixa de seleção. Para obter uma lista dos valores possíveis de estado, consulte [BM_GETCHECK](http://msdn.microsoft.com/library/windows/desktop/bb775986) no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)] *.*  
  
 Para obter mais informações sobre DDX, consulte [troca de dados de caixa de diálogo e validação](../../mfc/dialog-data-exchange-and-validation.md).  
  
### <a name="requirements"></a>Requisitos  
  **Cabeçalho** afxdd_.h  
  
##  <a name="a-nameddxcontrola--ddxcontrol"></a><a name="ddx_control"></a>DDX_Control  
 O `DDX_Control` função subclasses de controle, especificado pelo `nIDC`, da caixa de diálogo, exibição de formulário ou objeto de exibição de controle.  
  
```  
void AFXAPI DDX_Control(
    CDataExchange* pDX,  
    int nIDC,  
    CWnd& rControl);  
```  
  
### <a name="parameters"></a>Parâmetros  
 `pDX`  
 Um ponteiro para um [CDataExchange](../../mfc/reference/cdataexchange-class.md) objeto.  
  
 `nIDC`  
 A ID de recurso do controle a ser uma subclasse.  
  
 *rControl*  
 Uma referência a uma variável de membro da caixa de diálogo, exibição de formulário ou objeto de exibição de controle relacionadas ao controle especificado.  
  
### <a name="remarks"></a>Comentários  
 O `pDX` objeto é fornecido pela estrutura quando o `DoDataExchange` função é chamada. Portanto, `DDX_Control` só deve ser chamado dentro de sua substituição do `DoDataExchange`.  
  
 Para obter mais informações sobre DDX, consulte [troca de dados de caixa de diálogo e validação](../../mfc/dialog-data-exchange-and-validation.md).  
  
### <a name="requirements"></a>Requisitos  
  **Cabeçalho** afxdd_.h  
  
##  <a name="a-nameddxdatetimectrla--ddxdatetimectrl"></a><a name="ddx_datetimectrl"></a>DDX_DateTimeCtrl  
 O `DDX_DateTimeCtrl` função gerencia a transferência de dados de data / hora entre um controle de selecionador de data e hora ( [CDateTimeCtrl](../../mfc/reference/cdatetimectrl-class.md)) em um objeto de exibição de formulário ou caixa de diálogo e em uma [CTime](../../atl-mfc-shared/reference/ctime-class.md) ou um [COleDateTime](../../atl-mfc-shared/reference/coledatetime-class.md) membro de dados do objeto de exibição de formulário ou caixa de diálogo.  
  
```  
void AFXAPI DDX_DateTimeCtrl(
    CDataExchange* pDX,  
    int nIDC,  
    CTime& value);

void AFXAPI DDX_DateTimeCtrl(
    CDataExchange* pDX,  
    int nIDC,  
    COleDateTime& value);

void AFXAPI DDX_DateTimeCtrl(
    CDataExchange* pDX,  
    int nIDC,  
    CString& value);  
```  
  
### <a name="parameters"></a>Parâmetros  
 `pDX`  
 Um ponteiro para um [CDataExchange](../../mfc/reference/cdataexchange-class.md) objeto. O framework fornece esse objeto para estabelecer o contexto de troca de dados, incluindo sua direção. Você não precisa excluir este objeto.  
  
 `nIDC`  
 A ID de recurso do controle de seletor de data e hora associado à variável de membro.  
  
 *value*  
 Nas duas primeiras versões, uma referência a um `CTime` ou `COleDateTime` variável de membro, caixa de diálogo, exibição de formulário ou objeto de exibição de controle com o qual os dados são trocados. Na terceira versão, uma referência a um `CString` objeto de exibição de controle de membro de dados.  
  
### <a name="remarks"></a>Comentários  
 Quando `DDX_DateTimeCtrl` é chamado, *valor* é definido como o atual estado da data e o controle de seletor de tempo ou o controle é definido como *valor*, dependendo da direção do exchange.  
  
 Na terceira versão acima, `DDX_DateTimeCtrl` gerencia a transferência de `CString` controle de tempo de dados entre uma data e uma [CString](../../atl-mfc-shared/reference/cstringt-class.md) membro de dados do objeto de exibição de controle. A cadeia de caracteres é formatada usando regras da localidade atual para formatar datas e horas.  
  
 Para obter mais informações sobre DDX, consulte [troca de dados de caixa de diálogo e validação](../../mfc/dialog-data-exchange-and-validation.md).  
  
### <a name="requirements"></a>Requisitos  
  **Cabeçalho** afxdd_.h  
  
##  <a name="a-nameddxipaddressa--ddxipaddress"></a><a name="ddx_ipaddress"></a>DDX_IPAddress  
 O `DDX_IPAddress` função gerencia a transferência de dados entre um controle de endereço IP e um membro de dados do objeto de exibição de controle.  
  
```  
void AFXAPI DDX_IPAddress(
    CDataExchange* pDX,  
    int nIDC,  
    DWORD& value);  
```  
  
### <a name="parameters"></a>Parâmetros  
 `pDX`  
 Um ponteiro para um `CDataExchange` objeto. O framework fornece esse objeto para estabelecer o contexto de troca de dados, incluindo sua direção.  
  
 `nIDC`  
 A ID de recurso do controle de endereço IP associado à propriedade do controle.  
  
 *value*  
 Uma referência para o `DWORD` que contém o valor do campo de quatro do controle de endereço IP. Os campos são preenchidos ou como segue.  
  
|Campo|Que contém o valor do campo de bits|  
|-----------|-------------------------------------|  
|3|0 a 7|  
|2|8 a 15|  
|1|16 a 23|  
|0|24 a 31|  
  
 Usar o Win32 [IPM_GETADDRESS](http://msdn.microsoft.com/library/windows/desktop/bb761378) para ler o valor ou use [IPM_SETADDRESS](http://msdn.microsoft.com/library/windows/desktop/bb761380) para preencher o valor. Essas mensagens são descritas no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
### <a name="remarks"></a>Comentários  
 Quando `DDX_IPAddress` é chamado, *valor* é leia o controle de endereço IP, ou *valor* é gravado para o controle, dependendo da direção do exchange.  
  
 Para obter mais informações sobre DDX, consulte [troca de dados de caixa de diálogo e validação](../../mfc/dialog-data-exchange-and-validation.md).  
  
### <a name="requirements"></a>Requisitos  
  **Cabeçalho** afxdd_.h  
  
##  <a name="a-nameddxlbindexa--ddxlbindex"></a><a name="ddx_lbindex"></a>DDX_LBIndex  
 O `DDX_LBIndex` função gerencia a transferência de `int` dados entre um controle de caixa de listagem em uma caixa de diálogo, exibição ou objeto de exibição de controle de formulário e um `int` membro de dados do objeto de exibição de controle, exibição de formulário ou caixa de diálogo.  
  
```  
void AFXAPI DDX_LBIndex(
    CDataExchange* pDX,  
    int nIDC,  
    int& index);  
```  
  
### <a name="parameters"></a>Parâmetros  
 `pDX`  
 Um ponteiro para um `CDataExchange` objeto. O framework fornece esse objeto para estabelecer o contexto de troca de dados, incluindo sua direção.  
  
 `nIDC`  
 A ID de controle de caixa de listagem associada com a propriedade de controle de recursos.  
  
 *índice*  
 Uma referência a uma variável de membro do objeto de exibição de controle com o qual os dados são trocados, exibição de formulário ou caixa de diálogo.  
  
### <a name="remarks"></a>Comentários  
 Quando `DDX_LBIndex` é chamado, *índice* é definida para o índice da seleção atual de caixa de lista. Se nenhum item é selecionado, *índice* é definido como -1.  
  
 Para obter mais informações sobre DDX, consulte [troca de dados de caixa de diálogo e validação](../../mfc/dialog-data-exchange-and-validation.md).  
  
### <a name="requirements"></a>Requisitos  
  **Cabeçalho** afxdd_.h  
  
##  <a name="a-nameddxlbstringa--ddxlbstring"></a><a name="ddx_lbstring"></a>DDX_LBString  
 O `DDX_LBString` função gerencia a transferência de `CString` dados entre um controle de caixa de listagem em uma caixa de diálogo, exibição ou objeto de exibição de controle de formulário e um `CString` membro de dados do objeto de exibição de controle, exibição de formulário ou caixa de diálogo.  
  
```  
void AFXAPI DDX_LBString(
    CDataExchange* pDX,  
    int nIDC,  
    CString& value);  
```  
  
### <a name="parameters"></a>Parâmetros  
 `pDX`  
 Um ponteiro para um `CDataExchange` objeto. O framework fornece esse objeto para estabelecer o contexto de troca de dados, incluindo sua direção.  
  
 `nIDC`  
 A ID de controle de caixa de listagem associada com a propriedade de controle de recursos.  
  
 *value*  
 Uma referência a uma variável de membro do objeto de exibição de controle com o qual os dados são trocados, exibição de formulário ou caixa de diálogo.  
  
### <a name="remarks"></a>Comentários  
 Quando `DDX_LBString` é chamado para transferir dados para um controle de caixa de listagem, o primeiro item no controle corresponde cujo início *valor* está selecionado. (Para corresponder o item inteiro em vez de apenas um prefixo, use [DDX_LBStringExact](#ddx_lbstringexact).) Se não houver nenhuma correspondência, nenhum item está selecionado. A correspondência diferencia maiusculas de minúsculas.  
  
 Quando `DDX_LBString` é chamado para transferir dados de um controle de caixa de listagem, *valor* está definido para a seleção atual da caixa de lista. Se nenhum item é selecionado, *valor* é definido como uma cadeia de caracteres de comprimento zero.  
  
> [!NOTE]
>  Se a caixa de lista é uma lista suspensa, o valor trocado é limitado a 255 caracteres.  
  
 Para obter mais informações sobre DDX, consulte [troca de dados de caixa de diálogo e validação](../../mfc/dialog-data-exchange-and-validation.md).  
  
### <a name="requirements"></a>Requisitos  
  **Cabeçalho** afxdd_.h  
  
##  <a name="a-nameddxlbstringexacta--ddxlbstringexact"></a><a name="ddx_lbstringexact"></a>DDX_LBStringExact  
 O `DDX_CBStringExact` função gerencia a transferência de `CString` dados entre o controle de edição de um controle de caixa de listagem em uma caixa de diálogo, exibição ou objeto de exibição de controle de formulário e um `CString` membro de dados do objeto de exibição de controle, exibição de formulário ou caixa de diálogo.  
  
```  
void AFXAPI DDX_LBStringExact(
    CDataExchange* pDX,  
    int nIDC,  
    CString& value);  
```  
  
### <a name="parameters"></a>Parâmetros  
 `pDX`  
 Um ponteiro para um `CDataExchange` objeto. O framework fornece esse objeto para estabelecer o contexto de troca de dados, incluindo sua direção.  
  
 `nIDC`  
 A ID de controle de caixa de listagem associada com a propriedade de controle de recursos.  
  
 *value*  
 Uma referência a uma variável de membro do objeto de exibição de controle com o qual os dados são trocados, exibição de formulário ou caixa de diálogo.  
  
### <a name="remarks"></a>Comentários  
 Quando `DDX_LBStringExact` é chamado para transferir dados para um controle de caixa de listagem, o primeiro item no controle que corresponde a *valor* está selecionado. (Para corresponder apenas um prefixo em vez do item inteiro, use [DDX_LBString](#ddx_lbstring).) Se não houver nenhuma correspondência, nenhum item está selecionado. A correspondência diferencia maiusculas de minúsculas.  
  
 Quando `DDX_CBStringExact` é chamado para transferir dados de um controle de caixa de listagem, *valor* está definido para a seleção atual da caixa de lista. Se nenhum item é selecionado, *valor* é definido como uma cadeia de caracteres de comprimento zero.  
  
> [!NOTE]
>  Se a caixa de lista é uma lista suspensa, o valor trocado é limitado a 255 caracteres.  
  
 Para obter mais informações sobre DDX, consulte [troca de dados de caixa de diálogo e validação](../../mfc/dialog-data-exchange-and-validation.md).  
  
### <a name="requirements"></a>Requisitos  
  **Cabeçalho** afxdd_.h  
  
##  <a name="a-nameddxmonthcalctrla--ddxmonthcalctrl"></a><a name="ddx_monthcalctrl"></a>DDX_MonthCalCtrl  
 O `DDX_MonthCalCtrl` função gerencia a transferência de dados de data entre um controle de calendário mensal ( [CMonthCalCtrl](../../mfc/reference/cmonthcalctrl-class.md)) em uma caixa de diálogo, modo de exibição de formulário, ou objeto de exibição de controle e um [CTime](../../atl-mfc-shared/reference/ctime-class.md) ou um [COleDateTime](../../atl-mfc-shared/reference/coledatetime-class.md) membro de dados do objeto de exibição de controle, exibição de formulário ou caixa de diálogo.  
  
```  
void AFXAPI DDX_MonthCalCtrl(
    CDataExchange* pDX,  
    int nIDC,  
    CTime& value);

void AFXAPI DDX_MonthCalCtrl(
    CDataExchange* pDX,  
    int nIDC,  
    COleDateTime& value);  
```  
  
### <a name="parameters"></a>Parâmetros  
 `pDX`  
 Um ponteiro para um [CDataExchange](../../mfc/reference/cdataexchange-class.md) objeto. O framework fornece esse objeto para estabelecer o contexto de troca de dados, incluindo sua direção. Você não precisa excluir este objeto.  
  
 `nIDC`  
 A ID de recurso do controle de calendário do mês associado à variável de membro.  
  
 *value*  
 Uma referência a um `CTime` ou `COleDateTime` variável de membro do objeto de exibição de controle com o qual os dados são trocados, exibição de formulário ou caixa de diálogo.  
  
### <a name="remarks"></a>Comentários  
  
> [!NOTE]
>  O controle gerencia um valor de data. Os campos de hora no objeto de tempo estão definido para refletir a hora de criação da janela de controle ou qualquer tempo foi definido no controle com uma chamada para `CMonthCalCtrl::SetCurSel`.  
  
 Quando `DDX_MonthCalCtrl` é chamado, *valor* está definido para o estado atual do controle de calendário do mês.  
  
 Para obter mais informações sobre DDX, consulte [troca de dados de caixa de diálogo e validação](../../mfc/dialog-data-exchange-and-validation.md).  
  
### <a name="requirements"></a>Requisitos  
  **Cabeçalho** afxdd_.h  
  
##  <a name="a-nameddxradioa--ddxradio"></a><a name="ddx_radio"></a>DDX_Radio  
 O `DDX_Radio` função gerencia a transferência de `int` dados entre um grupo de controle de opção em uma caixa de diálogo, exibição ou objeto de exibição de controle de formulário e um `int` membro de dados do objeto de exibição de controle, exibição de formulário ou caixa de diálogo. O valor de `int` membro de dados é determinado de acordo com qual opção botão dentro do grupo é selecionado.  
  
```  
void AFXAPI DDX_Radio(
    CDataExchange* pDX,  
    int nIDC,  
    int& value);  
```  
  
### <a name="parameters"></a>Parâmetros  
 `pDX`  
 Um ponteiro para um `CDataExchange` objeto. O framework fornece esse objeto para estabelecer o contexto de troca de dados, incluindo sua direção.  
  
 `nIDC`  
 A ID de recurso do primeiro controle de rádio no grupo.  
  
 *value*  
 Uma referência a uma variável de membro do objeto de exibição de controle com o qual os dados são trocados, exibição de formulário ou caixa de diálogo.  
  
### <a name="remarks"></a>Comentários  
 Quando `DDX_Radio` é chamado, *valor* está definido para o estado atual do grupo de controle de rádio. O valor é definido como um índice baseado em 0 do controle de rádio que atualmente é verificado ou -1 se não há controles de opção são verificadas.  
  
 Por exemplo, no caso em que o primeiro botão de opção no grupo é verificado (o botão com o estilo WS_GROUP) o valor da `int` membro é 0 e assim por diante.  
  
 Para obter mais informações sobre DDX, consulte [troca de dados de caixa de diálogo e validação](../../mfc/dialog-data-exchange-and-validation.md).  
  
### <a name="requirements"></a>Requisitos  
  **Cabeçalho** afxdd_.h  
  
##  <a name="a-nameddxscrolla--ddxscroll"></a><a name="ddx_scroll"></a>DDX_Scroll  
 O `DDX_Scroll` função gerencia a transferência de `int` dados entre um controle de barra de rolagem em uma caixa de diálogo, exibição ou objeto de exibição de controle de formulário e um `int` membro de dados do objeto de exibição de controle, exibição de formulário ou caixa de diálogo.  
  
```  
void AFXAPI DDX_Scroll(
    CDataExchange* pDX,  
    int nIDC,  
    int& value);  
```  
  
### <a name="parameters"></a>Parâmetros  
 `pDX`  
 Um ponteiro para um `CDataExchange` objeto. O framework fornece esse objeto para estabelecer o contexto de troca de dados, incluindo sua direção.  
  
 `nIDC`  
 A ID de controle barra de rolagem associado com a propriedade de controle de recursos.  
  
 *value*  
 Uma referência a uma variável de membro da caixa de diálogo, exibição de formulário ou controle exiba o objeto com o qual os dados são trocados.  
  
### <a name="remarks"></a>Comentários  
 Quando `DDX_Scroll` é chamado, *valor* é definido como a posição atual do thumb do controle. Para obter mais informações sobre os valores associados com a posição atual do thumb do controle, consulte [GetScrollPos](http://msdn.microsoft.com/library/windows/desktop/bb787585) no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
 Para obter mais informações sobre DDX, consulte [troca de dados de caixa de diálogo e validação](../../mfc/dialog-data-exchange-and-validation.md).  
  
### <a name="requirements"></a>Requisitos  
  **Cabeçalho** afxdd_.h  
  
##  <a name="a-nameddxslidera--ddxslider"></a><a name="ddx_slider"></a>DDX_Slider  
 O `DDX_Slider` função gerencia a transferência de `int` dados entre um controle deslizante em uma exibição de formulário ou caixa de diálogo e uma `int` membro de dados do objeto de exibição de formulário ou caixa de diálogo.  
  
```  
void AFXAPI DDX_Slider(
    CDataExchange* pDX,  
    int nIDC,  
    int& value);  
```  
  
### <a name="parameters"></a>Parâmetros  
 `pDX`  
 Um ponteiro para um [CDataExchange](../../mfc/reference/cdataexchange-class.md) objeto. O framework fornece esse objeto para estabelecer o contexto de troca de dados, incluindo sua direção.  
  
 `nIDC`  
 A ID de recurso do controle deslizante.  
  
 *value*  
 Uma referência para o valor a ser trocado. Este parâmetro contém ou define a posição atual do controle deslizante.  
  
### <a name="remarks"></a>Comentários  
 Quando `DDX_Slider` é chamado, *valor* é definido como a posição atual do thumb do controle, ou o valor recebe a posição, dependendo da direção do exchange.  
  
 Para obter mais informações sobre DDX, consulte [troca de dados de caixa de diálogo e validação](../../mfc/dialog-data-exchange-and-validation.md). Para obter informações sobre controles deslizantes, consulte [CSliderCtrl usando](../../mfc/using-csliderctrl.md).  
  
### <a name="requirements"></a>Requisitos  
  **Cabeçalho** afxdd_.h  
  
##  <a name="a-nameddxtexta--ddxtext"></a><a name="ddx_text"></a>DDX_Text  
 O `DDX_Text` função gerencia a transferência de `int`, **UINT**, **longo**, `DWORD`, `CString`, **float**, ou **duplo** dados entre um controle de edição na caixa de diálogo, exibição de formulário ou controle de exibição e uma [CString](../../atl-mfc-shared/reference/cstringt-class.md) membro de dados do objeto de exibição de controle, exibição de formulário ou caixa de diálogo.  
  
```  
void AFXAPI DDX_Text(
    CDataExchange* pDX,  
    int nIDC,  
    BYTE& value);

void AFXAPI DDX_Text(
    CDataExchange* pDX,  
    int nIDC,  
    short& value);

void AFXAPI DDX_Text(
    CDataExchange* pDX,  
    int nIDC,  
    int& value);

void AFXAPI DDX_Text(
    CDataExchange* pDX,  
    int nIDC,  
    UINT& value);

void AFXAPI DDX_Text(
    CDataExchange* pDX,  
    int nIDC,  
    long& value);

void AFXAPI DDX_Text(
    CDataExchange* pDX,  
    int nIDC,  
    DWORD& value);

void AFXAPI DDX_Text(
    CDataExchange* pDX,  
    int nIDC,  
    CString& value);

void AFXAPI DDX_Text(
    CDataExchange* pDX,  
    int nIDC,  
    float& value);

void AFXAPI DDX_Text(
    CDataExchange* pDX,  
    int nIDC,  
    double& value);

void AFXAPI DDX_Text(
    CDataExchange* pDX,  
    int nIDC,  
    COleCurrency& value);

void AFXAPI DDX_Text(
    CDataExchange* pDX,  
    int nIDC,  
    COleDateTime& value);  
```  
  
### <a name="parameters"></a>Parâmetros  
 `pDX`  
 Um ponteiro para um [CDataExchange](../../mfc/reference/cdataexchange-class.md) objeto. O framework fornece esse objeto para estabelecer o contexto de troca de dados, incluindo sua direção.  
  
 `nIDC`  
 A ID de um controle de edição na caixa de diálogo, exibição de formulário ou objeto de exibição de controle.  
  
 *value*  
 Uma referência a um membro de dados na caixa de diálogo, exibição de formulário ou objeto de exibição de controle. O tipo de dados *valor* depende de qual das versões sobrecarregadas do `DDX_Text` você usar.  
  
### <a name="remarks"></a>Comentários  
 Para obter mais informações sobre DDX, consulte [troca de dados de caixa de diálogo e validação](../../mfc/dialog-data-exchange-and-validation.md).  

### <a name="requirements"></a>Requisitos  
  **Cabeçalho** afxdd_.h  

## <a name="see-also"></a>Consulte também  
 [Rotinas de validação de dados de caixa de diálogo padrão](../../mfc/reference/standard-dialog-data-validation-routines.md)   
 [Macros e globais](../../mfc/reference/mfc-macros-and-globals.md)

