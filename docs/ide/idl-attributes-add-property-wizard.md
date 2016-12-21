---
title: "Atributos IDL, Assistente para Adicionar Propriedade | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
f1_keywords: 
  - "vc.codewiz.prop.idlattributes"
dev_langs: 
  - "C++"
ms.assetid: 356ed666-79d0-4bd9-a5e7-cda679cbadbd
caps.latest.revision: 6
caps.handback.revision: 6
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Atributos IDL, Assistente para Adicionar Propriedade
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Use esta página do Assistente para adicionar propriedade para especificar quaisquer configurações da interface definition language \(IDL\) para a propriedade.  
  
 **ID**  
 Define o ID numérico que identifica a propriedade.  Esta opção não está disponível para propriedades de interfaces personalizadas.  Consulte  [id](http://msdn.microsoft.com/library/windows/desktop/aa367040) na  *Referência MIDL*.  
  
 **HelpContext**  
 Especifica uma identificação de contexto que permite que as informações de modo de exibição do usuário sobre essa propriedade no arquivo de Ajuda.  Consulte  [helpcontext](http://msdn.microsoft.com/library/windows/desktop/aa366851) na  *Referência MIDL*.  
  
 **HelpString**  
 Especifica a string que é usada para descrever o elemento a que se aplica.  Por padrão, ele é definido como "propriedade  *o nome da propriedade*." Consulte  [helpstring](http://msdn.microsoft.com/library/windows/desktop/aa366856) na  *Referência MIDL*.  
  
## Outras opções  
 Nem todas as opções estão disponíveis para todos os tipos de propriedade.  
  
|Opção|Descrição|  
|-----------|---------------|  
|**ligáveis**|Indica que a propriedade oferece suporte a vinculação de dados.  Consulte  [vinculáveis](http://msdn.microsoft.com/library/windows/desktop/aa366738) na  *Referência MIDL*.  Para a implementação das ações da propriedade, essa opção é definida por padrão e é inalterável.|  
|**defaultbind**|Indica que a propriedade única e ligável melhor representa o objeto.  Consulte  [defaultbind](http://msdn.microsoft.com/library/windows/desktop/aa366790) na  *Referência MIDL*.|  
|**displaybind**|Indica que essa propriedade deve ser exibida ao usuário como bindable.  Consulte  [displaybind](http://msdn.microsoft.com/library/windows/desktop/aa366804) na  *Referência MIDL*.|  
|**immediatebind**|Indica que o banco de dados será notificado imediatamente de todas as alterações feitas nessa propriedade de um objeto com dados vinculados.  Consulte  [immediatebind](http://msdn.microsoft.com/library/windows/desktop/aa367045) na  *Referência MIDL*.|  
|**defaultcollelem**|Indica que a propriedade é uma função de assessor de um elemento da coleção padrão.  Consulte  [defaultcollelem](http://msdn.microsoft.com/library/windows/desktop/aa366792) na  *Referência MIDL*.|  
|**nonbrowsable**|Marcas de um membro de interface ou dispinterface que não deve ser exibido em um navegador de propriedades.  Consulte  [nonbrowsable](http://msdn.microsoft.com/library/windows/desktop/aa367117) na  *Referência MIDL*.|  
|**requestedit**|Indica que a propriedade oferece suporte a  **OnRequestEdit** notificação consulte  [requestedit](http://msdn.microsoft.com/library/windows/desktop/aa367155) na  *Referência MIDL*.  Para a implementação das ações da propriedade, essa opção é definida por padrão e é inalterável.|  
|**fonte**|Indica que um membro da propriedade é uma fonte de eventos.  Consulte  [origem](http://msdn.microsoft.com/library/windows/desktop/aa367166) na  *Referência MIDL*.|  
|**oculto**|Indica que a propriedade existe mas não deve ser exibida em um navegador orientada ao usuário.  Consulte  [oculto](http://msdn.microsoft.com/library/windows/desktop/aa366861) na  *Referência MIDL*.|  
|**restrito**|Especifica que a propriedade não pode ser chamada arbitrariamente.  Consulte  [restritos](http://msdn.microsoft.com/library/windows/desktop/aa367157) na  *Referência MIDL*.|  
|`local`|Para o compilador MIDL, especifica que a propriedade não é remota.  Consulte  [local](http://msdn.microsoft.com/library/windows/desktop/aa367071) na  *Referência MIDL*.|  
  
## Consulte também  
 [Adicionando uma propriedade](../Topic/Adding%20a%20Property%20\(Visual%20C++\).md)   
 [Nomes, Assistente para Adicionar Propriedade](../ide/names-add-property-wizard.md)   
 [Implementando uma interface](../ide/implementing-an-interface-visual-cpp.md)   
 [Propriedades de estoque](../ide/stock-properties.md)