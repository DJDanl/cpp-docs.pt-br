---
title: "CL invoca o vinculador | Microsoft Docs"
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
  - "cl"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "compilador cl.exe [C++], compilando sem vinculação"
  - "compilador cl.exe [C++], controlando vinculador"
  - "compilando o código-fonte [C++], sem vinculação"
  - "invocando vinculador do compilador"
  - "ferramenta LINK [C++], invocando do compilador CL"
ms.assetid: eae47ef7-09eb-40c9-b318-7c714cd452fc
caps.latest.revision: 8
caps.handback.revision: 8
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# CL invoca o vinculador
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

O CL invocada automaticamente o vinculador depois de criar a menos que a opção \/c é usada.  Passagens de CL ao vinculador os nomes dos arquivos de .obj criados durante a compilação e os nomes de outros arquivos especificados na linha de comando.  O vinculador usa as opções listadas na variável de ambiente de LINK.  Você pode usar a opção \/link para especificar opções do vinculador na linha de comando de CL.  Opções que seguem a substituição da opção \/link aqueles na variável de ambiente de LINK.  As opções na tabela a seguir suprimem vincular.  
  
|Opção|Descrição|  
|-----------|---------------|  
|\/c|Construir sem vincular|  
|\/E, \/EP, \/P|Preprocess sem compilar ou vincular|  
|\/Zg|Gerencia protótipos de função|  
|\/Zs|Verifique a sintaxe|  
  
 Para obter detalhes adicionais sobre vincular, consulte [Opções do vinculador](../../build/reference/linker-options.md).  
  
## Exemplo  
 Suponha que você está criando três arquivos de origem de C: 2.0 MAIN.c, MOD1.c, e. MOD2.c.  Cada arquivo inclui uma chamada a uma função definida em um arquivo diferente:  
  
-   MAIN.c chama a função `func1` em MOD1.c e a função `func2` em. MOD2.c.  
  
-   MOD1.c chama as funções da biblioteca `printf_s` e `scanf_s`do padrão.  
  
-   MOD2.c chama as funções dos gráficos `myline` nomeadas e `mycircle`, que são definidas em uma biblioteca MYGRAPH.lib nomeada.  
  
 Para criar esse programa, compile com a seguinte linha de comando:  
  
```  
CL MAIN.c MOD1.C MOD2.C MYGRAPH.lib  
```  
  
 CL O primeiro os arquivos de origem cria C e cria arquivos de objeto MAIN.obj, MOD1.obj, e MOD2.obj.  O compilador coloca o nome da biblioteca padrão em cada arquivo de .obj.  Para obter mais detalhes, consulte [Use a biblioteca de tempo de execução](../../build/reference/md-mt-ld-use-run-time-library.md).  
  
 O CL transmite os nomes dos arquivos de .obj, junto com o nome MYGRAPH.lib, ao vinculador.  O vinculador resolve as referências externas como segue:  
  
1.  Em MAIN.obj, a referência a `func1` é resolvida usando a definição em MOD1.obj; a referência a `func2` é resolvida usando a definição em MOD2.obj.  
  
2.  Em MOD1.obj, as referências a `printf_s` e `scanf_s` são resolvidos usando as definições que encontra na biblioteca do vinculador denominado dentro de MOD1.obj.  
  
3.  Em MOD2.obj, as referências a `myline` e `mycircle` são resolvidos usando as definições em MYGRAPH.lib.  
  
## Consulte também  
 [Opções do compilador](../../build/reference/compiler-options.md)   
 [Definindo opções do compilador](../Topic/Setting%20Compiler%20Options.md)