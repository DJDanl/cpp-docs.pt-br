---
title: "Acessando todos os membros de uma coleção | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
dev_langs:
- C++
helpviewer_keywords:
- MFC, collections
- enumerations [MFC]
- enumerating collections [MFC]
- collections [MFC], accessing
- collection classes [MFC]
- ', '
- ', '
- ', '
- ', '
- ', '
- ', '
- ', '
ms.assetid: 7bbae518-062e-4393-81f9-b22abd2e5f59
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 34ba2795c12695702b2e38034081e17d69c156d4
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="accessing-all-members-of-a-collection"></a>Acessando todos os membros de uma coleção
As classes de coleção MFC matriz — ambos baseado em modelo e não — usa índices para acessar seus elementos. As classes de coleção MFC lista e mapa — ambos baseado em modelo e não — use um indicador do tipo **posição** para descrever a posição especificada dentro da coleção. Para acessar um ou mais membros dessas coleções, você primeiro inicializar o indicador de posição repetidamente passa essa posição na coleção e peça-lo para retornar o próximo elemento. A coleção não é responsável por manter informações de estado sobre o progresso da iteração. Essa informação é mantida no indicador de posição. Mas, dada uma posição específica, a coleção é responsável por retornar o próximo elemento.  
  
 Os procedimentos a seguir mostram como iterar nos três principais tipos de coleções fornecidos com MFC:  
  
-   [Iteração de uma matriz](#_core_to_iterate_an_array)  
  
-   [Iteração de uma lista](#_core_to_iterate_a_list)  
  
-   [Iteração de um mapa](#_core_to_iterate_a_map)  
  
### <a name="_core_to_iterate_an_array"></a>Para repetir uma matriz  
  
1.  Usar números sequenciais de índice com o `GetAt` função de membro:  
  
     [!code-cpp[NVC_MFCCollections#12](../mfc/codesnippet/cpp/accessing-all-members-of-a-collection_1.cpp)]  
  
     Este exemplo usa uma matriz de ponteiro tipado que contém ponteiros para `CPerson` objetos. A matriz é derivada da classe `CObArray`, um de nontemplate classes predefinidas. `GetAt`Retorna um ponteiro para um `CPerson` objeto. Para classes de coleção do tipo ponteiro — matrizes ou listas — o primeiro parâmetro especifica a classe base; o segundo parâmetro especifica o tipo para armazenar.  
  
     O `CTypedPtrArray` classe também sobrecargas de **[]** operador para que você pode usar a sintaxe de subscrito de matriz habitual para acessar elementos de uma matriz. Uma alternativa à instrução no corpo do `for` está acima do loop  
  
     [!code-cpp[NVC_MFCCollections#13](../mfc/codesnippet/cpp/accessing-all-members-of-a-collection_2.cpp)]  
  
     Este operador existe em **const** e não-**const** versões. O **const** versão, o que é invocado para **const** matrizes, pode aparecer somente no lado direito de uma instrução de atribuição.  
  
### <a name="_core_to_iterate_a_list"></a>Para repetir uma lista  
  
1.  Use as funções de membro `GetHeadPosition` e `GetNext` para examinar a lista:  
  
     [!code-cpp[NVC_MFCCollections#14](../mfc/codesnippet/cpp/accessing-all-members-of-a-collection_3.cpp)]  
  
     Este exemplo usa uma lista de tipo de ponteiro para contêm ponteiros para `CPerson` objetos. A declaração de lista é semelhante a uma matriz no procedimento de [para uma matriz de iterar](#_core_to_iterate_an_array) , mas é derivado da classe `CObList`. `GetNext`Retorna um ponteiro para um `CPerson` objeto.  
  
### <a name="_core_to_iterate_a_map"></a>Para fazer a iteração de um mapa  
  
1.  Use `GetStartPosition` para ir para o início do mapa e `GetNextAssoc` repetidamente obter a próxima chave e valor do mapa, conforme mostrado pelo exemplo a seguir:  
  
     [!code-cpp[NVC_MFCCollections#15](../mfc/codesnippet/cpp/accessing-all-members-of-a-collection_4.cpp)]  
  
     Este exemplo usa um modelo simples de mapa (em vez de uma coleção de tipo ponteiro) que usa `CString` chaves e armazena ponteiros para `CPerson` objetos. Quando você usa funções de acesso como `GetNextAssoc`, a classe fornece ponteiros para `CPerson` objetos. Se você usar uma das coleções de mapa de nontemplate em vez disso, você deve converter retornado `CObject` ponteiro para um ponteiro para um `CPerson`.  
  
    > [!NOTE]
    >  Para mapas de nontemplate, o compilador requer uma referência a um `CObject` ponteiro no último parâmetro para `GetNextAssoc`. Na entrada, você deve converter os ponteiros para tipo, conforme mostrado no exemplo a seguir.  
  
     A solução de modelo é mais simples e ajuda a fornecer a melhor segurança de tipos. O código de nontemplate é mais complicado, como você pode ver aqui:  
  
     [!code-cpp[NVC_MFCCollections#16](../mfc/codesnippet/cpp/accessing-all-members-of-a-collection_5.cpp)]  
  
 Para obter mais informações, consulte [excluir todos os objetos em uma coleção CObject](../mfc/deleting-all-objects-in-a-cobject-collection.md).  
  
## <a name="see-also"></a>Consulte também  
 [Coleções](../mfc/collections.md)

