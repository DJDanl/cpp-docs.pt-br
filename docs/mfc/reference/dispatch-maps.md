---
title: Mapas de envios | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- vc.mfc.macros.maps
dev_langs:
- C++
helpviewer_keywords:
- dispatch maps. macros
- dispatch maps
- dispatch map macros
ms.assetid: bef9d08b-ad35-4c3a-99d8-04150c7c04e2
caps.latest.revision: 14
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
ms.translationtype: Machine Translation
ms.sourcegitcommit: 17a158366f94d27b7a46917282425d652e6b9042
ms.openlocfilehash: 48e5d1fe207089733caa5ed9e8ca30c2de21f95f
ms.contentlocale: pt-br
ms.lasthandoff: 02/25/2017

---
# <a name="dispatch-maps"></a>Mapas de expedição
Automação OLE fornece maneiras para chamar métodos e acessar propriedades entre aplicativos. O mecanismo fornecido pela biblioteca Microsoft Foundation Class para despachar essas solicitações é o "mapa de expedição", que designa os nomes internos e externos de funções de objeto e propriedades, bem como os tipos de dados das propriedades próprias e argumentos da função.  
  
### <a name="dispatch-maps"></a>Mapas de expedição  
  
|||  
|-|-|  
|[DECLARE_DISPATCH_MAP](#declare_dispatch_map)|Declara que um mapa de expedição será usado para expor métodos e propriedades (deve ser usado na declaração da classe) de uma classe.|  
|[BEGIN_DISPATCH_MAP](#begin_dispatch_map)|Inicia a definição de um mapa de expedição.|  
|[END_DISPATCH_MAP](#end_dispatch_map)|Termina a definição de um mapa de expedição.|  
|[DISP_FUNCTION](#disp_function)|Usado em um mapa de expedição para definir uma função de automação OLE.|  
|[DISP_PROPERTY](#disp_property)|Define uma propriedade de automação OLE.|  
|[DISP_PROPERTY_EX](#disp_property_ex)|Define uma propriedade de automação OLE e nomeia as funções Get e Set.|  
|[DISP_PROPERTY_NOTIFY](#disp_property_notify)|Define uma propriedade de automação OLE com a notificação.|  
|[DISP_PROPERTY_PARAM](#disp_property_param)|Define uma propriedade de automação OLE que usa os nomes e os parâmetros as funções Get e Set.|  
|[DISP_DEFVALUE](#disp_defvalue)|Torna o valor padrão de um objeto de uma propriedade existente.|  
  
##  <a name="declare_dispatch_map"></a>DECLARE_DISPATCH_MAP  
 Se um `CCmdTarget`-classe derivada em seu programa oferece suporte a automação OLE, que classe deve fornecer um mapa de expedição para expor seus métodos e propriedades.  
  
```   
DECLARE_DISPATCH_MAP()  
```  
  
### <a name="remarks"></a>Comentários  
 Use o `DECLARE_DISPATCH_MAP` macro no final da sua declaração de classe. Em seguida, na. Funções de arquivo CPP que define o membro da classe, use o `BEGIN_DISPATCH_MAP` macro. Incluir entradas de macro para cada um de sua classe do exposto métodos e propriedades ( `DISP_FUNCTION`, `DISP_PROPERTY`e assim por diante). Por fim, use o `END_DISPATCH_MAP` macro.  
  
> [!NOTE]
>  Se você declarar membros após `DECLARE_DISPATCH_MAP`, você deve especificar um novo tipo de acesso ( **pública**, `private`, ou `protected`) para eles.  
  
 Os assistentes do Assistente de aplicativo e o código auxiliar na criação de classes de automação e na manutenção de mapas de expedição. Para obter mais informações sobre mapas de expedição, consulte [servidores de automação](../../mfc/automation-servers.md).  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFCAutomation n º&10;](../../mfc/codesnippet/cpp/dispatch-maps_1.h)]  

### <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxwin. h  

##  <a name="begin_dispatch_map"></a>BEGIN_DISPATCH_MAP  
 Declara a definição de seu mapa de expedição.  
  
```  
BEGIN_DISPATCH_MAP(theClass, baseClass)   
```  
  
### <a name="parameters"></a>Parâmetros  
 `theClass`  
 Especifica o nome da classe que possui esse mapa de expedição.  
  
 `baseClass`  
 Especifica o nome da classe base `theClass`.  
  
### <a name="remarks"></a>Comentários  
 No arquivo de implementação (. cpp) que define as funções de membro da sua classe, inicie o mapa de expedição com o `BEGIN_DISPATCH_MAP` macro, adicione entradas de macro para cada uma das suas propriedades e funções de expedição e conclua o mapa de expedição com o `END_DISPATCH_MAP` macro.  

### <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxdisp.h  

##  <a name="end_dispatch_map"></a>END_DISPATCH_MAP  
 Termina a definição de seu mapa de expedição.  
  
```   
END_DISPATCH_MAP()  
```  
  
### <a name="remarks"></a>Comentários  
 Ele deve ser usado em conjunto com `BEGIN_DISPATCH_MAP`.  

### <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxdisp.h  

##  <a name="disp_function"></a>DISP_FUNCTION  
 Define uma função de automação OLE em um mapa de expedição.  
  
```   
DISP_FUNCTION(
  theClass, 
  pszName, 
  pfnMember, 
  vtRetVal, 
  vtsParams)   
```  
  
### <a name="parameters"></a>Parâmetros  
 `theClass`  
 Nome da classe.  
  
 `pszName`  
 Nome externo da função.  
  
 `pfnMember`  
 Nome da função de membro.  
  
 `vtRetVal`  
 Um valor que especifica o tipo de retorno da função.  
  
 `vtsParams`  
 Uma lista separada por espaço de uma ou mais constantes especificando a lista de parâmetros da função.  
  
### <a name="remarks"></a>Comentários  
 O `vtRetVal` argumento é do tipo **VARTYPE**. Os seguintes valores possíveis para esse argumento são tirados de `VARENUM` enumeração:  
  
|Símbolo|Tipo de retorno|  
|------------|-----------------|  
|`VT_EMPTY`|`void`|  
|`VT_I2`|**short**|  
|`VT_I4`|**long**|  
|`VT_R4`|**float**|  
|`VT_R8`|**double**|  
|`VT_CY`|**CY**|  
|`VT_DATE`|**DATA**|  
|`VT_BSTR`|`BSTR`|  
|**VT_DISPATCH**|`LPDISPATCH`|  
|`VT_ERROR`|`SCODE`|  
|`VT_BOOL`|**BOOL**|  
|**VT_VARIANT**|**VARIANT**|  
|**VT_UNKNOWN**|`LPUNKNOWN`|  
  
 O `vtsParams` argumento é uma lista separada por espaço dos valores a **VTS_** constantes. Um ou mais desses valores separados por espaços (não vírgulas) Especifica a lista de parâmetros da função. Por exemplo, 
  
 [!code-cpp[NVC_MFCAutomation&#14;](../../mfc/codesnippet/cpp/dispatch-maps_2.cpp)]  
  
 Especifica uma lista contendo um inteiro curto seguido por um ponteiro para um inteiro curto.  
  
 O **VTS_** constantes e seus significados são os seguintes:  
  
|Símbolo|Tipo de parâmetro|  
|------------|--------------------|  
|**VTS_I2**|`Short`|  
|**VTS_I4**|`Long`|  
|**VTS_R4**|**Float**|  
|**VTS_R8**|`Double`|  
|**VTS_CY**|**CY const** ou **CY\***|  
|**VTS_DATE**|**DATA**|  
|**VTS_BSTR**|`LPCSTR`|  
|**VTS_DISPATCH**|`LPDISPATCH`|  
|**VTS_SCODE**|`SCODE`|  
|**VTS_BOOL**|**BOOL**|  
|**VTS_VARIANT**|**VARIANTE const\* ** ou **VARIANT < /**|  
|**VTS_UNKNOWN**|`LPUNKNOWN`|  
|**VTS_PI2**|**curto\***|  
|**VTS_PI4**|**Longas\***|  
|**VTS_PR4**|**float\***|  
|**VTS_PR8**|**duplo\***|  
|**VTS_PCY**|**CY\***|  
|**VTS_PDATE**|**DATA\***|  
|**VTS_PBSTR**|**BSTR\***|  
|**VTS_PDISPATCH**|**LPDISPATCH\***|  
|**VTS_PSCODE**|**SCODE\***|  
|**VTS_PBOOL**|**BOOL\***|  
|**VTS_PVARIANT**|**VARIANT\***|  
|**VTS_PUNKNOWN**|**LPUNKNOWN\***|  
|**VTS_NONE**|Sem parâmetros|  

### <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxdisp.h 

##  <a name="disp_property"></a>DISP_PROPERTY  
 Define uma propriedade de automação OLE em um mapa de expedição.  
  
```   
DISP_PROPERTY(
  theClass, 
  pszName, 
  memberName, 
  vtPropType)   
```  
  
### <a name="parameters"></a>Parâmetros  
 `theClass`  
 Nome da classe.  
  
 `pszName`  
 Nome externo da propriedade.  
  
 `memberName`  
 Nome da variável de membro no qual a propriedade é armazenada.  
  
 `vtPropType`  
 Um valor que especifica o tipo da propriedade.  
  
### <a name="remarks"></a>Comentários  
 O `vtPropType` argumento é do tipo **VARTYPE**. Os valores possíveis para esse argumento são tirados de `VARENUM` enumeração:  
  
|Símbolo|**Tipo de propriedade**|  
|------------|-----------------------|  
|`VT_I2`|**short**|  
|`VT_I4`|**long**|  
|`VT_R4`|**float**|  
|`VT_R8`|**double**|  
|`VT_CY`|**CY**|  
|`VT_DATE`|**DATA**|  
|`VT_BSTR`|`CString`|  
|**VT_DISPATCH**|`LPDISPATCH`|  
|`VT_ERROR`|`SCODE`|  
|`VT_BOOL`|**BOOL**|  
|**VT_VARIANT**|**VARIANT**|  
|**VT_UNKNOWN**|`LPUNKNOWN`|  
  
 Quando um cliente externo altera a propriedade, o valor da variável de membro especificado por `memberName` muda; não há nenhuma notificação de alteração.  

### <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxdisp.h 

##  <a name="disp_property_ex"></a>DISP_PROPERTY_EX  
 Define um nome e uma propriedade de automação OLE as funções usadas para obter e definir o valor da propriedade em um mapa de expedição.  
  
```   
DISP_PROPERTY_EX(
  theClass, 
  pszName, 
  memberGet, 
  memberSet, 
  vtPropType)   
```  
  
### <a name="parameters"></a>Parâmetros  
 `theClass`  
 Nome da classe.  
  
 `pszName`  
 Nome externo da propriedade.  
  
 `memberGet`  
 Nome da função de membro usada para obter a propriedade.  
  
 `memberSet`  
 Nome da função de membro usada para definir a propriedade.  
  
 `vtPropType`  
 Um valor que especifica o tipo da propriedade.  
  
### <a name="remarks"></a>Comentários  
 O `memberGet` e `memberSet` funções têm assinaturas determinadas pelo `vtPropType` argumento. O `memberGet` função não utiliza argumentos e retorna um valor do tipo especificado por `vtPropType`. O `memberSet` função usa um argumento do tipo especificado pelo `vtPropType` e não retorna nada.  
  
 O `vtPropType` argumento é do tipo **VARTYPE**. Os valores possíveis para esse argumento são tirados de `VARENUM` enumeração. Para obter uma lista desses valores, consulte os comentários para o `vtRetVal` parâmetro em [DISP_FUNCTION](#disp_function). Observe que `VT_EMPTY`, listado no `DISP_FUNCTION` comentários, não é permitido como um tipo de dados da propriedade.  

### <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxdisp.h 

##  <a name="disp_property_notify"></a>DISP_PROPERTY_NOTIFY  
 Define uma propriedade de automação OLE com notificação em um mapa de expedição.  
  
```   
DISP_PROPERTY_NOTIFY(
  theClass, 
  szExternalName, 
  memberName, 
  pfnAfterSet, 
  vtPropType)   
```  
  
### <a name="parameters"></a>Parâmetros  
 `theClass`  
 Nome da classe.  
  
 `szExternalName`  
 Nome externo da propriedade.  
  
 `memberName`  
 Nome da variável de membro no qual a propriedade é armazenada.  
  
 `pfnAfterSet`  
 Nome da função de notificação para `szExternalName`.  
  
 `vtPropType`  
 Um valor que especifica o tipo da propriedade.  
  
### <a name="remarks"></a>Comentários  
 Ao contrário de propriedades definidas com `DISP_PROPERTY`, uma propriedade definida com `DISP_PROPERTY_NOTIFY` automaticamente chamará a função especificada por `pfnAfterSet` quando a propriedade é alterada.  
  
 O `vtPropType` argumento é do tipo **VARTYPE**. Os valores possíveis para esse argumento são tirados de `VARENUM` enumeração:  
  
|Símbolo|**Tipo de propriedade**|  
|------------|-----------------------|  
|`VT_I2`|**short**|  
|`VT_I4`|**long**|  
|`VT_R4`|**float**|  
|`VT_R8`|**double**|  
|`VT_CY`|**CY**|  
|`VT_DATE`|**DATA**|  
|`VT_BSTR`|`CString`|  
|**VT_DISPATCH**|`LPDISPATCH`|  
|`VT_ERROR`|`SCODE`|  
|`VT_BOOL`|**BOOL**|  
|**VT_VARIANT**|**VARIANT**|  
|**VT_UNKNOWN**|`LPUNKNOWN`|  

### <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxdisp.h 

##  <a name="disp_property_param"></a>DISP_PROPERTY_PARAM  
 Define uma propriedade acessada com separado **obter** e `Set` funções de membro.  
  
```   
DISP_PROPERTY_PARAM(
  theClass, 
  pszExternalName, 
  pfnGet, 
  pfnSet, 
  vtPropType,
  vtsParams)   
```  
  
### <a name="parameters"></a>Parâmetros  
 `theClass`  
 Nome da classe.  
  
 *pszExternalName*  
 Nome externo da propriedade.  
  
 `pfnGet`  
 Nome da função de membro usada para obter a propriedade.  
  
 `pfnSet`  
 Nome da função de membro usada para definir a propriedade.  
  
 `vtPropType`  
 Um valor que especifica o tipo da propriedade.  
  
 `vtsParams`  
 Uma cadeia de caracteres separada por espaço **VTS_** tipos de parâmetro variante, um para cada parâmetro.  
  
### <a name="remarks"></a>Comentários  
 Ao contrário do `DISP_PROPERTY_EX` macro, essa macro permite que você especifique uma lista de parâmetros para a propriedade. Isso é útil para implementar propriedades que são indexadas ou com parâmetros.  
  
### <a name="example"></a>Exemplo  
 Considere a seguinte declaração de get e membro do conjunto de funções que permitem ao usuário solicitar uma linha e coluna específica ao acessar a propriedade:  
  
 [!code-cpp[NVC_MFCActiveXControl n º&9;](../../mfc/codesnippet/cpp/dispatch-maps_3.h)]  
  
 Esses correspondem aos seguintes `DISP_PROPERTY_PARAM` macro no mapa de expedição de controle:  
  
 [!code-cpp[NVC_MFCActiveXControl n º&10;](../../mfc/codesnippet/cpp/dispatch-maps_4.cpp)]  
  
 Como outro exemplo, considere o seguinte get e membro do conjunto de funções:  
  
 [!code-cpp[NVC_MFCActiveXControl n º&11;](../../mfc/codesnippet/cpp/dispatch-maps_5.h)]  
  
 Esses correspondem aos seguintes `DISP_PROPERTY_PARAM` macro no mapa de expedição de controle:  
  
 [!code-cpp[NVC_MFCActiveXControl&#12;](../../mfc/codesnippet/cpp/dispatch-maps_6.cpp)]  

### <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxdisp.h 

##  <a name="disp_defvalue"></a>DISP_DEFVALUE  
 Torna o valor padrão de um objeto de uma propriedade existente.  
  
```   
DISP_DEFVALUE(theClass, pszName)   
```  
  
### <a name="parameters"></a>Parâmetros  
 `theClass`  
 Nome da classe.  
  
 `pszName`  
 Nome externo da propriedade que representa o "valor" do objeto.  
  
### <a name="remarks"></a>Comentários  
 Um valor padrão pode fazer programação de seu objeto de automação simples aos aplicativos Visual Basic.  
  
 O "valor padrão" do objeto é a propriedade que é recuperada ou definida quando uma referência a um objeto não especifica uma propriedade ou função de membro.  

### <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxdisp.h 

## <a name="see-also"></a>Consulte também  
 [Macros e globais](../../mfc/reference/mfc-macros-and-globals.md)

