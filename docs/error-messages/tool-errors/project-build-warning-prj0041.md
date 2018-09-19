---
title: Aviso PRJ0041 de projeto | Microsoft Docs
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
ms.openlocfilehash: 7677c5718783065f64e52f98f7ddbed76e905d2a
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46038133"
---
# <a name="project-build-warning-prj0041"></a>Aviso PRJ0041 de Build de Projeto

Não é possível encontrar a dependência 'dependência' arquivo 'arquivo'. Seu projeto ainda pode ser compilado, mas talvez continue aparecendo desatualizado até que esse arquivo é encontrado.

Um arquivo (arquivo.idl/.odl, ou arquivo de recurso, por exemplo, continha uma instrução de inclusão que o sistema de projeto não foi possível resolver.

Como o sistema de projeto não processa as instruções do pré-processador (#if, por exemplo), a instrução incorreta pode não, na verdade, ser parte da compilação.

Para resolver este aviso, exclua todo o código desnecessário em arquivos. rc ou adicione arquivos de espaço reservado de nome apropriado.