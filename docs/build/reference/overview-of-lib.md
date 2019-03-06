---
title: Visão geral de LIB
ms.date: 11/04/2016
f1_keywords:
- Lib
helpviewer_keywords:
- LIB [C++], modes
ms.assetid: e997d423-f574-434f-8b56-25585d137ee0
ms.openlocfilehash: a66f78d225a5899b53a931c7eb6a0564de689ca1
ms.sourcegitcommit: bff17488ac5538b8eaac57156a4d6f06b37d6b7f
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/05/2019
ms.locfileid: "57423281"
---
# <a name="overview-of-lib"></a>Visão geral de LIB

LIB cria bibliotecas padrão, importe as bibliotecas e exportar arquivos que você pode usar com [LINK](../../build/reference/linker-options.md) ao compilar um programa. LIB é executado em um prompt de comando.

Você pode usar LIB nos seguintes modos:

- [Criar ou modificar uma biblioteca COFF](../../build/reference/managing-a-library.md)

- [Extrair um objeto de membro para um arquivo](../../build/reference/extracting-a-library-member.md)

- [Criando um arquivo de exportação e uma biblioteca de importação](../../build/reference/working-with-import-libraries-and-export-files.md)

Esses modos são mutuamente excludentes; Você pode usar LIB no modo de apenas um por vez.

## <a name="lib-options"></a>Opções de lib

A tabela a seguir lista as opções para lib.exe, com um link para obter mais informações.

|Opção|Descrição|
|-|-|
|**/DEF**|Crie uma biblioteca de importação e um arquivo de exportação.<br/><br/>Para obter mais informações, consulte [Compilando uma biblioteca de importação e exportação de arquivo](../../build/reference/building-an-import-library-and-export-file.md).|
|**/ERRORREPORT**|   Envie à Microsoft informações sobre erros internos com lib.exe.<br/><br/>Para obter mais informações, consulte [executando LIB](../../build/reference/running-lib.md).|
|**/EXPORT**|   Exporta uma função de seu programa.<br/><br/>Para obter mais informações, consulte [Compilando uma biblioteca de importação e exportação de arquivo](../../build/reference/building-an-import-library-and-export-file.md).|
|**/EXTRACT**|   Crie um arquivo de objeto (. obj) que contém uma cópia de um membro de uma biblioteca existente.<br/><br/>Para obter mais informações, consulte [extraindo um membro da biblioteca](../../build/reference/extracting-a-library-member.md).|
|**/INCLUDE**|   Adiciona um símbolo à tabela de símbolos.<br/><br/>Para obter mais informações, consulte [Compilando uma biblioteca de importação e exportação de arquivo](../../build/reference/building-an-import-library-and-export-file.md).|
|**/LIBPATH**|   Substitui o caminho da biblioteca de ambiente.<br/><br/>Para obter mais informações, consulte [Gerenciando uma biblioteca](../../build/reference/managing-a-library.md).|
|**/LIST**|   Exibe informações sobre a biblioteca de saída para a saída padrão.<br/><br/>Para obter mais informações, consulte [Gerenciando uma biblioteca](../../build/reference/managing-a-library.md).|
|**/LTCG**|   Faz com que a biblioteca a ser criada usando a geração de código para link-time.<br/><br/>Para obter mais informações, consulte [executando LIB](../../build/reference/running-lib.md).|
|**/MACHINE**|   Especifica a plataforma de destino para o programa.<br/><br/>Para obter mais informações, consulte [executando LIB](../../build/reference/running-lib.md).|
|**/NAME**|   Ao criar uma biblioteca de importação, especifica o nome da DLL para o qual a biblioteca de importação está sendo criada.<br/><br/>Para obter mais informações, consulte [Gerenciando uma biblioteca](../../build/reference/managing-a-library.md).|
|**/NODEFAULTLIB**|   Remove uma ou mais bibliotecas padrão da lista de bibliotecas que busca ao resolver referências externas.<br/><br/>Para obter mais informações, consulte [Gerenciando uma biblioteca](../../build/reference/managing-a-library.md).|
|**/NOLOGO**|   Suprime a exibição do que o número de versão e mensagem de direitos autorais do LIB e impede a repetição de arquivos de comando.<br/><br/>Para obter mais informações, consulte [executando LIB](../../build/reference/running-lib.md).|
|**/OUT**|   Substitui o nome do arquivo de saída padrão.<br/><br/>Para obter mais informações, consulte [Gerenciando uma biblioteca](../../build/reference/managing-a-library.md).|
|**/REMOVE**|   Omite um objeto da biblioteca de saída.<br/><br/>Para obter mais informações, consulte [Gerenciando uma biblioteca](../../build/reference/managing-a-library.md).|
|**/SUBSYSTEM**|   Informa o sistema operacional como executar um programa criado por meio da vinculação para a biblioteca de saída.<br/><br/>Para obter mais informações, consulte [Gerenciando uma biblioteca](../../build/reference/managing-a-library.md).|
|**/VERBOSE**|   Exibe detalhes sobre o progresso da sessão, incluindo nomes de arquivos. obj que está sendo adicionados.<br/><br/>Para obter mais informações, consulte [executando LIB](../../build/reference/running-lib.md).|
|**/WX**|   Trate avisos como erros.<br/><br/>Para obter mais informações, consulte [executando LIB](../../build/reference/running-lib.md).|

## <a name="see-also"></a>Consulte também

[Referência de LIB](../../build/reference/lib-reference.md)<br/>
[Arquivos de entrada de LIB](../../build/reference/lib-input-files.md)<br/>
[Arquivos de saída de LIB](../../build/reference/lib-output-files.md)<br/>
[Outra saída de LIB](../../build/reference/other-lib-output.md)<br/>
[Estrutura de uma biblioteca](../../build/reference/structure-of-a-library.md)
