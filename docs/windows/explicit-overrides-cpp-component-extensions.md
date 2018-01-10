---
title: "Substituições explícitas (extensões de componentes C++) | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: language-reference
dev_langs: C++
helpviewer_keywords: overriding, override [C++]
ms.assetid: 4ec3eaf5-163b-4df8-8f16-7a2ec04c3d0f
caps.latest.revision: "21"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 346dd73952934d514b2741c41d5a27816b7152ac
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="explicit-overrides--c-component-extensions"></a>Substituições explícitas (Extensões de componente C++)
Este tópico discute como substituir explicitamente um membro de uma classe base ou interface. Uma substituição (explícita) nomeada só deve ser usada para substituir um método com um método derivado que tem um nome diferente.  
  
## <a name="all-runtimes"></a>Todos os Tempos de Execução  
 **Sintaxe**  
  
```  
  
      overriding-function-declarator = type::function [,type::function] { overriding-function-definition }  
overriding-function-declarator = function { overriding-function-definition }  
```  
  
 **Parâmetros**  
  
 *Declarador de substituição de função*  
 A lista de argumento, nome e tipo de retorno da função de substituição.  Observe que a função de substituição não precisa ter o mesmo nome que a função que está sendo substituído.  
  
 *type*  
 O tipo base que contém uma função para substituir.  
  
 *function*  
 Uma lista delimitada por vírgulas de um ou mais nomes de função para substituir.  
  
 *definição de substituição de função*  
 As instruções de corpo de função que definem a função de substituição.  
  
 **Comentários**  
  
 Use explícita substituições para criar um alias para uma assinatura de método ou para fornecer diferentes implementações de métodos witht a mesma assinatura.  
  
 Para obter informações sobre como modificar o comportamento de tipos herdados e membros de tipo herdado, consulte [especificadores de substituição](../windows/override-specifiers-cpp-component-extensions.md).  
  
## <a name="windows-runtime"></a>Tempo de Execução do Windows  
  
### <a name="requirements"></a>Requisitos  
 Opção do compilador: **/ZW**  
  
## <a name="common-language-runtime"></a>Common Language Runtime 
 **Comentários**  
  
 Para obter informações sobre explícita substituem em código nativo ou código compilado com **/CLR: oldSyntax**, consulte [substituições explícitas](../cpp/explicit-overrides-cpp.md).  
  
### <a name="requirements"></a>Requisitos  
 Opção de compilador: **/clr**  
  
### <a name="examples"></a>Exemplos  
 **Exemplo**  
  
 O exemplo de código a seguir mostra um simple, implícita substituição e implementação de um membro em uma interface base, não usando substituições explícitas.  
  
```  
// explicit_override_1.cpp  
// compile with: /clr  
interface struct I1 {  
   virtual void f();  
};  
  
ref class X : public I1 {  
public:  
   virtual void f() {  
      System::Console::WriteLine("X::f override of I1::f");  
   }  
};  
  
int main() {  
   I1 ^ MyI = gcnew X;  
   MyI -> f();  
}  
```  
  
 **Saída**  
  
```Output  
X::f override of I1::f  
```  
  
 **Exemplo**  
  
 O exemplo de código a seguir mostra como implementar todos os membros de interface com uma assinatura comuns, usando a sintaxe de substituição explícita.  
  
```  
  
// explicit_override_2.cpp  
// compile with: /clr  
interface struct I1 {  
   virtual void f();  
};  
  
interface struct I2 {  
   virtual void f();  
};  
  
ref struct X : public I1, I2 {  
   virtual void f() = I1::f, I2::f {  
      System::Console::WriteLine("X::f override of I1::f and I2::f");  
   }  
};  
  
int main() {  
   I1 ^ MyI = gcnew X;  
   I2 ^ MyI2 = gcnew X;  
   MyI -> f();  
   MyI2 -> f();  
}  
```  
  
 **Saída**  
  
```Output  
X::f override of I1::f and I2::f  
X::f override of I1::f and I2::f  
```  
  
 **Exemplo**  
  
 O exemplo de código a seguir mostra como uma substituição de função pode ter um nome diferente da função que está implementando.  
  
```  
// explicit_override_3.cpp  
// compile with: /clr  
interface struct I1 {  
   virtual void f();  
};  
  
ref class X : public I1 {  
public:  
   virtual void g() = I1::f {  
      System::Console::WriteLine("X::g");  
   }  
};  
  
int main() {  
   I1 ^ a = gcnew X;  
   a->f();  
}  
```  
  
 **Saída**  
  
```Output  
X::g  
```  
  
 **Exemplo**  
  
 O exemplo de código a seguir mostra uma implementação de interface explícita que implementa uma coleção de tipo seguro.  
  
```  
// explicit_override_4.cpp  
// compile with: /clr /LD  
using namespace System;  
ref class R : ICloneable {  
   int X;  
  
   virtual Object^ C() sealed = ICloneable::Clone {  
      return this->Clone();  
   }  
  
public:  
   R() : X(0) {}  
   R(int x) : X(x) {}  
  
   virtual R^ Clone() {  
      R^ r = gcnew R;  
      r->X = this->X;  
      return r;  
   }  
};  
```  
  
## <a name="see-also"></a>Consulte também  
 [Extensões de componentes para plataformas de tempo de execução](../windows/component-extensions-for-runtime-platforms.md)