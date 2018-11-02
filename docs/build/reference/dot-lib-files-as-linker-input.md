---
title: Arquivos .Lib como entrada de vinculador
ms.date: 11/04/2016
f1_keywords:
- VC.Project.VCLinkerTool.AdditionalDependencies
helpviewer_keywords:
- OMF libraries
- linking [C++], OMF libraries
- import libraries, linker files
- libraries [C++], .lib files as linker input
- COFF files, import libraries
- default libraries [C++], linker output
- default libraries [C++]
- defaults [C++], libraries
- .lib files
ms.assetid: dc5d2b1c-2487-41fa-aa71-ad1e0647958b
ms.openlocfilehash: 0bf791d682b66d9d0da968fb0bfd5229e912e84c
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50505334"
---
# <a name="lib-files-as-linker-input"></a>Arquivos .Lib como entrada de vinculador

LINK aceita as bibliotecas padrão COFF e COFF importe as bibliotecas, que geralmente têm a extensão. lib. Bibliotecas padrão contêm objetos e são criadas pela ferramenta de LIB. Bibliotecas de importação contêm informações sobre exportações em outros programas e são criadas pelo LINK quando ele compila um programa que contém exportações ou pela ferramenta de LIB. Para obter informações sobre como usar LIB para criar um padrão ou importe as bibliotecas, consulte [referência de LIB](../../build/reference/lib-reference.md). Para obter detalhes sobre como usar o LINK para criar uma biblioteca de importação, consulte o [/DLL](../../build/reference/dll-build-a-dll.md) opção.

Uma biblioteca é especificada para LINK como um argumento de nome de arquivo ou uma biblioteca padrão. LINK resolve referências externas por meio da pesquisa pela primeira vez em bibliotecas especificadas na linha de comando, em seguida, em default bibliotecas especificado com o [/DEFAULTLIB](../../build/reference/defaultlib-specify-default-library.md) opção, e, em seguida, em default bibliotecas nomeado em arquivos. obj. Se um caminho é especificado com o nome da biblioteca, o LINK procura a biblioteca nesse diretório. Se nenhum caminho for especificado, o LINK procura primeiro no diretório que está executando o LINK do e, em seguida, em qualquer diretório especificado na variável de ambiente LIB.

## <a name="to-add-lib-files-as-linker-input-in-the-development-environment"></a>Para adicionar arquivos. lib como entrada de vinculador no ambiente de desenvolvimento

1. Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, confira [Trabalhando com propriedades do projeto](../../ide/working-with-project-properties.md).

1. Escolha o **entrada** página de propriedades na **vinculador** pasta.

1. Modificar a **dependências adicionais** propriedade para adicionar os arquivos. lib.

## <a name="to-programmatically-add-lib-files-as-linker-input"></a>Para adicionar programaticamente arquivos. lib como entrada de vinculador

- Ver [AdditionalDependencies](https://msdn.microsoft.com/library/microsoft.visualstudio.vcprojectengine.vclinkertool.additionaldependencies.aspx).

## <a name="example"></a>Exemplo

O exemplo a seguir mostra como criar e usar um arquivo. lib. Primeiro, crie um arquivo. lib:

```cpp
// lib_link_input_1.cpp
// compile by using: cl /LD lib_link_input_1.cpp
__declspec(dllexport) int Test() {
   return 213;
}
```

E, em seguida, compile Este exemplo usando o arquivo. lib que você acabou de criar:

```cpp
// lib_link_input_2.cpp
// compile by using: cl /EHsc lib_link_input_1.lib lib_link_input_2.cpp
__declspec(dllimport) int Test();
#include <iostream>
int main() {
   std::cout << Test() << std::endl;
}
```

```Output
213
```

## <a name="see-also"></a>Consulte também

[Arquivos de entrada de LINK](../../build/reference/link-input-files.md)<br/>
[Opções do vinculador](../../build/reference/linker-options.md)