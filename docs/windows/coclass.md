---
title: coclass | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
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
ms.openlocfilehash: 5eb9c7e632151c039b76a0f389cd18c68c0740ab
ms.sourcegitcommit: d55ac596ba8f908f5d91d228dc070dad31cb8360
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/08/2018
---
# <a name="coclass"></a>coclass
Cria um objeto COM, que pode implementar uma interface COM.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
  
[coclass]  
  
```  
  
## <a name="remarks"></a>Comentários  
 O **coclass** atributo C++ coloca uma construção de coclass no arquivo. idl gerado.  
  
 Ao definir uma coclass, você também pode especificar o [uuid](../windows/uuid-cpp-attributes.md), [versão](../windows/version-cpp.md), [threading](../windows/threading-cpp.md), [vi_progid](../windows/vi-progid.md), e [progid ](../windows/progid.md) atributos. Se qualquer um deles não for especificado, ele será gerado.  
  
 Se dois arquivos de cabeçalho contêm classes com o **coclass** de atributos e não especificar um GUID, o compilador usará o mesmo GUID para ambas as classes e o que resultará em um erro MIDL.  Portanto, você deve usar o `uuid` atributo quando você usar **coclass**.  
  
 **Projetos ATL**  
  
 Quando esse atributo precede uma definição de classe ou estrutura em um projeto ATL, ele:  
  
-   Insere um código ou dados para dar suporte a registro automático para o objeto.  
  
-   Insere um código ou dados para dar suporte a uma fábrica de classe COM para o objeto.  
  
-   Insere um código ou dados para implementar **IUnknown** e tornar o objeto de um objeto instanciável no COM.  
  
 Especificamente, as seguintes classes base são adicionadas ao objeto de destino:  
  
-   [Classe de CComCoClass](../atl/reference/ccomcoclass-class.md) fornece o modelo de fábrica e agregação de classe padrão para o objeto.  
  
-   [Classe CComObjectRootEx](../atl/reference/ccomobjectrootex-class.md) tem um modelo com base na classe de modelo de threading especificada pelo [threading](../windows/threading-cpp.md) atributo. Se o **threading** atributo não for especificado, o padrão de modelo de threading é apartment.  
  
-   [IProvideClassInfo2Impl](../atl/reference/iprovideclassinfo2impl-class.md) é adicionado se o [noncreatable](../windows/noncreatable.md) atributo não for especificado para o objeto de destino.  
  
 Finalmente, qualquer interface dupla que não é definido usando IDL inserido é substituído pelo correspondente [IDispatchImpl](../atl/reference/idispatchimpl-class.md) classe. Se a interface dupla é definida em IDL inserida, a interface específica na lista de base não é modificado.  
  
 O **coclass** atributo também disponibiliza as seguintes funções por meio de código injetado ou, no caso de `GetObjectCLSID`, como um método estático na classe base `CComCoClass`:  
  
-   `UpdateRegistry` registra as fábricas de classe da classe de destino.  
  
-   `GetObjectCLSID`, que está relacionado ao registro, também pode ser usado para obter o CLSID da classe de destino.  
  
-   **GetObjectFriendlyName** por padrão retorna uma cadeia de caracteres de formato "\<*nome de classe de destino*> `Object`". Se essa função já está presente, ele não será adicionado. Adicione essa função para a classe de destino para retornar um nome amigável que o gerado automaticamente.  
  
-   **GetProgID**, que está relacionado ao registro, retorna a cadeia de caracteres especificada com o [progid](../windows/progid.md) atributo.  
  
-   **GetVersionIndependentProgID** tem a mesma funcionalidade que **GetProgID**, mas retorna a cadeia de caracteres especificada com [vi_progid](../windows/vi-progid.md).  
  
 As seguintes alterações que estão relacionadas ao mapa COM, são feitas para a classe de destino:  
  
-   Um mapa COM é adicionado com entradas de todas as interfaces que deriva de classe de destino e todas as entradas especificadas pelo [COM pontos de entrada da Interface](../mfc/com-interface-entry-points.md) atributo ou aquelas necessárias para o [agregações](../windows/aggregates.md) atributo.  
  
-   Um [OBJECT_ENTRY_AUTO](../atl/reference/object-map-macros.md#object_entry_auto) macro é inserida no mapa de COM.
  
 O nome da coclass gerado no arquivo. IDL para a classe terá o mesmo nome que a classe.  Por exemplo, referindo-se ao exemplo a seguir, para acessar a ID de classe para uma coclass CMyClass, em um cliente por meio do arquivo de cabeçalho gerado pelo MIDL, use CLSID_CMyClass.  
  
## <a name="example"></a>Exemplo  
 O código a seguir mostra como usar o **coclass** atributo:  
  
```  
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
  
 O exemplo a seguir mostra como substituir a implementação padrão de uma função que aparece no código injetado pelo **coclass** atributo. Consulte [/Fx](../build/reference/fx-merge-injected-code.md) para obter mais informações sobre a exibição de código injetado. Qualquer classes base ou interfaces que você pode usar para uma classe ser aparecerá no código injetado.   Além disso, se uma classe está incluída por padrão no código injetado e você especificar explicitamente essa classe como base para seu coclass, o provedor de atributo usará o formato especificado no seu código.  
  
```  
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
   // by adding the definition of UpdateRegistry to your code,   
   // the function will not be included in the injected code  
   static HRESULT WINAPI UpdateRegistry(BOOL bRegister) {  
      // you can add to the default implementation  
      CRegistryVirtualMachine rvm;  
      HRESULT hr;  
      if (FAILED(hr = rvm.AddStandardReplacements()))  
         return hr;  
      rvm.AddReplacement(_T("FriendlyName"), GetObjectFriendlyName());  
      return rvm.VMUpdateRegistry(GetOpCodes(), GetOpcodeStringVals(),  
         GetOpcodeDWORDVals(), GetOpcodeBinaryVals(), bRegister);  
   }  
};  
```  
  
## <a name="requirements"></a>Requisitos  
  
### <a name="attribute-context"></a>Contexto de atributo  
  
|||  
|-|-|  
|**Aplica-se a**|**class**, `struct`|  
|**Repetível**|Não|  
|**Atributos necessários.**|Nenhum|  
|**Atributos inválidos**|Nenhum|  
  
 Para obter mais informações sobre os contextos de atributo, consulte [contextos de atributo](../windows/attribute-contexts.md).  
  
## <a name="see-also"></a>Consulte também  
 [Atributos IDL](../windows/idl-attributes.md)   
 [Atributos COM](../windows/com-attributes.md)   
 [Atributos de classe](../windows/class-attributes.md)   
 [TypeDef, Enum, Union e Struct atributos](../windows/typedef-enum-union-and-struct-attributes.md)   
 [appobject](../windows/appobject.md)