---
title: "literal (extensões de componentes C++) | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: language-reference
f1_keywords:
- literal
- literal_cpp
dev_langs:
- C++
helpviewer_keywords:
- literal keyword [C++]
ms.assetid: 6b1a1f36-2e1d-4a23-8eb6-172f4f3c477f
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: f858e94bf916c2d441cee607739bb9e08da09b85
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="literal-c-component-extensions"></a>literal (Extensões de Componentes C++)
Uma variável (membro de dados) é marcada como `literal` em uma **/clr** compilação é o equivalente nativo um `static const` variável.  
  
## <a name="all-platforms"></a>Todas as Plataformas  
 **Comentários**  
  
 (Não há nenhum comentários para esse recurso de idioma que se aplicam a todos os tempos de execução).  
  
## <a name="windows-runtime"></a>Tempo de Execução do Windows  
 **Comentários**  
  
 (Não há nenhum comentários para esse recurso de idioma que se aplicam somente no tempo de execução do Windows).  
  
### <a name="requirements"></a>Requisitos  
 Opção do compilador: **/ZW**  
  
## <a name="common-language-runtime"></a>Common Language Runtime  
  
## <a name="remarks"></a>Comentários  
 Um membro de dados marcado como `literal` devem ser inicializados quando declarados e o valor deve ser uma constante integral, enum ou tipo de cadeia de caracteres. Conversão do tipo da expressão de inicialização para o tipo do estático const-membro de dados não deve exigir uma conversão definida pelo usuário.  
  
 Nenhuma memória é alocada para o campo literal em tempo de execução; o compilador só insere seu valor nos metadados para a classe.  
  
 Uma variável marcada `static const` não estarão disponíveis nos metadados para outros compiladores.  
  
 Para obter mais informações, consulte [estático](../cpp/storage-classes-cpp.md) e [const](../cpp/const-cpp.md).  
  
 `literal`é uma palavra-chave contextual. Consulte [sensível ao contexto palavras-chave](../windows/context-sensitive-keywords-cpp-component-extensions.md) para obter mais informações.  
  
## <a name="example"></a>Exemplo  
 Este exemplo mostra que uma `literal` variável implica `static`.  
  
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
  
## <a name="example"></a>Exemplo  
 O exemplo a seguir mostra o efeito da literal em metadados:  
  
```  
// mcppv2_literal2.cpp  
// compile with: /clr /LD  
public ref struct A {  
   literal int lit = 0;  
   static const int sc = 1;  
};  
```  
  
 Observe a diferença nos metadados do `sc` e `lit`: o `modopt` diretiva é aplicada a `sc`, que significa que ela pode ser ignorado por outros compiladores.  
  
```  
.field public static int32 modopt([mscorlib]System.Runtime.CompilerServices.IsConst) sc = int32(0x0000000A)  
```  
  
```  
.field public static literal int32 lit = int32(0x0000000A)  
```  
  
## <a name="example"></a>Exemplo  
 O exemplo a seguir, criado em c#, faz referência o metadados criado no exemplo anterior e mostra o efeito das `literal` e `static const` variáveis:  
  
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
  
## <a name="requirements"></a>Requisitos  
 Opção de compilador: **/clr**  
  
## <a name="see-also"></a>Consulte também  
 [Extensões de componentes para plataformas de tempo de execução](../windows/component-extensions-for-runtime-platforms.md)