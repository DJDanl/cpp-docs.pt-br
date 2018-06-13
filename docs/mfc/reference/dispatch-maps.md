---
title: Mapas de envios | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: reference
f1_keywords:
- vc.mfc.macros.maps
dev_langs:
- C++
helpviewer_keywords:
- dispatch maps [MFC], macros
- dispatch maps [MFC]
- dispatch map macros [MFC]
ms.assetid: bef9d08b-ad35-4c3a-99d8-04150c7c04e2
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 313e465698da5799a107bc3bdbeb6d2cbbe47303
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33377090"
---
# <a name="dispatch-maps"></a>Mapas de expedição
Automação OLE fornece maneiras para chamar os métodos e acessar propriedades em aplicativos. O mecanismo fornecido pelo biblioteca Microsoft Foundation Class para distribuir essas solicitações é o "mapa de expedição", que designa os nomes internos e externos de funções de objetos e propriedades, bem como os tipos de dados das propriedades de si mesmos e do argumentos de função.  
  
### <a name="dispatch-maps"></a>Mapas de expedição  
  
|||  
|-|-|  
|[DECLARE_DISPATCH_MAP](#declare_dispatch_map)|Declara que um mapa de expedição será usado para expor métodos e propriedades (deve ser usado na declaração da classe) de uma classe.|  
|[BEGIN_DISPATCH_MAP](#begin_dispatch_map)|Inicia a definição de um mapa de expedição.|  
|[END_DISPATCH_MAP](#end_dispatch_map)|Finaliza a definição de um mapa de expedição.|  
|[DISP_FUNCTION](#disp_function)|Usado em um mapa de expedição para definir uma função de automação OLE.|  
|[DISP_PROPERTY](#disp_property)|Define uma propriedade de automação OLE.|  
|[DISP_PROPERTY_EX](#disp_property_ex)|Define uma propriedade de automação OLE e nomeia as funções Get e Set.|  
|[DISP_PROPERTY_NOTIFY](#disp_property_notify)|Define uma propriedade de automação OLE com a notificação.|  
|[DISP_PROPERTY_PARAM](#disp_property_param)|Define uma propriedade de automação OLE que usa nomes e os parâmetros que as funções Get e Set.|  
|[DISP_DEFVALUE](#disp_defvalue)|Torna o valor padrão de um objeto de uma propriedade existente.|  
  
##  <a name="declare_dispatch_map"></a>  DECLARE_DISPATCH_MAP  
 Se um `CCmdTarget`-classe derivada em seu programa dá suporte a automação OLE, que a classe deve fornecer um mapa de expedição para expor seus métodos e propriedades.  
  
```   
DECLARE_DISPATCH_MAP()  
```  
  
### <a name="remarks"></a>Comentários  
 Use o `DECLARE_DISPATCH_MAP` macro no final da sua declaração de classe. Em seguida, no. Funções de arquivo CPP que define o membro da classe, use o `BEGIN_DISPATCH_MAP` macro. Incluir entradas de macro para cada classe do exposto métodos e propriedades ( `DISP_FUNCTION`, `DISP_PROPERTY`e assim por diante). Por fim, use o `END_DISPATCH_MAP` macro.  
  
> [!NOTE]
>  Se você declarar membros após `DECLARE_DISPATCH_MAP`, você deve especificar um novo tipo de acesso ( **pública**, `private`, ou `protected`) para eles.  
  
 Os assistentes de Assistente de aplicativo e o código auxiliar na criação de classes de automação e na manutenção de mapas de expedição. Para obter mais informações sobre mapas de expedição, consulte [servidores de automação](../../mfc/automation-servers.md).  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFCAutomation#10](../../mfc/codesnippet/cpp/dispatch-maps_1.h)]  

### <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxwin.h  

##  <a name="begin_dispatch_map"></a>  BEGIN_DISPATCH_MAP  
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
 No arquivo de implementação (. cpp) que define as funções de membro para a sua classe, inicie o mapa de expedição com o `BEGIN_DISPATCH_MAP` macro, adicione entradas de macro para cada uma das suas funções de expedição e propriedades e concluir o mapa de expedição com o `END_DISPATCH_MAP` macro.  

### <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxdisp.h  

##  <a name="end_dispatch_map"></a>  END_DISPATCH_MAP  
 Finaliza a definição de seu mapa de expedição.  
  
```   
END_DISPATCH_MAP()  
```  
  
### <a name="remarks"></a>Comentários  
 Ele deve ser usado em conjunto com `BEGIN_DISPATCH_MAP`.  

### <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxdisp.h  

##  <a name="disp_function"></a>  DISP_FUNCTION  
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
 Uma lista separada por espaços de uma ou mais constantes especificando a lista de parâmetros da função.  
  
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
|`VT_DATE`|**DATE**|  
|`VT_BSTR`|`BSTR`|  
|**VT_DISPATCH**|`LPDISPATCH`|  
|`VT_ERROR`|`SCODE`|  
|`VT_BOOL`|**BOOL**|  
|**VT_VARIANT**|**VARIANT**|  
|**VT_UNKNOWN**|`LPUNKNOWN`|  
  
 O `vtsParams` argumento é uma lista separada dos valores a **VTS_** constantes. Um ou mais desses valores separados por espaços (não vírgulas) Especifica a lista de parâmetros da função. Por exemplo, 
  
 [!code-cpp[NVC_MFCAutomation#14](../../mfc/codesnippet/cpp/dispatch-maps_2.cpp)]  
  
 Especifica uma lista que contém um valor de inteiro curto seguido de um ponteiro para um inteiro curto.  
  
 O **VTS_** constantes e seus significados são os seguintes:  
  
|Símbolo|Tipo de parâmetro|  
|------------|--------------------|  
|**VTS_I2**|`Short`|  
|**VTS_I4**|`Long`|  
|**VTS_R4**|**Float**|  
|**VTS_R8**|`Double`|  
|**VTS_CY**|**Const CY** ou **CY\***|  
|**VTS_DATE**|**DATE**|  
|**VTS_BSTR**|`LPCSTR`|  
|**VTS_DISPATCH**|`LPDISPATCH`|  
|**VTS_SCODE**|`SCODE`|  
|**VTS_BOOL**|**BOOL**|  
|**VTS_VARIANT**|**VARIANTE const\***  ou **VARIANT &**|  
|**VTS_UNKNOWN**|`LPUNKNOWN`|  
|**VTS_PI2**|**short\***|  
|**VTS_PI4**|**long\***|  
|**VTS_PR4**|**float\***|  
|**VTS_PR8**|**Duplo\***|  
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

##  <a name="disp_property"></a>  DISP_PROPERTY  
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
|`VT_DATE`|**DATE**|  
|`VT_BSTR`|`CString`|  
|**VT_DISPATCH**|`LPDISPATCH`|  
|`VT_ERROR`|`SCODE`|  
|`VT_BOOL`|**BOOL**|  
|**VT_VARIANT**|**VARIANT**|  
|**VT_UNKNOWN**|`LPUNKNOWN`|  
  
 Quando um cliente externo altera a propriedade, o valor da variável de membro especificado por `memberName` altera; não há nenhuma notificação de alteração.  

### <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxdisp.h 

##  <a name="disp_property_ex"></a>  DISP_PROPERTY_EX  
 Define uma propriedade de automação OLE e o nome as funções usadas para obter e definir o valor da propriedade em um mapa de expedição.  
  
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
 O `memberGet` e `memberSet` funções têm assinaturas determinadas pelo `vtPropType` argumento. O `memberGet` função não utiliza argumentos e retorna um valor do tipo especificado pelo `vtPropType`. O `memberSet` função aceita um argumento do tipo especificado pelo `vtPropType` e não retorna nada.  
  
 O `vtPropType` argumento é do tipo **VARTYPE**. Os valores possíveis para esse argumento são tirados de `VARENUM` enumeração. Para obter uma lista desses valores, consulte os comentários para o `vtRetVal` parâmetro em [DISP_FUNCTION](#disp_function). Observe que `VT_EMPTY`, listado no `DISP_FUNCTION` comentários, não é permitido como um tipo de dados da propriedade.  

### <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxdisp.h 

##  <a name="disp_property_notify"></a>  DISP_PROPERTY_NOTIFY  
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
 Ao contrário das propriedades definidas com `DISP_PROPERTY`, uma propriedade definida com `DISP_PROPERTY_NOTIFY` automaticamente chamará a função especificada por `pfnAfterSet` quando a propriedade é alterada.  
  
 O `vtPropType` argumento é do tipo **VARTYPE**. Os valores possíveis para esse argumento são tirados de `VARENUM` enumeração:  
  
|Símbolo|**Tipo de propriedade**|  
|------------|-----------------------|  
|`VT_I2`|**short**|  
|`VT_I4`|**long**|  
|`VT_R4`|**float**|  
|`VT_R8`|**double**|  
|`VT_CY`|**CY**|  
|`VT_DATE`|**DATE**|  
|`VT_BSTR`|`CString`|  
|**VT_DISPATCH**|`LPDISPATCH`|  
|`VT_ERROR`|`SCODE`|  
|`VT_BOOL`|**BOOL**|  
|**VT_VARIANT**|**VARIANT**|  
|**VT_UNKNOWN**|`LPUNKNOWN`|  

### <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxdisp.h 

##  <a name="disp_property_param"></a>  DISP_PROPERTY_PARAM  
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
 Uma cadeia de caracteres de separada **VTS_** tipos de parâmetro variante, um para cada parâmetro.  
  
### <a name="remarks"></a>Comentários  
 Ao contrário de `DISP_PROPERTY_EX` macro, esta macro permite que você especifique uma lista de parâmetros para a propriedade. Isso é útil para implementar propriedades que são indexadas ou com parâmetros.  
  
### <a name="example"></a>Exemplo  
 Considere a seguinte declaração de get e membro do conjunto de funções que permitem ao usuário solicitar uma linha e coluna específica ao acessar a propriedade:  
  
 [!code-cpp[NVC_MFCActiveXControl#9](../../mfc/codesnippet/cpp/dispatch-maps_3.h)]  
  
 Eles correspondem ao seguinte `DISP_PROPERTY_PARAM` macro no mapa de expedição de controle:  
  
 [!code-cpp[NVC_MFCActiveXControl#10](../../mfc/codesnippet/cpp/dispatch-maps_4.cpp)]  
  
 Como outro exemplo, considere o seguinte get e membro do conjunto de funções:  
  
 [!code-cpp[NVC_MFCActiveXControl#11](../../mfc/codesnippet/cpp/dispatch-maps_5.h)]  
  
 Eles correspondem ao seguinte `DISP_PROPERTY_PARAM` macro no mapa de expedição de controle:  
  
 [!code-cpp[NVC_MFCActiveXControl#12](../../mfc/codesnippet/cpp/dispatch-maps_6.cpp)]  

### <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxdisp.h 

##  <a name="disp_defvalue"></a>  DISP_DEFVALUE  
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
 Usando um valor padrão pode tornar a programação de seu objeto de automação mais simples para aplicativos do Visual Basic.  
  
 "Valor padrão" de seu objeto é a propriedade que é recuperada ou definida quando uma referência a um objeto não especifica uma propriedade ou função de membro.  

### <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxdisp.h 

## <a name="see-also"></a>Consulte também  
 [Macros e globais](../../mfc/reference/mfc-macros-and-globals.md)
