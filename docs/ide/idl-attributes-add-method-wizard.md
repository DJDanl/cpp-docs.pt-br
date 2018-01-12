---
title: "Atributos IDL, Assistente de método | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-ide
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords: vc.codewiz.method.idlattrib
dev_langs: C++
helpviewer_keywords:
- Add Method Wizard [C++]
- IDL attributes, Add Method Wizard
ms.assetid: f80c3bc1-b515-4d6c-83ee-98c2c21ba902
caps.latest.revision: "6"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 9792f8b7758ff5a1e5742b6643d9f73931bce6f9
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="idl-attributes-add-method-wizard"></a>Atributos IDL, Assistente de Adição de Método
Use esta página do Assistente para adicionar método para especificar quaisquer configurações de linguagem IDL de definição de interface para o método.  
  
 **id**  
 Define a ID numérica que identifica o método. Consulte [id](http://msdn.microsoft.com/library/windows/desktop/aa367040) no *referência MIDL*.  
  
 Essa caixa não está disponível para interfaces personalizados e não está disponível para dispinterfaces do MFC.  
  
 **call_as**  
 Especifica o nome de um método remoto ao qual esse método local pode ser mapeado. Consulte [call_as](http://msdn.microsoft.com/library/windows/desktop/aa366748) no *referência MIDL*.  
  
 Não disponível para dispinterfaces do MFC.  
  
 **helpcontext**  
 Especifica uma ID de contexto que permite que usuários exibir informações sobre esse método no arquivo de Ajuda. Consulte [helpcontext](http://msdn.microsoft.com/library/windows/desktop/aa366851) no *referência MIDL*.  
  
 Não disponível para dispinterfaces do MFC.  
  
 **helpstring**  
 Especifica uma cadeia de caracteres que é usada para descrever o elemento ao qual se aplica. Por padrão, ele é definido como "método *nome do método*." Consulte [helpstring](http://msdn.microsoft.com/library/windows/desktop/aa366856) no *referência MIDL*.  
  
 Não disponível para dispinterfaces do MFC.  
  
 **Atributos adicionais**  
 Não disponível para dispinterfaces do MFC.  
  
|Atributo|Descrição|  
|---------------|-----------------|  
|**hidden**|Indica que o método existe, mas não deve ser exibido em um navegador orientado ao usuário. Consulte [oculta](http://msdn.microsoft.com/library/windows/desktop/aa366861) no *referência MIDL*.|  
|**código-fonte**|Indica que um membro do método é uma origem de eventos. Consulte [fonte](http://msdn.microsoft.com/library/windows/desktop/aa367166) no *referência MIDL*.|  
|`local`|Especifica o compilador MIDL que o método não é remoto. Consulte [local](http://msdn.microsoft.com/library/windows/desktop/aa367071) no *referência MIDL*.|  
|**restricted**|Especifica que o método não pode ser chamado arbitrariamente. Consulte [restrito](http://msdn.microsoft.com/library/windows/desktop/aa367157) no *referência MIDL*.|  
|**vararg**|Especifica que o método aceita um número variável de argumentos. Para fazer isso, o último argumento deve ser uma matriz segura do **VARIANT** tipo que contém todos os argumentos restantes. Consulte [vararg](http://msdn.microsoft.com/library/windows/desktop/aa367304) no *referência MIDL*.|  
  
## <a name="see-also"></a>Consulte também  
 [Adicionando um método](../ide/adding-a-method-visual-cpp.md)   
 [Assistente de Adição de Método](../ide/add-method-wizard.md)