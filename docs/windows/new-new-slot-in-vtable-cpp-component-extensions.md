---
title: "novo (novo slot em vtable) (extensões de componentes C++) | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: language-reference
dev_langs: C++
helpviewer_keywords: new keyword [C++]
ms.assetid: 1a9a5704-f02f-46ae-ad65-f0f2b6dbabc3
caps.latest.revision: "20"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: f208a62fd49e7aea67acf5b7e3e49d3571f8d910
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="new-new-slot-in-vtable--c-component-extensions"></a>novo (novo slot em vtable) (Extensões de Componentes C++)
O `new` palavra-chave indica que um membro virtual receberá um novo slot em de vtable.  
  
## <a name="all-runtimes"></a>Todos os Tempos de Execução  
 (Não há nenhum comentários para esse recurso de idioma que se aplicam a todos os tempos de execução).  
  
## <a name="windows-runtime"></a>Tempo de Execução do Windows  
 Não tem suporte em tempo de execução do Windows.  
  
## <a name="common-language-runtime"></a>Common Language Runtime 
 **Comentários**  
  
 Em um **/clr** compilação, `new` indica que um membro virtual receberá um novo slot no vtable; se a função não substituir um método de classe base.  
  
 `new`faz com que o modificador newslot a serem adicionadas ao nível de integridade para a função.  Para obter mais informações sobre newslot, consulte:  
  
-   [Método MethodInfo.GetBaseDefinition](https://msdn.microsoft.com/en-us/library/system.reflection.methodinfo.getbasedefinition.aspx)  
  
-   [Enumeração MethodAttributes](https://msdn.microsoft.com/en-us/library/system.reflection.methodattributes.aspx)  
  
### <a name="requirements"></a>Requisitos  
 Opção de compilador: **/clr**  
  
### <a name="examples"></a>Exemplos  
 **Exemplo**  
  
 O exemplo a seguir mostra o efeito de `new`.  
  
```  
// newslot.cpp  
// compile with: /clr  
ref class C {  
public:  
   virtual void f() {  
      System::Console::WriteLine("C::f() called");  
   }  
  
   virtual void g() {  
      System::Console::WriteLine("C::g() called");  
   }  
};  
  
ref class D : public C {  
public:  
   virtual void f() new {  
      System::Console::WriteLine("D::f() called");  
   }  
  
   virtual void g() override {  
      System::Console::WriteLine("D::g() called");  
   }  
};  
  
ref class E : public D {  
public:  
   virtual void f() override {  
      System::Console::WriteLine("E::f() called");  
   }  
};  
  
int main() {  
   D^ d = gcnew D;  
   C^ c = gcnew D;  
  
   c->f();   // calls C::f  
   d->f();   // calls D::f  
  
   c->g();   // calls D::g  
   d->g();   // calls D::g  
  
   D ^ e = gcnew E;  
   e->f();   // calls E::f  
}  
```  
  
 **Saída**  
  
```Output  
C::f() called  
  
D::f() called  
  
D::g() called  
  
D::g() called  
  
E::f() called  
```  
  
## <a name="see-also"></a>Consulte também  
 [Extensões de componentes para plataformas de tempo de execução](../windows/component-extensions-for-runtime-platforms.md)   
 [Especificadores de substituição](../windows/override-specifiers-cpp-component-extensions.md)