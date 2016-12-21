---
title: "coclass | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "language-reference"
f1_keywords: 
  - "vc-attr.coclass"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "coclass attribute"
ms.assetid: 42da6a10-3af9-4b43-9a1d-689d00b61eb3
caps.latest.revision: 13
caps.handback.revision: 13
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# coclass
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Cria um objeto COM, que pode implementar uma interface COM.  
  
## Sintaxe  
  
```  
  
[coclass]  
  
```  
  
## Comentários  
 O  **coclass** atributo C\+\+ coloca uma construção coclass no arquivo. idl gerado.  
  
 Ao definir um coclass, você também pode especificar o  [uuid](../windows/uuid-cpp-attributes.md),  [versão](../windows/version-cpp.md),  [threading](../windows/threading-cpp.md),  [vi\_progid](../windows/vi-progid.md), e  [progid](../Topic/progid.md) atributos.  Se qualquer um deles não for especificado, ele será gerado.  
  
 Se dois arquivos de cabeçalho contém classes com o  **coclass** de atributo e não especificar um GUID, o compilador usará o mesmo GUID para ambas as classes, e isso resultará em um erro MIDL.  Portanto, você deve usar o `uuid` quando você usa o atributo  **coclass**.  
  
 **Projetos do ATL**  
  
 Quando esse atributo precede uma definição de classe ou estrutura em um projeto ATL, ele:  
  
-   Insere um código ou dados para dar suporte a registro automático para o objeto.  
  
-   Insere um código ou dados para suportar uma fábrica de classes COM para o objeto.  
  
-   Injeta o código ou dados para implementar  **IUnknown** e tornar o objeto em um objeto COM pode ser criado.  
  
 Especificamente, as seguintes classes base são adicionadas ao objeto de destino:  
  
-   [Classe CComCoClass](../Topic/CComCoClass%20Class.md) fornece o modelo de fábrica e agregação de classe padrão para o objeto.  
  
-   [Classe CComObjectRootEx](../atl/reference/ccomobjectrootex-class.md) tem um modelo com base na classe de modelo de threading especificada pelo  [threading](../windows/threading-cpp.md) atributo.  Se o  **threading** atributo não for especificado, o padrão de modelo de threading é apartamento.  
  
-   [IProvideClassInfo2Impl](../atl/reference/iprovideclassinfo2impl-class.md) é adicionada se a  [noncreatable](../windows/noncreatable.md) atributo não for especificado para o objeto de destino.  
  
 Finalmente, qualquer interface dupla que não está definido com IDL incorporada é substituído com o correspondente  [IDispatchImpl](../atl/reference/idispatchimpl-class.md) classe.  Se a interface dupla é definida no IDL incorporado, a interface específica na lista base não é modificada.  
  
 O  **coclass** atributo também disponibiliza as seguintes funções por meio do código injetado ou no caso de `GetObjectCLSID`, como um método estático na classe base `CComCoClass`:  
  
-   `UpdateRegistry`registra as fábricas de classe da classe destino.  
  
-   `GetObjectCLSID`, que está relacionado ao registro, também pode ser usado para obter o CLSID da classe destino.  
  
-   **GetObjectFriendlyName** por padrão retorna uma seqüência de caracteres do formato "\<*nome de classe de destino*\>  `Object`".  Se essa função já estiver presente, ele não será adicionado.  Adicione esta função para a classe de destino para retornar um nome mais amigável daquele gerado automaticamente.  
  
-   **GetProgID**, que está relacionado ao registro, retorna a seqüência de caracteres especificado com o  [progid](../Topic/progid.md) atributo.  
  
-   **GetVersionIndependentProgID** tem a mesma funcionalidade que  **GetProgID**, mas ele retorna a seqüência de caracteres especificada com  [vi\_progid](../windows/vi-progid.md).  
  
 São feitas as alterações a seguir, estão relacionadas ao mapa COM, a classe de destino:  
  
-   Um mapa COM é adicionado com entradas para a classe de destino deriva de todas as interfaces e todas as entradas especificadas pela  [COM pontos de entrada de Interface](../mfc/com-interface-entry-points.md) atributo ou aquelas necessárias para o  [agregados](../windows/aggregates.md) atributo.  
  
-   Um  [OBJECT\_ENTRY\_AUTO](../Topic/OBJECT_ENTRY_AUTO.md) macro é inserida no mapa de COM.  Esta macro é semelhante a  [OBJECT\_ENTRY](http://msdn.microsoft.com/pt-br/abd10ee2-54f0-4f94-9ec2-ddf8f4c8c8cd) em termos de funcionalidade, mas não precisa fazer parte do mapa COM da classe destino.  
  
 O nome do coclass gerado no arquivo. idl para a classe terá o mesmo nome da classe.  Por exemplo e se referindo ao exemplo a seguir, para acessar o ID de classe para um coclass CMyClass, em um cliente através do arquivo de cabeçalho gerado pelo MIDL, use CLSID\_CMyClass.  
  
## Exemplo  
 O código a seguir mostra como usar o  **coclass** atributo:  
  
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
  
 O exemplo a seguir mostra como substituir a implementação do padrão de uma função que aparece no código injetado pelo  **coclass** atributo.  Consulte  [\/Fx](../build/reference/fx-merge-injected-code.md) para obter mais informações sobre como exibir o código injetado.  As classes base ou interfaces que você pode usar para uma classe ser aparecerão no código injetado.   Além disso, se uma classe é incluída por padrão no código injetado e você especifica explicitamente essa classe como base para seu coclass, o provedor de atributo usará a forma especificada em seu código.  
  
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
  
## Requisitos  
  
### Contexto de atributo  
  
|||  
|-|-|  
|**Se aplica a**|**classe**,`struct`|  
|**Reproduzíveis**|Não|  
|**Atributos obrigatórios**|Nenhum|  
|**Atributos inválidos**|Nenhum|  
  
 Para obter mais informações sobre os contextos de atributo, consulte  [Atributo contextos](../windows/attribute-contexts.md).  
  
## Consulte também  
 [IDL Attributes](../windows/idl-attributes.md)   
 [COM Attributes](../Topic/COM%20Attributes.md)   
 [Class Attributes](../windows/class-attributes.md)   
 [Typedef, Enum, Union, and Struct Attributes](../windows/typedef-enum-union-and-struct-attributes.md)   
 [appobject](../Topic/appobject.md)