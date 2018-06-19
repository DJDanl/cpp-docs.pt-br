---
title: Erro fatal C1052 | Microsoft Docs
ms.custom: ''
ms.date: 05/08/2017
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C1052
dev_langs:
- C++
helpviewer_keywords:
- C1052
ms.assetid: f2c09a2f-d3c1-4420-9501-ffcb65caf87b
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: d8d272b71a527763245ccf7c8d69bd11a915eab7
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33225847"
---
# <a name="fatal-error-c1052"></a>Erro fatal C1052

> arquivo de banco de dados do programa, '*filename*', foi gerado pelo vinculador com /debug: fastlink; compilador não pode atualizar esses arquivos PDB; exclua-o ou use /Fd para especificar um nome de arquivo PDB diferente

O compilador não pode atualizar os mesmos arquivos de banco de dados (PDB) do programa que são gerados pelo vinculador quando o [/Debug: fastlink](../../build/reference/debug-generate-debug-info.md) opção é especificada. Normalmente, os arquivos PDB gerado pelo compilador e os arquivos PDB gerado pelo vinculador têm nomes diferentes. No entanto, se estiverem definidos para usar os mesmos nomes, esse erro pode resultar.

Para corrigir esse problema, você pode excluir explicitamente os arquivos PDB antes de compilar novamente, ou você pode criar nomes diferentes para os arquivos PDB gerado pelo compilador e vinculador gerado.

Para especificar o nome do arquivo PDB gerado pelo compilador na linha de comando, use o [/Fd](../../build/reference/fd-program-database-file-name.md) opção de compilador. Para especificar o nome do arquivo PDB gerado pelo compilador no IDE, abra o **páginas de propriedade** caixa de diálogo para seu projeto e, no **propriedades de configuração**, **C/C++**,  **Arquivos de saída** , defina o **nome do arquivo de banco de dados de programa** propriedade. Por padrão, essa propriedade é `$(IntDir)vc$(PlatformToolsetVersion).pdb`.

Como alternativa, você pode definir o nome do arquivo PDB gerado pelo vinculador. Para especificar o nome do arquivo PDB gerado pelo vinculador na linha de comando, use o [/PDB](../../build/reference/pdb-use-program-database.md) opção de vinculador. Para especificar o nome do arquivo PDB gerado pelo vinculador no IDE, abra o **páginas de propriedade** caixa de diálogo para seu projeto e, no **propriedades de configuração**, **vinculador**,  **Depuração** , defina o **gerar arquivo de banco de dados do programa** propriedade. Por padrão, essa propriedade é definida como `$(OutDir)$(TargetName).pdb`.
