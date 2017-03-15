---
title: "functional (STL/CLR) | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "reference"
f1_keywords: 
  - "<cliext/functional>"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Cabeçalho &lt;cliext/functional&gt; [STL/CLR]"
  - "Cabeçalho &lt;functional&gt; [STL/CLR]"
  - "funções funcionais [STL/CLR]"
ms.assetid: 88738b8c-5d37-4375-970e-a4442bf5efde
caps.latest.revision: 16
caps.handback.revision: 16
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# functional (STL/CLR)
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Inclui o cabeçalho `<cliext/functional>` de STL\/CLR para definir um número classes de modelo e delegados relacionados e funções do modelo.  
  
## Sintaxe  
  
```  
#include <functional>  
```  
  
## Declarações  
  
|Delegate|Descrição|  
|--------------|---------------|  
|[binary\_delegate](../Topic/binary_delegate%20\(STL-CLR\).md)|Delegado de dois argumentos.|  
|[binary\_delegate\_noreturn](../dotnet/binary-delegate-noreturn-stl-clr.md)|Delegado de dois argumentos que retorna `void`.|  
|[unary\_delegate](../dotnet/unary-delegate-stl-clr.md)|Delegação de um argumento.|  
|[unary\_delegate\_noreturn](../dotnet/unary-delegate-noreturn-stl-clr.md)|Delegação de um argumento que retorna `void`.|  
  
|Classe|Descrição|  
|------------|---------------|  
|[binary\_negate](../dotnet/binary-negate-stl-clr.md)|Funtor para negar um funtor de dois argumentos.|  
|[binder1st](../dotnet/binder1st-stl-clr.md)|Funtor para associar o primeiro argumento para um funtor de dois argumentos.|  
|[binder2nd](../Topic/binder2nd%20\(STL-CLR\).md)|Funtor para associar o segundo argumento para um funtor de dois argumentos.|  
|[divides](../dotnet/divides-stl-clr.md)|Funtor de divisão.|  
|[equal\_to](../dotnet/equal-to-stl-clr.md)|Funtor igual de comparação.|  
|[greater](../dotnet/greater-stl-clr.md)|Maior funtor de comparação.|  
|[greater\_equal](../Topic/greater_equal%20\(STL-CLR\).md)|Maior ou igual funtor de comparação.|  
|[less](../dotnet/less-stl-clr.md)|O menos funtor de comparação.|  
|[less\_equal](../dotnet/less-equal-stl-clr.md)|Menor ou igual funtor de comparação.|  
|[logical\_and](../dotnet/logical-and-stl-clr.md)|Funtor AND lógica.|  
|[logical\_not](../dotnet/logical-not-stl-clr.md)|NOT funtor lógico.|  
|[logical\_or](../Topic/logical_or%20\(STL-CLR\).md)|Funtor OR lógico.|  
|[minus](../dotnet/minus-stl-clr.md)|Subtrai o funtor.|  
|[módulo](../dotnet/modulus-stl-clr.md)|Funtor do módulo.|  
|[multiplies](../Topic/multiplies%20\(STL-CLR\).md)|Multiplique o funtor.|  
|[negate](../Topic/negate%20\(STL-CLR\).md)|Funtor para retornar o argumento negado.|  
|[not\_equal\_to](../dotnet/not-equal-to-stl-clr.md)|Funtor diferente de comparação.|  
|[plus](../dotnet/plus-stl-clr.md)|Adicionar o funtor.|  
|[unary\_negate](../dotnet/unary-negate-stl-clr.md)|Funtor para negar um funtor de um argumento.|  
  
|Função|Descrição|  
|------------|---------------|  
|[bind1st](../dotnet/bind1st-stl-clr.md)|Gerencie um binder1st para um argumento e um funtor.|  
|[bind2nd](../dotnet/bind2nd-stl-clr.md)|Gerencie um binder2nd para um argumento e um funtor.|  
|[not1](../dotnet/not1-stl-clr.md)|Gerencie um unary\_negate para um funtor.|  
|[not1](../dotnet/not1-stl-clr.md)|Gerencie um binary\_negate para um funtor.|  
  
## Requisitos  
 cliext \<de**Cabeçalho:** \/funcional\>  
  
 cliext de**Namespace:**  
  
## Consulte também  
 [Biblioteca STL\/CLR](../dotnet/stl-clr-library-reference.md)