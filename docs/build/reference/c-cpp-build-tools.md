---
title: Ferramentas de Build MSVC adicionais
ms.date: 08/28/2019
f1_keywords:
- c.build
helpviewer_keywords:
- builds [C++], C/C++ tools
- tools [C++], build
ms.assetid: 48d9daf4-6bbf-473a-8ce2-bf2923b69f80
ms.openlocfilehash: 53c7c2f8c162cd851b4612e75ba14b019d9cbd63
ms.sourcegitcommit: e10a5feea193c249ddc5a6faba48e7c6d8784e73
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/30/2019
ms.locfileid: "70177287"
---
# <a name="additional-msvc-build-tools"></a>Ferramentas de Build MSVC adicionais

O Visual Studio fornece os seguintes utilitários de linha de comando para exibir ou manipular a saída da compilação:

- [Lib. EXE](lib-reference.md) é usado para criar e gerenciar uma biblioteca de arquivos de objeto de formato de arquivo de objeto comum (COFF). Ele também pode ser usado para criar arquivos de exportação e importar bibliotecas para referenciar definições exportadas.

- [EDITBIN. EXE](editbin-reference.md) é usado para modificar arquivos binários COFF.

- [DUMPBIN. EXE](dumpbin-reference.md) exibe informações (como uma tabela de símbolos) sobre arquivos binários COFF.

- [NMAKE](nmake-reference.md) lê e executa makefiles.

- [ERRLOOK](value-edit-control.md), o utilitário de pesquisa de erro, recupera uma mensagem de erro do sistema ou uma mensagem de erro de módulo com base no valor inserido.

- [XDCMake](xdcmake-reference.md). Uma ferramenta para processar arquivos de código-fonte que contêm comentários de documentação marcados com marcas XML.

- [BSCMAKE. EXE](bscmake-reference.md) (fornecido somente para compatibilidade com versões anteriores) cria um arquivo de informações de procura (. BSC) que contém informações sobre os símbolos (classes, funções, dados, macros e tipos) em seu programa. Essas informações são exibidas em procurar janelas dentro do ambiente de desenvolvimento. (Um arquivo. BSC também pode ser compilado no ambiente de desenvolvimento.)

O SDK do Windows também tem várias ferramentas de Build, incluindo [RC. EXE](/windows/win32/menurc/resource-compiler), que o C++ compilador invoca para compilar recursos nativos do Windows, como caixas de diálogo, páginas de propriedades, bitmaps, tabelas de cadeias de caracteres e assim por diante.

## <a name="see-also"></a>Consulte também

[Referência de build C/C++](c-cpp-building-reference.md)<br/>
[Nomes decorados](decorated-names.md)<br/>
[Opções do compilador MSVC](compiler-options.md)<br/>
[Opções de vinculador MSVC](linker-options.md)
