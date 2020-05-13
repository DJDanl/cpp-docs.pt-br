---
title: módulo (Atributo C++ COM)
ms.date: 10/02/2018
f1_keywords:
- vc-attr.module
helpviewer_keywords:
- module attributes
ms.assetid: 02223b2a-62b5-4262-832f-564b1e11e58e
ms.openlocfilehash: 9d4f9e23aaf182e28930ba3a4462b07533ba9015
ms.sourcegitcommit: 7a6116e48c3c11b97371b8ae4ecc23adce1f092d
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/22/2020
ms.locfileid: "81754382"
---
# <a name="module-c"></a>module (C++)

Define o bloco de biblioteca no arquivo .idl.

## <a name="syntax"></a>Sintaxe

```cpp
[ module (type=dll, name=string, version=1.0, uuid=uuid, lcid=integer, control=boolean, helpstring=string, helpstringdll=string, helpfile=string, helpcontext=integer, helpstringcontext=integer, hidden=boolean, restricted=boolean, custom=string, resource_name=string,) ];
```

### <a name="parameters"></a>Parâmetros

*tipo*<br/>
(Opcional) Pode ser um dos seguintes:

- `dll`Adiciona funções e classes que permitem que a DLL resultante funcione como um servidor COM em processo. Esse é o valor padrão.

- `exe`Adiciona funções e classes que permitem que o executável resultante funcione como um servidor COM fora do processo.

- `service`Adiciona funções e classes que permitem que o executável resultante funcione como um serviço NT.

- `unspecified`Desativa a injeção de código ATL relacionada ao atributo do módulo: a injeção da classe ATL Module, _AtlModule de instância global e funções de ponto de entrada. Não desativa a injeção de código ATL devido a outros atributos no projeto.

*name*<br/>
(Opcional) O nome do bloco da biblioteca.

*version*<br/>
(Opcional) O número da versão que você deseja atribuir ao bloco da biblioteca. O valor padrão é 1.0.

*uuid*<br/>
A identificação única da biblioteca. Se você omiti-lo este parâmetro, um ID será gerado automaticamente para a biblioteca. Você pode precisar recuperar o *uuid* do bloco da biblioteca, o que você pode fazer usando o identificador **__uuidof (nome** *da biblioteca).* **)**

*Lcid*<br/>
O parâmetro de localização. Consulte [lcid](/windows/win32/Midl/lcid) para obter mais informações.

*Controle*<br/>
(Opcional) Especifica que todas as coclasses da biblioteca são controles.

*helpstring*<br/>
Especifica a biblioteca do tipo.

*helpstringdll*<br/>
(Opcional) Define o nome do arquivo .dll para usar para executar uma pesquisa de seqüência de seqüência de documentos. Consulte [helpstringdll](/windows/win32/Midl/helpstringdll) para obter mais informações.

*Helpfile*<br/>
(Opcional) O nome do arquivo **Ajuda** para a biblioteca do tipo.

*helpcontext*<br/>
(Opcional) O **ID de ajuda** para esta biblioteca de tipo.

*helpstringcontext*<br/>
(Opcional) Consulte [o helpstringcontext](helpstringcontext.md) para obter mais informações.

*Escondidos*<br/>
(Opcional) Impede que toda a biblioteca seja exibida. Este uso destina-se a ser usado com controles. Os hosts precisam criar uma nova biblioteca de tipos que envolva o controle com propriedades estendidas. Consulte o atributo MIDL [oculto](/windows/win32/Midl/hidden) para obter mais informações.

*Restrito*<br/>
(Opcional) Os membros da biblioteca não podem ser chamados arbitrariamente. Consulte o atributo MIDL [restrito](/windows/win32/Midl/restricted) para obter mais informações.

*Personalizado*<br/>
(Opcional) Um ou mais atributos; isso é semelhante ao atributo [personalizado.](custom-cpp.md) O primeiro parâmetro a *ser personalizado* é o GUID do atributo. Por exemplo:

```
[module(custom={guid,1}, custom={guid1,2})]
```

*Resource_name*<br/>
O ID de recurso de string do arquivo .rgs usado para registrar o ID do APP da DLL, executável ou serviço. Quando o módulo é de serviço de tipo, este argumento também é usado para obter o ID da string que contém o nome do serviço.

