---
title: coclass (atributo de COM do C++) | Microsoft Docs
ms.custom: ''
ms.date: 10/02/2018
ms.technology:
- cpp-windows
ms.topic: reference
f1_keywords:
- vc-attr.coclass
dev_langs:
- C++
helpviewer_keywords:
- coclass attribute
ms.assetid: 42da6a10-3af9-4b43-9a1d-689d00b61eb3
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: df131b79d3247e39aecb95c81564d7ac9fc2732d
ms.sourcegitcommit: a9dcbcc85b4c28eed280d8e451c494a00d8c4c25
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/25/2018
ms.locfileid: "50058928"
---
# <a name="coclass"></a>coclass

Cria um objeto COM, que pode implementar uma interface COM.

## <a name="syntax"></a>Sintaxe

```cpp
[coclass]
```

## <a name="remarks"></a>Comentários

O **coclass** atributo C++ coloca uma construção de coclass no arquivo. idl gerado.

Ao definir uma coclass, você também pode especificar o [uuid](uuid-cpp-attributes.md), [versão](version-cpp.md), [threading](threading-cpp.md), [vi_progid](vi-progid.md), e [progid ](progid.md) atributos. Se qualquer um deles não for especificado, ele será gerado.

Se dois arquivos de cabeçalho contêm classes com o **coclass** de atributo e não especificar um GUID, o compilador usará o mesmo GUID para ambas as classes e o que resultará em um erro MIDL.  Portanto, você deve usar o `uuid` atributo quando você usa **coclass**.

**Projetos ATL**

Quando esse atributo precede uma definição de classe ou estrutura em um projeto ATL, ele:

- Injeta código ou os dados para dar suporte ao registro automático para o objeto.

- Injeta código ou os dados para dar suporte a uma fábrica de classes COM para o objeto.

- Injeta código ou os dados para implementar `IUnknown` e fazer o objeto de um objeto instanciável no COM.

Especificamente, as seguintes classes base são adicionadas ao objeto de destino:

- [Classe CComCoClass](../../atl/reference/ccomcoclass-class.md) fornece o modelo de fábrica e agregação de classe padrão para o objeto.

- [Classe CComObjectRootEx](../../atl/reference/ccomobjectrootex-class.md) tem um modelo com base na classe de modelo de threading especificado pelo [threading](threading-cpp.md) atributo. Se o `threading` atributo não for especificado, o padrão modelo de threading é apartment.

- [IProvideClassInfo2Impl](../../atl/reference/iprovideclassinfo2impl-class.md) será adicionado se o [noncreatable](noncreatable.md) atributo não for especificado para o objeto de destino.

Por fim, qualquer interface dupla que não está definido com IDL inserida é substituído pelo correspondente [IDispatchImpl](../../atl/reference/idispatchimpl-class.md) classe. Se a interface dupla é definida em IDL inserida, a interface específica na lista de base não será modificado.

O **coclass** atributo também disponibiliza as seguintes funções por meio de código injetado ou no caso de `GetObjectCLSID`, como um método estático na classe base `CComCoClass`:

- `UpdateRegistry` registra as fábricas de classe da classe de destino.

- `GetObjectCLSID`, que está relacionado ao registro, também pode ser usado para obter o CLSID da classe de destino.

- `GetObjectFriendlyName` Por padrão, retorna uma cadeia de caracteres de formato "\<*nome de classe de destino*> `Object`". Se essa função já estiver presente, ele não será adicionado. Adicione essa função para a classe de destino para retornar um nome mais amigável daquele gerado automaticamente.

- `GetProgID`, que está relacionado ao registro, retorna a cadeia de caracteres especificada com o [progid](progid.md) atributo.

- `GetVersionIndependentProgID` tem a mesma funcionalidade que `GetProgID`, mas ele retorna a cadeia de caracteres especificada com [vi_progid](vi-progid.md).

As seguintes alterações estão relacionadas ao mapa de COM, são feitas para a classe de destino:

- Um mapa COM é adicionado com as entradas para todas as interfaces que deriva de classe de destino e todas as entradas especificadas pela [COM pontos de entrada da Interface](../../mfc/com-interface-entry-points.md) atributo ou aquelas necessárias para o [agregações](aggregates.md) atributo.

- Uma [OBJECT_ENTRY_AUTO](../../atl/reference/object-map-macros.md#object_entry_auto) macro é inserida no mapa COM.

O nome da coclass gerado no arquivo. IDL para a classe terá o mesmo nome que a classe.  Por exemplo e se referindo ao exemplo a seguir, para acessar a ID de classe para uma coclass `CMyClass`, em um cliente por meio do arquivo de cabeçalho gerado pelo MIDL, use `CLSID_CMyClass`.

## <a name="example"></a>Exemplo

O código a seguir mostra como usar o **coclass** atributo:

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

O exemplo a seguir mostra como substituir a implementação padrão de uma função que aparece no código injetado pela **coclass** atributo. Ver [/Fx](../../build/reference/fx-merge-injected-code.md) para obter mais informações sobre como exibir o código injetado. Quaisquer interfaces que você pode usar para uma classe ou classes base será ser exibida no código injetado. Além disso, se uma classe está incluída por padrão no código injetado e você especificar explicitamente essa classe como uma base para seu coclass, o provedor de atributo usará o formulário especificado no seu código.

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

### <a name="attribute-context"></a>Atributo de contexto

|||
|-|-|
|**Aplica-se a**|**classe**, **struct**|
|**Repetível**|Não|
|**Atributos obrigatórios**|Nenhum|
|**Atributos inválidos**|Nenhum|

Para obter mais informações sobre os contextos de atributo, consulte [contextos de atributo](cpp-attributes-com-net.md#contexts).

## <a name="see-also"></a>Consulte também

[Atributos de IDL](idl-attributes.md)<br/>
[Atributos de COM](com-attributes.md)<br/>
[Atributos de classe](class-attributes.md)<br/>
[Atributos Typedef, Enum, Union e Struct](typedef-enum-union-and-struct-attributes.md)<br/>
[appobject](appobject.md)