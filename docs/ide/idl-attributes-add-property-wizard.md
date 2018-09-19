---
title: Atributos IDL, Assistente de Adição de Propriedade | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-ide
ms.topic: conceptual
f1_keywords:
- vc.codewiz.prop.idlattributes
dev_langs:
- C++
ms.assetid: 356ed666-79d0-4bd9-a5e7-cda679cbadbd
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 7da654321dfae520f458374654a21a9e8ebb98f5
ms.sourcegitcommit: 92f2fff4ce77387b57a4546de1bd4bd464fb51b6
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/17/2018
ms.locfileid: "45706637"
---
# <a name="idl-attributes-add-property-wizard"></a>Atributos IDL, Assistente para Adicionar Propriedade
Use esta página do Assistente de Adição de Propriedade para especificar as configurações de linguagem IDL para a propriedade.  
  
- **id**

   Define a ID numérica que identifica a propriedade. Essa opção não está disponível para propriedades de interfaces personalizadas. Confira [id](/windows/desktop/Midl/id) na *Referência de MIDL*.  
  
- **helpcontext**

   Especifica uma ID de contexto que permite ao usuário exibir informações sobre essa propriedade no arquivo de Ajuda. Confira [helpcontext](/windows/desktop/Midl/helpcontext) na *Referência de MIDL*.  
  
- **helpstring**

   Especifica uma cadeia de caracteres que é usada para descrever o elemento ao qual ela se aplica. Por padrão, ela é definida como "property *Nome da propriedade*." Confira [helpstring](/windows/desktop/Midl/helpstring) na *Referência de MIDL*.  
  
## <a name="other-options"></a>Outras opções  

Nem todas as opções estão disponíveis para todos os tipos de propriedade.  
  
|Opção|Descrição|  
|------------|-----------------|  
|**bindable**|Indica que a propriedade dá suporte à associação de dados. Confira [bindable](/windows/desktop/Midl/bindable) na *Referência de MIDL*. Para a implementação de estoque da propriedade, essa opção está definida por padrão e não pode ser alterada.|  
|**defaultbind**|Indica que essa única propriedade associável melhor representa o objeto. Confira [defaultbind](/windows/desktop/Midl/defaultbind) na *Referência de MIDL*.|  
|**displaybind**|Indica que essa propriedade deve ser exibida para o usuário como associável. Confira [displaybind](/windows/desktop/Midl/displaybind) na *Referência de MIDL*.|  
|**immediatebind**|Indica que o banco de dados será notificado imediatamente de todas as alterações nessa propriedade de um objeto associado a dados. Confira [immediatebind](/windows/desktop/Midl/immediatebind) na *Referência de MIDL*.|  
|**defaultcollelem**|Indica que a propriedade é uma função de acessador para um elemento da coleção padrão. Confira [defaultcollelem](/windows/desktop/Midl/defaultcollelem) na *Referência de MIDL*.|  
|**nonbrowsable**|Marca um membro de interface ou de dispinterface que não deve ser exibido em um navegador de propriedades. Confira [nonbrowsable](/windows/desktop/Midl/nonbrowsable) na *Referência de MIDL*.|  
|**requestedit**|Indica que a propriedade dá suporte à notificação **OnRequestEdit**. Confira [requestedit](/windows/desktop/Midl/requestedit) na *Referência de MIDL*. Para a implementação de estoque da propriedade, essa opção está definida por padrão e não pode ser alterada.|  
|**source**|Indica que um membro da propriedade é uma origem de eventos. Confira [source](/windows/desktop/Midl/source) na *Referência de MIDL*.|  
|**hidden**|Indica que a propriedade existe, mas que não deveria ser exibida em um navegador orientado ao usuário. Confira [hidden](/windows/desktop/Midl/hidden) na *Referência de MIDL*.|  
|**restricted**|Especifica que a propriedade não pode ser chamada arbitrariamente. Confira [restricted](/windows/desktop/Midl/restricted) na *Referência de MIDL*.|  
|`local`|Especifica para o compilador MIDL que a propriedade não é remota. Confira [local](/windows/desktop/Midl/local) na *Referência de MIDL*.|  
  
## <a name="see-also"></a>Consulte também  
 [Adicionando uma propriedade](../ide/adding-a-property-visual-cpp.md)   
 [Nomes, Assistente de Adição de Propriedade](../ide/names-add-property-wizard.md)   
 [Implementando uma interface](../ide/implementing-an-interface-visual-cpp.md)   
 [Propriedades de estoque](../ide/stock-properties.md)