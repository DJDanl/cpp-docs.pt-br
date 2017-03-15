---
title: "Atributos IDL, Assistente de Adi&#231;&#227;o de M&#233;todo | Microsoft Docs"
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
  - "vc.codewiz.method.idlattrib"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Assistente de Adição de Método [C++]"
  - "atributos IDL, Assistente de Adição de Método"
ms.assetid: f80c3bc1-b515-4d6c-83ee-98c2c21ba902
caps.latest.revision: 6
caps.handback.revision: 6
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Atributos IDL, Assistente de Adi&#231;&#227;o de M&#233;todo
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Use esta página do Assistente para Adicionar método para especificar quaisquer configurações da interface definition language \(IDL\) para o método.  
  
 **ID**  
 Define o ID numérico que identifica o método.  Consulte  [id](http://msdn.microsoft.com/library/windows/desktop/aa367040) na  *Referência MIDL*.  
  
 Esta caixa não está disponível para interfaces personalizadas e não está disponível para dispinterfaces do MFC.  
  
 **call\_as**  
 Especifica o nome de um método remoto ao qual esse método local pode ser mapeado.  Consulte  [call\_as](http://msdn.microsoft.com/library/windows/desktop/aa366748) na  *Referência MIDL*.  
  
 Não disponível para dispinterfaces do MFC.  
  
 **HelpContext**  
 Especifica uma identificação de contexto que permite que as informações de modo de exibição do usuário sobre esse método no arquivo de Ajuda.  Consulte  [helpcontext](http://msdn.microsoft.com/library/windows/desktop/aa366851) na  *Referência MIDL*.  
  
 Não disponível para dispinterfaces do MFC.  
  
 **HelpString**  
 Especifica a string que é usada para descrever o elemento a que se aplica.  Por padrão, ele é definido como "método  *nome do método*." Consulte  [helpstring](http://msdn.microsoft.com/library/windows/desktop/aa366856) na  *Referência MIDL*.  
  
 Não disponível para dispinterfaces do MFC.  
  
 **Atributos adicionais**  
 Não disponível para dispinterfaces do MFC.  
  
|Atributo|Descrição|  
|--------------|---------------|  
|**oculto**|Indica que o método existe mas não deve ser exibido em um navegador orientada ao usuário.  Consulte  [oculto](http://msdn.microsoft.com/library/windows/desktop/aa366861) na  *Referência MIDL*.|  
|**fonte**|Indica que um membro do método é uma fonte de eventos.  Consulte  [origem](http://msdn.microsoft.com/library/windows/desktop/aa367166) na  *Referência MIDL*.|  
|`local`|Para o compilador MIDL, especifica que o método não é remoto.  Consulte  [local](http://msdn.microsoft.com/library/windows/desktop/aa367071) na  *Referência MIDL*.|  
|**restrito**|Especifica que o método não pode ser chamado arbitrariamente.  Consulte  [restritos](http://msdn.microsoft.com/library/windows/desktop/aa367157) na  *Referência MIDL*.|  
|**vararg**|Especifica que o método recebe um número variável de argumentos.  Para fazer isso, o último argumento deve ser uma matriz segura de  **VARIANT** tipo que contém todos os argumentos restantes.  Consulte  [vararg](http://msdn.microsoft.com/library/windows/desktop/aa367304) na  *Referência MIDL*.|  
  
## Consulte também  
 [Adicionando um método](../ide/adding-a-method-visual-cpp.md)   
 [Assistente de Adição de Método](../ide/add-method-wizard.md)