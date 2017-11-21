---
title: Erro de Build prj0009 no projeto | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords: PRJ0009
dev_langs: C++
helpviewer_keywords: PRJ0009
ms.assetid: 89291778-cda4-495d-983f-ddcc06dfc98b
caps.latest.revision: "6"
author: corob-msft
ms.author: corob
manager: ghogen
ms.openlocfilehash: 4793a4541c133372e7833853caad174303f2a9dc
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="project-build-error-prj0009"></a>Erro de Build PRJ0009 no Projeto
Criar log não pôde ser aberto para gravação.  
  
 **Certifique-se de que o arquivo não está aberto por outro processo e não está protegido contra gravação.**  
  
 Depois de definir o **criar log** propriedade **Sim** e executar uma compilação ou recompilação, Visual C++ não pôde abrir o log de compilação no modo exclusivo.  
  
 Inspecione o **criar log** configuração abrindo o **opções** caixa de diálogo (no **ferramentas** menu, clique em **opções** comando) e, em seguida, selecionando **VC + + compilação** no **projetos** pasta. O arquivo de compilação é chamado BuildLog e é gravado para o diretório intermediário $(IntDir).  
  
 Possíveis motivos para esse erro:  
  
-   Você está executando dois processos do Visual C++ e tentar criar a mesma configuração do mesmo projeto em ambos ao mesmo tempo.  
  
-   O arquivo de log de compilação é aberto em um processo que bloqueia o arquivo.  
  
-   O usuário não tem permissão para criar um arquivo.  
  
-   O usuário atual não tem acesso de gravação para o arquivo BuildLog.