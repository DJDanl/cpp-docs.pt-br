---
title: "PRJ0006 de erro de compilação de projeto | Documentos do Microsoft"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- PRJ0006
dev_langs:
- C++
helpviewer_keywords:
- PRJ0006
ms.assetid: ce092be4-1652-414f-8cb5-b97ef5841f89
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
ms.translationtype: Machine Translation
ms.sourcegitcommit: 3168772cbb7e8127523bc2fc2da5cc9b4f59beb8
ms.openlocfilehash: 012291448f9c83d4557d889a63c7e7e5d16bc748
ms.contentlocale: pt-br
ms.lasthandoff: 02/25/2017

---
# <a name="project-build-error-prj0006"></a>Erro de Build PRJ0006 no Projeto
Não foi possível abrir o arquivo temporário 'arquivo'. Verifique se o arquivo existe e se o diretório não está protegido contra gravação.  
  
 Visual C++ não pôde criar um arquivo temporário durante o processo de compilação. Motivos para isso:  
  
-   Nenhum diretório temp.  
  
-   Diretório temp somente leitura.  
  
-   Sem espaço em disco.  
  
-   A pasta $ (IntDir) é somente leitura ou contém arquivos temporários que são somente leitura.  
  
 Esse erro também ocorrerá após erro PRJ0007: não foi possível criar o diretório' diretório de saída'. Erro prj0007 () significa que não foi possível criar o diretório $ (IntDir), indicando a criação de arquivos temporariamente também falharão.  
  
 Arquivos temporários são criados sempre que você especificar:  
  
-   Um arquivo de resposta.  
  
-   Uma etapa de compilação personalizada.  
  
-   Um evento de compilação.
