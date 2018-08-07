---
title: novo (novo slot em vtable) (extensões de componentes C++) | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: reference
dev_langs:
- C++
helpviewer_keywords:
- new keyword [C++]
ms.assetid: 1a9a5704-f02f-46ae-ad65-f0f2b6dbabc3
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 32452b4fd44aed2bc399165b3184d974f22d90b6
ms.sourcegitcommit: 4586bfc32d8bc37ab08b24816d7fad5df709bfa3
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/07/2018
ms.locfileid: "39607005"
---
# <a name="new-new-slot-in-vtable--c-component-extensions"></a>novo (novo slot em vtable) (Extensões de Componentes C++)
O **novo** palavra-chave indica que um membro virtual obterá um novo slot em vtable.  
  
## <a name="all-runtimes"></a>Todos os Tempos de Execução  
 (Não há nenhum comentário sobre este recurso de linguagem que se aplicam a todos os tempos de execução.)  
  
## <a name="windows-runtime"></a>Tempo de Execução do Windows  
 Não tem suporte em tempo de execução do Windows.  
  
## <a name="common-language-runtime"></a>Common Language Runtime 
### <a name="remarks"></a>Comentários  
  
 Em um `/clr` compilação, **nova** indica que um membro virtual obterá um novo slot em vtable; que a função não substitui um método de classe base.  
  
 **novo** faz com que o modificador newslot a ser adicionado ao IL para a função.  Para obter mais informações sobre novo slot, consulte:  
  
-   [Método MethodInfo. Getbasedefinition](https://msdn.microsoft.com/library/system.reflection.methodinfo.getbasedefinition.aspx)  
  
-   [Enumeração de MethodAttributes](https://msdn.microsoft.com/library/system.reflection.methodattributes.aspx)  
  
### <a name="requirements"></a>Requisitos  
 Opção do compilador: `/clr`  
  
### <a name="examples"></a>Exemplos  
  
 O exemplo a seguir mostra o efeito **novo**.  
  
```cpp  
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