---
title: Erro de Build PRJ0003 no Projeto
ms.date: 11/04/2016
f1_keywords:
- PRJ0003
helpviewer_keywords:
- PRJ0003
ms.assetid: fc5a84bb-c6d3-41d6-8dd6-475455820778
ms.openlocfilehash: 00d101e62d49078ebfcfff9455497f30224b84fe
ms.sourcegitcommit: 72583d30170d6ef29ea5c6848dc00169f2c909aa
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/18/2019
ms.locfileid: "59039492"
---
# <a name="project-build-error-prj0003"></a>Erro de Build PRJ0003 no Projeto

> Erro ao gerar '*linha de comando*'.

O *linha de comando* comando formado de entrada na **páginas de propriedades** caixa de diálogo retornou um código de erro, mas nenhuma informação é exibida no **saída** janela.

Os motivos possíveis para esse erro incluem:

- Seu projeto depende do servidor ATL. A partir do Visual Studio 2008, servidor ATL não está mais incluída como parte do Visual Studio, mas foi lançado como um projeto de código-fonte compartilhado no CodePlex. Para baixar o código-fonte ATL Server e ferramentas, vá para [biblioteca do servidor ATL e ferramentas](http://go.microsoft.com/fwlink/p/?linkid=81979).

- Recursos insuficientes do sistema. Feche alguns aplicativos para resolver esse problema.

- Privilégios de segurança insuficientes. Verifique se que você tem privilégios suficientes.

- Caminhos de executável especificado na **diretórios VC + +** não incluem o caminho para a ferramenta que você está tentando executar. Para obter informações, consulte [definir compilador e propriedades de compilação](../../build/working-with-project-properties.md)

- Para projetos makefile, um comando para executar em qualquer um estiver faltando **linha de comando de compilação** ou **recompilar linha de comando**.

## <a name="see-also"></a>Consulte também

[Erros e avisos de build do projeto (PRJxxxx)](../../error-messages/tool-errors/project-build-errors-and-warnings-prjxxxx.md)