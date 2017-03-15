---
title: "Implementando uma cole&#231;&#227;o com base STL- | Microsoft Docs"
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
  - "Interface de ICollectionOnSTLImpl"
ms.assetid: 6d49f819-1957-4813-b074-3f12c494d8ca
caps.latest.revision: 12
caps.handback.revision: 7
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Implementando uma cole&#231;&#227;o com base STL-
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

ATL fornece a interface de `ICollectionOnSTLImpl` para permitir que você rapidamente implementar interfaces com base na coleção de \(STL\) de biblioteca padrão do modelo em seus objetos.  Para entender como essa classe funciona, você trabalhará com um exemplo simples \(abaixo\) que usa essa classe implementar clientes voltadas para uma coleção somente leitura de automação.  
  
 O código de exemplo é de [exemplo de ATLCollections](../top/visual-cpp-samples.md).  
  
 Para concluir este procedimento, você:  
  
-   [Gerar um novo objeto simples](#vccongenerating_an_object).  
  
-   [Edite o arquivo de IDL](#vcconedit_the_idl) para a interface gerado.  
  
-   [crie cinco typedefs](#vcconstorage_and_exposure_typedefs) que descreve como os itens de coleção são armazenados e como eles serão expostos aos clientes através da interface.  
  
-   [Crie dois typedefs para classes de diretiva de impressão](#vcconcopy_classes).  
  
-   [Crie typedefs para as implementações do enumerador e de coleção](#vcconenumeration_and_collection).  
  
-   [Editar o código gerado assistentes C\+\+ para usar o typedef de coleção](#vcconedit_the_generated_code).  
  
-   [Adicione código para preencher a coleção](#vcconpopulate_the_collection).  
  
##  <a name="vccongenerating_an_object"></a> Gerando um novo objeto simples  
 Crie um novo projeto, garantindo que a caixa de atributos em configurações de aplicativo está desmarcada.  Use o ATL adiciona a caixa de diálogo da classe e adiciona o assistente simples do objeto para gerar um objeto simples chamado `Words`.  Certifique\-se de que uma interface dupla chamada `IWords` é gerada.  Os objetos da classe gerada serão usados para representar uma coleção da palavra \(isto é, cadeias de caracteres\).  
  
##  <a name="vcconedit_the_idl"></a> Editando o Arquivo IDL  
 Agora, abra o arquivo de IDL e adicione as três propriedades necessárias para transformar `IWords` em uma interface somente leitura de coleção, como mostrado abaixo:  
  
 [!code-cpp[NVC_ATL_COM#24](../atl/codesnippet/CPP/implementing-an-stl-based-collection_1.idl)]  
  
 Este é o formulário padrão para uma interface somente leitura de coleção criada com clientes de automação em mente.  Os comentários numerados em esta definição de interface correspondem aos comentários em:  
  
1.  As interfaces duais de coleção são geralmente porque os clientes de automação acessam a propriedade de `_NewEnum` através de **IDispatch::Invoke**.  Em o entanto, os clientes de automação podem acessar os métodos restantes através de vtable, para que as interfaces duais são preferíveis a dispinterfaces.  
  
2.  Se uma interface dupla ou um dispinterface não serão estendidos em tempo de execução \(ou seja, você não irá fornecer métodos adicionais ou propriedades através de **IDispatch::Invoke**\), você deve aplicar o atributo de **nonextensible** a sua definição.  Esse atributo permite que clientes de automação para executar em tempo de compilação completa a verificação de código.  Em esse caso, a interface não deve ser estendido.  
  
3.  O DISPID correto é importante se você deseja clientes de automação para poder usar essa propriedade.  \(Observe que há apenas um sublinhado em **DISPID\_NEWENUM**.\)  
  
4.  Você pode fornecer qualquer como o valor DISPID da propriedade de **Item** .  Em o entanto, **Item** normalmente usa **DISPID\_VALUE** para fazer\-lhe a propriedade padrão.  Isso permite que os clientes de automação se referirem a propriedade sem nomeá\-la explicitamente.  
  
5.  O tipo de dados usado para valores de retorno da propriedade de **Item** é o tipo de item armazenado na coleção tanto quanto os clientes COM.  A interface retorna cadeias de caracteres, portanto você deve usar o tipo cadeia de caracteres do padrão COM, `BSTR`.  Você pode armazenar os dados em um formato diferente internamente como será visto brevemente.  
  
6.  O usado para o valor DISPID da propriedade de **Contagem** é completamente arbitrário.  Não há padrão DISPID para essa propriedade.  
  
##  <a name="vcconstorage_and_exposure_typedefs"></a> Criando Typedefs para armazenamento e a exposição  
 Uma vez que a interface da coleção é definida, você precisa decidir como os dados serão armazenados, e como os dados serão expostas através de enumeração.  
  
 As respostas a essas perguntas podem ser fornecidas na forma de um número de typedefs, que você pode adicionar próximo à parte superior do arquivo de cabeçalho para sua classe recém\-criado:  
  
 [!code-cpp[NVC_ATL_COM#25](../atl/codesnippet/CPP/implementing-an-stl-based-collection_2.h)]  
  
 Em esse caso, você irá armazenar os dados como **std::vector** de **std::string**S.  **std::vector** é uma classe do contêiner de STL que se comporta como uma matriz gerenciado.  **std::string** é a classe de cadeia de caracteres da biblioteca do C\+\+ padrão.  Essas classes facilitam trabalhar com uma coleção de cadeias de caracteres.  
  
 Desde que o suporte do Visual Basic é vital para o sucesso de essa interface, o enumerador retornado pela propriedade de `_NewEnum` deve oferecer suporte a interface de **IEnumVARIANT** .  Esta é a única interface de enumerador compreendido pelo Visual Basic.  
  
##  <a name="vcconcopy_classes"></a> Criando Typedefs para classes de diretiva de impressão  
 Os typedefs que você criou até agora fornecem todas as informações que você precisa criar um typedefs adicionais para as classes de impressão que serão usadas pelo enumerador e a coleção:  
  
 [!code-cpp[NVC_ATL_COM#26](../atl/codesnippet/CPP/implementing-an-stl-based-collection_3.h)]  
  
 Em esse exemplo, você pode usar a classe de `GenericCopy` personalizada definida em VCUE\_Copy.h e em VCUE\_CopyString.h do exemplo de [ATLCollections](../top/visual-cpp-samples.md) .  Você pode usar esta classe no outro código, mas você pode precisar definir uma especializações adicionais de `GenericCopy` para oferecer suporte aos tipos de dados usados em suas próprias coleções.  Para obter mais informações, consulte [Classes de diretiva de impressão de ATL](../Topic/ATL%20Copy%20Policy%20Classes.md).  
  
##  <a name="vcconenumeration_and_collection"></a> Criando Typedefs para a enumeração e da coleção  
 Agora todos os parâmetros de modelo necessários especializar as classes de `CComEnumOnSTL` e de `ICollectionOnSTLImpl` para essa situação foram fornecidos na forma de typedefs.  Para simplificar o uso de especializações, crie dois mais typedefs como mostrado abaixo:  
  
 [!code-cpp[NVC_ATL_COM#27](../atl/codesnippet/CPP/implementing-an-stl-based-collection_4.h)]  
  
 Agora `CollectionType` é um sinónimo para uma especialização de `ICollectionOnSTLImpl` que implementa o definido anteriormente interface de `IWords` e fornece um enumerador que suporte **IEnumVARIANT**.  
  
##  <a name="vcconedit_the_generated_code"></a> Editando código Gerado assistentes  
 Agora você deve derivar `CWords` de implementação de interface representada pelo typedef de `CollectionType` em vez de `IWords`, como mostrado abaixo:  
  
 [!code-cpp[NVC_ATL_COM#28](../atl/codesnippet/CPP/implementing-an-stl-based-collection_5.h)]  
  
##  <a name="vcconpopulate_the_collection"></a> Adicionando código para preencher a coleção  
 A única coisa que resta é preencher o vetor com dados.  Em esse exemplo simples, você pode adicionar algumas palavra à coleção no construtor para a classe:  
  
 [!code-cpp[NVC_ATL_COM#29](../atl/codesnippet/CPP/implementing-an-stl-based-collection_6.h)]  
  
 Agora, você pode testar o código com o cliente de sua escolha.  
  
## Consulte também  
 [Coleções e enumeradores](../atl/atl-collections-and-enumerators.md)   
 [exemplo de ATLCollections](../top/visual-cpp-samples.md)   
 [Classes de política de cópia do ATL](../Topic/ATL%20Copy%20Policy%20Classes.md)