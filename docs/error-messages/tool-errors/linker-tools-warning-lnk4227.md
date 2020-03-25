---
title: Aviso LNK4227 (Ferramentas de Vinculador)
ms.date: 11/04/2016
f1_keywords:
- LNK4227
helpviewer_keywords:
- LNK4227
ms.assetid: 941a0414-9964-4e02-8487-f9daa42ef7f9
ms.openlocfilehash: 7b75cff4f03370951245bde1b485d538ffdb4007
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80182936"
---
# <a name="linker-tools-warning-lnk4227"></a>Aviso LNK4227 (Ferramentas de Vinculador)

> aviso de operação de metadados (*HRESULT*): *warning_message*

O vinculador detectou diferenças de metadados ao mesclar:

- Um ou mais assemblies referenciados com o assembly que está sendo compilado no momento.

- Um ou mais arquivos de código-fonte em uma compilação.

Por exemplo, LNK4227 pode ser causado se você tiver duas funções globais com o mesmo nome, mas as informações de parâmetro declaradas de forma diferente (ou seja, as declarações não forem consistentes em todos os compilandos). Use ildasm. exe/TEXT/METADATA *object_file* em cada arquivo. obj para ver como os tipos diferem.

O LNK4227 também é usado para relatar problemas originados em outra ferramenta. Procure a mensagem de aviso para obter mais informações.

Os problemas de metadados devem ser corrigidos para resolver o aviso.

## <a name="example"></a>Exemplo

LNK4227 é gerado quando um assembly referenciado foi assinado de forma diferente do assembly que faz referência a ele.

O exemplo a seguir gera LNK4227:

```cpp
// LNK4227.cpp
// compile with: /clr
using namespace System::Reflection;

[assembly:AssemblyDelaySignAttribute(false)];

int main() {}
```

e, em seguida,

```cpp
// LNK4227b.cpp
// compile with: /clr LNK4227.cpp /FeLNK4227b.exe
using namespace System::Reflection;
using namespace System::Runtime::CompilerServices;

[assembly:AssemblyDelaySignAttribute(true)];
// Try the following line instead
// [assembly:AssemblyDelaySignAttribute(false)];

ref class MyClass
{
};
```

## <a name="example"></a>Exemplo

LNK4227 também pode ser gerado quando os números de versão no formato incorreto são passados para atributos de assembly.  A notação ' * ' é específica para o `AssemblyVersionAttribute`.  Para resolver esse aviso, use apenas números nos atributos de versão diferentes de `AssemblyVersionAttribute`.

O exemplo a seguir gera LNK4227:

```cpp
// LNK4227e.cpp
// compile with: /clr /LD /W1
using namespace System::Reflection;
[assembly:AssemblyVersionAttribute("2.3.*")];   // OK
[assembly:AssemblyFileVersionAttribute("2.3.*")];   // LNK4227
// try the following line instead
// [assembly:AssemblyFileVersionAttribute("2.3")];
```
