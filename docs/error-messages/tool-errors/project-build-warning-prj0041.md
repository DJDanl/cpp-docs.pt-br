---
title: Aviso PRJ0041 de Build do projeto | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- PRJ0041
dev_langs:
- C++
helpviewer_keywords:
- PRJ0041
ms.assetid: dc9f4cf9-6bd5-4222-89e8-7802a59bb96b
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 6e845967b0a7116d6edade98b571de5bc1bcd9a1
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="project-build-warning-prj0041"></a>Aviso PRJ0041 de Build de Projeto
Não é possível localizar ausente dependência dependência para o arquivo 'file'. Seu projeto ainda pode ser compilado, mas talvez continue aparecendo desatualizado até que esse arquivo é encontrado.  
  
 Um arquivo (arquivo de recurso ou arquivo.idl/.odl, por exemplo, continha uma instrução que o sistema do projeto não foi possível resolver.  
  
 Como o sistema do projeto não processar instruções do pré-processador (#if, por exemplo), a instrução inválida não pode, na verdade, ser parte da compilação.  
  
 Para resolver este aviso, exclua todo o código em arquivos. rc desnecessário ou adicionar arquivos de espaço reservado de nome apropriado.