---
title: literal (extensões de componentes C++) | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: reference
f1_keywords:
- literal
- literal_cpp
dev_langs:
- C++
helpviewer_keywords:
- literal keyword [C++]
ms.assetid: 6b1a1f36-2e1d-4a23-8eb6-172f4f3c477f
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 78dda3c52192b0d2755bdc8f8944eb0e1443e7af
ms.sourcegitcommit: 4586bfc32d8bc37ab08b24816d7fad5df709bfa3
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/07/2018
ms.locfileid: "39604168"
---
# <a name="literal-c-component-extensions"></a>literal (Extensões de Componentes C++)
Uma variável (membro de dados) marcado como **literal** em um **/clr** a compilação é o equivalente nativo de uma **const estático** variável.  
  
## <a name="all-platforms"></a>Todas as Plataformas  
### <a name="remarks"></a>Comentários 
  
 (Não há nenhum comentário sobre este recurso de linguagem que se aplicam a todos os tempos de execução.)  
  
## <a name="windows-runtime"></a>Tempo de Execução do Windows  
### <a name="remarks"></a>Comentários 
  
 (Não há nenhum comentário sobre este recurso de linguagem que se aplicam a apenas o tempo de execução do Windows.)  
  
### <a name="requirements"></a>Requisitos  
 Opção do compilador: `/ZW`  
  
## <a name="common-language-runtime"></a>Common Language Runtime  
  
## <a name="remarks"></a>Comentários  
 Um membro de dados marcado como **literal** devem ser inicializados quando declarados e o valor deve ser uma constante integral, enum ou tipo de cadeia de caracteres. Conversão do tipo da expressão de inicialização para o tipo do const dados-membro estático não deve exigir uma conversão definida pelo usuário.  
  
 Nenhuma memória é alocada para o campo literal em tempo de execução; o compilador insere apenas seu valor nos metadados para a classe.  
  
 Uma variável marcados **const estático** não estarão disponíveis nos metadados para outros compiladores.  
  
 Para obter mais informações, consulte [estáticos](../cpp/storage-classes-cpp.md) e [const](../cpp/const-cpp.md).  
  
 **literal** é uma palavra-chave contextual. Ver [contextual as palavras-chave](../windows/context-sensitive-keywords-cpp-component-extensions.md) para obter mais informações.  
  
## <a name="example"></a>Exemplo  
 Este exemplo mostra que um **literal** variável implica **estático**.  
  
```cpp  
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
 O exemplo a seguir mostra o efeito das literal nos metadados:  
  
```cpp  
// mcppv2_literal2.cpp  
// compile with: /clr /LD  
public ref struct A {  
   literal int lit = 0;  
   static const int sc = 1;  
};  
```  
  
 Observe a diferença nos metadados para `sc` e `lit`: o `modopt` diretiva é aplicada a `sc`, que significa que ele pode ser ignorado por outros compiladores.  
  
```  
.field public static int32 modopt([mscorlib]System.Runtime.CompilerServices.IsConst) sc = int32(0x0000000A)  
```  
  
```  
.field public static literal int32 lit = int32(0x0000000A)  
```  
  
## <a name="example"></a>Exemplo  
 O exemplo a seguir, criado no c#, faz referência o metadados criado no exemplo anterior e mostra o efeito das **literal** e **const estático** variáveis:  
  
```cs  
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
 Opção do compilador: `/clr`  
  
## <a name="see-also"></a>Consulte também  
 [Extensões de componentes para plataformas de tempo de execução](../windows/component-extensions-for-runtime-platforms.md)