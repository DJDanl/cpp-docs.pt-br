---
title: Copiar propriedades do projeto de origem (Linux C++)
ms.date: 06/07/2019
ms.assetid: 1a44230d-5dd8-4d33-93b4-e77e03e00150
ms.openlocfilehash: afc65fb7fbc3866081fbf7da6d3c5014ba1c268d
ms.sourcegitcommit: 8adabe177d557c74566c13145196c11cef5d10d4
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/10/2019
ms.locfileid: "66821319"
---
# <a name="copy-sources-project-properties-linux-c"></a>Copiar propriedades do projeto de origem (Linux C++)

::: moniker range="vs-2015"

O suporte ao Linux está disponível no Visual Studio 2017 e posterior.

::: moniker-end

::: moniker range=">=vs-2017"

As propriedades definidas nesta página de propriedades aplicam-se a todos os arquivos no projeto, exceto aos que têm as propriedades no nível do arquivo definidas.

Propriedade | Descrição
--- | ---
Origens para copiar | Especifica as fontes a serem copiadas para o sistema remoto. Alterar essa lista pode mudar ou afetar de algum outro modo a estrutura de diretórios em que os arquivos são copiados para o sistema remoto.
Fontes de dados | Especifica se as fontes devem ser copiadas para o sistema remoto.
Fontes adicionais a serem copiadas | Especifica as fontes adicionais a serem copiadas para o sistema remoto. Opcionalmente, a lista pode ser fornecida como um local para pares de mapeamento remoto usando uma sintaxe como esta: fulllocalpath1:=fullremotepath1;fulllocalpath2:=fullremotepath2, em que um arquivo local pode ser copiado para o local remoto especificado no sistema remoto.

::: moniker-end
