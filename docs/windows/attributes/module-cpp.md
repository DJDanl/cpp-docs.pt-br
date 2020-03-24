---
title: módulo (C++ atributo com)
ms.date: 10/02/2018
f1_keywords:
- vc-attr.module
helpviewer_keywords:
- module attributes
ms.assetid: 02223b2a-62b5-4262-832f-564b1e11e58e
ms.openlocfilehash: e93073a1728063038ddd4e28dbb313854ee3c8c5
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80166686"
---
# <a name="module-c"></a>module (C++)

Define o bloco de biblioteca no arquivo. idl.

## <a name="syntax"></a>Sintaxe

```cpp
[ module (type=dll, name=string, version=1.0, uuid=uuid, lcid=integer, control=boolean, helpstring=string, helpstringdll=string, helpfile=string, helpcontext=integer, helpstringcontext=integer, hidden=boolean, restricted=boolean, custom=string, resource_name=string,) ];
```

### <a name="parameters"></a>parâmetros

*tipo*<br/>
Adicional Pode ser um dos seguintes:

- `dll` adiciona funções e classes que permitem que a DLL resultante funcione como um servidor COM em processo. Esse é o valor padrão.

- `exe` adiciona funções e classes que permitem que o executável resultante funcione como um servidor COM fora do processo.

- `service` adiciona funções e classes que permitem que o executável resultante funcione como um serviço NT.

- `unspecified` desabilita a injeção de código ATL relacionada ao atributo de módulo: a injeção de classe de módulo ATL, _AtlModule de instância global e funções de ponto de entrada. Não desabilita a injeção de código ATL devido a outros atributos no projeto.

*name*<br/>
Adicional O nome do bloco de biblioteca.

*version*<br/>
Adicional O número de versão que você deseja atribuir ao bloco de biblioteca. O valor padrão é 1.0.

*uuid*<br/>
A ID exclusiva da biblioteca. Se você omitir esse parâmetro, uma ID será gerada automaticamente para a biblioteca. Talvez seja necessário recuperar o *UUID* do seu bloco de biblioteca, que pode ser feito usando o identificador **__uuidof (** *LibraryName* **)** .

*lcid*<br/>
O parâmetro de localização. Consulte [LCID](/windows/win32/Midl/lcid) para obter mais informações.

*control*<br/>
Adicional Especifica que todas as coclasses na biblioteca são controles.

*helpstring*<br/>
Especifica a biblioteca de tipos.

*helpstringdll*<br/>
Adicional Define o nome do arquivo. dll a ser usado para executar uma pesquisa de cadeia de caracteres de documento. Consulte [helpstringdll](/windows/win32/Midl/helpstringdll) para obter mais informações.

*helpfile*<br/>
Adicional O nome do arquivo de **ajuda** para a biblioteca de tipos.

*helpcontext*<br/>
Adicional A **ID da ajuda** para esta biblioteca de tipos.

*helpstringcontext*<br/>
Adicional Consulte [helpstringcontext](helpstringcontext.md) para obter mais informações.

*hidden*<br/>
Adicional Impede que toda a biblioteca seja exibida. Esse uso destina-se ao uso com controles. Os hosts precisam criar uma nova biblioteca de tipos que encapsula o controle com propriedades estendidas. Consulte o atributo MIDL [oculto](/windows/win32/Midl/hidden) para obter mais informações.

*restricted*<br/>
Adicional Os membros da biblioteca não podem ser chamados arbitrariamente. Consulte o atributo MIDL [restrito](/windows/win32/Midl/restricted) para obter mais informações.

*custom*<br/>
Adicional Um ou mais atributos; Isso é semelhante ao atributo [personalizado](custom-cpp.md) . O primeiro parâmetro para *personalizado* é o GUID do atributo. Por exemplo:

```
[module(custom={guid,1}, custom={guid1,2})]
```

*resource_name*<br/>
A ID de recurso da cadeia de caracteres do arquivo. rgs usado para registrar a ID do aplicativo da DLL, do executável ou do serviço. Quando o módulo é do tipo serviço, esse argumento também é usado para obter a ID da cadeia de caracteres que contém o nome do serviço.

