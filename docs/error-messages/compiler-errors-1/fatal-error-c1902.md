---
title: Erro fatal C1902 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C1902
dev_langs:
- C++
helpviewer_keywords:
- C1902
ms.assetid: 2dc066cc-fcb1-4725-8bcb-9f44dd0905b7
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: b23507b6531f9ee4e5ce5efd5b60a1977206635c
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33228193"
---
# <a name="fatal-error-c1902"></a>Erro fatal C1902
Incompatibilidade de Gerenciador de banco de dados do programa; Verifique a instalação  
  
Um arquivo de banco de dados de programa (. PDB) foi criado usando uma versão mais recente do mspdb*XXX*. dll que o compilador encontrado no sistema. Esse erro geralmente indica que mspdbsrv.exe ou mspdbcore.dll estão ausentes ou têm versões diferentes de mspdb*XXX*. dll. (O *XXX* espaço reservado de mspdb*XXX*alterações de nome de arquivo. dll em cada versão do produto. Por exemplo, no Visual Studio 2015, o nome do arquivo é mspdb140.dll.)  
  
Certifique-se de versões correspondentes do mspdbsrv.exe, mspdbcore.dll e mspdb*XXX*. dll está instalado no seu sistema. Certifique-se de que as versões incompatíveis não foram copiadas para o diretório que contém as ferramentas de compilador e o link para sua plataforma de destino. Por exemplo, você pode ter copiado os arquivos para que você pode chamar a ferramenta de compilador ou link do prompt de comando sem definir o **caminho** variável de ambiente adequadamente.