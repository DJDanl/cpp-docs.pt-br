---
title: Mapas de expedição
ms.date: 06/20/2018
helpviewer_keywords:
- dispatch maps [MFC], macros
- dispatch maps [MFC]
- dispatch map macros [MFC]
ms.assetid: bef9d08b-ad35-4c3a-99d8-04150c7c04e2
ms.openlocfilehash: 59dd8c7a7b0b930ffdb68fd96410fd73aeb02e81
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81365750"
---
# <a name="dispatch-maps"></a>Mapas de expedição

A OLE Automation fornece maneiras de chamar métodos e acessar propriedades entre aplicativos. O mecanismo fornecido pela Microsoft Foundation Class Library para despachar essas solicitações é o "mapa de despacho", que designa os nomes internos e externos das funções e propriedades dos objetos, bem como os tipos de dados das próprias propriedades e dos argumentos de função.

|Macro do mapa de despacho|Descrição|
|-|-|
|[DECLARE_DISPATCH_MAP](#declare_dispatch_map)|Declara que um mapa de despacho será usado para expor os métodos e propriedades de uma classe (deve ser usado na declaração de classe).|
|[BEGIN_DISPATCH_MAP](#begin_dispatch_map)|Inicia a definição de um mapa de despacho.|
|[END_DISPATCH_MAP](#end_dispatch_map)|Termina a definição de um mapa de despacho.|
|[DISP_FUNCTION](#disp_function)|Usado em um mapa de despacho para definir uma função de automação OLE.|
|[DISP_PROPERTY](#disp_property)|Define uma propriedade de automação OLE.|
|[DISP_PROPERTY_EX](#disp_property_ex)|Define uma propriedade de automação OLE e nomeia as funções Get and Set.|
|[DISP_PROPERTY_NOTIFY](#disp_property_notify)|Define uma propriedade de automação OLE com notificação.|
|[DISP_PROPERTY_PARAM](#disp_property_param)|Define uma propriedade de automação OLE que leva parâmetros e nomeia as funções Get and Set.|
|[DISP_DEFVALUE](#disp_defvalue)|Faz de uma propriedade existente o valor padrão de um objeto.|

## <a name="declare_dispatch_map"></a><a name="declare_dispatch_map"></a>DECLARE_DISPATCH_MAP

Se `CCmdTarget`uma classe derivada em seu programa suportar a Automação OLE, essa classe deve fornecer um mapa de expedição para expor seus métodos e propriedades.

```cpp
DECLARE_DISPATCH_MAP()
```

### <a name="remarks"></a>Comentários

Use a DECLARE_DISPATCH_MAP macro no final da declaração da sua classe. Então, no. Arquivo CPP que define as funções do membro para a classe, use a BEGIN_DISPATCH_MAP macro. Em seguida, inclua entradas de macro para cada um dos métodos e propriedades expostos de sua classe (DISP_FUNCTION, DISP_PROPERTY e assim por diante). Por fim, use o macro END_DISPATCH_MAP.

> [!NOTE]
> Se você declarar quaisquer membros após DECLARE_DISPATCH_MAP, você deve especificar um novo tipo de acesso **(público,** **privado**ou **protegido)** para eles.

O Assistente de Aplicativos e os assistentes de código auxiliam na criação de classes de automação e na manutenção de mapas de expedição. Para obter mais informações sobre mapas de despacho, consulte [Servidores de automação](../../mfc/automation-servers.md).

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCAutomation#10](../../mfc/codesnippet/cpp/dispatch-maps_1.h)]

### <a name="requirements"></a>Requisitos

**Cabeçalho:** afxwin.h

## <a name="begin_dispatch_map"></a><a name="begin_dispatch_map"></a>Begin_dispatch_map

Declara a definição do seu mapa de despacho.

```cpp
BEGIN_DISPATCH_MAP(theClass, baseClass)
```

### <a name="parameters"></a>Parâmetros

*Theclass*<br/>
Especifica o nome da classe que possui este mapa de despacho.

*Baseclass*<br/>
Especifica o nome da classe base *doClass*.

### <a name="remarks"></a>Comentários

No arquivo de implementação (.cpp) que define as funções do membro para sua classe, inicie o mapa de despacho com a BEGIN_DISPATCH_MAP macro, adicione entradas de macro para cada uma de suas funções e propriedades de expedição e complete o mapa de despacho com a macro END_DISPATCH_MAP.

### <a name="requirements"></a>Requisitos

**Cabeçalho:** afxdisp.h

## <a name="end_dispatch_map"></a><a name="end_dispatch_map"></a>END_DISPATCH_MAP

Termina a definição do seu mapa de despacho.

```cpp
END_DISPATCH_MAP()
```

### <a name="remarks"></a>Comentários

Deve ser usado em conjunto com BEGIN_DISPATCH_MAP.

### <a name="requirements"></a>Requisitos

**Cabeçalho:** afxdisp.h

## <a name="disp_function"></a><a name="disp_function"></a>Disp_function

Define uma função de automação OLE em um mapa de despacho.

```cpp
DISP_FUNCTION(
    theClass,
    pszName,
    pfnMember,
    vtRetVal,
    vtsParams)
```

### <a name="parameters"></a>Parâmetros

*Theclass*<br/>
Nome da classe.

*Pszname*<br/>
Nome externo da função.

*pfnMember*<br/>
Nome da função membro.

*vtRetVal*<br/>
Um valor especificando o tipo de retorno da função.

*Vtsparams*<br/>
Uma lista separada pelo espaço de uma ou mais constantes especificando a lista de parâmetros da função.

### <a name="remarks"></a>Comentários

O argumento *vtRetVal* é do tipo VARTYPE. Os seguintes valores possíveis para `VARENUM` este argumento são retirados da enumeração:

|Símbolo|Tipo de retorno|
|------------|-----------------|
|VT_EMPTY|**void**|
|VT_I2|**Curto**|
|VT_I4|**Longas**|
|VT_R4|**float**|
|VT_R8|**double**|
|VT_CY|CY|
|VT_DATE|DATE|
|VT_BSTR|BSTR|
|VT_DISPATCH|LPDISPATCH|
|VT_ERROR|SCODE|
|VT_BOOL|BOOL|
|VT_VARIANT|VARIANT|
|VT_UNKNOWN|Lpunknown|

O argumento *vtsParams* é uma lista de `VTS_*` valores separados pelo espaço das constantes. Um ou mais desses valores separados por espaços (não commas) especifica míseros da função. Por exemplo,

[!code-cpp[NVC_MFCAutomation#14](../../mfc/codesnippet/cpp/dispatch-maps_2.cpp)]

especifica uma lista contendo um inteiro curto seguido de um ponteiro para um inteiro curto.

As `VTS_` constantes e seus significados são os seguintes:

|Símbolo|Tipo de parâmetro|
|------------|--------------------|
|VTS_I2|**Curto**|
|VTS_I4|**Longas**|
|VTS_R4|**float**|
|VTS_R8|**double**|
|VTS_CY|`const CY` ou `CY*`|
|VTS_DATE|DATE|
|VTS_BSTR|LPCSTR|
|VTS_DISPATCH|LPDISPATCH|
|VTS_SCODE|SCODE|
|VTS_BOOL|BOOL|
|VTS_VARIANT|`const VARIANT*` ou `VARIANT&`|
|VTS_UNKNOWN|Lpunknown|
|VTS_PI2|__Curto\*__|
|VTS_PI4|__Longas\*__|
|VTS_PR4|__float\*__|
|VTS_PR8|__Duplo\*__|
|VTS_PCY|`CY*`|
|VTS_PDATE|`DATE*`|
|VTS_PBSTR|`BSTR*`|
|VTS_PDISPATCH|`LPDISPATCH*`|
|VTS_PSCODE|`SCODE*`|
|VTS_PBOOL|`BOOL*`|
|VTS_PVARIANT|`VARIANT*`|
|VTS_PUNKNOWN|`LPUNKNOWN*`|
|VTS_NONE|Sem parâmetros|

### <a name="requirements"></a>Requisitos

**Cabeçalho:** afxdisp.h

## <a name="disp_property"></a><a name="disp_property"></a>Disp_property

Define uma propriedade de automação OLE em um mapa de despacho.

```cpp
DISP_PROPERTY(
    theClass,
    pszName,
    memberName,
    vtPropType)
```

### <a name="parameters"></a>Parâmetros

*Theclass*<br/>
Nome da classe.

*Pszname*<br/>
Nome externo da propriedade.

*Membername*<br/>
Nome da variável membro em que a propriedade é armazenada.

*Vtproptype*<br/>
Um valor especificando o tipo da propriedade.

### <a name="remarks"></a>Comentários

O argumento *vtPropType* é do tipo **VARTYPE**. Os valores possíveis para este argumento são retirados da enumeração VARENUM:

|Símbolo|Tipo de propriedade|
|------------|-----------------------|
|VT_I2|**Curto**|
|VT_I4|**Longas**|
|VT_R4|**float**|
|VT_R8|**double**|
|VT_CY|CY|
|VT_DATE|DATE|
|VT_BSTR|`CString`|
|VT_DISPATCH|LPDISPATCH|
|VT_ERROR|SCODE|
|VT_BOOL|BOOL|
|VT_VARIANT|VARIANT|
|VT_UNKNOWN|Lpunknown|

Quando um cliente externo altera a propriedade, o valor da variável membro especificado pelo *membroNome* muda; não há notificação da mudança.

### <a name="requirements"></a>Requisitos

**Cabeçalho:** afxdisp.h

## <a name="disp_property_ex"></a><a name="disp_property_ex"></a>Disp_property_ex

Define uma propriedade de automação OLE e nomeia as funções usadas para obter e definir o valor da propriedade em um mapa de despacho.

```cpp
DISP_PROPERTY_EX(
    theClass,
    pszName,
    memberGet,
    memberSet,
    vtPropType)
```

### <a name="parameters"></a>Parâmetros

*Theclass*<br/>
Nome da classe.

*Pszname*<br/>
Nome externo da propriedade.

*membroObter*<br/>
Nome da função de membro usado para obter a propriedade.

*Memberset*<br/>
Nome da função de membro usada para definir a propriedade.

*Vtproptype*<br/>
Um valor especificando o tipo da propriedade.

### <a name="remarks"></a>Comentários

As funções *memberGet* e *memberSet* têm assinaturas determinadas pelo argumento *vtPropType.* A função *memberGet* não tem argumentos e retorna um valor do tipo especificado por *vtPropType*. A função *memberSet* leva um argumento do tipo especificado por *vtPropType* e não retorna nada.

O argumento *vtPropType* é do tipo VARTYPE. Os valores possíveis para este argumento são retirados da enumeração VARENUM. Para obter uma lista desses valores, consulte as Observações para o parâmetro *vtRetVal* em [DISP_FUNCTION](#disp_function). Note que VT_EMPTY, listadas nas observações DISP_FUNCTION, não são permitidas como um tipo de dados de propriedade.

### <a name="requirements"></a>Requisitos

**Cabeçalho:** afxdisp.h

## <a name="disp_property_notify"></a><a name="disp_property_notify"></a>Disp_property_notify

Define uma propriedade de automação OLE com notificação em um mapa de despacho.

```cpp
DISP_PROPERTY_NOTIFY(
    theClass,
    szExternalName,
    memberName,
    pfnAfterSet,
    vtPropType)
```

### <a name="parameters"></a>Parâmetros

*Theclass*<br/>
Nome da classe.

*szExternalName*<br/>
Nome externo da propriedade.

*Membername*<br/>
Nome da variável membro em que a propriedade é armazenada.

*pfnAfterSet*<br/>
Nome da função de notificação para *szExternalName*.

*Vtproptype*<br/>
Um valor especificando o tipo da propriedade.

### <a name="remarks"></a>Comentários

Ao contrário das propriedades definidas com DISP_PROPERTY, uma propriedade definida com DISP_PROPERTY_NOTIFY chamará automaticamente a função especificada por *pfnAfterSet* quando a propriedade for alterada.

O argumento *vtPropType* é do tipo VARTYPE. Os valores possíveis para este argumento são retirados da enumeração VARENUM:

|Símbolo|Tipo de propriedade|
|------------|-----------------------|
|VT_I2|**Curto**|
|VT_I4|**Longas**|
|VT_R4|**float**|
|VT_R8|**double**|
|VT_CY|CY|
|VT_DATE|DATE|
|VT_BSTR|`CString`|
|VT_DISPATCH|LPDISPATCH|
|VT_ERROR|SCODE|
|VT_BOOL|BOOL|
|VT_VARIANT|VARIANT|
|VT_UNKNOWN|Lpunknown|

### <a name="requirements"></a>Requisitos

**Cabeçalho:** afxdisp.h

## <a name="disp_property_param"></a><a name="disp_property_param"></a>Disp_property_param

Define uma propriedade acessada com funções separadas `Get` e `Set` membros.

```cpp
DISP_PROPERTY_PARAM(
    theClass,
    pszExternalName,
    pfnGet,
    pfnSet,
    vtPropType,
    vtsParams)
```

### <a name="parameters"></a>Parâmetros

*Theclass*<br/>
Nome da classe.

*pszExternalName*<br/>
Nome externo da propriedade.

*pfnGet*<br/>
Nome da função de membro usado para obter a propriedade.

*pfnSet*<br/>
Nome da função de membro usada para definir a propriedade.

*Vtproptype*<br/>
Um valor especificando o tipo da propriedade.

*Vtsparams*<br/>
Uma seqüência de `VTS_*` tipos de parâmetros de variantes separados pelo espaço, um para cada parâmetro.

### <a name="remarks"></a>Comentários

Ao contrário da DISP_PROPERTY_EX macro, essa macro permite especificar uma lista de parâmetros para a propriedade. Isso é útil para implementar propriedades indexadas ou parametrizadas.

### <a name="example"></a>Exemplo

Considere a seguinte declaração de obter e definir funções de membro que permitem ao usuário solicitar uma linha e coluna específicas ao acessar a propriedade:

[!code-cpp[NVC_MFCActiveXControl#9](../../mfc/codesnippet/cpp/dispatch-maps_3.h)]

Estes correspondem à seguinte DISP_PROPERTY_PARAM macro no mapa de despacho de controle:

[!code-cpp[NVC_MFCActiveXControl#10](../../mfc/codesnippet/cpp/dispatch-maps_4.cpp)]

Como outro exemplo, considere as seguintes funções de obter e definir membros:

[!code-cpp[NVC_MFCActiveXControl#11](../../mfc/codesnippet/cpp/dispatch-maps_5.h)]

Estes correspondem à seguinte DISP_PROPERTY_PARAM macro no mapa de despacho de controle:

[!code-cpp[NVC_MFCActiveXControl#12](../../mfc/codesnippet/cpp/dispatch-maps_6.cpp)]

### <a name="requirements"></a>Requisitos

**Cabeçalho:** afxdisp.h

## <a name="disp_defvalue"></a><a name="disp_defvalue"></a>DISP_DEFVALUE

Faz de uma propriedade existente o valor padrão de um objeto.

```cpp
DISP_DEFVALUE(theClass, pszName)
```

### <a name="parameters"></a>Parâmetros

*Theclass*<br/>
Nome da classe.

*Pszname*<br/>
Nome externo da propriedade que representa o "valor" do objeto.

### <a name="remarks"></a>Comentários

Usar um valor padrão pode tornar a programação do objeto de automação mais simples para aplicações Visual Basic.

O "valor padrão" do objeto é a propriedade recuperada ou definida quando uma referência a um objeto não especifica uma função de propriedade ou membro.

### <a name="requirements"></a>Requisitos

**Cabeçalho:** afxdisp.h

## <a name="see-also"></a>Confira também

[Macros e globais](../../mfc/reference/mfc-macros-and-globals.md)
