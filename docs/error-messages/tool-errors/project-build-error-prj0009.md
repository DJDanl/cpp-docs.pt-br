---
title: "PRJ0009 de erro de compilação de projeto | Documentos do Microsoft"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- PRJ0009
dev_langs:
- C++
helpviewer_keywords:
- PRJ0009
ms.assetid: 89291778-cda4-495d-983f-ddcc06dfc98b
caps.latest.revision: 6
author: corob-msft
ms.author: corob
manager: ghogen
translation.priority.ht:
- cs-cz
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- pl-pl
- pt-br
- ru-ru
- tr-tr
- zh-cn
- zh-tw
translationtype: Machine Translation
ms.sourcegitcommit: 3168772cbb7e8127523bc2fc2da5cc9b4f59beb8
ms.openlocfilehash: 3e3d36b814bee46c799c63778fb8cb152eb0dcbf
ms.lasthandoff: 02/25/2017

---
# <a name="project-build-error-prj0009"></a>Erro de Build PRJ0009 no Projeto
Criar log não pôde ser aberto para gravação.  
  
 **Certifique-se de que o arquivo não está aberto por outro processo e não é protegido contra gravação.**  
  
 Depois de definir o **criar log** propriedade **Sim** e executar uma compilação ou recompilação, Visual C++ não foi possível abrir o log de compilação em modo exclusivo.  
  
 Inspecionar o **criar log** configuração abrindo o **opções** caixa de diálogo (no **ferramentas** menu, clique em **opções** comando) e, em seguida, selecionando **VC + + compilação** no **projetos** pasta. O arquivo de compilação é chamado BuildLog e é gravado para o diretório intermediário $(IntDir).  
  
 Possíveis motivos para esse erro:  
  
-   Você está executando dois processos do Visual C++ e tentar compilar a mesma configuração do mesmo projeto em ambos simultaneamente.  
  
-   O arquivo de log de compilação é aberto em um processo que bloqueia o arquivo.  
  
-   O usuário não tem permissão para criar um arquivo.  
  
-   O usuário atual não tem acesso de gravação para o arquivo BuildLog.
