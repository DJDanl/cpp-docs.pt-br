---
title: Classe COleDispatchDriver
ms.date: 11/04/2016
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
ms.openlocfilehash: fa88147b57b0506f7f9ab96d4a5d2f43fdd75458
ms.sourcegitcommit: fcb48824f9ca24b1f8bd37d647a4d592de1cc925
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/15/2019
ms.locfileid: "69504177"
---
# <a name="coledispatchdriver-class"></a>Classe COleDispatchDriver

Implementa o lado do cliente da automação OLE.

## <a name="syntax"></a>Sintaxe

```
class COleDispatchDriver
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[COleDispatchDriver::COleDispatchDriver](#coledispatchdriver)|Constrói um objeto `COleDispatchDriver`.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[COleDispatchDriver::AttachDispatch](#attachdispatch)|Anexa uma `IDispatch` conexão `COleDispatchDriver` ao objeto.|
|[COleDispatchDriver::CreateDispatch](#createdispatch)|Cria uma `IDispatch` conexão e a anexa `COleDispatchDriver` ao objeto.|
|[COleDispatchDriver::DetachDispatch](#detachdispatch)|Desanexa uma `IDispatch` conexão, sem liberá-la.|
|[COleDispatchDriver::GetProperty](#getproperty)|Obtém uma propriedade de automação.|
|[COleDispatchDriver::InvokeHelper](#invokehelper)|Auxiliar para chamar métodos de automação.|
|[COleDispatchDriver::ReleaseDispatch](#releasedispatch)|Libera uma `IDispatch` conexão.|
|[COleDispatchDriver::SetProperty](#setproperty)|Define uma propriedade de automação.|

### <a name="public-operators"></a>Operadores públicos

|Nome|Descrição|
|----------|-----------------|
|[COleDispatchDriver:: Operator =](#operator_eq)|Copia o valor de origem no `COleDispatchDriver` objeto.|
|[Operador COleDispatchDriver:: Operator LPDISPATCH](#operator_lpdispatch)|Acessa o ponteiro subjacente `IDispatch` .|

### <a name="public-data-members"></a>Membros de Dados Públicos

|Nome|Descrição|
|----------|-----------------|
|[COleDispatchDriver::m_bAutoRelease](#m_bautorelease)|Especifica se é para liberar `IDispatch` a `ReleaseDispatch` destruição de durante ou de objeto.|
|[COleDispatchDriver::m_lpDispatch](#m_lpdispatch)|Indica o ponteiro para a `IDispatch` interface anexada a `COleDispatchDriver`este.|

## <a name="remarks"></a>Comentários

`COleDispatchDriver`Não tem uma classe base.

As interfaces de expedição OLE fornecem acesso aos métodos e às propriedades de um objeto. Funções de membro `COleDispatchDriver` de anexar, desanexar, criar e liberar uma conexão de expedição `IDispatch`do tipo. Outras funções de membro usam listas de argumentos variáveis para `IDispatch::Invoke`simplificar a chamada.

Essa classe pode ser usada diretamente, mas geralmente é usada somente por classes criadas pelo Assistente para adicionar classe. Quando você cria novas C++ classes importando uma biblioteca de tipos, as novas classes são `COleDispatchDriver`derivadas de.

Para obter mais informações sobre `COleDispatchDriver`como usar o, consulte os seguintes artigos:

- [Clientes de automação](../../mfc/automation-clients.md)

- [Servidores de automação](../../mfc/automation-servers.md)

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`COleDispatchDriver`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** AFXDISP. h

##  <a name="attachdispatch"></a>  COleDispatchDriver::AttachDispatch

Chame a `AttachDispatch` função de membro para anexar `IDispatch` um ponteiro ao `COleDispatchDriver` objeto. Para obter mais informações, consulte [implementando a interface IDispatch](/previous-versions/windows/desktop/automat/implementing-the-idispatch-interface).

```
void AttachDispatch(
    LPDISPATCH lpDispatch,
    BOOL bAutoRelease = TRUE);
