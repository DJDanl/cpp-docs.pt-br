---
title: Copiar propriedades do projeto de origem (Linux C++)
ms.date: 9/26/2017
ms.assetid: 1a44230d-5dd8-4d33-93b4-e77e03e00150
ms.openlocfilehash: dd0a26db58265724f0a0e46c31365c97c00ff568
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50477240"
---
# <a name="copy-sources-project-properties-linux-c"></a>Copiar propriedades do projeto de origem (Linux C++)

As propriedades definidas nesta página de propriedades aplicam-se a todos os arquivos no projeto, exceto aos que têm as propriedades no nível do arquivo definidas.

Propriedade | Descrição
--- | ---
Origens para copiar | Especifica as fontes a serem copiadas para o sistema remoto. Alterar essa lista pode mudar ou afetar de algum outro modo a estrutura de diretórios em que os arquivos são copiados para o sistema remoto.
Fontes de dados | Especifica se as fontes devem ser copiadas para o sistema remoto.
Fontes adicionais a serem copiadas | Especifica as fontes adicionais a serem copiadas para o sistema remoto. Opcionalmente, a lista pode ser fornecida como um local para pares de mapeamento remoto usando uma sintaxe como esta: fulllocalpath1:=fullremotepath1;fulllocalpath2:=fullremotepath2, em que um arquivo local pode ser copiado para o local remoto especificado no sistema remoto.
