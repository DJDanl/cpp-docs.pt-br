---
title: Erro das Ferramentas de Vinculador LNK1123
ms.date: 12/29/2017
f1_keywords:
- LNK1123
helpviewer_keywords:
- LNK1123
ms.openlocfilehash: 31fd634291bfb0af17348197ae8a6225ac490c89
ms.sourcegitcommit: fcb48824f9ca24b1f8bd37d647a4d592de1cc925
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/15/2019
ms.locfileid: "69509905"
---
# <a name="linker-tools-error-lnk1123"></a>Erro das Ferramentas de Vinculador LNK1123

> falha durante a conversão para COFF: arquivo inválido ou corrompido

Os arquivos de entrada devem ter o formato COFF (Common Object File Format). Se um arquivo de entrada não for COFF, o vinculador tenta converter automaticamente objetos OMF de 32 bits para COFF ou executa CVTRES.EXE para converter arquivos de recurso. Essa mensagem indica que o vinculador não pode converter o arquivo. Isso também ocorre ao usar uma versão incompatível do CVTRES.EXE de outra instalação do Visual Studio, do Windows Development Kit ou do .NET Framework.

> [!NOTE]
> Se você estiver executando uma versão anterior do Visual Studio, pode não haver suporte para a conversão automática.

## <a name="to-fix-the-problem"></a>Para corrigir o problema

- Aplica todos os service packs e atualizações para sua versão do Visual Studio. Isso é especialmente importante para o Visual Studio 2010.

- Tente compilar com a vinculação incremental desabilitada. Na barra de menus, escolha **Projeto**, **Propriedades**. Na caixa de diálogo **páginas de propriedades** , expanda **Propriedades de configuração**, **vinculador**. Altere o valor de **habilitar vinculação incremental** para **não**.

- Verifique se a versão do CVTRES.EXE encontrada primeiro na variável de ambiente PATH combina com a versão das ferramentas de compilação ou com a versão do Conjunto de Ferramentas de Plataforma, usado no projeto.

- Tente desativar a opção Inserir manifesto. Na barra de menus, escolha **Projeto**, **Propriedades**. Na caixa de diálogo **páginas de propriedades** , expanda **Propriedades de configuração**, ferramenta de **manifesto**, **entrada e saída**. Altere o valor do **manifesto de inserção** para **não**.

- Verifique se o tipo de arquivo é válido. Por exemplo, verifique se um objeto OMF é de 32 bits e não de 16 bits. Para obter mais informações, consulte [. Obj files como entrada](../../build/reference/dot-obj-files-as-linker-input.md) do vinculador e [formato PE](/windows/win32/Debug/pe-format).

- Verifique se o arquivo não está corrompido. Recompile-o, se necessário.

## <a name="see-also"></a>Consulte também

[Arquivos .obj como entrada do vinculador](../../build/reference/dot-obj-files-as-linker-input.md)<br/>
[Referência de EDITBIN](../../build/reference/editbin-reference.md)<br/>
[Referência de DUMPBIN](../../build/reference/dumpbin-reference.md)
