---
title: Propriedades de estoque | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-ide
ms.tgt_pltfrm: 
ms.topic: article
dev_langs: C++
helpviewer_keywords:
- stock properties, about stock properties
- stock properties
ms.assetid: a89fc454-0b8e-447a-9033-4c8af46a24d9
caps.latest.revision: "6"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 9bbc721669d51860c01c760a8d1f9fb899e019e3
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="stock-properties"></a>Propriedades de estoque
Se você estiver adicionando uma propriedade para um dispinterface MFC usando o [Assistente para adição de propriedade](../ide/idl-attributes-add-property-wizard.md), você pode escolher uma propriedade de estoque do **nome da propriedade** lista o [nomes](../ide/names-add-property-wizard.md) página do Assistente. Estas são as seguintes propriedades:  
  
|Property name|Descrição|  
|-------------------|-----------------|  
|**Aparência**|Retorna ou define um valor que determina a aparência do controle. O controle **aparência** propriedade pode incluir ou omitir os efeitos de exibição tridimensionais. Essa é uma propriedade de leitura/gravação do ambiente.|  
|`BackColor`|Retorna ou define o controle ambiente `BackColor` propriedade para uma cor da paleta (RGB) ou uma cor do sistema predefinidos. Por padrão, seu valor corresponde à cor do primeiro plano do contêiner do controle. Essa é uma propriedade de leitura/gravação do ambiente.|  
|`BorderStyle`|Retorna ou define o estilo de borda para um controle. Esta é uma propriedade de leitura/gravação.|  
|**Legenda**|Retorna ou define o controle **legenda** propriedade. A legenda é o título da janela. **Legenda** não tem nenhum **variável membro** tipo de implementação.|  
|**Habilitado**|Retorna ou define o controle **habilitado** propriedade. Um controle habilitado pode responder a eventos gerados pelo usuário.|  
|**Fonte**|Retorna ou define a fonte de ambiente do controle. NULL se o controle não tiver nenhuma fonte.|  
|`ForeColor`|Retorna ou define o controle ambiente `ForeColor` propriedade.|  
|**hWnd**|Retorna ou define o controle **hWnd** propriedade. **hWnd** não tem nenhum **variável membro** tipo de implementação.|  
|**Estado de prontidão é**|Retorna ou define o controle **estado de prontidão é** propriedade. Um controle pode ser não inicializada, inicializado, carregar, interativo ou completa. Consulte [estado de prontidão é](https://msdn.microsoft.com/en-us/library/aa768362.aspx) no *SDK Internet* para obter mais informações.|  
|**Texto**|Retorna ou define o texto contido em um controle. **Texto** não tem nenhum **variável membro** tipo de implementação.|  
  
## <a name="see-also"></a>Consulte também  
 [Adicionando uma propriedade](../ide/adding-a-property-visual-cpp.md)   
 [Atributos IDL, Assistente para Adicionar Propriedade](../ide/idl-attributes-add-property-wizard.md)