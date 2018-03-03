---
title: Vinculando a CRT em seu projeto ATL | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- DllMainCRTStartup
- wWinMainCRTStartup
- WinMainCRTStartup
dev_langs:
- C++
helpviewer_keywords:
- CRT, linking with ATL
- WinMainCRTStartup method
- DllMainCRTStartup method
- wWinMainCRTStartup method
- ATL, C Run-Time library (CRT)
ms.assetid: 650957ae-362c-4ecf-8b03-5d49138e8b5b
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 631426fece3960303d67d8929e99c404beaab998
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="linking-to-the-crt-in-your-atl-project"></a>Vinculando a CRT em seu projeto ATL
O [bibliotecas em tempo de execução C](../c-runtime-library/crt-library-features.md) (CRT) fornece muitas funções úteis que podem facilitar programação muito durante o desenvolvimento de ATL. Todos os projetos ATL vincule à biblioteca CRT. Você pode ver as vantagens e desvantagens de vinculação de método em [benefícios e as vantagens e desvantagens do método usado para vincular CRT](../atl/benefits-and-tradeoffs-of-the-method-used-to-link-to-the-crt.md).  
  
## <a name="effects-of-linking-to-the-crt-on-your-program-image"></a>Efeitos de vinculação para CRT em sua imagem de programa  
 Se você vincular estaticamente CRT, código do CRT é colocado em sua imagem executável e não é necessário ter a DLL do CRT presente em um sistema para executar sua imagem. Se você vincular dinamicamente CRT, referências ao código na DLL do CRT são colocadas em sua imagem, mas não o próprio código. Em ordem para a imagem ser executado em um determinado sistema, a DLL do CRT deve estar presente no sistema. Mesmo quando você dinamicamente vincular CRT, você pode achar que alguns códigos podem ser vinculados estaticamente (por exemplo, **DllMainCRTStartup**).  
  
 Quando você vincular sua imagem, explícita ou implicitamente especifique um ponto de entrada que o sistema operacional chamará depois de carregar a imagem. Para uma DLL, o ponto de entrada padrão é **DllMainCRTStartup**. Para um executável, ele é **WinMainCRTStartup**. Você pode substituir o padrão com a opção de vinculador /ENTRY. CRT fornece uma implementação de **DllMainCRTStartup**, **WinMainCRTStartup**, e **wWinMainCRTStartup** (o ponto de entrada Unicode para um EXE). Esses pontos de entrada fornecido CRT chamar construtores em objetos globais e inicializar outras estruturas de dados que são usadas por algumas funções de CRT. Esse código de inicialização adiciona cerca de 25K à imagem se ele está vinculado estaticamente. Se ele estiver vinculado dinamicamente, a maioria do código é na DLL, para que o tamanho da imagem fique pequeno.  
  
 Para obter mais informações, consulte o tópico de vinculador [/ENTRY (símbolo de ponto de entrada)](../build/reference/entry-entry-point-symbol.md).  
  
## <a name="optimization-options"></a>Opções de otimização  
 Usando a opção de vinculador /OPT: NOWIN98 pode reduzir ainda mais um controle ATL padrão por 10 mil, às custas do aumento de tempo em sistemas Windows 98 de carregamento. Para obter mais informações sobre opções de vinculação, consulte [/OPÇ (otimizações)](../build/reference/opt-optimizations.md).  
  
## <a name="see-also"></a>Consulte também  
 [Programando com código ATL e C Run-Time](../atl/programming-with-atl-and-c-run-time-code.md)   
 [Comportamento de DLLs e da biblioteca em tempo de execução do Visual C++](../build/run-time-library-behavior.md)

