---
title: "No&#231;&#245;es b&#225;sicas sobre a fun&#231;&#227;o auxiliar | Microsoft Docs"
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
  - "Função __delayLoadHelper"
  - "Função __delayLoadHelper2"
  - "carregamento atrasado de DLLs, Função auxiliar"
  - "delayhlp.cpp"
  - "delayimp.h"
  - "delayimp.lib"
  - "funções auxiliares"
ms.assetid: 6279c12c-d908-4967-b0b3-cabfc3e91d3d
caps.latest.revision: 8
caps.handback.revision: 8
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# No&#231;&#245;es b&#225;sicas sobre a fun&#231;&#227;o auxiliar
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

A função auxiliar para carregar posterior vinculador\- suporte é o fato que carrega a DLL em tempo de execução.  Você pode alterar a função auxiliar para personalizar o comportamento escrevendo sua própria função e vinculando a seu programa em vez de usar a função auxiliar fornecida em Delayimp.lib.  Uma função auxiliar atende todos os DLL carregados atraso.  
  
 Você pode fornecer sua própria versão de função auxiliar se desejar fazer o processamento específico com base nos nomes de DLL ou imports.  
  
 A função auxiliar executar as seguintes ações:  
  
-   Verifica o identificador armazenada na biblioteca para ver se ele já foi carregada já  
  
-   Chamadas **LoadLibrary** para tentar a carga da DLL  
  
-   Chamadas **GetProcAddress** a tentar obter o endereço do procedimento  
  
-   Retorna a importação de atraso ao carregar o thunk para chamar o ponto de entrada agora carregado  
  
 A função auxiliar pode chamar para somente a um gancho de notificação em seu programa depois de cada uma das seguintes ações:  
  
-   Quando a função auxiliar iniciar  
  
-   Imediatamente antes de **LoadLibrary** é chamado na função auxiliar  
  
-   Imediatamente antes de **GetProcAddress** é chamado na função auxiliar  
  
-   Se a chamada a **LoadLibrary** na função auxiliar falha  
  
-   Se a chamada a **GetProcAddress** na função auxiliar falha  
  
-   Após a função auxiliar é o processamento executado  
  
 Cada um desses pontos de gancho pode retornar um valor que altera o processamento regular da rotina de auxiliar de alguma forma a não ser que retornam ao thunk de carga de importação de atraso.  
  
 O código padrão de auxiliar pode ser encontrado em Delayhlp.cpp e em Delayimp.h \(em vc \\ inclua\) e é compilado em Delayimp.lib em vc biblioteca \(\\\).  Você precisará incluir essa biblioteca nas compilações a menos que você escrever sua própria função auxiliar.  
  
 Os tópicos a seguir descrevem a função auxiliar:  
  
-   [Alterações na DLL atrasado carregando a função auxiliar desde o Visual C\+\+ 6.0](../../build/reference/changes-in-the-dll-delayed-loading-helper-function-since-visual-cpp-6-0.md)  
  
-   [Convenções, parâmetros, e tipo de retorno de chamada](../../build/reference/calling-conventions-parameters-and-return-type.md)  
  
-   [Definições da estrutura e da constante](../../build/reference/structure-and-constant-definitions.md)  
  
-   [Calculando valores necessários](../../build/reference/calculating-necessary-values.md)  
  
-   [Descarregando DLL Atraso\- carregado](../../build/reference/explicitly-unloading-a-delay-loaded-dll.md)  
  
## Consulte também  
 [Suporte de vinculador para DLLs carregadas com atraso](../../build/reference/linker-support-for-delay-loaded-dlls.md)