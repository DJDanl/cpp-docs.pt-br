---
title: Aviso PRJ0041 de Build do projeto | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords: PRJ0041
dev_langs: C++
helpviewer_keywords: PRJ0041
ms.assetid: dc9f4cf9-6bd5-4222-89e8-7802a59bb96b
caps.latest.revision: "6"
author: corob-msft
ms.author: corob
manager: ghogen
ms.openlocfilehash: e5a9d5fb5350e4ae6b33fc167aae14b1361291e9
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="project-build-warning-prj0041"></a>Aviso PRJ0041 de Build de Projeto
Não é possível localizar ausente dependência dependência para o arquivo 'file'. Seu projeto ainda pode ser compilado, mas talvez continue aparecendo desatualizado até que esse arquivo é encontrado.  
  
 Um arquivo (arquivo de recurso ou arquivo.idl/.odl, por exemplo, continha uma instrução que o sistema do projeto não foi possível resolver.  
  
 Como o sistema do projeto não processar instruções do pré-processador (#if, por exemplo), a instrução inválida não pode, na verdade, ser parte da compilação.  
  
 Para resolver este aviso, exclua todo o código em arquivos. rc desnecessário ou adicionar arquivos de espaço reservado de nome apropriado.