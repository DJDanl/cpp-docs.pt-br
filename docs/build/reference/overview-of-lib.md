---
title: Visão geral de LIB | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-tools
ms.topic: reference
f1_keywords:
- Lib
dev_langs:
- C++
helpviewer_keywords:
- LIB [C++], modes
ms.assetid: e997d423-f574-434f-8b56-25585d137ee0
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: d8fd3d370da4f841e85086e3d061508d68414e96
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
ms.locfileid: "32379192"
---
# <a name="overview-of-lib"></a>Visão geral de LIB
LIB cria bibliotecas padrão, bibliotecas de importação e exportar arquivos que você pode usar com [LINK](../../build/reference/linker-options.md) durante a criação de um programa. LIB é executado em um prompt de comando.  
  
 Você pode usar o LIB nos seguintes modos:  
  
-   [Criando ou modificando uma biblioteca COFF](../../build/reference/managing-a-library.md)  
  
-   [Extrair um objeto de membro para um arquivo](../../build/reference/extracting-a-library-member.md)  
  
-   [Criando um arquivo de exportação e uma biblioteca de importação](../../build/reference/working-with-import-libraries-and-export-files.md)  
  
 Esses modos são mutuamente exclusivos; Você pode usar LIB no modo somente por vez.  
  
## <a name="lib-options"></a>Opções de lib  
 A tabela a seguir lista as opções de lib.exe, com um link para obter mais informações.  
  
 **/ DEF**  
 Crie uma biblioteca de importação e um arquivo de exportação.  
  
 Para obter mais informações, consulte [Compilando uma biblioteca de importação e exportação de arquivo](../../build/reference/building-an-import-library-and-export-file.md).  
  
 **/ERRORREPORT**  
 Envie informações à Microsoft sobre erros internos com lib.exe.  
  
 Para obter mais informações, consulte [executando LIB](../../build/reference/running-lib.md).  
  
 **/EXPORT**  
 Exporta uma função em seu programa.  
  
 Para obter mais informações, consulte [Compilando uma biblioteca de importação e exportação de arquivo](../../build/reference/building-an-import-library-and-export-file.md).  
  
 **/ EXTRAIR**  
 Crie um arquivo de objeto (. obj) que contenha uma cópia de um membro de uma biblioteca existente.  
  
 Para obter mais informações, consulte [extraindo um membro da biblioteca](../../build/reference/extracting-a-library-member.md).  
  
 **/INCLUDE**  
 Adiciona um símbolo para a tabela de símbolos.  
  
 Para obter mais informações, consulte [Compilando uma biblioteca de importação e exportação de arquivo](../../build/reference/building-an-import-library-and-export-file.md).  
  
 **/ LIBPATH**  
 Substitui o caminho da biblioteca de ambiente.  
  
 Para obter mais informações, consulte [Gerenciando uma biblioteca](../../build/reference/managing-a-library.md).  
  
 **/ LISTA**  
 Exibe informações sobre a biblioteca de saída para a saída padrão.  
  
 Para obter mais informações, consulte [Gerenciando uma biblioteca](../../build/reference/managing-a-library.md).  
  
 **/LTCG**  
 Faz com que a biblioteca a ser criada usando a geração de código para link-time.  
  
 Para obter mais informações, consulte [executando LIB](../../build/reference/running-lib.md).  
  
 **/ MÁQUINA**  
 Especifica a plataforma de destino para o programa.  
  
 Para obter mais informações, consulte [executando LIB](../../build/reference/running-lib.md).  
  
 **/ NOME**  
 Ao criar uma biblioteca de importação, especifica o nome da DLL para o qual a biblioteca de importação está sendo compilada.  
  
 Para obter mais informações, consulte [Gerenciando uma biblioteca](../../build/reference/managing-a-library.md).  
  
 **/NODEFAULTLIB**  
 Remove uma ou mais bibliotecas padrão da lista de bibliotecas que busca ao resolver referências externas.  
  
 Para obter mais informações, consulte [Gerenciando uma biblioteca](../../build/reference/managing-a-library.md).  
  
 **/NOLOGO**  
 Suprime a exibição do número de mensagem e a versão de direitos autorais do LIB e impede a repetição de arquivos de comando.  
  
 Para obter mais informações, consulte [executando LIB](../../build/reference/running-lib.md).  
  
 **/ ENTRADA SAÍDA**  
 Substitui o nome do arquivo de saída padrão.  
  
 Para obter mais informações, consulte [Gerenciando uma biblioteca](../../build/reference/managing-a-library.md).  
  
 **OU REMOVER**  
 Omite a um objeto da biblioteca de saída.  
  
 Para obter mais informações, consulte [Gerenciando uma biblioteca](../../build/reference/managing-a-library.md).  
  
 **/SUBSYSTEM**  
 Informa o sistema operacional como executar um programa criado por meio da vinculação para a biblioteca de saída.  
  
 Para obter mais informações, consulte [Gerenciando uma biblioteca](../../build/reference/managing-a-library.md).  
  
 **/VERBOSE**  
 Exibe detalhes sobre o progresso da sessão, incluindo os nomes dos arquivos. obj que está sendo adicionados.  
  
 Para obter mais informações, consulte [executando LIB](../../build/reference/running-lib.md).  
  
 **/WX**  
 Trate avisos como erros.  
  
 Para obter mais informações, consulte [executando LIB](../../build/reference/running-lib.md).  
  
## <a name="see-also"></a>Consulte também  
 [Referência LIB](../../build/reference/lib-reference.md)   
 [Arquivos de entrada LIB](../../build/reference/lib-input-files.md)   
 [Arquivos de saída LIB](../../build/reference/lib-output-files.md)   
 [Outra saída LIB](../../build/reference/other-lib-output.md)   
 [Estrutura de uma biblioteca](../../build/reference/structure-of-a-library.md)