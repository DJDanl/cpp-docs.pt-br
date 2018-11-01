---
title: Geração de manifesto na linha de comando
ms.date: 11/04/2016
helpviewer_keywords:
- manifests [C++]
- manifest tool (mt.exe)
ms.assetid: fc2ff255-82b1-4c44-af76-8405c5850292
ms.openlocfilehash: e192122a5b9411f983683c2fa01fab2aded49ffe
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50505347"
---
# <a name="manifest-generation-at-the-command-line"></a>Geração de manifesto na linha de comando

Ao criar aplicativos C/C++ na linha de comando, usando nmake ou ferramentas semelhantes, o manifesto é gerado depois que o vinculador processou todos os arquivos de objeto e compilado o binário final. O vinculador coleta informações de assembly armazenadas nos arquivos de objeto e combina essas informações em um arquivo de manifesto final. Por padrão, o vinculador gerará um arquivo chamado *binary_name*. *extensão*. manifest para descrever o binário final. O vinculador não insere um arquivo de manifesto dentro do binário e só pode gerar um manifesto como um arquivo externo. Há várias maneiras de inserir um manifesto em final binário, como o uso de [ferramenta de manifesto (mt.exe)](https://msdn.microsoft.com/library/aa375649) ou compilar o manifesto em um arquivo de recurso. É importante ter em mente que têm regras específicas a serem seguidas ao inserir um manifesto em binário final para habilitar recursos como a vinculação incremental, assinatura, e editar e continuar. Essas e outras opções são discutidas na [como: inserir um manifesto dentro de um aplicativo C/C++](../build/how-to-embed-a-manifest-inside-a-c-cpp-application.md) ao compilar na linha de comando.

## <a name="see-also"></a>Consulte também

[Manifestos](https://msdn.microsoft.com/library/aa375365)<br/>
[/INCREMENTAL (vincular de maneira incremental)](../build/reference/incremental-link-incrementally.md)<br/>
[Assemblies de nome forte (assinatura de assembly) (C++/CLI)](../dotnet/strong-name-assemblies-assembly-signing-cpp-cli.md)<br/>
[Editar e continuar](/visualstudio/debugger/edit-and-continue)<br/>
[Noções básicas sobre o Manifest Generation para programas do C/C++](../build/understanding-manifest-generation-for-c-cpp-programs.md)<br/>
