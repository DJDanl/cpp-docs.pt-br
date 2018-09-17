---
title: módulo (C++) | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: reference
f1_keywords:
- vc-attr.module
dev_langs:
- C++
helpviewer_keywords:
- module attributes
ms.assetid: 02223b2a-62b5-4262-832f-564b1e11e58e
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: ac443927c2dcbb00cc01dd3cd63a95441a4a1bf0
ms.sourcegitcommit: 92f2fff4ce77387b57a4546de1bd4bd464fb51b6
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/17/2018
ms.locfileid: "45711787"
---
# <a name="module-c"></a>module (C++)

Define o bloco de biblioteca no arquivo. idl.

## <a name="syntax"></a>Sintaxe

```cpp
[ module (
   type=dll,
   name=string,
   version=1.0,
   uuid=uuid,
   lcid=integer,
   control=boolean,
   helpstring=string,
   helpstringdll=string,
   helpfile=string,
   helpcontext=integer,
   helpstringcontext=integer,
   hidden=boolean,
   restricted=boolean,
   custom=string,
   resource_name=string,
) ];
```

### <a name="parameters"></a>Parâmetros

*type*  
(Opcional) Pode ser uma das seguintes opções:

- `dll` Adiciona funções e classes que permitem que a DLL resultante funcionar como um servidor de COM em processo. Este é o valor padrão.

- `exe` Adiciona funções e classes que permitem resultante executável para funcionarem como um limite de servidor COM de processo.

- `service` Adiciona funções e classes que permitem resultante executável para funcionarem como um serviço NT.

- `unspecified` Desabilita a injeção de código de ATL relacionado ao atributo de módulo: funções de ponto a injeção de classe de módulo ATL, _AtlModule de instância global e entrada. Não desabilite a injeção de código de ATL devido a outros atributos no projeto.

*name*  
(Opcional) O nome do bloco de biblioteca.

*version*  
(Opcional) O número de versão que você deseja atribuir ao bloco de biblioteca. O valor padrão é 1.0.

*uuid*  
A ID exclusiva para a biblioteca. Se você omitir esse parâmetro, uma ID será gerada automaticamente para a biblioteca. Talvez você precise recuperar o *uuid* de seu bloco de biblioteca, que pode ser feito usando o identificador **uuidof (** *libraryname* **)**.

*lcid*  
O parâmetro de localização. Ver [lcid](/windows/desktop/Midl/lcid) para obter mais informações.

*control*  
(Opcional) Especifica que todas as coclasses na biblioteca de controles.

*helpstring*  
Especifica a biblioteca de tipos.

*helpstringdll*  
(Opcional) Define o nome do arquivo. dll para usar para executar uma pesquisa de cadeia de caracteres do documento. Ver [helpstringdll](/windows/desktop/Midl/helpstringdll) para obter mais informações.

*helpfile*  
(Opcional) O nome da **ajudar** arquivo da biblioteca de tipos.

*helpcontext*  
(Opcional) O **identificação ajuda** para esta biblioteca de tipos.

*helpstringcontext*  
(Opcional) Ver [helpstringcontext](../windows/helpstringcontext.md) para obter mais informações.

*hidden*  
(Opcional) Impede que a biblioteca inteira seja exibido. Esse uso destina-se para uso com controles. Hosts precisam criar uma nova biblioteca de tipo que encapsula o controle com propriedades estendidas. Consulte a [ocultos](/windows/desktop/Midl/hidden) atributo MIDL para obter mais informações.

*restricted*  
(Opcional) Membros da biblioteca não podem ser chamados arbitrariamente. Consulte a [restrito](/windows/desktop/Midl/restricted) atributo MIDL para obter mais informações.

*custom*  
(Opcional) Um ou mais atributos; Isso é semelhante a [personalizado](../windows/custom-cpp.md) atributo. O primeiro parâmetro para *personalizado* é o GUID do atributo. Por exemplo:

```
[module(custom={guid,1}, custom={guid1,2})]
```

*resource_name*  
A ID de recurso de cadeia de caracteres do arquivo. rgs usado para registrar a ID do aplicativo da DLL, executável ou de serviço. Quando o módulo é do tipo serviço, esse argumento também é usado para obter a ID da cadeia de caracteres que contém o nome do serviço.

> [!NOTE]
> O arquivo. rgs e a cadeia de caracteres que contém o nome do serviço devem conter o mesmo valor numérico.

## <a name="remarks"></a>Comentários

A menos que você especifique o *restrito* parâmetro [emitidl](../windows/emitidl.md), **módulo** é necessária em qualquer programa que usa atributos de C++.

