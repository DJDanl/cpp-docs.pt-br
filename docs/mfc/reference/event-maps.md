---
title: Mapas de evento | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- vc.mfc.macros.maps
dev_langs:
- C++
helpviewer_keywords:
- event maps
ms.assetid: 1ed53aee-bc53-43cd-834a-6fb935c0d29b
caps.latest.revision: 15
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
ms.openlocfilehash: 4c4777496ce609d7c2fa20da726f211264095b6e
ms.lasthandoff: 02/25/2017

---
# <a name="event-maps"></a>Mapas de evento
Sempre que um controle deseja notificar seu contêiner que alguma ação (determinada pelo desenvolvedor do controle) aconteceu (como um pressionamento de tecla, clique do mouse ou uma alteração no estado do controle), ele chama uma função de acionamento de evento. Essa função notifica o contêiner de controle que alguma ação importante ocorreu, disparando o evento relacionado.  
  
 A biblioteca Microsoft Foundation Class oferece um modelo de programação otimizado para eventos acionados. Nesse modelo, "mapas de evento" são usados para designar quais funções disparar os eventos para um determinado controle. Mapas de evento contêm uma macro para cada evento. Por exemplo, um mapa de evento que dispara um estoque clique evento teria esta aparência:  
  
 [!code-cpp[NVC_MFCAxCtl n º&16;](../../mfc/reference/codesnippet/cpp/event-maps_1.cpp)]  
  
 O **EVENT_STOCK_CLICK** macro indica que o controle será disparado um clique evento sempre que detecta um mouse de estoque. Para obter uma lista mais detalhada dos outros eventos de estoque, consulte o artigo [controles ActiveX: eventos](../../mfc/mfc-activex-controls-events.md). Macros também estão disponíveis para indicar eventos personalizados.  
  
 Embora as macros de mapa de evento são importantes, geralmente não inseri-los diretamente. Isso ocorre porque a janela Propriedades cria automaticamente entradas de mapa de evento em seus arquivos de origem quando você usá-lo para associar a eventos de acionamento de evento funções. Qualquer momento em que você deseja editar ou adicionar uma entrada de mapa de evento, você pode usar a janela Propriedades.  
  
 Para oferecer suporte a mapas de evento, o MFC fornece as seguintes macros:  
  
### <a name="event-map-declaration-and-demarcation"></a>Declaração de mapa de evento e demarcação  
  
