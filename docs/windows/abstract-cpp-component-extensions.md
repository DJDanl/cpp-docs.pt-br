---
title: Resumo (extensões de componentes C++) | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: reference
f1_keywords:
- abstract
- abstract_cpp
dev_langs:
- C++
helpviewer_keywords:
- abstract keyword [C++]
ms.assetid: cbae3408-0378-4ac8-b70d-c016b381a6d5
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: dcaef98df96b54025cd44a52a2e27a7bc5a83545
ms.sourcegitcommit: d55ac596ba8f908f5d91d228dc070dad31cb8360
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/08/2018
---
# <a name="abstract--c-component-extensions"></a>abstrata (Extensões de Componentes C++)
O `abstract` palavra-chave declara um:  
  
-   Um tipo pode ser usado como um tipo base, mas o próprio tipo não pode ser instanciado.  
  
-   Uma função de membro de tipo pode ser definida apenas em um tipo derivado.  
  
## <a name="all-platforms"></a>Todas as Plataformas  
 **Sintaxe**  
  
```  
  
      class-declaration  
      class-identifier  
      abstract {}  
virtualreturn-typemember-function-identifier() abstract ;  
  
```  
  
 **Comentários**  
  
 A primeira sintaxe de exemplo declara uma classe abstrata. O *declaração de classe* componente pode ser uma declaração C++ nativo (`class` ou `struct`), ou uma declaração de extensão do C++ (`ref class` ou `ref struct`) se o **/ZW** ou **/clr** opção de compilador é especificada.  
  
 A segunda sintaxe de exemplo declara uma função membro virtual a ser abstract. Declarando um resumo da função é o mesmo que declarar uma função virtual pura. Declarando um resumo da função de membro também faz com que a classe do delimitador deve ser declarado abstrato.  
  
 O `abstract` palavra-chave é suportada no código nativo e a plataforma específica; ou seja, ele pode ser compilado com ou sem o **/ZW** ou **/clr** opção de compilador.  
  
 Você pode detectar no tempo de compilação se um tipo é abstrato com o `__is_abstract(type)` característica de tipo. Para obter mais informações, consulte [suporte para características do tipo de compilador](../windows/compiler-support-for-type-traits-cpp-component-extensions.md).  
  
 O `abstract` palavra-chave é um especificador de substituição sensível ao contexto. Para obter mais informações sobre palavras-chave contextuais, consulte [sensível ao contexto palavras-chave](../windows/context-sensitive-keywords-cpp-component-extensions.md). Para obter mais informações sobre especificadores de substituição, consulte [como: declarar especificadores de substituição em compilações nativas](../dotnet/how-to-declare-override-specifiers-in-native-compilations-cpp-cli.md).  
  
## <a name="windows-runtime"></a>Tempo de Execução do Windows  
 Para obter mais informações, consulte [classes e estruturas Ref](http://msdn.microsoft.com/library/windows/apps/hh699870.aspx).  
  
### <a name="requirements"></a>Requisitos  
 Opção do compilador: **/ZW**  
  
## <a name="common-language-runtime"></a>Common Language Runtime 
  
### <a name="requirements"></a>Requisitos  
 Opção de compilador: **/clr**  
  
### <a name="examples"></a>Exemplos  
 **Exemplo**  
  
 O exemplo de código a seguir gera um erro porque classe `X` está marcado como `abstract`.  
  
```  
// abstract_keyword.cpp  
// compile with: /clr  
ref class X abstract {  
public:  
   virtual void f() {}  
};  
  
int main() {  
   X ^ MyX = gcnew X;   // C3622  
}  
```  
  
 **Exemplo**  
  
 O exemplo de código a seguir gera um erro porque ele instancia uma classe nativo que está marcado como `abstract`. Este erro ocorre com ou sem o **/clr** opção de compilador.  
  
```  
// abstract_keyword_2.cpp  
class X abstract {  
public:  
   virtual void f() {}  
};  
  
int main() {  
   X * MyX = new X; // C3622: 'X': a class declared as 'abstract'  
                    // cannot be instantiated. See declaration of 'X'}  
  
```  
  
 **Exemplo**  
  
 O exemplo de código a seguir gera um erro porque função `f` inclui uma definição mas está marcado como `abstract`. A instrução final no exemplo mostra que a declarar uma função virtual abstrata é equivalente à declaração de uma função virtual pura.  
  
```  
// abstract_keyword_3.cpp  
// compile with: /clr  
ref class X {  
public:  
   virtual void f() abstract {}   // C3634  
   virtual void g() = 0 {}   // C3634  
};  
```  
  
## <a name="see-also"></a>Consulte também  
 [Extensões de componentes para plataformas de tempo de execução](../windows/component-extensions-for-runtime-platforms.md)