---
title: "Redistribuindo um aplicativo ATL | Microsoft Docs"
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
  - "ATL, redistribuindo"
  - "Modelos OLE DB, redistribuindo"
  - "redistribuindo ATL"
  - "redistribuindo modelos OLE DB"
ms.assetid: 9a696b22-2345-43ec-826b-be7cb8cfd676
caps.latest.revision: 16
caps.handback.revision: 16
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Redistribuindo um aplicativo ATL
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

A partir do Visual Studio 2012, a biblioteca ATL \(Active Template\) é uma biblioteca de somente de cabeçalho.  Projetos ATL não tem um vínculo dinâmico para a opção de ATL.  Nenhuma biblioteca ATL redistribuível é necessária.  
  
 Se você redistribuir um aplicativo executável ATL, você deve registrar o arquivo .exe \(e todos os controles dentro dele\) emitindo o comando a seguir:  
  
```  
filename /regserver  
  
```  
  
 onde `filename` é o nome do arquivo executável.  
  
 No Visual Studio 2010, um projeto ATL pode ser criado para um MinDependency ou uma configuração de MinSize.  Uma configuração de MinDependency é obtido quando você definir o **uso de ATL** propriedade **Link estático para ATL** no **geral** página de propriedades e defina o **biblioteca de tempo de execução** propriedade **multi\-threaded \(\/ MT\)** no **geração de código** página de propriedade \(pasta C\/C\+\+\).  
  
 Uma configuração de MinSize é obtido quando você definir o **uso de ATL** propriedade **Link dinâmico para ATL** no **geral** página de propriedade ou conjunto do **biblioteca de tempo de execução** propriedade **DLL multi\-threaded \(\/ MD\)** no **geração de código** página de propriedade \(pasta C\/C\+\+\).  
  
 MinSize faz com que a saída de arquivo tão pequenas quanto possível mas exige que ATL100.dll e msvcr100 \(se você tiver selecionado o **DLL multi\-threaded \(\/ MD\)** opção\) no computador de destino.  ATL100.dll deve ser registrado no computador de destino para garantir que todas as funcionalidades do ATL estão presente.  ATL100.dll contém ANSI e Unicode exporta.  
  
 Se você compilar seu projeto ATL ou modelos OLE DB de destino MinDependency, não é necessário instalar e registrar ATL100.dll no computador de destino, embora você poderá obter uma imagem ampliada do programa.  
  
 Para aplicativos de modelos OLE DB, certifique\-se de que o computador de destino tem as versões mais recentes dos arquivos do Microsoft Data Access Components \(MDAC\).  Para obter mais informações, consulte [Redistribuindo arquivos de suporte de banco de dados](../ide/redistributing-database-support-files.md).  
  
## Consulte também  
 [Redistribuindo arquivos do Visual C\+\+](../Topic/Redistributing%20Visual%20C++%20Files.md)