---
title: dllexport, dllimport
ms.date: 11/04/2016
f1_keywords:
- dllimport_cpp
- dllexport_cpp
helpviewer_keywords:
- dllexport __declspec keyword
- __declspec keyword [C++], dllexport
- dllimport __declspec keyword
- __declspec keyword [C++], dllimport
ms.assetid: ff95b645-ef55-4e72-b848-df44657b3208
ms.openlocfilehash: 0a8d90770552b8b9ab9169378289108d91811216
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80189449"
---
# <a name="dllexport-dllimport"></a>dllexport, dllimport

**Seção específica da Microsoft**

Os atributos de classe de armazenamento **dllexport** e **DllImport** são extensões específicas da Microsoft para o C C++ e idiomas. É possível usá-las para exportar e importar funções, dados e objetos para ou a partir de um DLL.

## <a name="syntax"></a>Sintaxe

```
   __declspec( dllimport ) declarator
   __declspec( dllexport ) declarator
```

## <a name="remarks"></a>Comentários

Esses atributos definem explicitamente a interface da DLL para seu cliente, que pode ser o arquivo executável ou outro DLL. A declaração de funções como **dllexport** elimina a necessidade de um arquivo de definição de módulo (. def), pelo menos em relação à especificação de funções exportadas. O atributo **dllexport** substitui a palavra-chave **__export** .

Se uma classe está marcada como declspec (dllexport), todas as especializações de modelos de classe na hierarquia de classe são marcadas implicitamente como declspec (dllexport). Isso significa que os modelos de classe são instanciados explicitamente e que os membros da classe devem ser definidos.

**dllexport** de uma função expõe a função com seu nome decorado. Para funções em C++, isso inclui a desconfiguração do nome. Para funções ou funções C declaradas como `extern "C"`, isso inclui a decoração específica da plataforma com base na Convenção de chamada. Para obter informações sobre decoração de nome emC++ C/Code, consulte [nomes decorados](../build/reference/decorated-names.md). Nenhuma decoração de nome é aplicada às funções C exportadas ou C++ `extern "C"` funções usando a Convenção de chamada `__cdecl`.

Para exportar um nome não decorado, você pode vincular usando um arquivo de definição de módulo (. def) que define o nome não decorado em uma seção exportações. Para obter mais informações, consulte [exportações](../build/reference/exports.md). Outra maneira de exportar um nome não decorado é usar uma diretiva `#pragma comment(linker, "/export:alias=decorated_name")` no código-fonte.

Ao declarar **dllexport** ou **DllImport**, você deve usar a [sintaxe de atributo estendido](../cpp/declspec.md) e a palavra-chave **__declspec** .

## <a name="example"></a>Exemplo

```cpp
// Example of the dllimport and dllexport class attributes
__declspec( dllimport ) int i;
__declspec( dllexport ) void func();
```

Como alternativa, para tornar seu código mais legível, você pode usar definições de macro:

```cpp
#define DllImport   __declspec( dllimport )
#define DllExport   __declspec( dllexport )

DllExport void func();
DllExport int i = 10;
DllImport int j;
DllExport int n;
```

Para obter mais informações, consulte:

- [Definições e declarações](../cpp/definitions-and-declarations-cpp.md)

- [Definindo funções C++ embutidas com dllexport e dllimport](../cpp/defining-inline-cpp-functions-with-dllexport-and-dllimport.md)

- [Regras e limitações gerais](../cpp/general-rules-and-limitations.md)

- [Usando dllimport e dllexport em classes do C++](../cpp/using-dllimport-and-dllexport-in-cpp-classes.md)

**Fim da seção específica da Microsoft**

## <a name="see-also"></a>Confira também

[__declspec](../cpp/declspec.md)<br/>
[Palavras-chave](../cpp/keywords-cpp.md)
