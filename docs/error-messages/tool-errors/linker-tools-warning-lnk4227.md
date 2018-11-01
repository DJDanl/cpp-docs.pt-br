---
title: Aviso LNK4227 (Ferramentas de Vinculador)
ms.date: 11/04/2016
f1_keywords:
- LNK4227
helpviewer_keywords:
- LNK4227
ms.assetid: 941a0414-9964-4e02-8487-f9daa42ef7f9
ms.openlocfilehash: fb657719c69445ce23d36ccf04ac4a14db0955e4
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50558256"
---
# <a name="linker-tools-warning-lnk4227"></a>Aviso LNK4227 (Ferramentas de Vinculador)

> Aviso da operação de metadados (*HRESULT*): *warning_message*

O vinculador detectou diferenças de metadados durante a mesclagem:

- Um ou mais assemblies referenciados com o assembly sendo criado.

- Um ou mais arquivos de código fonte em uma compilação.

Por exemplo, LNK4227 pode ser causado se você tiver duas funções globais com o mesmo nome mas com informações de parâmetro declarado de forma diferente (ou seja, as declarações não são consistentes em todos os compilandos). Use ildasm.exe chave /TEXT /METADATA *object_file* em cada arquivo. obj para ver como os tipos forem diferentes.

LNK4227 também é usado para relatar problemas que se originam em outra ferramenta. Procure a mensagem de aviso para obter mais informações.

Os problemas de metadados devem ser corrigidos para resolver o aviso.

## <a name="example"></a>Exemplo

LNK4227 é gerado quando um assembly referenciado foi assinado de forma diferente do que o assembly que faz referência a ele.

O exemplo a seguir gera LNK4227:

```cpp
// LNK4227.cpp
// compile with: /clr
using namespace System::Reflection;

[assembly:AssemblyDelaySignAttribute(false)];

int main() {}
```

E, em seguida,

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

LNK4227 também podem ser gerados quando os números de versão no formato errado são passados para os atributos de assembly.  O ' *' notation é específico para o `AssemblyVersionAttribute`.  Para resolver este aviso, use somente os números nos atributos de versão diferente de `AssemblyVersionAttribute`.

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