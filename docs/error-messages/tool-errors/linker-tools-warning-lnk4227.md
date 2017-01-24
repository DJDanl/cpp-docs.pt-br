---
title: "Aviso LNK4227 (Ferramentas de Vinculador) | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "error-reference"
f1_keywords: 
  - "LNK4227"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "LNK4227"
ms.assetid: 941a0414-9964-4e02-8487-f9daa42ef7f9
caps.latest.revision: 11
caps.handback.revision: 11
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Aviso LNK4227 (Ferramentas de Vinculador)
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

aviso da operação de metadados \(HRESULT\): warning\_message  
  
 As diferenças detectadas o vinculador de metadados ao mesclar:  
  
-   Um ou mais assemblies referenciados pelo assembly que está sendo que está sendo criado.  
  
-   Um ou mais arquivos de origem em uma compilação.  
  
 Por exemplo, LNK4227 pode ser causado se você tem duas funções globais com as mesmas informações de mas nome do parâmetro declarado de forma diferente \(as instruções não são consistentes em todos os compilands\).  O uso ildasm.exe \/TEXT \/METADATA `object_file` em cada arquivo de .obj e você deve considerar como os tipos forem diferentes.  
  
 LNK4227 também reporta problemas que se originam com outra ferramenta.  Por exemplo, al.exe; consulte [Erros e avisos da ferramenta de Al.exe](http://msdn.microsoft.com/pt-br/7f125d49-0a03-47a6-9ba9-d61a679a7d4b).  
  
 Os problemas de metadados devem ser corrigidos para resolver o aviso.  
  
 Por exemplo, LNK4227 é gerado quando um assembly referenciado foi assinado de modo diferente do assembly que a referencie.  
  
 O seguinte exemplo gera LNK4227:  
  
```  
// LNK4227.cpp  
// compile with: /clr  
using namespace System::Reflection;  
  
[assembly:AssemblyDelaySignAttribute(false)];  
  
int main() {}  
```  
  
 em seguida, e  
  
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
  
 O seguinte exemplo gera LNK4227:  
  
```  
// LNK4227c.cpp  
// compile with: /clr:oldSyntax  
#using <mscorlib.dll>  
using namespace System::Reflection;  
  
[assembly:AssemblyDelaySignAttribute(false)];  
  
int main() {}  
```  
  
 em seguida, e  
  
```  
// LNK4227d.cpp  
// compile with: /clr:oldSyntax LNK4227c.cpp /FeLNK4227d.exe  
#using <mscorlib.dll>  
using namespace System::Reflection;  
using namespace System::Runtime::CompilerServices;  
  
[assembly:AssemblyDelaySignAttribute(true)];  
  
__gc class MyClass  
{  
};  
```  
  
 LNK4227 também pode ser gerado quando os números de versão no formato errado são passados aos atributos do assembly.  “\*” Notação é específica ao AssemblyVersionAttribute.  Para resolver esse aviso, use somente números nos atributos de versão diferentes de AssemblyVersionAttribute.  
  
 O seguinte exemplo gera LNK4227:  
  
```  
// LNK4227e.cpp  
// compile with: /clr /LD /W1  
using namespace System::Reflection;  
[assembly:AssemblyVersionAttribute("2.3.*")];   // OK  
[assembly:AssemblyFileVersionAttribute("2.3.*")];   // LNK4227  
// try the following line instead  
// [assembly:AssemblyFileVersionAttribute("2.3")];  
```