```

### <a name="parameters"></a>Parâmetros

*lpDispatch*<br/>
Ponteiro para um objeto `IDispatch` OLE a ser anexado `COleDispatchDriver` ao objeto.

*bAutoRelease*<br/>
Especifica se o despacho deve ser liberado quando esse objeto sair do escopo.

### <a name="remarks"></a>Comentários

Essa função libera qualquer `IDispatch` ponteiro que já esteja anexado `COleDispatchDriver` ao objeto.

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

*lpDispatch*<br/>
Ponteiro para um objeto `IDispatch` OLE a ser anexado `COleDispatchDriver` ao objeto.

*bAutoRelease*<br/>
Especifica se o despacho deve ser liberado quando esse objeto sair do escopo.

*dispatchSrc*<br/>
Referência a um objeto `COleDispatchDriver` existente.

### <a name="remarks"></a>Comentários

O formulário `COleDispatchDriver` (`LPDISPATCH lpDispatch`, **bool**`bAutoRelease` = **true**) conecta a interface [IDispatch](/previous-versions/windows/desktop/automat/implementing-the-idispatch-interface).

O formulário `COleDispatchDriver`( **const**`COleDispatchDriver`&  `COleDispatchDriver` ) copia um objeto existente e incrementa a contagem de referência.`dispatchSrc`

O formulário `COleDispatchDriver`() cria um `COleDispatchDriver` objeto, mas não conecta a `IDispatch` interface. Antes de `COleDispatchDriver`usar () sem argumentos, você deve conectar `IDispatch` um a ele usando [COleDispatchDriver:: createexpedição](#createdispatch) ou [COleDispatchDriver:: AttachDispatch](#attachdispatch). Para obter mais informações, consulte [implementando a interface IDispatch](/previous-versions/windows/desktop/automat/implementing-the-idispatch-interface).

### <a name="example"></a>Exemplo

  Consulte o exemplo de [COleDispatchDriver:: createexpedição](#createdispatch).

##  <a name="createdispatch"></a>  COleDispatchDriver::CreateDispatch

Cria um objeto de interface [IDispatch](/previous-versions/windows/desktop/automat/implementing-the-idispatch-interface) e o `COleDispatchDriver` anexa ao objeto.

```
BOOL CreateDispatch(
    REFCLSID clsid,
    COleException* pError = NULL);

BOOL CreateDispatch(
    LPCTSTR lpszProgID,
    COleException* pError = NULL);
```

### <a name="parameters"></a>Parâmetros

*clsid*<br/>
ID de classe do `IDispatch` objeto de conexão a ser criado.

*pError*<br/>
Ponteiro para um objeto de exceção OLE, que conterá o código de status resultante da criação.

*lpszProgID*<br/>
Ponteiro para o identificador programático, como "Excel. Document. 5", do objeto de automação para o qual o objeto de expedição deve ser criado.

### <a name="return-value"></a>Valor de retorno

Diferente de zero em caso de êxito; caso contrário, 0.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCOleContainer#4](../../mfc/codesnippet/cpp/coledispatchdriver-class_2.cpp)]

##  <a name="detachdispatch"></a>  COleDispatchDriver::DetachDispatch

Desanexa a conexão atual `IDispatch` deste objeto.

```
LPDISPATCH DetachDispatch();
```

### <a name="return-value"></a>Valor de retorno

Um ponteiro para o objeto OLE `IDispatch` anexado anteriormente.

### <a name="remarks"></a>Comentários

O `IDispatch` não é liberado.

Para obter mais informações sobre o tipo LPDISPATCH, consulte [implementando a interface IDispatch](/previous-versions/windows/desktop/automat/implementing-the-idispatch-interface) no SDK do Windows.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCOleContainer#5](../../mfc/codesnippet/cpp/coledispatchdriver-class_3.cpp)]

##  <a name="getproperty"></a>  COleDispatchDriver::GetProperty

Obtém a propriedade de objeto especificada por *dwDispID*.

```
void GetProperty(
    DISPID dwDispID,
    VARTYPE vtProp,
    void* pvProp) const;
