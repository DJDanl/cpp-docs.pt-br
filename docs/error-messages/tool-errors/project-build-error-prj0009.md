---
title: Erro de Build prj0009 no projeto | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- PRJ0009
dev_langs:
- C++
helpviewer_keywords:
- PRJ0009
ms.assetid: 89291778-cda4-495d-983f-ddcc06dfc98b
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: e5692ec643f5e3fe1adebf68048a6c435ab05d6f
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33318448"
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