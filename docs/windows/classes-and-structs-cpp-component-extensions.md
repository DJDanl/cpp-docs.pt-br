---
title: Classes e estruturas (extensões de componentes C++) | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: reference
dev_langs:
- C++
helpviewer_keywords:
- ref class keyword [C++]
- value class keyword [C++]
- value struct keyword [C++]
- ref struct keyword [C++]
ms.assetid: 5c360764-b229-49c6-9357-66213afbc372
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 9863786e5e017b69217f984e3aa6d1db597e74d3
ms.sourcegitcommit: d55ac596ba8f908f5d91d228dc070dad31cb8360
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/08/2018
ms.locfileid: "33864909"
---
# <a name="classes-and-structs--c-component-extensions"></a>Classes e Estruturas (Extensões de Componentes C++)
Declara uma classe ou estrutura cujo *vida útil do objeto* é gerenciada automaticamente. Quando o objeto não está mais acessível ou sai do escopo, o Visual C++ descarta automaticamente a memória alocada para o objeto.  
  
## <a name="all-runtimes"></a>Todos os Tempos de Execução  
 **Sintaxe**  
  
```  
  
      class_access  
      ref class  
      name  
      modifier :  inherit_accessbase_type {};  
class_accessref structnamemodifier :  inherit_accessbase_type {};  
class_accessvalue classnamemodifier :  inherit_accessbase_type {};  
class_accessvalue structnamemodifier :  inherit_accessbase_type {};  
  
```  
  
 **Parâmetros**  
  
 *class_access* (opcional)  
 A acessibilidade de classe ou struct fora do assembly. Os valores possíveis são **pública** e `private` (`private` é o padrão). Classes aninhadas ou structs não podem ter um *class_access* especificador.  
  
 *name*  
 O nome da classe ou estrutura.  
  
 *modificador* (opcional)  
 [abstrato](../windows/abstract-cpp-component-extensions.md) e [lacrado](../windows/sealed-cpp-component-extensions.md) são modificadores válidos.  
  
 *inherit_access* (opcional)  
 A acessibilidade de `base_type`. A acessibilidade permitida somente é `public` (`public` é o padrão).  
  
 *base_type* (opcional)  
 Um tipo base. No entanto, um tipo de valor não pode atuar como um tipo base.  
  
 Para obter mais informações, consulte as descrições de idioma específico desse parâmetro em tempo de execução do Windows e Runtimesections de linguagem comum.  
  
 **Comentários**  
  
 A acessibilidade de membro padrão de um objeto declarado com **classe ref** ou **classe de valor** é `private`. E a acessibilidade de membro padrão de um objeto declarado com **estrutura ref** ou **estrutura de valor** é `public`.  
  
 Quando um tipo de referência herda de outro tipo de referência, funções virtuais na classe base devem ser substituídas explicitamente (com [substituir](../windows/override-cpp-component-extensions.md)) ou oculto (com [novo (novo slot em vtable)](../windows/new-new-slot-in-vtable-cpp-component-extensions.md)). As funções de classe derivada também devem ser explicitamente marcadas como `virtual`.  
  
 Para detectar no tempo de compilação se um tipo é um `ref class` ou `ref struct`, ou um `value class` ou `value struct`, use `__is_ref_class (type)`, `__is_value_class (type)`, ou `__is_simple_value_class (type)`. Para obter mais informações, consulte [suporte para características do tipo de compilador](../windows/compiler-support-for-type-traits-cpp-component-extensions.md).  
  
 Para obter mais informações sobre classes e estruturas, consulte  
  
-   [Criando Classes e estruturas](../dotnet/how-to-define-and-consume-classes-and-structs-cpp-cli.md)  
  
 
  
-   [Semântica da pilha do C++ para tipos de referência](../dotnet/cpp-stack-semantics-for-reference-types.md)  
  
-   [Classes, estruturas e uniões](../cpp/classes-and-structs-cpp.md)  
  
-   [Destruidores e finalizadores em como: definir e consumir classes e estruturas (C + + CLI)](../dotnet/how-to-define-and-consume-classes-and-structs-cpp-cli.md#BKMK_Destructors_and_finalizers)  
  
-   [Operadores definidos pelo usuário (C++/CLI)](../dotnet/user-defined-operators-cpp-cli.md)  
  
-   [Conversões definidas pelo usuário (C++/CLI)](../dotnet/user-defined-conversions-cpp-cli.md)  
  
-   [Como encapsular a classe nativa a ser usada por C#](../dotnet/how-to-wrap-native-class-for-use-by-csharp.md)  
  
-   [Classes genéricas (C++/CLI)](../windows/generic-classes-cpp-cli.md)  
  
## <a name="windows-runtime"></a>Tempo de Execução do Windows  
 **Comentários**  
  
 Consulte [classes e estruturas Ref](http://msdn.microsoft.com/library/windows/apps/hh699870.aspx) e [classes e estruturas de valor](http://msdn.microsoft.com/library/windows/apps/hh699861.aspx).  
  
 **Parâmetros**  
  
 *base_type* (opcional)  
 Um tipo base. Um `ref class` ou `ref struct` pode herdar de zero ou mais interfaces e zero ou um `ref` tipos. Um `value class` ou `value struct` só pode herdar de zero ou mais interfaces.  
  
 Quando você declara um objeto usando o `ref class` ou `ref struct` palavras-chave, o objeto é acessado por um identificador para um objeto, ou seja, um ponteiro de contador de referência para o objeto. Quando a variável declarada sai do escopo, o compilador exclui automaticamente o objeto subjacente. Quando o objeto é usado como um parâmetro em uma chamada ou é armazenado em uma variável, um identificador para o objeto é realmente transmitido ou armazenado.  
  
 Quando você declara um objeto usando o `value class` ou `value struct` palavras-chave, o tempo de vida do objeto do objeto declarado não é supervisionado. O objeto é como qualquer outra classe C++ padrão ou struct.  
  
### <a name="requirements"></a>Requisitos  
 Opção do compilador: **/ZW**  
  
## <a name="common-language-runtime"></a>Common Language Runtime 
 **Comentários**  
  
 A tabela a seguir lista as diferenças de sintaxe mostrada no **todos os tempos de execução** seção são específicas para o C + + CLI.  
  
 **Parâmetros**  
  
 *base_type* (opcional)  
 Um tipo base. Um `ref class` ou `ref struct` pode herdar de zero ou mais gerenciados interfaces e zero ou tipos de uma ref. Um `value class` ou `value struct` só pode herdar de zero ou mais interfaces gerenciadas.  
  
 O `ref class` e `ref struct` palavras-chave diz ao compilador que a classe ou estrutura deve ser alocado no heap. Quando o objeto é usado como um parâmetro em uma chamada ou é armazenado em uma variável, uma referência ao objeto é realmente transmitida ou armazenada.  
  
 O `value class` e `value struct` palavras-chave informa ao compilador que o valor de alocado de classe ou estrutura é passado para funções ou armazenado em membros.  
  
### <a name="requirements"></a>Requisitos  
 Opção de compilador: **/clr**  
  
## <a name="see-also"></a>Consulte também  
 [Extensões de componentes para plataformas de tempo de execução](../windows/component-extensions-for-runtime-platforms.md)