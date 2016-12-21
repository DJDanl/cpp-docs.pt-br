---
title: "Criando um recurso de dados ou novo personalizado | Microsoft Docs"
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
  - "vc.editors.binary"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "recursos personalizados [C++]"
  - "recursos de dados [C++]"
  - "recursos [Visual Studio], criando"
ms.assetid: 9918bf96-38fa-43a1-a384-572f95d84950
caps.latest.revision: 13
caps.handback.revision: 9
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Criando um recurso de dados ou novo personalizado
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Você pode criar um novo recurso personalizado ou dados colocando o recurso em um arquivo separado usando a sintaxe do arquivo de script \(. rc\) de recurso normal e, em seguida, incluindo o arquivo clicando duas vezes o seu projeto no Solution Explorer e clicando em **inclui recursos** no menu de atalho.  
  
### Para criar um novo recurso personalizado ou dados  
  
1.  [Criar um arquivo. rc](../windows/how-to-create-a-resource-script-file.md) que contém o recurso personalizado ou dados.  
  
     Você pode digitar dados personalizados em um arquivo. rc como terminada em nulo cadeias de caracteres entre aspas ou inteiros em formato octal, hexadecimal ou decimal.  
  
2.  Em **Solution Explorer**, clique com o arquivo do projeto. RC e clique em **inclui recursos** no menu de atalho.  
  
3.  No **diretivas de tempo de compilação** digite um **\#include** instrução que fornece o nome do arquivo que contém o recurso personalizado. Por exemplo:  
  
    ```  
    #include mydata.rc  
    ```  
  
     Verifique se a sintaxe e a ortografia de que você digitou estão corretas. O conteúdo de **diretivas de tempo de compilação** caixa são inseridos no arquivo de script de recurso, exatamente como você os digitou.  
  
4.  Clique em **OK** para registrar as alterações.  
  
 É outra maneira de criar um recurso personalizado importar um arquivo externo como o recurso personalizado. Para obter mais informações, consulte [Importando e exportando recursos](../windows/how-to-import-and-export-resources.md).  
  
 Para obter informações sobre como adicionar recursos a projetos gerenciados, consulte [recursos em aplicativos](../Topic/Resources%20in%20Desktop%20Apps.md) no *Guia do desenvolvedor do .NET Framework.* Para obter informações sobre como adicionar manualmente os arquivos de recurso para projetos gerenciados, acessar recursos, exibir recursos estáticos e atribuir cadeias de caracteres de recursos a propriedades, consulte [passo a passo: Localizando Windows Forms](http://msdn.microsoft.com/pt-br/9a96220d-a19b-4de0-9f48-01e5d82679e5) e [Walkthrough: Using Resources for Localization with ASP.NET](../Topic/Walkthrough:%20Using%20Resources%20for%20Localization%20with%20ASP.NET.md).  
  
 Requisitos  
  
 Win32  
  
## Consulte também  
 [Editor binário](../mfc/binary-editor.md)