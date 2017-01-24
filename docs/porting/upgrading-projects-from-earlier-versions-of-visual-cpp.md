---
title: "Atualizando projetos a partir de vers&#245;es anteriores do Visual C++ | Microsoft Docs"
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
  - "movimentação de código de 32 bits"
  - "atualizando aplicativos Visual C++, código de 32 bits"
ms.assetid: 18cdacaa-4742-43db-9e4c-2d9e73d8cc84
caps.latest.revision: 36
caps.handback.revision: 34
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Atualizando projetos a partir de vers&#245;es anteriores do Visual C++
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Na maioria dos casos, você pode abrir um projeto que foi criado em uma versão anterior do Visual Studio. No entanto, para fazer isso, o Visual Studio atualiza o projeto. Se você salvar esse projeto atualizado, ele não pode ser aberto na versão anterior.  
  
> [!IMPORTANT]
>  Se você tentar converter um projeto que já tenha sido convertido, Visual Studio solicitará confirmação porque a reconversão exclui arquivos existentes.  
  
 Muitos projetos atualizados e soluções podem ser criadas com êxito sem modificação. No entanto, alguns projetos podem exigir alterações em configurações, o código\-fonte ou ambos. É recomendável que você use as diretrizes a seguir para resolver os problemas de configurações primeiro e, em seguida, se ainda não compilar o projeto, você pode resolver os problemas de código.  
  
1.  Faça uma cópia dos arquivos de solução e projeto existente. Instale a versão atual do Visual Studio e a versão mais antiga lado a lado para que você possa comparar versões dos arquivos se você quiser.  
  
2.  Na versão atual do Visual Studio, abra — e, portanto, atualize\-a cópia do projeto ou da solução e salvá\-lo.  
  
3.  Para cada projeto convertido, abra o menu de atalho e escolha **propriedades**. Em **Propriedades de configuração**, selecione **geral** e, em seguida, para **conjunto de ferramentas de plataforma**, selecione a versão atual. \(Por exemplo, para o Visual Studio 2013, selecione v120.\)  
  
4.  Compile a solução. Se a compilação falhar, modifique as configurações e recompile.  
  
 Fontes de dados estão contidas em um projeto de banco de dados separado para que você pode modificar e depurar os procedimentos armazenados nessas fontes mais facilmente. Se você atualizar um projeto de C\+\+ que contém fontes de dados, um projeto de banco de dados separado é criado automaticamente.  
  
 Para obter informações sobre como atualizar as destino versões do Windows, consulte [Modificando WINVER e \_WIN32\_WINNT](../porting/modifying-winver-and-win32-winnt.md).  
  
## Consulte também  
 [Alterações no sistema de compilação](../build/build-system-changes.md)   
 [Alterações significativas no Visual C\+\+ 2015](../Topic/Visual%20C++%20change%20history%202003%20-%2020151.md)   
 [Comportamento não padrão](../Topic/Nonstandard%20Behavior.md)