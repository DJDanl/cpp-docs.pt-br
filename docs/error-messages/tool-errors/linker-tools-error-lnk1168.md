---
title: Erro das Ferramentas de Vinculador LNK1168
ms.date: 11/04/2016
f1_keywords:
- LNK1168
helpviewer_keywords:
- LNK1168
ms.assetid: 97ead151-fd99-46fe-9a1d-7e84dc0b8cc8
ms.openlocfilehash: f0eb63c124162dbb515782bbd014c556c12de153
ms.sourcegitcommit: 28eae422049ac3381c6b1206664455dbb56cbfb6
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/31/2019
ms.locfileid: "66450896"
---
# <a name="linker-tools-error-lnk1168"></a>Erro das Ferramentas de Vinculador LNK1168

não foi possível abrir filename para escrita

O vinculador não pode gravar em `filename`. O arquivo pode estar em uso e em seu identificador de arquivo bloqueado por outro processo, ou você pode não ter permissão de gravação para o arquivo, ou para o diretório ou o compartilhamento de rede em que ele está localizado. Esse erro geralmente é causado por uma condição transitória – por exemplo, um bloqueio mantido por um programa antivírus, processo de indexação de pesquisa de um arquivo ou um atraso na liberação de um bloqueio mantido pelo sistema de compilação do Visual Studio.

Para corrigir esse problema, verifique se o identificador do arquivo `filename` não está bloqueado e se você tem permissão de gravação para o arquivo. Se for um executável, verifique se não está em execução.

Você pode usar os utilitários do Windows SysInternals [manipular](/sysinternals/downloads/handle) ou [Process Explorer](/sysinternals/downloads/process-explorer) para determinar qual processo tem um arquivo de bloqueio de identificador `filename`. Você também pode usar o Process Explorer para liberar bloqueios em identificadores de arquivos abertos. Para obter informações sobre como usar esses utilitários, consulte os arquivos da Ajuda que os acompanham.

Se o arquivo estiver bloqueado por um programa antivírus, você poderá resolver esse problema excluindo os diretórios de saída de compilação de verificação automática pelo programa antivírus. Os verificadores antivírus são disparados frequentemente pela criação de novos arquivos no sistema de arquivos e mantêm bloqueios em arquivos durante a análise. Consulte a documentação do programa antivírus para obter detalhes sobre como excluir diretórios específicos da verificação.

Se o arquivo for bloqueada por um serviço de indexação de pesquisa, você poderá resolver esse problema excluindo os diretórios de saída de compilação de indexação automática. Consulte a documentação do serviço de indexação para obter mais informações. Para alterar a serviço de indexação de pesquisa de Windows, use **as opções de indexação** em que o Windows **painel de controle**. Para obter mais informações, consulte [no Windows 10 a indexação de pesquisa: PERGUNTAS FREQUENTES SOBRE](https://support.microsoft.com/help/4098843/windows-10-search-indexing-faq).

Se o executável não puder ser substituído pelo processo de compilação, ele poderá estar bloqueado pelo Explorador de Arquivos. Se o **experiência de aplicativo** serviço foi desabilitado, o Explorador de arquivos poderá se ater a um bloqueio de identificador de arquivo executável por um longo período. Para corrigir esse problema, execute **Services. msc** e, em seguida, abra o **propriedades** caixa de diálogo para o **experiência de aplicativo** service. Alterar o **tipo de inicialização** de **desabilitado** para **Manual**.
