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
ms.openlocfilehash: 57f9eaa33abd0f24a1d584c5ba2a1e4d6f9e5d44
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="coledispatchdriver-class"></a>Classe COleDispatchDriver
Implementa o lado do cliente de automação OLE.  
  
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
|[COleDispatchDriver::CreateDispatch](#createdispatch)|Cria um `IDispatch` conexão e anexa-o para o `COleDispatchDriver` objeto.|  
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
|[COleDispatchDriver::m_bAutoRelease](#m_bautorelease)|Especifica se deseja liberar o `IDispatch` durante `ReleaseDispatch` ou destruição de objeto.|  
|[COleDispatchDriver::m_lpDispatch](#m_lpdispatch)|Indica o ponteiro para o `IDispatch` interface conectada a este `COleDispatchDriver`.|  
  
## <a name="remarks"></a>Comentários  
 `COleDispatchDriver` não tem uma classe base.  
  
 Interfaces de expedição OLE fornecem acesso aos métodos e propriedades de um objeto. Funções de membro `COleDispatchDriver` anexar, desanexar, criar e liberar uma conexão de expedição do tipo `IDispatch`. Outras funções de membro usarem listas de argumentos variáveis para simplificar a chamada **IDispatch:: Invoke**.  
  
 Essa classe pode ser usada diretamente, mas geralmente é usado somente por classes criadas pelo Assistente para Adicionar classe. Quando você cria novas classes C++ importando uma biblioteca de tipos, as novas classes são derivadas de `COleDispatchDriver`.  
  
 Para obter mais informações sobre como usar `COleDispatchDriver`, consulte os seguintes artigos:  
  
- [Clientes de automação](../../mfc/automation-clients.md)  
  
- [Servidores de automação](../../mfc/automation-servers.md)  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 `COleDispatchDriver`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxdisp.h  
  
##  <a name="attachdispatch"></a>  COleDispatchDriver::AttachDispatch  
 Chamar o `AttachDispatch` a função de membro para anexar um `IDispatch` ponteiro para o `COleDispatchDriver` objeto. Para obter mais informações, consulte [Implementando a IDispatch Interface](http://msdn.microsoft.com/en-us/0e171f7f-0022-4e9b-ac8e-98192828e945).  
  
```  
void AttachDispatch(
        LPDISPATCH lpDispatch,  
        BOOL bAutoRelease = TRUE);
```  
  
### <a name="parameters"></a>Parâmetros  
 `lpDispatch`  
 Ponteiro para uma OLE `IDispatch` objeto a ser anexado ao `COleDispatchDriver` objeto.  
  
 `bAutoRelease`  
 Especifica se o envio será liberado quando este objeto sai do escopo.  
  
### <a name="remarks"></a>Comentários  
 Essa função libera qualquer `IDispatch` que já está anexado ao ponteiro de `COleDispatchDriver` objeto.  
  
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
 `lpDispatch`  
 Ponteiro para uma OLE `IDispatch` objeto a ser anexado ao `COleDispatchDriver` objeto.  
  
 `bAutoRelease`  
 Especifica se o envio será liberado quando este objeto sai do escopo.  
  
 `dispatchSrc`  
 Fazer referência a um existente `COleDispatchDriver` objeto.  
  
### <a name="remarks"></a>Comentários  
 O formulário `COleDispatchDriver`( `LPDISPATCH lpDispatch`, **BOOL**`bAutoRelease` = **TRUE**) conecta-se a [IDispatch](http://msdn.microsoft.com/en-us/0e171f7f-0022-4e9b-ac8e-98192828e945) interface.  
  
 O formulário `COleDispatchDriver`( **const**`COleDispatchDriver`& `dispatchSrc`) copia um existente `COleDispatchDriver` do objeto e incrementa a contagem de referência.  
  
 O formulário `COleDispatchDriver`() cria um `COleDispatchDriver` do objeto, mas não se conecta a `IDispatch` interface. Antes de usar `COleDispatchDriver`() sem argumentos, você deve conectar um `IDispatch` a ele usando o [COleDispatchDriver::CreateDispatch](#createdispatch) ou [COleDispatchDriver::AttachDispatch](#attachdispatch). Para obter mais informações, consulte [Implementando a IDispatch Interface](http://msdn.microsoft.com/en-us/0e171f7f-0022-4e9b-ac8e-98192828e945).  
  
### <a name="example"></a>Exemplo  
  Consulte o exemplo para [COleDispatchDriver::CreateDispatch](#createdispatch).  
  
##  <a name="createdispatch"></a>  COleDispatchDriver::CreateDispatch  
 Cria um [IDispatch](http://msdn.microsoft.com/en-us/0e171f7f-0022-4e9b-ac8e-98192828e945) objeto de interface e anexa-o para o `COleDispatchDriver` objeto.  
  
```  
BOOL CreateDispatch(
        REFCLSID clsid,  
        COleException* pError = NULL);

 
BOOL CreateDispatch(
    LPCTSTR lpszProgID,  
    COleException* pError = NULL);
```  
  
### <a name="parameters"></a>Parâmetros  
 `clsid`  
 ID de classe do `IDispatch` objeto de conexão a ser criado.  
  
 `pError`  
 Ponteiro para um objeto de exceção OLE, que contém o código de status resultante da criação.  
  
 `lpszProgID`  
 Ponteiro para o identificador programático, como "Excel.Document.5", do objeto de automação para o qual o objeto de expedição será criado.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero em caso de sucesso; Caso contrário, 0.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFCOleContainer#4](../../mfc/codesnippet/cpp/coledispatchdriver-class_2.cpp)]  
  
##  <a name="detachdispatch"></a>  COleDispatchDriver::DetachDispatch  
 Desanexa atual `IDispatch` conexão deste objeto.  
  
```  
LPDISPATCH DetachDispatch();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um ponteiro para o OLE anexado anteriormente `IDispatch` objeto.  
  
### <a name="remarks"></a>Comentários  
 O `IDispatch` não está liberada.  
  
 Para obter mais informações sobre o `LPDISPATCH` de tipo, consulte [Implementando a IDispatch Interface](http://msdn.microsoft.com/en-us/0e171f7f-0022-4e9b-ac8e-98192828e945) no SDK do Windows.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFCOleContainer#5](../../mfc/codesnippet/cpp/coledispatchdriver-class_3.cpp)]  
  
##  <a name="getproperty"></a>  COleDispatchDriver::GetProperty  
 Obtém a propriedade do objeto especificada pelo `dwDispID`.  
  
```  
void GetProperty(
    DISPID dwDispID,  
    VARTYPE vtProp,  
    void* pvProp) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 `dwDispID`  
 Identifica a propriedade a ser recuperado.  
  
 `vtProp`  
 Especifica a propriedade a ser recuperado. Para os valores possíveis, consulte a seção comentários para [COleDispatchDriver::InvokeHelper](#invokehelper).  
  
 `pvProp`  
 Endereço da variável que receberá o valor da propriedade. Ele deve corresponder ao tipo especificado pelo `vtProp`.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFCOleContainer#6](../../mfc/codesnippet/cpp/coledispatchdriver-class_4.cpp)]  
  
##  <a name="invokehelper"></a>  COleDispatchDriver::InvokeHelper  
 Chama o método de objeto ou a propriedade especificada pelo `dwDispID`, no contexto especificado pelos `wFlags`.  
  
```  
void AFX_CDECL InvokeHelper(
        DISPID dwDispID,  
        WORD wFlags,  
        VARTYPE vtRet,  
        void* pvRet,  
        const BYTE* pbParamInfo, ...);
```  
  
### <a name="parameters"></a>Parâmetros  
 `dwDispID`  
 Identifica o método ou propriedade a ser invocado.  
  
 `wFlags`  
 Sinalizadores que descrevem o contexto da chamada para **IDispatch:: Invoke**. . Para obter uma lista de valores possíveis, consulte o `wFlags` parâmetro em [IDispatch:: Invoke](http://msdn.microsoft.com/library/windows/desktop/ms221479\(v=vs.85\).aspx) no SDK do Windows.  
  
 `vtRet`  
 Especifica o tipo do valor de retorno. Para os valores possíveis, consulte a seção comentários.  
  
 `pvRet`  
 Endereço da variável que receberá o valor da propriedade ou valor de retorno. Ele deve corresponder ao tipo especificado pelo `vtRet`.  
  
 `pbParamInfo`  
 Ponteiro para uma cadeia de caracteres terminada em nulo de bytes especificando os tipos dos parâmetros a seguir `pbParamInfo`.  
  
 *...*  
 A lista de variáveis de parâmetros de tipos especificados no `pbParamInfo`.  
  
### <a name="remarks"></a>Comentários  
 O `pbParamInfo` parâmetro especifica os tipos de parâmetros passados para o método ou propriedade. Lista de argumentos variável é representada por **...**  na declaração de sintaxe.  
  
 Os valores possíveis para a `vtRet` argumento são tiradas de `VARENUM` enumeração. Os valores possíveis são:  
  
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
  
 O `pbParamInfo` argumento é uma lista separada por espaços de **VTS_** constantes. Um ou mais desses valores, separados por espaços (não vírgulas), especifica a lista de parâmetros da função. Os valores possíveis são listados com o [EVENT_CUSTOM](event-maps.md#event_custom) macro.  
  
 Esta função converte os parâmetros a serem **VARIANTARG** valores e, em seguida, invoca o [IDispatch:: Invoke](http://msdn.microsoft.com/library/windows/desktop/ms221479\(v=vs.85\).aspx) método. Se a chamada para `Invoke` falhar, esta função lançará uma exceção. Se o `SCODE` (código de status) retornado por **IDispatch:: Invoke** é `DISP_E_EXCEPTION`, essa função lança um [COleException](../../mfc/reference/coleexception-class.md) objeto; caso contrário, ele lança uma [ COleDispatchException](../../mfc/reference/coledispatchexception-class.md).  
  
 Para obter mais informações, consulte [VARIANTARG](http://msdn.microsoft.com/en-us/e305240e-9e11-4006-98cc-26f4932d2118), [Implementando a IDispatch Interface](http://msdn.microsoft.com/library/windows/desktop/ms221037\(v=vs.85\).aspx), [IDispatch:: Invoke](http://msdn.microsoft.com/library/windows/desktop/ms221479\(v=vs.85\).aspx), e [estrutura de códigos de erro COM](http://msdn.microsoft.com/library/windows/desktop/ms690088) no SDK do Windows.  
  
### <a name="example"></a>Exemplo  
  Consulte o exemplo para [COleDispatchDriver::CreateDispatch](#createdispatch).  
  
##  <a name="m_bautorelease"></a>  COleDispatchDriver::m_bAutoRelease  
 Se **TRUE**, o objeto COM acessados por [m_lpDispatch](#m_lpdispatch) será automaticamente liberada quando [ReleaseDispatch](#releasedispatch) é chamado ou quando isso `COleDispatchDriver` objeto destruído.  
  
```  
BOOL m_bAutoRelease;  
```  
  
### <a name="remarks"></a>Comentários  
 Por padrão, `m_bAutoRelease` é definido como **TRUE** no construtor.  
  
 Para obter mais informações sobre como liberar objetos COM, consulte [Implementando a contagem de referência](http://msdn.microsoft.com/library/windows/desktop/ms693431) e [IUnknown](http://msdn.microsoft.com/library/windows/desktop/ms682317) no SDK do Windows.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFCOleContainer#9](../../mfc/codesnippet/cpp/coledispatchdriver-class_5.cpp)]  
  
##  <a name="m_lpdispatch"></a>  COleDispatchDriver::m_lpDispatch  
 O ponteiro para o `IDispatch` interface conectada a este `COleDispatchDriver`.  
  
```  
LPDISPATCH m_lpDispatch;  
```  
  
### <a name="remarks"></a>Comentários  
 O `m_lpDispatch` membro de dados é uma variável pública do tipo `LPDISPATCH`.  
  
 Para obter mais informações, consulte [IDispatch](http://msdn.microsoft.com/en-us/0e171f7f-0022-4e9b-ac8e-98192828e945) no SDK do Windows.  
  
### <a name="example"></a>Exemplo  
  Consulte o exemplo para [COleDispatchDriver::AttachDispatch](#attachdispatch).  
  
##  <a name="operator_eq"></a>  COleDispatchDriver::operator =  
 Copia o valor de origem para o `COleDispatchDriver` objeto.  
  
```  
const COleDispatchDriver& operator=(const COleDispatchDriver& dispatchSrc);
```  
  
### <a name="parameters"></a>Parâmetros  
 `dispatchSrc`  
 Um ponteiro para um existente `COleDispatchDriver` objeto.  
  
##  <a name="operator_lpdispatch"></a>  COleDispatchDriver::operator LPDISPATCH  
 Acessa subjacente `IDispatch` ponteiro o `COleDispatchDriver` objeto.  
  
```  
operator LPDISPATCH();
```   
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFCOleContainer#8](../../mfc/codesnippet/cpp/coledispatchdriver-class_6.cpp)]  
  
##  <a name="releasedispatch"></a>  COleDispatchDriver::ReleaseDispatch  
 Versões de `IDispatch` conexão. Para obter mais informações, consulte [Implementando a IDispatch Interface](http://msdn.microsoft.com/en-us/0e171f7f-0022-4e9b-ac8e-98192828e945)  
  
```  
void ReleaseDispatch();
```  
  
### <a name="remarks"></a>Comentários  
 Se a versão automática tiver sido definido para esta conexão, esta função chama **IDispatch::Release** antes de liberar a interface.  
  
### <a name="example"></a>Exemplo  
  Consulte o exemplo para [COleDispatchDriver::AttachDispatch](#attachdispatch).  
  
##  <a name="setproperty"></a>  COleDispatchDriver::SetProperty  
 Define a propriedade do objeto OLE especificada pelo `dwDispID`.  
  
```  
void AFX_CDECL SetProperty(
    DISPID dwDispID,  
    VARTYPE vtProp, ...);
```  
  
### <a name="parameters"></a>Parâmetros  
 `dwDispID`  
 Identifica a propriedade a ser definida.  
  
 `vtProp`  
 Especifica o tipo da propriedade a ser definido. Para os valores possíveis, consulte a seção comentários para [COleDispatchDriver::InvokeHelper](#invokehelper).  
  
 *...*  
 Um único parâmetro do tipo especificado pelo `vtProp`.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFCOleContainer#7](../../mfc/codesnippet/cpp/coledispatchdriver-class_7.cpp)]  
  
## <a name="see-also"></a>Consulte também  
 [Exemplo MFC CALCDRIV](../../visual-cpp-samples.md)   
 [Exemplo MFC ACDUAL](../../visual-cpp-samples.md)   
 [Gráfico de hierarquia](../../mfc/hierarchy-chart.md)   
 [Classe CCmdTarget](../../mfc/reference/ccmdtarget-class.md)
