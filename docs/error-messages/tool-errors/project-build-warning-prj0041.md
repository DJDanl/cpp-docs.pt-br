---
title: Aviso PRJ0041 de Build de Projeto
ms.date: 11/04/2016
f1_keywords:
- PRJ0041
helpviewer_keywords:
- PRJ0041
ms.assetid: dc9f4cf9-6bd5-4222-89e8-7802a59bb96b
ms.openlocfilehash: b0fceff05ffe35515965b7e0a880c8b4c941b07e
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50583203"
---
# <a name="project-build-warning-prj0041"></a>Aviso PRJ0041 de Build de Projeto

Não é possível encontrar a dependência 'dependência' arquivo 'arquivo'. Seu projeto ainda pode ser compilado, mas talvez continue aparecendo desatualizado até que esse arquivo é encontrado.

Um arquivo (arquivo.idl/.odl, ou arquivo de recurso, por exemplo, continha uma instrução de inclusão que o sistema de projeto não foi possível resolver.

Como o sistema de projeto não processa as instruções do pré-processador (#if, por exemplo), a instrução incorreta pode não, na verdade, ser parte da compilação.

Para resolver este aviso, exclua todo o código desnecessário em arquivos. rc ou adicione arquivos de espaço reservado de nome apropriado.