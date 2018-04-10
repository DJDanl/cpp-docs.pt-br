---
title: Conceitos básicos de ATL COM objetos | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.reviewer: ''
ms.suite: ''
ms.technology:
- cpp-windows
ms.tgt_pltfrm: ''
ms.topic: article
dev_langs:
- C++
helpviewer_keywords:
- COM, and ATL
- ATL, COM
- ATL COM objects
- COM objects, ATL
ms.assetid: 0f9c9d98-cc28-45da-89ac-dc94cee422fe
caps.latest.revision: 25
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 6a5a43af31a88420c154d7a57d27d2b69787d11d
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="fundamentals-of-atl-com-objects"></a>Conceitos básicos de objetos COM de ATL
A ilustração a seguir descreve a relação entre as classes e interfaces que são usadas para definir um objeto COM da ATL.  
  
 ![Estrutura ATL](../atl/media/vc307y1.gif "vc307y1")  
  
> [!NOTE]
>  Este diagrama mostra que `CComObject` é derivado de `CYourClass` enquanto `CComAggObject` e `CComPolyObject` incluem `CYourClass` como uma variável de membro.  
  
 Há três maneiras de definir um objeto COM da ATL. A opção padrão é usar o `CComObject` classe que é derivada de `CYourClass`. A segunda opção é criar um objeto agregado usando a `CComAggObject` classe. A terceira opção é usar o `CComPolyObject` classe. `CComPolyObject`atua como um híbrido: ele pode funcionar como um `CComObject` classe ou como um `CComAggObject` classe, dependendo de como ela é criada pela primeira vez. Para obter mais informações sobre como usar o `CComPolyObject` de classe, consulte [CComPolyObject classe](../atl/reference/ccompolyobject-class.md).  
  
 Quando você usa COM da ATL padrão, você usa dois objetos: um objeto externo e um objeto interno. Clientes externos acessam a funcionalidade do objeto interna por meio das funções de invólucro que são definidas no objeto externo. O objeto externo é do tipo `CComObject`.  
  
 Quando você usa um objeto agregado, o objeto externo não fornecem wrappers para a funcionalidade do objeto interno. Em vez disso, o objeto externo fornece um ponteiro que é acessado diretamente por clientes externos. Nesse cenário, o objeto externo é do tipo `CComAggObject`. O objeto interno é uma variável de membro do objeto de dados externa e é do tipo `CYourClass`.  
  
 Como o cliente não precise percorrer o objeto externo para interagir com o objeto interno, objetos agregados são geralmente mais eficientes. Além disso, o objeto externo não precisa saber a funcionalidade do objeto agregado, considerando que a interface do objeto agregado está diretamente disponível para o cliente. No entanto, nem todos os objetos podem ser agregados. Para um objeto a ser agregada, ele precisa ser criado com agregação em mente.  
  
 ATL implementa [IUnknown](http://msdn.microsoft.com/library/windows/desktop/ms680509) em duas fases:  
  
-   [CComObject](../atl/reference/ccomobject-class.md), [CComAggObject](../atl/reference/ccomaggobject-class.md), ou [CComPolyObject](../atl/reference/ccompolyobject-class.md) implementa o **IUnknown** métodos.  
  
-   [CComObjectRoot](../atl/reference/ccomobjectroot-class.md) ou [CComObjectRootEx](../atl/reference/ccomobjectrootex-class.md) gerencia a contagem de referência e ponteiros externos de **IUnknown**.  
  
 Outros aspectos do objeto ATL COM são tratados por outras classes:  
  
-   [CComCoClass](../atl/reference/ccomcoclass-class.md) define o modelo de fábrica e agregação de classe de padrão do objeto.  
  
-   [IDispatchImpl](../atl/reference/idispatchimpl-class.md) fornece uma implementação padrão da `IDispatch Interface` parte de qualquer interface dupla no objeto.  
  
-   [ISupportErrorInfoImpl](../atl/reference/isupporterrorinfoimpl-class.md) implementa o **ISupportErrorInfo** interface que garante que as informações de erro pode ser propagado a cadeia de chamada corretamente.  
  
## <a name="in-this-section"></a>Nesta seção  
 [Implementando CComObjectRootEx](../atl/implementing-ccomobjectrootex.md)  
 Mostrar entradas do mapa de COM para a implementação de exemplo `CComObjectRootEx`.  
  
 [Implementando CComObject, CComAggObject e CComPolyObject](../atl/implementing-ccomobject-ccomaggobject-and-ccompolyobject.md)  
 Discute como o **DECLARE_\*_AGGREGATABLE** macros afetam o uso de `CComObject`, `CComAggObject`, e `CComPolyObject`.  
  
 [Suporte a IDispatch e IErrorInfo](../atl/supporting-idispatch-and-ierrorinfo.md)  
 Lista as classes de implementação do ATL para usar para oferecer suporte a `IDispatch` e **IErrorInfo** interfaces.  
  
 [Suporte a IDispEventImpl](../atl/supporting-idispeventimpl.md)  
 Discute as etapas para implementar um ponto de conexão para a sua classe.  
  
 [Alterando a fábrica de classes padrão e o modelo de agregação](../atl/changing-the-default-class-factory-and-aggregation-model.md)  
 Mostre quais macros para usar para alterar o modelo de fábrica e agregação de classe padrão.  
  
 [Criando um objeto agregado](../atl/creating-an-aggregated-object.md)  
 Lista as etapas para criar um objeto agregado.  
  
## <a name="related-sections"></a>Seções relacionadas  
 [Criando um projeto ATL](../atl/reference/creating-an-atl-project.md)  
 Fornece informações sobre como criar um objeto COM da ATL.  
  
 [ATL](../atl/active-template-library-atl-concepts.md)  
 Fornece links para tópicos conceituais sobre como programar usando o Active Template Library.  
  
## <a name="see-also"></a>Consulte também  
 [Conceitos](../atl/active-template-library-atl-concepts.md)