Um bloco de biblioteca será criado se, além de **módulo** atributo, código-fonte também usa [dispinterface](../windows/dispinterface.md), [duplo](../windows/dual.md), [objeto](../windows/object-cpp.md), ou um atributo que implica [coclass](../windows/coclass.md).

Um bloco de biblioteca é permitido em um arquivo. idl. Várias entradas do módulo no código-fonte serão mescladas com os valores de parâmetro mais recentes que está sendo implementados.

Se esse atributo for usado em um projeto que usa ATL, altera o comportamento do atributo. Além do comportamento acima, o atributo também insere um objeto global (chamado `_AtlModule`) do tipo correto e código de suporte adicionais. Se o atributo for autônomo, ele insere uma classe derivada do tipo de módulo correto. Se o atributo é aplicado a uma classe, ele adiciona uma classe base do tipo de módulo correto. O tipo correto é determinado pelo valor de *tipo* parâmetro:

- `type` = **DLL**

   [CAtlDllModuleT](../atl/reference/catldllmodulet-class.md) é usado como a classe base e a entrada DLL padrão pontos necessários para um servidor COM. Esses pontos de entrada são [DllMain](/windows/desktop/Dlls/dllmain), [DllRegisterServer](https://msdn.microsoft.com/library/windows/desktop/ms682162), [DllUnRegisterServer](https://msdn.microsoft.com/library/windows/desktop/ms691457), [DllCanUnloadNow](/windows/desktop/api/combaseapi/nf-combaseapi-dllcanunloadnow), e [ DllGetClassObject](https://msdn.microsoft.com/library/windows/desktop/dd797891).

- `type` = **exe**

   [CAtlExeModuleT](../atl/reference/catlexemodulet-class.md) é usado como a classe base e o ponto de entrada executável padrão [WinMain](https://msdn.microsoft.com/library/windows/desktop/ms633559).

- `type` = **Serviço**

   [CAtlServiceModuleT](../atl/reference/catlservicemodulet-class.md) é usado como a classe base e o ponto de entrada executável padrão [WinMain](https://msdn.microsoft.com/library/windows/desktop/ms633559).

- `type` = **não especificado**

   Desabilita a injeção de código de ATL relacionado ao atributo de módulo.

## <a name="example"></a>Exemplo

O código a seguir mostra como criar um bloco de biblioteca no arquivo. idl gerado.

```cpp
// cpp_attr_ref_module1.cpp
// compile with: /LD
[module(name="MyLibrary", version="1.2", helpfile="MyHelpFile")];
```

O código a seguir mostra que você pode fornecer sua própria implementação de uma função que apareceria no código que foi inserido como resultado do uso **módulo**. Ver [/Fx](../build/reference/fx-merge-injected-code.md) para obter mais informações sobre como exibir o código injetado. Para substituir uma das funções inseridas pela **módulo** atributo, tornar uma classe que conterá a implementação da função e verifique o **módulo** atributo se aplica a essa classe.

```cpp
// cpp_attr_ref_module2.cpp
// compile with: /LD /link /OPT:NOREF
#include <atlbase.h>
#include <atlcom.h>
#include <atlwin.h>
#include <atltypes.h>
#include <atlctl.h>
#include <atlhost.h>
#include <atlplus.h>

// no semicolon after attribute block
[module(dll, name="MyLibrary", version="1.2", helpfile="MyHelpFile")]
// module attribute now applies to this class
class CMyClass {
public:
BOOL WINAPI DllMain(DWORD dwReason, LPVOID lpReserved) {
   // add your own code here
   return __super::DllMain(dwReason, lpReserved);
   }
};
```

## <a name="requirements"></a>Requisitos

### <a name="attribute-context"></a>Atributo de contexto

|||
|-|-|
|**Aplica-se a**|Em qualquer lugar|
|**Repetível**|Não|
|**Atributos obrigatórios**|Nenhum|
|**Atributos inválidos**|Nenhum|

Para obter mais informações, consulte [contextos de atributo](../windows/attribute-contexts.md).

## <a name="see-also"></a>Consulte também

[Atributos de IDL](../windows/idl-attributes.md)  
[Atributos de classe](../windows/class-attributes.md)  
[Atributos independentes](../windows/stand-alone-attributes.md)  
[Atributos Typedef, Enum, Union e Struct](../windows/typedef-enum-union-and-struct-attributes.md)  
[usesgetlasterror](../windows/usesgetlasterror.md)  
[Biblioteca](/windows/desktop/Midl/library)  
[helpcontext](../windows/helpcontext.md)  
[helpstring](../windows/helpstring.md)  
[helpfile](../windows/helpfile.md)  
[version](../windows/version-cpp.md)  