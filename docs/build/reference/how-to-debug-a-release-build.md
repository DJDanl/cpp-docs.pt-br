---
title: "Como: depurar uma compilação de versão | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
dev_langs: C++
helpviewer_keywords:
- debugging [C++], release builds
- release builds, debugging
ms.assetid: d333e4d1-4e6c-4384-84a9-cb549702da25
caps.latest.revision: "7"
author: corob-msft
ms.author: corob
manager: ghogen
ms.openlocfilehash: 2719adff3099d4507b1e2f70348023f9d8ec92eb
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="how-to-debug-a-release-build"></a>Como depurar um build da versão
Você pode depurar um build de versão de um aplicativo.  
  
### <a name="to-debug-a-release-build"></a>Para depurar uma compilação de versão  
  
1.  Abra o **páginas de propriedade** caixa de diálogo para o projeto. Para obter detalhes, consulte [trabalhar com propriedades do projeto](../../ide/working-with-project-properties.md).  
  
2.  Clique o **C/C++** nó. Definir **formato informações de depuração** para [compatível C7 (/ Z7)](../../build/reference/z7-zi-zi-debug-information-format.md) ou **banco de dados do programa (/Zi)**.  
  
3.  Expanda **vinculador** e clique no **geral** nó. Definir **habilitar vínculo Incremental** para [não (/ /INCREMENTAL: NO)](../../build/reference/incremental-link-incrementally.md).  
  
4.  Selecione o **depuração** nó. Definir **gerar informações de depuração** para [Sim (/debug)](../../build/reference/debug-generate-debug-info.md).  
  
5.  Selecione o **otimização** nó. Definir **referências** para [/OPT: REF](../../build/reference/opt-optimizations.md) e **habilitar dobra COMDAT** para [/OPT: ICF](../../build/reference/opt-optimizations.md).  
  
6.  Agora você pode depurar seu aplicativo de compilação de versão. Para encontrar um problema, percorrer o código (ou a depuração Just-In-Time de uso), até encontrar onde ocorre a falha e, em seguida, determinar os parâmetros incorretos ou o código.  
  
     Se um aplicativo funciona em uma compilação de depuração, mas não em uma compilação de versão, uma das otimizações de compilador pode expor um defeito no código-fonte. Para isolar o problema, desabilite otimizações selecionadas para cada arquivo de código fonte até localizar o arquivo e otimização que está causando o problema. (Para acelerar o processo, você pode dividir os arquivos em dois grupos, desabilitar a otimização de um grupo e quando você encontrar um problema em um grupo, continuar dividindo até que você isole o arquivo com problema.)  
  
     Você pode usar [/RTC](../../build/reference/rtc-run-time-error-checks.md) para tentar expor esses erros em suas compilações de depuração.  
  
     Para obter mais informações, consulte [otimizando seu código](../../build/reference/optimizing-your-code.md).  
  
## <a name="see-also"></a>Consulte também  
 [Corrigindo problemas do build de versão](../../build/reference/fixing-release-build-problems.md)