---
title: Atributos IDL, Assistente para adicionar propriedade | Microsoft Docs
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
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="idl-attributes-add-property-wizard"></a>Atributos IDL, Assistente para Adicionar Propriedade
Use esta página do Assistente para adicionar propriedade para especificar as configurações de linguagem IDL de definição de interface para a propriedade.  
  
 **id**  
 Define a ID numérica que identifica a propriedade. Essa opção não está disponível para as propriedades de interfaces personalizados. Consulte [id](http://msdn.microsoft.com/library/windows/desktop/aa367040) no *referência MIDL*.  
  
 **helpcontext**  
 Especifica uma ID de contexto que permite que usuários exibir informações sobre essa propriedade no arquivo de Ajuda. Consulte [helpcontext](http://msdn.microsoft.com/library/windows/desktop/aa366851) no *referência MIDL*.  
  
 **helpstring**  
 Especifica uma cadeia de caracteres que é usada para descrever o elemento ao qual se aplica. Por padrão, ele é definido como "propriedade *nome da propriedade*." Consulte [helpstring](http://msdn.microsoft.com/library/windows/desktop/aa366856) no *referência MIDL*.  
  
## <a name="other-options"></a>Outras opções  
 Nem todas as opções estão disponíveis para todos os tipos de propriedade.  
  
|Opção|Descrição|  
|------------|-----------------|  
|**bindable**|Indica que a propriedade dá suporte à associação de dados. Consulte [associável](http://msdn.microsoft.com/library/windows/desktop/aa366738) no *referência MIDL*. Para a implementação de estoque da propriedade, essa opção é definida por padrão e não pode ser alterada.|  
|**defaultbind**|Indica que a única propriedade associável melhor representa o objeto. Consulte [defaultbind](http://msdn.microsoft.com/library/windows/desktop/aa366790) no *referência MIDL*.|  
|**displaybind**|Indica que essa propriedade deve ser exibida para o usuário como associável. Consulte [displaybind](http://msdn.microsoft.com/library/windows/desktop/aa366804) no *referência MIDL*.|  
|**immediatebind**|Indica que o banco de dados será notificado imediatamente de todas as alterações a esta propriedade de um objeto de associação de dados. Consulte [immediatebind](http://msdn.microsoft.com/library/windows/desktop/aa367045) no *referência MIDL*.|  
|**defaultcollelem**|Indica que a propriedade é uma função de acessador de um elemento de coleção padrão. Consulte [defaultcollelem](http://msdn.microsoft.com/library/windows/desktop/aa366792) no *referência MIDL*.|  
|**nonbrowsable**|Marcas de um membro de interface ou dispinterface não deve ser exibido em um navegador de propriedades. Consulte [nonbrowsable](http://msdn.microsoft.com/library/windows/desktop/aa367117) no *referência MIDL*.|  
|**requestedit**|Indica que a propriedade oferece suporte a **OnRequestEdit** notificação consulte [requestedit](http://msdn.microsoft.com/library/windows/desktop/aa367155) no *referência MIDL*. Para a implementação de estoque da propriedade, essa opção é definida por padrão e não pode ser alterada.|  
|**Código-fonte**|Indica que um membro da propriedade é uma origem de eventos. Consulte [fonte](http://msdn.microsoft.com/library/windows/desktop/aa367166) no *referência MIDL*.|  
|**hidden**|Indica que a propriedade existe, mas não deve ser exibida em um navegador orientado ao usuário. Consulte [oculta](http://msdn.microsoft.com/library/windows/desktop/aa366861) no *referência MIDL*.|  
|**restricted**|Especifica que a propriedade não pode ser chamada arbitrariamente. Consulte [restrito](http://msdn.microsoft.com/library/windows/desktop/aa367157) no *referência MIDL*.|  
|`local`|Especifica o compilador MIDL que a propriedade não é remota. Consulte [local](http://msdn.microsoft.com/library/windows/desktop/aa367071) no *referência MIDL*.|  
  
## <a name="see-also"></a>Consulte também  
 [Adicionando uma propriedade](../ide/adding-a-property-visual-cpp.md)   
 [Nomes, Assistente para adicionar propriedade](../ide/names-add-property-wizard.md)   
 [Implementando uma Interface](../ide/implementing-an-interface-visual-cpp.md)   
 [Propriedades de estoque](../ide/stock-properties.md)