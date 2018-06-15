---
title: Atributos IDL, Assistente de Adição de Método | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-ide
ms.topic: conceptual
f1_keywords:
- vc.codewiz.method.idlattrib
dev_langs:
- C++
helpviewer_keywords:
- Add Method Wizard [C++]
- IDL attributes, Add Method Wizard
ms.assetid: f80c3bc1-b515-4d6c-83ee-98c2c21ba902
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 4a7a1e8fe89f64ad5909e7c1415545e3b3d80196
ms.sourcegitcommit: a4454b91d556a3dc43d8755cdcdeabcc9285a20e
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/04/2018
ms.locfileid: "33337763"
---
# <a name="idl-attributes-add-method-wizard"></a>Atributos IDL, Assistente de Adição de Método
Use esta página do Assistente de Adição de Método para especificar as configurações de linguagem IDL para o método.  
  
 **id**  
 Define a ID numérica que identifica o método. Confira [id](http://msdn.microsoft.com/library/windows/desktop/aa367040) na *Referência de MIDL*.  
  
 Essa caixa não está disponível para interfaces personalizadas nem para dispinterfaces MFC.  
  
 **call_as**  
 Especifica o nome de um método remoto para o qual esse método local pode ser mapeado. Confira [call_as](http://msdn.microsoft.com/library/windows/desktop/aa366748) na *Referência de MIDL*.  
  
 Não disponível para dispinterfaces MFC.  
  
 **helpcontext**  
 Especifica uma ID de contexto que permite ao usuário exibir informações sobre esse método no arquivo de Ajuda. Confira [helpcontext](http://msdn.microsoft.com/library/windows/desktop/aa366851) na *Referência de MIDL*.  
  
 Não disponível para dispinterfaces MFC.  
  
 **helpstring**  
 Especifica uma cadeia de caracteres que é usada para descrever o elemento ao qual ela se aplica. Por padrão, ela é definida como "method *Nome do método*". Confira [helpstring](http://msdn.microsoft.com/library/windows/desktop/aa366856) na *Referência de MIDL*.  
  
 Não disponível para dispinterfaces MFC.  
  
 **Atributos adicionais**  
 Não disponível para dispinterfaces MFC.  
  
|Atributo|Descrição|  
|---------------|-----------------|  
|**hidden**|Indica que o método existe, mas que não deveria ser exibido em um navegador orientado ao usuário. Confira [hidden](http://msdn.microsoft.com/library/windows/desktop/aa366861) na *Referência de MIDL*.|  
|**source**|Indica que um membro do método é uma origem de eventos. Confira [source](http://msdn.microsoft.com/library/windows/desktop/aa367166) na *Referência de MIDL*.|  
|`local`|Especifica para o compilador MIDL que o método não é remoto. Confira [local](http://msdn.microsoft.com/library/windows/desktop/aa367071) na *Referência de MIDL*.|  
|**restricted**|Especifica que o método não pode ser chamado arbitrariamente. Confira [restricted](http://msdn.microsoft.com/library/windows/desktop/aa367157) na *Referência de MIDL*.|  
|**vararg**|Especifica que o método usa um número variável de argumentos. Para fazer isso, o último argumento precisa ser uma matriz segura do tipo **VARIANT** que contém todos os argumentos restantes. Confira [vararg](http://msdn.microsoft.com/library/windows/desktop/aa367304) na *Referência de MIDL*.|  
  
## <a name="see-also"></a>Consulte também  
 [Adicionando um método](../ide/adding-a-method-visual-cpp.md)   
 [Assistente de Adição de Método](../ide/add-method-wizard.md)