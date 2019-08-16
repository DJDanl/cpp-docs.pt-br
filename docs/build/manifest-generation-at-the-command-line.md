---
title: Geração de manifesto na linha de comando
ms.date: 11/04/2016
helpviewer_keywords:
- manifests [C++]
- manifest tool (mt.exe)
ms.assetid: fc2ff255-82b1-4c44-af76-8405c5850292
ms.openlocfilehash: 381406213422e286dd9aba26adcdbd6caff7bfe3
ms.sourcegitcommit: fcb48824f9ca24b1f8bd37d647a4d592de1cc925
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/15/2019
ms.locfileid: "69493200"
---
# <a name="manifest-generation-at-the-command-line"></a>Geração de manifesto na linha de comando

Ao criar C/C++ Applications a partir da linha de comando usando NMAKE ou ferramentas semelhantes, o manifesto é gerado depois que o vinculador processa todos os arquivos de objeto e criou o binário final. O vinculador coleta informações de assembly armazenadas nos arquivos de objeto e combina essas informações em um arquivo de manifesto final. Por padrão, o vinculador irá gerar um arquivo chamado *binary_name*. *extensão*. manifest para descrever o binário final. O vinculador não incorpora um arquivo de manifesto dentro do binário e só pode gerar um manifesto como um arquivo externo. Há várias maneiras de inserir um manifesto dentro do binário final, como usar a ferramenta de [manifesto (Mt. exe)](/windows/win32/sbscs/mt-exe) ou compilar o manifesto em um arquivo de recurso. É importante ter em mente que regras específicas devem ser seguidas ao inserir um manifesto dentro do binário final para habilitar recursos como vinculação incremental, assinatura e edição e continuação. Essas e outras opções são discutidas [em como: Insira um manifesto dentro de um aplicativoC++ ](how-to-embed-a-manifest-inside-a-c-cpp-application.md) C/ao criar na linha de comando.

## <a name="see-also"></a>Consulte também

[Manifestos](/windows/win32/sbscs/manifests)<br/>
[/INCREMENTAL (vincular de maneira incremental)](reference/incremental-link-incrementally.md)<br/>
[Assemblies de nome forte (assinatura de assembly) (C++/CLI)](../dotnet/strong-name-assemblies-assembly-signing-cpp-cli.md)<br/>
[Editar e continuar](/visualstudio/debugger/edit-and-continue)<br/>
[Noções básicas sobre o Manifest Generation para programas do C/C++](understanding-manifest-generation-for-c-cpp-programs.md)<br/>
