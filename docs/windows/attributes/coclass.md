---
title: coclass (C++ atributo com)
ms.date: 10/02/2018
f1_keywords:
- vc-attr.coclass
helpviewer_keywords:
- coclass attribute
ms.assetid: 42da6a10-3af9-4b43-9a1d-689d00b61eb3
ms.openlocfilehash: 76540e90fef2e840b91bb07f570a7b8c0987eb10
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80168325"
---
# <a name="coclass"></a>coclass

Cria um objeto COM, que pode implementar uma interface COM.

## <a name="syntax"></a>Sintaxe

```cpp
[coclass]
```

## <a name="remarks"></a>Comentários

O atributo **coclass** C++ coloca uma construção coclass no arquivo. idl gerado.

Ao definir uma coclass, você também pode especificar os atributos [UUID](uuid-cpp-attributes.md), [version](version-cpp.md), [Threading](threading-cpp.md), [vi_progid](vi-progid.md)e [ProgID](progid.md) . Se qualquer um deles não for especificado, ele será gerado.

Se dois arquivos de cabeçalho contiverem classes com o atributo **coclass** e não especificarem um GUID, o compilador usará o mesmo GUID para ambas as classes e isso resultará em um erro MIDL.  Portanto, você deve usar o atributo `uuid` ao usar **coclass**.

**Projetos da ATL**

Quando esse atributo precede uma definição de classe ou estrutura em um projeto ATL, ele:

- Injeta código ou dados para dar suporte ao registro automático do objeto.

- Injeta código ou dados para dar suporte a uma fábrica de classes COM do objeto.

- Injeta código ou dados para implementar `IUnknown` e transformar o objeto em um objeto COM-creatable.

Especificamente, as seguintes classes base são adicionadas ao objeto de destino:

- A [classe CComCoClass](../../atl/reference/ccomcoclass-class.md) fornece a fábrica de classes padrão e o modelo de agregação para o objeto.

- A [classe CComObjectRootEx](../../atl/reference/ccomobjectrootex-class.md) tem um modelo baseado na classe de modelo de Threading especificada pelo atributo [Threading](threading-cpp.md) . Se o atributo `threading` não for especificado, o modelo de Threading padrão será Apartment.

- [IProvideClassInfo2Impl](../../atl/reference/iprovideclassinfo2impl-class.md) será adicionado se o atributo não- [cri](noncreatable.md) não for especificado para o objeto de destino.

Finalmente, qualquer interface dupla que não esteja definida usando IDL inserida será substituída pela classe [IDispatchImpl](../../atl/reference/idispatchimpl-class.md) correspondente. Se a interface dupla for definida em IDL inserida, a interface específica na lista de base não será modificada.

O atributo **coclass** também torna as seguintes funções disponíveis por meio de código injetado, ou no caso de `GetObjectCLSID`, como um método estático na classe base `CComCoClass`:

- `UpdateRegistry` registra as fábricas de classe da classe de destino.

- `GetObjectCLSID`, que está relacionado ao registro, também pode ser usado para obter o CLSID da classe de destino.

- `GetObjectFriendlyName`, por padrão, retorna uma cadeia de caracteres do formato "\<*nome da classe de destino*> `Object`". Se essa função já estiver presente, ela não será adicionada. Adicione essa função à classe de destino para retornar um nome mais amigável do que aquela gerada automaticamente.

- `GetProgID`, que está relacionado ao registro, retorna a cadeia de caracteres especificada com o atributo [ProgID](progid.md) .

- `GetVersionIndependentProgID` tem a mesma funcionalidade que `GetProgID`, mas retorna a cadeia de caracteres especificada com [vi_progid](vi-progid.md).

As seguintes alterações, que estão relacionadas ao mapa COM, são feitas na classe de destino:

- Um mapa COM é adicionado com entradas para todas as interfaces das quais a classe de destino deriva e todas as entradas especificadas pelo atributo de [pontos de entrada de interface com](../../mfc/com-interface-entry-points.md) ou aquelas requeridas pelo atributo de [agregações](aggregates.md) .

- Uma macro [OBJECT_ENTRY_AUTO](../../atl/reference/object-map-macros.md#object_entry_auto) é inserida no mapa com.

O nome da coclasse gerada no arquivo. idl da classe terá o mesmo nome que a classe.  Por exemplo, e fazendo referência ao exemplo a seguir, para acessar a ID de classe de um `CMyClass`de coclasse, em um cliente por meio do arquivo de cabeçalho gerado por MIDL, use `CLSID_CMyClass`.

## <a name="example"></a>Exemplo

O código a seguir mostra como usar o atributo **coclass** :

```cpp
// cpp_attr_ref_coclass1.cpp
// compile with: /LD
#include "unknwn.h"
[module(name="MyLib")];

[ object, uuid("00000000-0000-0000-0000-000000000001") ]
__interface I {
   HRESULT func();
};

[coclass, progid("MyCoClass.coclass.1"), vi_progid("MyCoClass.coclass"),
appobject, uuid("9E66A294-4365-11D2-A997-00C04FA37DDB")]
class CMyClass : public I {};
```

O exemplo a seguir mostra como substituir a implementação padrão de uma função que aparece no código injetado pelo atributo **coclass** . Consulte [/FX](../../build/reference/fx-merge-injected-code.md) para obter mais informações sobre como exibir código injetado. Todas as classes base ou interfaces que você usar para uma classe serão exibidas no código injetado. Além disso, se uma classe for incluída por padrão no código injetado e você especificar explicitamente essa classe como uma base para sua coclass, o provedor de atributos usará o formulário especificado em seu código.

```cpp
// cpp_attr_ref_coclass2.cpp
// compile with: /LD
#include <atlbase.h>
#include <atlcom.h>
#include <atlwin.h>
#include <atltypes.h>
#include <atlctl.h>
#include <atlhost.h>
#include <atlplus.h>

[module(name="MyLib")];

[object, uuid("00000000-0000-0000-0000-000000000000")]
__interface bb {};

[coclass, uuid("00000000-0000-0000-0000-000000000001")]
class CMyClass : public bb {
public:
   // by adding the definition of UpdateRegistry to your code, // the function will not be included in the injected code
   static HRESULT WINAPI UpdateRegistry(BOOL bRegister) {
      // you can add to the default implementation
      CRegistryVirtualMachine rvm;
      HRESULT hr;
      if (FAILED(hr = rvm.AddStandardReplacements()))
         return hr;
      rvm.AddReplacement(_T("FriendlyName"), GetObjectFriendlyName());
      return rvm.VMUpdateRegistry(GetOpCodes(), GetOpcodeStringVals(),       GetOpcodeDWORDVals(), GetOpcodeBinaryVals(), bRegister);
   }
};
```

## <a name="requirements"></a>Requisitos

### <a name="attribute-context"></a>Contexto de atributo

|||
|-|-|
|**Aplica-se a**|**classe**, **struct**|
|**Repetível**|Não|
|**Atributos necessários**|Nenhum|
|**Atributos inválidos**|Nenhum|

Para obter mais informações sobre os contextos de atributo, consulte [contextos de atributo](cpp-attributes-com-net.md#contexts).

## <a name="see-also"></a>Confira também

[Atributos de IDL](idl-attributes.md)<br/>
[Atributos de COM](com-attributes.md)<br/>
[Atributos de classe](class-attributes.md)<br/>
[Atributos Typedef, Enum, Union e Struct](typedef-enum-union-and-struct-attributes.md)<br/>
[appobject](appobject.md)
