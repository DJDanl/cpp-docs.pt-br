---
title: "Adicionando formata&#231;&#227;o ou caracteres especiais a uma cadeia de caracteres | Microsoft Docs"
ms.custom: ""
ms.date: "12/15/2016"
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
  - "caracteres ASCII, adicionando a cadeias de caracteres"
  - "caracteres especiais, adicionando a cadeias de caracteres"
  - "cadeias de caracteres [C++], formatação"
  - "cadeias de caracteres [C++], caracteres especiais"
ms.assetid: c40f394a-8b2c-4896-ab30-6922863ddbb5
caps.latest.revision: 11
caps.handback.revision: 8
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Adicionando formata&#231;&#227;o ou caracteres especiais a uma cadeia de caracteres
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

### Para adicionar caracteres especiais ou de formatação para uma seqüência de caracteres  
  
1.  Abra a tabela de cadeia de caracteres clicando duas vezes no ícone correspondente na  [Exibição de recurso](../windows/resource-view-window.md).  
  
    > [!NOTE]
    >  Se o seu projeto já não contém um arquivo. rc, consulte  [criar um novo arquivo de Script de recurso](../windows/how-to-create-a-resource-script-file.md).  
  
2.  Selecione a seqüência de caracteres que você deseja modificar.  
  
3.  No  [Janela Propriedades do](../Topic/Properties%20Window.md), adicionar qualquer uma das seqüências de escape padrão listados abaixo ao texto na  **legenda** caixa e pressione  **ENTER**.  
  
    |Para obter essa|Digite isto|  
    |---------------------|-----------------|  
    |Nova linha|\\n|  
    |Retorno de carro|\\r|  
    |Tab|\\t|  
    |Invertida\)|\\\\|  
    |Caractere ASCII|\\ddd \(notação octal\)|  
    |Alerta \(bell\)|\\a|  
  
> [!NOTE]
>  O editor de seqüência não suporta o conjunto completo de caracteres de escape ASCI.  Você só pode usar os listados acima.  
  
 Para obter informações sobre como adicionar recursos a projetos gerenciados \(aquelas que visam common language runtime\), consulte  [recursos em aplicativos](../Topic/Resources%20in%20Desktop%20Apps.md) na  *.Guia. do desenvolvedor do NET Framework* Para informações sobre como adicionar manualmente os arquivos de recursos para projetos gerenciados, acesso a recursos, exibindo recursos estáticos e a atribuição de seqüências de caracteres de recursos a propriedades, consulte  [Walkthrough: Localizing Windows Forms](http://msdn.microsoft.com/pt-br/9a96220d-a19b-4de0-9f48-01e5d82679e5) e [Walkthrough: Using Resources for Localization with ASP.NET](../Topic/Walkthrough:%20Using%20Resources%20for%20Localization%20with%20ASP.NET.md).  
  
 **Requisitos**  
  
 Win32  
  
## Consulte também  
 [Editor de Cadeia de Caracteres](../mfc/string-editor.md)   
 [Seqüências de caracteres](_win32_Strings)   
 [sobre seqüências de caracteres](_win32_About_Strings_cpp)