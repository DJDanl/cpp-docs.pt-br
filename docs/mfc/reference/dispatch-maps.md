---
title: Mapas de expedição
ms.date: 06/20/2018
helpviewer_keywords:
- dispatch maps [MFC], macros
- dispatch maps [MFC]
- dispatch map macros [MFC]
ms.assetid: bef9d08b-ad35-4c3a-99d8-04150c7c04e2
ms.openlocfilehash: f1afa95d7c20d54f2015255a7e4e0d7ad9ae9c2b
ms.sourcegitcommit: 7ecd91d8ce18088a956917cdaf3a3565bd128510
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/16/2020
ms.locfileid: "79421348"
---
# <a name="dispatch-maps"></a>Mapas de expedição

A automação OLE fornece maneiras de chamar métodos e acessar propriedades entre aplicativos. O mecanismo fornecido pelo biblioteca MFC para expedir essas solicitações é o "mapa de expedição", que designa os nomes interno e externo das funções e propriedades do objeto, bem como os tipos de dados das próprias propriedades e de argumentos da função.

|Macro do mapa de expedição|DESCRIÇÃO|
|-|-|
|[DECLARE_DISPATCH_MAP](#declare_dispatch_map)|Declara que um mapa de expedição será usado para expor os métodos e as propriedades de uma classe (deve ser usado na declaração de classe).|
|[BEGIN_DISPATCH_MAP](#begin_dispatch_map)|Inicia a definição de um mapa de expedição.|
|[END_DISPATCH_MAP](#end_dispatch_map)|Finaliza a definição de um mapa de expedição.|
|[DISP_FUNCTION](#disp_function)|Usado em um mapa de expedição para definir uma função de automação OLE.|
|[DISP_PROPERTY](#disp_property)|Define uma propriedade de automação OLE.|
|[DISP_PROPERTY_EX](#disp_property_ex)|Define uma propriedade de automação OLE e nomeia as funções Get e Set.|
|[DISP_PROPERTY_NOTIFY](#disp_property_notify)|Define uma propriedade de automação OLE com notificação.|
|[DISP_PROPERTY_PARAM](#disp_property_param)|Define uma propriedade de automação OLE que usa parâmetros e nomeia as funções Get e Set.|
|[DISP_DEFVALUE](#disp_defvalue)|Torna uma propriedade existente o valor padrão de um objeto.|

## <a name="declare_dispatch_map"></a>DECLARE_DISPATCH_MAP

Se uma classe derivada de `CCmdTarget`em seu programa oferecer suporte à automação OLE, essa classe deverá fornecer um mapa de expedição para expor seus métodos e propriedades.

```cpp
DECLARE_DISPATCH_MAP()
```

### <a name="remarks"></a>Comentários

Use a macro DECLARE_DISPATCH_MAP no final da declaração de sua classe. Em seguida, no. Arquivo CPP que define as funções de membro para a classe, use a macro BEGIN_DISPATCH_MAP. Em seguida, inclua entradas de macro para cada um dos métodos e propriedades expostos de sua classe (DISP_FUNCTION, DISP_PROPERTY e assim por diante). Por fim, use a macro END_DISPATCH_MAP.

> [!NOTE]
> Se você declarar quaisquer membros após DECLARE_DISPATCH_MAP, deverá especificar um novo tipo de acesso ( **público**, **privado**ou **protegido**) para eles.

O assistente de aplicativo e os assistentes de código auxiliam na criação de classes de automação e na manutenção de mapas de expedição. Para obter mais informações sobre mapas de expedição, consulte [servidores de automação](../../mfc/automation-servers.md).

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCAutomation#10](../../mfc/codesnippet/cpp/dispatch-maps_1.h)]

### <a name="requirements"></a>Requisitos

**Cabeçalho:** Afxwin. h

## <a name="begin_dispatch_map"></a>BEGIN_DISPATCH_MAP

Declara a definição de seu mapa de expedição.

```cpp
BEGIN_DISPATCH_MAP(theClass, baseClass)
```

### <a name="parameters"></a>parâmetros

*Classe*<br/>
Especifica o nome da classe que possui este mapa de expedição.

*baseClass*<br/>
Especifica o nome da classe base da *classe*.

### <a name="remarks"></a>Comentários

No arquivo de implementação (. cpp) que define as funções de membro para sua classe, inicie o mapa de expedição com a macro BEGIN_DISPATCH_MAP, adicione entradas de macro para cada uma das suas funções e propriedades de expedição e conclua o mapa de expedição com o END_DISPATCH_ Macro de mapa.

### <a name="requirements"></a>Requisitos

**Cabeçalho:** AFXDISP. h

## <a name="end_dispatch_map"></a>END_DISPATCH_MAP

Termina a definição de seu mapa de expedição.

```cpp
END_DISPATCH_MAP()
```

### <a name="remarks"></a>Comentários

Ele deve ser usado em conjunto com BEGIN_DISPATCH_MAP.

### <a name="requirements"></a>Requisitos

**Cabeçalho:** AFXDISP. h

## <a name="disp_function"></a>DISP_FUNCTION

Define uma função de automação OLE em um mapa de expedição.

```cpp
DISP_FUNCTION(
    theClass,
    pszName,
    pfnMember,
    vtRetVal,
    vtsParams)
```

### <a name="parameters"></a>parâmetros

*Classe*<br/>
Nome da classe.

*pszName*<br/>
Nome externo da função.

*pfnMember*<br/>
Nome da função de membro.

*vtRetVal*<br/>
Um valor que especifica o tipo de retorno da função.

*vtsParams*<br/>
Uma lista separada por espaços de uma ou mais constantes que especificam a lista de parâmetros da função.

### <a name="remarks"></a>Comentários

O argumento *vtRetVal* é do tipo VarType. Os seguintes valores possíveis para esse argumento são obtidos da enumeração de `VARENUM`:

|Símbolo|Tipo de retorno|
|------------|-----------------|
|VT_EMPTY|**void**|
|VT_I2|**short**|
|VT_I4|**long**|
|VT_R4|**float**|
|VT_R8|**double**|
|VT_CY|CY|
|VT_DATE|DATE|
|VT_BSTR|BSTR|
|VT_DISPATCH|LPDISPATCH|
|VT_ERROR|SCODE|
|VT_BOOL|BOOL|
|VT_VARIANT|VARIANT|
|VT_UNKNOWN|LPUNKNOWN|

O argumento *vtsParams* é uma lista de valores separados por espaços das constantes `VTS_*`. Um ou mais desses valores separados por espaços (e não por vírgulas) especifica a lista de parâmetros da função. Por exemplo,

[!code-cpp[NVC_MFCAutomation#14](../../mfc/codesnippet/cpp/dispatch-maps_2.cpp)]

Especifica uma lista que contém um inteiro curto seguido por um ponteiro para um inteiro curto.

As constantes `VTS_` e seus significados são os seguintes:

|Símbolo|Tipo de parâmetro|
|------------|--------------------|
|VTS_I2|**short**|
|VTS_I4|**long**|
|VTS_R4|**float**|
|VTS_R8|**double**|
|VTS_CY|`const CY` ou `CY*`|
|VTS_DATE|DATE|
|VTS_BSTR|LPCSTR|
|VTS_DISPATCH|LPDISPATCH|
|VTS_SCODE|SCODE|
|VTS_BOOL|BOOL|
|VTS_VARIANT|`const VARIANT*` ou `VARIANT&`|
|VTS_UNKNOWN|LPUNKNOWN|
|VTS_PI2|__\* curto__|
|VTS_PI4|__\* longo__|
|VTS_PR4|__\* flutuante__|
|VTS_PR8|__\* duplo__|
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

**Cabeçalho:** AFXDISP. h

## <a name="disp_property"></a>DISP_PROPERTY

Define uma propriedade de automação OLE em um mapa de expedição.

```cpp
DISP_PROPERTY(
    theClass,
    pszName,
    memberName,
    vtPropType)
```

### <a name="parameters"></a>parâmetros

*Classe*<br/>
Nome da classe.

*pszName*<br/>
Nome externo da propriedade.

*memberName*<br/>
Nome da variável de membro na qual a propriedade é armazenada.

*vtPropType*<br/>
Um valor que especifica o tipo da propriedade.

### <a name="remarks"></a>Comentários

O argumento *vtPropType* é do tipo **VarType**. Os valores possíveis para esse argumento são obtidos da enumeração VARENUM:

|Símbolo|Tipo de propriedade|
|------------|-----------------------|
|VT_I2|**short**|
|VT_I4|**long**|
|VT_R4|**float**|
|VT_R8|**double**|
|VT_CY|CY|
|VT_DATE|DATE|
|VT_BSTR|`CString`|
|VT_DISPATCH|LPDISPATCH|
|VT_ERROR|SCODE|
|VT_BOOL|BOOL|
|VT_VARIANT|VARIANT|
|VT_UNKNOWN|LPUNKNOWN|

Quando um cliente externo altera a propriedade, o valor da variável de membro especificada por *MemberName* é alterado; Não há nenhuma notificação da alteração.

### <a name="requirements"></a>Requisitos

**Cabeçalho:** AFXDISP. h

## <a name="disp_property_ex"></a>DISP_PROPERTY_EX

Define uma propriedade de automação OLE e nomear as funções usadas para obter e definir o valor da propriedade em um mapa de expedição.

```cpp
DISP_PROPERTY_EX(
    theClass,
    pszName,
    memberGet,
    memberSet,
    vtPropType)
```

### <a name="parameters"></a>parâmetros

*Classe*<br/>
Nome da classe.

*pszName*<br/>
Nome externo da propriedade.

*memberGet*<br/>
Nome da função de membro usada para obter a propriedade.

*memberSet*<br/>
Nome da função de membro usada para definir a propriedade.

*vtPropType*<br/>
Um valor que especifica o tipo da propriedade.

### <a name="remarks"></a>Comentários

As funções *memberGet* e *MemberSet* têm assinaturas determinadas pelo argumento *vtPropType* . A função *memberGet* não usa argumentos e retorna um valor do tipo especificado por *vtPropType*. A função *MemberSet* usa um argumento do tipo especificado por *vtPropType* e não retorna nada.

O argumento *vtPropType* é do tipo VarType. Os valores possíveis para esse argumento são obtidos da enumeração VARENUM. Para obter uma lista desses valores, consulte os comentários para o parâmetro *vtRetVal* em [DISP_FUNCTION](#disp_function). Observe que VT_EMPTY, listados na DISP_FUNCTION comentários, não são permitidos como um tipo de dados de propriedade.

### <a name="requirements"></a>Requisitos

**Cabeçalho:** AFXDISP. h

## <a name="disp_property_notify"></a>DISP_PROPERTY_NOTIFY

Define uma propriedade de automação OLE com notificação em um mapa de expedição.

```cpp
DISP_PROPERTY_NOTIFY(
    theClass,
    szExternalName,
    memberName,
    pfnAfterSet,
    vtPropType)
```

### <a name="parameters"></a>parâmetros

*Classe*<br/>
Nome da classe.

*szExternalName*<br/>
Nome externo da propriedade.

*memberName*<br/>
Nome da variável de membro na qual a propriedade é armazenada.

*pfnAfterSet*<br/>
Nome da função de notificação para *szExternalName*.

*vtPropType*<br/>
Um valor que especifica o tipo da propriedade.

### <a name="remarks"></a>Comentários

Ao contrário das propriedades definidas com DISP_PROPERTY, uma propriedade definida com DISP_PROPERTY_NOTIFY chamará automaticamente a função especificada por *pfnAfterSet* quando a propriedade for alterada.

O argumento *vtPropType* é do tipo VarType. Os valores possíveis para esse argumento são obtidos da enumeração VARENUM:

|Símbolo|Tipo de propriedade|
|------------|-----------------------|
|VT_I2|**short**|
|VT_I4|**long**|
|VT_R4|**float**|
|VT_R8|**double**|
|VT_CY|CY|
|VT_DATE|DATE|
|VT_BSTR|`CString`|
|VT_DISPATCH|LPDISPATCH|
|VT_ERROR|SCODE|
|VT_BOOL|BOOL|
|VT_VARIANT|VARIANT|
|VT_UNKNOWN|LPUNKNOWN|

### <a name="requirements"></a>Requisitos

**Cabeçalho:** AFXDISP. h

## <a name="disp_property_param"></a>DISP_PROPERTY_PARAM

Define uma propriedade acessada com `Get` separadas e funções de membro de `Set`.

```cpp
DISP_PROPERTY_PARAM(
    theClass,
    pszExternalName,
    pfnGet,
    pfnSet,
    vtPropType,
    vtsParams)
```

### <a name="parameters"></a>parâmetros

*Classe*<br/>
Nome da classe.

*pszExternalName*<br/>
Nome externo da propriedade.

*pfnGet*<br/>
Nome da função de membro usada para obter a propriedade.

*pfnSet*<br/>
Nome da função de membro usada para definir a propriedade.

*vtPropType*<br/>
Um valor que especifica o tipo da propriedade.

*vtsParams*<br/>
Uma cadeia de caracteres de `VTS_*` tipos de parâmetro variados separados por espaços, um para cada parâmetro.

### <a name="remarks"></a>Comentários

Ao contrário da macro DISP_PROPERTY_EX, essa macro permite que você especifique uma lista de parâmetros para a propriedade. Isso é útil para implementar propriedades que são indexadas ou parametrizadas.

### <a name="example"></a>Exemplo

Considere a seguinte declaração de funções de membro get e set que permitem ao usuário solicitar uma linha e coluna específicas ao acessar a propriedade:

[!code-cpp[NVC_MFCActiveXControl#9](../../mfc/codesnippet/cpp/dispatch-maps_3.h)]

Eles correspondem à seguinte macro DISP_PROPERTY_PARAM no mapa de expedição de controle:

[!code-cpp[NVC_MFCActiveXControl#10](../../mfc/codesnippet/cpp/dispatch-maps_4.cpp)]

Como outro exemplo, considere as seguintes funções de membro get e Set:

[!code-cpp[NVC_MFCActiveXControl#11](../../mfc/codesnippet/cpp/dispatch-maps_5.h)]

Eles correspondem à seguinte macro DISP_PROPERTY_PARAM no mapa de expedição de controle:

[!code-cpp[NVC_MFCActiveXControl#12](../../mfc/codesnippet/cpp/dispatch-maps_6.cpp)]

### <a name="requirements"></a>Requisitos

**Cabeçalho:** AFXDISP. h

## <a name="disp_defvalue"></a>DISP_DEFVALUE

Torna uma propriedade existente o valor padrão de um objeto.

```cpp
DISP_DEFVALUE(theClass, pszName)
```

### <a name="parameters"></a>parâmetros

*Classe*<br/>
Nome da classe.

*pszName*<br/>
Nome externo da propriedade que representa o "valor" do objeto.

### <a name="remarks"></a>Comentários

Usar um valor padrão pode tornar a programação do objeto de automação mais simples para aplicativos Visual Basic.

O "valor padrão" do seu objeto é a propriedade que é recuperada ou definida quando uma referência a um objeto não especifica uma propriedade ou função de membro.

### <a name="requirements"></a>Requisitos

**Cabeçalho:** AFXDISP. h

## <a name="see-also"></a>Confira também

[Macros e globais](../../mfc/reference/mfc-macros-and-globals.md)
