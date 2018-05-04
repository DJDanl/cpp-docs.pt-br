---
title: Classes e estruturas (C++) | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-language
ms.topic: language-reference
dev_langs:
- C++
helpviewer_keywords:
- Visual C++, classes
- structures, C++ classes
- user-defined types
- classes [C++]
- user-defined types, C++ classes
ms.assetid: 516dd496-13fb-4f17-845a-e9ca45437873
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 61348578018a5bbddcaff293fa3ed76575eb16de
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
---
# <a name="classes-and-structs-c"></a>Classes e structs (C++)
Esta seção apresenta as estruturas e classes C++. As duas construções são idênticas em C++, exceto que em structs a acessibilidade padrão é pública, enquanto em classes, o padrão é particular.  
  
 Classes e estruturas são as construções no qual você pode definir seus próprios tipos. Classes e estruturas podem conter membros de dados e funções de membro, que permitem descrever o estado e o comportamento do tipo.  
  
 Os seguintes tópicos estão incluídos:  
  
-   [class](../cpp/class-cpp.md)  
  
-   [struct](../cpp/struct-cpp.md)  
  
-   [Visão geral de membros de classe](../cpp/class-member-overview.md)  
  
-   [Controle de Acesso a membro](../cpp/member-access-control-cpp.md)  
  
-   [Herança](../cpp/inheritance-cpp.md)  
  
-   [Membros estáticos](../cpp/static-members-cpp.md)  
  
-   [Conversões de tipo definido pelo usuário](../cpp/user-defined-type-conversions-cpp.md)  
  
-   [Mutáveis (especificador mutável) membros de dados](../cpp/mutable-data-members-cpp.md)  
  
-   [Declarações de classe aninhada](../cpp/nested-class-declarations.md)  
  
-   [Tipos de classe anônima](../cpp/anonymous-class-types.md)  
  
-   [Ponteiros para membros](../cpp/pointers-to-members.md)  
  
-   [Ponteiro this](../cpp/this-pointer.md)  
  
-   [Campos de bits C++](../cpp/cpp-bit-fields.md)  
  
 Os três tipos de classe são estrutura, classe e união. Eles são declarados usando o [struct](../cpp/struct-cpp.md), [classe](../cpp/class-cpp.md), e [união](../cpp/unions.md) palavras-chave (consulte [definindo tipos de classe](http://msdn.microsoft.com/en-us/e8c65425-0f3a-4dca-afc2-418c3b1e57da)). A tabela a seguir mostra as diferenças entre os três tipos de classe.  
  
 Para obter mais informações sobre uniões, consulte [uniões](../cpp/unions.md). Para obter informações sobre classes gerenciadas e estruturas, consulte [Classes e estruturas](../windows/classes-and-structs-cpp-component-extensions.md).  
  
### <a name="access-control-and-constraints-of-structures-classes-and-unions"></a>Controle de acesso e restrições de estruturas, classes e uniões  
  
|Estruturas|Classes|Uniões|  
|----------------|-------------|------------|  
|a chave da classe é `struct`|classe de chave é **classe**|classe de chave é **union**|  
|O acesso padrão é público|O acesso padrão é particular|O acesso padrão é público|  
|Nenhuma restrição de uso|Nenhuma restrição de uso|Use apenas um membro de cada vez|  
  
## <a name="see-also"></a>Consulte também  
 [Referência da linguagem C++](../cpp/cpp-language-reference.md)