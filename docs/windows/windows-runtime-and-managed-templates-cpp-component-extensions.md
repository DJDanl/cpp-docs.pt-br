---
title: Tempo de execução do Windows e modelos gerenciados (extensões de componentes C++) | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: reference
dev_langs:
- C++
helpviewer_keywords:
- templates, with CLR types
ms.assetid: cf59d16b-5514-448b-9a95-e0b4fcb616a6
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 6fe449842cc019520a3d73528db05a26b17dcd99
ms.sourcegitcommit: 38af5a1bf35249f0a51e3aafc6e4077859c8f0d9
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/09/2018
ms.locfileid: "40011556"
---
# <a name="windows-runtime-and-managed-templates-c-component-extensions"></a>Windows Runtime e Modelos Gerenciados (Extensões de Componentes C++)
Modelos permitem que você defina um protótipo de um tempo de execução do Windows ou o tipo common language runtime e, em seguida, criar uma instância de variações desse tipo por meio de parâmetros de tipo de modelo diferente.  
  
## <a name="all-runtimes"></a>Todos os Tempos de Execução  
 Você pode criar modelos de tipos de valor ou referência.  Para obter mais informações sobre como criar tipos de valor ou referência, consulte [Classes e Structs](../windows/classes-and-structs-cpp-component-extensions.md).  
  
 Para obter mais informações sobre modelos de classe C++ padrão, consulte [modelos de classe](../cpp/class-templates.md).  
  
## <a name="windows-runtime"></a>Tempo de Execução do Windows  
 (Não há nenhum comentário sobre este recurso de linguagem que se aplicam a apenas o tempo de execução do Windows.)  
  
### <a name="requirements"></a>Requisitos  
 Opção do compilador: `/ZW`  
  
## <a name="common-language-runtime"></a>Common Language Runtime  
 Existem algumas limitações para a criação de modelos de classe de tipos gerenciados que são demonstrados nos exemplos de código a seguir.  
  
### <a name="requirements"></a>Requisitos  
 Opção do compilador: `/clr`  
  
### <a name="examples"></a>Exemplos  
  
 É possível criar uma instância de um tipo genérico com um parâmetro de modelo do tipo gerenciado, mas você não pode instanciar um modelo gerenciado com um parâmetro de modelo de tipo genérico. Isso ocorre porque os tipos genéricos são resolvidos em tempo de execução. Para obter mais informações, consulte [genéricos e modelos (Visual C++)](../windows/generics-and-templates-visual-cpp.md).  
  
```cpp  
// managed_templates.cpp  
// compile with: /clr /c  
  
generic<class T>   
ref class R;   
  
template<class T>   
ref class Z {  
   // Instantiate a generic with a template parameter.  
   R<T>^ r;    // OK  
};  
  
generic<class T>   
ref class R {  
   // Cannot instantiate a template with a generic parameter.  
   Z<T>^ z;   // C3231  
};  
```  
  
 Um tipo genérico ou uma função não pode ser aninhada em um modelo gerenciado.  
  
```cpp  
// managed_templates_2.cpp  
// compile with: /clr /c  
  
template<class T> public ref class R {  
   generic<class T> ref class W {};   // C2959  
};  
```  
  
 Você não pode acessar modelos definidos em um assembly referenciado com C + + / sintaxe de linguagem da CLI, mas você pode usar a reflexão. Se um modelo não é instanciado, ele não é emitido nos metadados. Se um modelo é instanciado, apenas as funções de membro referenciado serão exibido nos metadados.  
  
```cpp  
// managed_templates_3.cpp  
// compile with: /clr  
  
// Will not appear in metadata.  
template<class T> public ref class A {};  
  
// Will appear in metadata as a specialized type.  
template<class T> public ref class R {  
public:  
   // Test is referenced, will appear in metadata  
   void Test() {}  
  
   // Test2 is not referenced, will not appear in metadata  
   void Test2() {}  
};  
  
// Will appear in metadata.  
generic<class T> public ref class G { };  
  
public ref class S { };  
  
int main() {  
   R<int>^ r = gcnew R<int>;  
   r->Test();  
}  
```  
  
 Você pode alterar o modificador gerenciado de uma classe em uma especialização parcial ou uma especialização explícita de um modelo de classe.  
  
```cpp  
// managed_templates_4.cpp  
// compile with: /clr /c  
  
// class template  
// ref class  
template <class T>  
ref class A {};  
  
// partial template specialization  
// value type  
template <class T>  
value class A <T *> {};  
  
// partial template specialization  
// interface  
template <class T>   
interface class A<T%> {};  
  
// explicit template specialization  
// native class  
template <>  
class A <int> {};  
```  
  
## <a name="see-also"></a>Consulte também  
 [Extensões de componentes para plataformas de tempo de execução](../windows/component-extensions-for-runtime-platforms.md)