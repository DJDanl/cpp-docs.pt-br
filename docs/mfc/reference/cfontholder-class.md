---
title: Classe CFontHolder | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- CFontHolder
- AFXCTL/CFontHolder
- AFXCTL/CFontHolder::CFontHolder
- AFXCTL/CFontHolder::GetDisplayString
- AFXCTL/CFontHolder::GetFontDispatch
- AFXCTL/CFontHolder::GetFontHandle
- AFXCTL/CFontHolder::InitializeFont
- AFXCTL/CFontHolder::QueryTextMetrics
- AFXCTL/CFontHolder::ReleaseFont
- AFXCTL/CFontHolder::Select
- AFXCTL/CFontHolder::SetFont
- AFXCTL/CFontHolder::m_pFont
dev_langs:
- C++
helpviewer_keywords:
- CFontHolder [MFC], CFontHolder
- CFontHolder [MFC], GetDisplayString
- CFontHolder [MFC], GetFontDispatch
- CFontHolder [MFC], GetFontHandle
- CFontHolder [MFC], InitializeFont
- CFontHolder [MFC], QueryTextMetrics
- CFontHolder [MFC], ReleaseFont
- CFontHolder [MFC], Select
- CFontHolder [MFC], SetFont
- CFontHolder [MFC], m_pFont
ms.assetid: 728ab472-0c97-440d-889f-1324c6e1b6b8
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: dd5f13f2ec48f38fde140361d31a5e08ae6228b9
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="cfontholder-class"></a>Classe CFontHolder
Implementa a propriedade Font estoque e encapsula a funcionalidade de um objeto de fonte do Windows e o `IFont` interface.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class CFontHolder  
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CFontHolder::CFontHolder](#cfontholder)|Constrói um objeto `CFontHolder`.|  
  
### <a name="public-methods"></a>Métodos Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CFontHolder::GetDisplayString](#getdisplaystring)|Recupera a cadeia de caracteres exibida no navegador de propriedade do recipiente.|  
|[CFontHolder::GetFontDispatch](#getfontdispatch)|Retorna a fonte `IDispatch` interface.|  
|[CFontHolder::GetFontHandle](#getfonthandle)|Retorna um identificador para uma fonte do Windows.|  
|[CFontHolder::InitializeFont](#initializefont)|Inicializa uma `CFontHolder` objeto.|  
|[CFontHolder::QueryTextMetrics](#querytextmetrics)|Recupera as informações da fonte relacionados.|  
|[CFontHolder::ReleaseFont](#releasefont)|Desconecta o `CFontHolder` de objeto o `IFont` e `IFontNotification` interfaces.|  
|[CFontHolder::Select](#select)|Seleciona um recurso de fonte em um contexto de dispositivo.|  
|[CFontHolder::SetFont](#setfont)|Conecta-se a `CFontHolder` o objeto para um `IFont` interface.|  
  
### <a name="public-data-members"></a>Membros de Dados Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CFontHolder::m_pFont](#m_pfont)|Um ponteiro para o `CFontHolder` do objeto `IFont` interface.|  
  
## <a name="remarks"></a>Comentários  
 `CFontHolder`não tem uma classe base.  
  
 Use essa classe para implementar propriedades de fonte personalizada para seu controle. Para obter informações sobre como criar essas propriedades, consulte o artigo [controles ActiveX: usando fontes](../../mfc/mfc-activex-controls-using-fonts.md).  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 `CFontHolder`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxctl. h  
  
##  <a name="cfontholder"></a>CFontHolder::CFontHolder  
 Constrói um objeto `CFontHolder`.  
  
```  
explicit CFontHolder(LPPROPERTYNOTIFYSINK pNotify);
```  
  
### <a name="parameters"></a>Parâmetros  
 *pNotify*  
 Ponteiro para a fonte `IPropertyNotifySink` interface.  
  
### <a name="remarks"></a>Comentários  
 Você deve chamar `InitializeFont` para inicializar o objeto resultante antes de usá-lo.  
  
##  <a name="getdisplaystring"></a>CFontHolder::GetDisplayString  
 Recupera uma cadeia de caracteres que pode ser exibida no navegador de propriedade do recipiente.  
  
```  
BOOL GetDisplayString(CString& strValue);
```  
  
### <a name="parameters"></a>Parâmetros  
 `strValue`  
 Referência para o [CString](../../atl-mfc-shared/reference/cstringt-class.md) que é manter a cadeia de caracteres de exibição.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se a cadeia de caracteres é recuperada com êxito. Caso contrário, 0.  
  
##  <a name="getfontdispatch"></a>CFontHolder::GetFontDispatch  
 Chame essa função para recuperar um ponteiro para a interface de expedição da fonte.  
  
```  
LPFONTDISP GetFontDispatch();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um ponteiro para o `CFontHolder` do objeto **IFontDisp** interface. Observe que a função que chama `GetFontDispatch` deve chamar `IUnknown::Release` nesse ponteiro de interface quando fazê-lo.  
  
### <a name="remarks"></a>Comentários  
 Chamar `InitializeFont` antes de chamar `GetFontDispatch`.  
  
##  <a name="getfonthandle"></a>CFontHolder::GetFontHandle  
 Chame essa função para obter um identificador para uma fonte do Windows.  
  
```  
HFONT GetFontHandle();

 
HFONT GetFontHandle(
    long cyLogical,  
    long cyHimetric);
```  
  
### <a name="parameters"></a>Parâmetros  
 `cyLogical`  
 Altura, em unidades lógicas, do retângulo no qual o controle é desenhado.  
  
 `cyHimetric`  
 Altura, em `MM_HIMETRIC` unidades do controle.  
  
### <a name="return-value"></a>Valor de retorno  
 Um identificador para o objeto de fonte; Caso contrário, **nulo**.  
  
### <a name="remarks"></a>Comentários  
 A taxa de `cyLogical` e `cyHimetric` é usada para calcular o tamanho de exibição correta, em unidades lógicas, para que o tamanho do ponto da fonte é expresso em `MM_HIMETRIC` unidades:  
  
 Exibir tamanho = ( `cyLogical`  /  `cyHimetric`) X tamanho da fonte  
  
 A versão sem parâmetros retorna um identificador para uma fonte corretamente o tamanho da tela.  
  
##  <a name="initializefont"></a>CFontHolder::InitializeFont  
 Inicializa uma `CFontHolder` objeto.  
  
```  
void InitializeFont(
    const FONTDESC* pFontDesc = NULL,  
    LPDISPATCH pFontDispAmbient = NULL);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pFontDesc`  
 Ponteiro para uma estrutura de descrição da fonte ( [FONTDESC](http://msdn.microsoft.com/library/windows/desktop/ms692782)) que especifica as características da fonte.  
  
 `pFontDispAmbient`  
 Ponteiro para a propriedade fonte de ambiente do contêiner.  
  
### <a name="remarks"></a>Comentários  
 Se `pFontDispAmbient` não é **nulo**, o `CFontHolder` objeto está conectado a um clone do `IFont` interface usada pela propriedade fonte de ambiente do contêiner.  
  
 Se `pFontDispAmbient` é **nulo**, um novo objeto de fonte é criado a partir da descrição da fonte apontada pelo `pFontDesc` ou, se `pFontDesc` é **nulo**, uma descrição padrão.  
  
 Chamar essa função depois de construir um `CFontHolder` objeto.  
  
##  <a name="m_pfont"></a>CFontHolder::m_pFont  
 Um ponteiro para o `CFontHolder` do objeto `IFont` interface.  
  
```  
LPFONT m_pFont;  
```  
  
##  <a name="querytextmetrics"></a>CFontHolder::QueryTextMetrics  
 Recupera informações sobre a fonte física representada pelo `CFontHolder` objeto.  
  
```  
void QueryTextMetrics(LPTEXTMETRIC lptm);
```  
  
### <a name="parameters"></a>Parâmetros  
 `lptm`  
 Um ponteiro para um [TEXTMETRIC](http://msdn.microsoft.com/library/windows/desktop/dd145132) estrutura que receberá as informações.  
  
##  <a name="releasefont"></a>CFontHolder::ReleaseFont  
 Essa função desconecta o `CFontHolder` do objeto de seu `IFont` interface.  
  
```  
void ReleaseFont();
```  
  
##  <a name="select"></a>CFontHolder::Select  
 Chame essa função para selecionar a fonte do controle no contexto de dispositivo especificado.  
  
```  
CFont* Select(
    CDC* pDC,  
    long cyLogical,  
    long cyHimetric);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pDC`  
 Contexto de dispositivo no qual a fonte é selecionada.  
  
 `cyLogical`  
 Altura, em unidades lógicas, do retângulo no qual o controle é desenhado.  
  
 `cyHimetric`  
 Altura, em `MM_HIMETRIC` unidades do controle.  
  
### <a name="return-value"></a>Valor de retorno  
 Um ponteiro para a fonte que está sendo substituído.  
  
### <a name="remarks"></a>Comentários  
 Consulte [GetFontHandle](#getfonthandle) para uma discussão sobre o `cyLogical` e `cyHimetric` parâmetros.  
  
##  <a name="setfont"></a>CFontHolder::SetFont  
 Libera qualquer fonte existente e se conecta a `CFontHolder` o objeto para um `IFont` interface.  
  
```  
void SetFont(LPFONT pNewFont);
```  
  
### <a name="parameters"></a>Parâmetros  
 *pNewFont*  
 Ponteiro para o novo `IFont` interface.  
  
## <a name="see-also"></a>Consulte também  
 [Gráfico de hierarquia](../../mfc/hierarchy-chart.md)   
 [Classe CPropExchange](../../mfc/reference/cpropexchange-class.md)
