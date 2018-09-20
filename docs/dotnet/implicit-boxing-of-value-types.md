---
title: Conversão Boxing implícita de tipos de valor | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-cli
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- boxing, Visual C++
- __box keyword
- boxing
- boxing, __box keyword
- value types, boxed
ms.assetid: 9597c92f-a3fe-44af-ad80-f9d656847a35
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- dotnet
ms.openlocfilehash: e9c232dba6d766d0855bb4bb29e33d85b5fd5a2d
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46387582"
---
# <a name="implicit-boxing-of-value-types"></a>Conversão boxing implícita de tipos de valor

A conversão boxing de tipos de valor foi alterado de extensões gerenciadas para C++ para Visual C++.

No design de linguagem, podemos imposto uma posição filosóficas no lugar de uma experiência prática com o recurso e, na prática, ele foi um erro. Como uma analogia, no original vários design de linguagem de herança, Stroustrup decidiu que não foi possível inicializar um Subobjeto da classe base virtual dentro de um construtor de classe derivada e, portanto, a linguagem exigia que qualquer classe que serve como base virtual classe deve definir um construtor padrão. É esse construtor padrão que poderia ser chamado por qualquer derivação virtual subsequente.

O problema de uma hierarquia de classe base virtual é que a responsabilidade para a inicialização do objeto subdiretório virtual compartilhado é transferida com cada derivação subsequente. Por exemplo, se eu definir uma classe base para qual inicialização requer a alocação de um buffer, o tamanho especificado pelo usuário daquele buffer pode ser passado como um argumento para o construtor. Se eu fornecer, em seguida, duas derivações virtuais subsequentes, chamá-las `inputb` e `outputb`, cada um fornece um valor específico para o construtor de classe base. Agora, quando eu derivada uma `in_out` classe tanto `inputb` e `outputb`, nenhum desses valores para o subobjeto de classe de base virtual compartilhado podem facilmente ser tem permissão para avaliar.

Portanto, no design da linguagem original, Stroustrup não permitida a inicialização explícita de uma classe base virtual dentro da lista de inicialização de membro do construtor de classe derivada. Enquanto isso resolveu o problema, na prática, a incapacidade para direcionar a inicialização da classe base virtual provou impracticable. Keith Gorlen da National Institute de integridade, que tinha implementado uma versão freeware da biblioteca de coleção do SmallTalk chamada nihcl, foi uma voz de princípio em convencer Stroustrup que ele tinha propor um design de linguagem mais flexível.

Um princípio de design hierárquico e orientada a objeto mantém que uma classe derivada deve se preocupar apenas com a implementação não particular de suas classes base imediatas. Para dar suporte a um design flexível de inicialização para a herança virtual, Stroustrup tinha que viola esse princípio. A classe mais derivada em uma hierarquia assume a responsabilidade por toda a inicialização de subobjeto virtual, independentemente de profundidade na hierarquia da qual ele ocorre. Por exemplo, `inputb` e `outputb` são ambos responsável por inicializar explicitamente a classe base virtual imediata. Quando `in_out` deriva de ambos `inputb` e `outputb`, `in_out` torna-se responsável para a inicialização de uma vez removido a classe base virtual e a inicialização tornados explícita dentro `inputb` e `outputb` é suprimido.

Isso fornece a flexibilidade necessária por desenvolvedores de linguagem, mas às custas de uma semântica complicada. Essa carga de complicação é retirada se podemos restringir uma classe base virtual para ser sem estado e simplesmente permitir que ele especifica uma interface. Essa é uma linguagem de design recomendado dentro do C++. Dentro do CLR de programação, ele é gerado para a política com o tipo de Interface.

Aqui está um exemplo de código simple – e, nesse caso, a conversão boxing explícita é desnecessária:

```
// Managed Extensions for C++ requires explicit __box operation
int my1DIntArray __gc[] = { 1, 2, 3, 4, 5 };
Object* myObjArray __gc[] = {
   __box(26), __box(27), __box(28), __box(29), __box(30)
};

Console::WriteLine( "{0}\t{1}\t{2}", __box(0),
   __box(my1DIntArray->GetLowerBound(0)),
   __box(my1DIntArray->GetUpperBound(0)) );
```

Como você pode ver, há muita boxing em andamento. Tipo de valor em Visual C++, conversão boxing é implícita:

```
// new syntax makes boxing implicit
array<int>^ my1DIntArray = {1,2,3,4,5};
array<Object^>^ myObjArray = {26,27,28,29,30};

Console::WriteLine( "{0}\t{1}\t{2}", 0,
   my1DIntArray->GetLowerBound( 0 ),
   my1DIntArray->GetUpperBound( 0 ) );
```

## <a name="see-also"></a>Consulte também

[Tipos de valor e seus comportamentos (C++/CLI)](../dotnet/value-types-and-their-behaviors-cpp-cli.md)<br/>
[Conversão boxing](../windows/boxing-cpp-component-extensions.md)