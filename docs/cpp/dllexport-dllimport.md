---
title: dllexport, dllimport | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-language
ms.topic: language-reference
f1_keywords:
- dllimport_cpp
- dllexport_cpp
dev_langs:
- C++
helpviewer_keywords:
- dllexport __declspec keyword
- __declspec keyword [C++], dllexport
- dllimport __declspec keyword
- __declspec keyword [C++], dllimport
ms.assetid: ff95b645-ef55-4e72-b848-df44657b3208
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: f21256ca78a4bf5f268c4fa3d03c86bc52c91670
ms.sourcegitcommit: 51f804005b8d921468775a0316de52ad39b77c3e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/02/2018
ms.locfileid: "39461670"
---
# <a name="dllexport-dllimport"></a>dllexport, dllimport
**Seção específica da Microsoft**  
  
 O **dllexport** e **dllimport** atributos de classe de armazenamento são extensões específicas da Microsoft para as linguagens C e C++. É possível usá-las para exportar e importar funções, dados e objetos para ou a partir de um DLL.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
   __declspec( dllimport ) declarator  
   __declspec( dllexport ) declarator  
```  
  
## <a name="remarks"></a>Comentários  
 Esses atributos definem explicitamente a interface da DLL para seu cliente, que pode ser o arquivo executável ou outro DLL. Declarar funções como **dllexport** elimina a necessidade de um arquivo de definição de módulo (. def), pelo menos em relação à especificação de funções exportadas. O **dllexport** atributo substitui a **export** palavra-chave.  
  
 Se uma classe está marcada como declspec (dllexport), todas as especializações de modelos de classe na hierarquia de classe são marcadas implicitamente como declspec (dllexport). Isso significa que os modelos de classe são instanciados explicitamente e que os membros da classe devem ser definidos.  
  
 **dllexport** de uma função expõe a função com seu nome decorado. Para funções em C++, isso inclui a desconfiguração do nome. Para funções de C ou funções que são declaradas como `extern "C"`, isso inclui decoração de plataforma específica com base na convenção de chamada. Para obter informações sobre a decoração de nome no código C/C++, consulte [nomes decorados](../build/reference/decorated-names.md). Sem decoração de nome é aplicada a funções exportadas de C ou C++ `extern "C"` as funções que usam o `__cdecl` convenção de chamada.  
  
 Para exportar um nome não decorado, você pode vincular usando um arquivo de definição de módulo (. def) que define o nome não decorado em uma seção de exportações. Para obter mais informações, consulte [exportações](../build/reference/exports.md). Outra maneira de exportar um nome não decorado é usar um `#pragma comment(linker, "/export:alias=decorated_name")` diretiva no código-fonte.  
  
 Quando você declara **dllexport** ou **dllimport**, você deve usar [sintaxe de atributo estendida](../cpp/declspec.md) e o **declspec** palavra-chave.  
  
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
  
-   [Definições e declarações](../cpp/definitions-and-declarations-cpp.md)  
  
-   [Definindo funções C++ embutidas com dllexport e dllimport](../cpp/defining-inline-cpp-functions-with-dllexport-and-dllimport.md)  
  
-   [Regras e limitações gerais](../cpp/general-rules-and-limitations.md)  
  
-   [Usando dllimport e dllexport em classes do C++](../cpp/using-dllimport-and-dllexport-in-cpp-classes.md)  
  
**Fim da seção específica da Microsoft**  
  
## <a name="see-also"></a>Consulte também  
 [__declspec](../cpp/declspec.md)   
 [Palavras-chave](../cpp/keywords-cpp.md)