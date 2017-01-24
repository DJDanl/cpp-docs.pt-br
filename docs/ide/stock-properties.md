---
title: "Propriedades de estoque | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "propriedades de estoque"
  - "propriedades de estoque, sobre propriedades de estoque"
ms.assetid: a89fc454-0b8e-447a-9033-4c8af46a24d9
caps.latest.revision: 6
caps.handback.revision: 6
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Propriedades de estoque
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Se você estiver adicionando uma propriedade para um dispinterface MFC usando o  [Assistente para adicionar a propriedade](../ide/idl-attributes-add-property-wizard.md), você pode escolher uma propriedade das ações a partir do  **nome da propriedade** listar no  [nomes](../ide/names-add-property-wizard.md) página do assistente.  Essas propriedades são os seguintes:  
  
|Nome da propriedade|Descrição|  
|-------------------------|---------------|  
|**Aparência**|Retorna ou define um valor que determina a aparência do controle.  O controle  **aparência** propriedade pode incluir ou omitir os efeitos de exibição tridimensionais.  Isso é uma propriedade de leitura\/gravação de temperatura ambiente.|  
|`BackColor`|Retorna ou define o controle temperatura ambiente `BackColor` propriedade para uma cor de paleta \(RGB\) ou uma cor do sistema predefinidos.  Por padrão, o seu valor corresponde à cor do primeiro plano do recipiente do controle.  Isso é uma propriedade de leitura\/gravação de temperatura ambiente.|  
|`BorderStyle`|Retorna ou define o estilo de borda para um controle.  Esta é uma propriedade de leitura\/gravação.|  
|**Legenda**|Retorna ou define o controle  **legenda** propriedade.  A legenda é o título da janela.  **Legenda** não possui  **variável de membro** tipo de implementação.|  
|**Enabled**|Retorna ou define o controle  **Enabled** propriedade.  Um controle habilitado pode responder a eventos gerados pelo usuário.|  
|**Fonte**|Retorna ou define a fonte de ambiente do controle.  NULL se o controle não tiver nenhuma fonte.|  
|`ForeColor`|Retorna ou define o controle temperatura ambiente `ForeColor` propriedade.|  
|**hWnd**|Retorna ou define o controle  **hWnd** propriedade.  **hWnd** não possui  **variável de membro** tipo de implementação.|  
|**ReadyState**|Retorna ou define o controle  **ReadyState** propriedade.  Um controle pode ser não inicializada, inicializado, carregando, interativo ou concluída.  Consulte  [READYSTATE](https://msdn.microsoft.com/en-us/library/aa768362.aspx) na  *SDK Internet* para obter mais informações.|  
|**Texto**|Retorna ou define o texto contido em um controle.  **Texto** não possui  **variável de membro** tipo de implementação.|  
  
## Consulte também  
 [Adicionando uma propriedade](../Topic/Adding%20a%20Property%20\(Visual%20C++\).md)   
 [Atributos IDL, Assistente para Adicionar Propriedade](../ide/idl-attributes-add-property-wizard.md)