---
title: "Implementação de páginas de propriedade | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
dev_langs: C++
helpviewer_keywords:
- IPropertyPage2 class
- IPropertyPage class
- property pages, implementing
ms.assetid: 62f29440-33a7-40eb-a1ef-3634c95f640c
caps.latest.revision: "11"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: ac80bdd9e38d14b53aea7b691d480272cce66e7b
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="implementing-property-pages"></a>Implementação de páginas de propriedade
Páginas de propriedades são COM os objetos que implementam o `IPropertyPage` ou **IPropertyPage2** interface. ATL fornece suporte para a implementação de páginas de propriedade por meio de [Assistente de página de propriedades ATL](../atl/reference/atl-property-page-wizard.md) no [caixa de diálogo Adicionar classe](../ide/add-class-dialog-box.md).  
  
 Para criar uma página de propriedades usando a ATL:  
  
-   Crie ou abra um projeto do servidor ATL Dynamic-link library (DLL).  
  
-   Abra o [caixa de diálogo Adicionar classe](../ide/add-class-dialog-box.md) e selecione **página de propriedades ATL**.  
  
-   Certifique-se de que sua página de propriedades é apartment threaded (desde que ele tem uma interface de usuário).  
  
-   Defina o título, a descrição (cadeia de caracteres do documento) e o arquivo de ajuda a ser associado a sua página.  
  
-   Adicione controles para o recurso de caixa de diálogo gerado para atuar como a interface do usuário de sua página de propriedades.  
  
-   Responda a alterações na interface do usuário da página para executar a validação, atualize a página do site ou atualizar os objetos associados à página. Em particular, chame [IPropertyPageImpl::SetDirty](../atl/reference/ipropertypageimpl-class.md#setdirty) quando o usuário faz alterações para a página de propriedades.  
  
-   Opcionalmente, substitua o `IPropertyPageImpl` métodos usando as diretrizes abaixo.  
  
    |Método IPropertyPageImpl|Substitua quando quiser...|Observações|  
    |------------------------------|----------------------------------|-----------|  
    |[SetObjects](../atl/reference/ipropertypageimpl-class.md#setobjects)|Execute verificações de integridade básico no número de objetos que está sendo passado para a página e as interfaces que oferecem suporte a eles.|Execute seu próprio código antes de chamar a implementação da classe base. Se os objetos que está sendo definidos não está de acordo com suas expectativas, você deve fazer a chamada assim que possível.|  
    |[Ativar](../atl/reference/ipropertypageimpl-class.md#activate)|Inicialize a interface do usuário da página (por exemplo, definir os controles de caixa de diálogo com valores da propriedade atual de objetos, criar controles dinamicamente ou executar outras inicializações).|Chame a implementação da classe base antes de seu código para que a classe base tenha a oportunidade de criar a janela de diálogo e todos os controles antes de tentar atualizá-los.|  
    |[Aplicar](../atl/reference/ipropertypageimpl-class.md#apply)|Valide as configurações de propriedade e atualizar os objetos.|Não é necessário para chamar a implementação da classe base desde que ela não faz nada além de rastreamento de chamada.|  
    |[Desativar](../atl/reference/ipropertypageimpl-class.md#deactivate)|Limpe itens relacionados a janela.|A implementação da classe base destrói a caixa de diálogo que representa a página de propriedades. Se você precisa limpar antes da caixa de diálogo é destruída, você deve adicionar o código antes de chamar a classe base.|  
  
 Para uma implementação de página de propriedade de exemplo, consulte [exemplo: Implementando uma página de propriedades](../atl/example-implementing-a-property-page.md).  
  
> [!NOTE]
>  Se você deseja hospedar controles ActiveX em sua página de propriedades, você precisará alterar a derivação de sua classe gerada pelo assistente. Substituir **CDialogImpl\<CYourClass >** com **CAxDialogImpl\<CYourClass >** na lista de classes base.  
  
## <a name="see-also"></a>Consulte também  
 [Páginas de propriedade](../atl/atl-com-property-pages.md)   
 [Exemplo de ATLPages](../visual-cpp-samples.md)

