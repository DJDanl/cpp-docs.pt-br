---
title: "Derivando uma classe de CObject | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
f1_keywords: 
  - "CObject"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe CObject, derivando de"
  - "Classe CObject, derivando de classes que podem ser serializadas"
  - "Macro DECLARE_DYNAMIC"
  - "Macro DECLARE_DYNCREATE"
  - "Macro DECLARE_SERIAL"
  - "classes derivadas, de CObject"
  - "macros [C++], serialização"
  - "serialização [C++], Macros "
ms.assetid: 5ea4ea41-08b5-4bd8-b247-c5de8c152a27
caps.latest.revision: 11
caps.handback.revision: 7
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Derivando uma classe de CObject
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Este artigo descreve as etapas mínimas necessárias para derivar uma classe de [CObject](../Topic/CObject%20Class.md).  Outros artigos da classe de `CObject` descrevem as etapas necessárias para tirar proveito dos recursos específicos de `CObject` , como a serialização e suporte de diagnóstico de depuração.  
  
 Em discussões de `CObject`, os termos “interface do arquivo” e “o arquivo implementação” é frequentemente usado.  O arquivo da interface \(geralmente chamado do arquivo de cabeçalho, ou. O arquivo de H\) contém a declaração de classe e qualquer outra informações necessárias para usar a classe.  O arquivo de implementação \(ou arquivo de .CPP\) contém a definição de classe bem como o código que implementa funções de membro da classe.  Por exemplo, para uma classe nomeada `CPerson`, você normalmente deve criar um arquivo da interface nomeada PERSON.H e o arquivo de implementação PERSON.CPP denominada.  No entanto, para algumas pequenas classes que não são compartilhadas entre aplicativos, algumas vezes é mais fácil combinar a interface e a implementação do em um único arquivo de .CPP.  
  
 Você pode escolher entre quatro níveis de funcionalidade para derivar uma classe de `CObject`:  
  
-   Funcionalidade básica: Não há suporte para obter informações ou a serialização da classe de tempo de execução mas inclui gerenciamento de memória diagnóstico.  
  
-   Funcionalidade básica mais suporte para as informações da classe de tempo de execução.  
  
-   Funcionalidade básica mais suporte para as informações da classe de tempo de execução e a criação dinâmico.  
  
-   Funcionalidade básica mais suporte para as informações da classe de tempo de execução, a criação dinâmico, e a serialização.  
  
 As classes criada para reutilização posterior \(aqueles que servirá como classes base\) devem incluir pelo menos o suporte da classe de tempo de execução e suporte de serialização, se houver necessidade futura de serialização é antecipada.  
  
 Você escolhe o nível de funcionalidade usando macros específicos de declaração e a implementação na declaração e na implementação das classes que você se deriva de `CObject`.  
  
 A tabela a seguir mostra a relação entre as macros usado para serialização de suporte e informações de tempo de execução.  
  
### Macros usados para as informações de serialização e de tempo de execução  
  
|Macro usado|CObject::IsKindOf|CRuntimeClass::<br /><br /> CreateObject|CArchive::operator\>\><br /><br /> CArchive::operator\<\<|  
|-----------------|-----------------------|--------------------------------------|-------------------------------------------------------|  
|Funcionalidade básica de `CObject`|Não|Não|Não|  
|`DECLARE_DYNAMIC`|Sim|Não|Não|  
|`DECLARE_DYNCREATE`|Sim|Sim|Não|  
|`DECLARE_SERIAL`|Sim|Sim|Sim|  
  
#### Para usar a funcionalidade básica de CObject  
  
1.  Use a sintaxe normal do C\+\+ para derivar a sua classe de `CObject` \(ou uma classe derivada de `CObject`\).  
  
     O exemplo a seguir mostra o caso mais simples, a derivação de uma classe de `CObject`:  
  
     [!code-cpp[NVC_MFCCObjectSample#1](../mfc/codesnippet/CPP/deriving-a-class-from-cobject_1.h)]  
  
 Normalmente, o entanto, talvez você queira substituir algumas das funções de membro de `CObject` para lidar com valores específicos de sua nova classe.  Por exemplo, você pode geralmente queira substituir a função de `Dump` de `CObject` para fornecer saída de depuração para o conteúdo da classe.  Para obter detalhes sobre como anular `Dump`, consulte o artigo [Diagnóstico: Despejando conteúdo do objeto](http://msdn.microsoft.com/pt-br/727855b1-5a83-44bd-9fe3-f1d535584b59).  Talvez você também queira substituir a função de `AssertValid` de `CObject` para fornecer teste personalizados para validar a consistência dos membros de dados de objetos da classe.  Para obter uma descrição de como substituir `AssertValid`, consulte [MFC ASSERT\_VALID e CObject::AssertValid](http://msdn.microsoft.com/pt-br/7654fb75-9e9a-499a-8165-0a96faf2d5e6).  
  
 O artigo [Especificando níveis de funcionalidade](../mfc/specifying-levels-of-functionality.md) descreve como especificar outros níveis de funcionalidade, inclusive informações da classe de tempo de execução, a criação do objeto dinâmico, e a serialização.  
  
## Consulte também  
 [Usando CObject](../mfc/using-cobject.md)