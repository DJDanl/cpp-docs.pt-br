---
title: "Diretiva #using (C++) | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
f1_keywords: 
  - "friend_as_cpp"
  - "#using"
  - "friend_as"
  - "#using_cpp"
dev_langs: 
  - "C++"
  - "C"
helpviewer_keywords: 
  - "Diretiva #using"
  - "variável de ambiente LIBPATH"
  - "pré-processador, Diretivas ()"
  - "diretiva using (#using)"
ms.assetid: 870b15e5-f361-40a8-ba1c-c57d75c8809a
caps.latest.revision: 17
caps.handback.revision: 17
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Diretiva #using (C++)
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Importa metadados para um programa compilado com [\/clr](../build/reference/clr-common-language-runtime-compilation.md).  
  
## Sintaxe  
  
```  
#using file [as_friend]  
```  
  
#### Parâmetros  
 `file`  
 Um MSIL .dll, .exe, .netmodule ou .obj.  Por exemplo,  
  
 `#using <MyComponent.dll>`  
  
 as\_friend  
 Especifica que todos os tipos em `file` são acessíveis.  Para obter mais informações, consulte [Assemblies amigáveis \(C\+\+\)](../dotnet/friend-assemblies-cpp.md).  
  
## Comentários  
 `file` pode ser um arquivo de linguagem intermediária da Microsoft \(MSIL\) que você importa para seus dados gerenciados e construções gerenciadas.  Se um arquivo .dll contém um manifesto do assembly, todos os .dlls referenciados no manifesto são importados, e o assembly que você está criando listará o *arquivo* dos metadados como uma referência de assembly.  
  
 Se `file` não contém um assembly \(se `file` é um módulo\) e se você não quer usar as informações de tipo do módulo no aplicativo atual \(assembly\), pode apenas indicar que o módulo faz parte do assembly; use [\/ASSEMBLYMODULE](../build/reference/assemblymodule-add-a-msil-module-to-the-assembly.md).  Então, os tipos no módulo estariam disponíveis para qualquer aplicativo que fizesse referência ao assembly.  
  
 Uma alternativa ai uso de `#using` é a opção de compilador [\/FU](../build/reference/fu-name-forced-hash-using-file.md).  
  
 os assemblies de .exe transmitidos para `#using` devem ser compilados com **\/clr:safe** ou **\/clr:pure** ou com qualquer um dos outros compiladores do Visual Studio \(Visual Basic ou Visual C\#, por exemplo\).  Tentar importar metadados de um assembly .exe compilado com **\/clr** resultará em uma exceção de carregamento de arquivo.  
  
> [!NOTE]
>  Um componente que é referenciado com `#using` pode ser executado com outra versão do arquivo importado no tempo de compilação, fazendo com que um aplicativo cliente gere resultados inesperados.  
  
 Para que o compilador reconheça um tipo em um assembly \(não um módulo\), ele precisa ser forçado a resolver o tipo, que você pode fazer, por exemplo, definindo uma instância do tipo.  Há outras maneiras de resolver nomes de tipo em um assembly para o compilador, por exemplo, se você herda de um tipo em um assembly, o nome do tipo se tornará, então, conhecido do compilador.  
  
 Ao importar metadados criados a partir do código\-fonte que usou [\_\_declspec \(thread\)](../cpp/thread.md), a semântica de thread não persiste nos metadados.  Por exemplo, uma variável declarada com **\_\_declspec\(thread\)**, compilada em um programa que é criado para o .NET Framework Common Language Runtime e, então, importada via `#using` não terá mais a semântica de **\_\_declspec\(thread\)** na variável.  
  
 Todos os tipos importados \(gerenciados e nativos\) em um arquivo referenciado por `#using` estão disponíveis, mas o compilador tratará os tipos nativos como declarações, não como definições.  
  
 mscorlib.dll é referenciado automaticamente durante a compilação com **\/clr**.  
  
 A variável de ambiente LIBPATH especifica os diretórios que serão pesquisados quando o compilador tentar resolver os nomes de arquivo transmitidos para `#using`.  
  
 O compilador pesquisará referências ao longo do seguinte caminho:  
  
-   Um caminho especificado na instrução `#using`.  
  
-   O diretório atual.  
  
-   O diretório do sistema do .NET Framework.  
  
-   Diretórios adicionados com a opção de compilador [\/AI](../build/reference/ai-specify-metadata-directories.md).  
  
-   Diretórios na variável de ambiente LIBPATH.  
  
## Exemplo  
 Se você criar um assembly \(C\) e fizer referência a um assembly \(B\) que faz referência a outro assembly \(A\), não terá que fazer referência explicitamente ao assembly A, a menos que use explicitamente um dos tipos de A em C.  
  
```  
// using_assembly_A.cpp  
// compile with: /clr /LD  
public ref class A {};  
```  
  
## Exemplo  
  
```  
// using_assembly_B.cpp  
// compile with: /clr /LD  
#using "using_assembly_A.dll"  
public ref class B {  
public:  
   void Test(A a) {}  
   void Test() {}  
};  
  
```  
  
## Exemplo  
 No exemplo a seguir, não há erros do compilador por não fazer referência usando \_assembly\_A.dll, pois o programa não usa nenhum dos tipos definidos no uso de \_assembly\_A.cpp.  
  
```  
// using_assembly_C.cpp  
// compile with: /clr  
#using "using_assembly_B.dll"  
int main() {  
   B b;  
   b.Test();  
}  
```  
  
## Consulte também  
 [Diretivas de pré\-processador](../preprocessor/preprocessor-directives.md)