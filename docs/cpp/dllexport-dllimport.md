---
title: dllexport, dllimport | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-language
ms.tgt_pltfrm: 
ms.topic: language-reference
f1_keywords:
- dllimport_cpp
- dllexport_cpp
- dllexport
- dllimport
dev_langs:
- C++
helpviewer_keywords:
- dllexport __declspec keyword
- __declspec keyword [C++], dllexport
- dllimport __declspec keyword
- __declspec keyword [C++], dllimport
ms.assetid: ff95b645-ef55-4e72-b848-df44657b3208
caps.latest.revision: 13
author: mikeblome
ms.author: mblome
manager: ghogen
translation.priority.ht:
- cs-cz
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- pl-pl
- pt-br
- ru-ru
- tr-tr
- zh-cn
- zh-tw
ms.translationtype: HT
ms.sourcegitcommit: 6ffef5f51e57cf36d5984bfc43d023abc8bc5c62
ms.openlocfilehash: 029f5b915b71395f81ada2e2174eafeb59230443
ms.contentlocale: pt-br
ms.lasthandoff: 09/25/2017

---
# <a name="dllexport-dllimport"></a>dllexport, dllimport
**Seção específica da Microsoft**  
  
 O `dllexport` e **dllimport** atributos de classe de armazenamento são extensões específicas da Microsoft para as linguagens C e C++. É possível usá-las para exportar e importar funções, dados e objetos para ou a partir de um DLL.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
  
      __declspec( dllimport ) declarator  
__declspec( dllexport ) declarator  
```  
  
## <a name="remarks"></a>Comentários  
 Esses atributos definem explicitamente a interface da DLL para seu cliente, que pode ser o arquivo executável ou outro DLL. Declarar funções como `dllexport` elimina a necessidade de um arquivo de definição de módulo (.def), pelo menos em relação à especificação de funções exportadas. O atributo `dllexport` substitui a palavra-chave `__export`.  
  
 Se uma classe está marcada como declspec (dllexport), todas as especializações de modelos de classe na hierarquia de classe são marcadas implicitamente como declspec (dllexport). Isso significa que os modelos de classe são instanciados explicitamente e que os membros da classe devem ser definidos.  
  
 `dllexport` de uma função expõe a função com seu nome decorado. Para funções em C++, isso inclui a desconfiguração do nome. Para funções de C ou funções que são declaradas como `extern "C"`, isso inclui a decoração de específico de plataforma que é baseada na convenção de chamada. Para obter informações sobre a decoração de nome no código C/C++, consulte [nomes decorados](../build/reference/decorated-names.md). Sem decoração do nome é aplicada a funções exportadas de C ou C++ `extern "C"` funções usando o `__cdecl` convenção de chamada.  
  
 Para exportar um nome não decorado, você pode vincular usando um arquivo de definição de módulo (. def) que define o nome não decorado em uma seção de exportações. Para obter mais informações, consulte [exportações](../build/reference/exports.md). Outra maneira de exportar um nome não decorado é usar um `#pragma comment(linker, "/export:alias=decorated_name")` diretiva no código-fonte.  
  
 Quando você declara `dllexport` ou **dllimport**, você deve usar [estendido a sintaxe do atributo](../cpp/declspec.md) e `__declspec` palavra-chave.  
  
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
 [declspec](../cpp/declspec.md)   
 [Palavras-chave](../cpp/keywords-cpp.md)
