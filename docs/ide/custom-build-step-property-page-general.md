---
title: "P&#225;gina de propriedades Etapa de Compila&#231;&#227;o Personalizada: geral | Microsoft Docs"
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
  - "VC.Project.VCCustomBuildStep.AdditionalInputs"
  - "VC.Project.VCCustomBuildStep.CustomBuildAfterTargets"
  - "VC.Project.VCCustomBuildStep.CustomBuildBeforeTargets"
  - "VC.Project.VCCustomBuildStep.Outputs"
  - "VC.Project.VCCustomBuildStep.Message"
  - "VC.Project.VCCustomBuildStep.Command"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "etapa de compilação personalizada (geral)"
  - "propriedades de projeto, etapa de compilação personalizada"
ms.assetid: bd319741-0491-46c4-a428-7c61b4b46a02
caps.latest.revision: 7
caps.handback.revision: 7
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# P&#225;gina de propriedades Etapa de Compila&#231;&#227;o Personalizada: geral
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Para cada combinação de configuração de projeto e plataforma de destino em seu projeto, você pode especificar uma etapa personalizada a ser executada quando o projeto é compilado.  
  
## Lista UIElement  
 **Linha de Comando**  
 O comando a ser executado pela etapa de compilação personalizada.  
  
 **Descrição**  
 Uma mensagem que será exibida quando a etapa de compilação personalizada for executada.  
  
 **Saídas**  
 O arquivo de saída gerado pela etapa de compilação personalizada.  Essa configuração é necessária para que as compilações incrementais funcionem corretamente.  
  
 **Dependências adicionais**  
 Uma lista delimitada por ponto\-e\-vírgula de arquivos de entrada adicionais a ser usada para a etapa de compilação personalizada.  
  
 **Executar Depois de Executar Antes**  
 Essas opções definem quando a etapa de compilação personalizada é executada no processo de compilação, em relação aos destinos listados.  Os destinos mais comumente listados são BuildGenerateSources, BuildCompile e BuildLink, porque representam as etapas principais no processo de compilação.  Outros destinos frequentemente listados são Midl, CLCompile e Link.  
  
 Tratar saída como conteúdo  
 Essa opção só é significativa para aplicativos da Windows Store ou do Windows Phone, que incluem todos os arquivos de conteúdo no pacote .appx.  
  
### Para especificar uma etapa de compilação personalizada  
  
1.  Na barra de menus, escolha **Projeto**, **Propriedades**.  Para obter mais informações, consulte [Como abrir páginas de propriedade do projeto](../misc/how-to-open-project-property-pages.md).  
  
2.  Na caixa de diálogo **Páginas de Propriedades**, navegue até a página **Propriedades de Configuração**, **Etapa de Compilação Personalizada**, **Geral**.  
  
3.  Modifique as configurações.  
  
## Consulte também  
 [Páginas de propriedade](../ide/property-pages-visual-cpp.md)