---
title: "dllexport, dllimport | Microsoft Docs"
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
  - "dllimport_cpp"
  - "dllexport_cpp"
  - "dllexport"
  - "dllimport"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Palavra-chave __declspec [C++], dllexport"
  - "Palavra-chave __declspec [C++], dllimport"
  - "palavra-chave dllexport __declspec"
  - "palavra-chave dllimport __declspec"
ms.assetid: ff95b645-ef55-4e72-b848-df44657b3208
caps.latest.revision: 13
caps.handback.revision: 13
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# dllexport, dllimport
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

**Específico da Microsoft**  
  
 Os atributos de classe de armazenamento `dllexport` e **dllimport** são extensões específicas da Microsoft para as linguagens C e C\+\+.  É possível usá\-las para exportar e importar funções, dados e objetos para ou a partir de um DLL.  
  
## Sintaxe  
  
```  
  
        __declspec( dllimport ) declarator  
__declspec( dllexport ) declarator  
```  
  
## Comentários  
 Esses atributos definem explicitamente a interface da DLL para seu cliente, que pode ser o arquivo executável ou outro DLL.  Declarar funções como `dllexport` elimina a necessidade de um arquivo de definição de módulo \(.def\), pelo menos em relação à especificação de funções exportadas.  O atributo `dllexport` substitui a palavra\-chave `__export`.  
  
 Se uma classe está marcada como declspec \(dllexport\), todas as especializações de modelos de classe na hierarquia de classe são marcadas implicitamente como declspec \(dllexport\).  Isso significa que os modelos de classe são instanciados explicitamente e que os membros da classe devem ser definidos.  
  
 `dllexport` de uma função expõe a função com seu nome decorado.  Para funções em C\+\+, isso inclui a desconfiguração do nome.  Para C ou funções que são declaradas como `extern "C"`, isso inclui decoração de plataforma específica com base na convenção de chamada.  Para obter informações sobre a decoração de nome no código C\/C\+\+, consulte [Nomes decorados](../Topic/Decorated%20Names.md).  Sem decoração de nome é aplicada a funções exportadas do C ou C\+\+ `extern "C"` as funções que usam o `__cdecl` convenção de chamada.  
  
 Para exportar um nome não decorado, você pode vincular usando um arquivo de definição de módulo \(. def\) que define o nome não decorado na seção EXPORTS.  Para obter mais informações, consulte [exportações](../Topic/EXPORTS.md).  Outra maneira de exportar um nome não decorado é usar um `#pragma comment(linker, "/export:``alias``=``decorated_name``")` diretiva no código\-fonte.  
  
 Ao declarar `dllexport` ou **dllimport**, você deve usar [a sintaxe de atributo estendido](../cpp/declspec.md) e a palavra\-chave `__declspec`.  
  
## Exemplo  
  
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
  
-   [Definindo funções embutidas do C\+\+ com dllexport e dllimport](../cpp/defining-inline-cpp-functions-with-dllexport-and-dllimport.md)  
  
-   [Regras e limitações gerais](../cpp/general-rules-and-limitations.md)  
  
-   [Usando o dllimport e o dllexport nas classes do C\+\+](../cpp/using-dllimport-and-dllexport-in-cpp-classes.md)  
  
 **FIM de Específico da Microsoft**  
  
## Consulte também  
 [\_\_declspec](../cpp/declspec.md)   
 [Palavras\-chave C\+\+](../cpp/keywords-cpp.md)