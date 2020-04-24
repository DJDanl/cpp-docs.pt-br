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
ms.openlocfilehash: 2b52ed3137a9a515278e018d69751aedaddb0cf1
ms.sourcegitcommit: 7a6116e48c3c11b97371b8ae4ecc23adce1f092d
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/22/2020
ms.locfileid: "81753887"
---
# <a name="coledispatchdriver-class"></a>Classe COleDispatchDriver

Implementa o lado cliente da automação OLE.

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
|[COleDispatchDriver::CreateDispatch](#createdispatch)|Cria `IDispatch` uma conexão e `COleDispatchDriver` a prende ao objeto.|
|[COleDispatchDriver::DetachDispatch](#detachdispatch)|Destaca uma `IDispatch` conexão, sem liberá-la.|
|[COleDispatchDriver::GetProperty](#getproperty)|Consegue uma propriedade de automação.|
|[COleDispatchDriver::InvokeHelper](#invokehelper)|Auxiliar para chamar métodos de automação.|
|[COleDispatchDriver::Despacho de lançamento](#releasedispatch)|Libera uma `IDispatch` conexão.|
|[COleDispatchDriver::SetProperty](#setproperty)|Define uma propriedade de automação.|

### <a name="public-operators"></a>Operadores públicos

|Nome|Descrição|
|----------|-----------------|
|[COleDispatchDriver::operador =](#operator_eq)|Copia o valor `COleDispatchDriver` de origem no objeto.|
|[COleDispatchDriver::operador LPDISPATCH](#operator_lpdispatch)|Acessa o `IDispatch` ponteiro subjacente.|

### <a name="public-data-members"></a>Membros de Dados Públicos

|Nome|Descrição|
|----------|-----------------|
|[COleDispatchDriver::m_bAutoRelease](#m_bautorelease)|Especifica se deve `IDispatch` liberar `ReleaseDispatch` a destruição durante ou objeto.|
|[COleDispatchDriver::m_lpDispatch](#m_lpdispatch)|Indica o ponteiro `IDispatch` para a `COleDispatchDriver`interface anexada a isso .|

## <a name="remarks"></a>Comentários

`COleDispatchDriver`não tem uma classe base.

As interfaces de despacho OLE fornecem acesso aos métodos e propriedades de um objeto. Funções do `COleDispatchDriver` membro de anexar, desprender, criar `IDispatch`e liberar uma conexão de despacho do tipo . Outras funções de membros usam `IDispatch::Invoke`listas de argumentos variáveis para simplificar a chamada .

Esta classe pode ser usada diretamente, mas geralmente é usada apenas por classes criadas pelo assistente Adicionar classe. Quando você cria novas classes C++ importando uma biblioteca de `COleDispatchDriver`tipos, as novas classes são derivadas de .

Para obter mais `COleDispatchDriver`informações sobre como usar, consulte os seguintes artigos:

- [Clientes de automação](../../mfc/automation-clients.md)

- [Servidores de automação](../../mfc/automation-servers.md)

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`COleDispatchDriver`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxdisp.h

## <a name="coledispatchdriverattachdispatch"></a><a name="attachdispatch"></a>COleDispatchDriver::AttachDispatch

Ligue `AttachDispatch` para a função `IDispatch` membro `COleDispatchDriver` para anexar um ponteiro ao objeto. Para obter mais informações, consulte [Implementando a interface iDispatch](/previous-versions/windows/desktop/automat/implementing-the-idispatch-interface).

```cpp
void AttachDispatch(
    LPDISPATCH lpDispatch,
    BOOL bAutoRelease = TRUE);
```

### <a name="parameters"></a>Parâmetros

*LpDispatch*<br/>
Ponteiro para um `IDispatch` objeto OLE a `COleDispatchDriver` ser anexado ao objeto.

*bVersão automática*<br/>
Especifica se o despacho deve ser liberado quando este objeto sair do escopo.

### <a name="remarks"></a>Comentários

Esta função libera `IDispatch` qualquer ponteiro que já `COleDispatchDriver` esteja conectado ao objeto.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCOleContainer#3](../../mfc/codesnippet/cpp/coledispatchdriver-class_1.cpp)]

## <a name="coledispatchdrivercoledispatchdriver"></a><a name="coledispatchdriver"></a>COleDispatchDriver::COleDispatchDriver

Constrói um objeto `COleDispatchDriver`.

```
COleDispatchDriver();
COleDispatchDriver(LPDISPATCH lpDispatch, BOOL bAutoRelease = TRUE);
COleDispatchDriver(const COleDispatchDriver& dispatchSrc);
```

### <a name="parameters"></a>Parâmetros

*LpDispatch*<br/>
Ponteiro para um `IDispatch` objeto OLE a `COleDispatchDriver` ser anexado ao objeto.

*bVersão automática*<br/>
Especifica se o despacho deve ser liberado quando este objeto sair do escopo.

*despachoSrc*<br/>
Referência a um `COleDispatchDriver` objeto existente.

### <a name="remarks"></a>Comentários

O `COleDispatchDriver`formulário `LPDISPATCH lpDispatch`( , **BOOL**`bAutoRelease` = **TRUE**) conecta a interface [IDispatch.](/previous-versions/windows/desktop/automat/implementing-the-idispatch-interface)

O `COleDispatchDriver`formulário **(const**`COleDispatchDriver`& `dispatchSrc`) `COleDispatchDriver` copia um objeto existente e incrementa a contagem de referência.

O `COleDispatchDriver`formulário ( `COleDispatchDriver` ) cria um `IDispatch` objeto, mas não conecta a interface. Antes `COleDispatchDriver`de usar ( ) sem `IDispatch` argumentos, você deve conectá-lo a ele usando [cOleDispatchDriver::CreateDispatch](#createdispatch) ou [COleDispatchDriver::AttachDispatch](#attachdispatch). Para obter mais informações, consulte [Implementando a interface iDispatch](/previous-versions/windows/desktop/automat/implementing-the-idispatch-interface).

### <a name="example"></a>Exemplo

  Veja o exemplo de [COleDispatchDriver::CreateDispatch](#createdispatch).

## <a name="coledispatchdrivercreatedispatch"></a><a name="createdispatch"></a>COleDispatchDriver::CreateDispatch

Cria um objeto de interface [iDispatch](/previous-versions/windows/desktop/automat/implementing-the-idispatch-interface) e o anexa ao `COleDispatchDriver` objeto.

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
ID de `IDispatch` classe do objeto de conexão a ser criado.

*pError*<br/>
Ponteiro para um objeto de exceção OLE, que manterá o código de status resultante da criação.

*lpszProgID*<br/>
Ponteiro para o identificador programático, como "Excel.Document.5", do objeto de automação para o qual o objeto de expedição deve ser criado.

### <a name="return-value"></a>Valor retornado

Não zero no sucesso; caso contrário, 0.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCOleContainer#4](../../mfc/codesnippet/cpp/coledispatchdriver-class_2.cpp)]

## <a name="coledispatchdriverdetachdispatch"></a><a name="detachdispatch"></a>COleDispatchDriver::DetachDispatch

Destaca a conexão atual `IDispatch` deste objeto.

```
LPDISPATCH DetachDispatch();
```

### <a name="return-value"></a>Valor retornado

Um ponteiro para o objeto `IDispatch` OLE anteriormente anexado.

### <a name="remarks"></a>Comentários

O `IDispatch` não foi liberado.

Para obter mais informações sobre o tipo LPDISPATCH, consulte [Implementando a interface IDispatch](/previous-versions/windows/desktop/automat/implementing-the-idispatch-interface) no Windows SDK.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCOleContainer#5](../../mfc/codesnippet/cpp/coledispatchdriver-class_3.cpp)]

## <a name="coledispatchdrivergetproperty"></a><a name="getproperty"></a>COleDispatchDriver::GetProperty

Obtém a propriedade do objeto especificada por *dwDispID*.

```cpp
void GetProperty(
    DISPID dwDispID,
    VARTYPE vtProp,
    void* pvProp) const;
```

### <a name="parameters"></a>Parâmetros

*Dwdispid*<br/>
Identifica a propriedade a ser recuperada.

*Vtprop*<br/>
Especifica a propriedade a ser recuperada. Para obter valores possíveis, consulte a seção Observações de [COleDispatchDriver::InvokeHelper](#invokehelper).

*Pvprop*<br/>
Endereço da variável que receberá o valor da propriedade. Deve corresponder ao tipo especificado por *vtProp*.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCOleContainer#6](../../mfc/codesnippet/cpp/coledispatchdriver-class_4.cpp)]

## <a name="coledispatchdriverinvokehelper"></a><a name="invokehelper"></a>COleDispatchDriver::InvokeHelper

Chama o método ou propriedade do objeto especificado por *dwDispID,* no contexto especificado por *wFlags*.

```cpp
void AFX_CDECL InvokeHelper(
    DISPID dwDispID,
    WORD wFlags,
    VARTYPE vtRet,
    void* pvRet,
    const BYTE* pbParamInfo, ...);
```

### <a name="parameters"></a>Parâmetros

*Dwdispid*<br/>
Identifica o método ou propriedade a ser invocado.

*Wflags*<br/>
Bandeiras descrevendo o contexto `IDispatch::Invoke`da chamada para . . Para obter uma lista de valores possíveis, consulte o parâmetro *wFlags* em [IDispatch::Invocar](/windows/win32/api/oaidl/nf-oaidl-idispatch-invoke) no Windows SDK.

*vtRet*<br/>
Especifica o tipo do valor de retorno. Para obter valores possíveis, consulte a seção Observações.

*pvRet*<br/>
Endereço da variável que receberá o valor do imóvel ou o valor de retorno. Deve corresponder ao tipo especificado por *vtRet*.

*Pbparaminfo*<br/>
Ponteiro para uma seqüência de bytes com término nulo especificando os tipos dos parâmetros após *pbParamInfo*.

*...*<br/>
Lista variável de parâmetros, de tipos especificados no *pbParamInfo*.

### <a name="remarks"></a>Comentários

O parâmetro *pbParamInfo* especifica os tipos dos parâmetros passados para o método ou propriedade. A lista variável de argumentos é representada **por...** na declaração de sintaxe.

Os valores possíveis para o argumento *vtRet* são retirados da enumeração VARENUM. Os valores possíveis são:

|Símbolo|Tipo de retorno|
|------------|-----------------|
|VT_EMPTY|**void**|
|VT_I2|**Curto**|
|VT_I4|**long**|
|VT_R4|**float**|
|VT_R8|**double**|
|VT_CY|**CY**|
|VT_DATE|**Data**|
|VT_BSTR|BSTR|
|VT_DISPATCH|LPDISPATCH|
|VT_ERROR|SCODE|
|VT_BOOL|**Bool**|
|VT_VARIANT|**Variante**|
|VT_UNKNOWN|Lpunknown|

O *argumento pbParamInfo* é uma lista separada pelo espaço de **VTS_** constantes. Um ou mais desses valores, separados por espaços (não commas), especifica a lista de parâmetros da função. Os valores possíveis são listados com a [EVENT_CUSTOM](event-maps.md#event_custom) macro.

Esta função converte os parâmetros em valores VARIANTARG e, em seguida, invoca o método [IDispatch::Invoke.](/windows/win32/api/oaidl/nf-oaidl-idispatch-invoke) Se a `Invoke` chamada falhar, esta função abrirá uma exceção. Se o SCODE (código de `IDispatch::Invoke` status) retornado for DISP_E_EXCEPTION, essa função lançará um objeto [COleException;](../../mfc/reference/coleexception-class.md) caso contrário, ele lança um [COleDispatchException](../../mfc/reference/coledispatchexception-class.md).

Para obter mais informações, consulte [VARIANTARG](/windows/win32/api/oaidl/ns-oaidl-variant), [Implementando a Interface iDispatch](/previous-versions/windows/desktop/automat/implementing-the-idispatch-interface), [IDispatch::Invoke](/windows/win32/api/oaidl/nf-oaidl-idispatch-invoke)e [Estrutura de Códigos de Erro COM](/windows/win32/com/structure-of-com-error-codes) no Windows SDK.

### <a name="example"></a>Exemplo

  Veja o exemplo de [COleDispatchDriver::CreateDispatch](#createdispatch).

## <a name="coledispatchdriverm_bautorelease"></a><a name="m_bautorelease"></a>COleDispatchDriver::m_bAutoRelease

Se TRUE, o objeto COM acessado por [m_lpDispatch](#m_lpdispatch) será automaticamente liberado `COleDispatchDriver` quando o [ReleaseDispatch](#releasedispatch) for chamado ou quando este objeto for destruído.

```
BOOL m_bAutoRelease;
```

### <a name="remarks"></a>Comentários

Por padrão, `m_bAutoRelease` é definido como TRUE no construtor.

Para obter mais informações sobre a liberação de objetos COM, consulte [Implementando contagem de referências](/windows/win32/com/implementing-reference-counting) e [IUnknown::Lançamento](/windows/win32/api/unknwn/nf-unknwn-iunknown-release) no SDK do Windows.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCOleContainer#9](../../mfc/codesnippet/cpp/coledispatchdriver-class_5.cpp)]

## <a name="coledispatchdriverm_lpdispatch"></a><a name="m_lpdispatch"></a>COleDispatchDriver::m_lpDispatch

O ponteiro `IDispatch` para a interface `COleDispatchDriver`anexada a isso .

```
LPDISPATCH m_lpDispatch;
```

### <a name="remarks"></a>Comentários

O `m_lpDispatch` membro de dados é uma variável pública do tipo LPDISPATCH.

Para obter mais informações, consulte [IDispatch](/previous-versions/windows/desktop/automat/implementing-the-idispatch-interface) no Windows SDK.

### <a name="example"></a>Exemplo

  Veja o exemplo de [COleDispatchDriver::AttachDispatch](#attachdispatch).

## <a name="coledispatchdriveroperator-"></a><a name="operator_eq"></a>COleDispatchDriver::operador =

Copia o valor `COleDispatchDriver` de origem no objeto.

```
const COleDispatchDriver& operator=(const COleDispatchDriver& dispatchSrc);
```

### <a name="parameters"></a>Parâmetros

*despachoSrc*<br/>
Um ponteiro para `COleDispatchDriver` um objeto existente.

## <a name="coledispatchdriveroperator-lpdispatch"></a><a name="operator_lpdispatch"></a>COleDispatchDriver::operador LPDISPATCH

Acessa o `IDispatch` ponteiro `COleDispatchDriver` subjacente do objeto.

```
operator LPDISPATCH();
```

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCOleContainer#8](../../mfc/codesnippet/cpp/coledispatchdriver-class_6.cpp)]

## <a name="coledispatchdriverreleasedispatch"></a><a name="releasedispatch"></a>COleDispatchDriver::Despacho de lançamento

Libera a `IDispatch` conexão. Para obter mais informações, consulte [Implementando a interface iDispatch](/previous-versions/windows/desktop/automat/implementing-the-idispatch-interface)

```cpp
void ReleaseDispatch();
```

### <a name="remarks"></a>Comentários

Se a versão automática tiver sido definida `IDispatch::Release` para esta conexão, esta função será chamada antes de liberar a interface.

### <a name="example"></a>Exemplo

  Veja o exemplo de [COleDispatchDriver::AttachDispatch](#attachdispatch).

## <a name="coledispatchdriversetproperty"></a><a name="setproperty"></a>COleDispatchDriver::SetProperty

Define a propriedade do objeto OLE especificada por *dwDispID*.

```cpp
void AFX_CDECL SetProperty(
    DISPID dwDispID,
    VARTYPE vtProp, ...);
```

### <a name="parameters"></a>Parâmetros

*Dwdispid*<br/>
Identifica a propriedade a ser definida.

*Vtprop*<br/>
Especifica o tipo de propriedade a ser definida. Para obter valores possíveis, consulte a seção Observações de [COleDispatchDriver::InvokeHelper](#invokehelper).

*...*<br/>
Um único parâmetro do tipo especificado por *vtProp*.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCOleContainer#7](../../mfc/codesnippet/cpp/coledispatchdriver-class_7.cpp)]

## <a name="see-also"></a>Confira também

[Amostra de MFC CALCDRIV](../../overview/visual-cpp-samples.md)<br/>
[MFC Amostra ACDUAL](../../overview/visual-cpp-samples.md)<br/>
[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classe CCmdTarget](../../mfc/reference/ccmdtarget-class.md)
