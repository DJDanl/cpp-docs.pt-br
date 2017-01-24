---
title: "pgomgr | Microsoft Docs"
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
  - "programa pgomgr"
  - "otimizações guiadas por perfil, pgomgr"
ms.assetid: 74589126-df18-42c9-8739-26d60e148d6a
caps.latest.revision: 18
caps.handback.revision: 18
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# pgomgr
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Adiciona dados do perfil de um ou mais arquivos de .pgc no arquivo de .pgd.  
  
## Sintaxe  
  
```  
pgomgr [options] pgcfiles pgdfile  
```  
  
#### Parâmetros  
 `options`  
 As seguintes opções podem ser especificadas ao pgomgr:  
  
 Opções disponíveis de pgomgr vídeos de**\/help—**\(para curto\/?\).  
  
 **\/clear—**Faz com que o arquivo de .pgd a ser apagado de todas as informações de perfil.  Você não pode especificar um arquivo de .pgc quando **\/clear** é especificado.  
  
 **\/detail**— Exibe as estatísticas detalhadas, incluindo informações sobre a cobertura do gráfico de fluxo.  
  
 **\/summary**— Estatísticas por função vídeos.  
  
 **\/unique**— quando usadas com **\/summary**, as causas decoraram nomes de função para exibir.  A opção, quando \/unique não é usado, é que os nomes de função undecorated sejam exibidos.  
  
 **\/merge :**\[*n*\]**—**faz com que os dados no arquivo ou em arquivos de .pgc a serem adicionados ao arquivo de .pgd.  O parâmetro opcional, *em*, permite que você especifique que os dados devem ser adicionados tempo *de em* .  Por exemplo, se um cenário seria feito normalmente 6 vezes, você pode tornar uma vez em um execução do teste e o adiciona ao arquivo de .pgd seis vezes com **pgomgr \/merge:6**.  
  
 `pgcfiles`  
 Um ou mais dados do perfil dos arquivos de .pgc cujos você deseja mesclar no arquivo de .pgd.  Você pode especificar um único arquivo de .pgc um ou mais arquivos de .pgc.  Se você não especifica nenhum arquivo de .pgc, o pgomgr mesclará todos os arquivos de .pgc cujos nomes de arquivo são os mesmos do arquivo de .pgd.  
  
 `pgdfile`  
 O arquivo de .pgd em que você mescla dados do arquivo ou arquivos de .pgc.  
  
## Comentários  
  
> [!NOTE]
>  É possível iniciar esta ferramenta somente usando o prompt de comando [!INCLUDE[vsprvs](../../assembler/masm/includes/vsprvs_md.md)].  Não é possível iniciá\-lo a partir de um prompt de comando do sistema ou do gerenciador de arquivos.  
  
## Exemplo  
 No exemplo a seguir, o arquivo de .pgd foi limpo de dados do perfil.  
  
```  
pgomgr /clear myapp.pgd  
```  
  
 No exemplo a seguir, os dados do perfil em myapp1.pgc foram adicionados ao arquivo de .pgd 3 vezes.  
  
```  
pgomgr /merge:3 myapp1.pgc myapp.pgd  
```  
  
 No exemplo a seguir, os dados do perfil de todos os arquivos de myapp\#.pgc são adicionados ao arquivo de myapp.pgd.  
  
```  
pgomgr -merge myapp1.pgd  
```  
  
## Consulte também  
 [Ferramentas para otimização orientada a perfil](../../build/reference/tools-for-manual-profile-guided-optimization.md)