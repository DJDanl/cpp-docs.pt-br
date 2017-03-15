---
title: "literal (C++ Component Extensions) | Microsoft Docs"
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
  - "literal"
  - "literal_cpp"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "literal keyword [C++]"
ms.assetid: 6b1a1f36-2e1d-4a23-8eb6-172f4f3c477f
caps.latest.revision: 20
caps.handback.revision: 20
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# literal (C++ Component Extensions)
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Uma variável \(membro de dados\) marcada como `literal` em uma compilação de **\/clr** é o equivalente nativo de uma variável de `static const` .  
  
## Todas as Plataformas  
 **Comentários**  
  
 \(Não há nenhum comentário sobre este recurso de linguagem que se aplica a todos os tempos de execução\).  
  
## [!INCLUDE[wrt](../atl/reference/includes/wrt_md.md)]  
 **Comentários**  
  
 \(Não há nenhum comentário sobre este recurso de linguagem que se aplica somente Tempo de Execução do Windows\).  
  
### Requisitos  
 Opção do compilador: **\/ZW**  
  
## Common Language Runtime  
  
## Comentários  
 Um membro de dados marcado como `literal`deve ser inicializado quando declarado e o valor deve ser uma integral, uma enum, ou um tipo constante de cadeia de caracteres.  A conversão do tipo da expressão de inicialização o tipo de membro estático de dados de const não requer uma conversão definido pelo usuário.  
  
 Nenhuma memória alocada para o campo literal em tempo de execução; o compilador insere somente seu valor nos metadados da classe.  
  
 `static const` marcado variável não estará disponível nos metadados para outros compiladores.  
  
 Para obter mais informações, consulte [Estático](../misc/static-cpp.md) e [const](../cpp/const-cpp.md).  
  
 `literal` é uma palavra\-chave contextual.  Consulte [Palavras\-chave Contextuais](../windows/context-sensitive-keywords-cpp-component-extensions.md) para maiores informações.  
  
## Exemplo  
 Este exemplo mostra que uma variável de `literal` implica `static`.  
  
```  
// mcppv2_literal.cpp  
// compile with: /clr  
ref struct X {  
   literal int i = 4;  
};  
  
int main() {  
   int value = X::i;  
}  
```  
  
## Exemplo  
 O exemplo a seguir mostra o efeito do literal nos metadados:  
  
```  
// mcppv2_literal2.cpp  
// compile with: /clr /LD  
public ref struct A {  
   literal int lit = 0;  
   static const int sc = 1;  
};  
```  
  
 Observe a diferença nos metadados de `sc` e `lit`: a política de `modopt` é aplicada a `sc`, o que significa que pode ser ignorada por outros compiladores.  
  
```  
.field public static int32 modopt([mscorlib]System.Runtime.CompilerServices.IsConst) sc = int32(0x0000000A)  
```  
  
```  
.field public static literal int32 lit = int32(0x0000000A)  
```  
  
## Exemplo  
 O exemplo a seguir, criado no C\#, referencia os metadados criados no exemplo anterior e mostra o efeito de `literal` e variáveis de `static const` :  
  
```  
// mcppv2_literal3.cs  
// compile with: /reference:mcppv2_literal2.dll  
// A C# program  
class B {  
   public static void Main() {  
      // OK  
      System.Console.WriteLine(A.lit);  
      System.Console.WriteLine(A.sc);  
  
      // C# does not enforce C++ const  
      A.sc = 9;  
      System.Console.WriteLine(A.sc);  
  
      // C# enforces const for a literal  
      A.lit = 9;   // CS0131  
  
      // you can assign a C++ literal variable to a C# const variable  
      const int i = A.lit;  
      System.Console.WriteLine(i);  
  
      // but you cannot assign a C++ static const variable  
      // to a C# const variable  
      const int j = A.sc;   // CS0133  
      System.Console.WriteLine(j);  
   }  
}  
```  
  
## Requisitos  
 Opção do compilador: **\/clr**  
  
## Consulte também  
 [Component Extensions for Runtime Platforms](../windows/component-extensions-for-runtime-platforms.md)