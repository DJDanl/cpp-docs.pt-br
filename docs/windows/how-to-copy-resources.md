---
title: "Como copiar recursos | Microsoft Docs"
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
  - "vc.resvw.resource.copying"
  - "vs.resvw.resource.copying"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Arquivos .rc, copiando recursos entre"
  - "arquivos rc, copiando recursos entre"
  - "arquivos de recurso, copiando ou movendo recursos entre"
  - "arquivos de recurso, agrupando lado a lado"
  - "recursos [Visual Studio], copiando"
  - "recursos [Visual Studio], movendo entre arquivos"
ms.assetid: 65f523e8-017f-4fc6-82d1-083c56d9131f
caps.latest.revision: 6
caps.handback.revision: 6
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Como copiar recursos
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Você pode copiar recursos de um arquivo para outro sem alterá\-los ou você pode  [alterar o idioma ou a condição de um recurso ao copiá\-lo](../windows/how-to-change-the-language-or-condition-of-a-resource-while-copying.md).  
  
 É fácil copiar recursos de um recurso existente ou um arquivo executável do arquivo de recurso atual.  Para fazer isso, você abra ambos os arquivos que contêm recursos ao mesmo tempo e arraste os itens de um arquivo para outro ou copie e cole entre os dois arquivos.  Esse método funciona para arquivos de script \(. rc\) de recursos e arquivos de modelo \(. rct\) de recursos, bem como arquivos executáveis \(. exe\).  
  
> [!NOTE]
>  O Visual C\+\+ inclui exemplos de arquivos de recurso que você pode usar em seu próprio aplicativo.  Para obter mais informações, consulte  [Clip\-art: recursos comuns](http://msdn.microsoft.com/pt-br/9bac2891-b6b3-49ec-a287-cec850c707e0).  
  
 Você pode usar o método de arrastar\-e\-soltar entre arquivos. rc que estão abertos  [fora do projeto](../windows/how-to-open-a-resource-script-file-outside-of-a-project-standalone.md).  
  
### Para copiar recursos entre os arquivos usando o método de arrastar\-e\-soltar  
  
1.  Abra ambos os arquivos de recurso autônomos \(para obter mais informações, consulte  [Exibindo recursos em um arquivo de parte externa de um projeto. rc](../windows/how-to-open-a-resource-script-file-outside-of-a-project-standalone.md)\).  Por exemplo, abra Source1.rc e Source2.rc.  
  
2.  Dentro do primeiro arquivo. rc, clique no recurso que você deseja copiar.  Por exemplo, na Source1.rc, clique em IDD\_DIALOG1.  
  
3.  Mantenha pressionada a tecla CTRL e arraste o recurso para o segundo arquivo. rc.  Por exemplo, arraste IDD\_DIALOG1 de Source1.rc para Source2.rc.  
  
    > [!NOTE]
    >  Arrastar o recurso sem manter pressionada a tecla CTRL move o recurso em vez de copiá\-lo.  
  
### Para copiar recursos usando copiar e colar  
  
1.  Abra ambos os arquivos de recurso autônomos \(para obter mais informações, consulte  [Exibindo recursos em um arquivo de parte externa de um projeto. rc](../windows/how-to-open-a-resource-script-file-outside-of-a-project-standalone.md)\).  Por exemplo, Source1.rc e Source2.rc.  
  
2.  No arquivo de origem do qual você deseja copiar um recurso \(por exemplo, Source1.rc\), um recurso de atalho e escolha  **Copy** no menu de atalho.  
  
3.  Clique com o botão direito no arquivo de recurso no qual você gostaria de colar o recurso \(por exemplo, Source2.rc\).  Escolha  **Colar** no menu de atalho.  
  
    > [!NOTE]
    >  Você não pode arrastar e soltar, copiar, recortar ou colar entre arquivos de recurso no projeto \(modo de exibição de recurso\) e arquivos. rc autônomo \(aqueles abertos em janelas de documento\).  Você poderia fazer isso nas versões anteriores do produto.  
  
    > [!NOTE]
    >  Para evitar conflitos com nomes de símbolo ou valores do arquivo existente, Visual C\+\+ podem alterar valor de símbolo do recurso transferido ou o nome do símbolo e o valor quando você copiá\-lo para o novo arquivo.  
  
 Para obter informações sobre como adicionar recursos a projetos gerenciados, consulte  [recursos em aplicativos](../Topic/Resources%20in%20Desktop%20Apps.md) na  *.Guia. do desenvolvedor do NET Framework* Para informações sobre como adicionar manualmente os arquivos de recursos para projetos gerenciados, acesso a recursos, exibindo recursos estáticos e a atribuição de seqüências de caracteres de recursos a propriedades, consulte  [Walkthrough: Localizing Windows Forms](http://msdn.microsoft.com/pt-br/9a96220d-a19b-4de0-9f48-01e5d82679e5) e [Walkthrough: Using Resources for Localization with ASP.NET](../Topic/Walkthrough:%20Using%20Resources%20for%20Localization%20with%20ASP.NET.md).  
  
 Requisitos  
  
 Win32  
  
## Consulte também  
 [Como abrir o arquivo de script do recurso fora de um projeto \(autônomo\)](../windows/how-to-open-a-resource-script-file-outside-of-a-project-standalone.md)   
 [Arquivos de recursos](../mfc/resource-files-visual-studio.md)   
 [Editores de recursos](../mfc/resource-editors.md)