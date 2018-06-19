---
title: Aviso LNK4227 das ferramentas de vinculador | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- LNK4227
dev_langs:
- C++
helpviewer_keywords:
- LNK4227
ms.assetid: 941a0414-9964-4e02-8487-f9daa42ef7f9
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 4b56617ee355654dfbb198252ea37cdb344950cf
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33302104"
---
# <a name="linker-tools-warning-lnk4227"></a>Aviso LNK4227 (Ferramentas de Vinculador)  
  
> Aviso de operação de metadados (*HRESULT*): *warning_message*  
  
O vinculador detectou diferenças de metadados ao mesclar:  
  
-   Um ou mais assemblies referenciados com assembly que está sendo criado.  
  
-   Um ou mais arquivos de código fonte uma compilação.  
  
Por exemplo, LNK4227 pode ocorrer se você tiver duas funções globais com o mesmo nome, mas as informações de parâmetro declarado de forma diferente (ou seja, declarações não são consistentes em todos os compilandos). Use ildasm.exe /TEXT /METADATA *object_file* em cada arquivo. obj para ver como os tipos são diferentes.  
  
LNK4227 também é usado para relatar problemas que se originam em outra ferramenta. Procure a mensagem de aviso para obter mais informações.  
  
Os problemas de metadados devem ser corrigidos para resolver o aviso.  
  
## <a name="example"></a>Exemplo  
  
LNK4227 é gerado quando um assembly referenciado foi assinado diferente do assembly que faz referência a ele.  
  
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
  
LNK4227 também podem ser gerados quando os números de versão no formato errado são passados para os atributos de assembly.  O ' *' notação é específica para o `AssemblyVersionAttribute`.  Para resolver este aviso, use apenas números em um dos atributos de versão diferente de `AssemblyVersionAttribute`.  
  
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