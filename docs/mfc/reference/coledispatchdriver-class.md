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
ms.sourcegitcommit: 3e8fa01f323bc5043a48a0c18b855d38af3648d4
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/06/2020
ms.locfileid: "78855428"
---
# <a name="coledispatchdriver-class"></a>Classe COleDispatchDriver

Implementa o lado do cliente da automação OLE.

## <a name="syntax"></a>Sintaxe

```
class COleDispatchDriver
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|DESCRIÇÃO|
|----------|-----------------|
|[COleDispatchDriver:: COleDispatchDriver](#coledispatchdriver)|Constrói um objeto `COleDispatchDriver`.|

### <a name="public-methods"></a>Métodos públicos

|Nome|DESCRIÇÃO|
|----------|-----------------|
|[COleDispatchDriver:: AttachDispatch](#attachdispatch)|Anexa uma conexão `IDispatch` ao objeto `COleDispatchDriver`.|
|[COleDispatchDriver:: createexpedição](#createdispatch)|Cria uma conexão `IDispatch` e a anexa ao objeto `COleDispatchDriver`.|
|[COleDispatchDriver::D etachDispatch](#detachdispatch)|Desanexa uma conexão `IDispatch`, sem liberá-la.|
|[COleDispatchDriver:: GetProperty](#getproperty)|Obtém uma propriedade de automação.|
|[COleDispatchDriver:: especificados InvokeHelper](#invokehelper)|Auxiliar para chamar métodos de automação.|
|[COleDispatchDriver:: ReleaseDispatch](#releasedispatch)|Libera uma conexão `IDispatch`.|
|[COleDispatchDriver:: SetProperty](#setproperty)|Define uma propriedade de automação.|

### <a name="public-operators"></a>Operadores públicos

|Nome|DESCRIÇÃO|
|----------|-----------------|
|[COleDispatchDriver:: Operator =](#operator_eq)|Copia o valor de origem no objeto `COleDispatchDriver`.|
|[Operador COleDispatchDriver:: Operator LPDISPATCH](#operator_lpdispatch)|Acessa o ponteiro de `IDispatch` subjacente.|

### <a name="public-data-members"></a>Membros de Dados Públicos

|Nome|DESCRIÇÃO|
|----------|-----------------|
|[COleDispatchDriver:: m_bAutoRelease](#m_bautorelease)|Especifica se a `IDispatch` deve ser liberada durante a destruição de `ReleaseDispatch` ou objeto.|
|[COleDispatchDriver:: m_lpDispatch](#m_lpdispatch)|Indica o ponteiro para a interface de `IDispatch` anexada a este `COleDispatchDriver`.|

## <a name="remarks"></a>Comentários

`COleDispatchDriver` não tem uma classe base.

As interfaces de expedição OLE fornecem acesso aos métodos e às propriedades de um objeto. As funções de membro de `COleDispatchDriver` anexar, desanexar, criar e liberar uma conexão de expedição do tipo `IDispatch`. Outras funções de membro usam listas de argumentos variáveis para simplificar a chamada `IDispatch::Invoke`.

Essa classe pode ser usada diretamente, mas geralmente é usada somente por classes criadas pelo Assistente para adicionar classe. Quando você cria novas C++ classes importando uma biblioteca de tipos, as novas classes são derivadas de `COleDispatchDriver`.

Para obter mais informações sobre como usar `COleDispatchDriver`, consulte os seguintes artigos:

- [Clientes de automação](../../mfc/automation-clients.md)

- [Servidores de automação](../../mfc/automation-servers.md)

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`COleDispatchDriver`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** AFXDISP. h

##  <a name="attachdispatch"></a>COleDispatchDriver:: AttachDispatch

Chame a função de membro `AttachDispatch` para anexar um ponteiro de `IDispatch` ao objeto `COleDispatchDriver`. Para obter mais informações, consulte [implementando a interface IDispatch](/previous-versions/windows/desktop/automat/implementing-the-idispatch-interface).

```
void AttachDispatch(
    LPDISPATCH lpDispatch,
    BOOL bAutoRelease = TRUE);
