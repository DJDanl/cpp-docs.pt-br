---
title: "Editor de informa&#231;&#245;es da vers&#227;o | Microsoft Docs"
ms.custom: ""
ms.date: "12/15/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
f1_keywords: 
  - "vc.editors.version.F1"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Editor de informações de versão sobre o editor de informações de versão"
  - "editores, informações de versão"
  - "editores de recursos do editor de informações de versão"
ms.assetid: 772e6f19-f765-4cec-9521-0ad3eeb99f9b
caps.latest.revision: 13
caps.handback.revision: 9
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Editor de informa&#231;&#245;es da vers&#227;o
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Informações de versão consistem da empresa e identificação do produto, um número de versão do produto e a notificação de direitos autorais e marcas. Com o editor de informações de versão, você pode cria e manter esses dados, que são armazenados no recurso de informações de versão. O recurso de informações de versão não é necessário por um aplicativo, mas é um local útil para coletar informações que identificam o aplicativo. Informações de versão também são usadas por APIs de configuração.  
  
 Um recurso de informações de versão tem um bloco superior e um ou mais blocos inferiores: um único bloco fixo de informações na parte superior e um ou mais blocos de informações de versão na parte inferior \(para outros idiomas e\/ou conjuntos de caracteres\). O bloco superior tem caixas numéricas editáveis e selecionáveis listas suspensas. Os blocos inferiores têm somente as caixas de texto editável.  
  
> [!NOTE]
>  O padrão do Windows é ter apenas uma versão recurso, chamado VS\_VERSION\_INFO.  
  
 O editor de informações de versão permite que você:  
  
-   [Editar uma cadeia de caracteres em um recurso de informações de versão](../mfc/editing-a-string-in-a-version-information-resource.md)  
  
-   [Adicionar informações de versão para outro idioma \(novo bloco de informações de versão\)](../mfc/adding-version-information-for-another-language.md)  
  
-   [Excluir um bloco de informações de versão](../mfc/deleting-a-version-information-block.md)  
  
-   [Acessar informações de versão em seu programa](../mfc/accessing-version-information-from-within-your-program.md)  
  
    > [!NOTE]
    >  Ao usar o editor de informações de versão, em muitos casos você pode clique com botão direito para exibir um menu de atalho de comandos específicos do recurso. Por exemplo, se você clicar em enquanto estiver apontando para uma entrada de cabeçalho do bloco, o menu de atalho mostra os comandos de novas informações de bloco de versão e excluir informações do bloco de versão.  
  
 Para obter informações sobre como adicionar recursos a projetos gerenciados, consulte [recursos em aplicativos](../Topic/Resources%20in%20Desktop%20Apps.md) no *Guia do desenvolvedor do .NET Framework.* Para obter informações sobre como adicionar manualmente os arquivos de recurso para projetos gerenciados, acessar recursos, exibir recursos estáticos e atribuir cadeias de caracteres de recursos a propriedades, consulte [passo a passo: Localizando Windows Forms](http://msdn.microsoft.com/pt-br/9a96220d-a19b-4de0-9f48-01e5d82679e5) e [Walkthrough: Using Resources for Localization with ASP.NET](../Topic/Walkthrough:%20Using%20Resources%20for%20Localization%20with%20ASP.NET.md).  
  
## Requisitos  
 Win32  
  
## Consulte também  
 [Editores de recursos](../mfc/resource-editors.md)   
 [Menus e outros recursos](http://msdn.microsoft.com/library/windows/desktop/ms632583.aspx)