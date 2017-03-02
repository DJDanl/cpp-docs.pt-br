---
title: Aviso LNK4227 das ferramentas de vinculador | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- LNK4227
dev_langs:
- C++
helpviewer_keywords:
- LNK4227
ms.assetid: 941a0414-9964-4e02-8487-f9daa42ef7f9
caps.latest.revision: 11
author: corob-msft
ms.author: corob
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
translationtype: Machine Translation
ms.sourcegitcommit: c243063a9770542f137d5950e8a269f771960f74
ms.openlocfilehash: ee566318c7d19159f9a2c084d348b5010a65e2de
ms.lasthandoff: 02/25/2017

---
# <a name="linker-tools-warning-lnk4227"></a>Aviso LNK4227 (Ferramentas de Vinculador)
Aviso de operação de metadados (HRESULT): warning_message  
  
O vinculador detectou diferenças de metadados durante a mesclagem:  
  
-   Um ou mais assemblies referenciados com o assembly que está sendo criado no momento.  
  
-   Um ou mais arquivos de código fonte em uma compilação.  
  
Por exemplo, LNK4227 pode ser causado se você tiver duas funções globais com o mesmo nome mas informações de parâmetro declarado de forma diferente (declarações não são consistentes em todos os compilandos). Use ildasm.exe /TEXT /METADATA `object_file` em cada obj arquivo e você verá como os tipos são diferentes.  
  
LNK4227 também relata problemas que se originam em outra ferramenta. Por exemplo, al.exe; consulte [Al.exe Tool Errors and Warnings](http://msdn.microsoft.com/en-us/7f125d49-0a03-47a6-9ba9-d61a679a7d4b).  
  
Os problemas de metadados devem ser corrigidos para resolver o aviso.  
  
Por exemplo, LNK4227 é gerado quando um assembly referenciado foi assinado diferente do assembly que faz referência a ele.  
  
O exemplo a seguir gera LNK4227:  
  
```  
// LNK4227.cpp  
// compile with: /clr  
using namespace System::Reflection;  
  
[assembly:AssemblyDelaySignAttribute(false)];  
  
int main() {}  
```  
  
 e, em seguida,  
  
```  
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
  
LNK4227 também podem ser gerados quando os números de versão no formato errado são passados para atributos de assembly.  O ' *' notação é específica para AssemblyVersionAttribute.  Para resolver esse aviso, use apenas os números nos atributos de versão diferente AssemblyVersionAttribute.  
  
O exemplo a seguir gera LNK4227:  
  
```  
// LNK4227e.cpp  
// compile with: /clr /LD /W1  
using namespace System::Reflection;  
[assembly:AssemblyVersionAttribute("2.3.*")];   // OK  
[assembly:AssemblyFileVersionAttribute("2.3.*")];   // LNK4227  
// try the following line instead  
// [assembly:AssemblyFileVersionAttribute("2.3")];  
```
