---
title: "pgosweep | Microsoft Docs"
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
  - "programa pgosweep"
  - "otimizações guiadas por perfil, pgosweep"
ms.assetid: f39dd3b7-1cd9-4c3b-8e8b-fb794744b757
caps.latest.revision: 22
caps.handback.revision: 22
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# pgosweep
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Usado na otimização perfil\- orientada para gravar todas analisar dados de um programa em execução no arquivo de .pgc.  
  
## Sintaxe  
  
```  
pgosweep [options] image pgcfile  
```  
  
#### Parâmetros  
 `options`  
 Um parâmetro opcional que pode ser deixado em branco.  Os valores válidos para `options` são os seguintes:  
  
-   **\/?** ou **\/help,** exibem a mensagem da ajuda.  
  
-   **\/noreset,** preserva a contagem em estruturas de dados de tempo de execução.  
  
 `image`  
 O caminho completo de um arquivo ou arquivo .dll que é criado usando a opção \/LTCG:PGINSTRUMENTdo compilador.  
  
 `pgcfile`  
 O arquivo de .pgc onde este comando gravará os dados para fora conta.  
  
## Comentários  
 Este comando funciona em programas que foram compilados com a opção do compilador de \/LTCG:PGINSTRUMENT .  Interrompe um programa em execução e grava os dados do perfil para um novo arquivo de .pgc.  Por padrão, o comando redefine contagens após cada operação de gravação.  Se você especificar a opção de **\/noreset** , o comando os valores, mas eles não redefinido no programa em execução.  Essa opção apresentará dados duplicados se você recuperar os dados do perfil posterior.  
  
 Um uso de backup para `pgosweep` é recuperar informações de perfil apenas durante o tempo de execução do aplicativo.  Por exemplo, você pode executar `pgosweep` shortly after você inicia o aplicativo e descarta esse arquivo.  Isso deve remover os perfis de dados associados ao custo de inicialização.  Em seguida, você pode executar `pgosweep` antes de encerrar o aplicativo.  Agora os dados coletados têm informações de perfil somente de tempo de execução.  
  
 Ao nomear um arquivo de .pgc \(\)`pgcfile`você pode usar o formato padrão, que é *appname\!n*.pgc.  Se você usar esse formato, o compilador encontrará esses dados no estágio de \/LTCG:PGO .  Se você não usar o formato padrão, você deve usar [pgomgr](../../build/reference/pgomgr.md) para mesclar os arquivos de .pgc.  
  
## Exemplo  
  
```  
pgosweep myapp.exe myapp!1.pgc  
```  
  
 Neste exemplo, `pgosweep` grava informações de perfil para myapp.exe ao myapp\! 1.pgc.  
  
## Consulte também  
 [Ferramentas para otimização orientada a perfil](../../build/reference/tools-for-manual-profile-guided-optimization.md)