---
title: "Conversão Boxing implícita de tipos de valor | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
dev_langs: C++
helpviewer_keywords:
- boxing, Visual C++
- __box keyword
- boxing
- boxing, __box keyword
- value types, boxed
ms.assetid: 9597c92f-a3fe-44af-ad80-f9d656847a35
caps.latest.revision: "9"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.openlocfilehash: 1f489c686a182840e142264476c3906d0cbfe97b
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="implicit-boxing-of-value-types"></a>Conversão boxing implícita de tipos de valor
A conversão boxing de tipos de valor foi alterado de extensões gerenciadas para C++ para Visual C++.  
  
 No design de idioma é imposto de uma posição filosóficas em vez de uma experiência prática com o recurso e, na prática, ele foi um erro. Como uma analogia, no original vários design de linguagem de herança, Stroustrup decidido que um objeto de subsistema de classe base virtual não pôde ser inicializado em um construtor de classe derivada e, portanto, o idioma necessário que qualquer classe que serve como uma base virtual classe deve definir um construtor padrão. É esse construtor padrão que poderia ser chamado por qualquer derivação virtual subsequente.  
  
 O problema de uma hierarquia de classe base virtual é responsabilidade para a inicialização do objeto subdiretório virtual compartilhado é deslocado com cada derivação subsequente. Por exemplo, se definir uma classe base para que a inicialização exige a alocação de um buffer, o tamanho de buffer especificado pelo usuário pode ser passado como um argumento para o construtor. Se, em seguida, fornecer duas derivações virtuais subsequentes, chamá-los `inputb` e `outputb`, cada fornece um valor específico para o construtor de classe base. Agora, quando eu derivada um `in_out` classe tanto `inputb` e `outputb`, nenhum desses valores para o objeto de classe base virtual compartilhada sub pode facilmente possa avaliar.  
  
 Portanto, no design original do idioma, Stroustrup não permitida a inicialização explícita de uma classe base virtual dentro da lista de inicialização de membro do construtor de classe derivada. Enquanto isso solucionou o problema, na prática, a incapacidade para direcionar a inicialização da classe base virtual tornava impracticable. Keith Gorlen da National Institute de integridade, que tinha implementado uma versão gratuitos da biblioteca de coleção SmallTalk chamada nihcl, foi uma voz princípio convencer Stroustrup que ele tinha a criar um design de idioma mais flexível.  
  
 Um princípio de design hierárquico e orientada a objeto mantém que uma classe derivada deve se preocupar somente com a implementação não particular de suas classes base imediatas. Para dar suporte a um projeto de inicialização flexível de herança virtual, Stroustrup tinha que violam esse princípio. A classe mais derivada em uma hierarquia assume a responsabilidade por todas as inicializações subobjeto virtual independentemente da profundidade na hierarquia, ele ocorre. Por exemplo, `inputb` e `outputb` são responsáveis por explicitamente inicializar sua classe base virtual imediata. Quando `in_out` deriva de ambos `inputb` e `outputb`, `in_out` se torna responsável para a inicialização de uma vez removido a classe base virtual e a inicialização tornados explícita em `inputb` e `outputb` é suprimida.  
  
 Isso fornece a flexibilidade necessária por desenvolvedores de idioma, mas às custas de uma semântica complicada. Esta sobrecarga do complicativo é retirada se podemos restringir uma classe base virtual sem estado e simplesmente permite especificar uma interface. Este é um idioma de design recomendado em C++. Na programação de CLR, ele é gerado para a política com o tipo de Interface.  
  
 Aqui está um exemplo de código simples - e, nesse caso, a conversão explícita é necessário:  
  
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
  
 Como você pode ver, há muito boxing acontecendo. Tipo de valor em Visual C++, conversão boxing é implícita:  
  
```  
// new syntax makes boxing implicit  
array<int>^ my1DIntArray = {1,2,3,4,5};  
array<Object^>^ myObjArray = {26,27,28,29,30};  
  
Console::WriteLine( "{0}\t{1}\t{2}", 0,   
   my1DIntArray->GetLowerBound( 0 ),   
   my1DIntArray->GetUpperBound( 0 ) );  
```  
  
## <a name="see-also"></a>Consulte também  
 [Tipos de valor e seus comportamentos (C + + CLI)](../dotnet/value-types-and-their-behaviors-cpp-cli.md)   
 [Conversão boxing](../windows/boxing-cpp-component-extensions.md)