```

### <a name="parameters"></a>parâmetros

*lpDispatch*<br/>
Ponteiro para um objeto OLE `IDispatch` a ser anexado ao objeto `COleDispatchDriver`.

*bAutoRelease*<br/>
Especifica se o despacho deve ser liberado quando esse objeto sair do escopo.

### <a name="remarks"></a>Comentários

Essa função libera qualquer ponteiro de `IDispatch` que já esteja anexado ao objeto `COleDispatchDriver`.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCOleContainer#3](../../mfc/codesnippet/cpp/coledispatchdriver-class_1.cpp)]

##  <a name="coledispatchdriver"></a>COleDispatchDriver:: COleDispatchDriver

Constrói um objeto `COleDispatchDriver`.

```
COleDispatchDriver();
COleDispatchDriver(LPDISPATCH lpDispatch, BOOL bAutoRelease = TRUE);
COleDispatchDriver(const COleDispatchDriver& dispatchSrc);
```

### <a name="parameters"></a>parâmetros

*lpDispatch*<br/>
Ponteiro para um objeto OLE `IDispatch` a ser anexado ao objeto `COleDispatchDriver`.

*bAutoRelease*<br/>
Especifica se o despacho deve ser liberado quando esse objeto sair do escopo.

*dispatchSrc*<br/>
Referência a um objeto de `COleDispatchDriver` existente.

### <a name="remarks"></a>Comentários

O formulário `COleDispatchDriver`(`LPDISPATCH lpDispatch`, **BOOL**`bAutoRelease` = **true**) conecta a interface [IDispatch](/previous-versions/windows/desktop/automat/implementing-the-idispatch-interface) .

O formulário `COleDispatchDriver`( **const**`COleDispatchDriver`& `dispatchSrc`) copia um objeto de `COleDispatchDriver` existente e incrementa a contagem de referência.

O formulário `COleDispatchDriver`() cria um objeto `COleDispatchDriver`, mas não conecta a interface `IDispatch`. Antes de usar o `COleDispatchDriver`() sem argumentos, você deve conectar um `IDispatch` a ele usando [COleDispatchDriver:: createexpedição](#createdispatch) ou [COleDispatchDriver:: AttachDispatch](#attachdispatch). Para obter mais informações, consulte [implementando a interface IDispatch](/previous-versions/windows/desktop/automat/implementing-the-idispatch-interface).

### <a name="example"></a>Exemplo

  Consulte o exemplo de [COleDispatchDriver:: createexpedição](#createdispatch).

##  <a name="createdispatch"></a>COleDispatchDriver:: createexpedição

Cria um objeto de interface [IDispatch](/previous-versions/windows/desktop/automat/implementing-the-idispatch-interface) e o anexa ao objeto `COleDispatchDriver`.

```
BOOL CreateDispatch(
    REFCLSID clsid,
    COleException* pError = NULL);

BOOL CreateDispatch(
    LPCTSTR lpszProgID,
    COleException* pError = NULL);
```

### <a name="parameters"></a>parâmetros

*CLSID*<br/>
ID de classe do objeto de conexão `IDispatch` a ser criado.

*pError*<br/>
Ponteiro para um objeto de exceção OLE, que conterá o código de status resultante da criação.

*lpszProgID*<br/>
Ponteiro para o identificador programático, como "Excel. Document. 5", do objeto de automação para o qual o objeto de expedição deve ser criado.

### <a name="return-value"></a>Valor retornado

Diferente de zero em caso de êxito; caso contrário, 0.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCOleContainer#4](../../mfc/codesnippet/cpp/coledispatchdriver-class_2.cpp)]

##  <a name="detachdispatch"></a>COleDispatchDriver::D etachDispatch

Desanexa a conexão de `IDispatch` atual deste objeto.

```
LPDISPATCH DetachDispatch();
```

### <a name="return-value"></a>Valor retornado

Um ponteiro para o objeto OLE `IDispatch` anexado anteriormente.

### <a name="remarks"></a>Comentários

O `IDispatch` não é liberado.

Para obter mais informações sobre o tipo LPDISPATCH, consulte [implementando a interface IDispatch](/previous-versions/windows/desktop/automat/implementing-the-idispatch-interface) no SDK do Windows.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCOleContainer#5](../../mfc/codesnippet/cpp/coledispatchdriver-class_3.cpp)]

##  <a name="getproperty"></a>COleDispatchDriver:: GetProperty

Obtém a propriedade de objeto especificada por *dwDispID*.

```
void GetProperty(
    DISPID dwDispID,
    VARTYPE vtProp,
    void* pvProp) const;
```

### <a name="parameters"></a>parâmetros

*dwDispID*<br/>
Identifica a propriedade a ser recuperada.

*vtProp*<br/>
Especifica a propriedade a ser recuperada. Para obter os valores possíveis, consulte a seção comentários para [COleDispatchDriver:: especificados InvokeHelper](#invokehelper).

*pvProp*<br/>
Endereço da variável que receberá o valor da propriedade. Ele deve corresponder ao tipo especificado por *vtProp*.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCOleContainer#6](../../mfc/codesnippet/cpp/coledispatchdriver-class_4.cpp)]

##  <a name="invokehelper"></a>COleDispatchDriver:: especificados InvokeHelper

Chama o método de objeto ou a propriedade especificada por *dwDispID*, no contexto especificado por *wFlags*.

```
void AFX_CDECL InvokeHelper(
    DISPID dwDispID,
    WORD wFlags,
    VARTYPE vtRet,
    void* pvRet,
    const BYTE* pbParamInfo, ...);
