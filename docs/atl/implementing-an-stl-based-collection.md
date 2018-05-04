---
title: Implementação de uma coleção de baseado em biblioteca padrão C++ | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-atl
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- ICollectionOnSTLImpl interface
ms.assetid: 6d49f819-1957-4813-b074-3f12c494d8ca
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 14a09f54598b525346a65b56a335711f114878cb
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
---
# <a name="implementing-a-c-standard-library-based-collection"></a>Implementação de uma coleção de baseado em biblioteca padrão C++
ATL fornece o `ICollectionOnSTLImpl` interface para permitir que você implemente rapidamente interfaces de coleção com base em biblioteca padrão C++ em seus objetos. Para entender como funciona a essa classe, você trabalhará através de um exemplo simples (abaixo) que usa essa classe para implementar uma coleção somente leitura destinada a clientes de automação.  
  
 O código de exemplo é do [ATLCollections exemplo](../visual-cpp-samples.md).  
  
 Para concluir este procedimento, você irá:  
  
-   [Gerar um novo objeto simples](#vccongenerating_an_object).  
  
-   [Edite o arquivo IDL](#vcconedit_the_idl) para a interface gerada.  
  
-   [Criar definições de cinco tipo](#vcconstorage_and_exposure_typedefs) que descreve como os itens de coleta são armazenados e como eles serão expostos aos clientes por meio de interfaces COM.  
  
-   [Criar duas definições de tipo para cópia de classes de política](#vcconcopy_classes).  
  
-   [Criar definições de tipo para as implementações de enumerador e coleção](#vcconenumeration_and_collection).  
  
-   [Editar o código de C++ geradas pelo Assistente para usar o coleção typedef](#vcconedit_the_generated_code).  
  
-   [Adicione código para preencher a coleção](#vcconpopulate_the_collection).  
  
##  <a name="vccongenerating_an_object"></a> Gerar um novo objeto Simple  
 Crie um novo projeto, garantindo que a caixa de atributos em configurações do aplicativo está desmarcada. Use a caixa de diálogo Adicionar classe de ATL e adicionar Assistente de objeto simples para gerar um objeto simples chamado `Words`. Certifique-se de que uma interface dupla chamado `IWords` é gerado. Objetos da classe gerada serão ser usados para representar um conjunto de palavras (isto é, cadeias de caracteres).  
  
##  <a name="vcconedit_the_idl"></a> Editando o arquivo IDL  
 Agora, abra o arquivo IDL e adicione as três propriedades necessárias para ativar `IWords` em uma interface de coleção somente leitura, conforme mostrado abaixo:  
  
 [!code-cpp[NVC_ATL_COM#24](../atl/codesnippet/cpp/implementing-an-stl-based-collection_1.idl)]  
  
 Este é o formulário padrão para uma interface de coleção somente leitura criado com clientes de automação em mente. Os comentários numerados nesta definição de interface correspondem aos comentários abaixo:  
  
1.  Interfaces de coleção são geralmente duplas como clientes de automação acessa o `_NewEnum` propriedade via **IDispatch:: Invoke**. No entanto, os clientes de automação poderá acessar os métodos restantes via vtable, portanto preferível dispinterfaces interfaces duplas.  
  
2.  Se uma interface dual ou dispinterface não será estendido em tempo de execução (ou seja, você não fornecer extras métodos ou propriedades por meio de **IDispatch:: Invoke**), você deve aplicar o **nonextensible** atributo sua definição. Este atributo permite que os clientes de automação executar a verificação de código completo em tempo de compilação. Nesse caso, a interface não deve ser estendida.  
  
3.  O DISPID correto é importante se você desejar que clientes de automação para poder usar essa propriedade. (Observe que há apenas um sublinhado no **DISPID_NEWENUM**.)  
  
4.  Você pode fornecer qualquer valor como DISPID do **Item** propriedade. No entanto, **Item** geralmente usa **DISPID_VALUE** para tornar a propriedade padrão da coleção. Isso permite que os clientes de automação fazer referência à propriedade sem nomeá-lo explicitamente.  
  
5.  O tipo de dados usado para o valor de retorno de **Item** propriedade é o tipo de item armazenado na coleção que clientes COM interessam. A interface retorna cadeias de caracteres, então você deve usar o tipo de cadeia de caracteres COM, `BSTR`. Você pode armazenar os dados em um formato diferente internamente como você verá em breve.  
  
6.  O valor usado para DISPID do **contagem** propriedade é completamente arbitrária. Não há nenhum DISPID padrão para essa propriedade.  
  
##  <a name="vcconstorage_and_exposure_typedefs"></a> Criando definições de tipo para armazenamento e a exposição  
 Quando a interface da coleção é definida, você precisa decidir como os dados serão armazenados e como os dados serão expostos por meio do enumerador.  
  
 As respostas a essas perguntas podem ser fornecidas na forma de um número de definições de tipo, que pode ser adicionado na parte superior do arquivo de cabeçalho para a classe recém-criada:  
  
 [!code-cpp[NVC_ATL_COM#25](../atl/codesnippet/cpp/implementing-an-stl-based-collection_2.h)]  
  
 Nesse caso, você armazenará os dados como um **std:: Vector** de **std::string**s. **std:: Vector** é uma classe de contêiner de biblioteca padrão C++ se comporta como uma matriz gerenciada. **std::string** é a classe de cadeia de caracteres da biblioteca padrão C++. Essas classes tornam mais fácil trabalhar com uma coleção de cadeias de caracteres.  
  
 Como suporte ao Visual Basic é essencial para o sucesso desta interface, o enumerador retornado pelo `_NewEnum` deve oferecer suporte à propriedade de **IEnumVARIANT** interface. Essa é a interface de enumerador somente entendida pelo Visual Basic.  
  
##  <a name="vcconcopy_classes"></a> Criando definições de tipo para Classes de política de cópia  
 Definições de tipo que você criou até agora fornecem todas as informações que você precisa criar mais definições de tipo para as classes de cópia que serão usadas pelo enumerador e coleção:  
  
 [!code-cpp[NVC_ATL_COM#26](../atl/codesnippet/cpp/implementing-an-stl-based-collection_3.h)]  
  
 Neste exemplo, você pode usar personalizado `GenericCopy` classe definida em VCUE_Copy.h e VCUE_CopyString.h da [ATLCollections](../visual-cpp-samples.md) exemplo. Você pode usar essa classe em outro código, mas talvez seja necessário definir ainda mais especializações de `GenericCopy` para dar suporte a tipos de dados usados em suas próprias coleções. Para obter mais informações, consulte [Classes da ATL cópia política](../atl/atl-copy-policy-classes.md).  
  
##  <a name="vcconenumeration_and_collection"></a> Criando definições de tipo de enumeração e coleção  
 Agora todos os parâmetros de modelo necessários para especializar o `CComEnumOnSTL` e `ICollectionOnSTLImpl` classes para essa situação foram fornecidos na forma de definições de tipo. Para simplificar o uso dos especializações, crie duas typedefs mais conforme mostrado abaixo:  
  
 [!code-cpp[NVC_ATL_COM#27](../atl/codesnippet/cpp/implementing-an-stl-based-collection_4.h)]  
  
 Agora `CollectionType` é um sinônimo para uma especialização de `ICollectionOnSTLImpl` que implementa o `IWords` interface definidas anteriormente e fornece um enumerador que dá suporte a **IEnumVARIANT**.  
  
##  <a name="vcconedit_the_generated_code"></a> Editar o código gerado pelo Assistente  
 Agora você deve derivar `CWords` da implementação da interface representada pelo `CollectionType` typedef em vez de `IWords`, conforme mostrado abaixo:  
  
 [!code-cpp[NVC_ATL_COM#28](../atl/codesnippet/cpp/implementing-an-stl-based-collection_5.h)]  
  
##  <a name="vcconpopulate_the_collection"></a> Adicionando código para preencher a coleção  
 É a única coisa que permanece preencher o vetor com dados. Neste exemplo simples, você pode adicionar algumas palavras para a coleção no construtor da classe:  
  
 [!code-cpp[NVC_ATL_COM#29](../atl/codesnippet/cpp/implementing-an-stl-based-collection_6.h)]  
  
 Agora, você pode testar o código com o cliente de sua escolha.  
  
## <a name="see-also"></a>Consulte também  
 [Coleções e enumeradores](../atl/atl-collections-and-enumerators.md)   
 [Exemplo de ATLCollections](../visual-cpp-samples.md)   
 [Classes de política de cópia da ATL](../atl/atl-copy-policy-classes.md)