|||  
|-|-|  
|[DECLARE_EVENT_MAP](#declare_event_map)|Declara que um mapa de evento será usado em uma classe para mapear os eventos para funções de acionamento de evento (deve ser usado na declaração da classe).|  
|[BEGIN_EVENT_MAP](#begin_event_map)|Começa a definição de um mapa de evento (deve ser usado na implementação da classe).|  
|[END_EVENT_MAP](#end_event_map)|Termina a definição de um mapa de evento (deve ser usado na implementação da classe).|  
  
### <a name="event-mapping-macros"></a>Macros de mapeamento do evento  
  
|||  
|-|-|  
|[EVENT_CUSTOM](#event_custom)|Indica qual função de acionamento de evento irá disparar o evento especificado.|  
|[EVENT_CUSTOM_ID](#event_custom_id)|Indica qual função de acionamento de evento irá disparar o evento especificado, com uma ID de expedição designado.|  
  
### <a name="message-mapping-macros"></a>Macros de mapeamento de mensagem  
  
|||  
|-|-|  
|[ON_OLEVERB](#on_oleverb)|Indica um verbo personalizado tratado pelo controle OLE.|  
|[ON_STDOLEVERB](#on_stdoleverb)|Substitui um mapeamento de verbo padrão do controle OLE.|  
  
##  <a name="a-namedeclareeventmapa--declareeventmap"></a><a name="declare_event_map"></a>DECLARE_EVENT_MAP  
 Cada `COleControl`-classe derivada em seu programa pode fornecer um mapa de evento para especificar os eventos que o controle será acionado.  
  
```   
DECLARE_EVENT_MAP()   
```  
  
### <a name="remarks"></a>Comentários  
 Use o `DECLARE_EVENT_MAP` macro no final da sua declaração de classe. Em seguida, no arquivo. cpp que define as funções de membro da classe, use o `BEGIN_EVENT_MAP` macro, entradas de macro para cada um dos eventos do controle e o `END_EVENT_MAP` macro para declarar o final da lista de eventos.  
  
 Para obter mais informações sobre mapas de evento, consulte o artigo [controles ActiveX: eventos](../../mfc/mfc-activex-controls-events.md).  
  
### <a name="requirements"></a>Requisitos  
  **Cabeçalho** afxctl.h  
  
##  <a name="a-namebegineventmapa--begineventmap"></a><a name="begin_event_map"></a>BEGIN_EVENT_MAP  
 Começa a definição do mapa de evento.  
  
```   
BEGIN_EVENT_MAP(theClass,  baseClass)  
```  
  
### <a name="parameters"></a>Parâmetros  
 `theClass`  
 Especifica o nome da classe de controle cujo evento mapear isso.  
  
 `baseClass`  
 Especifica o nome da classe base da `theClass`.  
  
### <a name="remarks"></a>Comentários  
 No arquivo de implementação (. cpp) que define as funções de membro da sua classe, inicie o mapa de evento com o `BEGIN_EVENT_MAP` macro, em seguida, adicionar entradas de macro para cada um de seus eventos e conclua o mapa de evento com o `END_EVENT_MAP` macro.  
  
 Para obter mais informações sobre o evento mapeia e `BEGIN_EVENT_MAP` macro, consulte o artigo [controles ActiveX: eventos](../../mfc/mfc-activex-controls-events.md).  
  
### <a name="requirements"></a>Requisitos  
  **Cabeçalho** afxctl.h  
  
##  <a name="a-nameendeventmapa--endeventmap"></a><a name="end_event_map"></a>END_EVENT_MAP  
 Use o `END_EVENT_MAP` macro para finalizar a definição do mapa de evento.  
  
```   
END_EVENT_MAP()   
```  
  
### <a name="requirements"></a>Requisitos  
  **Cabeçalho** afxctl.h  
  
##  <a name="a-nameeventcustoma--eventcustom"></a><a name="event_custom"></a>EVENT_CUSTOM  
 Define uma entrada de mapa de evento para um evento personalizado.  
  
```   
EVENT_CUSTOM(pszName, pfnFire,  vtsParams) 
```  
  
### <a name="parameters"></a>Parâmetros  
 `pszName`  
 O nome do evento.  
  
 `pfnFire`  
 O nome da função de acionamento do evento.  
  
 `vtsParams`  
 Uma lista separada por espaço de uma ou mais constantes especificando a lista de parâmetros da função.  
  
### <a name="remarks"></a>Comentários  
 O `vtsParams` parâmetro é uma lista separada por espaço dos valores a **VTS_** constantes. Um ou mais desses valores separados por espaços (não vírgulas) Especifica a lista de parâmetros da função. Por exemplo:  
  
 [!code-cpp[NVC_MFCActiveXControl&13;](../../mfc/codesnippet/cpp/event-maps_2.cpp)]  
  
 Especifica a cor de uma lista contendo um inteiro de 32 bits que representa um RGB valor, seguido por um ponteiro para o **IFontDisp** interface de um objeto de fonte OLE.  
  
 O **VTS_** constantes e seus significados são os seguintes:  
  
|Símbolo|Tipo de parâmetro|  
|------------|--------------------|  
|**VTS_I2**|**short**|  
|**VTS_I4**|**long**|  
|**VTS_R4**|**float**|  
|**VTS_R8**|**double**|  
|**VTS_COLOR**|**OLE_COLOR**|  
|**VTS_CY**|**MOEDA**|  
|**VTS_DATE**|**DATA**|  
|**VTS_BSTR**|**Const char\***|  
|**VTS_DISPATCH**|`LPDISPATCH`|  
|**VTS_FONT**|**IFontDispatch\***|  
|**VTS_HANDLE**|`HANDLE`|  
|**VTS_SCODE**|`SCODE`|  
|**VTS_BOOL**|**BOOL**|  
|**VTS_VARIANT**|**VARIANTE const\***|  
|**VTS_PVARIANT**|**VARIANT\***|  
|**VTS_UNKNOWN**|`LPUNKNOWN`|  
|**VTS_OPTEXCLUSIVE**|**OLE_OPTEXCLUSIVE**|  
|**VTS_PICTURE**|**IPictureDisp\***|  
|**VTS_TRISTATE**|**OLE_TRISTATE**|  
|**VTS_XPOS_PIXELS**|**OLE_XPOS_PIXELS**|  
|**VTS_YPOS_PIXELS**|**OLE_YPOS_PIXELS**|  
|**VTS_XSIZE_PIXELS**|**OLE_XSIZE_PIXELS**|  
|**VTS_YSIZE_PIXELS**|**OLE_YSIZE_PIXELS**|  
|**VTS_XPOS_HIMETRIC**|**OLE_XPOS_HIMETRIC**|  
|**VTS_YPOS_HIMETRIC**|**OLE_YPOS_HIMETRIC**|  
|**VTS_XSIZE_HIMETRIC**|**OLE_XSIZE_HIMETRIC**|  
|**VTS_YSIZE_HIMETRIC**|**OLE_YSIZE_HIMETRIC**|  
  
> [!NOTE]
>  Constantes variantes adicionais foram definidas para todos os tipos variantes, com exceção de **VTS_FONT** e **VTS_PICTURE**, que fornecem um ponteiro para a constante de dados variant. Essas constantes são nomeados usando o **VTS_P** `constantname` convenção. Por exemplo, **VTS_PCOLOR** é um ponteiro para um **VTS_COLOR** constante.  
  
### <a name="requirements"></a>Requisitos  
  **Cabeçalho** afxctl.h  
  
##  <a name="a-nameeventcustomida--eventcustomid"></a><a name="event_custom_id"></a>EVENT_CUSTOM_ID  
 Define um evento de disparo de função para um evento personalizado que pertence à ID de expedição especificado por `dispid`.  
  
```   
EVENT_CUSTOM_ID(
  pszName,   
  dispid,   
  pfnFire,
  vtsParams)  
 
```  
  
### <a name="parameters"></a>Parâmetros  
 `pszName`  
 O nome do evento.  
  
 `dispid`  
 A ID de expedição usada pelo controle ao disparar o evento.  
  
 `pfnFire`  
 O nome da função de acionamento do evento.  
  
 `vtsParams`  
 Uma lista de variáveis de parâmetros passados para o contêiner de controle quando o evento é disparado.  
  
### <a name="remarks"></a>Comentários  
 O `vtsParams` argumento é uma lista separada por espaço dos valores a **VTS_** constantes. Um ou mais desses valores separados por espaços, vírgulas não especifica a lista de parâmetros da função. Por exemplo:  
  
 [!code-cpp[NVC_MFCActiveXControl&13;](../../mfc/codesnippet/cpp/event-maps_2.cpp)]  
  
 Especifica a cor de uma lista contendo um inteiro de 32 bits que representa um RGB valor, seguido por um ponteiro para o **IFontDisp** interface de um objeto de fonte OLE.  
  
 Para obter uma lista de **VTS_** constantes, consulte [EVENT_CUSTOM](#event_custom).  
  
### <a name="requirements"></a>Requisitos  
  **Cabeçalho** afxctl.h  
  
##  <a name="a-nameonoleverba--onoleverb"></a><a name="on_oleverb"></a>ON_OLEVERB  
 Essa macro define uma entrada de mapa de mensagem que mapeia um verbo personalizado para uma função de membro específico do seu controle.  
  
```   
ON_OLEVERB(idsVerbName,  memberFxn)   
```  
  
### <a name="parameters"></a>Parâmetros  
 *idsVerbName*  
 A ID de recurso de cadeia de caracteres do nome do verbo.  
  
 `memberFxn`  
 A função chamada pela estrutura quando o verbo é invocado.  
  
### <a name="remarks"></a>Comentários  
 O editor de recursos pode ser usado para criar nomes de verbos personalizados que são adicionados à sua tabela de cadeia de caracteres.  
  
 O protótipo de função para `memberFxn` é:  
  
 `BOOL memberFxn(`    
 `LPMSG` `lpMsg` `,`   
 `HWND` `hWndParent` `,`   
 `LPCRECT` `lpRect`   `);`  
  
 Os valores da `lpMsg`, `hWndParent`, e `lpRect` parâmetros são obtidos dos parâmetros correspondentes do **IOleObject:: DoVerb** função de membro.  
  
### <a name="requirements"></a>Requisitos  
  **Cabeçalho** afxole.h  
  
##  <a name="a-nameonstdoleverba--onstdoleverb"></a><a name="on_stdoleverb"></a>ON_STDOLEVERB  
 Use essa macro para substituir o comportamento padrão de um verbo padrão.  
  
```   
ON_STDOLEVERB(iVerb,   memberFxn)   
```  
  
### <a name="parameters"></a>Parâmetros  
 `iVerb`  
 O índice de verbo padrão para o verbo que está sendo substituído.  
  
 `memberFxn`  
 A função chamada pela estrutura quando o verbo é invocado.  
  
### <a name="remarks"></a>Comentários  
 O índice de verbo padrão está no formato **OLEIVERB_**, seguido por uma ação. `OLEIVERB_SHOW`, `OLEIVERB_HIDE`, e `OLEIVERB_UIACTIVATE` são alguns exemplos de verbos padrão.  
  
 Consulte [ON_OLEVERB](#on_oleverb) para obter uma descrição do protótipo da função a ser usado como o `memberFxn` parâmetro.  

  
### <a name="requirements"></a>Requisitos  
  **Cabeçalho** afxole.h  
    
## <a name="see-also"></a>Consulte também  
 [Macros e globais](../../mfc/reference/mfc-macros-and-globals.md)