> [!NOTE]
> Tanto o arquivo .rgs quanto a string que contém o nome do serviço devem conter o mesmo valor numérico.

## <a name="remarks"></a>Comentários

A menos que você especifique o parâmetro *restrito* para [emitidl,](emitidl.md) **o módulo** é necessário em qualquer programa que use atributos C++.

Um bloco de biblioteca será criado se, além do atributo do **módulo,** o código-fonte também usar [dispinterface](dispinterface.md), [dual](dual.md), [objeto](object-cpp.md)ou um atributo que implique [coclasse](coclass.md).

Um bloco de biblioteca é permitido em um arquivo .idl. Várias entradas de módulo no código-fonte serão mescladas, com os valores de parâmetro mais recentes sendo implementados.

Se esse atributo for usado dentro de um projeto que usa ATL, o comportamento do atributo muda. Além do comportamento acima, o atributo também insere um objeto global (chamado `_AtlModule`) do tipo correto e código de suporte adicional. Se o atributo for autônomo, ele insere uma classe derivada do tipo de módulo correto. Se o atributo for aplicado a uma classe, ele adicionará uma classe base do tipo de módulo correto. O tipo correto é determinado pelo valor do parâmetro de *tipo:*

- `type` = **Dll**

   [O CAtlDllModuleT](../../atl/reference/catldllmodulet-class.md) é usado como a classe base e os pontos de entrada DLL padrão necessários para um servidor COM. Esses pontos de entrada são [DllMain,](/windows/win32/Dlls/dllmain) [DllRegisterServer,](/windows/win32/api/olectl/nf-olectl-dllregisterserver) [DllUnRegisterServer,](/windows/win32/api/olectl/nf-olectl-dllunregisterserver) [DllCanUnloadNow](/windows/win32/api/combaseapi/nf-combaseapi-dllcanunloadnow)e [DllGetClassObject](/windows/win32/api/combaseapi/nf-combaseapi-dllgetclassobject).

- `type` = **Exe**

   [CAtlExeModuleT](../../atl/reference/catlexemodulet-class.md) é usado como a classe base e o ponto de entrada executável padrão [WinMain](/windows/win32/api/winbase/nf-winbase-winmain).

- `type` = **Serviço**

   [CAtlServiceModuleT](../../atl/reference/catlservicemodulet-class.md) é usado como a classe base e o ponto de entrada executável padrão [WinMain](/windows/win32/api/winbase/nf-winbase-winmain).

- `type` = **Unspecified**

   Desativa a injeção de código ATL relacionado ao atributo do módulo.

## <a name="example"></a>Exemplo

O código a seguir mostra como criar um bloco de biblioteca no arquivo .idl gerado.

```cpp
// cpp_attr_ref_module1.cpp
// compile with: /LD
[module(name="MyLibrary", version="1.2", helpfile="MyHelpFile")];
```

O código a seguir mostra que você pode fornecer sua própria implementação de uma função que apareceria no código que foi injetado como resultado do uso do **módulo**. Consulte [/Fx](../../build/reference/fx-merge-injected-code.md) para obter mais informações sobre a visualização do código injetado. Para substituir uma das funções inseridas pelo atributo do **módulo,** faça uma aula que contenha sua implementação da função e faça com que o atributo do **módulo** se aplique a essa classe.

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
|**Aplica-se a**|Onde|
|**Repetível**|Não|
|**Atributos necessários**|Nenhum|
|**Atributos inválidos**|Nenhum|

Para obter mais informações, consulte [Contextos de atributos](cpp-attributes-com-net.md#contexts).

## <a name="see-also"></a>Confira também

[Atributos IDL](idl-attributes.md)<br/>
[Atributos de classe](class-attributes.md)<br/>
[Atributos independentes](stand-alone-attributes.md)<br/>
[Atributos Typedef, Enum, Union e Struct](typedef-enum-union-and-struct-attributes.md)<br/>
[usesgetlasterror](usesgetlasterror.md)<br/>
[Biblioteca](/windows/win32/Midl/library)<br/>
[helpcontext](helpcontext.md)<br/>
[helpstring](helpstring.md)<br/>
[Helpfile](helpfile.md)<br/>
[version](version-cpp.md)
