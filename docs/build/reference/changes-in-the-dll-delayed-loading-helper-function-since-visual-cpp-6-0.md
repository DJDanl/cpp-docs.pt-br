---
title: "Altera&#231;&#245;es feitas na fun&#231;&#227;o auxiliar de carregamento com atraso da DLL desde o Visual C++ 6.0 | Microsoft Docs"
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
  - "Função __delayLoadHelper2"
  - "carregamento atrasado de DLLs, o que foi alterado"
  - "funções auxiliares, o que foi alterado"
  - "Método PFromRva"
ms.assetid: 99f0be69-105d-49ba-8dd5-3be7939c0c72
caps.latest.revision: 6
caps.handback.revision: 6
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Altera&#231;&#245;es feitas na fun&#231;&#227;o auxiliar de carregamento com atraso da DLL desde o Visual C++ 6.0
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Se você tiver várias versões do Visual C\+\+ em seu computador ou se você tiver definido sua própria função auxiliar, você pode ser afetado por alterações feitas à DLL atrasado carregando a função auxiliar.  Por exemplo:  
  
-   **\_\_delayLoadHelper** agora é **\_\_delayLoadHelper2**  
  
-   **\_\_pfnDliNotifyHook** agora é **\_\_pfnDliNotifyHook2**  
  
-   **\_\_pfnDliFailureHook** agora é **\_\_pfnDliFailureHook2**  
  
-   **\_\_FUnloadDelayLoadedDLL** agora é **\_\_FUnloadDelayLoadedDLL2**  
  
> [!NOTE]
>  Se você estiver usando a função padrão auxiliares, essas alterações não afetarão o.  Não há nenhuma alteração em relação à medida que você invoca o vinculador.  
  
## Várias versões do Visual C\+\+  
 Se você tiver várias versões do Visual C\+\+ no computador, verifique as correspondências delayimp.lib do vinculador.  Se houver uma incompatibilidade, você obterá um relatório de erros `___delayLoadHelper2@8` ou `___delayLoadHelper@8` do vinculador como um símbolo externo não resolvido.  O antigo implica um novo vinculador com um delayimp.lib antigo, e o último implica um o vinculador antigo por um novo delayimp.lib.  
  
 Se você receber um erro não resolvido do vinculador, execute [dumpbin \/linkermember](../../build/reference/linkermember.md): 1 em delayimp.lib que você espera conter a função auxiliar para ver que função auxiliar é definida por vez.  A função auxiliar também poderia ser definida em um arquivo de objeto; executar [dumpbin \/symbols](../../build/reference/symbols.md) e procure `delayLoadHelper(2)`.  
  
 Se você souber o vinculador Visual C\+\+ 6.0, então:  
  
-   Dumpbin de execução no arquivo de .lib ou de .obj auxiliares de carga de atraso para determinar se define **\_\_delayLoadHelper2**.  Caso contrário, o link falhará.  
  
-   Define **\_\_delayLoadHelper** no arquivo de .lib ou de .obj auxiliares de carga de atraso.  
  
## Função definido pelo usuário auxiliar  
 Se você definir sua própria função auxiliar e estiver usando a versão atual do Visual C\+\+, faça o seguinte:  
  
-   Renomeie a função auxiliar a **\_\_delayLoadHelper2**.  
  
-   Como os ponteiros no descritor de atraso \(ImgDelayDescr em delayimp.h\) foram modificados de endereços absolutos vaso \(\) para endereços relacionados \(\) RVAs funcionem como esperado em ambos os 32 \- e programas de 64 bits, você precisa converter esses novamente nos ponteiros.  Uma nova função foi apresentada: PFromRva, encontrado em delayhlp.cpp.  Você pode usar essa função em cada um dos campos do descritor para convertê\-los novamente a 32 \- ou ponteiros de 64 bits.  A função padrão auxiliares de carga de atraso continua a ser um bom modelo a ser usado como um exemplo.  
  
## Carregar todas as importações para uma DLL Atraso\- carregado  
 O vinculador pode carregar todas as importações de uma DLL que você especifica para atraso ser carregado.  Consulte [Carregando todas as importações para uma DLL Atraso\- carregado](../../build/reference/loading-all-imports-for-a-delay-loaded-dll.md) para obter mais informações.  
  
## Consulte também  
 [Understanding the Helper Function](http://msdn.microsoft.com/pt-br/6279c12c-d908-4967-b0b3-cabfc3e91d3d)