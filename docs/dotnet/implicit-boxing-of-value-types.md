---
title: "Convers&#227;o boxing impl&#237;cita de tipos de valor | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Palavra-chave __box"
  - "boxing"
  - "boxing, Palavra-chave __box"
  - "boxing, Visual C++"
  - "tipos de valor, demarcado"
ms.assetid: 9597c92f-a3fe-44af-ad80-f9d656847a35
caps.latest.revision: 9
caps.handback.revision: 9
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Convers&#227;o boxing impl&#237;cita de tipos de valor
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

O com os tipos de valor foi alterada de extensões gerenciadas para C\+\+ a [!INCLUDE[cpp_current_long](../Token/cpp_current_long_md.md)].  
  
 Design de idiomas, é imposta uma posição filosófica no lugar da experiência prática com o recurso e, na prática, era um erro.  Como uma analogia, no design original do idioma de herança múltipla, Stroustrup decidiu que um novo objeto virtual da classe base não pôde ser inicializado em um construtor de classe derivada e, consequentemente o idioma exigido que qualquer classificação do serviço como uma classe base virtual deve definir um construtor padrão.  É o construtor padrão que será invocado por uma derivação virtual subsequente.  
  
 O problema de uma hierarquia virtual da classe base é de responsabilidade da inicialização de um objeto virtual compartilhado desloca com cada derivação subsequente.  Por exemplo, se eu defino uma classe base para que a inicialização exige a alocação de um buffer, o tamanho especificado pelo usuário desse buffer pode ser passado como um argumento para o construtor.  Se eu forneço em duas derivações virtuais subsequentes, chamar `inputb` e `outputb`, cada um fornece um valor específico para o construtor da classe base.  Agora, quando eu derivei uma classe de `in_out` de `inputb` e de `outputb`, nenhum desses valores ao subobjeto virtual compartilhado da classe base apreciàvel podem ser permitidos avaliar.  
  
 Em virtude disso, o design original do idioma, Stroustrup recusou a inicialização explícita de uma classe base virtual na lista de inicialização do construtor de classe derivada.  Quando isso solucionar o problema, na prática a incapacidade direcionar a inicialização da classe base virtual provou impraticável.  Keith Gorlen de formato de integridade nacional, que haviam implementado uma versão de freeware de biblioteca da coleção de tagarelice chamou o nihcl, era uma voz da entidade de segurança em Stroustrup de convencimento que teve que vir superior com um design mais flexível do idioma.  
  
 Um princípio de design hierárquico orientado a objeto que mantém uma classe derivada se deve estar relacionada somente com a implementação não privada de suas classes base imediata.  Para oferecer suporte a um design flexível de inicialização para herança virtual, Stroustrup tinha que viole esse princípio.  A maioria de classe derivada em uma hierarquia assume a responsabilidade para qualquer inicialização virtual do subobjeto independentemente do nível de profundidade da hierarquia ocorre.  Por exemplo, `inputb` e `outputb` são ambos responsáveis por explicitamente inicializar sua classe base virtual imediata.  Quando `in_out` se deriva do `inputb` e `outputb`, `in_out` é responsável pela inicialização da classe base virtual uma vez removido, e a inicialização fez explícito dentro de `inputb` e `outputb` será suprimido.  
  
 Isso fornece a flexibilidade exigida por desenvolvedores de idioma, mas à custa de uma semântica complicada.  Essa carga de complicação é tirada acionado se nós restringimos uma classe base virtual para ser sem estado e para permitir apenas que especifica a interface.  Este é um idioma recomendado de design em C\+\+.  Dentro de CLR que programa, é aumentado na política com o tipo de interface.  
  
 Aqui está um exemplo simples de código e nesse caso, o com explícito é desnecessário:  
  
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
  
 Como você pode ver, há muitos de boxing aceitos em.  Em [!INCLUDE[cpp_current_long](../Token/cpp_current_long_md.md)], o com o tipo de valor está implícito:  
  
```  
// new syntax makes boxing implicit  
array<int>^ my1DIntArray = {1,2,3,4,5};  
array<Object^>^ myObjArray = {26,27,28,29,30};  
  
Console::WriteLine( "{0}\t{1}\t{2}", 0,   
   my1DIntArray->GetLowerBound( 0 ),   
   my1DIntArray->GetUpperBound( 0 ) );  
```  
  
## Consulte também  
 [Tipos de valor e seus comportamentos \(C\+\+\/CLI\)](../dotnet/value-types-and-their-behaviors-cpp-cli.md)   
 [Boxing](../windows/boxing-cpp-component-extensions.md)