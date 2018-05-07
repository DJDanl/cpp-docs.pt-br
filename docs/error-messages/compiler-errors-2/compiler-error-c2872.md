---
title: C2872 de erro do compilador | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C2872
dev_langs:
- C++
helpviewer_keywords:
- C2872
ms.assetid: c619ef97-6e0e-41d7-867c-f8d28a07d553
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 636f263382c41806e04c50c0770340305a3013ce
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="compiler-error-c2872"></a>C2872 de erro do compilador
'*símbolo*': símbolo ambíguo  
  
O compilador não pode determinar o símbolo que você está referenciando. Mais de um símbolo com o nome especificado está no escopo. Consulte as notas de mensagem de erro para os locais de arquivo e as declarações a seguir o compilador encontrado para o símbolo ambíguo. Para corrigir esse problema, você pode qualificar totalmente o símbolo ambíguo usando seu namespace, por exemplo, `std::byte` ou `::byte`. Você também pode usar um [alias de namespace](../../cpp/namespaces-cpp.md#namespace_aliases) para dar um nome curto conveniente para uso de um namespace incluído quando desambiguação símbolos no seu código-fonte.  
  
C2872 pode ocorrer se um arquivo de cabeçalho inclui um [usando diretiva](../../cpp/namespaces-cpp.md#using_directives), e um arquivo de cabeçalho subsequente é incluído que contém um tipo que é também o namespace especificado no `using` diretiva. Especifique um `using` diretiva somente depois de todos os arquivos de cabeçalho são especificados com `#include`.  
  
 Para obter mais informações sobre C2872, consulte os artigos da Base de dados de Conhecimento [PRB: compilador erros quando você usar #import com XML no Visual C++ .NET](http://support.microsoft.com/kb/316317) e ["C2872 de erro: 'Platform': símbolo ambíguo" mensagem de erro quando você usar o Namespace Windows::Foundation::Metadata no Visual Studio 2013](https://support.microsoft.com/kb/2890859).  
  
## <a name="example"></a>Exemplo  
 O exemplo a seguir gera C2872, como uma referência ambígua é feita a uma variável chamada `i`; duas variáveis com o mesmo nome estão no escopo:  
  
```cpp  
// C2872.cpp  
// compile with: cl /EHsc C2872.cpp  
namespace A {  
   int i;  
}  
  
using namespace A;  
int i;  
int main() {  
   ::i++;   // ok, uses i from global namespace  
   A::i++;   // ok, uses i from namespace A  
   i++;   // C2872 ambiguous: ::i or A::i? 
   // To fix this issue, use the fully qualified name
   // for the intended variable. 
}  
```