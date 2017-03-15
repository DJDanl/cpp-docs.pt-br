---
title: "Op&#231;&#245;es EDITBIN | Microsoft Docs"
ms.custom: ""
ms.date: "12/16/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
f1_keywords: 
  - "editbin"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Programa EDITBIN, opções"
ms.assetid: 2da9f88e-cbab-4d64-bb66-ef700535230f
caps.latest.revision: 11
caps.handback.revision: 11
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Op&#231;&#245;es EDITBIN
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Você pode usar EDITBIN para modificar arquivos de objeto, arquivos executáveis, \(DLLs\) e bibliotecas de vínculo dinâmico\) nativa.  As opções especificam as alterações que EDITBIN faz.  
  
 Uma opção consiste em um especificador da opção, que é um traço \(–\) ou uma barra \(\/\), seguido pelo nome da opção.  Os nomes de opção não podem ser abreviados.  Algumas opções têm os argumentos que são especificados depois de dois\-pontos \(: \).  Nenhum espaço ou a guia são permitidos em uma especificação da opção.  Use um ou mais espaços ou guias para separar especificações de opção na linha de comando.  Os nomes da opção e seus argumentos da palavra\-chave ou argumentos de nome de arquivo não diferenciam maiúsculas de minúsculas.  Por exemplo, o associar e \/BIND significa a mesma coisa.  
  
 EDITBIN tem as seguintes opções:  
  
|Opção|Finalidade|  
|-----------|----------------|  
|[\/ALLOWBIND](../../build/reference/allowbind.md)|Especifica se uma DLL pode ser associado.|  
|[\/ALLOWISOLATION](../Topic/-ALLOWISOLATION.md)|Especifica o comportamento de pesquisa da DLL ou do arquivo executável.|  
|[\/APPCONTAINER](../../build/reference/appcontainer.md)|Especifica se o aplicativo deve executar no AppContainer\- por exemplo, um aplicativo de [!INCLUDE[win8_appname_long](../../build/includes/win8_appname_long_md.md)] .|  
|[\/BIND](../../build/reference/bind.md)|Define os endereços dos pontos de entrada nos objetos especificados ao tempo de carregamento de velocidade.|  
|[\/DYNAMICBASE](../../build/reference/dynamicbase.md)|Especifica se a DLL ou a imagem executável podem ser aleatoriamente em rebased de hora usando o randomization \(ASLR\) do layout do espaço de endereço.|  
|[\/ERRORREPORT](../../build/reference/errorreport-editbin-exe.md)|Relata erros internos a Microsoft.|  
|[\/HEAP](../../build/reference/heap.md)|Define o tamanho do heap da imagem executável em bytes.|  
|[\/HIGHENTROPYVA](../../build/reference/highentropyva.md)|Especifica se a DLL ou a imagem executável dão suporte ao randomization \(64 bits\) alto \(ASLR\) do layout do espaço de endereço da entropia.|  
|[\/INTEGRITYCHECK](../Topic/-INTEGRITYCHECK.md)|Especifica se a verificação da assinatura digital no tempo de carregamento.|  
|[\/LARGEADDRESSAWARE](../Topic/-LARGEADDRESSAWARE.md)|Especifica se o objeto oferece suporte aos endereços que são maiores de duas gigabytes.|  
|[\/NOLOGO](../../build/reference/nologo-editbin.md)|Suprime a faixa de inicialização de EDITBIN.|  
|[\/NXCOMPAT](../Topic/-NXCOMPAT.md)|Especifica se a imagem executável é compatível com prevenção de execução dos dados do windows.|  
|[\/REBASE](../Topic/-REBASE.md)|Define os endereços de base para os objetos especificados.|  
|[\/RELEASE](../../build/reference/release.md)|Define a soma de verificação no cabeçalho.|  
|[\/SECTION](../Topic/-SECTION%20\(EDITBIN\).md)|Substitui os atributos de uma seção.|  
|[\/STACK](../../build/reference/stack.md)|Define o tamanho da pilha de imagem executável em bytes.|  
|[\/SUBSYSTEM](../../build/reference/subsystem.md)|Especifica o ambiente de execução.|  
|[\/SWAPRUN](../../build/reference/swaprun.md)|Especifica que a imagem executável devem ser copiados para o arquivo de permuta, e executa de lá.|  
|[\/TSAWARE](../../build/reference/tsaware.md)|Especifica que o aplicativo é projetado para ser executado em um ambiente de vários usuários.|  
|[\/VERSION](../../build/reference/version.md)|Define o número de versão no cabeçalho.|  
  
## Consulte também  
 [Ferramentas de compilação do C\/C\+\+](../Topic/C-C++%20Build%20Tools.md)   
 [Referência de EDITBIN](../Topic/EDITBIN%20Reference.md)