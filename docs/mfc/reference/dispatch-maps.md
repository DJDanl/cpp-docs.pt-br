---
title: Mapas de envios | Microsoft Docs
ms.custom: ''
ms.date: 06/20/2018
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
ms.openlocfilehash: 3d22c94513e80c4f353de9e10588f219a2d3be92
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46388063"
---
# <a name="dispatch-maps"></a>Mapas de expedição

Automação OLE fornece maneiras para chamar métodos e acessar propriedades entre aplicativos. O mecanismo fornecido pelo biblioteca Microsoft Foundation Class para distribuir essas solicitações é o "mapa de expedição", que designa os nomes internos e externos de propriedades e funções de objeto, bem como os tipos de dados das propriedades em si e de argumentos da função.

|Macro de mapa de expedição|Descrição|
|-|-|
|[DECLARE_DISPATCH_MAP](#declare_dispatch_map)|Declara que um mapa de expedição será usado para expor métodos e propriedades (deve ser usado na declaração de classe) de uma classe.|
|[BEGIN_DISPATCH_MAP](#begin_dispatch_map)|Inicia a definição de um mapa de expedição.|
|[END_DISPATCH_MAP](#end_dispatch_map)|Finaliza a definição de um mapa de expedição.|
|[DISP_FUNCTION](#disp_function)|Usado em um mapa de expedição para definir uma função de automação OLE.|
|[DISP_PROPERTY](#disp_property)|Define uma propriedade de automação OLE.|
|[DISP_PROPERTY_EX](#disp_property_ex)|Define uma propriedade de automação OLE e nomeia as funções Get e Set.|
|[DISP_PROPERTY_NOTIFY](#disp_property_notify)|Define uma propriedade de automação OLE com notificação.|
|[DISP_PROPERTY_PARAM](#disp_property_param)|Define uma propriedade de automação OLE que usa nomes e os parâmetros que as funções Get e Set.|
|[DISP_DEFVALUE](#disp_defvalue)|Torna o valor padrão de um objeto de uma propriedade existente.|

## <a name="declare_dispatch_map"></a>  DECLARE_DISPATCH_MAP

Se um `CCmdTarget`-classe derivada em seu programa dá suporte à automação OLE, que a classe deve fornecer um mapa de expedição para expor seus métodos e propriedades.

```cpp
DECLARE_DISPATCH_MAP()
```

### <a name="remarks"></a>Comentários

Use a macro DECLARE_DISPATCH_MAP no final de sua declaração de classe. Em seguida, na. Arquivo CPP que define as funções de membro para a classe, use a macro BEGIN_DISPATCH_MAP. Em seguida, inclua entradas de macro para cada um dos métodos expostos da sua classe e propriedades (DISP_FUNCTION, DISP_PROPERTY e assim por diante). Por fim, use a macro END_DISPATCH_MAP.

> [!NOTE]
> Se você declarar nenhum membro depois DECLARE_DISPATCH_MAP, você deve especificar um novo tipo de acesso ( **pública**, **privada**, ou **protegido**) para eles.

Os assistentes de código e o Assistente para aplicativo auxiliar na criação de classes de automação e na manutenção de mapas de expedição. Para obter mais informações sobre mapas de expedição, consulte [servidores de automação](../../mfc/automation-servers.md).

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCAutomation#10](../../mfc/codesnippet/cpp/dispatch-maps_1.h)]

### <a name="requirements"></a>Requisitos

**Cabeçalho:** afxwin. h

## <a name="begin_dispatch_map"></a>  BEGIN_DISPATCH_MAP

Declara a definição de seu mapa de expedição.

```cpp
BEGIN_DISPATCH_MAP(theClass, baseClass)
```

### <a name="parameters"></a>Parâmetros

*theClass*<br/>
Especifica o nome da classe que possui este mapa de expedição.

*baseClass*<br/>
Especifica o nome da classe base *theClass*.

### <a name="remarks"></a>Comentários

No arquivo de implementação (. cpp) que define as funções de membro para a sua classe, iniciar o mapa de expedição com a macro BEGIN_DISPATCH_MAP, adicione entradas de macro para cada uma das suas propriedades e as funções de expedição e concluir o mapa de expedição com o END_DISPATCH_ Macro de mapa.

### <a name="requirements"></a>Requisitos

**Cabeçalho:** afxdisp.h

## <a name="end_dispatch_map"></a>  END_DISPATCH_MAP

Finaliza a definição de seu mapa de expedição.

```cpp
END_DISPATCH_MAP()
```

### <a name="remarks"></a>Comentários

Ele deve ser usado em conjunto com BEGIN_DISPATCH_MAP.

### <a name="requirements"></a>Requisitos

**Cabeçalho:** afxdisp.h

## <a name="disp_function"></a>  DISP_FUNCTION

Define uma função de automação OLE em um mapa de expedição.

```cpp
DISP_FUNCTION(
  theClass,
  pszName,
  pfnMember,
  vtRetVal,
  vtsParams)
```

### <a name="parameters"></a>Parâmetros

*theClass*<br/>
Nome da classe.

*pszName*<br/>
Nome externo da função.

*pfnMember*<br/>
Nome da função de membro.

*vtRetVal*<br/>
Um valor que especifica o tipo de retorno da função.

*vtsParams*<br/>
Uma lista separada por espaços de uma ou mais constantes especificando a lista de parâmetros da função.

### <a name="remarks"></a>Comentários

O *vtRetVal* argumento é do tipo VARTYPE. Os seguintes valores possíveis para esse argumento são tirados o `VARENUM` enumeração:

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

O *vtsParams* argumento é uma lista separada por espaço de valores da `VTS_*` constantes. Um ou mais desses valores separados por espaços (não a vírgula) Especifica a lista de parâmetros da função. Por exemplo,

[!code-cpp[NVC_MFCAutomation#14](../../mfc/codesnippet/cpp/dispatch-maps_2.cpp)]

Especifica uma lista que contém um inteiro curto seguido por um ponteiro para um inteiro curto.

O `VTS_` constantes e seus significados são da seguinte maneira:

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
|VTS_PI2|__short\*__|
|VTS_PI4|__long\*__|
|VTS_PR4|__float\*__|
|VTS_PR8|__Double\*__|
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

## <a name="disp_property"></a>  DISP_PROPERTY

Define uma propriedade de automação OLE em um mapa de expedição.

```cpp
DISP_PROPERTY(
  theClass,
  pszName,
  memberName,
  vtPropType)
```

### <a name="parameters"></a>Parâmetros

*theClass*<br/>
Nome da classe.

*pszName*<br/>
Nome externo da propriedade.

*Nome do membro*<br/>
Nome da variável de membro no qual a propriedade é armazenada.

*vtPropType*<br/>
Um valor que especifica o tipo da propriedade.

### <a name="remarks"></a>Comentários

O *vtPropType* argumento é do tipo **VARTYPE**. Os valores possíveis para esse argumento são tirados da enumeração VARENUM:

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

Quando um cliente externo altera a propriedade, o valor da variável de membro especificado por *memberName* for alterado; não há nenhuma notificação de alteração.

### <a name="requirements"></a>Requisitos

**Cabeçalho:** afxdisp.h

## <a name="disp_property_ex"></a>  DISP_PROPERTY_EX

Define uma propriedade de automação OLE e o nome as funções usadas para obter e definir o valor da propriedade em um mapa de expedição.

```cpp
DISP_PROPERTY_EX(
  theClass,
  pszName,
  memberGet,
  memberSet,
  vtPropType)
```

### <a name="parameters"></a>Parâmetros

*theClass*<br/>
Nome da classe.

*pszName*<br/>
Nome externo da propriedade.

*memberGet*<br/>
Nome da função de membro usada para obter a propriedade.

*conjunto de membros*<br/>
Nome da função de membro usada para definir a propriedade.

*vtPropType*<br/>
Um valor que especifica o tipo da propriedade.

### <a name="remarks"></a>Comentários

O *memberGet* e *memberSet* funções têm assinaturas determinadas pelo *vtPropType* argumento. O *memberGet* função não utiliza argumentos e retorna um valor do tipo especificado por *vtPropType*. O *memberSet* função usa um argumento do tipo especificado pelo *vtPropType* e não retorna nada.

O *vtPropType* argumento é do tipo VARTYPE. Os valores possíveis para esse argumento são tirados da enumeração VARENUM. Para obter uma lista desses valores, consulte os comentários para o *vtRetVal* parâmetro na [DISP_FUNCTION](#disp_function). Observe que VT_EMPTY, listados em comentários DISP_FUNCTION, não é permitido como um tipo de dados de propriedade.

### <a name="requirements"></a>Requisitos

**Cabeçalho:** afxdisp.h

## <a name="disp_property_notify"></a>  DISP_PROPERTY_NOTIFY

Define uma propriedade de automação OLE com notificação em um mapa de expedição.

```cpp
DISP_PROPERTY_NOTIFY(
  theClass,
  szExternalName,
  memberName,
  pfnAfterSet,
  vtPropType)
```

### <a name="parameters"></a>Parâmetros

*theClass*<br/>
Nome da classe.

*szExternalName*<br/>
Nome externo da propriedade.

*Nome do membro*<br/>
Nome da variável de membro no qual a propriedade é armazenada.

*pfnAfterSet*<br/>
Nome da função de notificação *szExternalName*.

*vtPropType*<br/>
Um valor que especifica o tipo da propriedade.

### <a name="remarks"></a>Comentários

Ao contrário das propriedades definidas com DISP_PROPERTY, uma propriedade definida com DISP_PROPERTY_NOTIFY automaticamente chama a função especificada por *pfnAfterSet* quando a propriedade é alterada.

O *vtPropType* argumento é do tipo VARTYPE. Os valores possíveis para esse argumento são tirados da enumeração VARENUM:

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

**Cabeçalho:** afxdisp.h

## <a name="disp_property_param"></a>  DISP_PROPERTY_PARAM

Define uma propriedade acessada com separado `Get` e `Set` funções de membro.

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

*theClass*<br/>
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
Uma cadeia de caracteres separada por espaço `VTS_*` tipos de parâmetro variante, um para cada parâmetro.

### <a name="remarks"></a>Comentários

Ao contrário de macro DISP_PROPERTY_EX, essa macro permite que você especifique uma lista de parâmetros para a propriedade. Isso é útil para implementar propriedades que são indexadas ou com parâmetros.

### <a name="example"></a>Exemplo

Considere a seguinte declaração de get e membro do conjunto de funções que permitem ao usuário solicitar uma linha e coluna específica ao acessar a propriedade:

[!code-cpp[NVC_MFCActiveXControl#9](../../mfc/codesnippet/cpp/dispatch-maps_3.h)]

Elas correspondem à seguinte macro DISP_PROPERTY_PARAM no mapa de expedição de controle:

[!code-cpp[NVC_MFCActiveXControl#10](../../mfc/codesnippet/cpp/dispatch-maps_4.cpp)]

Como outro exemplo, considere o seguinte get e membro do conjunto de funções:

[!code-cpp[NVC_MFCActiveXControl#11](../../mfc/codesnippet/cpp/dispatch-maps_5.h)]

Elas correspondem à seguinte macro DISP_PROPERTY_PARAM no mapa de expedição de controle:

[!code-cpp[NVC_MFCActiveXControl#12](../../mfc/codesnippet/cpp/dispatch-maps_6.cpp)]

### <a name="requirements"></a>Requisitos

**Cabeçalho:** afxdisp.h

## <a name="disp_defvalue"></a>  DISP_DEFVALUE

Torna o valor padrão de um objeto de uma propriedade existente.

```cpp
DISP_DEFVALUE(theClass, pszName)
```

### <a name="parameters"></a>Parâmetros

*theClass*<br/>
Nome da classe.

*pszName*<br/>
Nome externo da propriedade que representa o "valor" do objeto.

### <a name="remarks"></a>Comentários

Usando um valor padrão pode tornar a programação de seu objeto de automação mais simples para aplicativos Visual Basic.

O "valor padrão" de seu objeto é a propriedade que é recuperada ou definida quando uma referência a um objeto não especifica uma propriedade ou função de membro.

### <a name="requirements"></a>Requisitos

**Cabeçalho:** afxdisp.h

## <a name="see-also"></a>Consulte também

[Macros e globais](../../mfc/reference/mfc-macros-and-globals.md)
