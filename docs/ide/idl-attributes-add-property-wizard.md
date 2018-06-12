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
ms.openlocfilehash: 77931296d8d33337c4e630b7327a1ec8fd0a458f
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33340184"
---
# <a name="idl-attributes-add-property-wizard"></a>Atributos IDL, Assistente para Adicionar Propriedade
Use esta página do Assistente de Adição de Propriedade para especificar as configurações de linguagem IDL para a propriedade.  
  
 **id**  
 Define a ID numérica que identifica a propriedade. Essa opção não está disponível para propriedades de interfaces personalizadas. Confira [id](http://msdn.microsoft.com/library/windows/desktop/aa367040) na *Referência de MIDL*.  
  
 **helpcontext**  
 Especifica uma ID de contexto que permite ao usuário exibir informações sobre essa propriedade no arquivo de Ajuda. Confira [helpcontext](http://msdn.microsoft.com/library/windows/desktop/aa366851) na *Referência de MIDL*.  
  
 **helpstring**  
 Especifica uma cadeia de caracteres que é usada para descrever o elemento ao qual ela se aplica. Por padrão, ela é definida como "property *Nome da propriedade*." Confira [helpstring](http://msdn.microsoft.com/library/windows/desktop/aa366856) na *Referência de MIDL*.  
  
## <a name="other-options"></a>Outras opções  
 Nem todas as opções estão disponíveis para todos os tipos de propriedade.  
  
|Opção|Descrição|  
|------------|-----------------|  
|**bindable**|Indica que a propriedade dá suporte à associação de dados. Confira [bindable](http://msdn.microsoft.com/library/windows/desktop/aa366738) na *Referência de MIDL*. Para a implementação de estoque da propriedade, essa opção está definida por padrão e não pode ser alterada.|  
|**defaultbind**|Indica que essa única propriedade associável melhor representa o objeto. Confira [defaultbind](http://msdn.microsoft.com/library/windows/desktop/aa366790) na *Referência de MIDL*.|  
|**displaybind**|Indica que essa propriedade deve ser exibida para o usuário como associável. Confira [displaybind](http://msdn.microsoft.com/library/windows/desktop/aa366804) na *Referência de MIDL*.|  
|**immediatebind**|Indica que o banco de dados será notificado imediatamente de todas as alterações nessa propriedade de um objeto associado a dados. Confira [immediatebind](http://msdn.microsoft.com/library/windows/desktop/aa367045) na *Referência de MIDL*.|  
|**defaultcollelem**|Indica que a propriedade é uma função de acessador para um elemento da coleção padrão. Confira [defaultcollelem](http://msdn.microsoft.com/library/windows/desktop/aa366792) na *Referência de MIDL*.|  
|**nonbrowsable**|Marca um membro de interface ou de dispinterface que não deve ser exibido em um navegador de propriedades. Confira [nonbrowsable](http://msdn.microsoft.com/library/windows/desktop/aa367117) na *Referência de MIDL*.|  
|**requestedit**|Indica que a propriedade dá suporte à notificação **OnRequestEdit**. Confira [requestedit](http://msdn.microsoft.com/library/windows/desktop/aa367155) na *Referência de MIDL*. Para a implementação de estoque da propriedade, essa opção está definida por padrão e não pode ser alterada.|  
|**source**|Indica que um membro da propriedade é uma origem de eventos. Confira [source](http://msdn.microsoft.com/library/windows/desktop/aa367166) na *Referência de MIDL*.|  
|**hidden**|Indica que a propriedade existe, mas que não deveria ser exibida em um navegador orientado ao usuário. Confira [hidden](http://msdn.microsoft.com/library/windows/desktop/aa366861) na *Referência de MIDL*.|  
|**restricted**|Especifica que a propriedade não pode ser chamada arbitrariamente. Confira [restricted](http://msdn.microsoft.com/library/windows/desktop/aa367157) na *Referência de MIDL*.|  
|`local`|Especifica para o compilador MIDL que a propriedade não é remota. Confira [local](http://msdn.microsoft.com/library/windows/desktop/aa367071) na *Referência de MIDL*.|  
  
## <a name="see-also"></a>Consulte também  
 [Adicionando uma propriedade](../ide/adding-a-property-visual-cpp.md)   
 [Nomes, Assistente de Adição de Propriedade](../ide/names-add-property-wizard.md)   
 [Implementando uma interface](../ide/implementing-an-interface-visual-cpp.md)   
 [Propriedades de estoque](../ide/stock-properties.md)