---
title: 'Como: fazer uma coleção fortemente tipada | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- type-safe collections [MFC]
- serializing collection-class elements [MFC]
- collection classes [MFC], type safety
- SerializeElements function [MFC]
- collection classes [MFC], template-based
- serialization [MFC], collection classes
- collection classes [MFC], deriving from nontemplate
ms.assetid: 7230b2db-4283-4083-b098-eb231bf5b89e
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 1cbcdeec6e39e104625d1b5d47c494915a821d38
ms.sourcegitcommit: 060f381fe0807107ec26c18b46d3fcb859d8d2e7
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/25/2018
ms.locfileid: "36930027"
---
# <a name="how-to-make-a-type-safe-collection"></a>Como fazer uma coleção fortemente tipada
Este artigo explica como criar coleções fortemente tipadas para seus próprios tipos de dados. Os tópicos incluem:  
  
-   [Usando classes com base no modelo de segurança de tipo](#_core_using_template.2d.based_classes_for_type_safety)  
  
-   [Implementando funções auxiliares](#_core_implementing_helper_functions)  
  
-   [Usando classes de coleção de nontemplate](#_core_using_nontemplate_collection_classes)  
  
 A biblioteca Microsoft Foundation Class fornece coleções fortemente tipadas predefinidas com base em modelos do C++. Como são modelos, essas classes ajudam a fornecer a segurança de tipo e a facilidade de uso sem a conversão de tipo e outro trabalho extra envolvidos no uso de uma classe nontemplate para essa finalidade. O exemplo MFC [COLETAR](../visual-cpp-samples.md) demonstra o uso de classes de coleção com base em modelo em um aplicativo MFC. Em geral, use essas classes sempre que você escrever novo código de coleções.  
  
##  <a name="_core_using_template.2d.based_classes_for_type_safety"></a> Usando Classes com base no modelo de segurança de tipo  
  
#### <a name="to-use-template-based-classes"></a>Para usar classes com base no modelo  
  
1.  Declare uma variável do tipo de classe de coleção. Por exemplo:  
  
     [!code-cpp[NVC_MFCCollections#7](../mfc/codesnippet/cpp/how-to-make-a-type-safe-collection_1.cpp)]  
  
2.  Chame o membro de funções do objeto da coleção. Por exemplo:  
  
     [!code-cpp[NVC_MFCCollections#8](../mfc/codesnippet/cpp/how-to-make-a-type-safe-collection_2.cpp)]  
  
3.  Se necessário, implemente o [funções auxiliares](../mfc/reference/collection-class-helpers.md) e [SerializeElements](../mfc/reference/collection-class-helpers.md#serializeelements). Para obter informações sobre a implementação dessas funções, consulte [implementando funções de auxiliar](#_core_implementing_helper_functions).  
  
 Este exemplo mostra a declaração de uma lista de números inteiros. O primeiro parâmetro na etapa 1 é o tipo de dados armazenados como elementos da lista. O segundo parâmetro especifica como os dados são passados para e retornadas de funções de membro da classe de coleção, como `Add` e `GetAt`.  
  
##  <a name="_core_implementing_helper_functions"></a> Implementando funções auxiliares  
 As classes de coleção com base em modelo `CArray`, `CList`, e `CMap` usar cinco funções de auxiliar global que você pode personalizar conforme necessário para sua classe derivada de coleção. Para obter informações sobre essas funções de auxiliar, consulte [auxiliares da classe de coleção](../mfc/reference/collection-class-helpers.md) no *referência MFC*. Implementação da função de serialização é necessária para a maioria dos usos das classes de coleção com base em modelo.  
  
###  <a name="_core_serializing_elements"></a> Serializando elementos  
 O `CArray`, `CList`, e `CMap` classes chamada `SerializeElements` para armazenar elementos de coleção ou lê-los de um arquivo.  
  
 A implementação padrão da `SerializeElements` função auxiliar não uma gravação de bit a bit dos objetos para o arquivamento ou de leitura do arquivo morto para os objetos, dependendo se os objetos estão sendo armazenados em um bit a bit ou recuperada do arquivo morto. Substituir `SerializeElements` se essa ação não é apropriada.  
  
 Se sua coleção armazena objetos derivados de `CObject` e você usar o `IMPLEMENT_SERIAL` macro na implementação da classe de elemento de coleção, você pode tirar proveito da funcionalidade de serialização incorporado `CArchive` e `CObject`:  
  
 [!code-cpp[NVC_MFCCollections#9](../mfc/codesnippet/cpp/how-to-make-a-type-safe-collection_3.cpp)]  
  
 Os operadores de inserção sobrecarregado para `CArchive` chamar `CObject::Serialize` (ou uma substituição dessa função) para cada `CPerson` objeto.  
  
##  <a name="_core_using_nontemplate_collection_classes"></a> Usando Classes de coleção de Nontemplate  
 MFC também oferece suporte as classes de coleção introduzidas com a versão 1.0 do MFC. Essas classes não são baseadas em modelos. Eles podem ser usados para conter dados dos tipos suportados `CObject*`, `UINT`, `DWORD`, e `CString`. Você pode usar essas coleções predefinidas (como `CObList`) para armazenar coleções de qualquer objeto derivado de `CObject`. MFC também fornece outras coleções predefinidas para conter tipos primitivos como `UINT` e ponteiros de void (`void`*). Em geral, no entanto, geralmente é útil definir suas próprias coleções fortemente tipadas para armazenar objetos de uma classe mais específica e seus derivados. Observe que não fazer isso com as classes de coleção com base em modelos mais trabalho do que usar as classes de modelo.  
  
 Há duas maneiras de criar coleções fortemente tipadas com as coleções de nontemplate:  
  
1.  Use as coleções de nontemplate, com conversão de tipo, se necessário. Essa é a abordagem mais fácil.  
  
2.  Derivam e estender uma coleção fortemente tipada de nontemplate.  
  
#### <a name="to-use-the-nontemplate-collections-with-type-casting"></a>Para usar as coleções de nontemplate com conversão de tipo  
  
1.  Use uma das classes de nontemplate, como `CWordArray`, diretamente.  
  
     Por exemplo, você pode criar um `CWordArray` adicionar quaisquer valores de 32 bits para ele e recuperá-las. Não há mais fazer nada. Você simplesmente usar a funcionalidade predefinida.  
  
     Você também pode usar uma coleção predefinida, como `CObList`, para armazenar qualquer objeto derivado de `CObject`. Um `CObList` coleta está definida para conter os ponteiros para `CObject`. Quando você recupera um objeto na lista, talvez você precise converter o resultado para o tipo adequado desde o `CObList` retornarão ponteiros para `CObject`. Por exemplo, se você armazenar `CPerson` objetos em um `CObList` coleção, você precisa converter um elemento recuperado para ser um ponteiro para um `CPerson` objeto. O exemplo a seguir usa uma `CObList` coleção para manter `CPerson` objetos:  
  
     [!code-cpp[NVC_MFCCollections#10](../mfc/codesnippet/cpp/how-to-make-a-type-safe-collection_4.cpp)]  
  
     Essa técnica de uso de um tipo de coleção predefinida e conversão conforme necessário, pode ser adequada para muitas das suas necessidades de coleção. Se você precisar de funcionalidade adicional ou mais segurança de tipo, usar uma classe com base em modelo, ou siga o procedimento a seguir.  
  
#### <a name="to-derive-and-extend-a-nontemplate-type-safe-collection"></a>Para derivar e estender uma coleção fortemente tipada de nontemplate  
  
1.  Derive sua própria classe de coleção de uma das classes de nontemplate predefinidos.  
  
     Quando você derivar de sua classe, você pode adicionar funções de invólucro de tipo seguro para fornecer uma interface de tipo seguro para as funções existentes.  
  
     Por exemplo, se você derivado de uma lista de `CObList` para manter `CPerson` objetos, você pode adicionar as funções de invólucro `AddHeadPerson` e `GetHeadPerson`, conforme mostrado abaixo.  
  
     [!code-cpp[NVC_MFCCollections#11](../mfc/codesnippet/cpp/how-to-make-a-type-safe-collection_5.h)]  
  
     Essas funções de wrapper fornecem uma maneira de tipo seguro para adicionar e recuperar `CPerson` objetos da lista derivada. Você pode ver que para o `GetHeadPerson` função, é simplesmente encapsulando a conversão de tipo.  
  
     Você também pode adicionar novas funcionalidades definindo novas funções que estendem os recursos da coleção em vez de apenas envolvendo a funcionalidade existente nos wrappers fortemente tipado. Por exemplo, o artigo [excluir todos os objetos em uma coleção CObject](../mfc/deleting-all-objects-in-a-cobject-collection.md) descreve uma função para excluir todos os objetos contidos em uma lista. Essa função foi adicionada à classe derivada como uma função de membro.  
  
## <a name="see-also"></a>Consulte também  
 [Coleções](../mfc/collections.md)

