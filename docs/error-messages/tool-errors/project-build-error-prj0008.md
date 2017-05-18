---
title: "PRJ0008 de erro de compilação de projeto | Documentos do Microsoft"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- PRJ0008
dev_langs:
- C++
helpviewer_keywords:
- PRJ0008
ms.assetid: 6bf7f17a-d2a8-4826-99c7-d600d846952f
caps.latest.revision: 7
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
ms.openlocfilehash: 9057dc41d0678c2d24dfc9e058fb1ebf785de399
ms.contentlocale: pt-br
ms.lasthandoff: 02/25/2017

---
# <a name="project-build-error-prj0008"></a>Erro de Build PRJ0008 no Projeto
Não foi possível excluir o arquivo 'arquivo'.  
  
 **Certifique-se de que o arquivo não está aberto por outro processo e não é protegido contra gravação.**  
  
 Durante uma reconstrução ou limpar o Visual C++ exclui todos os arquivos de saída e intermediários conhecidos para a compilação, bem como todos os arquivos que atende às especificações de curinga no **extensões para excluir na limpeza** propriedade o [página de propriedade de configurações de configuração geral](../../ide/general-property-page-project.md).  
  
 Você verá esse erro se o Visual C++ não é possível excluir um arquivo. Para resolver o erro, verifique o arquivo e o diretório gravável para o usuário que faz a compilação.
