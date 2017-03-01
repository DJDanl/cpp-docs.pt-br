---
title: "PRJ0041 de aviso de compilação de projeto | Documentos do Microsoft"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- PRJ0041
dev_langs:
- C++
helpviewer_keywords:
- PRJ0041
ms.assetid: dc9f4cf9-6bd5-4222-89e8-7802a59bb96b
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
ms.openlocfilehash: d2654c0daa81a9b7cd8e0920aad35a902dc84a5f
ms.lasthandoff: 02/25/2017

---
# <a name="project-build-warning-prj0041"></a>Aviso PRJ0041 de Build de Projeto
Não é possível localizar ausente dependência 'dependência' arquivo 'arquivo'. Seu projeto ainda pode ser compilado, mas talvez continue aparecendo desatualizado até que esse arquivo é encontrado.  
  
 Um arquivo (arquivo de recurso ou arquivo.idl/.odl, por exemplo, contido uma instrução que não foi possível resolver o sistema do projeto.  
  
 Como o sistema do projeto não processa as instruções do pré-processador (#if, por exemplo), a instrução incorreta pode não realmente ser parte da compilação.  
  
 Para resolver esse aviso, excluir todo o código em arquivos. rc desnecessário ou adicionar arquivos de espaço reservado de nome apropriado.
