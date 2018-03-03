---
title: "sealed (extensões de componentes C++) | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: language-reference
f1_keywords:
- sealed_cpp
- sealed
dev_langs:
- C++
helpviewer_keywords:
- sealed keyword [C++]
ms.assetid: 3d0d688a-41aa-45f5-a25a-65c44206521e
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: bb8a8b7ea695d878235898a8741adf04ba91748c
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="sealed--c-component-extensions"></a>autenticada (Extensões de Componentes C++)
`sealed`é uma palavra-chave contextual para classes ref que indica que um membro virtual não pode ser substituído ou que um tipo não pode ser usado como um tipo base.  
  
> [!NOTE]
>  O ISO C++ 11 linguagem padrão tem o [final](../cpp/final-specifier.md) palavra-chave, que tem suporte no Visual Studio. Use `final` classes padrão, e `sealed` em classes ref.  
  
## <a name="all-runtimes"></a>Todos os Tempos de Execução  
  
## <a name="syntax"></a>Sintaxe
  
```  
ref class identifier sealed {...};  
virtual return-type identifier() sealed {...};  
```  
  
### <a name="parameters"></a>Parâmetros  
  
 *identifier*  
 O nome da função ou classe.  
  
 *tipo de retorno*  
 O tipo que é retornado por uma função.  
  
## <a name="remarks"></a>Comentários  
  
 No primeiro exemplo de sintaxe, uma classe está lacrada. No segundo exemplo, uma função virtual está lacrada.  
  
 O `sealed` palavra-chave é válido para destinos nativo e também para o tempo de execução do Windows e o common language runtime (CLR). Para obter mais informações, consulte [especificadores de substituição e compilações nativas](../dotnet/how-to-declare-override-specifiers-in-native-compilations-cpp-cli.md).  
  
 Você pode detectar no tempo de compilação se um tipo é lacrado, usando o `__is_sealed(type)` característica de tipo. Para obter mais informações, consulte [suporte para características do tipo de compilador](../windows/compiler-support-for-type-traits-cpp-component-extensions.md).  
  
 `sealed`é uma palavra-chave contextual.  Para obter mais informações, consulte [sensível ao contexto palavras-chave](../windows/context-sensitive-keywords-cpp-component-extensions.md).  
  
## <a name="windows-runtime"></a>Tempo de Execução do Windows  
 Consulte [classes e estruturas Ref](http://msdn.microsoft.com/library/windows/apps/hh699870.aspx).  
  
### <a name="requirements"></a>Requisitos  
 Opção do compilador: **/ZW**  
  
## <a name="common-language-runtime"></a>Common Language Runtime  
 (Não há nenhum comentários para esse recurso de idioma que se aplicam a apenas o common language runtime).  
  
### <a name="requirements"></a>Requisitos  
 Opção de compilador: **/clr**  
  
### <a name="examples"></a>Exemplos  
 Este exemplo de código a seguir mostra o efeito de `sealed` em um membro virtual.  
  
```cpp  
// sealed_keyword.cpp  
// compile with: /clr  
interface struct I1 {  
   virtual void f();  
   virtual void g();  
};  
  
ref class X : I1 {  
public:  
   virtual void f() {  
      System::Console::WriteLine("X::f override of I1::f");  
   }  
  
   virtual void g() sealed {  
      System::Console::WriteLine("X::f override of I1::g");  
   }  
};  
  
ref class Y : public X {  
public:  
   virtual void f() override {  
      System::Console::WriteLine("Y::f override of I1::f");  
   }  
  
   /*  
   // the following override generates a compiler error  
   virtual void g() override {  
      System::Console::WriteLine("Y::g override of I1::g");  
   }    
   */  
};  
  
int main() {  
   I1 ^ MyI = gcnew X;  
   MyI -> f();  
   MyI -> g();  
  
   I1 ^ MyI2 = gcnew Y;  
   MyI2 -> f();  
}  
```  
  
```Output  
X::f override of I1::f  
X::f override of I1::g  
Y::f override of I1::f  
```  
  
 O exemplo de código a seguir mostra como marcar uma classe como fechado.  
  
```cpp  
// sealed_keyword_2.cpp  
// compile with: /clr  
interface struct I1 {  
   virtual void f();  
};  
  
ref class X sealed : I1 {  
public:  
   virtual void f() override {}  
};  
  
ref class Y : public X {   // C3246 base class X is sealed  
public:  
   virtual void f() override {}  
};  
```  
  
## <a name="see-also"></a>Consulte também  
 [Extensões de componentes para plataformas de tempo de execução](../windows/component-extensions-for-runtime-platforms.md)