```

### <a name="parameters"></a>Parâmetros

*dwDispID*<br/>
Identifica a propriedade a ser recuperada.

*vtProp*<br/>
Especifica a propriedade a ser recuperada. Para obter os valores possíveis, consulte a seção comentários para [COleDispatchDriver:: especificados InvokeHelper](#invokehelper).

*pvProp*<br/>
Endereço da variável que receberá o valor da propriedade. Ele deve corresponder ao tipo especificado por *vtProp*.

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

*dwDispID*<br/>
Identifica o método ou a propriedade a ser invocada.

*wFlags*<br/>
Sinalizadores que descrevem o contexto da chamada para `IDispatch::Invoke`. . Para obter uma lista de valores possíveis, consulte o parâmetro *wFlags* em [IDispatch:: Invoke](/windows/win32/api/oaidl/nf-oaidl-idispatch-invoke) no SDK do Windows.

*vtRet*<br/>
Especifica o tipo do valor de retorno. Para obter os valores possíveis, consulte a seção comentários.

*pvRet*<br/>
Endereço da variável que receberá o valor da propriedade ou o valor de retorno. Ele deve corresponder ao tipo especificado por *vtRet*.

*pbParamInfo*<br/>
Ponteiro para uma cadeia de caracteres de bytes terminada em nulo especificando os tipos dos parâmetros após *pbParamInfo*.

*...*<br/>
Lista variável de parâmetros, dos tipos especificados em *pbParamInfo*.

### <a name="remarks"></a>Comentários

O parâmetro *pbParamInfo* especifica os tipos dos parâmetros passados para o método ou a propriedade. A lista variável de argumentos é representada por **...** na declaração de sintaxe.

Os valores possíveis para o argumento *vtRet* são extraídos da enumeração VarEnum. Os valores possíveis são:

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
|VT_VARIANT|**VARIANTE**|
|VT_UNKNOWN|LPUNKNOWN|

O argumento *pbParamInfo* é uma lista separada por espaços de constantes **VTS_** . Um ou mais desses valores, separados por espaços (não vírgulas), especifica a lista de parâmetros da função. Os valores possíveis são listados com a macro [EVENT_CUSTOM](event-maps.md#event_custom) .

Essa função converte os parâmetros em valores VARIANTARG e, em seguida, invoca o método [IDispatch:: Invoke](/windows/win32/api/oaidl/nf-oaidl-idispatch-invoke) . Se a chamada para `Invoke` falhar, essa função gerará uma exceção. Se o SCODE (código de status) retornado `IDispatch::Invoke` por for DISP_E_EXCEPTION, essa função lançará um objeto [COleException](../../mfc/reference/coleexception-class.md) ; caso contrário, ele lançará um [COleDispatchException](../../mfc/reference/coledispatchexception-class.md).

Para obter mais informações, consulte [VARIANTARG](/windows/win32/api/oaidl/ns-oaidl-variant), [implementando a interface IDispatch](/previous-versions/windows/desktop/automat/implementing-the-idispatch-interface), [IDispatch:: Invoke](/windows/win32/api/oaidl/nf-oaidl-idispatch-invoke)e a [estrutura de códigos de erro com](/windows/win32/com/structure-of-com-error-codes) no SDK do Windows.

### <a name="example"></a>Exemplo

  Consulte o exemplo de [COleDispatchDriver:: createexpedição](#createdispatch).

##  <a name="m_bautorelease"></a>  COleDispatchDriver::m_bAutoRelease

Se for true, o objeto com acessado pelo [m_lpDispatch](#m_lpdispatch) será liberado automaticamente quando [ReleaseDispatch](#releasedispatch) for chamado ou `COleDispatchDriver` quando esse objeto for destruído.

```
BOOL m_bAutoRelease;
```

### <a name="remarks"></a>Comentários

Por padrão, `m_bAutoRelease` é definido como true no construtor.

Para obter mais informações sobre como lançar objetos COM, consulte [implementando a contagem de referência](/windows/win32/com/implementing-reference-counting) e [IUnknown:: Release](/windows/win32/api/unknwn/nf-unknwn-iunknown-release) no SDK do Windows.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCOleContainer#9](../../mfc/codesnippet/cpp/coledispatchdriver-class_5.cpp)]

##  <a name="m_lpdispatch"></a>  COleDispatchDriver::m_lpDispatch

O ponteiro para a `IDispatch` interface anexada a `COleDispatchDriver`isso.

```
LPDISPATCH m_lpDispatch;
```

### <a name="remarks"></a>Comentários

O `m_lpDispatch` membro de dados é uma variável pública do tipo LPDISPATCH.

Para obter mais informações, consulte [IDispatch](/previous-versions/windows/desktop/automat/implementing-the-idispatch-interface) no SDK do Windows.

### <a name="example"></a>Exemplo

  Consulte o exemplo de [COleDispatchDriver:: AttachDispatch](#attachdispatch).

##  <a name="operator_eq"></a>  COleDispatchDriver::operator =

Copia o valor de origem no `COleDispatchDriver` objeto.

```
const COleDispatchDriver& operator=(const COleDispatchDriver& dispatchSrc);
```

### <a name="parameters"></a>Parâmetros

*dispatchSrc*<br/>
Um ponteiro para um objeto `COleDispatchDriver` existente.

##  <a name="operator_lpdispatch"></a>Operador COleDispatchDriver:: Operator LPDISPATCH

Acessa o ponteiro subjacente `IDispatch` `COleDispatchDriver` do objeto.

```
operator LPDISPATCH();
```

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCOleContainer#8](../../mfc/codesnippet/cpp/coledispatchdriver-class_6.cpp)]

##  <a name="releasedispatch"></a>  COleDispatchDriver::ReleaseDispatch

Libera a `IDispatch` conexão. Para obter mais informações, consulte [implementando a interface IDispatch](/previous-versions/windows/desktop/automat/implementing-the-idispatch-interface)

```
void ReleaseDispatch();
```

### <a name="remarks"></a>Comentários

Se a liberação automática tiver sido definida para essa conexão, essa função `IDispatch::Release` chamará antes de liberar a interface.

### <a name="example"></a>Exemplo

  Consulte o exemplo de [COleDispatchDriver:: AttachDispatch](#attachdispatch).

##  <a name="setproperty"></a>  COleDispatchDriver::SetProperty

Define a propriedade de objeto OLE especificada por *dwDispID*.

```
void AFX_CDECL SetProperty(
    DISPID dwDispID,
    VARTYPE vtProp, ...);
```

### <a name="parameters"></a>Parâmetros

*dwDispID*<br/>
Identifica a propriedade a ser definida.

*vtProp*<br/>
Especifica o tipo da propriedade a ser definida. Para obter os valores possíveis, consulte a seção comentários para [COleDispatchDriver:: especificados InvokeHelper](#invokehelper).

*...*<br/>
Um único parâmetro do tipo especificado por *vtProp*.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCOleContainer#7](../../mfc/codesnippet/cpp/coledispatchdriver-class_7.cpp)]

## <a name="see-also"></a>Consulte também

[Exemplo de CALCDRIV do MFC](../../overview/visual-cpp-samples.md)<br/>
[Exemplo de ACDUAL do MFC](../../overview/visual-cpp-samples.md)<br/>
[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classe CCmdTarget](../../mfc/reference/ccmdtarget-class.md)