> [!NOTE]
> O arquivo. rgs e a cadeia de caracteres que contém o nome do serviço devem conter o mesmo valor numérico.

## <a name="remarks"></a>Comentários

A menos que você especifique o parâmetro *Restricted* para [emitidl](emitidl.md), o **módulo** é necessário em qualquer C++ programa que usa atributos.

Um bloco de biblioteca será criado se, além do atributo de **módulo** , o código-fonte também usar [dispinterface](dispinterface.md), [Dual](dual.md), [Object](object-cpp.md)ou um atributo que implica [coclass](coclass.md).

Um bloco de biblioteca é permitido em um arquivo. idl. Várias entradas de módulo no código-fonte serão mescladas, com os valores de parâmetro mais recentes sendo implementados.

Se esse atributo for usado em um projeto que usa ATL, o comportamento do atributo será alterado. Além do comportamento acima, o atributo também insere um objeto global (chamado `_AtlModule`) do tipo correto e o código de suporte adicional. Se o atributo for autônomo, ele inserirá uma classe derivada do tipo de módulo correto. Se o atributo for aplicado a uma classe, ele adicionará uma classe base do tipo de módulo correto. O tipo correto é determinado pelo valor do parâmetro de *tipo* :

- `type` = **dll**

   [CAtlDllModuleT](../../atl/reference/catldllmodulet-class.md) é usado como a classe base e os pontos de entrada padrão da dll necessários para um servidor com. Esses pontos de entrada são [DllMain](/windows/win32/Dlls/dllmain), [DllRegisterServer](/windows/win32/api/olectl/nf-olectl-dllregisterserver), [DllUnregisterServer](/windows/win32/api/olectl/nf-olectl-dllunregisterserver), [DllCanUnloadNow](/windows/win32/api/combaseapi/nf-combaseapi-dllcanunloadnow)e [DllGetClassObject](/previous-versions//dd797891\(v=vs.85\)).

- `type` = **exe**

   [CAtlExeModuleT](../../atl/reference/catlexemodulet-class.md) é usado como a classe base e o ponto de entrada executável padrão [WinMain](/windows/win32/api/winbase/nf-winbase-winmain).

- **serviço** de  = `type`

   [CAtlServiceModuleT](../../atl/reference/catlservicemodulet-class.md) é usado como a classe base e o ponto de entrada executável padrão [WinMain](/windows/win32/api/winbase/nf-winbase-winmain).

- `type` = **não especificado**

   Desabilita a injeção de código ATL relacionada ao atributo de módulo.

## <a name="example"></a>Exemplo

O código a seguir mostra como criar um bloco de biblioteca no arquivo. idl gerado.

```cpp
// cpp_attr_ref_module1.cpp
// compile with: /LD
[module(name="MyLibrary", version="1.2", helpfile="MyHelpFile")];
```

O código a seguir mostra que você pode fornecer sua própria implementação de uma função que apareceria no código que foi injetado como resultado do uso do **módulo**. Consulte [/FX](../../build/reference/fx-merge-injected-code.md) para obter mais informações sobre como exibir código injetado. Para substituir uma das funções inseridas pelo atributo de **módulo** , crie uma classe que conterá sua implementação da função e faça com que o atributo de **módulo** se aplique a essa classe.

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

### <a name="attribute-context"></a>Contexto de atributo

|||
|-|-|
|**Aplica-se a**|Lugares|
|**Repetível**|Não|
|**Atributos necessários**|Nenhum|
|**Atributos inválidos**|Nenhum|

Para obter mais informações, consulte [contextos de atributo](cpp-attributes-com-net.md#contexts).

## <a name="see-also"></a>Confira também

[Atributos de IDL](idl-attributes.md)<br/>
[Atributos de classe](class-attributes.md)<br/>
[Atributos independentes](stand-alone-attributes.md)<br/>
[Atributos Typedef, Enum, Union e Struct](typedef-enum-union-and-struct-attributes.md)<br/>
[usesgetlasterror](usesgetlasterror.md)<br/>
[biblioteca](/windows/win32/Midl/library)<br/>
[helpcontext](helpcontext.md)<br/>
[helpstring](helpstring.md)<br/>
[helpfile](helpfile.md)<br/>
[version](version-cpp.md)
