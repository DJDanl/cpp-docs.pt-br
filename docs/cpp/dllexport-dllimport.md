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
ms.openlocfilehash: f03c945375cbe8c399e604e12f070b5a63d316f7
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87221647"
---
# <a name="dllexport-dllimport"></a>dllexport, dllimport

**Específico da Microsoft**

O **`dllexport`** e os **`dllimport`** atributos de classe de armazenamento são extensões específicas da Microsoft para as linguagens C e C++. É possível usá-las para exportar e importar funções, dados e objetos para ou a partir de um DLL.

## <a name="syntax"></a>Sintaxe

```
   __declspec( dllimport ) declarator
   __declspec( dllexport ) declarator
```

## <a name="remarks"></a>Comentários

Esses atributos definem explicitamente a interface da DLL para seu cliente, que pode ser o arquivo executável ou outro DLL. A declaração de funções como **`dllexport`** elimina a necessidade de um arquivo de definição de módulo (. def), pelo menos em relação à especificação de funções exportadas. O **`dllexport`** atributo substitui a palavra-chave **__export** .

Se uma classe está marcada como declspec (dllexport), todas as especializações de modelos de classe na hierarquia de classe são marcadas implicitamente como declspec (dllexport). Isso significa que os modelos de classe são instanciados explicitamente e que os membros da classe devem ser definidos.

**`dllexport`** de uma função expõe a função com seu nome decorado. Para funções em C++, isso inclui a desconfiguração do nome. Para funções ou funções C declaradas como `extern "C"` , isso inclui a decoração específica da plataforma com base na Convenção de chamada. Para obter informações sobre a decoração de nome no código C/C++, consulte [nomes decorados](../build/reference/decorated-names.md). Nenhuma decoração de nome é aplicada às funções C exportadas ou às `extern "C"` funções C++ usando a **`__cdecl`** Convenção de chamada.

Para exportar um nome não decorado, você pode vincular usando um arquivo de definição de módulo (. def) que define o nome não decorado em uma seção exportações. Para obter mais informações, consulte [exportações](../build/reference/exports.md). Outra maneira de exportar um nome não decorado é usar uma `#pragma comment(linker, "/export:alias=decorated_name")` diretiva no código-fonte.

Ao declarar **`dllexport`** ou **`dllimport`** , você deve usar a [sintaxe de atributo estendido](../cpp/declspec.md) e a **`__declspec`** palavra-chave.

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

- [Definindo funções C++ embutidas com dllexport e DllImport](../cpp/defining-inline-cpp-functions-with-dllexport-and-dllimport.md)

- [Regras e limitações gerais](../cpp/general-rules-and-limitations.md)

- [Usando DllImport e dllexport em classes C++](../cpp/using-dllimport-and-dllexport-in-cpp-classes.md)

**FINAL específico da Microsoft**

## <a name="see-also"></a>Confira também

[__declspec](../cpp/declspec.md)<br/>
[Palavras-chave](../cpp/keywords-cpp.md)
