---
title: Copiar propriedades do projeto de origem (Linux C++) | Microsoft Docs
ms.custom: 
ms.date: 9/26/2017
ms.reviewer: 
ms.suite: 
ms.technology: vs-ide-general
ms.tgt_pltfrm: 
ms.topic: article
ms.assetid: 1a44230d-5dd8-4d33-93b4-e77e03e00150
author: mikeblome
ms.author: mblome
manager: ghogen
f1_keywords: VC.Project.VCConfiguration.BuildLogFile
ms.openlocfilehash: d552ef6bd5106b3db0e30214d8fbc144b9aa00eb
ms.sourcegitcommit: ca2f94dfd015e0098a6eaf5c793ec532f1c97de1
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2017
---
# <a name="copy-sources-project-properties-linux-c"></a>Copiar propriedades do projeto de origem (Linux C++)
As propriedades definidas nesta página de propriedades aplicam-se a todos os arquivos no projeto, exceto aos que têm as propriedades no nível do arquivo definidas.

Propriedade | Descrição
--- | ---
Origens para copiar | Especifica as fontes a serem copiadas para o sistema remoto. Alterar essa lista pode mudar ou afetar de algum outro modo a estrutura de diretórios em que os arquivos são copiados para o sistema remoto.
Fontes de dados | Especifica se as fontes devem ser copiadas para o sistema remoto.
Fontes adicionais a serem copiadas | Especifica as fontes adicionais a serem copiadas para o sistema remoto. Opcionalmente, a lista pode ser fornecida como um local para pares de mapeamento remoto usando uma sintaxe como esta: fulllocalpath1:=fullremotepath1;fulllocalpath2:=fullremotepath2, em que um arquivo local pode ser copiado para o local remoto especificado no sistema remoto.