```

### <a name="parameters"></a>parâmetros

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

O argumento *pbParamInfo* é uma lista separada por espaços de constantes de **VTS_** . Um ou mais desses valores, separados por espaços (não vírgulas), especifica a lista de parâmetros da função. Os valores possíveis são listados com a macro [EVENT_CUSTOM](event-maps.md#event_custom) .

Essa função converte os parâmetros em valores VARIANTARG e, em seguida, invoca o método [IDispatch:: Invoke](/windows/win32/api/oaidl/nf-oaidl-idispatch-invoke) . Se a chamada para `Invoke` falhar, essa função gerará uma exceção. Se o SCODE (código de status) retornado por `IDispatch::Invoke` for DISP_E_EXCEPTION, essa função lançará um objeto [COleException](../../mfc/reference/coleexception-class.md) ; caso contrário, ele lançará um [COleDispatchException](../../mfc/reference/coledispatchexception-class.md).

Para obter mais informações, consulte [VARIANTARG](/windows/win32/api/oaidl/ns-oaidl-variant), [implementando a interface IDispatch](/previous-versions/windows/desktop/automat/implementing-the-idispatch-interface), [IDispatch:: Invoke](/windows/win32/api/oaidl/nf-oaidl-idispatch-invoke)e a [estrutura de códigos de erro com](/windows/win32/com/structure-of-com-error-codes) no SDK do Windows.

### <a name="example"></a>Exemplo

  Consulte o exemplo de [COleDispatchDriver:: createexpedição](#createdispatch).

##  <a name="m_bautorelease"></a>COleDispatchDriver:: m_bAutoRelease

Se for TRUE, o objeto COM acessado pelo [m_lpDispatch](#m_lpdispatch) será liberado automaticamente quando [ReleaseDispatch](#releasedispatch) for chamado ou quando esse objeto `COleDispatchDriver` for destruído.

```
BOOL m_bAutoRelease;
```

### <a name="remarks"></a>Comentários

Por padrão, `m_bAutoRelease` é definido como TRUE no construtor.

Para obter mais informações sobre como lançar objetos COM, consulte [implementando a contagem de referência](/windows/win32/com/implementing-reference-counting) e [IUnknown:: Release](/windows/win32/api/unknwn/nf-unknwn-iunknown-release) no SDK do Windows.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCOleContainer#9](../../mfc/codesnippet/cpp/coledispatchdriver-class_5.cpp)]

##  <a name="m_lpdispatch"></a>COleDispatchDriver:: m_lpDispatch

O ponteiro para a interface de `IDispatch` anexada a este `COleDispatchDriver`.

```
LPDISPATCH m_lpDispatch;
```

### <a name="remarks"></a>Comentários

O membro de dados `m_lpDispatch` é uma variável pública do tipo LPDISPATCH.

Para obter mais informações, consulte [IDispatch](/previous-versions/windows/desktop/automat/implementing-the-idispatch-interface) no SDK do Windows.

### <a name="example"></a>Exemplo

  Consulte o exemplo de [COleDispatchDriver:: AttachDispatch](#attachdispatch).

##  <a name="operator_eq"></a>COleDispatchDriver:: Operator =

Copia o valor de origem no objeto `COleDispatchDriver`.

```
const COleDispatchDriver& operator=(const COleDispatchDriver& dispatchSrc);
```

### <a name="parameters"></a>parâmetros

*dispatchSrc*<br/>
Um ponteiro para um objeto de `COleDispatchDriver` existente.

##  <a name="operator_lpdispatch"></a>Operador COleDispatchDriver:: Operator LPDISPATCH

Acessa o ponteiro de `IDispatch` subjacente do objeto `COleDispatchDriver`.

```
operator LPDISPATCH();
```

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCOleContainer#8](../../mfc/codesnippet/cpp/coledispatchdriver-class_6.cpp)]

##  <a name="releasedispatch"></a>COleDispatchDriver:: ReleaseDispatch

Libera a conexão `IDispatch`. Para obter mais informações, consulte [implementando a interface IDispatch](/previous-versions/windows/desktop/automat/implementing-the-idispatch-interface)

```
void ReleaseDispatch();
```

### <a name="remarks"></a>Comentários

Se a liberação automática tiver sido definida para essa conexão, essa função chamará `IDispatch::Release` antes de liberar a interface.

### <a name="example"></a>Exemplo

  Consulte o exemplo de [COleDispatchDriver:: AttachDispatch](#attachdispatch).

##  <a name="setproperty"></a>COleDispatchDriver:: SetProperty

Define a propriedade de objeto OLE especificada por *dwDispID*.

```
void AFX_CDECL SetProperty(
    DISPID dwDispID,
    VARTYPE vtProp, ...);
```

### <a name="parameters"></a>parâmetros

*dwDispID*<br/>
Identifica a propriedade a ser definida.

*vtProp*<br/>
Especifica o tipo da propriedade a ser definida. Para obter os valores possíveis, consulte a seção comentários para [COleDispatchDriver:: especificados InvokeHelper](#invokehelper).

*...*<br/>
Um único parâmetro do tipo especificado por *vtProp*.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCOleContainer#7](../../mfc/codesnippet/cpp/coledispatchdriver-class_7.cpp)]

## <a name="see-also"></a>Confira também

[Exemplo de CALCDRIV do MFC](../../overview/visual-cpp-samples.md)<br/>
[Exemplo de ACDUAL do MFC](../../overview/visual-cpp-samples.md)<br/>
[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classe CCmdTarget](../../mfc/reference/ccmdtarget-class.md)
