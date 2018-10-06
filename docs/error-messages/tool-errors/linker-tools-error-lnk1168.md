---
title: Ferramentas de vinculador LNK1168 erro | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- LNK1168
dev_langs:
- C++
helpviewer_keywords:
- LNK1168
ms.assetid: 97ead151-fd99-46fe-9a1d-7e84dc0b8cc8
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 0910c23202b975999e10ef2effaebc470c62fb9d
ms.sourcegitcommit: a738519aa491a493a8f213971354356c0e6a5f3a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/05/2018
ms.locfileid: "48821069"
---
# <a name="linker-tools-error-lnk1168"></a>Erro das Ferramentas de Vinculador LNK1168

não foi possível abrir filename para escrita

O vinculador não pode gravar em `filename`. O arquivo pode estar em uso e em seu identificador de arquivo bloqueado por outro processo, ou você pode não ter permissão de gravação para o arquivo, ou para o diretório ou o compartilhamento de rede em que ele está localizado. Esse erro geralmente é causado por uma condição transitória – por exemplo, um bloqueio mantido por um programa antivírus, processo de indexação de pesquisa de um arquivo ou um atraso na liberação de um bloqueio mantido pelo sistema de compilação do Visual Studio.

Para corrigir esse problema, verifique se o identificador do arquivo `filename` não está bloqueado e se você tem permissão de gravação para o arquivo. Se for um executável, verifique se não está em execução.

Você pode usar os utilitários do Windows SysInternals [manipular](http://technet.microsoft.com/sysinternals/bb896655.aspx) ou [Process Explorer](http://technet.microsoft.com/sysinternals/bb896653) para determinar qual processo tem um arquivo de bloqueio de identificador `filename`. Você também pode usar o Process Explorer para liberar bloqueios em identificadores de arquivos abertos. Para obter informações sobre como usar esses utilitários, consulte os arquivos da Ajuda que os acompanham.

Se o arquivo estiver bloqueado por um programa antivírus, você poderá resolver esse problema excluindo os diretórios de saída de compilação de verificação automática pelo programa antivírus. Os verificadores antivírus são disparados frequentemente pela criação de novos arquivos no sistema de arquivos e mantêm bloqueios em arquivos durante a análise. Consulte a documentação do programa antivírus para obter detalhes sobre como excluir diretórios específicos da verificação.

Se o arquivo for bloqueada por um serviço de indexação de pesquisa, você poderá resolver esse problema excluindo os diretórios de saída de compilação de indexação automática. Consulte a documentação do serviço de indexação para obter mais informações. Para alterar a serviço de indexação de pesquisa de Windows, use **as opções de indexação** em que o Windows **painel de controle**. Para obter mais informações, consulte [Windows melhorar pesquisas usando o índice: perguntas frequentes](http://windows.microsoft.com/windows/improve-windows-searches-using-index-faq#1TC=windows-7).

Se o executável não puder ser substituído pelo processo de compilação, ele poderá estar bloqueado pelo Explorador de Arquivos. Se o **experiência de aplicativo** serviço foi desabilitado, o Explorador de arquivos poderá se ater a um bloqueio de identificador de arquivo executável por um longo período. Para corrigir esse problema, execute **Services. msc** e, em seguida, abra o **propriedades** caixa de diálogo para o **experiência de aplicativo** service. Alterar o **tipo de inicialização** de **desabilitado** para **Manual**.

## <a name="see-also"></a>Consulte também

[Você pode receber um "erro de PRJ0008" ou a mensagem de erro "Erro Fatal LNK1168" ao tentar criar uma solução ou um projeto do ActiveX no Visual C++](http://support.microsoft.com/kb/308358)