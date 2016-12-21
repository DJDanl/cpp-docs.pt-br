---
title: "Editando uma cadeia de caracteres em um recurso de informa&#231;&#245;es da vers&#227;o | Microsoft Docs"
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
  - "vc.editors.version"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "recursos de informações de versão"
  - "recursos [Visual Studio], editando informações de versão"
ms.assetid: d3a7d4e4-7d31-47c2-902c-f50b8404ba4f
caps.latest.revision: 13
caps.handback.revision: 9
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Editando uma cadeia de caracteres em um recurso de informa&#231;&#245;es da vers&#227;o
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

### Para editar uma cadeia de caracteres em um recurso de informações de versão  
  
1.  Clique no item uma vez para selecioná\-lo, em seguida, novamente para começar a editá\-lo. Faça as alterações diretamente na tabela de informações de versão ou no [janela propriedades](../Topic/Properties%20Window.md). As alterações feitas serão refletidas em ambos.  
  
     **Observação** ao editar o **FILEFLAGS** chave no editor de informações de versão, você observará que não é possível definir o **Depurar**, **compilação particular**, ou **compilação especial** propriedades \(na janela de propriedades\) para arquivos. RC:  
  
    -   Define as informações de versão do **Depurar** propriedade com um \#ifdef no script de recurso, com base no **Debug** sinalizador de compilação.  
  
    -   Se o **compilação particular** chave tem um **valor** definido na tabela de informações de versão, correspondente **compilação particular** propriedade \(na janela de propriedades\) para o **FILEFLAGS** chave será **True**. Se o **valor** está vazia, a propriedade será **False**. Da mesma forma, o **compilação especial** chave \(na tabela de informações de versão\) está ligado ao **compilação especial** propriedade para o **FILEFLAGS** chave.  
  
 Você pode classificar a sequência de informações do bloco de cadeia de caracteres clicando nos títulos de coluna de valor ou a chave. Esses cabeçalhos reorganizar automaticamente as informações em seqüência selecionada.  
  
 Para obter informações sobre como adicionar recursos a projetos gerenciados, consulte [recursos em aplicativos](../Topic/Resources%20in%20Desktop%20Apps.md) no *Guia do desenvolvedor do .NET Framework.* Para obter informações sobre como adicionar manualmente os arquivos de recurso para projetos gerenciados, acessar recursos, exibir recursos estáticos e atribuir cadeias de caracteres de recursos a propriedades, consulte [passo a passo: Localizando Windows Forms](http://msdn.microsoft.com/pt-br/9a96220d-a19b-4de0-9f48-01e5d82679e5) e [Walkthrough: Using Resources for Localization with ASP.NET](../Topic/Walkthrough:%20Using%20Resources%20for%20Localization%20with%20ASP.NET.md).  
  
 **Requisitos**  
  
 Win32  
  
## Consulte também  
 [Editor de informações da versão](../mfc/version-information-editor.md)   
 [Informações de versão \(Windows\)](https://msdn.microsoft.com/library/windows/desktop/ms646981.aspx)