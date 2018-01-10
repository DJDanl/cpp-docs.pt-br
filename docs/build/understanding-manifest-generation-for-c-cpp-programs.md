---
title: "Noções básicas sobre geração de manifesto para programas do C/C++ | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
dev_langs: C++
helpviewer_keywords: manifests [C++]
ms.assetid: a1f24221-5b09-4824-be48-92eae5644b53
caps.latest.revision: "12"
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 848b4b449fa2c9c8930a616b70a5b61cb28d8fbf
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="understanding-manifest-generation-for-cc-programs"></a>Noções básicas sobre geração de manifesto para programas do C/C++
Um [manifesto](http://msdn.microsoft.com/library/aa375365) é um documento XML que pode ser um arquivo XML externo ou um recurso incorporado dentro de um aplicativo ou um assembly. O manifesto de um [aplicativo isolado](http://msdn.microsoft.com/library/aa375190) é usado para gerenciar os nomes e as versões de assemblies lado a lado compartilhados para que o aplicativo deve associar em tempo de execução. O manifesto de um assembly lado a lado especifica suas dependências em outros assemblies, versões, recursos e nomes.  
  
 Há duas maneiras de criar um manifesto para um aplicativo isolado ou um assembly lado a lado. Primeiro, o autor do assembly pode criar manualmente um arquivo de manifesto seguindo as regras e requisitos de nomenclatura. Como alternativa, se um programa só depende de assemblies do Visual C++, como CRT, MFC, ATL ou outras pessoas, em seguida, um manifesto pode ser gerado automaticamente pelo vinculador.  
  
 Os cabeçalhos das bibliotecas do Visual C++ contêm informações de assembly, e quando as bibliotecas são incluídas no código do aplicativo, essas informações de assembly são usadas pelo vinculador para formar um manifesto para o binário final. O vinculador não insere o arquivo de manifesto dentro do binário e só pode gerar o manifesto como um arquivo externo. Ter um manifesto como um arquivo externo pode não funcionar para todos os cenários. Por exemplo, é recomendável que assemblies privados têm manifestos incorporados. Em compilações de linha de comando, como aquelas que usam nmake para compilar o código, um manifesto pode ser inserido usando a ferramenta de manifesto. Para obter mais informações, consulte [geração de manifesto na linha de comando](../build/manifest-generation-at-the-command-line.md). Ao compilar no [!INCLUDE[vsprvs](../assembler/masm/includes/vsprvs_md.md)], pode ser inserido um manifesto definindo uma propriedade para a ferramenta de manifesto a **propriedades do projeto** caixa de diálogo, consulte [geração de manifesto no Visual Studio](../build/manifest-generation-in-visual-studio.md).  
  
## <a name="see-also"></a>Consulte também  
 [Conceitos de aplicativos isolados e Assemblies lado a lado](../build/concepts-of-isolated-applications-and-side-by-side-assemblies.md)   
 [Compilando aplicativos isolados do C/C++ e assemblies lado a lado](../build/building-c-cpp-isolated-applications-and-side-by-side-assemblies.md)