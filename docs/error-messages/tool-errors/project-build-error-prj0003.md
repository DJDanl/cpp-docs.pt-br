---
title: Erro de Build PRJ0003 no Projeto
ms.date: 11/04/2016
f1_keywords:
- PRJ0003
helpviewer_keywords:
- PRJ0003
ms.assetid: fc5a84bb-c6d3-41d6-8dd6-475455820778
ms.openlocfilehash: 59028c6d886630ef7db115a2ea93327669b2fcfd
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80192920"
---
# <a name="project-build-error-prj0003"></a>Erro de Build PRJ0003 no Projeto

> Erro ao gerar a '*linha de comando*'.

O comando de *linha de comando* formado por entrada na caixa de diálogo **páginas de propriedades** retornou um código de erro, mas nenhuma informação é exibida na janela **saída** .

Os motivos possíveis para esse erro incluem:

- Seu projeto depende do servidor ATL. A partir do Visual Studio 2008, o servidor ATL não é mais incluído como parte do Visual Studio, mas foi lançado como um projeto de código-fonte compartilhado no CodePlex. Para baixar o código-fonte e as ferramentas do servidor ATL, vá para [biblioteca e ferramentas do servidor ATL](https://go.microsoft.com/fwlink/p/?linkid=81979).

- Recursos do sistema insuficientes. Feche alguns aplicativos para resolver isso.

- Privilégios de segurança insuficientes. Verifique se você tem privilégios de segurança suficientes.

- Os caminhos executáveis especificados nos **diretórios vc + +** não incluem o caminho para a ferramenta que você está tentando executar. Para obter informações, consulte [definir compilador e propriedades de compilação](../../build/working-with-project-properties.md)

- Para projetos Makefile, você não tem um comando para executar em uma **linha de comando de compilação** ou em uma **linha de comando de recompilação**.

## <a name="see-also"></a>Confira também

[Erros e avisos de build do projeto (PRJxxxx)](../../error-messages/tool-errors/project-build-errors-and-warnings-prjxxxx.md)
