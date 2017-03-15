---
title: "/Zc:rvalueCast (Aplicar regras de convers&#227;o de tipo) | Microsoft Docs"
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
  - "rvaluecast"
  - "/Zc:rvalueCast"
  - "VC.Project.VCCLCompilerTool.EnforceTypeConversionRules"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "opções de compilador /Zc (C++)"
  - "Aplicar regras de conversão de tipo"
  - "rvaluecast"
  - "opções de compilador Zc (C++)"
  - "opções de compilador -Zc (C++)"
ms.assetid: 7825277d-e565-4c48-b0fb-76ac0b0c6e38
caps.latest.revision: 8
caps.handback.revision: 8
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# /Zc:rvalueCast (Aplicar regras de convers&#227;o de tipo)
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Quando a opção **\/Zc:rvalueCast** é especificada, o compilador identifica corretamente um tipo de referência rvalue como resultado de uma operação de conversão de acordo com o padrão C\+\+11.  Quando a opção não está especificada, o comportamento do compilador é o mesmo do Visual Studio 2012.  Por padrão, **\/Zc:rvalueCast** permanece desativado.  Por uma questão de conformidade e para eliminar erros no uso de conversões, recomendamos que você use **\/Zc:rvalueCast**.  
  
## Sintaxe  
  
```  
/Zc:rvalueCast[-]  
```  
  
## Comentários  
 Se **\/Zc:rvalueCast** for especificado, o compilador seguirá a seção 5.4 do padrão C\+\+11 e tratará apenas expressões de conversão que resultem em tipos de não referência e expressões de conversão que resultem em referências rvalue para tipos de não função como tipos rvalue.  Por padrão, ou se **\/Zc:rvalueCast\-** estiver especificado, o compilador não estará em conformidade e tratará todas as expressões de conversão que resultem em referências rvalue como rvalues.  
  
 Use **\/Zc:rvalueCast** caso você passe uma expressão de conversão como argumento para uma função que utilize um rvalue como tipo de referência.  O comportamento padrão causa o erro de compilador [C2664](../../error-messages/compiler-errors-2/compiler-error-c2664.md) quando o compilador determina incorretamente o tipo de expressão de conversão.  O exemplo mostra um erro de compilador no código correto quando \/Zc:rvalueCast não é especificado:  
  
```cpp  
// Test of /Zc:rvalueCast  
// compile by using:  
// cl /c /Zc:rvalueCast- make_thing.cpp  
// cl /c /Zc:rvalueCast make_thing.cpp  
  
#include <utility>  
  
template <typename T>   
struct Thing {  
   // Construct a Thing by using two rvalue reference parameters  
   Thing(T&& t1, T&& t2)  
      : thing1(t1), thing2(t2) {}  
  
   T& thing1;  
   T& thing2;  
};  
  
// Create a Thing, using move semantics if possible  
template <typename T>  
Thing<T> make_thing(T&& t1, T&& t2)  
{  
   return (Thing<T>(std::forward<T>(t1), std::forward<T>(t2)));  
}  
  
struct Test1 {  
   long a;  
   long b;  
  
   Thing<long> test() {   
      // Use identity casts to create rvalues as arguments  
      return make_thing(static_cast<long>(a), static_cast<long>(b));   
   }  
};  
  
```  
  
 Talvez o comportamento do compilador padrão não relate o erro C2102 quando apropriado.  Neste exemplo, o compilador não relatará um erro se o endereço de um rvalue criado por uma conversão de identidade for utilizado quando **\/Zc:rvalueCast** não for especificado:  
  
```cpp  
int main() {  
   int a = 1;  
   int *p = &a;   // Okay, take address of lvalue   
                  // Identity cast creates rvalue from lvalue;    
   p = &(int)a;   // problem: should cause C2102: '&' requires l-value  
}  
```  
  
 Para obter mais informações sobre problemas de conformidade no Visual C\+\+, consulte [Comportamento não padrão](../Topic/Nonstandard%20Behavior.md).  
  
### Para definir esta opção do compilador no ambiente de desenvolvimento do Visual Studio  
  
1.  Abra a caixa de diálogo **Páginas de Propriedades** do projeto.  Para obter detalhes, consulte [Trabalhando com propriedades do projeto](../../ide/working-with-project-properties.md).  
  
2.  Selecione a pasta **C\/C\+\+**.  
  
3.  Selecione a página de propriedades de **Linha de Comando**.  
  
4.  Modifique a propriedade **Opções Adicionais** para incluir **\/Zc:rvalueCast** e escolha **OK**.  
  
## Consulte também  
 [\/Zc \(conformidade\)](../../build/reference/zc-conformance.md)