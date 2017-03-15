---
title: "Platform, default, and cli Namespaces  (C++ Component Extensions) | Microsoft Docs"
ms.custom: ""
ms.date: "12/16/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "language-reference"
f1_keywords: 
  - "lang"
  - "cli"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "lang namespace"
  - "cli namespace"
ms.assetid: 9d38bd1e-dc78-47d1-a84b-9b4683e52c9c
caps.latest.revision: 19
caps.handback.revision: 19
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Platform, default, and cli Namespaces  (C++ Component Extensions)
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Um namespace qualifica os nomes dos elementos da linguagem para que os nomes não entrem em conflito com nomes idênticos em outras áreas do código\-fonte.  Por exemplo, uma colisão de nomes pode impedir que o compilador reconhecer [Palavras\-chave Contextuais](../windows/context-sensitive-keywords-cpp-component-extensions.md).  Os namespaces são usados pelo compilador, mas não preservados no assembly compilado.  
  
## Todos os Tempos de Execução  
 O Visual C\+\+ fornece um namespace padrão para seu projeto quando o projeto é criado.  Você pode renomear manualmente o namespace, ainda que no [!INCLUDE[wrt](../atl/reference/includes/wrt_md.md)] o nome do arquivo .winmd deva corresponder ao nome do namespace raiz.  
  
## [!INCLUDE[wrt](../atl/reference/includes/wrt_md.md)]  
 Para obter mais informações, consulte [Namespaces e visibilidade de tipos \(C \+ c\+\+ \/CX\)](http://msdn.microsoft.com/library/windows/apps/hh969551.aspx).  
  
### Requisitos  
 Opção do compilador: **\/ZW**  
  
## [!INCLUDE[clr_for_headings](../dotnet/includes/clr_for_headings_md.md)]  
 **Sintaxe**  
  
```  
using namespace cli;  
```  
  
 **Observações**  
  
 A [!INCLUDE[cppcli](../build/reference/includes/cppcli_md.md)] oferece suporte ao namespace `cli`.  Para compilar com **\/clr**, a instrução `using` na seção Syntax é implícita.  
  
 Os seguintes recursos de linguagem estão no namespace `cli`:  
  
-   [Arrays](../windows/arrays-cpp-component-extensions.md)  
  
-   [interior\_ptr \(C\+\+\/CLI\)](../windows/interior-ptr-cpp-cli.md)  
  
-   [pin\_ptr \(C\+\+\/CLI\)](../Topic/pin_ptr%20\(C++-CLI\).md)  
  
-   [safe\_cast](../windows/safe-cast-cpp-component-extensions.md)  
  
### Requisitos  
 Opção do compilador: **\/clr**  
  
### Exemplos  
 **Exemplo**  
  
 O exemplo de código a seguir demonstra que é possível usar um símbolo no namespace `cli` como um símbolo definido pelo usuário em seu código.  No entanto, assim que tiver feito isso, você terá que qualificar explícita ou implicitamente suas referências para o elemento de linguagem `cli` de mesmo nome.  
  
```  
// cli_namespace.cpp  
// compile with: /clr  
using namespace cli;  
int main() {  
   array<int> ^ MyArray = gcnew array<int>(100);  
   int array = 0;  
  
   array<int> ^ MyArray2 = gcnew array<int>(100);   // C2062  
  
   // OK  
   cli::array<int> ^ MyArray2 = gcnew cli::array<int>(100);  
   ::array<int> ^ MyArray3 = gcnew ::array<int>(100);  
}  
```  
  
## Consulte também  
 [Component Extensions for Runtime Platforms](../windows/component-extensions-for-runtime-platforms.md)