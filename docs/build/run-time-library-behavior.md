---
title: "Comportamento da biblioteca em tempo de execu&#231;&#227;o | Microsoft Docs"
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
  - "_DllMainCRTStartup"
  - "CRT_INIT"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Macro _CRT_INIT"
  - "Método _DllMainCRTStartup"
  - "Função DllMain"
  - "DLLs [C++], função de ponto de entrada"
  - "DLLs [C++], comportamento da biblioteca em tempo de execução"
  - "DLLs [C++], sequência de inicialização"
  - "anexação de processo [C++]"
  - "desanexação de processo [C++]"
  - "tempo de execução [C++], sequência de inicialização de DLL"
ms.assetid: e06f24ab-6ca5-44ef-9857-aed0c6f049f2
caps.latest.revision: 8
caps.handback.revision: 8
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Comportamento da biblioteca em tempo de execu&#231;&#227;o
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

O código de biblioteca de tempo de execução C\/C\+\+ executa a sequência de inicialização da DLL, eliminando a necessidade de vincular a um módulo separado como era necessário nas janelas 3.x.  É incluído no código de biblioteca de tempo de execução C\/C\+\+ o ponto **\_DllMainCRTStartup**chamado função da DLL.  A função de **\_DllMainCRTStartup** faz diversas coisas, inclusive chamar **\_CRT\_INIT**, que inicializa a biblioteca de tempo de execução C\/C\+\+ e invoca construtores estáticos, C\+\+ em variáveis não local.  Sem essa função, a biblioteca de tempo de execução será mantida em um estado não inicializado.  **\_CRT\_INIT** está disponível para um CRT estaticamente vinculado ou vincular a DLL Msvcr90.dll de CRT, de uma DLL do usuário.  
  
 Quando é possível especificar outra função de ponto de usando \/ENTRY: opção do vinculador, não é recomendado porque sua função de ponto de que teria duplicar tudo o que faz **\_DllMainCRTStartup** .  Ao criar DLL no Visual C\+\+, **\_DllMainCRTStartup** é vinculado em automaticamente e você não precisa especificar uma função de ponto de usando \/ENTRY: opção do vinculador.  
  
 Além de inicializar a biblioteca de tempo de execução C, **\_DllMainCRTStartup** chama uma função chamada `DllMain`.  Dependendo do tipo da DLL você está criando, Visual C\+\+ fornece `DllMain` para você e obtém vinculado de forma que **\_DllMainCRTStartup** sempre tenha algo chamar.  Dessa forma, caso você não precise inicializar o DLL, não há nada especial você tem que fazer ao criar seu DLL.  Se você precisar inicializar o DLL, onde você adicionar seu código depende do tipo da DLL que você estiver escrevendo.  Para obter mais informações, consulte [Inicializando uma DLL](../build/initializing-a-dll.md).  
  
 O código de biblioteca de tempo de execução chama C\/C\+\+ construtores e destruidores em estático, variáveis não local.  Por exemplo, o seguinte origem da DLL, `Equus` e duas `Sugar` são estáticas, objetos não local da classe `CHorse`, definidos em Horses.h.  Não há nenhuma função no código fonte que contém as chamadas para uma função de construtor para `CHorse` ou à função de destruidor pois esses objetos são definidos fora de qualquer função.  Em virtude disso, as chamadas para estes construtores e destruidores devem ser executados pelo código de tempo de execução.  O código de biblioteca de tempo de execução para aplicativos também executa essa função.  
  
```  
#include "horses.h"  
  
CHorse  Equus( ARABIAN, MALE );  
CHorse  Sugar( THOROUGHBRED, FEMALE );  
  
BOOL    WINAPI   DllMain (HANDLE hInst,   
                            ULONG ul_reason_for_call,  
                            LPVOID lpReserved)  
...  
```  
  
 Sempre que um novo processo tenta usar a DLL, o sistema operacional cria uma cópia separada dos dados da DLL: isso é chamado de anexação do processo.  O código de biblioteca de tempo de execução para a DLL chama os construtores para todos os objetos globais, se houver, chama e na função de `DllMain` com anexo de processamento selecionada.  A situação oposta processo é desanexar: as chamadas `DllMain` de código da biblioteca de tempo de execução com processo selecionado e desanexação chamar uma lista de funções de término, incluindo funções de `atexit` , destruidores para os objetos globais, e destruidores para os objetos estáticos.  Observe que a ordem de eventos na anexação do processo é o oposto do que no processo de desanexação.  
  
 O código de biblioteca de tempo de execução também é chamado durante a anexação de thread e o thread desanexar, mas o código em tempo de execução não faz nenhuma inicialização ou encerramento por conta própria.  
  
## O que você deseja fazer?  
  
-   [Inicialize um DLL](../build/initializing-a-dll.md)  
  
## Consulte também  
 [DLLs no Visual C\+\+](../build/dlls-in-visual-cpp.md)