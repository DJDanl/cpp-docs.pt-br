---
title: "Caixa de di&#225;logo S&#237;mbolos do Recurso | Microsoft Docs"
ms.custom: ""
ms.date: "12/14/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
f1_keywords: 
  - "vc.editors.resourcesymbols"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Caixa de diálogo Alterar Símbolo"
  - "Caixa de diálogo Novo Símbolo"
  - "Caixa de diálogo Símbolos de Recurso"
ms.assetid: 9706cde3-1f48-4fcd-bedb-2b03b455e3c1
caps.latest.revision: 7
caps.handback.revision: 7
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Caixa de di&#225;logo S&#237;mbolos do Recurso
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

O **símbolos de recurso** caixa de diálogo permite que você adicione símbolos de recurso novo, altere os símbolos que são exibidos ou saltar para o local no código\-fonte em que um símbolo está em uso.  
  
 **Nome**  
 Exibe o nome do símbolo.  Para obter mais informações, consulte [restrições de nome de símbolo](../windows/symbol-name-restrictions.md).  
  
 **Valor**  
 Exibe o valor numérico do símbolo.  Para obter mais informações, consulte [restrições de valor do símbolo](../Topic/Symbol%20Value%20Restrictions.md).  
  
 **Em uso**  
 Quando selecionado, especifica que o símbolo está sendo usado por um ou mais recursos.  Um ou mais recursos estão listados na usado pela caixa.  
  
 **Mostrar símbolos somente leitura**  
 Quando selecionada, exibe os recursos somente leitura.  Por padrão, a caixa de diálogo do símbolo de recurso exibe somente os recursos podem ser modificados no arquivo de script de recurso, mas com essa opção selecionada, os recursos podem ser modificados aparecem em negrito e recursos somente leitura são exibidos em texto sem formatação.  
  
 **Usado por**  
 Exibe um ou mais recursos usando o símbolo selecionado na lista de símbolos.  Para mover para o editor para um determinado recurso, selecione o recurso de **usado por** caixa e clique em **Exibir uso**.  Para obter mais informações, consulte [Abrir o Editor de recursos para um símbolo dado](../Topic/Opening%20the%20Resource%20Editor%20for%20a%20Given%20Symbol.md).  
  
 **Novo**  
 Abre a caixa de diálogo Novo símbolo, que permite que você defina o nome e, se necessário, um valor para um novo identificador simbólico do recurso.  Para obter mais informações, consulte [Criando novos símbolos](../windows/creating-new-symbols.md).  
  
 **Alteração**  
 Abre a caixa de diálogo Alterar símbolo, que permite que você altere o nome ou o valor de um símbolo.  Se o símbolo for um controle ou recursos em uso, o símbolo pode ser alterado somente do editor de recurso correspondente.  Para obter mais informações, consulte [alterando símbolos não atribuídos](../Topic/Changing%20Unassigned%20Symbols.md).  
  
 **Exibir uso**  
 Abre o recurso que contém o símbolo no editor de recurso correspondente.  Para obter mais informações, consulte [Abrir o Editor de recursos para um símbolo dado](../Topic/Opening%20the%20Resource%20Editor%20for%20a%20Given%20Symbol.md).  
  
 Para obter informações sobre como adicionar recursos a projetos gerenciados, consulte [Recursos em aplicativos](../Topic/Resources%20in%20Desktop%20Apps.md) no *Guia do desenvolvedor do .NET Framework.* Para obter informações sobre como adicionar manualmente os arquivos de recursos a projetos gerenciados, acessar recursos, exibir recursos estáticos e atribuir cadeias de caracteres de recursos para propriedades, consulte [Walkthrough: Using Resources for Localization with ASP.NET](../Topic/Walkthrough:%20Using%20Resources%20for%20Localization%20with%20ASP.NET.md).  
  
## Requisitos  
 Win32  
  
## Consulte também  
 [Exibindo símbolos de recurso](../windows/viewing-resource-symbols.md)