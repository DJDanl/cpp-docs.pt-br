---
title: "Como fazer uma cole&#231;&#227;o fortemente tipada | Microsoft Docs"
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
  - "classes de coleção, derivando de nontemplate"
  - "classes de coleção, baseado em modelo"
  - "classes de coleção, segurança de tipo"
  - "serialização [C++], classes de coleção"
  - "Função SerializeElements"
  - "serializando elementos de classe de coleção"
  - "coleções fortemente tipadas"
ms.assetid: 7230b2db-4283-4083-b098-eb231bf5b89e
caps.latest.revision: 10
caps.handback.revision: 7
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Como fazer uma cole&#231;&#227;o fortemente tipada
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Este artigo explica como fazer coleções de tipo seguras para seus próprios tipos de dados.  Os tópicos incluem:  
  
-   [Usando classes com base na segurança de tipo](#_core_using_template.2d.based_classes_for_type_safety)  
  
-   [Implementando funções auxiliares](#_core_implementing_helper_functions)  
  
-   [Usando classes de coleção de nontemplate](#_core_using_nontemplate_collection_classes)  
  
 A biblioteca de classes do Microsoft fornece as coleções de tipo seguras predefinidas com base em modelos C\+\+.  Como são modelos, essas classes ajudam a fornecer segurança ao tipo e a facilidade de uso sem a conversão do tipo e o outro trabalho adicional envolvidos em usar uma classe de nontemplate para essa finalidade.  O exemplo [COLLECT](../top/visual-cpp-samples.md) MFC demonstra o uso de classes com base na coleção em um aplicativo MFC.  Em geral, use essas classes quando você grava o novo código de coleções.  
  
##  <a name="_core_using_template.2d.based_classes_for_type_safety"></a> Usando classes com base na segurança de tipo  
  
#### Para usar com base em classes  
  
1.  Declare uma variável do tipo de classe de coleção.  Por exemplo:  
  
     [!code-cpp[NVC_MFCCollections#7](../mfc/codesnippet/CPP/how-to-make-a-type-safe-collection_1.cpp)]  
  
2.  Chame as funções de membro do objeto da coleção.  Por exemplo:  
  
     [!code-cpp[NVC_MFCCollections#8](../mfc/codesnippet/CPP/how-to-make-a-type-safe-collection_2.cpp)]  
  
3.  Se necessário, implemente [funções auxiliares](../mfc/reference/collection-class-helpers.md) e [SerializeElements](../Topic/SerializeElements.md).  Para obter informações sobre como implementar essas funções, consulte [Implementando funções auxiliares](#_core_implementing_helper_functions).  
  
 Este exemplo mostra a declaração de uma lista de números inteiros.  O primeiro parâmetro na etapa 1 é o tipo de dados armazenados como elementos na lista.  O segundo parâmetro especifica a maneira como os dados devem ser transmitidos e retornado as funções de membro da coleção, como **Adicionar** e `GetAt`.  
  
##  <a name="_core_implementing_helper_functions"></a> Implementando funções auxiliares  
 A coleção baseada no modelo de classificação `CArray`, `CList`as funções, e globais do auxiliar de uso de cinco `CMap` que você pode personalizar conforme necessário para sua classe derivada da coleção.  Para obter informações sobre essas funções auxiliares, consulte [Auxiliares da classe de coleção](../mfc/reference/collection-class-helpers.md)*na referência de MFC*.  A implementação da função de serialização é necessária para a maioria dos usos das classes com base na coleção.  
  
###  <a name="_core_serializing_elements"></a> Serializando os elementos  
 `CArray`, `CList`, e as classes de `CMap` chamam `SerializeElements` para armazenar os elementos da coleção em ou para lê\-los de um arquivo morto.  
  
 A implementação padrão da função auxiliar de `SerializeElements` faz uma gravação de bit a bit dos objetos no arquivo, ou uma leitura de bit a bit de arquivo morto a objetos, dependendo se objetos estão sendo armazenados em ou recuperados de arquivo morto.  Substituir `SerializeElements` se essa ação não é apropriado.  
  
 Se sua coleção armazena os objetos derivados de `CObject` e você usa a macro de `IMPLEMENT_SERIAL` na implementação da classe do elemento da coleção, você pode se beneficiar da funcionalidade de serialização criada em `CArchive` e em `CObject`:  
  
 [!code-cpp[NVC_MFCCollections#9](../mfc/codesnippet/CPP/how-to-make-a-type-safe-collection_3.cpp)]  
  
 Os operadores sobrecarregados de inserção para `CArchive` chamam `CObject::Serialize` \(ou uma substituição dessa função\) para cada objeto de **CPerson** .  
  
##  <a name="_core_using_nontemplate_collection_classes"></a> Usando classes de coleção de Nontemplate  
 MFC O também oferece suporte às classes de coleção introduzidas com a versão 1,0 MFC.  Essas classes não são baseadas em modelos.  Pode ser usado para conter dados dos tipos com suporte `CObject*`, **UINT**, `DWORD`, e `CString`.  Você pode usar essas coleções predefinidas \(como `CObList`\) para manter coleções de todos os objetos derivados de `CObject`.  MFC O também fornece outras coleções predefinidas para manter tipos primitivos como **UINT** e ponteiros`void`nulos \(\*\).  No entanto, em geral, geralmente é útil definir suas próprias coleções de tipo seguras para reter objetos de uma classe específica e mais de seus derivadas.  Observe que faz isso através das classes de coleção não baseadas em modelos é mais trabalho do que usar as classes com base em log.  
  
 Há duas maneiras de criar coleções de tipo seguros com as coleções de nontemplate:  
  
1.  Use as coleções de nontemplate, com o tipo que converte se necessário.  Essa é a abordagem mais fácil.  
  
2.  Derivar de e estender uma coleção fortemente tipado de nontemplate.  
  
#### Para usar as coleções de nontemplate a conversão do tipo  
  
1.  Use uma das classes de nontemplate, como `CWordArray`, diretamente.  
  
     Por exemplo, você pode criar `CWordArray` e adicionar todos os valores de 32 bits, então fazer.  Não há nada mais fazer.  Você usa apenas a funcionalidade predefinida.  
  
     Você também pode usar uma coleção predefinida, como `CObList`, manter todos os objetos derivados de `CObject`.  Uma coleção de `CObList` é definida para armazenar ponteiros para `CObject`.  Quando você recupera um objeto da lista, você pode precisar converter o resultado com o tipo apropriado como as funções de `CObList` retornam ponteiros a `CObject`.  Por exemplo, se você armazenar objetos de `CPerson` em uma coleção de `CObList` , você precisa converter um elemento recuperado para ser um ponteiro para um objeto de `CPerson` .  O exemplo a seguir usa uma coleção de `CObList` para reter objetos de `CPerson` :  
  
     [!code-cpp[NVC_MFCCollections#10](../mfc/codesnippet/CPP/how-to-make-a-type-safe-collection_4.cpp)]  
  
     Essa técnica de usar um tipo predefinido da coleção e de converter conforme necessário pode ser suficiente para muitas de suas necessidades da coleção.  Se você precisar de uma funcionalidade adicional ou um mais segurança do tipo, use uma classe baseada no modelo de, ou siga o procedimento a seguir.  
  
#### Para derivar e estender uma coleção de nontemplate fortemente tipado  
  
1.  Derivar sua própria classe de coleção em uma das classes predefinidas de nontemplate.  
  
     Quando você deve derivar a sua classe, você pode adicionar funções de tipo seguras de invólucro para fornecer uma interface fortemente tipado as funções existentes.  
  
     Por exemplo, se você derivadas uma lista de `CObList` para reter objetos de `CPerson` , você pode adicionar as funções `AddHeadPerson` e `GetHeadPerson`de wrapper, como mostrado abaixo.  
  
     [!code-cpp[NVC_MFCCollections#11](../mfc/codesnippet/CPP/how-to-make-a-type-safe-collection_5.h)]  
  
     Essas funções de invólucro fornecem uma maneira fortemente tipado de adicionar e recuperar objetos de `CPerson` da lista derivada.  Você pode ver isso para a função de `GetHeadPerson` , você está encapsulando somente a conversão do tipo.  
  
     Você também pode adicionar nova funcionalidade definindo as novas funções que ampliam os recursos da coleção em vez de apenas envolvendo a funcionalidade existente em wrappers tipo seguro.  Por exemplo, o artigo [Excluindo todos os objetos em uma coleção de CObject](../Topic/Deleting%20All%20Objects%20in%20a%20CObject%20Collection.md) descreve uma função para excluir todos os objetos contidos em uma lista.  Esta função pode ser adicionada à classe derivada como uma função de membro.  
  
## Consulte também  
 [Coleções](../mfc/collections.md)