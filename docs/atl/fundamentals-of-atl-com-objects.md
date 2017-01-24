---
title: "Fundamentos de objetos COM de ATL | Microsoft Docs"
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
  - "Objetos COM de ATL"
  - "ATL, COM"
  - "objetos COM, ATL"
  - "COM, e ATL"
ms.assetid: 0f9c9d98-cc28-45da-89ac-dc94cee422fe
caps.latest.revision: 25
caps.handback.revision: 20
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Fundamentos de objetos COM de ATL
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

A ilustração a seguir descrevem a relação entre as classes e interfaces que são usadas para definir um objeto COM de ATL.  
  
 ![Estrutura do ATL](../atl/media/vc307y1.png "vc307Y1")  
  
> [!NOTE]
>  Este diagrama mostra `CComObject` que é derivado de `CYourClass` enquanto `CComAggObject` e `CComPolyObject` incluem `CYourClass` como um variável de membro.  
  
 Existem três maneiras para definir um objeto COM de ATL.  a opção padrão é usar a classe de `CComObject` que é derivada de `CYourClass`.  a segunda opção é criar um objeto agregado usando a classe de `CComAggObject` .  a terceira opção é usar a classe de `CComPolyObject` .  `CComPolyObject` atua como um híbrido: pode funcionar como uma classe de `CComObject` ou como uma classe de `CComAggObject` , dependendo de como é projetado principalmente.  Para obter mais informações sobre como usar a classe de `CComPolyObject` , consulte [Classe de CComPolyObject](../atl/reference/ccompolyobject-class.md).  
  
 Quando você usa o padrão ATL COM, você usa dois objetos: um objeto externo e um objeto interno.  Os clientes externos acesso à funcionalidade interna de objeto com as funções do wrapper que são definidas no objeto externo.  O objeto externo é do tipo `CComObject`.  
  
 Quando você usa um objeto agregado, o objeto externo não fornece os wrappers para a funcionalidade interna do objeto.  Em vez de isso, o objeto externo fornece um ponteiro que é acessado diretamente por clientes externos.  Em esse cenário, o objeto externo é do tipo `CComAggObject`.  O objeto interno é um variável de membro objeto externo, e é do tipo `CYourClass`.  
  
 Porque o cliente não precisa passar pelo objeto externo interagir com o objeto interno, os objetos agregados são geralmente mais eficientes.  Além de isso, o objeto externo não precisa saber a funcionalidade do objeto agregado, dado que a interface do objeto diretamente agregado está disponível para o cliente.  Em o entanto, nem todos os objetos podem ser agregados.  Para que um objeto seja, agregado precisam ser criado com agregação em mente.  
  
 ATL implementa [IUnknown](http://msdn.microsoft.com/library/windows/desktop/ms680509) em dois estágios:  
  
-   Implementa de[CComObject](../atl/reference/ccomobject-class.md), de [CComAggObject](../atl/reference/ccomaggobject-class.md), ou de [CComPolyObject](../atl/reference/ccompolyobject-class.md) os métodos de **IUnknown** .  
  
-   [CComObjectRoot](../atl/reference/ccomobjectroot-class.md) ou [CComObjectRootEx](../atl/reference/ccomobjectrootex-class.md) gerenciam a contagem de referência e ponteiros fora de **IUnknown**.  
  
 Outros aspectos do seu objeto COM de ATL são tratados por outras classes:  
  
-   [CComCoClass](../Topic/CComCoClass%20Class.md) define o modelo padrão de fábrica e de distribuição da classe do objeto.  
  
-   [IDispatchImpl](../atl/reference/idispatchimpl-class.md) fornece uma implementação padrão de parte de `IDispatch Interface` de todas as interfaces duais no objeto.  
  
-   [ISupportErrorInfoImpl](../atl/reference/isupporterrorinfoimpl-class.md) implementa a interface de **ISupportErrorInfo** que garante que as informações de erro pode ser propagadas acima da cadeia de chamada corretamente.  
  
## Nesta seção  
 [implementando CComObjectRootEx](../Topic/Implementing%20CComObjectRootEx.md)  
 Entradas do mapa da do exemplo de apresentação para implementar `CComObjectRootEx`.  
  
 [implementando CComObject, CComAggObject, e CComPolyObject](../atl/implementing-ccomobject-ccomaggobject-and-ccompolyobject.md)  
 Discute como macros de **DECLARE\_\*\_AGGREGATABLE** afetam o uso de `CComObject`, de `CComAggObject`, e de `CComPolyObject`.  
  
 [Suporte IDispatch e IErrorInfo](../atl/supporting-idispatch-and-ierrorinfo.md)  
 Lista as classes de implementação de ATL para usar o para oferecer suporte `IDispatch` e **IErrorInfo** interfaces.  
  
 [Suporte IDispEventImpl](../atl/supporting-idispeventimpl.md)  
 Discute as etapas para implementar um ponto de conexão para a classe.  
  
 [Modificando o modelo padrão de fábrica e de distribuição de classe](../atl/changing-the-default-class-factory-and-aggregation-model.md)  
 Apresentação que macros a usar para alterar o factory e a agregação padrão da classe modelar.  
  
 [criando um objeto agregado](../atl/creating-an-aggregated-object.md)  
 Lista as etapas para criar um objeto agregado.  
  
## Seções relacionadas  
 [criando um projeto de ATL](../atl/reference/creating-an-atl-project.md)  
 Fornece informações sobre a criação de um objeto através de ATL.  
  
 [ATL](../atl/active-template-library-atl-concepts.md)  
 Fornece links para tópicos conceituais sobre como programar usando a biblioteca ativa do modelo.  
  
## Consulte também  
 [Conceitos](../atl/active-template-library-atl-concepts.md)