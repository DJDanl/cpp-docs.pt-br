---
title: "Especificando n&#237;veis de funcionalidade | Microsoft Docs"
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
  - "Classe CObject, adicionando funcionalidade a classes derivadas"
  - "suporte à criação dinâmica"
  - "níveis [C++]"
  - "níveis [C++], funcionalidade em CObject"
  - "tempo de execução [C++], informações de classe"
  - "classe runtime, suporte a informações"
  - "serialização [C++], Cobject"
ms.assetid: 562669ba-c858-4f66-b5f1-b3beeea4f486
caps.latest.revision: 9
caps.handback.revision: 5
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Especificando n&#237;veis de funcionalidade
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Este artigo descreve como adicionar os seguintes níveis de funcionalidades ao seu [CObject](../Topic/CObject%20Class.md)\- classe derivada:  
  
-   [Informações da classe de tempo de execução](#_core_to_add_run.2d.time_class_information)  
  
-   [Suporte de criação dinâmico](#_core_to_add_dynamic_creation_support)  
  
-   [Suporte de serialização](#_core_to_add_serialization_support)  
  
 Para uma descrição geral da funcionalidade de `CObject` , consulte o artigo [Com uma classe de CObject](../mfc/deriving-a-class-from-cobject.md).  
  
#### Para adicionar informações da classe de tempo de execução  
  
1.  Derivar a sua classe de `CObject`, conforme descrito no artigo de [Com uma classe de CObject](../mfc/deriving-a-class-from-cobject.md) .  
  
2.  Use a macro de `DECLARE_DYNAMIC` em sua declaração de classe, como mostrado a seguir:  
  
     [!code-cpp[NVC_MFCCObjectSample#2](../mfc/codesnippet/CPP/specifying-levels-of-functionality_1.h)]  
  
3.  Use a macro de `IMPLEMENT_DYNAMIC` no arquivo de implementação\) \(.CPP da classe.  Esta macro usa como argumentos o nome da classe e sua classe base, como segue:  
  
     [!code-cpp[NVC_MFCCObjectSample#3](../mfc/codesnippet/CPP/specifying-levels-of-functionality_2.cpp)]  
  
> [!NOTE]
>  `IMPLEMENT_DYNAMIC` sempre colocado no arquivo de implementação .CPP \(\) para a sua classe.  A macro de `IMPLEMENT_DYNAMIC` deve ser avaliada apenas uma vez durante a compilação e não em virtude disso deve ser usado em um arquivo \(da interface. H\) que poderia ser incluído em mais de um arquivo.  
  
#### Para adicionar suporte dinâmico de criação  
  
1.  Derivar a sua classe de `CObject`.  
  
2.  Use a macro de `DECLARE_DYNCREATE` na declaração da classe.  
  
3.  Define um construtor sem argumentos \(um construtor padrão\).  
  
4.  Use a macro de `IMPLEMENT_DYNCREATE` no arquivo de implementação da classe.  
  
#### Para adicionar suporte de serialização  
  
1.  Derivar a sua classe de `CObject`.  
  
2.  Substitua a função de membro de `Serialize` .  
  
    > [!NOTE]
    >  Se você chamar `Serialize` diretamente, ou seja, você não quiser serializar o objeto através de um ponteiro polimórfica, omitir as etapas de 3 a 5.  
  
3.  Use a macro de `DECLARE_SERIAL` na declaração da classe.  
  
4.  Define um construtor sem argumentos \(um construtor padrão\).  
  
5.  Use a macro de `IMPLEMENT_SERIAL` no arquivo de implementação da classe.  
  
> [!NOTE]
>  Pontos “de” polimórfica um ponteiro para um objeto de uma classe chamada \(A\) ou um objeto de qualquer classe derivada da \(digamos, B\).  Para serializar por meio de um ponteiro polimórfica, a estrutura deve determinar a classe de tempo de execução do objeto que está serializando \(b\), desde que pode ser um objeto de qualquer classe derivada de uma determinada classe base \(a\).  
  
 Para obter mais detalhes sobre como habilitar a serialização quando você deve derivar a sua classe de `CObject`, consulte os artigos [Arquivos em MFC](../mfc/files-in-mfc.md) e [Serialização](../Topic/Serialization%20in%20MFC.md).  
  
## Consulte também  
 [Derivando uma classe de CObject](../mfc/deriving-a-class-from-cobject.md)