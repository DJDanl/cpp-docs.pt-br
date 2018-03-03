---
title: Aviso PRJ0041 de Build do projeto | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- PRJ0041
dev_langs:
- C++
helpviewer_keywords:
- PRJ0041
ms.assetid: dc9f4cf9-6bd5-4222-89e8-7802a59bb96b
caps.latest.revision: 
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 231b58cb0c13d1a3f87e010a5100da564b0be806
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="project-build-warning-prj0041"></a>Aviso PRJ0041 de Build de Projeto
Não é possível localizar ausente dependência dependência para o arquivo 'file'. Seu projeto ainda pode ser compilado, mas talvez continue aparecendo desatualizado até que esse arquivo é encontrado.  
  
 Um arquivo (arquivo de recurso ou arquivo.idl/.odl, por exemplo, continha uma instrução que o sistema do projeto não foi possível resolver.  
  
 Como o sistema do projeto não processar instruções do pré-processador (#if, por exemplo), a instrução inválida não pode, na verdade, ser parte da compilação.  
  
 Para resolver este aviso, exclua todo o código em arquivos. rc desnecessário ou adicionar arquivos de espaço reservado de nome apropriado.