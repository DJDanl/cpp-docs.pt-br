---
title: Classe COleDispatchDriver | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: reference
f1_keywords:
- COleDispatchDriver
- AFXDISP/COleDispatchDriver
- AFXDISP/COleDispatchDriver::COleDispatchDriver
- AFXDISP/COleDispatchDriver::AttachDispatch
- AFXDISP/COleDispatchDriver::CreateDispatch
- AFXDISP/COleDispatchDriver::DetachDispatch
- AFXDISP/COleDispatchDriver::GetProperty
- AFXDISP/COleDispatchDriver::InvokeHelper
- AFXDISP/COleDispatchDriver::ReleaseDispatch
- AFXDISP/COleDispatchDriver::SetProperty
- AFXDISP/COleDispatchDriver::m_bAutoRelease
- AFXDISP/COleDispatchDriver::m_lpDispatch
dev_langs:
- C++
helpviewer_keywords:
- COleDispatchDriver [MFC], COleDispatchDriver
- COleDispatchDriver [MFC], AttachDispatch
- COleDispatchDriver [MFC], CreateDispatch
- COleDispatchDriver [MFC], DetachDispatch
- COleDispatchDriver [MFC], GetProperty
- COleDispatchDriver [MFC], InvokeHelper
- COleDispatchDriver [MFC], ReleaseDispatch
- COleDispatchDriver [MFC], SetProperty
- COleDispatchDriver [MFC], m_bAutoRelease
- COleDispatchDriver [MFC], m_lpDispatch
ms.assetid: 3ed98daf-cdc7-4374-8a0c-cf695a8d3657
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: e25684e0adcace0510f74bdc98968ef52ad6d797
ms.sourcegitcommit: 9a0905c03a73c904014ec9fd3d6e59e4fa7813cd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/29/2018
ms.locfileid: "43209562"
---
# <a name="coledispatchdriver-class"></a>Classe COleDispatchDriver
implementa o lado do cliente da automação OLE.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class COleDispatchDriver  
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[COleDispatchDriver::COleDispatchDriver](#coledispatchdriver)|Constrói um objeto `COleDispatchDriver`.|  
  
### <a name="public-methods"></a>Métodos Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[COleDispatchDriver::AttachDispatch](#attachdispatch)|Anexa uma `IDispatch` conexão para o `COleDispatchDriver` objeto.|  
|[COleDispatchDriver::CreateDispatch](#createdispatch)|Cria uma `IDispatch` conexão e anexa-o para o `COleDispatchDriver` objeto.|  
|[COleDispatchDriver::DetachDispatch](#detachdispatch)|Desanexa um `IDispatch` conexão sem liberá-lo.|  
|[COleDispatchDriver::GetProperty](#getproperty)|Obtém uma propriedade de automação.|  
|[COleDispatchDriver::InvokeHelper](#invokehelper)|Auxiliar para chamar métodos de automação.|  
|[COleDispatchDriver::ReleaseDispatch](#releasedispatch)|Versões de um `IDispatch` conexão.|  
|[COleDispatchDriver::SetProperty](#setproperty)|Define uma propriedade de automação.|  
  
### <a name="public-operators"></a>Operadores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[COleDispatchDriver::operator =](#operator_eq)|Copia o valor de origem para o `COleDispatchDriver` objeto.|  
|[COleDispatchDriver::operator LPDISPATCH](#operator_lpdispatch)|Acessa subjacente `IDispatch` ponteiro.|  
  
### <a name="public-data-members"></a>Membros de Dados Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[COleDispatchDriver::m_bAutoRelease](#m_bautorelease)|Especifica se deve liberar o `IDispatch` durante a `ReleaseDispatch` ou destruição de objeto.|  
|[COleDispatchDriver::m_lpDispatch](#m_lpdispatch)|Indica o ponteiro para o `IDispatch` interface conectada a este `COleDispatchDriver`.|  
  
## <a name="remarks"></a>Comentários  
 `COleDispatchDriver` não tem uma classe base.  
  
 Interfaces de expedição OLE fornecem acesso a métodos e propriedades de um objeto. Funções de membro `COleDispatchDriver` anexar, desanexar, criar e liberar uma conexão de expedição do tipo `IDispatch`. Outras funções de membro usarem listas de argumentos variáveis para simplificar a chamada `IDispatch::Invoke`.  
  
 Essa classe pode ser usada diretamente, mas geralmente é usado apenas por classes criadas pelo assistente Adicionar classe. Quando você cria novas classes C++ importando uma biblioteca de tipos, as novas classes são derivadas de `COleDispatchDriver`.  
  
 Para obter mais informações sobre como usar `COleDispatchDriver`, consulte os seguintes artigos:  
  
- [Clientes de automação](../../mfc/automation-clients.md)  
  
- [Servidores de automação](../../mfc/automation-servers.md)  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 `COleDispatchDriver`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxdisp.h  
  
##  <a name="attachdispatch"></a>  COleDispatchDriver::AttachDispatch  
 Chame o `AttachDispatch` função de membro para anexar uma `IDispatch` ponteiro para o `COleDispatchDriver` objeto. Para obter mais informações, consulte [Implementando a IDispatch Interface](/previous-versions/windows/desktop/automat/implementing-the-idispatch-interface).  
  
```  
void AttachDispatch(
        LPDISPATCH lpDispatch,  
        BOOL bAutoRelease = TRUE);
```  
  
### <a name="parameters"></a>Parâmetros  
 *lpDispatch*  
 Ponteiro para uma OLE `IDispatch` o objeto a ser anexado ao `COleDispatchDriver` objeto.  
  
 *bAutoRelease*  
 Especifica se a expedição é ser liberado quando esse objeto sai do escopo.  
  
### <a name="remarks"></a>Comentários  
 Essa função libera qualquer `IDispatch` que já está anexado ao ponteiro a `COleDispatchDriver` objeto.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFCOleContainer#3](../../mfc/codesnippet/cpp/coledispatchdriver-class_1.cpp)]  
  
##  <a name="coledispatchdriver"></a>  COleDispatchDriver::COleDispatchDriver  
 Constrói um objeto `COleDispatchDriver`.  
  
```  
COleDispatchDriver();  
COleDispatchDriver(LPDISPATCH lpDispatch, BOOL bAutoRelease = TRUE);  
  COleDispatchDriver(const COleDispatchDriver& dispatchSrc);
```  
  
### <a name="parameters"></a>Parâmetros  
 *lpDispatch*  
 Ponteiro para uma OLE `IDispatch` o objeto a ser anexado ao `COleDispatchDriver` objeto.  
  
 *bAutoRelease*  
 Especifica se a expedição é ser liberado quando esse objeto sai do escopo.  
  
 *dispatchSrc*  
 Fazer referência a um existente `COleDispatchDriver` objeto.  
  
### <a name="remarks"></a>Comentários  
 O formulário `COleDispatchDriver`( `LPDISPATCH lpDispatch`, **BOOL**`bAutoRelease` = **TRUE**) conecta-se a [IDispatch](/previous-versions/windows/desktop/automat/implementing-the-idispatch-interface) interface.  
  
 O formulário `COleDispatchDriver`( **const**`COleDispatchDriver`& `dispatchSrc`) copia existente `COleDispatchDriver` do objeto e incrementa a contagem de referência.  
  
 O formulário `COleDispatchDriver`() cria um `COleDispatchDriver` do objeto, mas não se conecta a `IDispatch` interface. Antes de usar `COleDispatchDriver`() sem argumentos, você deve conectar-se um `IDispatch` a ele usando [COleDispatchDriver::CreateDispatch](#createdispatch) ou [COleDispatchDriver::AttachDispatch](#attachdispatch). Para obter mais informações, consulte [Implementando a IDispatch Interface](/previous-versions/windows/desktop/automat/implementing-the-idispatch-interface).  
  
### <a name="example"></a>Exemplo  
  Veja o exemplo de [COleDispatchDriver::CreateDispatch](#createdispatch).  
  
##  <a name="createdispatch"></a>  COleDispatchDriver::CreateDispatch  
 Cria uma [IDispatch](/previous-versions/windows/desktop/automat/implementing-the-idispatch-interface) objeto de interface e anexa-o para o `COleDispatchDriver` objeto.  
  
```  
BOOL CreateDispatch(
        REFCLSID clsid,  
        COleException* pError = NULL);

 
BOOL CreateDispatch(
    LPCTSTR lpszProgID,  
    COleException* pError = NULL);
```  
  
### <a name="parameters"></a>Parâmetros  
 *clsid*  
 ID de classe do `IDispatch` objeto de conexão a ser criado.  
  
 *pError*  
 Ponteiro para um objeto de exceção OLE, que manterá o código de status resultante da criação.  
  
 *lpszProgID*  
 Ponteiro para o identificador programático, como "Excel.Document.5", do objeto de automação para o qual o objeto de expedição deve ser criado.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero em caso de êxito; Caso contrário, 0.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFCOleContainer#4](../../mfc/codesnippet/cpp/coledispatchdriver-class_2.cpp)]  
  
##  <a name="detachdispatch"></a>  COleDispatchDriver::DetachDispatch  
 Desanexa a atual `IDispatch` conexão deste objeto.  
  
```  
LPDISPATCH DetachDispatch();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um ponteiro para o OLE anexado anteriormente `IDispatch` objeto.  
  
### <a name="remarks"></a>Comentários  
 O `IDispatch` não é liberado.  
  
 Para obter mais informações sobre o tipo LPDISPATCH, consulte [Implementando a IDispatch Interface](/previous-versions/windows/desktop/automat/implementing-the-idispatch-interface) no SDK do Windows.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFCOleContainer#5](../../mfc/codesnippet/cpp/coledispatchdriver-class_3.cpp)]  
  
##  <a name="getproperty"></a>  COleDispatchDriver::GetProperty  
 Obtém a propriedade do objeto especificada por *dwDispID*.  
  
```  
void GetProperty(
    DISPID dwDispID,  
    VARTYPE vtProp,  
    void* pvProp) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 *dwDispID*  
 Identifica a propriedade a ser recuperado.  
  
 *vtProp*  
 Especifica a propriedade a ser recuperado. Para os valores possíveis, consulte a seção comentários para [COleDispatchDriver::InvokeHelper](#invokehelper).  
  
 *pvProp*  
 Endereço da variável que receberá o valor da propriedade. Ele deve corresponder ao tipo especificado pelo *vtProp*.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFCOleContainer#6](../../mfc/codesnippet/cpp/coledispatchdriver-class_4.cpp)]  
  
##  <a name="invokehelper"></a>  COleDispatchDriver::InvokeHelper  
 Chama o método de objeto ou a propriedade especificada por *dwDispID*, no contexto especificado por *wFlags*.  
  
```  
void AFX_CDECL InvokeHelper(
        DISPID dwDispID,  
        WORD wFlags,  
        VARTYPE vtRet,  
        void* pvRet,  
        const BYTE* pbParamInfo, ...);
```  
  
### <a name="parameters"></a>Parâmetros  
 *dwDispID*  
 Identifica o método ou propriedade a ser invocado.  
  
 *wFlags*  
 Sinalizadores que descrevem o contexto da chamada para `IDispatch::Invoke`. . Para obter uma lista de valores possíveis, consulte o *wFlags* parâmetro na [IDispatch:: Invoke](/previous-versions/windows/desktop/api/oaidl/nf-oaidl-idispatch-invoke) no SDK do Windows.  
  
 *vtRet*  
 Especifica o tipo do valor de retorno. Para os valores possíveis, consulte a seção comentários.  
  
 *pvRet*  
 Endereço da variável que receberá o valor da propriedade ou valor de retorno. Ele deve corresponder ao tipo especificado pelo *vtRet*.  
  
 *pbParamInfo*  
 Ponteiro para uma cadeia de caracteres terminada em nulo de bytes que especifica os tipos dos parâmetros a seguir *pbParamInfo*.  
  
 *...*  
 A lista de variáveis de parâmetros de tipos especificados em *pbParamInfo*.  
  
### <a name="remarks"></a>Comentários  
 O *pbParamInfo* parâmetro especifica os tipos dos parâmetros passados para o método ou propriedade. A lista de argumentos de variáveis é representada por **...**  na declaração de sintaxe.  
  
 Os valores possíveis para o *vtRet* argumento são obtidos a partir da enumeração VARENUM. Os valores possíveis são:  
  
|Símbolo|Tipo de retorno|  
|------------|-----------------|  
|VT_EMPTY|**void**|  
|VT_I2|**short**|  
|VT_I4|**long**|  
|VT_R4|**float**|  
|VT_R8|**double**|  
|VT_CY|**CY**|  
|VT_DATE|**DATE**|  
|VT_BSTR|BSTR|  
|VT_DISPATCH|LPDISPATCH|  
|VT_ERROR|SCODE|  
|VT_BOOL|**BOOL**|  
|VT_VARIANT|**VARIANT**|  
|VT_UNKNOWN|LPUNKNOWN|  
  
 O *pbParamInfo* argumento é uma lista separada por espaço **VTS_** constantes. Um ou mais desses valores, separados por espaços (não a vírgula), especifica a lista de parâmetros da função. Os valores possíveis são listados com o [EVENT_CUSTOM](event-maps.md#event_custom) macro.  
  
 Esta função converte os parâmetros para valores VARIANTARG, em seguida, invoca o [IDispatch:: Invoke](/previous-versions/windows/desktop/api/oaidl/nf-oaidl-idispatch-invoke) método. Se a chamada para `Invoke` falhar, essa função gerará uma exceção. Se o SCODE (código de status) retornado por `IDispatch::Invoke` é DISP_E_EXCEPTION, essa função gera uma [COleException](../../mfc/reference/coleexception-class.md) objeto; caso contrário, ele gerará uma [COleDispatchException](../../mfc/reference/coledispatchexception-class.md).  
  
 Para obter mais informações, consulte [VARIANTARG](/previous-versions/windows/desktop/api/oaidl/ns-oaidl-tagvariant), [Implementando a IDispatch Interface](/previous-versions/windows/desktop/automat/implementing-the-idispatch-interface), [IDispatch:: Invoke](/previous-versions/windows/desktop/api/oaidl/nf-oaidl-idispatch-invoke), e [estrutura de códigos de erro COM](/windows/desktop/com/structure-of-com-error-codes) em que o Windows SDK.  
  
### <a name="example"></a>Exemplo  
  Veja o exemplo de [COleDispatchDriver::CreateDispatch](#createdispatch).  
  
##  <a name="m_bautorelease"></a>  COleDispatchDriver::m_bAutoRelease  
 Se for TRUE, o objeto COM é acessado por [m_lpDispatch](#m_lpdispatch) será automaticamente liberado quando [ReleaseDispatch](#releasedispatch) é chamado ou quando isso `COleDispatchDriver` objeto é destruído.  
  
```  
BOOL m_bAutoRelease;  
```  
  
### <a name="remarks"></a>Comentários  
 Por padrão, `m_bAutoRelease` está definido como TRUE no construtor.  
  
 Para obter mais informações sobre a liberação de objetos COM, consulte [implementação de contagem de referência](/windows/desktop/com/implementing-reference-counting) e [IUnknown:: Release](/windows/desktop/api/unknwn/nf-unknwn-iunknown-release) no SDK do Windows.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFCOleContainer#9](../../mfc/codesnippet/cpp/coledispatchdriver-class_5.cpp)]  
  
##  <a name="m_lpdispatch"></a>  COleDispatchDriver::m_lpDispatch  
 O ponteiro para o `IDispatch` interface conectada a este `COleDispatchDriver`.  
  
```  
LPDISPATCH m_lpDispatch;  
```  
  
### <a name="remarks"></a>Comentários  
 O `m_lpDispatch` membro de dados é uma variável pública do tipo LPDISPATCH.  
  
 Para obter mais informações, consulte [IDispatch](/previous-versions/windows/desktop/automat/implementing-the-idispatch-interface) no SDK do Windows.  
  
### <a name="example"></a>Exemplo  
  Veja o exemplo de [COleDispatchDriver::AttachDispatch](#attachdispatch).  
  
##  <a name="operator_eq"></a>  COleDispatchDriver::operator =  
 Copia o valor de origem para o `COleDispatchDriver` objeto.  
  
```  
const COleDispatchDriver& operator=(const COleDispatchDriver& dispatchSrc);
```  
  
### <a name="parameters"></a>Parâmetros  
 *dispatchSrc*  
 Um ponteiro para um existente `COleDispatchDriver` objeto.  
  
##  <a name="operator_lpdispatch"></a>  COleDispatchDriver::operator LPDISPATCH  
 Acessa subjacente `IDispatch` ponteiro do `COleDispatchDriver` objeto.  
  
```  
operator LPDISPATCH();
```   
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFCOleContainer#8](../../mfc/codesnippet/cpp/coledispatchdriver-class_6.cpp)]  
  
##  <a name="releasedispatch"></a>  COleDispatchDriver::ReleaseDispatch  
 Versões de `IDispatch` conexão. Para obter mais informações, consulte [Implementando a IDispatch Interface](/previous-versions/windows/desktop/automat/implementing-the-idispatch-interface)  
  
```  
void ReleaseDispatch();
```  
  
### <a name="remarks"></a>Comentários  
 Se a liberação automática tiver sido definida para essa conexão, essa função chama `IDispatch::Release` antes de liberar a interface.  
  
### <a name="example"></a>Exemplo  
  Veja o exemplo de [COleDispatchDriver::AttachDispatch](#attachdispatch).  
  
##  <a name="setproperty"></a>  COleDispatchDriver::SetProperty  
 Define a propriedade do objeto OLE especificada por *dwDispID*.  
  
```  
void AFX_CDECL SetProperty(
    DISPID dwDispID,  
    VARTYPE vtProp, ...);
```  
  
### <a name="parameters"></a>Parâmetros  
 *dwDispID*  
 Identifica a propriedade a ser definido.  
  
 *vtProp*  
 Especifica o tipo da propriedade a ser definido. Para os valores possíveis, consulte a seção comentários para [COleDispatchDriver::InvokeHelper](#invokehelper).  
  
 *...*  
 Um único parâmetro do tipo especificado pelo *vtProp*.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFCOleContainer#7](../../mfc/codesnippet/cpp/coledispatchdriver-class_7.cpp)]  
  
## <a name="see-also"></a>Consulte também  
 [Exemplo MFC CALCDRIV](../../visual-cpp-samples.md)   
 [Exemplo MFC ACDUAL](../../visual-cpp-samples.md)   
 [Gráfico da hierarquia](../../mfc/hierarchy-chart.md)   
 [Classe CCmdTarget](../../mfc/reference/ccmdtarget-class.md)
