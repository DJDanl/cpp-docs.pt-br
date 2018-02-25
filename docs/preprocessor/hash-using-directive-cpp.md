---
title: '#Diretiva using (C + + CLR) | Microsoft Docs'
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- friend_as_cpp
- '#using'
- friend_as
- '#using_cpp'
dev_langs:
- C++
helpviewer_keywords:
- using directive (#using)
- '#using directive'
- LIBPATH environment variable
- preprocessor, directives
ms.assetid: 870b15e5-f361-40a8-ba1c-c57d75c8809a
caps.latest.revision: 
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: a1c43acde6e4f755c6757fc933c80091ba05927c
ms.sourcegitcommit: d51ed21ab2b434535f5c1d553b22e432073e1478
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/23/2018
---
# <a name="using-directive-cclr"></a># Diretiva using (C + + CLR)
Importa os metadados para um programa compilado com [/clr](../build/reference/clr-common-language-runtime-compilation.md).  
  
## <a name="syntax"></a>Sintaxe  
  
```  
#using file [as_friend]  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `file`  
 Um MSIL .dll, .exe, .netmodule ou .obj. Por exemplo,  
  
 `#using <MyComponent.dll>`  
  
 as_friend  
 Especifica que todos os tipos em `file` são acessíveis.  Para obter mais informações, consulte [Friend Assemblies (C++)](../dotnet/friend-assemblies-cpp.md).  
  
## <a name="remarks"></a>Comentários  
 `file` pode ser um arquivo de linguagem intermediária da Microsoft (MSIL) que você importa para seus dados gerenciados e construções gerenciadas. Se um arquivo. dll contém um manifesto do assembly, todos os. DLLs referenciados no manifesto são importados e o assembly que você está criando listará *arquivo* nos metadados como uma referência de assembly.  
  
 Se `file` não contém um assembly (se `file` é um módulo) e se você não pretende usar informações do tipo do módulo no aplicativo atual (assembly), você tem a opção de apenas indicando que o módulo faz parte do assembly; use [/ASSEMBLYMODULE](../build/reference/assemblymodule-add-a-msil-module-to-the-assembly.md). Então, os tipos no módulo estariam disponíveis para qualquer aplicativo que fizesse referência ao assembly.  
  
 Uma alternativa para usar `#using` é o [/FU](../build/reference/fu-name-forced-hash-using-file.md) opção de compilador.  
  
 assemblies .exe passado para `#using` deve ser compilada usando um dos compiladores .NET Visual Studio (Visual Basic ou Visual c#, por exemplo).  Tentativa de importar metadados de um assembly de .exe compilado com **/clr** resultará em uma exceção ao carregar o arquivo.  
  
> [!NOTE]
>  Um componente que é referenciado com `#using` pode ser executado com outra versão do arquivo importado no tempo de compilação, fazendo com que um aplicativo cliente gere resultados inesperados.  
  
 Para que o compilador reconheça um tipo em um assembly (não um módulo), ele precisa ser forçado a resolver o tipo, que você pode fazer, por exemplo, definindo uma instância do tipo. Há outras maneiras de resolver nomes de tipo em um assembly para o compilador, por exemplo, se você herda de um tipo em um assembly, o nome do tipo se tornará, então, conhecido do compilador.  
  
 Ao importar metadados criado a partir de código-fonte usada [__declspec(thread)](../cpp/thread.md), a semântica de thread não é mantida nos metadados. Por exemplo, uma variável declarada com **__declspec(thread)**, compilado em um programa que é compilado para o .NET Framework common language runtime e, em seguida, importados por meio de `#using`, não terá mais **declspec ( thread)** semântica na variável.  
  
 Todos os tipos importados (gerenciados e nativos) em um arquivo referenciado por `#using` estão disponíveis, mas o compilador tratará os tipos nativos como declarações, não como definições.  
  
 mscorlib é referenciado automaticamente ao compilar com **/clr**.  
  
 A variável de ambiente LIBPATH especifica os diretórios que serão pesquisados quando o compilador tentar resolver os nomes de arquivo transmitidos para `#using`.  
  
 O compilador pesquisará referências ao longo do seguinte caminho:  
  
-   Um caminho especificado na instrução `#using`.  
  
-   O diretório atual.  
  
-   O diretório do sistema do .NET Framework.  
  
-   Diretórios adicionados com o [/AI](../build/reference/ai-specify-metadata-directories.md) opção de compilador.  
  
-   Diretórios na variável de ambiente LIBPATH.  
  
## <a name="example"></a>Exemplo  
 Se você criar um assembly (C) e fizer referência a um assembly (B) que faz referência a outro assembly (A), não terá que fazer referência explicitamente ao assembly A, a menos que use explicitamente um dos tipos de A em C.  
  
```  
// using_assembly_A.cpp  
// compile with: /clr /LD  
public ref class A {};  
```  
  
## <a name="example"></a>Exemplo  
  
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
  
## <a name="example"></a>Exemplo  
 No exemplo a seguir, não há erros do compilador por não fazer referência usando _assembly_A.dll, pois o programa não usa nenhum dos tipos definidos no uso de _assembly_A.cpp.  
  
```  
// using_assembly_C.cpp  
// compile with: /clr  
#using "using_assembly_B.dll"  
int main() {  
   B b;  
   b.Test();  
}  
```  
  
## <a name="see-also"></a>Consulte também  
 [Diretivas do pré-processador](../preprocessor/preprocessor-directives.md)