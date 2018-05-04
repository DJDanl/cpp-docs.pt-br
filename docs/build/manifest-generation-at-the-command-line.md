---
title: Geração de manifesto na linha de comando | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-tools
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- manifests [C++]
- manifest tool (mt.exe)
ms.assetid: fc2ff255-82b1-4c44-af76-8405c5850292
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 7f740030e48a33284a31da4ebd46f0c4d7b6ac7e
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
---
# <a name="manifest-generation-at-the-command-line"></a>Geração de manifesto na linha de comando
Ao criar aplicativos C/C++ na linha de comando usando nmake ou ferramentas semelhantes, o manifesto é gerado depois que o vinculador é processado todos os arquivos de objeto e compilado binário final. O vinculador coleta informações de assembly armazenadas nos arquivos de objeto e combina essas informações em um arquivo de manifesto final. Por padrão, o vinculador gerará um arquivo chamado < binary_name >. \<extensão >. manifest para descrever o binário final. O vinculador não insere um arquivo de manifesto dentro do binário e só pode gerar um manifesto como um arquivo externo. Há várias maneiras para inserir um manifesto em binário final, como o uso de [ferramenta de manifesto (mt.exe)](http://msdn.microsoft.com/library/aa375649) ou compilando manifesto em um arquivo de recurso. É importante ter em mente que regras específicas devem ser seguidos durante a inserção de um manifesto em binário final para habilitar recursos como vínculo incremental, assinatura, e editar e continuar. Estas e outras opções são discutidas em [como: inserir um manifesto dentro de um aplicativo C/C++](../build/how-to-embed-a-manifest-inside-a-c-cpp-application.md) ao compilar na linha de comando.  
  
## <a name="see-also"></a>Consulte também  
 [Manifestos](http://msdn.microsoft.com/library/aa375365)   
 [/INCREMENTAL (vincular de maneira incremental)](../build/reference/incremental-link-incrementally.md)   
 [Assemblies de nome forte (assinatura de Assembly) (C + + CLI)](../dotnet/strong-name-assemblies-assembly-signing-cpp-cli.md)   
 [Editar e continuar](/visualstudio/debugger/edit-and-continue)   
 [Noções básicas sobre o Manifest Generation para programas do C/C++](../build/understanding-manifest-generation-for-c-cpp-programs.md)